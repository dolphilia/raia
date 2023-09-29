#include "raia_font.h"

static int _raia_font_open(const char* font_path) {
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
    fclose(font_file);
    return (int)font_size_in_bytes;
}

RAIA_API const char * raia_font_open(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    const char* font_path = joint_get_in_str(joint, "font_path");
    int font_size_in_bytes = _raia_font_open(font_path);
    joint_add_out_int(joint, "result", font_size_in_bytes);
    return joint_out_write(joint);
}

static raia_font_t _raia_font_init_buffer(const char *font_path, uint8_t *font_buffer) {
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
    fread(font_buffer, 1, font_size_in_bytes, font_file);
    fclose(font_file);
    stbtt_fontinfo font_info;
    if (!stbtt_InitFont(&font_info, font_buffer, stbtt_GetFontOffsetForIndex(font_buffer, 0))) {
        fprintf(stderr, "Error: Failed to initialize font.\n");
        exit(EXIT_FAILURE);
    }
    raia_font_t font;
    font.font_info = font_info;
    font.font_buffer = font_buffer;
    return font;
}

RAIA_API const char * raia_font_init_buffer(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    const char* font_path = joint_get_in_str(joint, "font_path");
    uint8_t *font_buffer = (uint8_t *)(uintptr_t)joint_get_in_uint(joint, "font_buffer");
    raia_font_t font = _raia_font_init_buffer(font_path, font_buffer);
    joint_add_out_uint(joint, "userdata", (uint64_t)(uintptr_t)font.font_info.userdata);
    joint_add_out_uint(joint, "data", (uint64_t)(uintptr_t)font.font_info.data);
    joint_add_out_int(joint, "fontstart", font.font_info.fontstart);
    joint_add_out_int(joint, "numGlyphs", font.font_info.numGlyphs);
    joint_add_out_int(joint, "loca", font.font_info.loca);
    joint_add_out_int(joint, "head", font.font_info.head);
    joint_add_out_int(joint, "glyf", font.font_info.glyf);
    joint_add_out_int(joint, "hhea", font.font_info.hhea);
    joint_add_out_int(joint, "hmtx", font.font_info.hmtx);
    joint_add_out_int(joint, "kern", font.font_info.kern);
    joint_add_out_int(joint, "gpos", font.font_info.gpos);
    joint_add_out_int(joint, "svg", font.font_info.svg);
    joint_add_out_int(joint, "index_map", font.font_info.index_map);
    joint_add_out_int(joint, "indexToLocFormat", font.font_info.indexToLocFormat);
    joint_add_out_uint(joint, "cff_data", (uint64_t)(uintptr_t)font.font_info.cff.data);
    joint_add_out_int(joint, "cff_cursor", font.font_info.cff.cursor);
    joint_add_out_int(joint, "cff_size", font.font_info.cff.size);
    joint_add_out_uint(joint, "charstrings_data", (uint64_t)(uintptr_t)font.font_info.charstrings.data);
    joint_add_out_int(joint, "charstrings_cursor", font.font_info.charstrings.cursor);
    joint_add_out_int(joint, "charstrings_size", font.font_info.charstrings.size);
    joint_add_out_uint(joint, "gsubrs_data", (uint64_t)(uintptr_t)font.font_info.gsubrs.data);
    joint_add_out_int(joint, "gsubrs_cursor", font.font_info.gsubrs.cursor);
    joint_add_out_int(joint, "gsubrs_size", font.font_info.gsubrs.size);
    joint_add_out_uint(joint, "subrs_data", (uint64_t)(uintptr_t)font.font_info.subrs.data);
    joint_add_out_int(joint, "subrs_cursor", font.font_info.subrs.cursor);
    joint_add_out_int(joint, "subrs_size", font.font_info.subrs.size);
    joint_add_out_uint(joint, "fontdicts_data", (uint64_t)(uintptr_t)font.font_info.fontdicts.data);
    joint_add_out_int(joint, "fontdicts_cursor", font.font_info.fontdicts.cursor);
    joint_add_out_int(joint, "fontdicts_size", font.font_info.fontdicts.size);
    joint_add_out_uint(joint, "fdselect_data", (uint64_t)(uintptr_t)font.font_info.fdselect.data);
    joint_add_out_int(joint, "fdselect_cursor", font.font_info.fdselect.cursor);
    joint_add_out_int(joint, "fdselect_size", font.font_info.fdselect.size);
    return joint_out_write(joint);
}

