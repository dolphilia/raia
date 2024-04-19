//
// Created by dolphilia on 2024/01/11.
//

#include "sk_text_blob_builder_run_handler.h"

extern "C" {

SkTextBlobBuilderRunHandler *SkTextBlobBuilderRunHandler_new(const char *utf8Text, sk_point_t offset) {
    return new SkTextBlobBuilderRunHandler(utf8Text, static_sk_point_get(offset));
}

void SkTextBlobBuilderRunHandler_delete(SkTextBlobBuilderRunHandler *text_blob_builder_run_handler) {
    delete text_blob_builder_run_handler;
}

sk_text_blob_t SkTextBlobBuilderRunHandler_makeBlob(SkTextBlobBuilderRunHandler *text_blob_builder_run_handler) {
    return static_sk_text_blob_make(text_blob_builder_run_handler->makeBlob());
}

sk_point_t SkTextBlobBuilderRunHandler_endPoint(SkTextBlobBuilderRunHandler *text_blob_builder_run_handler) {
    return static_sk_point_make(text_blob_builder_run_handler->endPoint());
}

void SkTextBlobBuilderRunHandler_beginLine(SkTextBlobBuilderRunHandler *text_blob_builder_run_handler) {
    text_blob_builder_run_handler->beginLine();
}

void SkTextBlobBuilderRunHandler_runInfo(SkTextBlobBuilderRunHandler *text_blob_builder_run_handler, const SkTextBlobBuilderRunHandler::RunInfo *run_info) {
    text_blob_builder_run_handler->runInfo(*run_info);
}
void SkTextBlobBuilderRunHandler_commitRunInfo(SkTextBlobBuilderRunHandler *text_blob_builder_run_handler) {
    text_blob_builder_run_handler->commitRunInfo();
}

sk_shaper_run_handler_buffer_t SkTextBlobBuilderRunHandler_runBuffer(SkTextBlobBuilderRunHandler *text_blob_builder_run_handler, const SkTextBlobBuilderRunHandler::RunInfo *run_info) {
    return static_sk_shaper_run_handler_buffer_make(text_blob_builder_run_handler->runBuffer(*run_info));
}

void SkTextBlobBuilderRunHandler_commitRunBuffer(SkTextBlobBuilderRunHandler *text_blob_builder_run_handler, const SkTextBlobBuilderRunHandler::RunInfo *run_info) {
    text_blob_builder_run_handler->commitRunBuffer(*run_info);
}

void SkTextBlobBuilderRunHandler_commitLine(SkTextBlobBuilderRunHandler *text_blob_builder_run_handler) {
    text_blob_builder_run_handler->commitLine();
}

}