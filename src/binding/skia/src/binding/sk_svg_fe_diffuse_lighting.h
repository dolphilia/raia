//
// Created by dolphilia on 2024/02/06.
//

#ifndef RAIA_SKIA_SK_SVG_FE_DIFFUSE_LIGHTING_H
#define RAIA_SKIA_SK_SVG_FE_DIFFUSE_LIGHTING_H

#include "modules/svg/include/SkSVGFeLighting.h"
#include "../static/static_sk_svg_node.h"
#include "../static/static_sk_path.h"
#include "../static/static_sk_rect.h"
#include "../static/static_sk_image_filter.h"
#include "../static/static_sk_svg_fe_diffuse_lighting.h"

extern "C" {
void SkSVGFeDiffuseLighting_delete(SkSVGFeDiffuseLighting *svgFeDiffuseLighting);
sk_image_filter_t SkSVGFeDiffuseLighting_makeImageFilter(SkSVGFeDiffuseLighting *svgFeDiffuseLighting, const SkSVGRenderContext *ctx, const SkSVGFilterContext *fctx);
sk_rect_t SkSVGFeDiffuseLighting_resolveFilterSubregion(SkSVGFeDiffuseLighting *svgFeDiffuseLighting, const SkSVGRenderContext *svgRenderContext, const SkSVGFilterContext *svgFilterContext);
SkSVGColorspace SkSVGFeDiffuseLighting_resolveColorspace(SkSVGFeDiffuseLighting *svgFeDiffuseLighting, const SkSVGRenderContext *svgRenderContext, const SkSVGFilterContext *svgFilterContext);
void SkSVGFeDiffuseLighting_applyProperties(SkSVGFeDiffuseLighting *svgFeDiffuseLighting, SkSVGRenderContext *svgRenderContext);
void SkSVGFeDiffuseLighting_appendChild(SkSVGFeDiffuseLighting *svgFeDiffuseLighting, sk_svg_node_t svg_node);
void SkSVGFeDiffuseLighting_setTransform(SkSVGFeDiffuseLighting *svgFeDiffuseLighting, const SkSVGTransformType *t);
SkSVGTag SkSVGFeDiffuseLighting_tag(SkSVGFeDiffuseLighting *svgFeDiffuseLighting);
void SkSVGFeDiffuseLighting_render(SkSVGFeDiffuseLighting *svgFeDiffuseLighting, const SkSVGRenderContext *svgRenderContext);
bool SkSVGFeDiffuseLighting_asPaint(SkSVGFeDiffuseLighting *svgFeDiffuseLighting, const SkSVGRenderContext *svgRenderContext, SkPaint *paint);
sk_path_t SkSVGFeDiffuseLighting_asPath(SkSVGFeDiffuseLighting *svgFeDiffuseLighting, const SkSVGRenderContext *svgRenderContext);
sk_rect_t SkSVGFeDiffuseLighting_objectBoundingBox(SkSVGFeDiffuseLighting *svgFeDiffuseLighting, const SkSVGRenderContext *svgRenderContext);
void SkSVGFeDiffuseLighting_setAttribute(SkSVGFeDiffuseLighting *svgFeDiffuseLighting, SkSVGAttribute svgAttribute, const SkSVGValue &svgValue);
//bool SkSVGFeDiffuseLighting_setAttribute(SkSVGFeDiffuseLighting *svgFeDiffuseLighting, const char *attributeName, const char *attributeValue);
bool SkSVGFeDiffuseLighting_unique(SkSVGFeDiffuseLighting *svgFeDiffuseLighting);
void SkSVGFeDiffuseLighting_ref(SkSVGFeDiffuseLighting *svgFeDiffuseLighting);
void SkSVGFeDiffuseLighting_unref(SkSVGFeDiffuseLighting *svgFeDiffuseLighting);
// static
sk_svg_fe_diffuse_lighting_t SkSVGFeDiffuseLighting_Make();
bool SkSVGFeDiffuseLighting_IsFilterEffect (const sk_sp< SkSVGNode > *node);
}

#endif //RAIA_SKIA_SK_SVG_FE_DIFFUSE_LIGHTING_H
