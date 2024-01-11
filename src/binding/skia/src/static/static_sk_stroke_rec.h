//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_STATIC_SK_STROKE_REC_H
#define RAIA_SKIA_STATIC_SK_STROKE_REC_H

#include <string>
#include <map>
#include "include/core/SkStrokeRec.h"

void static_sk_stroke_rec_delete(const char *key);
SkStrokeRec static_sk_stroke_rec_get(const char *key);
void static_sk_stroke_rec_set(const char *key, SkStrokeRec value);

#endif //RAIA_SKIA_STATIC_SK_STROKE_REC_H
