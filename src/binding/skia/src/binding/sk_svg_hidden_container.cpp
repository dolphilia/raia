//
// Created by dolphilia on 2024/02/06.
//

#include "sk_svg_hidden_container.h"

extern "C" {

void SkSVGHiddenContainer_delete(SkSVGHiddenContainer *svgHiddenContainer) {
    delete svgHiddenContainer;
}

void SkSVGHiddenContainer_appendChild(SkSVGHiddenContainer *svgHiddenContainer, sk_svg_node_t svg_node) {
    svgHiddenContainer->appendChild(static_sk_svg_node_move(svg_node));
}

void SkSVGHiddenContainer_setTransform(SkSVGHiddenContainer *svgHiddenContainer, const SkSVGTransformType *t) {
    svgHiddenContainer->setTransform(*t);
}

SkSVGTag SkSVGHiddenContainer_tag(SkSVGHiddenContainer *svgHiddenContainer) {
    return svgHiddenContainer->tag();
}

void SkSVGHiddenContainer_render(SkSVGHiddenContainer *svgHiddenContainer, const SkSVGRenderContext *svgRenderContext) {
    svgHiddenContainer->render(*svgRenderContext);
}

bool SkSVGHiddenContainer_asPaint(SkSVGHiddenContainer *svgHiddenContainer, const SkSVGRenderContext *svgRenderContext, SkPaint *paint) {
    return svgHiddenContainer->asPaint(*svgRenderContext, paint);
}

sk_path_t SkSVGHiddenContainer_asPath(SkSVGHiddenContainer *svgHiddenContainer, const SkSVGRenderContext *svgRenderContext) {
    return static_sk_path_make(svgHiddenContainer->asPath(*svgRenderContext));
}

sk_rect_t SkSVGHiddenContainer_objectBoundingBox(SkSVGHiddenContainer *svgHiddenContainer, const SkSVGRenderContext *svgRenderContext) {
    return static_sk_rect_make(svgHiddenContainer->objectBoundingBox(*svgRenderContext));
}

void SkSVGHiddenContainer_setAttribute(SkSVGHiddenContainer *svgHiddenContainer, SkSVGAttribute svgAttribute, const SkSVGValue *svgValue) {
    svgHiddenContainer->setAttribute(svgAttribute, *svgValue);
}

// bool SkSVGHiddenContainer_setAttribute(SkSVGHiddenContainer *svgHiddenContainer, const char *attributeName, const char *attributeValue) {
//     svgHiddenContainer->
// }

bool SkSVGHiddenContainer_parseAndSetAttribute(SkSVGHiddenContainer *svgHiddenContainer, const char *name, const char *value) {
    return svgHiddenContainer->parseAndSetAttribute(name, value);
}

bool SkSVGHiddenContainer_unique(SkSVGHiddenContainer *svgHiddenContainer) {
    return svgHiddenContainer->unique();
}

void SkSVGHiddenContainer_ref(SkSVGHiddenContainer *svgHiddenContainer) {
    svgHiddenContainer->ref();
}

void SkSVGHiddenContainer_unref(SkSVGHiddenContainer *svgHiddenContainer) {
    svgHiddenContainer->unref();
}

}