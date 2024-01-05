//
// Created by dolphilia on 2024/01/05.
//

#ifndef RAIA_SKIA_STATIC_SK_CANVAS_H
#define RAIA_SKIA_STATIC_SK_CANVAS_H

#include <string>
#include <map>
#include "include/core/SkCanvas.h"

void static_sk_canvas_delete(const char *key);
SkCanvas *static_sk_canvas_get(const char *key);
void static_sk_canvas_set(const char *key, std::unique_ptr<SkCanvas> value);
std::unique_ptr<SkCanvas> static_sk_canvas_move(const char *key);

#endif //RAIA_SKIA_STATIC_SK_CANVAS_H
