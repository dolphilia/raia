//
// Created by dolphilia on 2024/01/30.
//

#ifndef RAIA_SKIA_SK_TYPEFACE_MAC_H
#define RAIA_SKIA_SK_TYPEFACE_MAC_H

#include "../../../common/c/utility/platform.h"

#ifdef __MACOS__
#include "include/ports/SkTypeface_mac.h"
#include <CoreText/CoreText.h>
extern "C" {
int Mac_SkMakeTypefaceFromCTFont(CTFontRef fontRef);
CTFontRef Mac_SkTypeface_GetCTFontRef(const SkTypeface *face);
}
#endif

#endif //RAIA_SKIA_SK_TYPEFACE_MAC_H
