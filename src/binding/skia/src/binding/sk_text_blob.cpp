//
// Created by dolphilia on 2024/01/11.
//

#include "sk_text_blob.h"

extern "C" {

void SkTextBlob_delete(SkTextBlob *text_blob) {
    delete &text_blob;
}

const SkRect * SkTextBlob_bounds(SkTextBlob *text_blob) {
    return &text_blob->bounds();
}

uint32_t SkTextBlob_uniqueID(SkTextBlob *text_blob) {
    return text_blob->uniqueID();
}

int SkTextBlob_getIntercepts(SkTextBlob *text_blob, const SkScalar bounds[2], SkScalar intervals[], const SkPaint *paint) {
    return text_blob->getIntercepts(bounds, intervals, paint);
}

size_t SkTextBlob_serialize(SkTextBlob *text_blob, const SkSerialProcs *procs, void *memory, size_t memory_size) {
    return text_blob->serialize(*procs, memory, memory_size);
}

sk_data_t SkTextBlob_serialize_2(SkTextBlob *text_blob, const SkSerialProcs *procs) {
    return static_sk_data_make(text_blob->serialize(*procs));
}

bool SkTextBlob_unique(SkTextBlob *text_blob) {
    return text_blob->unique();
}

void SkTextBlob_ref(SkTextBlob *text_blob) {
    text_blob->ref();
}

void SkTextBlob_unref(SkTextBlob *text_blob) {
    text_blob->unref();
}

void SkTextBlob_deref(SkTextBlob *text_blob) {
    text_blob->deref();
}

bool SkTextBlob_refCntGreaterThan(SkTextBlob *text_blob, int32_t threadIsolatedTestCnt) {
    return text_blob->refCntGreaterThan(threadIsolatedTestCnt);
}

// static

sk_text_blob_t SkTextBlob_MakeFromText(const void *text, size_t byteLength, const SkFont *font, SkTextEncoding encoding) {
    return static_sk_text_blob_make(SkTextBlob::MakeFromText(text, byteLength, *font, encoding));
}

sk_text_blob_t SkTextBlob_MakeFromString(const char *string, const SkFont *font, SkTextEncoding encoding) {
    return static_sk_text_blob_make(SkTextBlob::MakeFromString(string, *font, encoding));
}

sk_text_blob_t SkTextBlob_MakeFromPosTextH(const void *text, size_t byteLength, const SkScalar xpos[], SkScalar constY, const SkFont *font, SkTextEncoding encoding) {
    return static_sk_text_blob_make(SkTextBlob::MakeFromPosTextH(text, byteLength, xpos, constY, *font, encoding));
}

sk_text_blob_t SkTextBlob_MakeFromPosText(const void *text, size_t byteLength, const SkPoint pos[], const SkFont *font, SkTextEncoding encoding) {
    return static_sk_text_blob_make(SkTextBlob::MakeFromPosText(text, byteLength, pos, *font, encoding));
}

sk_text_blob_t SkTextBlob_MakeFromRSXform(const void *text, size_t byteLength, const SkRSXform xform[], const SkFont *font, SkTextEncoding encoding) {
    return static_sk_text_blob_make(SkTextBlob::MakeFromRSXform(text, byteLength, xform, *font, encoding));
}

sk_text_blob_t SkTextBlob_Deserialize(const void *data, size_t size, const SkDeserialProcs *procs) {
    return static_sk_text_blob_make(SkTextBlob::Deserialize(data, size, *procs));
}

}