//
// Created by dolphilia on 2024/01/10.
//

#include "sk_ref_cnt_base.h"

extern "C" {

SkRefCntBase *SkRefCntBase_new() {
    return new SkRefCntBase();
}

void SkRefCntBase_delete(SkRefCntBase *ref_cnt_base) {
    delete ref_cnt_base;
}

bool SkRefCntBase_unique(SkRefCntBase *ref_cnt_base) {
    return ref_cnt_base->unique();
}

void SkRefCntBase_ref(SkRefCntBase *ref_cnt_base) {
    ref_cnt_base->ref();
}

void SkRefCntBase_unref(SkRefCntBase *ref_cnt_base) {
    ref_cnt_base->unref();
}

}