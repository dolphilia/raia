import {Lib} from "raia_lib";
const lib = new Lib();

(function() {
    if (globalThis.__RAIA_SKIA__ === undefined) {
        globalThis.__RAIA_SKIA__ = {};
        globalThis.__RAIA_SKIA__.handle = lib.open("raia_skia");
        lib.add(globalThis.__RAIA_SKIA__.handle, "static_sk_rect_delete");
        lib.add(globalThis.__RAIA_SKIA__.handle, "static_sk_stream_get");
        lib.add(globalThis.__RAIA_SKIA__.handle, "static_sk_image_get");
        lib.add(globalThis.__RAIA_SKIA__.handle, "static_sk_stream_asset_get");
        lib.add(globalThis.__RAIA_SKIA__.handle, "static_sk_rect_get_ptr");
        lib.add(globalThis.__RAIA_SKIA__.handle, "SkBitmap_new");
        lib.add(globalThis.__RAIA_SKIA__.handle, "SkBitmap_allocN32Pixels");
        lib.add(globalThis.__RAIA_SKIA__.handle, "SkCanvas_new_3");
        lib.add(globalThis.__RAIA_SKIA__.handle, "SkPaint_new");
        lib.add(globalThis.__RAIA_SKIA__.handle, "SkPaint_setColor");
        lib.add(globalThis.__RAIA_SKIA__.handle, "SkRect_MakeXYWH");
        lib.add(globalThis.__RAIA_SKIA__.handle, "SkCanvas_drawRect");
        lib.add(globalThis.__RAIA_SKIA__.handle, "SkBitmap_width");
        lib.add(globalThis.__RAIA_SKIA__.handle, "SkBitmap_height");
        lib.add(globalThis.__RAIA_SKIA__.handle, "SkBitmap_getPixels");
        lib.add(globalThis.__RAIA_SKIA__.handle, "SkStream_MakeFromFile");
        lib.add(globalThis.__RAIA_SKIA__.handle, "SkData_MakeFromStream");
        lib.add(globalThis.__RAIA_SKIA__.handle, "SkStream_getLength");
        lib.add(globalThis.__RAIA_SKIA__.handle, "SkImages_DeferredFromEncodedData");
        lib.add(globalThis.__RAIA_SKIA__.handle, "SkCanvas_drawImage_4");
        lib.add(globalThis.__RAIA_SKIA__.handle, "SkBitmap_setPixels");
        lib.add(globalThis.__RAIA_SKIA__.handle, "SkStreamAsset_getLength");
        lib.add(globalThis.__RAIA_SKIA__.handle, "SkPath_new");
        lib.add(globalThis.__RAIA_SKIA__.handle, "SkPath_moveTo");
        lib.add(globalThis.__RAIA_SKIA__.handle, "SkPath_lineTo");
        lib.add(globalThis.__RAIA_SKIA__.handle, "SkPath_close");
        lib.add(globalThis.__RAIA_SKIA__.handle, "SkPaint_setAntiAlias");
        lib.add(globalThis.__RAIA_SKIA__.handle, "SkCanvas_drawPath");
        lib.add(globalThis.__RAIA_SKIA__.handle, "SkPaint_setBlendMode");
        lib.add(globalThis.__RAIA_SKIA__.handle, "SkCanvas_drawRoundRect");
    }
})();

