import {GLFW} from 'raia_glfw';

const glfw = new GLFW();

glfw.init();
glfw.windowHint(GLFW.CLIENT_API, GLFW.OPENGL_ES_API);
glfw.windowHint(GLFW.CONTEXT_VERSION_MAJOR, 3);
glfw.windowHint(GLFW.CONTEXT_VERSION_MINOR, 0);
glfw.windowHint(GLFW.OPENGL_PROFILE, GLFW.OPENGL_CORE_PROFILE);
glfw.windowHint(GLFW.CONTEXT_CREATION_API, GLFW.EGL_CONTEXT_API);
glfw.setErrorCallbackAlt();
glfw.setJoystickCallbackAlt();

const window = glfw.createWindow(800, 600, "title");

while(glfw.windowShouldClose(window) === 0) {
    glfw.swapBuffers(window);
    glfw.pollEvents();
}