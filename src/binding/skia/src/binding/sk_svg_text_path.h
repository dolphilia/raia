//
// Created by dolphilia on 2024/02/06.
//

#ifndef RAIA_SKIA_SK_SVG_TEXT_PATH_H
#define RAIA_SKIA_SK_SVG_TEXT_PATH_H

#include "modules/svg/include/SkSVGText.h"
#include "../static/static_sk_svg_node.h"
#include "../static/static_sk_path.h"
#include "../static/static_sk_rect.h"
#include "../static/static_sk_svg_text_path.h"

extern "C" {
void SkSVGTextPath_delete(SkSVGTextPath *svgTextPath);
void SkSVGTextPath_appendChild(SkSVGTextPath *svgTextPath, sk_svg_node_t svg_node);
void SkSVGTextPath_renderText(SkSVGTextPath *svgTextPath, const SkSVGRenderContext &svgRenderContext, SkSVGTextContext *svgTextContext, SkSVGXmlSpace svgXmlSpace);
void SkSVGTextPath_setTransform(SkSVGTextPath *svgTextPath, const SkSVGTransformType *t);
SkSVGTag SkSVGTextPath_tag(SkSVGTextPath *svgTextPath);
void SkSVGTextPath_render(SkSVGTextPath *svgTextPath, const SkSVGRenderContext *svgRenderContext);
bool SkSVGTextPath_asPaint(SkSVGTextPath *svgTextPath, const SkSVGRenderContext *svgRenderContext, SkPaint *paint);
sk_path_t SkSVGTextPath_asPath(SkSVGTextPath *svgTextPath, const SkSVGRenderContext *svgRenderContext);
sk_rect_t SkSVGTextPath_objectBoundingBox(SkSVGTextPath *svgTextPath, const SkSVGRenderContext *svgRenderContext);
void SkSVGTextPath_setAttribute(SkSVGTextPath *svgTextPath, SkSVGAttribute svgAttribute, const SkSVGValue *svgValue);
// bool SkSVGTextPath_setAttribute(SkSVGTextPath *svgTextPath, const char *attributeName, const char *attributeValue);
bool SkSVGTextPath_unique(SkSVGTextPath *svgTextPath);
void SkSVGTextPath_ref(SkSVGTextPath *svgTextPath);
void SkSVGTextPath_unref(SkSVGTextPath *svgTextPath);
// static
sk_svg_text_path_t SkSVGTextPath_Make();
}

#endif //RAIA_SKIA_SK_SVG_TEXT_PATH_H
