//
// Created by dolphilia on 2024/02/06.
//

#include "sk_svg_paint.h"

extern "C" {

// SkSVGPaint & operator= (const SkSVGPaint &)
// SkSVGPaint & operator= (SkSVGPaint &&)
// bool operator== (const SkSVGPaint &other)
// bool operator!= (const SkSVGPaint &other)

void SkSVGPaint_delete(SkSVGPaint *svgPaint) {
    delete svgPaint;
}

SkSVGPaint *SkSVGPaint_new() {
    return new SkSVGPaint();
}

SkSVGPaint *SkSVGPaint_new_2(SkSVGPaint::Type t) {
    return new SkSVGPaint(t);
}

SkSVGPaint *SkSVGPaint_new_3(SkSVGColor *c) {
    return new SkSVGPaint(*c);
}

SkSVGPaint *SkSVGPaint_new_4(const SkSVGIRI &iri, SkSVGColor *fallback_color) {
    return new SkSVGPaint(iri, *fallback_color);
}

SkSVGPaint *SkSVGPaint_new_5(const SkSVGPaint *svgPaint) {
    return new SkSVGPaint(*svgPaint);
}

SkSVGPaint::Type SkSVGPaint_type (SkSVGPaint *svgPaint) {
    return svgPaint->type();
}

const SkSVGColor * SkSVGPaint_color (SkSVGPaint *svgPaint) {
    return &svgPaint->color();
}

const SkSVGIRI * SkSVGPaint_iri (SkSVGPaint *svgPaint) {
    return &svgPaint->iri();
}

}