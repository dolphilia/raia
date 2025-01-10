//
// Created by dolphilia on 2024/02/06.
//

#ifndef RAIA_SKIA_SK_SVG_FE_MORPHOLOGY_H
#define RAIA_SKIA_SK_SVG_FE_MORPHOLOGY_H

#include "modules/svg/include/SkSVGFeMorphology.h"
#include "../static/static_sk_svg_node.h"
#include "../static/static_sk_path.h"
#include "../static/static_sk_rect.h"
#include "../static/static_sk_image_filter.h"
#include "../static/static_sk_svg_fe_morphology.h"

extern "C" {
void SkSVGFeMorphology_delete(SkSVGFeMorphology *svgFeMorphology);
sk_image_filter_t SkSVGFeMorphology_makeImageFilter(SkSVGFeMorphology *svgFeMorphology, const SkSVGRenderContext *ctx, const SkSVGFilterContext *fctx);
sk_rect_t SkSVGFeMorphology_resolveFilterSubregion(SkSVGFeMorphology *svgFeMorphology, const SkSVGRenderContext *svgRenderContext, const SkSVGFilterContext *svgFilterContext);
SkSVGColorspace SkSVGFeMorphology_resolveColorspace(SkSVGFeMorphology *svgFeMorphology, const SkSVGRenderContext *svgRenderContext, const SkSVGFilterContext *svgFilterContext);
void SkSVGFeMorphology_applyProperties(SkSVGFeMorphology *svgFeMorphology, SkSVGRenderContext *svgRenderContext);
void SkSVGFeMorphology_appendChild(SkSVGFeMorphology *svgFeMorphology, sk_svg_node_t svg_node);
void SkSVGFeMorphology_setTransform(SkSVGFeMorphology *svgFeMorphology, const SkSVGTransformType *t);
SkSVGTag SkSVGFeMorphology_tag(SkSVGFeMorphology *svgFeMorphology);
void SkSVGFeMorphology_render(SkSVGFeMorphology *svgFeMorphology, const SkSVGRenderContext *svgRenderContext);
bool SkSVGFeMorphology_asPaint(SkSVGFeMorphology *svgFeMorphology, const SkSVGRenderContext *svgRenderContext, SkPaint *paint);
sk_path_t SkSVGFeMorphology_asPath(SkSVGFeMorphology *svgFeMorphology, const SkSVGRenderContext *svgRenderContext);
sk_rect_t SkSVGFeMorphology_objectBoundingBox(SkSVGFeMorphology *svgFeMorphology, const SkSVGRenderContext *svgRenderContext);
void SkSVGFeMorphology_setAttribute(SkSVGFeMorphology *svgFeMorphology, SkSVGAttribute svgAttribute, const SkSVGValue *svgValue);
// bool SkSVGFeMorphology_setAttribute(SkSVGFeMorphology *svgFeMorphology, const char *attributeName, const char *attributeValue);
bool SkSVGFeMorphology_unique(SkSVGFeMorphology *svgFeMorphology);
void SkSVGFeMorphology_ref(SkSVGFeMorphology *svgFeMorphology);
void SkSVGFeMorphology_unref(SkSVGFeMorphology *svgFeMorphology);
// static
sk_svg_fe_morphology_t SkSVGFeMorphology_Make();
bool SkSVGFeMorphology_IsFilterEffect (const sk_sp< SkSVGNode > *node);
}

#endif //RAIA_SKIA_SK_SVG_FE_MORPHOLOGY_H
