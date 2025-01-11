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
#include "../static/static_sk_i_size.h"
#include "export_api.h"

extern "C" {
RAIA_API void SkAndroidCodec_delete(SkAndroidCodec *androidCodec);
RAIA_API const SkImageInfo* SkAndroidCodec_getInfo(SkAndroidCodec *androidCodec);
RAIA_API const skcms_ICCProfile* SkAndroidCodec_getICCProfile(SkAndroidCodec *androidCodec);
RAIA_API SkEncodedImageFormat SkAndroidCodec_getEncodedFormat(SkAndroidCodec *androidCodec);
RAIA_API SkColorType SkAndroidCodec_computeOutputColorType(SkAndroidCodec *androidCodec, SkColorType requestedColorType);
RAIA_API SkAlphaType SkAndroidCodec_computeOutputAlphaType(SkAndroidCodec *androidCodec, bool requestedUnpremul);
RAIA_API sk_color_space_t SkAndroidCodec_computeOutputColorSpace(SkAndroidCodec *androidCodec, SkColorType outputColorType, sk_color_space_t prefColorSpace);
RAIA_API int SkAndroidCodec_computeSampleSize(SkAndroidCodec *androidCodec, SkISize* size);
RAIA_API sk_i_size_t SkAndroidCodec_getSampledDimensions(SkAndroidCodec *androidCodec, int sampleSize);
RAIA_API bool SkAndroidCodec_getSupportedSubset(SkAndroidCodec *androidCodec, SkIRect* desiredSubset);
RAIA_API sk_i_size_t SkAndroidCodec_getSampledSubsetDimensions(SkAndroidCodec *androidCodec, int sampleSize, const SkIRect* subset);
RAIA_API SkCodec::Result SkAndroidCodec_getAndroidPixels(SkAndroidCodec *androidCodec, const SkImageInfo* info, void* pixels, size_t rowBytes, const SkAndroidCodec::AndroidOptions* options);
RAIA_API SkCodec::Result SkAndroidCodec_getAndroidPixels_2(SkAndroidCodec *androidCodec, const SkImageInfo* info, void* pixels, size_t rowBytes);
RAIA_API SkCodec::Result SkAndroidCodec_getPixels(SkAndroidCodec *androidCodec, const SkImageInfo* info, void* pixels, size_t rowBytes);
RAIA_API SkCodec* SkAndroidCodec_codec(SkAndroidCodec *androidCodec);
RAIA_API bool SkAndroidCodec_getAndroidGainmap(SkAndroidCodec *androidCodec, SkGainmapInfo* outInfo, std::unique_ptr<SkStream>* outGainmapImageStream);
// static
RAIA_API sk_android_codec_t SkAndroidCodec_MakeFromCodec(sk_codec_t codec);
RAIA_API sk_android_codec_t SkAndroidCodec_MakeFromStream(sk_codec_t codec, SkPngChunkReader* pngChunkReader);
RAIA_API sk_android_codec_t SkAndroidCodec_MakeFromData(sk_codec_t codec, SkPngChunkReader* pngChunkReader);
}

#endif //RAIA_SKIA_SK_ANDROID_CODEC_H
