//
// Created by dolphilia on 2024/01/10.
//

#ifndef RAIA_SKIA_SK_REF_CNT_BASE_H
#define RAIA_SKIA_SK_REF_CNT_BASE_H

#include "include/core/SkRefCnt.h"

extern "C" {
SkRefCntBase *SkRefCntBase_new();
void SkRefCntBase_delete(SkRefCntBase *ref_cnt_base);
bool SkRefCntBase_unique(SkRefCntBase *ref_cnt_base);
void SkRefCntBase_ref(SkRefCntBase *ref_cnt_base);
void SkRefCntBase_unref(SkRefCntBase *ref_cnt_base);
}

#endif //RAIA_SKIA_SK_REF_CNT_BASE_H
