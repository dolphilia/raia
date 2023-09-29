#include "raia_gles.h"

static const char *raia_not_use_s(const char *s) {
    return s;
}

RAIA_API const char *raia_gl_viewport(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    int x = joint_get_in_int(joint, "x");
    int y = joint_get_in_int(joint, "y");
    int width = joint_get_in_int(joint, "width");
    int height = joint_get_in_int(joint, "height");
    glViewport(x, y, width, height);
    joint_free(joint);
    return NULL;
}

RAIA_API const char *raia_gl_clear_color(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    double red = joint_get_in_real(joint, "red");
    double green = joint_get_in_real(joint, "green");
    double blue = joint_get_in_real(joint, "blue");
    double alpha = joint_get_in_real(joint, "alpha");
    glClearColor((float) red, (float) green, (float) blue, (float) alpha);
    joint_free(joint);
    return NULL;
}

RAIA_API const char *raia_gl_clear(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    GLbitfield mask = joint_get_in_uint(joint, "mask");
    glClear(mask);
    joint_free(joint);
    return NULL;
}

RAIA_API const char *raia_gl_use_program(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    GLuint program = joint_get_in_uint(joint, "program");
    glUseProgram(program);
    joint_free(joint);
    return NULL;
}

RAIA_API const char *raia_gl_vertex_attrib_pointer(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    GLuint index = joint_get_in_uint(joint, "index");
    GLint size = joint_get_in_int(joint, "size");
    GLenum type = joint_get_in_uint(joint, "type");
    GLboolean normalized = joint_get_in_uint(joint, "normalized");
    GLsizei stride = joint_get_in_int(joint, "stride");
    const void *pointer = (const void *) (uintptr_t) joint_get_in_uint(joint, "pointer"); // Float32Array
    glVertexAttribPointer(index, size, type, normalized, stride, pointer);
    joint_free(joint);
    return NULL;
}

RAIA_API const char *raia_gl_enable_vertex_attrib_array(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    GLuint index = joint_get_in_uint(joint, "index");
    glEnableVertexAttribArray(index);
    joint_free(joint);
    return NULL;
}

RAIA_API const char *raia_gl_tex_image_2d(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    GLenum target = joint_get_in_uint(joint, "target");
    GLint level = joint_get_in_int(joint, "level");
    GLint internalformat = joint_get_in_int(joint, "internalformat");
    GLsizei width = joint_get_in_int(joint, "width");
    GLsizei height = joint_get_in_int(joint, "height");
    GLint border = joint_get_in_int(joint, "border");
    GLenum format = joint_get_in_uint(joint, "format");
    GLenum type = joint_get_in_uint(joint, "type");
    const void *pixels = (const void *) (uintptr_t) joint_get_in_uint(joint, "pixels");
    glTexImage2D(target, level, internalformat, width, height, border, format, type, pixels);
    joint_free(joint);
    return NULL;
}

RAIA_API const char *raia_gl_active_texture(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    GLenum texture = joint_get_in_uint(joint, "texture");
    glActiveTexture(texture);
    joint_free(joint);
    return NULL;
}

RAIA_API const char *raia_gl_bind_texture(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    GLenum target = joint_get_in_uint(joint, "target");
    GLuint texture = joint_get_in_uint(joint, "texture");
    glBindTexture(target, texture);
    joint_free(joint);
    return NULL;
}

RAIA_API const char *raia_gl_uniform_1i(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    GLint location = joint_get_in_int(joint, "location");
    GLint v0 = joint_get_in_int(joint, "v0");
    glUniform1i(location, v0);
    joint_free(joint);
    return NULL;
}

RAIA_API const char *raia_gl_draw_elements(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    GLenum mode = joint_get_in_uint(joint, "mode");
    GLsizei count = joint_get_in_int(joint, "count");
    GLenum type = joint_get_in_uint(joint, "type");
    if (joint_is_in_null(joint, "pointer")) {
        glDrawElements(mode, count, type, 0); // indices
    } else {
        const void *indices = (const void *)joint_get_in_uint_to_ptr(joint, "pointer"); // Uint16Array
        glDrawElements(mode, count, type, indices); // indices
    }
    joint_free(joint);
    return NULL;
}

RAIA_API const char *raia_gl_create_shader(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    GLenum type = joint_get_in_uint(joint, "type");
    GLuint shader = glCreateShader(type);
    joint_add_out_uint(joint, "result", shader);
    return joint_out_write(joint);
}

RAIA_API const char *raia_gl_shader_source(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    GLuint shader = joint_get_in_uint(joint, "shader");
    GLsizei count = joint_get_in_int(joint, "count");
    GLchar *string = (char *) joint_get_in_str(joint, "string");
    if (joint_is_in_null(joint, "length")) {
        glShaderSource(shader, count, &string, NULL);
    } else {
        GLint length = joint_get_in_int(joint, "length");
        glShaderSource(shader, count, &string, &length);
    }
    joint_free(joint);
    return NULL;
}

