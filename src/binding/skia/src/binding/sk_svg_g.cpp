//
// Created by dolphilia on 2024/02/06.
//

#include "sk_svg_g.h"

extern "C" {

void SkSVGG_delete(SkSVGG *svgg) {
    delete svgg;
}

void SkSVGG_appendChild(SkSVGG *svgg, sk_svg_node_t svg_node) {
    svgg->appendChild(static_sk_svg_node_move(svg_node));
}

void SkSVGG_setTransform(SkSVGG *svgg, const SkSVGTransformType *t) {
    svgg->setTransform(*t);
}

SkSVGTag SkSVGG_tag(SkSVGG *svgg) {
    return svgg->tag();
}

void SkSVGG_render(SkSVGG *svgg, const SkSVGRenderContext *svgRenderContext) {
    svgg->render(*svgRenderContext);
}

bool SkSVGG_asPaint(SkSVGG *svgg, const SkSVGRenderContext *svgRenderContext, SkPaint *paint) {
    return svgg->asPaint(*svgRenderContext, paint);
}

sk_path_t SkSVGG_asPath(SkSVGG *svgg, const SkSVGRenderContext *svgRenderContext) {
    return static_sk_path_make(svgg->asPath(*svgRenderContext));
}

sk_rect_t SkSVGG_objectBoundingBox(SkSVGG *svgg, const SkSVGRenderContext *svgRenderContext) {
    return static_sk_rect_make(svgg->objectBoundingBox(*svgRenderContext));
}

void SkSVGG_setAttribute(SkSVGG *svgg, SkSVGAttribute svgAttribute, const SkSVGValue *svgValue) {
    svgg->setAttribute(svgAttribute, *svgValue);
}

// bool SkSVGG_setAttribute(SkSVGG *svgg, const char *attributeName, const char *attributeValue) {
//     svgg->
// }

bool SkSVGG_parseAndSetAttribute(SkSVGG *svgg, const char *name, const char *value) {
    return svgg->parseAndSetAttribute(name, value);
}

bool SkSVGG_unique(SkSVGG *svgg) {
    return svgg->unique();
}

void SkSVGG_ref(SkSVGG *svgg) {
    svgg->ref();
}

void SkSVGG_unref(SkSVGG *svgg) {
    svgg->unref();
}

// static

//int SkSVGG_Make() {
//    return static_sk_svg_g_make(SkSVGG::Make());
//}

}