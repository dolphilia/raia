//
// Created by dolphilia on 2024/02/06.
//

#ifndef RAIA_SKIA_SK_SVG_FE_LIGHT_SOURCE_H
#define RAIA_SKIA_SK_SVG_FE_LIGHT_SOURCE_H

#include "modules/svg/include/SkSVGFeLighting.h"
#include "../static/static_sk_svg_node.h"
#include "../static/static_sk_path.h"
#include "../static/static_sk_rect.h"
#include "../static/static_sk_image_filter.h"

extern "C" {
void SkSVGFeLighting_delete(SkSVGFeLighting *svgFeLighting);
sk_image_filter_t SkSVGFeLighting_makeImageFilter(SkSVGFeLighting *svgFeLighting, const SkSVGRenderContext *ctx, const SkSVGFilterContext *fctx);
sk_rect_t SkSVGFeLighting_resolveFilterSubregion(SkSVGFeLighting *svgFeLighting, const SkSVGRenderContext *svgRenderContext, const SkSVGFilterContext *svgFilterContext);
SkSVGColorspace SkSVGFeLighting_resolveColorspace(SkSVGFeLighting *svgFeLighting, const SkSVGRenderContext *svgRenderContext, const SkSVGFilterContext *svgFilterContext);
void SkSVGFeLighting_applyProperties(SkSVGFeLighting *svgFeLighting, SkSVGRenderContext *svgRenderContext);
void SkSVGFeLighting_appendChild(SkSVGFeLighting *svgFeLighting, sk_svg_node_t svg_node);
void SkSVGFeLighting_setTransform(SkSVGFeLighting *svgFeLighting, const SkSVGTransformType *t);
SkSVGTag SkSVGFeLighting_tag(SkSVGFeLighting *svgFeLighting);
void SkSVGFeLighting_render(SkSVGFeLighting *svgFeLighting, const SkSVGRenderContext *svgRenderContext);
bool SkSVGFeLighting_asPaint(SkSVGFeLighting *svgFeLighting, const SkSVGRenderContext *svgRenderContext, SkPaint *paint);
sk_path_t SkSVGFeLighting_asPath(SkSVGFeLighting *svgFeLighting, const SkSVGRenderContext *svgRenderContext);
sk_rect_t SkSVGFeLighting_objectBoundingBox(SkSVGFeLighting *svgFeLighting, const SkSVGRenderContext *svgRenderContext);
void SkSVGFeLighting_setAttribute(SkSVGFeLighting *svgFeLighting, SkSVGAttribute svgAttribute, const SkSVGValue *svgValue);
// bool SkSVGFeLighting_setAttribute(SkSVGFeLighting *svgFeLighting, const char *attributeName, const char *attributeValue);
bool SkSVGFeLighting_unique(SkSVGFeLighting *svgFeLighting);
void SkSVGFeLighting_ref(SkSVGFeLighting *svgFeLighting);
void SkSVGFeLighting_unref(SkSVGFeLighting *svgFeLighting);
// static
bool SkSVGFeLighting_IsFilterEffect (const sk_sp< SkSVGNode > *node);
}

#endif //RAIA_SKIA_SK_SVG_FE_LIGHT_SOURCE_H
