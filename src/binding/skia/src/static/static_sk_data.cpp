//
// Created by dolphilia on 2024/01/05.
//

#include "static_sk_data.h"

#include <utility>

static std::map<int , sk_sp<SkData>> static_sk_data;
static std::map<int , sk_sp<const SkData>> static_const_sk_data;
static int static_sk_data_index = 0;
static int static_const_sk_data_index = 0;

int static_sk_data_make(sk_sp<SkData> value) {
    static_sk_data[static_sk_data_index] = std::move(value);
    static_sk_data_index++;
    return static_sk_data_index - 1;
}

void static_sk_data_delete(int key) {
    static_sk_data[key].reset();
    static_sk_data.erase(key);
}

SkData *static_sk_data_get(int key) {
    return static_sk_data[key].get();
}

void static_sk_data_set(int key, sk_sp<SkData> value) {
    static_sk_data[key] = std::move(value);
}

sk_sp<SkData> static_sk_data_move(int key) {
    return std::move(static_sk_data[key]);
}

// const

int static_const_sk_data_make(sk_sp<const SkData> value) {
    static_const_sk_data[static_const_sk_data_index] = std::move(value);
    static_const_sk_data_index++;
    return static_const_sk_data_index - 1;
}


void static_const_sk_data_delete(int key) {
    static_const_sk_data[key].reset();
    static_const_sk_data.erase(key);
}

const SkData *static_const_sk_data_get(int key) {
    return static_const_sk_data[key].get();
}

void static_const_sk_data_set(int key, sk_sp<const SkData> value) {
    static_const_sk_data[key] = std::move(value);
}

sk_sp<const SkData> static_const_sk_data_move(int key) {
    return std::move(static_const_sk_data[key]);
}