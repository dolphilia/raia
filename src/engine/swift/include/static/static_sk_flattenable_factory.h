//
// Created by dolphilia on 2024/04/02.
//

#ifndef RAIA_SKIA_STATIC_SK_FLATTENABLE_FACTORY_H
#define RAIA_SKIA_STATIC_SK_FLATTENABLE_FACTORY_H

#include <set>
#include <string>
#include <map>
#include "include/core/SkFlattenable.h"
#include "export_api.h"

typedef int sk_flattenable_factory_t;

extern "C" {
RAIA_API void static_sk_flattenable_factory_delete(int key);
}

int static_sk_flattenable_factory_make(SkFlattenable::Factory value);
SkFlattenable::Factory static_sk_flattenable_factory_get(int key);

#endif //RAIA_SKIA_STATIC_SK_FLATTENABLE_FACTORY_H
