//
// Created by dolphilia on 2024/04/05.
//

#ifndef RAIA_SKIA_STATIC_SK_RSX_FORM_H
#define RAIA_SKIA_STATIC_SK_RSX_FORM_H

#ifdef __cplusplus
extern "C" {
#endif
typedef int sk_rsx_form_t;
void static_sk_rsx_form_delete(int key);
void * static_sk_rsx_form_get_ptr(int key); // -> SkRSXform *
#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_STATIC_SK_RSX_FORM_H
