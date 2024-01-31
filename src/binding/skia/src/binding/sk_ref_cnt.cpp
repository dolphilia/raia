//
// Created by dolphilia on 2024/01/10.
//

#include "sk_ref_cnt.h"

extern "C" {

void SkRefCnt_delete(SkRefCnt* refCnt) {
    delete refCnt;
}

bool SkRefCnt_unique(SkRefCnt* ref_cnt) {
    return ref_cnt->unique();
}

void SkRefCnt_ref(SkRefCnt* ref_cnt) {
    ref_cnt->ref();
}

void SkRefCnt_unref(SkRefCnt* ref_cnt) {
    ref_cnt->unref();
}

}