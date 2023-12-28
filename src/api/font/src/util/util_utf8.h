//
// Created by dolphilia on 2023/04/08.
//

#ifndef RAIA_DRAW_UTIL_UTF8_H
#define RAIA_DRAW_UTIL_UTF8_H

#include <stdint.h>
#include <stddef.h>

uint32_t utf8_to_codepoint(const uint8_t *utf8, int *bytes_read);

#endif //RAIA_DRAW_UTIL_UTF8_H
