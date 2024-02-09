//
// Created by dolphilia on 2024/02/06.
//

#include "sk_svg_fe_turbulence.h"

extern "C" {

void SkSVGFeTurbulence_delete(SkSVGFeTurbulence *svgFeTurbulence) {
    delete svgFeTurbulence;
}

sk_image_filter_t SkSVGFeTurbulence_makeImageFilter(SkSVGFeTurbulence *svgFeTurbulence, const SkSVGRenderContext *ctx, const SkSVGFilterContext *fctx) {
    return static_sk_image_filter_make(svgFeTurbulence->makeImageFilter(*ctx, *fctx));
}

sk_rect_t SkSVGFeTurbulence_resolveFilterSubregion(SkSVGFeTurbulence *svgFeTurbulence, const SkSVGRenderContext *svgRenderContext, const SkSVGFilterContext *svgFilterContext) {
    return static_sk_rect_make(svgFeTurbulence->resolveFilterSubregion(*svgRenderContext, *svgFilterContext));
}

SkSVGColorspace SkSVGFeTurbulence_resolveColorspace(SkSVGFeTurbulence *svgFeTurbulence, const SkSVGRenderContext *svgRenderContext, const SkSVGFilterContext *svgFilterContext) {
    return svgFeTurbulence->resolveColorspace(*svgRenderContext, *svgFilterContext);
}

void SkSVGFeTurbulence_applyProperties(SkSVGFeTurbulence *svgFeTurbulence, SkSVGRenderContext *svgRenderContext) {
    svgFeTurbulence->applyProperties(svgRenderContext);
}

void SkSVGFeTurbulence_appendChild(SkSVGFeTurbulence *svgFeTurbulence, sk_svg_node_t svg_node) {
    svgFeTurbulence->appendChild(static_sk_svg_node_move(svg_node));
}

void SkSVGFeTurbulence_setTransform(SkSVGFeTurbulence *svgFeTurbulence, const SkSVGTransformType *t) {
    svgFeTurbulence->setTransform(*t);
}

SkSVGTag SkSVGFeTurbulence_tag(SkSVGFeTurbulence *svgFeTurbulence) {
    return svgFeTurbulence->tag();
}

void SkSVGFeTurbulence_render(SkSVGFeTurbulence *svgFeTurbulence, const SkSVGRenderContext *svgRenderContext) {
    svgFeTurbulence->render(*svgRenderContext);
}

bool SkSVGFeTurbulence_asPaint(SkSVGFeTurbulence *svgFeTurbulence, const SkSVGRenderContext *svgRenderContext, SkPaint *paint) {
    return svgFeTurbulence->asPaint(*svgRenderContext, paint);
}

sk_path_t SkSVGFeTurbulence_asPath(SkSVGFeTurbulence *svgFeTurbulence, const SkSVGRenderContext *svgRenderContext) {
    return static_sk_path_make(svgFeTurbulence->asPath(*svgRenderContext));
}

sk_rect_t SkSVGFeTurbulence_objectBoundingBox(SkSVGFeTurbulence *svgFeTurbulence, const SkSVGRenderContext *svgRenderContext) {
    return static_sk_rect_make(svgFeTurbulence->objectBoundingBox(*svgRenderContext));
}

void SkSVGFeTurbulence_setAttribute(SkSVGFeTurbulence *svgFeTurbulence, SkSVGAttribute svgAttribute, const SkSVGValue *svgValue) {
    svgFeTurbulence->setAttribute(svgAttribute, *svgValue);
}

// bool SkSVGFeTurbulence_setAttribute(SkSVGFeTurbulence *svgFeTurbulence, const char *attributeName, const char *attributeValue) {
//     svgFeTurbulence->
// }

bool SkSVGFeTurbulence_unique(SkSVGFeTurbulence *svgFeTurbulence) {
    return svgFeTurbulence->unique();
}

void SkSVGFeTurbulence_ref(SkSVGFeTurbulence *svgFeTurbulence) {
    svgFeTurbulence->ref();
}

void SkSVGFeTurbulence_unref(SkSVGFeTurbulence *svgFeTurbulence) {
    svgFeTurbulence->unref();
}

// static

sk_svg_fe_turbulence_t SkSVGFeTurbulence_Make() {
    return static_sk_svg_fe_turbulence_make(SkSVGFeTurbulence::Make());
}

bool SkSVGFeTurbulence_IsFilterEffect (const sk_sp< SkSVGNode > *node) {
    return SkSVGFeTurbulence::IsFilterEffect(*node);
}

}