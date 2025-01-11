//
// Created by dolphilia on 2024/02/02.
//

#ifndef RAIA_SKIA_STATIC_SK_ANDROID_CODEC_H
#define RAIA_SKIA_STATIC_SK_ANDROID_CODEC_H

#include <set>
#include <string>
#include <map>
#include "include/codec/SkAndroidCodec.h"
#include "export_api.h"

typedef int sk_android_codec_t;

extern "C" {
RAIA_API void static_sk_android_codec_delete(int key);
RAIA_API SkAndroidCodec *static_sk_android_codec_get(int key);
}

int static_sk_android_codec_make(std::unique_ptr<SkAndroidCodec> value);
void static_sk_android_codec_set(int key, std::unique_ptr<SkAndroidCodec> value);
std::unique_ptr<SkAndroidCodec> static_sk_android_codec_move(int key);

#endif //RAIA_SKIA_STATIC_SK_ANDROID_CODEC_H
