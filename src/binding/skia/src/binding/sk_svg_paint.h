//
// Created by dolphilia on 2024/02/06.
//

#ifndef RAIA_SKIA_SK_SVG_PAINT_H
#define RAIA_SKIA_SK_SVG_PAINT_H

#include "modules/svg/include/SkSVGTypes.h"

extern "C" {
// SkSVGPaint & operator= (const SkSVGPaint &)
// SkSVGPaint & operator= (SkSVGPaint &&)
// bool operator== (const SkSVGPaint &other)
// bool operator!= (const SkSVGPaint &other)
void SkSVGPaint_delete(SkSVGPaint *svgPaint);
SkSVGPaint *SkSVGPaint_new();
SkSVGPaint *SkSVGPaint_new_2(SkSVGPaint::Type t);
SkSVGPaint *SkSVGPaint_new_3(SkSVGColor *c);
SkSVGPaint *SkSVGPaint_new_4(const SkSVGIRI &iri, SkSVGColor *fallback_color);
SkSVGPaint *SkSVGPaint_new_5(const SkSVGPaint *svgPaint);
SkSVGPaint::Type SkSVGPaint_type (SkSVGPaint *svgPaint);
const SkSVGColor * SkSVGPaint_color (SkSVGPaint *svgPaint);
const SkSVGIRI * SkSVGPaint_iri (SkSVGPaint *svgPaint);
}

#endif //RAIA_SKIA_SK_SVG_PAINT_H
