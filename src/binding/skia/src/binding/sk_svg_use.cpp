//
// Created by dolphilia on 2024/02/06.
//

#include "sk_svg_use.h"

extern "C" {

void SkSVGUse_delete(SkSVGUse *svgUse) {
    delete svgUse;
}

void SkSVGUse_appendChild(SkSVGUse *svgUse, sk_svg_node_t svg_node) {
    svgUse->appendChild(static_sk_svg_node_move(svg_node));
}

void SkSVGUse_setTransform(SkSVGUse *svgUse, const SkSVGTransformType *t) {
    svgUse->setTransform(*t);
}

SkSVGTag SkSVGUse_tag(SkSVGUse *svgUse) {
    return svgUse->tag();
}

void SkSVGUse_render(SkSVGUse *svgUse, const SkSVGRenderContext *svgRenderContext) {
    svgUse->render(*svgRenderContext);
}

bool SkSVGUse_asPaint(SkSVGUse *svgUse, const SkSVGRenderContext *svgRenderContext, SkPaint *paint) {
    return svgUse->asPaint(*svgRenderContext, paint);
}

sk_path_t SkSVGUse_asPath(SkSVGUse *svgUse, const SkSVGRenderContext *svgRenderContext) {
    return static_sk_path_make(svgUse->asPath(*svgRenderContext));
}

sk_rect_t SkSVGUse_objectBoundingBox(SkSVGUse *svgUse, const SkSVGRenderContext *svgRenderContext) {
    return static_sk_rect_make(svgUse->objectBoundingBox(*svgRenderContext));
}

void SkSVGUse_setAttribute(SkSVGUse *svgUse, SkSVGAttribute svgAttribute, const SkSVGValue *svgValue) {
    svgUse->setAttribute(svgAttribute, *svgValue);
}

// bool SkSVGUse_setAttribute(SkSVGUse *svgUse, const char *attributeName, const char *attributeValue) {
//     svgUse->
// }

bool SkSVGUse_unique(SkSVGUse *svgUse) {
    return svgUse->unique();
}

void SkSVGUse_ref(SkSVGUse *svgUse) {
    svgUse->ref();
}

void SkSVGUse_unref(SkSVGUse *svgUse) {
    svgUse->unref();
}

// static

sk_svg_use_t SkSVGUse_Make() {
    return static_sk_svg_use_make(SkSVGUse::Make());
}

}