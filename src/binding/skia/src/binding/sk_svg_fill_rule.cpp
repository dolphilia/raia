//
// Created by dolphilia on 2024/02/06.
//

#include "sk_svg_fill_rule.h"

extern "C" {

// SkSVGFillRule & operator= (const SkSVGFillRule &)
// bool operator== (const SkSVGFillRule &other)
// bool operator!= (const SkSVGFillRule &other)

void SkSVGFillRule_delete(SkSVGFillRule *svgFillRule) {
    delete svgFillRule;
}

SkSVGFillRule *SkSVGFillRule_new() {
    return new SkSVGFillRule();
}

SkSVGFillRule *SkSVGFillRule_new_2(SkSVGFillRule::Type t) {
    return new SkSVGFillRule(t);
}

SkSVGFillRule *SkSVGFillRule_new_3(const SkSVGFillRule *svgFillRule) {
    return new SkSVGFillRule(*svgFillRule);
}

SkSVGFillRule::Type SkSVGFillRule_type (SkSVGFillRule *svgFillRule) {
    return svgFillRule->type();
}

SkPathFillType SkSVGFillRule_asFillType (SkSVGFillRule *svgFillRule) {
    return svgFillRule->asFillType();
}

}