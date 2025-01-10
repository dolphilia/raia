#include "raia_gles.h"

#include "GLES3/gl32.h"

// MARK: GL ES 2.0

void raia_gl_active_texture (unsigned int texture) {
    glActiveTexture(texture);
}
void raia_gl_attach_shader (unsigned int program, unsigned int shader) {
    glAttachShader(program, shader);
}
void raia_gl_bind_attrib_location (unsigned int program, unsigned int index, const char *name) {
    glBindAttribLocation(program, index, name);
}
void raia_gl_bind_buffer (unsigned int target, unsigned int buffer) {
    glBindBuffer(target, buffer);
}
void raia_gl_bind_framebuffer (unsigned int target, unsigned int framebuffer) {
    glBindFramebuffer(target, framebuffer);
}
void raia_gl_bind_renderbuffer (unsigned int target, unsigned int renderbuffer) {
    glBindRenderbuffer(target, renderbuffer);
}
void raia_gl_bind_texture (unsigned int target, unsigned int texture) {
    glBindTexture(target, texture);
}
void raia_gl_blend_color (float red, float green, float blue, float alpha) {
    glBlendColor(red, green, blue, alpha);
}
void raia_gl_blend_equation (unsigned int mode) {
    glBlendEquation(mode);
}
void raia_gl_blend_equation_separate (unsigned int modeRGB, unsigned int modeAlpha) {
    glBlendEquationSeparate(modeRGB, modeAlpha);
}
void raia_gl_blend_func (unsigned int sfactor, unsigned int dfactor) {
    glBlendFunc(sfactor, dfactor);
}
void raia_gl_blend_func_separate (unsigned int sfactorRGB, unsigned int dfactorRGB, unsigned int sfactorAlpha, unsigned int dfactorAlpha) {
    glBlendFuncSeparate(sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha);
}
void raia_gl_buffer_data (unsigned int target, int size, const void *data, unsigned int usage) {
    glBufferData(target, size, data, usage);
}
void raia_gl_buffer_sub_data (unsigned int target, int offset, int size, const void *data) {
    glBufferSubData(target, offset, size, data);
}
unsigned int raia_gl_check_framebuffer_status (unsigned int target) {
    return glCheckFramebufferStatus(target);
}
void raia_gl_clear (unsigned int mask) {
    glClear(mask);
}
void raia_gl_clear_color (float red, float green, float blue, float alpha) {
    glClearColor(red, green, blue, alpha);
}
void raia_gl_clear_depth_f (float d) {
    glClearDepthf(d);
}
void raia_gl_clear_stencil (int s) {
    glClearStencil(s);
}
void raia_gl_color_mask (unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha) {
    glColorMask(red, green, blue, alpha);
}
void raia_gl_compile_shader (unsigned int shader) {
    glCompileShader(shader);
}
void raia_gl_compressed_tex_image_2d (unsigned int target, int level, unsigned int internalformat, int width, int height, int border, int imageSize, const void *data) {
    glCompressedTexImage2D(target, level, internalformat, width, height, border, imageSize, data);
}
void raia_gl_compressed_tex_sub_image_2d (unsigned int target, int level, int xoffset, int yoffset, int width, int height, unsigned int format, int imageSize, const void *data) {
    glCompressedTexSubImage2D(target, level, xoffset, yoffset, width, height, format, imageSize, data);
}
void raia_gl_copy_tex_image_2d (unsigned int target, int level, unsigned int internalformat, int x, int y, int width, int height, int border) {
    glCopyTexImage2D(target, level, internalformat, x, y, width, height, border);
}
void raia_gl_copy_tex_sub_image_2d (unsigned int target, int level, int xoffset, int yoffset, int x, int y, int width, int height) {
    glCopyTexSubImage2D(target, level, xoffset, yoffset, x, y, width, height);
}
unsigned int raia_gl_create_program (void) {
    return glCreateProgram();
}
unsigned int raia_gl_create_shader (unsigned int type) {
    return glCreateShader(type);
}
void raia_gl_cull_face (unsigned int mode) {
    glCullFace(mode);
}
void raia_gl_delete_buffers (int n, const void *buffers) {
    glDeleteBuffers(n, buffers);
}
void raia_gl_delete_framebuffers (int n, const void *framebuffers) {
    glDeleteFramebuffers(n, framebuffers);
}
void raia_gl_delete_program (unsigned int program) {
    glDeleteProgram(program);
}
void raia_gl_delete_renderbuffers (int n, const void *renderbuffers) {
    glDeleteRenderbuffers(n, renderbuffers);
}
void raia_gl_delete_shader (unsigned int shader) {
    glDeleteShader(shader);
}
void raia_gl_delete_textures (int n, const void *textures) {
    glDeleteTextures(n, textures);
}
void raia_gl_depth_func (unsigned int func) {
    glDepthFunc(func);
}
void raia_gl_depth_mask (unsigned char flag) {
    glDepthMask(flag);
}
void raia_gl_depth_range_f (float n, float f) {
    glDepthRangef(n, f);
}
void raia_gl_detach_shader (unsigned int program, unsigned int shader) {
    glDetachShader(program, shader);
}
void raia_gl_disable (unsigned int cap) {
    glDisable(cap);
}
void raia_gl_disable_vertex_attrib_array (unsigned int index) {
    glDisableVertexAttribArray(index);
}
void raia_gl_draw_arrays (unsigned int mode, int first, int count) {
    glDrawArrays(mode, first, count);
}
void raia_gl_draw_elements (unsigned int mode, int count, unsigned int type, const void *indices) {
    glDrawElements(mode, count, type, indices);
}
void raia_gl_enable (unsigned int cap) {
    glEnable(cap);
}
void raia_gl_enable_vertex_attrib_array (unsigned int index) {
    glEnableVertexAttribArray(index);
}
void raia_gl_finish (void) {
    glFinish();
}
void raia_gl_flush (void) {
    glFlush();
}
void raia_gl_framebuffer_renderbuffer (unsigned int target, unsigned int attachment, unsigned int renderbuffertarget, unsigned int renderbuffer) {
    glFramebufferRenderbuffer(target, attachment, renderbuffertarget, renderbuffer);
}
void raia_gl_framebuffer_texture_2d (unsigned int target, unsigned int attachment, unsigned int textarget, unsigned int texture, int level) {
    glFramebufferTexture2D(target, attachment, textarget, texture, level);
}
void raia_gl_front_face (unsigned int mode) {
    glFrontFace(mode);
}
void raia_gl_gen_buffers (int n, void *buffers) {
    glGenBuffers(n, buffers);
}
void raia_gl_generate_mipmap (unsigned int target) {
    glGenerateMipmap(target);
}
void raia_gl_gen_framebuffers (int n, void *framebuffers) {
    glGenFramebuffers(n, framebuffers);
}
void raia_gl_gen_renderbuffers (int n, void *renderbuffers) {
    glGenRenderbuffers(n, renderbuffers);
}
void raia_gl_gen_textures (int n, void *textures) {
    glGenTextures(n, textures);
}
void raia_gl_get_active_attrib (unsigned int program, unsigned int index, int bufSize, void *length, void *size, void *type, char *name) {
    glGetActiveAttrib(program, index, bufSize, length, size, type, name);
}
void raia_gl_get_active_uniform (unsigned int program, unsigned int index, int bufSize, void *length, void *size, void *type, char *name) {
    glGetActiveUniform(program, index, bufSize, length, size, type, name);
}
void raia_gl_get_attached_shaders (unsigned int program, int maxCount, void *count, void *shaders) {
    glGetAttachedShaders(program, maxCount, count, shaders);
}
int raia_gl_get_attrib_location (unsigned int program, const char *name) {
    return glGetAttribLocation(program, name);
}
void raia_gl_get_boolean_v (unsigned int pname, unsigned char *data) {
    glGetBooleanv(pname, data);
}
void raia_gl_get_buffer_parameter_iv (unsigned int target, unsigned int pname, void *params) {
    glGetBufferParameteriv(target, pname, params);
}
unsigned int raia_gl_get_error (void) {
    return glGetError();
}
void raia_gl_get_float_v (unsigned int pname, void *data) {
    glGetFloatv(pname, data);
}
void raia_gl_get_framebuffer_attachment_parameter_iv (unsigned int target, unsigned int attachment, unsigned int pname, void *params) {
    glGetFramebufferAttachmentParameteriv(target, attachment, pname, params);
}
void raia_gl_get_integer_v (unsigned int pname, void *data) {
    glGetIntegerv(pname, data);
}
void raia_gl_get_program_iv (unsigned int program, unsigned int pname, void *params) {
    glGetProgramiv(program, pname, params);
}
void raia_gl_get_program_info_log (unsigned int program, int bufSize, void *length, char *infoLog) {
    glGetProgramInfoLog(program, bufSize, length, infoLog);
}
void raia_gl_get_renderbuffer_parameter_iv (unsigned int target, unsigned int pname, void *params) {
    glGetRenderbufferParameteriv(target, pname, params);
}
void raia_gl_get_shader_iv (unsigned int shader, unsigned int pname, void *params) {
    glGetShaderiv(shader, pname, params);
}
void raia_gl_get_shader_info_log (unsigned int shader, int bufSize, void *length, char *infoLog) {
    glGetShaderInfoLog(shader, bufSize, length, infoLog);
}
void raia_gl_get_shader_precision_format (unsigned int shadertype, unsigned int precisiontype, void *range, void *precision) {
    glGetShaderPrecisionFormat(shadertype, precisiontype, range, precision);
}
void raia_gl_get_shader_source (unsigned int shader, int bufSize, void *length, char *source) {
    glGetShaderSource(shader, bufSize, length, source);
}
const unsigned char *raia_gl_get_string (unsigned int name) {
    return glGetString(name);
}
void raia_gl_get_tex_parameter_fv (unsigned int target, unsigned int pname, void *params) {
    glGetTexParameterfv(target, pname, params);
}
void raia_gl_get_tex_parameter_iv (unsigned int target, unsigned int pname, void *params) {
    glGetTexParameteriv(target, pname, params);
}
void raia_gl_get_uniform_fv (unsigned int program, int location, void *params) {
    glGetUniformfv(program, location, params);
}
void raia_gl_get_uniform_iv (unsigned int program, int location, void *params) {
    glGetUniformiv(program, location, params);
}
int raia_gl_get_uniform_location (unsigned int program, const char *name) {
    return glGetUniformLocation(program, name);
}
void raia_gl_get_vertex_attrib_fv (unsigned int index, unsigned int pname, void *params) {
    glGetVertexAttribfv(index, pname, params);
}
void raia_gl_get_vertex_attrib_iv (unsigned int index, unsigned int pname, void *params) {
    glGetVertexAttribiv(index, pname, params);
}
void raia_gl_get_vertex_attrib_pointer_v (unsigned int index, unsigned int pname, void **pointer) {
    glGetVertexAttribPointerv(index, pname, pointer);
}
void raia_gl_hint (unsigned int target, unsigned int mode) {
    glHint(target, mode);
}
unsigned char raia_gl_is_buffer (unsigned int buffer) {
    return glIsBuffer(buffer);
}
unsigned char raia_gl_is_enabled (unsigned int cap) {
    return glIsEnabled(cap);
}
unsigned char raia_gl_is_framebuffer (unsigned int framebuffer) {
    return glIsFramebuffer(framebuffer);
}
unsigned char raia_gl_is_program (unsigned int program) {
    return glIsProgram(program);
}
unsigned char raia_gl_is_renderbuffer (unsigned int renderbuffer) {
    return glIsRenderbuffer(renderbuffer);
}
unsigned char raia_gl_is_shader (unsigned int shader) {
    return glIsShader(shader);
}
unsigned char raia_gl_is_texture (unsigned int texture) {
    return glIsTexture(texture);
}
void raia_gl_line_width (float width) {
    glLineWidth(width);
}
void raia_gl_link_program (unsigned int program) {
    glLinkProgram(program);
}
void raia_gl_pixel_store_i (unsigned int pname, int param) {
    glPixelStorei(pname, param);
}
void raia_gl_polygon_offset (float factor, float units) {
    glPolygonOffset(factor, units);
}
void raia_gl_read_pixels (int x, int y, int width, int height, unsigned int format, unsigned int type, void *pixels) {
    glReadPixels(x, y, width, height, format, type, pixels);
}
void raia_gl_release_shader_compiler (void) {
    glReleaseShaderCompiler();
}
void raia_gl_renderbuffer_storage (unsigned int target, unsigned int internalformat, int width, int height) {
    glRenderbufferStorage(target, internalformat, width, height);
}
void raia_gl_sample_coverage (float value, unsigned char invert) {
    glSampleCoverage(value, invert);
}
void raia_gl_scissor (int x, int y, int width, int height) {
    glScissor(x, y, width, height);
}
void raia_gl_shader_binary (int count, const void *shaders, unsigned int binaryformat, const void *binary, int length) {
    glShaderBinary(count, shaders, binaryformat, binary, length);
}
void raia_gl_shader_source (unsigned int shader, int count, const char *const*string, const void *length) {
    glShaderSource(shader, count, string, length);
}
void raia_gl_stencil_func (unsigned int func, int ref, unsigned int mask) {
    glStencilFunc(func, ref, mask);
}
void raia_gl_stencil_func_separate (unsigned int face, unsigned int func, int ref, unsigned int mask) {
    glStencilFuncSeparate(face, func, ref, mask);
}
void raia_gl_stencil_mask (unsigned int mask) {
    glStencilMask(mask);
}
void raia_gl_stencil_mask_separate (unsigned int face, unsigned int mask) {
    glStencilMaskSeparate(face, mask);
}
void raia_gl_stencil_op (unsigned int fail, unsigned int zfail, unsigned int zpass) {
    glStencilOp(fail, zfail, zpass);
}
void raia_gl_stencil_op_separate (unsigned int face, unsigned int sfail, unsigned int dpfail, unsigned int dppass) {
    glStencilOpSeparate(face, sfail, dpfail, dppass);
}
void raia_gl_tex_image_2d (unsigned int target, int level, int internalformat, int width, int height, int border, unsigned int format, unsigned int type, const void *pixels) {
    glTexImage2D(target, level, internalformat, width, height, border, format, type, pixels);
}
void raia_gl_tex_parameter_f (unsigned int target, unsigned int pname, float param) {
    glTexParameterf(target, pname, param);
}
void raia_gl_tex_parameter_fv (unsigned int target, unsigned int pname, const void *params) {
    glTexParameterfv(target, pname, params);
}
void raia_gl_tex_parameter_i (unsigned int target, unsigned int pname, int param) {
    glTexParameteri(target, pname, param);
}
void raia_gl_tex_parameter_iv (unsigned int target, unsigned int pname, const void *params) {
    glTexParameteriv(target, pname, params);
}
void raia_gl_tex_sub_image_2d (unsigned int target, int level, int xoffset, int yoffset, int width, int height, unsigned int format, unsigned int type, const void *pixels) {
    glTexSubImage2D(target, level, xoffset, yoffset, width, height, format, type, pixels);
}
void raia_gl_uniform_1f (int location, float v0) {
    glUniform1f(location, v0);
}
void raia_gl_uniform_1fv (int location, int count, const void *value) {
    glUniform1fv(location, count, value);
}
void raia_gl_uniform_1i (int location, int v0) {
    glUniform1i(location, v0);
}
void raia_gl_uniform_1iv (int location, int count, const void *value) {
    glUniform1iv(location, count, value);
}
void raia_gl_uniform_2f (int location, float v0, float v1) {
    glUniform2f(location, v0, v1);
}
void raia_gl_uniform_2fv (int location, int count, const void *value) {
    glUniform2fv(location, count, value);
}
void raia_gl_uniform_2i (int location, int v0, int v1) {
    glUniform2i(location, v0, v1);
}
void raia_gl_uniform_2iv (int location, int count, const void *value) {
    glUniform2iv(location, count, value);
}
void raia_gl_uniform_3f (int location, float v0, float v1, float v2) {
    glUniform3f(location, v0, v1, v2);
}
void raia_gl_uniform_3fv (int location, int count, const void *value) {
    glUniform3fv(location, count, value);
}
void raia_gl_uniform_3i (int location, int v0, int v1, int v2) {
    glUniform3i(location, v0, v1, v2);
}
void raia_gl_uniform_3iv (int location, int count, const void *value) {
    glUniform3iv(location, count, value);
}
void raia_gl_uniform_4f (int location, float v0, float v1, float v2, float v3) {
    glUniform4f(location, v0, v1, v2, v3);
}
void raia_gl_uniform_4fv (int location, int count, const void *value) {
    glUniform4fv(location, count, value);
}
void raia_gl_uniform_4i (int location, int v0, int v1, int v2, int v3) {
    glUniform4i(location, v0, v1, v2, v3);
}
void raia_gl_uniform_4iv (int location, int count, const void *value) {
    glUniform4iv(location, count, value);
}
void raia_gl_uniform_matrix_2fv (int location, int count, unsigned char transpose, const void *value) {
    glUniformMatrix2fv(location, count, transpose, value);
}
void raia_gl_uniform_matrix_3fv (int location, int count, unsigned char transpose, const void *value) {
    glUniformMatrix3fv(location, count, transpose, value);
}
void raia_gl_uniform_matrix_4fv (int location, int count, unsigned char transpose, const void *value) {
    glUniformMatrix4fv(location, count, transpose, value);
}
void raia_gl_use_program (unsigned int program) {
    glUseProgram(program);
}
void raia_gl_validate_program (unsigned int program) {
    glValidateProgram(program);
}
void raia_gl_vertex_attrib_1f (unsigned int index, float x) {
    glVertexAttrib1f(index, x);
}
void raia_gl_vertex_attrib_1fv (unsigned int index, const void *v) {
    glVertexAttrib1fv(index, v);
}
void raia_gl_vertex_attrib_2f (unsigned int index, float x, float y) {
    glVertexAttrib2f(index, x, y);
}
void raia_gl_vertex_attrib_2fv (unsigned int index, const void *v) {
    glVertexAttrib2fv(index, v);
}
void raia_gl_vertex_attrib_3f (unsigned int index, float x, float y, float z) {
    glVertexAttrib3f(index, x, y, z);
}
void raia_gl_vertex_attrib_3fv (unsigned int index, const void *v) {
    glVertexAttrib3fv(index, v);
}
void raia_gl_vertex_attrib_4f (unsigned int index, float x, float y, float z, float w) {
    glVertexAttrib4f(index, x, y, z, w);
}
void raia_gl_vertex_attrib_4fv (unsigned int index, const void *v) {
    glVertexAttrib4fv(index, v);
}
void raia_gl_vertex_attrib_pointer (unsigned int index, int size, unsigned int type, unsigned char normalized, int stride, const void *pointer) {
    glVertexAttribPointer(index, size, type, normalized, stride, pointer);
}
void raia_gl_viewport (int x, int y, int width, int height) {
    glViewport(x, y, width, height);
}

