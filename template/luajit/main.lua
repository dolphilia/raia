local ffi = require("ffi")
local skia = require("modules/bindings/skia")
local stb = require("modules/bindings/stb")
local Raia = require("modules/raia")
local im = require("modules/bindings/imgui")

-- Skia
local info = skia.ImageInfo.Make(800, 600, skia.ColorType.RGBA8888, skia.AlphaType.Opaque)
local bitmap = skia.Bitmap.new()
skia.Bitmap.allocPixels_3(bitmap, skia.Static.SkImageInfo.get(info))

local canvas = skia.Canvas.new_3(bitmap)
local paint = skia.Paint.new()
local rect

-- 矩形を描画
skia.Paint.setARGB(paint, 255, 255, 255, 255)
rect = skia.Rect.MakeXYWH(0, 0, 800, 600)
skia.Canvas.drawRect(canvas, rect, paint)

-- 角丸矩形を描画
skia.Paint.setARGB(paint, 128, 0, 0, 0)
skia.Paint.setAntiAlias(paint, true) -- アンチエイリアシングをオンにする
rect = skia.Rect.MakeXYWH(100, 100, 600, 400)
skia.Canvas.drawRoundRect(canvas, skia.Static.SkRect.get(rect), 10, 10, paint)

-- 枠線を描画
skia.Paint.setStyle(paint, skia.Paint.Style.Stroke)  -- スタイルを枠線に設定
skia.Paint.setStrokeWidth(paint, 5)  -- 枠線の太さを設定
skia.Paint.setARGB(paint, 255, 0, 0, 0)
rect = skia.Rect.MakeXYWH(100, 100, 600, 400)
skia.Canvas.drawRoundRect(canvas, skia.Static.SkRect.get(rect), 10, 10, paint)

-- 文字を描画
local typeface_key
local font
local textblob_key

skia.Paint.setARGB(paint, 255, 255, 255, 255)
skia.Paint.setStyle(paint, skia.Paint.Style.Fill)  -- スタイルを塗りつぶしに設定
typeface_key = skia.Typeface.MakeFromFile("Mplus1-Regular.ttf", 0)
font = skia.Font.new_4(typeface_key, 64.0, 1.0, 0.0)
textblob_key = skia.TextBlob.MakeFromString("こんにちは! Raia!", font, 0)
skia.Font.setTypeface(font, typeface_key)
skia.Canvas.drawTextBlob(canvas, textblob_key, 120.0, 200.0, paint)

skia.Paint.setARGB(paint, 255, 0, 0, 0)
skia.Paint.setStyle(paint, skia.Paint.Style.Stroke)  -- スタイルを枠線に設定
skia.Paint.setStrokeWidth(paint, 2)
local typeface_key = skia.Typeface.MakeFromFile("Mplus1-Regular.ttf", 0)
local font = skia.Font.new_4(typeface_key, 64.0, 1.0, 0.0)
local textblob_key = skia.TextBlob.MakeFromString("こんにちは! Raia!", font, 0) -- SkTextEncoding::kUTF8 = 0
skia.Font.setTypeface(font, typeface_key)
skia.Canvas.drawTextBlob(canvas, textblob_key, 120.0, 200.0, paint)

-- グラデーションを描画する
local points = skia.Static.SkPointTwo.make(0, 0, 0, 500)

ffi.cdef[[
typedef uint32_t SkColor;
]]

local SK_ColorBLUE = 0xFF0000EE  -- A=255, R=0, G=0, B=255
local SK_ColorYELLOW = 0xFF000055  -- A=255, R=255, G=255, B=0
local colors = ffi.new("SkColor[2]", {SK_ColorBLUE, SK_ColorYELLOW})
local shader_key = skia.GradientShader.MakeLinear(skia.Static.SkPointTwo.get(points), colors, nil, 2, skia.TileMode.Clamp, 0, nil)
skia.Paint.setShader(paint, shader_key)
skia.Paint.setBlendMode(paint, skia.BlendMode.Overlay)
skia.Canvas.drawPaint(canvas, paint)

