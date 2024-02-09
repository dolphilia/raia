//
// Created by dolphilia on 2024/02/06.
//

#include "sk_svg_pattern.h"

extern "C" {

void SkSVGPattern_delete(SkSVGPattern *svgPattern) {
    delete svgPattern;
}

void SkSVGPattern_appendChild(SkSVGPattern *svgPattern, sk_svg_node_t svg_node) {
    svgPattern->appendChild(static_sk_svg_node_move(svg_node));
}

void SkSVGPattern_setTransform(SkSVGPattern *svgPattern, const SkSVGTransformType *t) {
    svgPattern->setTransform(*t);
}

SkSVGTag SkSVGPattern_tag(SkSVGPattern *svgPattern) {
    return svgPattern->tag();
}

void SkSVGPattern_render(SkSVGPattern *svgPattern, const SkSVGRenderContext *svgRenderContext) {
    svgPattern->render(*svgRenderContext);
}

bool SkSVGPattern_asPaint(SkSVGPattern *svgPattern, const SkSVGRenderContext *svgRenderContext, SkPaint *paint) {
    return svgPattern->asPaint(*svgRenderContext, paint);
}

sk_path_t SkSVGPattern_asPath(SkSVGPattern *svgPattern, const SkSVGRenderContext *svgRenderContext) {
    return static_sk_path_make(svgPattern->asPath(*svgRenderContext));
}

sk_rect_t SkSVGPattern_objectBoundingBox(SkSVGPattern *svgPattern, const SkSVGRenderContext *svgRenderContext) {
    return static_sk_rect_make(svgPattern->objectBoundingBox(*svgRenderContext));
}

void SkSVGPattern_setAttribute(SkSVGPattern *svgPattern, SkSVGAttribute svgAttribute, const SkSVGValue *svgValue) {
    svgPattern->setAttribute(svgAttribute, *svgValue);
}

// bool SkSVGPattern_setAttribute(SkSVGPattern *svgPattern, const char *attributeName, const char *attributeValue) {
//     svgPattern->
// }

bool SkSVGPattern_unique(SkSVGPattern *svgPattern) {
    return svgPattern->unique();
}

void SkSVGPattern_ref(SkSVGPattern *svgPattern) {
    svgPattern->ref();
}

void SkSVGPattern_unref(SkSVGPattern *svgPattern) {
    svgPattern->unref();
}

// static

sk_svg_pattern_t SkSVGPattern_Make() {
    return static_sk_svg_pattern_make(SkSVGPattern::Make());
}

}