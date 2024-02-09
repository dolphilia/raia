//
// Created by dolphilia on 2024/02/06.
//

#ifndef RAIA_SKIA_SK_SVG_FUNC_IRI_H
#define RAIA_SKIA_SK_SVG_FUNC_IRI_H

#include "modules/svg/include/SkSVGTypes.h"

extern "C" {
// bool operator== (const SkSVGFuncIRI &other)
// bool operator!= (const SkSVGFuncIRI &other)
void SkSVGFuncIRI_delete(SkSVGFuncIRI *svgFuncIri);
SkSVGFuncIRI *SkSVGFuncIRI_new();
SkSVGFuncIRI *SkSVGFuncIRI_new_2(SkSVGFuncIRI::Type t);
//SkSVGFuncIRI *SkSVGFuncIRI_new(SkSVGIRI &&iri);
SkSVGFuncIRI::Type SkSVGFuncIRI_type (SkSVGFuncIRI *svgFuncIri);
const SkSVGIRI * SkSVGFuncIRI_iri (SkSVGFuncIRI *svgFuncIri);
}

#endif //RAIA_SKIA_SK_SVG_FUNC_IRI_H
