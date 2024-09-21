local ffi = require("ffi")
local skia = require("modules/bindings/skia")
local stb = require("modules/bindings/stb")
local Raia = require("modules/raia")
local im = require("modules/bindings/imgui")
local gl = require("modules/bindings/gles")
-- local glfw = require("modules/bindings/glfw")

-- C標準ライブラリの関数をFFIで宣言
ffi.cdef[[
    typedef struct FILE FILE;
    FILE* fopen(const char* filename, const char* mode);
    size_t fread(void* ptr, size_t size, size_t count, FILE* stream);
    int fseek(FILE* stream, long offset, int origin);
    long ftell(FILE* stream);
    int fclose(FILE* stream);
    void* malloc(size_t size);
    void free(void* ptr);
]]

-- 定数をLua側で定義
local SEEK_SET = 0
local SEEK_CUR = 1
local SEEK_END = 2

-- ファイルをメモリに読み込む関数
local function load_file_to_memory(filename)
    -- ファイルを開く
    local file = ffi.C.fopen(filename, "rb")
    if file == nil then
        return nil, "ファイルが開けませんでした: " .. filename
    end

    -- ファイルサイズを取得
    ffi.C.fseek(file, 0, SEEK_END)
    local file_size = ffi.C.ftell(file)
    ffi.C.fseek(file, 0, SEEK_SET)

    -- メモリを確保してファイルを読み込む
    local buffer = ffi.C.malloc(file_size)
    if buffer == nil then
        ffi.C.fclose(file)
        return nil, "メモリ確保に失敗しました"
    end
    ffi.C.fread(buffer, 1, file_size, file)
    ffi.C.fclose(file)

    return buffer, file_size
end

-- メモリを解放する関数
local function free_memory(buffer)
    ffi.C.free(buffer)
end

--

Paint = {}
Paint.__index = Paint

function Paint:new()
    local getter = function(t, key)
        if key == "color" then
            return {
                rawget(t, "_color_red"),
                rawget(t, "_color_green"),
                rawget(t, "_color_blue"),
                rawget(t, "_color_alpha"),
            }
        else
            return Paint[key]
        end
    end

    local setter = function(t, key, value)
        if key == "color" then
            if raia.lua.type(value) == "table" and #value == 4 then
                t:setColorRGBA(value[1], value[2], value[3], value[4])
            else
                error("Position must be a table with at least two numeric values")
            end
        else
            rawset(t, key, value)
        end
    end

    local instance = {}
    setmetatable(instance, {
        __index = getter,
        __newindex = setter
    })

    -- デストラクタの設定
    local gc_proxy = ffi.new("struct {}")
    local destructor_callback = function()
        if instance.destructor then
            instance:destructor()
        end
    end
    ffi.gc(gc_proxy, destructor_callback)
    instance._gc_proxy = gc_proxy

    local paint = skia.Paint.new()
    skia.Paint.setARGB(paint, 255, 0, 0, 0)
    skia.Paint.setAntiAlias(paint, true) -- アンチエイリアシングをオンにする
    skia.Paint.setStyle(paint, skia.Paint.Style.Fill) -- 塗りつぶし

    rawset(instance, "_paint", paint)
    rawset(instance, "_color_red", 0)
    rawset(instance, "_color_green", 0)
    rawset(instance, "_color_blue", 0)
    rawset(instance, "_color_alpha", 255)
    rawset(instance, "_antialias", true)
    rawset(instance, "_style", skia.Paint.Style.Fill) -- 0

    return instance
end

function Paint:destructor()
    self._paint = nil
    collectgarbage()
end

function Paint:setColorRGBA(r, g, b, a)
    r = r or self._color_red
    g = g or self._color_green
    b = b or self._color_blue
    a = a or self._color_alpha
    local paint = self._paint
    skia.Paint.setARGB(paint, a, r, g, b)
    rawset(self, "_color_red", r)
    rawset(self, "_color_green", g)
    rawset(self, "_color_blue", b)
    rawset(self, "_color_alpha", a)
end

function Paint:setColor(r, g, b, a)
    self:setColorRGBA(r, g, b, a)
end

-- ペイントのスタイルを設定 (style == 0: 塗りつぶし, 1: 線画, 2: 線画と塗りつぶし)
function Paint:setStyle(style)
    local paint = self._paint
    skia.Paint.setStyle(paint, style)
end

function Paint:setStrokeWidth(width)
    local paint = self._paint
    skia.Paint.setStrokeWidth(paint, width)  
end

function Paint:getPaint()
    return self._paint
end

function Paint:getColorRed()
    return self._color_red
end

function Paint:getColorGreen()
    return self._color_green
