//
// Created by dolphilia on 2024/02/06.
//

#include "sk_svg_filter.h"
//#include "modules/svg/include/SkSVGFilter.h"
#include "../static/static_sk_svg_node.h"
#include "../static/static_sk_path.h"
#include "../static/static_sk_rect.h"
#include "../static/static_sk_image_filter.h"
#include "../static/static_sk_svg_fe_diffuse_lighting.h"

/*
//
// SkSVGFilter
//
void SkSVGFilter_delete(SkSVGFilter *svgFilter) {
    delete svg;
}

sk_sp< SkImageFilter > SkSVGFilter_buildFilterDAG (SkSVGFilter *svgFilter, const SkSVGRenderContext &svgRenderContext)
SVG_ATTR (FilterUnits, SkSVGObjectBoundingBoxUnits, SkSVGObjectBoundingBoxUnits(SkSVGObjectBoundingBoxUnits::Type::kObjectBoundingBox)) SVG_ATTR(PrimitiveUnits
SkSVGObjectBoundingBoxUnits (SkSVGFilter *svgFilter, SkSVGObjectBoundingBoxUnits::Type::kUserSpaceOnUse))
bool SkSVGFilter_parseAndSetAttribute(SkSVGFilter *svgFilter, const char *, const char *) {
    return svg->parseAndSetAttribute(name, value);
}

void SkSVGFilter_appendChild(sk_svg_node_t svg_node, SkSVGFilter *svgFilter) {
    svg->appendChild(static_sk_svg_node_move(svg_node));
}

void SkSVGFilter_setTransform(SkSVGFilter *svgFilter, const SkSVGTransformType *t) {
    svg->setTransform(*t);
}

SkSVGTag SkSVGFilter_tag(SkSVGFilter *svgFilter) {
    return svg->tag();
}

void SkSVGFilter_render(SkSVGFilter *svgFilter, const SkSVGRenderContext *svgRenderContext) {
    svg->render(*svgRenderContext);
}

bool SkSVGFilter_asPaint(SkSVGFilter *svgFilter, const SkSVGRenderContext *svgRenderContext, SkPaint *paint) {
    return svg->asPaint(*svgRenderContext, paint);
}

sk_path_t SkSVGFilter_asPath(SkSVGFilter *svgFilter, const SkSVGRenderContext *svgRenderContext) {
    return static_sk_path_make(svg->asPath(*svgRenderContext));
}

sk_rect_t SkSVGFilter_objectBoundingBox(SkSVGFilter *svgFilter, const SkSVGRenderContext *svgRenderContext) {
    return static_sk_rect_make(svg->objectBoundingBox(*svgRenderContext));
}

void SkSVGFilter_setAttribute(SkSVGFilter *svgFilter, SkSVGAttribute svgAttribute, const SkSVGValue *svgValue) {
    svg->setAttribute(svgAttribute, *svgValue);
}

// bool SkSVGFilter_setAttribute(SkSVGFilter *svgFilter, const char *attributeName, const char *attributeValue) {
//     svg->
// }

bool SkSVGFilter_unique(SkSVGFilter *svgFilter) {
    return svg->unique();
}

void SkSVGFilter_ref(SkSVGFilter *svgFilter) {
    svg->ref();
}

void SkSVGFilter_unref(SkSVGFilter *svgFilter) {
    svg->unref();
}

// static

sk_sp< SkSVGFilter > SkSVGFilter_Make() {
    SVG::Make()
}
*/