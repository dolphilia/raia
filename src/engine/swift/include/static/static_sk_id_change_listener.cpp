//
// Created by dolphilia on 2024/01/12.
//

#include "static_sk_id_change_listener.h"

#include <utility>
#include "static_sk_id_change_listener-internal.h"

static std::set<int> static_sk_id_change_listener_available_keys;
static std::map<int , sk_sp<SkIDChangeListener>> static_sk_id_change_listener;
static int static_sk_id_change_listener_index = 0;

int static_sk_id_change_listener_make(sk_sp<SkIDChangeListener> value) {
    int key;
    if (!static_sk_id_change_listener_available_keys.empty()) {
        auto it = static_sk_id_change_listener_available_keys.begin();
        key = *it;
        static_sk_id_change_listener_available_keys.erase(it);
    } else {
        key = static_sk_id_change_listener_index++;
    }
    static_sk_id_change_listener[key] = std::move(value);
    return key;
}

void static_sk_id_change_listener_delete(int key) {
    static_sk_id_change_listener[key].reset();
    static_sk_id_change_listener.erase(key);
    static_sk_id_change_listener_available_keys.insert(key);
}

void *static_sk_id_change_listener_get(int key) { // -> SkIDChangeListener *
    return static_sk_id_change_listener[key].get();
}

void static_sk_id_change_listener_set(int key, sk_sp<SkIDChangeListener> value) {
    static_sk_id_change_listener[key] = std::move(value);
}

sk_sp<SkIDChangeListener> static_sk_id_change_listener_move(int key) {
    return std::move(static_sk_id_change_listener[key]);
}
