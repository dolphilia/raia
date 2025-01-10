//
// Created by dolphilia on 2024/02/06.
//

#ifndef RAIA_SKIA_SK_SVG_FE_DISTANT_LIGHT_H
#define RAIA_SKIA_SK_SVG_FE_DISTANT_LIGHT_H

#include "modules/svg/include/SkSVGFeLightSource.h"
#include "../static/static_sk_svg_node.h"
#include "../static/static_sk_path.h"
#include "../static/static_sk_rect.h"
#include "../static/static_sk_svg_fe_distant_light.h"

extern "C" {
void SkSVGFeDistantLight_delete(SkSVGFeDistantLight *svgFeDistantLight);
SkPoint3 SkSVGFeDistantLight_computeDirection (SkSVGFeDistantLight *svgFeDistantLight);
void SkSVGFeDistantLight_appendChild(sk_svg_node_t svg_node, SkSVGFeDistantLight *svgFeDistantLight);
void SkSVGFeDistantLight_setTransform(SkSVGFeDistantLight *svgFeDistantLight, const SkSVGTransformType *t);
SkSVGTag SkSVGFeDistantLight_tag(SkSVGFeDistantLight *svgFeDistantLight);
void SkSVGFeDistantLight_render(SkSVGFeDistantLight *svgFeDistantLight, const SkSVGRenderContext *svgRenderContext);
bool SkSVGFeDistantLight_asPaint(SkSVGFeDistantLight *svgFeDistantLight, const SkSVGRenderContext *svgRenderContext, SkPaint *paint);
sk_path_t SkSVGFeDistantLight_asPath(SkSVGFeDistantLight *svgFeDistantLight, const SkSVGRenderContext *svgRenderContext);
sk_rect_t SkSVGFeDistantLight_objectBoundingBox(SkSVGFeDistantLight *svgFeDistantLight, const SkSVGRenderContext *svgRenderContext);
void SkSVGFeDistantLight_setAttribute(SkSVGFeDistantLight *svgFeDistantLight, SkSVGAttribute svgAttribute, const SkSVGValue *svgValue);
//bool SkSVGFeDistantLight_setAttribute(SkSVGFeDistantLight *svgFeDistantLight, const char *attributeName, const char *attributeValue);
bool SkSVGFeDistantLight_unique(SkSVGFeDistantLight *svgFeDistantLight);
void SkSVGFeDistantLight_ref(SkSVGFeDistantLight *svgFeDistantLight);
void SkSVGFeDistantLight_unref(SkSVGFeDistantLight *svgFeDistantLight);
// static
sk_svg_fe_distant_light_t SkSVGFeDistantLight_Make();
}

#endif //RAIA_SKIA_SK_SVG_FE_DISTANT_LIGHT_H
