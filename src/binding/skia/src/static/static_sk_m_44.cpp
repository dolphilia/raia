//
// Created by dolphilia on 2024/01/06.
//

#include "static_sk_m_44.h"

static std::map<std::string, SkM44> static_sk_m_44;

void static_sk_m_44_delete(const char *key) {
    static_sk_m_44.erase(key);
}

SkM44 static_sk_m_44_get(const char *key) {
    return static_sk_m_44[key];
}

void static_sk_m_44_set(const char *key, SkM44 value) {
    static_sk_m_44[key] = value;
}