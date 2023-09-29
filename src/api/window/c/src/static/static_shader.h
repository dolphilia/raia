//
//  static_shader.h
//  raia-engine
//
//  Created by dolphilia on 2022/09/30.
//

#ifndef static_shader_h
#define static_shader_h

#include <stdio.h>
#define GLFW_INCLUDE_ES2
#include "../wrapper/wrapper_glfw.h"
#include "../wrapper/wrapper_gles.h"

// raia_shader ヘッダー構造体
typedef struct raia_shader_t {
    GLfloat vertices[20];
    GLushort indices[6];
    GLuint program; // create shader program
    GLint pos_location; // Attribute locations
    GLint tex_location; // texture coordinate locations
    GLint sampler_location; // Sampler location
    GLuint texture;
} raia_shader_t;

void init_raia_shader(uint8_t* pixel_data, int width, int height);
raia_shader_t get_raia_shader(void);

#endif /* static_shader_h */
