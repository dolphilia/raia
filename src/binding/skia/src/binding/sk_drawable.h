//
// Created by dolphilia on 2024/01/08.
//

#ifndef RAIA_SKIA_SK_DRAWABLE_H
#define RAIA_SKIA_SK_DRAWABLE_H

#include "include/core/SkDrawable.h"
#include "../static/static_sk_drawable_gpu_draw_handler.h"
#include "../static/static_sk_picture.h"
#include "../static/static_sk_data.h"
#include "../static/static_sk_drawable.h"

extern "C" {
void SkDrawable_draw(SkDrawable *drawable, SkCanvas * canvas, const SkMatrix * matrix);
void SkDrawable_draw_2(SkDrawable *drawable, SkCanvas *canvas, SkScalar x, SkScalar y);
void SkDrawable_snapGpuDrawHandler(const char *gpu_draw_handler_key_out, SkDrawable *drawable, GrBackendApi backendApi, const SkMatrix *matrix, const SkIRect *clipBounds, const SkImageInfo *bufferInfo);
void SkDrawable_makePictureSnapshot(const char *sk_picture_key_out, SkDrawable *drawable);
uint32_t SkDrawable_getGenerationID(SkDrawable *drawable);
void SkDrawable_getBounds(const char *sk_rect_key_out, SkDrawable *drawable);
size_t SkDrawable_approximateBytesUsed(SkDrawable *drawable);
void SkDrawable_notifyDrawingChanged(SkDrawable *drawable);
SkFlattenable::Type SkDrawable_getFlattenableType(SkDrawable *drawable);
SkDrawable::Factory SkDrawable_getFactory(SkDrawable *drawable);
const char * SkDrawable_getTypeName(SkDrawable *drawable);
void SkDrawable_flatten(SkDrawable *drawable, SkWriteBuffer *write_buffer);
void SkDrawable_serialize(const char *sk_data_key_out, SkDrawable *drawable, const SkSerialProcs *serial_procs);
size_t SkDrawable_serialize_2(SkDrawable *drawable, void *memory, size_t memory_size, const SkSerialProcs *serial_procs);
bool SkDrawable_unique(SkDrawable *drawable);
void SkDrawable_ref(SkDrawable *drawable);
void SkDrawable_unref(SkDrawable *drawable);
// static
SkFlattenable::Type SkDrawable_GetFlattenableType();
void SkDrawable_Deserialize(const char *sk_drawable_key_out, const void *data, size_t size, const SkDeserialProcs *procs);
SkDrawable::Factory SkDrawable_NameToFactory(const char name[]);
const char * SkDrawable_FactoryToName(SkDrawable::Factory factory);
void SkDrawable_Register(const char name[], SkDrawable::Factory factory);
}

#endif //RAIA_SKIA_SK_DRAWABLE_H
