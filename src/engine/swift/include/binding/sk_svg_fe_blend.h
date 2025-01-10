//
// Created by dolphilia on 2024/02/06.
//

#ifndef RAIA_SKIA_SK_SVG_FE_BLEND_H
#define RAIA_SKIA_SK_SVG_FE_BLEND_H

#include "modules/svg/include/SkSVGFeBlend.h"
#include "../static/static_sk_svg_node.h"
#include "../static/static_sk_path.h"
#include "../static/static_sk_rect.h"
#include "../static/static_sk_image_filter.h"
#include "../static/static_sk_svg_fe_blend.h"

extern "C" {
void SkSVGFeBlend_delete(SkSVGFeBlend *svgFeBlend);
sk_image_filter_t SkSVGFeBlend_makeImageFilter (SkSVGFeBlend *svgFeBlend, const SkSVGRenderContext *ctx, const SkSVGFilterContext *fctx);
sk_rect_t SkSVGFeBlend_resolveFilterSubregion (SkSVGFeBlend *svgFeBlend, const SkSVGRenderContext *svgRenderContext, const SkSVGFilterContext *svgFilterContext);
SkSVGColorspace SkSVGFeBlend_resolveColorspace (SkSVGFeBlend *svgFeBlend, const SkSVGRenderContext *svgRenderContext, const SkSVGFilterContext *svgFilterContext);
void SkSVGFeBlend_applyProperties (SkSVGFeBlend *svgFeBlend, SkSVGRenderContext *svgRenderContext);
void SkSVGFeBlend_appendChild(SkSVGFeBlend *svgFeBlend, sk_svg_node_t svg_node);
void SkSVGFeBlend_setTransform (SkSVGFeBlend *svgFeBlend, const SkSVGTransformType *t);
SkSVGTag SkSVGFeBlend_tag (SkSVGFeBlend *svgFeBlend);
void SkSVGFeBlend_render (SkSVGFeBlend *svgFeBlend, const SkSVGRenderContext &svgRenderContext);
bool SkSVGFeBlend_asPaint (SkSVGFeBlend *svgFeBlend, const SkSVGRenderContext *svgRenderContext, SkPaint *paint);
sk_path_t SkSVGFeBlend_asPath (SkSVGFeBlend *svgFeBlend, const SkSVGRenderContext *svgRenderContext);
sk_rect_t SkSVGFeBlend_objectBoundingBox (SkSVGFeBlend *svgFeBlend, const SkSVGRenderContext *svgRenderContext);
void SkSVGFeBlend_setAttribute (SkSVGFeBlend *svgFeBlend, SkSVGAttribute svgAttribute, const SkSVGValue &svgValue);
//bool SkSVGFeBlend_setAttribute (SkSVGFeBlend *svgFeBlend, const char *attributeName, const char *attributeValue);
bool SkSVGFeBlend_unique (SkSVGFeBlend *svgFeBlend);
void SkSVGFeBlend_ref (SkSVGFeBlend *svgFeBlend);
void SkSVGFeBlend_unref (SkSVGFeBlend *svgFeBlend);
// static
sk_svg_fe_blend_t SkSVGFeBlend_Make ();
bool SkSVGFeBlend_IsFilterEffect (const sk_sp< SkSVGNode > *node);
}

#endif //RAIA_SKIA_SK_SVG_FE_BLEND_H
