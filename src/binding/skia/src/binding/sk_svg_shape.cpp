//
// Created by dolphilia on 2024/02/06.
//

#include "sk_svg_shape.h"

extern "C" {

void SkSVGShape_delete(SkSVGShape *svgShape) {
    delete svgShape;
}

void SkSVGShape_appendChild(SkSVGShape *svgShape, sk_svg_node_t svg_node) {
    svgShape->appendChild(static_sk_svg_node_move(svg_node));
}

void SkSVGShape_setTransform(SkSVGShape *svgShape, const SkSVGTransformType *t) {
    svgShape->setTransform(*t);
}

SkSVGTag SkSVGShape_tag(SkSVGShape *svgShape) {
    return svgShape->tag();
}

void SkSVGShape_render(SkSVGShape *svgShape, const SkSVGRenderContext *svgRenderContext) {
    svgShape->render(*svgRenderContext);
}

bool SkSVGShape_asPaint(SkSVGShape *svgShape, const SkSVGRenderContext *svgRenderContext, SkPaint *paint) {
    return svgShape->asPaint(*svgRenderContext, paint);
}

sk_path_t SkSVGShape_asPath(SkSVGShape *svgShape, const SkSVGRenderContext *svgRenderContext) {
    return static_sk_path_make(svgShape->asPath(*svgRenderContext));
}

sk_rect_t SkSVGShape_objectBoundingBox(SkSVGShape *svgShape, const SkSVGRenderContext *svgRenderContext) {
    return static_sk_rect_make(svgShape->objectBoundingBox(*svgRenderContext));
}

void SkSVGShape_setAttribute(SkSVGShape *svgShape, SkSVGAttribute svgAttribute, const SkSVGValue *svgValue) {
    svgShape->setAttribute(svgAttribute, *svgValue);
}

// bool SkSVGShape_setAttribute(SkSVGShape *svgShape, const char *attributeName, const char *attributeValue) {
//     svgShape->
// }

bool SkSVGShape_parseAndSetAttribute(SkSVGShape *svgShape, const char *name, const char *value) {
    return svgShape->parseAndSetAttribute(name, value);
}

bool SkSVGShape_unique(SkSVGShape *svgShape) {
    return svgShape->unique();
}

void SkSVGShape_ref(SkSVGShape *svgShape) {
    svgShape->ref();
}

void SkSVGShape_unref(SkSVGShape *svgShape) {
    svgShape->unref();
}

}