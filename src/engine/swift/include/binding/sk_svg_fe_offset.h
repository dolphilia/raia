//
// Created by dolphilia on 2024/02/06.
//

#ifndef RAIA_SKIA_SK_SVG_FE_OFFSET_H
#define RAIA_SKIA_SK_SVG_FE_OFFSET_H

#include "modules/svg/include/SkSVGFeOffset.h"
#include "../static/static_sk_svg_node.h"
#include "../static/static_sk_path.h"
#include "../static/static_sk_rect.h"
#include "../static/static_sk_image_filter.h"
#include "../static/static_sk_svg_fe_offset.h"

extern "C" {
void SkSVGFeOffset_delete(SkSVGFeOffset *svgFeOffset);
sk_image_filter_t SkSVGFeOffset_makeImageFilter(SkSVGFeOffset *svgFeOffset, const SkSVGRenderContext *ctx, const SkSVGFilterContext *fctx);
sk_rect_t SkSVGFeOffset_resolveFilterSubregion(SkSVGFeOffset *svgFeOffset, const SkSVGRenderContext *svgRenderContext, const SkSVGFilterContext *svgFilterContext);
SkSVGColorspace SkSVGFeOffset_resolveColorspace(SkSVGFeOffset *svgFeOffset, const SkSVGRenderContext *svgRenderContext, const SkSVGFilterContext *svgFilterContext);
void SkSVGFeOffset_applyProperties(SkSVGFeOffset *svgFeOffset, SkSVGRenderContext *svgRenderContext);
void SkSVGFeOffset_appendChild(SkSVGFeOffset *svgFeOffset, sk_svg_node_t svg_node);
void SkSVGFeOffset_setTransform(SkSVGFeOffset *svgFeOffset, const SkSVGTransformType *t);
SkSVGTag SkSVGFeOffset_tag(SkSVGFeOffset *svgFeOffset);
void SkSVGFeOffset_render(SkSVGFeOffset *svgFeOffset, const SkSVGRenderContext *svgRenderContext);
bool SkSVGFeOffset_asPaint(SkSVGFeOffset *svgFeOffset, const SkSVGRenderContext *svgRenderContext, SkPaint *paint);
sk_path_t SkSVGFeOffset_asPath(SkSVGFeOffset *svgFeOffset, const SkSVGRenderContext *svgRenderContext);
sk_rect_t SkSVGFeOffset_objectBoundingBox(SkSVGFeOffset *svgFeOffset, const SkSVGRenderContext *svgRenderContext);
void SkSVGFeOffset_setAttribute(SkSVGFeOffset *svgFeOffset, SkSVGAttribute svgAttribute, const SkSVGValue *svgValue);
// bool SkSVGFeOffset_setAttribute(SkSVGFeOffset *svgFeOffset, const char *attributeName, const char *attributeValue);
bool SkSVGFeOffset_unique(SkSVGFeOffset *svgFeOffset);
void SkSVGFeOffset_ref(SkSVGFeOffset *svgFeOffset);
void SkSVGFeOffset_unref(SkSVGFeOffset *svgFeOffset);
// static
sk_svg_fe_offset_t SkSVGFeOffset_Make();
bool SkSVGFeOffset_IsFilterEffect (const sk_sp< SkSVGNode > *node);
}

#endif //RAIA_SKIA_SK_SVG_FE_OFFSET_H
