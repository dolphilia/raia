//
// Created by dolphilia on 2024/02/06.
//

#include "sk_svg_fe_color_matrix.h"

extern "C" {

void SkSVGFeColorMatrix_delete(SkSVGFeColorMatrix *svgFeColorMatrix) {
    delete svgFeColorMatrix;
}

sk_image_filter_t SkSVGFeColorMatrix_makeImageFilter (SkSVGFeColorMatrix *svgFeColorMatrix, const SkSVGRenderContext *ctx, const SkSVGFilterContext *fctx) {
    return static_sk_image_filter_make(svgFeColorMatrix->makeImageFilter(*ctx, *fctx));
}

sk_rect_t SkSVGFeColorMatrix_resolveFilterSubregion (SkSVGFeColorMatrix *svgFeColorMatrix, const SkSVGRenderContext *svgRenderContext, const SkSVGFilterContext *svgFilterContext) {
    return static_sk_rect_make(svgFeColorMatrix->resolveFilterSubregion(*svgRenderContext, *svgFilterContext));
}

SkSVGColorspace SkSVGFeColorMatrix_resolveColorspace (SkSVGFeColorMatrix *svgFeColorMatrix, const SkSVGRenderContext *svgRenderContext, const SkSVGFilterContext *svgFilterContext) {
    return svgFeColorMatrix->resolveColorspace(*svgRenderContext, *svgFilterContext);
}

void SkSVGFeColorMatrix_applyProperties (SkSVGFeColorMatrix *svgFeColorMatrix, SkSVGRenderContext *svgRenderContext) {
    svgFeColorMatrix->applyProperties(svgRenderContext);
}

void SkSVGFeColorMatrix_appendChild(SkSVGFeColorMatrix *svgFeColorMatrix, sk_svg_node_t svg_node) {
    svgFeColorMatrix->appendChild(static_sk_svg_node_move(svg_node));
}

void SkSVGFeColorMatrix_setTransform (SkSVGFeColorMatrix *svgFeColorMatrix, const SkSVGTransformType *t) {
    svgFeColorMatrix->setTransform(*t);
}

SkSVGTag SkSVGFeColorMatrix_tag (SkSVGFeColorMatrix *svgFeColorMatrix) {
    return svgFeColorMatrix->tag();
}

void SkSVGFeColorMatrix_render (SkSVGFeColorMatrix *svgFeColorMatrix, const SkSVGRenderContext *svgRenderContext) {
    svgFeColorMatrix->render(*svgRenderContext);
}

bool SkSVGFeColorMatrix_asPaint (SkSVGFeColorMatrix *svgFeColorMatrix, const SkSVGRenderContext *svgRenderContext, SkPaint *paint) {
    return svgFeColorMatrix->asPaint(*svgRenderContext, paint);
}

sk_path_t SkSVGFeColorMatrix_asPath (SkSVGFeColorMatrix *svgFeColorMatrix, const SkSVGRenderContext *svgRenderContext) {
    return static_sk_path_make(svgFeColorMatrix->asPath(*svgRenderContext));
}

sk_rect_t SkSVGFeColorMatrix_objectBoundingBox (SkSVGFeColorMatrix *svgFeColorMatrix, const SkSVGRenderContext *svgRenderContext) {
    return static_sk_rect_make(svgFeColorMatrix->objectBoundingBox(*svgRenderContext));
}

void SkSVGFeColorMatrix_setAttribute (SkSVGFeColorMatrix *svgFeColorMatrix, SkSVGAttribute svgAttribute, const SkSVGValue *svgValue) {
    svgFeColorMatrix->setAttribute(svgAttribute, *svgValue);
}

//bool SkSVGFeColorMatrix_setAttribute (SkSVGFeColorMatrix *svgFeColorMatrix, const char *attributeName, const char *attributeValue) {
//    return svgFeColorMatrix->setAttribute(attributeName, attributeValue);
//}

bool SkSVGFeColorMatrix_unique (SkSVGFeColorMatrix *svgFeColorMatrix) {
    return svgFeColorMatrix->unique();
}

void SkSVGFeColorMatrix_ref (SkSVGFeColorMatrix *svgFeColorMatrix) {
    svgFeColorMatrix->ref();
}

void SkSVGFeColorMatrix_unref (SkSVGFeColorMatrix *svgFeColorMatrix) {
    svgFeColorMatrix->unref();
}

// static

sk_svg_fe_color_matrix_t SkSVGFeColorMatrix_Make () {
    return static_sk_svg_fe_color_matrix_make(SkSVGFeColorMatrix::Make());
}

bool SkSVGFeColorMatrix_IsFilterEffect (const sk_sp< SkSVGNode > *node) {
    return SkSVGFeColorMatrix::IsFilterEffect(*node);
}

}