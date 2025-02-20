extension Skia {
    //typealias SkColor = UInt32 // ARGB8888
    typealias SkPMColor = UInt32 // ARGB8888
    typealias ColorRGBA8888 = UInt32
    typealias SkScalar = Float
    // ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz
    typealias SkAndroidCodecMutablePointer = UnsafeMutableRawPointer
    typealias SkAndroidCodecConstPointer = UnsafeRawPointer
    typealias SkBitmapMutablePointer = UnsafeMutableRawPointer
    typealias SkBitmapConstPointer = UnsafeRawPointer
    typealias SkBitmapAllocatorMutablePointer = UnsafeMutableRawPointer
    typealias SkBitmapAllocatorConstPointer = UnsafeRawPointer
    typealias SkBlenderMutablePointer = UnsafeMutableRawPointer
    typealias SkBlenderConstPointer = UnsafeRawPointer
    typealias SkCanvasMutablePointer = UnsafeMutableRawPointer
    typealias SkCanvasConstPointer = UnsafeRawPointer
    typealias SkColor4fMutablePointer = UnsafeMutableRawPointer
    typealias SkColor4fConstPointer = UnsafeRawPointer
    typealias SkColorFilterMutablePointer = UnsafeMutableRawPointer
    typealias SkColorFilterConstPointer = UnsafeRawPointer
    typealias SkColorInfoMutablePointer = UnsafeMutableRawPointer
    typealias SkColorInfoConstPointer = UnsafeRawPointer
    typealias SkColorMatrixMutablePointer = UnsafeMutableRawPointer
    typealias SkColorMatrixConstPointer = UnsafeRawPointer
    typealias SkColorSpaceMutablePointer = UnsafeMutableRawPointer
    typealias SkColorSpaceConstPointer = UnsafeRawPointer
    typealias SkCubicResamplerMutablePointer = UnsafeMutableRawPointer
    typealias SkCubicResamplerConstPointer = UnsafeRawPointer
    typealias SkDataMutablePointer = UnsafeMutableRawPointer
    typealias SkDataConstPointer = UnsafeRawPointer
    typealias SkDrawableMutablePointer = UnsafeMutableRawPointer
    typealias SkDrawableConstPointer = UnsafeRawPointer
    typealias SkFlattenableMutablePointer = UnsafeMutableRawPointer
    typealias SkFlattenableConstPointer = UnsafeRawPointer
    typealias SkFlattenableFactoryMutablePointer = UnsafeMutableRawPointer
    typealias SKFlattenableFactoryConstPointer = UnsafeRawPointer
    typealias SkFontMutablePointer = UnsafeMutableRawPointer
    typealias SkFontConstPointer = UnsafeRawPointer
    typealias SkFontArgumentsMutablePointer = UnsafeMutableRawPointer
    typealias SkFontArgumentsConstPointer = UnsafeRawPointer
    typealias SkFontMgrMutablePointer = UnsafeMutableRawPointer
    typealias SkFontMgrConstPointer = UnsafeRawPointer
    typealias SkFontStyleMutablePointer = UnsafeMutableRawPointer
    typealias SkFontStyleConstPointer = UnsafeRawPointer
    typealias SkImageMutablePointer = UnsafeMutableRawPointer
    typealias SkImageConstPointer = UnsafeRawPointer
    typealias SkImageFilterMutablePointer = UnsafeMutableRawPointer
    typealias SkImageFilterConstPointer = UnsafeRawPointer
    typealias SkImageInfoMutablePointer = UnsafeMutableRawPointer
    typealias SkImageInfoConstPointer = UnsafeRawPointer
    typealias SkIPointMutablePointer = UnsafeMutableRawPointer
    typealias SkIPointConstPointer = UnsafeRawPointer
    typealias SkIRectMutablePointer = UnsafeMutableRawPointer
    typealias SkIRectConstPointer = UnsafeRawPointer
    typealias SkISizeMutablePointer = UnsafeMutableRawPointer
    typealias SkISizeConstPointer = UnsafeRawPointer
    typealias SkM44MutablePointer = UnsafeMutableRawPointer
    typealias SkM44ConstPointer = UnsafeRawPointer
    typealias SkMaskMutablePointer = UnsafeMutableRawPointer
    typealias SkMaskConstPointer = UnsafeRawPointer
    typealias SkMaskBuilderMutablePointer = UnsafeMutableRawPointer
    typealias SkMaskBuilderConstPointer = UnsafeRawPointer
    typealias SkMaskFilterMutablePointer = UnsafeMutableRawPointer
    typealias SkMaskFilterConstPointer = UnsafeRawPointer
    typealias SkMatrixMutablePointer = UnsafeMutableRawPointer
    typealias SkMatrixConstPointer = UnsafeRawPointer
    typealias SkMeshMutablePointer = UnsafeMutableRawPointer
    typealias SkMeshConstPointer = UnsafeRawPointer
    typealias SkPaintMutablePointer = UnsafeMutableRawPointer
    typealias SkPaintConstPointer = UnsafeRawPointer
    typealias SkPathMutablePointer = UnsafeMutableRawPointer
    typealias SkPathConstPointer = UnsafeRawPointer
    typealias SkPathEffectMutablePointer = UnsafeMutableRawPointer
    typealias SkPathEffectConstPointer = UnsafeRawPointer
    typealias SkPictureMutablePointer = UnsafeMutableRawPointer
    typealias SkPictureConstPointer = UnsafeRawPointer
    typealias SkPixelRefMutablePointer = UnsafeMutableRawPointer
    typealias SkPixelRefConstPointer = UnsafeRawPointer
    typealias SkPixmapMutablePointer = UnsafeMutableRawPointer
    typealias SkPixmapConstPointer = UnsafeRawPointer
    typealias SkPointMutablePointer = UnsafeMutableRawPointer
    typealias SkPointConstPointer = UnsafeRawPointer
    typealias SkPoint3MutablePointer = UnsafeMutableRawPointer
    typealias SkPoint3ConstPointer = UnsafeRawPointer
    typealias SkRectMutablePointer = UnsafeMutableRawPointer
    typealias SkRectConstPointer = UnsafeRawPointer
    typealias SkRegionMutablePointer = UnsafeMutableRawPointer
    typealias SkRegionConstPointer = UnsafeRawPointer
    typealias SkRRectMutablePointer = UnsafeMutableRawPointer
    typealias SkRRectConstPointer = UnsafeRawPointer
    typealias SkRSXformMutablePointer = UnsafeMutableRawPointer
    typealias SkRSXformConstPointer = UnsafeRawPointer
    typealias SkSamplingOptionsMutablePointer = UnsafeMutableRawPointer
    typealias SkSamplingOptionsConstPointer = UnsafeRawPointer
    typealias SkShaderMutablePointer = UnsafeMutableRawPointer
    typealias SkShaderConstPointer = UnsafeRawPointer
    typealias SkSizeMutablePointer = UnsafeMutableRawPointer
    typealias SkSizeConstPointer = UnsafeRawPointer
    typealias SkStreamMutablePointer = UnsafeMutableRawPointer
    typealias SkStreamConstPointer = UnsafeRawPointer
    typealias SkStreamAssetMutablePointer = UnsafeMutableRawPointer
    typealias SkStreamAssetConstPointer = UnsafeRawPointer
    typealias SkStringMutablePointer = UnsafeMutableRawPointer
    typealias SkStringConstPointer = UnsafeRawPointer
    typealias SkSurfaceMutablePointer = UnsafeMutableRawPointer
    typealias SkSurfaceConstPointer = UnsafeRawPointer
    typealias SkSurfacePropsMutablePointer = UnsafeMutableRawPointer
    typealias SkSurfacePropsConstPointer = UnsafeRawPointer
    typealias SkTextBlobMutablePointer = UnsafeMutableRawPointer
    typealias SkTextBlobConstPointer = UnsafeRawPointer
    typealias SkTypefaceMutablePointer = UnsafeMutableRawPointer
    typealias SkTypefaceConstPointer = UnsafeRawPointer
    typealias SkV2MutablePointer = UnsafeMutableRawPointer
    typealias SkV2ConstPointer = UnsafeRawPointer
    typealias SkV3MutablePointer = UnsafeMutableRawPointer
    typealias SkV3ConstPointer = UnsafeRawPointer
    typealias SkV4MutablePointer = UnsafeMutableRawPointer
    typealias SkV4ConstPointer = UnsafeRawPointer
    typealias SkVerticesMutablePointer = UnsafeMutableRawPointer
    typealias SkVerticesConstPointer = UnsafeRawPointer
    typealias SkWriteBufferMutablePointer = UnsafeMutableRawPointer
    typealias SkWriteBufferConstPointer = UnsafeRawPointer
    typealias SkWStreamMutablePointer = UnsafeMutableRawPointer
    typealias SkWStreamConstPointer = UnsafeRawPointer

    typealias StringViewMutablePointer = UnsafeMutableRawPointer
    typealias StringViewConstPointer = UnsafeRawPointer
}