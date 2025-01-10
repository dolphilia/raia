//
// Created by dolphilia on 2024/01/08.
//

#ifndef RAIA_SKIA_SK_CAPABILITIES_H
#define RAIA_SKIA_SK_CAPABILITIES_H

#include "include/core/SkCapabilities.h"
#include "../static/static_sk_capabilities.h"

extern "C" {
void SkCapabilities_delete(SkCapabilities *capabilities);
void SkCapabilities_ref(SkCapabilities *capabilities);
SkSL::Version SkCapabilities_skslVersion(SkCapabilities *capabilities);
bool SkCapabilities_unique(SkCapabilities *capabilities);
void SkCapabilities_unref(SkCapabilities *capabilities);
// static
const_sk_capabilities_t SkCapabilities_RasterBackend();
}

#endif //RAIA_SKIA_SK_CAPABILITIES_H
