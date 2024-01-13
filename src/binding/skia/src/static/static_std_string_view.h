//
// Created by dolphilia on 2024/01/12.
//

#ifndef RAIA_SKIA_STATIC_STD_STRING_VIEW_H
#define RAIA_SKIA_STATIC_STD_STRING_VIEW_H

#include <string>
#include <map>

void static_string_view_delete(const char *key);
std::string_view static_string_view_get(const char *key);
void static_string_view_set(const char *key, std::string_view value);

#endif //RAIA_SKIA_STATIC_STD_STRING_VIEW_H
