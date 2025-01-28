//
// Created by dolphilia on 2024/01/10.
//

#ifndef RAIA_SKIA_SK_PICTURE_H
#define RAIA_SKIA_SK_PICTURE_H

#ifdef __cplusplus
extern "C" {
#endif

void SkPicture_delete(void *picture); // (SkPicture *picture)
void SkPicture_playback(void *picture, void *canvas, void *callback); // (SkPicture *picture, SkCanvas *canvas, SkPicture::AbortCallback *callback)
int SkPicture_cullRect(void *picture); // (SkPicture *picture) -> sk_rect_t
unsigned int SkPicture_uniqueID(void *picture); // (SkPicture *picture) -> uint32_t
int SkPicture_serialize(void *picture, const void *procs); // (SkPicture *picture, const SkSerialProcs *procs) -> sk_data_t
void SkPicture_serialize_2(void *picture, void *stream, const void *procs); // (SkPicture *picture, SkWStream *stream, const SkSerialProcs *procs)
unsigned long SkPicture_approximateOpCount(void *picture); // (SkPicture *picture) -> size_t
unsigned long SkPicture_approximateBytesUsed(void *picture); // (SkPicture *picture) -> size_t
int SkPicture_makeShader(void *picture, int tmx, int tmy, int mode, const void *localMatrix, const void *tileRect); // (SkPicture *picture, SkTileMode tmx, SkTileMode tmy, SkFilterMode mode, const SkMatrix *localMatrix, const SkRect *tileRect) -> sk_shader_t
int SkPicture_makeShader_2(void *picture, int tmx, int tmy, int mode); // (SkPicture *picture, SkTileMode tmx, SkTileMode tmy, SkFilterMode mode) -> sk_shader_t
bool SkPicture_unique(void *picture); // (SkPicture *picture) -> bool
void SkPicture_ref(void *picture); // (SkPicture *picture)
void SkPicture_unref(void *picture); // (SkPicture *picture)

// static

int SkPicture_MakeFromStream(void *stream, const void *procs); // (SkStream *stream, const SkDeserialProcs *procs) -> sk_picture_t
int SkPicture_MakeFromData(const void *data, const void *procs); // (const SkData *data, const SkDeserialProcs *procs) -> sk_picture_t
int SkPicture_MakeFromData_2(const void *data, unsigned long size, const void *procs); // (const void *data, size_t size, const SkDeserialProcs *procs) -> sk_picture_t
int SkPicture_MakePlaceholder(int cull); // (sk_rect_t cull) -> sk_picture_t

#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_SK_PICTURE_H
