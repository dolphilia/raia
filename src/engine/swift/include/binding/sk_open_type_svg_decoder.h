//
// Created by dolphilia on 2024/01/09.
//

#ifndef RAIA_SKIA_SK_OPEN_TYPE_SVG_DECODER_H
#define RAIA_SKIA_SK_OPEN_TYPE_SVG_DECODER_H

#include "include/core/SkOpenTypeSVGDecoder.h"
#include "../static/static_sk_color.h"

extern "C" {
void SkOpenTypeSVGDecoder_delete(SkOpenTypeSVGDecoder *open_type_svg_decoder);
size_t SkOpenTypeSVGDecoder_approximateSize(SkOpenTypeSVGDecoder *open_type_svg_decoder);
bool SkOpenTypeSVGDecoder_render(SkOpenTypeSVGDecoder *open_type_svg_decoder, SkCanvas *canvas, int upem, SkGlyphID glyphId, SkColor foregroundColor, sk_color_t color);
}

#endif //RAIA_SKIA_SK_OPEN_TYPE_SVG_DECODER_H
