//
// Created by dolphilia on 2024/02/06.
//

#ifndef RAIA_SKIA_SK_SVG_FE_SPECULAR_LIGHTING_H
#define RAIA_SKIA_SK_SVG_FE_SPECULAR_LIGHTING_H

#include "modules/svg/include/SkSVGFeLighting.h"
#include "../static/static_sk_svg_node.h"
#include "../static/static_sk_path.h"
#include "../static/static_sk_rect.h"
#include "../static/static_sk_image_filter.h"
#include "../static/static_sk_svg_fe_specular_lighting.h"

extern "C" {
void SkSVGFeSpecularLighting_delete(SkSVGFeSpecularLighting *svgFeSpecularLighting);
sk_image_filter_t SkSVGFeSpecularLighting_makeImageFilter(SkSVGFeSpecularLighting *svgFeSpecularLighting, const SkSVGRenderContext *ctx, const SkSVGFilterContext *fctx);
sk_rect_t SkSVGFeSpecularLighting_resolveFilterSubregion(SkSVGFeSpecularLighting *svgFeSpecularLighting, const SkSVGRenderContext *svgRenderContext, const SkSVGFilterContext *svgFilterContext);
SkSVGColorspace SkSVGFeSpecularLighting_resolveColorspace(SkSVGFeSpecularLighting *svgFeSpecularLighting, const SkSVGRenderContext *svgRenderContext, const SkSVGFilterContext *svgFilterContext);
void SkSVGFeSpecularLighting_applyProperties(SkSVGFeSpecularLighting *svgFeSpecularLighting, SkSVGRenderContext *svgRenderContext);
void SkSVGFeSpecularLighting_appendChild(SkSVGFeSpecularLighting *svgFeSpecularLighting, sk_svg_node_t svg_node);
void SkSVGFeSpecularLighting_setTransform(SkSVGFeSpecularLighting *svgFeSpecularLighting, const SkSVGTransformType *t);
SkSVGTag SkSVGFeSpecularLighting_tag(SkSVGFeSpecularLighting *svgFeSpecularLighting);
void SkSVGFeSpecularLighting_render(SkSVGFeSpecularLighting *svgFeSpecularLighting, const SkSVGRenderContext *svgRenderContext);
bool SkSVGFeSpecularLighting_asPaint(SkSVGFeSpecularLighting *svgFeSpecularLighting, const SkSVGRenderContext *svgRenderContext, SkPaint *paint);
sk_path_t SkSVGFeSpecularLighting_asPath(SkSVGFeSpecularLighting *svgFeSpecularLighting, const SkSVGRenderContext *svgRenderContext);
sk_rect_t SkSVGFeSpecularLighting_objectBoundingBox(SkSVGFeSpecularLighting *svgFeSpecularLighting, const SkSVGRenderContext *svgRenderContext);
void SkSVGFeSpecularLighting_setAttribute(SkSVGFeSpecularLighting *svgFeSpecularLighting, SkSVGAttribute svgAttribute, const SkSVGValue *svgValue);
// bool SkSVGFeSpecularLighting_setAttribute(SkSVGFeSpecularLighting *svgFeSpecularLighting, const char *attributeName, const char *attributeValue);
bool SkSVGFeSpecularLighting_unique(SkSVGFeSpecularLighting *svgFeSpecularLighting);
void SkSVGFeSpecularLighting_ref(SkSVGFeSpecularLighting *svgFeSpecularLighting);
void SkSVGFeSpecularLighting_unref(SkSVGFeSpecularLighting *svgFeSpecularLighting);
// static
sk_svg_fe_specular_lighting_t SkSVGFeSpecularLighting_Make();
bool SkSVGFeSpecularLighting_IsFilterEffect (const sk_sp< SkSVGNode > *node);
}

#endif //RAIA_SKIA_SK_SVG_FE_SPECULAR_LIGHTING_H
