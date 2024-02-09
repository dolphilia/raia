//
// Created by dolphilia on 2024/02/06.
//

#include "sk_svg_dom.h"

#include <utility>

#include "modules/svg/include/SkSVGDOM.h"
#include "../static/static_sk_svg_dom.h"

//
// SkSVGDOM
//

//void SkSVGDOM_delete(SkSVGDOM *svgDom) {
//    delete svgDom;
//


SkSVGSVG * SkSVGDOM_getRoot (SkSVGDOM *svgDom) {
    return svgDom->getRoot();
}

//void SkSVGDOM_setContainerSize (SkSVGDOM *svgDom, const SkSize *size) {
//    svgDom->setContainerSize(*size);
//}

//const SkSize * SkSVGDOM_containerSize (SkSVGDOM *svgDom) {
//    return &svgDom->containerSize();
//}

//sk_sp< SkSVGNode > * SkSVGDOM_findNodeById (SkSVGDOM *svgDom, const char *id) {
//    return svgDom->findNodeById(id);
//}

//void SkSVGDOM_render (SkSVGDOM *svgDom, SkCanvas *canvas) {
//    svgDom->render(canvas);
//}


//void SkSVGDOM_renderNode (SkSVGDOM *svgDom, SkCanvas *canvas, SkSVGPresentationContext *svgPresentationContext, const char *id) {
//    svgDom->renderNode(canvas, *svgPresentationContext, id);
//}

bool SkSVGDOM_unique (SkSVGDOM *svgDom) {
    return svgDom->unique();
}

void SkSVGDOM_ref (SkSVGDOM *svgDom) {
    svgDom->ref();
}

void SkSVGDOM_unref (SkSVGDOM *svgDom) {
    svgDom->unique();
}

// static

//int SkSVGDOM_MakeFromStream (SkStream *str) {
//    return static_sk_svg_dom_make(SkSVGDOM::MakeFromStream(*str));
//}

//--

//SkSVGDOM::Builder * SkSVGDOM_Builder_setFontManager (SkSVGDOM::Builder *builder, sk_sp< SkFontMgr > fontMgr) {
//    return &builder->setFontManager(std::move(fontMgr));
//}

//sk_sp< SkSVGDOM > 	SkSVGDOM_Builder_make (SkSVGDOM::Builder *builder, SkStream &stream) {
//    return builder->make(stream);
//}