static raia_size_t _raia_font_draw_text_rgb(
        uint8_t *pixels, int width, int height, const uint8_t* text, int font_size,
        raia_color_t  color, int pos_x, int pos_y, stbtt_fontinfo font_info
) {
    int bytes = 0;
    uint32_t unicode_codepoint = utf8_to_codepoint(text,&bytes);

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
    raia_color_t current_color = color;
    raia_size_t size = {width, height};
    for (int y = 0; y < glyph_height; y++) {
        for (int x = 0; x < glyph_width; x++) {
            int pixel_x = pos_x + x;
            int pixel_y = pos_y + y + glyph_yoffset + (int)((float)font_size / 1.3);
            if (pixel_x >= 0 && pixel_x < width && pixel_y >= 0 && pixel_y < height) {
                uint8_t alpha = glyph_bitmap[y * glyph_width + x];
                point.x = pixel_x;
                point.y = pixel_y;
                current_color.alpha = alpha;
                set_pixel_rgb_alpha(pixels, point, color, alpha, size, 3);
            }
        }
    }

    stbtt_FreeBitmap(glyph_bitmap, 0);

    raia_size_t glyph_size;
    glyph_size.width = glyph_width;
    glyph_size.height = glyph_height;
    return glyph_size;
}

RAIA_API const char *raia_font_draw_char_rgb(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    uint8_t *pixels = (uint8_t *)(uintptr_t)joint_get_in_uint(joint, "pixels");
    int width = joint_get_in_int(joint, "width");
    int height = joint_get_in_int(joint, "height");
    const uint8_t *text = (const uint8_t *)joint_get_in_str(joint, "text");
    int font_size = joint_get_in_int(joint, "font_size");
    raia_color_t color = {
            .red = joint_get_in_int(joint, "color_red"),
            .green = joint_get_in_int(joint, "color_green"),
            .blue = joint_get_in_int(joint, "color_blue"),
    };
    int pos_x = joint_get_in_int(joint, "pos_x");
    int pos_y = joint_get_in_int(joint, "pos_y");
    stbtt_fontinfo font_info = {
            .userdata = (uint8_t *)(uintptr_t)joint_get_in_uint(joint, "userdata"),
            .data = (uint8_t *)(uintptr_t)joint_get_in_uint(joint, "data"),
            .fontstart = joint_get_in_int(joint, "fontstart"),
            .numGlyphs = joint_get_in_int(joint, "numGlyphs"),
            .loca = joint_get_in_int(joint, "loca"),
            .head = joint_get_in_int(joint, "head"),
            .glyf = joint_get_in_int(joint, "glyf"),
            .hhea = joint_get_in_int(joint, "hhea"),
            .hmtx = joint_get_in_int(joint, "hmtx"),
            .kern = joint_get_in_int(joint, "kern"),
            .gpos = joint_get_in_int(joint, "gpos"),
            .svg = joint_get_in_int(joint, "svg"),
            .index_map = joint_get_in_int(joint, "index_map"),
            .indexToLocFormat = joint_get_in_int(joint, "indexToLocFormat"),
            .cff.data = (uint8_t *)(uintptr_t)joint_get_in_uint(joint, "cff_data"),
            .cff.cursor = joint_get_in_int(joint, "cff_cursor"),
            .cff.size = joint_get_in_int(joint, "cff_size"),
            .charstrings.data = (uint8_t *)(uintptr_t)joint_get_in_uint(joint, "charstrings_data"),
            .charstrings.cursor = joint_get_in_int(joint, "charstrings_cursor"),
            .charstrings.size = joint_get_in_int(joint, "charstrings_size"),
            .gsubrs.data = (uint8_t *)(uintptr_t)joint_get_in_uint(joint, "gsubrs_data"),
            .gsubrs.cursor = joint_get_in_int(joint, "gsubrs_cursor"),
            .gsubrs.size = joint_get_in_int(joint, "gsubrs_data"),
            .subrs.data = (uint8_t *)(uintptr_t)joint_get_in_uint(joint, "subrs_data"),
            .subrs.cursor = joint_get_in_int(joint, "subrs_cursor"),
            .subrs.size = joint_get_in_int(joint, "subrs_size"),
            .fontdicts.data = (uint8_t *)(uintptr_t)joint_get_in_uint(joint, "fontdicts_data"),
            .fontdicts.cursor = joint_get_in_int(joint, "fontdicts_cursor"),
            .fontdicts.size = joint_get_in_int(joint, "fontdicts_size"),
            .fdselect.data = (uint8_t *)(uintptr_t)joint_get_in_uint(joint, "fdselect_data"),
            .fdselect.cursor = joint_get_in_int(joint, "fdselect_cursor"),
            .fdselect.size = joint_get_in_int(joint, "fdselect_size"),
    };

    raia_size_t glyph_size = _raia_font_draw_text_rgb(
            pixels,
            width,
            height,
            text,
            font_size,
            color,
            pos_x,
            pos_y,
            font_info
    );

    joint_add_out_int(joint, "width", glyph_size.width);
    joint_add_out_int(joint, "height", glyph_size.height);
    return joint_out_write(joint);
}

