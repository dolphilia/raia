//
// Created by dolphilia on 2024/02/06.
//

#ifndef RAIA_SKIA_SK_SVG_FE_GAUSSIAN_BLUR_H
#define RAIA_SKIA_SK_SVG_FE_GAUSSIAN_BLUR_H

#include "modules/svg/include/SkSVGFeGaussianBlur.h"
#include "../static/static_sk_svg_node.h"
#include "../static/static_sk_path.h"
#include "../static/static_sk_rect.h"
#include "../static/static_sk_image_filter.h"
#include "../static/static_sk_svg_fe_gaussian_blur.h"

extern "C" {
void SkSVGFeGaussianBlur_delete(SkSVGFeGaussianBlur *svgFeGaussianBlur);
sk_image_filter_t SkSVGFeGaussianBlur_makeImageFilter(SkSVGFeGaussianBlur *svgFeGaussianBlur, const SkSVGRenderContext *ctx, const SkSVGFilterContext *fctx);
sk_rect_t SkSVGFeGaussianBlur_resolveFilterSubregion(SkSVGFeGaussianBlur *svgFeGaussianBlur, const SkSVGRenderContext *svgRenderContext, const SkSVGFilterContext *svgFilterContext);
SkSVGColorspace SkSVGFeGaussianBlur_resolveColorspace(SkSVGFeGaussianBlur *svgFeGaussianBlur, const SkSVGRenderContext *svgRenderContext, const SkSVGFilterContext *svgFilterContext);
void SkSVGFeGaussianBlur_applyProperties(SkSVGFeGaussianBlur *svgFeGaussianBlur, SkSVGRenderContext *svgRenderContext);
void SkSVGFeGaussianBlur_appendChild(SkSVGFeGaussianBlur *svgFeGaussianBlur, sk_svg_node_t svg_node);
void SkSVGFeGaussianBlur_setTransform(SkSVGFeGaussianBlur *svgFeGaussianBlur, const SkSVGTransformType *t);
SkSVGTag SkSVGFeGaussianBlur_tag(SkSVGFeGaussianBlur *svgFeGaussianBlur);
void SkSVGFeGaussianBlur_render(SkSVGFeGaussianBlur *svgFeGaussianBlur, const SkSVGRenderContext *svgRenderContext);
bool SkSVGFeGaussianBlur_asPaint(SkSVGFeGaussianBlur *svgFeGaussianBlur, const SkSVGRenderContext *svgRenderContext, SkPaint *paint);
sk_path_t SkSVGFeGaussianBlur_asPath(SkSVGFeGaussianBlur *svgFeGaussianBlur, const SkSVGRenderContext *svgRenderContext);
sk_rect_t SkSVGFeGaussianBlur_objectBoundingBox(SkSVGFeGaussianBlur *svgFeGaussianBlur, const SkSVGRenderContext *svgRenderContext);
void SkSVGFeGaussianBlur_setAttribute(SkSVGFeGaussianBlur *svgFeGaussianBlur, SkSVGAttribute svgAttribute, const SkSVGValue *svgValue);
// bool SkSVGFeGaussianBlur_setAttribute(SkSVGFeGaussianBlur *svgFeGaussianBlur, const char *attributeName, const char *attributeValue);
bool SkSVGFeGaussianBlur_unique(SkSVGFeGaussianBlur *svgFeGaussianBlur);
void SkSVGFeGaussianBlur_ref(SkSVGFeGaussianBlur *svgFeGaussianBlur);
void SkSVGFeGaussianBlur_unref(SkSVGFeGaussianBlur *svgFeGaussianBlur);
// static
sk_svg_fe_gaussian_blur_t SkSVGFeGaussianBlur_Make();
bool SkSVGFeGaussianBlur_IsFilterEffect (const sk_sp< SkSVGNode > *node);
}

#endif //RAIA_SKIA_SK_SVG_FE_GAUSSIAN_BLUR_H
