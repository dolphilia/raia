//
// Created by dolphilia on 2024/02/06.
//

#ifndef RAIA_SKIA_SK_SVG_LINEAR_GRADIENT_H
#define RAIA_SKIA_SK_SVG_LINEAR_GRADIENT_H

#include "modules/svg/include/SkSVGLinearGradient.h"
#include "../static/static_sk_svg_node.h"
#include "../static/static_sk_path.h"
#include "../static/static_sk_rect.h"
#include "../static/static_sk_svg_linear_gradient.h"

extern "C" {
void SkSVGLinearGradient_delete(SkSVGLinearGradient *svgLinearGradient);
void SkSVGLinearGradient_appendChild(SkSVGLinearGradient *svgLinearGradient, sk_svg_node_t svg_node);
void SkSVGLinearGradient_setTransform(SkSVGLinearGradient *svgLinearGradient, const SkSVGTransformType *t);
SkSVGTag SkSVGLinearGradient_tag(SkSVGLinearGradient *svgLinearGradient);
void SkSVGLinearGradient_render(SkSVGLinearGradient *svgLinearGradient, const SkSVGRenderContext *svgRenderContext);
bool SkSVGLinearGradient_asPaint(SkSVGLinearGradient *svgLinearGradient, const SkSVGRenderContext *svgRenderContext, SkPaint *paint);
sk_path_t SkSVGLinearGradient_asPath(SkSVGLinearGradient *svgLinearGradient, const SkSVGRenderContext *svgRenderContext);
sk_rect_t SkSVGLinearGradient_objectBoundingBox(SkSVGLinearGradient *svgLinearGradient, const SkSVGRenderContext *svgRenderContext);
void SkSVGLinearGradient_setAttribute(SkSVGLinearGradient *svgLinearGradient, SkSVGAttribute svgAttribute, const SkSVGValue *svgValue);
// bool SkSVGLinearGradient_setAttribute(SkSVGLinearGradient *svgLinearGradient, const char *attributeName, const char *attributeValue);
bool SkSVGLinearGradient_unique(SkSVGLinearGradient *svgLinearGradient);
void SkSVGLinearGradient_ref(SkSVGLinearGradient *svgLinearGradient);
void SkSVGLinearGradient_unref(SkSVGLinearGradient *svgLinearGradient);
// static
sk_svg_linear_gradient_t SkSVGLinearGradient_Make();
}

#endif //RAIA_SKIA_SK_SVG_LINEAR_GRADIENT_H
