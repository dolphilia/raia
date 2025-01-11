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
#include "export_api.h"

typedef int sk_string_t;
typedef int sk_span_sk_string_t;

extern "C" {
RAIA_API void static_sk_string_delete(int key);
RAIA_API SkString * static_sk_string_get_ptr(int key);
// sk_span
RAIA_API void static_sk_span_sk_string_delete(int key);
RAIA_API SkString * static_sk_span_sk_string_get_ptr(int key, int index);
}

int static_sk_string_make(SkString value);
SkString static_sk_string_get(int key);
void static_sk_string_set(int key, SkString value);

// sk_span

int static_sk_span_sk_string_make(SkSpan<SkString> value);
SkSpan<SkString> static_sk_span_sk_string_get(int key);
void static_sk_span_sk_string_set(int key, SkSpan<SkString> value);

#endif //RAIA_SKIA_STATIC_SK_STRING_H
