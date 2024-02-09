//
// Created by dolphilia on 2024/02/06.
//

#include "sk_svg_fe_blend.h"

extern "C" {

void SkSVGFeBlend_delete(SkSVGFeBlend *svgFeBlend) {
    delete svgFeBlend;
}

sk_image_filter_t SkSVGFeBlend_makeImageFilter (SkSVGFeBlend *svgFeBlend, const SkSVGRenderContext *ctx, const SkSVGFilterContext *fctx) {
    return static_sk_image_filter_make(svgFeBlend->makeImageFilter(*ctx, *fctx));
}

sk_rect_t SkSVGFeBlend_resolveFilterSubregion (SkSVGFeBlend *svgFeBlend, const SkSVGRenderContext *svgRenderContext, const SkSVGFilterContext *svgFilterContext) {
    return static_sk_rect_make(svgFeBlend->resolveFilterSubregion(*svgRenderContext, *svgFilterContext));
}

SkSVGColorspace SkSVGFeBlend_resolveColorspace (SkSVGFeBlend *svgFeBlend, const SkSVGRenderContext *svgRenderContext, const SkSVGFilterContext *svgFilterContext) {
    return svgFeBlend->resolveColorspace(*svgRenderContext, *svgFilterContext);
}

void SkSVGFeBlend_applyProperties (SkSVGFeBlend *svgFeBlend, SkSVGRenderContext *svgRenderContext) {
    svgFeBlend->applyProperties(svgRenderContext);
}

void SkSVGFeBlend_appendChild(SkSVGFeBlend *svgFeBlend, sk_svg_node_t svg_node) {
    svgFeBlend->appendChild(static_sk_svg_node_move(svg_node));
}

void SkSVGFeBlend_setTransform (SkSVGFeBlend *svgFeBlend, const SkSVGTransformType *t) {
    svgFeBlend->setTransform(*t);
}

SkSVGTag SkSVGFeBlend_tag (SkSVGFeBlend *svgFeBlend) {
    return svgFeBlend->tag();
}

void SkSVGFeBlend_render (SkSVGFeBlend *svgFeBlend, const SkSVGRenderContext &svgRenderContext) {
    svgFeBlend->render(svgRenderContext);
}

bool SkSVGFeBlend_asPaint (SkSVGFeBlend *svgFeBlend, const SkSVGRenderContext *svgRenderContext, SkPaint *paint) {
    return svgFeBlend->asPaint(*svgRenderContext, paint);
}

sk_path_t SkSVGFeBlend_asPath (SkSVGFeBlend *svgFeBlend, const SkSVGRenderContext *svgRenderContext) {
    return static_sk_path_make(svgFeBlend->asPath(*svgRenderContext));
}

sk_rect_t SkSVGFeBlend_objectBoundingBox (SkSVGFeBlend *svgFeBlend, const SkSVGRenderContext *svgRenderContext) {
    return static_sk_rect_make(svgFeBlend->objectBoundingBox(*svgRenderContext));
}

void SkSVGFeBlend_setAttribute (SkSVGFeBlend *svgFeBlend, SkSVGAttribute svgAttribute, const SkSVGValue &svgValue) {
    svgFeBlend->setAttribute(svgAttribute, svgValue);
}

//bool SkSVGFeBlend_setAttribute (SkSVGFeBlend *svgFeBlend, const char *attributeName, const char *attributeValue) {
//    return svgFeBlend->setAttribute(attributeName, attributeValue);
//}

bool SkSVGFeBlend_unique (SkSVGFeBlend *svgFeBlend) {
    return svgFeBlend->unique();
}

void SkSVGFeBlend_ref (SkSVGFeBlend *svgFeBlend) {
    svgFeBlend->ref();
}

void SkSVGFeBlend_unref (SkSVGFeBlend *svgFeBlend) {
    svgFeBlend->unref();
}


// static

sk_svg_fe_blend_t SkSVGFeBlend_Make () {
    return static_sk_svg_fe_blend_make(SkSVGFeBlend::Make());
}

bool SkSVGFeBlend_IsFilterEffect (const sk_sp< SkSVGNode > *node) {
    return SkSVGFeBlend::IsFilterEffect(*node);
}

}