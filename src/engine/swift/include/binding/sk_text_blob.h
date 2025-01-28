//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_SK_TEXT_BLOB_H
#define RAIA_SKIA_SK_TEXT_BLOB_H

#ifdef __cplusplus
extern "C" {
#endif

void SkTextBlob_delete(void *text_blob); // (SkTextBlob *text_blob)
const void * SkTextBlob_bounds(void *text_blob); // (SkTextBlob *text_blob) -> const SkRect *
unsigned int SkTextBlob_uniqueID(void *text_blob); // (SkTextBlob *text_blob) -> uint32_t
int SkTextBlob_getIntercepts(void *text_blob, const void * bounds, void * intervals, const void *paint); // (SkTextBlob *text_blob, const SkScalar bounds[2], SkScalar intervals[], const SkPaint *paint) -> int
unsigned long SkTextBlob_serialize(void *text_blob, const void *procs, void *memory, unsigned long memory_size); // (SkTextBlob *text_blob, const SkSerialProcs *procs, void *memory, size_t memory_size) -> size_t
int SkTextBlob_serialize_2(void *text_blob, const void *procs); // (SkTextBlob *text_blob, const SkSerialProcs *procs) -> sk_data_t
bool SkTextBlob_unique(void *text_blob); // (SkTextBlob *text_blob) -> bool
void SkTextBlob_ref(void *text_blob); // (SkTextBlob *text_blob)
void SkTextBlob_unref(void *text_blob); // (SkTextBlob *text_blob)
void SkTextBlob_deref(void *text_blob); // (SkTextBlob *text_blob)
bool SkTextBlob_refCntGreaterThan(void *text_blob, int threadIsolatedTestCnt); // (SkTextBlob *text_blob, int32_t threadIsolatedTestCnt) -> bool

// static

int SkTextBlob_MakeFromText(const void *text, unsigned long byteLength, const void *font, int encoding); // (const void *text, size_t byteLength, const SkFont *font, SkTextEncoding encoding) -> sk_text_blob_t
int SkTextBlob_MakeFromString(const char *string, const void *font, int encoding); // (const char *string, const SkFont *font, SkTextEncoding encoding) -> sk_text_blob_t
int SkTextBlob_MakeFromPosTextH(const void *text, unsigned long byteLength, const void * xpos, float constY, const void *font, int encoding); // (const void *text, size_t byteLength, const SkScalar xpos[], SkScalar constY, const SkFont *font, SkTextEncoding encoding) -> sk_text_blob_t
int SkTextBlob_MakeFromPosText(const void *text, unsigned long byteLength, const void * pos, const void *font, int encoding); // (const void *text, size_t byteLength, const SkPoint pos[], const SkFont *font, SkTextEncoding encoding) -> sk_text_blob_t
int SkTextBlob_MakeFromRSXform(const void *text, unsigned long byteLength, const void * xform, const void *font, int encoding); // (const void *text, size_t byteLength, const SkRSXform xform[], const SkFont *font, SkTextEncoding encoding) -> sk_text_blob_t
int SkTextBlob_Deserialize(const void *data, unsigned long size, const void *procs); // (const void *data, size_t size, const SkDeserialProcs *procs) -> sk_text_blob_t

#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_SK_TEXT_BLOB_H
