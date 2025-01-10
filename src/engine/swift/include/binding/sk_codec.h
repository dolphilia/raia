//
// Created by dolphilia on 2024/02/02.
//

#ifndef RAIA_SKIA_SK_CODEC_H
#define RAIA_SKIA_SK_CODEC_H

#include "include/codec/SkCodec.h"
#include "../static/static_sk_data.h"
#include "../static/static_sk_stream.h"
#include "../static/static_sk_codec.h"
#include "../static/static_sk_image_info.h"
#include "../static/static_sk_i_rect.h"
#include "../static/static_std_tuple_sk_image_sk_codec_result.h"
#include "../static/static_std_vector_sk_codec_frame_info.h"
#include "../static/static_sk_i_size.h"

extern "C" {
void SkCodec_delete(SkCodec* codec);
sk_image_info_t SkCodec_getInfo(SkCodec* codec);
sk_i_size_t SkCodec_dimensions(SkCodec* codec);
sk_i_rect_t SkCodec_bounds(SkCodec* codec);
const skcms_ICCProfile* SkCodec_getICCProfile(SkCodec* codec);
SkEncodedOrigin SkCodec_getOrigin(SkCodec* codec);
sk_i_size_t SkCodec_getScaledDimensions(SkCodec* codec, float desiredScale);
bool SkCodec_getValidSubset(SkCodec* codec, SkIRect* desiredSubset);
SkEncodedImageFormat SkCodec_getEncodedFormat(SkCodec* codec);
SkCodec::Result SkCodec_getPixels(SkCodec* codec, const SkImageInfo* info, void* pixels, size_t rowBytes, const SkCodec::Options* options);
SkCodec::Result SkCodec_getPixels_2(SkCodec* codec, const SkImageInfo* info, void* pixels, size_t rowBytes);
SkCodec::Result SkCodec_getPixels_3(SkCodec* codec, const SkPixmap* pm, const SkCodec::Options* opts);
int SkCodec_getImage(SkCodec* codec, const SkImageInfo* info, const SkCodec::Options* opts);
int SkCodec_getImage_2(SkCodec* codec);
bool SkCodec_queryYUVAInfo(SkCodec* codec, const SkYUVAPixmapInfo::SupportedDataTypes* supportedDataTypes, SkYUVAPixmapInfo* yuvaPixmapInfo);
SkCodec::Result SkCodec_getYUVAPlanes(SkCodec* codec, const SkYUVAPixmaps* yuvaPixmaps);
SkCodec::Result SkCodec_startIncrementalDecode(SkCodec* codec, const SkImageInfo* dstInfo, void* dst, size_t rowBytes, const SkCodec::Options* options);
SkCodec::Result SkCodec_startIncrementalDecode_2(SkCodec* codec, const SkImageInfo* dstInfo, void* dst, size_t rowBytes);
SkCodec::Result SkCodec_incrementalDecode(SkCodec* codec, int* rowsDecoded);
SkCodec::Result SkCodec_startScanlineDecode(SkCodec* codec, const SkImageInfo* dstInfo, const SkCodec::Options* options);
SkCodec::Result SkCodec_startScanlineDecode_2(SkCodec* codec, const SkImageInfo* dstInfo);
int SkCodec_getScanlines(SkCodec* codec, void* dst, int countLines, size_t rowBytes);
bool SkCodec_skipScanlines(SkCodec* codec, int countLines);
SkCodec::SkScanlineOrder SkCodec_getScanlineOrder(SkCodec* codec);
int SkCodec_nextScanline(SkCodec* codec);
int SkCodec_outputScanline(SkCodec* codec, int inputScanline);
int SkCodec_getFrameCount(SkCodec* codec);
bool SkCodec_getFrameInfo(SkCodec* codec, int index, SkCodec::FrameInfo* info);
int SkCodec_getFrameInfo_2(SkCodec* codec);
int SkCodec_getRepetitionCount(SkCodec* codec);
// static
size_t SkCodec_MinBufferedBytesNeeded();
const char* SkCodec_ResultToString(SkCodec::Result result);
sk_codec_t SkCodec_MakeFromStream(sk_stream_t stream, SkCodec::Result* result, SkPngChunkReader* pngChunkReader, SkCodec::SelectionPolicy selectionPolicy);
sk_codec_t SkCodec_MakeFromData(sk_stream_t stream, SkPngChunkReader* pngChunkReader);
//void SkCodec_Register(bool (*peek)(const void*, size_t), std::unique_ptr<SkCodec> (*make)(std::unique_ptr<SkStream>, SkCodec::Result*));
}

#endif //RAIA_SKIA_SK_CODEC_H
