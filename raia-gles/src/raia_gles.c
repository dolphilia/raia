#include "raia_gles.h"

#ifdef __WINDOWS__
#define RAIA_EXPORT __declspec(dllexport)
#else
#define RAIA_EXPORT
#endif

static const char *raia_not_use_s(const char *s) {
    return s;
}

RAIA_EXPORT const char *raia_gl_viewport(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    int x = joint_get_in_int(joint, "x");
    int y = joint_get_in_int(joint, "y");
    int width = joint_get_in_int(joint, "width");
    int height = joint_get_in_int(joint, "height");
    glViewport(x, y, width, height);
    return joint_out_write(joint);
}

RAIA_EXPORT const char *raia_gl_clear_color(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    double red = joint_get_in_real(joint, "red");
    double green = joint_get_in_real(joint, "green");
    double blue = joint_get_in_real(joint, "blue");
    double alpha = joint_get_in_real(joint, "alpha");
    glClearColor((float) red, (float) green, (float) blue, (float) alpha);
    return joint_out_write(joint);
}

RAIA_EXPORT const char *raia_gl_clear(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    GLbitfield mask = joint_get_in_uint(joint, "mask");
    glClear(mask);
    return joint_out_write(joint);
}

RAIA_EXPORT const char *raia_gl_use_program(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    GLuint program = joint_get_in_uint(joint, "program");
    glUseProgram(program);
    return joint_out_write(joint);
}

RAIA_EXPORT const char *raia_gl_vertex_attrib_pointer(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    GLuint index = joint_get_in_uint(joint, "index");
    GLint size = joint_get_in_int(joint, "size");
    GLenum type = joint_get_in_uint(joint, "type");
    GLboolean normalized = joint_get_in_uint(joint, "normalized");
    GLsizei stride = joint_get_in_int(joint, "stride");
    const void *pointer = (const void *) (uintptr_t) joint_get_in_uint(joint, "pointer"); // Float32Array
    glVertexAttribPointer(index, size, type, normalized, stride, pointer);
    return joint_out_write(joint);
}

RAIA_EXPORT const char *raia_gl_vertex_attrib_pointer_0(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    GLuint index = joint_get_in_uint(joint, "index");
    GLint size = joint_get_in_int(joint, "size");
    GLenum type = joint_get_in_uint(joint, "type");
    GLboolean normalized = joint_get_in_uint(joint, "normalized");
    GLsizei stride = joint_get_in_int(joint, "stride");
    glVertexAttribPointer(index, size, type, normalized, stride, (void *)0);
    return joint_out_write(joint);
}

RAIA_EXPORT const char *raia_gl_vertex_attrib_pointer_20(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    GLuint index = joint_get_in_uint(joint, "index");
    GLint size = joint_get_in_int(joint, "size");
    GLenum type = joint_get_in_uint(joint, "type");
    GLboolean normalized = joint_get_in_uint(joint, "normalized");
    GLsizei stride = joint_get_in_int(joint, "stride");
    glVertexAttribPointer(index, size, type, normalized, stride, (void *)20);
    return joint_out_write(joint);
}

RAIA_EXPORT const char *raia_gl_enable_vertex_attrib_array(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    GLuint index = joint_get_in_uint(joint, "index");
    glEnableVertexAttribArray(index);
    return joint_out_write(joint);
}

RAIA_EXPORT const char *raia_gl_tex_image_2d(const char *s) {
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
    return joint_out_write(joint);
}

RAIA_EXPORT const char *raia_gl_active_texture(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    GLenum texture = joint_get_in_uint(joint, "texture");
    glActiveTexture(texture);
    return joint_out_write(joint);
}

RAIA_EXPORT const char *raia_gl_bind_texture(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    GLenum target = joint_get_in_uint(joint, "target");
    GLuint texture = joint_get_in_uint(joint, "texture");
    glBindTexture(target, texture);
    return joint_out_write(joint);
}

RAIA_EXPORT const char *raia_gl_uniform_1i(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    GLint location = joint_get_in_int(joint, "location");
    GLint v0 = joint_get_in_int(joint, "v0");
    glUniform1i(location, v0);
    return joint_out_write(joint);
}

RAIA_EXPORT const char *raia_gl_draw_elements(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    GLenum mode = joint_get_in_uint(joint, "mode");
    GLsizei count = joint_get_in_int(joint, "count");
    GLenum type = joint_get_in_uint(joint, "type");
    if (yyjson_is_null(yyjson_obj_get(joint->in_root, "pointer"))) {
        glDrawElements(mode, count, type, 0); // indices
    } else {
        const void *indices = (const void *) (uintptr_t) joint_get_in_uint(joint, "pointer"); // Uint16Array
        glDrawElements(mode, count, type, indices); // indices
    }
    return joint_out_write(joint);
}

RAIA_EXPORT const char *raia_gl_create_shader(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    GLenum type = joint_get_in_uint(joint, "type");
    GLuint shader = glCreateShader(type);
    joint_add_out_uint(joint, "result", shader);
    return joint_out_write(joint);
}

