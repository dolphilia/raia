//
// Created by dolphilia on 2024/02/01.
//

#ifndef RAIA_SKIA_SK_ENCODER_H
#define RAIA_SKIA_SK_ENCODER_H

#include "include/encode/SkEncoder.h"

extern "C" {
void SkEncoder_delete(SkEncoder *encoder);
bool SkEncoder_encodeRows(SkEncoder *encoder, int numRows);
}

#endif //RAIA_SKIA_SK_ENCODER_H
