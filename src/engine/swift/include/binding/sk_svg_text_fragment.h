//
// Created by dolphilia on 2024/02/06.
//

#ifndef RAIA_SKIA_SK_SVG_TEXT_FRAGMENT_H
#define RAIA_SKIA_SK_SVG_TEXT_FRAGMENT_H

#include "modules/svg/include/SkSVGText.h"
#include "../static/static_sk_svg_node.h"
#include "../static/static_sk_path.h"
#include "../static/static_sk_rect.h"

extern "C" {
void SkSVGTextFragment_delete(SkSVGTextFragment *svgTextFragment);
void SkSVGTextFragment_renderText(SkSVGTextFragment *svgTextFragment, const SkSVGRenderContext &svgRenderContext, SkSVGTextContext *svgTextContext, SkSVGXmlSpace svgXmlSpace);
void SkSVGTextFragment_setTransform(SkSVGTextFragment *svgTextFragment, const SkSVGTransformType *t);
SkSVGTag SkSVGTextFragment_tag(SkSVGTextFragment *svgTextFragment);
void SkSVGTextFragment_appendChild(SkSVGTextFragment *svgTextFragment, sk_svg_node_t svg_node);
void SkSVGTextFragment_render(SkSVGTextFragment *svgTextFragment, const SkSVGRenderContext *svgRenderContext);
bool SkSVGTextFragment_asPaint(SkSVGTextFragment *svgTextFragment, const SkSVGRenderContext *svgRenderContext, SkPaint *paint);
sk_path_t SkSVGTextFragment_asPath(SkSVGTextFragment *svgTextFragment, const SkSVGRenderContext *svgRenderContext);
sk_rect_t SkSVGTextFragment_objectBoundingBox(SkSVGTextFragment *svgTextFragment, const SkSVGRenderContext *svgRenderContext);
void SkSVGTextFragment_setAttribute(SkSVGTextFragment *svgTextFragment, SkSVGAttribute svgAttribute, const SkSVGValue *svgValue);
// bool SkSVGTextFragment_setAttribute(SkSVGTextFragment *svgTextFragment, const char *attributeName, const char *attributeValue);
bool SkSVGTextFragment_parseAndSetAttribute(SkSVGTextFragment *svgTextFragment, const char *name, const char *value);
bool SkSVGTextFragment_unique(SkSVGTextFragment *svgTextFragment);
void SkSVGTextFragment_ref(SkSVGTextFragment *svgTextFragment);
void SkSVGTextFragment_unref(SkSVGTextFragment *svgTextFragment);
}

#endif //RAIA_SKIA_SK_SVG_TEXT_FRAGMENT_H
