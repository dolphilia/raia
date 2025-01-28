//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_STATIC_SK_STROKE_REC_H
#define RAIA_SKIA_STATIC_SK_STROKE_REC_H

#ifdef __cplusplus
extern "C" {
#endif
typedef int sk_stroke_rec_t;
void static_sk_stroke_rec_delete(int key);
void * static_sk_stroke_rec_get_ptr(int key); // -> SkStrokeRec *
#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_STATIC_SK_STROKE_REC_H
