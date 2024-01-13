//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_SK_SAMPLING_OPTIONS_H
#define RAIA_SKIA_SK_SAMPLING_OPTIONS_H

#include "include/core/SkSamplingOptions.h"

extern "C" {
//bool operator==(const SkSamplingOptions &other)
//bool operator!=(const SkSamplingOptions &other)
//SkSamplingOptions *SkSamplingOptions_new_3 & operator=(const SkSamplingOptions &that) {
//    return new SkSamplingOptions();
//}
SkSamplingOptions *SkSamplingOptions_new();
SkSamplingOptions *SkSamplingOptions_new_2(const SkSamplingOptions *options);
SkSamplingOptions *SkSamplingOptions_new_3(SkFilterMode fm, SkMipmapMode mm);
SkSamplingOptions *SkSamplingOptions_new_4(SkFilterMode fm);
SkSamplingOptions *SkSamplingOptions_new_5(const SkCubicResampler *c);
bool SkSamplingOptions_isAniso(SkSamplingOptions *sampling_options);
// static
void SkSamplingOptions_Aniso(const char *sk_sampling_options_key_out, int maxAniso);
}

#endif //RAIA_SKIA_SK_SAMPLING_OPTIONS_H
