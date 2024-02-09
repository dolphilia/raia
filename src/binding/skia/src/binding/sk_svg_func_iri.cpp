//
// Created by dolphilia on 2024/02/06.
//

#include "sk_svg_func_iri.h"

extern "C" {

// bool operator== (const SkSVGFuncIRI &other)
// bool operator!= (const SkSVGFuncIRI &other)

void SkSVGFuncIRI_delete(SkSVGFuncIRI *svgFuncIri) {
    delete svgFuncIri;
}

SkSVGFuncIRI *SkSVGFuncIRI_new() {
    return new SkSVGFuncIRI();
}

SkSVGFuncIRI *SkSVGFuncIRI_new_2(SkSVGFuncIRI::Type t) {
    return new SkSVGFuncIRI(t);
}

//SkSVGFuncIRI *SkSVGFuncIRI_new(SkSVGIRI &&iri) {
//    return new SkSVGFuncIRI(iri);
//}

SkSVGFuncIRI::Type SkSVGFuncIRI_type (SkSVGFuncIRI *svgFuncIri) {
    return svgFuncIri->type();
}

const SkSVGIRI * SkSVGFuncIRI_iri (SkSVGFuncIRI *svgFuncIri) {
    return &svgFuncIri->iri();
}

}