//
// Created by dolphilia on 2024/01/10.
//

#ifndef RAIA_SKIA_SK_PICTURE_H
#define RAIA_SKIA_SK_PICTURE_H

#include "include/core/SkPicture.h"
#include "../static/static_sk_data.h"
#include "../static/static_sk_rect.h"
#include "../static/static_sk_shader.h"
#include "../static/static_sk_picture.h"

extern "C" {
void SkPicture_delete(SkPicture *picture);
void SkPicture_playback(SkPicture *picture, SkCanvas *canvas, SkPicture::AbortCallback *callback);
void SkPicture_cullRect(const char *sk_rect_key_out, SkPicture *picture);
uint32_t SkPicture_uniqueID(SkPicture *picture);
void SkPicture_serialize(const char *sk_data_key_out, SkPicture *picture, const SkSerialProcs *procs);
void SkPicture_serialize_2(SkPicture *picture, SkWStream *stream, const SkSerialProcs *procs);
size_t SkPicture_approximateOpCount(SkPicture *picture);
size_t SkPicture_approximateBytesUsed(SkPicture *picture);
void SkPicture_makeShader(const char *sk_shader_key_out, SkPicture *picture, SkTileMode tmx, SkTileMode tmy, SkFilterMode mode, const SkMatrix *localMatrix, const SkRect *tileRect);
void SkPicture_makeShader_2(const char *sk_shader_key_out, SkPicture *picture, SkTileMode tmx, SkTileMode tmy, SkFilterMode mode);
bool SkPicture_unique(SkPicture *picture);
void SkPicture_ref(SkPicture *picture);
void SkPicture_unref(SkPicture *picture);
// static
void SkPicture_MakeFromStream(const char *sk_picture_key_out, SkStream *stream, const SkDeserialProcs *procs);
void SkPicture_MakeFromData(const char *sk_picture_key_out, const SkData *data, const SkDeserialProcs *procs);
void SkPicture_MakeFromData_2(const char *sk_picture_key_out, const void *data, size_t size, const SkDeserialProcs *procs);
void SkPicture_MakePlaceholder(const char *sk_picture_key_out, SkRect cull);
}

#endif //RAIA_SKIA_SK_PICTURE_H
