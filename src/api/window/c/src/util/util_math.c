//
//  util_math.c
//  raia-engine
//
//  Created by dolphilia on 2022/09/09.
//

#include "util_math.h"

int rnd(int min, int max) {
    return min + (int)(rand() * (max - min + 1.0) / (1.0 + RAND_MAX));
}

uint32_t xor128(void) {
    static uint32_t x = 123456789;
    static uint32_t y = 362436069;
    static uint32_t z = 521288629;
    static uint32_t w = 88675123;
    uint32_t t;
    t = (x ^ (x << 11));
    x = y;
    y = z;
    z = w;
    return (w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));
}

uint32_t random_ul_range(uint32_t min_value, uint32_t max_value) {
    return (xor128() % (max_value - min_value + 1) + min_value);
}

int32_t rand_xor128(int32_t min_value, int32_t max_value) {
    if (min_value < 0) {
        uint32_t ul = random_ul_range(0, (uint32_t)(max_value + (-1) * min_value));
        return (int)(ul) + min_value;
    } else {
        return random_ul_range((uint32_t)(min_value), (uint32_t)(max_value));
    }
}
