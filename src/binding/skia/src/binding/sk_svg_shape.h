//
// Created by dolphilia on 2024/02/06.
//

#ifndef RAIA_SKIA_SK_SVG_SHAPE_H
#define RAIA_SKIA_SK_SVG_SHAPE_H

#include "modules/svg/include/SkSVGShape.h"
#include "../static/static_sk_svg_node.h"
#include "../static/static_sk_path.h"
#include "../static/static_sk_rect.h"

extern "C" {
void SkSVGShape_delete(SkSVGShape *svgShape);
void SkSVGShape_appendChild(SkSVGShape *svgShape, sk_svg_node_t svg_node);
void SkSVGShape_setTransform(SkSVGShape *svgShape, const SkSVGTransformType *t);
SkSVGTag SkSVGShape_tag(SkSVGShape *svgShape);
void SkSVGShape_render(SkSVGShape *svgShape, const SkSVGRenderContext *svgRenderContext);
bool SkSVGShape_asPaint(SkSVGShape *svgShape, const SkSVGRenderContext *svgRenderContext, SkPaint *paint);
sk_path_t SkSVGShape_asPath(SkSVGShape *svgShape, const SkSVGRenderContext *svgRenderContext);
sk_rect_t SkSVGShape_objectBoundingBox(SkSVGShape *svgShape, const SkSVGRenderContext *svgRenderContext);
void SkSVGShape_setAttribute(SkSVGShape *svgShape, SkSVGAttribute svgAttribute, const SkSVGValue *svgValue);
// bool SkSVGShape_setAttribute(SkSVGShape *svgShape, const char *attributeName, const char *attributeValue);
bool SkSVGShape_parseAndSetAttribute(SkSVGShape *svgShape, const char *name, const char *value);
bool SkSVGShape_unique(SkSVGShape *svgShape);
void SkSVGShape_ref(SkSVGShape *svgShape);
void SkSVGShape_unref(SkSVGShape *svgShape);
}

#endif //RAIA_SKIA_SK_SVG_SHAPE_H
