//
// Created by dolphilia on 2024/02/02.
//

#include "sk_encoded_origin.h"

extern "C" {

// static

int SkEncodedOrigin_SkEncodedOriginToMatrix(SkEncodedOrigin origin, int w, int h) {
    return static_sk_matrix_make(SkEncodedOriginToMatrix(origin, w, h));
}

bool SkEncodedOrigin_SkEncodedOriginSwapsWidthHeight(SkEncodedOrigin origin) {
    return SkEncodedOriginSwapsWidthHeight(origin);
}

}