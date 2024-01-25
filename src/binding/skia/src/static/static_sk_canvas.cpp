//
// Created by dolphilia on 2024/01/05.
//

#include "static_sk_canvas.h"

static std::map<int , std::unique_ptr<SkCanvas>> static_sk_canvas;

void static_sk_canvas_delete(int key) {
    static_sk_canvas[key].reset();
    static_sk_canvas.erase(key);
}

SkCanvas *static_sk_canvas_get(int key) {
    return static_sk_canvas[key].get();
}

void static_sk_canvas_set(int key, std::unique_ptr<SkCanvas> value) {
    static_sk_canvas[key] = std::move(value);
}

std::unique_ptr<SkCanvas> static_sk_canvas_move(int key) {
    return std::move(static_sk_canvas[key]);
}