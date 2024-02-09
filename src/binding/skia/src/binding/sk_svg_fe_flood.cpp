//
// Created by dolphilia on 2024/02/06.
//

#include "sk_svg_fe_flood.h"

extern "C" {

void SkSVGFeFlood_delete(SkSVGFeFlood *svgFeFlood) {
    delete svgFeFlood;
}

sk_image_filter_t SkSVGFeFlood_makeImageFilter(SkSVGFeFlood *svgFeFlood, const SkSVGRenderContext *ctx, const SkSVGFilterContext *fctx) {
    return static_sk_image_filter_make(svgFeFlood->makeImageFilter(*ctx, *fctx));
}

sk_rect_t SkSVGFeFlood_resolveFilterSubregion(SkSVGFeFlood *svgFeFlood, const SkSVGRenderContext *svgRenderContext, const SkSVGFilterContext *svgFilterContext) {
    return static_sk_rect_make(svgFeFlood->resolveFilterSubregion(*svgRenderContext, *svgFilterContext));
}

SkSVGColorspace SkSVGFeFlood_resolveColorspace(SkSVGFeFlood *svgFeFlood, const SkSVGRenderContext *svgRenderContext, const SkSVGFilterContext *svgFilterContext) {
    return svgFeFlood->resolveColorspace(*svgRenderContext, *svgFilterContext);
}

void SkSVGFeFlood_applyProperties(SkSVGFeFlood *svgFeFlood, SkSVGRenderContext *svgRenderContext) {
    svgFeFlood->applyProperties(svgRenderContext);
}

void SkSVGFeFlood_appendChild(SkSVGFeFlood *svgFeFlood, sk_svg_node_t svg_node) {
    svgFeFlood->appendChild(static_sk_svg_node_move(svg_node));
}

void SkSVGFeFlood_setTransform(SkSVGFeFlood *svgFeFlood, const SkSVGTransformType *t) {
    svgFeFlood->setTransform(*t);
}

SkSVGTag SkSVGFeFlood_tag(SkSVGFeFlood *svgFeFlood) {
    return svgFeFlood->tag();
}

void SkSVGFeFlood_render(SkSVGFeFlood *svgFeFlood, const SkSVGRenderContext *svgRenderContext) {
    svgFeFlood->render(*svgRenderContext);
}

bool SkSVGFeFlood_asPaint(SkSVGFeFlood *svgFeFlood, const SkSVGRenderContext *svgRenderContext, SkPaint *paint) {
    return svgFeFlood->asPaint(*svgRenderContext, paint);
}

sk_path_t SkSVGFeFlood_asPath(SkSVGFeFlood *svgFeFlood, const SkSVGRenderContext *svgRenderContext) {
    return static_sk_path_make(svgFeFlood->asPath(*svgRenderContext));
}

sk_rect_t SkSVGFeFlood_objectBoundingBox(SkSVGFeFlood *svgFeFlood, const SkSVGRenderContext *svgRenderContext) {
    return static_sk_rect_make(svgFeFlood->objectBoundingBox(*svgRenderContext));
}

void SkSVGFeFlood_setAttribute(SkSVGFeFlood *svgFeFlood, SkSVGAttribute svgAttribute, const SkSVGValue *svgValue) {
    svgFeFlood->setAttribute(svgAttribute, *svgValue);
}

// bool SkSVGFeFlood_setAttribute(SkSVGFeFlood *svgFeFlood, const char *attributeName, const char *attributeValue) {
//     svgFeFlood->
// }

bool SkSVGFeFlood_unique(SkSVGFeFlood *svgFeFlood) {
    return svgFeFlood->unique();
}

void SkSVGFeFlood_ref(SkSVGFeFlood *svgFeFlood) {
    svgFeFlood->ref();
}

void SkSVGFeFlood_unref(SkSVGFeFlood *svgFeFlood) {
    svgFeFlood->unref();
}

// static

sk_svg_fe_flood_t SkSVGFeFlood_Make() {
    return static_sk_svg_fe_flood_make(SkSVGFeFlood::Make());
}

bool SkSVGFeFlood_IsFilterEffect (const sk_sp< SkSVGNode > *node) {
    return SkSVGFeFlood::IsFilterEffect(*node);
}

}