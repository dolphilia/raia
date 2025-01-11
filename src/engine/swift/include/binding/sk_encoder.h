//
// Created by dolphilia on 2024/02/01.
//

#ifndef RAIA_SKIA_SK_ENCODER_H
#define RAIA_SKIA_SK_ENCODER_H

#include "include/encode/SkEncoder.h"
#include "export_api.h"

extern "C" {
RAIA_API void SkEncoder_delete(SkEncoder *encoder);
RAIA_API bool SkEncoder_encodeRows(SkEncoder *encoder, int numRows);
}

#endif //RAIA_SKIA_SK_ENCODER_H
