//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_STATIC_SK_STROKE_REC_H
#define RAIA_SKIA_STATIC_SK_STROKE_REC_H

#include <set>
#include <string>
#include <map>
#include "include/core/SkStrokeRec.h"
#include "export_api.h"

typedef int sk_stroke_rec_t;

extern "C" {
RAIA_API void static_sk_stroke_rec_delete(int key);
RAIA_API SkStrokeRec * static_sk_stroke_rec_get_ptr(int key);
}

int static_sk_stroke_rec_make(SkStrokeRec value);
SkStrokeRec static_sk_stroke_rec_get(int key);
void static_sk_stroke_rec_set(int key, SkStrokeRec value);

#endif //RAIA_SKIA_STATIC_SK_STROKE_REC_H
