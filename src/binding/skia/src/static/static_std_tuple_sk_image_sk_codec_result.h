//
// Created by dolphilia on 2024/02/02.
//

#ifndef RAIA_SKIA_STATIC_STD_TUPLE_SK_IMAGE_SK_CODEC_RESULT_H
#define RAIA_SKIA_STATIC_STD_TUPLE_SK_IMAGE_SK_CODEC_RESULT_H

#include <set>
#include <string>
#include <map>
#include <tuple>
#include <utility>
#include "include/core/SkYUVAPixmaps.h"
#include "include/core/SkImage.h"
#include "include/codec/SkCodec.h"

typedef int tuple_sk_image_sk_codec_result_t;

extern "C" void static_tuple_sk_image_sk_codec_result_delete(int key);
int static_tuple_sk_image_sk_codec_result_make(std::tuple<sk_sp<SkImage>, SkCodec::Result> value);
std::tuple<sk_sp<SkImage>, SkCodec::Result> static_tuple_sk_image_sk_codec_result_get(int key, int index);
void static_tuple_sk_image_sk_codec_result_set(int key, std::tuple<sk_sp<SkImage>, SkCodec::Result> value);

#endif //RAIA_SKIA_STATIC_STD_TUPLE_SK_IMAGE_SK_CODEC_RESULT_H
