//
// Created by dolphilia on 2024/02/06.
//

#include "sk_svg_fe_point_light.h"

extern "C" {

void SkSVGFePointLight_delete(SkSVGFePointLight *svgFePointLight) {
    delete svgFePointLight;
}

void SkSVGFePointLight_appendChild(SkSVGFePointLight *svgFePointLight, sk_svg_node_t svg_node) {
    svgFePointLight->appendChild(static_sk_svg_node_move(svg_node));
}

void SkSVGFePointLight_setTransform(SkSVGFePointLight *svgFePointLight, const SkSVGTransformType *t) {
    svgFePointLight->setTransform(*t);
}

SkSVGTag SkSVGFePointLight_tag(SkSVGFePointLight *svgFePointLight) {
    return svgFePointLight->tag();
}

void SkSVGFePointLight_render(SkSVGFePointLight *svgFePointLight, const SkSVGRenderContext *svgRenderContext) {
    svgFePointLight->render(*svgRenderContext);
}

bool SkSVGFePointLight_asPaint(SkSVGFePointLight *svgFePointLight, const SkSVGRenderContext *svgRenderContext, SkPaint *paint) {
    return svgFePointLight->asPaint(*svgRenderContext, paint);
}

sk_path_t SkSVGFePointLight_asPath(SkSVGFePointLight *svgFePointLight, const SkSVGRenderContext *svgRenderContext) {
    return static_sk_path_make(svgFePointLight->asPath(*svgRenderContext));
}

sk_rect_t SkSVGFePointLight_objectBoundingBox(SkSVGFePointLight *svgFePointLight, const SkSVGRenderContext *svgRenderContext) {
    return static_sk_rect_make(svgFePointLight->objectBoundingBox(*svgRenderContext));
}

void SkSVGFePointLight_setAttribute(SkSVGFePointLight *svgFePointLight, SkSVGAttribute svgAttribute, const SkSVGValue *svgValue) {
    svgFePointLight->setAttribute(svgAttribute, *svgValue);
}

// bool SkSVGFePointLight_setAttribute(SkSVGFePointLight *svgFePointLight, const char *attributeName, const char *attributeValue) {
//     svgFePointLight->
// }

bool SkSVGFePointLight_unique(SkSVGFePointLight *svgFePointLight) {
    return svgFePointLight->unique();
}

void SkSVGFePointLight_ref(SkSVGFePointLight *svgFePointLight) {
    svgFePointLight->ref();
}

void SkSVGFePointLight_unref(SkSVGFePointLight *svgFePointLight) {
    svgFePointLight->unref();
}

// static

sk_svg_fe_point_light_t SkSVGFePointLight_Make() {
    return static_sk_svg_fe_point_light_make(SkSVGFePointLight::Make());
}

}