//
// Created by dolphilia on 2024/02/02.
//

#ifndef RAIA_SKIA_STATIC_STD_VECTOR_SK_CODEC_FRAME_INFO_H
#define RAIA_SKIA_STATIC_STD_VECTOR_SK_CODEC_FRAME_INFO_H

#include <set>
#include <string>
#include <map>
#include <vector>
#include "include/core/SkScalar.h"
#include "include/codec/SkCodec.h"
#include "export_api.h"

typedef int vector_sk_codec_frame_into_t;

extern "C" {
RAIA_API void static_vector_sk_codec_frame_into_delete(int key);
RAIA_API void static_vector_sk_codec_frame_into_pop_back(int key);
RAIA_API void static_vector_sk_codec_frame_into_erase(int key, int index);
}

int static_vector_sk_codec_frame_into_make(std::vector<SkCodec::FrameInfo> value);
SkCodec::FrameInfo static_vector_sk_codec_frame_into_get(int key, int index);
void static_vector_sk_codec_frame_into_set(int key, std::vector<SkCodec::FrameInfo> value);
void static_vector_sk_codec_frame_into_push_back(int key, SkCodec::FrameInfo value);
void static_vector_sk_codec_frame_into_insert(int key, int index, SkCodec::FrameInfo value);

#endif //RAIA_SKIA_STATIC_STD_VECTOR_SK_CODEC_FRAME_INFO_H
