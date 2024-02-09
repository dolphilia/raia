//
// Created by dolphilia on 2024/02/06.
//

#include "sk_svg_line.h"

extern "C" {

void SkSVGLine_delete(SkSVGLine *svgLine) {
    delete svgLine;
}

void SkSVGLine_appendChild(SkSVGLine *svgLine, sk_svg_node_t svg_node) {
    svgLine->appendChild(static_sk_svg_node_move(svg_node));
}

void SkSVGLine_setTransform(SkSVGLine *svgLine, const SkSVGTransformType *t) {
    svgLine->setTransform(*t);
}

SkSVGTag SkSVGLine_tag(SkSVGLine *svgLine) {
    return svgLine->tag();
}

void SkSVGLine_render(SkSVGLine *svgLine, const SkSVGRenderContext *svgRenderContext) {
    svgLine->render(*svgRenderContext);
}

bool SkSVGLine_asPaint(SkSVGLine *svgLine, const SkSVGRenderContext *svgRenderContext, SkPaint *paint) {
    return svgLine->asPaint(*svgRenderContext, paint);
}

sk_path_t SkSVGLine_asPath(SkSVGLine *svgLine, const SkSVGRenderContext *svgRenderContext) {
    return static_sk_path_make(svgLine->asPath(*svgRenderContext));
}

sk_rect_t SkSVGLine_objectBoundingBox(SkSVGLine *svgLine, const SkSVGRenderContext *svgRenderContext) {
    return static_sk_rect_make(svgLine->objectBoundingBox(*svgRenderContext));
}

void SkSVGLine_setAttribute(SkSVGLine *svgLine, SkSVGAttribute svgAttribute, const SkSVGValue *svgValue) {
    svgLine->setAttribute(svgAttribute, *svgValue);
}

// bool SkSVGLine_setAttribute(SkSVGLine *svgLine, const char *attributeName, const char *attributeValue) {
//     svgLine->
// }

bool SkSVGLine_unique(SkSVGLine *svgLine) {
    return svgLine->unique();
}

void SkSVGLine_ref(SkSVGLine *svgLine) {
    svgLine->ref();
}

void SkSVGLine_unref(SkSVGLine *svgLine) {
    svgLine->unref();
}

// static

sk_svg_line_t SkSVGLine_Make() {
    return static_sk_svg_line_make(SkSVGLine::Make());
}

}