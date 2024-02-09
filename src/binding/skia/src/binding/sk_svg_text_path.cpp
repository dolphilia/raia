//
// Created by dolphilia on 2024/02/06.
//

#include "sk_svg_text_path.h"

extern "C" {

void SkSVGTextPath_delete(SkSVGTextPath *svgTextPath) {
    delete svgTextPath;
}

void SkSVGTextPath_appendChild(SkSVGTextPath *svgTextPath, sk_svg_node_t svg_node) {
    svgTextPath->appendChild(static_sk_svg_node_move(svg_node));
}

void SkSVGTextPath_renderText(SkSVGTextPath *svgTextPath, const SkSVGRenderContext &svgRenderContext, SkSVGTextContext *svgTextContext, SkSVGXmlSpace svgXmlSpace) {
    return svgTextPath->renderText(svgRenderContext, svgTextContext, svgXmlSpace);
}

void SkSVGTextPath_setTransform(SkSVGTextPath *svgTextPath, const SkSVGTransformType *t) {
    svgTextPath->setTransform(*t);
}

SkSVGTag SkSVGTextPath_tag(SkSVGTextPath *svgTextPath) {
    return svgTextPath->tag();
}

void SkSVGTextPath_render(SkSVGTextPath *svgTextPath, const SkSVGRenderContext *svgRenderContext) {
    svgTextPath->render(*svgRenderContext);
}

bool SkSVGTextPath_asPaint(SkSVGTextPath *svgTextPath, const SkSVGRenderContext *svgRenderContext, SkPaint *paint) {
    return svgTextPath->asPaint(*svgRenderContext, paint);
}

sk_path_t SkSVGTextPath_asPath(SkSVGTextPath *svgTextPath, const SkSVGRenderContext *svgRenderContext) {
    return static_sk_path_make(svgTextPath->asPath(*svgRenderContext));
}

sk_rect_t SkSVGTextPath_objectBoundingBox(SkSVGTextPath *svgTextPath, const SkSVGRenderContext *svgRenderContext) {
    return static_sk_rect_make(svgTextPath->objectBoundingBox(*svgRenderContext));
}

void SkSVGTextPath_setAttribute(SkSVGTextPath *svgTextPath, SkSVGAttribute svgAttribute, const SkSVGValue *svgValue) {
    svgTextPath->setAttribute(svgAttribute, *svgValue);
}

// bool SkSVGTextPath_setAttribute(SkSVGTextPath *svgTextPath, const char *attributeName, const char *attributeValue) {
//     svgTextPath->
// }

bool SkSVGTextPath_unique(SkSVGTextPath *svgTextPath) {
    return svgTextPath->unique();
}

void SkSVGTextPath_ref(SkSVGTextPath *svgTextPath) {
    svgTextPath->ref();
}

void SkSVGTextPath_unref(SkSVGTextPath *svgTextPath) {
    svgTextPath->unref();
}

// static

sk_svg_text_path_t SkSVGTextPath_Make() {
    return static_sk_svg_text_path_make(SkSVGTextPath::Make());
}

}