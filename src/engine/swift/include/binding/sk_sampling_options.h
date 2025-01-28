//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_SK_SAMPLING_OPTIONS_H
#define RAIA_SKIA_SK_SAMPLING_OPTIONS_H

#ifdef __cplusplus
extern "C" {
#endif

//bool operator==(const SkSamplingOptions &other)
//bool operator!=(const SkSamplingOptions &other)
//SkSamplingOptions *SkSamplingOptions_new_3 & operator=(const SkSamplingOptions &that)

void *SkSamplingOptions_new(); // () -> SkSamplingOptions *
void *SkSamplingOptions_new_2(const void *options); // (const SkSamplingOptions *options) -> SkSamplingOptions *
void *SkSamplingOptions_new_3(int fm, int mm); // (SkFilterMode fm, SkMipmapMode mm) -> SkSamplingOptions *
void *SkSamplingOptions_new_4(int fm); // (SkFilterMode fm) -> SkSamplingOptions *
void *SkSamplingOptions_new_5(const void *c); // (const SkCubicResampler *c) -> SkSamplingOptions *
void SkSamplingOptions_delete(void *sampling_options); // (SkSamplingOptions *sampling_options)
bool SkSamplingOptions_isAniso(void *sampling_options); // (SkSamplingOptions *sampling_options) -> bool

// static

int SkSamplingOptions_Aniso(int maxAniso); // (int maxAniso) -> sk_sampling_options_t

#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_SK_SAMPLING_OPTIONS_H
