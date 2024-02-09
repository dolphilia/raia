//
// Created by dolphilia on 2024/02/06.
//

#include "sk_svg_ellipse.h"

extern "C" {

void SkSVGEllipse_delete(SkSVGEllipse *svgEllipse) {
    delete svgEllipse;
}

void SkSVGEllipse_appendChild(SkSVGEllipse *svgEllipse, sk_svg_node_t svg_node) {
    svgEllipse->appendChild(static_sk_svg_node_move(svg_node));
}

void SkSVGEllipse_setTransform (SkSVGEllipse *svgEllipse, const SkSVGTransformType *t) {
    svgEllipse->setTransform(*t);
}

SkSVGTag SkSVGEllipse_tag (SkSVGEllipse *svgEllipse) {
    return svgEllipse->tag();
}

void SkSVGEllipse_render (SkSVGEllipse *svgEllipse, const SkSVGRenderContext *svgRenderContext) {
    svgEllipse->render(*svgRenderContext);
}

bool SkSVGEllipse_asPaint (SkSVGEllipse *svgEllipse, const SkSVGRenderContext *svgRenderContext, SkPaint *paint) {
    return svgEllipse->asPaint(*svgRenderContext, paint);
}

sk_path_t SkSVGEllipse_asPath (SkSVGEllipse *svgEllipse, const SkSVGRenderContext *svgRenderContext) {
    return static_sk_path_make(svgEllipse->asPath(*svgRenderContext));
}

sk_rect_t SkSVGEllipse_objectBoundingBox (SkSVGEllipse *svgEllipse, const SkSVGRenderContext *svgRenderContext) {
    return static_sk_rect_make(svgEllipse->objectBoundingBox(*svgRenderContext));
}

void SkSVGEllipse_setAttribute (SkSVGEllipse *svgEllipse, SkSVGAttribute svgAttribute, const SkSVGValue *svgValue) {
    svgEllipse->setAttribute(svgAttribute, *svgValue);
}

//bool SkSVGEllipse_setAttribute (SkSVGEllipse *svgEllipse, const char *attributeName, const char *attributeValue) {
//    svgEllipse->setAttribute(attributeName, attributeValue);
//}

bool SkSVGEllipse_unique (SkSVGEllipse *svgEllipse) {
    return svgEllipse->unique();
}

void SkSVGEllipse_ref (SkSVGEllipse *svgEllipse) {
    svgEllipse->ref();
}

void SkSVGEllipse_unref (SkSVGEllipse *svgEllipse) {
    svgEllipse->unref();
}

// static
sk_svg_ellipse_t SkSVGEllipse_Make () {
    return static_sk_svg_ellipse_make(SkSVGEllipse::Make());
}

}