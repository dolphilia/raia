#ifndef RAIA_WINDOW_RAIA_APP_H
#define RAIA_WINDOW_RAIA_APP_H

#include <time.h>
#include <stdio.h>
#define GLFW_INCLUDE_ES3
#define GL_GLEXT_PROTOTYPES
#include "GLFW/glfw3.h"
#include "GLES3/gl32.h"
#include "EGL/egl.h"
#include "static/static_callback.h"
#include "../../../../share/c/utility/export_api.h"
#include "../../../../share/c/utility/platform.h"
#include "../../../../share/c/wrapper/wrapper_yyjson.h"
#include "../../../../thirdparty/c/ibireme/yyjson.h"

#ifdef __WINDOWS__
#define GL_TEXTURE0 0x84C0
#endif

#endif //RAIA_WINDOW_RAIA_APP_H
