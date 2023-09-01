//
// Created by dolphilia on 2023/07/26.
//

#ifndef RAIA_V8_STATIC_RAIA_CONFIG_H
#define RAIA_V8_STATIC_RAIA_CONFIG_H

#include <iostream>
#include "../wrapper/wrapper_yyjson.h"

typedef struct {
    std::string root_dir;
    std::string startup_script;
    std::string preprocess_script;
    int debug_mode;
    int ts_mode;
    int es2015_mode;
    int preprocess;
} raia_config_t;

void init_raia_config(const char *json_file_name);
raia_config_t get_raia_config();
void set_raia_config_startup_script(std::string startup_script);

#endif //RAIA_V8_STATIC_RAIA_CONFIG_H
