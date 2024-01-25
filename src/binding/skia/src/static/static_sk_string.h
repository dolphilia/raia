//
// Created by dolphilia on 2024/01/10.
//

#ifndef RAIA_SKIA_STATIC_SK_STRING_H
#define RAIA_SKIA_STATIC_SK_STRING_H

#include <string>
#include <map>
#include "include/core/SkString.h"

void static_sk_string_delete(int key);
SkString static_sk_string_get(int key);
void static_sk_string_set(int key, SkString value);

#endif //RAIA_SKIA_STATIC_SK_STRING_H
