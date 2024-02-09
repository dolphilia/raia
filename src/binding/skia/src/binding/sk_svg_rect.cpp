//
// Created by dolphilia on 2024/02/06.
//

#include "sk_svg_rect.h"

extern "C" {

void SkSVGRect_delete(SkSVGRect *svgRect) {
    delete svgRect;
}

void SkSVGRect_appendChild(SkSVGRect *svgRect, sk_svg_node_t svg_node) {
    svgRect->appendChild(static_sk_svg_node_move(svg_node));
}

void SkSVGRect_setTransform(SkSVGRect *svgRect, const SkSVGTransformType *t) {
    svgRect->setTransform(*t);
}

SkSVGTag SkSVGRect_tag(SkSVGRect *svgRect) {
    return svgRect->tag();
}

void SkSVGRect_render(SkSVGRect *svgRect, const SkSVGRenderContext *svgRenderContext) {
    svgRect->render(*svgRenderContext);
}

bool SkSVGRect_asPaint(SkSVGRect *svgRect, const SkSVGRenderContext *svgRenderContext, SkPaint *paint) {
    return svgRect->asPaint(*svgRenderContext, paint);
}

sk_path_t SkSVGRect_asPath(SkSVGRect *svgRect, const SkSVGRenderContext *svgRenderContext) {
    return static_sk_path_make(svgRect->asPath(*svgRenderContext));
}

sk_rect_t SkSVGRect_objectBoundingBox(SkSVGRect *svgRect, const SkSVGRenderContext *svgRenderContext) {
    return static_sk_rect_make(svgRect->objectBoundingBox(*svgRenderContext));
}

void SkSVGRect_setAttribute(SkSVGRect *svgRect, SkSVGAttribute svgAttribute, const SkSVGValue *svgValue) {
    svgRect->setAttribute(svgAttribute, *svgValue);
}

// bool SkSVGRect_setAttribute(SkSVGRect *svgRect, const char *attributeName, const char *attributeValue) {
//     svgRect->
// }

bool SkSVGRect_unique(SkSVGRect *svgRect) {
    return svgRect->unique();
}

void SkSVGRect_ref(SkSVGRect *svgRect) {
    svgRect->ref();
}

void SkSVGRect_unref(SkSVGRect *svgRect) {
    svgRect->unref();
}

// static

sk_svg_rect_t SkSVGRect_Make() {
    return static_sk_svg_rect_make(SkSVGRect::Make());
}

}