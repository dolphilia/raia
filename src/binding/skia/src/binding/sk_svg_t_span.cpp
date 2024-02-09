//
// Created by dolphilia on 2024/02/06.
//

#include "sk_svg_t_span.h"

extern "C" {

void SkSVGTSpan_delete(SkSVGTSpan *svgTSpan) {
    delete svgTSpan;
}

void SkSVGTSpan_appendChild(SkSVGTSpan *svgTSpan, sk_svg_node_t svg_node) {
    svgTSpan->appendChild(static_sk_svg_node_move(svg_node));
}

void SkSVGTSpan_renderText(SkSVGTSpan *svgTSpan, const SkSVGRenderContext *svgRenderContext, SkSVGTextContext *svgTextContext, SkSVGXmlSpace svgXmlSpace) {
    return svgTSpan->renderText(*svgRenderContext, svgTextContext, svgXmlSpace);
}

void SkSVGTSpan_setTransform(SkSVGTSpan *svgTSpan, const SkSVGTransformType *t) {
    svgTSpan->setTransform(*t);
}

SkSVGTag SkSVGTSpan_tag(SkSVGTSpan *svgTSpan) {
    return svgTSpan->tag();
}

void SkSVGTSpan_render(SkSVGTSpan *svgTSpan, const SkSVGRenderContext *svgRenderContext) {
    svgTSpan->render(*svgRenderContext);
}

bool SkSVGTSpan_asPaint(SkSVGTSpan *svgTSpan, const SkSVGRenderContext *svgRenderContext, SkPaint *paint) {
    return svgTSpan->asPaint(*svgRenderContext, paint);
}

sk_path_t SkSVGTSpan_asPath(SkSVGTSpan *svgTSpan, const SkSVGRenderContext *svgRenderContext) {
    return static_sk_path_make(svgTSpan->asPath(*svgRenderContext));
}

sk_rect_t SkSVGTSpan_objectBoundingBox(SkSVGTSpan *svgTSpan, const SkSVGRenderContext *svgRenderContext) {
    return static_sk_rect_make(svgTSpan->objectBoundingBox(*svgRenderContext));
}

void SkSVGTSpan_setAttribute(SkSVGTSpan *svgTSpan, SkSVGAttribute svgAttribute, const SkSVGValue *svgValue) {
    svgTSpan->setAttribute(svgAttribute, *svgValue);
}

// bool SkSVGTSpan_setAttribute(SkSVGTSpan *svgTSpan, const char *attributeName, const char *attributeValue) {
//     svgTSpan->
// }

bool SkSVGTSpan_unique(SkSVGTSpan *svgTSpan) {
    return svgTSpan->unique();
}

void SkSVGTSpan_ref(SkSVGTSpan *svgTSpan) {
    svgTSpan->ref();
}

void SkSVGTSpan_unref(SkSVGTSpan *svgTSpan) {
    svgTSpan->unref();
}

// static

//int SkSVGTSpan_Make() {
//    return static_sk_svg_t_span_make(SkSVGTSpan::Make());
//}

}