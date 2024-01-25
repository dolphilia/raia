//
// Created by dolphilia on 2024/01/11.
//

#include "static_sk_shaper_font_run_iterator.h"

static std::map<int , std::unique_ptr<SkShaper::FontRunIterator>> static_sk_shaper_font_run_iterator;
static int static_sk_shaper_font_run_iterator_index = 0;

int static_sk_shaper_font_run_iterator_make(std::unique_ptr<SkShaper::FontRunIterator> value) {
    static_sk_shaper_font_run_iterator[static_sk_shaper_font_run_iterator_index] = std::move(value);
    static_sk_shaper_font_run_iterator_index++;
    return static_sk_shaper_font_run_iterator_index - 1;
}

void static_sk_shaper_font_run_iterator_delete(int key) {
    static_sk_shaper_font_run_iterator[key].reset();
    static_sk_shaper_font_run_iterator.erase(key);
}

SkShaper::FontRunIterator *static_sk_shaper_font_run_iterator_get(int key) {
    return static_sk_shaper_font_run_iterator[key].get();
}

void static_sk_shaper_font_run_iterator_set(int key, std::unique_ptr<SkShaper::FontRunIterator> value) {
    static_sk_shaper_font_run_iterator[key] = std::move(value);
}

std::unique_ptr<SkShaper::FontRunIterator> static_sk_shaper_font_run_iterator_move(int key) {
    return std::move(static_sk_shaper_font_run_iterator[key]);
}