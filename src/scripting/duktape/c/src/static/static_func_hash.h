//
// Created by dolphilia on 2023/05/04.
//

#ifndef RAIA_CORE_STATIC_FUNC_HASH_H
#define RAIA_CORE_STATIC_FUNC_HASH_H

#include "../uthash/uthash.h"
#include "static_plugin_hash.h"

/**
 * @param json C string written in json format.
 * @param data Binary data
 * @param size Binary data size
 * @return Returns a C string in json format.
 */
typedef const char*(*raia_func_t)(const char *s);

typedef struct raia_func_hash_t {
    char func_name[50];
    raia_func_t func_ret_ptr;
    UT_hash_handle hh;
} raia_func_hash_t;

void init_func_hash();
void free_func_hash();
void add_func_hash(const char *name, raia_func_t func);
raia_func_t find_func_hash(const char *name);
void delete_func_hash(const char *name);
void add_plugin_func_hash(void *handle, const char *name);
const char*call_func_hash(const char *name, const char *s);

#endif //RAIA_CORE_STATIC_FUNC_HASH_H
