//
// Created by dolphilia on 2024/01/05.
//

#include "static_sk_drawable_gpu_draw_handler.h"

static std::map<std::string, std::unique_ptr<SkDrawable::GpuDrawHandler>> static_sk_drawable_gpu_draw_handler;

void static_sk_drawable_gpu_draw_handler_delete(const char *key) {
    static_sk_drawable_gpu_draw_handler[key].reset();
    static_sk_drawable_gpu_draw_handler.erase(key);
}

SkDrawable::GpuDrawHandler *static_sk_drawable_gpu_draw_handler_get(const char *key) {
    return static_sk_drawable_gpu_draw_handler[key].get();
}

void static_sk_drawable_gpu_draw_handler_set(const char *key, std::unique_ptr<SkDrawable::GpuDrawHandler> value) {
    static_sk_drawable_gpu_draw_handler[key] = std::move(value);
}

std::unique_ptr<SkDrawable::GpuDrawHandler> static_sk_drawable_gpu_draw_handler_move(const char *key) {
    return std::move(static_sk_drawable_gpu_draw_handler[key]);
}