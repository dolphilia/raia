//
// Created by dolphilia on 2023/05/31.
//

#ifndef RAIA_DUKTAPE_STATIC_ENTRUST_H
#define RAIA_DUKTAPE_STATIC_ENTRUST_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct entrust_t {
    bool is_entrust;
    char *script;
} entrust_t ;

void init_entrust(void);
void free_entrust(void);
void set_is_entrust(bool is_entrust);
bool get_is_entrust(void);
void set_entrust_script(char* script);
const char *get_entrust_script(void);

#endif //RAIA_DUKTAPE_STATIC_ENTRUST_H
