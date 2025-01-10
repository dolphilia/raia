//
// Created by dolphilia on 2024/02/06.
//

#ifndef RAIA_SKIA_SK_SVG_FE_COMPOSITE_H
#define RAIA_SKIA_SK_SVG_FE_COMPOSITE_H

#include "modules/svg/include/SkSVGFeComposite.h"
#include "../static/static_sk_svg_node.h"
#include "../static/static_sk_path.h"
#include "../static/static_sk_rect.h"
#include "../static/static_sk_image_filter.h"
#include "../static/static_sk_svg_fe_composite.h"

extern "C" {
void SkSVGFeComposite_delete(SkSVGFeComposite *svgFeComposite);
sk_image_filter_t SkSVGFeComposite_makeImageFilter(SkSVGFeComposite *svgFeComposite, const SkSVGRenderContext *ctx, const SkSVGFilterContext *fctx);
sk_rect_t SkSVGFeComposite_resolveFilterSubregion(SkSVGFeComposite *svgFeComposite, const SkSVGRenderContext *svgRenderContext, const SkSVGFilterContext *svgFilterContext);
SkSVGColorspace SkSVGFeComposite_resolveColorspace(SkSVGFeComposite *svgFeComposite, const SkSVGRenderContext *svgRenderContext, const SkSVGFilterContext *svgFilterContext);
void SkSVGFeComposite_applyProperties(SkSVGFeComposite *svgFeComposite, SkSVGRenderContext *svgRenderContext);
void SkSVGFeComposite_appendChild(sk_svg_node_t svg_node, SkSVGFeComposite *svgFeComposite);
void SkSVGFeComposite_setTransform(SkSVGFeComposite *svgFeComposite, const SkSVGTransformType *t);
SkSVGTag SkSVGFeComposite_tag(SkSVGFeComposite *svgFeComposite);
void SkSVGFeComposite_render(SkSVGFeComposite *svgFeComposite, const SkSVGRenderContext *svgRenderContext);
bool SkSVGFeComposite_asPaint(SkSVGFeComposite *svgFeComposite, const SkSVGRenderContext &svgRenderContext, SkPaint *paint);
sk_path_t SkSVGFeComposite_asPath(SkSVGFeComposite *svgFeComposite, const SkSVGRenderContext *svgRenderContext);
sk_rect_t SkSVGFeComposite_objectBoundingBox(SkSVGFeComposite *svgFeComposite, const SkSVGRenderContext *svgRenderContext);
void SkSVGFeComposite_setAttribute(SkSVGFeComposite *svgFeComposite, SkSVGAttribute svgAttribute, const SkSVGValue *svgValue);
//bool SkSVGFeComposite_setAttribute(SkSVGFeComposite *svgFeComposite, const char *attributeName, const char *attributeValue);
bool SkSVGFeComposite_unique(SkSVGFeComposite *svgFeComposite);
void SkSVGFeComposite_ref(SkSVGFeComposite *svgFeComposite);
void SkSVGFeComposite_unref(SkSVGFeComposite *svgFeComposite);
// static
sk_svg_fe_composite_t SkSVGFeComposite_Make ();
bool SkSVGFeComposite_IsFilterEffect (const sk_sp< SkSVGNode > *node);
}

#endif //RAIA_SKIA_SK_SVG_FE_COMPOSITE_H
