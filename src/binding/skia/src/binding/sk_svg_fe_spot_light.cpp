//
// Created by dolphilia on 2024/02/06.
//

#include "sk_svg_fe_spot_light.h"

extern "C" {

void SkSVGFeSpotLight_delete(SkSVGFeSpotLight *svgFeSpotLight) {
    delete svgFeSpotLight;
}

void SkSVGFeSpotLight_appendChild(SkSVGFeSpotLight *svgFeSpotLight, sk_svg_node_t svg_node) {
    svgFeSpotLight->appendChild(static_sk_svg_node_move(svg_node));
}

void SkSVGFeSpotLight_setTransform(SkSVGFeSpotLight *svgFeSpotLight, const SkSVGTransformType *t) {
    svgFeSpotLight->setTransform(*t);
}

SkSVGTag SkSVGFeSpotLight_tag(SkSVGFeSpotLight *svgFeSpotLight) {
    return svgFeSpotLight->tag();
}

void SkSVGFeSpotLight_render(SkSVGFeSpotLight *svgFeSpotLight, const SkSVGRenderContext *svgRenderContext) {
    svgFeSpotLight->render(*svgRenderContext);
}

bool SkSVGFeSpotLight_asPaint(SkSVGFeSpotLight *svgFeSpotLight, const SkSVGRenderContext *svgRenderContext, SkPaint *paint) {
    return svgFeSpotLight->asPaint(*svgRenderContext, paint);
}

sk_path_t SkSVGFeSpotLight_asPath(SkSVGFeSpotLight *svgFeSpotLight, const SkSVGRenderContext *svgRenderContext) {
    return static_sk_path_make(svgFeSpotLight->asPath(*svgRenderContext));
}

sk_rect_t SkSVGFeSpotLight_objectBoundingBox(SkSVGFeSpotLight *svgFeSpotLight, const SkSVGRenderContext *svgRenderContext) {
    return static_sk_rect_make(svgFeSpotLight->objectBoundingBox(*svgRenderContext));
}

void SkSVGFeSpotLight_setAttribute(SkSVGFeSpotLight *svgFeSpotLight, SkSVGAttribute svgAttribute, const SkSVGValue *svgValue) {
    svgFeSpotLight->setAttribute(svgAttribute, *svgValue);
}

// bool SkSVGFeSpotLight_setAttribute(SkSVGFeSpotLight *svgFeSpotLight, const char *attributeName, const char *attributeValue) {
//     svgFeSpotLight->
// }

bool SkSVGFeSpotLight_unique(SkSVGFeSpotLight *svgFeSpotLight) {
    return svgFeSpotLight->unique();
}

void SkSVGFeSpotLight_ref(SkSVGFeSpotLight *svgFeSpotLight) {
    svgFeSpotLight->ref();
}

void SkSVGFeSpotLight_unref(SkSVGFeSpotLight *svgFeSpotLight) {
    svgFeSpotLight->unref();
}

// static

sk_svg_fe_spot_light_t SkSVGFeSpotLight_Make() {
    return static_sk_svg_fe_spot_light_make(SkSVGFeSpotLight::Make());
}

}