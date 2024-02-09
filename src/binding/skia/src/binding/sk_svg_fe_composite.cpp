//
// Created by dolphilia on 2024/02/06.
//

#include "sk_svg_fe_composite.h"

extern "C" {

void SkSVGFeComposite_delete(SkSVGFeComposite *svgFeComposite) {
    delete svgFeComposite;
}

sk_image_filter_t SkSVGFeComposite_makeImageFilter(SkSVGFeComposite *svgFeComposite, const SkSVGRenderContext *ctx, const SkSVGFilterContext *fctx) {
    return static_sk_image_filter_make(svgFeComposite->makeImageFilter(*ctx, *fctx));
}

sk_rect_t SkSVGFeComposite_resolveFilterSubregion(SkSVGFeComposite *svgFeComposite, const SkSVGRenderContext *svgRenderContext, const SkSVGFilterContext *svgFilterContext) {
    return static_sk_rect_make(svgFeComposite->resolveFilterSubregion(*svgRenderContext, *svgFilterContext));
}

SkSVGColorspace SkSVGFeComposite_resolveColorspace(SkSVGFeComposite *svgFeComposite, const SkSVGRenderContext *svgRenderContext, const SkSVGFilterContext *svgFilterContext) {
    return svgFeComposite->resolveColorspace(*svgRenderContext, *svgFilterContext);
}

void SkSVGFeComposite_applyProperties(SkSVGFeComposite *svgFeComposite, SkSVGRenderContext *svgRenderContext) {
    svgFeComposite->applyProperties(svgRenderContext);
}

void SkSVGFeComposite_apzpendChild(SkSVGFeComposite *svgFeComposite, sk_svg_node_t svg_node) {
    svgFeComposite->appendChild(static_sk_svg_node_move(svg_node));
}

void SkSVGFeComposite_setTransform(SkSVGFeComposite *svgFeComposite, const SkSVGTransformType *t) {
    svgFeComposite->setTransform(*t);
}

SkSVGTag SkSVGFeComposite_tag(SkSVGFeComposite *svgFeComposite) {
    return svgFeComposite->tag();
}

void SkSVGFeComposite_render(SkSVGFeComposite *svgFeComposite, const SkSVGRenderContext *svgRenderContext) {
    svgFeComposite->render(*svgRenderContext);
}

bool SkSVGFeComposite_asPaint(SkSVGFeComposite *svgFeComposite, const SkSVGRenderContext &svgRenderContext, SkPaint *paint) {
    return svgFeComposite->asPaint(svgRenderContext, paint);
}

sk_path_t SkSVGFeComposite_asPath(SkSVGFeComposite *svgFeComposite, const SkSVGRenderContext *svgRenderContext) {
    return static_sk_path_make(svgFeComposite->asPath(*svgRenderContext));
}

sk_rect_t SkSVGFeComposite_objectBoundingBox(SkSVGFeComposite *svgFeComposite, const SkSVGRenderContext *svgRenderContext) {
    return static_sk_rect_make(svgFeComposite->objectBoundingBox(*svgRenderContext));
}

void SkSVGFeComposite_setAttribute(SkSVGFeComposite *svgFeComposite, SkSVGAttribute svgAttribute, const SkSVGValue *svgValue) {
    svgFeComposite->setAttribute(svgAttribute, *svgValue);
}

//bool SkSVGFeComposite_setAttribute(SkSVGFeComposite *svgFeComposite, const char *attributeName, const char *attributeValue) {
//    svgFeComposite->
//}

bool SkSVGFeComposite_unique(SkSVGFeComposite *svgFeComposite) {
    return svgFeComposite->unique();
}

void SkSVGFeComposite_ref(SkSVGFeComposite *svgFeComposite) {
    svgFeComposite->ref();
}

void SkSVGFeComposite_unref(SkSVGFeComposite *svgFeComposite) {
    svgFeComposite->unref();
}

// static

sk_svg_fe_composite_t SkSVGFeComposite_Make () {
    return static_sk_svg_fe_composite_make(SkSVGFeComposite::Make());
}

bool SkSVGFeComposite_IsFilterEffect (const sk_sp< SkSVGNode > *node) {
    return SkSVGFeComposite::IsFilterEffect(*node);
}

}