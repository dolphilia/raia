//
// Created by dolphilia on 2024/02/06.
//

#ifndef RAIA_SKIA_SK_SVG_RECT_H
#define RAIA_SKIA_SK_SVG_RECT_H

#include "modules/svg/include/SkSVGRect.h"
#include "../static/static_sk_svg_node.h"
#include "../static/static_sk_path.h"
#include "../static/static_sk_rect.h"
#include "../static/static_sk_svg_rect.h"

extern "C" {
void SkSVGRect_delete(SkSVGRect *svgRect);
void SkSVGRect_appendChild(SkSVGRect *svgRect, sk_svg_node_t svg_node);
void SkSVGRect_setTransform(SkSVGRect *svgRect, const SkSVGTransformType *t);
SkSVGTag SkSVGRect_tag(SkSVGRect *svgRect);
void SkSVGRect_render(SkSVGRect *svgRect, const SkSVGRenderContext *svgRenderContext);
bool SkSVGRect_asPaint(SkSVGRect *svgRect, const SkSVGRenderContext *svgRenderContext, SkPaint *paint);
sk_path_t SkSVGRect_asPath(SkSVGRect *svgRect, const SkSVGRenderContext *svgRenderContext);
sk_rect_t SkSVGRect_objectBoundingBox(SkSVGRect *svgRect, const SkSVGRenderContext *svgRenderContext);
void SkSVGRect_setAttribute(SkSVGRect *svgRect, SkSVGAttribute svgAttribute, const SkSVGValue *svgValue);
// bool SkSVGRect_setAttribute(SkSVGRect *svgRect, const char *attributeName, const char *attributeValue);
bool SkSVGRect_unique(SkSVGRect *svgRect);
void SkSVGRect_ref(SkSVGRect *svgRect);
void SkSVGRect_unref(SkSVGRect *svgRect);
// static
sk_svg_rect_t SkSVGRect_Make();
}

#endif //RAIA_SKIA_SK_SVG_RECT_H
