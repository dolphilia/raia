//
// Created by dolphilia on 2024/02/06.
//

#include "sk_svg_image.h"
//#include "modules/svg/include/SkSVGImage.h"
#include "../static/static_sk_svg_node.h"
#include "../static/static_sk_path.h"
#include "../static/static_sk_rect.h"
#include "../static/static_sk_image_filter.h"
#include "../static/static_sk_svg_fe_diffuse_lighting.h"

/*
//
// SkSVGImage
//
void SkSVGImage_delete(SkSVGImage *svgImage) {
    delete svg;
}

void SkSVGImage_appendChild(sk_svg_node_t svg_node, SkSVGImage *svgImage) {
    svg->appendChild(static_sk_svg_node_move(svg_node));
}

bool SkSVGImage_onPrepareToRender (SkSVGImage *svgImage, SkSVGRenderContext *svgRenderContext)
void SkSVGImage_onRender (SkSVGImage *svgImage, const SkSVGRenderContext &svgRenderContext)
SkPath SkSVGImage_onAsPath (SkSVGImage *svgImage, const SkSVGRenderContext &svgRenderContext)
SkRect SkSVGImage_onObjectBoundingBox (SkSVGImage *svgImage, const SkSVGRenderContext &svgRenderContext)
void SkSVGImage_setTransform(SkSVGImage *svgImage, const SkSVGTransformType *t) {
    svg->setTransform(*t);
}

SkSVGTag SkSVGImage_tag(SkSVGImage *svgImage) {
    return svg->tag();
}

void SkSVGImage_render(SkSVGImage *svgImage, const SkSVGRenderContext *svgRenderContext) {
    svg->render(*svgRenderContext);
}

bool SkSVGImage_asPaint(SkSVGImage *svgImage, const SkSVGRenderContext *svgRenderContext, SkPaint *paint) {
    return svg->asPaint(*svgRenderContext, paint);
}

sk_path_t SkSVGImage_asPath(SkSVGImage *svgImage, const SkSVGRenderContext *svgRenderContext) {
    return static_sk_path_make(svg->asPath(*svgRenderContext));
}

sk_rect_t SkSVGImage_objectBoundingBox(SkSVGImage *svgImage, const SkSVGRenderContext *svgRenderContext) {
    return static_sk_rect_make(svg->objectBoundingBox(*svgRenderContext));
}

void SkSVGImage_setAttribute(SkSVGImage *svgImage, SkSVGAttribute svgAttribute, const SkSVGValue *svgValue) {
    svg->setAttribute(svgAttribute, *svgValue);
}

// bool SkSVGImage_setAttribute(SkSVGImage *svgImage, const char *attributeName, const char *attributeValue) {
//     svg->
// }

bool SkSVGImage_unique(SkSVGImage *svgImage) {
    return svg->unique();
}

void SkSVGImage_ref(SkSVGImage *svgImage) {
    svg->ref();
}

void SkSVGImage_unref(SkSVGImage *svgImage) {
    svg->unref();
}

// static

sk_sp< SkSVGImage > SkSVGImage_Make() {
    SVG::Make()
}

static ImageInfo SkSVGImage_LoadImage (const sk_sp< skresources::ResourceProvider > &resourceProvider, const SkSVGIRI &svgIri, const SkRect &rect, SkSVGPreserveAspectRatio svgPreserverAspectRatio)

 */