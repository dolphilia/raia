local ffi = require("ffi")

ffi.cdef[[
    typedef int32_t                khronos_int32_t;
    typedef uint32_t               khronos_uint32_t;
    typedef int64_t                khronos_int64_t;
    typedef uint64_t               khronos_uint64_t;
    typedef signed   char          khronos_int8_t;
    typedef unsigned char          khronos_uint8_t;
    typedef signed   short int     khronos_int16_t;
    typedef unsigned short int     khronos_uint16_t;
    typedef signed   long  int     khronos_intptr_t;
    typedef unsigned long  int     khronos_uintptr_t;
    typedef signed   long  int     khronos_ssize_t;
    typedef unsigned long  int     khronos_usize_t;
    typedef          float         khronos_float_t;
    typedef khronos_uint64_t       khronos_utime_nanoseconds_t;
    typedef khronos_int64_t        khronos_stime_nanoseconds_t;
    typedef khronos_int8_t GLbyte;
    typedef khronos_float_t GLclampf;
    typedef khronos_int32_t GLfixed;
    typedef khronos_int16_t GLshort;
    typedef khronos_uint16_t GLushort;
    typedef void GLvoid;
    typedef struct __GLsync *GLsync;
    typedef khronos_int64_t GLint64;
    typedef khronos_uint64_t GLuint64;
    typedef unsigned int GLenum;
    typedef unsigned int GLuint;
    typedef char GLchar;
    typedef khronos_float_t GLfloat;
    typedef khronos_ssize_t GLsizeiptr;
    typedef khronos_intptr_t GLintptr;
    typedef unsigned int GLbitfield;
    typedef int GLint;
    typedef unsigned char GLboolean;
    typedef int GLsizei;
    typedef khronos_uint8_t GLubyte;
    typedef void (*GLDEBUGPROC)(GLenum source,GLenum type,GLuint id,GLenum severity,GLsizei length,const GLchar *message,const void *userParam);
    //
    // GL ES 2.0
    //
    void raia_gl_active_texture (GLenum texture);
    void raia_gl_attach_shader (GLuint program, GLuint shader);
    void raia_gl_bind_attrib_location (GLuint program, GLuint index, const GLchar *name);
    void raia_gl_bind_buffer (GLenum target, GLuint buffer);
    void raia_gl_bind_framebuffer (GLenum target, GLuint framebuffer);
    void raia_gl_bind_renderbuffer (GLenum target, GLuint renderbuffer);
    void raia_gl_bind_texture (GLenum target, GLuint texture);
    void raia_gl_blend_color (GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
    void raia_gl_blend_equation (GLenum mode);
    void raia_gl_blend_equation_separate (GLenum modeRGB, GLenum modeAlpha);
    void raia_gl_blend_func (GLenum sfactor, GLenum dfactor);
    void raia_gl_blend_func_separate (GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
    void raia_gl_buffer_data (GLenum target, GLsizeiptr size, const void *data, GLenum usage);
    void raia_gl_buffer_sub_data (GLenum target, GLintptr offset, GLsizeiptr size, const void *data);
    GLenum raia_gl_check_framebuffer_status (GLenum target);
    void raia_gl_clear (GLbitfield mask);
    void raia_gl_clear_color (GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
    void raia_gl_clear_depth_f (GLfloat d);
    void raia_gl_clear_stencil (GLint s);
    void raia_gl_color_mask (GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
    void raia_gl_compile_shader (GLuint shader);
    void raia_gl_compressed_tex_image_2d (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void *data);
    void raia_gl_compressed_tex_sub_image_2d (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *data);
    void raia_gl_copy_tex_image_2d (GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
    void raia_gl_copy_tex_sub_image_2d (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
    GLuint raia_gl_create_program (void);
    GLuint raia_gl_create_shader (GLenum type);
    void raia_gl_cull_face (GLenum mode);
    void raia_gl_delete_buffers (GLsizei n, const GLuint *buffers);
    void raia_gl_delete_framebuffers (GLsizei n, const GLuint *framebuffers);
    void raia_gl_delete_program (GLuint program);
    void raia_gl_delete_renderbuffers (GLsizei n, const GLuint *renderbuffers);
    void raia_gl_delete_shader (GLuint shader);
    void raia_gl_delete_textures (GLsizei n, const GLuint *textures);
    void raia_gl_depth_func (GLenum func);
    void raia_gl_depth_mask (GLboolean flag);
    void raia_gl_depth_range_f (GLfloat n, GLfloat f);
    void raia_gl_detach_shader (GLuint program, GLuint shader);
    void raia_gl_disable (GLenum cap);
    void raia_gl_disable_vertex_attrib_array (GLuint index);
    void raia_gl_draw_arrays (GLenum mode, GLint first, GLsizei count);
    void raia_gl_draw_elements (GLenum mode, GLsizei count, GLenum type, const void *indices);
    void raia_gl_enable (GLenum cap);
    void raia_gl_enable_vertex_attrib_array (GLuint index);
    void raia_gl_finish (void);
    void raia_gl_flush (void);
    void raia_gl_framebuffer_renderbuffer (GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
    void raia_gl_framebuffer_texture_2d (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
    void raia_gl_front_face (GLenum mode);
    void raia_gl_gen_buffers (GLsizei n, GLuint *buffers);
    void raia_gl_generate_mipmap (GLenum target);
    void raia_gl_gen_framebuffers (GLsizei n, GLuint *framebuffers);
    void raia_gl_gen_renderbuffers (GLsizei n, GLuint *renderbuffers);
    void raia_gl_gen_textures (GLsizei n, GLuint *textures);
    void raia_gl_get_active_attrib (GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name);
    void raia_gl_get_active_uniform (GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name);
    void raia_gl_get_attached_shaders (GLuint program, GLsizei maxCount, GLsizei *count, GLuint *shaders);
    GLint raia_gl_get_attrib_location (GLuint program, const GLchar *name);
    void raia_gl_get_boolean_v (GLenum pname, GLboolean *data);
    void raia_gl_get_buffer_parameter_iv (GLenum target, GLenum pname, GLint *params);
    GLenum raia_gl_get_error (void);
    void raia_gl_get_float_v (GLenum pname, GLfloat *data);
    void raia_gl_get_framebuffer_attachment_parameter_iv (GLenum target, GLenum attachment, GLenum pname, GLint *params);
    void raia_gl_get_integer_v (GLenum pname, GLint *data);
    void raia_gl_get_program_iv (GLuint program, GLenum pname, GLint *params);
    void raia_gl_get_program_info_log (GLuint program, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
    void raia_gl_get_renderbuffer_parameter_iv (GLenum target, GLenum pname, GLint *params);
    void raia_gl_get_shader_iv (GLuint shader, GLenum pname, GLint *params);
    void raia_gl_get_shader_info_log (GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
    void raia_gl_get_shader_precision_format (GLenum shadertype, GLenum precisiontype, GLint *range, GLint *precision);
    void raia_gl_get_shader_source (GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *source);
    const GLubyte *raia_gl_get_string (GLenum name);
    void raia_gl_get_tex_parameter_fv (GLenum target, GLenum pname, GLfloat *params);
    void raia_gl_get_tex_parameter_iv (GLenum target, GLenum pname, GLint *params);
    void raia_gl_get_uniform_fv (GLuint program, GLint location, GLfloat *params);
    void raia_gl_get_uniform_iv (GLuint program, GLint location, GLint *params);
    GLint raia_gl_get_uniform_location (GLuint program, const GLchar *name);
    void raia_gl_get_vertex_attrib_fv (GLuint index, GLenum pname, GLfloat *params);
    void raia_gl_get_vertex_attrib_iv (GLuint index, GLenum pname, GLint *params);
    void raia_gl_get_vertex_attrib_pointer_v (GLuint index, GLenum pname, void **pointer);
    void raia_gl_hint (GLenum target, GLenum mode);
    GLboolean raia_gl_is_buffer (GLuint buffer);
    GLboolean raia_gl_is_enabled (GLenum cap);
    GLboolean raia_gl_is_framebuffer (GLuint framebuffer);
    GLboolean raia_gl_is_program (GLuint program);
    GLboolean raia_gl_is_renderbuffer (GLuint renderbuffer);
    GLboolean raia_gl_is_shader (GLuint shader);
    GLboolean raia_gl_is_texture (GLuint texture);
    void raia_gl_line_width (GLfloat width);
    void raia_gl_link_program (GLuint program);
    void raia_gl_pixel_store_i (GLenum pname, GLint param);
    void raia_gl_polygon_offset (GLfloat factor, GLfloat units);
    void raia_gl_read_pixels (GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void *pixels);
    void raia_gl_release_shader_compiler (void);
    void raia_gl_renderbuffer_storage (GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
    void raia_gl_sample_coverage (GLfloat value, GLboolean invert);
    void raia_gl_scissor (GLint x, GLint y, GLsizei width, GLsizei height);
    void raia_gl_shader_binary (GLsizei count, const GLuint *shaders, GLenum binaryformat, const void *binary, GLsizei length);
    void raia_gl_shader_source (GLuint shader, GLsizei count, const GLchar *const*string, const GLint *length);
    void raia_gl_stencil_func (GLenum func, GLint ref, GLuint mask);
    void raia_gl_stencil_func_separate (GLenum face, GLenum func, GLint ref, GLuint mask);
    void raia_gl_stencil_mask (GLuint mask);
    void raia_gl_stencil_mask_separate (GLenum face, GLuint mask);
    void raia_gl_stencil_op (GLenum fail, GLenum zfail, GLenum zpass);
    void raia_gl_stencil_op_separate (GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass);
    void raia_gl_tex_image_2d (GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void *pixels);
    void raia_gl_tex_parameter_f (GLenum target, GLenum pname, GLfloat param);
    void raia_gl_tex_parameter_fv (GLenum target, GLenum pname, const GLfloat *params);
    void raia_gl_tex_parameter_i (GLenum target, GLenum pname, GLint param);
    void raia_gl_tex_parameter_iv (GLenum target, GLenum pname, const GLint *params);
    void raia_gl_tex_sub_image_2d (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels);
    void raia_gl_uniform_1f (GLint location, GLfloat v0);
    void raia_gl_uniform_1fv (GLint location, GLsizei count, const GLfloat *value);
    void raia_gl_uniform_1i (GLint location, GLint v0);
    void raia_gl_uniform_1iv (GLint location, GLsizei count, const GLint *value);
    void raia_gl_uniform_2f (GLint location, GLfloat v0, GLfloat v1);
    void raia_gl_uniform_2fv (GLint location, GLsizei count, const GLfloat *value);
    void raia_gl_uniform_2i (GLint location, GLint v0, GLint v1);
    void raia_gl_uniform_2iv (GLint location, GLsizei count, const GLint *value);
    void raia_gl_uniform_3f (GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
    void raia_gl_uniform_3fv (GLint location, GLsizei count, const GLfloat *value);
    void raia_gl_uniform_3i (GLint location, GLint v0, GLint v1, GLint v2);
    void raia_gl_uniform_3iv (GLint location, GLsizei count, const GLint *value);
    void raia_gl_uniform_4f (GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
    void raia_gl_uniform_4fv (GLint location, GLsizei count, const GLfloat *value);
    void raia_gl_uniform_4i (GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
    void raia_gl_uniform_4iv (GLint location, GLsizei count, const GLint *value);
    void raia_gl_uniform_matrix_2fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
    void raia_gl_uniform_matrix_3fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
    void raia_gl_uniform_matrix_4fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
    void raia_gl_use_program (GLuint program);
    void raia_gl_validate_program (GLuint program);
    void raia_gl_vertex_attrib_1f (GLuint index, GLfloat x);
    void raia_gl_vertex_attrib_1fv (GLuint index, const GLfloat *v);
    void raia_gl_vertex_attrib_2f (GLuint index, GLfloat x, GLfloat y);
    void raia_gl_vertex_attrib_2fv (GLuint index, const GLfloat *v);
    void raia_gl_vertex_attrib_3f (GLuint index, GLfloat x, GLfloat y, GLfloat z);
    void raia_gl_vertex_attrib_3fv (GLuint index, const GLfloat *v);
    void raia_gl_vertex_attrib_4f (GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
    void raia_gl_vertex_attrib_4fv (GLuint index, const GLfloat *v);
    void raia_gl_vertex_attrib_pointer (GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *pointer);
    void raia_gl_viewport (GLint x, GLint y, GLsizei width, GLsizei height);
    //
    // GL ES 3.0
    //
    void raia_gl_read_buffer (GLenum src);
    void raia_gl_draw_range_elements (GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices);
    void raia_gl_tex_image_3d (GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void *pixels);
    void raia_gl_tex_sub_image_3d (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels);
    void raia_gl_copy_tex_sub_image_3d (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
    void raia_gl_compressed_tex_image_3d (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void *data);
    void raia_gl_compressed_tex_sub_image_3d (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *data);
    void raia_gl_gen_queries (GLsizei n, GLuint *ids);
    void raia_gl_delete_queries (GLsizei n, const GLuint *ids);
    GLboolean raia_gl_is_query (GLuint id);
    void raia_gl_begin_query (GLenum target, GLuint id);
    void raia_gl_end_query (GLenum target);
    void raia_gl_get_query_iv (GLenum target, GLenum pname, GLint *params);
    void raia_gl_get_query_object_uiv (GLuint id, GLenum pname, GLuint *params);
    GLboolean raia_gl_unmap_buffer (GLenum target);
    void raia_gl_get_buffer_pointer_v (GLenum target, GLenum pname, void **params);
    void raia_gl_draw_buffers (GLsizei n, const GLenum *bufs);
    void raia_gl_uniform_matrix_2x3fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
    void raia_gl_uniform_matrix_3x2fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
    void raia_gl_uniform_matrix_2x4fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
    void raia_gl_uniform_matrix_4x2fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
    void raia_gl_uniform_matrix_3x4fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
    void raia_gl_uniform_matrix_4x3fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
    void raia_gl_blit_framebuffer (GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
    void raia_gl_renderbuffer_storage_multisample (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
    void raia_gl_framebuffer_texture_layer (GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
    void *raia_gl_map_buffer_range (GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access);
    void raia_gl_flush_mapped_buffer_range (GLenum target, GLintptr offset, GLsizeiptr length);
    void raia_gl_bind_vertex_array (GLuint array);
    void raia_gl_delete_vertex_arrays (GLsizei n, const GLuint *arrays);
    void raia_gl_gen_vertex_arrays (GLsizei n, GLuint *arrays);
    GLboolean raia_gl_is_vertex_array (GLuint array);
    void raia_gl_get_integer_i_v (GLenum target, GLuint index, GLint *data);
    void raia_gl_begin_transform_feedback (GLenum primitiveMode);
    void raia_gl_end_transform_feedback (void);
    void raia_gl_bind_buffer_range (GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
    void raia_gl_bind_buffer_base (GLenum target, GLuint index, GLuint buffer);
    void raia_gl_transform_feedback_varyings (GLuint program, GLsizei count, const GLchar *const*varyings, GLenum bufferMode);
    void raia_gl_get_transform_feedback_varying (GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLsizei *size, GLenum *type, GLchar *name);
    void raia_gl_vertex_attrib_i_pointer (GLuint index, GLint size, GLenum type, GLsizei stride, const void *pointer);
    void raia_gl_get_vertex_attrib_iiv (GLuint index, GLenum pname, GLint *params);
    void raia_gl_get_vertex_attrib_iuiv (GLuint index, GLenum pname, GLuint *params);
    void raia_gl_vertex_attrib_i4i (GLuint index, GLint x, GLint y, GLint z, GLint w);
    void raia_gl_vertex_attrib_i4ui (GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
    void raia_gl_vertex_attrib_i4iv (GLuint index, const GLint *v);
    void raia_gl_vertex_attrib_i4uiv (GLuint index, const GLuint *v);
    void raia_gl_get_uniform_uiv (GLuint program, GLint location, GLuint *params);
    GLint raia_gl_get_frag_data_location (GLuint program, const GLchar *name);
    void raia_gl_uniform_1ui (GLint location, GLuint v0);
    void raia_gl_uniform_2ui (GLint location, GLuint v0, GLuint v1);
    void raia_gl_uniform_3ui (GLint location, GLuint v0, GLuint v1, GLuint v2);
    void raia_gl_uniform_4ui (GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
    void raia_gl_uniform_1uiv (GLint location, GLsizei count, const GLuint *value);
    void raia_gl_uniform_2uiv (GLint location, GLsizei count, const GLuint *value);
    void raia_gl_uniform_3uiv (GLint location, GLsizei count, const GLuint *value);
    void raia_gl_uniform_4uiv (GLint location, GLsizei count, const GLuint *value);
    void raia_gl_clear_buffer_iv (GLenum buffer, GLint drawbuffer, const GLint *value);
    void raia_gl_clear_buffer_uiv (GLenum buffer, GLint drawbuffer, const GLuint *value);
    void raia_gl_clear_buffer_fv (GLenum buffer, GLint drawbuffer, const GLfloat *value);
    void raia_gl_clear_buffer_fi (GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil);
    const GLubyte *raia_gl_get_string_i (GLenum name, GLuint index);
    void raia_gl_copy_buffer_sub_data (GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
    void raia_gl_get_uniform_indices (GLuint program, GLsizei uniformCount, const GLchar *const*uniformNames, GLuint *uniformIndices);
    void raia_gl_get_active_uniforms_iv (GLuint program, GLsizei uniformCount, const GLuint *uniformIndices, GLenum pname, GLint *params);
    GLuint raia_gl_get_uniform_block_index (GLuint program, const GLchar *uniformBlockName);
    void raia_gl_get_active_uniform_block_iv (GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint *params);
    void raia_gl_get_active_uniform_block_name (GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformBlockName);
    void raia_gl_uniform_block_binding (GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding);
    void raia_gl_draw_arrays_instanced (GLenum mode, GLint first, GLsizei count, GLsizei instancecount);
    void raia_gl_draw_elements_instanced (GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount);
    GLsync raia_gl_fence_sync (GLenum condition, GLbitfield flags);
    GLboolean raia_gl_is_sync (GLsync sync);
    void raia_gl_delete_sync (GLsync sync);
    GLenum raia_gl_client_wait_sync (GLsync sync, GLbitfield flags, GLuint64 timeout);
    void raia_gl_wait_sync (GLsync sync, GLbitfield flags, GLuint64 timeout);
    void raia_gl_get_integer_64v (GLenum pname, GLint64 *data);
    void raia_gl_get_sync_iv (GLsync sync, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *values);
    void raia_gl_get_integer_64i_v (GLenum target, GLuint index, GLint64 *data);
    void raia_gl_get_buffer_parameter_i64v (GLenum target, GLenum pname, GLint64 *params);
    void raia_gl_gen_samplers (GLsizei count, GLuint *samplers);
    void raia_gl_delete_samplers (GLsizei count, const GLuint *samplers);
    GLboolean raia_gl_is_sampler (GLuint sampler);
    void raia_gl_bind_sampler (GLuint unit, GLuint sampler);
    void raia_gl_sampler_parameter_i (GLuint sampler, GLenum pname, GLint param);
    void raia_gl_sampler_parameter_iv (GLuint sampler, GLenum pname, const GLint *param);
    void raia_gl_sampler_parameter_f (GLuint sampler, GLenum pname, GLfloat param);
    void raia_gl_sampler_parameter_fv (GLuint sampler, GLenum pname, const GLfloat *param);
    void raia_gl_get_sampler_parameter_iv (GLuint sampler, GLenum pname, GLint *params);
    void raia_gl_get_sampler_parameter_fv (GLuint sampler, GLenum pname, GLfloat *params);
    void raia_gl_vertex_attrib_divisor (GLuint index, GLuint divisor);
    void raia_gl_bind_transform_feedback (GLenum target, GLuint id);
    void raia_gl_delete_transform_feedbacks (GLsizei n, const GLuint *ids);
    void raia_gl_gen_transform_feedbacks (GLsizei n, GLuint *ids);
    GLboolean raia_gl_is_transform_feedback (GLuint id);
    void raia_gl_pause_transform_feedback (void);
    void raia_gl_resume_transform_feedback (void);
    void raia_gl_get_program_binary (GLuint program, GLsizei bufSize, GLsizei *length, GLenum *binaryFormat, void *binary);
    void raia_gl_program_binary (GLuint program, GLenum binaryFormat, const void *binary, GLsizei length);
    void raia_gl_program_parameter_i (GLuint program, GLenum pname, GLint value);
    void raia_gl_invalidate_framebuffer (GLenum target, GLsizei numAttachments, const GLenum *attachments);
    void raia_gl_invalidate_sub_framebuffer (GLenum target, GLsizei numAttachments, const GLenum *attachments, GLint x, GLint y, GLsizei width, GLsizei height);
    void raia_gl_tex_storage_2d (GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
    void raia_gl_tex_storage_3d (GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
    void raia_gl_get_internal_format_iv (GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint *params);
    //
    // GL ES 3.1
    //
    void raia_gl_dispatch_compute (GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z);
    void raia_gl_dispatch_compute_indirect (GLintptr indirect);
    void raia_gl_draw_arrays_indirect (GLenum mode, const void *indirect);
    void raia_gl_draw_elements_indirect (GLenum mode, GLenum type, const void *indirect);
    void raia_gl_framebuffer_parameter_i (GLenum target, GLenum pname, GLint param);
    void raia_gl_get_framebuffer_parameter_iv (GLenum target, GLenum pname, GLint *params);
    void raia_gl_get_program_interface_iv (GLuint program, GLenum programInterface, GLenum pname, GLint *params);
    GLuint raia_gl_get_program_resource_index (GLuint program, GLenum programInterface, const GLchar *name);
    void raia_gl_get_program_resource_name (GLuint program, GLenum programInterface, GLuint index, GLsizei bufSize, GLsizei *length, GLchar *name);
    void raia_gl_get_program_resource_iv (GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, const GLenum *props, GLsizei bufSize, GLsizei *length, GLint *params);
    GLint raia_gl_get_program_resource_location (GLuint program, GLenum programInterface, const GLchar *name);
    void raia_gl_use_program_stages (GLuint pipeline, GLbitfield stages, GLuint program);
    void raia_gl_active_shader_program (GLuint pipeline, GLuint program);
    GLuint raia_gl_create_shader_program_v (GLenum type, GLsizei count, const GLchar *const*strings);
    void raia_gl_bind_program_pipeline (GLuint pipeline);
    void raia_gl_delete_program_pipelines (GLsizei n, const GLuint *pipelines);
    void raia_gl_gen_program_pipelines (GLsizei n, GLuint *pipelines);
    GLboolean raia_gl_is_program_pipeline (GLuint pipeline);
    void raia_gl_get_program_pipeline_iv (GLuint pipeline, GLenum pname, GLint *params);
    void raia_gl_program_uniform_1i (GLuint program, GLint location, GLint v0);
    void raia_gl_program_uniform_2i (GLuint program, GLint location, GLint v0, GLint v1);
    void raia_gl_program_uniform_3i (GLuint program, GLint location, GLint v0, GLint v1, GLint v2);
    void raia_gl_program_uniform_4i (GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
    void raia_gl_program_uniform_1ui (GLuint program, GLint location, GLuint v0);
    void raia_gl_program_uniform_2ui (GLuint program, GLint location, GLuint v0, GLuint v1);
    void raia_gl_program_uniform_3ui (GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2);
    void raia_gl_program_uniform_4ui (GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
    void raia_gl_program_uniform_1f (GLuint program, GLint location, GLfloat v0);
    void raia_gl_program_uniform_2f (GLuint program, GLint location, GLfloat v0, GLfloat v1);
    void raia_gl_program_uniform_3f (GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
    void raia_gl_program_uniform_4f (GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
    void raia_gl_program_uniform_1iv (GLuint program, GLint location, GLsizei count, const GLint *value);
    void raia_gl_program_uniform_2iv (GLuint program, GLint location, GLsizei count, const GLint *value);
    void raia_gl_program_uniform_3iv (GLuint program, GLint location, GLsizei count, const GLint *value);
    void raia_gl_program_uniform_4iv (GLuint program, GLint location, GLsizei count, const GLint *value);
    void raia_gl_program_uniform_1uiv (GLuint program, GLint location, GLsizei count, const GLuint *value);
    void raia_gl_program_uniform_2uiv (GLuint program, GLint location, GLsizei count, const GLuint *value);
    void raia_gl_program_uniform_3uiv (GLuint program, GLint location, GLsizei count, const GLuint *value);
    void raia_gl_program_uniform_4uiv (GLuint program, GLint location, GLsizei count, const GLuint *value);
    void raia_gl_program_uniform_1fv (GLuint program, GLint location, GLsizei count, const GLfloat *value);
    void raia_gl_program_uniform_2fv (GLuint program, GLint location, GLsizei count, const GLfloat *value);
    void raia_gl_program_uniform_3fv (GLuint program, GLint location, GLsizei count, const GLfloat *value);
    void raia_gl_program_uniform_4fv (GLuint program, GLint location, GLsizei count, const GLfloat *value);
    void raia_gl_program_uniform_matrix_2fv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
    void raia_gl_program_uniform_matrix_3fv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
    void raia_gl_program_uniform_matrix_4fv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
    void raia_gl_program_uniform_matrix_2x3fv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
    void raia_gl_program_uniform_matrix_3x2fv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
    void raia_gl_program_uniform_matrix_2x4fv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
    void raia_gl_program_uniform_matrix_4x2fv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
    void raia_gl_program_uniform_matrix_3x4fv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
    void raia_gl_program_uniform_matrix_4x3fv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
    void raia_gl_validate_program_pipeline (GLuint pipeline);
    void raia_gl_get_program_pipeline_info_log (GLuint pipeline, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
    void raia_gl_bind_image_texture (GLuint unit, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLenum format);
    void raia_gl_get_boolean_i_v (GLenum target, GLuint index, GLboolean *data);
    void raia_gl_memory_barrier (GLbitfield barriers);
    void raia_gl_memory_barrier_by_region (GLbitfield barriers);
    void raia_gl_tex_storage_2d_multisample (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
    void raia_gl_get_multisample_fv (GLenum pname, GLuint index, GLfloat *val);
    void raia_gl_sample_mask_i (GLuint maskNumber, GLbitfield mask);
    void raia_gl_get_tex_level_parameter_iv (GLenum target, GLint level, GLenum pname, GLint *params);
    void raia_gl_get_tex_level_parameter_fv (GLenum target, GLint level, GLenum pname, GLfloat *params);
    void raia_gl_bind_vertex_buffer (GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
    void raia_gl_vertex_attrib_format (GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
    void raia_gl_vertex_attrib_i_format (GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
    void raia_gl_vertex_attrib_binding (GLuint attribindex, GLuint bindingindex);
    void raia_gl_vertex_binding_divisor (GLuint bindingindex, GLuint divisor);
    //
    // GL ES 3.2
    //
    void raia_gl_blend_barrier (void);
    void raia_gl_copy_image_sub_data (GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth);
    void raia_gl_debug_message_control (GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint *ids, GLboolean enabled);
    void raia_gl_debug_message_insert (GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *buf);
    void raia_gl_debug_message_callback (GLDEBUGPROC callback, const void *userParam);
    GLuint raia_gl_get_debug_message_log (GLuint count, GLsizei bufSize, GLenum *sources, GLenum *types, GLuint *ids, GLenum *severities, GLsizei *lengths, GLchar *messageLog);
    void raia_gl_push_debug_group (GLenum source, GLuint id, GLsizei length, const GLchar *message);
    void raia_gl_pop_debug_group (void);
    void raia_gl_object_label (GLenum identifier, GLuint name, GLsizei length, const GLchar *label);
    void raia_gl_get_object_label (GLenum identifier, GLuint name, GLsizei bufSize, GLsizei *length, GLchar *label);
    void raia_gl_object_ptr_label (const void *ptr, GLsizei length, const GLchar *label);
    void raia_gl_get_object_ptr_label (const void *ptr, GLsizei bufSize, GLsizei *length, GLchar *label);
    void raia_gl_get_pointer_v (GLenum pname, void **params);
    void raia_gl_enable_i (GLenum target, GLuint index);
    void raia_gl_disable_i (GLenum target, GLuint index);
    void raia_gl_blend_equation_i (GLuint buf, GLenum mode);
    void raia_gl_blend_equation_separate_i (GLuint buf, GLenum modeRGB, GLenum modeAlpha);
    void raia_gl_blend_func_i (GLuint buf, GLenum src, GLenum dst);
    void raia_gl_blend_func_separate_i (GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
    void raia_gl_color_mask_i (GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a);
    GLboolean raia_gl_is_enabled_i (GLenum target, GLuint index);
    void raia_gl_draw_elements_base_vertex (GLenum mode, GLsizei count, GLenum type, const void *indices, GLint basevertex);
    void raia_gl_draw_range_elements_base_vertex (GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices, GLint basevertex);
    void raia_gl_draw_elements_instanced_base_vertex (GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLint basevertex);
    void raia_gl_framebuffer_texture (GLenum target, GLenum attachment, GLuint texture, GLint level);
    void raia_gl_primitive_bounding_box (GLfloat minX, GLfloat minY, GLfloat minZ, GLfloat minW, GLfloat maxX, GLfloat maxY, GLfloat maxZ, GLfloat maxW);
    GLenum raia_gl_get_graphics_reset_status (void);
    void raia_gl_read_n_pixels (GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, void *data);
    void raia_gl_get_n_uniform_fv (GLuint program, GLint location, GLsizei bufSize, GLfloat *params);
    void raia_gl_get_n_uniform_iv (GLuint program, GLint location, GLsizei bufSize, GLint *params);
    void raia_gl_get_n_uniform_uiv (GLuint program, GLint location, GLsizei bufSize, GLuint *params);
    void raia_gl_min_sample_shading (GLfloat value);
    void raia_gl_patch_parameter_i (GLenum pname, GLint value);
    void raia_gl_tex_parameter_iiv (GLenum target, GLenum pname, const GLint *params);
    void raia_gl_tex_parameter_iuiv (GLenum target, GLenum pname, const GLuint *params);
    void raia_gl_get_tex_parameter_iiv (GLenum target, GLenum pname, GLint *params);
    void raia_gl_get_tex_parameter_iuiv (GLenum target, GLenum pname, GLuint *params);
    void raia_gl_sampler_parameter_iiv (GLuint sampler, GLenum pname, const GLint *param);
    void raia_gl_sampler_parameter_iuiv (GLuint sampler, GLenum pname, const GLuint *param);
    void raia_gl_get_sampler_parameter_iiv (GLuint sampler, GLenum pname, GLint *params);
    void raia_gl_get_sampler_parameter_iuiv (GLuint sampler, GLenum pname, GLuint *params);
    void raia_gl_tex_buffer (GLenum target, GLenum internalformat, GLuint buffer);
    void raia_gl_tex_buffer_range (GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size);
    void raia_gl_tex_storage_3d_multisample (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
    // (代替関数);
    const char *raia_gl_viewport_alt(const char *s);
    const char *raia_gl_clear_color_alt(const char *s);
    const char *raia_gl_clear_alt(const char *s);
    const char *raia_gl_use_program_alt(const char *s);
    const char *raia_gl_vertex_attrib_pointer_alt(const char *s);
    const char *raia_gl_enable_vertex_attrib_array_alt(const char *s);
    const char *raia_gl_tex_image_2d_alt(const char *s);
    const char *raia_gl_active_texture_alt(const char *s);
    const char *raia_gl_bind_texture_alt(const char *s);
    const char *raia_gl_uniform_1i_alt(const char *s);
    const char *raia_gl_draw_elements_alt(const char *s);
    const char *raia_gl_create_shader_alt(const char *s);
    const char *raia_gl_shader_source_alt(const char *s);
    const char *raia_gl_compile_shader_alt(const char *s);
    const char *raia_gl_get_shader_iv_alt(const char *s);
    const char *raia_gl_create_program_alt(const char *s);
    const char *raia_gl_attach_shader_alt(const char *s);
    const char *raia_gl_delete_shader_alt(const char *s);
    const char *raia_gl_link_program_alt(const char *s);
    const char *raia_gl_pixel_store_i_alt(const char *s);
    const char *raia_gl_gen_textures_alt(const char *s);
    const char *raia_gl_tex_parameter_i_alt(const char *s);
    const char *raia_gl_get_attrib_location_alt(const char *s);
    const char *raia_gl_get_uniform_location_alt(const char *s);
    const char *raia_gl_gen_vertex_arrays_alt(const char *s);
    const char *raia_gl_gen_buffers_alt(const char *s);
    const char *raia_gl_bind_vertex_array_alt(const char *s);
    const char *raia_gl_bind_buffer_alt(const char *s);
    const char *raia_gl_buffer_data_alt(const char *s);
    const char *raia_gl_delete_vertex_arrays_alt(const char *s);
    const char *raia_gl_delete_buffers_alt(const char *s);
    const char *raia_gl_delete_textures_alt(const char *s);
]]

local lib = ffi.load("raia_gles")
local GLES = {}

-- GL ES 2.0

GLES.DEPTH_BUFFER_BIT = 0x00000100
GLES.STENCIL_BUFFER_BIT = 0x00000400
GLES.COLOR_BUFFER_BIT = 0x00004000
GLES.FALSE = 0
GLES.TRUE = 1
GLES.POINTS = 0x0000
GLES.LINES = 0x0001
GLES.LINE_LOOP = 0x0002
GLES.LINE_STRIP = 0x0003
GLES.TRIANGLES = 0x0004
GLES.TRIANGLE_STRIP = 0x0005
GLES.TRIANGLE_FAN = 0x0006
GLES.ZERO = 0
GLES.ONE = 1
GLES.SRC_COLOR = 0x0300
GLES.ONE_MINUS_SRC_COLOR = 0x0301
GLES.SRC_ALPHA = 0x0302
GLES.ONE_MINUS_SRC_ALPHA = 0x0303
GLES.DST_ALPHA = 0x0304
GLES.ONE_MINUS_DST_ALPHA = 0x0305
GLES.DST_COLOR = 0x0306
GLES.ONE_MINUS_DST_COLOR = 0x0307
GLES.SRC_ALPHA_SATURATE = 0x0308
GLES.FUNC_ADD = 0x8006
GLES.BLEND_EQUATION = 0x8009
GLES.BLEND_EQUATION_RGB = 0x8009
GLES.BLEND_EQUATION_ALPHA = 0x883D
GLES.FUNC_SUBTRACT = 0x800A
GLES.FUNC_REVERSE_SUBTRACT = 0x800B
GLES.BLEND_DST_RGB = 0x80C8
GLES.BLEND_SRC_RGB = 0x80C9
GLES.BLEND_DST_ALPHA = 0x80CA
GLES.BLEND_SRC_ALPHA = 0x80CB
GLES.CONSTANT_COLOR = 0x8001
GLES.ONE_MINUS_CONSTANT_COLOR = 0x8002
GLES.CONSTANT_ALPHA = 0x8003
GLES.ONE_MINUS_CONSTANT_ALPHA = 0x8004
GLES.BLEND_COLOR = 0x8005
GLES.ARRAY_BUFFER = 0x8892
GLES.ELEMENT_ARRAY_BUFFER = 0x8893
GLES.ARRAY_BUFFER_BINDING = 0x8894
GLES.ELEMENT_ARRAY_BUFFER_BINDING = 0x8895
GLES.STREAM_DRAW = 0x88E0
GLES.STATIC_DRAW = 0x88E4
GLES.DYNAMIC_DRAW = 0x88E8
GLES.BUFFER_SIZE = 0x8764
GLES.BUFFER_USAGE = 0x8765
GLES.CURRENT_VERTEX_ATTRIB = 0x8626
GLES.FRONT = 0x0404
GLES.BACK = 0x0405
GLES.FRONT_AND_BACK = 0x0408
GLES.TEXTURE_2D = 0x0DE1
GLES.CULL_FACE = 0x0B44
GLES.BLEND = 0x0BE2
GLES.DITHER = 0x0BD0
GLES.STENCIL_TEST = 0x0B90
GLES.DEPTH_TEST = 0x0B71
GLES.SCISSOR_TEST = 0x0C11
GLES.POLYGON_OFFSET_FILL = 0x8037
GLES.SAMPLE_ALPHA_TO_COVERAGE = 0x809E
GLES.SAMPLE_COVERAGE = 0x80A0
GLES.NO_ERROR = 0
GLES.INVALID_ENUM = 0x0500
GLES.INVALID_VALUE = 0x0501
GLES.INVALID_OPERATION = 0x0502
GLES.OUT_OF_MEMORY = 0x0505
GLES.CW = 0x0900
GLES.CCW = 0x0901
GLES.LINE_WIDTH = 0x0B21
GLES.ALIASED_POINT_SIZE_RANGE = 0x846D
GLES.ALIASED_LINE_WIDTH_RANGE = 0x846E
GLES.CULL_FACE_MODE = 0x0B45
GLES.FRONT_FACE = 0x0B46
GLES.DEPTH_RANGE = 0x0B70
GLES.DEPTH_WRITEMASK = 0x0B72
GLES.DEPTH_CLEAR_VALUE = 0x0B73
GLES.DEPTH_FUNC = 0x0B74
GLES.STENCIL_CLEAR_VALUE = 0x0B91
GLES.STENCIL_FUNC = 0x0B92
GLES.STENCIL_FAIL = 0x0B94
GLES.STENCIL_PASS_DEPTH_FAIL = 0x0B95
GLES.STENCIL_PASS_DEPTH_PASS = 0x0B96
GLES.STENCIL_REF = 0x0B97
GLES.STENCIL_VALUE_MASK = 0x0B93
GLES.STENCIL_WRITEMASK = 0x0B98
GLES.STENCIL_BACK_FUNC = 0x8800
GLES.STENCIL_BACK_FAIL = 0x8801
GLES.STENCIL_BACK_PASS_DEPTH_FAIL = 0x8802
GLES.STENCIL_BACK_PASS_DEPTH_PASS = 0x8803
GLES.STENCIL_BACK_REF = 0x8CA3
GLES.STENCIL_BACK_VALUE_MASK = 0x8CA4
GLES.STENCIL_BACK_WRITEMASK = 0x8CA5
GLES.VIEWPORT = 0x0BA2
GLES.SCISSOR_BOX = 0x0C10
GLES.COLOR_CLEAR_VALUE = 0x0C22
GLES.COLOR_WRITEMASK = 0x0C23
GLES.UNPACK_ALIGNMENT = 0x0CF5
GLES.PACK_ALIGNMENT = 0x0D05
GLES.MAX_TEXTURE_SIZE = 0x0D33
GLES.MAX_VIEWPORT_DIMS = 0x0D3A
GLES.SUBPIXEL_BITS = 0x0D50
GLES.RED_BITS = 0x0D52
GLES.GREEN_BITS = 0x0D53
GLES.BLUE_BITS = 0x0D54
GLES.ALPHA_BITS = 0x0D55
GLES.DEPTH_BITS = 0x0D56
GLES.STENCIL_BITS = 0x0D57
GLES.POLYGON_OFFSET_UNITS = 0x2A00
GLES.POLYGON_OFFSET_FACTOR = 0x8038
GLES.TEXTURE_BINDING_2D = 0x8069
GLES.SAMPLE_BUFFERS = 0x80A8
GLES.SAMPLES = 0x80A9
GLES.SAMPLE_COVERAGE_VALUE = 0x80AA
GLES.SAMPLE_COVERAGE_INVERT = 0x80AB
GLES.NUM_COMPRESSED_TEXTURE_FORMATS = 0x86A2
GLES.COMPRESSED_TEXTURE_FORMATS = 0x86A3
GLES.DONT_CARE = 0x1100
GLES.FASTEST = 0x1101
GLES.NICEST = 0x1102
GLES.GENERATE_MIPMAP_HINT = 0x8192
GLES.BYTE = 0x1400
GLES.UNSIGNED_BYTE = 0x1401
GLES.SHORT = 0x1402
GLES.UNSIGNED_SHORT = 0x1403
GLES.INT = 0x1404
GLES.UNSIGNED_INT = 0x1405
GLES.FLOAT = 0x1406
GLES.FIXED = 0x140C
GLES.DEPTH_COMPONENT = 0x1902
GLES.ALPHA = 0x1906
GLES.RGB = 0x1907
GLES.RGBA = 0x1908
GLES.LUMINANCE = 0x1909
GLES.LUMINANCE_ALPHA = 0x190A
GLES.UNSIGNED_SHORT_4_4_4_4 = 0x8033
GLES.UNSIGNED_SHORT_5_5_5_1 = 0x8034
GLES.UNSIGNED_SHORT_5_6_5 = 0x8363
GLES.FRAGMENT_SHADER = 0x8B30
GLES.VERTEX_SHADER = 0x8B31
GLES.MAX_VERTEX_ATTRIBS = 0x8869
GLES.MAX_VERTEX_UNIFORM_VECTORS = 0x8DFB
GLES.MAX_VARYING_VECTORS = 0x8DFC
GLES.MAX_COMBINED_TEXTURE_IMAGE_UNITS = 0x8B4D
GLES.MAX_VERTEX_TEXTURE_IMAGE_UNITS = 0x8B4C
GLES.MAX_TEXTURE_IMAGE_UNITS = 0x8872
GLES.MAX_FRAGMENT_UNIFORM_VECTORS = 0x8DFD
GLES.SHADER_TYPE = 0x8B4F
GLES.DELETE_STATUS = 0x8B80
GLES.LINK_STATUS = 0x8B82
GLES.VALIDATE_STATUS = 0x8B83
GLES.ATTACHED_SHADERS = 0x8B85
GLES.ACTIVE_UNIFORMS = 0x8B86
GLES.ACTIVE_UNIFORM_MAX_LENGTH = 0x8B87
GLES.ACTIVE_ATTRIBUTES = 0x8B89
GLES.ACTIVE_ATTRIBUTE_MAX_LENGTH = 0x8B8A
GLES.SHADING_LANGUAGE_VERSION = 0x8B8C
GLES.CURRENT_PROGRAM = 0x8B8D
GLES.NEVER = 0x0200
GLES.LESS = 0x0201
GLES.EQUAL = 0x0202
GLES.LEQUAL = 0x0203
GLES.GREATER = 0x0204
GLES.NOTEQUAL = 0x0205
GLES.GEQUAL = 0x0206
GLES.ALWAYS = 0x0207
GLES.KEEP = 0x1E00
GLES.REPLACE = 0x1E01
GLES.INCR = 0x1E02
GLES.DECR = 0x1E03
GLES.INVERT = 0x150A
GLES.INCR_WRAP = 0x8507
GLES.DECR_WRAP = 0x8508
GLES.VENDOR = 0x1F00
GLES.RENDERER = 0x1F01
GLES.VERSION = 0x1F02
GLES.EXTENSIONS = 0x1F03
GLES.NEAREST = 0x2600
GLES.LINEAR = 0x2601
GLES.NEAREST_MIPMAP_NEAREST = 0x2700
GLES.LINEAR_MIPMAP_NEAREST = 0x2701
GLES.NEAREST_MIPMAP_LINEAR = 0x2702
GLES.LINEAR_MIPMAP_LINEAR = 0x2703
GLES.TEXTURE_MAG_FILTER = 0x2800
GLES.TEXTURE_MIN_FILTER = 0x2801
GLES.TEXTURE_WRAP_S = 0x2802
GLES.TEXTURE_WRAP_T = 0x2803
GLES.TEXTURE = 0x1702
GLES.TEXTURE_CUBE_MAP = 0x8513
GLES.TEXTURE_BINDING_CUBE_MAP = 0x8514
GLES.TEXTURE_CUBE_MAP_POSITIVE_X = 0x8515
GLES.TEXTURE_CUBE_MAP_NEGATIVE_X = 0x8516
GLES.TEXTURE_CUBE_MAP_POSITIVE_Y = 0x8517
GLES.TEXTURE_CUBE_MAP_NEGATIVE_Y = 0x8518
GLES.TEXTURE_CUBE_MAP_POSITIVE_Z = 0x8519
GLES.TEXTURE_CUBE_MAP_NEGATIVE_Z = 0x851A
GLES.MAX_CUBE_MAP_TEXTURE_SIZE = 0x851C
GLES.TEXTURE0 = 0x84C0
GLES.TEXTURE1 = 0x84C1
GLES.TEXTURE2 = 0x84C2
GLES.TEXTURE3 = 0x84C3
GLES.TEXTURE4 = 0x84C4
GLES.TEXTURE5 = 0x84C5
GLES.TEXTURE6 = 0x84C6
GLES.TEXTURE7 = 0x84C7
GLES.TEXTURE8 = 0x84C8
GLES.TEXTURE9 = 0x84C9
GLES.TEXTURE10 = 0x84CA
GLES.TEXTURE11 = 0x84CB
GLES.TEXTURE12 = 0x84CC
GLES.TEXTURE13 = 0x84CD
GLES.TEXTURE14 = 0x84CE
GLES.TEXTURE15 = 0x84CF
GLES.TEXTURE16 = 0x84D0
GLES.TEXTURE17 = 0x84D1
GLES.TEXTURE18 = 0x84D2
GLES.TEXTURE19 = 0x84D3
GLES.TEXTURE20 = 0x84D4
GLES.TEXTURE21 = 0x84D5
GLES.TEXTURE22 = 0x84D6
GLES.TEXTURE23 = 0x84D7
GLES.TEXTURE24 = 0x84D8
GLES.TEXTURE25 = 0x84D9
GLES.TEXTURE26 = 0x84DA
GLES.TEXTURE27 = 0x84DB
GLES.TEXTURE28 = 0x84DC
GLES.TEXTURE29 = 0x84DD
GLES.TEXTURE30 = 0x84DE
GLES.TEXTURE31 = 0x84DF
GLES.ACTIVE_TEXTURE = 0x84E0
GLES.REPEAT = 0x2901
GLES.CLAMP_TO_EDGE = 0x812F
GLES.MIRRORED_REPEAT = 0x8370
GLES.FLOAT_VEC2 = 0x8B50
GLES.FLOAT_VEC3 = 0x8B51
GLES.FLOAT_VEC4 = 0x8B52
GLES.INT_VEC2 = 0x8B53
GLES.INT_VEC3 = 0x8B54
GLES.INT_VEC4 = 0x8B55
GLES.BOOL = 0x8B56
GLES.BOOL_VEC2 = 0x8B57
GLES.BOOL_VEC3 = 0x8B58
GLES.BOOL_VEC4 = 0x8B59
GLES.FLOAT_MAT2 = 0x8B5A
GLES.FLOAT_MAT3 = 0x8B5B
GLES.FLOAT_MAT4 = 0x8B5C
GLES.SAMPLER_2D = 0x8B5E
GLES.SAMPLER_CUBE = 0x8B60
GLES.VERTEX_ATTRIB_ARRAY_ENABLED = 0x8622
GLES.VERTEX_ATTRIB_ARRAY_SIZE = 0x8623
GLES.VERTEX_ATTRIB_ARRAY_STRIDE = 0x8624
GLES.VERTEX_ATTRIB_ARRAY_TYPE = 0x8625
GLES.VERTEX_ATTRIB_ARRAY_NORMALIZED = 0x886A
GLES.VERTEX_ATTRIB_ARRAY_POINTER = 0x8645
GLES.VERTEX_ATTRIB_ARRAY_BUFFER_BINDING = 0x889F
GLES.IMPLEMENTATION_COLOR_READ_TYPE = 0x8B9A
GLES.IMPLEMENTATION_COLOR_READ_FORMAT = 0x8B9B
GLES.COMPILE_STATUS = 0x8B81
GLES.INFO_LOG_LENGTH = 0x8B84
GLES.SHADER_SOURCE_LENGTH = 0x8B88
GLES.SHADER_COMPILER = 0x8DFA
GLES.SHADER_BINARY_FORMATS = 0x8DF8
GLES.NUM_SHADER_BINARY_FORMATS = 0x8DF9
GLES.LOW_FLOAT = 0x8DF0
GLES.MEDIUM_FLOAT = 0x8DF1
GLES.HIGH_FLOAT = 0x8DF2
GLES.LOW_INT = 0x8DF3
GLES.MEDIUM_INT = 0x8DF4
GLES.HIGH_INT = 0x8DF5
GLES.FRAMEBUFFER = 0x8D40
GLES.RENDERBUFFER = 0x8D41
GLES.RGBA4 = 0x8056
GLES.RGB5_A1 = 0x8057
GLES.RGB565 = 0x8D62
GLES.DEPTH_COMPONENT16 = 0x81A5
GLES.STENCIL_INDEX8 = 0x8D48
GLES.RENDERBUFFER_WIDTH = 0x8D42
GLES.RENDERBUFFER_HEIGHT = 0x8D43
GLES.RENDERBUFFER_INTERNAL_FORMAT = 0x8D44
GLES.RENDERBUFFER_RED_SIZE = 0x8D50
GLES.RENDERBUFFER_GREEN_SIZE = 0x8D51
GLES.RENDERBUFFER_BLUE_SIZE = 0x8D52
GLES.RENDERBUFFER_ALPHA_SIZE = 0x8D53
GLES.RENDERBUFFER_DEPTH_SIZE = 0x8D54
GLES.RENDERBUFFER_STENCIL_SIZE = 0x8D55
GLES.FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE = 0x8CD0
GLES.FRAMEBUFFER_ATTACHMENT_OBJECT_NAME = 0x8CD1
GLES.FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL = 0x8CD2
GLES.FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE = 0x8CD3
GLES.COLOR_ATTACHMENT0 = 0x8CE0
GLES.DEPTH_ATTACHMENT = 0x8D00
GLES.STENCIL_ATTACHMENT = 0x8D20
GLES.NONE = 0
GLES.FRAMEBUFFER_COMPLETE = 0x8CD5
GLES.FRAMEBUFFER_INCOMPLETE_ATTACHMENT = 0x8CD6
GLES.FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT = 0x8CD7
GLES.FRAMEBUFFER_INCOMPLETE_DIMENSIONS = 0x8CD9
GLES.FRAMEBUFFER_UNSUPPORTED = 0x8CDD
GLES.FRAMEBUFFER_BINDING = 0x8CA6
GLES.RENDERBUFFER_BINDING = 0x8CA7
GLES.MAX_RENDERBUFFER_SIZE = 0x84E8
GLES.INVALID_FRAMEBUFFER_OPERATION = 0x0506

-- GL ES 3.0

GLES.READ_BUFFER = 0x0C02
GLES.UNPACK_ROW_LENGTH = 0x0CF2
GLES.UNPACK_SKIP_ROWS = 0x0CF3
GLES.UNPACK_SKIP_PIXELS = 0x0CF4
GLES.PACK_ROW_LENGTH = 0x0D02
GLES.PACK_SKIP_ROWS = 0x0D03
GLES.PACK_SKIP_PIXELS = 0x0D04
GLES.COLOR = 0x1800
GLES.DEPTH = 0x1801
GLES.STENCIL = 0x1802
GLES.RED = 0x1903
GLES.RGB8 = 0x8051
GLES.RGBA8 = 0x8058
GLES.RGB10_A2 = 0x8059
GLES.TEXTURE_BINDING_3D = 0x806A
GLES.UNPACK_SKIP_IMAGES = 0x806D
GLES.UNPACK_IMAGE_HEIGHT = 0x806E
GLES.TEXTURE_3D = 0x806F
GLES.TEXTURE_WRAP_R = 0x8072
GLES.MAX_3D_TEXTURE_SIZE = 0x8073
GLES.UNSIGNED_INT_2_10_10_10_REV = 0x8368
GLES.MAX_ELEMENTS_VERTICES = 0x80E8
GLES.MAX_ELEMENTS_INDICES = 0x80E9
GLES.TEXTURE_MIN_LOD = 0x813A
GLES.TEXTURE_MAX_LOD = 0x813B
GLES.TEXTURE_BASE_LEVEL = 0x813C
GLES.TEXTURE_MAX_LEVEL = 0x813D
GLES.MIN = 0x8007
GLES.MAX = 0x8008
GLES.DEPTH_COMPONENT24 = 0x81A6
GLES.MAX_TEXTURE_LOD_BIAS = 0x84FD
GLES.TEXTURE_COMPARE_MODE = 0x884C
GLES.TEXTURE_COMPARE_FUNC = 0x884D
GLES.CURRENT_QUERY = 0x8865
GLES.QUERY_RESULT = 0x8866
GLES.QUERY_RESULT_AVAILABLE = 0x8867
GLES.BUFFER_MAPPED = 0x88BC
GLES.BUFFER_MAP_POINTER = 0x88BD
GLES.STREAM_READ = 0x88E1
GLES.STREAM_COPY = 0x88E2
GLES.STATIC_READ = 0x88E5
GLES.STATIC_COPY = 0x88E6
GLES.DYNAMIC_READ = 0x88E9
GLES.DYNAMIC_COPY = 0x88EA
GLES.MAX_DRAW_BUFFERS = 0x8824
GLES.DRAW_BUFFER0 = 0x8825
GLES.DRAW_BUFFER1 = 0x8826
GLES.DRAW_BUFFER2 = 0x8827
GLES.DRAW_BUFFER3 = 0x8828
GLES.DRAW_BUFFER4 = 0x8829
GLES.DRAW_BUFFER5 = 0x882A
GLES.DRAW_BUFFER6 = 0x882B
GLES.DRAW_BUFFER7 = 0x882C
GLES.DRAW_BUFFER8 = 0x882D
GLES.DRAW_BUFFER9 = 0x882E
GLES.DRAW_BUFFER10 = 0x882F
GLES.DRAW_BUFFER11 = 0x8830
GLES.DRAW_BUFFER12 = 0x8831
GLES.DRAW_BUFFER13 = 0x8832
GLES.DRAW_BUFFER14 = 0x8833
GLES.DRAW_BUFFER15 = 0x8834
GLES.MAX_FRAGMENT_UNIFORM_COMPONENTS = 0x8B49
GLES.MAX_VERTEX_UNIFORM_COMPONENTS = 0x8B4A
GLES.SAMPLER_3D = 0x8B5F
GLES.SAMPLER_2D_SHADOW = 0x8B62
GLES.FRAGMENT_SHADER_DERIVATIVE_HINT = 0x8B8B
GLES.PIXEL_PACK_BUFFER = 0x88EB
GLES.PIXEL_UNPACK_BUFFER = 0x88EC
GLES.PIXEL_PACK_BUFFER_BINDING = 0x88ED
GLES.PIXEL_UNPACK_BUFFER_BINDING = 0x88EF
GLES.FLOAT_MAT2x3 = 0x8B65
GLES.FLOAT_MAT2x4 = 0x8B66
GLES.FLOAT_MAT3x2 = 0x8B67
GLES.FLOAT_MAT3x4 = 0x8B68
GLES.FLOAT_MAT4x2 = 0x8B69
GLES.FLOAT_MAT4x3 = 0x8B6A
GLES.SRGB = 0x8C40
GLES.SRGB8 = 0x8C41
GLES.SRGB8_ALPHA8 = 0x8C43
GLES.COMPARE_REF_TO_TEXTURE = 0x884E
GLES.MAJOR_VERSION = 0x821B
GLES.MINOR_VERSION = 0x821C
GLES.NUM_EXTENSIONS = 0x821D
GLES.RGBA32F = 0x8814
GLES.RGB32F = 0x8815
GLES.RGBA16F = 0x881A
GLES.RGB16F = 0x881B
GLES.VERTEX_ATTRIB_ARRAY_INTEGER = 0x88FD
GLES.MAX_ARRAY_TEXTURE_LAYERS = 0x88FF
GLES.MIN_PROGRAM_TEXEL_OFFSET = 0x8904
GLES.MAX_PROGRAM_TEXEL_OFFSET = 0x8905
GLES.MAX_VARYING_COMPONENTS = 0x8B4B
GLES.TEXTURE_2D_ARRAY = 0x8C1A
GLES.TEXTURE_BINDING_2D_ARRAY = 0x8C1D
GLES.R11F_G11F_B10F = 0x8C3A
GLES.UNSIGNED_INT_10F_11F_11F_REV = 0x8C3B
GLES.RGB9_E5 = 0x8C3D
GLES.UNSIGNED_INT_5_9_9_9_REV = 0x8C3E
GLES.TRANSFORM_FEEDBACK_VARYING_MAX_LENGTH = 0x8C76
GLES.TRANSFORM_FEEDBACK_BUFFER_MODE = 0x8C7F
GLES.MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS = 0x8C80
GLES.TRANSFORM_FEEDBACK_VARYINGS = 0x8C83
GLES.TRANSFORM_FEEDBACK_BUFFER_START = 0x8C84
GLES.TRANSFORM_FEEDBACK_BUFFER_SIZE = 0x8C85
GLES.TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN = 0x8C88
GLES.RASTERIZER_DISCARD = 0x8C89
GLES.MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS = 0x8C8A
GLES.MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS = 0x8C8B
GLES.INTERLEAVED_ATTRIBS = 0x8C8C
GLES.SEPARATE_ATTRIBS = 0x8C8D
GLES.TRANSFORM_FEEDBACK_BUFFER = 0x8C8E
GLES.TRANSFORM_FEEDBACK_BUFFER_BINDING = 0x8C8F
GLES.RGBA32UI = 0x8D70
GLES.RGB32UI = 0x8D71
GLES.RGBA16UI = 0x8D76
GLES.RGB16UI = 0x8D77
GLES.RGBA8UI = 0x8D7C
GLES.RGB8UI = 0x8D7D
GLES.RGBA32I = 0x8D82
GLES.RGB32I = 0x8D83
GLES.RGBA16I = 0x8D88
GLES.RGB16I = 0x8D89
GLES.RGBA8I = 0x8D8E
GLES.RGB8I = 0x8D8F
GLES.RED_INTEGER = 0x8D94
GLES.RGB_INTEGER = 0x8D98
GLES.RGBA_INTEGER = 0x8D99
GLES.SAMPLER_2D_ARRAY = 0x8DC1
GLES.SAMPLER_2D_ARRAY_SHADOW = 0x8DC4
GLES.SAMPLER_CUBE_SHADOW = 0x8DC5
GLES.UNSIGNED_INT_VEC2 = 0x8DC6
GLES.UNSIGNED_INT_VEC3 = 0x8DC7
GLES.UNSIGNED_INT_VEC4 = 0x8DC8
GLES.INT_SAMPLER_2D = 0x8DCA
GLES.INT_SAMPLER_3D = 0x8DCB
GLES.INT_SAMPLER_CUBE = 0x8DCC
GLES.INT_SAMPLER_2D_ARRAY = 0x8DCF
GLES.UNSIGNED_INT_SAMPLER_2D = 0x8DD2
GLES.UNSIGNED_INT_SAMPLER_3D = 0x8DD3
GLES.UNSIGNED_INT_SAMPLER_CUBE = 0x8DD4
GLES.UNSIGNED_INT_SAMPLER_2D_ARRAY = 0x8DD7
GLES.BUFFER_ACCESS_FLAGS = 0x911F
GLES.BUFFER_MAP_LENGTH = 0x9120
GLES.BUFFER_MAP_OFFSET = 0x9121
GLES.DEPTH_COMPONENT32F = 0x8CAC
GLES.DEPTH32F_STENCIL8 = 0x8CAD
GLES.FLOAT_32_UNSIGNED_INT_24_8_REV = 0x8DAD
GLES.FRAMEBUFFER_ATTACHMENT_COLOR_ENCODING = 0x8210
GLES.FRAMEBUFFER_ATTACHMENT_COMPONENT_TYPE = 0x8211
GLES.FRAMEBUFFER_ATTACHMENT_RED_SIZE = 0x8212
GLES.FRAMEBUFFER_ATTACHMENT_GREEN_SIZE = 0x8213
GLES.FRAMEBUFFER_ATTACHMENT_BLUE_SIZE = 0x8214
GLES.FRAMEBUFFER_ATTACHMENT_ALPHA_SIZE = 0x8215
GLES.FRAMEBUFFER_ATTACHMENT_DEPTH_SIZE = 0x8216
GLES.FRAMEBUFFER_ATTACHMENT_STENCIL_SIZE = 0x8217
GLES.FRAMEBUFFER_DEFAULT = 0x8218
GLES.FRAMEBUFFER_UNDEFINED = 0x8219
GLES.DEPTH_STENCIL_ATTACHMENT = 0x821A
GLES.DEPTH_STENCIL = 0x84F9
GLES.UNSIGNED_INT_24_8 = 0x84FA
GLES.DEPTH24_STENCIL8 = 0x88F0
GLES.UNSIGNED_NORMALIZED = 0x8C17
GLES.DRAW_FRAMEBUFFER_BINDING = 0x8CA6
GLES.READ_FRAMEBUFFER = 0x8CA8
GLES.DRAW_FRAMEBUFFER = 0x8CA9
GLES.READ_FRAMEBUFFER_BINDING = 0x8CAA
GLES.RENDERBUFFER_SAMPLES = 0x8CAB
GLES.FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER = 0x8CD4
GLES.MAX_COLOR_ATTACHMENTS = 0x8CDF
GLES.COLOR_ATTACHMENT1 = 0x8CE1
GLES.COLOR_ATTACHMENT2 = 0x8CE2
GLES.COLOR_ATTACHMENT3 = 0x8CE3
GLES.COLOR_ATTACHMENT4 = 0x8CE4
GLES.COLOR_ATTACHMENT5 = 0x8CE5
GLES.COLOR_ATTACHMENT6 = 0x8CE6
GLES.COLOR_ATTACHMENT7 = 0x8CE7
GLES.COLOR_ATTACHMENT8 = 0x8CE8
GLES.COLOR_ATTACHMENT9 = 0x8CE9
GLES.COLOR_ATTACHMENT10 = 0x8CEA
GLES.COLOR_ATTACHMENT11 = 0x8CEB
GLES.COLOR_ATTACHMENT12 = 0x8CEC
GLES.COLOR_ATTACHMENT13 = 0x8CED
GLES.COLOR_ATTACHMENT14 = 0x8CEE
GLES.COLOR_ATTACHMENT15 = 0x8CEF
GLES.COLOR_ATTACHMENT16 = 0x8CF0
GLES.COLOR_ATTACHMENT17 = 0x8CF1
GLES.COLOR_ATTACHMENT18 = 0x8CF2
GLES.COLOR_ATTACHMENT19 = 0x8CF3
GLES.COLOR_ATTACHMENT20 = 0x8CF4
GLES.COLOR_ATTACHMENT21 = 0x8CF5
GLES.COLOR_ATTACHMENT22 = 0x8CF6
GLES.COLOR_ATTACHMENT23 = 0x8CF7
GLES.COLOR_ATTACHMENT24 = 0x8CF8
GLES.COLOR_ATTACHMENT25 = 0x8CF9
GLES.COLOR_ATTACHMENT26 = 0x8CFA
GLES.COLOR_ATTACHMENT27 = 0x8CFB
GLES.COLOR_ATTACHMENT28 = 0x8CFC
GLES.COLOR_ATTACHMENT29 = 0x8CFD
GLES.COLOR_ATTACHMENT30 = 0x8CFE
GLES.COLOR_ATTACHMENT31 = 0x8CFF
GLES.FRAMEBUFFER_INCOMPLETE_MULTISAMPLE = 0x8D56
GLES.MAX_SAMPLES = 0x8D57
GLES.HALF_FLOAT = 0x140B
GLES.MAP_READ_BIT = 0x0001
GLES.MAP_WRITE_BIT = 0x0002
GLES.MAP_INVALIDATE_RANGE_BIT = 0x0004
GLES.MAP_INVALIDATE_BUFFER_BIT = 0x0008
GLES.MAP_FLUSH_EXPLICIT_BIT = 0x0010
GLES.MAP_UNSYNCHRONIZED_BIT = 0x0020
GLES.RG = 0x8227
GLES.RG_INTEGER = 0x8228
GLES.R8 = 0x8229
GLES.RG8 = 0x822B
GLES.R16F = 0x822D
GLES.R32F = 0x822E
GLES.RG16F = 0x822F
GLES.RG32F = 0x8230
GLES.R8I = 0x8231
GLES.R8UI = 0x8232
GLES.R16I = 0x8233
GLES.R16UI = 0x8234
GLES.R32I = 0x8235
GLES.R32UI = 0x8236
GLES.RG8I = 0x8237
GLES.RG8UI = 0x8238
GLES.RG16I = 0x8239
GLES.RG16UI = 0x823A
GLES.RG32I = 0x823B
GLES.RG32UI = 0x823C
GLES.VERTEX_ARRAY_BINDING = 0x85B5
GLES.R8_SNORM = 0x8F94
GLES.RG8_SNORM = 0x8F95
GLES.RGB8_SNORM = 0x8F96
GLES.RGBA8_SNORM = 0x8F97
GLES.SIGNED_NORMALIZED = 0x8F9C
GLES.PRIMITIVE_RESTART_FIXED_INDEX = 0x8D69
GLES.COPY_READ_BUFFER = 0x8F36
GLES.COPY_WRITE_BUFFER = 0x8F37
GLES.COPY_READ_BUFFER_BINDING = 0x8F36
GLES.COPY_WRITE_BUFFER_BINDING = 0x8F37
GLES.UNIFORM_BUFFER = 0x8A11
GLES.UNIFORM_BUFFER_BINDING = 0x8A28
GLES.UNIFORM_BUFFER_START = 0x8A29
GLES.UNIFORM_BUFFER_SIZE = 0x8A2A
GLES.MAX_VERTEX_UNIFORM_BLOCKS = 0x8A2B
GLES.MAX_FRAGMENT_UNIFORM_BLOCKS = 0x8A2D
GLES.MAX_COMBINED_UNIFORM_BLOCKS = 0x8A2E
GLES.MAX_UNIFORM_BUFFER_BINDINGS = 0x8A2F
GLES.MAX_UNIFORM_BLOCK_SIZE = 0x8A30
GLES.MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS = 0x8A31
GLES.MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS = 0x8A33
GLES.UNIFORM_BUFFER_OFFSET_ALIGNMENT = 0x8A34
GLES.ACTIVE_UNIFORM_BLOCK_MAX_NAME_LENGTH = 0x8A35
GLES.ACTIVE_UNIFORM_BLOCKS = 0x8A36
GLES.UNIFORM_TYPE = 0x8A37
GLES.UNIFORM_SIZE = 0x8A38
GLES.UNIFORM_NAME_LENGTH = 0x8A39
GLES.UNIFORM_BLOCK_INDEX = 0x8A3A
GLES.UNIFORM_OFFSET = 0x8A3B
GLES.UNIFORM_ARRAY_STRIDE = 0x8A3C
GLES.UNIFORM_MATRIX_STRIDE = 0x8A3D
GLES.UNIFORM_IS_ROW_MAJOR = 0x8A3E
GLES.UNIFORM_BLOCK_BINDING = 0x8A3F
GLES.UNIFORM_BLOCK_DATA_SIZE = 0x8A40
GLES.UNIFORM_BLOCK_NAME_LENGTH = 0x8A41
GLES.UNIFORM_BLOCK_ACTIVE_UNIFORMS = 0x8A42
GLES.UNIFORM_BLOCK_ACTIVE_UNIFORM_INDICES = 0x8A43
GLES.UNIFORM_BLOCK_REFERENCED_BY_VERTEX_SHADER = 0x8A44
GLES.UNIFORM_BLOCK_REFERENCED_BY_FRAGMENT_SHADER = 0x8A46
GLES.INVALID_INDEX = 0xFFFFFFFF
GLES.MAX_VERTEX_OUTPUT_COMPONENTS = 0x9122
GLES.MAX_FRAGMENT_INPUT_COMPONENTS = 0x9125
GLES.MAX_SERVER_WAIT_TIMEOUT = 0x9111
GLES.OBJECT_TYPE = 0x9112
GLES.SYNC_CONDITION = 0x9113
GLES.SYNC_STATUS = 0x9114
GLES.SYNC_FLAGS = 0x9115
GLES.SYNC_FENCE = 0x9116
GLES.SYNC_GPU_COMMANDS_COMPLETE = 0x9117
GLES.UNSIGNALED = 0x9118
GLES.SIGNALED = 0x9119
GLES.ALREADY_SIGNALED = 0x911A
GLES.TIMEOUT_EXPIRED = 0x911B
GLES.CONDITION_SATISFIED = 0x911C
GLES.WAIT_FAILED = 0x911D
GLES.SYNC_FLUSH_COMMANDS_BIT = 0x00000001
GLES.TIMEOUT_IGNORED = 0xFFFFFFFFFFFFFFFF
GLES.VERTEX_ATTRIB_ARRAY_DIVISOR = 0x88FE
GLES.ANY_SAMPLES_PASSED = 0x8C2F
GLES.ANY_SAMPLES_PASSED_CONSERVATIVE = 0x8D6A
GLES.SAMPLER_BINDING = 0x8919
GLES.RGB10_A2UI = 0x906F
GLES.TEXTURE_SWIZZLE_R = 0x8E42
GLES.TEXTURE_SWIZZLE_G = 0x8E43
GLES.TEXTURE_SWIZZLE_B = 0x8E44
GLES.TEXTURE_SWIZZLE_A = 0x8E45
GLES.GREEN = 0x1904
GLES.BLUE = 0x1905
GLES.INT_2_10_10_10_REV = 0x8D9F
GLES.TRANSFORM_FEEDBACK = 0x8E22
GLES.TRANSFORM_FEEDBACK_PAUSED = 0x8E23
GLES.TRANSFORM_FEEDBACK_ACTIVE = 0x8E24
GLES.TRANSFORM_FEEDBACK_BINDING = 0x8E25
GLES.PROGRAM_BINARY_RETRIEVABLE_HINT = 0x8257
GLES.PROGRAM_BINARY_LENGTH = 0x8741
GLES.NUM_PROGRAM_BINARY_FORMATS = 0x87FE
GLES.PROGRAM_BINARY_FORMATS = 0x87FF
GLES.COMPRESSED_R11_EAC = 0x9270
GLES.COMPRESSED_SIGNED_R11_EAC = 0x9271
GLES.COMPRESSED_RG11_EAC = 0x9272
GLES.COMPRESSED_SIGNED_RG11_EAC = 0x9273
GLES.COMPRESSED_RGB8_ETC2 = 0x9274
GLES.COMPRESSED_SRGB8_ETC2 = 0x9275
GLES.COMPRESSED_RGB8_PUNCHTHROUGH_ALPHA1_ETC2 = 0x9276
GLES.COMPRESSED_SRGB8_PUNCHTHROUGH_ALPHA1_ETC2 = 0x9277
GLES.COMPRESSED_RGBA8_ETC2_EAC = 0x9278
GLES.COMPRESSED_SRGB8_ALPHA8_ETC2_EAC = 0x9279
GLES.TEXTURE_IMMUTABLE_FORMAT = 0x912F
GLES.MAX_ELEMENT_INDEX = 0x8D6B
GLES.NUM_SAMPLE_COUNTS = 0x9380
GLES.TEXTURE_IMMUTABLE_LEVELS = 0x82DF

-- GL ES 3.1

GLES.COMPUTE_SHADER = 0x91B9
GLES.MAX_COMPUTE_UNIFORM_BLOCKS = 0x91BB
GLES.MAX_COMPUTE_TEXTURE_IMAGE_UNITS = 0x91BC
GLES.MAX_COMPUTE_IMAGE_UNIFORMS = 0x91BD
GLES.MAX_COMPUTE_SHARED_MEMORY_SIZE = 0x8262
GLES.MAX_COMPUTE_UNIFORM_COMPONENTS = 0x8263
GLES.MAX_COMPUTE_ATOMIC_COUNTER_BUFFERS = 0x8264
GLES.MAX_COMPUTE_ATOMIC_COUNTERS = 0x8265
GLES.MAX_COMBINED_COMPUTE_UNIFORM_COMPONENTS = 0x8266
GLES.MAX_COMPUTE_WORK_GROUP_INVOCATIONS = 0x90EB
GLES.MAX_COMPUTE_WORK_GROUP_COUNT = 0x91BE
GLES.MAX_COMPUTE_WORK_GROUP_SIZE = 0x91BF
GLES.COMPUTE_WORK_GROUP_SIZE = 0x8267
GLES.DISPATCH_INDIRECT_BUFFER = 0x90EE
GLES.DISPATCH_INDIRECT_BUFFER_BINDING = 0x90EF
GLES.COMPUTE_SHADER_BIT = 0x00000020
GLES.DRAW_INDIRECT_BUFFER = 0x8F3F
GLES.DRAW_INDIRECT_BUFFER_BINDING = 0x8F43
GLES.MAX_UNIFORM_LOCATIONS = 0x826E
GLES.FRAMEBUFFER_DEFAULT_WIDTH = 0x9310
GLES.FRAMEBUFFER_DEFAULT_HEIGHT = 0x9311
GLES.FRAMEBUFFER_DEFAULT_SAMPLES = 0x9313
GLES.FRAMEBUFFER_DEFAULT_FIXED_SAMPLE_LOCATIONS = 0x9314
GLES.MAX_FRAMEBUFFER_WIDTH = 0x9315
GLES.MAX_FRAMEBUFFER_HEIGHT = 0x9316
GLES.MAX_FRAMEBUFFER_SAMPLES = 0x9318
GLES.UNIFORM = 0x92E1
GLES.UNIFORM_BLOCK = 0x92E2
GLES.PROGRAM_INPUT = 0x92E3
GLES.PROGRAM_OUTPUT = 0x92E4
GLES.BUFFER_VARIABLE = 0x92E5
GLES.SHADER_STORAGE_BLOCK = 0x92E6
GLES.ATOMIC_COUNTER_BUFFER = 0x92C0
GLES.TRANSFORM_FEEDBACK_VARYING = 0x92F4
GLES.ACTIVE_RESOURCES = 0x92F5
GLES.MAX_NAME_LENGTH = 0x92F6
GLES.MAX_NUM_ACTIVE_VARIABLES = 0x92F7
GLES.NAME_LENGTH = 0x92F9
GLES.TYPE = 0x92FA
GLES.ARRAY_SIZE = 0x92FB
GLES.OFFSET = 0x92FC
GLES.BLOCK_INDEX = 0x92FD
GLES.ARRAY_STRIDE = 0x92FE
GLES.MATRIX_STRIDE = 0x92FF
GLES.IS_ROW_MAJOR = 0x9300
GLES.ATOMIC_COUNTER_BUFFER_INDEX = 0x9301
GLES.BUFFER_BINDING = 0x9302
GLES.BUFFER_DATA_SIZE = 0x9303
GLES.NUM_ACTIVE_VARIABLES = 0x9304
GLES.ACTIVE_VARIABLES = 0x9305
GLES.REFERENCED_BY_VERTEX_SHADER = 0x9306
GLES.REFERENCED_BY_FRAGMENT_SHADER = 0x930A
GLES.REFERENCED_BY_COMPUTE_SHADER = 0x930B
GLES.TOP_LEVEL_ARRAY_SIZE = 0x930C
GLES.TOP_LEVEL_ARRAY_STRIDE = 0x930D
GLES.LOCATION = 0x930E
GLES.VERTEX_SHADER_BIT = 0x00000001
GLES.FRAGMENT_SHADER_BIT = 0x00000002
GLES.ALL_SHADER_BITS = 0xFFFFFFFF
GLES.PROGRAM_SEPARABLE = 0x8258
GLES.ACTIVE_PROGRAM = 0x8259
GLES.PROGRAM_PIPELINE_BINDING = 0x825A
GLES.ATOMIC_COUNTER_BUFFER_BINDING = 0x92C1
GLES.ATOMIC_COUNTER_BUFFER_START = 0x92C2
GLES.ATOMIC_COUNTER_BUFFER_SIZE = 0x92C3
GLES.MAX_VERTEX_ATOMIC_COUNTER_BUFFERS = 0x92CC
GLES.MAX_FRAGMENT_ATOMIC_COUNTER_BUFFERS = 0x92D0
GLES.MAX_COMBINED_ATOMIC_COUNTER_BUFFERS = 0x92D1
GLES.MAX_VERTEX_ATOMIC_COUNTERS = 0x92D2
GLES.MAX_FRAGMENT_ATOMIC_COUNTERS = 0x92D6
GLES.MAX_COMBINED_ATOMIC_COUNTERS = 0x92D7
GLES.MAX_ATOMIC_COUNTER_BUFFER_SIZE = 0x92D8
GLES.MAX_ATOMIC_COUNTER_BUFFER_BINDINGS = 0x92DC
GLES.ACTIVE_ATOMIC_COUNTER_BUFFERS = 0x92D9
GLES.UNSIGNED_INT_ATOMIC_COUNTER = 0x92DB
GLES.MAX_IMAGE_UNITS = 0x8F38
GLES.MAX_VERTEX_IMAGE_UNIFORMS = 0x90CA
GLES.MAX_FRAGMENT_IMAGE_UNIFORMS = 0x90CE
GLES.MAX_COMBINED_IMAGE_UNIFORMS = 0x90CF
GLES.IMAGE_BINDING_NAME = 0x8F3A
GLES.IMAGE_BINDING_LEVEL = 0x8F3B
GLES.IMAGE_BINDING_LAYERED = 0x8F3C
GLES.IMAGE_BINDING_LAYER = 0x8F3D
GLES.IMAGE_BINDING_ACCESS = 0x8F3E
GLES.IMAGE_BINDING_FORMAT = 0x906E
GLES.VERTEX_ATTRIB_ARRAY_BARRIER_BIT = 0x00000001
GLES.ELEMENT_ARRAY_BARRIER_BIT = 0x00000002
GLES.UNIFORM_BARRIER_BIT = 0x00000004
GLES.TEXTURE_FETCH_BARRIER_BIT = 0x00000008
GLES.SHADER_IMAGE_ACCESS_BARRIER_BIT = 0x00000020
GLES.COMMAND_BARRIER_BIT = 0x00000040
GLES.PIXEL_BUFFER_BARRIER_BIT = 0x00000080
GLES.TEXTURE_UPDATE_BARRIER_BIT = 0x00000100
GLES.BUFFER_UPDATE_BARRIER_BIT = 0x00000200
GLES.FRAMEBUFFER_BARRIER_BIT = 0x00000400
GLES.TRANSFORM_FEEDBACK_BARRIER_BIT = 0x00000800
GLES.ATOMIC_COUNTER_BARRIER_BIT = 0x00001000
GLES.ALL_BARRIER_BITS = 0xFFFFFFFF
GLES.IMAGE_2D = 0x904D
GLES.IMAGE_3D = 0x904E
GLES.IMAGE_CUBE = 0x9050
GLES.IMAGE_2D_ARRAY = 0x9053
GLES.INT_IMAGE_2D = 0x9058
GLES.INT_IMAGE_3D = 0x9059
GLES.INT_IMAGE_CUBE = 0x905B
GLES.INT_IMAGE_2D_ARRAY = 0x905E
GLES.UNSIGNED_INT_IMAGE_2D = 0x9063
GLES.UNSIGNED_INT_IMAGE_3D = 0x9064
GLES.UNSIGNED_INT_IMAGE_CUBE = 0x9066
GLES.UNSIGNED_INT_IMAGE_2D_ARRAY = 0x9069
GLES.IMAGE_FORMAT_COMPATIBILITY_TYPE = 0x90C7
GLES.IMAGE_FORMAT_COMPATIBILITY_BY_SIZE = 0x90C8
GLES.IMAGE_FORMAT_COMPATIBILITY_BY_CLASS = 0x90C9
GLES.READ_ONLY = 0x88B8
GLES.WRITE_ONLY = 0x88B9
GLES.READ_WRITE = 0x88BA
GLES.SHADER_STORAGE_BUFFER = 0x90D2
GLES.SHADER_STORAGE_BUFFER_BINDING = 0x90D3
GLES.SHADER_STORAGE_BUFFER_START = 0x90D4
GLES.SHADER_STORAGE_BUFFER_SIZE = 0x90D5
GLES.MAX_VERTEX_SHADER_STORAGE_BLOCKS = 0x90D6
GLES.MAX_FRAGMENT_SHADER_STORAGE_BLOCKS = 0x90DA
GLES.MAX_COMPUTE_SHADER_STORAGE_BLOCKS = 0x90DB
GLES.MAX_COMBINED_SHADER_STORAGE_BLOCKS = 0x90DC
GLES.MAX_SHADER_STORAGE_BUFFER_BINDINGS = 0x90DD
GLES.MAX_SHADER_STORAGE_BLOCK_SIZE = 0x90DE
GLES.SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT = 0x90DF
GLES.SHADER_STORAGE_BARRIER_BIT = 0x00002000
GLES.MAX_COMBINED_SHADER_OUTPUT_RESOURCES = 0x8F39
GLES.DEPTH_STENCIL_TEXTURE_MODE = 0x90EA
GLES.STENCIL_INDEX = 0x1901
GLES.MIN_PROGRAM_TEXTURE_GATHER_OFFSET = 0x8E5E
GLES.MAX_PROGRAM_TEXTURE_GATHER_OFFSET = 0x8E5F
GLES.SAMPLE_POSITION = 0x8E50
GLES.SAMPLE_MASK = 0x8E51
GLES.SAMPLE_MASK_VALUE = 0x8E52
GLES.TEXTURE_2D_MULTISAMPLE = 0x9100
GLES.MAX_SAMPLE_MASK_WORDS = 0x8E59
GLES.MAX_COLOR_TEXTURE_SAMPLES = 0x910E
GLES.MAX_DEPTH_TEXTURE_SAMPLES = 0x910F
GLES.MAX_INTEGER_SAMPLES = 0x9110
GLES.TEXTURE_BINDING_2D_MULTISAMPLE = 0x9104
GLES.TEXTURE_SAMPLES = 0x9106
GLES.TEXTURE_FIXED_SAMPLE_LOCATIONS = 0x9107
GLES.TEXTURE_WIDTH = 0x1000
GLES.TEXTURE_HEIGHT = 0x1001
GLES.TEXTURE_DEPTH = 0x8071
GLES.TEXTURE_INTERNAL_FORMAT = 0x1003
GLES.TEXTURE_RED_SIZE = 0x805C
GLES.TEXTURE_GREEN_SIZE = 0x805D
GLES.TEXTURE_BLUE_SIZE = 0x805E
GLES.TEXTURE_ALPHA_SIZE = 0x805F
GLES.TEXTURE_DEPTH_SIZE = 0x884A
GLES.TEXTURE_STENCIL_SIZE = 0x88F1
GLES.TEXTURE_SHARED_SIZE = 0x8C3F
GLES.TEXTURE_RED_TYPE = 0x8C10
GLES.TEXTURE_GREEN_TYPE = 0x8C11
GLES.TEXTURE_BLUE_TYPE = 0x8C12
GLES.TEXTURE_ALPHA_TYPE = 0x8C13
GLES.TEXTURE_DEPTH_TYPE = 0x8C16
GLES.TEXTURE_COMPRESSED = 0x86A1
GLES.SAMPLER_2D_MULTISAMPLE = 0x9108
GLES.INT_SAMPLER_2D_MULTISAMPLE = 0x9109
GLES.UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE = 0x910A
GLES.VERTEX_ATTRIB_BINDING = 0x82D4
GLES.VERTEX_ATTRIB_RELATIVE_OFFSET = 0x82D5
GLES.VERTEX_BINDING_DIVISOR = 0x82D6
GLES.VERTEX_BINDING_OFFSET = 0x82D7
GLES.VERTEX_BINDING_STRIDE = 0x82D8
GLES.VERTEX_BINDING_BUFFER = 0x8F4F
GLES.MAX_VERTEX_ATTRIB_RELATIVE_OFFSET = 0x82D9
GLES.MAX_VERTEX_ATTRIB_BINDINGS = 0x82DA
GLES.MAX_VERTEX_ATTRIB_STRIDE = 0x82E5

-- GL ES 3.2

GLES.MULTISAMPLE_LINE_WIDTH_RANGE = 0x9381
GLES.MULTISAMPLE_LINE_WIDTH_GRANULARITY = 0x9382
GLES.MULTIPLY = 0x9294
GLES.SCREEN = 0x9295
GLES.OVERLAY = 0x9296
GLES.DARKEN = 0x9297
GLES.LIGHTEN = 0x9298
GLES.COLORDODGE = 0x9299
GLES.COLORBURN = 0x929A
GLES.HARDLIGHT = 0x929B
GLES.SOFTLIGHT = 0x929C
GLES.DIFFERENCE = 0x929E
GLES.EXCLUSION = 0x92A0
GLES.HSL_HUE = 0x92AD
GLES.HSL_SATURATION = 0x92AE
GLES.HSL_COLOR = 0x92AF
GLES.HSL_LUMINOSITY = 0x92B0
GLES.DEBUG_OUTPUT_SYNCHRONOUS = 0x8242
GLES.DEBUG_NEXT_LOGGED_MESSAGE_LENGTH = 0x8243
GLES.DEBUG_CALLBACK_FUNCTION = 0x8244
GLES.DEBUG_CALLBACK_USER_PARAM = 0x8245
GLES.DEBUG_SOURCE_API = 0x8246
GLES.DEBUG_SOURCE_WINDOW_SYSTEM = 0x8247
GLES.DEBUG_SOURCE_SHADER_COMPILER = 0x8248
GLES.DEBUG_SOURCE_THIRD_PARTY = 0x8249
GLES.DEBUG_SOURCE_APPLICATION = 0x824A
GLES.DEBUG_SOURCE_OTHER = 0x824B
GLES.DEBUG_TYPE_ERROR = 0x824C
GLES.DEBUG_TYPE_DEPRECATED_BEHAVIOR = 0x824D
GLES.DEBUG_TYPE_UNDEFINED_BEHAVIOR = 0x824E
GLES.DEBUG_TYPE_PORTABILITY = 0x824F
GLES.DEBUG_TYPE_PERFORMANCE = 0x8250
GLES.DEBUG_TYPE_OTHER = 0x8251
GLES.DEBUG_TYPE_MARKER = 0x8268
GLES.DEBUG_TYPE_PUSH_GROUP = 0x8269
GLES.DEBUG_TYPE_POP_GROUP = 0x826A
GLES.DEBUG_SEVERITY_NOTIFICATION = 0x826B
GLES.MAX_DEBUG_GROUP_STACK_DEPTH = 0x826C
GLES.DEBUG_GROUP_STACK_DEPTH = 0x826D
GLES.BUFFER = 0x82E0
GLES.SHADER = 0x82E1
GLES.PROGRAM = 0x82E2
GLES.VERTEX_ARRAY = 0x8074
GLES.QUERY = 0x82E3
GLES.PROGRAM_PIPELINE = 0x82E4
GLES.SAMPLER = 0x82E6
GLES.MAX_LABEL_LENGTH = 0x82E8
GLES.MAX_DEBUG_MESSAGE_LENGTH = 0x9143
GLES.MAX_DEBUG_LOGGED_MESSAGES = 0x9144
GLES.DEBUG_LOGGED_MESSAGES = 0x9145
GLES.DEBUG_SEVERITY_HIGH = 0x9146
GLES.DEBUG_SEVERITY_MEDIUM = 0x9147
GLES.DEBUG_SEVERITY_LOW = 0x9148
GLES.DEBUG_OUTPUT = 0x92E0
GLES.CONTEXT_FLAG_DEBUG_BIT = 0x00000002
GLES.STACK_OVERFLOW = 0x0503
GLES.STACK_UNDERFLOW = 0x0504
GLES.GEOMETRY_SHADER = 0x8DD9
GLES.GEOMETRY_SHADER_BIT = 0x00000004
GLES.GEOMETRY_VERTICES_OUT = 0x8916
GLES.GEOMETRY_INPUT_TYPE = 0x8917
GLES.GEOMETRY_OUTPUT_TYPE = 0x8918
GLES.GEOMETRY_SHADER_INVOCATIONS = 0x887F
GLES.LAYER_PROVOKING_VERTEX = 0x825E
GLES.LINES_ADJACENCY = 0x000A
GLES.LINE_STRIP_ADJACENCY = 0x000B
GLES.TRIANGLES_ADJACENCY = 0x000C
GLES.TRIANGLE_STRIP_ADJACENCY = 0x000D
GLES.MAX_GEOMETRY_UNIFORM_COMPONENTS = 0x8DDF
GLES.MAX_GEOMETRY_UNIFORM_BLOCKS = 0x8A2C
GLES.MAX_COMBINED_GEOMETRY_UNIFORM_COMPONENTS = 0x8A32
GLES.MAX_GEOMETRY_INPUT_COMPONENTS = 0x9123
GLES.MAX_GEOMETRY_OUTPUT_COMPONENTS = 0x9124
GLES.MAX_GEOMETRY_OUTPUT_VERTICES = 0x8DE0
GLES.MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS = 0x8DE1
GLES.MAX_GEOMETRY_SHADER_INVOCATIONS = 0x8E5A
GLES.MAX_GEOMETRY_TEXTURE_IMAGE_UNITS = 0x8C29
GLES.MAX_GEOMETRY_ATOMIC_COUNTER_BUFFERS = 0x92CF
GLES.MAX_GEOMETRY_ATOMIC_COUNTERS = 0x92D5
GLES.MAX_GEOMETRY_IMAGE_UNIFORMS = 0x90CD
GLES.MAX_GEOMETRY_SHADER_STORAGE_BLOCKS = 0x90D7
GLES.FIRST_VERTEX_CONVENTION = 0x8E4D
GLES.LAST_VERTEX_CONVENTION = 0x8E4E
GLES.UNDEFINED_VERTEX = 0x8260
GLES.PRIMITIVES_GENERATED = 0x8C87
GLES.FRAMEBUFFER_DEFAULT_LAYERS = 0x9312
GLES.MAX_FRAMEBUFFER_LAYERS = 0x9317
GLES.FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS = 0x8DA8
GLES.FRAMEBUFFER_ATTACHMENT_LAYERED = 0x8DA7
GLES.REFERENCED_BY_GEOMETRY_SHADER = 0x9309
GLES.PRIMITIVE_BOUNDING_BOX = 0x92BE
GLES.CONTEXT_FLAG_ROBUST_ACCESS_BIT = 0x00000004
GLES.CONTEXT_FLAGS = 0x821E
GLES.LOSE_CONTEXT_ON_RESET = 0x8252
GLES.GUILTY_CONTEXT_RESET = 0x8253
GLES.INNOCENT_CONTEXT_RESET = 0x8254
GLES.UNKNOWN_CONTEXT_RESET = 0x8255
GLES.RESET_NOTIFICATION_STRATEGY = 0x8256
GLES.NO_RESET_NOTIFICATION = 0x8261
GLES.CONTEXT_LOST = 0x0507
GLES.SAMPLE_SHADING = 0x8C36
GLES.MIN_SAMPLE_SHADING_VALUE = 0x8C37
GLES.MIN_FRAGMENT_INTERPOLATION_OFFSET = 0x8E5B
GLES.MAX_FRAGMENT_INTERPOLATION_OFFSET = 0x8E5C
GLES.FRAGMENT_INTERPOLATION_OFFSET_BITS = 0x8E5D
GLES.PATCHES = 0x000E
GLES.PATCH_VERTICES = 0x8E72
GLES.TESS_CONTROL_OUTPUT_VERTICES = 0x8E75
GLES.TESS_GEN_MODE = 0x8E76
GLES.TESS_GEN_SPACING = 0x8E77
GLES.TESS_GEN_VERTEX_ORDER = 0x8E78
GLES.TESS_GEN_POINT_MODE = 0x8E79
GLES.ISOLINES = 0x8E7A
GLES.QUADS = 0x0007
GLES.FRACTIONAL_ODD = 0x8E7B
GLES.FRACTIONAL_EVEN = 0x8E7C
GLES.MAX_PATCH_VERTICES = 0x8E7D
GLES.MAX_TESS_GEN_LEVEL = 0x8E7E
GLES.MAX_TESS_CONTROL_UNIFORM_COMPONENTS = 0x8E7F
GLES.MAX_TESS_EVALUATION_UNIFORM_COMPONENTS = 0x8E80
GLES.MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS = 0x8E81
GLES.MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS = 0x8E82
GLES.MAX_TESS_CONTROL_OUTPUT_COMPONENTS = 0x8E83
GLES.MAX_TESS_PATCH_COMPONENTS = 0x8E84
GLES.MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS = 0x8E85
GLES.MAX_TESS_EVALUATION_OUTPUT_COMPONENTS = 0x8E86
GLES.MAX_TESS_CONTROL_UNIFORM_BLOCKS = 0x8E89
GLES.MAX_TESS_EVALUATION_UNIFORM_BLOCKS = 0x8E8A
GLES.MAX_TESS_CONTROL_INPUT_COMPONENTS = 0x886C
GLES.MAX_TESS_EVALUATION_INPUT_COMPONENTS = 0x886D
GLES.MAX_COMBINED_TESS_CONTROL_UNIFORM_COMPONENTS = 0x8E1E
GLES.MAX_COMBINED_TESS_EVALUATION_UNIFORM_COMPONENTS = 0x8E1F
GLES.MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS = 0x92CD
GLES.MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS = 0x92CE
GLES.MAX_TESS_CONTROL_ATOMIC_COUNTERS = 0x92D3
GLES.MAX_TESS_EVALUATION_ATOMIC_COUNTERS = 0x92D4
GLES.MAX_TESS_CONTROL_IMAGE_UNIFORMS = 0x90CB
GLES.MAX_TESS_EVALUATION_IMAGE_UNIFORMS = 0x90CC
GLES.MAX_TESS_CONTROL_SHADER_STORAGE_BLOCKS = 0x90D8
GLES.MAX_TESS_EVALUATION_SHADER_STORAGE_BLOCKS = 0x90D9
GLES.PRIMITIVE_RESTART_FOR_PATCHES_SUPPORTED = 0x8221
GLES.IS_PER_PATCH = 0x92E7
GLES.REFERENCED_BY_TESS_CONTROL_SHADER = 0x9307
GLES.REFERENCED_BY_TESS_EVALUATION_SHADER = 0x9308
GLES.TESS_CONTROL_SHADER = 0x8E88
GLES.TESS_EVALUATION_SHADER = 0x8E87
GLES.TESS_CONTROL_SHADER_BIT = 0x00000008
GLES.TESS_EVALUATION_SHADER_BIT = 0x00000010
GLES.TEXTURE_BORDER_COLOR = 0x1004
GLES.CLAMP_TO_BORDER = 0x812D
GLES.TEXTURE_BUFFER = 0x8C2A
GLES.TEXTURE_BUFFER_BINDING = 0x8C2A
GLES.MAX_TEXTURE_BUFFER_SIZE = 0x8C2B
GLES.TEXTURE_BINDING_BUFFER = 0x8C2C
GLES.TEXTURE_BUFFER_DATA_STORE_BINDING = 0x8C2D
GLES.TEXTURE_BUFFER_OFFSET_ALIGNMENT = 0x919F
GLES.SAMPLER_BUFFER = 0x8DC2
GLES.INT_SAMPLER_BUFFER = 0x8DD0
GLES.UNSIGNED_INT_SAMPLER_BUFFER = 0x8DD8
GLES.IMAGE_BUFFER = 0x9051
GLES.INT_IMAGE_BUFFER = 0x905C
GLES.UNSIGNED_INT_IMAGE_BUFFER = 0x9067
GLES.TEXTURE_BUFFER_OFFSET = 0x919D
GLES.TEXTURE_BUFFER_SIZE = 0x919E
GLES.COMPRESSED_RGBA_ASTC_4x4 = 0x93B0
GLES.COMPRESSED_RGBA_ASTC_5x4 = 0x93B1
GLES.COMPRESSED_RGBA_ASTC_5x5 = 0x93B2
GLES.COMPRESSED_RGBA_ASTC_6x5 = 0x93B3
GLES.COMPRESSED_RGBA_ASTC_6x6 = 0x93B4
GLES.COMPRESSED_RGBA_ASTC_8x5 = 0x93B5
GLES.COMPRESSED_RGBA_ASTC_8x6 = 0x93B6
GLES.COMPRESSED_RGBA_ASTC_8x8 = 0x93B7
GLES.COMPRESSED_RGBA_ASTC_10x5 = 0x93B8
GLES.COMPRESSED_RGBA_ASTC_10x6 = 0x93B9
GLES.COMPRESSED_RGBA_ASTC_10x8 = 0x93BA
GLES.COMPRESSED_RGBA_ASTC_10x10 = 0x93BB
GLES.COMPRESSED_RGBA_ASTC_12x10 = 0x93BC
GLES.COMPRESSED_RGBA_ASTC_12x12 = 0x93BD
GLES.COMPRESSED_SRGB8_ALPHA8_ASTC_4x4 = 0x93D0
GLES.COMPRESSED_SRGB8_ALPHA8_ASTC_5x4 = 0x93D1
GLES.COMPRESSED_SRGB8_ALPHA8_ASTC_5x5 = 0x93D2
GLES.COMPRESSED_SRGB8_ALPHA8_ASTC_6x5 = 0x93D3
GLES.COMPRESSED_SRGB8_ALPHA8_ASTC_6x6 = 0x93D4
GLES.COMPRESSED_SRGB8_ALPHA8_ASTC_8x5 = 0x93D5
GLES.COMPRESSED_SRGB8_ALPHA8_ASTC_8x6 = 0x93D6
GLES.COMPRESSED_SRGB8_ALPHA8_ASTC_8x8 = 0x93D7
GLES.COMPRESSED_SRGB8_ALPHA8_ASTC_10x5 = 0x93D8
GLES.COMPRESSED_SRGB8_ALPHA8_ASTC_10x6 = 0x93D9
GLES.COMPRESSED_SRGB8_ALPHA8_ASTC_10x8 = 0x93DA
GLES.COMPRESSED_SRGB8_ALPHA8_ASTC_10x10 = 0x93DB
GLES.COMPRESSED_SRGB8_ALPHA8_ASTC_12x10 = 0x93DC
GLES.COMPRESSED_SRGB8_ALPHA8_ASTC_12x12 = 0x93DD
GLES.TEXTURE_CUBE_MAP_ARRAY = 0x9009
GLES.TEXTURE_BINDING_CUBE_MAP_ARRAY = 0x900A
GLES.SAMPLER_CUBE_MAP_ARRAY = 0x900C
GLES.SAMPLER_CUBE_MAP_ARRAY_SHADOW = 0x900D
GLES.INT_SAMPLER_CUBE_MAP_ARRAY = 0x900E
GLES.UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY = 0x900F
GLES.IMAGE_CUBE_MAP_ARRAY = 0x9054
GLES.INT_IMAGE_CUBE_MAP_ARRAY = 0x905F
GLES.UNSIGNED_INT_IMAGE_CUBE_MAP_ARRAY = 0x906A
GLES.TEXTURE_2D_MULTISAMPLE_ARRAY = 0x9102
GLES.TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY = 0x9105
GLES.SAMPLER_2D_MULTISAMPLE_ARRAY = 0x910B
GLES.INT_SAMPLER_2D_MULTISAMPLE_ARRAY = 0x910C
GLES.UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY = 0x910D

-- GL ES 2.0

function GLES.activeTexture(texture)
    return lib.raia_gl_active_texture(texture)
end

function GLES.attachShader(program, shader)
    return lib.raia_gl_attach_shader(program, shader)
end

function GLES.bindAttribLocation(program, index, name)
    return lib.raia_gl_bind_attrib_location(program, index, name)
end

function GLES.bindBuffer(target, buffer)
    return lib.raia_gl_bind_buffer(target, buffer)
end

function GLES.bindFramebuffer(target, framebuffer)
    return lib.raia_gl_bind_framebuffer(target, framebuffer)
end

function GLES.bindRenderbuffer(target, renderbuffer)
    return lib.raia_gl_bind_renderbuffer(target, renderbuffer)
end

function GLES.bindTexture(target, texture)
    return lib.raia_gl_bind_texture(target, texture)
end

function GLES.blendColor(red, green, blue, alpha)
    return lib.raia_gl_blend_color(red, green, blue, alpha)
end

function GLES.blendEquation(mode)
    return lib.raia_gl_blend_equation(mode)
end

function GLES.blendEquationSeparate(modeRGB, modeAlpha)
    return lib.raia_gl_blend_equation_separate(modeRGB, modeAlpha)
end

function GLES.blendFunc(sfactor, dfactor)
    return lib.raia_gl_blend_func(sfactor, dfactor)
end

function GLES.blendFuncSeparate(sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha)
    return lib.raia_gl_blend_func_separate(sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha)
end

function GLES.bufferData(target, size, data, usage)
    return lib.raia_gl_buffer_data(target, size, data, usage)
end

function GLES.bufferSubData(target, offset, size, data)
    return lib.raia_gl_buffer_sub_data(target, offset, size, data)
end

function GLES.checkFramebufferStatus(target)
    return lib.raia_gl_check_framebuffer_status(target)
end

function GLES.clear(mask)
    return lib.raia_gl_clear(mask)
end

function GLES.clearColor(red, green, blue, alpha)
    return lib.raia_gl_clear_color(red, green, blue, alpha)
end

function GLES.clearDepthf(d)
    return lib.raia_gl_clear_depth_f(d)
end

function GLES.clearStencil(s)
    return lib.raia_gl_clear_stencil(s)
end

function GLES.colorMask(red, green, blue, alpha)
    return lib.raia_gl_color_mask(red, green, blue, alpha)
end

function GLES.compileShader(shader)
    return lib.raia_gl_compile_shader(shader)
end

function GLES.compressedTexImage2D(target, level, internalformat, width, height, border, imageSize, data)
    return lib.raia_gl_compressed_tex_image_2d(target, level, internalformat, width, height, border, imageSize, data)
end

function GLES.compressedTexSubImage2D(target, level, xoffset, yoffset, width, height, format, imageSize, data)
    return lib.raia_gl_compressed_tex_sub_image_2d(target, level, xoffset, yoffset, width, height, format, imageSize, data)
end

function GLES.copyTexImage2D(target, level, internalformat, x, y, width, height, border)
    return lib.raia_gl_copy_tex_image_2d(target, level, internalformat, x, y, width, height, border)
end

function GLES.copyTexSubImage2D(target, level, xoffset, yoffset, x, y, width, height)
    return lib.raia_gl_copy_tex_sub_image_2d(target, level, xoffset, yoffset, x, y, width, height)
end

function GLES.createProgram()
    return lib.raia_gl_create_program()
end

function GLES.createShader(_type)
    return lib.raia_gl_create_shader(_type)
end

function GLES.cullFace(mode)
    return lib.raia_gl_cull_face(mode)
end

function GLES.deleteBuffers(n, buffers)
    return lib.raia_gl_delete_buffers(n, buffers)
end

function GLES.deleteFramebuffers(n, framebuffers)
    return lib.raia_gl_delete_framebuffers(n, framebuffers)
end

function GLES.deleteProgram(program)
    return lib.raia_gl_delete_program(program)
end

function GLES.deleteRenderbuffers(n, renderbuffers)
    return lib.raia_gl_delete_renderbuffers(n, renderbuffers)
end

function GLES.deleteShader(shader)
    return lib.raia_gl_delete_shader(shader)
end

function GLES.deleteTextures(n, textures)
    return lib.raia_gl_delete_textures(n, textures)
end

function GLES.depthFunc(func)
    return lib.raia_gl_depth_func(func)
end

function GLES.depthMask(flag)
    return lib.raia_gl_depth_mask(flag)
end

function GLES.depthRangef(n, f)
    return lib.raia_gl_depth_range_f(n, f)
end

function GLES.detachShader(program, shader)
    return lib.raia_gl_detach_shader(program, shader)
end

function GLES.disable(cap)
    return lib.raia_gl_disable(cap)
end

function GLES.disableVertexAttribArray(index)
    return lib.raia_gl_disable_vertex_attrib_array(index)
end

function GLES.drawArrays(mode, first, count)
    return lib.raia_gl_draw_arrays(mode, first, count)
end

function GLES.drawElements(mode, count, type, indices)
    return lib.raia_gl_draw_elements(mode, count, type, indices)
end

function GLES.enable(cap)
    return lib.raia_gl_enable(cap)
end

function GLES.enableVertexAttribArray(index)
    return lib.raia_gl_enable_vertex_attrib_array(index)
end

function GLES.finish()
    lib.raia_gl_finish()
end

function GLES.flush()
    lib.raia_gl_flush()
end

function GLES.framebufferRenderbuffer(target, attachment, renderbuffertarget, renderbuffer)
    return lib.raia_gl_framebuffer_renderbuffer(target, attachment, renderbuffertarget, renderbuffer)
end

function GLES.framebufferTexture2D(target, attachment, textarget, texture, level)
    return lib.raia_gl_framebuffer_texture_2d(target, attachment, textarget, texture, level)
end

function GLES.frontFace(mode)
    return lib.raia_gl_front_face(mode)
end

function GLES.genBuffers(n, buffers)
    return lib.raia_gl_gen_buffers(n, buffers)
end

function GLES.generateMipmap(target)
    return lib.raia_gl_generate_mipmap(target)
end

function GLES.genFramebuffers(n, framebuffers)
    return lib.raia_gl_gen_framebuffers(n, framebuffers)
end

function GLES.genRenderbuffers(n, renderbuffers)
    return lib.raia_gl_gen_renderbuffers(n, renderbuffers)
end

function GLES.genTextures(n, textures)
    return lib.raia_gl_gen_textures(n, textures)
end

function GLES.getActiveAttrib(program, index, bufSize, length, size, type, name)
    return lib.raia_gl_get_active_attrib(program, index, bufSize, length, size, type, name)
end

function GLES.getActiveUniform(program, index, bufSize, length, size, type, name)
    return lib.raia_gl_get_active_uniform(program, index, bufSize, length, size, type, name)
end

function GLES.getAttachedShaders(program, maxCount, count, shaders)
    return lib.raia_gl_get_attached_shaders(program, maxCount, count, shaders)
end

function GLES.getAttribLocation(program, name)
    return lib.raia_gl_get_attrib_location(program, name)
end

function GLES.getBooleanv(pname, data)
    return lib.raia_gl_get_boolean_v(pname, data)
end

function GLES.getBufferParameteriv(target, pname, params)
    return lib.raia_gl_get_buffer_parameter_iv(target, pname, params)
end

function GLES.getError()
    lib.raia_gl_get_error()
end

function GLES.getFloatv(pname, data)
    return lib.raia_gl_get_float_v(pname, data)
end

function GLES.getFramebufferAttachmentParameteriv(target, attachment, pname, params)
    return lib.raia_gl_get_framebuffer_attachment_parameter_iv(target, attachment, pname, params)
end

function GLES.getIntegerv(pname, data)
    return lib.raia_gl_get_integer_v(pname, data)
end

function GLES.getProgramiv(program, pname, params)
    return lib.raia_gl_get_program_iv(program, pname, params)
end

function GLES.getProgramInfoLog(program, bufSize, length, infoLog)
    return lib.raia_gl_get_program_info_log(program, bufSize, length, infoLog)
end

function GLES.getRenderbufferParameteriv(target, pname, params)
    return lib.raia_gl_get_renderbuffer_parameter_iv(target, pname, params)
end

function GLES.getShaderiv(shader, pname, params)
    return lib.raia_gl_get_shader_iv(shader, pname, params)
end

function GLES.getShaderInfoLog(shader, bufSize, length, infoLog)
    return lib.raia_gl_get_shader_info_log(shader, bufSize, length, infoLog)
end

function GLES.getShaderPrecisionFormat(shadertype, precisiontype, range, precision)
    return lib.raia_gl_get_shader_precision_format(shadertype, precisiontype, range, precision)
end

function GLES.getShaderSource(shader, bufSize, length, source)
    return lib.raia_gl_get_shader_source(shader, bufSize, length, source)
end

function GLES.getString(name)
    return lib.raia_gl_get_string(name)
end

function GLES.getTexParameterfv(target, pname, params)
    return lib.raia_gl_get_tex_parameter_fv(target, pname, params)
end

function GLES.getTexParameteriv(target, pname, params)
    return lib.raia_gl_get_tex_parameter_iv(target, pname, params)
end

function GLES.getUniformfv(program, location, params)
    return lib.raia_gl_get_uniform_fv(program, location, params)
end

function GLES.getUniformiv(program, location, params)
    return lib.raia_gl_get_uniform_iv(program, location, params)
end

function GLES.getUniformLocation(program, name)
    return lib.raia_gl_get_uniform_location(program, name)
end

function GLES.getVertexAttribfv(index, pname, params)
    return lib.raia_gl_get_vertex_attrib_fv(index, pname, params)
end

function GLES.getVertexAttribiv(index, pname, params)
    return lib.raia_gl_get_vertex_attrib_iv(index, pname, params)
end

function GLES.getVertexAttribPointerv(index, pname, pointer)
    return lib.raia_gl_get_vertex_attrib_pointer_v(index, pname, pointer)
end

function GLES.hint(target, mode)
    return lib.raia_gl_hint(target, mode)
end

function GLES.isBuffer(buffer)
    return lib.raia_gl_is_buffer(buffer)
end

function GLES.isEnabled(cap)
    return lib.raia_gl_is_enabled(cap)
end

function GLES.isFramebuffer(framebuffer)
    return lib.raia_gl_is_framebuffer(framebuffer)
end

function GLES.isProgram(program)
    return lib.raia_gl_is_program(program)
end

function GLES.isRenderbuffer(renderbuffer)
    return lib.raia_gl_is_renderbuffer(renderbuffer)
end

function GLES.isShader(shader)
    return lib.raia_gl_is_shader(shader)
end

function GLES.isTexture(texture)
    return lib.raia_gl_is_texture(texture)
end

function GLES.lineWidth(width)
    return lib.raia_gl_line_width(width)
end

function GLES.linkProgram(program)
    return lib.raia_gl_link_program(program)
end

function GLES.pixelStorei(pname, param)
    return lib.raia_gl_pixel_store_i(pname, param)
end

function GLES.polygonOffset(factor, units)
    return lib.raia_gl_polygon_offset(factor, units)
end

function GLES.readPixels(x, y, width, height, format, type, pixels)
    return lib.raia_gl_read_pixels(x, y, width, height, format, type, pixels)
end

function GLES.releaseShaderCompiler()
    lib.raia_gl_release_shader_compiler()
end

function GLES.renderbufferStorage(target, internalformat, width, height)
    return lib.raia_gl_renderbuffer_storage(target, internalformat, width, height)
end

function GLES.sampleCoverage(value, invert)
    return lib.raia_gl_sample_coverage(value, invert)
end

function GLES.scissor(x, y, width, height)
    return lib.raia_gl_scissor(x, y, width, height)
end

function GLES.shaderBinary(count, shaders, binaryformat, binary, length)
    return lib.raia_gl_shader_binary(count, shaders, binaryformat, binary, length)
end

function GLES.shaderSource(shader, count, string, length)
    return lib.raia_gl_shader_source(shader, count, string, length)
end

function GLES.stencilFunc(func, ref, mask)
    return lib.raia_gl_stencil_func(func, ref, mask)
end

function GLES.stencilFuncSeparate(face, func, ref, mask)
    return lib.raia_gl_stencil_func_separate(face, func, ref, mask)
end

function GLES.stencilMask(mask)
    return lib.raia_gl_stencil_mask(mask)
end

function GLES.stencilMaskSeparate(face, mask)
    return lib.raia_gl_stencil_mask_separate(face, mask)
end

function GLES.stencilOp(fail, zfail, zpass)
    return lib.raia_gl_stencil_op(fail, zfail, zpass)
end

function GLES.stencilOpSeparate(face, sfail, dpfail, dppass)
    return lib.raia_gl_stencil_op_separate(face, sfail, dpfail, dppass)
end

function GLES.texImage2D(target, level, internalformat, width, height, border, format, type, pixels)
    return lib.raia_gl_tex_image_2d(target, level, internalformat, width, height, border, format, type, pixels)
end

function GLES.texParameterf(target, pname, param)
    return lib.raia_gl_tex_parameter_f(target, pname, param)
end

function GLES.texParameterfv(target, pname, params)
    return lib.raia_gl_tex_parameter_fv(target, pname, params)
end

function GLES.texParameteri(target, pname, param)
    return lib.raia_gl_tex_parameter_i(target, pname, param)
end

function GLES.texParameteriv(target, pname, params)
    return lib.raia_gl_tex_parameter_iv(target, pname, params)
end

function GLES.texSubImage2D(target, level, xoffset, yoffset, width, height, format, type, pixels)
    return lib.raia_gl_tex_sub_image_2d(target, level, xoffset, yoffset, width, height, format, type, pixels)
end

function GLES.uniform1f(location, v0)
    return lib.raia_gl_uniform_1f(location, v0)
end

function GLES.uniform1fv(location, count, value)
    return lib.raia_gl_uniform_1fv(location, count, value)
end

function GLES.uniform1i(location, v0)
    return lib.raia_gl_uniform_1i(location, v0)
end

function GLES.uniform1iv(location, count, value)
    return lib.raia_gl_uniform_1iv(location, count, value)
end

function GLES.uniform2f(location, v0, v1)
    return lib.raia_gl_uniform_2f(location, v0, v1)
end

function GLES.uniform2fv(location, count, value)
    return lib.raia_gl_uniform_2fv(location, count, value)
end

function GLES.uniform2i(location, v0, v1)
    return lib.raia_gl_uniform_2i(location, v0, v1)
end

function GLES.uniform2iv(location, count, value)
    return lib.raia_gl_uniform_2iv(location, count, value)
end

function GLES.uniform3f(location, v0, v1, v2)
    return lib.raia_gl_uniform_3f(location, v0, v1, v2)
end

function GLES.uniform3fv(location, count, value)
    return lib.raia_gl_uniform_3fv(location, count, value)
end

function GLES.uniform3i(location, v0, v1, v2)
    return lib.raia_gl_uniform_3i(location, v0, v1, v2)
end

function GLES.uniform3iv(location, count, value)
    return lib.raia_gl_uniform_3iv(location, count, value)
end

function GLES.uniform4f(location, v0, v1, v2, v3)
    return lib.raia_gl_uniform_4f(location, v0, v1, v2, v3)
end

function GLES.uniform4fv(location, count, value)
    return lib.raia_gl_uniform_4fv(location, count, value)
end

function GLES.uniform4i(location, v0, v1, v2, v3)
    return lib.raia_gl_uniform_4i(location, v0, v1, v2, v3)
end

function GLES.uniform4iv(location, count, value)
    return lib.raia_gl_uniform_4iv(location, count, value)
end

function GLES.uniformMatrix2fv(location, count, transpose, value)
    return lib.raia_gl_uniform_matrix_2fv(location, count, transpose, value)
end

function GLES.uniformMatrix3fv(location, count, transpose, value)
    return lib.raia_gl_uniform_matrix_3fv(location, count, transpose, value)
end

function GLES.uniformMatrix4fv(location, count, transpose, value)
    return lib.raia_gl_uniform_matrix_4fv(location, count, transpose, value)
end

function GLES.useProgram(program)
    return lib.raia_gl_use_program(program)
end

function GLES.validateProgram(program)
    return lib.raia_gl_validate_program(program)
end

function GLES.vertexAttrib1f(index, x)
    return lib.raia_gl_vertex_attrib_1f(index, x)
end

function GLES.vertexAttrib1fv(index, v)
    return lib.raia_gl_vertex_attrib_1fv(index, v)
end

function GLES.vertexAttrib2f(index, x, y)
    return lib.raia_gl_vertex_attrib_2f(index, x, y)
end

function GLES.vertexAttrib2fv(index, v)
    return lib.raia_gl_vertex_attrib_2fv(index, v)
end

function GLES.vertexAttrib3f(index, x, y, z)
    return lib.raia_gl_vertex_attrib_3f(index, x, y, z)
end

function GLES.vertexAttrib3fv(index, v)
    return lib.raia_gl_vertex_attrib_3fv(index, v)
end

function GLES.vertexAttrib4f(index, x, y, z, w)
    return lib.raia_gl_vertex_attrib_4f(index, x, y, z, w)
end

function GLES.vertexAttrib4fv(index, v)
    return lib.raia_gl_vertex_attrib_4fv(index, v)
end

function GLES.vertexAttribPointer(index, size, type, normalized, stride, pointer)
    return lib.raia_gl_vertex_attrib_pointer(index, size, type, normalized, stride, pointer)
end

function GLES.viewport(x, y, width, height)
    return lib.raia_gl_viewport(x, y, width, height)
end

-- GL ES 3.0

function GLES.readBuffer(src)
    return lib.raia_gl_read_buffer(src)
end

function GLES.drawRangeElements(mode, start, _end, count, type, indices)
    return lib.raia_gl_draw_range_elements(mode, start, _end, count, type, indices)
end

function GLES.texImage3D(target, level, internalformat, width, height, depth, border, format, type, pixels)
    return lib.raia_gl_tex_image_3d(target, level, internalformat, width, height, depth, border, format, type, pixels)
end

function GLES.texSubImage3D(target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels)
    return lib.raia_gl_tex_sub_image_3d(target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels)
end

function GLES.copyTexSubImage3D(target, level, xoffset, yoffset, zoffset, x, y, width, height)
    return lib.raia_gl_copy_tex_sub_image_3d(target, level, xoffset, yoffset, zoffset, x, y, width, height)
end

function GLES.compressedTexImage3D(target, level, internalformat, width, height, depth, border, imageSize, data)
    return lib.raia_gl_compressed_tex_image_3d(target, level, internalformat, width, height, depth, border, imageSize, data)
end

function GLES.compressedTexSubImage3D(target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data)
    return lib.raia_gl_compressed_tex_sub_image_3d(target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data)
end

function GLES.genQueries(n, ids)
    return lib.raia_gl_gen_queries(n, ids)
end

function GLES.deleteQueries(n, ids)
    return lib.raia_gl_delete_queries(n, ids)
end

function GLES.isQuery(id)
    return lib.raia_gl_is_query(id)
end

function GLES.beginQuery(target, id)
    return lib.raia_gl_begin_query(target, id)
end

function GLES.endQuery(target)
    return lib.raia_gl_end_query(target)
end

function GLES.getQueryiv(target, pname, params)
    return lib.raia_gl_get_query_iv(target, pname, params)
end

function GLES.getQueryObjectuiv(id, pname, params)
    return lib.raia_gl_get_query_object_uiv(id, pname, params)
end

function GLES.unmapBuffer(target)
    return lib.raia_gl_unmap_buffer(target)
end

function GLES.getBufferPointerv(target, pname, params)
    return lib.raia_gl_get_buffer_pointer_v(target, pname, params)
end

function GLES.drawBuffers(n, bufs)
    return lib.raia_gl_draw_buffers(n, bufs)
end

function GLES.uniformMatrix2x3fv(location, count, transpose, value)
    return lib.raia_gl_uniform_matrix_2x3fv(location, count, transpose, value)
end

function GLES.uniformMatrix3x2fv(location, count, transpose, value)
    return lib.raia_gl_uniform_matrix_3x2fv(location, count, transpose, value)
end

function GLES.uniformMatrix2x4fv(location, count, transpose, value)
    return lib.raia_gl_uniform_matrix_2x4fv(location, count, transpose, value)
end

function GLES.uniformMatrix4x2fv(location, count, transpose, value)
    return lib.raia_gl_uniform_matrix_4x2fv(location, count, transpose, value)
end

function GLES.uniformMatrix3x4fv(location, count, transpose, value)
    return lib.raia_gl_uniform_matrix_3x4fv(location, count, transpose, value)
end

function GLES.uniformMatrix4x3fv(location, count, transpose, value)
    return lib.raia_gl_uniform_matrix_4x3fv(location, count, transpose, value)
end

function GLES.blitFramebuffer(srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter)
    return lib.raia_gl_blit_framebuffer(srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter)
end

function GLES.renderbufferStorageMultisample(target, samples, internalformat, width, height)
    return lib.raia_gl_renderbuffer_storage_multisample(target, samples, internalformat, width, height)
end

function GLES.framebufferTextureLayer(target, attachment, texture, level, layer)
    return lib.raia_gl_framebuffer_texture_layer(target, attachment, texture, level, layer)
end

function GLES.mapBufferRange(target, offset, length, access)
    return lib.raia_gl_map_buffer_range(target, offset, length, access)
end

function GLES.flushMappedBufferRange(target, offset, length)
    return lib.raia_gl_flush_mapped_buffer_range(target, offset, length)
end

function GLES.bindVertexArray(array)
    return lib.raia_gl_bind_vertex_array(array)
end

function GLES.deleteVertexArrays(n, arrays)
    return lib.raia_gl_delete_vertex_arrays(n, arrays)
end

function GLES.genVertexArrays(n, arrays)
    return lib.raia_gl_gen_vertex_arrays(n, arrays)
end

function GLES.isVertexArray(array)
    return lib.raia_gl_is_vertex_array(array)
end

function GLES.getIntegeri_v(target, index, data)
    raia_gl_get_integer_i_v(target, index, data)
end

function GLES.beginTransformFeedback(primitiveMode)
    return lib.raia_gl_begin_transform_feedback(primitiveMode)
end

function GLES.endTransformFeedback()
    lib.raia_gl_end_transform_feedback()
end

function GLES.bindBufferRange(target, index, buffer, offset, size)
    return lib.raia_gl_bind_buffer_range(target, index, buffer, offset, size)
end

function GLES.bindBufferBase(target, index, buffer)
    return lib.raia_gl_bind_buffer_base(target, index, buffer)
end

function GLES.transformFeedbackVaryings(program, count, varyings, bufferMode)
    return lib.raia_gl_transform_feedback_varyings(program, count, varyings, bufferMode)
end

function GLES.getTransformFeedbackVarying(program, index, bufSize, length, size, type, name)
    return lib.raia_gl_get_transform_feedback_varying(program, index, bufSize, length, size, type, name)
end

function GLES.vertexAttribIPointer(index, size, type, stride, pointer)
    return lib.raia_gl_vertex_attrib_i_pointer(index, size, type, stride, pointer)
end

function GLES.getVertexAttribIiv(index, pname, params)
    return lib.raia_gl_get_vertex_attrib_iiv(index, pname, params)
end

function GLES.getVertexAttribIuiv(index, pname, params)
    return lib.raia_gl_get_vertex_attrib_iuiv(index, pname, params)
end

function GLES.vertexAttribI4i(index, x, y, z, w)
    return lib.raia_gl_vertex_attrib_i4i(index, x, y, z, w)
end

function GLES.vertexAttribI4ui(index, x, y, z, w)
    return lib.raia_gl_vertex_attrib_i4ui(index, x, y, z, w)
end

function GLES.vertexAttribI4iv(index, v)
    return lib.raia_gl_vertex_attrib_i4iv(index, v)
end

function GLES.vertexAttribI4uiv(index, v)
    return lib.raia_gl_vertex_attrib_i4uiv(index, v)
end

function GLES.getUniformuiv(program, location, params)
    return lib.raia_gl_get_uniform_uiv(program, location, params)
end

function GLES.getFragDataLocation(program, name)
    return lib.raia_gl_get_frag_data_location(program, name)
end

function GLES.uniform1ui(location, v0)
    return lib.raia_gl_uniform_1ui(location, v0)
end

function GLES.uniform2ui(location, v0, v1)
    return lib.raia_gl_uniform_2ui(location, v0, v1)
end

function GLES.uniform3ui(location, v0, v1, v2)
    return lib.raia_gl_uniform_3ui(location, v0, v1, v2)
end

function GLES.uniform4ui(location, v0, v1, v2, v3)
    return lib.raia_gl_uniform_4ui(location, v0, v1, v2, v3)
end

function GLES.uniform1uiv(location, count, value)
    return lib.raia_gl_uniform_1uiv(location, count, value)
end

function GLES.uniform2uiv(location, count, value)
    return lib.raia_gl_uniform_2uiv(location, count, value)
end

function GLES.uniform3uiv(location, count, value)
    return lib.raia_gl_uniform_3uiv(location, count, value)
end

function GLES.uniform4uiv(location, count, value)
    return lib.raia_gl_uniform_4uiv(location, count, value)
end

function GLES.clearBufferiv(buffer, drawbuffer, value)
    return lib.raia_gl_clear_buffer_iv(buffer, drawbuffer, value)
end

function GLES.clearBufferuiv(buffer, drawbuffer, value)
    return lib.raia_gl_clear_buffer_uiv(buffer, drawbuffer, value)
end

function GLES.clearBufferfv(buffer, drawbuffer, value)
    return lib.raia_gl_clear_buffer_fv(buffer, drawbuffer, value)
end

function GLES.clearBufferfi(buffer, drawbuffer, depth, stencil)
    return lib.raia_gl_clear_buffer_fi(buffer, drawbuffer, depth, stencil)
end

function GLES.getStringi(name, index)
    return lib.raia_gl_get_string_i(name, index)
end

function GLES.copyBufferSubData(readTarget, writeTarget, readOffset, writeOffset, size)
    return lib.raia_gl_copy_buffer_sub_data(readTarget, writeTarget, readOffset, writeOffset, size)
end

function GLES.getUniformIndices(program, uniformCount, uniformNames, uniformIndices)
    return lib.raia_gl_get_uniform_indices(program, uniformCount, uniformNames, uniformIndices)
end

function GLES.getActiveUniformsiv(program, uniformCount, uniformIndices, pname, params)
    return lib.raia_gl_get_active_uniforms_iv(program, uniformCount, uniformIndices, pname, params)
end

function GLES.getUniformBlockIndex(program, uniformBlockName)
    return lib.raia_gl_get_uniform_block_index(program, uniformBlockName)
end

function GLES.getActiveUniformBlockiv(program, uniformBlockIndex, pname, params)
    return lib.raia_gl_get_active_uniform_block_iv(program, uniformBlockIndex, pname, params)
end

function GLES.getActiveUniformBlockName(program, uniformBlockIndex, bufSize, length, uniformBlockName)
    return lib.raia_gl_get_active_uniform_block_name(program, uniformBlockIndex, bufSize, length, uniformBlockName)
end

function GLES.uniformBlockBinding(program, uniformBlockIndex, uniformBlockBinding)
    return lib.raia_gl_uniform_block_binding(program, uniformBlockIndex, uniformBlockBinding)
end

function GLES.drawArraysInstanced(mode, first, count, instancecount)
    return lib.raia_gl_draw_arrays_instanced(mode, first, count, instancecount)
end

function GLES.drawElementsInstanced(mode, count, type, indices, instancecount)
    return lib.raia_gl_draw_elements_instanced(mode, count, type, indices, instancecount)
end

function GLES.fenceSync(condition, flags)
    return lib.raia_gl_fence_sync(condition, flags)
end

function GLES.isSync(sync)
    return lib.raia_gl_is_sync(sync)
end

function GLES.deleteSync(sync)
    return lib.raia_gl_delete_sync(sync)
end

function GLES.clientWaitSync(sync, flags, timeout)
    return lib.raia_gl_client_wait_sync(sync, flags, timeout)
end

function GLES.waitSync(sync, flags, timeout)
    return lib.raia_gl_wait_sync(sync, flags, timeout)
end

function GLES.getInteger64v(pname, data)
    return lib.raia_gl_get_integer_64v(pname, data)
end

function GLES.getSynciv(sync, pname, bufSize, length, values)
    return lib.raia_gl_get_sync_iv(sync, pname, bufSize, length, values)
end

function GLES.getInteger64i_v(target, index, data)
    raia_gl_get_integer_64i_v(target, index, data)
end

function GLES.getBufferParameteri64v(target, pname, params)
    return lib.raia_gl_get_buffer_parameter_i64v(target, pname, params)
end

function GLES.genSamplers(count, samplers)
    return lib.raia_gl_gen_samplers(count, samplers)
end

function GLES.deleteSamplers(count, samplers)
    return lib.raia_gl_delete_samplers(count, samplers)
end

function GLES.isSampler(sampler)
    return lib.raia_gl_is_sampler(sampler)
end

function GLES.bindSampler(unit, sampler)
    return lib.raia_gl_bind_sampler(unit, sampler)
end

function GLES.samplerParameteri(sampler, pname, param)
    return lib.raia_gl_sampler_parameter_i(sampler, pname, param)
end

function GLES.samplerParameteriv(sampler, pname, param)
    return lib.raia_gl_sampler_parameter_iv(sampler, pname, param)
end

function GLES.samplerParameterf(sampler, pname, param)
    return lib.raia_gl_sampler_parameter_f(sampler, pname, param)
end

function GLES.samplerParameterfv(sampler, pname, param)
    return lib.raia_gl_sampler_parameter_fv(sampler, pname, param)
end

function GLES.getSamplerParameteriv(sampler, pname, params)
    return lib.raia_gl_get_sampler_parameter_iv(sampler, pname, params)
end

function GLES.getSamplerParameterfv(sampler, pname, params)
    return lib.raia_gl_get_sampler_parameter_fv(sampler, pname, params)
end

function GLES.vertexAttribDivisor(index, divisor)
    return lib.raia_gl_vertex_attrib_divisor(index, divisor)
end

function GLES.bindTransformFeedback(target, id)
    return lib.raia_gl_bind_transform_feedback(target, id)
end

function GLES.deleteTransformFeedbacks(n, ids)
    return lib.raia_gl_delete_transform_feedbacks(n, ids)
end

function GLES.genTransformFeedbacks(n, ids)
    return lib.raia_gl_gen_transform_feedbacks(n, ids)
end

function GLES.isTransformFeedback(id)
    return lib.raia_gl_is_transform_feedback(id)
end

function GLES.pauseTransformFeedback()
    lib.raia_gl_pause_transform_feedback()
end

function GLES.resumeTransformFeedback()
    lib.raia_gl_resume_transform_feedback()
end

function GLES.getProgramBinary(program, bufSize, length, binaryFormat, binary)
    return lib.raia_gl_get_program_binary(program, bufSize, length, binaryFormat, binary)
end

function GLES.programBinary(program, binaryFormat, binary, length)
    return lib.raia_gl_program_binary(program, binaryFormat, binary, length)
end

function GLES.programParameteri(program, pname, value)
    return lib.raia_gl_program_parameter_i(program, pname, value)
end

function GLES.invalidateFramebuffer(target, numAttachments, attachments)
    return lib.raia_gl_invalidate_framebuffer(target, numAttachments, attachments)
end

function GLES.invalidateSubFramebuffer(target, numAttachments, attachments, x, y, width, height)
    return lib.raia_gl_invalidate_sub_framebuffer(target, numAttachments, attachments, x, y, width, height)
end

function GLES.texStorage2D(target, levels, internalformat, width, height)
    return lib.raia_gl_tex_storage_2d(target, levels, internalformat, width, height)
end

function GLES.texStorage3D(target, levels, internalformat, width, height, depth)
    return lib.raia_gl_tex_storage_3d(target, levels, internalformat, width, height, depth)
end

function GLES.getInternalformativ(target, internalformat, pname, bufSize, params)
    return lib.raia_gl_get_internal_format_iv(target, internalformat, pname, bufSize, params)
end

-- GL ES 3.1

function GLES.dispatchCompute(num_groups_x, num_groups_y, num_groups_z)
    return lib.raia_gl_dispatch_compute(num_groups_x, num_groups_y, num_groups_z)
end

function GLES.dispatchComputeIndirect(indirect)
    return lib.raia_gl_dispatch_compute_indirect(indirect)
end

function GLES.drawArraysIndirect(mode, indirect)
    return lib.raia_gl_draw_arrays_indirect(mode, indirect)
end

function GLES.drawElementsIndirect(mode, type, indirect)
    return lib.raia_gl_draw_elements_indirect(mode, type, indirect)
end

function GLES.framebufferParameteri(target, pname, param)
    return lib.raia_gl_framebuffer_parameter_i(target, pname, param)
end

function GLES.getFramebufferParameteriv(target, pname, params)
    return lib.raia_gl_get_framebuffer_parameter_iv(target, pname, params)
end

function GLES.getProgramInterfaceiv(program, programInterface, pname, params)
    return lib.raia_gl_get_program_interface_iv(program, programInterface, pname, params)
end

function GLES.getProgramResourceIndex(program, programInterface, name)
    return lib.raia_gl_get_program_resource_index(program, programInterface, name)
end

function GLES.getProgramResourceName(program, programInterface, index, bufSize, length, name)
    return lib.raia_gl_get_program_resource_name(program, programInterface, index, bufSize, length, name)
end

function GLES.getProgramResourceiv(program, programInterface, index, propCount, props, bufSize, length, params)
    return lib.raia_gl_get_program_resource_iv(program, programInterface, index, propCount, props, bufSize, length, params)
end

function GLES.getProgramResourceLocation(program, programInterface, name)
    return lib.raia_gl_get_program_resource_location(program, programInterface, name)
end

function GLES.useProgramStages(pipeline, stages, program)
    return lib.raia_gl_use_program_stages(pipeline, stages, program)
end

function GLES.activeShaderProgram(pipeline, program)
    return lib.raia_gl_active_shader_program(pipeline, program)
end

function GLES.createShaderProgramv(type, count, strings)
    return lib.raia_gl_create_shader_program_v(type, count, strings)
end

function GLES.bindProgramPipeline(pipeline)
    return lib.raia_gl_bind_program_pipeline(pipeline)
end

function GLES.deleteProgramPipelines(n, pipelines)
    return lib.raia_gl_delete_program_pipelines(n, pipelines)
end

function GLES.genProgramPipelines(n, pipelines)
    return lib.raia_gl_gen_program_pipelines(n, pipelines)
end

function GLES.isProgramPipeline(pipeline)
    return lib.raia_gl_is_program_pipeline(pipeline)
end

function GLES.getProgramPipelineiv(pipeline, pname, params)
    return lib.raia_gl_get_program_pipeline_iv(pipeline, pname, params)
end

function GLES.programUniform1i(program, location, v0)
    return lib.raia_gl_program_uniform_1i(program, location, v0)
end

function GLES.programUniform2i(program, location, v0, v1)
    return lib.raia_gl_program_uniform_2i(program, location, v0, v1)
end

function GLES.programUniform3i(program, location, v0, v1, v2)
    return lib.raia_gl_program_uniform_3i(program, location, v0, v1, v2)
end

function GLES.programUniform4i(program, location, v0, v1, v2, v3)
    return lib.raia_gl_program_uniform_4i(program, location, v0, v1, v2, v3)
end

function GLES.programUniform1ui(program, location, v0)
    return lib.raia_gl_program_uniform_1ui(program, location, v0)
end

function GLES.programUniform2ui(program, location, v0, v1)
    return lib.raia_gl_program_uniform_2ui(program, location, v0, v1)
end

function GLES.programUniform3ui(program, location, v0, v1, v2)
    return lib.raia_gl_program_uniform_3ui(program, location, v0, v1, v2)
end

function GLES.programUniform4ui(program, location, v0, v1, v2, v3)
    return lib.raia_gl_program_uniform_4ui(program, location, v0, v1, v2, v3)
end

function GLES.programUniform1f(program, location, v0)
    return lib.raia_gl_program_uniform_1f(program, location, v0)
end

function GLES.programUniform2f(program, location, v0, v1)
    return lib.raia_gl_program_uniform_2f(program, location, v0, v1)
end

function GLES.programUniform3f(program, location, v0, v1, v2)
    return lib.raia_gl_program_uniform_3f(program, location, v0, v1, v2)
end

function GLES.programUniform4f(program, location, v0, v1, v2, v3)
    return lib.raia_gl_program_uniform_4f(program, location, v0, v1, v2, v3)
end

function GLES.programUniform1iv(program, location, count, value)
    return lib.raia_gl_program_uniform_1iv(program, location, count, value)
end

function GLES.programUniform2iv(program, location, count, value)
    return lib.raia_gl_program_uniform_2iv(program, location, count, value)
end

function GLES.programUniform3iv(program, location, count, value)
    return lib.raia_gl_program_uniform_3iv(program, location, count, value)
end

function GLES.programUniform4iv(program, location, count, value)
    return lib.raia_gl_program_uniform_4iv(program, location, count, value)
end

function GLES.programUniform1uiv(program, location, count, value)
    return lib.raia_gl_program_uniform_1uiv(program, location, count, value)
end

function GLES.programUniform2uiv(program, location, count, value)
    return lib.raia_gl_program_uniform_2uiv(program, location, count, value)
end

function GLES.programUniform3uiv(program, location, count, value)
    return lib.raia_gl_program_uniform_3uiv(program, location, count, value)
end

function GLES.programUniform4uiv(program, location, count, value)
    return lib.raia_gl_program_uniform_4uiv(program, location, count, value)
end

function GLES.programUniform1fv(program, location, count, value)
    return lib.raia_gl_program_uniform_1fv(program, location, count, value)
end

function GLES.programUniform2fv(program, location, count, value)
    return lib.raia_gl_program_uniform_2fv(program, location, count, value)
end

function GLES.programUniform3fv(program, location, count, value)
    return lib.raia_gl_program_uniform_3fv(program, location, count, value)
end

function GLES.programUniform4fv(program, location, count, value)
    return lib.raia_gl_program_uniform_4fv(program, location, count, value)
end

function GLES.programUniformMatrix2fv(program, location, count, transpose, value)
    return lib.raia_gl_program_uniform_matrix_2fv(program, location, count, transpose, value)
end

function GLES.programUniformMatrix3fv(program, location, count, transpose, value)
    return lib.raia_gl_program_uniform_matrix_3fv(program, location, count, transpose, value)
end

function GLES.programUniformMatrix4fv(program, location, count, transpose, value)
    return lib.raia_gl_program_uniform_matrix_4fv(program, location, count, transpose, value)
end

function GLES.programUniformMatrix2x3fv(program, location, count, transpose, value)
    return lib.raia_gl_program_uniform_matrix_2x3fv(program, location, count, transpose, value)
end

function GLES.programUniformMatrix3x2fv(program, location, count, transpose, value)
    return lib.raia_gl_program_uniform_matrix_3x2fv(program, location, count, transpose, value)
end

function GLES.programUniformMatrix2x4fv(program, location, count, transpose, value)
    return lib.raia_gl_program_uniform_matrix_2x4fv(program, location, count, transpose, value)
end

function GLES.programUniformMatrix4x2fv(program, location, count, transpose, value)
    return lib.raia_gl_program_uniform_matrix_4x2fv(program, location, count, transpose, value)
end

function GLES.programUniformMatrix3x4fv(program, location, count, transpose, value)
    return lib.raia_gl_program_uniform_matrix_3x4fv(program, location, count, transpose, value)
end

function GLES.programUniformMatrix4x3fv(program, location, count, transpose, value)
    return lib.raia_gl_program_uniform_matrix_4x3fv(program, location, count, transpose, value)
end

function GLES.validateProgramPipeline(pipeline)
    return lib.raia_gl_validate_program_pipeline(pipeline)
end

function GLES.getProgramPipelineInfoLog(pipeline, bufSize, length, infoLog)
    return lib.raia_gl_get_program_pipeline_info_log(pipeline, bufSize, length, infoLog)
end

function GLES.bindImageTexture(unit, texture, level, layered, layer, access, format)
    return lib.raia_gl_bind_image_texture(unit, texture, level, layered, layer, access, format)
end

function GLES.getBooleani_v(target, index, data)
    raia_gl_get_boolean_i_v(target, index, data)
end

function GLES.memoryBarrier(barriers)
    return lib.raia_gl_memory_barrier(barriers)
end

function GLES.memoryBarrierByRegion(barriers)
    return lib.raia_gl_memory_barrier_by_region(barriers)
end

function GLES.texStorage2DMultisample(target, samples, internalformat, width, height, fixedsamplelocations)
    return lib.raia_gl_tex_storage_2d_multisample(target, samples, internalformat, width, height, fixedsamplelocations)
end

function GLES.getMultisamplefv(pname, index, val)
    return lib.raia_gl_get_multisample_fv(pname, index, val)
end

function GLES.sampleMaski(maskNumber, mask)
    return lib.raia_gl_sample_mask_i(maskNumber, mask)
end

function GLES.getTexLevelParameteriv(target, level, pname, params)
    return lib.raia_gl_get_tex_level_parameter_iv(target, level, pname, params)
end

function GLES.getTexLevelParameterfv(target, level, pname, params)
    return lib.raia_gl_get_tex_level_parameter_fv(target, level, pname, params)
end

function GLES.bindVertexBuffer(bindingindex, buffer, offset, stride)
    return lib.raia_gl_bind_vertex_buffer(bindingindex, buffer, offset, stride)
end

function GLES.vertexAttribFormat(attribindex, size, type, normalized, relativeoffset)
    return lib.raia_gl_vertex_attrib_format(attribindex, size, type, normalized, relativeoffset)
end

function GLES.vertexAttribIFormat(attribindex, size, type, relativeoffset)
    return lib.raia_gl_vertex_attrib_i_format(attribindex, size, type, relativeoffset)
end

function GLES.vertexAttribBinding(attribindex, bindingindex)
    return lib.raia_gl_vertex_attrib_binding(attribindex, bindingindex)
end

function GLES.vertexBindingDivisor(bindingindex, divisor)
    return lib.raia_gl_vertex_binding_divisor(bindingindex, divisor)
end

-- GL ES 3.2

function GLES.blendBarrier()
    lib.raia_gl_blend_barrier()
end

function GLES.copyImageSubData(srcName, srcTarget, srcLevel, srcX, srcY, srcZ, dstName, dstTarget, dstLevel, dstX, dstY, dstZ, srcWidth, srcHeight, srcDepth)
    return lib.raia_gl_copy_image_sub_data(srcName, srcTarget, srcLevel, srcX, srcY, srcZ, dstName, dstTarget, dstLevel, dstX, dstY, dstZ, srcWidth, srcHeight, srcDepth)
end

function GLES.debugMessageControl(source, type, severity, count, ids, enabled)
    return lib.raia_gl_debug_message_control(source, type, severity, count, ids, enabled)
end

function GLES.debugMessageInsert(source, type, id, severity, length, buf)
    return lib.raia_gl_debug_message_insert(source, type, id, severity, length, buf)
end

function GLES.debugMessageCallback(callback, userParam)
    return lib.raia_gl_debug_message_callback(callback, userParam)
end

function GLES.getDebugMessageLog(count, bufSize, sources, types, ids, severities, lengths, messageLog)
    return lib.raia_gl_get_debug_message_log(count, bufSize, sources, types, ids, severities, lengths, messageLog)
end

function GLES.pushDebugGroup(source, id, length, message)
    return lib.raia_gl_push_debug_group(source, id, length, message)
end

function GLES.popDebugGroup()
    lib.raia_gl_pop_debug_group()
end

function GLES.objectLabel(identifier, name, length, label)
    return lib.raia_gl_object_label(identifier, name, length, label)
end

function GLES.getObjectLabel(identifier, name, bufSize, length, label)
    return lib.raia_gl_get_object_label(identifier, name, bufSize, length, label)
end

function GLES.objectPtrLabel(ptr, length, label)
    return lib.raia_gl_object_ptr_label(ptr, length, label)
end

function GLES.getObjectPtrLabel(ptr, bufSize, length, label)
    return lib.raia_gl_get_object_ptr_label(ptr, bufSize, length, label)
end

function GLES.getPointerv(pname, params)
    return lib.raia_gl_get_pointer_v(pname, params)
end

function GLES.enablei(target, index)
    return lib.raia_gl_enable_i(target, index)
end

function GLES.disablei(target, index)
    return lib.raia_gl_disable_i(target, index)
end

function GLES.blendEquationi(buf, mode)
    return lib.raia_gl_blend_equation_i(buf, mode)
end

function GLES.blendEquationSeparatei(buf, modeRGB, modeAlpha)
    return lib.raia_gl_blend_equation_separate_i(buf, modeRGB, modeAlpha)
end

function GLES.blendFunci(buf, src, dst)
    return lib.raia_gl_blend_func_i(buf, src, dst)
end

function GLES.blendFuncSeparatei(buf, srcRGB, dstRGB, srcAlpha, dstAlpha)
    return lib.raia_gl_blend_func_separate_i(buf, srcRGB, dstRGB, srcAlpha, dstAlpha)
end

function GLES.colorMaski(index, r, g, b, a)
    return lib.raia_gl_color_mask_i(index, r, g, b, a)
end

function GLES.isEnabledi(target, index)
    return lib.raia_gl_is_enabled_i(target, index)
end

function GLES.drawElementsBaseVertex(mode, count, type, indices, basevertex)
    return lib.raia_gl_draw_elements_base_vertex(mode, count, type, indices, basevertex)
end

function GLES.drawRangeElementsBaseVertex(mode, start, _end, count, type, indices, basevertex)
    return lib.raia_gl_draw_range_elements_base_vertex(mode, start, _end, count, type, indices, basevertex)
end

function GLES.drawElementsInstancedBaseVertex(mode, count, type, indices, instancecount, basevertex)
    return lib.raia_gl_draw_elements_instanced_base_vertex(mode, count, type, indices, instancecount, basevertex)
end

function GLES.framebufferTexture(target, attachment, texture, level)
    return lib.raia_gl_framebuffer_texture(target, attachment, texture, level)
end

function GLES.primitiveBoundingBox(minX, minY, minZ, minW, maxX, maxY, maxZ, maxW)
    return lib.raia_gl_primitive_bounding_box(minX, minY, minZ, minW, maxX, maxY, maxZ, maxW)
end

function GLES.getGraphicsResetStatus()
    lib.raia_gl_get_graphics_reset_status()
end

function GLES.readnPixels(x, y, width, height, format, type, bufSize, data)
    return lib.raia_gl_read_n_pixels(x, y, width, height, format, type, bufSize, data)
end

function GLES.getnUniformfv(program, location, bufSize, params)
    return lib.raia_gl_get_n_uniform_fv(program, location, bufSize, params)
end

function GLES.getnUniformiv(program, location, bufSize, params)
    return lib.raia_gl_get_n_uniform_iv(program, location, bufSize, params)
end

function GLES.getnUniformuiv(program, location, bufSize, params)
    return lib.raia_gl_get_n_uniform_uiv(program, location, bufSize, params)
end

function GLES.minSampleShading(value)
    return lib.raia_gl_min_sample_shading(value)
end

function GLES.patchParameteri(pname, value)
    return lib.raia_gl_patch_parameter_i(pname, value)
end

function GLES.texParameterIiv(target, pname, params)
    return lib.raia_gl_tex_parameter_iiv(target, pname, params)
end

function GLES.texParameterIuiv(target, pname, params)
    return lib.raia_gl_tex_parameter_iuiv(target, pname, params)
end

function GLES.getTexParameterIiv(target, pname, params)
    return lib.raia_gl_get_tex_parameter_iiv(target, pname, params)
end

function GLES.getTexParameterIuiv(target, pname, params)
    return lib.raia_gl_get_tex_parameter_iuiv(target, pname, params)
end

function GLES.samplerParameterIiv(sampler, pname, param)
    return lib.raia_gl_sampler_parameter_iiv(sampler, pname, param)
end

function GLES.samplerParameterIuiv(sampler, pname, param)
    return lib.raia_gl_sampler_parameter_iuiv(sampler, pname, param)
end

function GLES.getSamplerParameterIiv(sampler, pname, params)
    return lib.raia_gl_get_sampler_parameter_iiv(sampler, pname, params)
end

function GLES.getSamplerParameterIuiv(sampler, pname, params)
    return lib.raia_gl_get_sampler_parameter_iuiv(sampler, pname, params)
end

function GLES.texBuffer(target, internalformat, buffer)
    return lib.raia_gl_tex_buffer(target, internalformat, buffer)
end

function GLES.texBufferRange(target, internalformat, buffer, offset, size)
    return lib.raia_gl_tex_buffer_range(target, internalformat, buffer, offset, size)
end

function GLES.texStorage3DMultisample(target, samples, internalformat, width, height, depth, fixedsamplelocations)
    return lib.raia_gl_tex_storage_3d_multisample(target, samples, internalformat, width, height, depth, fixedsamplelocations)
end

-- (代替関数)

function GLES.viewportAlt(x, y, width, height)
    return lib.raia_gl_viewport_alt(x, y, width, height)
end

function GLES.clearColorAlt(red, green, blue, alpha)
    return lib.raia_gl_clear_color_alt(red, green, blue, alpha)
end

function GLES.clearAlt(mask)
    return lib.raia_gl_clear_alt(mask)
end

function GLES.useProgramAlt(program)
    return lib.raia_gl_use_program_alt(program)
end

function GLES.vertexAttribPointerAlt(index, size, type, normalized, stride, pointer)
    return lib.raia_gl_vertex_attrib_pointer_alt(index, size, type, normalized, stride, pointer)
end

function GLES.enableVertexAttribArrayAlt(index)
    return lib.raia_gl_enable_vertex_attrib_array_alt(index)
end

function GLES.texImage2DAlt(target, level, internalformat, width, height, border, format, type, pixels)
    return lib.raia_gl_tex_image_2d_alt(target, level, internalformat, width, height, border, format, type, pixels)
end

function GLES.activeTextureAlt(texture)
    return lib.raia_gl_active_texture_alt(texture)
end

function GLES.bindTextureAlt(target, texture)
    return lib.raia_gl_bind_texture_alt(target, texture)
end

function GLES.uniform1iAlt(location, v0)
    return lib.raia_gl_uniform_1i_alt(location, v0)
end

function GLES.drawElementsAlt(mode, count, type, indices)
    return lib.raia_gl_draw_elements_alt(mode, count, type, indices)
end

function GLES.createShaderAlt(type)
    return lib.raia_gl_create_shader_alt(type)
end

function GLES.shaderSourceAlt(shader, count, string, length)
    return lib.raia_gl_shader_source_alt(shader, count, string, length)
end

function GLES.compileShaderAlt(shader)
    return lib.raia_gl_compile_shader_alt(shader)
end

function GLES.getShaderivAlt(shader, pname)
    return lib.raia_gl_get_shader_iv_alt(shader, pname)
end

function GLES.createProgramAlt()
    lib.raia_gl_create_program_alt()
end

function GLES.attachShaderAlt(program, shader)
    return lib.raia_gl_attach_shader_alt(program, shader)
end

function GLES.deleteShaderAlt(shader)
    return lib.raia_gl_delete_shader_alt(shader)
end

function GLES.linkProgramAlt(program)
    return lib.raia_gl_link_program_alt(program)
end

function GLES.pixelStoreiAlt(pname, param)
    return lib.raia_gl_pixel_store_i_alt(pname, param)
end

function GLES.genTexturesAlt(n)
    return lib.raia_gl_gen_textures_alt(n)
end

function GLES.texParameteriAlt(target, pname, param)
    return lib.raia_gl_tex_parameter_i_alt(target, pname, param)
end

function GLES.getAttribLocationAlt(program, name)
    return lib.raia_gl_get_attrib_location_alt(program, name)
end

function GLES.getUniformLocationAlt(program, name)
    return lib.raia_gl_get_uniform_location_alt(program, name)
end

function GLES.genVertexArraysAlt(n)
    return lib.raia_gl_gen_vertex_arrays_alt(n)
end

function GLES.genBuffersAlt(n)
    return lib.raia_gl_gen_buffers_alt(n)
end

function GLES.bindVertexArrayAlt(array)
    return lib.raia_gl_bind_vertex_array_alt(array)
end

function GLES.bindBufferAlt(target, buffer)
    return lib.raia_gl_bind_buffer_alt(target, buffer)
end

function GLES.bufferDataAlt(target, size, data, usage)
    return lib.raia_gl_buffer_data_alt(target, size, data, usage)
end

function GLES.deleteVertexArraysAlt(arrays)
    return lib.raia_gl_delete_vertex_arrays_alt(arrays)
end

function GLES.deleteBuffersAlt(buffers)
    return lib.raia_gl_delete_buffers_alt(buffers)
end

function GLES.deleteTexturesAlt(textures)
    return lib.raia_gl_delete_textures_alt(textures)
end

return GLES