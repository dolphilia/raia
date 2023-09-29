//
//  util_string.c
//  raia-engine
//
//  Created by dolphilia on 2022/09/09.
//

#include "util_string.h"

/// ２つの文字列は一致するか
bool is_equal_string(char *s1, char *s2) {
    if(strcmp(s1, s2) == 0) {
        return true;
    } else {
        return false;
    }
}

/// char配列を指定の文字列に置き換える
void set_array_from_str(char* array, char* src) {
    int i;
    for (i = 0; i < (int)strlen(src); i++) {
        array[i] = src[i];
    }
    array[i] = '\0';
}

/// 文字列を結合する
char* str_join(const char* str1, const char* str2) {
    char* result = (char*)malloc((int)strlen(str1) + (int)strlen(str2));
#ifdef __WINDOWS__
    sprintf_s(result, "%s%s", str1, str2); // 文字列を結合する
#else
    sprintf(result, "%s%s", str1, str2); // 文字列を結合する
#endif
    return result;
}
