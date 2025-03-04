//
// Created by dolphilia on 2024/01/05.
//

#ifndef RAIA_SKIA_STATIC_SK_FONT_MGR_H
#define RAIA_SKIA_STATIC_SK_FONT_MGR_H

#ifdef __cplusplus
extern "C" {
#endif
typedef int sk_font_mgr_t;
void static_sk_font_mgr_delete(int key);
void *static_sk_font_mgr_get_ptr(int key); // -> SkFontMgr *
#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_STATIC_SK_FONT_MGR_H
