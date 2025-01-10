//
// Created by dolphilia on 2024/02/06.
//

#ifndef RAIA_SKIA_SK_SVG_FE_SPOT_LIGHT_H
#define RAIA_SKIA_SK_SVG_FE_SPOT_LIGHT_H

#include "modules/svg/include/SkSVGFeLightSource.h"
#include "../static/static_sk_svg_node.h"
#include "../static/static_sk_path.h"
#include "../static/static_sk_rect.h"
#include "../static/static_sk_svg_fe_spot_light.h"

extern "C" {
void SkSVGFeSpotLight_delete(SkSVGFeSpotLight *svgFeSpotLight);
void SkSVGFeSpotLight_appendChild(SkSVGFeSpotLight *svgFeSpotLight, sk_svg_node_t svg_node);
void SkSVGFeSpotLight_setTransform(SkSVGFeSpotLight *svgFeSpotLight, const SkSVGTransformType *t);
SkSVGTag SkSVGFeSpotLight_tag(SkSVGFeSpotLight *svgFeSpotLight);
void SkSVGFeSpotLight_render(SkSVGFeSpotLight *svgFeSpotLight, const SkSVGRenderContext *svgRenderContext);
bool SkSVGFeSpotLight_asPaint(SkSVGFeSpotLight *svgFeSpotLight, const SkSVGRenderContext *svgRenderContext, SkPaint *paint);
sk_path_t SkSVGFeSpotLight_asPath(SkSVGFeSpotLight *svgFeSpotLight, const SkSVGRenderContext *svgRenderContext);
sk_rect_t SkSVGFeSpotLight_objectBoundingBox(SkSVGFeSpotLight *svgFeSpotLight, const SkSVGRenderContext *svgRenderContext);
void SkSVGFeSpotLight_setAttribute(SkSVGFeSpotLight *svgFeSpotLight, SkSVGAttribute svgAttribute, const SkSVGValue *svgValue);
// bool SkSVGFeSpotLight_setAttribute(SkSVGFeSpotLight *svgFeSpotLight, const char *attributeName, const char *attributeValue);
bool SkSVGFeSpotLight_unique(SkSVGFeSpotLight *svgFeSpotLight);
void SkSVGFeSpotLight_ref(SkSVGFeSpotLight *svgFeSpotLight);
void SkSVGFeSpotLight_unref(SkSVGFeSpotLight *svgFeSpotLight);
// static
sk_svg_fe_spot_light_t SkSVGFeSpotLight_Make();
}

#endif //RAIA_SKIA_SK_SVG_FE_SPOT_LIGHT_H
