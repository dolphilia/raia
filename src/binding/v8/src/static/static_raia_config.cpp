//
// Created by dolphilia on 2023/07/26.
//

#include "static_raia_config.h"

static raia_config_t raia_config;

void init_raia_config(const char *json_file_name) {
    joint_t *joint = joint_init_in_with_file(json_file_name);
    raia_config.debug_mode = joint_get_in_bool(joint, "debug_mode");
    raia_config.es2015_mode = joint_get_in_bool(joint, "es2015_mode");
    raia_config.ts_mode = joint_get_in_bool(joint, "ts_mode");
    raia_config.preprocess = joint_get_in_bool(joint, "preprocess");
    raia_config.startup_script = joint_get_in_str(joint, "startup_script");
    raia_config.preprocess_script = joint_get_in_str(joint, "preprocess_script");
    raia_config.root_dir = joint_get_in_str(joint, "root_dir");
    joint_free(joint);
}

raia_config_t get_raia_config() {
    return raia_config;
}

void set_raia_config_startup_script(std::string startup_script) {
    raia_config.startup_script = std::move(startup_script);
}
