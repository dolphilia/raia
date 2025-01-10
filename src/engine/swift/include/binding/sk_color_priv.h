//
// Created by dolphilia on 2024/01/08.
//

#ifndef RAIA_SKIA_SK_COLOR_PRIV_H
#define RAIA_SKIA_SK_COLOR_PRIV_H

#include "include/core/SkColorPriv.h"

extern "C" {
// static
unsigned SkColorPriv_SkAlpha255To256(U8CPU alpha);
uint32_t SkColorPriv_SkAlphaMulQ(uint32_t c, unsigned scale);
SkPMColor SkColorPriv_SkPackARGB32(U8CPU a, U8CPU r, U8CPU g, U8CPU b);
SkPMColor SkColorPriv_SkPackARGB32NoCheck(U8CPU a, U8CPU r, U8CPU g, U8CPU b);
SkPMColor SkColorPriv_SkPMSrcOver(SkPMColor src, SkPMColor dst);
SkPMColor SkColorPriv_SkPremultiplyARGBInline(U8CPU a, U8CPU r, U8CPU g, U8CPU b);
U8CPU SkColorPriv_SkUnitScalarClampToByte(SkScalar x);
}

#endif //RAIA_SKIA_SK_COLOR_PRIV_H
