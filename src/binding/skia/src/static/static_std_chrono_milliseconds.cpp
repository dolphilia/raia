//
// Created by dolphilia on 2024/04/01.
//

#include "static_std_chrono_milliseconds.h"

static std::set<int> static_chrono_milliseconds_available_keys;
static std::map<int , std::chrono::milliseconds> static_chrono_milliseconds;
static int static_chrono_milliseconds_index = 0;

int static_chrono_milliseconds_make(std::chrono::milliseconds value) {
    int key;
    if (!static_chrono_milliseconds_available_keys.empty()) {
        auto it = static_chrono_milliseconds_available_keys.begin();
        key = *it;
        static_chrono_milliseconds_available_keys.erase(it);
    } else {
        key = static_chrono_milliseconds_index++;
    }
    static_chrono_milliseconds[key] = value;
    return key;
}

void static_chrono_milliseconds_delete(int key) {
    static_chrono_milliseconds.erase(key);
    static_chrono_milliseconds_available_keys.insert(key);
}

std::chrono::milliseconds static_chrono_milliseconds_get(int key) {
    return static_chrono_milliseconds[key];
}

void static_chrono_milliseconds_set(int key, std::chrono::milliseconds value) {
    static_chrono_milliseconds[key] = value;
}