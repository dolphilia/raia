//
// Created by dolphilia on 2024/01/05.
//

#ifndef RAIA_SKIA_SK_ANNOTATION_H
#define RAIA_SKIA_SK_ANNOTATION_H

#include "include/core/SkCanvas.h"
#include "include/core/SkAnnotation.h"
#include "export_api.h"

extern "C" {
RAIA_API void SkAnnotation_SkAnnotateLinkToDestination(SkCanvas *canvas, const SkRect *rect, SkData *data);
RAIA_API void SkAnnotation_SkAnnotateNamedDestination(SkCanvas *canvas, const SkPoint *point, SkData *data);
RAIA_API void SkAnnotation_SkAnnotateRectWithURL(SkCanvas *canvas, const SkRect *rect, SkData *data);
}

#endif //RAIA_SKIA_SK_ANNOTATION_H
