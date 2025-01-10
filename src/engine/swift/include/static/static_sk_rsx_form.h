//
// Created by dolphilia on 2024/04/05.
//

#ifndef RAIA_SKIA_STATIC_SK_RSX_FORM_H
#define RAIA_SKIA_STATIC_SK_RSX_FORM_H

#include <set>
#include <map>
#include "include/core/SkRSXform.h"

typedef int sk_rsx_form_t;

int static_sk_rsx_form_make(SkRSXform value);
extern "C" void static_sk_rsx_form_delete(int key);
SkRSXform static_sk_rsx_form_get(int key);
void static_sk_rsx_form_set(int key, SkRSXform value);

#endif //RAIA_SKIA_STATIC_SK_RSX_FORM_H
