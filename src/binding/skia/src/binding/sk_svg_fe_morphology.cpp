//
// Created by dolphilia on 2024/02/06.
//

#include "sk_svg_fe_morphology.h"

extern "C" {

void SkSVGFeMorphology_delete(SkSVGFeMorphology *svgFeMorphology) {
    delete svgFeMorphology;
}

sk_image_filter_t SkSVGFeMorphology_makeImageFilter(SkSVGFeMorphology *svgFeMorphology, const SkSVGRenderContext *ctx, const SkSVGFilterContext *fctx) {
    return static_sk_image_filter_make(svgFeMorphology->makeImageFilter(*ctx, *fctx));
}

sk_rect_t SkSVGFeMorphology_resolveFilterSubregion(SkSVGFeMorphology *svgFeMorphology, const SkSVGRenderContext *svgRenderContext, const SkSVGFilterContext *svgFilterContext) {
    return static_sk_rect_make(svgFeMorphology->resolveFilterSubregion(*svgRenderContext, *svgFilterContext));
}

SkSVGColorspace SkSVGFeMorphology_resolveColorspace(SkSVGFeMorphology *svgFeMorphology, const SkSVGRenderContext *svgRenderContext, const SkSVGFilterContext *svgFilterContext) {
    return svgFeMorphology->resolveColorspace(*svgRenderContext, *svgFilterContext);
}

void SkSVGFeMorphology_applyProperties(SkSVGFeMorphology *svgFeMorphology, SkSVGRenderContext *svgRenderContext) {
    svgFeMorphology->applyProperties(svgRenderContext);
}

void SkSVGFeMorphology_appendChild(SkSVGFeMorphology *svgFeMorphology, sk_svg_node_t svg_node) {
    svgFeMorphology->appendChild(static_sk_svg_node_move(svg_node));
}

void SkSVGFeMorphology_setTransform(SkSVGFeMorphology *svgFeMorphology, const SkSVGTransformType *t) {
    svgFeMorphology->setTransform(*t);
}

SkSVGTag SkSVGFeMorphology_tag(SkSVGFeMorphology *svgFeMorphology) {
    return svgFeMorphology->tag();
}

void SkSVGFeMorphology_render(SkSVGFeMorphology *svgFeMorphology, const SkSVGRenderContext *svgRenderContext) {
    svgFeMorphology->render(*svgRenderContext);
}

bool SkSVGFeMorphology_asPaint(SkSVGFeMorphology *svgFeMorphology, const SkSVGRenderContext *svgRenderContext, SkPaint *paint) {
    return svgFeMorphology->asPaint(*svgRenderContext, paint);
}

sk_path_t SkSVGFeMorphology_asPath(SkSVGFeMorphology *svgFeMorphology, const SkSVGRenderContext *svgRenderContext) {
    return static_sk_path_make(svgFeMorphology->asPath(*svgRenderContext));
}

sk_rect_t SkSVGFeMorphology_objectBoundingBox(SkSVGFeMorphology *svgFeMorphology, const SkSVGRenderContext *svgRenderContext) {
    return static_sk_rect_make(svgFeMorphology->objectBoundingBox(*svgRenderContext));
}

void SkSVGFeMorphology_setAttribute(SkSVGFeMorphology *svgFeMorphology, SkSVGAttribute svgAttribute, const SkSVGValue *svgValue) {
    svgFeMorphology->setAttribute(svgAttribute, *svgValue);
}

// bool SkSVGFeMorphology_setAttribute(SkSVGFeMorphology *svgFeMorphology, const char *attributeName, const char *attributeValue) {
//     svgFeMorphology->
// }

bool SkSVGFeMorphology_unique(SkSVGFeMorphology *svgFeMorphology) {
    return svgFeMorphology->unique();
}

void SkSVGFeMorphology_ref(SkSVGFeMorphology *svgFeMorphology) {
    svgFeMorphology->ref();
}

void SkSVGFeMorphology_unref(SkSVGFeMorphology *svgFeMorphology) {
    svgFeMorphology->unref();
}

// static

sk_svg_fe_morphology_t SkSVGFeMorphology_Make() {
    return static_sk_svg_fe_morphology_make(SkSVGFeMorphology::Make());
}

bool SkSVGFeMorphology_IsFilterEffect (const sk_sp< SkSVGNode > *node) {
    return SkSVGFeMorphology::IsFilterEffect(*node);
}

}