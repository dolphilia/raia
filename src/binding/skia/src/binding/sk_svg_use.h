//
// Created by dolphilia on 2024/02/06.
//

#ifndef RAIA_SKIA_SK_SVG_USE_H
#define RAIA_SKIA_SK_SVG_USE_H

#include "modules/svg/include/SkSVGUse.h"
#include "../static/static_sk_svg_node.h"
#include "../static/static_sk_path.h"
#include "../static/static_sk_rect.h"
#include "../static/static_sk_svg_use.h"

extern "C" {
void SkSVGUse_delete(SkSVGUse *svgUse);
void SkSVGUse_appendChild(SkSVGUse *svgUse, sk_svg_node_t svg_node);
void SkSVGUse_setTransform(SkSVGUse *svgUse, const SkSVGTransformType *t);
SkSVGTag SkSVGUse_tag(SkSVGUse *svgUse);
void SkSVGUse_render(SkSVGUse *svgUse, const SkSVGRenderContext *svgRenderContext);
bool SkSVGUse_asPaint(SkSVGUse *svgUse, const SkSVGRenderContext *svgRenderContext, SkPaint *paint);
sk_path_t SkSVGUse_asPath(SkSVGUse *svgUse, const SkSVGRenderContext *svgRenderContext);
sk_rect_t SkSVGUse_objectBoundingBox(SkSVGUse *svgUse, const SkSVGRenderContext *svgRenderContext);
void SkSVGUse_setAttribute(SkSVGUse *svgUse, SkSVGAttribute svgAttribute, const SkSVGValue *svgValue);
// bool SkSVGUse_setAttribute(SkSVGUse *svgUse, const char *attributeName, const char *attributeValue);
bool SkSVGUse_unique(SkSVGUse *svgUse);
void SkSVGUse_ref(SkSVGUse *svgUse);
void SkSVGUse_unref(SkSVGUse *svgUse);
// static
sk_svg_use_t SkSVGUse_Make();
}

#endif //RAIA_SKIA_SK_SVG_USE_H
