//
// Created by dolphilia on 2024/02/06.
//

#include "sk_svg_fe_gaussian_blur.h"

extern "C" {

void SkSVGFeGaussianBlur_delete(SkSVGFeGaussianBlur *svgFeGaussianBlur) {
    delete svgFeGaussianBlur;
}

sk_image_filter_t SkSVGFeGaussianBlur_makeImageFilter(SkSVGFeGaussianBlur *svgFeGaussianBlur, const SkSVGRenderContext *ctx, const SkSVGFilterContext *fctx) {
    return static_sk_image_filter_make(svgFeGaussianBlur->makeImageFilter(*ctx, *fctx));
}

sk_rect_t SkSVGFeGaussianBlur_resolveFilterSubregion(SkSVGFeGaussianBlur *svgFeGaussianBlur, const SkSVGRenderContext *svgRenderContext, const SkSVGFilterContext *svgFilterContext) {
    return static_sk_rect_make(svgFeGaussianBlur->resolveFilterSubregion(*svgRenderContext, *svgFilterContext));
}

SkSVGColorspace SkSVGFeGaussianBlur_resolveColorspace(SkSVGFeGaussianBlur *svgFeGaussianBlur, const SkSVGRenderContext *svgRenderContext, const SkSVGFilterContext *svgFilterContext) {
    return svgFeGaussianBlur->resolveColorspace(*svgRenderContext, *svgFilterContext);
}

void SkSVGFeGaussianBlur_applyProperties(SkSVGFeGaussianBlur *svgFeGaussianBlur, SkSVGRenderContext *svgRenderContext) {
    svgFeGaussianBlur->applyProperties(svgRenderContext);
}

void SkSVGFeGaussianBlur_appendChild(SkSVGFeGaussianBlur *svgFeGaussianBlur, sk_svg_node_t svg_node) {
    svgFeGaussianBlur->appendChild(static_sk_svg_node_move(svg_node));
}

void SkSVGFeGaussianBlur_setTransform(SkSVGFeGaussianBlur *svgFeGaussianBlur, const SkSVGTransformType *t) {
    svgFeGaussianBlur->setTransform(*t);
}

SkSVGTag SkSVGFeGaussianBlur_tag(SkSVGFeGaussianBlur *svgFeGaussianBlur) {
    return svgFeGaussianBlur->tag();
}

void SkSVGFeGaussianBlur_render(SkSVGFeGaussianBlur *svgFeGaussianBlur, const SkSVGRenderContext *svgRenderContext) {
    svgFeGaussianBlur->render(*svgRenderContext);
}

bool SkSVGFeGaussianBlur_asPaint(SkSVGFeGaussianBlur *svgFeGaussianBlur, const SkSVGRenderContext *svgRenderContext, SkPaint *paint) {
    return svgFeGaussianBlur->asPaint(*svgRenderContext, paint);
}

sk_path_t SkSVGFeGaussianBlur_asPath(SkSVGFeGaussianBlur *svgFeGaussianBlur, const SkSVGRenderContext *svgRenderContext) {
    return static_sk_path_make(svgFeGaussianBlur->asPath(*svgRenderContext));
}

sk_rect_t SkSVGFeGaussianBlur_objectBoundingBox(SkSVGFeGaussianBlur *svgFeGaussianBlur, const SkSVGRenderContext *svgRenderContext) {
    return static_sk_rect_make(svgFeGaussianBlur->objectBoundingBox(*svgRenderContext));
}

void SkSVGFeGaussianBlur_setAttribute(SkSVGFeGaussianBlur *svgFeGaussianBlur, SkSVGAttribute svgAttribute, const SkSVGValue *svgValue) {
    svgFeGaussianBlur->setAttribute(svgAttribute, *svgValue);
}

// bool SkSVGFeGaussianBlur_setAttribute(SkSVGFeGaussianBlur *svgFeGaussianBlur, const char *attributeName, const char *attributeValue) {
//     svgFeGaussianBlur->
// }

bool SkSVGFeGaussianBlur_unique(SkSVGFeGaussianBlur *svgFeGaussianBlur) {
    return svgFeGaussianBlur->unique();
}

void SkSVGFeGaussianBlur_ref(SkSVGFeGaussianBlur *svgFeGaussianBlur) {
    svgFeGaussianBlur->ref();
}

void SkSVGFeGaussianBlur_unref(SkSVGFeGaussianBlur *svgFeGaussianBlur) {
    svgFeGaussianBlur->unref();
}

// static

sk_svg_fe_gaussian_blur_t SkSVGFeGaussianBlur_Make() {
    return static_sk_svg_fe_gaussian_blur_make(SkSVGFeGaussianBlur::Make());
}

bool SkSVGFeGaussianBlur_IsFilterEffect (const sk_sp< SkSVGNode > *node) {
    return SkSVGFeGaussianBlur::IsFilterEffect(*node);
}

}