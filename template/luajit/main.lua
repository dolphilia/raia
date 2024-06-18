local ffi = require("ffi")
local gl = require("modules/bindings/gles")
local glfw = require("modules/bindings/glfw")
local skia = require("modules/bindings/skia")

-- 初期化処理

if glfw.init() == 0 then
    error("Failed to initialize GLFW")
end

glfw.windowHint(glfw.CLIENT_API, glfw.OPENGL_ES_API)
glfw.windowHint(glfw.CONTEXT_VERSION_MAJOR, 3)
glfw.windowHint(glfw.CONTEXT_VERSION_MINOR, 0)
glfw.windowHint(glfw.OPENGL_PROFILE, glfw.OPENGL_CORE_PROFILE)
glfw.windowHint(glfw.CONTEXT_CREATION_API, glfw.EGL_CONTEXT_API)
glfw.windowHint(glfw.VISIBLE, glfw.TRUE)


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

--skia.Paint.setStyle(paint, skia.Paint.Style.Fill)
skia.Paint.setARGB(paint, 255, 255, 255, 255)
skia.Paint.setStyle(paint, skia.Paint.Style.Fill)  -- スタイルを枠線に設定
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



local pixels = skia.Bitmap.getPixels(bitmap);

bitmap = nil
rect = nil
collectgarbage("collect")


--

local width, height = 800, 600
local window = glfw.createWindow(width, height, "RaiaEngine")
if window == nil then
    glfw.terminate()
    error("Failed to create GLFW window")
end

glfw.makeContextCurrent(window)
glfw.swapInterval(1)

local vertices = ffi.new("float[32]", {
    -1.0, 1.0, 0.0,  0.0, 0.0,  -- Position 0, TexCoord 0
    -1.0, -1.0, 0.0,  0.0, 1.0, -- Position 1, TexCoord 1
     1.0, -1.0, 0.0,  1.0, 1.0, -- Position 2, TexCoord 2
     1.0, 1.0, 0.0,  1.0, 0.0   -- Position 3, TexCoord 3
})

local indices = ffi.new("unsigned int[6]", {0, 1, 2, 0, 2, 3})
local vao = ffi.new("GLuint[1]")
local vbo = ffi.new("GLuint[1]")
local ebo = ffi.new("GLuint[1]")

gl.genVertexArrays(1, vao)
gl.genBuffers(1, vbo)
gl.genBuffers(1, ebo)

gl.bindVertexArray(vao[0])
gl.bindBuffer(gl.ARRAY_BUFFER, vbo[0])
gl.bufferData(gl.ARRAY_BUFFER, ffi.sizeof(vertices), vertices, gl.STATIC_DRAW)
gl.bindBuffer(gl.ELEMENT_ARRAY_BUFFER, ebo[0])
gl.bufferData(gl.ELEMENT_ARRAY_BUFFER, ffi.sizeof(indices), indices, gl.STATIC_DRAW)

gl.vertexAttribPointer(0, 3, gl.FLOAT, gl.FALSE, 5 * ffi.sizeof("float"), ffi.cast("void *", 0))
gl.enableVertexAttribArray(0)
gl.vertexAttribPointer(1, 2, gl.FLOAT, gl.FALSE, 5 * ffi.sizeof("float"), ffi.cast("void *", 3 * ffi.sizeof("float")))
gl.enableVertexAttribArray(1)
gl.bindVertexArray(0)

local vertex_shader_source = [[
    attribute vec4 a_position;
    attribute vec2 a_texCoord;
    varying vec2 v_texCoord;
    void main() {
        gl_Position = a_position;
        v_texCoord = a_texCoord;
    }
]]

local fragment_shader_source = [[
    precision mediump float;
    varying vec2 v_texCoord;
    uniform sampler2D s_texture;
    void main() {
        gl_FragColor = texture2D(s_texture, v_texCoord);
    }
]]

local vertex_shader = gl.createShader(gl.VERTEX_SHADER)
gl.shaderSource(vertex_shader, 1, ffi.new("const char*[1]", {vertex_shader_source}), nil)
gl.compileShader(vertex_shader)
local fragment_shader = gl.createShader(gl.FRAGMENT_SHADER)
gl.shaderSource(fragment_shader, 1, ffi.new("const char*[1]", {fragment_shader_source}), nil);
gl.compileShader(fragment_shader);
local shader_program = gl.createProgram()
gl.attachShader(shader_program, vertex_shader)
gl.attachShader(shader_program, fragment_shader)
gl.linkProgram(shader_program)
gl.deleteShader(vertex_shader)
gl.deleteShader(fragment_shader)

local noiseTexture = ffi.new("GLuint[1]")
gl.genTextures(1, noiseTexture)
gl.bindTexture(gl.TEXTURE_2D, noiseTexture[0])
gl.texImage2D(gl.TEXTURE_2D, 0, gl.RGBA, width, height, 0, gl.RGBA, gl.UNSIGNED_BYTE, noiseData)
gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_MIN_FILTER, gl.NEAREST)
gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_MAG_FILTER, gl.NEAREST)

local frameCount = 0
local noiseTable = {}
local noiseData = ffi.new("GLubyte[?]", width * height * 4)
local previousTime = glfw.getTime()

-- ピクセルデータの確認用
-- RGBAデータを格納するバッファのサイズ
--[[
local pixel_size = 4 -- RGBAは4バイト
local buffer_size = width * height * pixel_size

-- uint8_t配列を作成
local buffer = ffi.new("uint8_t[?]", buffer_size)

-- バッファを赤色（RGBA: 255, 0, 0, 255）で初期化
for i = 0, buffer_size - 1, pixel_size do
    buffer[i] = 0      -- R
    buffer[i + 1] = 255    -- G
    buffer[i + 2] = 0    -- B
    buffer[i + 3] = 255  -- A
end
--
]]

while glfw.windowShouldClose(window) == 0 do
    gl.viewport(0, 0, 800, 600)
    gl.clearColor(1.0, 1.0, 1.0, 1.0)
    gl.clear(gl.COLOR_BUFFER_BIT)

    gl.bindTexture(gl.TEXTURE_2D, noiseTexture[0])
    gl.texImage2D(gl.TEXTURE_2D, 0, gl.RGBA, width, height, 0, gl.RGBA, gl.UNSIGNED_BYTE, pixels)
    
    gl.clear(gl.COLOR_BUFFER_BIT)
    gl.useProgram(shader_program)
    gl.bindVertexArray(vao[0])
    gl.activeTexture(gl.TEXTURE0)
    gl.drawElements(gl.TRIANGLES, 6, gl.UNSIGNED_INT, nil)

    -- フレームレート
    frameCount = frameCount + 1
    local currentTime = glfw.getTime()
    local elapsedTime = currentTime - previousTime

    -- 1秒ごとにフレームレートを計算して表示
    if elapsedTime >= 1.0 then
        print(frameCount / elapsedTime);
        previousTime = currentTime
        frameCount = 0
    end

    glfw.swapBuffers(window)
    glfw.pollEvents()
end

gl.deleteTextures(1, noiseTexture)
gl.deleteProgram(shader_program)
glfw.destroyWindow(window)
glfw.terminate()