//
// Created by dolphilia on 2024/01/09.
//

#include "sk_open_type_svg_decoder.h"
#include "../static/static_sk_color.h"
extern "C" {

void SkOpenTypeSVGDecoder_delete(SkOpenTypeSVGDecoder *open_type_svg_decoder) {
    delete open_type_svg_decoder;
}

size_t SkOpenTypeSVGDecoder_approximateSize(SkOpenTypeSVGDecoder *open_type_svg_decoder) {
    return open_type_svg_decoder->approximateSize();
}

bool SkOpenTypeSVGDecoder_render(SkOpenTypeSVGDecoder *open_type_svg_decoder, SkCanvas *canvas, int upem, SkGlyphID glyphId, SkColor foregroundColor, sk_color_t color) {
    return open_type_svg_decoder->render(*canvas, upem, glyphId, foregroundColor, static_sk_color_get(color));
}

}