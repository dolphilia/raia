//
// Created by dolphilia on 2024/02/06.
//

#include "sk_svg_radial_gradient.h"

extern "C" {

void SkSVGRadialGradient_delete(SkSVGRadialGradient *svgRadialGradient) {
    delete svgRadialGradient;
}

void SkSVGRadialGradient_appendChild(SkSVGRadialGradient *svgRadialGradient, sk_svg_node_t svg_node) {
    svgRadialGradient->appendChild(static_sk_svg_node_move(svg_node));
}

void SkSVGRadialGradient_setTransform(SkSVGRadialGradient *svgRadialGradient, const SkSVGTransformType *t) {
    svgRadialGradient->setTransform(*t);
}

SkSVGTag SkSVGRadialGradient_tag(SkSVGRadialGradient *svgRadialGradient) {
    return svgRadialGradient->tag();
}

void SkSVGRadialGradient_render(SkSVGRadialGradient *svgRadialGradient, const SkSVGRenderContext *svgRenderContext) {
    svgRadialGradient->render(*svgRenderContext);
}

bool SkSVGRadialGradient_asPaint(SkSVGRadialGradient *svgRadialGradient, const SkSVGRenderContext *svgRenderContext, SkPaint *paint) {
    return svgRadialGradient->asPaint(*svgRenderContext, paint);
}

sk_path_t SkSVGRadialGradient_asPath(SkSVGRadialGradient *svgRadialGradient, const SkSVGRenderContext *svgRenderContext) {
    return static_sk_path_make(svgRadialGradient->asPath(*svgRenderContext));
}

sk_rect_t SkSVGRadialGradient_objectBoundingBox(SkSVGRadialGradient *svgRadialGradient, const SkSVGRenderContext *svgRenderContext) {
    return static_sk_rect_make(svgRadialGradient->objectBoundingBox(*svgRenderContext));
}

void SkSVGRadialGradient_setAttribute(SkSVGRadialGradient *svgRadialGradient, SkSVGAttribute svgAttribute, const SkSVGValue *svgValue) {
    svgRadialGradient->setAttribute(svgAttribute, *svgValue);
}

// bool SkSVGRadialGradient_setAttribute(SkSVGRadialGradient *svgRadialGradient, const char *attributeName, const char *attributeValue) {
//     svgRadialGradient->
// }

bool SkSVGRadialGradient_unique(SkSVGRadialGradient *svgRadialGradient) {
    return svgRadialGradient->unique();
}

void SkSVGRadialGradient_ref(SkSVGRadialGradient *svgRadialGradient) {
    svgRadialGradient->ref();
}

void SkSVGRadialGradient_unref(SkSVGRadialGradient *svgRadialGradient) {
    svgRadialGradient->unref();
}

// static

sk_svg_radial_gradient_t SkSVGRadialGradient_Make() {
    return static_sk_svg_radial_gradient_make(SkSVGRadialGradient::Make());
}

}