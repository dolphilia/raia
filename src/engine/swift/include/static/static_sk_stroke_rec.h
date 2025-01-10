//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_STATIC_SK_STROKE_REC_H
#define RAIA_SKIA_STATIC_SK_STROKE_REC_H

#include <set>
#include <string>
#include <map>
#include "include/core/SkStrokeRec.h"

typedef int sk_stroke_rec_t;

int static_sk_stroke_rec_make(SkStrokeRec value);
extern "C" void static_sk_stroke_rec_delete(int key);
SkStrokeRec static_sk_stroke_rec_get(int key);
void static_sk_stroke_rec_set(int key, SkStrokeRec value);

#endif //RAIA_SKIA_STATIC_SK_STROKE_REC_H
