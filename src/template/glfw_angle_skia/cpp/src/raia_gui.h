//
// Created by dolphilia on 2023/08/08.
//

#ifndef RAIA_GUI_RAIA_GUI_H
#define RAIA_GUI_RAIA_GUI_H

extern "C" {
#include <time.h>
#include "../../../../common/c/utility/export_api.h"
#include "../../../../common/c/utility/platform.h"
#include "../../../../common/c/wrapper/wrapper_yyjson.h"
#define STB_IMAGE_IMPLEMENTATION
#include "../../../../third_party/c/nothings/stb/stb_image.h"
#include "GLFW/glfw3.h" // Will drag system OpenGL headers
#include "EGL/egl.h"
#include "GLES3/gl32.h"

#ifdef __WINDOWS__
#define GL_TEXTURE0 0x84C0
#endif

}

//#define GL_SILENCE_DEPRECATION
//#define IMGUI_IMPL_OPENGL_ES2
//#if defined(IMGUI_IMPL_OPENGL_ES2)
//#include "GLES3/gl32.h"
//#endif
//#include <random>
// [Win32] Our example includes a copy of glfw3.lib pre-compiled with VS2010 to maximize ease of testing and compatibility with old VS compilers.
// To link with VS2010-era libraries, VS2015+ requires linking with legacy_stdio_definitions.lib, which we do using this pragma.
// Your own project should not be affected, as you are likely to link with a newer binary of GLFW that is adequate for your version of Visual Studio.
//#if defined(_MSC_VER) && (_MSC_VER >= 1900) && !defined(IMGUI_DISABLE_WIN32_FUNCTIONS)
//#pragma comment(lib, "legacy_stdio_definitions")
//#endif

// This example can also compile and run with Emscripten! See 'Makefile.emscripten' for details.
//#ifdef __EMSCRIPTEN__
//#include "../libs/emscripten/emscripten_mainloop_stub.h"
//#endif

void event_error_callback(int error, const char *message);
void event_joystick_callback(int jid, int event);
void event_window_pos_callback(GLFWwindow *window, int x, int y);
void event_window_size_callback(GLFWwindow *window, int width, int height);
void event_window_close_callback(GLFWwindow *window);
void event_window_refresh_callback(GLFWwindow *window);
void event_window_focus_callback(GLFWwindow* window, int focused);
void event_window_iconify_callback(GLFWwindow *window, int iconified);
void event_framebuffer_size_callback(GLFWwindow *window, int width, int height);
void event_key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
void event_cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
void event_mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
void event_character_callback(GLFWwindow* window, unsigned int codepoint);
void event_character_mods_callback(GLFWwindow *window, unsigned int codepoint, int mods);
void event_cursor_enter_callback(GLFWwindow* window, int entered);
void event_scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
void event_drop_callback(GLFWwindow* window, int count, const char** paths);

#endif //RAIA_GUI_RAIA_GUI_H
