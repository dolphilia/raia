//
// Created by dolphilia on 2024/02/06.
//

#include "sk_svg_line_join.h"

extern "C" {

// SkSVGLineJoin & operator= (const SkSVGLineJoin &)
// bool operator== (const SkSVGLineJoin &other)
// bool operator!= (const SkSVGLineJoin &other)

void SkSVGLineJoin_delete(SkSVGLineJoin *svgLineJoin) {
    delete svgLineJoin;
}

SkSVGLineJoin *SkSVGLineJoin_new() {
    return new SkSVGLineJoin();
}

SkSVGLineJoin *SkSVGLineJoin_new_2(SkSVGLineJoin::Type t) {
    return new SkSVGLineJoin(t);
}

SkSVGLineJoin *SkSVGLineJoin_new_3(const SkSVGLineJoin &svgLineJoin) {
    return new SkSVGLineJoin(svgLineJoin);
}

SkSVGLineJoin::Type SkSVGLineJoin_type (SkSVGLineJoin *svgLineJoin) {
    return svgLineJoin->type();
}

}