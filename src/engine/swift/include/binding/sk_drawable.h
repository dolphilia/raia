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
#include "../static/static_sk_rect.h"
#include "../static/static_sk_flattenable_factory.h"

extern "C" {
void SkDrawable_delete(SkDrawable *drawable);
void SkDrawable_draw(SkDrawable *drawable, SkCanvas * canvas, const SkMatrix * matrix);
void SkDrawable_draw_2(SkDrawable *drawable, SkCanvas *canvas, SkScalar x, SkScalar y);
sk_drawable_gpu_draw_handler_t SkDrawable_snapGpuDrawHandler(SkDrawable *drawable, GrBackendApi backendApi, const SkMatrix *matrix, const SkIRect *clipBounds, const SkImageInfo *bufferInfo);
sk_picture_t SkDrawable_makePictureSnapshot(SkDrawable *drawable);
uint32_t SkDrawable_getGenerationID(SkDrawable *drawable);
sk_rect_t SkDrawable_getBounds(SkDrawable *drawable);
size_t SkDrawable_approximateBytesUsed(SkDrawable *drawable);
void SkDrawable_notifyDrawingChanged(SkDrawable *drawable);
SkFlattenable::Type SkDrawable_getFlattenableType(SkDrawable *drawable);
sk_flattenable_factory_t SkDrawable_getFactory(SkDrawable *drawable);
const char * SkDrawable_getTypeName(SkDrawable *drawable);
void SkDrawable_flatten(SkDrawable *drawable, SkWriteBuffer *write_buffer);
sk_data_t SkDrawable_serialize(SkDrawable *drawable, const SkSerialProcs *serial_procs);
size_t SkDrawable_serialize_2(SkDrawable *drawable, void *memory, size_t memory_size, const SkSerialProcs *serial_procs);
bool SkDrawable_unique(SkDrawable *drawable);
void SkDrawable_ref(SkDrawable *drawable);
void SkDrawable_unref(SkDrawable *drawable);
// static
SkFlattenable::Type SkDrawable_GetFlattenableType();
sk_drawable_t SkDrawable_Deserialize(const void *data, size_t size, const SkDeserialProcs *procs);
sk_flattenable_factory_t SkDrawable_NameToFactory(const char name[]);
const char * SkDrawable_FactoryToName(sk_flattenable_factory_t factory);
void SkDrawable_Register(const char name[], sk_flattenable_factory_t factory);
}

#endif //RAIA_SKIA_SK_DRAWABLE_H
