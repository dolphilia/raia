local ffi = require("ffi")
local Raia = require("modules/raia")
local im = require("modules/bindings/imgui")
local gl = require("modules/bindings/gles")
local ma = require("modules/bindings/miniaudio")
local Surface = require("modules/surface")

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
collectgarbage()
surface:setColor(0, 0, 0, 255)
surface:setStyle(1)
surface:setStrokeWidth(2)
surface:setPosition(100, 200)
surface:drawText("こんにちは! Raia!")

surface:drawGradient(0, 0, 0, 500, 0xFF0000EE, 0xFF000055)

surface:drawImage("miga.png", 100, 300)

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

    window:setPixels(pixels)
    window:redraw(false, false)

    im.render()
    im.OpenGL3.renderDrawData(im.getDrawData())
    local backup_current_context = window:getCurrentContext()
    im.updatePlatformWindows()
    im.renderPlatformWindowsDefault()
    window:makeContextCurrent(backup_current_context)

    window:swapBuffers()
    window:pollEvents()
    collectgarbage()
end

window = nil
collectgarbage()