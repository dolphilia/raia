//
// Created by dolphilia on 2024/02/06.
//

#include "sk_svg_text.h"

extern "C" {

void SkSVGText_delete(SkSVGText *svgText) {
    delete svgText;
}

void SkSVGText_appendChild(SkSVGText *svgText, sk_svg_node_t svg_node) {
    svgText->appendChild(static_sk_svg_node_move(svg_node));
}

void SkSVGText_renderText(SkSVGText *svgText, const SkSVGRenderContext &svgRenderContext, SkSVGTextContext *svgTextContext, SkSVGXmlSpace svgXmlSpace) {
    return svgText->renderText(svgRenderContext, svgTextContext, svgXmlSpace);
}

void SkSVGText_setTransform(SkSVGText *svgText, const SkSVGTransformType *t) {
    svgText->setTransform(*t);
}

SkSVGTag SkSVGText_tag(SkSVGText *svgText) {
    return svgText->tag();
}

void SkSVGText_render(SkSVGText *svgText, const SkSVGRenderContext *svgRenderContext) {
    svgText->render(*svgRenderContext);
}

bool SkSVGText_asPaint(SkSVGText *svgText, const SkSVGRenderContext *svgRenderContext, SkPaint *paint) {
    return svgText->asPaint(*svgRenderContext, paint);
}

sk_path_t SkSVGText_asPath(SkSVGText *svgText, const SkSVGRenderContext *svgRenderContext) {
    return static_sk_path_make(svgText->asPath(*svgRenderContext));
}

sk_rect_t SkSVGText_objectBoundingBox(SkSVGText *svgText, const SkSVGRenderContext *svgRenderContext) {
    return static_sk_rect_make(svgText->objectBoundingBox(*svgRenderContext));
}

void SkSVGText_setAttribute(SkSVGText *svgText, SkSVGAttribute svgAttribute, const SkSVGValue *svgValue) {
    svgText->setAttribute(svgAttribute, *svgValue);
}

// bool SkSVGText_setAttribute(SkSVGText *svgText, const char *attributeName, const char *attributeValue) {
//     svgText->
// }

bool SkSVGText_unique(SkSVGText *svgText) {
    return svgText->unique();
}

void SkSVGText_ref(SkSVGText *svgText) {
    svgText->ref();
}

void SkSVGText_unref(SkSVGText *svgText) {
    svgText->unref();
}

// static

sk_svg_text_t SkSVGText_Make() {
    return static_sk_svg_text_make(SkSVGText::Make());
}

}