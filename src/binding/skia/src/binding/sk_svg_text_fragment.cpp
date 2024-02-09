//
// Created by dolphilia on 2024/02/06.
//

#include "sk_svg_text_fragment.h"

extern "C" {

void SkSVGTextFragment_delete(SkSVGTextFragment *svgTextFragment) {
    delete svgTextFragment;
}

void SkSVGTextFragment_renderText(SkSVGTextFragment *svgTextFragment, const SkSVGRenderContext &svgRenderContext, SkSVGTextContext *svgTextContext, SkSVGXmlSpace svgXmlSpace) {
    return svgTextFragment->renderText(svgRenderContext, svgTextContext, svgXmlSpace);
}

void SkSVGTextFragment_setTransform(SkSVGTextFragment *svgTextFragment, const SkSVGTransformType *t) {
    svgTextFragment->setTransform(*t);
}

SkSVGTag SkSVGTextFragment_tag(SkSVGTextFragment *svgTextFragment) {
    return svgTextFragment->tag();
}

void SkSVGTextFragment_appendChild(SkSVGTextFragment *svgTextFragment, sk_svg_node_t svg_node) {
    svgTextFragment->appendChild(static_sk_svg_node_move(svg_node));
}

void SkSVGTextFragment_render(SkSVGTextFragment *svgTextFragment, const SkSVGRenderContext *svgRenderContext) {
    svgTextFragment->render(*svgRenderContext);
}

bool SkSVGTextFragment_asPaint(SkSVGTextFragment *svgTextFragment, const SkSVGRenderContext *svgRenderContext, SkPaint *paint) {
    return svgTextFragment->asPaint(*svgRenderContext, paint);
}

sk_path_t SkSVGTextFragment_asPath(SkSVGTextFragment *svgTextFragment, const SkSVGRenderContext *svgRenderContext) {
    return static_sk_path_make(svgTextFragment->asPath(*svgRenderContext));
}

sk_rect_t SkSVGTextFragment_objectBoundingBox(SkSVGTextFragment *svgTextFragment, const SkSVGRenderContext *svgRenderContext) {
    return static_sk_rect_make(svgTextFragment->objectBoundingBox(*svgRenderContext));
}

void SkSVGTextFragment_setAttribute(SkSVGTextFragment *svgTextFragment, SkSVGAttribute svgAttribute, const SkSVGValue *svgValue) {
    svgTextFragment->setAttribute(svgAttribute, *svgValue);
}

// bool SkSVGTextFragment_setAttribute(SkSVGTextFragment *svgTextFragment, const char *attributeName, const char *attributeValue) {
//     svgTextFragment->
// }

bool SkSVGTextFragment_parseAndSetAttribute(SkSVGTextFragment *svgTextFragment, const char *name, const char *value) {
    return svgTextFragment->parseAndSetAttribute(name, value);
}

bool SkSVGTextFragment_unique(SkSVGTextFragment *svgTextFragment) {
    return svgTextFragment->unique();
}

void SkSVGTextFragment_ref(SkSVGTextFragment *svgTextFragment) {
    svgTextFragment->ref();
}

void SkSVGTextFragment_unref(SkSVGTextFragment *svgTextFragment) {
    svgTextFragment->unref();
}

}