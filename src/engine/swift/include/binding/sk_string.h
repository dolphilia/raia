//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_SK_STRING_H
#define RAIA_SKIA_SK_STRING_H

#ifdef __cplusplus
extern "C" {
#endif

// SkString & operator=(const SkString &)
// SkString & operator=(SkString &&)
// SkString & operator=(const char text[])
// SkString & operator+=(const SkString &s)
// SkString & operator+=(const char text[])
// SkString & operator+=(const char c)
// char operator[](size_t n)
// char & operator[](size_t n)

void *SkString_new(); // () -> SkString *
void *SkString_new_2(unsigned long len); // (size_t len) -> SkString *
void *SkString_new_3(const char text[]); // (const char text[]) -> SkString *
void *SkString_new_4(const char text[], unsigned long len); // (const char text[], size_t len) -> SkString *
void *SkString_new_5(const void *str); // (const SkString *str) -> SkString *
void *SkString_new_6(const void *str); // (const std::string *str) -> SkString *
void *SkString_new_7(int view); // (string_view_t view) -> SkString *
void SkString_delete(void *string); // (SkString *string)
bool SkString_isEmpty(void *string); // (SkString *string) -> bool
unsigned long SkString_size(void *string); // (SkString *string) -> size_t
const char * SkString_data(void *string); // (SkString *string) -> const char *
char * SkString_data_2(void *string); // (SkString *string) -> char *
const char * SkString_c_str(void *string); // (SkString *string) -> const char *
bool SkString_equals(void *string, const void *str); // (SkString *string, const SkString *str) -> bool
bool SkString_equals_2(void *string, const char text[]); // (SkString *string, const char text[]) -> bool
bool SkString_equals_3(void *string, const char text[], unsigned long len); // (SkString *string, const char text[], size_t len) -> bool
bool SkString_startsWith(void *string, const char prefixStr[]); // (SkString *string, const char prefixStr[]) -> bool
bool SkString_startsWith_2(void *string, char prefixChar); // (SkString *string, char prefixChar) -> bool

//bool SkString_endsWith(SkString *string, const char suffixStr[]);
//bool SkString_endsWith_2(SkString *string, const char suffixChar);

bool SkString_contains(void *string, const char substring[]); // (SkString *string, const char substring[]) -> bool
bool SkString_contains_2(void *string, char subchar); // (SkString *string, char subchar) -> bool
int SkString_find(void *string, const char substring[]); // (SkString *string, const char substring[]) -> int
int SkString_findLastOf(void *string, char subchar); // (SkString *string, char subchar) -> int
void SkString_reset(void *string); // (SkString *string)
void SkString_resize(void *string, unsigned long len); // (SkString *string, size_t len)
void SkString_set(void *string, const void *src); // (SkString *string, const SkString *src)
void SkString_set_2(void *string, const char text[]); // (SkString *string, const char text[])
void SkString_set_3(void *string, const char text[], unsigned long len); // (SkString *string, const char text[], size_t len)
void SkString_set_4(void *string, int str); // (SkString *string, string_view_t str)
void SkString_insert(void *string, unsigned long offset, const char text[]); // (SkString *string, size_t offset, const char text[])
void SkString_insert_2(void *string, unsigned long offset, const char text[], unsigned long len); // (SkString *string, size_t offset, const char text[], size_t len)
void SkString_insert_3(void *string, unsigned long offset, const void *str); // (SkString *string, size_t offset, const SkString *str)
void SkString_insert_4(void *string, unsigned long offset, int str); // (SkString *string, size_t offset, string_view_t str)
void SkString_insertUnichar(void *string, unsigned long offset, int unichar); // (SkString *string, size_t offset, SkUnichar unichar)
void SkString_insertS32(void *string, unsigned long offset, int value); // (SkString *string, size_t offset, int32_t value)
void SkString_insertS64(void *string, unsigned long offset, long long value, int minDigits); // (SkString *string, size_t offset, int64_t value, int minDigits)
void SkString_insertU32(void *string, unsigned long offset, unsigned int value); // (SkString *string, size_t offset, uint32_t value)
void SkString_insertU64(void *string, unsigned long offset, unsigned long long value, int minDigits); // (SkString *string, size_t offset, uint64_t value, int minDigits)
void SkString_insertHex(void *string, unsigned long offset, unsigned int value, int minDigits); // (SkString *string, size_t offset, uint32_t value, int minDigits)
void SkString_insertScalar(void *string, unsigned long offset, float v); // (SkString *string, size_t offset, SkScalar v)
void SkString_append(void *string, const char text[]); // (SkString *string, const char text[])
void SkString_append_2(void *string, const char text[], unsigned long len); // (SkString *string, const char text[], size_t len)
void SkString_append_3(void *string, const void *str); // (SkString *string, const SkString *str)
void SkString_append_4(void *string, int str); // (SkString *string, string_view_t str)
void SkString_appendUnichar(void *string, int uni); // (SkString *string, SkUnichar uni)
void SkString_appendS32(void *string, int value); // (SkString *string, int32_t value)
void SkString_appendS64(void *string, long long value, int minDigits); // (SkString *string, int64_t value, int minDigits)
void SkString_appendU32(void *string, unsigned int value); // (SkString *string, uint32_t value)
void SkString_appendU64(void *string, unsigned long long value, int minDigits); // (SkString *string, uint64_t value, int minDigits)
void SkString_appendHex(void *string, unsigned int value, int minDigits); // (SkString *string, uint32_t value, int minDigits)
void SkString_appendScalar(void *string, float value); // (SkString *string, SkScalar value)
void SkString_prepend(void *string, const char text[]); // (SkString *string, const char text[])
void SkString_prepend_2(void *string, const char text[], unsigned long len); // (SkString *string, const char text[], size_t len)
void SkString_prepend_3(void *string, const void *str); // (SkString *string, const SkString *str)
void SkString_prepend_4(void *string, int str); // (SkString *string, string_view_t str)
void SkString_prependUnichar(void *string, int uni); // (SkString *string, SkUnichar uni)
void SkString_prependS32(void *string, int value); // (SkString *string, int32_t value)
void SkString_prependS64(void *string, int value, int minDigits); // (SkString *string, int32_t value, int minDigits)
void SkString_prependHex(void *string, unsigned int value, int minDigits); // (SkString *string, uint32_t value, int minDigits)
void SkString_prependScalar(void *string, float value); // (SkString *string, SkScalar value)

//void SkString_printf(SkString *string, const char format[],...);
//void SkString_printVAList(SkString *string, const char format[], va_list);
//void SkString_appendf(SkString *string, const char format[],...);
//void SkString_appendVAList(SkString *string, const char format[], va_list);
//void SkString_prependf(SkString *string, const char format[],...);
//void SkString_prependVAList(SkString *string, const char format[], va_list);

void SkString_remove(void *string, unsigned long offset, unsigned long length); // (SkString *string, size_t offset, size_t length)
void SkString_swap(void *string, void *other); // (SkString *string, SkString *other)

#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_SK_STRING_H
