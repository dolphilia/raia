//
// Created by dolphilia on 2024/02/06.
//

#include "sk_svg_fe_lighting.h"

extern "C" {

void SkSVGFeLightSource_delete(SkSVGFeLightSource *svgFeLightSource) {
    delete svgFeLightSource;
}

void SkSVGFeLightSource_appendChild(SkSVGFeLightSource *svgFeLightSource, sk_svg_node_t svg_node) {
    svgFeLightSource->appendChild(static_sk_svg_node_move(svg_node));
}

void SkSVGFeLightSource_setTransform(SkSVGFeLightSource *svgFeLightSource, const SkSVGTransformType *t) {
    svgFeLightSource->setTransform(*t);
}

SkSVGTag SkSVGFeLightSource_tag(SkSVGFeLightSource *svgFeLightSource) {
    return svgFeLightSource->tag();
}

void SkSVGFeLightSource_render(SkSVGFeLightSource *svgFeLightSource, const SkSVGRenderContext *svgRenderContext) {
    svgFeLightSource->render(*svgRenderContext);
}

bool SkSVGFeLightSource_asPaint(SkSVGFeLightSource *svgFeLightSource, const SkSVGRenderContext *svgRenderContext, SkPaint *paint) {
    return svgFeLightSource->asPaint(*svgRenderContext, paint);
}

sk_path_t SkSVGFeLightSource_asPath(SkSVGFeLightSource *svgFeLightSource, const SkSVGRenderContext *svgRenderContext) {
    return static_sk_path_make(svgFeLightSource->asPath(*svgRenderContext));
}

sk_rect_t SkSVGFeLightSource_objectBoundingBox(SkSVGFeLightSource *svgFeLightSource, const SkSVGRenderContext *svgRenderContext) {
    return static_sk_rect_make(svgFeLightSource->objectBoundingBox(*svgRenderContext));
}

void SkSVGFeLightSource_setAttribute(SkSVGFeLightSource *svgFeLightSource, SkSVGAttribute svgAttribute, const SkSVGValue *svgValue) {
    svgFeLightSource->setAttribute(svgAttribute, *svgValue);
}

// bool SkSVGFeLightSource_setAttribute(SkSVGFeLightSource *svgFeLightSource, const char *attributeName, const char *attributeValue) {
//     svgFeLightSource->
// }

bool SkSVGFeLightSource_parseAndSetAttribute(SkSVGFeLightSource *svgFeLightSource, const char *name, const char *value) {
    return svgFeLightSource->parseAndSetAttribute(name, value);
}

bool SkSVGFeLightSource_unique(SkSVGFeLightSource *svgFeLightSource) {
    return svgFeLightSource->unique();
}

void SkSVGFeLightSource_ref(SkSVGFeLightSource *svgFeLightSource) {
    svgFeLightSource->ref();
}

void SkSVGFeLightSource_unref(SkSVGFeLightSource *svgFeLightSource) {
    svgFeLightSource->unref();
}

}