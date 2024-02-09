//
// Created by dolphilia on 2024/02/02.
//

#ifndef RAIA_SKIA_SK_ANDROID_CODEC_H
#define RAIA_SKIA_SK_ANDROID_CODEC_H

#include "include/codec/SkAndroidCodec.h"
#include "../static/static_sk_color_space.h"
#include "../static/static_sk_codec.h"
#include "../static/static_sk_android_codec.h"
#include "../static/static_sk_stream.h"
#include "../static/static_sk_data.h"

extern "C" {
void SkAndroidCodec_delete(SkAndroidCodec *androidCodec);
const SkImageInfo* SkAndroidCodec_getInfo(SkAndroidCodec *androidCodec);
const skcms_ICCProfile* SkAndroidCodec_getICCProfile(SkAndroidCodec *androidCodec);
SkEncodedImageFormat SkAndroidCodec_getEncodedFormat(SkAndroidCodec *androidCodec);
SkColorType SkAndroidCodec_computeOutputColorType(SkAndroidCodec *androidCodec, SkColorType requestedColorType);
SkAlphaType SkAndroidCodec_computeOutputAlphaType(SkAndroidCodec *androidCodec, bool requestedUnpremul);
int SkAndroidCodec_computeOutputColorSpace(int static_sk_color_space_key_in, SkAndroidCodec *androidCodec, SkColorType outputColorType);
int SkAndroidCodec_computeSampleSize(SkAndroidCodec *androidCodec, SkISize* size);
SkISize SkAndroidCodec_getSampledDimensions(SkAndroidCodec *androidCodec, int sampleSize);
bool SkAndroidCodec_getSupportedSubset(SkAndroidCodec *androidCodec, SkIRect* desiredSubset);
SkISize SkAndroidCodec_getSampledSubsetDimensions(SkAndroidCodec *androidCodec, int sampleSize, const SkIRect* subset);
SkCodec::Result SkAndroidCodec_getAndroidPixels(SkAndroidCodec *androidCodec, const SkImageInfo* info, void* pixels, size_t rowBytes, const SkAndroidCodec::AndroidOptions* options);
SkCodec::Result SkAndroidCodec_getAndroidPixels_2(SkAndroidCodec *androidCodec, const SkImageInfo* info, void* pixels, size_t rowBytes);
SkCodec::Result SkAndroidCodec_getPixels(SkAndroidCodec *androidCodec, const SkImageInfo* info, void* pixels, size_t rowBytes);
SkCodec* SkAndroidCodec_codec(SkAndroidCodec *androidCodec);
bool SkAndroidCodec_getAndroidGainmap(SkAndroidCodec *androidCodec, SkGainmapInfo* outInfo, std::unique_ptr<SkStream>* outGainmapImageStream);
// static
int SkAndroidCodec_MakeFromCodec(int static_sk_codec_key_in);
int SkAndroidCodec_MakeFromStream(int static_sk_stream_key_in, SkPngChunkReader* pngChunkReader);
int SkAndroidCodec_MakeFromData(int static_sk_data_key_in, SkPngChunkReader* pngChunkReader);
}

#endif //RAIA_SKIA_SK_ANDROID_CODEC_H