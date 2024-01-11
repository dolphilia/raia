//
// Created by dolphilia on 2024/01/11.
//

#include "static_sk_stroke_rec.h"

static std::map<std::string, SkStrokeRec> static_sk_stroke_rec;

void static_sk_stroke_rec_delete(const char *key) {
    static_sk_stroke_rec.erase(key);
}

SkStrokeRec static_sk_stroke_rec_get(const char *key) {
    return static_sk_stroke_rec.at(key);
}

void static_sk_stroke_rec_set(const char *key, SkStrokeRec value) {
    static_sk_stroke_rec.at(key) = value;
}