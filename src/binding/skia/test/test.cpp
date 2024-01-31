//
// Created by dolphilia on 2024/01/26.
//

#include "test.h"
#include "../src/binding/sk_canvas.h"
#include "../src/binding/sk_paint.h"
#include "../src/binding/sk_rect.h"
#include "../src/binding/sk_surface.h"
#include "../src/binding/sk_surfaces.h"
#include "../src/binding/sk_image.h"
#include "../src/binding/sk_data.h"
#include "../src/binding/sk_stream.h"
#include "../src/binding/sk_bitmap.h"
#include "../src/binding/sk_file_w_stream.h"
#include "../src/binding/sk_path.h"
#include "../src/binding/sk_point.h"
#include "../src/binding/sk_typeface_mac.h"
#include "../../../common/c/utility/platform.h"
#ifdef __MACOS__
#include <CoreFoundation/CoreFoundation.h>
#include <CoreText/CoreText.h>
#endif
#include "include/core/SkData.h"
#include "include/core/SkStream.h"
#include "include/core/SkSpan.h"
#include "include/ports/SkFontMgr_data.h"
#include "include/ports/SkFontMgr_fontconfig.h"
#include "include/ports/SkTypeface_fontations.h"
#include "include/core/SkFontArguments.h"
#include "include/ports/SkFontMgr_directory.h"


#include <memory>
#include <vector>

//
#include "../src/static/static_sk_rect.h"
#include "../src/static/static_sk_surface.h"
//
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "../../../third_party/c/nothings/stb/stb_image_write.h"
#include "../src/binding/sk_text_blob.h"
#include "../src/binding/sk_font.h"
#include "../src/binding/sk_typeface.h"
#include "../src/binding/sk_gradient_shader.h"
#include "../src/binding/sk_perlin_noise_shader.h"
#include "../src/binding/sk_font_mgr.h"
#include "../src/binding/sk_font_mgr_fontconfig.h"

UTEST(cskia, drawRect) {
    const int image_width = 500;
    const int image_height = 500;
    SkBitmap* bitmap = SkBitmap_new();
    SkBitmap_allocN32Pixels(bitmap, image_width, image_height, false);
    SkCanvas *canvas = SkCanvas_new_3(bitmap);

    SkPaint *paint = SkPaint_new();
    SkPaint_setColor(paint,SK_ColorRED);
    int rect_key = SkRect_MakeXYWH(100, 100, 300, 300); // 矩形の位置とサイズ
    SkCanvas_drawRect(rect_key, canvas, paint);
    static_sk_rect_delete(rect_key);

    int bitmap_width = SkBitmap_width(bitmap);
    int bitmap_height = SkBitmap_height(bitmap);
    void* bitmap_pixels = SkBitmap_getPixels(bitmap);
    int bitmap_row_bytes = (int)SkBitmap_rowBytes(bitmap);
    stbi_write_png("output.png", bitmap_width, bitmap_height, 4, bitmap_pixels, (int)bitmap_row_bytes);

    // free
    SkBitmap_delete(bitmap);
    SkCanvas_delete(canvas);
    SkPaint_delete(paint);
}


UTEST(cskia, drawPath) {
    int image_width = 500;
    int image_height = 500;
    SkBitmap* bitmap = SkBitmap_new();
    SkBitmap_allocN32Pixels(bitmap, image_width, image_height, false);
    SkCanvas* canvas = SkCanvas_new_3(bitmap);

    SkPath* path = SkPath_new();
    float cx = (float)image_width / 2;
    float cy = (float)image_height / 2;
    float outerRadius = 100;
    float innerRadius  = 50;
    int numPoints = 5;
    const float kAngleStep = (2 * (float)M_PI) / (float)numPoints;
    const float kHalfAngleStep = kAngleStep / 2;
    SkPath_moveTo(path, cx + outerRadius, cy);
    for (int i = 1; i < numPoints * 2; ++i) {
        const float angle = kAngleStep * (float)i;
        const float radius = (i % 2 == 0) ? outerRadius : innerRadius;
        SkPath_lineTo(path, cx + radius * cos(angle), cy + radius * sin(angle));
    }
    SkPath_close(path);
    SkPaint *paint = SkPaint_new();
    SkPaint_setColor(paint, SK_ColorYELLOW);
    SkPaint_setAntiAlias(paint, true);
    SkCanvas_drawPath(canvas, path, paint);

    int bitmap_width = SkBitmap_width(bitmap);
    int bitmap_height = SkBitmap_height(bitmap);
    void* bitmap_pixels = SkBitmap_getPixels(bitmap);
    int bitmap_row_bytes = (int)SkBitmap_rowBytes(bitmap);
    stbi_write_png("output2.png", bitmap_width, bitmap_height, 4, bitmap_pixels, (int)bitmap_row_bytes);

    // free
    SkBitmap_delete(bitmap);
    SkCanvas_delete(canvas);
    SkPath_delete(path);
    SkPaint_delete(paint);
}

