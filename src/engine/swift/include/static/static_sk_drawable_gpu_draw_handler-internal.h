#ifndef STATIC_SK_DRAWABLE_GPU_DRAW_HANDLER_INTERNAL_H
#define STATIC_SK_DRAWABLE_GPU_DRAW_HANDLER_INTERNAL_H
#include <set>
#include <map>
#include "include/core/SkDrawable.h"
int static_sk_drawable_gpu_draw_handler_make(std::unique_ptr<SkDrawable::GpuDrawHandler> value);
void static_sk_drawable_gpu_draw_handler_set(int key, std::unique_ptr<SkDrawable::GpuDrawHandler> value);
std::unique_ptr<SkDrawable::GpuDrawHandler> static_sk_drawable_gpu_draw_handler_get_entity(int key);
#endif // STATIC_SK_DRAWABLE_GPU_DRAW_HANDLER_INTERNAL_H
