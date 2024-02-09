//
// Created by dolphilia on 2024/02/05.
//

#include "sk_svg_defs.h"



extern "C" {

void SkSVGDefs_delete(SkSVGDefs *svgDefs) {
    delete svgDefs;
}

void SkSVGDefs_appendChild(SkSVGDefs *svgDefs, sk_svg_node_t svg_node) {
    svgDefs->appendChild(static_sk_svg_node_move(svg_node));
}

void SkSVGDefs_setTransform (SkSVGDefs *svgDefs, const SkSVGTransformType &t) {
    svgDefs->setTransform(t);
}

SkSVGTag SkSVGDefs_tag (SkSVGDefs *svgDefs) {
    return svgDefs->tag();
}

void SkSVGDefs_render (SkSVGDefs *svgDefs, const SkSVGRenderContext &svgRenderContext) {
    svgDefs->render(svgRenderContext);
}

bool SkSVGDefs_asPaint (SkSVGDefs *svgDefs, const SkSVGRenderContext &svgRenderContext, SkPaint *paint) {
    return  svgDefs->asPaint(svgRenderContext, paint);
}

sk_path_t SkSVGDefs_asPath (SkSVGDefs *svgDefs, const SkSVGRenderContext &svgRenderContext) {
    return static_sk_path_make(svgDefs->asPath(svgRenderContext));
}

sk_rect_t SkSVGDefs_objectBoundingBox (SkSVGDefs *svgDefs, const SkSVGRenderContext &svgRenderContext) {
    return static_sk_rect_make(svgDefs->objectBoundingBox(svgRenderContext));
}

void SkSVGDefs_setAttribute (SkSVGDefs *svgDefs, SkSVGAttribute svgAttribute, const SkSVGValue &svgValue) {
    svgDefs->setAttribute(svgAttribute, svgValue);
}

//bool SkSVGDefs_setAttribute_2(SkSVGDefs *svgDefs, const char *attributeName, const char *attributeValue) {
//    return svgDefs->setAttribute(attributeName, attributeValue);
//}

bool SkSVGDefs_parseAndSetAttribute (SkSVGDefs *svgDefs, const char *name, const char *value) {
    return svgDefs->parseAndSetAttribute(name, value);
}

bool SkSVGDefs_unique (SkSVGDefs *svgDefs) {
    return svgDefs->unique();
}

void SkSVGDefs_ref (SkSVGDefs *svgDefs) {
    svgDefs->ref();
}

void SkSVGDefs_unref (SkSVGDefs *svgDefs) {
    svgDefs->unref();
}

// static

//int SkSVGDefs_Make () {
//    return static_sk_svg_defs_make(SkSVGDefs::Make());
//}

}