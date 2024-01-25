//
// Created by dolphilia on 2024/01/11.
//

#include "sk_text_blob.h"

extern "C" {

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

void SkTextBlob_serialize_2(int sk_data_key_out, SkTextBlob *text_blob, const SkSerialProcs *procs) {
    static_sk_data_set(sk_data_key_out, text_blob->serialize(*procs));
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

void SkTextBlob_MakeFromText(int sk_text_blob_key_out, const void *text, size_t byteLength, const SkFont *font, SkTextEncoding encoding) {
    static_sk_text_blob_set(sk_text_blob_key_out, SkTextBlob::MakeFromText(text, byteLength, *font, encoding));
}

void SkTextBlob_MakeFromString(int sk_text_blob_key_out, const char *string, const SkFont *font, SkTextEncoding encoding) {
    static_sk_text_blob_set(sk_text_blob_key_out, SkTextBlob::MakeFromString(string, *font, encoding));
}

void SkTextBlob_MakeFromPosTextH(int sk_text_blob_key_out, const void *text, size_t byteLength,
                                 const SkScalar xpos[], SkScalar constY, const SkFont *font, SkTextEncoding encoding) {
    static_sk_text_blob_set(sk_text_blob_key_out, SkTextBlob::MakeFromPosTextH(text, byteLength, xpos, constY, *font, encoding));
}

void SkTextBlob_MakeFromPosText(int sk_text_blob_key_out, const void *text, size_t byteLength,
                                const SkPoint pos[], const SkFont *font, SkTextEncoding encoding) {
    static_sk_text_blob_set(sk_text_blob_key_out, SkTextBlob::MakeFromPosText(text, byteLength, pos, *font, encoding));
}

void SkTextBlob_MakeFromRSXform(int sk_text_blob_key_out, const void *text, size_t byteLength,
                                const SkRSXform xform[], const SkFont *font, SkTextEncoding encoding) {
    static_sk_text_blob_set(sk_text_blob_key_out, SkTextBlob::MakeFromRSXform(text, byteLength, xform, *font, encoding));
}

void SkTextBlob_Deserialize(int sk_text_blob_key_out, const void *data, size_t size, const SkDeserialProcs *procs) {
    static_sk_text_blob_set(sk_text_blob_key_out, SkTextBlob::Deserialize(data, size, *procs));
}

}