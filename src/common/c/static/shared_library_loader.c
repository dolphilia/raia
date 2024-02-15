//
// Created by dolphilia on 2024/02/14.
//

#include "shared_library_loader.h"

static library_hash_t *libraries = NULL;
static deleted_key_list_t *deleted_keys = NULL;

// utility

static void display_error(const char *context) {
#ifdef __WINDOWS__
    DWORD dw = GetLastError();
    LPVOID lpMsgBuf;
    FormatMessage(
        FORMAT_MESSAGE_ALLOCATE_BUFFER |
        FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
        NULL,
        dw,
        MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
        (LPTSTR) &lpMsgBuf,
        0, NULL);
    fprintf(stderr, "Error in %s: %s\n", context, (char*)lpMsgBuf);
    LocalFree(lpMsgBuf);
#else
    fprintf(stderr, "Error in %s: %s\n", context, dlerror());
#endif
}

static void* allocate_and_initialize(size_t size) {
    void *ptr = malloc(size);
    if (ptr) {
        memset(ptr, 0, size);
    } else {
        fprintf(stderr, "Failed to allocate memory\n");
    }
    return ptr;
}

// --

void close_all_shared_library(void) {
    library_hash_t *current_library, *tmp_library;
    func_hash_t *current_func, *tmp_func;
    HASH_ITER(hh, libraries, current_library, tmp_library) {
        RAIA_DLCLOSE(current_library->handle);
        HASH_ITER(hh, current_library->func_hash, current_func, tmp_func) {
            HASH_DEL(current_library->func_hash, current_func);
            utstring_free(current_func->func_name);
            free(current_func);
        }
        HASH_DEL(libraries, current_library);
        free(current_library);
    }
    deleted_key_list_t *del_current, *del_tmp;
    LL_FOREACH_SAFE(deleted_keys, del_current, del_tmp) {
        LL_DELETE(deleted_keys, del_current);
        free(del_current);
    }
}

int open_shared_library(const char* library_name) {
    void* handle = NULL;
#ifdef __LINUX__
    size_t full_path_size = strlen(library_name) + 3; // "./" + library_name + '\0'
    char* full_path = (char*)malloc(full_path_size);
    if (!full_path) {
        fprintf(stderr, "Memory allocation failed\n");
        return -1;
    }
    strcpy(full_path, "./");
    strcat(full_path, library_name);
    handle = RAIA_DLOPEN(full_path);
    free(full_path);
#else
    handle = RAIA_DLOPEN(library_name);
#endif
    if (!handle) {
        display_error("open_shared_library");
        return -1;
    }
    int key;
    if (deleted_keys) {
        deleted_key_list_t *old = deleted_keys;
        key = old->key;
        LL_DELETE(deleted_keys, old);
        free(old);
    } else {
        static int next_key = 0;
        key = next_key++;
    }
    library_hash_t *library = allocate_and_initialize(sizeof(library_hash_t));
    if (library == NULL) {
        return -1;
    }
    library->id = key;
    library->handle = handle;
    HASH_ADD_INT(libraries, id, library);
    return key;
}

void* find_shared_library(int library_key) {
    library_hash_t *hash;
    HASH_FIND_INT(libraries, &library_key, hash);
    if (hash) {
        return hash->handle;
    }
    return NULL;
}

void close_shared_library(int library_key) {
    library_hash_t *library;
    HASH_FIND_INT(libraries, &library_key, library);
    if (library) {
        RAIA_DLCLOSE(library->handle);
        func_hash_t *current_func, *tmp_func;
        HASH_ITER(hh, library->func_hash, current_func, tmp_func) {
            HASH_DEL(library->func_hash, current_func);
            utstring_free(current_func->func_name);
            free(current_func);
        }
        HASH_DEL(libraries, library);
        free(library);
        deleted_key_list_t *new_key = allocate_and_initialize(sizeof(deleted_key_list_t));
        if (new_key) {
            new_key->key = library_key;
            LL_APPEND(deleted_keys, new_key);
        } else {
            fprintf(stderr, "Failed to allocate memory for deleted key\n");
        }
    }
}

void add_func_shared_library(int library_key, const char *func_name) {
    library_hash_t *library;
    HASH_FIND_INT(libraries, &library_key, library);
    if (library) {
        callable_func_t func = (callable_func_t)RAIA_DLSYM(library->handle, func_name);
        if (!func) {
            display_error(func_name);
            return;
        }
        func_hash_t *func_entry = allocate_and_initialize(sizeof(func_hash_t));
        if (func_entry == NULL) {
            return;
        }
        utstring_new(func_entry->func_name);
        utstring_printf(func_entry->func_name, "%s", func_name);
        func_entry->func_ptr = func;
        HASH_ADD_KEYPTR(hh, library->func_hash, utstring_body(func_entry->func_name), utstring_len(func_entry->func_name), func_entry);
    }
}

const char* call_func_shared_library(int library_key, const char *func_name, const char *json) {
    library_hash_t *library;
    func_hash_t *func_entry;
    HASH_FIND_INT(libraries, &library_key, library);
    if (library) {
        HASH_FIND_STR(library->func_hash, func_name, func_entry);
        if (func_entry && func_entry->func_ptr) {
            return func_entry->func_ptr(json);
        }
    }
    return NULL;
}

callable_func_t find_func_shared_library(int library_key, const char *func_name) {
    library_hash_t *library;
    func_hash_t *func_entry;
    HASH_FIND_INT(libraries, &library_key, library);
    if (library) {
        HASH_FIND_STR(library->func_hash, func_name, func_entry);
        if (func_entry) {
            return func_entry->func_ptr;
        }
    }
    return NULL;
}

void delete_func_shared_library(int library_key, const char *func_name) {
    library_hash_t *library;
    func_hash_t *func_entry;
    HASH_FIND_INT(libraries, &library_key, library);
    if (library) {
        HASH_FIND_STR(library->func_hash, func_name, func_entry);
        if (func_entry) {
            HASH_DEL(library->func_hash, func_entry);
            utstring_free(func_entry->func_name);
            free(func_entry);
        } else {
            fprintf(stderr, "Function '%s' not found in library %d\n", func_name, library_key);
        }
    } else {
        fprintf(stderr, "Library with key %d not found\n", library_key);
    }
}