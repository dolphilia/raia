//
// Created by dolphilia on 2024/02/02.
//

#include "sk_svg_circle.h"

extern "C" {

void SkSVGCircle_delete(SkSVGCircle *svgCircle) {
    delete svgCircle;
}

void SkSVGCircle_appendChild(SkSVGCircle *svgCircle, sk_svg_node_t svg_node) {
    svgCircle->appendChild(static_sk_svg_node_move(svg_node));
}

void SkSVGCircle_setTransform(SkSVGCircle *svgCircle, const SkSVGTransformType *t) {
    svgCircle->setTransform(*t);
}

SkSVGTag SkSVGCircle_tag(SkSVGCircle *svgCircle) {
    return svgCircle->tag();
}

void SkSVGCircle_render(SkSVGCircle *svgCircle, const SkSVGRenderContext *svgRenderContext) {
    svgCircle->render(*svgRenderContext);
}

bool SkSVGCircle_asPaint(SkSVGCircle *svgCircle, const SkSVGRenderContext *svgRenderContext, SkPaint *paint) {
    return svgCircle->asPaint(*svgRenderContext, paint);
}

sk_path_t SkSVGCircle_asPath(SkSVGCircle *svgCircle, const SkSVGRenderContext *svgRenderContext) {
    return static_sk_path_make(svgCircle->asPath(*svgRenderContext));
}

sk_rect_t SkSVGCircle_objectBoundingBox(SkSVGCircle *svgCircle, const SkSVGRenderContext *svgRenderContext) {
    return static_sk_rect_make(svgCircle->objectBoundingBox(*svgRenderContext));
}

void SkSVGCircle_setAttribute(SkSVGCircle *svgCircle, SkSVGAttribute svgAttribute, const SkSVGValue *svgValue) {
    svgCircle->setAttribute(svgAttribute, *svgValue);
}

//bool SkSVGCircle_setAttribute_2(SkSVGCircle *svgCircle, const char *attributeName, const char *attributeValue) {
//    return svgCircle->setAttribute(attributeName, attributeValue);
//}

bool SkSVGCircle_unique(SkSVGCircle *svgCircle) {
    return svgCircle->unique();
}

void SkSVGCircle_ref(SkSVGCircle *svgCircle) {
    svgCircle->ref();
}

void SkSVGCircle_unref(SkSVGCircle *svgCircle) {
    svgCircle->unref();
}

// static

sk_svg_circle_t SkSVGCircle_Make() {
    return static_sk_svg_circle_make(SkSVGCircle::Make());
}

}