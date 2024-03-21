#include "raia_gles.h"

//
// GL ES 2.0
//

RAIA_API void raia_gl_active_texture (GLenum texture) {
    glActiveTexture(texture);
}
RAIA_API void raia_gl_attach_shader (GLuint program, GLuint shader) {
    glAttachShader(program, shader);
}
RAIA_API void raia_gl_bind_attrib_location (GLuint program, GLuint index, const GLchar *name) {
    glBindAttribLocation(program, index, name);
}
RAIA_API void raia_gl_bind_buffer (GLenum target, GLuint buffer) {
    glBindBuffer(target, buffer);
}
RAIA_API void raia_gl_bind_framebuffer (GLenum target, GLuint framebuffer) {
    glBindFramebuffer(target, framebuffer);
}
RAIA_API void raia_gl_bind_renderbuffer (GLenum target, GLuint renderbuffer) {
    glBindRenderbuffer(target, renderbuffer);
}
RAIA_API void raia_gl_bind_texture (GLenum target, GLuint texture) {
    glBindTexture(target, texture);
}
RAIA_API void raia_gl_blend_color (GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) {
    glBlendColor(red, green, blue, alpha);
}
RAIA_API void raia_gl_blend_equation (GLenum mode) {
    glBlendEquation(mode);
}
RAIA_API void raia_gl_blend_equation_separate (GLenum modeRGB, GLenum modeAlpha) {
    glBlendEquationSeparate(modeRGB, modeAlpha);
}
RAIA_API void raia_gl_blend_func (GLenum sfactor, GLenum dfactor) {
    glBlendFunc(sfactor, dfactor);
}
RAIA_API void raia_gl_blend_func_separate (GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha) {
    glBlendFuncSeparate(sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha);
}
RAIA_API void raia_gl_buffer_data (GLenum target, GLsizeiptr size, const void *data, GLenum usage) {
    glBufferData(target, size, data, usage);
}
RAIA_API void raia_gl_buffer_sub_data (GLenum target, GLintptr offset, GLsizeiptr size, const void *data) {
    glBufferSubData(target, offset, size, data);
}
RAIA_API GLenum raia_gl_check_framebuffer_status (GLenum target) {
    return glCheckFramebufferStatus(target);
}
RAIA_API void raia_gl_clear (GLbitfield mask) {
    glClear(mask);
}
RAIA_API void raia_gl_clear_color (GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) {
    glClearColor(red, green, blue, alpha);
}
RAIA_API void raia_gl_clear_depth_f (GLfloat d) {
    glClearDepthf(d);
}
RAIA_API void raia_gl_clear_stencil (GLint s) {
    glClearStencil(s);
}
RAIA_API void raia_gl_color_mask (GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha) {
    glColorMask(red, green, blue, alpha);
}
RAIA_API void raia_gl_compile_shader (GLuint shader) {
    glCompileShader(shader);
}
RAIA_API void raia_gl_compressed_tex_image_2d (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void *data) {
    glCompressedTexImage2D(target, level, internalformat, width, height, border, imageSize, data);
}
RAIA_API void raia_gl_compressed_tex_sub_image_2d (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *data) {
    glCompressedTexSubImage2D(target, level, xoffset, yoffset, width, height, format, imageSize, data);
}
RAIA_API void raia_gl_copy_tex_image_2d (GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border) {
    glCopyTexImage2D(target, level, internalformat, x, y, width, height, border);
}
RAIA_API void raia_gl_copy_tex_sub_image_2d (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height) {
    glCopyTexSubImage2D(target, level, xoffset, yoffset, x, y, width, height);
}
RAIA_API GLuint raia_gl_create_program (void) {
    return glCreateProgram();
}
RAIA_API GLuint raia_gl_create_shader (GLenum type) {
    return glCreateShader(type);
}
RAIA_API void raia_gl_cull_face (GLenum mode) {
    glCullFace(mode);
}
RAIA_API void raia_gl_delete_buffers (GLsizei n, const GLuint *buffers) {
    glDeleteBuffers(n, buffers);
}
RAIA_API void raia_gl_delete_framebuffers (GLsizei n, const GLuint *framebuffers) {
    glDeleteFramebuffers(n, framebuffers);
}
RAIA_API void raia_gl_delete_program (GLuint program) {
    glDeleteProgram(program);
}
RAIA_API void raia_gl_delete_renderbuffers (GLsizei n, const GLuint *renderbuffers) {
    glDeleteRenderbuffers(n, renderbuffers);
}
RAIA_API void raia_gl_delete_shader (GLuint shader) {
    glDeleteShader(shader);
}
RAIA_API void raia_gl_delete_textures (GLsizei n, const GLuint *textures) {
    glDeleteTextures(n, textures);
}
RAIA_API void raia_gl_depth_func (GLenum func) {
    glDepthFunc(func);
}
RAIA_API void raia_gl_depth_mask (GLboolean flag) {
    glDepthMask(flag);
}
RAIA_API void raia_gl_depth_range_f (GLfloat n, GLfloat f) {
    glDepthRangef(n, f);
}
RAIA_API void raia_gl_detach_shader (GLuint program, GLuint shader) {
    glDetachShader(program, shader);
}
RAIA_API void raia_gl_disable (GLenum cap) {
    glDisable(cap);
}
RAIA_API void raia_gl_disable_vertex_attrib_array (GLuint index) {
    glDisableVertexAttribArray(index);
}
RAIA_API void raia_gl_draw_arrays (GLenum mode, GLint first, GLsizei count) {
    glDrawArrays(mode, first, count);
}
RAIA_API void raia_gl_draw_elements (GLenum mode, GLsizei count, GLenum type, const void *indices) {
    glDrawElements(mode, count, type, indices);
}
RAIA_API void raia_gl_enable (GLenum cap) {
    glEnable(cap);
}
RAIA_API void raia_gl_enable_vertex_attrib_array (GLuint index) {
    glEnableVertexAttribArray(index);
}
RAIA_API void raia_gl_finish (void) {
    glFinish();
}
RAIA_API void raia_gl_flush (void) {
    glFlush();
}
RAIA_API void raia_gl_framebuffer_renderbuffer (GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer) {
    glFramebufferRenderbuffer(target, attachment, renderbuffertarget, renderbuffer);
}
RAIA_API void raia_gl_framebuffer_texture_2d (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level) {
    glFramebufferTexture2D(target, attachment, textarget, texture, level);
}
RAIA_API void raia_gl_front_face (GLenum mode) {
    glFrontFace(mode);
}
RAIA_API void raia_gl_gen_buffers (GLsizei n, GLuint *buffers) {
    glGenBuffers(n, buffers);
}
RAIA_API void raia_gl_generate_mipmap (GLenum target) {
    glGenerateMipmap(target);
}
RAIA_API void raia_gl_gen_framebuffers (GLsizei n, GLuint *framebuffers) {
    glGenFramebuffers(n, framebuffers);
}
RAIA_API void raia_gl_gen_renderbuffers (GLsizei n, GLuint *renderbuffers) {
    glGenRenderbuffers(n, renderbuffers);
}
RAIA_API void raia_gl_gen_textures (GLsizei n, GLuint *textures) {
    glGenTextures(n, textures);
}
RAIA_API void raia_gl_get_active_attrib (GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name) {
    glGetActiveAttrib(program, index, bufSize, length, size, type, name);
}
RAIA_API void raia_gl_get_active_uniform (GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name) {
    glGetActiveUniform(program, index, bufSize, length, size, type, name);
}
RAIA_API void raia_gl_get_attached_shaders (GLuint program, GLsizei maxCount, GLsizei *count, GLuint *shaders) {
    glGetAttachedShaders(program, maxCount, count, shaders);
}
RAIA_API GLint raia_gl_get_attrib_location (GLuint program, const GLchar *name) {
    return glGetAttribLocation(program, name);
}
RAIA_API void raia_gl_get_boolean_v (GLenum pname, GLboolean *data) {
    glGetBooleanv(pname, data);
}
RAIA_API void raia_gl_get_buffer_parameter_iv (GLenum target, GLenum pname, GLint *params) {
    glGetBufferParameteriv(target, pname, params);
}
RAIA_API GLenum raia_gl_get_error (void) {
    return glGetError();
}
RAIA_API void raia_gl_get_float_v (GLenum pname, GLfloat *data) {
    glGetFloatv(pname, data);
}
RAIA_API void raia_gl_get_framebuffer_attachment_parameter_iv (GLenum target, GLenum attachment, GLenum pname, GLint *params) {
    glGetFramebufferAttachmentParameteriv(target, attachment, pname, params);
}
RAIA_API void raia_gl_get_integer_v (GLenum pname, GLint *data) {
    glGetIntegerv(pname, data);
}
RAIA_API void raia_gl_get_program_iv (GLuint program, GLenum pname, GLint *params) {
    glGetProgramiv(program, pname, params);
}
RAIA_API void raia_gl_get_program_info_log (GLuint program, GLsizei bufSize, GLsizei *length, GLchar *infoLog) {
    glGetProgramInfoLog(program, bufSize, length, infoLog);
}
RAIA_API void raia_gl_get_renderbuffer_parameter_iv (GLenum target, GLenum pname, GLint *params) {
    glGetRenderbufferParameteriv(target, pname, params);
}
RAIA_API void raia_gl_get_shader_iv (GLuint shader, GLenum pname, GLint *params) {
    glGetShaderiv(shader, pname, params);
}
RAIA_API void raia_gl_get_shader_info_log (GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *infoLog) {
    glGetShaderInfoLog(shader, bufSize, length, infoLog);
}
RAIA_API void raia_gl_get_shader_precision_format (GLenum shadertype, GLenum precisiontype, GLint *range, GLint *precision) {
    glGetShaderPrecisionFormat(shadertype, precisiontype, range, precision);
}
RAIA_API void raia_gl_get_shader_source (GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *source) {
    glGetShaderSource(shader, bufSize, length, source);
}
RAIA_API const GLubyte *raia_gl_get_string (GLenum name) {
    return glGetString(name);
}
RAIA_API void raia_gl_get_tex_parameter_fv (GLenum target, GLenum pname, GLfloat *params) {
    glGetTexParameterfv(target, pname, params);
}
RAIA_API void raia_gl_get_tex_parameter_iv (GLenum target, GLenum pname, GLint *params) {
    glGetTexParameteriv(target, pname, params);
}
RAIA_API void raia_gl_get_uniform_fv (GLuint program, GLint location, GLfloat *params) {
    glGetUniformfv(program, location, params);
}
RAIA_API void raia_gl_get_uniform_iv (GLuint program, GLint location, GLint *params) {
    glGetUniformiv(program, location, params);
}
RAIA_API GLint raia_gl_get_uniform_location (GLuint program, const GLchar *name) {
    return glGetUniformLocation(program, name);
}
RAIA_API void raia_gl_get_vertex_attrib_fv (GLuint index, GLenum pname, GLfloat *params) {
    glGetVertexAttribfv(index, pname, params);
}
RAIA_API void raia_gl_get_vertex_attrib_iv (GLuint index, GLenum pname, GLint *params) {
    glGetVertexAttribiv(index, pname, params);
}
RAIA_API void raia_gl_get_vertex_attrib_pointer_v (GLuint index, GLenum pname, void **pointer) {
    glGetVertexAttribPointerv(index, pname, pointer);
}
RAIA_API void raia_gl_hint (GLenum target, GLenum mode) {
    glHint(target, mode);
}
RAIA_API GLboolean raia_gl_is_buffer (GLuint buffer) {
    return glIsBuffer(buffer);
}
RAIA_API GLboolean raia_gl_is_enabled (GLenum cap) {
    return glIsEnabled(cap);
}
RAIA_API GLboolean raia_gl_is_framebuffer (GLuint framebuffer) {
    return glIsFramebuffer(framebuffer);
}
RAIA_API GLboolean raia_gl_is_program (GLuint program) {
    return glIsProgram(program);
}
RAIA_API GLboolean raia_gl_is_renderbuffer (GLuint renderbuffer) {
    return glIsRenderbuffer(renderbuffer);
}
RAIA_API GLboolean raia_gl_is_shader (GLuint shader) {
    return glIsShader(shader);
}
RAIA_API GLboolean raia_gl_is_texture (GLuint texture) {
    return glIsTexture(texture);
}
RAIA_API void raia_gl_line_width (GLfloat width) {
    glLineWidth(width);
}
RAIA_API void raia_gl_link_program (GLuint program) {
    glLinkProgram(program);
}
RAIA_API void raia_gl_pixel_store_i (GLenum pname, GLint param) {
    glPixelStorei(pname, param);
}
RAIA_API void raia_gl_polygon_offset (GLfloat factor, GLfloat units) {
    glPolygonOffset(factor, units);
}
RAIA_API void raia_gl_read_pixels (GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void *pixels) {
    glReadPixels(x, y, width, height, format, type, pixels);
}
RAIA_API void raia_gl_release_shader_compiler (void) {
    glReleaseShaderCompiler();
}
RAIA_API void raia_gl_renderbuffer_storage (GLenum target, GLenum internalformat, GLsizei width, GLsizei height) {
    glRenderbufferStorage(target, internalformat, width, height);
}
RAIA_API void raia_gl_sample_coverage (GLfloat value, GLboolean invert) {
    glSampleCoverage(value, invert);
}
RAIA_API void raia_gl_scissor (GLint x, GLint y, GLsizei width, GLsizei height) {
    glScissor(x, y, width, height);
}
RAIA_API void raia_gl_shader_binary (GLsizei count, const GLuint *shaders, GLenum binaryformat, const void *binary, GLsizei length) {
    glShaderBinary(count, shaders, binaryformat, binary, length);
}
RAIA_API void raia_gl_shader_source (GLuint shader, GLsizei count, const GLchar *const*string, const GLint *length) {
    glShaderSource(shader, count, string, length);
}
RAIA_API void raia_gl_stencil_func (GLenum func, GLint ref, GLuint mask) {
    glStencilFunc(func, ref, mask);
}
RAIA_API void raia_gl_stencil_func_separate (GLenum face, GLenum func, GLint ref, GLuint mask) {
    glStencilFuncSeparate(face, func, ref, mask);
}
RAIA_API void raia_gl_stencil_mask (GLuint mask) {
    glStencilMask(mask);
}
RAIA_API void raia_gl_stencil_mask_separate (GLenum face, GLuint mask) {
    glStencilMaskSeparate(face, mask);
}
RAIA_API void raia_gl_stencil_op (GLenum fail, GLenum zfail, GLenum zpass) {
    glStencilOp(fail, zfail, zpass);
}
RAIA_API void raia_gl_stencil_op_separate (GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass) {
    glStencilOpSeparate(face, sfail, dpfail, dppass);
}
RAIA_API void raia_gl_tex_image_2d (GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void *pixels) {
    glTexImage2D(target, level, internalformat, width, height, border, format, type, pixels);
}
RAIA_API void raia_gl_tex_parameter_f (GLenum target, GLenum pname, GLfloat param) {
    glTexParameterf(target, pname, param);
}
RAIA_API void raia_gl_tex_parameter_fv (GLenum target, GLenum pname, const GLfloat *params) {
    glTexParameterfv(target, pname, params);
}
RAIA_API void raia_gl_tex_parameter_i (GLenum target, GLenum pname, GLint param) {
    glTexParameteri(target, pname, param);
}
RAIA_API void raia_gl_tex_parameter_iv (GLenum target, GLenum pname, const GLint *params) {
    glTexParameteriv(target, pname, params);
}
RAIA_API void raia_gl_tex_sub_image_2d (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels) {
    glTexSubImage2D(target, level, xoffset, yoffset, width, height, format, type, pixels);
}
RAIA_API void raia_gl_uniform_1f (GLint location, GLfloat v0) {
    glUniform1f(location, v0);
}
RAIA_API void raia_gl_uniform_1fv (GLint location, GLsizei count, const GLfloat *value) {
    glUniform1fv(location, count, value);
}
RAIA_API void raia_gl_uniform_1i (GLint location, GLint v0) {
    glUniform1i(location, v0);
}
RAIA_API void raia_gl_uniform_1iv (GLint location, GLsizei count, const GLint *value) {
    glUniform1iv(location, count, value);
}
RAIA_API void raia_gl_uniform_2f (GLint location, GLfloat v0, GLfloat v1) {
    glUniform2f(location, v0, v1);
}
RAIA_API void raia_gl_uniform_2fv (GLint location, GLsizei count, const GLfloat *value) {
    glUniform2fv(location, count, value);
}
RAIA_API void raia_gl_uniform_2i (GLint location, GLint v0, GLint v1) {
    glUniform2i(location, v0, v1);
}
RAIA_API void raia_gl_uniform_2iv (GLint location, GLsizei count, const GLint *value) {
    glUniform2iv(location, count, value);
}
RAIA_API void raia_gl_uniform_3f (GLint location, GLfloat v0, GLfloat v1, GLfloat v2) {
    glUniform3f(location, v0, v1, v2);
}
RAIA_API void raia_gl_uniform_3fv (GLint location, GLsizei count, const GLfloat *value) {
    glUniform3fv(location, count, value);
}
RAIA_API void raia_gl_uniform_3i (GLint location, GLint v0, GLint v1, GLint v2) {
    glUniform3i(location, v0, v1, v2);
}
RAIA_API void raia_gl_uniform_3iv (GLint location, GLsizei count, const GLint *value) {
    glUniform3iv(location, count, value);
}
RAIA_API void raia_gl_uniform_4f (GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) {
    glUniform4f(location, v0, v1, v2, v3);
}
RAIA_API void raia_gl_uniform_4fv (GLint location, GLsizei count, const GLfloat *value) {
    glUniform4fv(location, count, value);
}
RAIA_API void raia_gl_uniform_4i (GLint location, GLint v0, GLint v1, GLint v2, GLint v3) {
    glUniform4i(location, v0, v1, v2, v3);
}
RAIA_API void raia_gl_uniform_4iv (GLint location, GLsizei count, const GLint *value) {
    glUniform4iv(location, count, value);
}
RAIA_API void raia_gl_uniform_matrix_2fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) {
    glUniformMatrix2fv(location, count, transpose, value);
}
RAIA_API void raia_gl_uniform_matrix_3fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) {
    glUniformMatrix3fv(location, count, transpose, value);
}
RAIA_API void raia_gl_uniform_matrix_4fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) {
    glUniformMatrix4fv(location, count, transpose, value);
}
RAIA_API void raia_gl_use_program (GLuint program) {
    glUseProgram(program);
}
RAIA_API void raia_gl_validate_program (GLuint program) {
    glValidateProgram(program);
}
RAIA_API void raia_gl_vertex_attrib_1f (GLuint index, GLfloat x) {
    glVertexAttrib1f(index, x);
}
RAIA_API void raia_gl_vertex_attrib_1fv (GLuint index, const GLfloat *v) {
    glVertexAttrib1fv(index, v);
}
RAIA_API void raia_gl_vertex_attrib_2f (GLuint index, GLfloat x, GLfloat y) {
    glVertexAttrib2f(index, x, y);
}
RAIA_API void raia_gl_vertex_attrib_2fv (GLuint index, const GLfloat *v) {
    glVertexAttrib2fv(index, v);
}
RAIA_API void raia_gl_vertex_attrib_3f (GLuint index, GLfloat x, GLfloat y, GLfloat z) {
    glVertexAttrib3f(index, x, y, z);
}
RAIA_API void raia_gl_vertex_attrib_3fv (GLuint index, const GLfloat *v) {
    glVertexAttrib3fv(index, v);
}
RAIA_API void raia_gl_vertex_attrib_4f (GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w) {
    glVertexAttrib4f(index, x, y, z, w);
}
RAIA_API void raia_gl_vertex_attrib_4fv (GLuint index, const GLfloat *v) {
    glVertexAttrib4fv(index, v);
}
RAIA_API void raia_gl_vertex_attrib_pointer (GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *pointer) {
    glVertexAttribPointer(index, size, type, normalized, stride, pointer);
}
RAIA_API void raia_gl_viewport (GLint x, GLint y, GLsizei width, GLsizei height) {
    glViewport(x, y, width, height);
}

