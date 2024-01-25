//
// Created by dolphilia on 2024/01/13.
//

#ifndef RAIA_SKIA_GR_RECORDING_CONTEXT_H
#define RAIA_SKIA_GR_RECORDING_CONTEXT_H

#include "include/gpu/GrRecordingContext.h"
#include "../static/static_sk_capabilities.h"

extern "C" {
void GrRecordingContext_delete(GrRecordingContext *recordingContext);
bool GrRecordingContext_abandoned(GrRecordingContext *recordingContext);
bool GrRecordingContext_colorTypeSupportedAsSurface(GrRecordingContext *recordingContext, SkColorType colorType);
int GrRecordingContext_maxTextureSize(GrRecordingContext *recordingContext);
int GrRecordingContext_maxRenderTargetSize(GrRecordingContext *recordingContext);
bool GrRecordingContext_colorTypeSupportedAsImage(GrRecordingContext *recordingContext, SkColorType colorType);
bool GrRecordingContext_supportsProtectedContent(GrRecordingContext *recordingContext);
int GrRecordingContext_maxSurfaceSampleCountForColorType(GrRecordingContext *recordingContext, SkColorType colorType);
void GrRecordingContext_skCapabilities(int sk_capabilities_key_out, GrRecordingContext *recordingContext);
//GrRecordingContextPriv GrRecordingContext_priv(GrRecordingContext *recordingContext);
//const GrRecordingContextPriv GrRecordingContext_priv(GrRecordingContext *recordingContext);
}

#endif //RAIA_SKIA_GR_RECORDING_CONTEXT_H
