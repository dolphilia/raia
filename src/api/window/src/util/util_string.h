//
//  util_string.h
//  raia-engine
//
//  Created by dolphilia on 2022/09/09.
//

#ifndef util_string_h
#define util_string_h

#include "../../../../../common/c/utility/platform.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

bool is_equal_string(char *s1, char *s2);
void set_array_from_str(char* array, char* src);
char* str_join(const char* str1, const char* str2);

#endif /* util_string_h */