//
// GL ES 3.0
//

RAIA_API void raia_gl_read_buffer (GLenum src) {
    glReadBuffer(src);
}
RAIA_API void raia_gl_draw_range_elements (GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices) {
    glDrawRangeElements(mode, start, end, count, type, indices);
}
RAIA_API void raia_gl_tex_image_3d (GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void *pixels) {
    glTexImage3D(target, level, internalformat, width, height, depth, border, format, type, pixels);
}
RAIA_API void raia_gl_tex_sub_image_3d (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels) {
    glTexSubImage3D(target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels);
}
RAIA_API void raia_gl_copy_tex_sub_image_3d (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height) {
    glCopyTexSubImage3D(target, level, xoffset, yoffset, zoffset, x, y, width, height);
}
RAIA_API void raia_gl_compressed_tex_image_3d (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void *data) {
    glCompressedTexImage3D(target, level, internalformat, width, height, depth, border, imageSize, data);
}
RAIA_API void raia_gl_compressed_tex_sub_image_3d (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *data) {
    glCompressedTexSubImage3D(target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data);
}
RAIA_API void raia_gl_gen_queries (GLsizei n, GLuint *ids) {
    glGenQueries(n, ids);
}
RAIA_API void raia_gl_delete_queries (GLsizei n, const GLuint *ids) {
    glDeleteQueries(n, ids);
}
RAIA_API GLboolean raia_gl_is_query (GLuint id) {
    return glIsQuery(id);
}
RAIA_API void raia_gl_begin_query (GLenum target, GLuint id) {
    glBeginQuery(target, id);
}
RAIA_API void raia_gl_end_query (GLenum target) {
    glEndQuery(target);
}
RAIA_API void raia_gl_get_query_iv (GLenum target, GLenum pname, GLint *params) {
    glGetQueryiv(target, pname, params);
}
RAIA_API void raia_gl_get_query_object_uiv (GLuint id, GLenum pname, GLuint *params) {
    glGetQueryObjectuiv(id, pname, params);
}
RAIA_API GLboolean raia_gl_unmap_buffer (GLenum target) {
    return glUnmapBuffer(target);
}
RAIA_API void raia_gl_get_buffer_pointer_v (GLenum target, GLenum pname, void **params) {
    glGetBufferPointerv(target, pname, params);
}
RAIA_API void raia_gl_draw_buffers (GLsizei n, const GLenum *bufs) {
    glDrawBuffers(n, bufs);
}
RAIA_API void raia_gl_uniform_matrix_2x3fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) {
    glUniformMatrix2x3fv(location, count, transpose, value);
}
RAIA_API void raia_gl_uniform_matrix_3x2fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) {
    glUniformMatrix3x2fv(location, count, transpose, value);
}
RAIA_API void raia_gl_uniform_matrix_2x4fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) {
    glUniformMatrix2x4fv(location, count, transpose, value);
}
RAIA_API void raia_gl_uniform_matrix_4x2fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) {
    glUniformMatrix4x2fv(location, count, transpose, value);
}
RAIA_API void raia_gl_uniform_matrix_3x4fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) {
    glUniformMatrix3x4fv(location, count, transpose, value);
}
RAIA_API void raia_gl_uniform_matrix_4x3fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) {
    glUniformMatrix4x3fv(location, count, transpose, value);
}
RAIA_API void raia_gl_blit_framebuffer (GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter) {
    glBlitFramebuffer(srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter);
}
RAIA_API void raia_gl_renderbuffer_storage_multisample (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height) {
    glRenderbufferStorageMultisample(target, samples, internalformat, width, height);
}
RAIA_API void raia_gl_framebuffer_texture_layer (GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer) {
    glFramebufferTextureLayer(target, attachment, texture, level, layer);
}
RAIA_API void *raia_gl_map_buffer_range (GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access) {
    return glMapBufferRange(target, offset, length, access);
}
RAIA_API void raia_gl_flush_mapped_buffer_range (GLenum target, GLintptr offset, GLsizeiptr length) {
    glFlushMappedBufferRange(target, offset, length);
}
RAIA_API void raia_gl_bind_vertex_array (GLuint array) {
    glBindVertexArray(array);
}
RAIA_API void raia_gl_delete_vertex_arrays (GLsizei n, const GLuint *arrays) {
    glDeleteVertexArrays(n, arrays);
}
RAIA_API void raia_gl_gen_vertex_arrays (GLsizei n, GLuint *arrays) {
    glGenVertexArrays(n, arrays);
}
RAIA_API GLboolean raia_gl_is_vertex_array (GLuint array) {
    return glIsVertexArray(array);
}
RAIA_API void raia_gl_get_integer_i_v (GLenum target, GLuint index, GLint *data) {
    glGetIntegeri_v(target, index, data);
}
RAIA_API void raia_gl_begin_transform_feedback (GLenum primitiveMode) {
    glBeginTransformFeedback(primitiveMode);
}
RAIA_API void raia_gl_end_transform_feedback (void) {
    glEndTransformFeedback();
}
RAIA_API void raia_gl_bind_buffer_range (GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size) {
    glBindBufferRange(target, index, buffer, offset, size);
}
RAIA_API void raia_gl_bind_buffer_base (GLenum target, GLuint index, GLuint buffer) {
    glBindBufferBase(target, index, buffer);
}
RAIA_API void raia_gl_transform_feedback_varyings (GLuint program, GLsizei count, const GLchar *const*varyings, GLenum bufferMode) {
    glTransformFeedbackVaryings(program, count, varyings, bufferMode);
}
RAIA_API void raia_gl_get_transform_feedback_varying (GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLsizei *size, GLenum *type, GLchar *name) {
    glGetTransformFeedbackVarying(program, index, bufSize, length, size, type, name);
}
RAIA_API void raia_gl_vertex_attrib_i_pointer (GLuint index, GLint size, GLenum type, GLsizei stride, const void *pointer) {
    glVertexAttribIPointer(index, size, type, stride, pointer);
}
RAIA_API void raia_gl_get_vertex_attrib_iiv (GLuint index, GLenum pname, GLint *params) {
    glGetVertexAttribIiv(index, pname, params);
}
RAIA_API void raia_gl_get_vertex_attrib_iuiv (GLuint index, GLenum pname, GLuint *params) {
    glGetVertexAttribIuiv(index, pname, params);
}
RAIA_API void raia_gl_vertex_attrib_i4i (GLuint index, GLint x, GLint y, GLint z, GLint w) {
    glVertexAttribI4i(index, x, y, z, w);
}
RAIA_API void raia_gl_vertex_attrib_i4ui (GLuint index, GLuint x, GLuint y, GLuint z, GLuint w) {
    glVertexAttribI4ui(index, x, y, z, w);
}
RAIA_API void raia_gl_vertex_attrib_i4iv (GLuint index, const GLint *v) {
    glVertexAttribI4iv(index, v);
}
RAIA_API void raia_gl_vertex_attrib_i4uiv (GLuint index, const GLuint *v) {
    glVertexAttribI4uiv(index, v);
}
RAIA_API void raia_gl_get_uniform_uiv (GLuint program, GLint location, GLuint *params) {
    glGetUniformuiv(program, location, params);
}
RAIA_API GLint raia_gl_get_frag_data_location (GLuint program, const GLchar *name) {
    return glGetFragDataLocation(program, name);
}
RAIA_API void raia_gl_uniform_1ui (GLint location, GLuint v0) {
    glUniform1ui(location, v0);
}
RAIA_API void raia_gl_uniform_2ui (GLint location, GLuint v0, GLuint v1) {
    glUniform2ui(location, v0, v1);
}
RAIA_API void raia_gl_uniform_3ui (GLint location, GLuint v0, GLuint v1, GLuint v2) {
    glUniform3ui(location, v0, v1, v2);
}
RAIA_API void raia_gl_uniform_4ui (GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3) {
    glUniform4ui(location, v0, v1, v2, v3);
}
RAIA_API void raia_gl_uniform_1uiv (GLint location, GLsizei count, const GLuint *value) {
    glUniform1uiv(location, count, value);
}
RAIA_API void raia_gl_uniform_2uiv (GLint location, GLsizei count, const GLuint *value) {
    glUniform2uiv(location, count, value);
}
RAIA_API void raia_gl_uniform_3uiv (GLint location, GLsizei count, const GLuint *value) {
    glUniform3uiv(location, count, value);
}
RAIA_API void raia_gl_uniform_4uiv (GLint location, GLsizei count, const GLuint *value) {
    glUniform4uiv(location, count, value);
}
RAIA_API void raia_gl_clear_buffer_iv (GLenum buffer, GLint drawbuffer, const GLint *value) {
    glClearBufferiv(buffer, drawbuffer, value);
}
RAIA_API void raia_gl_clear_buffer_uiv (GLenum buffer, GLint drawbuffer, const GLuint *value) {
    glClearBufferuiv(buffer, drawbuffer, value);
}
RAIA_API void raia_gl_clear_buffer_fv (GLenum buffer, GLint drawbuffer, const GLfloat *value) {
    glClearBufferfv(buffer, drawbuffer, value);
}
RAIA_API void raia_gl_clear_buffer_fi (GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil) {
    glClearBufferfi(buffer, drawbuffer, depth, stencil);
}
RAIA_API const GLubyte *raia_gl_get_string_i (GLenum name, GLuint index) {
    return glGetStringi(name, index);
}
RAIA_API void raia_gl_copy_buffer_sub_data (GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size) {
    glCopyBufferSubData(readTarget, writeTarget, readOffset, writeOffset, size);
}
RAIA_API void raia_gl_get_uniform_indices (GLuint program, GLsizei uniformCount, const GLchar *const*uniformNames, GLuint *uniformIndices) {
    glGetUniformIndices(program, uniformCount, uniformNames, uniformIndices);
}
RAIA_API void raia_gl_get_active_uniforms_iv (GLuint program, GLsizei uniformCount, const GLuint *uniformIndices, GLenum pname, GLint *params) {
    glGetActiveUniformsiv(program, uniformCount, uniformIndices, pname, params);
}
RAIA_API GLuint raia_gl_get_uniform_block_index (GLuint program, const GLchar *uniformBlockName) {
    return glGetUniformBlockIndex(program, uniformBlockName);
}
RAIA_API void raia_gl_get_active_uniform_block_iv (GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint *params) {
    glGetActiveUniformBlockiv(program, uniformBlockIndex, pname, params);
}
RAIA_API void raia_gl_get_active_uniform_block_name (GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformBlockName) {
    glGetActiveUniformBlockName(program, uniformBlockIndex, bufSize, length, uniformBlockName);
}
RAIA_API void raia_gl_uniform_block_binding (GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding) {
    glUniformBlockBinding(program, uniformBlockIndex, uniformBlockBinding);
}
RAIA_API void raia_gl_draw_arrays_instanced (GLenum mode, GLint first, GLsizei count, GLsizei instancecount) {
    glDrawArraysInstanced(mode, first, count, instancecount);
}
RAIA_API void raia_gl_draw_elements_instanced (GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount) {
    glDrawElementsInstanced(mode, count, type, indices, instancecount);
}
RAIA_API GLsync raia_gl_fence_sync (GLenum condition, GLbitfield flags) {
    return glFenceSync(condition, flags);
}
RAIA_API GLboolean raia_gl_is_sync (GLsync sync) {
    return glIsSync(sync);
}
RAIA_API void raia_gl_delete_sync (GLsync sync) {
    glDeleteSync(sync);
}
RAIA_API GLenum raia_gl_client_wait_sync (GLsync sync, GLbitfield flags, GLuint64 timeout) {
    return glClientWaitSync(sync, flags, timeout);
}
RAIA_API void raia_gl_wait_sync (GLsync sync, GLbitfield flags, GLuint64 timeout) {
    glWaitSync(sync, flags, timeout);
}
RAIA_API void raia_gl_get_integer_64v (GLenum pname, GLint64 *data) {
    glGetInteger64v(pname, data);
}
RAIA_API void raia_gl_get_sync_iv (GLsync sync, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *values) {
    glGetSynciv(sync, pname, bufSize, length, values);
}
RAIA_API void raia_gl_get_integer_64i_v (GLenum target, GLuint index, GLint64 *data) {
    glGetInteger64i_v(target, index, data);
}
RAIA_API void raia_gl_get_buffer_parameter_i64v (GLenum target, GLenum pname, GLint64 *params) {
    glGetBufferParameteri64v(target, pname, params);
}
RAIA_API void raia_gl_gen_samplers (GLsizei count, GLuint *samplers) {
    glGenSamplers(count, samplers);
}
RAIA_API void raia_gl_delete_samplers (GLsizei count, const GLuint *samplers) {
    glDeleteSamplers(count, samplers);
}
RAIA_API GLboolean raia_gl_is_sampler (GLuint sampler) {
    return glIsSampler(sampler);
}
RAIA_API void raia_gl_bind_sampler (GLuint unit, GLuint sampler) {
    glBindSampler(unit, sampler);
}
RAIA_API void raia_gl_sampler_parameter_i (GLuint sampler, GLenum pname, GLint param) {
    glSamplerParameteri(sampler, pname, param);
}
RAIA_API void raia_gl_sampler_parameter_iv (GLuint sampler, GLenum pname, const GLint *param) {
    glSamplerParameteriv(sampler, pname, param);
}
RAIA_API void raia_gl_sampler_parameter_f (GLuint sampler, GLenum pname, GLfloat param) {
    glSamplerParameterf(sampler, pname, param);
}
RAIA_API void raia_gl_sampler_parameter_fv (GLuint sampler, GLenum pname, const GLfloat *param) {
    glSamplerParameterfv(sampler, pname, param);
}
RAIA_API void raia_gl_get_sampler_parameter_iv (GLuint sampler, GLenum pname, GLint *params) {
    glGetSamplerParameteriv(sampler, pname, params);
}
RAIA_API void raia_gl_get_sampler_parameter_fv (GLuint sampler, GLenum pname, GLfloat *params) {
    glGetSamplerParameterfv(sampler, pname, params);
}
RAIA_API void raia_gl_vertex_attrib_divisor (GLuint index, GLuint divisor) {
    glVertexAttribDivisor(index, divisor);
}
RAIA_API void raia_gl_bind_transform_feedback (GLenum target, GLuint id) {
    glBindTransformFeedback(target, id);
}
RAIA_API void raia_gl_delete_transform_feedbacks (GLsizei n, const GLuint *ids) {
    glDeleteTransformFeedbacks(n, ids);
}
RAIA_API void raia_gl_gen_transform_feedbacks (GLsizei n, GLuint *ids) {
    glGenTransformFeedbacks(n, ids);
}
RAIA_API GLboolean raia_gl_is_transform_feedback (GLuint id) {
    return glIsTransformFeedback(id);
}
RAIA_API void raia_gl_pause_transform_feedback (void) {
    glPauseTransformFeedback();
}
RAIA_API void raia_gl_resume_transform_feedback (void) {
    glResumeTransformFeedback();
}
RAIA_API void raia_gl_get_program_binary (GLuint program, GLsizei bufSize, GLsizei *length, GLenum *binaryFormat, void *binary) {
    glGetProgramBinary(program, bufSize, length, binaryFormat, binary);
}
RAIA_API void raia_gl_program_binary (GLuint program, GLenum binaryFormat, const void *binary, GLsizei length) {
    glProgramBinary(program, binaryFormat, binary, length);
}
RAIA_API void raia_gl_program_parameter_i (GLuint program, GLenum pname, GLint value) {
    glProgramParameteri(program, pname, value);
}
RAIA_API void raia_gl_invalidate_framebuffer (GLenum target, GLsizei numAttachments, const GLenum *attachments) {
    glInvalidateFramebuffer(target, numAttachments, attachments);
}
RAIA_API void raia_gl_invalidate_sub_framebuffer (GLenum target, GLsizei numAttachments, const GLenum *attachments, GLint x, GLint y, GLsizei width, GLsizei height) {
    glInvalidateSubFramebuffer(target, numAttachments, attachments, x, y, width, height);
}
RAIA_API void raia_gl_tex_storage_2d (GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height) {
    glTexStorage2D(target, levels, internalformat, width, height);
}
RAIA_API void raia_gl_tex_storage_3d (GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth) {
    glTexStorage3D(target, levels, internalformat, width, height, depth);
}
RAIA_API void raia_gl_get_internal_format_iv (GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint *params) {
    glGetInternalformativ(target, internalformat, pname, bufSize, params);
}

