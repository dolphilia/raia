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
#include "export_api.h"

extern "C" {
RAIA_API void SkCodec_delete(SkCodec* codec);
RAIA_API sk_image_info_t SkCodec_getInfo(SkCodec* codec);
RAIA_API sk_i_size_t SkCodec_dimensions(SkCodec* codec);
RAIA_API sk_i_rect_t SkCodec_bounds(SkCodec* codec);
RAIA_API const skcms_ICCProfile* SkCodec_getICCProfile(SkCodec* codec);
RAIA_API SkEncodedOrigin SkCodec_getOrigin(SkCodec* codec);
RAIA_API sk_i_size_t SkCodec_getScaledDimensions(SkCodec* codec, float desiredScale);
RAIA_API bool SkCodec_getValidSubset(SkCodec* codec, SkIRect* desiredSubset);
RAIA_API SkEncodedImageFormat SkCodec_getEncodedFormat(SkCodec* codec);
RAIA_API SkCodec::Result SkCodec_getPixels(SkCodec* codec, const SkImageInfo* info, void* pixels, size_t rowBytes, const SkCodec::Options* options);
RAIA_API SkCodec::Result SkCodec_getPixels_2(SkCodec* codec, const SkImageInfo* info, void* pixels, size_t rowBytes);
RAIA_API SkCodec::Result SkCodec_getPixels_3(SkCodec* codec, const SkPixmap* pm, const SkCodec::Options* opts);
RAIA_API int SkCodec_getImage(SkCodec* codec, const SkImageInfo* info, const SkCodec::Options* opts);
RAIA_API int SkCodec_getImage_2(SkCodec* codec);
RAIA_API bool SkCodec_queryYUVAInfo(SkCodec* codec, const SkYUVAPixmapInfo::SupportedDataTypes* supportedDataTypes, SkYUVAPixmapInfo* yuvaPixmapInfo);
RAIA_API SkCodec::Result SkCodec_getYUVAPlanes(SkCodec* codec, const SkYUVAPixmaps* yuvaPixmaps);
RAIA_API SkCodec::Result SkCodec_startIncrementalDecode(SkCodec* codec, const SkImageInfo* dstInfo, void* dst, size_t rowBytes, const SkCodec::Options* options);
RAIA_API SkCodec::Result SkCodec_startIncrementalDecode_2(SkCodec* codec, const SkImageInfo* dstInfo, void* dst, size_t rowBytes);
RAIA_API SkCodec::Result SkCodec_incrementalDecode(SkCodec* codec, int* rowsDecoded);
RAIA_API SkCodec::Result SkCodec_startScanlineDecode(SkCodec* codec, const SkImageInfo* dstInfo, const SkCodec::Options* options);
RAIA_API SkCodec::Result SkCodec_startScanlineDecode_2(SkCodec* codec, const SkImageInfo* dstInfo);
RAIA_API int SkCodec_getScanlines(SkCodec* codec, void* dst, int countLines, size_t rowBytes);
RAIA_API bool SkCodec_skipScanlines(SkCodec* codec, int countLines);
RAIA_API SkCodec::SkScanlineOrder SkCodec_getScanlineOrder(SkCodec* codec);
RAIA_API int SkCodec_nextScanline(SkCodec* codec);
RAIA_API int SkCodec_outputScanline(SkCodec* codec, int inputScanline);
RAIA_API int SkCodec_getFrameCount(SkCodec* codec);
RAIA_API bool SkCodec_getFrameInfo(SkCodec* codec, int index, SkCodec::FrameInfo* info);
RAIA_API int SkCodec_getFrameInfo_2(SkCodec* codec);
RAIA_API int SkCodec_getRepetitionCount(SkCodec* codec);
// static
RAIA_API size_t SkCodec_MinBufferedBytesNeeded();
RAIA_API const char* SkCodec_ResultToString(SkCodec::Result result);
RAIA_API sk_codec_t SkCodec_MakeFromStream(sk_stream_t stream, SkCodec::Result* result, SkPngChunkReader* pngChunkReader, SkCodec::SelectionPolicy selectionPolicy);
RAIA_API sk_codec_t SkCodec_MakeFromData(sk_stream_t stream, SkPngChunkReader* pngChunkReader);
//void SkCodec_Register(bool (*peek)(const void*, size_t), std::unique_ptr<SkCodec> (*make)(std::unique_ptr<SkStream>, SkCodec::Result*));
}

#endif //RAIA_SKIA_SK_CODEC_H
