//
// Created by dolphilia on 2024/01/05.
//

#ifndef RAIA_SKIA_STATIC_SK_CANVAS_H
#define RAIA_SKIA_STATIC_SK_CANVAS_H

#include <set>
#include <string>
#include <map>
#include "include/core/SkCanvas.h"
#include "export_api.h"

typedef int sk_canvas_t;

extern "C" {
RAIA_API void static_sk_canvas_delete(int key);
RAIA_API SkCanvas *static_sk_canvas_get(int key);
}

int static_sk_canvas_make(std::unique_ptr<SkCanvas> value);
void static_sk_canvas_set(int key, std::unique_ptr<SkCanvas> value);
std::unique_ptr<SkCanvas> static_sk_canvas_move(int key);

#endif //RAIA_SKIA_STATIC_SK_CANVAS_H
