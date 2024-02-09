//
// Created by dolphilia on 2024/02/06.
//

#include "sk_svg_text_container.h"

extern "C" {

void SkSVGTextContainer_delete(SkSVGTextContainer *svgTextContainer) {
    delete svgTextContainer;
}

void SkSVGTextContainer_appendChild(SkSVGTextContainer *svgTextContainer, sk_svg_node_t svg_node) {
    svgTextContainer->appendChild(static_sk_svg_node_move(svg_node));
}

void SkSVGTextContainer_renderText(SkSVGTextContainer *svgTextContainer, const SkSVGRenderContext &svgRenderContext, SkSVGTextContext *svgTextContext, SkSVGXmlSpace svgXmlSpace) {
    return svgTextContainer->renderText(svgRenderContext, svgTextContext, svgXmlSpace);
}

void SkSVGTextContainer_setTransform(SkSVGTextContainer *svgTextContainer, const SkSVGTransformType *t) {
    svgTextContainer->setTransform(*t);
}

SkSVGTag SkSVGTextContainer_tag(SkSVGTextContainer *svgTextContainer) {
    return svgTextContainer->tag();
}

void SkSVGTextContainer_render(SkSVGTextContainer *svgTextContainer, const SkSVGRenderContext *svgRenderContext) {
    svgTextContainer->render(*svgRenderContext);
}

bool SkSVGTextContainer_asPaint(SkSVGTextContainer *svgTextContainer, const SkSVGRenderContext *svgRenderContext, SkPaint *paint) {
    return svgTextContainer->asPaint(*svgRenderContext, paint);
}

sk_path_t SkSVGTextContainer_asPath(SkSVGTextContainer *svgTextContainer, const SkSVGRenderContext *svgRenderContext) {
    return static_sk_path_make(svgTextContainer->asPath(*svgRenderContext));
}

sk_rect_t SkSVGTextContainer_objectBoundingBox(SkSVGTextContainer *svgTextContainer, const SkSVGRenderContext *svgRenderContext) {
    return static_sk_rect_make(svgTextContainer->objectBoundingBox(*svgRenderContext));
}

void SkSVGTextContainer_setAttribute(SkSVGTextContainer *svgTextContainer, SkSVGAttribute svgAttribute, const SkSVGValue *svgValue) {
    svgTextContainer->setAttribute(svgAttribute, *svgValue);
}

// bool SkSVGTextContainer_setAttribute(SkSVGTextContainer *svgTextContainer, const char *attributeName, const char *attributeValue) {
//     svgTextContainer->
// }

bool SkSVGTextContainer_unique(SkSVGTextContainer *svgTextContainer) {
    return svgTextContainer->unique();
}

void SkSVGTextContainer_ref(SkSVGTextContainer *svgTextContainer) {
    svgTextContainer->ref();
}

void SkSVGTextContainer_unref(SkSVGTextContainer *svgTextContainer) {
    svgTextContainer->unref();
}

}