//
// Created by dolphilia on 2024/01/05.
//

#include "static_sk_data.h"

static std::map<std::string, sk_sp<SkData>> static_sk_data;
static std::map<std::string, sk_sp<const SkData>> static_const_sk_data;

void static_sk_data_delete(const char *key) {
    static_sk_data[key].reset();
    static_sk_data.erase(key);
}

SkData *static_sk_data_get(const char *key) {
    return static_sk_data[key].get();
}

void static_sk_data_set(const char *key, sk_sp<SkData> value) {
    static_sk_data[key] = std::move(value);
}

sk_sp<SkData> static_sk_data_move(const char *key) {
    return std::move(static_sk_data[key]);
}