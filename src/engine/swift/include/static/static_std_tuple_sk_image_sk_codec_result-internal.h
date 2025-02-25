#ifndef STATIC_STD_TUPLE_SK_IMAGE_SK_CODEC_RESULT_INTERNAL_H
#define STATIC_STD_TUPLE_SK_IMAGE_SK_CODEC_RESULT_INTERNAL_H
#include <set>
#include <map>
#include <tuple>
#include <utility>
#include "include/core/SkYUVAPixmaps.h"
#include "include/core/SkImage.h"
#include "include/codec/SkCodec.h"
int static_tuple_sk_image_sk_codec_result_make(std::tuple<sk_sp<SkImage>, SkCodec::Result> value);
std::tuple<sk_sp<SkImage>, SkCodec::Result> static_tuple_sk_image_sk_codec_result_get_entity(int key);
void static_tuple_sk_image_sk_codec_result_set(int key, std::tuple<sk_sp<SkImage>, SkCodec::Result> value);
#endif // STATIC_STD_TUPLE_SK_IMAGE_SK_CODEC_RESULT_INTERNAL_H
