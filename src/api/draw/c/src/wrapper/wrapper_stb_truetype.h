//
// Created by dolphilia on 2023/04/08.
//

#ifndef RAIA_DRAW_WRAPPER_STB_TRUETYPE_H
#define RAIA_DRAW_WRAPPER_STB_TRUETYPE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "../util/util_pixel.h"
#include "../stb/stb_truetype.h"
#include "../../../../../share/c/utility/platform.h"

typedef struct {
    stbtt_fontinfo font_info;
    uint8_t *font_buffer;
    int font_size;
} raia_font_t;

typedef struct {
    int width;
    int height;
} CharacterSize;

raia_font_t init_font(uint8_t *font_buf, const char *font_path, int font_size);
CharacterSize render_character(uint8_t *pixels, int width, int height, int position_x, int position_y, const char *font_path, int font_size, uint32_t unicode_codepoint);

#endif //RAIA_DRAW_WRAPPER_STB_TRUETYPE_H
