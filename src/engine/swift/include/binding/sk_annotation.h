//
// Created by dolphilia on 2024/01/05.
//

#ifndef RAIA_SKIA_SK_ANNOTATION_H
#define RAIA_SKIA_SK_ANNOTATION_H

#ifdef __cplusplus
extern "C" {
#endif

void SkAnnotation_SkAnnotateLinkToDestination(void *canvas, const void *rect, void *data); // (SkCanvas *canvas, const SkRect *rect, SkData *data)
void SkAnnotation_SkAnnotateNamedDestination(void *canvas, const void *point, void *data); // (SkCanvas *canvas, const SkPoint *point, SkData *data)
void SkAnnotation_SkAnnotateRectWithURL(void *canvas, const void *rect, void *data); // (SkCanvas *canvas, const SkRect *rect, SkData *data)

#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_SK_ANNOTATION_H
