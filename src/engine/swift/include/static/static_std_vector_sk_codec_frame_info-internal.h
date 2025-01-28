#ifndef STATIC_STD_VECTOR_SK_CODEC_FRAME_INFO_INTERNAL_H
#define STATIC_STD_VECTOR_SK_CODEC_FRAME_INFO_INTERNAL_H
#include <set>
#include <map>
#include <vector>
#include "include/core/SkScalar.h"
#include "include/codec/SkCodec.h"
int static_vector_sk_codec_frame_into_make(std::vector<SkCodec::FrameInfo> value);
SkCodec::FrameInfo static_vector_sk_codec_frame_into_get(int key, int index);
void static_vector_sk_codec_frame_into_set(int key, std::vector<SkCodec::FrameInfo> value);
void static_vector_sk_codec_frame_into_push_back(int key, SkCodec::FrameInfo value);
void static_vector_sk_codec_frame_into_insert(int key, int index, SkCodec::FrameInfo value);
#endif // STATIC_STD_VECTOR_SK_CODEC_FRAME_INFO_INTERNAL_H
