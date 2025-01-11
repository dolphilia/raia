//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_SK_TEXT_BLOB_H
#define RAIA_SKIA_SK_TEXT_BLOB_H

#include "include/core/SkTextBlob.h"
#include "../static/static_sk_data.h"
#include "../static/static_sk_text_blob.h"
#include "export_api.h"

extern "C" {
RAIA_API void SkTextBlob_delete(SkTextBlob *text_blob);
RAIA_API const SkRect * SkTextBlob_bounds(SkTextBlob *text_blob);
RAIA_API uint32_t SkTextBlob_uniqueID(SkTextBlob *text_blob);
RAIA_API int SkTextBlob_getIntercepts(SkTextBlob *text_blob, const SkScalar bounds[2], SkScalar intervals[], const SkPaint *paint);
RAIA_API size_t SkTextBlob_serialize(SkTextBlob *text_blob, const SkSerialProcs *procs, void *memory, size_t memory_size);
RAIA_API sk_data_t SkTextBlob_serialize_2(SkTextBlob *text_blob, const SkSerialProcs *procs);
RAIA_API bool SkTextBlob_unique(SkTextBlob *text_blob);
RAIA_API void SkTextBlob_ref(SkTextBlob *text_blob);
RAIA_API void SkTextBlob_unref(SkTextBlob *text_blob);
RAIA_API void SkTextBlob_deref(SkTextBlob *text_blob);
RAIA_API bool SkTextBlob_refCntGreaterThan(SkTextBlob *text_blob, int32_t threadIsolatedTestCnt);
// static
RAIA_API sk_text_blob_t SkTextBlob_MakeFromText(const void *text, size_t byteLength, const SkFont *font, SkTextEncoding encoding);
RAIA_API sk_text_blob_t SkTextBlob_MakeFromString(const char *string, const SkFont *font, SkTextEncoding encoding);
RAIA_API sk_text_blob_t SkTextBlob_MakeFromPosTextH(const void *text, size_t byteLength, const SkScalar xpos[], SkScalar constY, const SkFont *font, SkTextEncoding encoding);
RAIA_API sk_text_blob_t SkTextBlob_MakeFromPosText(const void *text, size_t byteLength, const SkPoint pos[], const SkFont *font, SkTextEncoding encoding);
RAIA_API sk_text_blob_t SkTextBlob_MakeFromRSXform(const void *text, size_t byteLength, const SkRSXform xform[], const SkFont *font, SkTextEncoding encoding);
RAIA_API sk_text_blob_t SkTextBlob_Deserialize(const void *data, size_t size, const SkDeserialProcs *procs);
}

#endif //RAIA_SKIA_SK_TEXT_BLOB_H
