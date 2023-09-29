//
//  static_shader.c
//  raia-engine
//
//  Created by dolphilia on 2022/09/30.
//

#include "static_shader.h"

static raia_shader_t raia_shader;

void init_raia_shader(uint8_t* pixel_data, int width, int height) {
    GLfloat vertices[] = {
        -1.0f, 1.0f,  0.0f,  // Position 0
        0.0f,  0.0f,         // TexCoord 0
        -1.0f, -1.0f, 0.0f,  // Position 1
        0.0f,  1.0f,         // TexCoord 1
        1.0f,  -1.0f, 0.0f,  // Position 2
        1.0f,  1.0f,         // TexCoord 2
        1.0f,  1.0f,  0.0f,  // Position 3
        1.0f,  0.0f          // TexCoord 3
    };
    GLushort indices[] = {0, 1, 2, 0, 2, 3};
    
    for (int i = 0; i < sizeof(vertices) / sizeof(vertices[0]); i++) {
        raia_shader.vertices[i] = vertices[i];
    }
    for (int i = 0; i < sizeof(indices) / sizeof(indices[0]); i++) {
        raia_shader.indices[i] = indices[i];
    }

    // create shader program
    raia_shader.program = create_program();
    raia_shader.pos_location = glGetAttribLocation(raia_shader.program, "a_position"); // Attribute locations
    raia_shader.tex_location = glGetAttribLocation(raia_shader.program, "a_texCoord"); // texture coordinate locations
    raia_shader.sampler_location = glGetUniformLocation(raia_shader.program, "s_texture"); // Sampler location

    // Create Texture 2D
    raia_shader.texture = create_texture(pixel_data, width, height);
}

raia_shader_t get_raia_shader(void) {
    return raia_shader;
}
