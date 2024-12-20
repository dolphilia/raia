local ffi = require("ffi")

-- 汎用ファイナライザ設定関数
local function setFinalizer(key, deleteFunction)
    ffi.gc(ffi.new("int[1]", key), function(k)
        deleteFunction(k[0])
    end)
end

ffi.cdef[[
    void raia_gdImageDestroy(void * im);
    void * raia_gdImageCreateTrueColor(int sx, int sy);
    void raia_gdImageLine(void * im, int x1, int y1, int x2, int y2, int color);
    void raia_gdImageFilledRectangle(void * im, int x1, int y1, int x2, int y2, int color);
    void raia_gdImageFilledArc(void * im, int cx, int cy, int w, int h, int s, int e, int color, int style);
    // util
    void * raia_getPixels_gdImage(void * im);
    uint8_t *raia_getPixels_gdImage_RGBA(void * im, uint8_t * rgba);
    // C
    void* malloc(size_t size);
    void free(void* ptr);
]]

local lib = ffi.load("raia_libgd")
local GD = {}

function GD.imageDestroy(im)
    lib.raia_gdImageDestroy(im)
end

function GD.imageCreateTrueColor(sx, sy)
    local obj = lib.raia_gdImageCreateTrueColor(sx, sy)
    ffi.gc(obj, lib.raia_gdImageDestroy)
    return obj
end

function GD.imageLine(im, x1, y1, x2, y2, color)
    lib.raia_gdImageLine(im, x1, y1, x2, y2, color)
end

function GD.imageFilledRectangle(im, x1, y1, x2, y2, color)
    lib.raia_gdImageFilledRectangle(im, x1, y1, x2, y2, color)
end

function GD.imageFilledArc(im, cx, cy, w, h, s, e, color, style)
    lib.raia_gdImageFilledArc(im, cx, cy, w, h, s, e, color, style)
end

-- util

function GD.getPixels(im)
    return lib.raia_getPixels_gdImage(im)
end

function GD.getPixelsRGBA(im, rgba)
    lib.raia_getPixels_gdImage_RGBA(im, rgba)
end

return GD