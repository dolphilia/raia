//
// Created by dolphilia on 2024/02/06.
//

#ifndef RAIA_SKIA_SK_SVG_STOP_H
#define RAIA_SKIA_SK_SVG_STOP_H

#include "modules/svg/include/SkSVGStop.h"
#include "../static/static_sk_svg_node.h"
#include "../static/static_sk_path.h"
#include "../static/static_sk_rect.h"
#include "../static/static_sk_svg_stop.h"

extern "C" {
void SkSVGStop_delete(SkSVGStop *svgStop);
void SkSVGStop_appendChild(SkSVGStop *svgStop, sk_svg_node_t svg_node);
void SkSVGStop_setTransform(SkSVGStop *svgStop, const SkSVGTransformType *t);
SkSVGTag SkSVGStop_tag(SkSVGStop *svgStop);
void SkSVGStop_render(SkSVGStop *svgStop, const SkSVGRenderContext *svgRenderContext);
bool SkSVGStop_asPaint(SkSVGStop *svgStop, const SkSVGRenderContext *svgRenderContext, SkPaint *paint);
sk_path_t SkSVGStop_asPath(SkSVGStop *svgStop, const SkSVGRenderContext *svgRenderContext);
sk_rect_t SkSVGStop_objectBoundingBox(SkSVGStop *svgStop, const SkSVGRenderContext *svgRenderContext);
void SkSVGStop_setAttribute(SkSVGStop *svgStop, SkSVGAttribute svgAttribute, const SkSVGValue *svgValue);
// bool SkSVGStop_setAttribute(SkSVGStop *svgStop, const char *attributeName, const char *attributeValue);
bool SkSVGStop_unique(SkSVGStop *svgStop);
void SkSVGStop_ref(SkSVGStop *svgStop);
void SkSVGStop_unref(SkSVGStop *svgStop);
// static
sk_svg_stop_t SkSVGStop_Make();
}

#endif //RAIA_SKIA_SK_SVG_STOP_H