RAIA_API const char *raia_gl_compile_shader(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    GLuint shader = joint_get_in_uint(joint, "shader");
    glCompileShader(shader);
    joint_free(joint);
    return NULL;
}

RAIA_API const char *raia_gl_get_shader_iv(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    GLuint shader = joint_get_in_uint(joint, "shader");
    GLenum pname = joint_get_in_uint(joint, "pname");
    GLint params;
    glGetShaderiv(shader, pname, &params);
    joint_add_out_int(joint, "result", params);
    return joint_out_write(joint);
}

RAIA_API const char *raia_gl_create_program(const char *s) {
    GLuint program = glCreateProgram();
    joint_t *joint = joint_init_out();
    joint_add_out_uint(joint, "result", program);
    return joint_out_write(joint);
}

RAIA_API const char *raia_gl_attach_shader(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    GLuint program = joint_get_in_uint(joint, "program");
    GLuint shader = joint_get_in_uint(joint, "shader");
    glAttachShader(program, shader);
    joint_free(joint);
    return NULL;
}

RAIA_API const char *raia_gl_delete_shader(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    GLuint shader = joint_get_in_uint(joint, "shader");
    glDeleteShader(shader);
    joint_free(joint);
    return NULL;
}

RAIA_API const char *raia_gl_link_program(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    GLuint program = joint_get_in_uint(joint, "program");
    glLinkProgram(program);
    joint_free(joint);
    return NULL;
}

RAIA_API const char *raia_gl_pixel_store_i(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    GLenum pname = joint_get_in_uint(joint, "pname");
    GLint param = joint_get_in_int(joint, "param");
    glPixelStorei(pname, param);
    joint_free(joint);
    return NULL;
}

RAIA_API const char *raia_gl_gen_textures(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    GLsizei n = joint_get_in_int(joint, "n");
    GLuint textures;
    glGenTextures(n, &textures);
    joint_add_out_uint(joint, "result", textures);
    return joint_out_write(joint);
}

RAIA_API const char *raia_gl_tex_parameter_i(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    GLenum target = joint_get_in_uint(joint, "target");
    GLenum pname = joint_get_in_uint(joint, "pname");
    GLint param = joint_get_in_int(joint, "param");
    glTexParameteri(target, pname, param);
    joint_free(joint);
    return NULL;
}

RAIA_API const char *raia_gl_get_attrib_location(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    GLuint program = joint_get_in_uint(joint, "program");
    const char *name = joint_get_in_str(joint, "name");
    GLint location = glGetAttribLocation(program, name);
    joint_add_out_int(joint, "result", location);
    return joint_out_write(joint);
}

RAIA_API const char *raia_gl_get_uniform_location(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    GLuint program = joint_get_in_uint(joint, "program");
    const char *name = joint_get_in_str(joint, "name");
    GLint location = glGetUniformLocation(program, name);
    joint_add_out_int(joint, "result", location);
    return joint_out_write(joint);
}

RAIA_API const char *raia_gl_gen_vertex_arrays(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    GLsizei n = joint_get_in_int(joint, "n");
    GLuint arrays;
    glGenVertexArrays(n, &arrays);
    joint_add_out_uint(joint, "result", arrays);
    return joint_out_write(joint);
}

RAIA_API const char *raia_gl_gen_buffers(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    GLsizei n = joint_get_in_int(joint, "n");
    GLuint buffers;
    glGenBuffers(n, &buffers);
    joint_add_out_uint(joint, "result", buffers);
    return joint_out_write(joint);
}

RAIA_API const char *raia_gl_bind_vertex_array(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    GLuint array = joint_get_in_uint(joint, "array");
    glBindVertexArray(array);
    joint_free(joint);
    return NULL;
}

RAIA_API const char *raia_gl_bind_buffer(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    GLenum target = joint_get_in_uint(joint, "target");
    GLuint buffer = joint_get_in_uint(joint, "buffer");
    glBindBuffer(target, buffer);
    joint_free(joint);
    return NULL;
}

RAIA_API const char *raia_gl_buffer_data(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    GLenum target = joint_get_in_uint(joint, "target");
    GLsizeiptr size = joint_get_in_uint(joint, "size");
    const void *data = (const void *) (uintptr_t) joint_get_in_uint(joint, "data"); // Uint16Array
    GLenum usage = joint_get_in_uint(joint, "usage");
    glBufferData(target, size, data, usage);
    joint_free(joint);
    return NULL;
}

RAIA_API const char *raia_gl_delete_vertex_arrays(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    GLuint arrays = joint_get_in_uint(joint, "arrays");
    glDeleteVertexArrays(1, &arrays);
    joint_free(joint);
    return NULL;
}

RAIA_API const char *raia_gl_delete_buffers(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    GLuint buffers = joint_get_in_uint(joint, "buffers");
    glDeleteBuffers(1, &buffers);
    joint_free(joint);
    return NULL;
}

RAIA_API const char *raia_gl_delete_textures(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    GLuint textures = joint_get_in_uint(joint, "textures");
    glDeleteTextures(1, &textures);
    joint_free(joint);
    return NULL;
}