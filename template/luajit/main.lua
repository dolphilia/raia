local ffi = require("ffi")
local skia = require("modules/bindings/skia")
local stb = require("modules/bindings/stb")
local Raia = require("modules/raia")
local im = require("modules/bindings/imgui")
local gl = require("modules/bindings/gles")

print(raia.core.plus(100, 200))

ffi.cdef[[
    void *raia_internal_number_to_pointer(double number);
    typedef struct lua_State lua_State;
    void call_lua_function(lua_State *L);
]]

function raia.core.numToPtr(num)
    return ffi.C.raia_internal_number_to_pointer(num)
end

-- 呼び出されるLua関数
function my_lua_function()
    print("Hello from Lua function!")
end

-- Lua関数をCに登録
raia.core.registerLuaFunction(my_lua_function)

local L = raia.core.numToPtr(raia.core.getLuaState())
ffi.C.call_lua_function(L)


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


local pixels = skia.Bitmap.getPixels(bitmap)
local pixels_buffer = ffi.new("char[?]", 800 * 600 * 4)
ffi.C.memcpy(pixels_buffer, pixels, 800 * 600 * 4)

bitmap = nil
rect = nil
--collectgarbage("collect")
--

local system = Raia.System:new()
local timer = Raia.Timer:new()
local window = Raia.Window:new("RaiaEngine", 800, 600)


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
im.IO.setConfigFlags(config_flags)
im.styleColorsLight()

im.Style.setColors(im.Col.Text, 1.00, 1.00, 1.00, 1.00)
im.Style.setColors(im.Col.TextDisabled, 0.50, 0.50, 0.50, 1.00)
im.Style.setColors(im.Col.WindowBg, 0.10, 0.10, 0.10, 1.00)
im.Style.setColors(im.Col.ChildBg, 0.00, 0.00, 0.00, 0.00)
im.Style.setColors(im.Col.PopupBg, 0.19, 0.19, 0.19, 0.92)
im.Style.setColors(im.Col.Border, 0.19, 0.19, 0.19, 0.29)
im.Style.setColors(im.Col.BorderShadow, 0.00, 0.00, 0.00, 0.24)
im.Style.setColors(im.Col.FrameBg, 0.05, 0.05, 0.05, 0.54)
im.Style.setColors(im.Col.FrameBgHovered, 0.19, 0.19, 0.19, 0.54)
im.Style.setColors(im.Col.FrameBgActive, 0.20, 0.22, 0.23, 1.00)
im.Style.setColors(im.Col.TitleBg, 0.00, 0.00, 0.00, 1.00)
im.Style.setColors(im.Col.TitleBgActive, 0.06, 0.06, 0.06, 1.00)
im.Style.setColors(im.Col.TitleBgCollapsed, 0.00, 0.00, 0.00, 1.00)
im.Style.setColors(im.Col.MenuBarBg, 0.14, 0.14, 0.14, 1.00)
im.Style.setColors(im.Col.ScrollbarBg, 0.05, 0.05, 0.05, 0.54)
im.Style.setColors(im.Col.ScrollbarGrab, 0.34, 0.34, 0.34, 0.54)
im.Style.setColors(im.Col.ScrollbarGrabHovered, 0.40, 0.40, 0.40, 0.54)
im.Style.setColors(im.Col.ScrollbarGrabActive, 0.56, 0.56, 0.56, 0.54)
im.Style.setColors(im.Col.CheckMark, 0.33, 0.67, 0.86, 1.00)
im.Style.setColors(im.Col.SliderGrab, 0.34, 0.34, 0.34, 0.54)
im.Style.setColors(im.Col.SliderGrabActive, 0.56, 0.56, 0.56, 0.54)
im.Style.setColors(im.Col.Button, 0.05, 0.05, 0.05, 0.54)
im.Style.setColors(im.Col.ButtonHovered, 0.19, 0.19, 0.19, 0.54)
im.Style.setColors(im.Col.ButtonActive, 0.20, 0.22, 0.23, 1.00)
im.Style.setColors(im.Col.Header, 0.00, 0.00, 0.00, 0.52)
im.Style.setColors(im.Col.HeaderHovered, 0.00, 0.00, 0.00, 0.36)
im.Style.setColors(im.Col.HeaderActive, 0.20, 0.22, 0.23, 0.33)
im.Style.setColors(im.Col.Separator, 0.28, 0.28, 0.28, 0.29)
im.Style.setColors(im.Col.SeparatorHovered, 0.44, 0.44, 0.44, 0.29)
im.Style.setColors(im.Col.SeparatorActive, 0.40, 0.44, 0.47, 1.00)
im.Style.setColors(im.Col.ResizeGrip, 0.28, 0.28, 0.28, 0.29)
im.Style.setColors(im.Col.ResizeGripHovered, 0.44, 0.44, 0.44, 0.29)
im.Style.setColors(im.Col.ResizeGripActive, 0.40, 0.44, 0.47, 1.00)
im.Style.setColors(im.Col.Tab, 0.00, 0.00, 0.00, 0.52)
im.Style.setColors(im.Col.TabHovered, 0.14, 0.14, 0.14, 1.00)
im.Style.setColors(im.Col.TabActive, 0.20, 0.20, 0.20, 0.36)
im.Style.setColors(im.Col.TabUnfocused, 0.00, 0.00, 0.00, 0.52)
im.Style.setColors(im.Col.TabUnfocusedActive, 0.14, 0.14, 0.14, 1.00)
im.Style.setColors(im.Col.DockingPreview, 0.33, 0.67, 0.86, 1.00)
im.Style.setColors(im.Col.DockingEmptyBg, 1.00, 0.00, 0.00, 1.00)
im.Style.setColors(im.Col.PlotLines, 1.00, 0.00, 0.00, 1.00)
im.Style.setColors(im.Col.PlotLinesHovered, 1.00, 0.00, 0.00, 1.00)
im.Style.setColors(im.Col.PlotHistogram, 1.00, 0.00, 0.00, 1.00)
im.Style.setColors(im.Col.PlotHistogramHovered, 1.00, 0.00, 0.00, 1.00)
im.Style.setColors(im.Col.TableHeaderBg, 0.00, 0.00, 0.00, 0.52)
im.Style.setColors(im.Col.TableBorderStrong, 0.00, 0.00, 0.00, 0.52)
im.Style.setColors(im.Col.TableBorderLight, 0.28, 0.28, 0.28, 0.29)
im.Style.setColors(im.Col.TableRowBg, 0.00, 0.00, 0.00, 0.00)
im.Style.setColors(im.Col.TableRowBgAlt, 1.00, 1.00, 1.00, 0.06)
im.Style.setColors(im.Col.TextSelectedBg, 0.20, 0.22, 0.23, 1.00)
im.Style.setColors(im.Col.DragDropTarget, 0.33, 0.67, 0.86, 1.00)
im.Style.setColors(im.Col.NavHighlight, 1.00, 0.00, 0.00, 1.00)
im.Style.setColors(im.Col.NavWindowingHighlight, 1.00, 0.00, 0.00, 0.70)
im.Style.setColors(im.Col.NavWindowingDimBg, 1.00, 0.00, 0.00, 0.20)
im.Style.setColors(im.Col.ModalWindowDimBg, 1.00, 0.00, 0.00, 0.35)


