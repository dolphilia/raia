//
// Created by dolphilia on 2024/02/06.
//

#ifndef RAIA_SKIA_SK_SVG_IRI_H
#define RAIA_SKIA_SK_SVG_IRI_H

#include "modules/svg/include/SkSVGTypes.h"

extern "C" {
// bool operator== (const SkSVGIRI &other)
// bool operator!= (const SkSVGIRI &other)
void SkSVGIRI_delete(SkSVGIRI *svgIri);
SkSVGIRI *SkSVGIRI_new();
SkSVGIRI *SkSVGIRI_new_2(SkSVGIRI::Type t, const SkSVGStringType *iri);
SkSVGIRI::Type SkSVGIRI_type (SkSVGIRI *svgIri);
const SkSVGStringType * SkSVGIRI_iri (SkSVGIRI *svgIri);
}

#endif //RAIA_SKIA_SK_SVG_IRI_H
