//
// Created by dolphilia on 2024/02/01.
//

#ifndef RAIA_SKIA_STATIC_SK_ENCODER_FRAME_H
#define RAIA_SKIA_STATIC_SK_ENCODER_FRAME_H

#include <set>
#include <string>
#include <map>
#include "include/private/base/SkSpan_impl.h"
#include "include/encode/SkEncoder.h"

typedef int const_sk_encoder_frame_t;

int static_const_sk_encoder_frame_make(SkSpan<const SkEncoder::Frame> value);
extern "C" void static_const_sk_encoder_frame_delete(int key);
SkSpan<const SkEncoder::Frame> static_const_sk_encoder_frame_get(int key);
void static_const_encoder_frame_set(int key, SkSpan<const SkEncoder::Frame> value);

#endif //RAIA_SKIA_STATIC_SK_ENCODER_FRAME_H