export class Skia {
    // void static_sk_rect_delete(int key)
    static_sk_rect_delete(key) {
        return lib.ffi(
            globalThis.__RAIA_SKIA__.handle,
            "static_sk_rect_delete",
            "void",
            [
                ["sint", "key", key]
            ]
        );
    }
    // SkStream *static_sk_stream_get(int key)
    static_sk_stream_get(key) {
        return lib.ffi(
            globalThis.__RAIA_SKIA__.handle,
            "static_sk_stream_get",
            "pointer",
            [
                ["sint", "key", key]
            ]
        );
    }
    // SkImage *static_sk_image_get(int key)
    static_sk_image_get(key) {
        return lib.ffi(
            globalThis.__RAIA_SKIA__.handle,
            "static_sk_image_get",
            "pointer",
            [
                ["sint", "key", key]
            ]
        );
    }
    // SkStreamAsset *static_sk_stream_asset_get(int key)
    static_sk_stream_asset_get(key) {
        return lib.ffi(
            globalThis.__RAIA_SKIA__.handle,
            "static_sk_stream_asset_get",
            "pointer",
            [
                ["sint", "key", key]
            ]
        );
    }
    // SkRect *static_sk_rect_get_ptr(int key)
    static_sk_rect_get_ptr(key) {
        return lib.ffi(
            globalThis.__RAIA_SKIA__.handle,
            "static_sk_rect_get_ptr",
            "pointer",
            [
                ["sint", "key", key]
            ]
        );
    }
    // SkBitmap *SkBitmap_new(void)
    SkBitmap_new() {
        return lib.ffi(
            globalThis.__RAIA_SKIA__.handle,
            "SkBitmap_new",
            "pointer",
            null
        );
    }
    // void SkBitmap_allocN32Pixels(SkBitmap *bitmap, int width, int height, bool isOpaque)
    SkBitmap_allocN32Pixels(bitmap, width, height, isOpaque) {
        return lib.ffi(
            globalThis.__RAIA_SKIA__.handle,
            "SkBitmap_allocN32Pixels",
            "void",
            [
                ["pointer", "bitmap", bitmap],
                ["sint", "width", width],
                ["sint", "height", height],
                ["uint", "isOpaque", isOpaque]
            ]
        );
    }
    // SkCanvas *SkCanvas_new_3(SkBitmap *bitmap)
    SkCanvas_new_3(bitmap) {
        return lib.ffi(
            globalThis.__RAIA_SKIA__.handle,
            "SkCanvas_new_3",
            "pointer",
            [
                ["pointer", "bitmap", bitmap]
            ]
        );
    }
    //SkPaint *SkPaint_new()
    SkPaint_new() {
        return lib.ffi(
            globalThis.__RAIA_SKIA__.handle,
            "SkPaint_new",
            "pointer",
            null
        );
    }
    // void SkPaint_setColor(SkPaint *paint, SkColor color)
    SkPaint_setColor(paint, color) {
        return lib.ffi(
            globalThis.__RAIA_SKIA__.handle,
            "SkPaint_setColor",
            "void",
            [
                ["pointer", "paint", paint],
                ["uint32", "color", color]
            ]
        );
    }
    //sk_rect_t SkRect_MakeXYWH(float x, float y, float w, float h)
    SkRect_MakeXYWH(x, y, w, h) {
        return lib.ffi(
            globalThis.__RAIA_SKIA__.handle,
            "SkRect_MakeXYWH",
            "sint",
            [
                ["float", "x", x],
                ["float", "y", y],
                ["float", "w", w],
                ["float", "h", h],
            ]
        );
    }
    //void SkCanvas_drawRect(SkCanvas *canvas, sk_rect_t rect, const SkPaint *paint)
    SkCanvas_drawRect(canvas, rect, paint) {
        return lib.ffi(
            globalThis.__RAIA_SKIA__.handle,
            "SkCanvas_drawRect",
            "void",
            [
                ["pointer", "canvas", canvas],
                ["sint", "rect", rect],
                ["pointer", "paint", paint],
            ]
        );
    }
    // int SkBitmap_width(SkBitmap *bitmap)
    SkBitmap_width(bitmap) {
        return lib.ffi(
            globalThis.__RAIA_SKIA__.handle,
            "SkBitmap_width",
            "sint",
            [
                ["pointer", "bitmap", bitmap],
            ]
        );
    }
    // int SkBitmap_height(SkBitmap *bitmap)
    SkBitmap_height(bitmap) {
        return lib.ffi(
            globalThis.__RAIA_SKIA__.handle,
            "SkBitmap_height",
            "sint",
            [
                ["pointer", "bitmap", bitmap],
            ]
        );
    }
    // void *SkBitmap_getPixels(SkBitmap *bitmap);
    SkBitmap_getPixels(bitmap) {
        return lib.ffi(
            globalThis.__RAIA_SKIA__.handle,
            "SkBitmap_getPixels",
            "pointer",
            [
                ["pointer", "bitmap", bitmap],
            ]
        );
    }
    // sk_stream_t SkStream_MakeFromFile(const char *path)
    SkStream_MakeFromFile(path) {
        return lib.ffi(
            globalThis.__RAIA_SKIA__.handle,
            "SkStream_MakeFromFile",
            "sint",
            [
                ["string", "path", path],
            ]
        );
    }
    // sk_data_t SkData_MakeFromStream(SkStream *stream, size_t size)
    SkData_MakeFromStream(stream, size) {
        return lib.ffi(
            globalThis.__RAIA_SKIA__.handle,
            "SkData_MakeFromStream",
            "sint",
            [
                ["pointer", "stream", stream],
                ["uint", "size", size]
            ]
        );
    }
    // size_t SkStream_getLength(SkStream *stream)
    SkStream_getLength(stream) {
        return lib.ffi(
            globalThis.__RAIA_SKIA__.handle,
            "SkData_MakeFromStream",
            "uint",
            [
                ["pointer", "stream", stream]
            ]
        );
    }
    // sk_image_t SkImages_DeferredFromEncodedData(sk_data_t data)
    SkImages_DeferredFromEncodedData(data) {
        return lib.ffi(
            globalThis.__RAIA_SKIA__.handle,
            "SkImages_DeferredFromEncodedData",
            "uint",
            [
                ["sint", "data", data]
            ]
        );
    }
    // void SkCanvas_drawImage_4(SkCanvas *canvas, const SkImage *image, SkScalar left, SkScalar top)
    SkCanvas_drawImage_4(canvas, image, left, top) {
        return lib.ffi(
            globalThis.__RAIA_SKIA__.handle,
            "SkCanvas_drawImage_4",
            "void",
            [
                ["pointer", "canvas", canvas],
                ["pointer", "image", image],
                ["float", "left", left],
                ["float", "top", top],
            ]
        );
    }
    // void SkBitmap_setPixels(SkBitmap *bitmap, void *pixels)
    SkBitmap_setPixels(bitmap, pixels) {
        return lib.ffi(
            globalThis.__RAIA_SKIA__.handle,
            "SkBitmap_setPixels",
            "void",
            [
                ["pointer", "bitmap", bitmap],
                ["pointer", "pixels", pixels],
            ]
        );
    }
    // size_t SkStreamAsset_getLength(SkStreamAsset *stream_asset)
    SkStreamAsset_getLength(stream_asset) {
        return lib.ffi(
            globalThis.__RAIA_SKIA__.handle,
            "SkStreamAsset_getLength",
            "uint",
            [
                ["pointer", "stream_asset", stream_asset]
            ]
        );
    }
    // SkPath *SkPath_new()
    SkPath_new() {
        return lib.ffi(
            globalThis.__RAIA_SKIA__.handle,
            "SkPath_new",
            "pointer",
            null
        );
    }
    // SkPath *SkPath_moveTo(SkPath *path, SkScalar x, SkScalar y)
    SkPath_moveTo(path, x, y) {
        return lib.ffi(
            globalThis.__RAIA_SKIA__.handle,
            "SkPath_moveTo",
            "pointer",
            [
                ["pointer", "path", path],
                ["float", "x", x],
                ["float", "y", y],
            ]
        );
    }
    // SkPath *SkPath_lineTo(SkPath *path, SkScalar x, SkScalar y)
    SkPath_lineTo(path, x, y) {
        return lib.ffi(
            globalThis.__RAIA_SKIA__.handle,
            "SkPath_lineTo",
            "pointer",
            [
                ["pointer", "path", path],
                ["float", "x", x],
                ["float", "y", y],
            ]
        );
    }
    // SkPath *SkPath_close(SkPath *path)
    SkPath_close(path) {
        return lib.ffi(
            globalThis.__RAIA_SKIA__.handle,
            "SkPath_close",
            "pointer",
            [
                ["pointer", "path", path]
            ]
        );
    }
    // void SkPaint_setAntiAlias(SkPaint *paint, bool aa)
    SkPaint_setAntiAlias(paint, aa) {
        return lib.ffi(
            globalThis.__RAIA_SKIA__.handle,
            "SkPaint_setAntiAlias",
            "void",
            [
                ["pointer", "paint", paint],
                ["uint", "aa", aa],
            ]
        );
    }
    // void SkCanvas_drawPath(SkCanvas *canvas, const SkPath *path, const SkPaint *paint)
    SkCanvas_drawPath(canvas, path, paint) {
        return lib.ffi(
            globalThis.__RAIA_SKIA__.handle,
            "SkCanvas_drawPath",
            "void",
            [
                ["pointer", "canvas", canvas],
                ["pointer", "path", path],
                ["pointer", "paint", paint],
            ]
        );
    }
    // void SkPaint_setBlendMode(SkPaint *paint, SkBlendMode mode)
    SkPaint_setBlendMode(paint, mode) {
        return lib.ffi(
            globalThis.__RAIA_SKIA__.handle,
            "SkPaint_setBlendMode",
            "void",
            [
                ["pointer", "paint", paint],
                ["uint", "mode", mode],
            ]
        );
    }
    // void SkCanvas_drawRoundRect(SkCanvas *canvas, const SkRect *rect, SkScalar rx, SkScalar ry, const SkPaint *paint)
    SkCanvas_drawRoundRect(canvas, rect, rx, ry, paint) {
        return lib.ffi(
            globalThis.__RAIA_SKIA__.handle,
            "SkCanvas_drawRoundRect",
            "void",
            [
                ["pointer", "canvas", canvas],
                ["pointer", "rect", rect],
                ["float", "rx", rx],
                ["float", "ry", ry],
                ["pointer", "paint", paint],
            ]
        );
    }
}