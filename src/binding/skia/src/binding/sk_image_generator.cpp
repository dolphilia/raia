//
// Created by dolphilia on 2024/01/09.
//

#include "sk_image_generator.h"

extern "C" {

void SkImageGenerator_delete(SkImageGenerator *image_generator) {
    delete image_generator;
}

uint32_t SkImageGenerator_uniqueID(SkImageGenerator *image_generator) {
    return image_generator->uniqueID();
}

sk_data_t SkImageGenerator_refEncodedData(SkImageGenerator *image_generator) {
    return static_sk_data_make(image_generator->refEncodedData());
}

sk_image_info_t SkImageGenerator_getInfo(SkImageGenerator *image_generator) {
    return static_sk_image_info_make(image_generator->getInfo());
}

bool SkImageGenerator_isValid(SkImageGenerator *image_generator, GrRecordingContext *context) {
    return image_generator->isValid(context);
}

bool SkImageGenerator_isProtected(SkImageGenerator *image_generator) {
    return image_generator->isProtected();
}

bool SkImageGenerator_getPixels(SkImageGenerator *image_generator, const SkImageInfo *info, void *pixels, size_t rowBytes) {
    return image_generator->getPixels(*info, pixels, rowBytes);
}

bool SkImageGenerator_getPixels_2(SkImageGenerator *image_generator, const SkPixmap *pm) {
    return image_generator->getPixels(*pm);
}

bool SkImageGenerator_queryYUVAInfo(SkImageGenerator *image_generator, const SkYUVAPixmapInfo::SupportedDataTypes *supportedDataTypes, SkYUVAPixmapInfo *yuvaPixmapInfo) {
    return image_generator->queryYUVAInfo(*supportedDataTypes, yuvaPixmapInfo);
}

bool SkImageGenerator_getYUVAPlanes(SkImageGenerator *image_generator, const SkYUVAPixmaps *yuvaPixmaps) {
    return image_generator->getYUVAPlanes(*yuvaPixmaps);
}

bool SkImageGenerator_isTextureGenerator(SkImageGenerator *image_generator) {
    return image_generator->isTextureGenerator();
}

}