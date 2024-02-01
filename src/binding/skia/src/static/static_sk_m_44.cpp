//
// Created by dolphilia on 2024/01/06.
//

#include "static_sk_m_44.h"

static std::set<int> static_sk_m_44_available_keys;
static std::map<int , SkM44> static_sk_m_44;
static int static_sk_m_44_index = 0;

int static_sk_m_44_make(SkM44 value) {
    int key;
    if (!static_sk_m_44_available_keys.empty()) {
        auto it = static_sk_m_44_available_keys.begin();
        key = *it;
        static_sk_m_44_available_keys.erase(it);
    } else {
        key = static_sk_m_44_index++;
    }
    static_sk_m_44[key] = value;
    return key;
}

void static_sk_m_44_delete(int key) {
    static_sk_m_44.erase(key);
    static_sk_m_44_available_keys.insert(key);
}

SkM44 static_sk_m_44_get(int key) {
    return static_sk_m_44[key];
}

void static_sk_m_44_set(int key, SkM44 value) {
    static_sk_m_44[key] = value;
}