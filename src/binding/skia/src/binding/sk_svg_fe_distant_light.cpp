//
// Created by dolphilia on 2024/02/06.
//

#include "sk_svg_fe_distant_light.h"

extern "C" {

void SkSVGFeDistantLight_delete(SkSVGFeDistantLight *svgFeDistantLight) {
    delete svgFeDistantLight;
}

SkPoint3 SkSVGFeDistantLight_computeDirection (SkSVGFeDistantLight *svgFeDistantLight) {
    return svgFeDistantLight->computeDirection();
}

void SkSVGFeDistantLight_azppendChild(SkSVGFeDistantLight *svgFeDistantLight, sk_svg_node_t svg_node) {
    svgFeDistantLight->appendChild(static_sk_svg_node_move(svg_node));
}

void SkSVGFeDistantLight_setTransform(SkSVGFeDistantLight *svgFeDistantLight, const SkSVGTransformType *t) {
    svgFeDistantLight->setTransform(*t);
}

SkSVGTag SkSVGFeDistantLight_tag(SkSVGFeDistantLight *svgFeDistantLight) {
    return svgFeDistantLight->tag();
}

void SkSVGFeDistantLight_render(SkSVGFeDistantLight *svgFeDistantLight, const SkSVGRenderContext *svgRenderContext) {
    svgFeDistantLight->render(*svgRenderContext);
}

bool SkSVGFeDistantLight_asPaint(SkSVGFeDistantLight *svgFeDistantLight, const SkSVGRenderContext *svgRenderContext, SkPaint *paint) {
    return svgFeDistantLight->asPaint(*svgRenderContext, paint);
}

sk_path_t SkSVGFeDistantLight_asPath(SkSVGFeDistantLight *svgFeDistantLight, const SkSVGRenderContext *svgRenderContext) {
    return static_sk_path_make(svgFeDistantLight->asPath(*svgRenderContext));
}

sk_rect_t SkSVGFeDistantLight_objectBoundingBox(SkSVGFeDistantLight *svgFeDistantLight, const SkSVGRenderContext *svgRenderContext) {
    return static_sk_rect_make(svgFeDistantLight->objectBoundingBox(*svgRenderContext));
}

void SkSVGFeDistantLight_setAttribute(SkSVGFeDistantLight *svgFeDistantLight, SkSVGAttribute svgAttribute, const SkSVGValue *svgValue) {
    svgFeDistantLight->setAttribute(svgAttribute, *svgValue);
}

//bool SkSVGFeDistantLight_setAttribute(SkSVGFeDistantLight *svgFeDistantLight, const char *attributeName, const char *attributeValue) {
//    svgFeDistantLight->
//}

bool SkSVGFeDistantLight_unique(SkSVGFeDistantLight *svgFeDistantLight) {
    return svgFeDistantLight->unique();
}

void SkSVGFeDistantLight_ref(SkSVGFeDistantLight *svgFeDistantLight) {
    svgFeDistantLight->ref();
}

void SkSVGFeDistantLight_unref(SkSVGFeDistantLight *svgFeDistantLight) {
    svgFeDistantLight->unref();
}

// static

sk_svg_fe_distant_light_t SkSVGFeDistantLight_Make() {
    return static_sk_svg_fe_distant_light_make(SkSVGFeDistantLight::Make());
}

}