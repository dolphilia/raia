//
// Created by dolphilia on 2024/02/06.
//

#include "sk_svg_text_literal.h"

extern "C" {

void SkSVGTextLiteral_delete(SkSVGTextLiteral *svgTextLiteral) {
    delete svgTextLiteral;
}

void SkSVGTextLiteral_renderText(SkSVGTextLiteral *svgTextLiteral, const SkSVGRenderContext &svgRenderContext, SkSVGTextContext *svgTextContext, SkSVGXmlSpace svgXmlSpace) {
    return svgTextLiteral->renderText(svgRenderContext, svgTextContext, svgXmlSpace);
}

void SkSVGTextLiteral_setTransform(SkSVGTextLiteral *svgTextLiteral, const SkSVGTransformType *t) {
    svgTextLiteral->setTransform(*t);
}

SkSVGTag SkSVGTextLiteral_tag(SkSVGTextLiteral *svgTextLiteral) {
    return svgTextLiteral->tag();
}

void SkSVGTextLiteral_render(SkSVGTextLiteral *svgTextLiteral, const SkSVGRenderContext *svgRenderContext) {
    svgTextLiteral->render(*svgRenderContext);
}

bool SkSVGTextLiteral_asPaint(SkSVGTextLiteral *svgTextLiteral, const SkSVGRenderContext *svgRenderContext, SkPaint *paint) {
    return svgTextLiteral->asPaint(*svgRenderContext, paint);
}

sk_path_t SkSVGTextLiteral_asPath(SkSVGTextLiteral *svgTextLiteral, const SkSVGRenderContext *svgRenderContext) {
    return static_sk_path_make(svgTextLiteral->asPath(*svgRenderContext));
}

sk_rect_t SkSVGTextLiteral_objectBoundingBox(SkSVGTextLiteral *svgTextLiteral, const SkSVGRenderContext *svgRenderContext) {
    return static_sk_rect_make(svgTextLiteral->objectBoundingBox(*svgRenderContext));
}

void SkSVGTextLiteral_setAttribute(SkSVGTextLiteral *svgTextLiteral, SkSVGAttribute svgAttribute, const SkSVGValue *svgValue) {
    svgTextLiteral->setAttribute(svgAttribute, *svgValue);
}

// bool SkSVGTextLiteral_setAttribute(SkSVGTextLiteral *svgTextLiteral, const char *attributeName, const char *attributeValue) {
//     svgTextLiteral->
// }

bool SkSVGTextLiteral_parseAndSetAttribute(SkSVGTextLiteral *svgTextLiteral, const char *name, const char *value) {
    return svgTextLiteral->parseAndSetAttribute(name, value);
}

bool SkSVGTextLiteral_unique(SkSVGTextLiteral *svgTextLiteral) {
    return svgTextLiteral->unique();
}

void SkSVGTextLiteral_ref(SkSVGTextLiteral *svgTextLiteral) {
    svgTextLiteral->ref();
}

void SkSVGTextLiteral_unref(SkSVGTextLiteral *svgTextLiteral) {
    svgTextLiteral->unref();
}

// static

sk_svg_text_literal_t SkSVGTextLiteral_Make() {
    return static_sk_svg_text_literal_make(SkSVGTextLiteral::Make());
}

}