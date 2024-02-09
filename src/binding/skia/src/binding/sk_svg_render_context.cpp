//
// Created by dolphilia on 2024/02/06.
//

#include "sk_svg_render_context.h"
//#include "modules/svg/include/SkSVGRenderContext.h"
#include "../static/static_sk_svg_node.h"
#include "../static/static_sk_path.h"
#include "../static/static_sk_rect.h"
#include "../static/static_sk_image_filter.h"
#include "../static/static_sk_svg_fe_diffuse_lighting.h"
/*
//
// SkSVGRenderContext
//
void SkSVGRenderContext_delete(SkSVGRenderContext *svgRenderContext) {
    delete svg;
}

SkSVGRenderContext_new(SkCanvas *, const sk_sp< SkFontMgr > &fontMgr, const sk_sp< skresources::ResourceProvider > &resourceProvider, const SkSVGIDMapper &svgIDMapper, const SkSVGLengthContext &svgLengthContext, const SkSVGPresentationContext &svgPresentationContext, const OBBScope &obbScope)
SkSVGRenderContext_new(const SkSVGRenderContext &svgRenderContext)
SkSVGRenderContext_new(const SkSVGRenderContext &svgRenderContext, SkCanvas *)
SkSVGRenderContext_new(const SkSVGRenderContext &svgRenderContext, const SkSVGNode *)
const SkSVGLengthContext & SkSVGRenderContext_lengthContext (SkSVGRenderContext *svgRenderContext)
SkSVGLengthContext * SkSVGRenderContext_writableLengthContext (SkSVGRenderContext *svgRenderContext)
const SkSVGPresentationContext & SkSVGRenderContext_presentationContext (SkSVGRenderContext *svgRenderContext)
SkCanvas * SkSVGRenderContext_canvas (SkSVGRenderContext *svgRenderContext)
void SkSVGRenderContext_saveOnce (SkSVGRenderContext *svgRenderContext)
void SkSVGRenderContext_applyPresentationAttributes (SkSVGRenderContext *svgRenderContext, const SkSVGPresentationAttributes &svgPresentationAttribute, uint32_t flags)
BorrowedNode SkSVGRenderContext_findNodeById (SkSVGRenderContext *svgRenderContext, const SkSVGIRI &svgIri)
SkTLazy< SkPaint > SkSVGRenderContext_fillPaint (SkSVGRenderContext *svgRenderContext)
SkTLazy< SkPaint > SkSVGRenderContext_strokePaint (SkSVGRenderContext *svgRenderContext)
SkSVGColorType SkSVGRenderContext_resolveSvgColor (SkSVGRenderContext *svgRenderContext, const SkSVGColor &svgColor)
const SkPath * SkSVGRenderContext_clipPath (SkSVGRenderContext *svgRenderContext)
const sk_sp< skresources::ResourceProvider > & SkSVGRenderContext_resourceProvider (SkSVGRenderContext *svgRenderContext)
sk_sp< SkFontMgr > SkSVGRenderContext_fontMgr (SkSVGRenderContext *svgRenderContext)
OBBTransform SkSVGRenderContext_transformForCurrentOBB (SkSVGRenderContext *svgRenderContext, SkSVGObjectBoundingBoxUnits)
SkRect SkSVGRenderContext_resolveOBBRect (SkSVGRenderContext *svgRenderContext, const SkSVGLength &x, const SkSVGLength &y, const SkSVGLength &w, const SkSVGLength &h, SkSVGObjectBoundingBoxUnits)

 */