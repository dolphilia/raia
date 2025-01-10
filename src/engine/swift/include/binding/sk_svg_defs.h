//
// Created by dolphilia on 2024/02/05.
//

#ifndef RAIA_SKIA_SK_SVG_DEFS_H
#define RAIA_SKIA_SK_SVG_DEFS_H

#include "modules/svg/include/SkSVGDefs.h"
#include "../static/static_sk_svg_node.h"
#include "../static/static_sk_path.h"
#include "../static/static_sk_rect.h"
#include "../static/static_sk_svg_defs.h"

extern "C" {
void SkSVGDefs_delete(SkSVGDefs *svgDefs);
void SkSVGDefs_appendChild(SkSVGDefs *svgDefs, sk_svg_node_t svg_node);
void SkSVGDefs_setTransform (SkSVGDefs *svgDefs, const SkSVGTransformType &t);
SkSVGTag SkSVGDefs_tag (SkSVGDefs *svgDefs);
void SkSVGDefs_render (SkSVGDefs *svgDefs, const SkSVGRenderContext &svgRenderContext);
bool SkSVGDefs_asPaint (SkSVGDefs *svgDefs, const SkSVGRenderContext &svgRenderContext, SkPaint *paint);
sk_path_t SkSVGDefs_asPath (SkSVGDefs *svgDefs, const SkSVGRenderContext &svgRenderContext);
sk_rect_t SkSVGDefs_objectBoundingBox (SkSVGDefs *svgDefs, const SkSVGRenderContext &svgRenderContext);
void SkSVGDefs_setAttribute (SkSVGDefs *svgDefs, SkSVGAttribute svgAttribute, const SkSVGValue &svgValue);
//bool SkSVGDefs_setAttribute_2(SkSVGDefs *svgDefs, const char *attributeName, const char *attributeValue);
bool SkSVGDefs_parseAndSetAttribute (SkSVGDefs *svgDefs, const char *name, const char *value);
bool SkSVGDefs_unique (SkSVGDefs *svgDefs);
void SkSVGDefs_ref (SkSVGDefs *svgDefs);
void SkSVGDefs_unref (SkSVGDefs *svgDefs);
// static
//int SkSVGDefs_Make ();
}

#endif //RAIA_SKIA_SK_SVG_DEFS_H
