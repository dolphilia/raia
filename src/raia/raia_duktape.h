//
//  raia_duktape.h
//  raia-engine
//
//  Created by dolphilia on 2022/09/09.
//

#ifndef raia_duktape_h
#define raia_duktape_h

#define GLFW_INCLUDE_ES2
#define GL_GLEXT_PROTOTYPES
#include <stdio.h>
#include <time.h>
#ifdef _WIN32
#include <windows.h>
#else
#include <dlfcn.h>
#endif
#include "GLFW/glfw3.h"
#include "EGL/egl.h"
#include "static/static_pixel_data.h"
#include "static/static_header.h"
#include "static/static_window.h"
#include "static/static_duk_ctx.h"
#include "static/static_dlfcn.h"
#include "wrapper/wrapper_glfw.h"
#include "wrapper/wrapper_duktape.h"
#include "wrapper/wrapper_stb_image.h"
#include "util/util_pixel.h"
#include "util/util_math.h"
#include "raia/raia_gl.h"
#include "duktape/duktape.h"
#include "duktape_module/duk_module_duktape.h"


void duktape_start(void);

#endif /* raia_duktape_h */
