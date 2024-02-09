//
// Created by dolphilia on 2024/02/06.
//

#include "sk_svg_fe_specular_lighting.h"

extern "C" {

void SkSVGFeSpecularLighting_delete(SkSVGFeSpecularLighting *svgFeSpecularLighting) {
    delete svgFeSpecularLighting;
}

sk_image_filter_t SkSVGFeSpecularLighting_makeImageFilter(SkSVGFeSpecularLighting *svgFeSpecularLighting, const SkSVGRenderContext *ctx, const SkSVGFilterContext *fctx) {
    return static_sk_image_filter_make(svgFeSpecularLighting->makeImageFilter(*ctx, *fctx));
}

sk_rect_t SkSVGFeSpecularLighting_resolveFilterSubregion(SkSVGFeSpecularLighting *svgFeSpecularLighting, const SkSVGRenderContext *svgRenderContext, const SkSVGFilterContext *svgFilterContext) {
    return static_sk_rect_make(svgFeSpecularLighting->resolveFilterSubregion(*svgRenderContext, *svgFilterContext));
}

SkSVGColorspace SkSVGFeSpecularLighting_resolveColorspace(SkSVGFeSpecularLighting *svgFeSpecularLighting, const SkSVGRenderContext *svgRenderContext, const SkSVGFilterContext *svgFilterContext) {
    return svgFeSpecularLighting->resolveColorspace(*svgRenderContext, *svgFilterContext);
}

void SkSVGFeSpecularLighting_applyProperties(SkSVGFeSpecularLighting *svgFeSpecularLighting, SkSVGRenderContext *svgRenderContext) {
    svgFeSpecularLighting->applyProperties(svgRenderContext);
}

void SkSVGFeSpecularLighting_appendChild(SkSVGFeSpecularLighting *svgFeSpecularLighting, sk_svg_node_t svg_node) {
    svgFeSpecularLighting->appendChild(static_sk_svg_node_move(svg_node));
}

void SkSVGFeSpecularLighting_setTransform(SkSVGFeSpecularLighting *svgFeSpecularLighting, const SkSVGTransformType *t) {
    svgFeSpecularLighting->setTransform(*t);
}

SkSVGTag SkSVGFeSpecularLighting_tag(SkSVGFeSpecularLighting *svgFeSpecularLighting) {
    return svgFeSpecularLighting->tag();
}

void SkSVGFeSpecularLighting_render(SkSVGFeSpecularLighting *svgFeSpecularLighting, const SkSVGRenderContext *svgRenderContext) {
    svgFeSpecularLighting->render(*svgRenderContext);
}

bool SkSVGFeSpecularLighting_asPaint(SkSVGFeSpecularLighting *svgFeSpecularLighting, const SkSVGRenderContext *svgRenderContext, SkPaint *paint) {
    return svgFeSpecularLighting->asPaint(*svgRenderContext, paint);
}

sk_path_t SkSVGFeSpecularLighting_asPath(SkSVGFeSpecularLighting *svgFeSpecularLighting, const SkSVGRenderContext *svgRenderContext) {
    return static_sk_path_make(svgFeSpecularLighting->asPath(*svgRenderContext));
}

sk_rect_t SkSVGFeSpecularLighting_objectBoundingBox(SkSVGFeSpecularLighting *svgFeSpecularLighting, const SkSVGRenderContext *svgRenderContext) {
    return static_sk_rect_make(svgFeSpecularLighting->objectBoundingBox(*svgRenderContext));
}

void SkSVGFeSpecularLighting_setAttribute(SkSVGFeSpecularLighting *svgFeSpecularLighting, SkSVGAttribute svgAttribute, const SkSVGValue *svgValue) {
    svgFeSpecularLighting->setAttribute(svgAttribute, *svgValue);
}

// bool SkSVGFeSpecularLighting_setAttribute(SkSVGFeSpecularLighting *svgFeSpecularLighting, const char *attributeName, const char *attributeValue) {
//     svgFeSpecularLighting->
// }

bool SkSVGFeSpecularLighting_unique(SkSVGFeSpecularLighting *svgFeSpecularLighting) {
    return svgFeSpecularLighting->unique();
}

void SkSVGFeSpecularLighting_ref(SkSVGFeSpecularLighting *svgFeSpecularLighting) {
    svgFeSpecularLighting->ref();
}

void SkSVGFeSpecularLighting_unref(SkSVGFeSpecularLighting *svgFeSpecularLighting) {
    svgFeSpecularLighting->unref();
}

// static

sk_svg_fe_specular_lighting_t SkSVGFeSpecularLighting_Make() {
    return static_sk_svg_fe_specular_lighting_make(SkSVGFeSpecularLighting::Make());
}

bool SkSVGFeSpecularLighting_IsFilterEffect (const sk_sp< SkSVGNode > *node) {
    return SkSVGFeSpecularLighting::IsFilterEffect(*node);
}

}