static raia_size_t _raia_font_draw_text_rgba(
        uint8_t *pixels, int width, int height, const uint8_t* text, int font_size,
        raia_color_t  color, int pos_x, int pos_y, stbtt_fontinfo font_info
) {
    int bytes = 0;
    uint32_t unicode_codepoint = utf8_to_codepoint(text,&bytes);

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
    raia_color_t current_color = color;
    raia_size_t size = {width, height};
    for (int y = 0; y < glyph_height; y++) {
        for (int x = 0; x < glyph_width; x++) {
            int pixel_x = pos_x + x;
            int pixel_y = pos_y + y + glyph_yoffset + (int)((float)font_size / 1.3);
            if (pixel_x >= 0 && pixel_x < width && pixel_y >= 0 && pixel_y < height) {
                uint8_t alpha = glyph_bitmap[y * glyph_width + x];
                point.x = pixel_x;
                point.y = pixel_y;
                current_color.alpha = alpha;
                set_pixel_rgba(pixels, point, current_color, size, 4);
            }
        }
    }
    stbtt_FreeBitmap(glyph_bitmap, 0);
    raia_size_t glyph_size = {
            .width = glyph_width,
            .height = glyph_height,
    };
    return glyph_size;
}

RAIA_API const char * raia_font_draw_char_rgba(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    uint8_t *pixels = (uint8_t *)(uintptr_t)joint_get_in_uint(joint, "pixels");
    int width = joint_get_in_int(joint, "width");
    int height = joint_get_in_int(joint, "height");
    const uint8_t *text = (const uint8_t *)joint_get_in_str(joint, "text");
    int font_size = joint_get_in_int(joint, "font_size");
    raia_color_t color = {
            .red = joint_get_in_int(joint, "color_red"),
            .green = joint_get_in_int(joint, "color_green"),
            .blue = joint_get_in_int(joint, "color_blue"),
    };
    int pos_x = joint_get_in_int(joint, "pos_x");
    int pos_y = joint_get_in_int(joint, "pos_y");
    stbtt_fontinfo font_info = {
            .userdata = (uint8_t *)(uintptr_t)joint_get_in_uint(joint, "userdata"),
            .data = (uint8_t *)(uintptr_t)joint_get_in_uint(joint, "data"),
            .fontstart = joint_get_in_int(joint, "fontstart"),
            .numGlyphs = joint_get_in_int(joint, "numGlyphs"),
            .loca = joint_get_in_int(joint, "loca"),
            .head = joint_get_in_int(joint, "head"),
            .glyf = joint_get_in_int(joint, "glyf"),
            .hhea = joint_get_in_int(joint, "hhea"),
            .hmtx = joint_get_in_int(joint, "hmtx"),
            .kern = joint_get_in_int(joint, "kern"),
            .gpos = joint_get_in_int(joint, "gpos"),
            .svg = joint_get_in_int(joint, "svg"),
            .index_map = joint_get_in_int(joint, "index_map"),
            .indexToLocFormat = joint_get_in_int(joint, "indexToLocFormat"),
            .cff.data = (uint8_t *)(uintptr_t)joint_get_in_uint(joint, "cff_data"),
            .cff.cursor = joint_get_in_int(joint, "cff_cursor"),
            .cff.size = joint_get_in_int(joint, "cff_size"),
            .charstrings.data = (uint8_t *)(uintptr_t)joint_get_in_uint(joint, "charstrings_data"),
            .charstrings.cursor = joint_get_in_int(joint, "charstrings_cursor"),
            .charstrings.size = joint_get_in_int(joint, "charstrings_size"),
            .gsubrs.data = (uint8_t *)(uintptr_t)joint_get_in_uint(joint, "gsubrs_data"),
            .gsubrs.cursor = joint_get_in_int(joint, "gsubrs_cursor"),
            .gsubrs.size = joint_get_in_int(joint, "gsubrs_data"),
            .subrs.data = (uint8_t *)(uintptr_t)joint_get_in_uint(joint, "subrs_data"),
            .subrs.cursor = joint_get_in_int(joint, "subrs_cursor"),
            .subrs.size = joint_get_in_int(joint, "subrs_size"),
            .fontdicts.data = (uint8_t *)(uintptr_t)joint_get_in_uint(joint, "fontdicts_data"),
            .fontdicts.cursor = joint_get_in_int(joint, "fontdicts_cursor"),
            .fontdicts.size = joint_get_in_int(joint, "fontdicts_size"),
            .fdselect.data = (uint8_t *)(uintptr_t)joint_get_in_uint(joint, "fdselect_data"),
            .fdselect.cursor = joint_get_in_int(joint, "fdselect_cursor"),
            .fdselect.size = joint_get_in_int(joint, "fdselect_size"),
    };

    printf("%d\n", font_info.numGlyphs);

    raia_size_t glyph_size = _raia_font_draw_text_rgba(
            pixels,
            width,
            height,
            text,
            font_size,
            color,
            pos_x,
            pos_y,
            font_info);

    joint_add_out_int(joint, "width", glyph_size.width);
    joint_add_out_int(joint, "height", glyph_size.height);
    return joint_out_write(joint);
}

