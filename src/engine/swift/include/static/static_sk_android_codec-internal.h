//
// Created by dolphilia on 25/01/11.
//
#ifndef STATIC_SK_ANDROID_CODEC_INTERNAL_H
#define STATIC_SK_ANDROID_CODEC_INTERNAL_H
#include "include/codec/SkAndroidCodec.h"
#include <set>
#include <map>
int static_sk_android_codec_make(std::unique_ptr<SkAndroidCodec> value);
void static_sk_android_codec_set(int key, std::unique_ptr<SkAndroidCodec> value);
std::unique_ptr<SkAndroidCodec> static_sk_android_codec_get_entity(int key);
#endif //STATIC_SK_ANDROID_CODEC_INTERNAL_H
