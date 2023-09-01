//
// Created by dolphilia on 2023/08/08.
//

#ifndef RAIA_GUI_RAIA_GLES_H
#define RAIA_GUI_RAIA_GLES_H

#include <time.h>
#include "yyjson/yyjson.h"
#include "wrapper/wrapper_yyjson.h"
#include "platforms.h"
#include "EGL/egl.h"
#include "GLES3/gl32.h"

#ifdef __WINDOWS__
#include <windows.h>
#define RAIA_EXPORT __declspec(dllexport)
#else
#define RAIA_EXPORT
#endif
#ifdef __WINDOWS__
#define GL_TEXTURE0 0x84C0
#endif

RAIA_EXPORT const char *raia_gl_viewport(const char *s);
RAIA_EXPORT const char *raia_gl_clear_color(const char *s);
RAIA_EXPORT const char *raia_gl_clear(const char *s);
RAIA_EXPORT const char *raia_gl_use_program(const char *s);
RAIA_EXPORT const char *raia_gl_vertex_attrib_pointer(const char *s);
RAIA_EXPORT const char *raia_gl_enable_vertex_attrib_array(const char *s);
RAIA_EXPORT const char *raia_gl_tex_image_2d(const char *s);
RAIA_EXPORT const char *raia_gl_active_texture(const char *s);
RAIA_EXPORT const char *raia_gl_bind_texture(const char *s);
RAIA_EXPORT const char *raia_gl_uniform_1i(const char *s);
RAIA_EXPORT const char *raia_gl_draw_elements(const char *s);
RAIA_EXPORT const char *raia_gl_create_shader(const char *s);
RAIA_EXPORT const char *raia_gl_shader_source(const char *s);
RAIA_EXPORT const char *raia_gl_compile_shader(const char *s);
RAIA_EXPORT const char *raia_gl_get_shader_iv(const char *s);
RAIA_EXPORT const char *raia_gl_create_program(const char *s);
RAIA_EXPORT const char *raia_gl_attach_shader(const char *s);
RAIA_EXPORT const char *raia_gl_delete_shader(const char *s);
RAIA_EXPORT const char *raia_gl_link_program(const char *s);
RAIA_EXPORT const char *raia_gl_pixel_store_i(const char *s);
RAIA_EXPORT const char *raia_gl_gen_textures(const char *s);
RAIA_EXPORT const char *raia_gl_tex_parameter_i(const char *s);
RAIA_EXPORT const char *raia_gl_get_attrib_location(const char *s);
RAIA_EXPORT const char *raia_gl_get_uniform_location(const char *s);
RAIA_EXPORT const char *raia_gl_gen_vertex_arrays(const char *s);
RAIA_EXPORT const char *raia_gl_gen_buffers(const char *s);
RAIA_EXPORT const char *raia_gl_bind_vertex_array(const char *s);
RAIA_EXPORT const char *raia_gl_bind_buffer(const char *s);
RAIA_EXPORT const char *raia_gl_buffer_data(const char *s);

#endif //RAIA_GUI_RAIA_GLES_H
