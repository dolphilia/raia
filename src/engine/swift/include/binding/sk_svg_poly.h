//
// Created by dolphilia on 2024/02/06.
//

#ifndef RAIA_SKIA_SK_SVG_POLY_H
#define RAIA_SKIA_SK_SVG_POLY_H

#include "modules/svg/include/SkSVGPoly.h"
#include "../static/static_sk_svg_node.h"
#include "../static/static_sk_path.h"
#include "../static/static_sk_rect.h"
#include "../static/static_sk_svg_poly.h"

extern "C" {
void SkSVGPoly_delete(SkSVGPoly *svgPoly);
void SkSVGPoly_appendChild(SkSVGPoly *svgPoly, sk_svg_node_t svg_node);
void SkSVGPoly_setTransform(SkSVGPoly *svgPoly, const SkSVGTransformType *t);
SkSVGTag SkSVGPoly_tag(SkSVGPoly *svgPoly);
void SkSVGPoly_render(SkSVGPoly *svgPoly, const SkSVGRenderContext *svgRenderContext);
bool SkSVGPoly_asPaint(SkSVGPoly *svgPoly, const SkSVGRenderContext *svgRenderContext, SkPaint *paint);
sk_path_t SkSVGPoly_asPath(SkSVGPoly *svgPoly, const SkSVGRenderContext *svgRenderContext);
sk_rect_t SkSVGPoly_objectBoundingBox(SkSVGPoly *svgPoly, const SkSVGRenderContext *svgRenderContext);
void SkSVGPoly_setAttribute(SkSVGPoly *svgPoly, SkSVGAttribute svgAttribute, const SkSVGValue *svgValue);
// bool SkSVGPoly_setAttribute(SkSVGPoly *svgPoly, const char *attributeName, const char *attributeValue);
bool SkSVGPoly_unique(SkSVGPoly *svgPoly);
void SkSVGPoly_ref(SkSVGPoly *svgPoly);
void SkSVGPoly_unref(SkSVGPoly *svgPoly);
// static
sk_svg_poly_t SkSVGPoly_MakePolygon ();
sk_svg_poly_t SkSVGPoly_MakePolyline ();
}

#endif //RAIA_SKIA_SK_SVG_POLY_H
