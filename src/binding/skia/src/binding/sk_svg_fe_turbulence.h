//
// Created by dolphilia on 2024/02/06.
//

#ifndef RAIA_SKIA_SK_SVG_FE_TURBULENCE_H
#define RAIA_SKIA_SK_SVG_FE_TURBULENCE_H

#include "modules/svg/include/SkSVGFeTurbulence.h"
#include "../static/static_sk_svg_node.h"
#include "../static/static_sk_path.h"
#include "../static/static_sk_rect.h"
#include "../static/static_sk_image_filter.h"
#include "../static/static_sk_svg_fe_turbulence.h"

extern "C" {
void SkSVGFeTurbulence_delete(SkSVGFeTurbulence *svgFeTurbulence);
sk_image_filter_t SkSVGFeTurbulence_makeImageFilter(SkSVGFeTurbulence *svgFeTurbulence, const SkSVGRenderContext *ctx, const SkSVGFilterContext *fctx);
sk_rect_t SkSVGFeTurbulence_resolveFilterSubregion(SkSVGFeTurbulence *svgFeTurbulence, const SkSVGRenderContext *svgRenderContext, const SkSVGFilterContext *svgFilterContext);
SkSVGColorspace SkSVGFeTurbulence_resolveColorspace(SkSVGFeTurbulence *svgFeTurbulence, const SkSVGRenderContext *svgRenderContext, const SkSVGFilterContext *svgFilterContext);
void SkSVGFeTurbulence_applyProperties(SkSVGFeTurbulence *svgFeTurbulence, SkSVGRenderContext *svgRenderContext);
void SkSVGFeTurbulence_appendChild(SkSVGFeTurbulence *svgFeTurbulence, sk_svg_node_t svg_node);
void SkSVGFeTurbulence_setTransform(SkSVGFeTurbulence *svgFeTurbulence, const SkSVGTransformType *t);
SkSVGTag SkSVGFeTurbulence_tag(SkSVGFeTurbulence *svgFeTurbulence);
void SkSVGFeTurbulence_render(SkSVGFeTurbulence *svgFeTurbulence, const SkSVGRenderContext *svgRenderContext);
bool SkSVGFeTurbulence_asPaint(SkSVGFeTurbulence *svgFeTurbulence, const SkSVGRenderContext *svgRenderContext, SkPaint *paint);
sk_path_t SkSVGFeTurbulence_asPath(SkSVGFeTurbulence *svgFeTurbulence, const SkSVGRenderContext *svgRenderContext);
sk_rect_t SkSVGFeTurbulence_objectBoundingBox(SkSVGFeTurbulence *svgFeTurbulence, const SkSVGRenderContext *svgRenderContext);
void SkSVGFeTurbulence_setAttribute(SkSVGFeTurbulence *svgFeTurbulence, SkSVGAttribute svgAttribute, const SkSVGValue *svgValue);
// bool SkSVGFeTurbulence_setAttribute(SkSVGFeTurbulence *svgFeTurbulence, const char *attributeName, const char *attributeValue);
bool SkSVGFeTurbulence_unique(SkSVGFeTurbulence *svgFeTurbulence) ;
void SkSVGFeTurbulence_ref(SkSVGFeTurbulence *svgFeTurbulence);
void SkSVGFeTurbulence_unref(SkSVGFeTurbulence *svgFeTurbulence);
// static
sk_svg_fe_turbulence_t SkSVGFeTurbulence_Make();
bool SkSVGFeTurbulence_IsFilterEffect (const sk_sp< SkSVGNode > *node);
}

#endif //RAIA_SKIA_SK_SVG_FE_TURBULENCE_H
