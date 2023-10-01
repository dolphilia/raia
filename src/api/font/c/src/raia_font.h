#ifndef RAIA_FONT_RAIA_FONT_H
#define RAIA_FONT_RAIA_FONT_H

#include <stdio.h>
#include "../../../../common/c/utility/export_api.h"
#include "../../../../common/c/utility/platform.h"
#include "../../../../common/c/wrapper/wrapper_yyjson.h"
#define STB_TRUETYPE_IMPLEMENTATION
#include "../../../../third_party/c/nothings/stb/stb_truetype.h"
#include "util/util_pixel.h"
#include "util/util_utf8.h"

typedef struct {
    stbtt_fontinfo font_info;
    uint8_t *font_buffer;
    int font_size;
} raia_font_t;

#endif //RAIA_FONT_RAIA_FONT_H
