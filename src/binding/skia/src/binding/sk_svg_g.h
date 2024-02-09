//
// Created by dolphilia on 2024/02/06.
//

#ifndef RAIA_SKIA_SK_SVG_G_H
#define RAIA_SKIA_SK_SVG_G_H

#include "modules/svg/include/SkSVGG.h"
#include "../static/static_sk_svg_node.h"
#include "../static/static_sk_path.h"
#include "../static/static_sk_rect.h"
#include "../static/static_sk_svg_g.h"

extern "C" {
void SkSVGG_delete(SkSVGG *svgg);
void SkSVGG_appendChild(SkSVGG *svgg, sk_svg_node_t svg_node);
void SkSVGG_setTransform(SkSVGG *svgg, const SkSVGTransformType *t);
SkSVGTag SkSVGG_tag(SkSVGG *svgg);
void SkSVGG_render(SkSVGG *svgg, const SkSVGRenderContext *svgRenderContext);
bool SkSVGG_asPaint(SkSVGG *svgg, const SkSVGRenderContext *svgRenderContext, SkPaint *paint);
sk_path_t SkSVGG_asPath(SkSVGG *svgg, const SkSVGRenderContext *svgRenderContext);
sk_rect_t SkSVGG_objectBoundingBox(SkSVGG *svgg, const SkSVGRenderContext *svgRenderContext);
void SkSVGG_setAttribute(SkSVGG *svgg, SkSVGAttribute svgAttribute, const SkSVGValue *svgValue);
// bool SkSVGG_setAttribute(SkSVGG *svgg, const char *attributeName, const char *attributeValue);
bool SkSVGG_parseAndSetAttribute(SkSVGG *svgg, const char *name, const char *value);
bool SkSVGG_unique(SkSVGG *svgg);
void SkSVGG_ref(SkSVGG *svgg);
void SkSVGG_unref(SkSVGG *svgg);
// static
//int SkSVGG_Make();
}

#endif //RAIA_SKIA_SK_SVG_G_H
