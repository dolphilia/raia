#ifndef STATIC_SK_ENCODER_FRAME_INTERNAL_H
#define STATIC_SK_ENCODER_FRAME_INTERNAL_H
#include <set>
#include <map>
#include "include/private/base/SkSpan_impl.h"
#include "include/encode/SkEncoder.h"
int static_const_sk_encoder_frame_make(SkSpan<const SkEncoder::Frame> value);
SkSpan<const SkEncoder::Frame> static_const_sk_encoder_frame_get_entity(int key);
void static_const_encoder_frame_set(int key, SkSpan<const SkEncoder::Frame> value);
#endif // STATIC_SK_ENCODER_FRAME_INTERNAL_H
