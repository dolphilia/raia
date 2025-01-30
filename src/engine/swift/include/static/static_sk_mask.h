//
// Created by dolphilia on 25/01/30.
//

#ifndef STATIC_SK_MASK_H
#define STATIC_SK_MASK_H

#ifdef __cplusplus
extern "C" {
#endif

typedef int sk_mask_t;

void static_sk_mask_delete(int key);
void* static_sk_mask_get_ptr(int key);

#ifdef __cplusplus
}
#endif

#endif //STATIC_SK_MASK_H
