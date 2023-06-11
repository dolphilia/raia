//
// Created by dolphilia on 2023/05/04.
//

#include "static_func_hash.h"

static raia_func_hash_t *func_hash;

void init_func_hash(void) {
    func_hash = NULL;
}

void free_func_hash() {
    raia_func_hash_t *current_entry, *tmp;
    HASH_ITER(hh, func_hash, current_entry, tmp) {
        HASH_DEL(func_hash, current_entry);
        free(current_entry);
    }
}

void add_func_hash(const char *name, raia_func_t func) {
    raia_func_hash_t *entry = (raia_func_hash_t *)malloc(sizeof(raia_func_hash_t));
    strncpy(entry->func_name, name, sizeof(entry->func_name));
    entry->func_ret_ptr = func;
    HASH_ADD_STR(func_hash, func_name, entry);
}

raia_func_t find_func_hash(const char *name) {
    raia_func_hash_t *entry;
    HASH_FIND_STR(func_hash, name, entry);
    return entry ? entry->func_ret_ptr : NULL;
}

void delete_func_hash(const char *name) {
    raia_func_hash_t *entry;
    HASH_FIND_STR(func_hash, name, entry);
    if (entry) {
        HASH_DEL(func_hash, entry);
        free(entry);
    }
}

void add_plugin_func_hash(void *handle, const char *name) {
    raia_func_t func = (raia_func_t)raia_dlsym(handle, name);
    add_func_hash(name, func);
}

const char *call_func_hash(const char *name, const char *s) {
    raia_func_t func = find_func_hash(name);
    if (func) {
        return func(s);
    }
    return NULL;
}