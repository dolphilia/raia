//
// Created by dolphilia on 2024/02/02.
//

#include "sk_svg_attribute_parser.h"

extern "C" {

// SkSVGAttributeParser (const char[])

void SkSVGAttributeParser_delete(SkSVGAttributeParser * svgAttributeParser) {
    delete svgAttributeParser;
}

bool SkSVGAttributeParser_parseInteger(SkSVGAttributeParser * svgAttributeParser, SkSVGIntegerType *svgIntegerType) {
    return svgAttributeParser->parseInteger(svgIntegerType);
}

bool SkSVGAttributeParser_parseViewBox(SkSVGAttributeParser * svgAttributeParser, SkSVGViewBoxType *svgViewBoxType) {
    return svgAttributeParser->parseViewBox(svgViewBoxType);
}

bool SkSVGAttributeParser_parsePreserveAspectRatio(SkSVGAttributeParser * svgAttributeParser, SkSVGPreserveAspectRatio *svgPreserveAspectRatio) {
    return svgAttributeParser->parsePreserveAspectRatio(svgPreserveAspectRatio);
}

void SkSVGAttributeParser_parse(SkSVGAttributeParser * svgAttributeParser, SkSVGIntegerType* v) {
    svgAttributeParser->parse(v);
}

// static
// ParseResult< T > parse (const char *value)
// ParseResult< T > parse (const char *expectedName, const char *name, const char *value)
// ParseResult< PropertyT > parseProperty (const char *expectedName, const char *name, const char *value)

}
