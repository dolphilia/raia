//
// Created by dolphilia on 2024/02/02.
//

#ifndef RAIA_SKIA_SK_CODEC_H
#define RAIA_SKIA_SK_CODEC_H

#ifdef __cplusplus
extern "C" {
#endif

void SkCodec_delete(void * codec); // (SkCodec* codec)
int SkCodec_getInfo(void * codec); // (SkCodec* codec) -> sk_image_info_t
int SkCodec_dimensions(void * codec); // (SkCodec* codec) -> sk_i_size_t
int SkCodec_bounds(void * codec); // (SkCodec* codec) -> sk_i_rect_t
const void * SkCodec_getICCProfile(void * codec); // (SkCodec* codec) -> const skcms_ICCProfile*
int SkCodec_getOrigin(void * codec); // (SkCodec* codec) -> SkEncodedOrigin
int SkCodec_getScaledDimensions(void * codec, float desiredScale); // (SkCodec* codec, float desiredScale) -> sk_i_size_t
bool SkCodec_getValidSubset(void * codec, void * desiredSubset); // (SkCodec* codec, SkIRect* desiredSubset) -> bool
int SkCodec_getEncodedFormat(void * codec); // (SkCodec* codec) -> SkEncodedImageFormat
int SkCodec_getPixels(void * codec, const void * info, void* pixels, unsigned long rowBytes, const void * options); // (SkCodec* codec, const SkImageInfo* info, void* pixels, size_t rowBytes, const SkCodec::Options* options) -> SkCodec::Result
int SkCodec_getPixels_2(void * codec, const void * info, void* pixels, unsigned long rowBytes); // (SkCodec* codec, const SkImageInfo* info, void* pixels, size_t rowBytes) -> SkCodec::Result
int SkCodec_getPixels_3(void * codec, const void * pm, const void * opts); // (SkCodec* codec, const SkPixmap* pm, const SkCodec::Options* opts) -> SkCodec::Result
int SkCodec_getImage(void * codec, const void * info, const void * opts); // (SkCodec* codec, const SkImageInfo* info, const SkCodec::Options* opts) -> int
int SkCodec_getImage_2(void * codec); // (SkCodec* codec) -> int
bool SkCodec_queryYUVAInfo(void * codec, const void * supportedDataTypes, void * yuvaPixmapInfo); // (SkCodec* codec, const SkYUVAPixmapInfo::SupportedDataTypes* supportedDataTypes, SkYUVAPixmapInfo* yuvaPixmapInfo) -> bool
int SkCodec_getYUVAPlanes(void * codec, const void * yuvaPixmaps); // (SkCodec* codec, const SkYUVAPixmaps* yuvaPixmaps) -> SkCodec::Result
int SkCodec_startIncrementalDecode(void * codec, const void * dstInfo, void* dst, unsigned long rowBytes, const void * options); // (SkCodec* codec, const SkImageInfo* dstInfo, void* dst, size_t rowBytes, const SkCodec::Options* options) -> SkCodec::Result
int SkCodec_startIncrementalDecode_2(void * codec, const void * dstInfo, void* dst, unsigned long rowBytes); // (SkCodec* codec, const SkImageInfo* dstInfo, void* dst, size_t rowBytes) -> SkCodec::Result
int SkCodec_incrementalDecode(void * codec, int* rowsDecoded); // (SkCodec* codec, int* rowsDecoded) -> SkCodec::Result
int SkCodec_startScanlineDecode(void * codec, const void * dstInfo, const void * options); // (SkCodec* codec, const SkImageInfo* dstInfo, const SkCodec::Options* options) -> SkCodec::Result
int SkCodec_startScanlineDecode_2(void * codec, const void * dstInfo); // (SkCodec* codec, const SkImageInfo* dstInfo) -> SkCodec::Result
int SkCodec_getScanlines(void * codec, void* dst, int countLines, unsigned long rowBytes); // (SkCodec* codec, void* dst, int countLines, size_t rowBytes) -> int
bool SkCodec_skipScanlines(void * codec, int countLines); // (SkCodec* codec, int countLines) -> bool
int SkCodec_getScanlineOrder(void * codec); // (SkCodec* codec) -> SkCodec::SkScanlineOrder
int SkCodec_nextScanline(void * codec); // (SkCodec* codec) -> int
int SkCodec_outputScanline(void * codec, int inputScanline); // (SkCodec* codec, int inputScanline) -> int
int SkCodec_getFrameCount(void * codec); // (SkCodec* codec) -> int
bool SkCodec_getFrameInfo(void * codec, int index, void * info); // (SkCodec* codec, int index, SkCodec::FrameInfo* info) -> bool
int SkCodec_getFrameInfo_2(void * codec); // (SkCodec* codec) -> int
int SkCodec_getRepetitionCount(void * codec); // (SkCodec* codec) -> int

// static

unsigned long SkCodec_MinBufferedBytesNeeded(); // () -> size_t
const char* SkCodec_ResultToString(int result); // (SkCodec::Result result) -> const char*
int SkCodec_MakeFromStream(int stream, void * result, void * pngChunkReader, int selectionPolicy); // (sk_stream_t stream, SkCodec::Result* result, SkPngChunkReader* pngChunkReader, SkCodec::SelectionPolicy selectionPolicy) -> sk_codec_t
int SkCodec_MakeFromData(int stream, void * pngChunkReader); // (sk_stream_t stream, SkPngChunkReader* pngChunkReader) -> sk_codec_t

//void SkCodec_Register(bool (*peek)(const void*, size_t), std::unique_ptr<SkCodec> (*make)(std::unique_ptr<SkStream>, SkCodec::Result*));

#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_SK_CODEC_H
