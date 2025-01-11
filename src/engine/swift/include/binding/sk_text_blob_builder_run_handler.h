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
RAIA_API SkTextBlobBuilderRunHandler *SkTextBlobBuilderRunHandler_new(const char *utf8Text, sk_point_t offset);
RAIA_API void SkTextBlobBuilderRunHandler_delete(SkTextBlobBuilderRunHandler *text_blob_builder_run_handler);
RAIA_API sk_text_blob_t SkTextBlobBuilderRunHandler_makeBlob(SkTextBlobBuilderRunHandler *text_blob_builder_run_handler);
RAIA_API sk_point_t SkTextBlobBuilderRunHandler_endPoint(SkTextBlobBuilderRunHandler *text_blob_builder_run_handler);
RAIA_API void SkTextBlobBuilderRunHandler_beginLine(SkTextBlobBuilderRunHandler *text_blob_builder_run_handler);
RAIA_API void SkTextBlobBuilderRunHandler_runInfo(SkTextBlobBuilderRunHandler *text_blob_builder_run_handler, const SkTextBlobBuilderRunHandler::RunInfo *run_info);
RAIA_API void SkTextBlobBuilderRunHandler_commitRunInfo(SkTextBlobBuilderRunHandler *text_blob_builder_run_handler);
RAIA_API sk_shaper_run_handler_buffer_t SkTextBlobBuilderRunHandler_runBuffer(SkTextBlobBuilderRunHandler *text_blob_builder_run_handler, const SkTextBlobBuilderRunHandler::RunInfo *run_info);
RAIA_API void SkTextBlobBuilderRunHandler_commitRunBuffer(SkTextBlobBuilderRunHandler *text_blob_builder_run_handler, const SkTextBlobBuilderRunHandler::RunInfo *run_info);
RAIA_API void SkTextBlobBuilderRunHandler_commitLine(SkTextBlobBuilderRunHandler *text_blob_builder_run_handler);
}

#endif //RAIA_SKIA_SK_TEXT_BLOB_BUILDER_RUN_HANDLER_H
