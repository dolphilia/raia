//
// Created by dolphilia on 2024/02/06.
//

#ifndef RAIA_SKIA_SK_SVG_LINE_H
#define RAIA_SKIA_SK_SVG_LINE_H

#include "modules/svg/include/SkSVGLine.h"
#include "../static/static_sk_svg_node.h"
#include "../static/static_sk_path.h"
#include "../static/static_sk_rect.h"
#include "../static/static_sk_svg_line.h"

extern "C" {
void SkSVGLine_delete(SkSVGLine *svgLine);
void SkSVGLine_appendChild(SkSVGLine *svgLine, sk_svg_node_t svg_node);
void SkSVGLine_setTransform(SkSVGLine *svgLine, const SkSVGTransformType *t);
SkSVGTag SkSVGLine_tag(SkSVGLine *svgLine);
void SkSVGLine_render(SkSVGLine *svgLine, const SkSVGRenderContext *svgRenderContext);
bool SkSVGLine_asPaint(SkSVGLine *svgLine, const SkSVGRenderContext *svgRenderContext, SkPaint *paint);
sk_path_t SkSVGLine_asPath(SkSVGLine *svgLine, const SkSVGRenderContext *svgRenderContext);
sk_rect_t SkSVGLine_objectBoundingBox(SkSVGLine *svgLine, const SkSVGRenderContext *svgRenderContext);
void SkSVGLine_setAttribute(SkSVGLine *svgLine, SkSVGAttribute svgAttribute, const SkSVGValue *svgValue);
// bool SkSVGLine_setAttribute(SkSVGLine *svgLine, const char *attributeName, const char *attributeValue);
bool SkSVGLine_unique(SkSVGLine *svgLine);
void SkSVGLine_ref(SkSVGLine *svgLine);
void SkSVGLine_unref(SkSVGLine *svgLine);
// static
sk_svg_line_t SkSVGLine_Make();
}

#endif //RAIA_SKIA_SK_SVG_LINE_H
