//
// Created by dolphilia on 2024/02/01.
//

#ifndef RAIA_SKIA_SK_ENCODER_H
#define RAIA_SKIA_SK_ENCODER_H

#ifdef __cplusplus
extern "C" {
#endif

void SkEncoder_delete(void *encoder); // (SkEncoder *encoder)
bool SkEncoder_encodeRows(void *encoder, int numRows); // (SkEncoder *encoder, int numRows) -> bool

#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_SK_ENCODER_H
