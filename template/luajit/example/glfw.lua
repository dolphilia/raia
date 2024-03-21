local glfw = require("modules/glfw")

glfw.init()
glfw.windowHint(glfw.CLIENT_API, glfw.OPENGL_ES_API)
glfw.windowHint(glfw.CONTEXT_VERSION_MAJOR, 3)
glfw.windowHint(glfw.CONTEXT_VERSION_MINOR, 0)
glfw.windowHint(glfw.OPENGL_PROFILE, glfw.OPENGL_CORE_PROFILE)
glfw.windowHint(glfw.CONTEXT_CREATION_API, glfw.EGL_CONTEXT_API)
glfw.setErrorCallbackAlt()
glfw.setJoystickCallbackAlt();

local window = glfw.createWindow(800, 600, "title")

while glfw.windowShouldClose(window) == 0 do
    glfw.swapBuffers(window)
    glfw.pollEvents()
end