//
// Created by dolphilia on 2024/02/06.
//

#include "sk_svg_fe_diffuse_lighting.h"

extern "C" {

void SkSVGFeDiffuseLighting_delete(SkSVGFeDiffuseLighting *svgFeDiffuseLighting) {
    delete svgFeDiffuseLighting;
}

sk_image_filter_t SkSVGFeDiffuseLighting_makeImageFilter(SkSVGFeDiffuseLighting *svgFeDiffuseLighting, const SkSVGRenderContext *ctx, const SkSVGFilterContext *fctx) {
    return static_sk_image_filter_make(svgFeDiffuseLighting->makeImageFilter(*ctx, *fctx));
}

sk_rect_t SkSVGFeDiffuseLighting_resolveFilterSubregion(SkSVGFeDiffuseLighting *svgFeDiffuseLighting, const SkSVGRenderContext *svgRenderContext, const SkSVGFilterContext *svgFilterContext) {
    return static_sk_rect_make(svgFeDiffuseLighting->resolveFilterSubregion(*svgRenderContext, *svgFilterContext));
}

SkSVGColorspace SkSVGFeDiffuseLighting_resolveColorspace(SkSVGFeDiffuseLighting *svgFeDiffuseLighting, const SkSVGRenderContext *svgRenderContext, const SkSVGFilterContext *svgFilterContext) {
    return svgFeDiffuseLighting->resolveColorspace(*svgRenderContext, *svgFilterContext);
}

void SkSVGFeDiffuseLighting_applyProperties(SkSVGFeDiffuseLighting *svgFeDiffuseLighting, SkSVGRenderContext *svgRenderContext) {
    svgFeDiffuseLighting->applyProperties(svgRenderContext);
}

void SkSVGFeDiffuseLighting_appendChild(SkSVGFeDiffuseLighting *svgFeDiffuseLighting, sk_svg_node_t svg_node) {
    svgFeDiffuseLighting->appendChild(static_sk_svg_node_move(svg_node));
}

void SkSVGFeDiffuseLighting_setTransform(SkSVGFeDiffuseLighting *svgFeDiffuseLighting, const SkSVGTransformType *t) {
    svgFeDiffuseLighting->setTransform(*t);
}

SkSVGTag SkSVGFeDiffuseLighting_tag(SkSVGFeDiffuseLighting *svgFeDiffuseLighting) {
    return svgFeDiffuseLighting->tag();
}

void SkSVGFeDiffuseLighting_render(SkSVGFeDiffuseLighting *svgFeDiffuseLighting, const SkSVGRenderContext *svgRenderContext) {
    svgFeDiffuseLighting->render(*svgRenderContext);
}

bool SkSVGFeDiffuseLighting_asPaint(SkSVGFeDiffuseLighting *svgFeDiffuseLighting, const SkSVGRenderContext *svgRenderContext, SkPaint *paint) {
    return svgFeDiffuseLighting->asPaint(*svgRenderContext, paint);
}

sk_path_t SkSVGFeDiffuseLighting_asPath(SkSVGFeDiffuseLighting *svgFeDiffuseLighting, const SkSVGRenderContext *svgRenderContext) {
    return static_sk_path_make(svgFeDiffuseLighting->asPath(*svgRenderContext));
}

sk_rect_t SkSVGFeDiffuseLighting_objectBoundingBox(SkSVGFeDiffuseLighting *svgFeDiffuseLighting, const SkSVGRenderContext *svgRenderContext) {
    return static_sk_rect_make(svgFeDiffuseLighting->objectBoundingBox(*svgRenderContext));
}

void SkSVGFeDiffuseLighting_setAttribute(SkSVGFeDiffuseLighting *svgFeDiffuseLighting, SkSVGAttribute svgAttribute, const SkSVGValue &svgValue) {
    svgFeDiffuseLighting->setAttribute(svgAttribute, svgValue);
}

//bool SkSVGFeDiffuseLighting_setAttribute(SkSVGFeDiffuseLighting *svgFeDiffuseLighting, const char *attributeName, const char *attributeValue) {
//    svgFeDiffuseLighting->
//}

bool SkSVGFeDiffuseLighting_unique(SkSVGFeDiffuseLighting *svgFeDiffuseLighting) {
    return svgFeDiffuseLighting->unique();
}

void SkSVGFeDiffuseLighting_ref(SkSVGFeDiffuseLighting *svgFeDiffuseLighting) {
    svgFeDiffuseLighting->ref();
}

void SkSVGFeDiffuseLighting_unref(SkSVGFeDiffuseLighting *svgFeDiffuseLighting) {
    svgFeDiffuseLighting->unref();
}

// static

sk_svg_fe_diffuse_lighting_t SkSVGFeDiffuseLighting_Make() {
    return static_sk_svg_fe_diffuse_lighting_make(SkSVGFeDiffuseLighting::Make());
}

bool SkSVGFeDiffuseLighting_IsFilterEffect (const sk_sp< SkSVGNode > *node) {
    return SkSVGFeDiffuseLighting::IsFilterEffect(*node);
}

}