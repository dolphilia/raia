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
#include "export_api.h"

extern "C" {
RAIA_API void SkPicture_delete(SkPicture *picture);
RAIA_API void SkPicture_playback(SkPicture *picture, SkCanvas *canvas, SkPicture::AbortCallback *callback);
RAIA_API sk_rect_t SkPicture_cullRect(SkPicture *picture);
RAIA_API uint32_t SkPicture_uniqueID(SkPicture *picture);
RAIA_API sk_data_t SkPicture_serialize(SkPicture *picture, const SkSerialProcs *procs);
RAIA_API void SkPicture_serialize_2(SkPicture *picture, SkWStream *stream, const SkSerialProcs *procs);
RAIA_API size_t SkPicture_approximateOpCount(SkPicture *picture);
RAIA_API size_t SkPicture_approximateBytesUsed(SkPicture *picture);
RAIA_API sk_shader_t SkPicture_makeShader(SkPicture *picture, SkTileMode tmx, SkTileMode tmy, SkFilterMode mode, const SkMatrix *localMatrix, const SkRect *tileRect);
RAIA_API sk_shader_t SkPicture_makeShader_2(SkPicture *picture, SkTileMode tmx, SkTileMode tmy, SkFilterMode mode);
RAIA_API bool SkPicture_unique(SkPicture *picture);
RAIA_API void SkPicture_ref(SkPicture *picture);
RAIA_API void SkPicture_unref(SkPicture *picture);
// static
RAIA_API sk_picture_t SkPicture_MakeFromStream(SkStream *stream, const SkDeserialProcs *procs);
RAIA_API sk_picture_t SkPicture_MakeFromData(const SkData *data, const SkDeserialProcs *procs);
RAIA_API sk_picture_t SkPicture_MakeFromData_2(const void *data, size_t size, const SkDeserialProcs *procs);
RAIA_API sk_picture_t SkPicture_MakePlaceholder(sk_rect_t cull);
}

#endif //RAIA_SKIA_SK_PICTURE_H
