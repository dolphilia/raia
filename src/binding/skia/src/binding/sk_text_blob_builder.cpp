//
// Created by dolphilia on 2024/01/11.
//

#include "sk_text_blob_builder.h"

extern "C" {

SkTextBlobBuilder *SkTextBlobBuilder_new() {
    return new SkTextBlobBuilder();
}

void SkTextBlobBuilder_delete(SkTextBlobBuilder *text_blob_builder) {
    delete text_blob_builder;
}

sk_text_blob_t SkTextBlobBuilder_make(SkTextBlobBuilder *text_blob_builder) {
    return static_sk_text_blob_make(text_blob_builder->make());
}

const SkTextBlobBuilder::RunBuffer * SkTextBlobBuilder_allocRun(SkTextBlobBuilder *text_blob_builder, const SkFont *font, int count, SkScalar x, SkScalar y, const SkRect *bounds) {
    return &text_blob_builder->allocRun(*font, count, x, y, bounds);
}

const SkTextBlobBuilder::RunBuffer * SkTextBlobBuilder_allocRunPosH(SkTextBlobBuilder *text_blob_builder, const SkFont *font, int count, SkScalar y, const SkRect *bounds) {
    return &text_blob_builder->allocRunPosH(*font, count, y, bounds);
}

const SkTextBlobBuilder::RunBuffer * SkTextBlobBuilder_allocRunPos(SkTextBlobBuilder *text_blob_builder, const SkFont *font, int count, const SkRect *bounds) {
    return &text_blob_builder->allocRunPos(*font, count, bounds);
}

const SkTextBlobBuilder::RunBuffer * SkTextBlobBuilder_allocRunRSXform(SkTextBlobBuilder *text_blob_builder, const SkFont *font, int count) {
    return &text_blob_builder->allocRunRSXform(*font, count);
}

const SkTextBlobBuilder::RunBuffer * SkTextBlobBuilder_allocRunText(SkTextBlobBuilder *text_blob_builder, const SkFont *font, int count, SkScalar x, SkScalar y, int textByteCount, const SkRect *bounds) {
    return &text_blob_builder->allocRunText(*font, count, x, y, textByteCount, bounds);
}

const SkTextBlobBuilder::RunBuffer * SkTextBlobBuilder_allocRunTextPosH(SkTextBlobBuilder *text_blob_builder, const SkFont *font, int count, SkScalar y, int textByteCount, const SkRect *bounds) {
    return &text_blob_builder->allocRunTextPosH(*font, count, y, textByteCount, bounds);
}

const SkTextBlobBuilder::RunBuffer * SkTextBlobBuilder_allocRunTextPos(SkTextBlobBuilder *text_blob_builder, const SkFont *font, int count, int textByteCount, const SkRect *bounds) {
    return &text_blob_builder->allocRunTextPos(*font, count, textByteCount, bounds);
}

const SkTextBlobBuilder::RunBuffer * SkTextBlobBuilder_allocRunTextRSXform(SkTextBlobBuilder *text_blob_builder, const SkFont *font, int count, int textByteCount, const SkRect *bounds) {
    return &text_blob_builder->allocRunTextRSXform(*font, count, textByteCount, bounds);
}

}