UTEST(cskia, drawRect_rotate) {
    const int image_width = 500;
    const int image_height = 500;
    SkBitmap* bitmap = SkBitmap_new();
    SkBitmap_allocN32Pixels(bitmap, image_width, image_height, false);
    SkCanvas *canvas = SkCanvas_new_3(bitmap);

    SkCanvas_save(canvas);
    SkCanvas_translate(canvas, SkIntToScalar(128), SkIntToScalar(128));
    SkCanvas_rotate(canvas, SkIntToScalar(45));
    {
        int rect_key = SkRect_MakeXYWH(-90.5f, -90.5f, 181.0f, 181.0f);
        SkPaint *paint = SkPaint_new();
        SkPaint_setColor(paint, SK_ColorBLUE);
        SkCanvas_drawRect(rect_key, canvas, paint);
        static_sk_rect_delete(rect_key);
        SkPaint_delete(paint);
    }
    SkCanvas_restore(canvas);

    int bitmap_width = SkBitmap_width(bitmap);
    int bitmap_height = SkBitmap_height(bitmap);
    void* bitmap_pixels = SkBitmap_getPixels(bitmap);
    int bitmap_row_bytes = (int)SkBitmap_rowBytes(bitmap);
    stbi_write_png("output3.png", bitmap_width, bitmap_height, 4, bitmap_pixels, (int)bitmap_row_bytes);

    SkBitmap_delete(bitmap);
    SkCanvas_delete(canvas);
}

UTEST(cskia, drawTextBlob_Installedfont) {
    const int image_width = 500;
    const int image_height = 500;
    SkBitmap* bitmap = SkBitmap_new();
    SkBitmap_allocN32Pixels(bitmap, image_width, image_height, false);
    SkCanvas *canvas = SkCanvas_new_3(bitmap);

    SkPaint *paint1 = SkPaint_new();
    SkPaint *paint2 = SkPaint_new();
    SkPaint *paint3 = SkPaint_new();

    SkPaint_setAntiAlias(paint1, true);
    SkPaint_setColor(paint1, SkColorSetRGB(255, 0, 0));
    SkPaint_setStyle(paint1, SkPaint::kFill_Style);

    SkPaint_setAntiAlias(paint2, true);
    SkPaint_setColor(paint2, SkColorSetRGB(0, 136, 0));
    SkPaint_setStyle(paint2, SkPaint::kStroke_Style);
    SkPaint_setStrokeWidth(paint2, SkIntToScalar(3));

    SkPaint_setAntiAlias(paint3, true);
    SkPaint_setColor(paint3, SkColorSetRGB(136, 136, 136));

    CFStringRef fontName = CFStringCreateWithCString(NULL, "Helvetica", kCFStringEncodingUTF8);
    CGFloat fontSize = 12.0;
    CTFontRef fontRef = CTFontCreateWithName(fontName, fontSize, NULL);
    CFRelease(fontName);

    int typeface_key = Mac_SkMakeTypefaceFromCTFont(fontRef);
    SkFont* font = SkFont_new_4(typeface_key, 64.0f, 1.0f, 0.0f);
    static_sk_typeface_delete(typeface_key);

    int textblob_key = SkTextBlob_MakeFromString("Skia!", font, SkTextEncoding::kUTF8);
    SkCanvas_clear_2(canvas, SK_ColorWHITE);

    SkFont_setTypeface(typeface_key, font);
    SkCanvas_drawTextBlob(textblob_key, canvas, 1.0f, 64.0f, paint1);
    static_sk_text_blob_delete(textblob_key);

    int bitmap_width = SkBitmap_width(bitmap);
    int bitmap_height = SkBitmap_height(bitmap);
    void* bitmap_pixels = SkBitmap_getPixels(bitmap);
    int bitmap_row_bytes = (int)SkBitmap_rowBytes(bitmap);
    stbi_write_png("output4.png", bitmap_width, bitmap_height, 4, bitmap_pixels, (int)bitmap_row_bytes);

    SkBitmap_delete(bitmap);
    SkCanvas_delete(canvas);
    SkPaint_delete(paint1);
    SkPaint_delete(paint2);
    SkPaint_delete(paint3);
    SkFont_delete(font);
    CFRelease(fontRef);
}

