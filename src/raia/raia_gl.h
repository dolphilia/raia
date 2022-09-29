//
//  raia_glfw.h
//  raia-engine
//
//  Created by dolphilia on 2022/09/09.
//

#ifndef raia_gl_h
#define raia_gl_h

#define GLFW_INCLUDE_ES2
#define GL_GLEXT_PROTOTYPES
#include <stdio.h>
#include "static/static_header.h"
#include "static/static_window.h"
#include "static/static_pixel_data.h"
#include "static/static_shader.h"
#include "wrapper/wrapper_gles.h"
#include "util/util_math.h"

void glfw_start(void);
void glfw_redraw(void);

#endif /* raia_glfw_h */
