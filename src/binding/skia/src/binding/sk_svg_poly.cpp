//
// Created by dolphilia on 2024/02/06.
//

#include "sk_svg_poly.h"

extern "C" {

void SkSVGPoly_delete(SkSVGPoly *svgPoly) {
    delete svgPoly;
}

void SkSVGPoly_appendChild(SkSVGPoly *svgPoly, sk_svg_node_t svg_node) {
    svgPoly->appendChild(static_sk_svg_node_move(svg_node));
}

void SkSVGPoly_setTransform(SkSVGPoly *svgPoly, const SkSVGTransformType *t) {
    svgPoly->setTransform(*t);
}

SkSVGTag SkSVGPoly_tag(SkSVGPoly *svgPoly) {
    return svgPoly->tag();
}

void SkSVGPoly_render(SkSVGPoly *svgPoly, const SkSVGRenderContext *svgRenderContext) {
    svgPoly->render(*svgRenderContext);
}

bool SkSVGPoly_asPaint(SkSVGPoly *svgPoly, const SkSVGRenderContext *svgRenderContext, SkPaint *paint) {
    return svgPoly->asPaint(*svgRenderContext, paint);
}

sk_path_t SkSVGPoly_asPath(SkSVGPoly *svgPoly, const SkSVGRenderContext *svgRenderContext) {
    return static_sk_path_make(svgPoly->asPath(*svgRenderContext));
}

sk_rect_t SkSVGPoly_objectBoundingBox(SkSVGPoly *svgPoly, const SkSVGRenderContext *svgRenderContext) {
    return static_sk_rect_make(svgPoly->objectBoundingBox(*svgRenderContext));
}

void SkSVGPoly_setAttribute(SkSVGPoly *svgPoly, SkSVGAttribute svgAttribute, const SkSVGValue *svgValue) {
    svgPoly->setAttribute(svgAttribute, *svgValue);
}

// bool SkSVGPoly_setAttribute(SkSVGPoly *svgPoly, const char *attributeName, const char *attributeValue) {
//     svgPoly->
// }

bool SkSVGPoly_unique(SkSVGPoly *svgPoly) {
    return svgPoly->unique();
}

void SkSVGPoly_ref(SkSVGPoly *svgPoly) {
    svgPoly->ref();
}

void SkSVGPoly_unref(SkSVGPoly *svgPoly) {
    svgPoly->unref();
}

// static

sk_svg_poly_t SkSVGPoly_MakePolygon () {
    return static_sk_svg_poly_make(SkSVGPoly::MakePolygon());
}

sk_svg_poly_t SkSVGPoly_MakePolyline () {
    return static_sk_svg_poly_make(SkSVGPoly::MakePolyline());
}

}