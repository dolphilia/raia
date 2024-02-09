//
// Created by dolphilia on 2024/02/06.
//

#include "sk_svg_iri.h"

extern "C" {

// bool operator== (const SkSVGIRI &other)
// bool operator!= (const SkSVGIRI &other)

void SkSVGIRI_delete(SkSVGIRI *svgIri) {
    delete svgIri;
}

SkSVGIRI *SkSVGIRI_new() {
    return new SkSVGIRI();
}

SkSVGIRI *SkSVGIRI_new_2(SkSVGIRI::Type t, const SkSVGStringType *iri) {
    return new SkSVGIRI(t, *iri);
}

SkSVGIRI::Type SkSVGIRI_type (SkSVGIRI *svgIri) {
    return svgIri->type();
}

const SkSVGStringType * SkSVGIRI_iri (SkSVGIRI *svgIri) {
    return &svgIri->iri();
}

}