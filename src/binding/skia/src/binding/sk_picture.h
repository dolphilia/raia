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
sk_rect_t SkPicture_cullRect(SkPicture *picture);
uint32_t SkPicture_uniqueID(SkPicture *picture);
sk_data_t SkPicture_serialize(SkPicture *picture, const SkSerialProcs *procs);
void SkPicture_serialize_2(SkPicture *picture, SkWStream *stream, const SkSerialProcs *procs);
size_t SkPicture_approximateOpCount(SkPicture *picture);
size_t SkPicture_approximateBytesUsed(SkPicture *picture);
sk_shader_t SkPicture_makeShader(SkPicture *picture, SkTileMode tmx, SkTileMode tmy, SkFilterMode mode, const SkMatrix *localMatrix, const SkRect *tileRect);
sk_shader_t SkPicture_makeShader_2(SkPicture *picture, SkTileMode tmx, SkTileMode tmy, SkFilterMode mode);
bool SkPicture_unique(SkPicture *picture);
void SkPicture_ref(SkPicture *picture);
void SkPicture_unref(SkPicture *picture);
// static
sk_picture_t SkPicture_MakeFromStream(SkStream *stream, const SkDeserialProcs *procs);
sk_picture_t SkPicture_MakeFromData(const SkData *data, const SkDeserialProcs *procs);
sk_picture_t SkPicture_MakeFromData_2(const void *data, size_t size, const SkDeserialProcs *procs);
sk_picture_t SkPicture_MakePlaceholder(sk_rect_t cull);
}

#endif //RAIA_SKIA_SK_PICTURE_H
