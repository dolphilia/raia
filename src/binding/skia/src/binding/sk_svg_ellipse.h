//
// Created by dolphilia on 2024/02/06.
//

#ifndef RAIA_SKIA_SK_SVG_ELLIPSE_H
#define RAIA_SKIA_SK_SVG_ELLIPSE_H

#include "modules/svg/include/SkSVGEllipse.h"
#include "../static/static_sk_svg_node.h"
#include "../static/static_sk_svg_ellipse.h"
#include "../static/static_sk_path.h"
#include "../static/static_sk_rect.h"

extern "C" {
void SkSVGEllipse_delete(SkSVGEllipse *svgEllipse);
void SkSVGEllipse_appendChild(SkSVGEllipse *svgEllipse, sk_svg_node_t svg_node);
void SkSVGEllipse_setTransform (SkSVGEllipse *svgEllipse, const SkSVGTransformType *t);
SkSVGTag SkSVGEllipse_tag (SkSVGEllipse *svgEllipse);
void SkSVGEllipse_render (SkSVGEllipse *svgEllipse, const SkSVGRenderContext *svgRenderContext);
bool SkSVGEllipse_asPaint (SkSVGEllipse *svgEllipse, const SkSVGRenderContext *svgRenderContext, SkPaint *paint);
sk_path_t SkSVGEllipse_asPath (SkSVGEllipse *svgEllipse, const SkSVGRenderContext *svgRenderContext);
sk_rect_t SkSVGEllipse_objectBoundingBox (SkSVGEllipse *svgEllipse, const SkSVGRenderContext *svgRenderContext);
void SkSVGEllipse_setAttribute (SkSVGEllipse *svgEllipse, SkSVGAttribute svgAttribute, const SkSVGValue *svgValue);
//bool SkSVGEllipse_setAttribute (SkSVGEllipse *svgEllipse, const char *attributeName, const char *attributeValue);
bool SkSVGEllipse_unique (SkSVGEllipse *svgEllipse);
void SkSVGEllipse_ref (SkSVGEllipse *svgEllipse);
void SkSVGEllipse_unref (SkSVGEllipse *svgEllipse);
// static
sk_svg_ellipse_t SkSVGEllipse_Make ();
}

#endif //RAIA_SKIA_SK_SVG_ELLIPSE_H
