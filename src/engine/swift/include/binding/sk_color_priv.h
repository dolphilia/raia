//
// Created by dolphilia on 2024/01/08.
//

#ifndef RAIA_SKIA_SK_COLOR_PRIV_H
#define RAIA_SKIA_SK_COLOR_PRIV_H

#ifdef __cplusplus
extern "C" {
#endif

// static
unsigned SkColorPriv_SkAlpha255To256(unsigned int alpha); // (U8CPU alpha) -> unsigned
unsigned int SkColorPriv_SkAlphaMulQ(unsigned int c, unsigned scale); // (uint32_t c, unsigned scale) -> uint32_t
unsigned int SkColorPriv_SkPackARGB32(unsigned int a, unsigned int r, unsigned int g, unsigned int b); // (U8CPU a, U8CPU r, U8CPU g, U8CPU b) -> SkPMColor
unsigned int SkColorPriv_SkPackARGB32NoCheck(unsigned int a, unsigned int r, unsigned int g, unsigned int b); // (U8CPU a, U8CPU r, U8CPU g, U8CPU b) -> SkPMColor
unsigned int SkColorPriv_SkPMSrcOver(unsigned int  src, unsigned int  dst); // (SkPMColor src, SkPMColor dst) -> SkPMColor
unsigned int SkColorPriv_SkPremultiplyARGBInline(unsigned int a, unsigned int r, unsigned int g, unsigned int b); // (U8CPU a, U8CPU r, U8CPU g, U8CPU b) -> SkPMColor
unsigned int SkColorPriv_SkUnitScalarClampToByte(float x); // (SkScalar x) -> U8CPU

#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_SK_COLOR_PRIV_H
