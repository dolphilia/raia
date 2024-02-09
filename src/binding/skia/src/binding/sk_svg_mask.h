//
// Created by dolphilia on 2024/02/06.
//

#ifndef RAIA_SKIA_SK_SVG_MASK_H
#define RAIA_SKIA_SK_SVG_MASK_H

#include "modules/svg/include/SkSVGMask.h"
#include "../static/static_sk_svg_node.h"
#include "../static/static_sk_path.h"
#include "../static/static_sk_rect.h"
#include "../static/static_sk_svg_mask.h"

extern "C" {
void SkSVGMask_delete(SkSVGMask *svgMask);
void SkSVGMask_appendChild(SkSVGMask *svgMask, sk_svg_node_t svg_node);
void SkSVGMask_setTransform(SkSVGMask *svgMask, const SkSVGTransformType *t);
SkSVGTag SkSVGMask_tag(SkSVGMask *svgMask);
void SkSVGMask_render(SkSVGMask *svgMask, const SkSVGRenderContext *svgRenderContext);
bool SkSVGMask_asPaint(SkSVGMask *svgMask, const SkSVGRenderContext *svgRenderContext, SkPaint *paint);
sk_path_t SkSVGMask_asPath(SkSVGMask *svgMask, const SkSVGRenderContext *svgRenderContext);
sk_rect_t SkSVGMask_objectBoundingBox(SkSVGMask *svgMask, const SkSVGRenderContext *svgRenderContext);
void SkSVGMask_setAttribute(SkSVGMask *svgMask, SkSVGAttribute svgAttribute, const SkSVGValue *svgValue);
// bool SkSVGMask_setAttribute(SkSVGMask *svgMask, const char *attributeName, const char *attributeValue);
bool SkSVGMask_unique(SkSVGMask *svgMask);
void SkSVGMask_ref(SkSVGMask *svgMask);
void SkSVGMask_unref(SkSVGMask *svgMask);
// static
sk_svg_mask_t SkSVGMask_Make();
}

#endif //RAIA_SKIA_SK_SVG_MASK_H
