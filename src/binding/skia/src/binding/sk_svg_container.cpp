//
// Created by dolphilia on 2024/02/04.
//

#include "sk_svg_container.h"

extern "C" {

void SkSVGContainer_delete(SkSVGContainer *svgContainer) {
    delete svgContainer;
}

void SkSVGContainer_appendChild(SkSVGContainer *svgContainer, sk_svg_node_t svg_node) {
    svgContainer->appendChild(static_sk_svg_node_move(svg_node));
}

void SkSVGContainer_setTransform(SkSVGContainer *svgContainer, const SkSVGTransformType &t) {
    svgContainer->setTransform(t);
}

SkSVGTag SkSVGContainer_tag(SkSVGContainer *svgContainer) {
    return svgContainer->tag();
}

void SkSVGContainer_render(SkSVGContainer *svgContainer, const SkSVGRenderContext &svgRenderContext) {
    svgContainer->render(svgRenderContext);
}

bool SkSVGContainer_asPaint(SkSVGContainer *svgContainer, const SkSVGRenderContext &svgRenderContext, SkPaint *paint) {
    return svgContainer->asPaint(svgRenderContext, paint);
}

sk_path_t SkSVGContainer_asPath(SkSVGContainer *svgContainer, const SkSVGRenderContext &svgRenderContext) {
    return static_sk_path_make(svgContainer->asPath(svgRenderContext));
}

sk_rect_t SkSVGContainer_objectBoundingBox(SkSVGContainer *svgContainer, const SkSVGRenderContext &svgRenderContext) {
    return static_sk_rect_make(svgContainer->objectBoundingBox(svgRenderContext));
}

void SkSVGContainer_setAttribute(SkSVGContainer *svgContainer, SkSVGAttribute svgAttribute, const SkSVGValue &svgValue) {
    svgContainer->setAttribute(svgAttribute, svgValue);
}

//bool SkSVGContainer_setAttribute_2(SkSVGContainer* svgContainer, const char *attributeName, const char *attributeValue) {
//    return svgContainer->setAttribute(attributeName, attributeValue);
//}

bool SkSVGContainer_parseAndSetAttribute(SkSVGContainer *svgContainer, const char *name, const char *value) {
    return svgContainer->parseAndSetAttribute(name, value);
}

bool SkSVGContainer_unique(SkSVGContainer *svgContainer) {
    return svgContainer->unique();
}

void SkSVGContainer_ref(SkSVGContainer *svgContainer) {
    svgContainer->ref();
}

void SkSVGContainer_unref(SkSVGContainer *svgContainer) {
    svgContainer->unref();
}

}