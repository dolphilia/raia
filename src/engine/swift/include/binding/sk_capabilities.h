//
// Created by dolphilia on 2024/01/08.
//

#ifndef RAIA_SKIA_SK_CAPABILITIES_H
#define RAIA_SKIA_SK_CAPABILITIES_H

#ifdef __cplusplus
extern "C" {
#endif

void SkCapabilities_delete(void * capabilities); // (SkCapabilities *capabilities)
void SkCapabilities_ref(void * capabilities); // (SkCapabilities *capabilities)
int SkCapabilities_skslVersion(void * capabilities); // (SkCapabilities *capabilities) -> SkSL::Version
bool SkCapabilities_unique(void * capabilities); // (SkCapabilities *capabilities) -> bool
void SkCapabilities_unref(void * capabilities); // (SkCapabilities *capabilities)

// static

int SkCapabilities_RasterBackend(); // () -> const_sk_capabilities_t

#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_SK_CAPABILITIES_H
