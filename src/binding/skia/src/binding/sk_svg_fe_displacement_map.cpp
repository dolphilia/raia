//
// Created by dolphilia on 2024/02/06.
//

#include "sk_svg_fe_displacement_map.h"

extern "C" {

void SkSVGFeDisplacementMap_delete(SkSVGFeDisplacementMap *svgFeDisplacementMap) {
    delete svgFeDisplacementMap;
}

SkSVGColorspace SkSVGFeDisplacementMap_resolveColorspace(SkSVGFeDisplacementMap *svgFeDisplacementMap, const SkSVGRenderContext *svgRenderContext, const SkSVGFilterContext *svgFilterContext) {
    return svgFeDisplacementMap->resolveColorspace(*svgRenderContext, *svgFilterContext);
}

sk_image_filter_t SkSVGFeDisplacementMap_makeImageFilter(SkSVGFeDisplacementMap *svgFeDisplacementMap, const SkSVGRenderContext *ctx, const SkSVGFilterContext *fctx) {
    return static_sk_image_filter_make(svgFeDisplacementMap->makeImageFilter(*ctx, *fctx));
}

sk_rect_t SkSVGFeDisplacementMap_resolveFilterSubregion(SkSVGFeDisplacementMap *svgFeDisplacementMap, const SkSVGRenderContext *svgRenderContext, const SkSVGFilterContext *svgFilterContext) {
    return static_sk_rect_make(svgFeDisplacementMap->resolveFilterSubregion(*svgRenderContext, *svgFilterContext));
}

void SkSVGFeDisplacementMap_applyProperties(SkSVGFeDisplacementMap *svgFeDisplacementMap, SkSVGRenderContext *svgRenderContext) {
    svgFeDisplacementMap->applyProperties(svgRenderContext);
}

void SkSVGFeDisplacementMap_appendChild(SkSVGFeDisplacementMap *svgFeDisplacementMap, sk_svg_node_t svg_node) {
    svgFeDisplacementMap->appendChild(static_sk_svg_node_move(svg_node));
}

void SkSVGFeDisplacementMap_setTransform(SkSVGFeDisplacementMap *svgFeDisplacementMap, const SkSVGTransformType *t) {
    svgFeDisplacementMap->setTransform(*t);
}

SkSVGTag SkSVGFeDisplacementMap_tag(SkSVGFeDisplacementMap *svgFeDisplacementMap) {
    return svgFeDisplacementMap->tag();
}

void SkSVGFeDisplacementMap_render(SkSVGFeDisplacementMap *svgFeDisplacementMap, const SkSVGRenderContext *svgRenderContext) {
    svgFeDisplacementMap->render(*svgRenderContext);
}

bool SkSVGFeDisplacementMap_asPaint(SkSVGFeDisplacementMap *svgFeDisplacementMap, const SkSVGRenderContext *svgRenderContext, SkPaint *paint) {
    return svgFeDisplacementMap->asPaint(*svgRenderContext, paint);
}

sk_path_t SkSVGFeDisplacementMap_asPath(SkSVGFeDisplacementMap *svgFeDisplacementMap, const SkSVGRenderContext *svgRenderContext) {
    return static_sk_path_make(svgFeDisplacementMap->asPath(*svgRenderContext));
}

sk_rect_t SkSVGFeDisplacementMap_objectBoundingBox(SkSVGFeDisplacementMap *svgFeDisplacementMap, const SkSVGRenderContext *svgRenderContext) {
    return static_sk_rect_make(svgFeDisplacementMap->objectBoundingBox(*svgRenderContext));
}

void SkSVGFeDisplacementMap_setAttribute(SkSVGFeDisplacementMap *svgFeDisplacementMap, SkSVGAttribute svgAttribute, const SkSVGValue *svgValue) {
    svgFeDisplacementMap->setAttribute(svgAttribute, *svgValue);
}

//bool SkSVGFeDisplacementMap_setAttribute(SkSVGFeDisplacementMap *svgFeDisplacementMap, const char *attributeName, const char *attributeValue) {
//    svgFeDisplacementMap->
//}

bool SkSVGFeDisplacementMap_unique(SkSVGFeDisplacementMap *svgFeDisplacementMap) {
    return svgFeDisplacementMap->unique();
}

void SkSVGFeDisplacementMap_ref(SkSVGFeDisplacementMap *svgFeDisplacementMap) {
    svgFeDisplacementMap->ref();
}

void SkSVGFeDisplacementMap_unref(SkSVGFeDisplacementMap *svgFeDisplacementMap) {
    svgFeDisplacementMap->unref();
}

// static

sk_svg_fe_displacement_map_t SkSVGFeDisplacementMap_Make() {
    return static_sk_svg_fe_displacement_map_make(SkSVGFeDisplacementMap::Make());
}

bool SkSVGFeDisplacementMap_IsFilterEffect (const sk_sp< SkSVGNode > *node) {
    return SkSVGFeDisplacementMap::IsFilterEffect(*node);
}

}