im.Style.setWindowPadding(8.00, 8.00)
im.Style.setFramePadding(5.00, 2.00)
im.Style.setCellPadding(6.00, 6.00)
im.Style.setItemSpacing(6.00, 6.00)
im.Style.setItemInnerSpacing(6.00, 6.00)
im.Style.setTouchExtraPadding(0.00, 0.00)
im.Style.setIndentSpacing(25)
im.Style.setScrollbarSize(15)
im.Style.setGrabMinSize(10)
im.Style.setWindowBorderSize(1)
im.Style.setChildBorderSize(1)
im.Style.setPopupBorderSize(1)
im.Style.setFrameBorderSize(1)
im.Style.setTabBorderSize(1)
im.Style.setWindowRounding(7)
im.Style.setChildRounding(4)
im.Style.setFrameRounding(3)
im.Style.setPopupRounding(4)
im.Style.setScrollbarRounding(9)
im.Style.setGrabRounding(3)
im.Style.setLogSliderDeadzone(4)
im.Style.setTabRounding(4)

-- initImpl
im.GLFW.initForOpenGL(window.id, true);
im.OpenGL3.init("#version 300 es");
--

-- ImGui::image に表示するノイズテクスチャを生成
local width = 240
local height = 240
local noisePixels = ffi.new("GLubyte[?]", width * height * 3)
for i = 0, width * height * 3 - 1 do
    noisePixels[i] = math.random(0, 255)
end
local noiseTexture = ffi.new("GLuint[1]")
gl.genTextures(1, noiseTexture)
gl.bindTexture(gl.TEXTURE_2D, noiseTexture[0])
gl.texImage2D(gl.TEXTURE_2D, 0, gl.RGB, width, height, 0, gl.RGB, gl.UNSIGNED_BYTE, noisePixels)
gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_MIN_FILTER, gl.NEAREST)


--
--


while window:shouldClose() == false do
    im.OpenGL3.newFrame()
    im.GLFW.newFrame()
    im.newFrame()
    im.beginWindow("Debug")
    im.text(""..timer:getFPS().."FPS")
    im.text(""..(system:getMemoryUsage()/1000/1000).."MB")
    im.endWindow()
    im.beginWindow("Image")
    im.image(im.intToPtr(noiseTexture[0]), 240, 240)
    im.endWindow()
    im.showDemoWindow()
    im.showMetricsWindow()
    im.showStyleEditor()

    --window:setTitle("FPS:"..timer:getFPS().."|"..(system:getMemoryUsage()/1000/1000).."MB")
    --
    window:setPixels(pixels_buffer)
    window:redraw(false, false)



    im.render()
    im.OpenGL3.renderDrawData(im.getDrawData())

    local backup_current_context = window:getCurrentContext()

    im.updatePlatformWindows()
    im.renderPlatformWindowsDefault()

    window:makeContextCurrent(backup_current_context)

    window:swapBuffers()
    window:pollEvents()

    --
end