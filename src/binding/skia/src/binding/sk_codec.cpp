//
// Created by dolphilia on 2024/02/02.
//

#include "sk_codec.h"

extern "C" {

void SkCodec_delete(SkCodec* codec) {
    delete codec;
}

sk_image_info_t SkCodec_getInfo(SkCodec* codec) {
    return static_sk_image_info_make(codec->getInfo());
}

sk_i_size_t SkCodec_dimensions(SkCodec* codec) {
    return static_sk_i_size_make(codec->dimensions());
}

sk_i_rect_t SkCodec_bounds(SkCodec* codec) {
    return static_sk_i_rect_make(codec->bounds());
}

const skcms_ICCProfile* SkCodec_getICCProfile(SkCodec* codec) {
    return codec->getICCProfile();
}

SkEncodedOrigin SkCodec_getOrigin(SkCodec* codec) {
    return codec->getOrigin();
}

sk_i_size_t SkCodec_getScaledDimensions(SkCodec* codec, float desiredScale) {
    return static_sk_i_size_make(codec->getScaledDimensions(desiredScale));
}

bool SkCodec_getValidSubset(SkCodec* codec, SkIRect* desiredSubset) {
    return codec->getValidSubset(desiredSubset);
}

SkEncodedImageFormat SkCodec_getEncodedFormat(SkCodec* codec) {
    return codec->getEncodedFormat();
}

SkCodec::Result SkCodec_getPixels(SkCodec* codec, const SkImageInfo* info, void* pixels, size_t rowBytes, const SkCodec::Options* options) {
    return codec->getPixels(*info, pixels, rowBytes, options);
}

SkCodec::Result SkCodec_getPixels_2(SkCodec* codec, const SkImageInfo* info, void* pixels, size_t rowBytes) {
    return codec->getPixels(*info, pixels, rowBytes);
}

SkCodec::Result SkCodec_getPixels_3(SkCodec* codec, const SkPixmap* pm, const SkCodec::Options* opts) {
    return codec->getPixels(*pm, opts);
}

tuple_sk_image_sk_codec_result_t SkCodec_getImage(SkCodec* codec, const SkImageInfo* info, const SkCodec::Options* opts) {
    return static_tuple_sk_image_sk_codec_result_make(codec->getImage(*info, opts));
}

tuple_sk_image_sk_codec_result_t SkCodec_getImage_2(SkCodec* codec) {
    return static_tuple_sk_image_sk_codec_result_make(codec->getImage());
}

bool SkCodec_queryYUVAInfo(SkCodec* codec, const SkYUVAPixmapInfo::SupportedDataTypes* supportedDataTypes, SkYUVAPixmapInfo* yuvaPixmapInfo) {
    return codec->queryYUVAInfo(*supportedDataTypes, yuvaPixmapInfo);
}

SkCodec::Result SkCodec_getYUVAPlanes(SkCodec* codec, const SkYUVAPixmaps* yuvaPixmaps) {
    return codec->getYUVAPlanes(*yuvaPixmaps);
}

SkCodec::Result SkCodec_startIncrementalDecode(SkCodec* codec, const SkImageInfo* dstInfo, void* dst, size_t rowBytes, const SkCodec::Options* options) {
    return codec->startIncrementalDecode(*dstInfo, dst, rowBytes, options);
}

SkCodec::Result SkCodec_startIncrementalDecode_2(SkCodec* codec, const SkImageInfo* dstInfo, void* dst, size_t rowBytes) {
    return codec->startIncrementalDecode(*dstInfo, dst, rowBytes);
}

SkCodec::Result SkCodec_incrementalDecode(SkCodec* codec, int* rowsDecoded) {
    return codec->incrementalDecode(rowsDecoded);
}

SkCodec::Result SkCodec_startScanlineDecode(SkCodec* codec, const SkImageInfo* dstInfo, const SkCodec::Options* options) {
    return codec->startScanlineDecode(*dstInfo, options);
}

SkCodec::Result SkCodec_startScanlineDecode_2(SkCodec* codec, const SkImageInfo* dstInfo) {
    return codec->startScanlineDecode(*dstInfo);
}

int SkCodec_getScanlines(SkCodec* codec, void* dst, int countLines, size_t rowBytes) {
    return codec->getScanlines(dst, countLines, rowBytes);
}

bool SkCodec_skipScanlines(SkCodec* codec, int countLines) {
    return codec->skipScanlines(countLines);
}

SkCodec::SkScanlineOrder SkCodec_getScanlineOrder(SkCodec* codec) {
    return codec->getScanlineOrder();
}

int SkCodec_nextScanline(SkCodec* codec) {
    return codec->nextScanline();
}

int SkCodec_outputScanline(SkCodec* codec, int inputScanline) {
    return codec->outputScanline(inputScanline);
}

int SkCodec_getFrameCount(SkCodec* codec) {
    return codec->getFrameCount();
}

bool SkCodec_getFrameInfo(SkCodec* codec, int index, SkCodec::FrameInfo* info) {
    return codec->getFrameInfo(index, info);
}

vector_sk_codec_frame_into_t SkCodec_getFrameInfo_2(SkCodec* codec) {
    return static_vector_sk_codec_frame_into_make(codec->getFrameInfo());
}

int SkCodec_getRepetitionCount(SkCodec* codec) {
    return codec->getRepetitionCount();
}

// static

size_t SkCodec_MinBufferedBytesNeeded() {
    return SkCodec::MinBufferedBytesNeeded();
}

const char* SkCodec_ResultToString(SkCodec::Result result) {
    return SkCodec::ResultToString(result);
}

sk_codec_t SkCodec_MakeFromStream(sk_stream_t stream, SkCodec::Result* result, SkPngChunkReader* pngChunkReader, SkCodec::SelectionPolicy selectionPolicy) {
    return static_sk_codec_make(SkCodec::MakeFromStream(static_sk_stream_move(stream), result, pngChunkReader, selectionPolicy));
}

sk_codec_t SkCodec_MakeFromData(sk_stream_t stream, SkPngChunkReader* pngChunkReader) {
    return static_sk_codec_make(SkCodec::MakeFromData(static_sk_data_move(stream), pngChunkReader));
}

//void SkCodec_Register(bool (*peek)(const void*, size_t), std::unique_ptr<SkCodec> (*make)(std::unique_ptr<SkStream>, SkCodec::Result*)) {
//    SkCodec::Register(peek, make);
//}

}