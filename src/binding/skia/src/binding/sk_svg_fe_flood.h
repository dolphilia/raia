//
// Created by dolphilia on 2024/02/06.
//

#ifndef RAIA_SKIA_SK_SVG_FE_FLOOD_H
#define RAIA_SKIA_SK_SVG_FE_FLOOD_H

#include "modules/svg/include/SkSVGFeFlood.h"
#include "../static/static_sk_svg_node.h"
#include "../static/static_sk_path.h"
#include "../static/static_sk_rect.h"
#include "../static/static_sk_image_filter.h"
#include "../static/static_sk_svg_fe_flood.h"

extern "C" {
void SkSVGFeFlood_delete(SkSVGFeFlood *svgFeFlood);
sk_image_filter_t SkSVGFeFlood_makeImageFilter(SkSVGFeFlood *svgFeFlood, const SkSVGRenderContext *ctx, const SkSVGFilterContext *fctx);
sk_rect_t SkSVGFeFlood_resolveFilterSubregion(SkSVGFeFlood *svgFeFlood, const SkSVGRenderContext *svgRenderContext, const SkSVGFilterContext *svgFilterContext);
SkSVGColorspace SkSVGFeFlood_resolveColorspace(SkSVGFeFlood *svgFeFlood, const SkSVGRenderContext *svgRenderContext, const SkSVGFilterContext *svgFilterContext);
void SkSVGFeFlood_applyProperties(SkSVGFeFlood *svgFeFlood, SkSVGRenderContext *svgRenderContext);
void SkSVGFeFlood_appendChild(SkSVGFeFlood *svgFeFlood, sk_svg_node_t svg_node);
void SkSVGFeFlood_setTransform(SkSVGFeFlood *svgFeFlood, const SkSVGTransformType *t);
SkSVGTag SkSVGFeFlood_tag(SkSVGFeFlood *svgFeFlood);
void SkSVGFeFlood_render(SkSVGFeFlood *svgFeFlood, const SkSVGRenderContext *svgRenderContext);
bool SkSVGFeFlood_asPaint(SkSVGFeFlood *svgFeFlood, const SkSVGRenderContext *svgRenderContext, SkPaint *paint);
sk_path_t SkSVGFeFlood_asPath(SkSVGFeFlood *svgFeFlood, const SkSVGRenderContext *svgRenderContext);
sk_rect_t SkSVGFeFlood_objectBoundingBox(SkSVGFeFlood *svgFeFlood, const SkSVGRenderContext *svgRenderContext);
void SkSVGFeFlood_setAttribute(SkSVGFeFlood *svgFeFlood, SkSVGAttribute svgAttribute, const SkSVGValue *svgValue);
// bool SkSVGFeFlood_setAttribute(SkSVGFeFlood *svgFeFlood, const char *attributeName, const char *attributeValue);
bool SkSVGFeFlood_unique(SkSVGFeFlood *svgFeFlood);
void SkSVGFeFlood_ref(SkSVGFeFlood *svgFeFlood);
void SkSVGFeFlood_unref(SkSVGFeFlood *svgFeFlood);
// static
sk_svg_fe_flood_t SkSVGFeFlood_Make();
bool SkSVGFeFlood_IsFilterEffect (const sk_sp< SkSVGNode > *node);
}

#endif //RAIA_SKIA_SK_SVG_FE_FLOOD_H
