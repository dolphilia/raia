//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_SK_TEXT_BLOB_BUILDER_RUN_HANDLER_H
#define RAIA_SKIA_SK_TEXT_BLOB_BUILDER_RUN_HANDLER_H

#include "modules/skshaper/include/SkShaper.h"
#include "../static/static_sk_text_blob.h"
#include "../static/static_sk_shaper_run_handler_buffer.h"
#include "../static/static_sk_point.h"

extern "C" {
SkTextBlobBuilderRunHandler *SkTextBlobBuilderRunHandler_new(const char *utf8Text, sk_point_t offset);
void SkTextBlobBuilderRunHandler_delete(SkTextBlobBuilderRunHandler *text_blob_builder_run_handler);
sk_text_blob_t SkTextBlobBuilderRunHandler_makeBlob(SkTextBlobBuilderRunHandler *text_blob_builder_run_handler);
sk_point_t SkTextBlobBuilderRunHandler_endPoint(SkTextBlobBuilderRunHandler *text_blob_builder_run_handler);
void SkTextBlobBuilderRunHandler_beginLine(SkTextBlobBuilderRunHandler *text_blob_builder_run_handler);
void SkTextBlobBuilderRunHandler_runInfo(SkTextBlobBuilderRunHandler *text_blob_builder_run_handler, const SkTextBlobBuilderRunHandler::RunInfo *run_info);
void SkTextBlobBuilderRunHandler_commitRunInfo(SkTextBlobBuilderRunHandler *text_blob_builder_run_handler);
sk_shaper_run_handler_buffer_t SkTextBlobBuilderRunHandler_runBuffer(SkTextBlobBuilderRunHandler *text_blob_builder_run_handler, const SkTextBlobBuilderRunHandler::RunInfo *run_info);
void SkTextBlobBuilderRunHandler_commitRunBuffer(SkTextBlobBuilderRunHandler *text_blob_builder_run_handler, const SkTextBlobBuilderRunHandler::RunInfo *run_info);
void SkTextBlobBuilderRunHandler_commitLine(SkTextBlobBuilderRunHandler *text_blob_builder_run_handler);
}

#endif //RAIA_SKIA_SK_TEXT_BLOB_BUILDER_RUN_HANDLER_H
