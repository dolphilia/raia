//
// Created by dolphilia on 2024/01/11.
//

#include "static_sk_shaper_script_run_iterator.h"

static std::map<int , std::unique_ptr<SkShaper::ScriptRunIterator>> static_sk_shaper_script_run_iterator;

void static_sk_shaper_script_run_iterator_delete(int key) {
    static_sk_shaper_script_run_iterator[key].reset();
    static_sk_shaper_script_run_iterator.erase(key);
}

SkShaper::ScriptRunIterator *static_sk_shaper_script_run_iterator_get(int key) {
    return static_sk_shaper_script_run_iterator[key].get();
}

void static_sk_shaper_script_run_iterator_set(int key, std::unique_ptr<SkShaper::ScriptRunIterator> value) {
    static_sk_shaper_script_run_iterator[key] = std::move(value);
}

std::unique_ptr<SkShaper::ScriptRunIterator> static_sk_shaper_script_run_iterator_move(int key) {
    return std::move(static_sk_shaper_script_run_iterator[key]);
}