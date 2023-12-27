//
// Created by dolphilia on 2023/08/08.
//

#ifndef RAIA_GUI_RAIA_SKIA_H
#define RAIA_GUI_RAIA_SKIA_H

extern "C" {
#include <time.h>
#include "../../../common/c/utility/export_api.h"
#include "../../../common/c/utility/platform.h"
#include "../../../common/c/wrapper/wrapper_yyjson.h"
#define STB_IMAGE_IMPLEMENTATION
#include "../../../third_party/c/nothings/stb/stb_image.h"
#include "GLFW/glfw3.h" // Will drag system OpenGL headers
#include "EGL/egl.h"
#include "GLES3/gl32.h"

#ifdef __WINDOWS__
#define GL_TEXTURE0 0x84C0
#endif
}

#endif //RAIA_GUI_RAIA_SKIA_H
