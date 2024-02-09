//
// Created by dolphilia on 2024/01/13.
//

#include "gr_recording_context.h"

extern "C" {

void GrRecordingContext_delete(GrRecordingContext *recordingContext) {
    delete recordingContext;
}

bool GrRecordingContext_abandoned(GrRecordingContext *recordingContext) {
    return recordingContext->abandoned();
}

bool GrRecordingContext_colorTypeSupportedAsSurface(GrRecordingContext *recordingContext, SkColorType colorType) {
    return recordingContext->colorTypeSupportedAsSurface(colorType);
}

int GrRecordingContext_maxTextureSize(GrRecordingContext *recordingContext) {
    return recordingContext->maxTextureSize();
}

int GrRecordingContext_maxRenderTargetSize(GrRecordingContext *recordingContext) {
    return recordingContext->maxRenderTargetSize();
}

bool GrRecordingContext_colorTypeSupportedAsImage(GrRecordingContext *recordingContext, SkColorType colorType) {
    return recordingContext->colorTypeSupportedAsImage(colorType);
}

bool GrRecordingContext_supportsProtectedContent(GrRecordingContext *recordingContext) {
    return recordingContext->supportsProtectedContent();
}

int GrRecordingContext_maxSurfaceSampleCountForColorType(GrRecordingContext *recordingContext, SkColorType colorType) {
    return recordingContext->maxSurfaceSampleCountForColorType(colorType);
}

const_sk_capabilities_t GrRecordingContext_skCapabilities(GrRecordingContext *recordingContext) {
    return static_const_sk_capabilities_make(recordingContext->skCapabilities());
}

//GrRecordingContextPriv GrRecordingContext_priv(GrRecordingContext *recordingContext) {
//    return recordingContext->priv();
//}

//const GrRecordingContextPriv GrRecordingContext_priv(GrRecordingContext *recordingContext) {
//    return recordingContext->priv();
//}

}