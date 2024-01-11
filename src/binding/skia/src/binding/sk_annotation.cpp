//
// Created by dolphilia on 2024/01/05.
//

#include "sk_annotation.h"

extern "C" {

// SK_API

void SkAnnotation_SkAnnotateLinkToDestination(SkCanvas * canvas, const SkRect * rect, SkData * data) {
    SkAnnotateLinkToDestination(canvas, *rect, data);
}

void SkAnnotation_SkAnnotateNamedDestination(SkCanvas * canvas, const SkPoint * point, SkData * data) {
    SkAnnotateNamedDestination(canvas, *point, data);
}

void SkAnnotation_SkAnnotateRectWithURL(SkCanvas * canvas, const SkRect * rect, SkData * data) {
    SkAnnotateRectWithURL(canvas, *rect, data);
}

}