end

function Paint:getColorBlue()
    return self._color_blue
end

function Paint:getColorAlpha()
    return self._color_alpha
end

--

Font = {}
Font.__index = Font

function Font:new()
    local font_data_raw, font_data_size = load_file_to_memory("Mplus1-Regular.ttf")

    rawset(instance, "_font_data_raw", font_data_raw)
    --
    rawset(instance, "_font_size", 24)
    rawset(instance, "_font_data_size", font_data_size)
end

--

Surface = {}
Surface.__index = Surface

function Surface:new(width, height)
    width = width or 300
    height = height or 300

    local getter = function(t, key)
        if key == "paint" then
            return rawget(t, "_paint")
        elseif key == "opacity" then
            return rawget(t, "_opacity")
        elseif key == "bitmap" then
            return rawget(t, "_bitmap")
        elseif key == "position" then
            return {
                rawget(t, "_current_position_x"),
                rawget(t, "_current_position_y")
            }
        elseif key == "size" then
            return {
                rawget(t, "_width"),
                rawget(t, "_height")
            }
        else
            return Surface[key]
        end
    end

    local setter = function(t, key, value)
        if key == "position" then
            if raia.lua.type(value) == "table" and #value == 2 then
                t:setPosition(value[1], value[2])
            else
                error("Position must be a table with at least two numeric values")
            end
        elseif key == "size" then
            if raia.lua.type(value) == "table" and #value == 2 then
                t:setSize(value[1], value[2])
            else
                error("Position must be a table with at least two numeric values")
            end
        elseif key == "currentColor" then
            if raia.lua.type(value) == "table" and #value == 4 then
                t:setCurrentColorRGBA(value[1], value[2], value[3], value[4])
            else
                error("Position must be a table with at least two numeric values")
            end
        else
            rawset(t, key, value)
        end
    end

    local instance = {}
    setmetatable(instance, {
        __index = getter,
        __newindex = setter
    })

    -- デストラクタの設定
    local gc_proxy = ffi.new("struct {}")
    local destructor_callback = function()
        if instance.destructor then
            instance:destructor()
        end
    end
    ffi.gc(gc_proxy, destructor_callback)
    instance._gc_proxy = gc_proxy

    -- Surface の初期化
    local image_info = skia.ImageInfo.Make(width, height, skia.ColorType.RGBA8888, skia.AlphaType.Opaque)
    local bitmap = skia.Bitmap.new()
    skia.Bitmap.allocPixels_3(bitmap, skia.Static.SkImageInfo.get(image_info))
    local canvas = skia.Canvas.new_3(bitmap)
    local paint = Paint.new()
    local font_data_raw, font_data_size = load_file_to_memory("Mplus1-Regular.ttf")
    local rect = skia.Rect.MakeXYWH(0, 0, 500, 500)
    
    -- インスタンスのプロパティを設定
    rawset(instance, "_image_info", image_info)
    rawset(instance, "_bitmap", bitmap)
    rawset(instance, "_canvas", canvas)
    rawset(instance, "_paint", paint)
    rawset(instance, "_rect", rect)
    rawset(instance, "_font_data_raw", font_data_raw)
    --
    rawset(instance, "_font_data_size", font_data_size)
    rawset(instance, "_opacity", 1.0)
    rawset(instance, "_current_position_x", 0)
    rawset(instance, "_current_position_y", 0)
    rawset(instance, "_width", width)
    rawset(instance, "_height", height)
    rawset(instance, "_antialias", true)
    rawset(instance, "_font_size", 24)
    return instance
end

-- デストラクタ
function Surface:destructor()
    self._image_info = nil
    self._bitmap = nil
    self._canvas = nil
    self._paint = nil
    self._rect = nil
    if self._font_data_raw ~= nil then
        free_memory(self._font_data_raw)
        self._font_data_raw = nil
    end
    collectgarbage()
end

function Surface:setPosition(x, y)
    rawset(self, "_current_position_x", x)
    rawset(self, "_current_position_y", y)
end

-- 色を設定
function Surface:setColorRGBA(r, g, b, a)
    local paint = self._paint
    paint:setColor(r, g, b, a)
end

function Surface:setColor(r, g, b, a)
    self:setColorRGBA(r, g, b, a)
end

-- ペイントのスタイルを設定 (style == 0: 塗りつぶし, 1: 線画, 2: 線画と塗りつぶし)
function Surface:setStyle(style)
    local paint = self._paint
    skia.Paint.setStyle(paint:getPaint(), style)
end

-- 枠線の幅を設定
function Surface:setStrokeWidth(width)
    local paint = self._paint
    skia.Paint.setStrokeWidth(paint:getPaint(), width)  
