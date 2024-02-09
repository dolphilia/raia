//
// Created by dolphilia on 2024/02/06.
//

#ifndef RAIA_SKIA_SK_SVG_TEXT_H
#define RAIA_SKIA_SK_SVG_TEXT_H

#include "modules/svg/include/SkSVGText.h"
#include "../static/static_sk_svg_node.h"
#include "../static/static_sk_path.h"
#include "../static/static_sk_rect.h"
#include "../static/static_sk_svg_text.h"

extern "C" {
void SkSVGText_delete(SkSVGText *svgText);
void SkSVGText_appendChild(SkSVGText *svgText, sk_svg_node_t svg_node);
void SkSVGText_renderText(SkSVGText *svgText, const SkSVGRenderContext &svgRenderContext, SkSVGTextContext *svgTextContext, SkSVGXmlSpace svgXmlSpace);
void SkSVGText_setTransform(SkSVGText *svgText, const SkSVGTransformType *t);
SkSVGTag SkSVGText_tag(SkSVGText *svgText);
void SkSVGText_render(SkSVGText *svgText, const SkSVGRenderContext *svgRenderContext);
bool SkSVGText_asPaint(SkSVGText *svgText, const SkSVGRenderContext *svgRenderContext, SkPaint *paint);
sk_path_t SkSVGText_asPath(SkSVGText *svgText, const SkSVGRenderContext *svgRenderContext);
sk_rect_t SkSVGText_objectBoundingBox(SkSVGText *svgText, const SkSVGRenderContext *svgRenderContext);
void SkSVGText_setAttribute(SkSVGText *svgText, SkSVGAttribute svgAttribute, const SkSVGValue *svgValue);
// bool SkSVGText_setAttribute(SkSVGText *svgText, const char *attributeName, const char *attributeValue);
bool SkSVGText_unique(SkSVGText *svgText);
void SkSVGText_ref(SkSVGText *svgText);
void SkSVGText_unref(SkSVGText *svgText);
// static
sk_svg_text_t SkSVGText_Make();
}

#endif //RAIA_SKIA_SK_SVG_TEXT_H
