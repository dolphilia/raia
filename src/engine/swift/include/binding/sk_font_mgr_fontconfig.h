//
// Created by dolphilia on 2024/01/31.
//

#ifndef RAIA_SKIA_SK_FONT_MGR_FONTCONFIG_H
#define RAIA_SKIA_SK_FONT_MGR_FONTCONFIG_H

#include "include/core/SkFontMgr.h"
#include "include/ports/SkFontMgr_fontconfig.h"
#include "../static/static_sk_font_mgr.h"

extern "C" {
RAIA_API int CSkia_SkFontMgr_New_FontConfig(FcConfig *fc);
}

#endif //RAIA_SKIA_SK_FONT_MGR_FONTCONFIG_H
