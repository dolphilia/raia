//
// Created by dolphilia on 2024/02/06.
//

#ifndef RAIA_SKIA_SK_SVG_RADIAL_GRADIENT_H
#define RAIA_SKIA_SK_SVG_RADIAL_GRADIENT_H

#include "modules/svg/include/SkSVGRadialGradient.h"
#include "../static/static_sk_svg_node.h"
#include "../static/static_sk_path.h"
#include "../static/static_sk_rect.h"
#include "../static/static_sk_svg_radial_gradient.h"

extern "C" {
void SkSVGRadialGradient_delete(SkSVGRadialGradient *svgRadialGradient);
void SkSVGRadialGradient_appendChild(SkSVGRadialGradient *svgRadialGradient, sk_svg_node_t svg_node);
void SkSVGRadialGradient_setTransform(SkSVGRadialGradient *svgRadialGradient, const SkSVGTransformType *t);
SkSVGTag SkSVGRadialGradient_tag(SkSVGRadialGradient *svgRadialGradient);
void SkSVGRadialGradient_render(SkSVGRadialGradient *svgRadialGradient, const SkSVGRenderContext *svgRenderContext);
bool SkSVGRadialGradient_asPaint(SkSVGRadialGradient *svgRadialGradient, const SkSVGRenderContext *svgRenderContext, SkPaint *paint);
sk_path_t SkSVGRadialGradient_asPath(SkSVGRadialGradient *svgRadialGradient, const SkSVGRenderContext *svgRenderContext);
sk_rect_t SkSVGRadialGradient_objectBoundingBox(SkSVGRadialGradient *svgRadialGradient, const SkSVGRenderContext *svgRenderContext);
void SkSVGRadialGradient_setAttribute(SkSVGRadialGradient *svgRadialGradient, SkSVGAttribute svgAttribute, const SkSVGValue *svgValue);
// bool SkSVGRadialGradient_setAttribute(SkSVGRadialGradient *svgRadialGradient, const char *attributeName, const char *attributeValue);
bool SkSVGRadialGradient_unique(SkSVGRadialGradient *svgRadialGradient);
void SkSVGRadialGradient_ref(SkSVGRadialGradient *svgRadialGradient);
void SkSVGRadialGradient_unref(SkSVGRadialGradient *svgRadialGradient);
// static
sk_svg_radial_gradient_t SkSVGRadialGradient_Make();
}

#endif //RAIA_SKIA_SK_SVG_RADIAL_GRADIENT_H
