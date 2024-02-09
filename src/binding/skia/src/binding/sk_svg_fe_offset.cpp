//
// Created by dolphilia on 2024/02/06.
//

#include "sk_svg_fe_offset.h"

extern "C" {

void SkSVGFeOffset_delete(SkSVGFeOffset *svgFeOffset) {
    delete svgFeOffset;
}

sk_image_filter_t SkSVGFeOffset_makeImageFilter(SkSVGFeOffset *svgFeOffset, const SkSVGRenderContext *ctx, const SkSVGFilterContext *fctx) {
    return static_sk_image_filter_make(svgFeOffset->makeImageFilter(*ctx, *fctx));
}

sk_rect_t SkSVGFeOffset_resolveFilterSubregion(SkSVGFeOffset *svgFeOffset, const SkSVGRenderContext *svgRenderContext, const SkSVGFilterContext *svgFilterContext) {
    return static_sk_rect_make(svgFeOffset->resolveFilterSubregion(*svgRenderContext, *svgFilterContext));
}

SkSVGColorspace SkSVGFeOffset_resolveColorspace(SkSVGFeOffset *svgFeOffset, const SkSVGRenderContext *svgRenderContext, const SkSVGFilterContext *svgFilterContext) {
    return svgFeOffset->resolveColorspace(*svgRenderContext, *svgFilterContext);
}

void SkSVGFeOffset_applyProperties(SkSVGFeOffset *svgFeOffset, SkSVGRenderContext *svgRenderContext) {
    svgFeOffset->applyProperties(svgRenderContext);
}

void SkSVGFeOffset_appendChild(SkSVGFeOffset *svgFeOffset, sk_svg_node_t svg_node) {
    svgFeOffset->appendChild(static_sk_svg_node_move(svg_node));
}

void SkSVGFeOffset_setTransform(SkSVGFeOffset *svgFeOffset, const SkSVGTransformType *t) {
    svgFeOffset->setTransform(*t);
}

SkSVGTag SkSVGFeOffset_tag(SkSVGFeOffset *svgFeOffset) {
    return svgFeOffset->tag();
}

void SkSVGFeOffset_render(SkSVGFeOffset *svgFeOffset, const SkSVGRenderContext *svgRenderContext) {
    svgFeOffset->render(*svgRenderContext);
}

bool SkSVGFeOffset_asPaint(SkSVGFeOffset *svgFeOffset, const SkSVGRenderContext *svgRenderContext, SkPaint *paint) {
    return svgFeOffset->asPaint(*svgRenderContext, paint);
}

sk_path_t SkSVGFeOffset_asPath(SkSVGFeOffset *svgFeOffset, const SkSVGRenderContext *svgRenderContext) {
    return static_sk_path_make(svgFeOffset->asPath(*svgRenderContext));
}

sk_rect_t SkSVGFeOffset_objectBoundingBox(SkSVGFeOffset *svgFeOffset, const SkSVGRenderContext *svgRenderContext) {
    return static_sk_rect_make(svgFeOffset->objectBoundingBox(*svgRenderContext));
}

void SkSVGFeOffset_setAttribute(SkSVGFeOffset *svgFeOffset, SkSVGAttribute svgAttribute, const SkSVGValue *svgValue) {
    svgFeOffset->setAttribute(svgAttribute, *svgValue);
}

// bool SkSVGFeOffset_setAttribute(SkSVGFeOffset *svgFeOffset, const char *attributeName, const char *attributeValue) {
//     svgFeOffset->
// }

bool SkSVGFeOffset_unique(SkSVGFeOffset *svgFeOffset) {
    return svgFeOffset->unique();
}

void SkSVGFeOffset_ref(SkSVGFeOffset *svgFeOffset) {
    svgFeOffset->ref();
}

void SkSVGFeOffset_unref(SkSVGFeOffset *svgFeOffset) {
    svgFeOffset->unref();
}

// static

sk_svg_fe_offset_t SkSVGFeOffset_Make() {
    return static_sk_svg_fe_offset_make(SkSVGFeOffset::Make());
}

bool SkSVGFeOffset_IsFilterEffect (const sk_sp< SkSVGNode > *node) {
    return SkSVGFeOffset::IsFilterEffect(*node);
}

}