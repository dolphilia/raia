//
// Created by dolphilia on 2024/02/04.
//

#ifndef RAIA_SKIA_SK_SVG_CLIP_PATH_H
#define RAIA_SKIA_SK_SVG_CLIP_PATH_H

#include "modules/svg/include/SkSVGClipPath.h"
#include "../static/static_sk_svg_node.h"
#include "../static/static_sk_path.h"
#include "../static/static_sk_rect.h"
#include "../static/static_sk_svg_clip_path.h"

extern "C" {
void SkSVGClipPath_delete(SkSVGClipPath *svgClipPath);
//SVG_ATTR(ClipPathUnits, SkSVGObjectBoundingBoxUnits, SkSVGObjectBoundingBoxUnits(SkSVGObjectBoundingBoxUnits::Type::kUserSpaceOnUse)) private SkSVGClipPath ()
//bool SkSVGClipPath_parseAndSetAttribute(SkSVGClipPath *svgClipPath, const char *str1, const char *str2);
//SkPath SkSVGClipPath_resolveClip(SkSVGClipPath *svgClipPath, const SkSVGRenderContext &svgRenderContext);
void SkSVGClipPath_appendChild(SkSVGClipPath *svgClipPath, sk_svg_node_t svg_node);
void SkSVGClipPath_setTransform(SkSVGClipPath *svgClipPath, const SkSVGTransformType &t);
SkSVGTag SkSVGClipPath_tag(SkSVGClipPath *svgClipPath);
void SkSVGClipPath_render(SkSVGClipPath *svgClipPath, const SkSVGRenderContext &svgRenderContext);
bool SkSVGClipPath_asPaint(SkSVGClipPath *svgClipPath, const SkSVGRenderContext &svgRenderContext, SkPaint *paint);
sk_path_t SkSVGClipPath_asPath(SkSVGClipPath *svgClipPath, const SkSVGRenderContext &svgRenderContext);
sk_rect_t SkSVGClipPath_objectBoundingBox(SkSVGClipPath *svgClipPath, const SkSVGRenderContext &svgRenderContext);
void SkSVGClipPath_setAttribute(SkSVGClipPath *svgClipPath, SkSVGAttribute svgAttribute, const SkSVGValue &svgValue);
bool SkSVGClipPath_setAttribute_2(SkSVGClipPath *svgClipPath, const char *attributeName, const char *attributeValue);
bool SkSVGClipPath_unique(SkSVGClipPath *svgClipPath);
void SkSVGClipPath_ref(SkSVGClipPath *svgClipPath);
void SkSVGClipPath_unref(SkSVGClipPath *svgClipPath);
// static
sk_svg_clip_path_t SkSVGClipPath_Make();
}

#endif //RAIA_SKIA_SK_SVG_CLIP_PATH_H
