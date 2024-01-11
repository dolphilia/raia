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

void SkPicture_cullRect(const char *sk_rect_key_out, SkPicture *picture) {
    static_sk_rect_set(sk_rect_key_out, picture->cullRect());
}

uint32_t SkPicture_uniqueID(SkPicture *picture) {
    return picture->uniqueID();
}

void SkPicture_serialize(const char *sk_data_key_out, SkPicture *picture, const SkSerialProcs *procs) {
    static_sk_data_set(sk_data_key_out, picture->serialize(procs));
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

void SkPicture_makeShader(const char *sk_shader_key_out, SkPicture *picture, SkTileMode tmx, SkTileMode tmy, SkFilterMode mode, const SkMatrix *localMatrix, const SkRect *tileRect) {
    static_sk_shader_set(sk_shader_key_out, picture->makeShader(tmx, tmy, mode, localMatrix, tileRect));
}

void SkPicture_makeShader_2(const char *sk_shader_key_out, SkPicture *picture, SkTileMode tmx, SkTileMode tmy, SkFilterMode mode) {
    static_sk_shader_set(sk_shader_key_out, picture->makeShader(tmx, tmy, mode));
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

void SkPicture_MakeFromStream(const char *sk_picture_key_out, SkStream *stream, const SkDeserialProcs *procs) {
    static_sk_picture_set(sk_picture_key_out, SkPicture::MakeFromStream(stream, procs));
}

void SkPicture_MakeFromData(const char *sk_picture_key_out, const SkData *data, const SkDeserialProcs *procs) {
    static_sk_picture_set(sk_picture_key_out, SkPicture::MakeFromData(data, procs));
}

void SkPicture_MakeFromData_2(const char *sk_picture_key_out, const void *data, size_t size, const SkDeserialProcs *procs) {
    static_sk_picture_set(sk_picture_key_out, SkPicture::MakeFromData(data, size, procs));
}

void SkPicture_MakePlaceholder(const char *sk_picture_key_out, SkRect cull) {
    static_sk_picture_set(sk_picture_key_out, SkPicture::MakePlaceholder(cull));
}

}