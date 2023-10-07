//
// Created by dolphilia on 2023/05/31.
//

#include "static_entrust.h"


static entrust_t *entrust;

void init_entrust() {
    entrust = (entrust_t *)malloc(sizeof(entrust_t *) * 1);
}

void free_entrust() {
    free((void *)entrust->script);
    free((void *)entrust);
}

void set_is_entrust(bool is_entrust) {
    entrust->is_entrust = is_entrust;
}

bool get_is_entrust() {
    return entrust->is_entrust;
}

void set_entrust_script(char* script) {
    if (strlen(script) != 0) {
        entrust->script = (char *) malloc(sizeof(char) * (strlen(script) + 2));
        memcpy(entrust->script, script, strlen(script));
    }
}

const char *get_entrust_script() {
    return entrust->script;
}