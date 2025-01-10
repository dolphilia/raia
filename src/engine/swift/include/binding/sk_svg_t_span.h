//
// Created by dolphilia on 2024/02/06.
//

#ifndef RAIA_SKIA_SK_SVG_T_SPAN_H
#define RAIA_SKIA_SK_SVG_T_SPAN_H

#include "modules/svg/include/SkSVGText.h"
#include "../static/static_sk_svg_node.h"
#include "../static/static_sk_path.h"
#include "../static/static_sk_rect.h"
#include "../static/static_sk_svg_t_span.h"

extern "C" {
void SkSVGTSpan_delete(SkSVGTSpan *svgTSpan);
void SkSVGTSpan_appendChild(SkSVGTSpan *svgTSpan, sk_svg_node_t svg_node);
void SkSVGTSpan_renderText(SkSVGTSpan *svgTSpan, const SkSVGRenderContext *svgRenderContext, SkSVGTextContext *svgTextContext, SkSVGXmlSpace svgXmlSpace);
void SkSVGTSpan_setTransform(SkSVGTSpan *svgTSpan, const SkSVGTransformType *t);
SkSVGTag SkSVGTSpan_tag(SkSVGTSpan *svgTSpan);
void SkSVGTSpan_render(SkSVGTSpan *svgTSpan, const SkSVGRenderContext *svgRenderContext);
bool SkSVGTSpan_asPaint(SkSVGTSpan *svgTSpan, const SkSVGRenderContext *svgRenderContext, SkPaint *paint);
sk_path_t SkSVGTSpan_asPath(SkSVGTSpan *svgTSpan, const SkSVGRenderContext *svgRenderContext);
sk_rect_t SkSVGTSpan_objectBoundingBox(SkSVGTSpan *svgTSpan, const SkSVGRenderContext *svgRenderContext);
void SkSVGTSpan_setAttribute(SkSVGTSpan *svgTSpan, SkSVGAttribute svgAttribute, const SkSVGValue *svgValue);
// bool SkSVGTSpan_setAttribute(SkSVGTSpan *svgTSpan, const char *attributeName, const char *attributeValue);
bool SkSVGTSpan_unique(SkSVGTSpan *svgTSpan);
void SkSVGTSpan_ref(SkSVGTSpan *svgTSpan);
void SkSVGTSpan_unref(SkSVGTSpan *svgTSpan);
// static
//int SkSVGTSpan_Make();
}

#endif //RAIA_SKIA_SK_SVG_T_SPAN_H
