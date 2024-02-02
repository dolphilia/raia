//
// Created by dolphilia on 2024/02/02.
//

#include "sk_android_codec.h"

extern "C" {

void SkAndroidCodec_delete(SkAndroidCodec *androidCodec) {
    delete androidCodec;
}

const SkImageInfo* SkAndroidCodec_getInfo(SkAndroidCodec *androidCodec) {
    return &androidCodec->getInfo();
}

const skcms_ICCProfile* SkAndroidCodec_getICCProfile(SkAndroidCodec *androidCodec) {
    return androidCodec->getICCProfile();
}

SkEncodedImageFormat SkAndroidCodec_getEncodedFormat(SkAndroidCodec *androidCodec) {
    return androidCodec->getEncodedFormat();
}

SkColorType SkAndroidCodec_computeOutputColorType(SkAndroidCodec *androidCodec, SkColorType requestedColorType) {
    return androidCodec->computeOutputColorType(requestedColorType);
}

SkAlphaType SkAndroidCodec_computeOutputAlphaType(SkAndroidCodec *androidCodec, bool requestedUnpremul) {
    return androidCodec->computeOutputAlphaType(requestedUnpremul);
}

int SkAndroidCodec_computeOutputColorSpace(int static_sk_color_space_key_in, SkAndroidCodec *androidCodec, SkColorType outputColorType) {
    return static_sk_color_space_make(androidCodec->computeOutputColorSpace(outputColorType, static_sk_color_space_move(static_sk_color_space_key_in)));
}

int SkAndroidCodec_computeSampleSize(SkAndroidCodec *androidCodec, SkISize* size) {
    return androidCodec->computeSampleSize(size);
}

SkISize SkAndroidCodec_getSampledDimensions(SkAndroidCodec *androidCodec, int sampleSize) {
    return androidCodec->getSampledDimensions(sampleSize);
}

bool SkAndroidCodec_getSupportedSubset(SkAndroidCodec *androidCodec, SkIRect* desiredSubset) {
    return androidCodec->getSupportedSubset(desiredSubset);
}

SkISize SkAndroidCodec_getSampledSubsetDimensions(SkAndroidCodec *androidCodec, int sampleSize, const SkIRect* subset) {
    return androidCodec->getSampledSubsetDimensions(sampleSize, *subset);
}

SkCodec::Result SkAndroidCodec_getAndroidPixels(SkAndroidCodec *androidCodec, const SkImageInfo* info, void* pixels, size_t rowBytes, const SkAndroidCodec::AndroidOptions* options) {
    return androidCodec->getAndroidPixels(*info, pixels, rowBytes, options);
}

SkCodec::Result SkAndroidCodec_getAndroidPixels_2(SkAndroidCodec *androidCodec, const SkImageInfo* info, void* pixels, size_t rowBytes) {
    return androidCodec->getAndroidPixels(*info, pixels, rowBytes);
}

SkCodec::Result SkAndroidCodec_getPixels(SkAndroidCodec *androidCodec, const SkImageInfo* info, void* pixels, size_t rowBytes) {
    return androidCodec->getPixels(*info, pixels, rowBytes);
}

SkCodec* SkAndroidCodec_codec(SkAndroidCodec *androidCodec) {
    return androidCodec->codec();
}

bool SkAndroidCodec_getAndroidGainmap(SkAndroidCodec *androidCodec, SkGainmapInfo* outInfo, std::unique_ptr<SkStream>* outGainmapImageStream) {
    return androidCodec->getAndroidGainmap(outInfo, outGainmapImageStream);
}

// static

int SkAndroidCodec_MakeFromCodec(int static_sk_codec_key_in) {
    return static_sk_android_codec_make(SkAndroidCodec::MakeFromCodec(static_sk_codec_move(static_sk_codec_key_in)));
}

int SkAndroidCodec_MakeFromStream(int static_sk_stream_key_in, SkPngChunkReader* pngChunkReader) {
    return static_sk_android_codec_make(SkAndroidCodec::MakeFromStream(static_sk_stream_move(static_sk_stream_key_in), pngChunkReader));
}

int SkAndroidCodec_MakeFromData(int static_sk_data_key_in, SkPngChunkReader* pngChunkReader) {
    return static_sk_android_codec_make(SkAndroidCodec::MakeFromData(static_sk_data_move(static_sk_data_key_in), pngChunkReader));
}

}