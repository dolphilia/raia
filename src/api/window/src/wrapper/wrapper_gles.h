//
//  wrapper_gles.h
//  raia-engine
//
//  Created by dolphilia on 2022/09/30.
//

#ifndef wrapper_gles_h
#define wrapper_gles_h

#include <stdio.h>
#define GLFW_INCLUDE_ES2
#include "GLFW/glfw3.h"
#include "EGL/egl.h"

GLuint create_shader(GLenum type, const char *shader_src);
GLuint create_program(void);
GLuint create_texture(GLubyte* pixels, int width, int height);

#endif /* wrapper_gles_h */
