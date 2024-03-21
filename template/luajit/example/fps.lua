
local ffi = require("ffi")
local gl = require("modules/gles")
local glfw = require("modules/glfw")

if glfw.init() == 0 then
    error("Failed to initialize GLFW")
end

glfw.windowHint(glfw.CLIENT_API, glfw.OPENGL_ES_API)
glfw.windowHint(glfw.CONTEXT_VERSION_MAJOR, 3)
glfw.windowHint(glfw.CONTEXT_VERSION_MINOR, 0)
glfw.windowHint(glfw.OPENGL_PROFILE, glfw.OPENGL_CORE_PROFILE)
glfw.windowHint(glfw.CONTEXT_CREATION_API, glfw.EGL_CONTEXT_API)

local width, height = 800, 600
local window = glfw.createWindow(width, height, "Random Noise")
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

while glfw.windowShouldClose(window) == 0 do
    gl.viewport(0, 0, 800*2, 600*2)
    gl.clearColor(1.0, 1.0, 1.0, 1.0)
    gl.clear(gl.COLOR_BUFFER_BIT)

    gl.bindTexture(gl.TEXTURE_2D, noiseTexture[0])
    gl.texImage2D(gl.TEXTURE_2D, 0, gl.RGBA, width, height, 0, gl.RGBA, gl.UNSIGNED_BYTE, noiseData)
    
    gl.clear(gl.COLOR_BUFFER_BIT)
    gl.useProgram(shader_program)
    gl.bindVertexArray(vao[0])
    gl.activeTexture(gl.TEXTURE0)
    gl.drawElements(gl.TRIANGLES, 6, gl.UNSIGNED_INT, nil)

    for i = 0, width * height * 4 - 1 do
        noiseData[i] = math.random(0, 255)
    end

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