// MARK: GL ES 3.0

void raia_gl_read_buffer (unsigned int src) {
    glReadBuffer(src);
}
void raia_gl_draw_range_elements (unsigned int mode, unsigned int start, unsigned int end, int count, unsigned int type, const void *indices) {
    glDrawRangeElements(mode, start, end, count, type, indices);
}
void raia_gl_tex_image_3d (unsigned int target, int level, int internalformat, int width, int height, int depth, int border, unsigned int format, unsigned int type, const void *pixels) {
    glTexImage3D(target, level, internalformat, width, height, depth, border, format, type, pixels);
}
void raia_gl_tex_sub_image_3d (unsigned int target, int level, int xoffset, int yoffset, int zoffset, int width, int height, int depth, unsigned int format, unsigned int type, const void *pixels) {
    glTexSubImage3D(target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels);
}
void raia_gl_copy_tex_sub_image_3d (unsigned int target, int level, int xoffset, int yoffset, int zoffset, int x, int y, int width, int height) {
    glCopyTexSubImage3D(target, level, xoffset, yoffset, zoffset, x, y, width, height);
}
void raia_gl_compressed_tex_image_3d (unsigned int target, int level, unsigned int internalformat, int width, int height, int depth, int border, int imageSize, const void *data) {
    glCompressedTexImage3D(target, level, internalformat, width, height, depth, border, imageSize, data);
}
void raia_gl_compressed_tex_sub_image_3d (unsigned int target, int level, int xoffset, int yoffset, int zoffset, int width, int height, int depth, unsigned int format, int imageSize, const void *data) {
    glCompressedTexSubImage3D(target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data);
}
void raia_gl_gen_queries (int n, void *ids) {
    glGenQueries(n, ids);
}
void raia_gl_delete_queries (int n, const void *ids) {
    glDeleteQueries(n, ids);
}
unsigned char raia_gl_is_query (unsigned int id) {
    return glIsQuery(id);
}
void raia_gl_begin_query (unsigned int target, unsigned int id) {
    glBeginQuery(target, id);
}
void raia_gl_end_query (unsigned int target) {
    glEndQuery(target);
}
void raia_gl_get_query_iv (unsigned int target, unsigned int pname, void *params) {
    glGetQueryiv(target, pname, params);
}
void raia_gl_get_query_object_uiv (unsigned int id, unsigned int pname, void *params) {
    glGetQueryObjectuiv(id, pname, params);
}
unsigned char raia_gl_unmap_buffer (unsigned int target) {
    return glUnmapBuffer(target);
}
void raia_gl_get_buffer_pointer_v (unsigned int target, unsigned int pname, void **params) {
    glGetBufferPointerv(target, pname, params);
}
void raia_gl_draw_buffers (int n, const void *bufs) {
    glDrawBuffers(n, bufs);
}
void raia_gl_uniform_matrix_2x3fv (int location, int count, unsigned char transpose, const void *value) {
    glUniformMatrix2x3fv(location, count, transpose, value);
}
void raia_gl_uniform_matrix_3x2fv (int location, int count, unsigned char transpose, const void *value) {
    glUniformMatrix3x2fv(location, count, transpose, value);
}
void raia_gl_uniform_matrix_2x4fv (int location, int count, unsigned char transpose, const void *value) {
    glUniformMatrix2x4fv(location, count, transpose, value);
}
void raia_gl_uniform_matrix_4x2fv (int location, int count, unsigned char transpose, const void *value) {
    glUniformMatrix4x2fv(location, count, transpose, value);
}
void raia_gl_uniform_matrix_3x4fv (int location, int count, unsigned char transpose, const void *value) {
    glUniformMatrix3x4fv(location, count, transpose, value);
}
void raia_gl_uniform_matrix_4x3fv (int location, int count, unsigned char transpose, const void *value) {
    glUniformMatrix4x3fv(location, count, transpose, value);
}
void raia_gl_blit_framebuffer (int srcX0, int srcY0, int srcX1, int srcY1, int dstX0, int dstY0, int dstX1, int dstY1, unsigned int mask, unsigned int filter) {
    glBlitFramebuffer(srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter);
}
void raia_gl_renderbuffer_storage_multisample (unsigned int target, int samples, unsigned int internalformat, int width, int height) {
    glRenderbufferStorageMultisample(target, samples, internalformat, width, height);
}
void raia_gl_framebuffer_texture_layer (unsigned int target, unsigned int attachment, unsigned int texture, int level, int layer) {
    glFramebufferTextureLayer(target, attachment, texture, level, layer);
}
void *raia_gl_map_buffer_range (unsigned int target, int offset, int length, unsigned int access) {
    return glMapBufferRange(target, offset, length, access);
}
void raia_gl_flush_mapped_buffer_range (unsigned int target, int offset, int length) {
    glFlushMappedBufferRange(target, offset, length);
}
void raia_gl_bind_vertex_array (unsigned int array) {
    glBindVertexArray(array);
}
void raia_gl_delete_vertex_arrays (int n, const void *arrays) {
    glDeleteVertexArrays(n, arrays);
}
void raia_gl_gen_vertex_arrays (int n, void *arrays) {
    glGenVertexArrays(n, arrays);
}
unsigned char raia_gl_is_vertex_array (unsigned int array) {
    return glIsVertexArray(array);
}
void raia_gl_get_integer_i_v (unsigned int target, unsigned int index, void *data) {
    glGetIntegeri_v(target, index, data);
}
void raia_gl_begin_transform_feedback (unsigned int primitiveMode) {
    glBeginTransformFeedback(primitiveMode);
}
void raia_gl_end_transform_feedback (void) {
    glEndTransformFeedback();
}
void raia_gl_bind_buffer_range (unsigned int target, unsigned int index, unsigned int buffer, int offset, int size) {
    glBindBufferRange(target, index, buffer, offset, size);
}
void raia_gl_bind_buffer_base (unsigned int target, unsigned int index, unsigned int buffer) {
    glBindBufferBase(target, index, buffer);
}
void raia_gl_transform_feedback_varyings (unsigned int program, int count, const char *const*varyings, unsigned int bufferMode) {
    glTransformFeedbackVaryings(program, count, varyings, bufferMode);
}
void raia_gl_get_transform_feedback_varying (unsigned int program, unsigned int index, int bufSize, void *length, void *size, void *type, char *name) {
    glGetTransformFeedbackVarying(program, index, bufSize, length, size, type, name);
}
void raia_gl_vertex_attrib_i_pointer (unsigned int index, int size, unsigned int type, int stride, const void *pointer) {
    glVertexAttribIPointer(index, size, type, stride, pointer);
}
void raia_gl_get_vertex_attrib_iiv (unsigned int index, unsigned int pname, void *params) {
    glGetVertexAttribIiv(index, pname, params);
}
void raia_gl_get_vertex_attrib_iuiv (unsigned int index, unsigned int pname, void *params) {
    glGetVertexAttribIuiv(index, pname, params);
}
void raia_gl_vertex_attrib_i4i (unsigned int index, int x, int y, int z, int w) {
    glVertexAttribI4i(index, x, y, z, w);
}
void raia_gl_vertex_attrib_i4ui (unsigned int index, unsigned int x, unsigned int y, unsigned int z, unsigned int w) {
    glVertexAttribI4ui(index, x, y, z, w);
}
void raia_gl_vertex_attrib_i4iv (unsigned int index, const void *v) {
    glVertexAttribI4iv(index, v);
}
void raia_gl_vertex_attrib_i4uiv (unsigned int index, const void *v) {
    glVertexAttribI4uiv(index, v);
}
void raia_gl_get_uniform_uiv (unsigned int program, int location, void *params) {
    glGetUniformuiv(program, location, params);
}
int raia_gl_get_frag_data_location (unsigned int program, const char *name) {
    return glGetFragDataLocation(program, name);
}
void raia_gl_uniform_1ui (int location, unsigned int v0) {
    glUniform1ui(location, v0);
}
void raia_gl_uniform_2ui (int location, unsigned int v0, unsigned int v1) {
    glUniform2ui(location, v0, v1);
}
void raia_gl_uniform_3ui (int location, unsigned int v0, unsigned int v1, unsigned int v2) {
    glUniform3ui(location, v0, v1, v2);
}
void raia_gl_uniform_4ui (int location, unsigned int v0, unsigned int v1, unsigned int v2, unsigned int v3) {
    glUniform4ui(location, v0, v1, v2, v3);
}
void raia_gl_uniform_1uiv (int location, int count, const void *value) {
    glUniform1uiv(location, count, value);
}
void raia_gl_uniform_2uiv (int location, int count, const void *value) {
    glUniform2uiv(location, count, value);
}
void raia_gl_uniform_3uiv (int location, int count, const void *value) {
    glUniform3uiv(location, count, value);
}
void raia_gl_uniform_4uiv (int location, int count, const void *value) {
    glUniform4uiv(location, count, value);
}
void raia_gl_clear_buffer_iv (unsigned int buffer, int drawbuffer, const void *value) {
    glClearBufferiv(buffer, drawbuffer, value);
}
void raia_gl_clear_buffer_uiv (unsigned int buffer, int drawbuffer, const void *value) {
    glClearBufferuiv(buffer, drawbuffer, value);
}
void raia_gl_clear_buffer_fv (unsigned int buffer, int drawbuffer, const void *value) {
    glClearBufferfv(buffer, drawbuffer, value);
}
void raia_gl_clear_buffer_fi (unsigned int buffer, int drawbuffer, float depth, int stencil) {
    glClearBufferfi(buffer, drawbuffer, depth, stencil);
}
const unsigned char  *raia_gl_get_string_i (unsigned int name, unsigned int index) {
    return glGetStringi(name, index);
}
void raia_gl_copy_buffer_sub_data (unsigned int readTarget, unsigned int writeTarget, int readOffset, int writeOffset, int size) {
    glCopyBufferSubData(readTarget, writeTarget, readOffset, writeOffset, size);
}
void raia_gl_get_uniform_indices (unsigned int program, int uniformCount, const char *const*uniformNames, void *uniformIndices) {
    glGetUniformIndices(program, uniformCount, uniformNames, uniformIndices);
}
void raia_gl_get_active_uniforms_iv (unsigned int program, int uniformCount, const void *uniformIndices, unsigned int pname, void *params) {
    glGetActiveUniformsiv(program, uniformCount, uniformIndices, pname, params);
}
unsigned int raia_gl_get_uniform_block_index (unsigned int program, const char *uniformBlockName) {
    return glGetUniformBlockIndex(program, uniformBlockName);
}
void raia_gl_get_active_uniform_block_iv (unsigned int program, unsigned int uniformBlockIndex, unsigned int pname, void *params) {
    glGetActiveUniformBlockiv(program, uniformBlockIndex, pname, params);
}
void raia_gl_get_active_uniform_block_name (unsigned int program, unsigned int uniformBlockIndex, int bufSize, void *length, char *uniformBlockName) {
    glGetActiveUniformBlockName(program, uniformBlockIndex, bufSize, length, uniformBlockName);
}
void raia_gl_uniform_block_binding (unsigned int program, unsigned int uniformBlockIndex, unsigned int uniformBlockBinding) {
    glUniformBlockBinding(program, uniformBlockIndex, uniformBlockBinding);
}
void raia_gl_draw_arrays_instanced (unsigned int mode, int first, int count, int instancecount) {
    glDrawArraysInstanced(mode, first, count, instancecount);
}
void raia_gl_draw_elements_instanced (unsigned int mode, int count, unsigned int type, const void *indices, int instancecount) {
    glDrawElementsInstanced(mode, count, type, indices, instancecount);
}
void * raia_gl_fence_sync (unsigned int condition, unsigned int flags) {
    return glFenceSync(condition, flags);
}
unsigned char raia_gl_is_sync (void * sync) {
    return glIsSync(sync);
}
void raia_gl_delete_sync (void * sync) {
    glDeleteSync(sync);
}
unsigned int raia_gl_client_wait_sync (void * sync, unsigned int flags, unsigned long long timeout) {
    return glClientWaitSync(sync, flags, timeout);
}
void raia_gl_wait_sync (void * sync, unsigned int flags, unsigned long long timeout) {
    glWaitSync(sync, flags, timeout);
}
void raia_gl_get_integer_64v (unsigned int pname, void *data) {
    glGetInteger64v(pname, data);
}
void raia_gl_get_sync_iv (void * sync, unsigned int pname, int bufSize, void *length, void *values) {
    glGetSynciv(sync, pname, bufSize, length, values);
}
void raia_gl_get_integer_64i_v (unsigned int target, unsigned int index, void *data) {
    glGetInteger64i_v(target, index, data);
}
void raia_gl_get_buffer_parameter_i64v (unsigned int target, unsigned int pname, void *params) {
    glGetBufferParameteri64v(target, pname, params);
}
void raia_gl_gen_samplers (int count, void *samplers) {
    glGenSamplers(count, samplers);
}
void raia_gl_delete_samplers (int count, const void *samplers) {
    glDeleteSamplers(count, samplers);
}
unsigned char raia_gl_is_sampler (unsigned int sampler) {
    return glIsSampler(sampler);
}
void raia_gl_bind_sampler (unsigned int unit, unsigned int sampler) {
    glBindSampler(unit, sampler);
}
void raia_gl_sampler_parameter_i (unsigned int sampler, unsigned int pname, int param) {
    glSamplerParameteri(sampler, pname, param);
}
void raia_gl_sampler_parameter_iv (unsigned int sampler, unsigned int pname, const void *param) {
    glSamplerParameteriv(sampler, pname, param);
}
void raia_gl_sampler_parameter_f (unsigned int sampler, unsigned int pname, float param) {
    glSamplerParameterf(sampler, pname, param);
}
void raia_gl_sampler_parameter_fv (unsigned int sampler, unsigned int pname, const void *param) {
    glSamplerParameterfv(sampler, pname, param);
}
void raia_gl_get_sampler_parameter_iv (unsigned int sampler, unsigned int pname, void *params) {
    glGetSamplerParameteriv(sampler, pname, params);
}
void raia_gl_get_sampler_parameter_fv (unsigned int sampler, unsigned int pname, void *params) {
    glGetSamplerParameterfv(sampler, pname, params);
}
void raia_gl_vertex_attrib_divisor (unsigned int index, unsigned int divisor) {
    glVertexAttribDivisor(index, divisor);
}
void raia_gl_bind_transform_feedback (unsigned int target, unsigned int id) {
    glBindTransformFeedback(target, id);
}
void raia_gl_delete_transform_feedbacks (int n, const void *ids) {
    glDeleteTransformFeedbacks(n, ids);
}
void raia_gl_gen_transform_feedbacks (int n, void *ids) {
    glGenTransformFeedbacks(n, ids);
}
unsigned char raia_gl_is_transform_feedback (unsigned int id) {
    return glIsTransformFeedback(id);
}
void raia_gl_pause_transform_feedback (void) {
    glPauseTransformFeedback();
}
void raia_gl_resume_transform_feedback (void) {
    glResumeTransformFeedback();
}
void raia_gl_get_program_binary (unsigned int program, int bufSize, void *length, void *binaryFormat, void *binary) {
    glGetProgramBinary(program, bufSize, length, binaryFormat, binary);
}
void raia_gl_program_binary (unsigned int program, unsigned int binaryFormat, const void *binary, int length) {
    glProgramBinary(program, binaryFormat, binary, length);
}
void raia_gl_program_parameter_i (unsigned int program, unsigned int pname, int value) {
    glProgramParameteri(program, pname, value);
}
void raia_gl_invalidate_framebuffer (unsigned int target, int numAttachments, const void *attachments) {
    glInvalidateFramebuffer(target, numAttachments, attachments);
}
void raia_gl_invalidate_sub_framebuffer (unsigned int target, int numAttachments, const void *attachments, int x, int y, int width, int height) {
    glInvalidateSubFramebuffer(target, numAttachments, attachments, x, y, width, height);
}
void raia_gl_tex_storage_2d (unsigned int target, int levels, unsigned int internalformat, int width, int height) {
    glTexStorage2D(target, levels, internalformat, width, height);
}
void raia_gl_tex_storage_3d (unsigned int target, int levels, unsigned int internalformat, int width, int height, int depth) {
    glTexStorage3D(target, levels, internalformat, width, height, depth);
}
void raia_gl_get_internal_format_iv (unsigned int target, unsigned int internalformat, unsigned int pname, int bufSize, void *params) {
    glGetInternalformativ(target, internalformat, pname, bufSize, params);
}

