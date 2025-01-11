//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_SK_TEXT_BLOB_BUILDER_H
#define RAIA_SKIA_SK_TEXT_BLOB_BUILDER_H

#include "include/core/SkTextBlob.h"
#include "../static/static_sk_text_blob.h"
#include "export_api.h"

extern "C" {
RAIA_API SkTextBlobBuilder *SkTextBlobBuilder_new();
RAIA_API void SkTextBlobBuilder_delete(SkTextBlobBuilder *text_blob_builder);
RAIA_API sk_text_blob_t SkTextBlobBuilder_make(SkTextBlobBuilder *text_blob_builder);
RAIA_API const SkTextBlobBuilder::RunBuffer * SkTextBlobBuilder_allocRun(SkTextBlobBuilder *text_blob_builder, const SkFont *font, int count, SkScalar x, SkScalar y, const SkRect *bounds);
RAIA_API const SkTextBlobBuilder::RunBuffer * SkTextBlobBuilder_allocRunPosH(SkTextBlobBuilder *text_blob_builder, const SkFont *font, int count, SkScalar y, const SkRect *bounds);
RAIA_API const SkTextBlobBuilder::RunBuffer * SkTextBlobBuilder_allocRunPos(SkTextBlobBuilder *text_blob_builder, const SkFont *font, int count, const SkRect *bounds);
RAIA_API const SkTextBlobBuilder::RunBuffer * SkTextBlobBuilder_allocRunRSXform(SkTextBlobBuilder *text_blob_builder, const SkFont *font, int count);
RAIA_API const SkTextBlobBuilder::RunBuffer * SkTextBlobBuilder_allocRunText(SkTextBlobBuilder *text_blob_builder, const SkFont *font, int count, SkScalar x, SkScalar y, int textByteCount, const SkRect *bounds);
RAIA_API const SkTextBlobBuilder::RunBuffer * SkTextBlobBuilder_allocRunTextPosH(SkTextBlobBuilder *text_blob_builder, const SkFont *font, int count, SkScalar y, int textByteCount, const SkRect *bounds);
RAIA_API const SkTextBlobBuilder::RunBuffer * SkTextBlobBuilder_allocRunTextPos(SkTextBlobBuilder *text_blob_builder, const SkFont *font, int count, int textByteCount, const SkRect *bounds);
RAIA_API const SkTextBlobBuilder::RunBuffer * SkTextBlobBuilder_allocRunTextRSXform(SkTextBlobBuilder *text_blob_builder, const SkFont *font, int count, int textByteCount, const SkRect *bounds);
}

#endif //RAIA_SKIA_SK_TEXT_BLOB_BUILDER_H
