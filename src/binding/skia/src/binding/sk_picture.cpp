//
// Created by dolphilia on 2024/01/10.
//

#include "sk_picture.h"

extern "C" {

void SkPicture_delete(SkPicture *picture) {
    delete picture;
}

void SkPicture_playback(SkPicture *picture, SkCanvas *canvas, SkPicture::AbortCallback *callback) {
    picture->playback(canvas, callback);
}

sk_rect_t SkPicture_cullRect(SkPicture *picture) {
    return static_sk_rect_make(picture->cullRect());
}

uint32_t SkPicture_uniqueID(SkPicture *picture) {
    return picture->uniqueID();
}

sk_data_t SkPicture_serialize(SkPicture *picture, const SkSerialProcs *procs) {
    return static_sk_data_make(picture->serialize(procs));
}

void SkPicture_serialize_2(SkPicture *picture, SkWStream *stream, const SkSerialProcs *procs) {
    picture->serialize(stream, procs);
}

size_t SkPicture_approximateOpCount(SkPicture *picture) { //, bool nested
    return picture->approximateBytesUsed();
}

size_t SkPicture_approximateBytesUsed(SkPicture *picture) { //, SkPicture *picture_2
    return picture->approximateBytesUsed();
}

sk_shader_t SkPicture_makeShader(SkPicture *picture, SkTileMode tmx, SkTileMode tmy, SkFilterMode mode, const SkMatrix *localMatrix, const SkRect *tileRect) {
    return static_sk_shader_make(picture->makeShader(tmx, tmy, mode, localMatrix, tileRect));
}

sk_shader_t SkPicture_makeShader_2(SkPicture *picture, SkTileMode tmx, SkTileMode tmy, SkFilterMode mode) {
    return static_sk_shader_make(picture->makeShader(tmx, tmy, mode));
}

bool SkPicture_unique(SkPicture *picture) {
    return picture->unique();
}

void SkPicture_ref(SkPicture *picture) {
    picture->ref();
}

void SkPicture_unref(SkPicture *picture) {
    picture->unref();
}

// static

sk_picture_t SkPicture_MakeFromStream(SkStream *stream, const SkDeserialProcs *procs) {
    return static_sk_picture_make(SkPicture::MakeFromStream(stream, procs));
}

sk_picture_t SkPicture_MakeFromData(const SkData *data, const SkDeserialProcs *procs) {
    return static_sk_picture_make(SkPicture::MakeFromData(data, procs));
}

sk_picture_t SkPicture_MakeFromData_2(const void *data, size_t size, const SkDeserialProcs *procs) {
    return static_sk_picture_make(SkPicture::MakeFromData(data, size, procs));
}

sk_picture_t SkPicture_MakePlaceholder(sk_rect_t cull) {
    return static_sk_picture_make(SkPicture::MakePlaceholder(static_sk_rect_get(cull)));
}

}