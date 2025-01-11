//
// Created by dolphilia on 2024/01/10.
//

#ifndef RAIA_SKIA_SK_REF_CNT_BASE_H
#define RAIA_SKIA_SK_REF_CNT_BASE_H

#include "include/core/SkRefCnt.h"
#include "export_api.h"

extern "C" {
RAIA_API SkRefCntBase *SkRefCntBase_new();
RAIA_API void SkRefCntBase_delete(SkRefCntBase *ref_cnt_base);
RAIA_API bool SkRefCntBase_unique(SkRefCntBase *ref_cnt_base);
RAIA_API void SkRefCntBase_ref(SkRefCntBase *ref_cnt_base);
RAIA_API void SkRefCntBase_unref(SkRefCntBase *ref_cnt_base);
}

#endif //RAIA_SKIA_SK_REF_CNT_BASE_H
