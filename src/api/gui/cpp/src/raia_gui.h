//
// Created by dolphilia on 2023/08/08.
//

#ifndef RAIA_GUI_RAIA_GUI_H
#define RAIA_GUI_RAIA_GUI_H

#include "../../../../third_party/cpp/ocornut/imgui/imgui.h"
#include "../../../../third_party/cpp/ocornut/imgui/imgui_impl_glfw.h"
#include "../../../../third_party/cpp/ocornut/imgui/imgui_impl_opengl3.h"

extern "C" {
#include <time.h>
#include "../../../../common/c/utility/export_api.h"
#include "../../../../common/c/utility/platform.h"
#include "../../../../common/c/wrapper/wrapper_yyjson.h"
#define STB_IMAGE_IMPLEMENTATION
#include "../../../../third_party/c/nothings/stb/stb_image.h"
#include "util/util_math.h"
#include "static/static_callback.h"
#include "GLFW/glfw3.h" // Will drag system OpenGL headers

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


#endif //RAIA_GUI_RAIA_GUI_H
