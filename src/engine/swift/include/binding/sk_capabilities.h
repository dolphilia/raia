//
// Created by dolphilia on 2024/01/08.
//

#ifndef RAIA_SKIA_SK_CAPABILITIES_H
#define RAIA_SKIA_SK_CAPABILITIES_H

#include "include/core/SkCapabilities.h"
#include "../static/static_sk_capabilities.h"
#include "export_api.h"

extern "C" {
RAIA_API void SkCapabilities_delete(SkCapabilities *capabilities);
RAIA_API void SkCapabilities_ref(SkCapabilities *capabilities);
RAIA_API SkSL::Version SkCapabilities_skslVersion(SkCapabilities *capabilities);
RAIA_API bool SkCapabilities_unique(SkCapabilities *capabilities);
RAIA_API void SkCapabilities_unref(SkCapabilities *capabilities);
// static
RAIA_API const_sk_capabilities_t SkCapabilities_RasterBackend();
}

#endif //RAIA_SKIA_SK_CAPABILITIES_H
