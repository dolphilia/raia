//
// Created by dolphilia on 2024/01/09.
//

#ifndef RAIA_SKIA_SK_IMAGE_GENERATOR_H
#define RAIA_SKIA_SK_IMAGE_GENERATOR_H

#include "include/core/SkImageGenerator.h"
#include "../static/static_sk_data.h"
#include "../static/static_sk_image_info.h"
#include "export_api.h"

extern "C" {
RAIA_API void SkImageGenerator_delete(SkImageGenerator *image_generator);
RAIA_API uint32_t SkImageGenerator_uniqueID(SkImageGenerator *image_generator);
RAIA_API sk_data_t SkImageGenerator_refEncodedData(SkImageGenerator *image_generator);
RAIA_API sk_image_info_t SkImageGenerator_getInfo(SkImageGenerator *image_generator);
RAIA_API bool SkImageGenerator_isValid(SkImageGenerator *image_generator, GrRecordingContext *context);
RAIA_API bool SkImageGenerator_isProtected(SkImageGenerator *image_generator);
RAIA_API bool SkImageGenerator_getPixels(SkImageGenerator *image_generator, const SkImageInfo *info, void *pixels, size_t rowBytes);
RAIA_API bool SkImageGenerator_getPixels_2(SkImageGenerator *image_generator, const SkPixmap *pm);
RAIA_API bool SkImageGenerator_queryYUVAInfo(SkImageGenerator *image_generator, const SkYUVAPixmapInfo::SupportedDataTypes *supportedDataTypes, SkYUVAPixmapInfo *yuvaPixmapInfo);
RAIA_API bool SkImageGenerator_getYUVAPlanes(SkImageGenerator *image_generator, const SkYUVAPixmaps *yuvaPixmaps);
RAIA_API bool SkImageGenerator_isTextureGenerator(SkImageGenerator *image_generator);
}

#endif //RAIA_SKIA_SK_IMAGE_GENERATOR_H
