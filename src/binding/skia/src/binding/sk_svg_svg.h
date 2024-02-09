//
// Created by dolphilia on 2024/02/06.
//

#ifndef RAIA_SKIA_SK_SVG_SVG_H
#define RAIA_SKIA_SK_SVG_SVG_H

#include "modules/svg/include/SkSVGSVG.h"
#include "../static/static_sk_svg_node.h"
#include "../static/static_sk_path.h"
#include "../static/static_sk_rect.h"
#include "../static/static_sk_svg_svg.h"

extern "C" {
void SkSVGSVG_delete(SkSVGSVG *svgSvg);
SkSize SkSVGSVG_intrinsicSize (SkSVGSVG *svgSvg, const SkSVGLengthContext *svgLengthContext);
void SkSVGSVG_renderNode (SkSVGSVG *svgSvg, const SkSVGRenderContext *svgRenderContext, const SkSVGIRI *iri);
void SkSVGSVG_appendChild(SkSVGSVG *svgSvg, sk_svg_node_t svg_node);
void SkSVGSVG_setTransform(SkSVGSVG *svgSvg, const SkSVGTransformType *t);
SkSVGTag SkSVGSVG_tag(SkSVGSVG *svgSvg);
void SkSVGSVG_render(SkSVGSVG *svgSvg, const SkSVGRenderContext *svgRenderContext);
bool SkSVGSVG_asPaint(SkSVGSVG *svgSvg, const SkSVGRenderContext *svgRenderContext, SkPaint *paint);
sk_path_t SkSVGSVG_asPath(SkSVGSVG *svgSvg, const SkSVGRenderContext *svgRenderContext);
sk_rect_t SkSVGSVG_objectBoundingBox(SkSVGSVG *svgSvg, const SkSVGRenderContext *svgRenderContext);
void SkSVGSVG_setAttribute(SkSVGSVG *svgSvg, SkSVGAttribute svgAttribute, const SkSVGValue *svgValue);
// bool SkSVGSVG_setAttribute(cSkSVGSVG *svgSvg, onst char *attributeName, const char *attributeValue);
bool SkSVGSVG_parseAndSetAttribute(SkSVGSVG *svgSvg, const char *name, const char *value);
bool SkSVGSVG_unique(SkSVGSVG *svgSvg);
void SkSVGSVG_ref(SkSVGSVG *svgSvg);
void SkSVGSVG_unref(SkSVGSVG *svgSvg);
// static
sk_svg_svg_t SkSVGSVG_Make (SkSVGSVG::Type t);
}

#endif //RAIA_SKIA_SK_SVG_SVG_H
