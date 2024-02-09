//
// Created by dolphilia on 2024/02/06.
//

#include "sk_svg_gradient.h"

extern "C" {

void SkSVGGradient_delete(SkSVGGradient *svgGradient) {
    delete svgGradient;
}

void SkSVGGradient_appendChild(SkSVGGradient *svgGradient, sk_svg_node_t svg_node) {
    svgGradient->appendChild(static_sk_svg_node_move(svg_node));
}

void SkSVGGradient_setTransform(SkSVGGradient *svgGradient, const SkSVGTransformType *t) {
    svgGradient->setTransform(*t);
}

SkSVGTag SkSVGGradient_tag(SkSVGGradient *svgGradient) {
    return svgGradient->tag();
}

void SkSVGGradient_render(SkSVGGradient *svgGradient, const SkSVGRenderContext *svgRenderContext) {
    svgGradient->render(*svgRenderContext);
}

bool SkSVGGradient_asPaint(SkSVGGradient *svgGradient, const SkSVGRenderContext *svgRenderContext, SkPaint *paint) {
    return svgGradient->asPaint(*svgRenderContext, paint);
}

sk_path_t SkSVGGradient_asPath(SkSVGGradient *svgGradient, const SkSVGRenderContext *svgRenderContext) {
    return static_sk_path_make(svgGradient->asPath(*svgRenderContext));
}

sk_rect_t SkSVGGradient_objectBoundingBox(SkSVGGradient *svgGradient, const SkSVGRenderContext *svgRenderContext) {
    return static_sk_rect_make(svgGradient->objectBoundingBox(*svgRenderContext));
}

void SkSVGGradient_setAttribute(SkSVGGradient *svgGradient, SkSVGAttribute svgAttribute, const SkSVGValue *svgValue) {
    svgGradient->setAttribute(svgAttribute, *svgValue);
}

// bool SkSVGGradient_setAttribute(SkSVGGradient *svgGradient, const char *attributeName, const char *attributeValue) {
//     svgGradient->
// }

bool SkSVGGradient_unique(SkSVGGradient *svgGradient) {
    return svgGradient->unique();
}

void SkSVGGradient_ref(SkSVGGradient *svgGradient) {
    svgGradient->ref();
}

void SkSVGGradient_unref(SkSVGGradient *svgGradient) {
    svgGradient->unref();
}

}