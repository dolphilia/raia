//
// Created by dolphilia on 2024/01/08.
//

#include "sk_capabilities.h"

extern "C" {

void SkCapabilities_ref(SkCapabilities *capabilities) {
    capabilities->ref();
}

SkSL::Version SkCapabilities_skslVersion(SkCapabilities *capabilities) {
    return capabilities->skslVersion();
}

bool SkCapabilities_unique(SkCapabilities *capabilities) {
    return capabilities->unique();
}

void SkCapabilities_unref(SkCapabilities *capabilities) {
    capabilities->unref();
}

// static

void SkCapabilities_RasterBackend(const char *sk_capabilities_key_out) {
    static_const_sk_capabilities_set(sk_capabilities_key_out, SkCapabilities::RasterBackend());
}

}