//
// Created by dolphilia on 2024/01/11.
//

#include "static_sk_stroke_rec.h"

static std::set<int> static_sk_stroke_rec_available_keys;
static std::map<int , SkStrokeRec> static_sk_stroke_rec;
static int static_sk_stroke_rec_index = 0;

int static_sk_stroke_rec_make(SkStrokeRec value) {
    int key;
    if (!static_sk_stroke_rec_available_keys.empty()) {
        auto it = static_sk_stroke_rec_available_keys.begin();
        key = *it;
        static_sk_stroke_rec_available_keys.erase(it);
    } else {
        key = static_sk_stroke_rec_index++;
    }
    static_sk_stroke_rec.at(key) = value;
    return key;
}

void static_sk_stroke_rec_delete(int key) {
    static_sk_stroke_rec.erase(key);
    static_sk_stroke_rec_available_keys.insert(key);
}

SkStrokeRec static_sk_stroke_rec_get(int key) {
    return static_sk_stroke_rec.at(key);
}

void static_sk_stroke_rec_set(int key, SkStrokeRec value) {
    static_sk_stroke_rec.at(key) = value;
}