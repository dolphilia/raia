//
// Created by dolphilia on 25/02/17.
//

#ifndef SK_READ_BUFFER_H
#define SK_READ_BUFFER_H

#ifdef __cplusplus
extern "C" {
#endif

void * SkReadBuffer_new(); // () -> SkReadBuffer*
void * SkReadBuffer_new_2(const void* data, unsigned long size); // (const void* data, size_t size) -> SkReadBuffer*
void SkReadBuffer_delete(void * rect); // (SkReadBuffer* rect)
void SkReadBuffer_setMemory(void * buffer, const void* data, unsigned long size); // (SkReadBuffer* buffer, const void* data, size_t size)
bool SkReadBuffer_isVersionLT(void * buffer, int targetVersion); // (SkReadBuffer* buffer, SkPicturePriv::Version targetVersion) -> bool
unsigned int SkReadBuffer_getVersion(void * buffer); // (SkReadBuffer* buffer) -> uint32_t
void SkReadBuffer_setVersion(void * buffer, int version); // (SkReadBuffer* buffer, int version)
unsigned long SkReadBuffer_size(void * buffer); // (SkReadBuffer* buffer) -> size_t
unsigned long SkReadBuffer_offset(void * buffer); // (SkReadBuffer* buffer) -> size_t
bool SkReadBuffer_eof(void * buffer); // (SkReadBuffer* buffer) -> bool
const void* SkReadBuffer_skip(void * buffer, unsigned long size); // (SkReadBuffer* buffer, size_t size) -> const void*
const void* SkReadBuffer_skip_2(void * buffer, unsigned long count, unsigned long size); // (SkReadBuffer* buffer, size_t count, size_t size) -> const void*
unsigned long SkReadBuffer_available(void * buffer); // (SkReadBuffer* buffer) -> size_t

// template <typename T> const T* skipT()
// template <typename T> const T* skipT(size_t count)

bool SkReadBuffer_readBool(void * buffer); // (SkReadBuffer* buffer) -> bool
unsigned int SkReadBuffer_readColor(void * buffer); // (SkReadBuffer* buffer) -> SkColor
int SkReadBuffer_readInt(void * buffer); // (SkReadBuffer* buffer) -> int32_t
float SkReadBuffer_readScalar(void * buffer); // (SkReadBuffer* buffer) -> SkScalar
unsigned int SkReadBuffer_readUInt(void * buffer); // (SkReadBuffer* buffer) -> uint32_t
int SkReadBuffer_read32(void * buffer); // (SkReadBuffer* buffer) -> int32_t

// template <typename T> T read32LE(T max)

unsigned char SkReadBuffer_peekByte(void * buffer); // (SkReadBuffer* buffer) -> uint8_t
void SkReadBuffer_readString(void * buffer, void * string); // (SkReadBuffer* buffer, SkString* string)
void SkReadBuffer_readColor4f(void * buffer, void * color); // (SkReadBuffer* buffer, SkColor4f* color)
void SkReadBuffer_readPoint(void * buffer, void * point); // (SkReadBuffer* buffer, SkPoint* point)
int SkReadBuffer_readPoint_2(void * buffer); // (SkReadBuffer* buffer) -> sk_point_t
void SkReadBuffer_readPoint3(void * buffer, void * point); // (SkReadBuffer* buffer, SkPoint3* point)
void SkReadBuffer_read(void * buffer, void * m44); // (SkReadBuffer* buffer, SkM44* m44)
void SkReadBuffer_readMatrix(void * buffer, void * matrix); // (SkReadBuffer* buffer, SkMatrix* matrix)
void SkReadBuffer_readIRect(void * buffer, void * rect); // (SkReadBuffer* buffer, SkIRect* rect)
void SkReadBuffer_readRect(void * buffer, void * rect); // (SkReadBuffer* buffer, SkRect* rect)
int SkReadBuffer_readRect_2(void * buffer); // (SkReadBuffer* buffer) -> sk_rect_t
void SkReadBuffer_readRRect(void * buffer, void * rrect); // (SkReadBuffer* buffer, SkRRect* rrect)
void SkReadBuffer_readRegion(void * buffer, void * region); // (SkReadBuffer* buffer, SkRegion* region)
void SkReadBuffer_readPath(void * buffer, void * path); // (SkReadBuffer* buffer, SkPath* path)
int SkReadBuffer_readPaint(void * buffer); // (SkReadBuffer* buffer) -> sk_paint_t
void * SkReadBuffer_readRawFlattenable(void * buffer); // (SkReadBuffer* buffer) -> SkFlattenable*
void * SkReadBuffer_readFlattenable(void * buffer, int type); // (SkReadBuffer* buffer, SkFlattenable::Type type) -> SkFlattenable*

// template <typename T> sk_sp<T> readFlattenable()

int SkReadBuffer_readColorFilter(void * buffer); // (SkReadBuffer* buffer) -> sk_color_filter_t
int SkReadBuffer_readImageFilter(void * buffer); // (SkReadBuffer* buffer) -> sk_image_filter_t
int SkReadBuffer_readBlender(void * buffer); // (SkReadBuffer* buffer) -> sk_blender_t
int SkReadBuffer_readMaskFilter(void * buffer); // (SkReadBuffer* buffer) -> sk_mask_filter_t
int SkReadBuffer_readPathEffect(void * buffer); // (SkReadBuffer* buffer) -> sk_path_effect_t
int SkReadBuffer_readShader(void * buffer); // (SkReadBuffer* buffer) -> sk_shader_t
bool SkReadBuffer_readPad32(void * readBuffer, void * buffer, unsigned long bytes); // (SkReadBuffer* readBuffer, void* buffer, size_t bytes) -> bool
bool SkReadBuffer_readByteArray(void * buffer, void * value, unsigned long size); // (SkReadBuffer* buffer, void* value, size_t size) -> bool
bool SkReadBuffer_readColorArray(void * buffer, void * colors, unsigned long size); // (SkReadBuffer* buffer, SkColor* colors, size_t size) -> bool
bool SkReadBuffer_readColor4fArray(void * buffer, void * colors, unsigned long size); // (SkReadBuffer* buffer, SkColor4f* colors, size_t size) -> bool
bool SkReadBuffer_readIntArray(void * buffer, void * values, unsigned long size); // (SkReadBuffer* buffer, int32_t* values, size_t size) -> bool
bool SkReadBuffer_readPointArray(void * buffer, void * points, unsigned long size); // (SkReadBuffer* buffer, SkPoint* points, size_t size) -> bool
bool SkReadBuffer_readScalarArray(void * buffer, void * values, unsigned long size); // (SkReadBuffer* buffer, SkScalar* values, size_t size) -> bool
const void* SkReadBuffer_skipByteArray(void * buffer, void * size); // (SkReadBuffer* buffer, size_t* size) -> const void*
int SkReadBuffer_readByteArrayAsData(void * buffer); // (SkReadBuffer* buffer) -> sk_data_t
unsigned int SkReadBuffer_getArrayCount(void * buffer); // (SkReadBuffer* buffer) -> uint32_t
int SkReadBuffer_readImage(void * buffer); // (SkReadBuffer* buffer) -> sk_image_t
int SkReadBuffer_readTypeface(void * buffer); // (SkReadBuffer* buffer) -> sk_typeface_t
void SkReadBuffer_setTypefaceArray(void * buffer, void * array, int count); // (SkReadBuffer* buffer, sk_sp<SkTypeface>* array, int count)
void SkReadBuffer_setFactoryPlayback(void * buffer, void * array, int count); // (SkReadBuffer* buffer, SkFlattenable::Factory* array, int count)
void SkReadBuffer_setDeserialProcs(void * buffer, const void * procs); // (SkReadBuffer* buffer, const SkDeserialProcs* procs)
const void * SkReadBuffer_getDeserialProcs(void * buffer); // (SkReadBuffer* buffer) -> const SkDeserialProcs*
bool SkReadBuffer_allowSkSL(void * buffer); // (SkReadBuffer* buffer) -> bool
void SkReadBuffer_setAllowSkSL(void * buffer, bool allow); // (SkReadBuffer* buffer, bool allow)
bool SkReadBuffer_validate(void * buffer, bool isValid); // (SkReadBuffer* buffer, bool isValid) -> bool

// template <typename T> bool validateCanReadN(size_t n)

bool SkReadBuffer_isValid(void * buffer); // (SkReadBuffer* buffer) -> bool
bool SkReadBuffer_validateIndex(void * buffer, int index, int count); // (SkReadBuffer* buffer, int index, int count) -> bool
int SkReadBuffer_checkInt(void * buffer, int min, int max); // (SkReadBuffer* buffer, int min, int max) -> int32_t

// template <typename T> T checkRange(T min, T max)

int SkReadBuffer_checkFilterQuality(void * buffer); // (SkReadBuffer* buffer) -> SkLegacyFQ
int SkReadBuffer_readSampling(void * buffer); // (SkReadBuffer* buffer) -> sk_sampling_options_t

#ifdef __cplusplus
}
#endif

#endif //SK_READ_BUFFER_H