// MARK: GL ES 3.1

void raia_gl_dispatch_compute (unsigned int num_groups_x, unsigned int num_groups_y, unsigned int num_groups_z) {
    glDispatchCompute(num_groups_x, num_groups_y, num_groups_z);
}
void raia_gl_dispatch_compute_indirect (int indirect) {
    glDispatchComputeIndirect(indirect);
}
void raia_gl_draw_arrays_indirect (unsigned int mode, const void *indirect) {
    glDrawArraysIndirect(mode, indirect);
}
void raia_gl_draw_elements_indirect (unsigned int mode, unsigned int type, const void *indirect) {
    glDrawElementsIndirect(mode, type, indirect);
}
void raia_gl_framebuffer_parameter_i (unsigned int target, unsigned int pname, int param) {
    glFramebufferParameteri(target, pname, param);
}
void raia_gl_get_framebuffer_parameter_iv (unsigned int target, unsigned int pname, void *params) {
    glGetFramebufferParameteriv(target, pname, params);
}
void raia_gl_get_program_interface_iv (unsigned int program, unsigned int programInterface, unsigned int pname, void *params) {
    glGetProgramInterfaceiv(program, programInterface, pname, params);
}
unsigned int raia_gl_get_program_resource_index (unsigned int program, unsigned int programInterface, const char *name) {
    return glGetProgramResourceIndex(program, programInterface, name);
}
void raia_gl_get_program_resource_name (unsigned int program, unsigned int programInterface, unsigned int index, int bufSize, void *length, char *name) {
    glGetProgramResourceName(program, programInterface, index, bufSize, length, name);
}
void raia_gl_get_program_resource_iv (unsigned int program, unsigned int programInterface, unsigned int index, int propCount, const void *props, int bufSize, void *length, void *params) {
    glGetProgramResourceiv(program, programInterface, index, propCount, props, bufSize, length, params);
}
int raia_gl_get_program_resource_location (unsigned int program, unsigned int programInterface, const char *name) {
    return glGetProgramResourceLocation(program, programInterface, name);
}
void raia_gl_use_program_stages (unsigned int pipeline, unsigned int stages, unsigned int program) {
    glUseProgramStages(pipeline, stages, program);
}
void raia_gl_active_shader_program (unsigned int pipeline, unsigned int program) {
    glActiveShaderProgram(pipeline, program);
}
unsigned int raia_gl_create_shader_program_v (unsigned int type, int count, const char * const *strings) {
    return glCreateShaderProgramv(type, count, strings);
}
void raia_gl_bind_program_pipeline (unsigned int pipeline) {
    glBindProgramPipeline(pipeline);
}
void raia_gl_delete_program_pipelines (int n, const void *pipelines) {
    glDeleteProgramPipelines(n, pipelines);
}
void raia_gl_gen_program_pipelines (int n, void *pipelines) {
    glGenProgramPipelines(n, pipelines);
}
unsigned char raia_gl_is_program_pipeline (unsigned int pipeline) {
    return glIsProgramPipeline(pipeline);
}
void raia_gl_get_program_pipeline_iv (unsigned int pipeline, unsigned int pname, void *params) {
    glGetProgramPipelineiv(pipeline, pname, params);
}
void raia_gl_program_uniform_1i (unsigned int program, int location, int v0) {
    glProgramUniform1i(program, location, v0);
}
void raia_gl_program_uniform_2i (unsigned int program, int location, int v0, int v1) {
    glProgramUniform2i(program, location, v0, v1);
}
void raia_gl_program_uniform_3i (unsigned int program, int location, int v0, int v1, int v2) {
    glProgramUniform3i(program, location, v0, v1, v2);
}
void raia_gl_program_uniform_4i (unsigned int program, int location, int v0, int v1, int v2, int v3) {
    glProgramUniform4i(program, location, v0, v1, v2, v3);
}
void raia_gl_program_uniform_1ui (unsigned int program, int location, unsigned int v0) {
    glProgramUniform1ui(program, location, v0);
}
void raia_gl_program_uniform_2ui (unsigned int program, int location, unsigned int v0, unsigned int v1) {
    glProgramUniform2ui(program, location, v0, v1);
}
void raia_gl_program_uniform_3ui (unsigned int program, int location, unsigned int v0, unsigned int v1, unsigned int v2) {
    glProgramUniform3ui(program, location, v0, v1, v2);
}
void raia_gl_program_uniform_4ui (unsigned int program, int location, unsigned int v0, unsigned int v1, unsigned int v2, unsigned int v3) {
    glProgramUniform4ui(program, location, v0, v1, v2, v3);
}
void raia_gl_program_uniform_1f (unsigned int program, int location, float v0) {
    glProgramUniform1f(program, location, v0);
}
void raia_gl_program_uniform_2f (unsigned int program, int location, float v0, float v1) {
    glProgramUniform2f(program, location, v0, v1);
}
void raia_gl_program_uniform_3f (unsigned int program, int location, float v0, float v1, float v2) {
    glProgramUniform3f(program, location, v0, v1, v2);
}
void raia_gl_program_uniform_4f (unsigned int program, int location, float v0, float v1, float v2, float v3) {
    glProgramUniform4f(program, location, v0, v1, v2, v3);
}
void raia_gl_program_uniform_1iv (unsigned int program, int location, int count, const void *value) {
    glProgramUniform1iv(program, location, count, value);
}
void raia_gl_program_uniform_2iv (unsigned int program, int location, int count, const void *value) {
    glProgramUniform2iv(program, location, count, value);
}
void raia_gl_program_uniform_3iv (unsigned int program, int location, int count, const void *value) {
    glProgramUniform3iv(program, location, count, value);
}
void raia_gl_program_uniform_4iv (unsigned int program, int location, int count, const void *value) {
    glProgramUniform4iv(program, location, count, value);
}
void raia_gl_program_uniform_1uiv (unsigned int program, int location, int count, const void *value) {
    glProgramUniform1uiv(program, location, count, value);
}
void raia_gl_program_uniform_2uiv (unsigned int program, int location, int count, const void *value) {
    glProgramUniform2uiv(program, location, count, value);
}
void raia_gl_program_uniform_3uiv (unsigned int program, int location, int count, const void *value) {
    glProgramUniform3uiv(program, location, count, value);
}
void raia_gl_program_uniform_4uiv (unsigned int program, int location, int count, const void *value) {
    glProgramUniform4uiv(program, location, count, value);
}
void raia_gl_program_uniform_1fv (unsigned int program, int location, int count, const void *value) {
    glProgramUniform1fv(program, location, count, value);
}
void raia_gl_program_uniform_2fv (unsigned int program, int location, int count, const void *value) {
    glProgramUniform2fv(program, location, count, value);
}
void raia_gl_program_uniform_3fv (unsigned int program, int location, int count, const void *value) {
    glProgramUniform3fv(program, location, count, value);
}
void raia_gl_program_uniform_4fv (unsigned int program, int location, int count, const void *value) {
    glProgramUniform4fv(program, location, count, value);
}
void raia_gl_program_uniform_matrix_2fv (unsigned int program, int location, int count, unsigned char transpose, const void *value) {
    glProgramUniformMatrix2fv(program, location, count, transpose, value);
}
void raia_gl_program_uniform_matrix_3fv (unsigned int program, int location, int count, unsigned char transpose, const void *value) {
    glProgramUniformMatrix3fv(program, location, count, transpose, value);
}
void raia_gl_program_uniform_matrix_4fv (unsigned int program, int location, int count, unsigned char transpose, const void *value) {
    glProgramUniformMatrix4fv(program, location, count, transpose, value);
}
void raia_gl_program_uniform_matrix_2x3fv (unsigned int program, int location, int count, unsigned char transpose, const void *value) {
    glProgramUniformMatrix2x3fv(program, location, count, transpose, value);
}
void raia_gl_program_uniform_matrix_3x2fv (unsigned int program, int location, int count, unsigned char transpose, const void *value) {
    glProgramUniformMatrix3x2fv(program, location, count, transpose, value);
}
void raia_gl_program_uniform_matrix_2x4fv (unsigned int program, int location, int count, unsigned char transpose, const void *value) {
    glProgramUniformMatrix2x4fv(program, location, count, transpose, value);
}
void raia_gl_program_uniform_matrix_4x2fv (unsigned int program, int location, int count, unsigned char transpose, const void *value) {
    glProgramUniformMatrix4x2fv(program, location, count, transpose, value);
}
void raia_gl_program_uniform_matrix_3x4fv (unsigned int program, int location, int count, unsigned char transpose, const void *value) {
    glProgramUniformMatrix3x4fv(program, location, count, transpose, value);
}
void raia_gl_program_uniform_matrix_4x3fv (unsigned int program, int location, int count, unsigned char transpose, const void *value) {
    glProgramUniformMatrix4x3fv(program, location, count, transpose, value);
}
void raia_gl_validate_program_pipeline (unsigned int pipeline) {
    glValidateProgramPipeline(pipeline);
}
void raia_gl_get_program_pipeline_info_log (unsigned int pipeline, int bufSize, void *length, char *infoLog) {
    glGetProgramPipelineInfoLog(pipeline, bufSize, length, infoLog);
}
void raia_gl_bind_image_texture (unsigned int unit, unsigned int texture, int level, unsigned char layered, int layer, unsigned int access, unsigned int format) {
    glBindImageTexture(unit, texture, level, layered, layer, access, format);
}
void raia_gl_get_boolean_i_v (unsigned int target, unsigned int index, unsigned char *data) {
    glGetBooleani_v(target, index, data);
}
void raia_gl_memory_barrier (unsigned int barriers) {
    glMemoryBarrier(barriers);
}
void raia_gl_memory_barrier_by_region (unsigned int barriers) {
    glMemoryBarrierByRegion(barriers);
}
void raia_gl_tex_storage_2d_multisample (unsigned int target, int samples, unsigned int internalformat, int width, int height, unsigned char fixedsamplelocations) {
    glTexStorage2DMultisample(target, samples, internalformat, width, height, fixedsamplelocations);
}
void raia_gl_get_multisample_fv (unsigned int pname, unsigned int index, void *val) {
    glGetMultisamplefv(pname, index, val);
}
void raia_gl_sample_mask_i (unsigned int maskNumber, unsigned int mask) {
    glSampleMaski(maskNumber, mask);
}
void raia_gl_get_tex_level_parameter_iv (unsigned int target, int level, unsigned int pname, void *params) {
    glGetTexLevelParameteriv(target, level, pname, params);
}
void raia_gl_get_tex_level_parameter_fv (unsigned int target, int level, unsigned int pname, void *params) {
    glGetTexLevelParameterfv(target, level, pname, params);
}
void raia_gl_bind_vertex_buffer (unsigned int bindingindex, unsigned int buffer, int offset, int stride) {
    glBindVertexBuffer(bindingindex, buffer, offset, stride);
}
void raia_gl_vertex_attrib_format (unsigned int attribindex, int size, unsigned int type, unsigned char normalized, unsigned int relativeoffset) {
    glVertexAttribFormat(attribindex, size, type, normalized, relativeoffset);
}
void raia_gl_vertex_attrib_i_format (unsigned int attribindex, int size, unsigned int type, unsigned int relativeoffset) {
    glVertexAttribIFormat(attribindex, size, type, relativeoffset);
}
void raia_gl_vertex_attrib_binding (unsigned int attribindex, unsigned int bindingindex) {
    glVertexAttribBinding(attribindex, bindingindex);
}
void raia_gl_vertex_binding_divisor (unsigned int bindingindex, unsigned int divisor) {
    glVertexBindingDivisor(bindingindex, divisor);
}

