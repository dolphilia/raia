//
// Created by dolphilia on 2024/04/08.
//

#ifndef RAIA_SKIA_STATIC_SK_SHAPER_RUN_HANDLER_BUFFER_H
#define RAIA_SKIA_STATIC_SK_SHAPER_RUN_HANDLER_BUFFER_H

#include <set>
#include <map>
#include "modules/skshaper/include/SkShaper.h"

typedef int sk_shaper_run_handler_buffer_t;

int static_sk_shaper_run_handler_buffer_make(SkShaper::RunHandler::Buffer value);
extern "C" void static_sk_shaper_run_handler_buffer_delete(int key);
SkShaper::RunHandler::Buffer static_sk_shaper_run_handler_buffer_get(int key);
void static_sk_shaper_run_handler_buffer_set(int key, SkShaper::RunHandler::Buffer value);

#endif //RAIA_SKIA_STATIC_SK_SHAPER_RUN_HANDLER_BUFFER_H
