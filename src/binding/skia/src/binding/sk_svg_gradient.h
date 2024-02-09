//
// Created by dolphilia on 2024/02/06.
//

#ifndef RAIA_SKIA_SK_SVG_GRADIENT_H
#define RAIA_SKIA_SK_SVG_GRADIENT_H

#include "modules/svg/include/SkSVGGradient.h"
#include "../static/static_sk_svg_node.h"
#include "../static/static_sk_path.h"
#include "../static/static_sk_rect.h"

extern "C" {
void SkSVGGradient_delete(SkSVGGradient *svgGradient);
void SkSVGGradient_appendChild(SkSVGGradient *svgGradient, sk_svg_node_t svg_node);
void SkSVGGradient_setTransform(SkSVGGradient *svgGradient, const SkSVGTransformType *t);
SkSVGTag SkSVGGradient_tag(SkSVGGradient *svgGradient);
void SkSVGGradient_render(SkSVGGradient *svgGradient, const SkSVGRenderContext *svgRenderContext);
bool SkSVGGradient_asPaint(SkSVGGradient *svgGradient, const SkSVGRenderContext *svgRenderContext, SkPaint *paint);
sk_path_t SkSVGGradient_asPath(SkSVGGradient *svgGradient, const SkSVGRenderContext *svgRenderContext);
sk_rect_t SkSVGGradient_objectBoundingBox(SkSVGGradient *svgGradient, const SkSVGRenderContext *svgRenderContext);
void SkSVGGradient_setAttribute(SkSVGGradient *svgGradient, SkSVGAttribute svgAttribute, const SkSVGValue *svgValue);
// bool SkSVGGradient_setAttribute(SkSVGGradient *svgGradient, const char *attributeName, const char *attributeValue);
bool SkSVGGradient_unique(SkSVGGradient *svgGradient);
void SkSVGGradient_ref(SkSVGGradient *svgGradient);
void SkSVGGradient_unref(SkSVGGradient *svgGradient);
}

#endif //RAIA_SKIA_SK_SVG_GRADIENT_H