end

-- 矩形を描画
function Surface:drawRect(x, y, width, height)
    local canvas = self._canvas
    local paint = self._paint
    local rect = self._rect
    skia.Rect.setXYWH(skia.Static.SkRect.get(rect), x, y, width, height)
    skia.Canvas.drawRect(canvas, rect, paint:getPaint())
end

-- 角丸矩形を描画
function Surface:drawRoundRect(x, y, width, height, rx, ry)
    local canvas = self._canvas
    local paint = self._paint
    local rect = self._rect
    skia.Rect.setXYWH(skia.Static.SkRect.get(rect), x, y, width, height)
    skia.Canvas.drawRoundRect(canvas, skia.Static.SkRect.get(rect), rx, ry, paint:getPaint())
end

-- ピクセルを取得する
function Surface:getPixels()
    local bitmap = self._bitmap
    return skia.Bitmap.getPixels(bitmap)
end

-- 文字を描画する
function Surface:drawText(text, x, y)
    x = x or self._current_position_x
    y = y or self._current_position_y
    local canvas = self._canvas
    local paint = self._paint
    local font_data_raw = self._font_data_raw
    local font_data_size = self._font_data_size
    local font_data = skia.Data.MakeWithCopy(font_data_raw, font_data_size)--skia.Data.MakeFromFileName("Mplus1-Regular.ttf")
    local typeface = skia.Typeface.MakeFromData(font_data, 0)--skia.Typeface.MakeFromFile("Mplus1-Regular.ttf", 0)
    local font_size = self._font_size
    local font = skia.Font.new_4(typeface, font_size, 1.0, 0.0)
    local textblob = skia.TextBlob.MakeFromString(text, font, 0) -- SkTextEncoding::kUTF8 = 0
    skia.Font.setTypeface(font, typeface)
    skia.Canvas.drawTextBlob(canvas, textblob, x, y, paint:getPaint())
    --
    font_data = nil
    typeface = nil
    font = nil
    textblob = nil
    collectgarbage()
end

-- フォントサイズを設定する
function Surface:setFontSize(size)
    rawset(self, "_font_size", size)
end

-- return Surface

--

local surface = Surface:new(800, 600)
surface:setColor(255, 255, 255, 255)
surface:drawRect(0, 0, 800, 600)
surface:setColor(0, 0, 0, 128)
surface:drawRoundRect(100, 100, 600, 400, 10, 10)

surface:setColor(0, 0, 0, 255)
surface:setStyle(1)
surface:setStrokeWidth(5)
surface:drawRoundRect(100, 100, 600, 400, 10, 10)

surface:setFontSize(64)
surface:setColor(255, 255, 255, 255)
surface:setStyle(0)  -- スタイルを塗りつぶしに設定
surface:setPosition(100, 200)
surface:drawText("こんにちは! Raia!")

surface:setColor(0, 0, 0, 255)
surface:setStyle(1)
surface:setStrokeWidth(2)
surface:setPosition(100, 200)
surface:drawText("こんにちは! Raia!")



-- グラデーションを描画する

ffi.cdef[[
typedef uint32_t SkColor;
]]

--[[
local points = skia.Static.SkPointTwo.make(0, 0, 0, 500)
local SK_ColorBLUE = 0xFF0000EE  -- A=255, R=0, G=0, B=255
local SK_ColorYELLOW = 0xFF000055  -- A=255, R=255, G=255, B=0
local colors = ffi.new("SkColor[2]", {SK_ColorBLUE, SK_ColorYELLOW})
local shader_key = skia.GradientShader.MakeLinear(skia.Static.SkPointTwo.get(points), colors, nil, 2, skia.TileMode.Clamp, 0, nil)
skia.Paint.setShader(paint, shader_key)
skia.Paint.setBlendMode(paint, skia.BlendMode.Overlay)
skia.Canvas.drawPaint(canvas, paint)
]]

-- 画像を読み込む

ffi.cdef[[
    void* memcpy(void* dest, const void* src, size_t n);
]]

--[[
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
]]
--


local pixels = surface:getPixels()
local pixels_buffer = ffi.new("char[?]", 800 * 600 * 4)
ffi.C.memcpy(pixels_buffer, pixels, 800 * 600 * 4)

surface.font_data_raw = nil
surface = nil

collectgarbage()

-- bitmap = nil
-- rect = nil
--collectgarbage("collect")
--

local system = Raia.System:new()
local timer = Raia.Timer:new()
local window = Raia.Window:new("RaiaEngine", 800, 600)

window.position = {0, 0}

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
end

window = nil
collectgarbage()