//
//  wrapper_gles.c
//  raia-engine
//
//  Created by dolphilia on 2022/09/30.
//

#include "wrapper_gles.h"

GLuint create_shader(GLenum type, const char *shader_src) {
    GLuint shader = glCreateShader(type);
    glShaderSource (shader, 1, &shader_src, NULL);
    glCompileShader (shader);
    GLint compiled;
    glGetShaderiv (shader, GL_COMPILE_STATUS, &compiled);
    return shader;
}

GLuint create_program(void) {
    GLbyte vShaderStr[] =
        "attribute vec4 a_position;"
        "attribute vec2 a_texCoord;"
        "varying vec2 v_texCoord;"
        "void main() {"
        "    gl_Position = a_position;"
        "    v_texCoord = a_texCoord;"
        "}";
    GLbyte fShaderStr[] =
        "precision mediump float;"
        "varying vec2 v_texCoord;"
        "uniform sampler2D s_texture;"
        "void main() {"
        "    gl_FragColor = texture2D(s_texture, v_texCoord);"
        "}";
    GLuint program = glCreateProgram(); // Handle to a program object
    GLuint vs = create_shader(GL_VERTEX_SHADER, (const char*)vShaderStr);
    GLuint fs = create_shader(GL_FRAGMENT_SHADER, (const char*)fShaderStr);
    glAttachShader(program, vs);
    glDeleteShader(vs);
    glAttachShader(program, fs);
    glDeleteShader(fs);
    glLinkProgram (program); // Link the program
    return program;
}

GLuint create_texture(GLubyte* pixels, int width, int height) {
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1); // Use tightly packed data
    GLuint texture; // Generate a texture object
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture); // Bind the texture object
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, pixels);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); // Set the filtering mode
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    return texture;
}
