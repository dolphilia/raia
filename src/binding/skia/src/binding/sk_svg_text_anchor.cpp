//
// Created by dolphilia on 2024/02/06.
//

#include "sk_svg_text_anchor.h"

extern "C" {

// bool operator== (const SkSVGTextAnchor &other)
// bool operator!= (const SkSVGTextAnchor &other)

void SkSVGTextAnchor_delete(SkSVGTextAnchor *svgTextAnchor) {
    delete svgTextAnchor;
}

SkSVGTextAnchor *SkSVGTextAnchor_new() {
    return new SkSVGTextAnchor();
}

SkSVGTextAnchor *SkSVGTextAnchor_new_2(SkSVGTextAnchor::Type t) {
    return new SkSVGTextAnchor(t);
}

SkSVGTextAnchor::Type SkSVGTextAnchor_type (SkSVGTextAnchor *svgTextAnchor) {
    return svgTextAnchor->type();
}

}