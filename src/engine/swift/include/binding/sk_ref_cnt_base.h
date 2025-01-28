//
// Created by dolphilia on 2024/01/10.
//

#ifndef RAIA_SKIA_SK_REF_CNT_BASE_H
#define RAIA_SKIA_SK_REF_CNT_BASE_H

#ifdef __cplusplus
extern "C" {
#endif

void *SkRefCntBase_new();
void SkRefCntBase_delete(void *ref_cnt_base);
bool SkRefCntBase_unique(void *ref_cnt_base);
void SkRefCntBase_ref(void *ref_cnt_base);
void SkRefCntBase_unref(void *ref_cnt_base);

#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_SK_REF_CNT_BASE_H
