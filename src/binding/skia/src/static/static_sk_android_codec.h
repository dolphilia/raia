//
// Created by dolphilia on 2024/02/02.
//

#ifndef RAIA_SKIA_STATIC_SK_ANDROID_CODEC_H
#define RAIA_SKIA_STATIC_SK_ANDROID_CODEC_H

#include <set>
#include <string>
#include <map>
#include "include/codec/SkAndroidCodec.h"

typedef int sk_android_codec_t;

int static_sk_android_codec_make(std::unique_ptr<SkAndroidCodec> value);
extern "C" void static_sk_android_codec_delete(int key);
extern "C" SkAndroidCodec *static_sk_android_codec_get(int key);
void static_sk_android_codec_set(int key, std::unique_ptr<SkAndroidCodec> value);
std::unique_ptr<SkAndroidCodec> static_sk_android_codec_move(int key);

#endif //RAIA_SKIA_STATIC_SK_ANDROID_CODEC_H
