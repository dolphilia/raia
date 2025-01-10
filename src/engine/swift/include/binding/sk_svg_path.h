//
// Created by dolphilia on 2024/02/06.
//

#ifndef RAIA_SKIA_SK_SVG_PATH_H
#define RAIA_SKIA_SK_SVG_PATH_H

#include "modules/svg/include/SkSVGPath.h"
#include "../static/static_sk_svg_node.h"
#include "../static/static_sk_path.h"
#include "../static/static_sk_rect.h"
#include "../static/static_sk_svg_path.h"

extern "C" {
void SkSVGPath_delete(SkSVGPath *svgPath);
void SkSVGPath_appendChild(SkSVGPath *svgPath, sk_svg_node_t svg_node);
void SkSVGPath_setTransform(SkSVGPath *svgPath, const SkSVGTransformType *t);
SkSVGTag SkSVGPath_tag(SkSVGPath *svgPath);
void SkSVGPath_render(SkSVGPath *svgPath, const SkSVGRenderContext *svgRenderContext);
bool SkSVGPath_asPaint(SkSVGPath *svgPath, const SkSVGRenderContext *svgRenderContext, SkPaint *paint);
sk_path_t SkSVGPath_asPath(SkSVGPath *svgPath, const SkSVGRenderContext *svgRenderContext);
sk_rect_t SkSVGPath_objectBoundingBox(SkSVGPath *svgPath, const SkSVGRenderContext *svgRenderContext);
void SkSVGPath_setAttribute(SkSVGPath *svgPath, SkSVGAttribute svgAttribute, const SkSVGValue *svgValue);
// bool SkSVGPath_setAttribute(SkSVGPath *svgPath, const char *attributeName, const char *attributeValue);
bool SkSVGPath_unique(SkSVGPath *svgPath);
void SkSVGPath_ref(SkSVGPath *svgPath);
void SkSVGPath_unref(SkSVGPath *svgPath);
// static
sk_svg_path_t SkSVGPath_Make();
}

#endif //RAIA_SKIA_SK_SVG_PATH_H
