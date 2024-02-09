//
// Created by dolphilia on 2024/02/06.
//

#include "sk_svg_path.h"

extern "C" {

void SkSVGPath_delete(SkSVGPath *svgPath) {
    delete svgPath;
}

void SkSVGPath_appendChild(SkSVGPath *svgPath, sk_svg_node_t svg_node) {
    svgPath->appendChild(static_sk_svg_node_move(svg_node));
}

void SkSVGPath_setTransform(SkSVGPath *svgPath, const SkSVGTransformType *t) {
    svgPath->setTransform(*t);
}

SkSVGTag SkSVGPath_tag(SkSVGPath *svgPath) {
    return svgPath->tag();
}

void SkSVGPath_render(SkSVGPath *svgPath, const SkSVGRenderContext *svgRenderContext) {
    svgPath->render(*svgRenderContext);
}

bool SkSVGPath_asPaint(SkSVGPath *svgPath, const SkSVGRenderContext *svgRenderContext, SkPaint *paint) {
    return svgPath->asPaint(*svgRenderContext, paint);
}

sk_path_t SkSVGPath_asPath(SkSVGPath *svgPath, const SkSVGRenderContext *svgRenderContext) {
    return static_sk_path_make(svgPath->asPath(*svgRenderContext));
}

sk_rect_t SkSVGPath_objectBoundingBox(SkSVGPath *svgPath, const SkSVGRenderContext *svgRenderContext) {
    return static_sk_rect_make(svgPath->objectBoundingBox(*svgRenderContext));
}

void SkSVGPath_setAttribute(SkSVGPath *svgPath, SkSVGAttribute svgAttribute, const SkSVGValue *svgValue) {
    svgPath->setAttribute(svgAttribute, *svgValue);
}

// bool SkSVGPath_setAttribute(SkSVGPath *svgPath, const char *attributeName, const char *attributeValue) {
//     svgPath->
// }

bool SkSVGPath_unique(SkSVGPath *svgPath) {
    return svgPath->unique();
}

void SkSVGPath_ref(SkSVGPath *svgPath) {
    svgPath->ref();
}

void SkSVGPath_unref(SkSVGPath *svgPath) {
    svgPath->unref();
}

// static

sk_svg_path_t SkSVGPath_Make() {
    return static_sk_svg_path_make(SkSVGPath::Make());
}

}