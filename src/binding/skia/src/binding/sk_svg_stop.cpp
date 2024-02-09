//
// Created by dolphilia on 2024/02/06.
//

#include "sk_svg_stop.h"

extern "C" {

void SkSVGStop_delete(SkSVGStop *svgStop) {
    delete svgStop;
}

void SkSVGStop_appendChild(SkSVGStop *svgStop, sk_svg_node_t svg_node) {
    svgStop->appendChild(static_sk_svg_node_move(svg_node));
}

void SkSVGStop_setTransform(SkSVGStop *svgStop, const SkSVGTransformType *t) {
    svgStop->setTransform(*t);
}

SkSVGTag SkSVGStop_tag(SkSVGStop *svgStop) {
    return svgStop->tag();
}

void SkSVGStop_render(SkSVGStop *svgStop, const SkSVGRenderContext *svgRenderContext) {
    svgStop->render(*svgRenderContext);
}

bool SkSVGStop_asPaint(SkSVGStop *svgStop, const SkSVGRenderContext *svgRenderContext, SkPaint *paint) {
    return svgStop->asPaint(*svgRenderContext, paint);
}

sk_path_t SkSVGStop_asPath(SkSVGStop *svgStop, const SkSVGRenderContext *svgRenderContext) {
    return static_sk_path_make(svgStop->asPath(*svgRenderContext));
}

sk_rect_t SkSVGStop_objectBoundingBox(SkSVGStop *svgStop, const SkSVGRenderContext *svgRenderContext) {
    return static_sk_rect_make(svgStop->objectBoundingBox(*svgRenderContext));
}

void SkSVGStop_setAttribute(SkSVGStop *svgStop, SkSVGAttribute svgAttribute, const SkSVGValue *svgValue) {
    svgStop->setAttribute(svgAttribute, *svgValue);
}

// bool SkSVGStop_setAttribute(SkSVGStop *svgStop, const char *attributeName, const char *attributeValue) {
//     svgStop->
// }

bool SkSVGStop_unique(SkSVGStop *svgStop) {
    return svgStop->unique();
}

void SkSVGStop_ref(SkSVGStop *svgStop) {
    svgStop->ref();
}

void SkSVGStop_unref(SkSVGStop *svgStop) {
    svgStop->unref();
}

// static

sk_svg_stop_t SkSVGStop_Make() {
    return static_sk_svg_stop_make(SkSVGStop::Make());
}

}