//
// Created by dolphilia on 2024/01/08.
//

#include "sk_image_filters.h"

extern "C" {

void SkImageFilters_delete(SkImageFilters * imageFilters) {
    delete imageFilters;
}

// static

sk_image_filter_t SkImageFilters_Arithmetic(SkScalar k1, SkScalar k2, SkScalar k3, SkScalar k4, bool enforcePMColor, sk_image_filter_t background, sk_image_filter_t foreground, const SkImageFilters::CropRect *cropRect) {
    return static_sk_image_filter_make(SkImageFilters::Arithmetic(k1, k2, k3, k4, enforcePMColor, static_sk_image_filter_move(background), static_sk_image_filter_move(foreground), *cropRect));
}

sk_image_filter_t SkImageFilters_Blend(SkBlendMode mode, sk_image_filter_t background, sk_image_filter_t foreground, const SkImageFilters::CropRect *cropRect) {
    return static_sk_image_filter_make(SkImageFilters::Blend(mode, static_sk_image_filter_move(background), static_sk_image_filter_move(foreground), *cropRect));
}

sk_image_filter_t SkImageFilters_Blend_2(sk_blender_t blender, sk_image_filter_t background, sk_image_filter_t foreground, const SkImageFilters::CropRect *cropRect) {
    return static_sk_image_filter_make(SkImageFilters::Blend(static_sk_blender_move(blender), static_sk_image_filter_move(background), static_sk_image_filter_move(foreground), *cropRect));
}

sk_image_filter_t SkImageFilters_Blur(SkScalar sigmaX, SkScalar sigmaY, SkTileMode tileMode, sk_image_filter_t input, const SkImageFilters::CropRect *cropRect) {
    return static_sk_image_filter_make(SkImageFilters::Blur(sigmaX, sigmaY, tileMode, static_sk_image_filter_move(input), *cropRect));
}

sk_image_filter_t SkImageFilters_Blur_2(SkScalar sigmaX, SkScalar sigmaY, sk_image_filter_t input, const SkImageFilters::CropRect *cropRect) {
    return static_sk_image_filter_make(SkImageFilters::Blur(sigmaX, sigmaY, static_sk_image_filter_move(input), *cropRect));
}

sk_image_filter_t SkImageFilters_ColorFilter(sk_color_filter_t cf, sk_image_filter_t input, const SkImageFilters::CropRect *cropRect) {
    return static_sk_image_filter_make(SkImageFilters::ColorFilter(static_sk_color_filter_move(cf), static_sk_image_filter_move(input), *cropRect));
}

sk_image_filter_t SkImageFilters_Compose(sk_image_filter_t outer, sk_image_filter_t inner) {
    return static_sk_image_filter_make(SkImageFilters::Compose(static_sk_image_filter_move(outer), static_sk_image_filter_move(inner)));
}

sk_image_filter_t SkImageFilters_Crop(const SkRect *rect, SkTileMode tileMode, sk_image_filter_t input) {
    return static_sk_image_filter_make(SkImageFilters::Crop(*rect, tileMode, static_sk_image_filter_move(input)));
}

sk_image_filter_t SkImageFilters_Crop_2(const SkRect *rect, sk_image_filter_t input) {
    return static_sk_image_filter_make(SkImageFilters::Crop(*rect, static_sk_image_filter_move(input)));
}

sk_image_filter_t SkImageFilters_DisplacementMap(SkColorChannel xChannelSelector, SkColorChannel yChannelSelector, SkScalar scale, sk_image_filter_t displacement, sk_image_filter_t color, const SkImageFilters::CropRect *cropRect) {
    return static_sk_image_filter_make(SkImageFilters::DisplacementMap(xChannelSelector, yChannelSelector, scale, static_sk_image_filter_move(displacement), static_sk_image_filter_move(color), *cropRect));
}

sk_image_filter_t SkImageFilters_DropShadow(SkScalar dx, SkScalar dy, SkScalar sigmaX, SkScalar sigmaY, SkColor color, sk_image_filter_t input, const SkImageFilters::CropRect *cropRect) {
    return static_sk_image_filter_make(SkImageFilters::DropShadow(dx, dy, sigmaX, sigmaY, color, static_sk_image_filter_move(input), *cropRect));
}

sk_image_filter_t SkImageFilters_DropShadowOnly(SkScalar dx, SkScalar dy, SkScalar sigmaX, SkScalar sigmaY, SkColor color, sk_image_filter_t input, const SkImageFilters::CropRect *cropRect) {
    return static_sk_image_filter_make(SkImageFilters::DropShadowOnly(dx, dy, sigmaX, sigmaY, color, static_sk_image_filter_move(input), *cropRect));
}

sk_image_filter_t SkImageFilters_Empty() {
    return static_sk_image_filter_make(SkImageFilters::Empty());
}

sk_image_filter_t SkImageFilters_Image(sk_image_t image, const SkRect *srcRect, const SkRect *dstRect, const SkSamplingOptions *sampling) {
    return static_sk_image_filter_make(SkImageFilters::Image(static_sk_image_move(image), *srcRect, *dstRect, *sampling));
}

sk_image_filter_t SkImageFilters_Image_2(sk_image_t image, const SkSamplingOptions *sampling) {
    return static_sk_image_filter_make(SkImageFilters::Image(static_sk_image_move(image), *sampling));
}

sk_image_filter_t SkImageFilters_Magnifier(const SkRect *lensBounds, SkScalar zoomAmount, SkScalar inset, const SkSamplingOptions *sampling, sk_image_filter_t input, const SkImageFilters::CropRect *cropRect) {
    return static_sk_image_filter_make(SkImageFilters::Magnifier(*lensBounds, zoomAmount, inset, *sampling, static_sk_image_filter_move(input), *cropRect));
}

sk_image_filter_t SkImageFilters_MatrixConvolution(const SkISize *kernelSize, const SkScalar kernel[], SkScalar gain, SkScalar bias, const SkIPoint *kernelOffset, SkTileMode tileMode, bool convolveAlpha, sk_image_filter_t input, const SkImageFilters::CropRect *cropRect) {
    return static_sk_image_filter_make(SkImageFilters::MatrixConvolution(*kernelSize, kernel, gain, bias, *kernelOffset, tileMode, convolveAlpha, static_sk_image_filter_move(input), *cropRect));
}

sk_image_filter_t SkImageFilters_MatrixTransform(const SkMatrix *matrix, const SkSamplingOptions *sampling, sk_image_filter_t input) {
    return static_sk_image_filter_make(SkImageFilters::MatrixTransform(*matrix, *sampling, static_sk_image_filter_move(input)));
}

sk_image_filter_t SkImageFilters_Merge(sk_sp<SkImageFilter> *filters, int count, const SkImageFilters::CropRect *cropRect) {
    return static_sk_image_filter_make(SkImageFilters::Merge(filters, count, *cropRect));
}

sk_image_filter_t SkImageFilters_Merge_2(sk_image_filter_t first, sk_image_filter_t second, const SkImageFilters::CropRect *cropRect) {
    return static_sk_image_filter_make(SkImageFilters::Merge(static_sk_image_filter_move(first), static_sk_image_filter_move(second), *cropRect));
}

sk_image_filter_t SkImageFilters_Offset(SkScalar dx, SkScalar dy, sk_image_filter_t input, const SkImageFilters::CropRect *cropRect) {
    return static_sk_image_filter_make(SkImageFilters::Offset(dx, dy, static_sk_image_filter_move(input), *cropRect));
}

sk_image_filter_t SkImageFilters_Picture(sk_picture_t picture, const SkRect *targetRect) {
    return static_sk_image_filter_make(SkImageFilters::Picture(static_sk_picture_move(picture), *targetRect));
}

sk_image_filter_t SkImageFilters_Picture_2(sk_picture_t picture) {
    return static_sk_image_filter_make(SkImageFilters::Picture(static_sk_picture_move(picture)));
}

sk_image_filter_t SkImageFilters_RuntimeShader(const SkRuntimeShaderBuilder *builder, string_view_t childShaderName, sk_image_filter_t input) {
    return static_sk_image_filter_make(SkImageFilters::RuntimeShader(*builder, static_string_view_get(childShaderName), static_sk_image_filter_move(input)));
}

sk_image_filter_t SkImageFilters_RuntimeShader_2(const SkRuntimeShaderBuilder *builder, SkScalar sampleRadius, string_view_t childShaderName, sk_image_filter_t input) {
    return static_sk_image_filter_make(SkImageFilters::RuntimeShader(*builder, sampleRadius, static_string_view_get(childShaderName), static_sk_image_filter_move(input)));
}

sk_image_filter_t SkImageFilters_RuntimeShader_3(const SkRuntimeShaderBuilder *builder, std::string_view childShaderNames[], const sk_sp<SkImageFilter> *inputs, int inputCount) {
    return static_sk_image_filter_make(SkImageFilters::RuntimeShader(*builder, childShaderNames, inputs, inputCount));
}

sk_image_filter_t SkImageFilters_RuntimeShader_4(const SkRuntimeShaderBuilder *builder, SkScalar maxSampleRadius, std::string_view childShaderNames[], const sk_sp<SkImageFilter> *inputs, int inputCount) {
    return static_sk_image_filter_make(SkImageFilters::RuntimeShader(*builder, maxSampleRadius, childShaderNames, inputs, inputCount));
}

sk_image_filter_t SkImageFilters_Shader(sk_shader_t shader, const SkImageFilters::CropRect *cropRect) {
    return static_sk_image_filter_make(SkImageFilters::Shader(static_sk_shader_move(shader), *cropRect));
}

sk_image_filter_t SkImageFilters_Shader_2(sk_shader_t shader, SkImageFilters::Dither dither, const SkImageFilters::CropRect *cropRect) {
    return static_sk_image_filter_make(SkImageFilters::Shader(static_sk_shader_move(shader), dither, *cropRect));
}

sk_image_filter_t SkImageFilters_Tile(const SkRect *src, const SkRect *dst, sk_image_filter_t input) {
    return static_sk_image_filter_make(SkImageFilters::Tile(*src, *dst, static_sk_image_filter_move(input)));
}

sk_image_filter_t SkImageFilters_Dilate(SkScalar radiusX, SkScalar radiusY, sk_image_filter_t input, const SkImageFilters::CropRect *cropRect) {
    return static_sk_image_filter_make(SkImageFilters::Dilate(radiusX, radiusY, static_sk_image_filter_move(input), *cropRect));
}

sk_image_filter_t SkImageFilters_Erode(SkScalar radiusX, SkScalar radiusY, sk_image_filter_t input, const SkImageFilters::CropRect *cropRect) {
    return static_sk_image_filter_make(SkImageFilters::Erode(radiusX, radiusY, static_sk_image_filter_move(input), *cropRect));
}

sk_image_filter_t SkImageFilters_DistantLitDiffuse(const SkPoint3 *direction, SkColor lightColor, SkScalar surfaceScale, SkScalar kd, sk_image_filter_t input, const SkImageFilters::CropRect *cropRect) {
    return static_sk_image_filter_make(SkImageFilters::DistantLitDiffuse(*direction, lightColor, surfaceScale, kd, static_sk_image_filter_move(input), *cropRect));
}

sk_image_filter_t SkImageFilters_PointLitDiffuse(const SkPoint3 *location, SkColor lightColor, SkScalar surfaceScale, SkScalar kd, sk_image_filter_t input, const SkImageFilters::CropRect *cropRect) {
    return static_sk_image_filter_make(SkImageFilters::PointLitDiffuse(*location, lightColor, surfaceScale, kd, static_sk_image_filter_move(input), *cropRect));
}

sk_image_filter_t SkImageFilters_SpotLitDiffuse(const SkPoint3 *location, const SkPoint3 *target, SkScalar falloffExponent, SkScalar cutoffAngle, SkColor lightColor, SkScalar surfaceScale, SkScalar kd, sk_image_filter_t input, const SkImageFilters::CropRect *cropRect) {
    return static_sk_image_filter_make(SkImageFilters::SpotLitDiffuse(*location, *target, falloffExponent, cutoffAngle, lightColor, surfaceScale, kd, static_sk_image_filter_move(input), *cropRect));
}

sk_image_filter_t SkImageFilters_DistantLitSpecular(const SkPoint3 *direction, SkColor lightColor, SkScalar surfaceScale, SkScalar ks, SkScalar shininess, sk_image_filter_t input, const SkImageFilters::CropRect *cropRect) {
    return static_sk_image_filter_make(SkImageFilters::DistantLitSpecular(*direction, lightColor, surfaceScale, ks, shininess, static_sk_image_filter_move(input), *cropRect));
}

sk_image_filter_t SkImageFilters_PointLitSpecular(const SkPoint3 *location, SkColor lightColor, SkScalar surfaceScale, SkScalar ks, SkScalar shininess, sk_image_filter_t input, const SkImageFilters::CropRect *cropRect) {
    return static_sk_image_filter_make(SkImageFilters::PointLitSpecular(*location, lightColor, surfaceScale, ks, shininess, static_sk_image_filter_move(input), *cropRect));
}

sk_image_filter_t SkImageFilters_SpotLitSpecular(const SkPoint3 *location, const SkPoint3 *target, SkScalar falloffExponent, SkScalar cutoffAngle, SkColor lightColor, SkScalar surfaceScale, SkScalar ks, SkScalar shininess, sk_image_filter_t input, const SkImageFilters::CropRect *cropRect) {
    return static_sk_image_filter_make(SkImageFilters::SpotLitSpecular(*location, *target, falloffExponent, cutoffAngle, lightColor, surfaceScale, ks, shininess, static_sk_image_filter_move(input), *cropRect));
}

}