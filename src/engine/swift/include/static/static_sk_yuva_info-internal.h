#ifndef STATIC_SK_YUVA_INFO_INTERNAL_H
#define STATIC_SK_YUVA_INFO_INTERNAL_H
#include <set>
#include <map>
#include "include/core/SkYUVAInfo.h"
int static_sk_yuva_info_make(SkYUVAInfo value);
SkYUVAInfo static_sk_yuva_info_get_entity(int key);
void static_sk_yuva_info_set(int key, SkYUVAInfo value);
#endif // STATIC_SK_YUVA_INFO_INTERNAL_H
