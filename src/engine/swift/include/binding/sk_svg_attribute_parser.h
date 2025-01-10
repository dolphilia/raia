//
// Created by dolphilia on 2024/02/02.
//

#ifndef RAIA_SKIA_SK_SVG_ATTRIBUTE_PARSER_H
#define RAIA_SKIA_SK_SVG_ATTRIBUTE_PARSER_H

#include "modules/svg/include/SkSVGAttributeParser.h"

extern "C" {
void SkSVGAttributeParser_delete(SkSVGAttributeParser * svgAttributeParser);
bool SkSVGAttributeParser_parseInteger(SkSVGAttributeParser * svgAttributeParser, SkSVGIntegerType *svgIntegerType);
bool SkSVGAttributeParser_parseViewBox(SkSVGAttributeParser * svgAttributeParser, SkSVGViewBoxType *svgViewBoxType);
bool SkSVGAttributeParser_parsePreserveAspectRatio(SkSVGAttributeParser * svgAttributeParser, SkSVGPreserveAspectRatio *svgPreserveAspectRatio);
void SkSVGAttributeParser_parse(SkSVGAttributeParser * svgAttributeParser, SkSVGIntegerType* v);
}

#endif //RAIA_SKIA_SK_SVG_ATTRIBUTE_PARSER_H
