//
// Created by dolphilia on 2024/01/08.
//

#ifndef RAIA_SKIA_SK_IMAGE_FILTERS_H
#define RAIA_SKIA_SK_IMAGE_FILTERS_H

#ifdef __cplusplus
extern "C" {
#endif

void SkImageFilters_delete(void *imageFilters); // (SkImageFilters *imageFilters)

// static

int SkImageFilters_Arithmetic(float k1, float k2, float k3, float k4, bool enforcePMColor, int background, int foreground, const void *cropRect); // (SkScalar k1, SkScalar k2, SkScalar k3, SkScalar k4, bool enforcePMColor, sk_image_filter_t background, sk_image_filter_t foreground, const SkImageFilters::CropRect *cropRect) -> sk_image_filter_t
int SkImageFilters_Blend(int mode, int background, int foreground, const void *cropRect); // (SkBlendMode mode, sk_image_filter_t background, sk_image_filter_t foreground, const SkImageFilters::CropRect *cropRect) -> sk_image_filter_t
int SkImageFilters_Blend_2(int blender, int background, int foreground, const void *cropRect); // (sk_blender_t blender, sk_image_filter_t background, sk_image_filter_t foreground, const SkImageFilters::CropRect *cropRect) -> sk_image_filter_t
int SkImageFilters_Blur(float sigmaX, float sigmaY, int tileMode, int input, const void *cropRect); // (SkScalar sigmaX, SkScalar sigmaY, SkTileMode tileMode, sk_image_filter_t input, const SkImageFilters::CropRect *cropRect) -> sk_image_filter_t
int SkImageFilters_Blur_2(float sigmaX, float sigmaY, int input, const void *cropRect); // (SkScalar sigmaX, SkScalar sigmaY, sk_image_filter_t input, const SkImageFilters::CropRect *cropRect) -> sk_image_filter_t
int SkImageFilters_ColorFilter(int cf, int input, const void *cropRect); // (sk_color_filter_t cf, sk_image_filter_t input, const SkImageFilters::CropRect *cropRect) -> sk_image_filter_t
int SkImageFilters_Compose(int outer, int inner); // (sk_image_filter_t outer, sk_image_filter_t inner) -> sk_image_filter_t
int SkImageFilters_Crop(const void *rect, int tileMode, int input); // (const SkRect *rect, SkTileMode tileMode, sk_image_filter_t input) -> sk_image_filter_t
int SkImageFilters_Crop_2(const void *rect, int input); // (const SkRect *rect, sk_image_filter_t input) -> sk_image_filter_t
int SkImageFilters_DisplacementMap(int xChannelSelector, int yChannelSelector, float scale, int displacement, int color, const void *cropRect); // (SkColorChannel xChannelSelector, SkColorChannel yChannelSelector, SkScalar scale, sk_image_filter_t displacement, sk_image_filter_t color, const SkImageFilters::CropRect *cropRect) -> sk_image_filter_t
int SkImageFilters_DropShadow(float dx, float dy, float sigmaX, float sigmaY, unsigned int color, int input, const void *cropRect); // (SkScalar dx, SkScalar dy, SkScalar sigmaX, SkScalar sigmaY, SkColor color, sk_image_filter_t input, const SkImageFilters::CropRect *cropRect) -> sk_image_filter_t
int SkImageFilters_DropShadowOnly(float dx, float dy, float sigmaX, float sigmaY, unsigned int color, int input, const void *cropRect); // (SkScalar dx, SkScalar dy, SkScalar sigmaX, SkScalar sigmaY, SkColor color, sk_image_filter_t input, const SkImageFilters::CropRect *cropRect) -> sk_image_filter_t
int SkImageFilters_Empty(); // () -> sk_image_filter_t
int SkImageFilters_Image(int image, const void *srcRect, const void *dstRect, const void *sampling); // (sk_image_t image, const SkRect *srcRect, const SkRect *dstRect, const SkSamplingOptions *sampling) -> sk_image_filter_t
int SkImageFilters_Image_2(int image, const void *sampling); // (sk_image_t image, const SkSamplingOptions *sampling) -> sk_image_filter_t
int SkImageFilters_Magnifier(const void *lensBounds, float zoomAmount, float inset, const void *sampling, int input, const void *cropRect); // (const SkRect *lensBounds, SkScalar zoomAmount, SkScalar inset, const SkSamplingOptions *sampling, sk_image_filter_t input, const SkImageFilters::CropRect *cropRect) -> sk_image_filter_t
int SkImageFilters_MatrixConvolution(const void *kernelSize, const void * kernel, float gain, float bias, const void *kernelOffset, int tileMode, bool convolveAlpha, int input, const void *cropRect); // (const SkISize *kernelSize, const SkScalar kernel[], SkScalar gain, SkScalar bias, const SkIPoint *kernelOffset, SkTileMode tileMode, bool convolveAlpha, sk_image_filter_t input, const SkImageFilters::CropRect *cropRect) -> sk_image_filter_t
int SkImageFilters_MatrixTransform(const void *matrix, const void *sampling, int input); // (const SkMatrix *matrix, const SkSamplingOptions *sampling, sk_image_filter_t input) -> sk_image_filter_t
int SkImageFilters_Merge(void *filters, int count, const void *cropRect); // (sk_sp<SkImageFilter> *filters, int count, const SkImageFilters::CropRect *cropRect) -> sk_image_filter_t
int SkImageFilters_Merge_2(int first, int second, const void *cropRect); // (sk_image_filter_t first, sk_image_filter_t second, const SkImageFilters::CropRect *cropRect) -> sk_image_filter_t
int SkImageFilters_Offset(float dx, float dy, int input, const void *cropRect); // (SkScalar dx, SkScalar dy, sk_image_filter_t input, const SkImageFilters::CropRect *cropRect) -> sk_image_filter_t
int SkImageFilters_Picture(int picture, const void *targetRect); // (sk_picture_t picture, const SkRect *targetRect) -> sk_image_filter_t
int SkImageFilters_Picture_2(int picture); // (sk_picture_t picture) -> sk_image_filter_t
int SkImageFilters_RuntimeShader(const void *builder, int childShaderName, int input); // (const SkRuntimeShaderBuilder *builder, string_view_t childShaderName, sk_image_filter_t input) -> sk_image_filter_t
int SkImageFilters_RuntimeShader_2(const void *builder, float sampleRadius, int childShaderName, int input); // (const SkRuntimeShaderBuilder *builder, SkScalar sampleRadius, string_view_t childShaderName, sk_image_filter_t input) -> sk_image_filter_t
int SkImageFilters_RuntimeShader_3(const void *builder, void * childShaderNames, const void *inputs, int inputCount); // (const SkRuntimeShaderBuilder *builder, std::string_view childShaderNames[], const sk_sp<SkImageFilter> *inputs, int inputCount) -> sk_image_filter_t
int SkImageFilters_RuntimeShader_4(const void *builder, float maxSampleRadius, void * childShaderNames, const void *inputs, int inputCount); // (const SkRuntimeShaderBuilder *builder, SkScalar maxSampleRadius, std::string_view childShaderNames[], const sk_sp<SkImageFilter> *inputs, int inputCount) -> sk_image_filter_t
int SkImageFilters_Shader(int shader, const void *cropRect); // (sk_shader_t shader, const SkImageFilters::CropRect *cropRect) -> sk_image_filter_t
int SkImageFilters_Shader_2(int shader, int dither, const void *cropRect); // (sk_shader_t shader, SkImageFilters::Dither dither, const SkImageFilters::CropRect *cropRect) -> sk_image_filter_t
int SkImageFilters_Tile(const void *src, const void *dst, int input); // (const SkRect *src, const SkRect *dst, sk_image_filter_t input) -> sk_image_filter_t
int SkImageFilters_Dilate(float radiusX, float radiusY, int input, const void *cropRect); // (SkScalar radiusX, SkScalar radiusY, sk_image_filter_t input, const SkImageFilters::CropRect *cropRect) -> sk_image_filter_t
int SkImageFilters_Erode(float radiusX, float radiusY, int input, const void *cropRect); // (SkScalar radiusX, SkScalar radiusY, sk_image_filter_t input, const SkImageFilters::CropRect *cropRect) -> sk_image_filter_t
int SkImageFilters_DistantLitDiffuse(const void *direction, unsigned int lightColor, float surfaceScale, float kd, int input, const void *cropRect); // (const SkPoint3 *direction, SkColor lightColor, SkScalar surfaceScale, SkScalar kd, sk_image_filter_t input, const SkImageFilters::CropRect *cropRect) -> sk_image_filter_t
int SkImageFilters_PointLitDiffuse(const void *location, unsigned int lightColor, float surfaceScale, float kd, int input, const void *cropRect); // (const SkPoint3 *location, SkColor lightColor, SkScalar surfaceScale, SkScalar kd, sk_image_filter_t input, const SkImageFilters::CropRect *cropRect) -> sk_image_filter_t
int SkImageFilters_SpotLitDiffuse(const void *location, const void *target, float falloffExponent, float cutoffAngle, unsigned int lightColor, float surfaceScale, float kd, int input, const void *cropRect); // (const SkPoint3 *location, const SkPoint3 *target, SkScalar falloffExponent, SkScalar cutoffAngle, SkColor lightColor, SkScalar surfaceScale, SkScalar kd, sk_image_filter_t input, const SkImageFilters::CropRect *cropRect) -> sk_image_filter_t
int SkImageFilters_DistantLitSpecular(const void *direction, unsigned int lightColor, float surfaceScale, float ks, float shininess, int input, const void *cropRect); // (const SkPoint3 *direction, SkColor lightColor, SkScalar surfaceScale, SkScalar ks, SkScalar shininess, sk_image_filter_t input, const SkImageFilters::CropRect *cropRect) -> sk_image_filter_t
int SkImageFilters_PointLitSpecular(const void *location, unsigned int lightColor, float surfaceScale, float ks, float shininess, int input, const void *cropRect); // (const SkPoint3 *location, SkColor lightColor, SkScalar surfaceScale, SkScalar ks, SkScalar shininess, sk_image_filter_t input, const SkImageFilters::CropRect *cropRect) -> sk_image_filter_t
int SkImageFilters_SpotLitSpecular(const void *location, const void *target, float falloffExponent, float cutoffAngle, unsigned int lightColor, float surfaceScale, float ks, float shininess, int input, const void *cropRect); // (const SkPoint3 *location, const SkPoint3 *target, SkScalar falloffExponent, SkScalar cutoffAngle, SkColor lightColor, SkScalar surfaceScale, SkScalar ks, SkScalar shininess, sk_image_filter_t input, const SkImageFilters::CropRect *cropRect) -> sk_image_filter_t

#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_SK_IMAGE_FILTERS_H
