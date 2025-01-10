//
// Created by dolphilia on 2024/02/02.
//

#ifndef RAIA_SKIA_STATIC_SK_SVG_CIRCLE_H
#define RAIA_SKIA_SK_SVG_CIRCLE_H

#include "modules/svg/include/SkSVGCircle.h"
#include "../static/static_sk_svg_node.h"
#include "../static/static_sk_svg_circle.h"
#include "../static/static_sk_path.h"
#include "../static/static_sk_rect.h"

extern "C" {
void SkSVGCircle_delete(SkSVGCircle *svgCircle);
void SkSVGCircle_appendChild(SkSVGCircle *svgCircle, sk_svg_node_t svg_node);
void SkSVGCircle_setTransform(SkSVGCircle *svgCircle, const SkSVGTransformType *t);
SkSVGTag SkSVGCircle_tag(SkSVGCircle *svgCircle);
void SkSVGCircle_render(SkSVGCircle *svgCircle, const SkSVGRenderContext *svgRenderContext);
bool SkSVGCircle_asPaint(SkSVGCircle *svgCircle, const SkSVGRenderContext *svgRenderContext, SkPaint *paint);
sk_path_t SkSVGCircle_asPath(SkSVGCircle *svgCircle, const SkSVGRenderContext *svgRenderContext);
sk_rect_t SkSVGCircle_objectBoundingBox(SkSVGCircle *svgCircle, const SkSVGRenderContext *svgRenderContext);
void SkSVGCircle_setAttribute(SkSVGCircle *svgCircle, SkSVGAttribute svgAttribute, const SkSVGValue *svgValue);
//bool SkSVGCircle_setAttribute_2(SkSVGCircle *svgCircle, const char *attributeName, const char *attributeValue);
bool SkSVGCircle_unique(SkSVGCircle *svgCircle);
void SkSVGCircle_ref(SkSVGCircle *svgCircle);
void SkSVGCircle_unref(SkSVGCircle *svgCircle);
// static
sk_svg_circle_t SkSVGCircle_Make();
}

#endif //RAIA_SKIA_STATIC_SK_SVG_CIRCLE_H
