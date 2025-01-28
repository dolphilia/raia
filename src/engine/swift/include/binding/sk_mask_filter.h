//
// Created by dolphilia on 2024/01/09.
//

#ifndef RAIA_SKIA_SK_MASK_FILTER_H
#define RAIA_SKIA_SK_MASK_FILTER_H

#ifdef __cplusplus
extern "C" {
#endif

void SkMaskFilter_delete(void *maskFilter); // (SkMaskFilter *maskFilter)
int SkMaskFilter_approximateFilteredBounds(void *mask_filter, const void *src); // (SkMaskFilter *mask_filter, const SkRect *src) -> sk_rect_t
int SkMaskFilter_getFactory(void *mask_filter); // (SkMaskFilter *mask_filter) -> sk_flattenable_factory_t
const char *SkMaskFilter_getTypeName(void *mask_filter); // (SkMaskFilter *mask_filter) -> const char *
void SkMaskFilter_flatten(void *mask_filter, void *buffer); // (SkMaskFilter *mask_filter, SkWriteBuffer *buffer)
int SkMaskFilter_getFlattenableType(void *mask_filter); // (SkMaskFilter *mask_filter) -> SkMaskFilter::Type
int SkMaskFilter_serialize(void *mask_filter, const void *procs); // (SkMaskFilter *mask_filter, const SkSerialProcs *procs) -> sk_data_t
unsigned long SkMaskFilter_serialize_2(void *mask_filter, void *memory, unsigned long memory_size, const void *procs); // (SkMaskFilter *mask_filter, void *memory, size_t memory_size, const SkSerialProcs *procs) -> size_t
bool SkMaskFilter_unique(void *mask_filter); // (SkMaskFilter *mask_filter) -> bool
void SkMaskFilter_ref(void *mask_filter); // (SkMaskFilter *mask_filter)
void SkMaskFilter_unref(void *mask_filter); // (SkMaskFilter *mask_filter)

// static

int SkMaskFilter_MakeBlur(int style, float sigma, bool respectCTM); // (SkBlurStyle style, SkScalar sigma, bool respectCTM) -> sk_mask_filter_t
int SkMaskFilter_Deserialize(const void *data, unsigned long size, const void *procs); // (const void *data, size_t size, const SkDeserialProcs *procs) -> sk_mask_filter_t
int SkMaskFilter_NameToFactory(const char name[]); // (const char name[]) -> sk_flattenable_factory_t
const char *SkMaskFilter_FactoryToName(int factory); // (sk_flattenable_factory_t factory) -> const char *
void SkMaskFilter_Register(const char name[], int factory); // (const char name[], sk_flattenable_factory_t factory)

#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_SK_MASK_FILTER_H
