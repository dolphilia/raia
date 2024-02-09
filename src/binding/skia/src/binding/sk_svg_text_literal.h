//
// Created by dolphilia on 2024/02/06.
//

#ifndef RAIA_SKIA_SK_SVG_TEXT_LITERAL_H
#define RAIA_SKIA_SK_SVG_TEXT_LITERAL_H

#include "modules/svg/include/SkSVGText.h"
#include "../static/static_sk_path.h"
#include "../static/static_sk_rect.h"
#include "../static/static_sk_svg_text_literal.h"

extern "C" {
void SkSVGTextLiteral_delete(SkSVGTextLiteral *svgTextLiteral);
void SkSVGTextLiteral_renderText(SkSVGTextLiteral *svgTextLiteral, const SkSVGRenderContext &svgRenderContext, SkSVGTextContext *svgTextContext, SkSVGXmlSpace svgXmlSpace);
void SkSVGTextLiteral_setTransform(SkSVGTextLiteral *svgTextLiteral, const SkSVGTransformType *t);
SkSVGTag SkSVGTextLiteral_tag(SkSVGTextLiteral *svgTextLiteral);
void SkSVGTextLiteral_render(SkSVGTextLiteral *svgTextLiteral, const SkSVGRenderContext *svgRenderContext);
bool SkSVGTextLiteral_asPaint(SkSVGTextLiteral *svgTextLiteral, const SkSVGRenderContext *svgRenderContext, SkPaint *paint);
sk_path_t SkSVGTextLiteral_asPath(SkSVGTextLiteral *svgTextLiteral, const SkSVGRenderContext *svgRenderContext);
sk_rect_t SkSVGTextLiteral_objectBoundingBox(SkSVGTextLiteral *svgTextLiteral, const SkSVGRenderContext *svgRenderContext);
void SkSVGTextLiteral_setAttribute(SkSVGTextLiteral *svgTextLiteral, SkSVGAttribute svgAttribute, const SkSVGValue *svgValue);
// bool SkSVGTextLiteral_setAttribute(SkSVGTextLiteral *svgTextLiteral, const char *attributeName, const char *attributeValue);
bool SkSVGTextLiteral_parseAndSetAttribute(SkSVGTextLiteral *svgTextLiteral, const char *name, const char *value);
bool SkSVGTextLiteral_unique(SkSVGTextLiteral *svgTextLiteral);
void SkSVGTextLiteral_ref(SkSVGTextLiteral *svgTextLiteral);
void SkSVGTextLiteral_unref(SkSVGTextLiteral *svgTextLiteral);
// static
sk_svg_text_literal_t SkSVGTextLiteral_Make();
}

#endif //RAIA_SKIA_SK_SVG_TEXT_LITERAL_H
