//
// Created by dolphilia on 2024/01/08.
//

#include "sk_color_priv.h"

extern "C" {

// static

unsigned SkColorPriv_SkAlpha255To256(U8CPU alpha) {
    return SkAlpha255To256(alpha);
}

uint32_t SkColorPriv_SkAlphaMulQ(uint32_t c, unsigned scale) {
    return SkAlphaMulQ(c, scale);
}

SkPMColor SkColorPriv_SkPackARGB32(U8CPU a, U8CPU r, U8CPU g, U8CPU b) {
    return SkPackARGB32(a, r, g, b);
}

SkPMColor SkColorPriv_SkPackARGB32NoCheck(U8CPU a, U8CPU r, U8CPU g, U8CPU b) {
    return SkPackARGB32NoCheck(a, r, g, b);
}

SkPMColor SkColorPriv_SkPMSrcOver(SkPMColor src, SkPMColor dst) {
    return SkPMSrcOver(src, dst);
}

SkPMColor SkColorPriv_SkPremultiplyARGBInline(U8CPU a, U8CPU r, U8CPU g, U8CPU b) {
    return SkPremultiplyARGBInline(a, r, g, b);
}

U8CPU SkColorPriv_SkUnitScalarClampToByte(SkScalar x) {
    return SkUnitScalarClampToByte(x);
}

}