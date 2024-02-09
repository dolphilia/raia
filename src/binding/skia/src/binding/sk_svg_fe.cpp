//
// Created by dolphilia on 2024/02/06.
//

#include "sk_svg_fe.h"

extern "C" {

void SkSVGFe_delete(SkSVGFe *svgFe) {
    delete svgFe;
}

sk_image_filter_t SkSVGFe_makeImageFilter (SkSVGFe *svgFe, const SkSVGRenderContext *ctx, const SkSVGFilterContext *fctx) {
    return static_sk_image_filter_make(svgFe->makeImageFilter(*ctx, *fctx));
}

sk_rect_t SkSVGFe_resolveFilterSubregion (SkSVGFe *svgFe, const SkSVGRenderContext *svgRenderContext, const SkSVGFilterContext *svgFilterContext) {
    return static_sk_rect_make(svgFe->resolveFilterSubregion(*svgRenderContext, *svgFilterContext));
}

SkSVGColorspace SkSVGFe_resolveColorspace (SkSVGFe *svgFe, const SkSVGRenderContext *svgRenderContext, const SkSVGFilterContext *svgFilterContext) {
    return svgFe->resolveColorspace(*svgRenderContext, *svgFilterContext);
}

void SkSVGFe_applyProperties (SkSVGFe *svgFe, SkSVGRenderContext *svgRenderContext) {
    svgFe->applyProperties(svgRenderContext);
}

void SkSVGFe_appendChild(SkSVGFe *svgFe, sk_svg_node_t svg_node) {
    svgFe->appendChild(static_sk_svg_node_move(svg_node));
}

void SkSVGFe_setTransform (SkSVGFe *svgFe, const SkSVGTransformType *t) {
    svgFe->setTransform(*t);
}

SkSVGTag SkSVGFe_tag (SkSVGFe *svgFe) {
    return svgFe->tag();
}

void SkSVGFe_render (SkSVGFe *svgFe, const SkSVGRenderContext *svgRenderContext) {
    svgFe->render(*svgRenderContext);
}

bool SkSVGFe_asPaint (SkSVGFe *svgFe, const SkSVGRenderContext *svgRenderContext, SkPaint *paint) {
    return svgFe->asPaint(*svgRenderContext, paint);
}

sk_path_t SkSVGFe_asPath (SkSVGFe *svgFe, const SkSVGRenderContext *svgRenderContext) {
    return static_sk_path_make(svgFe->asPath(*svgRenderContext));
}

sk_rect_t SkSVGFe_objectBoundingBox (SkSVGFe *svgFe, const SkSVGRenderContext *svgRenderContext) {
    return static_sk_rect_make(svgFe->objectBoundingBox(*svgRenderContext));
}

void SkSVGFe_setAttribute (SkSVGFe *svgFe, SkSVGAttribute svgAttribute, const SkSVGValue *svgValue) {
    svgFe->setAttribute(svgAttribute, *svgValue);
}

//bool SkSVGFe_setAttribute (SkSVGFe *svgFe, const char *attributeName, const char *attributeValue) {
//    return svgFe->setAttribute(attributeName, attributeValue);
//}

bool SkSVGFe_unique (SkSVGFe *svgFe) {
    return svgFe->unique();
}

void SkSVGFe_ref (SkSVGFe *svgFe) {
    svgFe->ref();
}

void SkSVGFe_unref (SkSVGFe *svgFe) {
    svgFe->unref();
}

// static

bool SkSVGFe_IsFilterEffect (const sk_sp<SkSVGNode> *node) {
    return SkSVGFe::IsFilterEffect(*node);
}

}