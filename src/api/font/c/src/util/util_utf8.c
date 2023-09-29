//
// Created by dolphilia on 2023/04/08.
//

#include "util_utf8.h"

uint32_t utf8_to_codepoint(const uint8_t *utf8, int *bytes_read) {
    uint32_t codepoint = 0;
    int bytes = 0;

    if ((utf8[0] & 0x80) == 0) {
        // 1-byte character
        codepoint = utf8[0];
        bytes = 1;
    }
    else if ((utf8[0] & 0xE0) == 0xC0) {
        // 2-byte character
        codepoint = utf8[0] & 0x1F;
        codepoint <<= 6;
        codepoint |= utf8[1] & 0x3F;
        bytes = 2;
    }
    else if ((utf8[0] & 0xF0) == 0xE0) {
        // 3-byte character
        codepoint = utf8[0] & 0x0F;
        codepoint <<= 6;
        codepoint |= utf8[1] & 0x3F;
        codepoint <<= 6;
        codepoint |= utf8[2] & 0x3F;
        bytes = 3;
    }
    else if ((utf8[0] & 0xF8) == 0xF0) {
        // 4-byte character
        codepoint = utf8[0] & 0x07;
        codepoint <<= 6;
        codepoint |= utf8[1] & 0x3F;
        codepoint <<= 6;
        codepoint |= utf8[2] & 0x3F;
        codepoint <<= 6;
        codepoint |= utf8[3] & 0x3F;
        bytes = 4;
    } else {
        // Invalid UTF-8 sequence
        codepoint = 0xFFFD;  // Unicode replacement character
        bytes = 1;
    }

    if (bytes_read) {
        *bytes_read = bytes;
    }
    return codepoint;
}