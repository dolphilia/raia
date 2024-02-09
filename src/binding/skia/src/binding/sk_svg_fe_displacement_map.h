//
// Created by dolphilia on 2024/02/06.
//

#ifndef RAIA_SKIA_SK_SVG_FE_DISPLACEMENT_MAP_H
#define RAIA_SKIA_SK_SVG_FE_DISPLACEMENT_MAP_H

#include "modules/svg/include/SkSVGFeDisplacementMap.h"
#include "../static/static_sk_svg_node.h"
#include "../static/static_sk_path.h"
#include "../static/static_sk_rect.h"
#include "../static/static_sk_image_filter.h"
#include "../static/static_sk_svg_fe_displacement_map.h"

extern "C" {
void SkSVGFeDisplacementMap_delete(SkSVGFeDisplacementMap *svgFeDisplacementMap);
SkSVGColorspace SkSVGFeDisplacementMap_resolveColorspace(SkSVGFeDisplacementMap *svgFeDisplacementMap, const SkSVGRenderContext *svgRenderContext, const SkSVGFilterContext *svgFilterContext);
sk_image_filter_t SkSVGFeDisplacementMap_makeImageFilter(SkSVGFeDisplacementMap *svgFeDisplacementMap, const SkSVGRenderContext *ctx, const SkSVGFilterContext *fctx);
sk_rect_t SkSVGFeDisplacementMap_resolveFilterSubregion(SkSVGFeDisplacementMap *svgFeDisplacementMap, const SkSVGRenderContext *svgRenderContext, const SkSVGFilterContext *svgFilterContext);
void SkSVGFeDisplacementMap_applyProperties(SkSVGFeDisplacementMap *svgFeDisplacementMap, SkSVGRenderContext *svgRenderContext);
void SkSVGFeDisplacementMap_appendChild(SkSVGFeDisplacementMap *svgFeDisplacementMap, sk_svg_node_t svg_node);
void SkSVGFeDisplacementMap_setTransform(SkSVGFeDisplacementMap *svgFeDisplacementMap, const SkSVGTransformType *t);
SkSVGTag SkSVGFeDisplacementMap_tag(SkSVGFeDisplacementMap *svgFeDisplacementMap);
void SkSVGFeDisplacementMap_render(SkSVGFeDisplacementMap *svgFeDisplacementMap, const SkSVGRenderContext *svgRenderContext);
bool SkSVGFeDisplacementMap_asPaint(SkSVGFeDisplacementMap *svgFeDisplacementMap, const SkSVGRenderContext *svgRenderContext, SkPaint *paint);
sk_path_t SkSVGFeDisplacementMap_asPath(SkSVGFeDisplacementMap *svgFeDisplacementMap, const SkSVGRenderContext *svgRenderContext);
sk_rect_t SkSVGFeDisplacementMap_objectBoundingBox(SkSVGFeDisplacementMap *svgFeDisplacementMap, const SkSVGRenderContext *svgRenderContext);
void SkSVGFeDisplacementMap_setAttribute(SkSVGFeDisplacementMap *svgFeDisplacementMap, SkSVGAttribute svgAttribute, const SkSVGValue *svgValue);
//bool SkSVGFeDisplacementMap_setAttribute(SkSVGFeDisplacementMap *svgFeDisplacementMap, const char *attributeName, const char *attributeValue);
bool SkSVGFeDisplacementMap_unique(SkSVGFeDisplacementMap *svgFeDisplacementMap);
void SkSVGFeDisplacementMap_ref(SkSVGFeDisplacementMap *svgFeDisplacementMap);
void SkSVGFeDisplacementMap_unref(SkSVGFeDisplacementMap *svgFeDisplacementMap);
// static
sk_svg_fe_displacement_map_t SkSVGFeDisplacementMap_Make();
bool SkSVGFeDisplacementMap_IsFilterEffect (const sk_sp< SkSVGNode > *node);
}

#endif //RAIA_SKIA_SK_SVG_FE_DISPLACEMENT_MAP_H
