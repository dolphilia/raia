//
// Created by dolphilia on 2024/02/06.
//

#ifndef RAIA_SKIA_SK_SVG_FE_IMAGE_H
#define RAIA_SKIA_SK_SVG_FE_IMAGE_H

#include "modules/svg/include/SkSVGFeImage.h"
#include "../static/static_sk_svg_node.h"
#include "../static/static_sk_path.h"
#include "../static/static_sk_rect.h"
#include "../static/static_sk_image_filter.h"
#include "../static/static_sk_svg_fe_image.h"

extern "C" {
void SkSVGFeImage_delete(SkSVGFeImage *svgFeImage);
sk_image_filter_t SkSVGFeImage_makeImageFilter(SkSVGFeImage *svgFeImage, const SkSVGRenderContext *ctx, const SkSVGFilterContext *fctx);
sk_rect_t SkSVGFeImage_resolveFilterSubregion(SkSVGFeImage *svgFeImage, const SkSVGRenderContext *svgRenderContext, const SkSVGFilterContext *svgFilterContext);
SkSVGColorspace SkSVGFeImage_resolveColorspace(SkSVGFeImage *svgFeImage, const SkSVGRenderContext *svgRenderContext, const SkSVGFilterContext *svgFilterContext);
void SkSVGFeImage_applyProperties(SkSVGFeImage *svgFeImage, SkSVGRenderContext *svgRenderContext);
void SkSVGFeImage_appendChild(SkSVGFeImage *svgFeImage, sk_svg_node_t svg_node);
void SkSVGFeImage_setTransform(SkSVGFeImage *svgFeImage, const SkSVGTransformType *t);
SkSVGTag SkSVGFeImage_tag(SkSVGFeImage *svgFeImage);
void SkSVGFeImage_render(SkSVGFeImage *svgFeImage, const SkSVGRenderContext *svgRenderContext);
bool SkSVGFeImage_asPaint(SkSVGFeImage *svgFeImage, const SkSVGRenderContext *svgRenderContext, SkPaint *paint);
sk_path_t SkSVGFeImage_asPath(SkSVGFeImage *svgFeImage, const SkSVGRenderContext *svgRenderContext);
sk_rect_t SkSVGFeImage_objectBoundingBox(SkSVGFeImage *svgFeImage, const SkSVGRenderContext *svgRenderContext);
void SkSVGFeImage_setAttribute(SkSVGFeImage *svgFeImage, SkSVGAttribute svgAttribute, const SkSVGValue *svgValue);
// bool SkSVGFeImage_setAttribute(SkSVGFeImage *svgFeImage, const char *attributeName, const char *attributeValue);
bool SkSVGFeImage_unique(SkSVGFeImage *svgFeImage);
void SkSVGFeImage_ref(SkSVGFeImage *svgFeImage);
void SkSVGFeImage_unref(SkSVGFeImage *svgFeImage);
// static
//int SkSVGFeImage_Make();
bool SkSVGFeImage_IsFilterEffect (const sk_sp< SkSVGNode > *node);
}

#endif //RAIA_SKIA_SK_SVG_FE_IMAGE_H
