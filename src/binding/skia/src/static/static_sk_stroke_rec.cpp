//
// Created by dolphilia on 2024/01/11.
//

#include "static_sk_stroke_rec.h"

static std::map<int , SkStrokeRec> static_sk_stroke_rec;

void static_sk_stroke_rec_delete(int key) {
    static_sk_stroke_rec.erase(key);
}

SkStrokeRec static_sk_stroke_rec_get(int key) {
    return static_sk_stroke_rec.at(key);
}

void static_sk_stroke_rec_set(int key, SkStrokeRec value) {
    static_sk_stroke_rec.at(key) = value;
}