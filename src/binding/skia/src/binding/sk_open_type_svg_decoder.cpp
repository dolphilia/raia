//
// Created by dolphilia on 2024/01/09.
//

#include "sk_open_type_svg_decoder.h"

extern "C" {

void SkOpenTypeSVGDecoder_delete(SkOpenTypeSVGDecoder *open_type_svg_decoder) {
    delete open_type_svg_decoder;
}

size_t SkOpenTypeSVGDecoder_approximateSize(SkOpenTypeSVGDecoder *open_type_svg_decoder) {
    return open_type_svg_decoder->approximateSize();
}

bool SkOpenTypeSVGDecoder_render(SkOpenTypeSVGDecoder *open_type_svg_decoder, SkCanvas &canvas, int upem, SkGlyphID glyphId, SkColor foregroundColor, SkSpan<SkColor> palette) {
    return open_type_svg_decoder->render(canvas, upem, glyphId, foregroundColor, palette);
}

}