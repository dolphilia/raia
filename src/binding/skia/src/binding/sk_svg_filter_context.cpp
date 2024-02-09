//
// Created by dolphilia on 2024/02/06.
//

#include "sk_svg_filter_context.h"
//#include "modules/svg/include/SkSVGFilterContext.h"
#include "../static/static_sk_svg_node.h"
#include "../static/static_sk_path.h"
#include "../static/static_sk_rect.h"
#include "../static/static_sk_image_filter.h"
#include "../static/static_sk_svg_fe_diffuse_lighting.h"

/*
//
// SkSVGFilterContext
//
void SkSVGFilterContext_delete(SkSVGFilterContext *svgFilterContext) {
    delete svg;
}

SkSVGFilterContext_new(const SkRect &filterEffectsRegion, const SkSVGObjectBoundingBoxUnits &primitiveUnits)
const SkRect & SkSVGFilterContext_filterEffectsRegion (SkSVGFilterContext *svgFilterContext)
const SkRect & SkSVGFilterContext_filterPrimitiveSubregion (SkSVGFilterContext *svgFilterContext, const SkSVGFeInputType &svgFeInputType)
const SkSVGObjectBoundingBoxUnits & SkSVGFilterContext_primitiveUnits (SkSVGFilterContext *svgFilterContext)
void SkSVGFilterContext_registerResult (SkSVGFilterContext *svgFilterContext, const SkSVGStringType &svgStringType, const sk_sp< SkImageFilter > &imageFilter, const SkRect &rect, SkSVGColorspace svgColorspace)
void SkSVGFilterContext_setPreviousResult (SkSVGFilterContext *svgFilterContext, const sk_sp< SkImageFilter > &imageFIlter, const SkRect &rect, SkSVGColorspace)
bool SkSVGFilterContext_previousResultIsSourceGraphic (SkSVGFilterContext *svgFilterContext)
SkSVGColorspace SkSVGFilterContext_resolveInputColorspace (SkSVGFilterContext *svgFilterContext, const SkSVGRenderContext &svgRenderContext, const SkSVGFeInputType &svgFeInputType)
sk_sp< SkImageFilter > SkSVGFilterContext_resolveInput (SkSVGFilterContext *svgFilterContext, const SkSVGRenderContext &svgRenderContext, const SkSVGFeInputType &svgFeInputType)
sk_sp< SkImageFilter > SkSVGFilterContext_resolveInput (SkSVGFilterContext *svgFilterContext, const SkSVGRenderContext &svgRenderContext, const SkSVGFeInputType &svgFeInputType, SkSVGColorspace svgColorspace)

*/