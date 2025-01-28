//
// Created by dolphilia on 2024/01/10.
//

#ifndef RAIA_SKIA_STATIC_SK_STRING_H
#define RAIA_SKIA_STATIC_SK_STRING_H


#ifdef __cplusplus
extern "C" {
#endif
typedef int sk_string_t;
void static_sk_string_delete(int key);
void * static_sk_string_get_ptr(int key); // -> SkString *
// sk_span
void static_sk_span_sk_string_delete(int key);
void * static_sk_span_sk_string_get_ptr(int key, int index); // -> SkString *
#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_STATIC_SK_STRING_H
