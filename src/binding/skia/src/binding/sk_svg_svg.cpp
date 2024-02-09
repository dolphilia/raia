//
// Created by dolphilia on 2024/02/06.
//

#include "sk_svg_svg.h"

extern "C" {

void SkSVGSVG_delete(SkSVGSVG *svgSvg) {
    delete svgSvg;
}

SkSize SkSVGSVG_intrinsicSize (SkSVGSVG *svgSvg, const SkSVGLengthContext *svgLengthContext) {
    return svgSvg->intrinsicSize(*svgLengthContext);
}

void SkSVGSVG_renderNode (SkSVGSVG *svgSvg, const SkSVGRenderContext *svgRenderContext, const SkSVGIRI *iri) {
    svgSvg->renderNode(*svgRenderContext, *iri);
}

void SkSVGSVG_appendChild(SkSVGSVG *svgSvg, sk_svg_node_t svg_node) {
    svgSvg->appendChild(static_sk_svg_node_move(svg_node));
}

void SkSVGSVG_setTransform(SkSVGSVG *svgSvg, const SkSVGTransformType *t) {
    svgSvg->setTransform(*t);
}

SkSVGTag SkSVGSVG_tag(SkSVGSVG *svgSvg) {
    return svgSvg->tag();
}

void SkSVGSVG_render(SkSVGSVG *svgSvg, const SkSVGRenderContext *svgRenderContext) {
    svgSvg->render(*svgRenderContext);
}

bool SkSVGSVG_asPaint(SkSVGSVG *svgSvg, const SkSVGRenderContext *svgRenderContext, SkPaint *paint) {
    return svgSvg->asPaint(*svgRenderContext, paint);
}

sk_path_t SkSVGSVG_asPath(SkSVGSVG *svgSvg, const SkSVGRenderContext *svgRenderContext) {
    return static_sk_path_make(svgSvg->asPath(*svgRenderContext));
}

sk_rect_t SkSVGSVG_objectBoundingBox(SkSVGSVG *svgSvg, const SkSVGRenderContext *svgRenderContext) {
    return static_sk_rect_make(svgSvg->objectBoundingBox(*svgRenderContext));
}

void SkSVGSVG_setAttribute(SkSVGSVG *svgSvg, SkSVGAttribute svgAttribute, const SkSVGValue *svgValue) {
    svgSvg->setAttribute(svgAttribute, *svgValue);
}

// bool SkSVGSVG_setAttribute(cSkSVGSVG *svgSvg, onst char *attributeName, const char *attributeValue) {
//     svgSvg->
// }

bool SkSVGSVG_parseAndSetAttribute(SkSVGSVG *svgSvg, const char *name, const char *value) {
    return svgSvg->parseAndSetAttribute(name, value);
}

bool SkSVGSVG_unique(SkSVGSVG *svgSvg) {
    return svgSvg->unique();
}

void SkSVGSVG_ref(SkSVGSVG *svgSvg) {
    svgSvg->ref();
}

void SkSVGSVG_unref(SkSVGSVG *svgSvg) {
    svgSvg->unref();
}

// static

sk_svg_svg_t SkSVGSVG_Make (SkSVGSVG::Type t) {
    return static_sk_svg_svg_make(SkSVGSVG::Make(t));
}

}