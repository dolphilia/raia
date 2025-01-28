//
// Created by dolphilia on 2024/01/09.
//

#ifndef RAIA_SKIA_SK_IMAGE_GENERATOR_H
#define RAIA_SKIA_SK_IMAGE_GENERATOR_H

#ifdef __cplusplus
extern "C" {
#endif

void SkImageGenerator_delete(void *image_generator); // (SkImageGenerator *image_generator)
unsigned int SkImageGenerator_uniqueID(void *image_generator); // (SkImageGenerator *image_generator) -> uint32_t
int SkImageGenerator_refEncodedData(void *image_generator); // (SkImageGenerator *image_generator) -> sk_data_t
int SkImageGenerator_getInfo(void *image_generator); // (SkImageGenerator *image_generator) -> sk_image_info_t
bool SkImageGenerator_isValid(void *image_generator, void *context); // (SkImageGenerator *image_generator, GrRecordingContext *context) -> bool
bool SkImageGenerator_isProtected(void *image_generator); // (SkImageGenerator *image_generator) -> bool
bool SkImageGenerator_getPixels(void *image_generator, const void *info, void *pixels, unsigned long rowBytes); // (SkImageGenerator *image_generator, const SkImageInfo *info, void *pixels, size_t rowBytes) -> bool
bool SkImageGenerator_getPixels_2(void *image_generator, const void *pm); // (SkImageGenerator *image_generator, const SkPixmap *pm) -> bool
bool SkImageGenerator_queryYUVAInfo(void *image_generator, const void *supportedDataTypes, void *yuvaPixmapInfo); // (SkImageGenerator *image_generator, const SkYUVAPixmapInfo::SupportedDataTypes *supportedDataTypes, SkYUVAPixmapInfo *yuvaPixmapInfo) -> bool
bool SkImageGenerator_getYUVAPlanes(void *image_generator, const void *yuvaPixmaps); // (SkImageGenerator *image_generator, const SkYUVAPixmaps *yuvaPixmaps) -> bool
bool SkImageGenerator_isTextureGenerator(void *image_generator); // (SkImageGenerator *image_generator) -> bool

#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_SK_IMAGE_GENERATOR_H
