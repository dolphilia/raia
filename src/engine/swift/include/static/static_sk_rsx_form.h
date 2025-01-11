//
// Created by dolphilia on 2024/04/05.
//

#ifndef RAIA_SKIA_STATIC_SK_RSX_FORM_H
#define RAIA_SKIA_STATIC_SK_RSX_FORM_H

#include <set>
#include <map>
#include "include/core/SkRSXform.h"
#include "export_api.h"

typedef int sk_rsx_form_t;

extern "C" {
RAIA_API void static_sk_rsx_form_delete(int key);
RAIA_API SkRSXform * static_sk_rsx_form_get_ptr(int key);
}

int static_sk_rsx_form_make(SkRSXform value);
SkRSXform static_sk_rsx_form_get(int key);
void static_sk_rsx_form_set(int key, SkRSXform value);

#endif //RAIA_SKIA_STATIC_SK_RSX_FORM_H
