//
// Created by dolphilia on 2024/02/04.
//

#ifndef RAIA_SKIA_SK_SVG_CONTAINER_H
#define RAIA_SKIA_SK_SVG_CONTAINER_H

#include "modules/svg/include/SkSVGContainer.h"
#include "../static/static_sk_svg_node.h"
#include "../static/static_sk_path.h"
#include "../static/static_sk_rect.h"

extern "C" {
void SkSVGContainer_delete(SkSVGContainer *svgContainer);
void SkSVGContainer_appendChild(SkSVGContainer *svgContainer, sk_svg_node_t svg_node);
void SkSVGContainer_setTransform(SkSVGContainer *svgContainer, const SkSVGTransformType &t);
SkSVGTag SkSVGContainer_tag(SkSVGContainer *svgContainer);
void SkSVGContainer_render(SkSVGContainer *svgContainer, const SkSVGRenderContext &svgRenderContext);
bool SkSVGContainer_asPaint(SkSVGContainer *svgContainer, const SkSVGRenderContext &svgRenderContext, SkPaint *paint);
sk_path_t SkSVGContainer_asPath(SkSVGContainer *svgContainer, const SkSVGRenderContext &svgRenderContext);
sk_rect_t SkSVGContainer_objectBoundingBox(SkSVGContainer *svgContainer, const SkSVGRenderContext &svgRenderContext);
void SkSVGContainer_setAttribute(SkSVGContainer *svgContainer, SkSVGAttribute svgAttribute, const SkSVGValue &svgValue);
//bool SkSVGContainer_setAttribute_2(SkSVGContainer* svgContainer, const char *attributeName, const char *attributeValue);
bool SkSVGContainer_parseAndSetAttribute(SkSVGContainer *svgContainer, const char *name, const char *value);
bool SkSVGContainer_unique(SkSVGContainer *svgContainer);
void SkSVGContainer_ref(SkSVGContainer *svgContainer);
void SkSVGContainer_unref(SkSVGContainer *svgContainer);
}

#endif //RAIA_SKIA_SK_SVG_CONTAINER_H
