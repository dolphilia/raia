//
// Created by dolphilia on 2024/01/05.
//

#ifndef RAIA_SKIA_STATIC_SK_DRAWABLE_GPU_DRAW_HANDLER_H
#define RAIA_SKIA_STATIC_SK_DRAWABLE_GPU_DRAW_HANDLER_H

#include <set>
#include <string>
#include <map>
#include "include/core/SkDrawable.h"

typedef int sk_drawable_gpu_draw_handler_t;

int static_sk_drawable_gpu_draw_handler_make(std::unique_ptr<SkDrawable::GpuDrawHandler> value);
extern "C" void static_sk_drawable_gpu_draw_handler_delete(int key);
extern "C" SkDrawable::GpuDrawHandler *static_sk_drawable_gpu_draw_handler_get(int key);
void static_sk_drawable_gpu_draw_handler_set(int key, std::unique_ptr<SkDrawable::GpuDrawHandler> value);
std::unique_ptr<SkDrawable::GpuDrawHandler> static_sk_drawable_gpu_draw_handler_move(int key);

#endif //RAIA_SKIA_STATIC_SK_DRAWABLE_GPU_DRAW_HANDLER_H
