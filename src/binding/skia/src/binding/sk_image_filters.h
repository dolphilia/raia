//
// Created by dolphilia on 2024/01/08.
//

#ifndef RAIA_SKIA_SK_IMAGE_FILTERS_H
#define RAIA_SKIA_SK_IMAGE_FILTERS_H

#include "include/core/SkBlender.h"
#include "include/effects/SkImageFilters.h"
#include "../static/static_sk_image_filter.h"
#include "../static/static_sk_color_filter.h"
#include "../static/static_sk_image.h"
#include "../static/static_sk_picture.h"
#include "../static/static_sk_shader.h"
#include "../static/static_sk_blender.h"

extern "C" {
void SkImageFilters_delete(SkImageFilters * imageFilters);
// static
int SkImageFilters_Arithmetic(int sk_image_filter_key_in_1, int sk_image_filter_key_in_2, SkScalar k1, SkScalar k2, SkScalar k3, SkScalar k4, bool enforcePMColor, const SkImageFilters::CropRect *cropRect);
int SkImageFilters_Blend(int sk_image_filter_key_in_1, int sk_image_filter_key_in_2, SkBlendMode mode, const SkImageFilters::CropRect *cropRect);
int SkImageFilters_Blend_2(int sk_blender_key_in, int sk_image_filter_key_in_1, int sk_image_filter_key_in_2, const SkImageFilters::CropRect *cropRect);
int SkImageFilters_Blur(int sk_image_filter_key_in, SkScalar sigmaX, SkScalar sigmaY, SkTileMode tileMode, const SkImageFilters::CropRect *cropRect);
int SkImageFilters_Blur_2(int sk_image_filter_key_in, SkScalar sigmaX, SkScalar sigmaY, const SkImageFilters::CropRect *cropRect);
int SkImageFilters_ColorFilter(int sk_image_color_key_in, int sk_image_filter_key_in, const SkImageFilters::CropRect *cropRect);
int SkImageFilters_Compose(int sk_image_filter_key_in_1, int sk_image_filter_key_in_2);
int SkImageFilters_Crop(int sk_image_filter_key_in, const SkRect *rect, SkTileMode tileMode);
int SkImageFilters_Crop_2(int sk_image_filter_key_in, const SkRect *rect);
int SkImageFilters_DisplacementMap(int sk_image_filter_key_in_1, int sk_image_filter_key_in_2, SkColorChannel xChannelSelector, SkColorChannel yChannelSelector, SkScalar scale, const SkImageFilters::CropRect *cropRect);
int SkImageFilters_DropShadow(int sk_image_filter_key_in, SkScalar dx, SkScalar dy, SkScalar sigmaX, SkScalar sigmaY, SkColor color, const SkImageFilters::CropRect *cropRect);
int SkImageFilters_DropShadowOnly(int sk_image_filter_key_in, SkScalar dx, SkScalar dy, SkScalar sigmaX, SkScalar sigmaY, SkColor color, const SkImageFilters::CropRect *cropRect);
int SkImageFilters_Empty();
int SkImageFilters_Image(int sk_image_key_in, const SkRect *srcRect, const SkRect *dstRect, const SkSamplingOptions *sampling);
int SkImageFilters_Image_2(int sk_image_key_in, const SkSamplingOptions *sampling);
int SkImageFilters_Magnifier(int sk_image_filter_key_in, const SkRect *lensBounds, SkScalar zoomAmount, SkScalar inset, const SkSamplingOptions *sampling, const SkImageFilters::CropRect *cropRect);
int SkImageFilters_MatrixConvolution(int sk_image_filter_key_in, const SkISize *kernelSize, const SkScalar kernel[], SkScalar gain, SkScalar bias, const SkIPoint *kernelOffset, SkTileMode tileMode, bool convolveAlpha, const SkImageFilters::CropRect *cropRect);
int SkImageFilters_MatrixTransform(int sk_image_filter_key_in, const SkMatrix *matrix, const SkSamplingOptions *sampling);
int SkImageFilters_Merge(sk_sp<SkImageFilter> *filters, int count, const SkImageFilters::CropRect *cropRect);
int SkImageFilters_Merge_2(int sk_image_filter_key_in_1, int sk_image_filter_key_in_2, const SkImageFilters::CropRect *cropRect);
int SkImageFilters_Offset(int sk_image_filter_key_in, SkScalar dx, SkScalar dy, const SkImageFilters::CropRect *cropRect);
int SkImageFilters_Picture(int sk_picture_key_in, const SkRect *targetRect);
int SkImageFilters_Picture_2(int sk_picture_key_in);
int SkImageFilters_RuntimeShader(int sk_image_filter_key_in, const SkRuntimeShaderBuilder *builder, std::string_view childShaderName);
int SkImageFilters_RuntimeShader_2(int sk_image_filter_key_in, const SkRuntimeShaderBuilder *builder, SkScalar sampleRadius, std::string_view childShaderName);
int SkImageFilters_RuntimeShader_3(const SkRuntimeShaderBuilder *builder, std::string_view childShaderNames[], const sk_sp<SkImageFilter> *inputs, int inputCount);
int SkImageFilters_RuntimeShader_4(const SkRuntimeShaderBuilder *builder, SkScalar maxSampleRadius, std::string_view childShaderNames[], const sk_sp<SkImageFilter> *inputs, int inputCount);
int SkImageFilters_Shader(int sk_shader_key_in, const SkImageFilters::CropRect *cropRect);
int SkImageFilters_Shader_2(int sk_shader_key_in, SkImageFilters::Dither dither, const SkImageFilters::CropRect *cropRect);
int SkImageFilters_Tile(int sk_image_filter_key_in, const SkRect *src, const SkRect *dst);
int SkImageFilters_Dilate(int sk_image_filter_key_in, SkScalar radiusX, SkScalar radiusY, const SkImageFilters::CropRect *cropRect);
int SkImageFilters_Erode(int sk_image_filter_key_in, SkScalar radiusX, SkScalar radiusY, const SkImageFilters::CropRect *cropRect);
int SkImageFilters_DistantLitDiffuse(int sk_image_filter_key_in, const SkPoint3 *direction, SkColor lightColor, SkScalar surfaceScale, SkScalar kd, const SkImageFilters::CropRect *cropRect);
int SkImageFilters_PointLitDiffuse(int sk_image_filter_key_in, const SkPoint3 *location, SkColor lightColor, SkScalar surfaceScale, SkScalar kd, const SkImageFilters::CropRect *cropRect);
int SkImageFilters_SpotLitDiffuse(int sk_image_filter_key_in, const SkPoint3 *location, const SkPoint3 *target, SkScalar falloffExponent, SkScalar cutoffAngle, SkColor lightColor, SkScalar surfaceScale, SkScalar kd, const SkImageFilters::CropRect *cropRect);
int SkImageFilters_DistantLitSpecular(int sk_image_filter_key_in, const SkPoint3 *direction, SkColor lightColor, SkScalar surfaceScale, SkScalar ks, SkScalar shininess, const SkImageFilters::CropRect *cropRect);
int SkImageFilters_PointLitSpecular(int sk_image_filter_key_in, const SkPoint3 *location, SkColor lightColor, SkScalar surfaceScale, SkScalar ks, SkScalar shininess, const SkImageFilters::CropRect *cropRect);
int SkImageFilters_SpotLitSpecular(int sk_image_filter_key_in, const SkPoint3 *location, const SkPoint3 *target, SkScalar falloffExponent, SkScalar cutoffAngle, SkColor lightColor, SkScalar surfaceScale, SkScalar ks, SkScalar shininess, const SkImageFilters::CropRect *cropRect);
}

#endif //RAIA_SKIA_SK_IMAGE_FILTERS_H
