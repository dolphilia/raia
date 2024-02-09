//
// Created by dolphilia on 2024/02/06.
//

#include "sk_svg_linear_gradient.h"

extern "C" {

void SkSVGLinearGradient_delete(SkSVGLinearGradient *svgLinearGradient) {
    delete svgLinearGradient;
}

void SkSVGLinearGradient_appendChild(SkSVGLinearGradient *svgLinearGradient, sk_svg_node_t svg_node) {
    svgLinearGradient->appendChild(static_sk_svg_node_move(svg_node));
}

void SkSVGLinearGradient_setTransform(SkSVGLinearGradient *svgLinearGradient, const SkSVGTransformType *t) {
    svgLinearGradient->setTransform(*t);
}

SkSVGTag SkSVGLinearGradient_tag(SkSVGLinearGradient *svgLinearGradient) {
    return svgLinearGradient->tag();
}

void SkSVGLinearGradient_render(SkSVGLinearGradient *svgLinearGradient, const SkSVGRenderContext *svgRenderContext) {
    svgLinearGradient->render(*svgRenderContext);
}

bool SkSVGLinearGradient_asPaint(SkSVGLinearGradient *svgLinearGradient, const SkSVGRenderContext *svgRenderContext, SkPaint *paint) {
    return svgLinearGradient->asPaint(*svgRenderContext, paint);
}

sk_path_t SkSVGLinearGradient_asPath(SkSVGLinearGradient *svgLinearGradient, const SkSVGRenderContext *svgRenderContext) {
    return static_sk_path_make(svgLinearGradient->asPath(*svgRenderContext));
}

sk_rect_t SkSVGLinearGradient_objectBoundingBox(SkSVGLinearGradient *svgLinearGradient, const SkSVGRenderContext *svgRenderContext) {
    return static_sk_rect_make(svgLinearGradient->objectBoundingBox(*svgRenderContext));
}

void SkSVGLinearGradient_setAttribute(SkSVGLinearGradient *svgLinearGradient, SkSVGAttribute svgAttribute, const SkSVGValue *svgValue) {
    svgLinearGradient->setAttribute(svgAttribute, *svgValue);
}

// bool SkSVGLinearGradient_setAttribute(SkSVGLinearGradient *svgLinearGradient, const char *attributeName, const char *attributeValue) {
//     svgLinearGradient->
// }

bool SkSVGLinearGradient_unique(SkSVGLinearGradient *svgLinearGradient) {
    return svgLinearGradient->unique();
}

void SkSVGLinearGradient_ref(SkSVGLinearGradient *svgLinearGradient) {
    svgLinearGradient->ref();
}

void SkSVGLinearGradient_unref(SkSVGLinearGradient *svgLinearGradient) {
    svgLinearGradient->unref();
}

// static

sk_svg_linear_gradient_t SkSVGLinearGradient_Make() {
    return static_sk_svg_linear_gradient_make(SkSVGLinearGradient::Make());
}

}