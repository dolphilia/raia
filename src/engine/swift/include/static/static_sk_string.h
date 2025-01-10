//
// Created by dolphilia on 2024/01/10.
//

#ifndef RAIA_SKIA_STATIC_SK_STRING_H
#define RAIA_SKIA_STATIC_SK_STRING_H

#include <set>
#include <string>
#include <map>
#include "include/core/SkString.h"
#include "include/private/base/SkSpan_impl.h"

typedef int sk_string_t;
typedef int sk_span_sk_string_t;

int static_sk_string_make(SkString value);
extern "C" void static_sk_string_delete(int key);
SkString static_sk_string_get(int key);
void static_sk_string_set(int key, SkString value);

//

int static_sk_span_sk_string_make(SkSpan<SkString> value);
extern "C" void static_sk_span_sk_string_delete(int key);
SkSpan<SkString> static_sk_span_sk_string_get(int key);
void static_sk_span_sk_string_set(int key, SkSpan<SkString> value);

#endif //RAIA_SKIA_STATIC_SK_STRING_H
