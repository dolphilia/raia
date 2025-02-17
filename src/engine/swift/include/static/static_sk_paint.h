//
// Created by dolphilia on 25/02/17.
//

#ifndef STATIC_SK_PAINT_H
#define STATIC_SK_PAINT_H
#ifdef __cplusplus
extern "C" {
#endif
typedef int sk_paint_t;
void static_sk_paint_delete(int key);
void *static_sk_paint_get_ptr(int key);
#ifdef __cplusplus
}
#endif
#endif //STATIC_SK_PAINT_H