//
// GL ES 3.1
//

RAIA_API void raia_gl_dispatch_compute (GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z) {
    glDispatchCompute(num_groups_x, num_groups_y, num_groups_z);
}
RAIA_API void raia_gl_dispatch_compute_indirect (GLintptr indirect) {
    glDispatchComputeIndirect(indirect);
}
RAIA_API void raia_gl_draw_arrays_indirect (GLenum mode, const void *indirect) {
    glDrawArraysIndirect(mode, indirect);
}
RAIA_API void raia_gl_draw_elements_indirect (GLenum mode, GLenum type, const void *indirect) {
    glDrawElementsIndirect(mode, type, indirect);
}
RAIA_API void raia_gl_framebuffer_parameter_i (GLenum target, GLenum pname, GLint param) {
    glFramebufferParameteri(target, pname, param);
}
RAIA_API void raia_gl_get_framebuffer_parameter_iv (GLenum target, GLenum pname, GLint *params) {
    glGetFramebufferParameteriv(target, pname, params);
}
RAIA_API void raia_gl_get_program_interface_iv (GLuint program, GLenum programInterface, GLenum pname, GLint *params) {
    glGetProgramInterfaceiv(program, programInterface, pname, params);
}
RAIA_API GLuint raia_gl_get_program_resource_index (GLuint program, GLenum programInterface, const GLchar *name) {
    return glGetProgramResourceIndex(program, programInterface, name);
}
RAIA_API void raia_gl_get_program_resource_name (GLuint program, GLenum programInterface, GLuint index, GLsizei bufSize, GLsizei *length, GLchar *name) {
    glGetProgramResourceName(program, programInterface, index, bufSize, length, name);
}
RAIA_API void raia_gl_get_program_resource_iv (GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, const GLenum *props, GLsizei bufSize, GLsizei *length, GLint *params) {
    glGetProgramResourceiv(program, programInterface, index, propCount, props, bufSize, length, params);
}
RAIA_API GLint raia_gl_get_program_resource_location (GLuint program, GLenum programInterface, const GLchar *name) {
    return glGetProgramResourceLocation(program, programInterface, name);
}
RAIA_API void raia_gl_use_program_stages (GLuint pipeline, GLbitfield stages, GLuint program) {
    glUseProgramStages(pipeline, stages, program);
}
RAIA_API void raia_gl_active_shader_program (GLuint pipeline, GLuint program) {
    glActiveShaderProgram(pipeline, program);
}
RAIA_API GLuint raia_gl_create_shader_program_v (GLenum type, GLsizei count, const GLchar *const*strings) {
    return glCreateShaderProgramv(type, count, strings);
}
RAIA_API void raia_gl_bind_program_pipeline (GLuint pipeline) {
    glBindProgramPipeline(pipeline);
}
RAIA_API void raia_gl_delete_program_pipelines (GLsizei n, const GLuint *pipelines) {
    glDeleteProgramPipelines(n, pipelines);
}
RAIA_API void raia_gl_gen_program_pipelines (GLsizei n, GLuint *pipelines) {
    glGenProgramPipelines(n, pipelines);
}
RAIA_API GLboolean raia_gl_is_program_pipeline (GLuint pipeline) {
    return glIsProgramPipeline(pipeline);
}
RAIA_API void raia_gl_get_program_pipeline_iv (GLuint pipeline, GLenum pname, GLint *params) {
    glGetProgramPipelineiv(pipeline, pname, params);
}
RAIA_API void raia_gl_program_uniform_1i (GLuint program, GLint location, GLint v0) {
    glProgramUniform1i(program, location, v0);
}
RAIA_API void raia_gl_program_uniform_2i (GLuint program, GLint location, GLint v0, GLint v1) {
    glProgramUniform2i(program, location, v0, v1);
}
RAIA_API void raia_gl_program_uniform_3i (GLuint program, GLint location, GLint v0, GLint v1, GLint v2) {
    glProgramUniform3i(program, location, v0, v1, v2);
}
RAIA_API void raia_gl_program_uniform_4i (GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3) {
    glProgramUniform4i(program, location, v0, v1, v2, v3);
}
RAIA_API void raia_gl_program_uniform_1ui (GLuint program, GLint location, GLuint v0) {
    glProgramUniform1ui(program, location, v0);
}
RAIA_API void raia_gl_program_uniform_2ui (GLuint program, GLint location, GLuint v0, GLuint v1) {
    glProgramUniform2ui(program, location, v0, v1);
}
RAIA_API void raia_gl_program_uniform_3ui (GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2) {
    glProgramUniform3ui(program, location, v0, v1, v2);
}
RAIA_API void raia_gl_program_uniform_4ui (GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3) {
    glProgramUniform4ui(program, location, v0, v1, v2, v3);
}
RAIA_API void raia_gl_program_uniform_1f (GLuint program, GLint location, GLfloat v0) {
    glProgramUniform1f(program, location, v0);
}
RAIA_API void raia_gl_program_uniform_2f (GLuint program, GLint location, GLfloat v0, GLfloat v1) {
    glProgramUniform2f(program, location, v0, v1);
}
RAIA_API void raia_gl_program_uniform_3f (GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2) {
    glProgramUniform3f(program, location, v0, v1, v2);
}
RAIA_API void raia_gl_program_uniform_4f (GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) {
    glProgramUniform4f(program, location, v0, v1, v2, v3);
}
RAIA_API void raia_gl_program_uniform_1iv (GLuint program, GLint location, GLsizei count, const GLint *value) {
    glProgramUniform1iv(program, location, count, value);
}
RAIA_API void raia_gl_program_uniform_2iv (GLuint program, GLint location, GLsizei count, const GLint *value) {
    glProgramUniform2iv(program, location, count, value);
}
RAIA_API void raia_gl_program_uniform_3iv (GLuint program, GLint location, GLsizei count, const GLint *value) {
    glProgramUniform3iv(program, location, count, value);
}
RAIA_API void raia_gl_program_uniform_4iv (GLuint program, GLint location, GLsizei count, const GLint *value) {
    glProgramUniform4iv(program, location, count, value);
}
RAIA_API void raia_gl_program_uniform_1uiv (GLuint program, GLint location, GLsizei count, const GLuint *value) {
    glProgramUniform1uiv(program, location, count, value);
}
RAIA_API void raia_gl_program_uniform_2uiv (GLuint program, GLint location, GLsizei count, const GLuint *value) {
    glProgramUniform2uiv(program, location, count, value);
}
RAIA_API void raia_gl_program_uniform_3uiv (GLuint program, GLint location, GLsizei count, const GLuint *value) {
    glProgramUniform3uiv(program, location, count, value);
}
RAIA_API void raia_gl_program_uniform_4uiv (GLuint program, GLint location, GLsizei count, const GLuint *value) {
    glProgramUniform4uiv(program, location, count, value);
}
RAIA_API void raia_gl_program_uniform_1fv (GLuint program, GLint location, GLsizei count, const GLfloat *value) {
    glProgramUniform1fv(program, location, count, value);
}
RAIA_API void raia_gl_program_uniform_2fv (GLuint program, GLint location, GLsizei count, const GLfloat *value) {
    glProgramUniform2fv(program, location, count, value);
}
RAIA_API void raia_gl_program_uniform_3fv (GLuint program, GLint location, GLsizei count, const GLfloat *value) {
    glProgramUniform3fv(program, location, count, value);
}
RAIA_API void raia_gl_program_uniform_4fv (GLuint program, GLint location, GLsizei count, const GLfloat *value) {
    glProgramUniform4fv(program, location, count, value);
}
RAIA_API void raia_gl_program_uniform_matrix_2fv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) {
    glProgramUniformMatrix2fv(program, location, count, transpose, value);
}
RAIA_API void raia_gl_program_uniform_matrix_3fv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) {
    glProgramUniformMatrix3fv(program, location, count, transpose, value);
}
RAIA_API void raia_gl_program_uniform_matrix_4fv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) {
    glProgramUniformMatrix4fv(program, location, count, transpose, value);
}
RAIA_API void raia_gl_program_uniform_matrix_2x3fv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) {
    glProgramUniformMatrix2x3fv(program, location, count, transpose, value);
}
RAIA_API void raia_gl_program_uniform_matrix_3x2fv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) {
    glProgramUniformMatrix3x2fv(program, location, count, transpose, value);
}
RAIA_API void raia_gl_program_uniform_matrix_2x4fv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) {
    glProgramUniformMatrix2x4fv(program, location, count, transpose, value);
}
RAIA_API void raia_gl_program_uniform_matrix_4x2fv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) {
    glProgramUniformMatrix4x2fv(program, location, count, transpose, value);
}
RAIA_API void raia_gl_program_uniform_matrix_3x4fv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) {
    glProgramUniformMatrix3x4fv(program, location, count, transpose, value);
}
RAIA_API void raia_gl_program_uniform_matrix_4x3fv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) {
    glProgramUniformMatrix4x3fv(program, location, count, transpose, value);
}
RAIA_API void raia_gl_validate_program_pipeline (GLuint pipeline) {
    glValidateProgramPipeline(pipeline);
}
RAIA_API void raia_gl_get_program_pipeline_info_log (GLuint pipeline, GLsizei bufSize, GLsizei *length, GLchar *infoLog) {
    glGetProgramPipelineInfoLog(pipeline, bufSize, length, infoLog);
}
RAIA_API void raia_gl_bind_image_texture (GLuint unit, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLenum format) {
    glBindImageTexture(unit, texture, level, layered, layer, access, format);
}
RAIA_API void raia_gl_get_boolean_i_v (GLenum target, GLuint index, GLboolean *data) {
    glGetBooleani_v(target, index, data);
}
RAIA_API void raia_gl_memory_barrier (GLbitfield barriers) {
    glMemoryBarrier(barriers);
}
RAIA_API void raia_gl_memory_barrier_by_region (GLbitfield barriers) {
    glMemoryBarrierByRegion(barriers);
}
RAIA_API void raia_gl_tex_storage_2d_multisample (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations) {
    glTexStorage2DMultisample(target, samples, internalformat, width, height, fixedsamplelocations);
}
RAIA_API void raia_gl_get_multisample_fv (GLenum pname, GLuint index, GLfloat *val) {
    glGetMultisamplefv(pname, index, val);
}
RAIA_API void raia_gl_sample_mask_i (GLuint maskNumber, GLbitfield mask) {
    glSampleMaski(maskNumber, mask);
}
RAIA_API void raia_gl_get_tex_level_parameter_iv (GLenum target, GLint level, GLenum pname, GLint *params) {
    glGetTexLevelParameteriv(target, level, pname, params);
}
RAIA_API void raia_gl_get_tex_level_parameter_fv (GLenum target, GLint level, GLenum pname, GLfloat *params) {
    glGetTexLevelParameterfv(target, level, pname, params);
}
RAIA_API void raia_gl_bind_vertex_buffer (GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride) {
    glBindVertexBuffer(bindingindex, buffer, offset, stride);
}
RAIA_API void raia_gl_vertex_attrib_format (GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset) {
    glVertexAttribFormat(attribindex, size, type, normalized, relativeoffset);
}
RAIA_API void raia_gl_vertex_attrib_i_format (GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset) {
    glVertexAttribIFormat(attribindex, size, type, relativeoffset);
}
RAIA_API void raia_gl_vertex_attrib_binding (GLuint attribindex, GLuint bindingindex) {
    glVertexAttribBinding(attribindex, bindingindex);
}
RAIA_API void raia_gl_vertex_binding_divisor (GLuint bindingindex, GLuint divisor) {
    glVertexBindingDivisor(bindingindex, divisor);
}

