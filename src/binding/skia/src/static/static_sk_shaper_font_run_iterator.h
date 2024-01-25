//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_STATIC_SK_SHAPER_FONT_RUN_ITERATOR_H
#define RAIA_SKIA_STATIC_SK_SHAPER_FONT_RUN_ITERATOR_H

#include <string>
#include <map>
#include "modules/skshaper/include/SkShaper.h"

int static_sk_shaper_font_run_iterator_make(std::unique_ptr<SkShaper::FontRunIterator> value);
void static_sk_shaper_font_run_iterator_delete(int key);
SkShaper::FontRunIterator *static_sk_shaper_font_run_iterator_get(int key);
void static_sk_shaper_font_run_iterator_set(int key, std::unique_ptr<SkShaper::FontRunIterator> value);
std::unique_ptr<SkShaper::FontRunIterator> static_sk_shaper_font_run_iterator_move(int key);

#endif //RAIA_SKIA_STATIC_SK_SHAPER_FONT_RUN_ITERATOR_H
