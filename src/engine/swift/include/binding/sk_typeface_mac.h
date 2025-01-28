//
// Created by dolphilia on 2024/01/30.
//

#ifndef RAIA_SKIA_SK_TYPEFACE_MAC_H
#define RAIA_SKIA_SK_TYPEFACE_MAC_H

#ifdef __APPLE__
#ifdef TARGET_OS_MAC

#ifdef __cplusplus
extern "C" {
#endif

int Mac_SkMakeTypefaceFromCTFont(void * fontRef); // (CTFontRef fontRef) -> sk_typeface_t
const void * Mac_SkTypeface_GetCTFontRef(const void *face); // (const SkTypeface *face) -> CTFontRef

#ifdef __cplusplus
}
#endif

#endif
#endif

#endif //RAIA_SKIA_SK_TYPEFACE_MAC_H
