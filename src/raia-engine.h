//
//  raia-engine.h
//  raia-engine
//
//  Created by dolphilia on 2022/09/09.
//

#ifndef raia_engine_h
#define raia_engine_h

#define GLFW_INCLUDE_ES2
#define GL_GLEXT_PROTOTYPES
#include <stdio.h>
#include <stdlib.h>
#include "platforms.h"
#include "duktape/duktape.h"
#include "util/util_io.h"
#include "util/util_string.h"
#include "util/util_pixel.h"
#include "util/util_math.h"
#include "wrapper/wrapper_glfw.h"
#include "wrapper/wrapper_duktape.h"
#include "static/static_header.h"
#include "static/static_pixel_data.h"
#include "static/static_window.h"
#include "static/static_shader.h"
#include "static/static_duk_ctx.h"
#include "raia/raia_gl.h"
#include "raia/raia_al.h"
#include "raia/raia_duktape.h"

#endif /* raia_engine_h */
