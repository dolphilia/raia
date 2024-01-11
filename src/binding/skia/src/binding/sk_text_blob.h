//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_SK_TEXT_BLOB_H
#define RAIA_SKIA_SK_TEXT_BLOB_H

#include "include/core/SkTextBlob.h"
#include "../static/static_sk_data.h"
#include "../static/static_sk_text_blob.h"

extern "C" {
const SkRect * SkTextBlob_bounds(SkTextBlob *text_blob);
uint32_t SkTextBlob_uniqueID(SkTextBlob *text_blob);
int SkTextBlob_getIntercepts(SkTextBlob *text_blob, const SkScalar bounds[2], SkScalar intervals[], const SkPaint *paint);
size_t SkTextBlob_serialize(SkTextBlob *text_blob, const SkSerialProcs &procs, void *memory, size_t memory_size);
void SkTextBlob_serialize_2(const char *sk_data_key_out, SkTextBlob *text_blob, const SkSerialProcs &procs);
bool SkTextBlob_unique(SkTextBlob *text_blob);
void SkTextBlob_ref(SkTextBlob *text_blob);
void SkTextBlob_unref(SkTextBlob *text_blob);
void SkTextBlob_deref(SkTextBlob *text_blob);
bool SkTextBlob_refCntGreaterThan(SkTextBlob *text_blob, int32_t threadIsolatedTestCnt);
// static
void SkTextBlob_MakeFromText(const char *sk_text_blob_key_out, const void *text, size_t byteLength, const SkFont &font, SkTextEncoding encoding);
void SkTextBlob_MakeFromString(const char *sk_text_blob_key_out, const char *string, const SkFont &font, SkTextEncoding encoding);
void SkTextBlob_MakeFromPosTextH(const char *sk_text_blob_key_out, const void *text, size_t byteLength, const SkScalar xpos[], SkScalar constY, const SkFont &font, SkTextEncoding encoding);
void SkTextBlob_MakeFromPosText(const char *sk_text_blob_key_out, const void *text, size_t byteLength, const SkPoint pos[], const SkFont &font, SkTextEncoding encoding);
void SkTextBlob_MakeFromRSXform(const char *sk_text_blob_key_out, const void *text, size_t byteLength, const SkRSXform xform[], const SkFont &font, SkTextEncoding encoding);
void SkTextBlob_Deserialize(const char *sk_text_blob_key_out, const void *data, size_t size, const SkDeserialProcs &procs);
}

#endif //RAIA_SKIA_SK_TEXT_BLOB_H
