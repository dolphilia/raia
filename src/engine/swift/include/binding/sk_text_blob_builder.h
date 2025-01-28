//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_SK_TEXT_BLOB_BUILDER_H
#define RAIA_SKIA_SK_TEXT_BLOB_BUILDER_H

#ifdef __cplusplus
extern "C" {
#endif

void * SkTextBlobBuilder_new(); // () -> SkTextBlobBuilder *
void SkTextBlobBuilder_delete(void *text_blob_builder); // (SkTextBlobBuilder *text_blob_builder)
int SkTextBlobBuilder_make(void *text_blob_builder); // (SkTextBlobBuilder *text_blob_builder) -> sk_text_blob_t
const void * SkTextBlobBuilder_allocRun(void *text_blob_builder, const void *font, int count, float x, float y, const void *bounds); // (SkTextBlobBuilder *text_blob_builder, const SkFont *font, int count, SkScalar x, SkScalar y, const SkRect *bounds) -> const SkTextBlobBuilder::RunBuffer *
const void * SkTextBlobBuilder_allocRunPosH(void *text_blob_builder, const void *font, int count, float y, const void *bounds); // (SkTextBlobBuilder *text_blob_builder, const SkFont *font, int count, SkScalar y, const SkRect *bounds) -> const SkTextBlobBuilder::RunBuffer *
const void * SkTextBlobBuilder_allocRunPos(void *text_blob_builder, const void *font, int count, const void *bounds); // (SkTextBlobBuilder *text_blob_builder, const SkFont *font, int count, const SkRect *bounds) -> const SkTextBlobBuilder::RunBuffer *
const void * SkTextBlobBuilder_allocRunRSXform(void *text_blob_builder, const void *font, int count); // (SkTextBlobBuilder *text_blob_builder, const SkFont *font, int count) -> const SkTextBlobBuilder::RunBuffer *
const void * SkTextBlobBuilder_allocRunText(void *text_blob_builder, const void *font, int count, float x, float y, int textByteCount, const void *bounds); // (SkTextBlobBuilder *text_blob_builder, const SkFont *font, int count, SkScalar x, SkScalar y, int textByteCount, const SkRect *bounds) -> const SkTextBlobBuilder::RunBuffer *
const void * SkTextBlobBuilder_allocRunTextPosH(void *text_blob_builder, const void *font, int count, float y, int textByteCount, const void *bounds); // (SkTextBlobBuilder *text_blob_builder, const SkFont *font, int count, SkScalar y, int textByteCount, const SkRect *bounds) -> const SkTextBlobBuilder::RunBuffer *
const void * SkTextBlobBuilder_allocRunTextPos(void *text_blob_builder, const void *font, int count, int textByteCount, const void *bounds); // (SkTextBlobBuilder *text_blob_builder, const SkFont *font, int count, int textByteCount, const SkRect *bounds) -> const SkTextBlobBuilder::RunBuffer *
const void * SkTextBlobBuilder_allocRunTextRSXform(void *text_blob_builder, const void *font, int count, int textByteCount, const void *bounds); // (SkTextBlobBuilder *text_blob_builder, const SkFont *font, int count, int textByteCount, const SkRect *bounds) -> const SkTextBlobBuilder::RunBuffer *

#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_SK_TEXT_BLOB_BUILDER_H