-- 画像を読み込む

ffi.cdef[[
    void* memcpy(void* dest, const void* src, size_t n);
]]

local filePath = "miga.png"
local width = ffi.new("int[1]")
local height = ffi.new("int[1]")
local channels = ffi.new("int[1]")

local image_data = stb.Image.load(filePath, width, height, channels, stb.Image.ColorMode.RGBA)
if image_data == nil then
    local reason = ffi.string(stb.Image.failureReason())
    io.stderr:write("Error loading PNG file: ", reason, "\n")
    os.exit(1)
end

local image_info = skia.ImageInfo.Make(width[0], height[0], skia.ColorType.RGBA8888, skia.AlphaType.Unpremul) -- Unpremul
local image_info_ptr = skia.Static.SkImageInfo.get(image_info);

local image_bitmap = skia.Bitmap.new()
skia.Bitmap.allocPixels_3(image_bitmap, image_info_ptr)
local image_pixels = skia.Bitmap.getPixels(image_bitmap)

ffi.C.memcpy(image_pixels, image_data, width[0] * height[0] * 4)
stb.Image.imageFree(image_data)

skia.Paint.setBlendMode(paint, skia.BlendMode.SrcOver) -- skia.BlendMode.SrcOver
local samplingOptions = skia.SamplingOptions.new_4(1)

local image = skia.Bitmap.asImage(image_bitmap)
skia.Canvas.drawImage_2(canvas, image, 250, 240, samplingOptions, paint)

--image = skia.Bitmap.asImage(image_bitmap)
--skia.Canvas.drawImage_2(canvas, image, 50, 0, samplingOptions, paint)

--

local pixels = skia.Bitmap.getPixels(bitmap);
local pixels_buffer = ffi.new("char[?]", 800 * 600 * 4)
ffi.C.memcpy(pixels_buffer, pixels, 800 * 600 * 4)

bitmap = nil
rect = nil
collectgarbage("collect")

--

local system = Raia.System:new()
local timer = Raia.Timer:new()
local window = Raia.Window:new("Title", 800, 600)


-- ImGui
-- init
im.checkVersion()
local ctx = im.createContext()
-- config
local bit = require("bit")
local config_flags = 0
config_flags = bit.bor(config_flags, im.ConfigFlags.NavEnableKeyboard)
config_flags = bit.bor(config_flags, im.ConfigFlags.NavEnableGamepad)
config_flags = bit.bor(config_flags, im.ConfigFlags.DockingEnable)
config_flags = bit.bor(config_flags, im.ConfigFlags.ViewportsEnable)
im.getIO_configFlags(config_flags)
im.styleColorsLight()
-- initImpl
im.initForOpenGLImplGLFW(window.id, true);
im.initImplOpenGL3("#version 300 es");
--


while window:shouldClose() == false do
    im.newFrameImplOpenGL3()
    im.newFrameImplGLFW()
    im.newFrame()
    im.Begin("Debug")
    im.text(""..timer:getFPS().."FPS")
    im.text(""..(system:getMemoryUsage()/1000/1000).."MB")
    im.End()
    im.showDemoWindow()
    im.showMetricsWindow()
    im.showStyleEditor()
    --window:setTitle("FPS:"..timer:getFPS().."|"..(system:getMemoryUsage()/1000/1000).."MB")
    --
    window:setPixels(pixels_buffer)
    window:redraw(false, false)
    local backup_current_context = window:getCurrentContext()
    im.render()
    im.renderDrawDataImplOpenGL3(im.getDrawData())
    im.updatePlatformWindows()
    im.renderPlatformWindowsDefault()
    window:makeContextCurrent(backup_current_context)
    window:swapBuffers()
    window:pollEvents()
end