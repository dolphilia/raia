#ifndef STATIC_STD_STRING_VIEW_INTERNAL_H
#define STATIC_STD_STRING_VIEW_INTERNAL_H
#include <set>
#include <map>
int static_string_view_make(std::string_view value);
std::string_view static_string_view_get(int key);
void static_string_view_set(int key, std::string_view value);
#endif // STATIC_STD_STRING_VIEW_INTERNAL_H
