//
// Created by dolphilia on 2024/01/11.
//

#include "sk_sampling_options.h"
#include "../static/static_sk_sampling_options.h"

extern "C" {

//bool operator==(const SkSamplingOptions &other)
//bool operator!=(const SkSamplingOptions &other)
//SkSamplingOptions *SkSamplingOptions_new_3 & operator=(const SkSamplingOptions &that) {
//    return new SkSamplingOptions();
//}

SkSamplingOptions *SkSamplingOptions_new() {
    return new SkSamplingOptions();
}

SkSamplingOptions *SkSamplingOptions_new_2(const SkSamplingOptions *options) {
    return new SkSamplingOptions(*options);
}

SkSamplingOptions *SkSamplingOptions_new_3(SkFilterMode fm, SkMipmapMode mm) {
    return new SkSamplingOptions(fm, mm);
}

SkSamplingOptions *SkSamplingOptions_new_4(SkFilterMode fm) {
    return new SkSamplingOptions(fm);
}

SkSamplingOptions *SkSamplingOptions_new_5(const SkCubicResampler *c) {
    return new SkSamplingOptions(*c);
}

bool SkSamplingOptions_isAniso(SkSamplingOptions *sampling_options) {
    return sampling_options->isAniso();
}

// static

void SkSamplingOptions_Aniso(const char *sk_sampling_options_key_out, int maxAniso) {
    static_sk_sampling_options_set(sk_sampling_options_key_out, SkSamplingOptions::Aniso(maxAniso));
}

}