// MARK: GL ES 3.2

void raia_gl_blend_barrier (void) {
    glBlendBarrier();
}
void raia_gl_copy_image_sub_data (unsigned int srcName, unsigned int srcTarget, int srcLevel, int srcX, int srcY, int srcZ, unsigned int dstName, unsigned int dstTarget, int dstLevel, int dstX, int dstY, int dstZ, int srcWidth, int srcHeight, int srcDepth) {
    glCopyImageSubData(srcName, srcTarget, srcLevel, srcX, srcY, srcZ, dstName, dstTarget, dstLevel, dstX, dstY, dstZ, srcWidth, srcHeight, srcDepth);
}
void raia_gl_debug_message_control (unsigned int source, unsigned int type, unsigned int severity, int count, const void *ids, unsigned char enabled) {
    glDebugMessageControl(source, type, severity, count, ids, enabled);
}
void raia_gl_debug_message_insert (unsigned int source, unsigned int type, unsigned int id, unsigned int severity, int length, const char *buf) {
    glDebugMessageInsert(source, type, id, severity, length, buf);
}
void raia_gl_debug_message_callback (void * callback, const void *userParam) {
    glDebugMessageCallback(callback, userParam);
}
unsigned int raia_gl_get_debug_message_log (unsigned int count, int bufSize, void *sources, void *types, void *ids, void *severities, void *lengths, char *messageLog) {
    return glGetDebugMessageLog(count, bufSize, sources, types, ids, severities, lengths, messageLog);
}
void raia_gl_push_debug_group (unsigned int source, unsigned int id, int length, const char *message) {
    glPushDebugGroup(source, id, length, message);
}
void raia_gl_pop_debug_group (void) {
    glPopDebugGroup();
}
void raia_gl_object_label (unsigned int identifier, unsigned int name, int length, const char *label) {
    glObjectLabel(identifier, name, length, label);
}
void raia_gl_get_object_label (unsigned int identifier, unsigned int name, int bufSize, void *length, char *label) {
    glGetObjectLabel(identifier, name, bufSize, length, label);
}
void raia_gl_object_ptr_label (const void *ptr, int length, const char *label) {
    glObjectPtrLabel(ptr, length, label);
}
void raia_gl_get_object_ptr_label (const void *ptr, int bufSize, void *length, char *label) {
    glGetObjectPtrLabel(ptr, bufSize, length, label);
}
void raia_gl_get_pointer_v (unsigned int pname, void **params) {
    glGetPointerv(pname, params);
}
void raia_gl_enable_i (unsigned int target, unsigned int index) {
    glEnablei(target, index);
}
void raia_gl_disable_i (unsigned int target, unsigned int index) {
    glDisablei(target, index);
}
void raia_gl_blend_equation_i (unsigned int buf, unsigned int mode) {
    glBlendEquationi(buf, mode);
}
void raia_gl_blend_equation_separate_i (unsigned int buf, unsigned int modeRGB, unsigned int modeAlpha) {
    glBlendEquationSeparatei(buf, modeRGB, modeAlpha);
}
void raia_gl_blend_func_i (unsigned int buf, unsigned int src, unsigned int dst) {
    glBlendFunci(buf, src, dst);
}
void raia_gl_blend_func_separate_i (unsigned int buf, unsigned int srcRGB, unsigned int dstRGB, unsigned int srcAlpha, unsigned int dstAlpha) {
    glBlendFuncSeparatei(buf, srcRGB, dstRGB, srcAlpha, dstAlpha);
}
void raia_gl_color_mask_i (unsigned int index, unsigned char r, unsigned char g, unsigned char b, unsigned char a) {
    glColorMaski(index, r, g, b, a);
}
unsigned char raia_gl_is_enabled_i (unsigned int target, unsigned int index) {
    return glIsEnabledi(target, index);
}
void raia_gl_draw_elements_base_vertex (unsigned int mode, int count, unsigned int type, const void *indices, int basevertex) {
    glDrawElementsBaseVertex(mode, count, type, indices, basevertex);
}
void raia_gl_draw_range_elements_base_vertex (unsigned int mode, unsigned int start, unsigned int end, int count, unsigned int type, const void *indices, int basevertex) {
    glDrawRangeElementsBaseVertex(mode, start, end, count, type, indices, basevertex);
}
void raia_gl_draw_elements_instanced_base_vertex (unsigned int mode, int count, unsigned int type, const void *indices, int instancecount, int basevertex) {
    glDrawElementsInstancedBaseVertex(mode, count, type, indices, instancecount, basevertex);
}
void raia_gl_framebuffer_texture (unsigned int target, unsigned int attachment, unsigned int texture, int level) {
    glFramebufferTexture(target, attachment, texture, level);
}
void raia_gl_primitive_bounding_box (float minX, float minY, float minZ, float minW, float maxX, float maxY, float maxZ, float maxW) {
    glPrimitiveBoundingBox(minX, minY, minZ, minW, maxX, maxY, maxZ, maxW);
}
unsigned int raia_gl_get_graphics_reset_status (void) {
    return glGetGraphicsResetStatus();
}
void raia_gl_read_n_pixels (int x, int y, int width, int height, unsigned int format, unsigned int type, int bufSize, void *data) {
    glReadnPixels(x, y, width, height, format, type, bufSize, data);
}
void raia_gl_get_n_uniform_fv (unsigned int program, int location, int bufSize, void *params) {
    glGetnUniformfv(program, location, bufSize, params);
}
void raia_gl_get_n_uniform_iv (unsigned int program, int location, int bufSize, void *params) {
    glGetnUniformiv(program, location, bufSize, params);
}
void raia_gl_get_n_uniform_uiv (unsigned int program, int location, int bufSize, void *params) {
    glGetnUniformuiv(program, location, bufSize, params);
}
void raia_gl_min_sample_shading (float value) {
    glMinSampleShading(value);
}
void raia_gl_patch_parameter_i (unsigned int pname, int value) {
    glPatchParameteri(pname, value);
}
void raia_gl_tex_parameter_iiv (unsigned int target, unsigned int pname, const void *params) {
    glTexParameterIiv(target, pname, params);
}
void raia_gl_tex_parameter_iuiv (unsigned int target, unsigned int pname, const void *params) {
    glTexParameterIuiv(target, pname, params);
}
void raia_gl_get_tex_parameter_iiv (unsigned int target, unsigned int pname, void *params) {
    glGetTexParameterIiv(target, pname, params);
}
void raia_gl_get_tex_parameter_iuiv (unsigned int target, unsigned int pname, void *params) {
    glGetTexParameterIuiv(target, pname, params);
}
void raia_gl_sampler_parameter_iiv (unsigned int sampler, unsigned int pname, const void *param) {
    glSamplerParameterIiv(sampler, pname, param);
}
void raia_gl_sampler_parameter_iuiv (unsigned int sampler, unsigned int pname, const void *param) {
    glSamplerParameterIuiv(sampler, pname, param);
}
void raia_gl_get_sampler_parameter_iiv (unsigned int sampler, unsigned int pname, void *params) {
    glGetSamplerParameterIiv(sampler, pname, params);
}
void raia_gl_get_sampler_parameter_iuiv (unsigned int sampler, unsigned int pname, void *params) {
    glGetSamplerParameterIuiv(sampler, pname, params);
}
void raia_gl_tex_buffer (unsigned int target, unsigned int internalformat, unsigned int buffer) {
    glTexBuffer(target, internalformat, buffer);
}
void raia_gl_tex_buffer_range (unsigned int target, unsigned int internalformat, unsigned int buffer, int offset, int size) {
    glTexBufferRange(target, internalformat, buffer, offset, size);
}
void raia_gl_tex_storage_3d_multisample (unsigned int target, int samples, unsigned int internalformat, int width, int height, int depth, unsigned char fixedsamplelocations) {
    glTexStorage3DMultisample(target, samples, internalformat, width, height, depth, fixedsamplelocations);
}