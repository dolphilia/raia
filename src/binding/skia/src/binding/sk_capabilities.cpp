//
// Created by dolphilia on 2024/01/08.
//

#include "sk_capabilities.h"

extern "C" {

void SkCapabilities_delete(SkCapabilities *capabilities) {
    delete capabilities;
}

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

const_sk_capabilities_t SkCapabilities_RasterBackend() {
    return static_const_sk_capabilities_make(SkCapabilities::RasterBackend());
}

}