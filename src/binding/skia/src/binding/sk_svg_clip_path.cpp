//
// Created by dolphilia on 2024/02/04.
//

#include "sk_svg_clip_path.h"

extern "C" {

void SkSVGClipPath_delete(SkSVGClipPath *svgClipPath) {
    delete svgClipPath;
}

//SVG_ATTR(ClipPathUnits, SkSVGObjectBoundingBoxUnits, SkSVGObjectBoundingBoxUnits(SkSVGObjectBoundingBoxUnits::Type::kUserSpaceOnUse)) private SkSVGClipPath ()

//bool SkSVGClipPath_parseAndSetAttribute(SkSVGClipPath *svgClipPath, const char *str1, const char *str2) {
//    return svgClipPath->
//}

//SkPath SkSVGClipPath_resolveClip(SkSVGClipPath *svgClipPath, const SkSVGRenderContext &svgRenderContext) {
//    return svgClipPath->
//}

void SkSVGClipPath_appendChild(SkSVGClipPath *svgClipPath, sk_svg_node_t svg_node) {
    svgClipPath->appendChild(static_sk_svg_node_move(svg_node));
}

void SkSVGClipPath_setTransform(SkSVGClipPath *svgClipPath, const SkSVGTransformType &t) {
    svgClipPath->setTransform(t);
}

SkSVGTag SkSVGClipPath_tag(SkSVGClipPath *svgClipPath) {
    return svgClipPath->tag();
}

void SkSVGClipPath_render(SkSVGClipPath *svgClipPath, const SkSVGRenderContext &svgRenderContext) {
    svgClipPath->render(svgRenderContext);
}

bool SkSVGClipPath_asPaint(SkSVGClipPath *svgClipPath, const SkSVGRenderContext &svgRenderContext, SkPaint *paint) {
    return svgClipPath->asPaint(svgRenderContext, paint);
}

sk_path_t SkSVGClipPath_asPath(SkSVGClipPath *svgClipPath, const SkSVGRenderContext &svgRenderContext) {
    return static_sk_path_make(svgClipPath->asPath(svgRenderContext));
}

sk_rect_t SkSVGClipPath_objectBoundingBox(SkSVGClipPath *svgClipPath, const SkSVGRenderContext &svgRenderContext) {
    return static_sk_rect_make(svgClipPath->objectBoundingBox(svgRenderContext));
}

void SkSVGClipPath_setAttribute(SkSVGClipPath *svgClipPath, SkSVGAttribute svgAttribute, const SkSVGValue &svgValue) {
    svgClipPath->setAttribute(svgAttribute, svgValue);
}

//bool SkSVGClipPath_setAttribute_2(SkSVGClipPath *svgClipPath, const char *attributeName, const char *attributeValue) {
//    return svgClipPath->setAttribute(attributeName, attributeValue);
//}

bool SkSVGClipPath_unique(SkSVGClipPath *svgClipPath) {
    return svgClipPath->unique();
}

void SkSVGClipPath_ref(SkSVGClipPath *svgClipPath) {
    svgClipPath->ref();
}

void SkSVGClipPath_unref(SkSVGClipPath *svgClipPath) {
    svgClipPath->unref();
}

// static

sk_svg_clip_path_t SkSVGClipPath_Make() {
    return static_sk_svg_clip_path_make(SkSVGClipPath::Make());
}

}