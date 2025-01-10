//
// Created by dolphilia on 2024/02/06.
//

#ifndef RAIA_SKIA_SK_SVG_FE_H
#define RAIA_SKIA_SK_SVG_FE_H

#include "modules/svg/include/SkSVGFe.h"
#include "../static/static_sk_svg_node.h"
#include "../static/static_sk_path.h"
#include "../static/static_sk_rect.h"
#include "../static/static_sk_image_filter.h"

extern "C" {
void SkSVGFe_delete(SkSVGFe *svgFe);
sk_image_filter_t SkSVGFe_makeImageFilter (SkSVGFe *svgFe, const SkSVGRenderContext *ctx, const SkSVGFilterContext *fctx);
sk_rect_t SkSVGFe_resolveFilterSubregion (SkSVGFe *svgFe, const SkSVGRenderContext *svgRenderContext, const SkSVGFilterContext *svgFilterContext);
SkSVGColorspace SkSVGFe_resolveColorspace (SkSVGFe *svgFe, const SkSVGRenderContext *svgRenderContext, const SkSVGFilterContext *svgFilterContext);
void SkSVGFe_applyProperties (SkSVGFe *svgFe, SkSVGRenderContext *svgRenderContext);
void SkSVGFe_appendChild(SkSVGFe *svgFe, sk_svg_node_t svg_node);
void SkSVGFe_setTransform (SkSVGFe *svgFe, const SkSVGTransformType *t);
SkSVGTag SkSVGFe_tag (SkSVGFe *svgFe);
void SkSVGFe_render (SkSVGFe *svgFe, const SkSVGRenderContext *svgRenderContext);
bool SkSVGFe_asPaint (SkSVGFe *svgFe, const SkSVGRenderContext *svgRenderContext, SkPaint *paint);
sk_path_t SkSVGFe_asPath (SkSVGFe *svgFe, const SkSVGRenderContext *svgRenderContext);
sk_rect_t SkSVGFe_objectBoundingBox (SkSVGFe *svgFe, const SkSVGRenderContext *svgRenderContext);
void SkSVGFe_setAttribute (SkSVGFe *svgFe, SkSVGAttribute svgAttribute, const SkSVGValue *svgValue);
//bool SkSVGFe_setAttribute (SkSVGFe *svgFe, const char *attributeName, const char *attributeValue);
bool SkSVGFe_unique (SkSVGFe *svgFe);
void SkSVGFe_ref (SkSVGFe *svgFe);
void SkSVGFe_unref (SkSVGFe *svgFe);
// static
bool SkSVGFe_IsFilterEffect (const sk_sp<SkSVGNode> *node);
}

#endif //RAIA_SKIA_SK_SVG_FE_H
