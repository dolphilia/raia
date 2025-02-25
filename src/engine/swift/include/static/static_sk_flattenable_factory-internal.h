#ifndef STATIC_SK_FLATTENABLE_FACTORY_INTERNAL_H
#define STATIC_SK_FLATTENABLE_FACTORY_INTERNAL_H
#include <set>
#include <map>
#include "include/core/SkFlattenable.h"
int static_sk_flattenable_factory_make(SkFlattenable::Factory value);
SkFlattenable::Factory static_sk_flattenable_factory_get_entity(int key);
#endif // STATIC_SK_FLATTENABLE_FACTORY_INTERNAL_H
