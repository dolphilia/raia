//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_SK_STRING_H
#define RAIA_SKIA_SK_STRING_H

#include "include/core/SkString.h"
#include "../static/static_std_string_view.h"

extern "C" {
// SkString & operator=(const SkString &)
// SkString & operator=(SkString &&)
// SkString & operator=(const char text[])
// SkString & operator+=(const SkString &s)
// SkString & operator+=(const char text[])
// SkString & operator+=(const char c)
// char operator[](size_t n)
// char & operator[](size_t n)
SkString *SkString_new();
SkString *SkString_new_2(size_t len);
SkString *SkString_new_3(const char text[]);
SkString *SkString_new_4(const char text[], size_t len);
SkString *SkString_new_5(const SkString *str);
SkString *SkString_new_6(const std::string *str);
SkString *SkString_new_7(string_view_t view);
void SkString_delete(SkString *string);
bool SkString_isEmpty(SkString *string);
size_t SkString_size(SkString *string);
const char * SkString_data(SkString *string);
char * SkString_data_2(SkString *string);
const char * SkString_c_str(SkString *string);
bool SkString_equals(SkString *string, const SkString *str);
bool SkString_equals_2(SkString *string, const char text[]);
bool SkString_equals_3(SkString *string, const char text[], size_t len);
bool SkString_startsWith(SkString *string, const char prefixStr[]);
bool SkString_startsWith_2(SkString *string, char prefixChar);
//bool SkString_endsWith(SkString *string, const char suffixStr[]);
//bool SkString_endsWith_2(SkString *string, const char suffixChar);
bool SkString_contains(SkString *string, const char substring[]);
bool SkString_contains_2(SkString *string, char subchar);
int SkString_find(SkString *string, const char substring[]);
int SkString_findLastOf(SkString *string, char subchar);
void SkString_reset(SkString *string);
void SkString_resize(SkString *string, size_t len);
void SkString_set(SkString *string, const SkString *src);
void SkString_set_2(SkString *string, const char text[]);
void SkString_set_3(SkString *string, const char text[], size_t len);
void SkString_set_4(SkString *string, string_view_t str);
void SkString_insert(SkString *string, size_t offset, const char text[]);
void SkString_insert_2(SkString *string, size_t offset, const char text[], size_t len);
void SkString_insert_3(SkString *string, size_t offset, const SkString *str);
void SkString_insert_4(SkString *string, size_t offset, string_view_t str);
void SkString_insertUnichar(SkString *string, size_t offset, SkUnichar unichar);
void SkString_insertS32(SkString *string, size_t offset, int32_t value);
void SkString_insertS64(SkString *string, size_t offset, int64_t value, int minDigits);
void SkString_insertU32(SkString *string, size_t offset, uint32_t value);
void SkString_insertU64(SkString *string, size_t offset, uint64_t value, int minDigits);
void SkString_insertHex(SkString *string, size_t offset, uint32_t value, int minDigits);
void SkString_insertScalar(SkString *string, size_t offset, SkScalar v);
void SkString_append(SkString *string, const char text[]);
void SkString_append_2(SkString *string, const char text[], size_t len);
void SkString_append_3(SkString *string, const SkString *str);
void SkString_append_4(SkString *string, string_view_t str);
void SkString_appendUnichar(SkString *string, SkUnichar uni);
void SkString_appendS32(SkString *string, int32_t value);
void SkString_appendS64(SkString *string, int64_t value, int minDigits);
void SkString_appendU32(SkString *string, uint32_t value);
void SkString_appendU64(SkString *string, uint64_t value, int minDigits);
void SkString_appendHex(SkString *string, uint32_t value, int minDigits);
void SkString_appendScalar(SkString *string, SkScalar value);
void SkString_prepend(SkString *string, const char text[]);
void SkString_prepend_2(SkString *string, const char text[], size_t len);
void SkString_prepend_3(SkString *string, const SkString *str);
void SkString_prepend_4(SkString *string, string_view_t str);
void SkString_prependUnichar(SkString *string, SkUnichar uni);
void SkString_prependS32(SkString *string, int32_t value);
void SkString_prependS64(SkString *string, int32_t value, int minDigits);
void SkString_prependHex(SkString *string, uint32_t value, int minDigits);
void SkString_prependScalar(SkString *string, SkScalar value);
//void SkString_printf(SkString *string, const char format[],...);
//void SkString_printVAList(SkString *string, const char format[], va_list);
//void SkString_appendf(SkString *string, const char format[],...);
//void SkString_appendVAList(SkString *string, const char format[], va_list);
//void SkString_prependf(SkString *string, const char format[],...);
//void SkString_prependVAList(SkString *string, const char format[], va_list);
void SkString_remove(SkString *string, size_t offset, size_t length);
void SkString_swap(SkString *string, SkString *other);
}

#endif //RAIA_SKIA_SK_STRING_H