UTEST(cskia, drawTextBlob_fromFile) {
    const int image_width = 500;
    const int image_height = 500;
    SkBitmap* bitmap = SkBitmap_new();
    SkBitmap_allocN32Pixels(bitmap, image_width, image_height, false);
    SkCanvas *canvas = SkCanvas_new_3(bitmap);

    SkPaint *paint1 = SkPaint_new();
    SkPaint *paint2 = SkPaint_new();
    SkPaint *paint3 = SkPaint_new();

    SkPaint_setAntiAlias(paint1, true);
    SkPaint_setColor(paint1, SkColorSetRGB(255, 0, 0));
    SkPaint_setStyle(paint1, SkPaint::kFill_Style);

    SkPaint_setAntiAlias(paint2, true);
    SkPaint_setColor(paint2, SkColorSetRGB(0, 136, 0));
    SkPaint_setStyle(paint2, SkPaint::kStroke_Style);
    SkPaint_setStrokeWidth(paint2, SkIntToScalar(3));

    SkPaint_setAntiAlias(paint3, true);
    SkPaint_setColor(paint3, SkColorSetRGB(136, 136, 136));


    // フォントファイルのパスを指定
    CFStringRef fontPath = CFStringCreateWithCString(kCFAllocatorDefault, "Mplus1-Regular.ttf", kCFStringEncodingUTF8);
    CFURLRef fontURL = CFURLCreateWithFileSystemPath(kCFAllocatorDefault, fontPath, kCFURLPOSIXPathStyle, false);
    CFRelease(fontPath); // CFStringRefを解放

    // フォント記述子を作成
    CFArrayRef fontDescriptors = CTFontManagerCreateFontDescriptorsFromURL(fontURL);
    CFRelease(fontURL); // CFURLRefを解放

    // 配列から最初のフォント記述子を取得
    CTFontDescriptorRef fontDescriptor = (CTFontDescriptorRef)CFArrayGetValueAtIndex(fontDescriptors, 0);

    // フォント記述子を使用してCTFontを作成
    CTFontRef theCTFont = CTFontCreateWithFontDescriptor(fontDescriptor, 12.0, NULL);


    int typeface_key = Mac_SkMakeTypefaceFromCTFont(theCTFont);
    SkFont* font = SkFont_new_4(typeface_key, 64.0f, 1.0f, 0.0f);
    static_sk_typeface_delete(typeface_key);

    int textblob_key = SkTextBlob_MakeFromString("Skia!", font, SkTextEncoding::kUTF8);
    SkCanvas_clear_2(canvas, SK_ColorWHITE);

    SkFont_setTypeface(typeface_key, font);
    SkCanvas_drawTextBlob(textblob_key, canvas, 1.0f, 64.0f, paint1);
    static_sk_text_blob_delete(textblob_key);


    int bitmap_width = SkBitmap_width(bitmap);
    int bitmap_height = SkBitmap_height(bitmap);
    void* bitmap_pixels = SkBitmap_getPixels(bitmap);
    int bitmap_row_bytes = (int)SkBitmap_rowBytes(bitmap);
    stbi_write_png("Mac_SkMakeTypefaceFromCTFont.png", bitmap_width, bitmap_height, 4, bitmap_pixels, (int)bitmap_row_bytes);

    SkBitmap_delete(bitmap);
    SkCanvas_delete(canvas);
    SkPaint_delete(paint1);
    SkPaint_delete(paint2);
    SkPaint_delete(paint3);
    SkFont_delete(font);
    CFRelease(theCTFont);
    CFRelease(fontDescriptors);
}

