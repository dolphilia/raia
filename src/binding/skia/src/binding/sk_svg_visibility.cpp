//
// Created by dolphilia on 2024/02/06.
//

#include "sk_svg_visibility.h"

extern "C" {

// SkSVGVisibility & operator= (const SkSVGVisibility &)
// bool operator== (const SkSVGVisibility &other)
// bool operator!= (const SkSVGVisibility &other)

void SkSVGVisibility_delete(SkSVGVisibility *svgVisibility) {
    delete svgVisibility;
}

SkSVGVisibility *SkSVGVisibility_new() {
    return new SkSVGVisibility();
}

SkSVGVisibility *SkSVGVisibility_new_2(SkSVGVisibility::Type t) {
    return new SkSVGVisibility(t);
}

SkSVGVisibility *SkSVGVisibility_new_3(const SkSVGVisibility *svgVisibility) {
    return new SkSVGVisibility(*svgVisibility);
}

SkSVGVisibility::Type SkSVGVisibility_type (SkSVGVisibility *svgVisibility) {
    return svgVisibility->type();
}

}