RAIA_EXPORT const char *raia_gl_shader_source(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    GLuint shader = joint_get_in_uint(joint, "shader");
    GLsizei count = joint_get_in_int(joint, "count");
    GLchar *string = (char *) joint_get_in_str(joint, "string");
    if (yyjson_is_null(yyjson_obj_get(joint->in_root, "length"))) {
        glShaderSource(shader, count, &string, NULL);
    } else {
        GLint length = joint_get_in_int(joint, "length");
        glShaderSource(shader, count, &string, &length);
    }
    return joint_out_write(joint);
}

RAIA_EXPORT const char *raia_gl_compile_shader(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    GLuint shader = joint_get_in_uint(joint, "shader");
    glCompileShader(shader);
    return joint_out_write(joint);
}

RAIA_EXPORT const char *raia_gl_get_shader_iv(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    GLuint shader = joint_get_in_uint(joint, "shader");
    GLenum pname = joint_get_in_uint(joint, "pname");
    GLint params;
    glGetShaderiv(shader, pname, &params);
    joint_add_out_int(joint, "result", params);
    return joint_out_write(joint);
}

RAIA_EXPORT const char *raia_gl_create_program(const char *s) {
    GLuint program = glCreateProgram();
    joint_t *joint = joint_init_out();
    joint_add_out_uint(joint, "result", program);
    return joint_out_write(joint);
}

RAIA_EXPORT const char *raia_gl_attach_shader(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    GLuint program = joint_get_in_uint(joint, "program");
    GLuint shader = joint_get_in_uint(joint, "shader");
    glAttachShader(program, shader);
    return joint_out_write(joint);
}

RAIA_EXPORT const char *raia_gl_delete_shader(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    GLuint shader = joint_get_in_uint(joint, "shader");
    glDeleteShader(shader);
    return joint_out_write(joint);
}

RAIA_EXPORT const char *raia_gl_link_program(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    GLuint program = joint_get_in_uint(joint, "program");
    glLinkProgram(program);
    return joint_out_write(joint);
}

RAIA_EXPORT const char *raia_gl_pixel_store_i(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    GLenum pname = joint_get_in_uint(joint, "pname");
    GLint param = joint_get_in_int(joint, "param");
    glPixelStorei(pname, param);
    return joint_out_write(joint);
}

RAIA_EXPORT const char *raia_gl_gen_textures(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    GLsizei n = joint_get_in_int(joint, "n");
    GLuint textures;
    glGenTextures(n, &textures);
    joint_add_out_uint(joint, "result", textures);
    return joint_out_write(joint);
}

RAIA_EXPORT const char *raia_gl_tex_parameter_i(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    GLenum target = joint_get_in_uint(joint, "target");
    GLenum pname = joint_get_in_uint(joint, "pname");
    GLint param = joint_get_in_int(joint, "param");
    glTexParameteri(target, pname, param);
    return joint_out_write(joint);
}

RAIA_EXPORT const char *raia_gl_get_attrib_location(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    GLuint program = joint_get_in_uint(joint, "program");
    const char *name = joint_get_in_str(joint, "name");
    GLint location = glGetAttribLocation(program, name);
    joint_add_out_int(joint, "result", location);
    return joint_out_write(joint);
}

RAIA_EXPORT const char *raia_gl_get_uniform_location(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    GLuint program = joint_get_in_uint(joint, "program");
    const char *name = joint_get_in_str(joint, "name");
    GLint location = glGetUniformLocation(program, name);
    joint_add_out_int(joint, "result", location);
    return joint_out_write(joint);
}

RAIA_EXPORT const char *raia_gl_gen_vertex_arrays(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    GLsizei n = joint_get_in_int(joint, "n");
    GLuint arrays;
    glGenVertexArrays(n, &arrays);
    joint_add_out_uint(joint, "result", arrays);
    return joint_out_write(joint);
}

RAIA_EXPORT const char *raia_gl_gen_buffers(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    GLsizei n = joint_get_in_int(joint, "n");
    GLuint buffers;
    glGenBuffers(n, &buffers);
    joint_add_out_uint(joint, "result", buffers);
    return joint_out_write(joint);
}

RAIA_EXPORT const char *raia_gl_bind_vertex_array(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    GLuint array = joint_get_in_uint(joint, "array");
    glBindVertexArray(array);
    return joint_out_write(joint);
}

RAIA_EXPORT const char *raia_gl_bind_buffer(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    GLenum target = joint_get_in_uint(joint, "target");
    GLuint buffer = joint_get_in_uint(joint, "buffer");
    glBindBuffer(target, buffer);
    return joint_out_write(joint);
}

RAIA_EXPORT const char *raia_gl_buffer_data(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    GLenum target = joint_get_in_uint(joint, "target");
    GLsizeiptr size = joint_get_in_uint(joint, "size");
    const void *data = (const void *) (uintptr_t) joint_get_in_uint(joint, "data"); // Uint16Array
    GLenum usage = joint_get_in_uint(joint, "usage");
    glBufferData(target, size, data, usage);
    return joint_out_write(joint);
}