UTEST(cskia, SkTypeface_MakeFromFile) {
    const int image_width = 500;
    const int image_height = 500;
    SkBitmap* bitmap = SkBitmap_new();
    SkBitmap_allocN32Pixels(bitmap, image_width, image_height, false);
    SkCanvas *canvas = SkCanvas_new_3(bitmap);

    SkPaint *paint1 = SkPaint_new();
    SkPaint *paint2 = SkPaint_new();
    SkPaint *paint3 = SkPaint_new();

    SkPaint_setAntiAlias(paint1, true);
    SkPaint_setColor(paint1, SkColorSetRGB(255, 0, 0));
    SkPaint_setStyle(paint1, SkPaint::kFill_Style);

    SkPaint_setAntiAlias(paint2, true);
    SkPaint_setColor(paint2, SkColorSetRGB(0, 136, 0));
    SkPaint_setStyle(paint2, SkPaint::kStroke_Style);
    SkPaint_setStrokeWidth(paint2, SkIntToScalar(3));

    SkPaint_setAntiAlias(paint3, true);
    SkPaint_setColor(paint3, SkColorSetRGB(136, 136, 136));

    int typeface_key = SkTypeface_MakeFromFile("Mplus1-Regular.ttf", 0);
    SkFont* font = SkFont_new_4(typeface_key, 64.0f, 1.0f, 0.0f);
    static_sk_typeface_delete(typeface_key);

    int textblob_key = SkTextBlob_MakeFromString("Skia!", font, SkTextEncoding::kUTF8);
    SkCanvas_clear_2(canvas, SK_ColorWHITE);

    SkFont_setTypeface(typeface_key, font);
    SkCanvas_drawTextBlob(textblob_key, canvas, 1.0f, 64.0f, paint1);
    static_sk_text_blob_delete(textblob_key);

    int bitmap_width = SkBitmap_width(bitmap);
    int bitmap_height = SkBitmap_height(bitmap);
    void* bitmap_pixels = SkBitmap_getPixels(bitmap);
    int bitmap_row_bytes = (int)SkBitmap_rowBytes(bitmap);
    stbi_write_png("SkTypeface_MakeFromFile.png", bitmap_width, bitmap_height, 4, bitmap_pixels, (int)bitmap_row_bytes);

    SkBitmap_delete(bitmap);
    SkCanvas_delete(canvas);
    SkPaint_delete(paint1);
    SkPaint_delete(paint2);
    SkPaint_delete(paint3);
    SkFont_delete(font);
}

UTEST(cskia, SkGradientShader) {
    const int image_width = 500;
    const int image_height = 500;
    SkBitmap *bitmap = SkBitmap_new();
    SkBitmap_allocN32Pixels(bitmap, image_width, image_height, false);
    SkCanvas *canvas = SkCanvas_new_3(bitmap);

    SkPoint point1 = SkPoint_Make(0.0f, 0.0f);
    SkPoint point2 = SkPoint_Make(500.0f, 500.0f);
    SkPoint points[2] = {point1, point2};
    SkColor colors[2] = {SK_ColorBLUE, SK_ColorYELLOW};
    SkPaint *paint = SkPaint_new();
    int shader_key = SkGradientShader_MakeLinear(points, colors, nullptr, 2, SkTileMode::kClamp, 0, nullptr);
    SkPaint_setShader(shader_key, paint);
    SkCanvas_drawPaint(canvas, paint);
    static_sk_shader_delete(shader_key);

    int bitmap_width = SkBitmap_width(bitmap);
    int bitmap_height = SkBitmap_height(bitmap);
    void *bitmap_pixels = SkBitmap_getPixels(bitmap);
    int bitmap_row_bytes = (int) SkBitmap_rowBytes(bitmap);
    stbi_write_png("output5.png", bitmap_width, bitmap_height, 4, bitmap_pixels, (int) bitmap_row_bytes);

    SkBitmap_delete(bitmap);
    SkCanvas_delete(canvas);
    SkPaint_delete(paint);
}

UTEST(cskia, FractalNoise) {
    const int image_width = 500;
    const int image_height = 500;
    SkBitmap *bitmap = SkBitmap_new();
    SkBitmap_allocN32Pixels(bitmap, image_width, image_height, false);
    SkCanvas *canvas = SkCanvas_new_3(bitmap);

    SkCanvas_clear_2(canvas, SK_ColorWHITE);
    SkPaint *paint = SkPaint_new();
    int shader_key = SkPerlinNoiseShader_MakeFractalNoise(0.05f, 0.05f, 4, 0.0f, NULL);
    SkPaint_setShader(shader_key, paint);
    SkCanvas_drawPaint(canvas, paint);
    static_sk_shader_delete(shader_key);

    int bitmap_width = SkBitmap_width(bitmap);
    int bitmap_height = SkBitmap_height(bitmap);
    void *bitmap_pixels = SkBitmap_getPixels(bitmap);
    int bitmap_row_bytes = (int)SkBitmap_rowBytes(bitmap);
    stbi_write_png("output6.png", bitmap_width, bitmap_height, 4, bitmap_pixels, (int) bitmap_row_bytes);

    SkBitmap_delete(bitmap);
    SkCanvas_delete(canvas);
    SkPaint_delete(paint);
}

UTEST_MAIN()