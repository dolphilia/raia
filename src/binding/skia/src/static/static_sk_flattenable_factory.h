//
// Created by dolphilia on 2024/04/02.
//

#ifndef RAIA_SKIA_STATIC_SK_FLATTENABLE_FACTORY_H
#define RAIA_SKIA_STATIC_SK_FLATTENABLE_FACTORY_H

#include <set>
#include <string>
#include <map>
#include "include/core/SkFlattenable.h"

typedef int sk_flattenable_factory_t;

int static_sk_flattenable_factory_make(SkFlattenable::Factory value);
extern "C" void static_sk_flattenable_factory_delete(int key);
SkFlattenable::Factory static_sk_flattenable_factory_get(int key);

#endif //RAIA_SKIA_STATIC_SK_FLATTENABLE_FACTORY_H
