//
// Created by dolphilia on 2024/01/08.
//

#ifndef RAIA_SKIA_SK_COLOR_FILTER_H
#define RAIA_SKIA_SK_COLOR_FILTER_H

#ifdef __cplusplus
extern "C" {
#endif

void SkColorFilter_delete(void *color_filter); // (SkColorFilter *color_filter)
bool SkColorFilter_asAColorMode(void *color_filter, void *color, void *mode); // (SkColorFilter *color_filter, SkColor *color, SkBlendMode *mode) -> bool
bool SkColorFilter_asAColorMatrix(void *color_filter, float matrix[20]); // (SkColorFilter *color_filter, float matrix[20]) -> bool
bool SkColorFilter_isAlphaUnchanged(void *color_filter); // (SkColorFilter *color_filter) -> bool
unsigned int  SkColorFilter_filterColor(void *color_filter, unsigned int  color); // (SkColorFilter *color_filter, SkColor color) -> SkColor
int SkColorFilter_filterColor4f(void *color_filter, const void *srcColor, void *srcCS, void *dstCS); // (SkColorFilter *color_filter, const SkColor4f *srcColor, SkColorSpace *srcCS, SkColorSpace *dstCS) -> sk_color_4f_t
int SkColorFilter_makeComposed(void *color_filter, int inner); // (SkColorFilter *color_filter, sk_color_filter_t inner) -> sk_color_filter_t
int SkColorFilter_makeWithWorkingColorSpace(void *color_filter, int colorSpace); // (SkColorFilter *color_filter, sk_color_space_t colorSpace) -> sk_color_filter_t
int SkColorFilter_getFactory(void *color_filter); // (SkColorFilter *color_filter) -> sk_flattenable_factory_t
const char *SkColorFilter_getTypeName(void *color_filter); // (SkColorFilter *color_filter) -> const char *
void SkColorFilter_flatten(void *color_filter, void *write_buffer); // (SkColorFilter *color_filter, SkWriteBuffer *write_buffer)
int SkColorFilter_getFlattenableType(void *color_filter); // (SkColorFilter *color_filter) -> SkColorFilter::Type
int SkColorFilter_serialize(void *color_filter, const void *serial_procs); // (SkColorFilter *color_filter, const SkSerialProcs *serial_procs) -> sk_data_t
unsigned long SkColorFilter_serialize_2(void *color_filter, void *memory, unsigned long memory_size, const void *serial_procs); // (SkColorFilter *color_filter, void *memory, size_t memory_size, const SkSerialProcs *serial_procs) -> size_t
bool SkColorFilter_unique(void *color_filter); // (SkColorFilter *color_filter) -> bool
void SkColorFilter_ref(void *color_filter); // (SkColorFilter *color_filter)
void SkColorFilter_unref(void *color_filter); // (SkColorFilter *color_filter)

// static

int SkColorFilter_Deserialize(const void *data, unsigned long size, const void *procs); // (const void *data, size_t size, const SkDeserialProcs *procs) -> sk_color_filter_t
int SkColorFilter_NameToFactory(const char name[]); // (const char name[]) -> sk_flattenable_factory_t
const char *SkColorFilter_FactoryToName(int factory); // (sk_flattenable_factory_t factory) -> const char *
void SkColorFilter_Register(const char name[], int factory); // (const char name[], sk_flattenable_factory_t factory)

#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_SK_COLOR_FILTER_H
