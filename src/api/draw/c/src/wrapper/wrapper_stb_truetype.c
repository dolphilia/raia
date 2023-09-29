//
// Created by dolphilia on 2023/04/08.
//

#include "wrapper_stb_truetype.h"

raia_font_t init_font(uint8_t *font_buf, const char *font_path, int font_size) {
    FILE *font_file;
#ifdef __WINDOWS__
    fopen_s(&font_file, font_path, "rb");
#else
    font_file = fopen(font_path, "rb");
#endif
    if ((font_file) == NULL) {
        fprintf(stderr, "Error: Unable to open font file.\n");
        exit(EXIT_FAILURE);
    }

    fseek(font_file, 0, SEEK_END);
    long font_size_in_bytes = ftell(font_file);
    fseek(font_file, 0, SEEK_SET);

    uint8_t *font_buffer = (uint8_t *)malloc(font_size_in_bytes);
    fread(font_buffer, 1, font_size_in_bytes, font_file);
    fclose(font_file);

    stbtt_fontinfo font_info;
    if (!stbtt_InitFont(&font_info, font_buffer, stbtt_GetFontOffsetForIndex(font_buffer, 0))) {
        fprintf(stderr, "Error: Failed to initialize font.\n");
        exit(EXIT_FAILURE);
    }

    raia_font_t raia_font;
    raia_font.font_info = font_info;
    raia_font.font_buffer = font_buffer;
    raia_font.font_size = font_size;
    return raia_font;
}

CharacterSize render_character(uint8_t *pixels, int width, int height, int position_x, int position_y, const char *font_path, int font_size, uint32_t unicode_codepoint) {
    FILE *font_file;
#ifdef __WINDOWS__
    fopen_s(&font_file, font_path, "rb");
#else
    font_file = fopen(font_path, "rb");
#endif
    if ((font_file) == NULL) {
        fprintf(stderr, "Error: Unable to open font file.\n");
        exit(EXIT_FAILURE);
    }

    fseek(font_file, 0, SEEK_END);
    long font_size_in_bytes = ftell(font_file);
    fseek(font_file, 0, SEEK_SET);

    uint8_t *font_buffer = (uint8_t *)malloc(font_size_in_bytes);
    fread(font_buffer, 1, font_size_in_bytes, font_file);
    fclose(font_file);

    stbtt_fontinfo font_info;
    if (!stbtt_InitFont(&font_info, font_buffer, stbtt_GetFontOffsetForIndex(font_buffer, 0))) {
        fprintf(stderr, "Error: Failed to initialize font.\n");
        exit(EXIT_FAILURE);
    }

    float scale = stbtt_ScaleForPixelHeight(&font_info, font_size);
    int ascent, descent, line_gap;
    stbtt_GetFontVMetrics(&font_info, &ascent, &descent, &line_gap);
    ascent *= scale;
    descent *= scale;

    int advance_width, left_side_bearing;
    stbtt_GetCodepointHMetrics(&font_info, unicode_codepoint, &advance_width, &left_side_bearing);
    advance_width *= scale;
    left_side_bearing *= scale;

    int glyph_width, glyph_height, glyph_xoffset, glyph_yoffset;
    uint8_t *glyph_bitmap = stbtt_GetCodepointBitmap(&font_info, 0, scale, unicode_codepoint, &glyph_width, &glyph_height, &glyph_xoffset, &glyph_yoffset);

    raia_point_t point;
    raia_color_t color = {0,0,0,0};
    raia_size_t size = {width, height};
    for (int y = 0; y < glyph_height; y++) {
        for (int x = 0; x < glyph_width; x++) {
            int pixel_x = position_x + x;// + glyph_xoffset;
            int pixel_y = position_y + y;// + glyph_yoffset;
            if (pixel_x >= 0 && pixel_x < width && pixel_y >= 0 && pixel_y < height) {
                uint8_t alpha = glyph_bitmap[y * glyph_width + x];
                int pixel_index = (pixel_y * width + pixel_x) * 4;
                point.x = pixel_x;
                point.y = pixel_y;
                color.alpha = alpha;
                set_pixel_rgba(pixels,  point, color, size, 4);
            }
        }
    }

    stbtt_FreeBitmap(glyph_bitmap, 0);
    free(font_buffer);

    CharacterSize character_size;
    character_size.width = glyph_width;
    character_size.height = glyph_height;
    return character_size;
}