//
// Created by dolphilia on 2024/01/12.
//

#include "static_sk_id_change_listener.h"

static std::map<int , sk_sp<SkIDChangeListener>> static_sk_id_change_listener;

void static_sk_id_change_listener_delete(int key) {
    static_sk_id_change_listener[key].reset();
    static_sk_id_change_listener.erase(key);
}

SkIDChangeListener *static_sk_id_change_listener_get(int key) {
    return static_sk_id_change_listener[key].get();
}

void static_sk_id_change_listener_set(int key, sk_sp<SkIDChangeListener> value) {
    static_sk_id_change_listener[key] = std::move(value);
}

sk_sp<SkIDChangeListener> static_sk_id_change_listener_move(int key) {
    return std::move(static_sk_id_change_listener[key]);
}