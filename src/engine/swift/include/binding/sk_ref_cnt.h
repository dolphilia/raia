//
// Created by dolphilia on 2024/01/10.
//

#ifndef RAIA_SKIA_SK_REF_CNT_H
#define RAIA_SKIA_SK_REF_CNT_H

#include "include/core/SkRefCnt.h"
#include "export_api.h"

extern "C" {
RAIA_API void SkRefCnt_delete(SkRefCnt* refCnt);
RAIA_API bool SkRefCnt_unique(SkRefCnt* ref_cnt);
RAIA_API void SkRefCnt_ref(SkRefCnt* ref_cnt);
RAIA_API void SkRefCnt_unref(SkRefCnt* ref_cnt);
}

#endif //RAIA_SKIA_SK_REF_CNT_H
