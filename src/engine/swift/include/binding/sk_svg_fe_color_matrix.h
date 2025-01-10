//
// Created by dolphilia on 2024/02/06.
//

#ifndef RAIA_SKIA_SK_SVG_FE_COLOR_MATRIX_H
#define RAIA_SKIA_SK_SVG_FE_COLOR_MATRIX_H

#include "modules/svg/include/SkSVGFeColorMatrix.h"
#include "../static/static_sk_svg_node.h"
#include "../static/static_sk_path.h"
#include "../static/static_sk_rect.h"
#include "../static/static_sk_image_filter.h"
#include "../static/static_sk_svg_fe_color_matrix.h"

extern "C" {
void SkSVGFeColorMatrix_delete(SkSVGFeColorMatrix *svgFeColorMatrix);
sk_image_filter_t SkSVGFeColorMatrix_makeImageFilter (SkSVGFeColorMatrix *svgFeColorMatrix, const SkSVGRenderContext *ctx, const SkSVGFilterContext *fctx);
sk_rect_t SkSVGFeColorMatrix_resolveFilterSubregion (SkSVGFeColorMatrix *svgFeColorMatrix, const SkSVGRenderContext *svgRenderContext, const SkSVGFilterContext *svgFilterContext);
SkSVGColorspace SkSVGFeColorMatrix_resolveColorspace (SkSVGFeColorMatrix *svgFeColorMatrix, const SkSVGRenderContext *svgRenderContext, const SkSVGFilterContext *svgFilterContext);
void SkSVGFeColorMatrix_applyProperties (SkSVGFeColorMatrix *svgFeColorMatrix, SkSVGRenderContext *svgRenderContext);
void SkSVGFeColorMatrix_appendChild(SkSVGFeColorMatrix *svgFeColorMatrix, sk_svg_node_t svg_node);
void SkSVGFeColorMatrix_setTransform (SkSVGFeColorMatrix *svgFeColorMatrix, const SkSVGTransformType *t);
SkSVGTag SkSVGFeColorMatrix_tag (SkSVGFeColorMatrix *svgFeColorMatrix);
void SkSVGFeColorMatrix_render (SkSVGFeColorMatrix *svgFeColorMatrix, const SkSVGRenderContext *svgRenderContext);
bool SkSVGFeColorMatrix_asPaint (SkSVGFeColorMatrix *svgFeColorMatrix, const SkSVGRenderContext *svgRenderContext, SkPaint *paint);
sk_path_t SkSVGFeColorMatrix_asPath (SkSVGFeColorMatrix *svgFeColorMatrix, const SkSVGRenderContext *svgRenderContext);
sk_rect_t SkSVGFeColorMatrix_objectBoundingBox (SkSVGFeColorMatrix *svgFeColorMatrix, const SkSVGRenderContext *svgRenderContext);
void SkSVGFeColorMatrix_setAttribute (SkSVGFeColorMatrix *svgFeColorMatrix, SkSVGAttribute svgAttribute, const SkSVGValue *svgValue);
//bool SkSVGFeColorMatrix_setAttribute (SkSVGFeColorMatrix *svgFeColorMatrix, const char *attributeName, const char *attributeValue);
bool SkSVGFeColorMatrix_unique (SkSVGFeColorMatrix *svgFeColorMatrix);
void SkSVGFeColorMatrix_ref (SkSVGFeColorMatrix *svgFeColorMatrix);
void SkSVGFeColorMatrix_unref (SkSVGFeColorMatrix *svgFeColorMatrix);
// static
sk_svg_fe_color_matrix_t SkSVGFeColorMatrix_Make ();
bool SkSVGFeColorMatrix_IsFilterEffect (const sk_sp< SkSVGNode > *node);
}

#endif //RAIA_SKIA_SK_SVG_FE_COLOR_MATRIX_H
