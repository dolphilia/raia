#ifndef RAIA_FONT_RAIA_FONT_H
#define RAIA_FONT_RAIA_FONT_H

#include <stdio.h>
#include "../../../../share/c/utility/export_api.h"
#include "../../../../share/c/utility/platform.h"
#include "../../../../share/c/wrapper/wrapper_yyjson.h"
#include "util/util_pixel.h"
#include "util/util_utf8.h"
#define STB_TRUETYPE_IMPLEMENTATION
#include "../../../../thirdparty/c/nothings/stb/stb_truetype.h"

typedef struct {
    stbtt_fontinfo font_info;
    uint8_t *font_buffer;
    int font_size;
} raia_font_t;

#endif //RAIA_FONT_RAIA_FONT_H
