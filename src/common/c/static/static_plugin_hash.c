//
// Created by dolphilia on 2022/12/10.
//

#include "static_plugin_hash.h"

static raia_plugin_hash_t *plugin_hash;

void init_plugin_hash(void) {
    plugin_hash = NULL;
}

void free_plugin_hash() {
    raia_plugin_hash_t *current_entry, *tmp;
    HASH_ITER(hh, plugin_hash, current_entry, tmp) {
        raia_dlclose(current_entry->handle);
        HASH_DEL(plugin_hash, current_entry);
        free(current_entry);
    }
}

void *add_plugin_hash(const char *name) {
#ifdef __LINUX__
    char path[500];
    sprintf(path, "./%s\0", name);
    void * handle = raia_dlopen(path);
#else
    void *handle = raia_dlopen(name);
#endif
    raia_plugin_hash_t *entry = (raia_plugin_hash_t *)malloc(sizeof(raia_plugin_hash_t));
    strncpy(entry->name, name, sizeof(entry->name));
    entry->handle = handle;
    HASH_ADD_STR(plugin_hash, name, entry);
    return handle;
}

void *find_plugin_hash(const char *name) {
    raia_plugin_hash_t *entry;
    HASH_FIND_STR(plugin_hash, name, entry);
    return entry ? entry->handle : NULL;
}

void delete_plugin_hash(const char *name) {
    raia_plugin_hash_t *entry;
    HASH_FIND_STR(plugin_hash, name, entry);
    if (entry) {
        raia_dlclose(entry->handle);
        HASH_DEL(plugin_hash, entry);
        free(entry);
    }
}