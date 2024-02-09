//
// Created by dolphilia on 2024/02/06.
//

#ifndef RAIA_SKIA_SK_SVG_TEXT_CONTAINER_H
#define RAIA_SKIA_SK_SVG_TEXT_CONTAINER_H

#include "modules/svg/include/SkSVGText.h"
#include "../static/static_sk_svg_node.h"
#include "../static/static_sk_path.h"
#include "../static/static_sk_rect.h"

extern "C" {
void SkSVGTextContainer_delete(SkSVGTextContainer *svgTextContainer);
void SkSVGTextContainer_appendChild(SkSVGTextContainer *svgTextContainer, sk_svg_node_t svg_node);
void SkSVGTextContainer_renderText(SkSVGTextContainer *svgTextContainer, const SkSVGRenderContext &svgRenderContext, SkSVGTextContext *svgTextContext, SkSVGXmlSpace svgXmlSpace);
void SkSVGTextContainer_setTransform(SkSVGTextContainer *svgTextContainer, const SkSVGTransformType *t);
SkSVGTag SkSVGTextContainer_tag(SkSVGTextContainer *svgTextContainer);
void SkSVGTextContainer_render(SkSVGTextContainer *svgTextContainer, const SkSVGRenderContext *svgRenderContext);
bool SkSVGTextContainer_asPaint(SkSVGTextContainer *svgTextContainer, const SkSVGRenderContext *svgRenderContext, SkPaint *paint);
sk_path_t SkSVGTextContainer_asPath(SkSVGTextContainer *svgTextContainer, const SkSVGRenderContext *svgRenderContext);
sk_rect_t SkSVGTextContainer_objectBoundingBox(SkSVGTextContainer *svgTextContainer, const SkSVGRenderContext *svgRenderContext);
void SkSVGTextContainer_setAttribute(SkSVGTextContainer *svgTextContainer, SkSVGAttribute svgAttribute, const SkSVGValue *svgValue);
// bool SkSVGTextContainer_setAttribute(SkSVGTextContainer *svgTextContainer, const char *attributeName, const char *attributeValue);
bool SkSVGTextContainer_unique(SkSVGTextContainer *svgTextContainer);
void SkSVGTextContainer_ref(SkSVGTextContainer *svgTextContainer);
void SkSVGTextContainer_unref(SkSVGTextContainer *svgTextContainer);
}

#endif //RAIA_SKIA_SK_SVG_TEXT_CONTAINER_H