//
// GL ES 3.2
//

RAIA_API void raia_gl_blend_barrier (void) {
    glBlendBarrier();
}
RAIA_API void raia_gl_copy_image_sub_data (GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth) {
    glCopyImageSubData(srcName, srcTarget, srcLevel, srcX, srcY, srcZ, dstName, dstTarget, dstLevel, dstX, dstY, dstZ, srcWidth, srcHeight, srcDepth);
}
RAIA_API void raia_gl_debug_message_control (GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint *ids, GLboolean enabled) {
    glDebugMessageControl(source, type, severity, count, ids, enabled);
}
RAIA_API void raia_gl_debug_message_insert (GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *buf) {
    glDebugMessageInsert(source, type, id, severity, length, buf);
}
RAIA_API void raia_gl_debug_message_callback (GLDEBUGPROC callback, const void *userParam) {
    glDebugMessageCallback(callback, userParam);
}
RAIA_API GLuint raia_gl_get_debug_message_log (GLuint count, GLsizei bufSize, GLenum *sources, GLenum *types, GLuint *ids, GLenum *severities, GLsizei *lengths, GLchar *messageLog) {
    return glGetDebugMessageLog(count, bufSize, sources, types, ids, severities, lengths, messageLog);
}
RAIA_API void raia_gl_push_debug_group (GLenum source, GLuint id, GLsizei length, const GLchar *message) {
    glPushDebugGroup(source, id, length, message);
}
RAIA_API void raia_gl_pop_debug_group (void) {
    glPopDebugGroup();
}
RAIA_API void raia_gl_object_label (GLenum identifier, GLuint name, GLsizei length, const GLchar *label) {
    glObjectLabel(identifier, name, length, label);
}
RAIA_API void raia_gl_get_object_label (GLenum identifier, GLuint name, GLsizei bufSize, GLsizei *length, GLchar *label) {
    glGetObjectLabel(identifier, name, bufSize, length, label);
}
RAIA_API void raia_gl_object_ptr_label (const void *ptr, GLsizei length, const GLchar *label) {
    glObjectPtrLabel(ptr, length, label);
}
RAIA_API void raia_gl_get_object_ptr_label (const void *ptr, GLsizei bufSize, GLsizei *length, GLchar *label) {
    glGetObjectPtrLabel(ptr, bufSize, length, label);
}
RAIA_API void raia_gl_get_pointer_v (GLenum pname, void **params) {
    glGetPointerv(pname, params);
}
RAIA_API void raia_gl_enable_i (GLenum target, GLuint index) {
    glEnablei(target, index);
}
RAIA_API void raia_gl_disable_i (GLenum target, GLuint index) {
    glDisablei(target, index);
}
RAIA_API void raia_gl_blend_equation_i (GLuint buf, GLenum mode) {
    glBlendEquationi(buf, mode);
}
RAIA_API void raia_gl_blend_equation_separate_i (GLuint buf, GLenum modeRGB, GLenum modeAlpha) {
    glBlendEquationSeparatei(buf, modeRGB, modeAlpha);
}
RAIA_API void raia_gl_blend_func_i (GLuint buf, GLenum src, GLenum dst) {
    glBlendFunci(buf, src, dst);
}
RAIA_API void raia_gl_blend_func_separate_i (GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha) {
    glBlendFuncSeparatei(buf, srcRGB, dstRGB, srcAlpha, dstAlpha);
}
RAIA_API void raia_gl_color_mask_i (GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a) {
    glColorMaski(index, r, g, b, a);
}
RAIA_API GLboolean raia_gl_is_enabled_i (GLenum target, GLuint index) {
    return glIsEnabledi(target, index);
}
RAIA_API void raia_gl_draw_elements_base_vertex (GLenum mode, GLsizei count, GLenum type, const void *indices, GLint basevertex) {
    glDrawElementsBaseVertex(mode, count, type, indices, basevertex);
}
RAIA_API void raia_gl_draw_range_elements_base_vertex (GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices, GLint basevertex) {
    glDrawRangeElementsBaseVertex(mode, start, end, count, type, indices, basevertex);
}
RAIA_API void raia_gl_draw_elements_instanced_base_vertex (GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLint basevertex) {
    glDrawElementsInstancedBaseVertex(mode, count, type, indices, instancecount, basevertex);
}
RAIA_API void raia_gl_framebuffer_texture (GLenum target, GLenum attachment, GLuint texture, GLint level) {
    glFramebufferTexture(target, attachment, texture, level);
}
RAIA_API void raia_gl_primitive_bounding_box (GLfloat minX, GLfloat minY, GLfloat minZ, GLfloat minW, GLfloat maxX, GLfloat maxY, GLfloat maxZ, GLfloat maxW) {
    glPrimitiveBoundingBox(minX, minY, minZ, minW, maxX, maxY, maxZ, maxW);
}
RAIA_API GLenum raia_gl_get_graphics_reset_status (void) {
    return glGetGraphicsResetStatus();
}
RAIA_API void raia_gl_read_n_pixels (GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, void *data) {
    glReadnPixels(x, y, width, height, format, type, bufSize, data);
}
RAIA_API void raia_gl_get_n_uniform_fv (GLuint program, GLint location, GLsizei bufSize, GLfloat *params) {
    glGetnUniformfv(program, location, bufSize, params);
}
RAIA_API void raia_gl_get_n_uniform_iv (GLuint program, GLint location, GLsizei bufSize, GLint *params) {
    glGetnUniformiv(program, location, bufSize, params);
}
RAIA_API void raia_gl_get_n_uniform_uiv (GLuint program, GLint location, GLsizei bufSize, GLuint *params) {
    glGetnUniformuiv(program, location, bufSize, params);
}
RAIA_API void raia_gl_min_sample_shading (GLfloat value) {
    glMinSampleShading(value);
}
RAIA_API void raia_gl_patch_parameter_i (GLenum pname, GLint value) {
    glPatchParameteri(pname, value);
}
RAIA_API void raia_gl_tex_parameter_iiv (GLenum target, GLenum pname, const GLint *params) {
    glTexParameterIiv(target, pname, params);
}
RAIA_API void raia_gl_tex_parameter_iuiv (GLenum target, GLenum pname, const GLuint *params) {
    glTexParameterIuiv(target, pname, params);
}
RAIA_API void raia_gl_get_tex_parameter_iiv (GLenum target, GLenum pname, GLint *params) {
    glGetTexParameterIiv(target, pname, params);
}
RAIA_API void raia_gl_get_tex_parameter_iuiv (GLenum target, GLenum pname, GLuint *params) {
    glGetTexParameterIuiv(target, pname, params);
}
RAIA_API void raia_gl_sampler_parameter_iiv (GLuint sampler, GLenum pname, const GLint *param) {
    glSamplerParameterIiv(sampler, pname, param);
}
RAIA_API void raia_gl_sampler_parameter_iuiv (GLuint sampler, GLenum pname, const GLuint *param) {
    glSamplerParameterIuiv(sampler, pname, param);
}
RAIA_API void raia_gl_get_sampler_parameter_iiv (GLuint sampler, GLenum pname, GLint *params) {
    glGetSamplerParameterIiv(sampler, pname, params);
}
RAIA_API void raia_gl_get_sampler_parameter_iuiv (GLuint sampler, GLenum pname, GLuint *params) {
    glGetSamplerParameterIuiv(sampler, pname, params);
}
RAIA_API void raia_gl_tex_buffer (GLenum target, GLenum internalformat, GLuint buffer) {
    glTexBuffer(target, internalformat, buffer);
}
RAIA_API void raia_gl_tex_buffer_range (GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size) {
    glTexBufferRange(target, internalformat, buffer, offset, size);
}
RAIA_API void raia_gl_tex_storage_3d_multisample (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations) {
    glTexStorage3DMultisample(target, samples, internalformat, width, height, depth, fixedsamplelocations);
}

