//
// Created by dolphilia on 2023/05/04.
//

#include "static_func_hash.h"

static raia_func_hash_t *hash_table;

void init_func_hash(void) {
    hash_table = NULL;
}

void free_func_hash() {
    raia_func_hash_t *current_entry, *tmp;
    HASH_ITER(hh, hash_table, current_entry, tmp) {
        HASH_DEL(hash_table, current_entry);
        free(current_entry);
    }
}

void add_func_hash(const char *func_name, raia_func_t func_ptr) {
    raia_func_hash_t *entry = (raia_func_hash_t *)malloc(sizeof(raia_func_hash_t));
    strncpy(entry->func_name, func_name, sizeof(entry->func_name));
    entry->func_ret_ptr = func_ptr;
    HASH_ADD_STR(hash_table, func_name, entry);
}

raia_func_t find_func_hash(const char *func_name) {
    raia_func_hash_t *entry;
    HASH_FIND_STR(hash_table, func_name, entry);
    return entry ? entry->func_ret_ptr : NULL;
}

void delete_func_hash(const char *func_name) {
    raia_func_hash_t *entry;
    HASH_FIND_STR(hash_table, func_name, entry);
    if (entry) {
        HASH_DEL(hash_table, entry);
        free(entry);
    }
}

void add_plugin_func_hash(const char *func_name) {
    void *handle = get_plugin_handle();
    raia_func_t func_ptr = (raia_func_t)raia_dlsym(handle, func_name);
    add_func_hash(func_name, func_ptr);
}

void *call_func_hash(const char *func_name, const char *src, void *data, int size) {
    raia_func_t func_ptr = find_func_hash(func_name);
    if (func_ptr) {
        return func_ptr(src, data, size);
    }
    return NULL;
}