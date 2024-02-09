//
// Created by dolphilia on 2024/01/30.
//

#include "sk_typeface_mac.h"

#ifdef __MACOS__

extern "C" {

sk_typeface_t Mac_SkMakeTypefaceFromCTFont(CTFontRef fontRef) {
    return static_sk_typeface_make(SkMakeTypefaceFromCTFont(fontRef));
}

CTFontRef Mac_SkTypeface_GetCTFontRef(const SkTypeface *face) {
    return SkTypeface_GetCTFontRef(face);
}

}

#endif