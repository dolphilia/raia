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
#include "../static/static_std_string_view.h"

extern "C" {
void SkImageFilters_delete(SkImageFilters * imageFilters);
// static
sk_image_filter_t SkImageFilters_Arithmetic(SkScalar k1, SkScalar k2, SkScalar k3, SkScalar k4, bool enforcePMColor, sk_image_filter_t background, sk_image_filter_t foreground, const SkImageFilters::CropRect *cropRect);
sk_image_filter_t SkImageFilters_Blend(SkBlendMode mode, sk_image_filter_t background, sk_image_filter_t foreground, const SkImageFilters::CropRect *cropRect);
sk_image_filter_t SkImageFilters_Blend_2(sk_blender_t blender, sk_image_filter_t background, sk_image_filter_t foreground, const SkImageFilters::CropRect *cropRect);
sk_image_filter_t SkImageFilters_Blur(SkScalar sigmaX, SkScalar sigmaY, SkTileMode tileMode, sk_image_filter_t input, const SkImageFilters::CropRect *cropRect);
sk_image_filter_t SkImageFilters_Blur_2(SkScalar sigmaX, SkScalar sigmaY, sk_image_filter_t input, const SkImageFilters::CropRect *cropRect);
sk_image_filter_t SkImageFilters_ColorFilter(sk_color_filter_t cf, sk_image_filter_t input, const SkImageFilters::CropRect *cropRect);
sk_image_filter_t SkImageFilters_Compose(sk_image_filter_t outer, sk_image_filter_t inner);
sk_image_filter_t SkImageFilters_Crop(const SkRect *rect, SkTileMode tileMode, sk_image_filter_t input);
sk_image_filter_t SkImageFilters_Crop_2(const SkRect *rect, sk_image_filter_t input);
sk_image_filter_t SkImageFilters_DisplacementMap(SkColorChannel xChannelSelector, SkColorChannel yChannelSelector, SkScalar scale, sk_image_filter_t displacement, sk_image_filter_t color, const SkImageFilters::CropRect *cropRect);
sk_image_filter_t SkImageFilters_DropShadow(SkScalar dx, SkScalar dy, SkScalar sigmaX, SkScalar sigmaY, SkColor color, sk_image_filter_t input, const SkImageFilters::CropRect *cropRect);
sk_image_filter_t SkImageFilters_DropShadowOnly(SkScalar dx, SkScalar dy, SkScalar sigmaX, SkScalar sigmaY, SkColor color, sk_image_filter_t input, const SkImageFilters::CropRect *cropRect);
sk_image_filter_t SkImageFilters_Empty();
sk_image_filter_t SkImageFilters_Image(sk_image_t image, const SkRect *srcRect, const SkRect *dstRect, const SkSamplingOptions *sampling);
sk_image_filter_t SkImageFilters_Image_2(sk_image_t image, const SkSamplingOptions *sampling);
sk_image_filter_t SkImageFilters_Magnifier(const SkRect *lensBounds, SkScalar zoomAmount, SkScalar inset, const SkSamplingOptions *sampling, sk_image_filter_t input, const SkImageFilters::CropRect *cropRect);
sk_image_filter_t SkImageFilters_MatrixConvolution(const SkISize *kernelSize, const SkScalar kernel[], SkScalar gain, SkScalar bias, const SkIPoint *kernelOffset, SkTileMode tileMode, bool convolveAlpha, sk_image_filter_t input, const SkImageFilters::CropRect *cropRect);
sk_image_filter_t SkImageFilters_MatrixTransform(const SkMatrix *matrix, const SkSamplingOptions *sampling, sk_image_filter_t input);
sk_image_filter_t SkImageFilters_Merge(sk_sp<SkImageFilter> *filters, int count, const SkImageFilters::CropRect *cropRect);
sk_image_filter_t SkImageFilters_Merge_2(sk_image_filter_t first, sk_image_filter_t second, const SkImageFilters::CropRect *cropRect);
sk_image_filter_t SkImageFilters_Offset(SkScalar dx, SkScalar dy, sk_image_filter_t input, const SkImageFilters::CropRect *cropRect);
sk_image_filter_t SkImageFilters_Picture(sk_picture_t picture, const SkRect *targetRect);
sk_image_filter_t SkImageFilters_Picture_2(sk_picture_t picture);
sk_image_filter_t SkImageFilters_RuntimeShader(const SkRuntimeShaderBuilder *builder, string_view_t childShaderName, sk_image_filter_t input);
sk_image_filter_t SkImageFilters_RuntimeShader_2(const SkRuntimeShaderBuilder *builder, SkScalar sampleRadius, string_view_t childShaderName, sk_image_filter_t input);
sk_image_filter_t SkImageFilters_RuntimeShader_3(const SkRuntimeShaderBuilder *builder, std::string_view childShaderNames[], const sk_sp<SkImageFilter> *inputs, int inputCount);
sk_image_filter_t SkImageFilters_RuntimeShader_4(const SkRuntimeShaderBuilder *builder, SkScalar maxSampleRadius, std::string_view childShaderNames[], const sk_sp<SkImageFilter> *inputs, int inputCount);
sk_image_filter_t SkImageFilters_Shader(sk_shader_t shader, const SkImageFilters::CropRect *cropRect);
sk_image_filter_t SkImageFilters_Shader_2(sk_shader_t shader, SkImageFilters::Dither dither, const SkImageFilters::CropRect *cropRect);
sk_image_filter_t SkImageFilters_Tile(const SkRect *src, const SkRect *dst, sk_image_filter_t input);
sk_image_filter_t SkImageFilters_Dilate(SkScalar radiusX, SkScalar radiusY, sk_image_filter_t input, const SkImageFilters::CropRect *cropRect);
sk_image_filter_t SkImageFilters_Erode(SkScalar radiusX, SkScalar radiusY, sk_image_filter_t input, const SkImageFilters::CropRect *cropRect);
sk_image_filter_t SkImageFilters_DistantLitDiffuse(const SkPoint3 *direction, SkColor lightColor, SkScalar surfaceScale, SkScalar kd, sk_image_filter_t input, const SkImageFilters::CropRect *cropRect);
sk_image_filter_t SkImageFilters_PointLitDiffuse(const SkPoint3 *location, SkColor lightColor, SkScalar surfaceScale, SkScalar kd, sk_image_filter_t input, const SkImageFilters::CropRect *cropRect);
sk_image_filter_t SkImageFilters_SpotLitDiffuse(const SkPoint3 *location, const SkPoint3 *target, SkScalar falloffExponent, SkScalar cutoffAngle, SkColor lightColor, SkScalar surfaceScale, SkScalar kd, sk_image_filter_t input, const SkImageFilters::CropRect *cropRect);
sk_image_filter_t SkImageFilters_DistantLitSpecular(const SkPoint3 *direction, SkColor lightColor, SkScalar surfaceScale, SkScalar ks, SkScalar shininess, sk_image_filter_t input, const SkImageFilters::CropRect *cropRect);
sk_image_filter_t SkImageFilters_PointLitSpecular(const SkPoint3 *location, SkColor lightColor, SkScalar surfaceScale, SkScalar ks, SkScalar shininess, sk_image_filter_t input, const SkImageFilters::CropRect *cropRect);
sk_image_filter_t SkImageFilters_SpotLitSpecular(const SkPoint3 *location, const SkPoint3 *target, SkScalar falloffExponent, SkScalar cutoffAngle, SkColor lightColor, SkScalar surfaceScale, SkScalar ks, SkScalar shininess, sk_image_filter_t input, const SkImageFilters::CropRect *cropRect);
}

#endif //RAIA_SKIA_SK_IMAGE_FILTERS_H
