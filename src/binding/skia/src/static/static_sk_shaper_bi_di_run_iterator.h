//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_STATIC_SK_SHAPER_BI_DI_RUN_ITERATOR_H
#define RAIA_SKIA_STATIC_SK_SHAPER_BI_DI_RUN_ITERATOR_H

#include <string>
#include <map>
#include "modules/skshaper/include/SkShaper.h"

void static_sk_shaper_bi_di_run_iterator_delete(const char *key);
SkShaper::BiDiRunIterator *static_sk_shaper_bi_di_run_iterator_get(const char *key);
void static_sk_shaper_bi_di_run_iterator_set(const char *key, std::unique_ptr<SkShaper::BiDiRunIterator> value);
std::unique_ptr<SkShaper::BiDiRunIterator> static_sk_shaper_bi_di_run_iterator_move(const char *key);

#endif //RAIA_SKIA_STATIC_SK_SHAPER_BI_DI_RUN_ITERATOR_H
