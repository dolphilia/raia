//
// Created by dolphilia on 2024/01/08.
//

#include "sk_image_filters.h"

extern "C" {

// static

void SkImageFilters_Arithmetic(const char *sk_image_filter_key_out, const char *sk_image_filter_key_in_1, const char *sk_image_filter_key_in_2, SkScalar k1, SkScalar k2, SkScalar k3, SkScalar k4, bool enforcePMColor, const SkImageFilters::CropRect *cropRect) {
    static_sk_image_filter_set(sk_image_filter_key_out, SkImageFilters::Arithmetic(k1, k2, k3, k4, enforcePMColor, static_sk_image_filter_move(sk_image_filter_key_in_1), static_sk_image_filter_move(sk_image_filter_key_in_2), *cropRect));
}

void SkImageFilters_Blend(const char *sk_image_filter_key_out, const char *sk_image_filter_key_in_1, const char *sk_image_filter_key_in_2, SkBlendMode mode, const SkImageFilters::CropRect *cropRect) {
    static_sk_image_filter_set(sk_image_filter_key_out, SkImageFilters::Blend(mode, static_sk_image_filter_move(sk_image_filter_key_in_1), static_sk_image_filter_move(sk_image_filter_key_in_2), *cropRect));
}

void SkImageFilters_Blend_2(const char *sk_image_filter_key_out, const char *sk_blender_key_in, const char *sk_image_filter_key_in_1, const char *sk_image_filter_key_in_2, const SkImageFilters::CropRect *cropRect) {
    static_sk_image_filter_set(sk_image_filter_key_out, SkImageFilters::Blend(static_sk_blender_move(sk_blender_key_in), static_sk_image_filter_move(sk_image_filter_key_in_1), static_sk_image_filter_move(sk_image_filter_key_in_2), *cropRect));
}

void SkImageFilters_Blur(const char *sk_image_filter_key_out, const char *sk_image_filter_key_in, SkScalar sigmaX, SkScalar sigmaY, SkTileMode tileMode, const SkImageFilters::CropRect *cropRect) {
    static_sk_image_filter_set(sk_image_filter_key_out, SkImageFilters::Blur(sigmaX, sigmaY, tileMode, static_sk_image_filter_move(sk_image_filter_key_in), *cropRect));
}

void SkImageFilters_Blur_2(const char *sk_image_filter_key_out, const char *sk_image_filter_key_in, SkScalar sigmaX, SkScalar sigmaY, const SkImageFilters::CropRect *cropRect) {
    static_sk_image_filter_set(sk_image_filter_key_out, SkImageFilters::Blur(sigmaX, sigmaY, static_sk_image_filter_move(sk_image_filter_key_in), *cropRect));
}

void SkImageFilters_ColorFilter(const char *sk_image_filter_key_out, const char *sk_image_color_key_in, const char *sk_image_filter_key_in, const SkImageFilters::CropRect *cropRect) {
    static_sk_image_filter_set(sk_image_filter_key_out, SkImageFilters::ColorFilter(static_sk_color_filter_move(sk_image_color_key_in), static_sk_image_filter_move(sk_image_filter_key_in), *cropRect));
}

void SkImageFilters_Compose(const char *sk_image_filter_key_out, const char *sk_image_filter_key_in_1, const char *sk_image_filter_key_in_2) {
    static_sk_image_filter_set(sk_image_filter_key_out, SkImageFilters::Compose(static_sk_image_filter_move(sk_image_filter_key_in_1), static_sk_image_filter_move(sk_image_filter_key_in_2)));
}

void SkImageFilters_Crop(const char *sk_image_filter_key_out, const char *sk_image_filter_key_in, const SkRect *rect, SkTileMode tileMode) {
    static_sk_image_filter_set(sk_image_filter_key_out, SkImageFilters::Crop(*rect, tileMode, static_sk_image_filter_move(sk_image_filter_key_in)));
}

void SkImageFilters_Crop_2(const char *sk_image_filter_key_out, const char *sk_image_filter_key_in, const SkRect *rect) {
    static_sk_image_filter_set(sk_image_filter_key_out, SkImageFilters::Crop(*rect, static_sk_image_filter_move(sk_image_filter_key_in)));
}

void SkImageFilters_DisplacementMap(const char *sk_image_filter_key_out, const char *sk_image_filter_key_in_1, const char *sk_image_filter_key_in_2, SkColorChannel xChannelSelector, SkColorChannel yChannelSelector, SkScalar scale, const SkImageFilters::CropRect *cropRect) {
    static_sk_image_filter_set(sk_image_filter_key_out, SkImageFilters::DisplacementMap(xChannelSelector, yChannelSelector, scale, static_sk_image_filter_move(sk_image_filter_key_in_1), static_sk_image_filter_move(sk_image_filter_key_in_2), *cropRect));
}

void SkImageFilters_DropShadow(const char *sk_image_filter_key_out, const char *sk_image_filter_key_in, SkScalar dx, SkScalar dy, SkScalar sigmaX, SkScalar sigmaY, SkColor color, const SkImageFilters::CropRect *cropRect) {
    static_sk_image_filter_set(sk_image_filter_key_out, SkImageFilters::DropShadow(dx, dy, sigmaX, sigmaY, color, static_sk_image_filter_move(sk_image_filter_key_in), *cropRect));
}

void SkImageFilters_DropShadowOnly(const char *sk_image_filter_key_out, const char *sk_image_filter_key_in, SkScalar dx, SkScalar dy, SkScalar sigmaX, SkScalar sigmaY, SkColor color, const SkImageFilters::CropRect *cropRect) {
    static_sk_image_filter_set(sk_image_filter_key_out, SkImageFilters::DropShadowOnly(dx, dy, sigmaX, sigmaY, color, static_sk_image_filter_move(sk_image_filter_key_in), *cropRect));
}

void SkImageFilters_Empty(const char *sk_image_filter_key_out) {
    static_sk_image_filter_set(sk_image_filter_key_out, SkImageFilters::Empty());
}

void SkImageFilters_Image(const char *sk_image_filter_key_out, const char *sk_image_key_in, const SkRect *srcRect, const SkRect *dstRect, const SkSamplingOptions *sampling) {
    static_sk_image_filter_set(sk_image_filter_key_out, SkImageFilters::Image(static_sk_image_move(sk_image_key_in), *srcRect, *dstRect, *sampling));
}

void SkImageFilters_Image_2(const char *sk_image_filter_key_out, const char *sk_image_key_in, const SkSamplingOptions *sampling) {
    static_sk_image_filter_set(sk_image_filter_key_out, SkImageFilters::Image(static_sk_image_move(sk_image_key_in), *sampling));
}

void SkImageFilters_Magnifier(const char *sk_image_filter_key_out, const char *sk_image_filter_key_in, const SkRect *lensBounds, SkScalar zoomAmount, SkScalar inset, const SkSamplingOptions *sampling, const SkImageFilters::CropRect *cropRect) {
    static_sk_image_filter_set(sk_image_filter_key_out, SkImageFilters::Magnifier(*lensBounds, zoomAmount, inset, *sampling, static_sk_image_filter_move(sk_image_filter_key_in), *cropRect));
}

void SkImageFilters_MatrixConvolution(const char *sk_image_filter_key_out, const char *sk_image_filter_key_in, const SkISize *kernelSize, const SkScalar kernel[], SkScalar gain, SkScalar bias, const SkIPoint *kernelOffset, SkTileMode tileMode, bool convolveAlpha, const SkImageFilters::CropRect *cropRect) {
    static_sk_image_filter_set(sk_image_filter_key_out, SkImageFilters::MatrixConvolution(*kernelSize, kernel, gain, bias, *kernelOffset, tileMode, convolveAlpha, static_sk_image_filter_move(sk_image_filter_key_in), *cropRect));
}

void SkImageFilters_MatrixTransform(const char *sk_image_filter_key_out, const char *sk_image_filter_key_in, const SkMatrix *matrix, const SkSamplingOptions *sampling) {
    static_sk_image_filter_set(sk_image_filter_key_out, SkImageFilters::MatrixTransform(*matrix, *sampling, static_sk_image_filter_move(sk_image_filter_key_in)));
}

void SkImageFilters_Merge(const char *sk_image_filter_key_out, sk_sp<SkImageFilter> *filters, int count, const SkImageFilters::CropRect *cropRect) {
    static_sk_image_filter_set(sk_image_filter_key_out, SkImageFilters::Merge(filters, count, *cropRect));
}

void SkImageFilters_Merge_2(const char *sk_image_filter_key_out, const char *sk_image_filter_key_in_1, const char *sk_image_filter_key_in_2, const SkImageFilters::CropRect *cropRect) {
    static_sk_image_filter_set(sk_image_filter_key_out, SkImageFilters::Merge(static_sk_image_filter_move(sk_image_filter_key_in_1), static_sk_image_filter_move(sk_image_filter_key_in_2), *cropRect));
}

void SkImageFilters_Offset(const char *sk_image_filter_key_out, const char *sk_image_filter_key_in, SkScalar dx, SkScalar dy, const SkImageFilters::CropRect *cropRect) {
    static_sk_image_filter_set(sk_image_filter_key_out, SkImageFilters::Offset(dx, dy, static_sk_image_filter_move(sk_image_filter_key_in), *cropRect));
}

void SkImageFilters_Picture(const char *sk_image_filter_key_out, const char *sk_picture_key_in, const SkRect *targetRect) {
    static_sk_image_filter_set(sk_image_filter_key_out, SkImageFilters::Picture(static_sk_picture_move(sk_picture_key_in), *targetRect));
}

void SkImageFilters_Picture_2(const char *sk_image_filter_key_out, const char *sk_picture_key_in) {
    static_sk_image_filter_set(sk_image_filter_key_out, SkImageFilters::Picture(static_sk_picture_move(sk_picture_key_in)));
}

void SkImageFilters_RuntimeShader(const char *sk_image_filter_key_out, const char *sk_image_filter_key_in, const SkRuntimeShaderBuilder *builder, std::string_view childShaderName) {
    static_sk_image_filter_set(sk_image_filter_key_out, SkImageFilters::RuntimeShader(*builder, childShaderName, static_sk_image_filter_move(sk_image_filter_key_in)));
}

void SkImageFilters_RuntimeShader_2(const char *sk_image_filter_key_out, const char *sk_image_filter_key_in, const SkRuntimeShaderBuilder *builder, SkScalar sampleRadius, std::string_view childShaderName) {
    static_sk_image_filter_set(sk_image_filter_key_out, SkImageFilters::RuntimeShader(*builder, sampleRadius, childShaderName, static_sk_image_filter_move(sk_image_filter_key_in)));
}

void SkImageFilters_RuntimeShader_3(const char *sk_image_filter_key_out, const SkRuntimeShaderBuilder *builder, std::string_view childShaderNames[], const sk_sp<SkImageFilter> *inputs, int inputCount) {
    static_sk_image_filter_set(sk_image_filter_key_out, SkImageFilters::RuntimeShader(*builder, childShaderNames, inputs, inputCount));
}

void SkImageFilters_RuntimeShader_4(const char *sk_image_filter_key_out, const SkRuntimeShaderBuilder *builder, SkScalar maxSampleRadius, std::string_view childShaderNames[], const sk_sp<SkImageFilter> *inputs, int inputCount) {
    static_sk_image_filter_set(sk_image_filter_key_out, SkImageFilters::RuntimeShader(*builder, maxSampleRadius, childShaderNames, inputs, inputCount));
}

void SkImageFilters_Shader(const char *sk_image_filter_key_out, const char *sk_shader_key_in, const SkImageFilters::CropRect *cropRect) {
    static_sk_image_filter_set(sk_image_filter_key_out, SkImageFilters::Shader(static_sk_shader_move(sk_shader_key_in), *cropRect));
}

void SkImageFilters_Shader_2(const char *sk_image_filter_key_out, const char *sk_shader_key_in, SkImageFilters::Dither dither, const SkImageFilters::CropRect *cropRect) {
    static_sk_image_filter_set(sk_image_filter_key_out, SkImageFilters::Shader(static_sk_shader_move(sk_shader_key_in), dither, *cropRect));
}

void SkImageFilters_Tile(const char *sk_image_filter_key_out, const char *sk_image_filter_key_in, const SkRect *src, const SkRect *dst) {
    static_sk_image_filter_set(sk_image_filter_key_out, SkImageFilters::Tile(*src, *dst, static_sk_image_filter_move(sk_image_filter_key_in)));
}

void SkImageFilters_Dilate(const char *sk_image_filter_key_out, const char *sk_image_filter_key_in, SkScalar radiusX, SkScalar radiusY, const SkImageFilters::CropRect *cropRect) {
    static_sk_image_filter_set(sk_image_filter_key_out, SkImageFilters::Dilate(radiusX, radiusY, static_sk_image_filter_move(sk_image_filter_key_in), *cropRect));
}

void SkImageFilters_Erode(const char *sk_image_filter_key_out, const char *sk_image_filter_key_in, SkScalar radiusX, SkScalar radiusY, const SkImageFilters::CropRect *cropRect) {
    static_sk_image_filter_set(sk_image_filter_key_out, SkImageFilters::Erode(radiusX, radiusY, static_sk_image_filter_move(sk_image_filter_key_in), *cropRect));
}

void SkImageFilters_DistantLitDiffuse(const char *sk_image_filter_key_out, const char *sk_image_filter_key_in, const SkPoint3 *direction, SkColor lightColor, SkScalar surfaceScale, SkScalar kd, const SkImageFilters::CropRect *cropRect) {
    static_sk_image_filter_set(sk_image_filter_key_out, SkImageFilters::DistantLitDiffuse(*direction, lightColor, surfaceScale, kd, static_sk_image_filter_move(sk_image_filter_key_in), *cropRect));
}

void SkImageFilters_PointLitDiffuse(const char *sk_image_filter_key_out, const char *sk_image_filter_key_in, const SkPoint3 *location, SkColor lightColor, SkScalar surfaceScale, SkScalar kd, const SkImageFilters::CropRect *cropRect) {
    static_sk_image_filter_set(sk_image_filter_key_out, SkImageFilters::PointLitDiffuse(*location, lightColor, surfaceScale, kd, static_sk_image_filter_move(sk_image_filter_key_in), *cropRect));
}

void SkImageFilters_SpotLitDiffuse(const char *sk_image_filter_key_out, const char *sk_image_filter_key_in, const SkPoint3 *location, const SkPoint3 *target, SkScalar falloffExponent, SkScalar cutoffAngle, SkColor lightColor, SkScalar surfaceScale, SkScalar kd, const SkImageFilters::CropRect *cropRect) {
    static_sk_image_filter_set(sk_image_filter_key_out, SkImageFilters::SpotLitDiffuse(*location, *target, falloffExponent, cutoffAngle, lightColor, surfaceScale, kd, static_sk_image_filter_move(sk_image_filter_key_in), *cropRect));
}

void SkImageFilters_DistantLitSpecular(const char *sk_image_filter_key_out, const char *sk_image_filter_key_in, const SkPoint3 *direction, SkColor lightColor, SkScalar surfaceScale, SkScalar ks, SkScalar shininess, const SkImageFilters::CropRect *cropRect) {
    static_sk_image_filter_set(sk_image_filter_key_out, SkImageFilters::DistantLitSpecular(*direction, lightColor, surfaceScale, ks, shininess, static_sk_image_filter_move(sk_image_filter_key_in), *cropRect));
}

void SkImageFilters_PointLitSpecular(const char *sk_image_filter_key_out, const char *sk_image_filter_key_in, const SkPoint3 *location, SkColor lightColor, SkScalar surfaceScale, SkScalar ks, SkScalar shininess, const SkImageFilters::CropRect *cropRect) {
    static_sk_image_filter_set(sk_image_filter_key_out, SkImageFilters::PointLitSpecular(*location, lightColor, surfaceScale, ks, shininess, static_sk_image_filter_move(sk_image_filter_key_in), *cropRect));
}

void SkImageFilters_SpotLitSpecular(const char *sk_image_filter_key_out, const char *sk_image_filter_key_in, const SkPoint3 *location, const SkPoint3 *target, SkScalar falloffExponent, SkScalar cutoffAngle, SkColor lightColor, SkScalar surfaceScale, SkScalar ks, SkScalar shininess, const SkImageFilters::CropRect *cropRect) {
    static_sk_image_filter_set(sk_image_filter_key_out, SkImageFilters::SpotLitSpecular(*location, *target, falloffExponent, cutoffAngle, lightColor, surfaceScale, ks, shininess, static_sk_image_filter_move(sk_image_filter_key_in), *cropRect));
}

}