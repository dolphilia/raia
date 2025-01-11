//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_SK_SAMPLING_OPTIONS_H
#define RAIA_SKIA_SK_SAMPLING_OPTIONS_H

#include "include/core/SkSamplingOptions.h"
#include "../static/static_sk_sampling_options.h"
#include "export_api.h"

extern "C" {
//bool operator==(const SkSamplingOptions &other)
//bool operator!=(const SkSamplingOptions &other)
//SkSamplingOptions *SkSamplingOptions_new_3 & operator=(const SkSamplingOptions &that) {
//    return new SkSamplingOptions();
//}
RAIA_API SkSamplingOptions *SkSamplingOptions_new();
RAIA_API SkSamplingOptions *SkSamplingOptions_new_2(const SkSamplingOptions *options);
RAIA_API SkSamplingOptions *SkSamplingOptions_new_3(SkFilterMode fm, SkMipmapMode mm);
RAIA_API SkSamplingOptions *SkSamplingOptions_new_4(SkFilterMode fm);
RAIA_API SkSamplingOptions *SkSamplingOptions_new_5(const SkCubicResampler *c);
RAIA_API void SkSamplingOptions_delete(SkSamplingOptions *sampling_options);
RAIA_API bool SkSamplingOptions_isAniso(SkSamplingOptions *sampling_options);
// static
RAIA_API sk_sampling_options_t SkSamplingOptions_Aniso(int maxAniso);
}

#endif //RAIA_SKIA_SK_SAMPLING_OPTIONS_H
