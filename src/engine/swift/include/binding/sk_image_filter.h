//
// Created by dolphilia on 2024/01/08.
//

#ifndef RAIA_SKIA_SK_IMAGE_FILTER_H
#define RAIA_SKIA_SK_IMAGE_FILTER_H

#ifdef __cplusplus
extern "C" {
#endif

void SkImageFilter_delete(void *image_filter); // (SkImageFilter *image_filter)
int SkImageFilter_filterBounds(void *image_filter, const void *src, const void *ctm, int direction, const void *inputRect); // (SkImageFilter *image_filter, const SkIRect *src, const SkMatrix *ctm, SkImageFilter::MapDirection direction, const SkIRect *inputRect) -> sk_i_rect_t
bool SkImageFilter_isColorFilterNode(void *image_filter, void **filterPtr); // (SkImageFilter *image_filter, SkColorFilter **filterPtr) -> bool
bool SkImageFilter_asColorFilter(void *image_filter, void **filterPtr); // (SkImageFilter *image_filter, SkColorFilter **filterPtr) -> bool
bool SkImageFilter_asAColorFilter(void *image_filter, void **filterPtr); // (SkImageFilter *image_filter, SkColorFilter **filterPtr) -> bool
int SkImageFilter_countInputs(void *image_filter); // (SkImageFilter *image_filter) -> int
const void *SkImageFilter_getInput(void *image_filter, int i); // (SkImageFilter *image_filter, int i) -> const SkImageFilter *
int SkImageFilter_computeFastBounds(void *image_filter, const void *bounds); // (SkImageFilter *image_filter, const SkRect *bounds) -> sk_rect_t
bool SkImageFilter_canComputeFastBounds(void *image_filter); // (SkImageFilter *image_filter) -> bool
int SkImageFilter_makeWithLocalMatrix(void *image_filter, const void *matrix); // (SkImageFilter *image_filter, const SkMatrix *matrix) -> sk_image_filter_t
int SkImageFilter_getFactory(void *image_filter); // (SkImageFilter *image_filter) -> sk_flattenable_factory_t
const char *SkImageFilter_getTypeName(void *image_filter); // (SkImageFilter *image_filter) -> const char *
void SkImageFilter_flatten(void *image_filter, void *buffer); // (SkImageFilter *image_filter, SkWriteBuffer *buffer)
int SkImageFilter_getFlattenableType(void *image_filter); // (SkImageFilter *image_filter) -> SkImageFilter::Type
int SkImageFilter_serialize(void *image_filter, const void *procs); // (SkImageFilter *image_filter, const SkSerialProcs *procs) -> sk_data_t
unsigned long SkImageFilter_serialize_2(void *image_filter, void *memory, unsigned long memory_size, const void *procs); // (SkImageFilter *image_filter, void *memory, size_t memory_size, const SkSerialProcs *procs) -> size_t
bool SkImageFilter_unique(void *image_filter); // (SkImageFilter *image_filter) -> bool
void SkImageFilter_ref(void *image_filter); // (SkImageFilter *image_filter)
void SkImageFilter_unref(void *image_filter); // (SkImageFilter *image_filter)

// static

int SkImageFilter_Deserialize(const void *data, unsigned long size, const void *procs); // (const void *data, size_t size, const SkDeserialProcs *procs) -> sk_image_filter_t
int SkImageFilter_NameToFactory(const char name[]); // (const char name[]) -> sk_flattenable_factory_t
const char *SkImageFilter_FactoryToName(int factory); // (sk_flattenable_factory_t factory) -> const char *
void SkImageFilter_Register(const char name[], int factory); // (const char name[], sk_flattenable_factory_t factory)

#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_SK_IMAGE_FILTER_H
