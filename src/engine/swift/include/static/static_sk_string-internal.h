#ifndef STATIC_SK_STRING_INTERNAL_H
#define STATIC_SK_STRING_INTERNAL_H
#include <set>
#include <map>
#include "include/core/SkString.h"
#include "include/private/base/SkSpan_impl.h"
int static_sk_string_make(SkString value);
SkString static_sk_string_get_entity(int key);
void static_sk_string_set(int key, SkString value);
// sk_span
int static_sk_span_sk_string_make(SkSpan<SkString> value);
SkSpan<SkString> static_sk_span_sk_string_get_entity(int key);
void static_sk_span_sk_string_set(int key, SkSpan<SkString> value);
#endif // STATIC_SK_STRING_INTERNAL_H
