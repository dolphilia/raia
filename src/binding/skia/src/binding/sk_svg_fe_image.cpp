//
// Created by dolphilia on 2024/02/06.
//

#include "sk_svg_fe_image.h"

extern "C" {

void SkSVGFeImage_delete(SkSVGFeImage *svgFeImage) {
    delete svgFeImage;
}

sk_image_filter_t SkSVGFeImage_makeImageFilter(SkSVGFeImage *svgFeImage, const SkSVGRenderContext *ctx, const SkSVGFilterContext *fctx) {
    return static_sk_image_filter_make(svgFeImage->makeImageFilter(*ctx, *fctx));
}

sk_rect_t SkSVGFeImage_resolveFilterSubregion(SkSVGFeImage *svgFeImage, const SkSVGRenderContext *svgRenderContext, const SkSVGFilterContext *svgFilterContext) {
    return static_sk_rect_make(svgFeImage->resolveFilterSubregion(*svgRenderContext, *svgFilterContext));
}

SkSVGColorspace SkSVGFeImage_resolveColorspace(SkSVGFeImage *svgFeImage, const SkSVGRenderContext *svgRenderContext, const SkSVGFilterContext *svgFilterContext) {
    return svgFeImage->resolveColorspace(*svgRenderContext, *svgFilterContext);
}

void SkSVGFeImage_applyProperties(SkSVGFeImage *svgFeImage, SkSVGRenderContext *svgRenderContext) {
    svgFeImage->applyProperties(svgRenderContext);
}

void SkSVGFeImage_appendChild(SkSVGFeImage *svgFeImage, sk_svg_node_t svg_node) {
    svgFeImage->appendChild(static_sk_svg_node_move(svg_node));
}

void SkSVGFeImage_setTransform(SkSVGFeImage *svgFeImage, const SkSVGTransformType *t) {
    svgFeImage->setTransform(*t);
}

SkSVGTag SkSVGFeImage_tag(SkSVGFeImage *svgFeImage) {
    return svgFeImage->tag();
}

void SkSVGFeImage_render(SkSVGFeImage *svgFeImage, const SkSVGRenderContext *svgRenderContext) {
    svgFeImage->render(*svgRenderContext);
}

bool SkSVGFeImage_asPaint(SkSVGFeImage *svgFeImage, const SkSVGRenderContext *svgRenderContext, SkPaint *paint) {
    return svgFeImage->asPaint(*svgRenderContext, paint);
}

sk_path_t SkSVGFeImage_asPath(SkSVGFeImage *svgFeImage, const SkSVGRenderContext *svgRenderContext) {
    return static_sk_path_make(svgFeImage->asPath(*svgRenderContext));
}

sk_rect_t SkSVGFeImage_objectBoundingBox(SkSVGFeImage *svgFeImage, const SkSVGRenderContext *svgRenderContext) {
    return static_sk_rect_make(svgFeImage->objectBoundingBox(*svgRenderContext));
}

void SkSVGFeImage_setAttribute(SkSVGFeImage *svgFeImage, SkSVGAttribute svgAttribute, const SkSVGValue *svgValue) {
    svgFeImage->setAttribute(svgAttribute, *svgValue);
}

// bool SkSVGFeImage_setAttribute(SkSVGFeImage *svgFeImage, const char *attributeName, const char *attributeValue) {
//     svgFeImage->
// }

bool SkSVGFeImage_unique(SkSVGFeImage *svgFeImage) {
    return svgFeImage->unique();
}

void SkSVGFeImage_ref(SkSVGFeImage *svgFeImage) {
    svgFeImage->ref();
}

void SkSVGFeImage_unref(SkSVGFeImage *svgFeImage) {
    svgFeImage->unref();
}

// static

//int SkSVGFeImage_Make() {
//    return static_sk_svg_fe_image_make(SkSVGFeImage::Make());
//}

bool SkSVGFeImage_IsFilterEffect (const sk_sp< SkSVGNode > *node) {
    return SkSVGFeImage::IsFilterEffect(*node);
}

}