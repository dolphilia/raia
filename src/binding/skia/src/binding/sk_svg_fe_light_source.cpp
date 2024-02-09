//
// Created by dolphilia on 2024/02/06.
//

#include "sk_svg_fe_light_source.h"

extern "C" {

void SkSVGFeLighting_delete(SkSVGFeLighting *svgFeLighting) {
    delete svgFeLighting;
}

sk_image_filter_t SkSVGFeLighting_makeImageFilter(SkSVGFeLighting *svgFeLighting, const SkSVGRenderContext *ctx, const SkSVGFilterContext *fctx) {
    return static_sk_image_filter_make(svgFeLighting->makeImageFilter(*ctx, *fctx));
}

sk_rect_t SkSVGFeLighting_resolveFilterSubregion(SkSVGFeLighting *svgFeLighting, const SkSVGRenderContext *svgRenderContext, const SkSVGFilterContext *svgFilterContext) {
    return static_sk_rect_make(svgFeLighting->resolveFilterSubregion(*svgRenderContext, *svgFilterContext));
}

SkSVGColorspace SkSVGFeLighting_resolveColorspace(SkSVGFeLighting *svgFeLighting, const SkSVGRenderContext *svgRenderContext, const SkSVGFilterContext *svgFilterContext) {
    return svgFeLighting->resolveColorspace(*svgRenderContext, *svgFilterContext);
}

void SkSVGFeLighting_applyProperties(SkSVGFeLighting *svgFeLighting, SkSVGRenderContext *svgRenderContext) {
    svgFeLighting->applyProperties(svgRenderContext);
}

void SkSVGFeLighting_appendChild(SkSVGFeLighting *svgFeLighting, sk_svg_node_t svg_node) {
    svgFeLighting->appendChild(static_sk_svg_node_move(svg_node));
}

void SkSVGFeLighting_setTransform(SkSVGFeLighting *svgFeLighting, const SkSVGTransformType *t) {
    svgFeLighting->setTransform(*t);
}

SkSVGTag SkSVGFeLighting_tag(SkSVGFeLighting *svgFeLighting) {
    return svgFeLighting->tag();
}

void SkSVGFeLighting_render(SkSVGFeLighting *svgFeLighting, const SkSVGRenderContext *svgRenderContext) {
    svgFeLighting->render(*svgRenderContext);
}

bool SkSVGFeLighting_asPaint(SkSVGFeLighting *svgFeLighting, const SkSVGRenderContext *svgRenderContext, SkPaint *paint) {
    return svgFeLighting->asPaint(*svgRenderContext, paint);
}

sk_path_t SkSVGFeLighting_asPath(SkSVGFeLighting *svgFeLighting, const SkSVGRenderContext *svgRenderContext) {
    return static_sk_path_make(svgFeLighting->asPath(*svgRenderContext));
}

sk_rect_t SkSVGFeLighting_objectBoundingBox(SkSVGFeLighting *svgFeLighting, const SkSVGRenderContext *svgRenderContext) {
    return static_sk_rect_make(svgFeLighting->objectBoundingBox(*svgRenderContext));
}

void SkSVGFeLighting_setAttribute(SkSVGFeLighting *svgFeLighting, SkSVGAttribute svgAttribute, const SkSVGValue *svgValue) {
    svgFeLighting->setAttribute(svgAttribute, *svgValue);
}

// bool SkSVGFeLighting_setAttribute(SkSVGFeLighting *svgFeLighting, const char *attributeName, const char *attributeValue) {
//     svgFeLighting->
// }

bool SkSVGFeLighting_unique(SkSVGFeLighting *svgFeLighting) {
    return svgFeLighting->unique();
}

void SkSVGFeLighting_ref(SkSVGFeLighting *svgFeLighting) {
    svgFeLighting->ref();
}

void SkSVGFeLighting_unref(SkSVGFeLighting *svgFeLighting) {
    svgFeLighting->unref();
}

// static

bool SkSVGFeLighting_IsFilterEffect (const sk_sp< SkSVGNode > *node) {
    return SkSVGFeLighting::IsFilterEffect(*node);
}

}