//
// Created by dolphilia on 2024/01/05.
//

#ifndef RAIA_SKIA_STATIC_SK_DRAWABLE_GPU_DRAW_HANDLER_H
#define RAIA_SKIA_STATIC_SK_DRAWABLE_GPU_DRAW_HANDLER_H

#include <string>
#include <map>
#include "include/core/SkDrawable.h"

void static_sk_drawable_gpu_draw_handler_delete(const char *key);
SkDrawable::GpuDrawHandler *static_sk_drawable_gpu_draw_handler_get(const char *key);
void static_sk_drawable_gpu_draw_handler_set(const char *key, std::unique_ptr<SkDrawable::GpuDrawHandler> value);
std::unique_ptr<SkDrawable::GpuDrawHandler> static_sk_drawable_gpu_draw_handler_move(const char *key);

#endif //RAIA_SKIA_STATIC_SK_DRAWABLE_GPU_DRAW_HANDLER_H
