//
// Created by dolphilia on 2024/02/02.
//

#include "static_sk_codecs_decoder.h"
#include "static_sk_codecs_decoder-internal.h"

static std::set<int> static_sk_codecs_decoder_available_keys;
static std::map<int , SkCodecs::Decoder> static_sk_codecs_decoder;
static int static_sk_codecs_decoder_index = 0;

int static_sk_codecs_decoder_make(SkCodecs::Decoder value) {
    int key;
    if (!static_sk_codecs_decoder_available_keys.empty()) {
        auto it = static_sk_codecs_decoder_available_keys.begin();
        key = *it;
        static_sk_codecs_decoder_available_keys.erase(it);
    } else {
        key = static_sk_codecs_decoder_index++;
    }
    static_sk_codecs_decoder[key] = std::move(value);
    return key;
}

void static_sk_codecs_decoder_delete(int key) {
    static_sk_codecs_decoder.erase(key);
    static_sk_codecs_decoder_available_keys.insert(key);
}

SkCodecs::Decoder static_sk_codecs_decoder_get(int key) {
    return static_sk_codecs_decoder[key];
}

void * static_sk_codecs_decoder_get_ptr(int key) { // -> SkCodecs::Decoder *
    return &static_sk_codecs_decoder[key];
}

void static_sk_codecs_decoder_set(int key, SkCodecs::Decoder value) {
    static_sk_codecs_decoder[key] = std::move(value);
}
