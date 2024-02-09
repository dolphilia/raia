//
// Created by dolphilia on 2024/02/06.
//

#ifndef RAIA_SKIA_SK_SVG_HIDDEN_CONTAINER_H
#define RAIA_SKIA_SK_SVG_HIDDEN_CONTAINER_H

#include "modules/svg/include/SkSVGHiddenContainer.h"
#include "../static/static_sk_svg_node.h"
#include "../static/static_sk_path.h"
#include "../static/static_sk_rect.h"

extern "C" {
void SkSVGHiddenContainer_delete(SkSVGHiddenContainer *svgHiddenContainer);
void SkSVGHiddenContainer_appendChild(SkSVGHiddenContainer *svgHiddenContainer, sk_svg_node_t svg_node);
void SkSVGHiddenContainer_setTransform(SkSVGHiddenContainer *svgHiddenContainer, const SkSVGTransformType *t);
SkSVGTag SkSVGHiddenContainer_tag(SkSVGHiddenContainer *svgHiddenContainer);
void SkSVGHiddenContainer_render(SkSVGHiddenContainer *svgHiddenContainer, const SkSVGRenderContext *svgRenderContext);
bool SkSVGHiddenContainer_asPaint(SkSVGHiddenContainer *svgHiddenContainer, const SkSVGRenderContext *svgRenderContext, SkPaint *paint);
sk_path_t SkSVGHiddenContainer_asPath(SkSVGHiddenContainer *svgHiddenContainer, const SkSVGRenderContext *svgRenderContext);
sk_rect_t SkSVGHiddenContainer_objectBoundingBox(SkSVGHiddenContainer *svgHiddenContainer, const SkSVGRenderContext *svgRenderContext);
void SkSVGHiddenContainer_setAttribute(SkSVGHiddenContainer *svgHiddenContainer, SkSVGAttribute svgAttribute, const SkSVGValue *svgValue);
// bool SkSVGHiddenContainer_setAttribute(SkSVGHiddenContainer *svgHiddenContainer, const char *attributeName, const char *attributeValue);
bool SkSVGHiddenContainer_parseAndSetAttribute(SkSVGHiddenContainer *svgHiddenContainer, const char *name, const char *value);
bool SkSVGHiddenContainer_unique(SkSVGHiddenContainer *svgHiddenContainer);
void SkSVGHiddenContainer_ref(SkSVGHiddenContainer *svgHiddenContainer);
void SkSVGHiddenContainer_unref(SkSVGHiddenContainer *svgHiddenContainer);
}

#endif //RAIA_SKIA_SK_SVG_HIDDEN_CONTAINER_H
