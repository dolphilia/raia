//
// Created by dolphilia on 2024/01/12.
//

#include "static_sk_id_change_listener.h"

static std::map<std::string, sk_sp<SkIDChangeListener>> static_sk_id_change_listener;

void static_sk_id_change_listener_delete(const char *key) {
    static_sk_id_change_listener[key].reset();
    static_sk_id_change_listener.erase(key);
}

SkIDChangeListener *static_sk_id_change_listener_get(const char *key) {
    return static_sk_id_change_listener[key].get();
}

void static_sk_id_change_listener_set(const char *key, sk_sp<SkIDChangeListener> value) {
    static_sk_id_change_listener[key] = std::move(value);
}

sk_sp<SkIDChangeListener> static_sk_id_change_listener_move(const char *key) {
    return std::move(static_sk_id_change_listener[key]);
}