//
// Created by dolphilia on 2024/01/11.
//

#include "sk_string.h"

extern "C" {

// SkString & operator=(const SkString &)
// SkString & operator=(SkString &&)
// SkString & operator=(const char text[])
// SkString & operator+=(const SkString &s)
// SkString & operator+=(const char text[])
// SkString & operator+=(const char c)
// char operator[](size_t n)
// char & operator[](size_t n)

SkString *SkString_new() {
    return new SkString();
}

SkString *SkString_new_2(size_t len) {
    return new SkString(len);
}

SkString *SkString_new_3(const char text[]) {
    return new SkString(text);
}

SkString *SkString_new_4(const char text[], size_t len) {
    return new SkString(text, len);
}

SkString *SkString_new_5(const SkString *str) {
    return new SkString(*str);
}

SkString *SkString_new_6(const std::string *str) {
    return new SkString(*str);
}

SkString *SkString_new_7(string_view_t view) {
    return new SkString(static_string_view_get(view));
}

void SkString_delete(SkString *string) {
    delete string;
}
bool SkString_isEmpty(SkString *string) {
    return string->isEmpty();
}

size_t SkString_size(SkString *string) {
    return string->size();
}

const char * SkString_data(SkString *string) {
    return string->data();
}

char * SkString_data_2(SkString *string) {
    return string->data();
}

const char * SkString_c_str(SkString *string) {
    return string->c_str();
}

bool SkString_equals(SkString *string, const SkString *str) {
    return string->equals(*str);
}

bool SkString_equals_2(SkString *string, const char text[]) {
    return string->equals(text);
}

bool SkString_equals_3(SkString *string, const char text[], size_t len) {
    return string->equals(text, len);
}

bool SkString_startsWith(SkString *string, const char prefixStr[]) {
    return string->startsWith(prefixStr);
}

bool SkString_startsWith_2(SkString *string, const char prefixChar) {
    return string->startsWith(prefixChar);
}

//bool SkString_endsWith(SkString *string, const char suffixStr[]) {
//    return string->endsWith(suffixStr);
//}

//bool SkString_endsWith_2(SkString *string, const char suffixChar) {
//    return string->endsWith(suffixChar);
//}

bool SkString_contains(SkString *string, const char substring[]) {
    return string->contains(substring);
}

bool SkString_contains_2(SkString *string, const char subchar) {
    return string->contains(subchar);
}

int SkString_find(SkString *string, const char substring[]) {
    return string->find(substring);
}

int SkString_findLastOf(SkString *string, const char subchar) {
    return string->findLastOf(subchar);
}

void SkString_reset(SkString *string) {
    string->reset();
}

void SkString_resize(SkString *string, size_t len) {
    string->resize(len);
}

void SkString_set(SkString *string, const SkString *src) {
    string->set(*src);
}

void SkString_set_2(SkString *string, const char text[]) {
    string->set(text);
}

void SkString_set_3(SkString *string, const char text[], size_t len) {
    string->set(text, len);
}

void SkString_set_4(SkString *string, string_view_t str) {
    string->set(static_string_view_get(str));
}

void SkString_insert(SkString *string, size_t offset, const char text[]) {
    string->insert(offset, text);
}

void SkString_insert_2(SkString *string, size_t offset, const char text[], size_t len) {
    string->insert(offset, text, len);
}

void SkString_insert_3(SkString *string, size_t offset, const SkString *str) {
    string->insert(offset, *str);
}

void SkString_insert_4(SkString *string, size_t offset, string_view_t str) {
    string->insert(offset, static_string_view_get(str));
}

void SkString_insertUnichar(SkString *string, size_t offset, SkUnichar unichar) {
    string->insertUnichar(offset, unichar);
}

void SkString_insertS32(SkString *string, size_t offset, int32_t value) {
    string->insertS32(offset, value);
}

void SkString_insertS64(SkString *string, size_t offset, int64_t value, int minDigits) {
    string->insertS64(offset, value, minDigits);
}

void SkString_insertU32(SkString *string, size_t offset, uint32_t value) {
    string->insertU32(offset, value);
}

void SkString_insertU64(SkString *string, size_t offset, uint64_t value, int minDigits) {
    string->insertU64(offset, value, minDigits);
}

void SkString_insertHex(SkString *string, size_t offset, uint32_t value, int minDigits) {
    string->insertHex(offset, value, minDigits);
}

void SkString_insertScalar(SkString *string, size_t offset, SkScalar v) {
    string->insertScalar(offset, v);
}

void SkString_append(SkString *string, const char text[]) {
    string->append(text);
}

void SkString_append_2(SkString *string, const char text[], size_t len) {
    string->append(text, len);
}

void SkString_append_3(SkString *string, const SkString *str) {
    string->append(*str);
}

void SkString_append_4(SkString *string, string_view_t str) {
    string->append(static_string_view_get(str));
}

void SkString_appendUnichar(SkString *string, SkUnichar uni) {
    string->appendUnichar(uni);
}

void SkString_appendS32(SkString *string, int32_t value) {
    string->appendS32(value);
}

void SkString_appendS64(SkString *string, int64_t value, int minDigits) {
    string->appendS64(value, minDigits);
}

void SkString_appendU32(SkString *string, uint32_t value) {
    string->appendU32(value);
}

void SkString_appendU64(SkString *string, uint64_t value, int minDigits) {
    string->appendU64(value, minDigits);
}

void SkString_appendHex(SkString *string, uint32_t value, int minDigits) {
    string->appendHex(value, minDigits);
}

void SkString_appendScalar(SkString *string, SkScalar value) {
    string->appendScalar(value);
}

void SkString_prepend(SkString *string, const char text[]) {
    string->prepend(text);
}

void SkString_prepend_2(SkString *string, const char text[], size_t len) {
    string->prepend(text, len);
}

void SkString_prepend_3(SkString *string, const SkString *str) {
    string->prepend(*str);
}

void SkString_prepend_4(SkString *string, string_view_t str) {
    string->prepend(static_string_view_get(str));
}

void SkString_prependUnichar(SkString *string, SkUnichar uni) {
    string->prependUnichar(uni);
}

void SkString_prependS32(SkString *string, int32_t value) {
    string->prependS32(value);
}

void SkString_prependS64(SkString *string, int32_t value, int minDigits) {
    string->prependS64(value, minDigits);
}

void SkString_prependHex(SkString *string, uint32_t value, int minDigits) {
    string->prependHex(value, minDigits);
}

void SkString_prependScalar(SkString *string, SkScalar value) {
    string->prependScalar(value);
}

// @TODO

//void SkString_printf(SkString *string, const char format[],...) {
//    string->
//}

//void SkString_printVAList(SkString *string, const char format[], va_list) {
//    string->
//}

//void SkString_appendf(SkString *string, const char format[],...)  {
//    string->
//}

//void SkString_appendVAList(SkString *string, const char format[], va_list) {
//    string->
//}

//void SkString_prependf(SkString *string, const char format[],...) {
//    string->
//}

//void SkString_prependVAList(SkString *string, const char format[], va_list) {
//    string->
//}

void SkString_remove(SkString *string, size_t offset, size_t length) {
    string->remove(offset, length);
}

void SkString_swap(SkString *string, SkString *other) {
    string->swap(*other);
}

}