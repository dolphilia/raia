//
// Created by dolphilia on 2024/02/06.
//

#ifndef RAIA_SKIA_SK_SVG_PATTERN_H
#define RAIA_SKIA_SK_SVG_PATTERN_H

#include "modules/svg/include/SkSVGPattern.h"
#include "../static/static_sk_svg_node.h"
#include "../static/static_sk_path.h"
#include "../static/static_sk_rect.h"
#include "../static/static_sk_svg_pattern.h"

extern "C" {
void SkSVGPattern_delete(SkSVGPattern *svgPattern);
void SkSVGPattern_appendChild(SkSVGPattern *svgPattern, sk_svg_node_t svg_node);
void SkSVGPattern_setTransform(SkSVGPattern *svgPattern, const SkSVGTransformType *t);
SkSVGTag SkSVGPattern_tag(SkSVGPattern *svgPattern);
void SkSVGPattern_render(SkSVGPattern *svgPattern, const SkSVGRenderContext *svgRenderContext);
bool SkSVGPattern_asPaint(SkSVGPattern *svgPattern, const SkSVGRenderContext *svgRenderContext, SkPaint *paint);
sk_path_t SkSVGPattern_asPath(SkSVGPattern *svgPattern, const SkSVGRenderContext *svgRenderContext);
sk_rect_t SkSVGPattern_objectBoundingBox(SkSVGPattern *svgPattern, const SkSVGRenderContext *svgRenderContext);
void SkSVGPattern_setAttribute(SkSVGPattern *svgPattern, SkSVGAttribute svgAttribute, const SkSVGValue *svgValue);
// bool SkSVGPattern_setAttribute(SkSVGPattern *svgPattern, const char *attributeName, const char *attributeValue);
bool SkSVGPattern_unique(SkSVGPattern *svgPattern);
void SkSVGPattern_ref(SkSVGPattern *svgPattern);
void SkSVGPattern_unref(SkSVGPattern *svgPattern);
// static
sk_svg_pattern_t SkSVGPattern_Make();
}

#endif //RAIA_SKIA_SK_SVG_PATTERN_H
