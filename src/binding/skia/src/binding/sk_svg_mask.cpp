//
// Created by dolphilia on 2024/02/06.
//

#include "sk_svg_mask.h"

extern "C" {

void SkSVGMask_delete(SkSVGMask *svgMask) {
    delete svgMask;
}

void SkSVGMask_appendChild(SkSVGMask *svgMask, sk_svg_node_t svg_node) {
    svgMask->appendChild(static_sk_svg_node_move(svg_node));
}

void SkSVGMask_setTransform(SkSVGMask *svgMask, const SkSVGTransformType *t) {
    svgMask->setTransform(*t);
}

SkSVGTag SkSVGMask_tag(SkSVGMask *svgMask) {
    return svgMask->tag();
}

void SkSVGMask_render(SkSVGMask *svgMask, const SkSVGRenderContext *svgRenderContext) {
    svgMask->render(*svgRenderContext);
}

bool SkSVGMask_asPaint(SkSVGMask *svgMask, const SkSVGRenderContext *svgRenderContext, SkPaint *paint) {
    return svgMask->asPaint(*svgRenderContext, paint);
}

sk_path_t SkSVGMask_asPath(SkSVGMask *svgMask, const SkSVGRenderContext *svgRenderContext) {
    return static_sk_path_make(svgMask->asPath(*svgRenderContext));
}

sk_rect_t SkSVGMask_objectBoundingBox(SkSVGMask *svgMask, const SkSVGRenderContext *svgRenderContext) {
    return static_sk_rect_make(svgMask->objectBoundingBox(*svgRenderContext));
}

void SkSVGMask_setAttribute(SkSVGMask *svgMask, SkSVGAttribute svgAttribute, const SkSVGValue *svgValue) {
    svgMask->setAttribute(svgAttribute, *svgValue);
}

// bool SkSVGMask_setAttribute(SkSVGMask *svgMask, const char *attributeName, const char *attributeValue) {
//     svgMask->
// }

bool SkSVGMask_unique(SkSVGMask *svgMask) {
    return svgMask->unique();
}

void SkSVGMask_ref(SkSVGMask *svgMask) {
    svgMask->ref();
}

void SkSVGMask_unref(SkSVGMask *svgMask) {
    svgMask->unref();
}

// static

sk_svg_mask_t SkSVGMask_Make() {
    return static_sk_svg_mask_make(SkSVGMask::Make());
}

}