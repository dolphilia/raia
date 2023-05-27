//
// Created by dolphilia on 2023/05/04.
//

#ifndef RAIA_CORE_STATIC_FUNC_HASH_H
#define RAIA_CORE_STATIC_FUNC_HASH_H

#include "../uthash/uthash.h"
#include "static_plugin_loader.h"

/**
 * @param json C string written in json format.
 * @param data Binary data
 * @param size Binary data size
 * @return Returns a C string in json format.
 */
typedef void *(*raia_func_t)(const char *src, void *data, int size);

typedef struct raia_func_hash_t {
    char func_name[50];
    raia_func_t func_ret_ptr;
    UT_hash_handle hh;
} raia_func_hash_t;

void init_func_hash();
void free_func_hash();
void add_func_hash(const char *func_name, raia_func_t func_ptr);
raia_func_t find_func_hash(const char *func_name);
void delete_func_hash(const char *func_name);
void add_plugin_func_hash(const char *func_name);
void *call_func_hash(const char *func_name, const char *src, void *data, int size);

#endif //RAIA_CORE_STATIC_FUNC_HASH_H
