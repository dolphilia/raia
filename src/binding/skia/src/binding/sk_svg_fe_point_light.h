//
// Created by dolphilia on 2024/02/06.
//

#ifndef RAIA_SKIA_SK_SVG_FE_POINT_LIGHT_H
#define RAIA_SKIA_SK_SVG_FE_POINT_LIGHT_H

#include "modules/svg/include/SkSVGFeLightSource.h"
#include "../static/static_sk_svg_node.h"
#include "../static/static_sk_path.h"
#include "../static/static_sk_rect.h"
#include "../static/static_sk_svg_fe_point_light.h"

extern "C" {
void SkSVGFePointLight_delete(SkSVGFePointLight *svgFePointLight);
void SkSVGFePointLight_appendChild(SkSVGFePointLight *svgFePointLight, sk_svg_node_t svg_node);
void SkSVGFePointLight_setTransform(SkSVGFePointLight *svgFePointLight, const SkSVGTransformType *t);
SkSVGTag SkSVGFePointLight_tag(SkSVGFePointLight *svgFePointLight);
void SkSVGFePointLight_render(SkSVGFePointLight *svgFePointLight, const SkSVGRenderContext *svgRenderContext);
bool SkSVGFePointLight_asPaint(SkSVGFePointLight *svgFePointLight, const SkSVGRenderContext *svgRenderContext, SkPaint *paint);
sk_path_t SkSVGFePointLight_asPath(SkSVGFePointLight *svgFePointLight, const SkSVGRenderContext *svgRenderContext);
sk_rect_t SkSVGFePointLight_objectBoundingBox(SkSVGFePointLight *svgFePointLight, const SkSVGRenderContext *svgRenderContext);
void SkSVGFePointLight_setAttribute(SkSVGFePointLight *svgFePointLight, SkSVGAttribute svgAttribute, const SkSVGValue *svgValue);
// bool SkSVGFePointLight_setAttribute(SkSVGFePointLight *svgFePointLight, const char *attributeName, const char *attributeValue);
bool SkSVGFePointLight_unique(SkSVGFePointLight *svgFePointLight);
void SkSVGFePointLight_ref(SkSVGFePointLight *svgFePointLight);
void SkSVGFePointLight_unref(SkSVGFePointLight *svgFePointLight);
// static
sk_svg_fe_point_light_t SkSVGFePointLight_Make();
}

#endif //RAIA_SKIA_SK_SVG_FE_POINT_LIGHT_H
