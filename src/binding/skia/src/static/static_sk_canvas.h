//
// Created by dolphilia on 2024/01/05.
//

#ifndef RAIA_SKIA_STATIC_SK_CANVAS_H
#define RAIA_SKIA_STATIC_SK_CANVAS_H

#include <set>
#include <string>
#include <map>
#include "include/core/SkCanvas.h"

typedef int sk_canvas_t;

int static_sk_canvas_make(std::unique_ptr<SkCanvas> value);
extern "C" void static_sk_canvas_delete(int key);
extern "C" SkCanvas *static_sk_canvas_get(int key);
void static_sk_canvas_set(int key, std::unique_ptr<SkCanvas> value);
std::unique_ptr<SkCanvas> static_sk_canvas_move(int key);

#endif //RAIA_SKIA_STATIC_SK_CANVAS_H
