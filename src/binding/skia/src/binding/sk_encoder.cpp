//
// Created by dolphilia on 2024/02/01.
//

#include "sk_encoder.h"

extern "C" {

void SkEncoder_delete(SkEncoder *encoder) {
    delete encoder;
}

bool SkEncoder_encodeRows(SkEncoder *encoder, int numRows) {
    return encoder->encodeRows(numRows);
}

}