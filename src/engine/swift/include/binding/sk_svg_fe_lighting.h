//
// Created by dolphilia on 2024/02/06.
//

#ifndef RAIA_SKIA_SK_SVG_FE_LIGHTING_H
#define RAIA_SKIA_SK_SVG_FE_LIGHTING_H

#include "modules/svg/include/SkSVGFeLightSource.h"
#include "../static/static_sk_svg_node.h"
#include "../static/static_sk_path.h"
#include "../static/static_sk_rect.h"

extern "C" {
void SkSVGFeLightSource_delete(SkSVGFeLightSource *svgFeLightSource);
void SkSVGFeLightSource_appendChild(SkSVGFeLightSource *svgFeLightSource, sk_svg_node_t svg_node);
void SkSVGFeLightSource_setTransform(SkSVGFeLightSource *svgFeLightSource, const SkSVGTransformType *t);
SkSVGTag SkSVGFeLightSource_tag(SkSVGFeLightSource *svgFeLightSource);
void SkSVGFeLightSource_render(SkSVGFeLightSource *svgFeLightSource, const SkSVGRenderContext *svgRenderContext);
bool SkSVGFeLightSource_asPaint(SkSVGFeLightSource *svgFeLightSource, const SkSVGRenderContext *svgRenderContext, SkPaint *paint);
sk_path_t SkSVGFeLightSource_asPath(SkSVGFeLightSource *svgFeLightSource, const SkSVGRenderContext *svgRenderContext);
sk_rect_t SkSVGFeLightSource_objectBoundingBox(SkSVGFeLightSource *svgFeLightSource, const SkSVGRenderContext *svgRenderContext);
void SkSVGFeLightSource_setAttribute(SkSVGFeLightSource *svgFeLightSource, SkSVGAttribute svgAttribute, const SkSVGValue *svgValue);
// bool SkSVGFeLightSource_setAttribute(SkSVGFeLightSource *svgFeLightSource, const char *attributeName, const char *attributeValue);
bool SkSVGFeLightSource_parseAndSetAttribute(SkSVGFeLightSource *svgFeLightSource, const char *name, const char *value);
bool SkSVGFeLightSource_unique(SkSVGFeLightSource *svgFeLightSource);
void SkSVGFeLightSource_ref(SkSVGFeLightSource *svgFeLightSource);
void SkSVGFeLightSource_unref(SkSVGFeLightSource *svgFeLightSource);
}

#endif //RAIA_SKIA_SK_SVG_FE_LIGHTING_H
