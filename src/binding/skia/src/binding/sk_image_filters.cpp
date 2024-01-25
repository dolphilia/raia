//
// Created by dolphilia on 2024/01/08.
//

#include "sk_image_filters.h"

extern "C" {

// static

int SkImageFilters_Arithmetic(int sk_image_filter_key_in_1, int sk_image_filter_key_in_2, SkScalar k1, SkScalar k2, SkScalar k3, SkScalar k4, bool enforcePMColor, const SkImageFilters::CropRect *cropRect) {
    return static_sk_image_filter_make(SkImageFilters::Arithmetic(k1, k2, k3, k4, enforcePMColor, static_sk_image_filter_move(sk_image_filter_key_in_1), static_sk_image_filter_move(sk_image_filter_key_in_2), *cropRect));
}

int SkImageFilters_Blend(int sk_image_filter_key_in_1, int sk_image_filter_key_in_2, SkBlendMode mode, const SkImageFilters::CropRect *cropRect) {
    return static_sk_image_filter_make(SkImageFilters::Blend(mode, static_sk_image_filter_move(sk_image_filter_key_in_1), static_sk_image_filter_move(sk_image_filter_key_in_2), *cropRect));
}

int SkImageFilters_Blend_2(int sk_blender_key_in, int sk_image_filter_key_in_1, int sk_image_filter_key_in_2, const SkImageFilters::CropRect *cropRect) {
    return static_sk_image_filter_make(SkImageFilters::Blend(static_sk_blender_move(sk_blender_key_in), static_sk_image_filter_move(sk_image_filter_key_in_1), static_sk_image_filter_move(sk_image_filter_key_in_2), *cropRect));
}

int SkImageFilters_Blur(int sk_image_filter_key_in, SkScalar sigmaX, SkScalar sigmaY, SkTileMode tileMode, const SkImageFilters::CropRect *cropRect) {
    return static_sk_image_filter_make(SkImageFilters::Blur(sigmaX, sigmaY, tileMode, static_sk_image_filter_move(sk_image_filter_key_in), *cropRect));
}

int SkImageFilters_Blur_2(int sk_image_filter_key_in, SkScalar sigmaX, SkScalar sigmaY, const SkImageFilters::CropRect *cropRect) {
    return static_sk_image_filter_make(SkImageFilters::Blur(sigmaX, sigmaY, static_sk_image_filter_move(sk_image_filter_key_in), *cropRect));
}

int SkImageFilters_ColorFilter(int sk_image_color_key_in, int sk_image_filter_key_in, const SkImageFilters::CropRect *cropRect) {
    return static_sk_image_filter_make(SkImageFilters::ColorFilter(static_sk_color_filter_move(sk_image_color_key_in), static_sk_image_filter_move(sk_image_filter_key_in), *cropRect));
}

int SkImageFilters_Compose(int sk_image_filter_key_in_1, int sk_image_filter_key_in_2) {
    return static_sk_image_filter_make(SkImageFilters::Compose(static_sk_image_filter_move(sk_image_filter_key_in_1), static_sk_image_filter_move(sk_image_filter_key_in_2)));
}

int SkImageFilters_Crop(int sk_image_filter_key_in, const SkRect *rect, SkTileMode tileMode) {
    return static_sk_image_filter_make(SkImageFilters::Crop(*rect, tileMode, static_sk_image_filter_move(sk_image_filter_key_in)));
}

int SkImageFilters_Crop_2(int sk_image_filter_key_in, const SkRect *rect) {
    return static_sk_image_filter_make(SkImageFilters::Crop(*rect, static_sk_image_filter_move(sk_image_filter_key_in)));
}

int SkImageFilters_DisplacementMap(int sk_image_filter_key_in_1, int sk_image_filter_key_in_2, SkColorChannel xChannelSelector, SkColorChannel yChannelSelector, SkScalar scale, const SkImageFilters::CropRect *cropRect) {
    return static_sk_image_filter_make(SkImageFilters::DisplacementMap(xChannelSelector, yChannelSelector, scale, static_sk_image_filter_move(sk_image_filter_key_in_1), static_sk_image_filter_move(sk_image_filter_key_in_2), *cropRect));
}

int SkImageFilters_DropShadow(int sk_image_filter_key_in, SkScalar dx, SkScalar dy, SkScalar sigmaX, SkScalar sigmaY, SkColor color, const SkImageFilters::CropRect *cropRect) {
    return static_sk_image_filter_make(SkImageFilters::DropShadow(dx, dy, sigmaX, sigmaY, color, static_sk_image_filter_move(sk_image_filter_key_in), *cropRect));
}

int SkImageFilters_DropShadowOnly(int sk_image_filter_key_in, SkScalar dx, SkScalar dy, SkScalar sigmaX, SkScalar sigmaY, SkColor color, const SkImageFilters::CropRect *cropRect) {
    return static_sk_image_filter_make(SkImageFilters::DropShadowOnly(dx, dy, sigmaX, sigmaY, color, static_sk_image_filter_move(sk_image_filter_key_in), *cropRect));
}

int SkImageFilters_Empty() {
    return static_sk_image_filter_make(SkImageFilters::Empty());
}

int SkImageFilters_Image(int sk_image_key_in, const SkRect *srcRect, const SkRect *dstRect, const SkSamplingOptions *sampling) {
    return static_sk_image_filter_make(SkImageFilters::Image(static_sk_image_move(sk_image_key_in), *srcRect, *dstRect, *sampling));
}

int SkImageFilters_Image_2(int sk_image_key_in, const SkSamplingOptions *sampling) {
    return static_sk_image_filter_make(SkImageFilters::Image(static_sk_image_move(sk_image_key_in), *sampling));
}

int SkImageFilters_Magnifier(int sk_image_filter_key_in, const SkRect *lensBounds, SkScalar zoomAmount, SkScalar inset, const SkSamplingOptions *sampling, const SkImageFilters::CropRect *cropRect) {
    return static_sk_image_filter_make(SkImageFilters::Magnifier(*lensBounds, zoomAmount, inset, *sampling, static_sk_image_filter_move(sk_image_filter_key_in), *cropRect));
}

int SkImageFilters_MatrixConvolution(int sk_image_filter_key_in, const SkISize *kernelSize, const SkScalar kernel[], SkScalar gain, SkScalar bias, const SkIPoint *kernelOffset, SkTileMode tileMode, bool convolveAlpha, const SkImageFilters::CropRect *cropRect) {
    return static_sk_image_filter_make(SkImageFilters::MatrixConvolution(*kernelSize, kernel, gain, bias, *kernelOffset, tileMode, convolveAlpha, static_sk_image_filter_move(sk_image_filter_key_in), *cropRect));
}

int SkImageFilters_MatrixTransform(int sk_image_filter_key_in, const SkMatrix *matrix, const SkSamplingOptions *sampling) {
    return static_sk_image_filter_make(SkImageFilters::MatrixTransform(*matrix, *sampling, static_sk_image_filter_move(sk_image_filter_key_in)));
}

int SkImageFilters_Merge(sk_sp<SkImageFilter> *filters, int count, const SkImageFilters::CropRect *cropRect) {
    return static_sk_image_filter_make(SkImageFilters::Merge(filters, count, *cropRect));
}

int SkImageFilters_Merge_2(int sk_image_filter_key_in_1, int sk_image_filter_key_in_2, const SkImageFilters::CropRect *cropRect) {
    return static_sk_image_filter_make(SkImageFilters::Merge(static_sk_image_filter_move(sk_image_filter_key_in_1), static_sk_image_filter_move(sk_image_filter_key_in_2), *cropRect));
}

int SkImageFilters_Offset(int sk_image_filter_key_in, SkScalar dx, SkScalar dy, const SkImageFilters::CropRect *cropRect) {
    return static_sk_image_filter_make(SkImageFilters::Offset(dx, dy, static_sk_image_filter_move(sk_image_filter_key_in), *cropRect));
}

int SkImageFilters_Picture(int sk_picture_key_in, const SkRect *targetRect) {
    return static_sk_image_filter_make(SkImageFilters::Picture(static_sk_picture_move(sk_picture_key_in), *targetRect));
}

int SkImageFilters_Picture_2(int sk_picture_key_in) {
    return static_sk_image_filter_make(SkImageFilters::Picture(static_sk_picture_move(sk_picture_key_in)));
}

int SkImageFilters_RuntimeShader(int sk_image_filter_key_in, const SkRuntimeShaderBuilder *builder, std::string_view childShaderName) {
    return static_sk_image_filter_make(SkImageFilters::RuntimeShader(*builder, childShaderName, static_sk_image_filter_move(sk_image_filter_key_in)));
}

int SkImageFilters_RuntimeShader_2(int sk_image_filter_key_in, const SkRuntimeShaderBuilder *builder, SkScalar sampleRadius, std::string_view childShaderName) {
    return static_sk_image_filter_make(SkImageFilters::RuntimeShader(*builder, sampleRadius, childShaderName, static_sk_image_filter_move(sk_image_filter_key_in)));
}

int SkImageFilters_RuntimeShader_3(const SkRuntimeShaderBuilder *builder, std::string_view childShaderNames[], const sk_sp<SkImageFilter> *inputs, int inputCount) {
    return static_sk_image_filter_make(SkImageFilters::RuntimeShader(*builder, childShaderNames, inputs, inputCount));
}

int SkImageFilters_RuntimeShader_4(const SkRuntimeShaderBuilder *builder, SkScalar maxSampleRadius, std::string_view childShaderNames[], const sk_sp<SkImageFilter> *inputs, int inputCount) {
    return static_sk_image_filter_make(SkImageFilters::RuntimeShader(*builder, maxSampleRadius, childShaderNames, inputs, inputCount));
}

int SkImageFilters_Shader(int sk_shader_key_in, const SkImageFilters::CropRect *cropRect) {
    return static_sk_image_filter_make(SkImageFilters::Shader(static_sk_shader_move(sk_shader_key_in), *cropRect));
}

int SkImageFilters_Shader_2(int sk_shader_key_in, SkImageFilters::Dither dither, const SkImageFilters::CropRect *cropRect) {
    return static_sk_image_filter_make(SkImageFilters::Shader(static_sk_shader_move(sk_shader_key_in), dither, *cropRect));
}

int SkImageFilters_Tile(int sk_image_filter_key_in, const SkRect *src, const SkRect *dst) {
    return static_sk_image_filter_make(SkImageFilters::Tile(*src, *dst, static_sk_image_filter_move(sk_image_filter_key_in)));
}

int SkImageFilters_Dilate(int sk_image_filter_key_in, SkScalar radiusX, SkScalar radiusY, const SkImageFilters::CropRect *cropRect) {
    return static_sk_image_filter_make(SkImageFilters::Dilate(radiusX, radiusY, static_sk_image_filter_move(sk_image_filter_key_in), *cropRect));
}

int SkImageFilters_Erode(int sk_image_filter_key_in, SkScalar radiusX, SkScalar radiusY, const SkImageFilters::CropRect *cropRect) {
    return static_sk_image_filter_make(SkImageFilters::Erode(radiusX, radiusY, static_sk_image_filter_move(sk_image_filter_key_in), *cropRect));
}

int SkImageFilters_DistantLitDiffuse(int sk_image_filter_key_in, const SkPoint3 *direction, SkColor lightColor, SkScalar surfaceScale, SkScalar kd, const SkImageFilters::CropRect *cropRect) {
    return static_sk_image_filter_make(SkImageFilters::DistantLitDiffuse(*direction, lightColor, surfaceScale, kd, static_sk_image_filter_move(sk_image_filter_key_in), *cropRect));
}

int SkImageFilters_PointLitDiffuse(int sk_image_filter_key_in, const SkPoint3 *location, SkColor lightColor, SkScalar surfaceScale, SkScalar kd, const SkImageFilters::CropRect *cropRect) {
    return static_sk_image_filter_make(SkImageFilters::PointLitDiffuse(*location, lightColor, surfaceScale, kd, static_sk_image_filter_move(sk_image_filter_key_in), *cropRect));
}

int SkImageFilters_SpotLitDiffuse(int sk_image_filter_key_in, const SkPoint3 *location, const SkPoint3 *target, SkScalar falloffExponent, SkScalar cutoffAngle, SkColor lightColor, SkScalar surfaceScale, SkScalar kd, const SkImageFilters::CropRect *cropRect) {
    return static_sk_image_filter_make(SkImageFilters::SpotLitDiffuse(*location, *target, falloffExponent, cutoffAngle, lightColor, surfaceScale, kd, static_sk_image_filter_move(sk_image_filter_key_in), *cropRect));
}

int SkImageFilters_DistantLitSpecular(int sk_image_filter_key_in, const SkPoint3 *direction, SkColor lightColor, SkScalar surfaceScale, SkScalar ks, SkScalar shininess, const SkImageFilters::CropRect *cropRect) {
    return static_sk_image_filter_make(SkImageFilters::DistantLitSpecular(*direction, lightColor, surfaceScale, ks, shininess, static_sk_image_filter_move(sk_image_filter_key_in), *cropRect));
}

int SkImageFilters_PointLitSpecular(int sk_image_filter_key_in, const SkPoint3 *location, SkColor lightColor, SkScalar surfaceScale, SkScalar ks, SkScalar shininess, const SkImageFilters::CropRect *cropRect) {
    return static_sk_image_filter_make(SkImageFilters::PointLitSpecular(*location, lightColor, surfaceScale, ks, shininess, static_sk_image_filter_move(sk_image_filter_key_in), *cropRect));
}

int SkImageFilters_SpotLitSpecular(int sk_image_filter_key_in, const SkPoint3 *location, const SkPoint3 *target, SkScalar falloffExponent, SkScalar cutoffAngle, SkColor lightColor, SkScalar surfaceScale, SkScalar ks, SkScalar shininess, const SkImageFilters::CropRect *cropRect) {
    return static_sk_image_filter_make(SkImageFilters::SpotLitSpecular(*location, *target, falloffExponent, cutoffAngle, lightColor, surfaceScale, ks, shininess, static_sk_image_filter_move(sk_image_filter_key_in), *cropRect));
}

}