// (代替関数)

RAIA_API const char *raia_gl_viewport_alt(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    int x = joint_get_in_int(joint, "x");
    int y = joint_get_in_int(joint, "y");
    int width = joint_get_in_int(joint, "width");
    int height = joint_get_in_int(joint, "height");
    glViewport(x, y, width, height);
    joint_free(joint);
    return NULL;
}

RAIA_API const char *raia_gl_clear_color_alt(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    double red = joint_get_in_real(joint, "red");
    double green = joint_get_in_real(joint, "green");
    double blue = joint_get_in_real(joint, "blue");
    double alpha = joint_get_in_real(joint, "alpha");
    glClearColor((float) red, (float) green, (float) blue, (float) alpha);
    joint_free(joint);
    return NULL;
}

RAIA_API const char *raia_gl_clear_alt(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    GLbitfield mask = joint_get_in_uint(joint, "mask");
    glClear(mask);
    joint_free(joint);
    return NULL;
}

RAIA_API const char *raia_gl_use_program_alt(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    GLuint program = joint_get_in_uint(joint, "program");
    glUseProgram(program);
    joint_free(joint);
    return NULL;
}

RAIA_API const char *raia_gl_vertex_attrib_pointer_alt(const char *s) {
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

RAIA_API const char *raia_gl_enable_vertex_attrib_array_alt(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    GLuint index = joint_get_in_uint(joint, "index");
    glEnableVertexAttribArray(index);
    joint_free(joint);
    return NULL;
}

RAIA_API const char *raia_gl_tex_image_2d_alt(const char *s) {
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

RAIA_API const char *raia_gl_active_texture_alt(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    GLenum texture = joint_get_in_uint(joint, "texture");
    glActiveTexture(texture);
    joint_free(joint);
    return NULL;
}

RAIA_API const char *raia_gl_bind_texture_alt(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    GLenum target = joint_get_in_uint(joint, "target");
    GLuint texture = joint_get_in_uint(joint, "texture");
    glBindTexture(target, texture);
    joint_free(joint);
    return NULL;
}

RAIA_API const char *raia_gl_uniform_1i_alt(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    GLint location = joint_get_in_int(joint, "location");
    GLint v0 = joint_get_in_int(joint, "v0");
    glUniform1i(location, v0);
    joint_free(joint);
    return NULL;
}

RAIA_API const char *raia_gl_draw_elements_alt(const char *s) {
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

RAIA_API const char *raia_gl_create_shader_alt(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    GLenum type = joint_get_in_uint(joint, "type");
    GLuint shader = glCreateShader(type);
    joint_add_out_uint(joint, "result", shader);
    return joint_out_write(joint);
}

RAIA_API const char *raia_gl_shader_source_alt(const char *s) {
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

RAIA_API const char *raia_gl_compile_shader_alt(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    GLuint shader = joint_get_in_uint(joint, "shader");
    glCompileShader(shader);
    joint_free(joint);
    return NULL;
}

RAIA_API const char *raia_gl_get_shader_iv_alt(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    GLuint shader = joint_get_in_uint(joint, "shader");
    GLenum pname = joint_get_in_uint(joint, "pname");
    GLint params;
    glGetShaderiv(shader, pname, &params);
    joint_add_out_int(joint, "result", params);
    return joint_out_write(joint);
}

RAIA_API const char *raia_gl_create_program_alt(const char *s) {
    GLuint program = glCreateProgram();
    joint_t *joint = joint_init_out();
    joint_add_out_uint(joint, "result", program);
    return joint_out_write(joint);
}

RAIA_API const char *raia_gl_attach_shader_alt(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    GLuint program = joint_get_in_uint(joint, "program");
    GLuint shader = joint_get_in_uint(joint, "shader");
    glAttachShader(program, shader);
    joint_free(joint);
    return NULL;
}

RAIA_API const char *raia_gl_delete_shader_alt(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    GLuint shader = joint_get_in_uint(joint, "shader");
    glDeleteShader(shader);
    joint_free(joint);
    return NULL;
}

RAIA_API const char *raia_gl_link_program_alt(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    GLuint program = joint_get_in_uint(joint, "program");
    glLinkProgram(program);
    joint_free(joint);
    return NULL;
}

RAIA_API const char *raia_gl_pixel_store_i_alt(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    GLenum pname = joint_get_in_uint(joint, "pname");
    GLint param = joint_get_in_int(joint, "param");
    glPixelStorei(pname, param);
    joint_free(joint);
    return NULL;
}

RAIA_API const char *raia_gl_gen_textures_alt(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    GLsizei n = joint_get_in_int(joint, "n");
    GLuint textures;
    glGenTextures(n, &textures);
    joint_add_out_uint(joint, "result", textures);
    return joint_out_write(joint);
}

RAIA_API const char *raia_gl_tex_parameter_i_alt(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    GLenum target = joint_get_in_uint(joint, "target");
    GLenum pname = joint_get_in_uint(joint, "pname");
    GLint param = joint_get_in_int(joint, "param");
    glTexParameteri(target, pname, param);
    joint_free(joint);
    return NULL;
}

RAIA_API const char *raia_gl_get_attrib_location_alt(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    GLuint program = joint_get_in_uint(joint, "program");
    const char *name = joint_get_in_str(joint, "name");
    GLint location = glGetAttribLocation(program, name);
    joint_add_out_int(joint, "result", location);
    return joint_out_write(joint);
}

RAIA_API const char *raia_gl_get_uniform_location_alt(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    GLuint program = joint_get_in_uint(joint, "program");
    const char *name = joint_get_in_str(joint, "name");
    GLint location = glGetUniformLocation(program, name);
    joint_add_out_int(joint, "result", location);
    return joint_out_write(joint);
}

RAIA_API const char *raia_gl_gen_vertex_arrays_alt(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    GLsizei n = joint_get_in_int(joint, "n");
    GLuint arrays;
    glGenVertexArrays(n, &arrays);
    joint_add_out_uint(joint, "result", arrays);
    return joint_out_write(joint);
}

RAIA_API const char *raia_gl_gen_buffers_alt(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    GLsizei n = joint_get_in_int(joint, "n");
    GLuint buffers;
    glGenBuffers(n, &buffers);
    joint_add_out_uint(joint, "result", buffers);
    return joint_out_write(joint);
}

RAIA_API const char *raia_gl_bind_vertex_array_alt(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    GLuint array = joint_get_in_uint(joint, "array");
    glBindVertexArray(array);
    joint_free(joint);
    return NULL;
}

RAIA_API const char *raia_gl_bind_buffer_alt(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    GLenum target = joint_get_in_uint(joint, "target");
    GLuint buffer = joint_get_in_uint(joint, "buffer");
    glBindBuffer(target, buffer);
    joint_free(joint);
    return NULL;
}

RAIA_API const char *raia_gl_buffer_data_alt(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    GLenum target = joint_get_in_uint(joint, "target");
    GLsizeiptr size = joint_get_in_uint(joint, "size");
    const void *data = (const void *) (uintptr_t) joint_get_in_uint(joint, "data"); // Uint16Array
    GLenum usage = joint_get_in_uint(joint, "usage");
    glBufferData(target, size, data, usage);
    joint_free(joint);
    return NULL;
}

RAIA_API const char *raia_gl_delete_vertex_arrays_alt(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    GLuint arrays = joint_get_in_uint(joint, "arrays");
    glDeleteVertexArrays(1, &arrays);
    joint_free(joint);
    return NULL;
}

RAIA_API const char *raia_gl_delete_buffers_alt(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    GLuint buffers = joint_get_in_uint(joint, "buffers");
    glDeleteBuffers(1, &buffers);
    joint_free(joint);
    return NULL;
}

RAIA_API const char *raia_gl_delete_textures_alt(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    GLuint textures = joint_get_in_uint(joint, "textures");
    glDeleteTextures(1, &textures);
    joint_free(joint);
    return NULL;
}