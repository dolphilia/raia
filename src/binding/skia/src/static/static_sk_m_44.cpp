//
// Created by dolphilia on 2024/01/06.
//

#include "static_sk_m_44.h"

static std::map<int , SkM44> static_sk_m_44;

void static_sk_m_44_delete(int key) {
    static_sk_m_44.erase(key);
}

SkM44 static_sk_m_44_get(int key) {
    return static_sk_m_44[key];
}

void static_sk_m_44_set(int key, SkM44 value) {
    static_sk_m_44[key] = value;
}