static raia_size_t _raia_font_get_text_size(const uint8_t* text, int font_size, stbtt_fontinfo font_info) {
    int bytes = 0;
    uint32_t unicode_codepoint = utf8_to_codepoint(text,&bytes);

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

    stbtt_FreeBitmap(glyph_bitmap, 0);
    raia_size_t glyph_size = {
            .width = glyph_width,
            .height = glyph_height,
    };
    return glyph_size;
}

RAIA_API const char * raia_font_get_char_size(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    const uint8_t *text = (const uint8_t *)joint_get_in_str(joint, "text");
    int font_size = joint_get_in_int(joint, "font_size");
    stbtt_fontinfo font_info = {
            .userdata = (uint8_t *)(uintptr_t)joint_get_in_uint(joint, "userdata"),
            .data = (uint8_t *)(uintptr_t)joint_get_in_uint(joint, "data"),
            .fontstart = joint_get_in_int(joint, "fontstart"),
            .numGlyphs = joint_get_in_int(joint, "numGlyphs"),
            .loca = joint_get_in_int(joint, "loca"),
            .head = joint_get_in_int(joint, "head"),
            .glyf = joint_get_in_int(joint, "glyf"),
            .hhea = joint_get_in_int(joint, "hhea"),
            .hmtx = joint_get_in_int(joint, "hmtx"),
            .kern = joint_get_in_int(joint, "kern"),
            .gpos = joint_get_in_int(joint, "gpos"),
            .svg = joint_get_in_int(joint, "svg"),
            .index_map = joint_get_in_int(joint, "index_map"),
            .indexToLocFormat = joint_get_in_int(joint, "indexToLocFormat"),
            .cff.data = (uint8_t *)(uintptr_t)joint_get_in_uint(joint, "cff_data"),
            .cff.cursor = joint_get_in_int(joint, "cff_cursor"),
            .cff.size = joint_get_in_int(joint, "cff_size"),
            .charstrings.data = (uint8_t *)(uintptr_t)joint_get_in_uint(joint, "charstrings_data"),
            .charstrings.cursor = joint_get_in_int(joint, "charstrings_cursor"),
            .charstrings.size = joint_get_in_int(joint, "charstrings_size"),
            .gsubrs.data = (uint8_t *)(uintptr_t)joint_get_in_uint(joint, "gsubrs_data"),
            .gsubrs.cursor = joint_get_in_int(joint, "gsubrs_cursor"),
            .gsubrs.size = joint_get_in_int(joint, "gsubrs_data"),
            .subrs.data = (uint8_t *)(uintptr_t)joint_get_in_uint(joint, "subrs_data"),
            .subrs.cursor = joint_get_in_int(joint, "subrs_cursor"),
            .subrs.size = joint_get_in_int(joint, "subrs_size"),
            .fontdicts.data = (uint8_t *)(uintptr_t)joint_get_in_uint(joint, "fontdicts_data"),
            .fontdicts.cursor = joint_get_in_int(joint, "fontdicts_cursor"),
            .fontdicts.size = joint_get_in_int(joint, "fontdicts_size"),
            .fdselect.data = (uint8_t *)(uintptr_t)joint_get_in_uint(joint, "fdselect_data"),
            .fdselect.cursor = joint_get_in_int(joint, "fdselect_cursor"),
            .fdselect.size = joint_get_in_int(joint, "fdselect_size"),
    };

    raia_size_t glyph_size = _raia_font_get_text_size(text, font_size, font_info);

    joint_add_out_int(joint, "width", glyph_size.width);
    joint_add_out_int(joint, "height", glyph_size.height);
    return joint_out_write(joint);
}