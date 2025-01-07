import Foundation

extension GLES {

    // MARK: GL ES 2.0

    static func activeTexture(texture: Int) {
        raia_gl_active_texture(GLenum(texture))
    }
    
    static func attachShader(program: Int, shader: Int) {
        raia_gl_attach_shader(GLuint(program), GLuint(shader))
    }
    
    static func bindAttribLocation(program: Int, index: Int, name: String) {
        raia_gl_bind_attrib_location(GLuint(program), GLuint(index), name)
    }
    
    static func bindBuffer(target: Int, buffer: Int) {
        raia_gl_bind_buffer(GLenum(target), GLuint(buffer))
    }
    
    static func bindFramebuffer(target: Int, framebuffer: Int) {
        raia_gl_bind_framebuffer(GLenum(target), GLuint(framebuffer))
    }
    
    static func bindRenderbuffer(target: Int, renderbuffer: Int) {
        raia_gl_bind_renderbuffer(GLenum(target), GLuint(renderbuffer))
    }
    
    static func bindTexture(target: Int, texture: Int) {
        raia_gl_bind_texture(GLenum(target), GLuint(texture))
    }
    
    static func blendColor(red: Float, green: Float, blue: Float, alpha: Float) {
        raia_gl_blend_color(red, green, blue, alpha)
    }
    
    static func blendEquation(mode: Int) {
        raia_gl_blend_equation(GLenum(mode))
    }
    
    static func blendEquationSeparate(modeRGB: Int, modeAlpha: Int) {
        raia_gl_blend_equation_separate(GLenum(modeRGB), GLenum(modeAlpha))
    }
    
    static func blendFunc(sfactor: Int, dfactor: Int) {
        raia_gl_blend_func(GLenum(sfactor), GLenum(dfactor))
    }
    
    static func blendFuncSeparate(sfactorRGB: Int, dfactorRGB: Int, sfactorAlpha: Int, dfactorAlpha: Int) {
        raia_gl_blend_func_separate(GLenum(sfactorRGB), GLenum(dfactorRGB), GLenum(sfactorAlpha), GLenum(dfactorAlpha))
    }
    
    static func bufferData(target: Int, size: Int, data: UnsafeRawPointer?, usage: Int) {
        raia_gl_buffer_data(GLenum(target), GLsizeiptr(size), data, GLenum(usage))
    }
    
    static func bufferSubData(target: Int, offset: Int, size: Int, data: UnsafeRawPointer?) {
        raia_gl_buffer_sub_data(GLenum(target), GLintptr(offset), GLsizeiptr(size), data)
    }
    
    static func checkFramebufferStatus(target: Int) -> Int {
        return Int(raia_gl_check_framebuffer_status(GLenum(target)))
    }
    
    static func clear(mask: Int) {
        raia_gl_clear(GLbitfield(mask))
    }
    
    static func clearColor(red: Float, green: Float, blue: Float, alpha: Float) {
        raia_gl_clear_color(red, green, blue, alpha)
    }
    
    static func clearDepthf(depth: Float) {
        raia_gl_clear_depth_f(depth)
    }
    
    static func clearStencil(s: Int) {
        raia_gl_clear_stencil(GLint(s))
    }
    
    static func colorMask(red: Bool, green: Bool, blue: Bool, alpha: Bool) {
        raia_gl_color_mask(GLboolean(red ? 1 : 0), GLboolean(green ? 1 : 0), GLboolean(blue ? 1 : 0), GLboolean(alpha ? 1 : 0))
    }
    
    static func compileShader(shader: Int) {
        raia_gl_compile_shader(GLuint(shader))
    }
    
    static func compressedTexImage2D(target: Int, level: Int, internalFormat: Int, width: Int, height: Int, border: Int, imageSize: Int, data: UnsafeRawPointer?) {
        raia_gl_compressed_tex_image_2d(GLenum(target), GLint(level), GLenum(internalFormat), GLsizei(width), GLsizei(height), GLint(border), GLsizei(imageSize), data)
    }
    
    static func compressedTexSubImage2D(target: Int, level: Int, xoffset: Int, yoffset: Int, width: Int, height: Int, format: Int, imageSize: Int, data: UnsafeRawPointer?) {
        raia_gl_compressed_tex_sub_image_2d(GLenum(target), GLint(level), GLint(xoffset), GLint(yoffset), GLsizei(width), GLsizei(height), GLenum(format), GLsizei(imageSize), data)
    }
    
    static func copyTexImage2D(target: Int, level: Int, internalFormat: Int, x: Int, y: Int, width: Int, height: Int, border: Int) {
        raia_gl_copy_tex_image_2d(GLenum(target), GLint(level), GLenum(internalFormat), GLint(x), GLint(y), GLsizei(width), GLsizei(height), GLint(border))
    }
    
    static func copyTexSubImage2D(target: Int, level: Int, xoffset: Int, yoffset: Int, x: Int, y: Int, width: Int, height: Int) {
        raia_gl_copy_tex_sub_image_2d(GLenum(target), GLint(level), GLint(xoffset), GLint(yoffset), GLint(x), GLint(y), GLsizei(width), GLsizei(height))
    }

    static func createProgram() -> Int {
        return Int(raia_gl_create_program())
    }
    
    static func createShader(type: Int) -> Int {
        return Int(raia_gl_create_shader(GLenum(type)))
    }
    
    static func cullFace(mode: Int) {
        raia_gl_cull_face(GLenum(mode))
    }
    
    static func deleteBuffers(n: Int, buffers: UnsafePointer<UInt32>) {
        raia_gl_delete_buffers(GLsizei(n), buffers)
    }
    
    static func deleteFramebuffers(n: Int, framebuffers: UnsafePointer<UInt32>) {
        raia_gl_delete_framebuffers(GLsizei(n), framebuffers)
    }
    
    static func deleteProgram(program: Int) {
        raia_gl_delete_program(GLuint(program))
    }
    
    static func deleteRenderbuffers(n: Int, renderbuffers: UnsafePointer<UInt32>) {
        raia_gl_delete_renderbuffers(GLsizei(n), renderbuffers)
    }
    
    static func deleteShader(shader: Int) {
        raia_gl_delete_shader(GLuint(shader))
    }
    
    static func deleteTextures(n: Int, textures: UnsafePointer<UInt32>) {
        raia_gl_delete_textures(GLsizei(n), textures)
    }
    
    static func depthFunc(func_: Int) {
        raia_gl_depth_func(GLenum(func_))
    }
    
    static func depthMask(flag: Bool) {
        raia_gl_depth_mask(GLboolean(flag ? 1 : 0))
    }
    
    static func depthRangef(n: Float, f: Float) {
        raia_gl_depth_range_f(n, f)
    }
    
    static func detachShader(program: Int, shader: Int) {
        raia_gl_detach_shader(GLuint(program), GLuint(shader))
    }
    
    static func disable(cap: Int) {
        raia_gl_disable(GLenum(cap))
    }
    
    static func disableVertexAttribArray(index: Int) {
        raia_gl_disable_vertex_attrib_array(GLuint(index))
    }
    
    static func drawArrays(mode: Int, first: Int, count: Int) {
        raia_gl_draw_arrays(GLenum(mode), GLint(first), GLsizei(count))
    }
    
    static func drawElements(mode: Int, count: Int, type: Int, indices: UnsafeRawPointer?) {
        raia_gl_draw_elements(GLenum(mode), GLsizei(count), GLenum(type), indices)
    }
    
    static func enable(cap: Int) {
        raia_gl_enable(GLenum(cap))
    }
    
    static func enableVertexAttribArray(index: Int) {
        raia_gl_enable_vertex_attrib_array(GLuint(index))
    }
    
    static func finish() {
        raia_gl_finish()
    }
    
    static func flush() {
        raia_gl_flush()
    }
    
    static func framebufferRenderbuffer(target: Int, attachment: Int, renderbufferTarget: Int, renderbuffer: Int) {
        raia_gl_framebuffer_renderbuffer(GLenum(target), GLenum(attachment), GLenum(renderbufferTarget), GLuint(renderbuffer))
    }
    
    static func framebufferTexture2D(target: Int, attachment: Int, textureTarget: Int, texture: Int, level: Int) {
        raia_gl_framebuffer_texture_2d(GLenum(target), GLenum(attachment), GLenum(textureTarget), GLuint(texture), GLint(level))
    }
    
    static func frontFace(mode: Int) {
        raia_gl_front_face(GLenum(mode))
    }

    static func genBuffers(n: Int, buffers: UnsafeMutablePointer<UInt32>) {
        raia_gl_gen_buffers(GLsizei(n), buffers)
    }
    
    static func generateMipmap(target: Int) {
        raia_gl_generate_mipmap(GLenum(target))
    }
    
    static func genFramebuffers(n: Int, framebuffers: UnsafeMutablePointer<UInt32>) {
        raia_gl_gen_framebuffers(GLsizei(n), framebuffers)
    }
    
    static func genRenderbuffers(n: Int, renderbuffers: UnsafeMutablePointer<UInt32>) {
        raia_gl_gen_renderbuffers(GLsizei(n), renderbuffers)
    }
    
    static func genTextures(n: Int, textures: UnsafeMutablePointer<UInt32>) {
        raia_gl_gen_textures(GLsizei(n), textures)
    }
    
    static func getActiveAttrib(program: Int, index: Int, bufSize: Int, length: UnsafeMutablePointer<Int32>?, size: UnsafeMutablePointer<Int32>?, type: UnsafeMutablePointer<UInt32>?, name: UnsafeMutablePointer<CChar>) {
        raia_gl_get_active_attrib(GLuint(program), GLuint(index), GLsizei(bufSize), length, size, type, name)
    }
    
    static func getActiveUniform(program: Int, index: Int, bufSize: Int, length: UnsafeMutablePointer<Int32>?, size: UnsafeMutablePointer<Int32>?, type: UnsafeMutablePointer<UInt32>?, name: UnsafeMutablePointer<CChar>) {
        raia_gl_get_active_uniform(GLuint(program), GLuint(index), GLsizei(bufSize), length, size, type, name)
    }
    
    static func getAttachedShaders(program: Int, maxCount: Int, count: UnsafeMutablePointer<Int32>?, shaders: UnsafeMutablePointer<UInt32>) {
        raia_gl_get_attached_shaders(GLuint(program), GLsizei(maxCount), count, shaders)
    }
    
    static func getAttribLocation(program: Int, name: String) -> Int {
        return Int(raia_gl_get_attrib_location(GLuint(program), name))
    }
    
    static func getBooleanv(pname: Int, data: UnsafeMutablePointer<UInt8>) {
        raia_gl_get_boolean_v(GLenum(pname), data)
    }
    
    static func getBufferParameteriv(target: Int, pname: Int, params: UnsafeMutablePointer<Int32>) {
        raia_gl_get_buffer_parameter_iv(GLenum(target), GLenum(pname), params)
    }
    
    static func getError() -> Int {
        return Int(raia_gl_get_error())
    }
    
    static func getFloatv(pname: Int, data: UnsafeMutablePointer<Float>) {
        raia_gl_get_float_v(GLenum(pname), data)
    }
    
    static func getFramebufferAttachmentParameteriv(target: Int, attachment: Int, pname: Int, params: UnsafeMutablePointer<Int32>) {
        raia_gl_get_framebuffer_attachment_parameter_iv(GLenum(target), GLenum(attachment), GLenum(pname), params)
    }
    
    static func getIntegerv(pname: Int, data: UnsafeMutablePointer<Int32>) {
        raia_gl_get_integer_v(GLenum(pname), data)
    }
    
    static func getProgramiv(program: Int, pname: Int, params: UnsafeMutablePointer<Int32>) {
        raia_gl_get_program_iv(GLuint(program), GLenum(pname), params)
    }
    
    static func getProgramInfoLog(program: Int, bufSize: Int, length: UnsafeMutablePointer<Int32>?, infoLog: UnsafeMutablePointer<CChar>) {
        raia_gl_get_program_info_log(GLuint(program), GLsizei(bufSize), length, infoLog)
    }
    
    static func getRenderbufferParameteriv(target: Int, pname: Int, params: UnsafeMutablePointer<Int32>) {
        raia_gl_get_renderbuffer_parameter_iv(GLenum(target), GLenum(pname), params)
    }
    
    static func getShaderiv(shader: Int, pname: Int, params: UnsafeMutablePointer<Int32>) {
        raia_gl_get_shader_iv(GLuint(shader), GLenum(pname), params)
    }
    
    static func getShaderInfoLog(shader: Int, bufSize: Int, length: UnsafeMutablePointer<Int32>?, infoLog: UnsafeMutablePointer<CChar>) {
        raia_gl_get_shader_info_log(GLuint(shader), GLsizei(bufSize), length, infoLog)
    }
    
    static func getShaderPrecisionFormat(shaderType: Int, precisionType: Int, range: UnsafeMutablePointer<Int32>, precision: UnsafeMutablePointer<Int32>) {
        raia_gl_get_shader_precision_format(GLenum(shaderType), GLenum(precisionType), range, precision)
    }
    
    static func getShaderSource(shader: Int, bufSize: Int, length: UnsafeMutablePointer<Int32>?, source: UnsafeMutablePointer<CChar>) {
        raia_gl_get_shader_source(GLuint(shader), GLsizei(bufSize), length, source)
    }

    static func getString(name: Int) -> String? {
        guard let result = raia_gl_get_string(GLenum(name)) else {
            return nil
        }
        return String(cString: result)
    }
    
    static func getTexParameterfv(target: Int, pname: Int, params: UnsafeMutablePointer<Float>) {
        raia_gl_get_tex_parameter_fv(GLenum(target), GLenum(pname), params)
    }
    
    static func getTexParameteriv(target: Int, pname: Int, params: UnsafeMutablePointer<Int32>) {
        raia_gl_get_tex_parameter_iv(GLenum(target), GLenum(pname), params)
    }
    
    static func getUniformfv(program: Int, location: Int, params: UnsafeMutablePointer<Float>) {
        raia_gl_get_uniform_fv(GLuint(program), GLint(location), params)
    }
    
    static func getUniformiv(program: Int, location: Int, params: UnsafeMutablePointer<Int32>) {
        raia_gl_get_uniform_iv(GLuint(program), GLint(location), params)
    }
    
    static func getUniformLocation(program: Int, name: String) -> Int {
        return Int(raia_gl_get_uniform_location(GLuint(program), name))
    }
    
    static func getVertexAttribfv(index: Int, pname: Int, params: UnsafeMutablePointer<Float>) {
        raia_gl_get_vertex_attrib_fv(GLuint(index), GLenum(pname), params)
    }
    
    static func getVertexAttribiv(index: Int, pname: Int, params: UnsafeMutablePointer<Int32>) {
        raia_gl_get_vertex_attrib_iv(GLuint(index), GLenum(pname), params)
    }
    
    static func getVertexAttribPointerv(index: Int, pname: Int, pointer: UnsafeMutablePointer<UnsafeMutableRawPointer?>) {
        raia_gl_get_vertex_attrib_pointer_v(GLuint(index), GLenum(pname), pointer)
    }
    
    static func hint(target: Int, mode: Int) {
        raia_gl_hint(GLenum(target), GLenum(mode))
    }
    
    static func isBuffer(buffer: Int) -> Bool {
        return raia_gl_is_buffer(GLuint(buffer)) == GLboolean(1)
    }
    
    static func isEnabled(cap: Int) -> Bool {
        return raia_gl_is_enabled(GLenum(cap)) == GLboolean(1)
    }
    
    static func isFramebuffer(framebuffer: Int) -> Bool {
        return raia_gl_is_framebuffer(GLuint(framebuffer)) == GLboolean(1)
    }
    
    static func isProgram(program: Int) -> Bool {
        return raia_gl_is_program(GLuint(program)) == GLboolean(1)
    }
    
    static func isRenderbuffer(renderbuffer: Int) -> Bool {
        return raia_gl_is_renderbuffer(GLuint(renderbuffer)) == GLboolean(1)
    }
    
    static func isShader(shader: Int) -> Bool {
        return raia_gl_is_shader(GLuint(shader)) == GLboolean(1)
    }
    
    static func isTexture(texture: Int) -> Bool {
        return raia_gl_is_texture(GLuint(texture)) == GLboolean(1)
    }

    static func lineWidth(width: Float) {
        raia_gl_line_width(width)
    }
    
    static func linkProgram(program: Int) {
        raia_gl_link_program(GLuint(program))
    }
    
    static func pixelStorei(pname: Int, param: Int) {
        raia_gl_pixel_store_i(GLenum(pname), GLint(param))
    }
    
    static func polygonOffset(factor: Float, units: Float) {
        raia_gl_polygon_offset(factor, units)
    }
    
    static func readPixels(x: Int, y: Int, width: Int, height: Int, format: Int, type: Int, pixels: UnsafeMutableRawPointer) {
        raia_gl_read_pixels(GLint(x), GLint(y), GLsizei(width), GLsizei(height), GLenum(format), GLenum(type), pixels)
    }
    
    static func releaseShaderCompiler() {
        raia_gl_release_shader_compiler()
    }
    
    static func renderbufferStorage(target: Int, internalFormat: Int, width: Int, height: Int) {
        raia_gl_renderbuffer_storage(GLenum(target), GLenum(internalFormat), GLsizei(width), GLsizei(height))
    }
    
    static func sampleCoverage(value: Float, invert: Bool) {
        raia_gl_sample_coverage(value, GLboolean(invert ? 1 : 0))
    }
    
    static func scissor(x: Int, y: Int, width: Int, height: Int) {
        raia_gl_scissor(GLint(x), GLint(y), GLsizei(width), GLsizei(height))
    }
    
    static func shaderBinary(count: Int, shaders: UnsafePointer<UInt32>, binaryFormat: Int, binary: UnsafeRawPointer, length: Int) {
        raia_gl_shader_binary(GLsizei(count), shaders, GLenum(binaryFormat), binary, GLsizei(length))
    }
    
    static func shaderSource(shader: Int, count: Int, strings: UnsafePointer<UnsafePointer<CChar>?>, lengths: UnsafePointer<Int32>?) {
        raia_gl_shader_source(GLuint(shader), GLsizei(count), strings, lengths)
    }
    
    static func stencilFunc(func_: Int, ref: Int, mask: Int) {
        raia_gl_stencil_func(GLenum(func_), GLint(ref), GLuint(mask))
    }
    
    static func stencilFuncSeparate(face: Int, func_: Int, ref: Int, mask: Int) {
        raia_gl_stencil_func_separate(GLenum(face), GLenum(func_), GLint(ref), GLuint(mask))
    }
    
    static func stencilMask(mask: Int) {
        raia_gl_stencil_mask(GLuint(mask))
    }
    
    static func stencilMaskSeparate(face: Int, mask: Int) {
        raia_gl_stencil_mask_separate(GLenum(face), GLuint(mask))
    }
    
    static func stencilOp(fail: Int, zFail: Int, zPass: Int) {
        raia_gl_stencil_op(GLenum(fail), GLenum(zFail), GLenum(zPass))
    }
    
    static func stencilOpSeparate(face: Int, sFail: Int, dpFail: Int, dpPass: Int) {
        raia_gl_stencil_op_separate(GLenum(face), GLenum(sFail), GLenum(dpFail), GLenum(dpPass))
    }

    static func texImage2D(target: Int, level: Int, internalFormat: Int, width: Int, height: Int, border: Int, format: Int, type: Int, pixels: UnsafeRawPointer?) {
        raia_gl_tex_image_2d(GLenum(target), GLint(level), GLint(internalFormat), GLsizei(width), GLsizei(height), GLint(border), GLenum(format), GLenum(type), pixels)
    }

    static func texParameterf(target: Int, pname: Int, param: Float) {
        raia_gl_tex_parameter_f(GLenum(target), GLenum(pname), param)
    }

    static func texParameterfv(target: Int, pname: Int, params: UnsafePointer<Float>) {
        raia_gl_tex_parameter_fv(GLenum(target), GLenum(pname), params)
    }

    static func texParameteri(target: Int, pname: Int, param: Int) {
        raia_gl_tex_parameter_i(GLenum(target), GLenum(pname), GLint(param))
    }

    static func texParameteriv(target: Int, pname: Int, params: UnsafePointer<Int32>) {
        raia_gl_tex_parameter_iv(GLenum(target), GLenum(pname), params)
    }

    static func texSubImage2D(target: Int, level: Int, xOffset: Int, yOffset: Int, width: Int, height: Int, format: Int, type: Int, pixels: UnsafeRawPointer?) {
        raia_gl_tex_sub_image_2d(GLenum(target), GLint(level), GLint(xOffset), GLint(yOffset), GLsizei(width), GLsizei(height), GLenum(format), GLenum(type), pixels)
    }

    static func uniform1f(location: Int, v0: Float) {
        raia_gl_uniform_1f(GLint(location), v0)
    }

    static func uniform1fv(location: Int, count: Int, value: UnsafePointer<Float>) {
        raia_gl_uniform_1fv(GLint(location), GLsizei(count), value)
    }

    static func uniform1i(location: Int, v0: Int) {
        raia_gl_uniform_1i(GLint(location), GLint(v0))
    }

    static func uniform1iv(location: Int, count: Int, value: UnsafePointer<Int32>) {
        raia_gl_uniform_1iv(GLint(location), GLsizei(count), value)
    }

    static func uniform2f(location: Int, v0: Float, v1: Float) {
        raia_gl_uniform_2f(GLint(location), v0, v1)
    }

    static func uniform2fv(location: Int, count: Int, value: UnsafePointer<Float>) {
        raia_gl_uniform_2fv(GLint(location), GLsizei(count), value)
    }

    static func uniform2i(location: Int, v0: Int, v1: Int) {
        raia_gl_uniform_2i(GLint(location), GLint(v0), GLint(v1))
    }

    static func uniform2iv(location: Int, count: Int, value: UnsafePointer<Int32>) {
        raia_gl_uniform_2iv(GLint(location), GLsizei(count), value)
    }

    static func uniform3f(location: Int, v0: Float, v1: Float, v2: Float) {
        raia_gl_uniform_3f(GLint(location), v0, v1, v2)
    }

    static func uniform3fv(location: Int, count: Int, value: UnsafePointer<Float>) {
        raia_gl_uniform_3fv(GLint(location), GLsizei(count), value)
    }

    static func uniform3i(location: Int, v0: Int, v1: Int, v2: Int) {
        raia_gl_uniform_3i(GLint(location), GLint(v0), GLint(v1), GLint(v2))
    }

    static func uniform3iv(location: Int, count: Int, value: UnsafePointer<Int32>) {
        raia_gl_uniform_3iv(GLint(location), GLsizei(count), value)
    }

    static func uniform4f(location: Int, v0: Float, v1: Float, v2: Float, v3: Float) {
        raia_gl_uniform_4f(GLint(location), v0, v1, v2, v3)
    }

    static func uniform4fv(location: Int, count: Int, value: UnsafePointer<Float>) {
        raia_gl_uniform_4fv(GLint(location), GLsizei(count), value)
    }

    static func uniform4i(location: Int, v0: Int, v1: Int, v2: Int, v3: Int) {
        raia_gl_uniform_4i(GLint(location), GLint(v0), GLint(v1), GLint(v2), GLint(v3))
    }

    static func uniform4iv(location: Int, count: Int, value: UnsafePointer<Int32>) {
        raia_gl_uniform_4iv(GLint(location), GLsizei(count), value)
    }

    static func uniformMatrix2fv(location: Int, count: Int, transpose: Bool, value: UnsafePointer<Float>) {
        raia_gl_uniform_matrix_2fv(GLint(location), GLsizei(count), GLboolean(transpose ? 1 : 0), value)
    }

    static func uniformMatrix3fv(location: Int, count: Int, transpose: Bool, value: UnsafePointer<Float>) {
        raia_gl_uniform_matrix_3fv(GLint(location), GLsizei(count), GLboolean(transpose ? 1 : 0), value)
    }

    static func uniformMatrix4fv(location: Int, count: Int, transpose: Bool, value: UnsafePointer<Float>) {
        raia_gl_uniform_matrix_4fv(GLint(location), GLsizei(count), GLboolean(transpose ? 1 : 0), value)
    }

    static func useProgram(program: Int) {
        raia_gl_use_program(GLuint(program))
    }
    
    static func validateProgram(program: Int) {
        raia_gl_validate_program(GLuint(program))
    }
    
    static func vertexAttrib1f(index: Int, x: Float) {
        raia_gl_vertex_attrib_1f(GLuint(index), x)
    }
    
    static func vertexAttrib1fv(index: Int, v: UnsafePointer<Float>) {
        raia_gl_vertex_attrib_1fv(GLuint(index), v)
    }
    
    static func vertexAttrib2f(index: Int, x: Float, y: Float) {
        raia_gl_vertex_attrib_2f(GLuint(index), x, y)
    }
    
    static func vertexAttrib2fv(index: Int, v: UnsafePointer<Float>) {
        raia_gl_vertex_attrib_2fv(GLuint(index), v)
    }
    
    static func vertexAttrib3f(index: Int, x: Float, y: Float, z: Float) {
        raia_gl_vertex_attrib_3f(GLuint(index), x, y, z)
    }
    
    static func vertexAttrib3fv(index: Int, v: UnsafePointer<Float>) {
        raia_gl_vertex_attrib_3fv(GLuint(index), v)
    }
    
    static func vertexAttrib4f(index: Int, x: Float, y: Float, z: Float, w: Float) {
        raia_gl_vertex_attrib_4f(GLuint(index), x, y, z, w)
    }
    
    static func vertexAttrib4fv(index: Int, v: UnsafePointer<Float>) {
        raia_gl_vertex_attrib_4fv(GLuint(index), v)
    }
    
    static func vertexAttribPointer(index: Int, size: Int, type: Int, normalized: Bool, stride: Int, pointer: UnsafeRawPointer?) {
        raia_gl_vertex_attrib_pointer(GLuint(index), GLint(size), GLenum(type), GLboolean(normalized ? 1 : 0), GLsizei(stride), pointer)
    }
    
    static func viewport(x: Int, y: Int, width: Int, height: Int) {
        raia_gl_viewport(GLint(x), GLint(y), GLsizei(width), GLsizei(height))
    }

    // MARK: GL ES 3.0

    static func readBuffer(src: Int) {
        raia_gl_read_buffer(GLenum(src))
    }
    
    static func drawRangeElements(mode: Int, start: Int, end: Int, count: Int, type: Int, indices: UnsafeRawPointer?) {
        raia_gl_draw_range_elements(GLenum(mode), GLuint(start), GLuint(end), GLsizei(count), GLenum(type), indices)
    }
    
    static func texImage3D(target: Int, level: Int, internalFormat: Int, width: Int, height: Int, depth: Int, border: Int, format: Int, type: Int, pixels: UnsafeRawPointer?) {
        raia_gl_tex_image_3d(GLenum(target), GLint(level), GLint(internalFormat), GLsizei(width), GLsizei(height), GLsizei(depth), GLint(border), GLenum(format), GLenum(type), pixels)
    }
    
    static func texSubImage3D(target: Int, level: Int, xOffset: Int, yOffset: Int, zOffset: Int, width: Int, height: Int, depth: Int, format: Int, type: Int, pixels: UnsafeRawPointer?) {
        raia_gl_tex_sub_image_3d(GLenum(target), GLint(level), GLint(xOffset), GLint(yOffset), GLint(zOffset), GLsizei(width), GLsizei(height), GLsizei(depth), GLenum(format), GLenum(type), pixels)
    }
    
    static func copyTexSubImage3D(target: Int, level: Int, xOffset: Int, yOffset: Int, zOffset: Int, x: Int, y: Int, width: Int, height: Int) {
        raia_gl_copy_tex_sub_image_3d(GLenum(target), GLint(level), GLint(xOffset), GLint(yOffset), GLint(zOffset), GLint(x), GLint(y), GLsizei(width), GLsizei(height))
    }
    
    static func compressedTexImage3D(target: Int, level: Int, internalFormat: Int, width: Int, height: Int, depth: Int, border: Int, imageSize: Int, data: UnsafeRawPointer?) {
        raia_gl_compressed_tex_image_3d(GLenum(target), GLint(level), GLenum(internalFormat), GLsizei(width), GLsizei(height), GLsizei(depth), GLint(border), GLsizei(imageSize), data)
    }
    
    static func compressedTexSubImage3D(target: Int, level: Int, xOffset: Int, yOffset: Int, zOffset: Int, width: Int, height: Int, depth: Int, format: Int, imageSize: Int, data: UnsafeRawPointer?) {
        raia_gl_compressed_tex_sub_image_3d(GLenum(target), GLint(level), GLint(xOffset), GLint(yOffset), GLint(zOffset), GLsizei(width), GLsizei(height), GLsizei(depth), GLenum(format), GLsizei(imageSize), data)
    }
    
    static func genQueries(n: Int, ids: UnsafeMutablePointer<UInt32>) {
        raia_gl_gen_queries(GLsizei(n), ids)
    }
    
    static func deleteQueries(n: Int, ids: UnsafePointer<UInt32>) {
        raia_gl_delete_queries(GLsizei(n), ids)
    }
    
    static func isQuery(id: Int) -> Bool {
        return raia_gl_is_query(GLuint(id)) == GLboolean(1)
    }
    
    static func beginQuery(target: Int, id: Int) {
        raia_gl_begin_query(GLenum(target), GLuint(id))
    }
    
    static func endQuery(target: Int) {
        raia_gl_end_query(GLenum(target))
    }
    
    static func getQueryiv(target: Int, pname: Int, params: UnsafeMutablePointer<Int32>) {
        raia_gl_get_query_iv(GLenum(target), GLenum(pname), params)
    }
    
    static func getQueryObjectuiv(id: Int, pname: Int, params: UnsafeMutablePointer<UInt32>) {
        raia_gl_get_query_object_uiv(GLuint(id), GLenum(pname), params)
    }
    
    static func unmapBuffer(target: Int) -> Bool {
        return raia_gl_unmap_buffer(GLenum(target)) == GLboolean(1)
    }
    
    static func getBufferPointerv(target: Int, pname: Int, params: UnsafeMutablePointer<UnsafeMutableRawPointer?>) {
        raia_gl_get_buffer_pointer_v(GLenum(target), GLenum(pname), params)
    }
    
    static func drawBuffers(n: Int, bufs: UnsafePointer<UInt32>) {
        raia_gl_draw_buffers(GLsizei(n), bufs)
    }

    static func uniformMatrix2x3fv(location: Int, count: Int, transpose: Bool, value: UnsafePointer<Float>) {
        raia_gl_uniform_matrix_2x3fv(GLint(location), GLsizei(count), GLboolean(transpose ? 1 : 0), value)
    }

    static func uniformMatrix3x2fv(location: Int, count: Int, transpose: Bool, value: UnsafePointer<Float>) {
        raia_gl_uniform_matrix_3x2fv(GLint(location), GLsizei(count), GLboolean(transpose ? 1 : 0), value)
    }

    static func uniformMatrix2x4fv(location: Int, count: Int, transpose: Bool, value: UnsafePointer<Float>) {
        raia_gl_uniform_matrix_2x4fv(GLint(location), GLsizei(count), GLboolean(transpose ? 1 : 0), value)
    }

    static func uniformMatrix4x2fv(location: Int, count: Int, transpose: Bool, value: UnsafePointer<Float>) {
        raia_gl_uniform_matrix_4x2fv(GLint(location), GLsizei(count), GLboolean(transpose ? 1 : 0), value)
    }

    static func uniformMatrix3x4fv(location: Int, count: Int, transpose: Bool, value: UnsafePointer<Float>) {
        raia_gl_uniform_matrix_3x4fv(GLint(location), GLsizei(count), GLboolean(transpose ? 1 : 0), value)
    }

    static func uniformMatrix4x3fv(location: Int, count: Int, transpose: Bool, value: UnsafePointer<Float>) {
        raia_gl_uniform_matrix_4x3fv(GLint(location), GLsizei(count), GLboolean(transpose ? 1 : 0), value)
    }

    static func blitFramebuffer(srcX0: Int, srcY0: Int, srcX1: Int, srcY1: Int, dstX0: Int, dstY0: Int, dstX1: Int, dstY1: Int, mask: Int, filter: Int) {
        raia_gl_blit_framebuffer(GLint(srcX0), GLint(srcY0), GLint(srcX1), GLint(srcY1), GLint(dstX0), GLint(dstY0), GLint(dstX1), GLint(dstY1), GLbitfield(mask), GLenum(filter))
    }

    static func renderbufferStorageMultisample(target: Int, samples: Int, internalFormat: Int, width: Int, height: Int) {
        raia_gl_renderbuffer_storage_multisample(GLenum(target), GLsizei(samples), GLenum(internalFormat), GLsizei(width), GLsizei(height))
    }

    static func framebufferTextureLayer(target: Int, attachment: Int, texture: Int, level: Int, layer: Int) {
        raia_gl_framebuffer_texture_layer(GLenum(target), GLenum(attachment), GLuint(texture), GLint(level), GLint(layer))
    }

    static func mapBufferRange(target: Int, offset: Int, length: Int, access: Int) -> UnsafeMutableRawPointer? {
        return raia_gl_map_buffer_range(GLenum(target), GLintptr(offset), GLsizeiptr(length), GLbitfield(access))
    }

    static func flushMappedBufferRange(target: Int, offset: Int, length: Int) {
        raia_gl_flush_mapped_buffer_range(GLenum(target), GLintptr(offset), GLsizeiptr(length))
    }

    static func bindVertexArray(array: Int) {
        raia_gl_bind_vertex_array(GLuint(array))
    }

    static func deleteVertexArrays(n: Int, arrays: UnsafePointer<UInt32>) {
        raia_gl_delete_vertex_arrays(GLsizei(n), arrays)
    }

    static func genVertexArrays(n: Int, arrays: UnsafeMutablePointer<UInt32>) {
        raia_gl_gen_vertex_arrays(GLsizei(n), arrays)
    }

    static func isVertexArray(array: Int) -> Bool {
        return raia_gl_is_vertex_array(GLuint(array)) == GLboolean(1)
    }

    static func getIntegeri_v(target: Int, index: Int, data: UnsafeMutablePointer<Int32>) {
        raia_gl_get_integer_i_v(GLenum(target), GLuint(index), data)
    }

    static func beginTransformFeedback(primitiveMode: Int) {
        raia_gl_begin_transform_feedback(GLenum(primitiveMode))
    }

    static func endTransformFeedback() {
        raia_gl_end_transform_feedback()
    }

    static func bindBufferRange(target: Int, index: Int, buffer: Int, offset: Int, size: Int) {
        raia_gl_bind_buffer_range(GLenum(target), GLuint(index), GLuint(buffer), GLintptr(offset), GLsizeiptr(size))
    }

    static func bindBufferBase(target: Int, index: Int, buffer: Int) {
        raia_gl_bind_buffer_base(GLenum(target), GLuint(index), GLuint(buffer))
    }

    static func transformFeedbackVaryings(program: Int, count: Int, varyings: UnsafePointer<UnsafePointer<CChar>?>, bufferMode: Int) {
        raia_gl_transform_feedback_varyings(GLuint(program), GLsizei(count), varyings, GLenum(bufferMode))
    }

    static func getTransformFeedbackVarying(program: Int, index: Int, bufSize: Int, length: UnsafeMutablePointer<Int32>?, size: UnsafeMutablePointer<Int32>?, type: UnsafeMutablePointer<UInt32>?, name: UnsafeMutablePointer<CChar>) {
        raia_gl_get_transform_feedback_varying(GLuint(program), GLuint(index), GLsizei(bufSize), length, size, type, name)
    }

    static func vertexAttribIPointer(index: Int, size: Int, type: Int, stride: Int, pointer: UnsafeRawPointer?) {
        raia_gl_vertex_attrib_i_pointer(GLuint(index), GLint(size), GLenum(type), GLsizei(stride), pointer)
    }

    static func getVertexAttribIiv(index: Int, pname: Int, params: UnsafeMutablePointer<Int32>) {
        raia_gl_get_vertex_attrib_iiv(GLuint(index), GLenum(pname), params)
    }

    static func getVertexAttribIuiv(index: Int, pname: Int, params: UnsafeMutablePointer<UInt32>) {
        raia_gl_get_vertex_attrib_iuiv(GLuint(index), GLenum(pname), params)
    }

    static func vertexAttribI4i(index: Int, x: Int, y: Int, z: Int, w: Int) {
        raia_gl_vertex_attrib_i4i(GLuint(index), GLint(x), GLint(y), GLint(z), GLint(w))
    }

    static func vertexAttribI4ui(index: Int, x: UInt32, y: UInt32, z: UInt32, w: UInt32) {
        raia_gl_vertex_attrib_i4ui(GLuint(index), GLuint(x), GLuint(y), GLuint(z), GLuint(w))
    }

    static func vertexAttribI4iv(index: Int, v: UnsafePointer<Int32>) {
        raia_gl_vertex_attrib_i4iv(GLuint(index), v)
    }

    static func vertexAttribI4uiv(index: Int, v: UnsafePointer<UInt32>) {
        raia_gl_vertex_attrib_i4uiv(GLuint(index), v)
    }

    static func getUniformuiv(program: Int, location: Int, params: UnsafeMutablePointer<UInt32>) {
        raia_gl_get_uniform_uiv(GLuint(program), GLint(location), params)
    }

    static func getFragDataLocation(program: Int, name: String) -> Int {
        return Int(raia_gl_get_frag_data_location(GLuint(program), name))
    }

    static func uniform1ui(location: Int, v0: UInt32) {
        raia_gl_uniform_1ui(GLint(location), GLuint(v0))
    }

    static func uniform2ui(location: Int, v0: UInt32, v1: UInt32) {
        raia_gl_uniform_2ui(GLint(location), GLuint(v0), GLuint(v1))
    }

    static func uniform3ui(location: Int, v0: UInt32, v1: UInt32, v2: UInt32) {
        raia_gl_uniform_3ui(GLint(location), GLuint(v0), GLuint(v1), GLuint(v2))
    }

    static func uniform4ui(location: Int, v0: UInt32, v1: UInt32, v2: UInt32, v3: UInt32) {
        raia_gl_uniform_4ui(GLint(location), GLuint(v0), GLuint(v1), GLuint(v2), GLuint(v3))
    }

    static func uniform1uiv(location: Int, count: Int, value: UnsafePointer<UInt32>) {
        raia_gl_uniform_1uiv(GLint(location), GLsizei(count), value)
    }

    static func uniform2uiv(location: Int, count: Int, value: UnsafePointer<UInt32>) {
        raia_gl_uniform_2uiv(GLint(location), GLsizei(count), value)
    }

    static func uniform3uiv(location: Int, count: Int, value: UnsafePointer<UInt32>) {
        raia_gl_uniform_3uiv(GLint(location), GLsizei(count), value)
    }

    static func uniform4uiv(location: Int, count: Int, value: UnsafePointer<UInt32>) {
        raia_gl_uniform_4uiv(GLint(location), GLsizei(count), value)
    }

    static func clearBufferiv(buffer: Int, drawbuffer: Int, value: UnsafePointer<Int32>) {
        raia_gl_clear_buffer_iv(GLenum(buffer), GLint(drawbuffer), value)
    }

    static func clearBufferuiv(buffer: Int, drawbuffer: Int, value: UnsafePointer<UInt32>) {
        raia_gl_clear_buffer_uiv(GLenum(buffer), GLint(drawbuffer), value)
    }

    static func clearBufferfv(buffer: Int, drawbuffer: Int, value: UnsafePointer<Float>) {
        raia_gl_clear_buffer_fv(GLenum(buffer), GLint(drawbuffer), value)
    }

    static func clearBufferfi(buffer: Int, drawbuffer: Int, depth: Float, stencil: Int) {
        raia_gl_clear_buffer_fi(GLenum(buffer), GLint(drawbuffer), depth, GLint(stencil))
    }

    static func getStringi(name: Int, index: Int) -> String? {
        guard let result = raia_gl_get_string_i(GLenum(name), GLuint(index)) else {
            return nil
        }
        return String(cString: result)
    }

    static func copyBufferSubData(readTarget: Int, writeTarget: Int, readOffset: Int, writeOffset: Int, size: Int) {
        raia_gl_copy_buffer_sub_data(GLenum(readTarget), GLenum(writeTarget), GLintptr(readOffset), GLintptr(writeOffset), GLsizeiptr(size))
    }

    static func getUniformIndices(program: Int, uniformCount: Int, uniformNames: UnsafePointer<UnsafePointer<CChar>?>, uniformIndices: UnsafeMutablePointer<UInt32>) {
        raia_gl_get_uniform_indices(GLuint(program), GLsizei(uniformCount), uniformNames, uniformIndices)
    }

    static func getActiveUniformsiv(program: Int, uniformCount: Int, uniformIndices: UnsafePointer<UInt32>, pname: Int, params: UnsafeMutablePointer<Int32>) {
        raia_gl_get_active_uniforms_iv(GLuint(program), GLsizei(uniformCount), uniformIndices, GLenum(pname), params)
    }

    static func getUniformBlockIndex(program: Int, uniformBlockName: String) -> Int {
        return Int(raia_gl_get_uniform_block_index(GLuint(program), uniformBlockName))
    }

    static func getActiveUniformBlockiv(program: Int, uniformBlockIndex: Int, pname: Int, params: UnsafeMutablePointer<Int32>) {
        raia_gl_get_active_uniform_block_iv(GLuint(program), GLuint(uniformBlockIndex), GLenum(pname), params)
    }

    static func getActiveUniformBlockName(program: Int, uniformBlockIndex: Int, bufSize: Int, length: UnsafeMutablePointer<Int32>?, uniformBlockName: UnsafeMutablePointer<CChar>) {
        raia_gl_get_active_uniform_block_name(GLuint(program), GLuint(uniformBlockIndex), GLsizei(bufSize), length, uniformBlockName)
    }

    static func uniformBlockBinding(program: Int, uniformBlockIndex: Int, uniformBlockBinding: Int) {
        raia_gl_uniform_block_binding(GLuint(program), GLuint(uniformBlockIndex), GLuint(uniformBlockBinding))
    }

    static func drawArraysInstanced(mode: Int, first: Int, count: Int, instanceCount: Int) {
        raia_gl_draw_arrays_instanced(GLenum(mode), GLint(first), GLsizei(count), GLsizei(instanceCount))
    }

    static func drawElementsInstanced(mode: Int, count: Int, type: Int, indices: UnsafeRawPointer?, instanceCount: Int) {
        raia_gl_draw_elements_instanced(GLenum(mode), GLsizei(count), GLenum(type), indices, GLsizei(instanceCount))
    }

    // MARK: TODO

    static func fenceSync(condition: Int, flags: Int) -> OpaquePointer {
        return raia_gl_fence_sync(GLenum(condition), GLbitfield(flags))
    }

    static func isSync(sync: OpaquePointer) -> Bool {
        return raia_gl_is_sync(sync) == GLboolean(1)
    }

    static func deleteSync(sync: OpaquePointer) {
        raia_gl_delete_sync(sync)
    }

    static func clientWaitSync(sync: OpaquePointer, flags: Int, timeout: UInt64) -> Int {
        return Int(raia_gl_client_wait_sync(sync, GLbitfield(flags), GLuint64(timeout)))
    }

    static func waitSync(sync: OpaquePointer, flags: Int, timeout: UInt64) {
        raia_gl_wait_sync(sync, GLbitfield(flags), GLuint64(timeout))
    }

    static func getInteger64v(pname: Int, data: UnsafeMutablePointer<Int64>) {
        raia_gl_get_integer_64v(GLenum(pname), data)
    }

    static func getSynciv(sync: OpaquePointer, pname: Int, bufSize: Int, length: UnsafeMutablePointer<Int32>?, values: UnsafeMutablePointer<Int32>) {
        raia_gl_get_sync_iv(sync, GLenum(pname), GLsizei(bufSize), length, values)
    }

    static func getInteger64i_v(target: Int, index: Int, data: UnsafeMutablePointer<Int64>) {
        raia_gl_get_integer_64i_v(GLenum(target), GLuint(index), data)
    }

    static func getBufferParameteri64v(target: Int, pname: Int, params: UnsafeMutablePointer<Int64>) {
        raia_gl_get_buffer_parameter_i64v(GLenum(target), GLenum(pname), params)
    }

    static func genSamplers(count: Int, samplers: UnsafeMutablePointer<UInt32>) {
        raia_gl_gen_samplers(GLsizei(count), samplers)
    }

    static func deleteSamplers(count: Int, samplers: UnsafePointer<UInt32>) {
        raia_gl_delete_samplers(GLsizei(count), samplers)
    }

    static func isSampler(sampler: Int) -> Bool {
        return raia_gl_is_sampler(GLuint(sampler)) == GLboolean(1)
    }

    static func bindSampler(unit: Int, sampler: Int) {
        raia_gl_bind_sampler(GLuint(unit), GLuint(sampler))
    }

    static func samplerParameteri(sampler: Int, pname: Int, param: Int) {
        raia_gl_sampler_parameter_i(GLuint(sampler), GLenum(pname), GLint(param))
    }

    static func samplerParameteriv(sampler: Int, pname: Int, param: UnsafePointer<Int32>) {
        raia_gl_sampler_parameter_iv(GLuint(sampler), GLenum(pname), param)
    }

    static func samplerParameterf(sampler: Int, pname: Int, param: Float) {
        raia_gl_sampler_parameter_f(GLuint(sampler), GLenum(pname), param)
    }

    static func samplerParameterfv(sampler: Int, pname: Int, param: UnsafePointer<Float>) {
        raia_gl_sampler_parameter_fv(GLuint(sampler), GLenum(pname), param)
    }

    static func getSamplerParameteriv(sampler: Int, pname: Int, params: UnsafeMutablePointer<Int32>) {
        raia_gl_get_sampler_parameter_iv(GLuint(sampler), GLenum(pname), params)
    }

    static func getSamplerParameterfv(sampler: Int, pname: Int, params: UnsafeMutablePointer<Float>) {
        raia_gl_get_sampler_parameter_fv(GLuint(sampler), GLenum(pname), params)
    }

    static func vertexAttribDivisor(index: Int, divisor: Int) {
        raia_gl_vertex_attrib_divisor(GLuint(index), GLuint(divisor))
    }

    static func bindTransformFeedback(target: Int, id: Int) {
        raia_gl_bind_transform_feedback(GLenum(target), GLuint(id))
    }

    static func deleteTransformFeedbacks(n: Int, ids: UnsafePointer<UInt32>) {
        raia_gl_delete_transform_feedbacks(GLsizei(n), ids)
    }

    static func genTransformFeedbacks(n: Int, ids: UnsafeMutablePointer<UInt32>) {
        raia_gl_gen_transform_feedbacks(GLsizei(n), ids)
    }

    static func isTransformFeedback(id: Int) -> Bool {
        return raia_gl_is_transform_feedback(GLuint(id)) == GLboolean(1)
    }

    static func pauseTransformFeedback() {
        raia_gl_pause_transform_feedback()
    }

    static func resumeTransformFeedback() {
        raia_gl_resume_transform_feedback()
    }

    static func getProgramBinary(program: Int, bufSize: Int, length: UnsafeMutablePointer<Int32>?, binaryFormat: UnsafeMutablePointer<UInt32>?, binary: UnsafeMutableRawPointer) {
        raia_gl_get_program_binary(GLuint(program), GLsizei(bufSize), length, binaryFormat, binary)
    }

    static func programBinary(program: Int, binaryFormat: Int, binary: UnsafeRawPointer, length: Int) {
        raia_gl_program_binary(GLuint(program), GLenum(binaryFormat), binary, GLsizei(length))
    }

    static func programParameteri(program: Int, pname: Int, value: Int) {
        raia_gl_program_parameter_i(GLuint(program), GLenum(pname), GLint(value))
    }

    static func invalidateFramebuffer(target: Int, numAttachments: Int, attachments: UnsafePointer<UInt32>) {
        raia_gl_invalidate_framebuffer(GLenum(target), GLsizei(numAttachments), attachments)
    }

    static func invalidateSubFramebuffer(target: Int, numAttachments: Int, attachments: UnsafePointer<UInt32>, x: Int, y: Int, width: Int, height: Int) {
        raia_gl_invalidate_sub_framebuffer(GLenum(target), GLsizei(numAttachments), attachments, GLint(x), GLint(y), GLsizei(width), GLsizei(height))
    }

    static func texStorage2D(target: Int, levels: Int, internalFormat: Int, width: Int, height: Int) {
        raia_gl_tex_storage_2d(GLenum(target), GLsizei(levels), GLenum(internalFormat), GLsizei(width), GLsizei(height))
    }

    static func texStorage3D(target: Int, levels: Int, internalFormat: Int, width: Int, height: Int, depth: Int) {
        raia_gl_tex_storage_3d(GLenum(target), GLsizei(levels), GLenum(internalFormat), GLsizei(width), GLsizei(height), GLsizei(depth))
    }

    static func getInternalFormativ(target: Int, internalFormat: Int, pname: Int, bufSize: Int, params: UnsafeMutablePointer<Int32>) {
        raia_gl_get_internal_format_iv(GLenum(target), GLenum(internalFormat), GLenum(pname), GLsizei(bufSize), params)
    }

    // MARK: GL ES 3.1

    static func dispatchCompute(numGroupsX: Int, numGroupsY: Int, numGroupsZ: Int) {
        raia_gl_dispatch_compute(GLuint(numGroupsX), GLuint(numGroupsY), GLuint(numGroupsZ))
    }

    static func dispatchComputeIndirect(indirect: Int) {
        raia_gl_dispatch_compute_indirect(GLintptr(indirect))
    }

    static func drawArraysIndirect(mode: Int, indirect: UnsafeRawPointer) {
        raia_gl_draw_arrays_indirect(GLenum(mode), indirect)
    }

    static func drawElementsIndirect(mode: Int, type: Int, indirect: UnsafeRawPointer) {
        raia_gl_draw_elements_indirect(GLenum(mode), GLenum(type), indirect)
    }

    static func framebufferParameteri(target: Int, pname: Int, param: Int) {
        raia_gl_framebuffer_parameter_i(GLenum(target), GLenum(pname), GLint(param))
    }

    static func getFramebufferParameteriv(target: Int, pname: Int, params: UnsafeMutablePointer<Int32>) {
        raia_gl_get_framebuffer_parameter_iv(GLenum(target), GLenum(pname), params)
    }

    static func getProgramInterfaceiv(program: Int, programInterface: Int, pname: Int, params: UnsafeMutablePointer<Int32>) {
        raia_gl_get_program_interface_iv(GLuint(program), GLenum(programInterface), GLenum(pname), params)
    }

    static func getProgramResourceIndex(program: Int, programInterface: Int, name: String) -> Int {
        return Int(raia_gl_get_program_resource_index(GLuint(program), GLenum(programInterface), name))
    }

    static func getProgramResourceName(program: Int, programInterface: Int, index: Int, bufSize: Int, length: UnsafeMutablePointer<Int32>?, name: UnsafeMutablePointer<CChar>) {
        raia_gl_get_program_resource_name(GLuint(program), GLenum(programInterface), GLuint(index), GLsizei(bufSize), length, name)
    }

    static func getProgramResourceiv(program: Int, programInterface: Int, index: Int, propCount: Int, props: UnsafePointer<UInt32>, bufSize: Int, length: UnsafeMutablePointer<Int32>?, params: UnsafeMutablePointer<Int32>) {
        raia_gl_get_program_resource_iv(GLuint(program), GLenum(programInterface), GLuint(index), GLsizei(propCount), props, GLsizei(bufSize), length, params)
    }

    static func getProgramResourceLocation(program: Int, programInterface: Int, name: String) -> Int {
        return Int(raia_gl_get_program_resource_location(GLuint(program), GLenum(programInterface), name))
    }

    static func useProgramStages(pipeline: Int, stages: Int, program: Int) {
        raia_gl_use_program_stages(GLuint(pipeline), GLbitfield(stages), GLuint(program))
    }

    static func activeShaderProgram(pipeline: Int, program: Int) {
        raia_gl_active_shader_program(GLuint(pipeline), GLuint(program))
    }

    static func createShaderProgramv(type: Int, count: Int, strings: UnsafePointer<UnsafePointer<CChar>?>) -> Int {
        return Int(raia_gl_create_shader_program_v(GLenum(type), GLsizei(count), strings))
    }

    static func bindProgramPipeline(pipeline: Int) {
        raia_gl_bind_program_pipeline(GLuint(pipeline))
    }

    static func deleteProgramPipelines(n: Int, pipelines: UnsafePointer<UInt32>) {
        raia_gl_delete_program_pipelines(GLsizei(n), pipelines)
    }

    static func genProgramPipelines(n: Int, pipelines: UnsafeMutablePointer<UInt32>) {
        raia_gl_gen_program_pipelines(GLsizei(n), pipelines)
    }

    static func isProgramPipeline(pipeline: Int) -> Bool {
        return raia_gl_is_program_pipeline(GLuint(pipeline)) == GLboolean(1)
    }

    static func getProgramPipelineiv(pipeline: Int, pname: Int, params: UnsafeMutablePointer<Int32>) {
        raia_gl_get_program_pipeline_iv(GLuint(pipeline), GLenum(pname), params)
    }

    static func programUniform1i(program: Int, location: Int, v0: Int) {
        raia_gl_program_uniform_1i(GLuint(program), GLint(location), GLint(v0))
    }

    static func programUniform2i(program: Int, location: Int, v0: Int, v1: Int) {
        raia_gl_program_uniform_2i(GLuint(program), GLint(location), GLint(v0), GLint(v1))
    }

    static func programUniform3i(program: Int, location: Int, v0: Int, v1: Int, v2: Int) {
        raia_gl_program_uniform_3i(GLuint(program), GLint(location), GLint(v0), GLint(v1), GLint(v2))
    }

    static func programUniform4i(program: Int, location: Int, v0: Int, v1: Int, v2: Int, v3: Int) {
        raia_gl_program_uniform_4i(GLuint(program), GLint(location), GLint(v0), GLint(v1), GLint(v2), GLint(v3))
    }

    static func programUniform1ui(program: Int, location: Int, v0: UInt32) {
        raia_gl_program_uniform_1ui(GLuint(program), GLint(location), GLuint(v0))
    }

    static func programUniform2ui(program: Int, location: Int, v0: UInt32, v1: UInt32) {
        raia_gl_program_uniform_2ui(GLuint(program), GLint(location), GLuint(v0), GLuint(v1))
    }

    static func programUniform3ui(program: Int, location: Int, v0: UInt32, v1: UInt32, v2: UInt32) {
        raia_gl_program_uniform_3ui(GLuint(program), GLint(location), GLuint(v0), GLuint(v1), GLuint(v2))
    }

    static func programUniform4ui(program: Int, location: Int, v0: UInt32, v1: UInt32, v2: UInt32, v3: UInt32) {
        raia_gl_program_uniform_4ui(GLuint(program), GLint(location), GLuint(v0), GLuint(v1), GLuint(v2), GLuint(v3))
    }

    static func programUniform1f(program: Int, location: Int, v0: Float) {
        raia_gl_program_uniform_1f(GLuint(program), GLint(location), GLfloat(v0))
    }

    static func programUniform2f(program: Int, location: Int, v0: Float, v1: Float) {
        raia_gl_program_uniform_2f(GLuint(program), GLint(location), GLfloat(v0), GLfloat(v1))
    }

    static func programUniform3f(program: Int, location: Int, v0: Float, v1: Float, v2: Float) {
        raia_gl_program_uniform_3f(GLuint(program), GLint(location), GLfloat(v0), GLfloat(v1), GLfloat(v2))
    }

    static func programUniform4f(program: Int, location: Int, v0: Float, v1: Float, v2: Float, v3: Float) {
        raia_gl_program_uniform_4f(GLuint(program), GLint(location), GLfloat(v0), GLfloat(v1), GLfloat(v2), GLfloat(v3))
    }

    static func programUniform1iv(program: Int, location: Int, count: Int, value: UnsafePointer<Int32>) {
        raia_gl_program_uniform_1iv(GLuint(program), GLint(location), GLsizei(count), value)
    }

    static func programUniform2iv(program: Int, location: Int, count: Int, value: UnsafePointer<Int32>) {
        raia_gl_program_uniform_2iv(GLuint(program), GLint(location), GLsizei(count), value)
    }

    static func programUniform3iv(program: Int, location: Int, count: Int, value: UnsafePointer<Int32>) {
        raia_gl_program_uniform_3iv(GLuint(program), GLint(location), GLsizei(count), value)
    }

    static func programUniform4iv(program: Int, location: Int, count: Int, value: UnsafePointer<Int32>) {
        raia_gl_program_uniform_4iv(GLuint(program), GLint(location), GLsizei(count), value)
    }

    static func programUniform1uiv(program: Int, location: Int, count: Int, value: UnsafePointer<UInt32>) {
        raia_gl_program_uniform_1uiv(GLuint(program), GLint(location), GLsizei(count), value)
    }

    static func programUniform2uiv(program: Int, location: Int, count: Int, value: UnsafePointer<UInt32>) {
        raia_gl_program_uniform_2uiv(GLuint(program), GLint(location), GLsizei(count), value)
    }

    static func programUniform3uiv(program: Int, location: Int, count: Int, value: UnsafePointer<UInt32>) {
        raia_gl_program_uniform_3uiv(GLuint(program), GLint(location), GLsizei(count), value)
    }

    static func programUniform4uiv(program: Int, location: Int, count: Int, value: UnsafePointer<UInt32>) {
        raia_gl_program_uniform_4uiv(GLuint(program), GLint(location), GLsizei(count), value)
    }

    static func programUniform1fv(program: Int, location: Int, count: Int, value: UnsafePointer<Float>) {
        raia_gl_program_uniform_1fv(GLuint(program), GLint(location), GLsizei(count), value)
    }

    static func programUniform2fv(program: Int, location: Int, count: Int, value: UnsafePointer<Float>) {
        raia_gl_program_uniform_2fv(GLuint(program), GLint(location), GLsizei(count), value)
    }

    static func programUniform3fv(program: Int, location: Int, count: Int, value: UnsafePointer<Float>) {
        raia_gl_program_uniform_3fv(GLuint(program), GLint(location), GLsizei(count), value)
    }

    static func programUniform4fv(program: Int, location: Int, count: Int, value: UnsafePointer<Float>) {
        raia_gl_program_uniform_4fv(GLuint(program), GLint(location), GLsizei(count), value)
    }

    static func programUniformMatrix2fv(program: Int, location: Int, count: Int, transpose: Bool, value: UnsafePointer<Float>) {
        raia_gl_program_uniform_matrix_2fv(GLuint(program), GLint(location), GLsizei(count), GLboolean(transpose ? 1 : 0), value)
    }

    static func programUniformMatrix3fv(program: Int, location: Int, count: Int, transpose: Bool, value: UnsafePointer<Float>) {
        raia_gl_program_uniform_matrix_3fv(GLuint(program), GLint(location), GLsizei(count), GLboolean(transpose ? 1 : 0), value)
    }

    static func programUniformMatrix4fv(program: Int, location: Int, count: Int, transpose: Bool, value: UnsafePointer<Float>) {
        raia_gl_program_uniform_matrix_4fv(GLuint(program), GLint(location), GLsizei(count), GLboolean(transpose ? 1 : 0), value)
    }

    static func programUniformMatrix2x3fv(program: Int, location: Int, count: Int, transpose: Bool, value: UnsafePointer<Float>) {
        raia_gl_program_uniform_matrix_2x3fv(GLuint(program), GLint(location), GLsizei(count), GLboolean(transpose ? 1 : 0), value)
    }

    static func programUniformMatrix3x2fv(program: Int, location: Int, count: Int, transpose: Bool, value: UnsafePointer<Float>) {
        raia_gl_program_uniform_matrix_3x2fv(GLuint(program), GLint(location), GLsizei(count), GLboolean(transpose ? 1 : 0), value)
    }

    static func programUniformMatrix2x4fv(program: Int, location: Int, count: Int, transpose: Bool, value: UnsafePointer<Float>) {
        raia_gl_program_uniform_matrix_2x4fv(GLuint(program), GLint(location), GLsizei(count), GLboolean(transpose ? 1 : 0), value)
    }

    static func programUniformMatrix4x2fv(program: Int, location: Int, count: Int, transpose: Bool, value: UnsafePointer<Float>) {
        raia_gl_program_uniform_matrix_4x2fv(GLuint(program), GLint(location), GLsizei(count), GLboolean(transpose ? 1 : 0), value)
    }

    static func programUniformMatrix3x4fv(program: Int, location: Int, count: Int, transpose: Bool, value: UnsafePointer<Float>) {
        raia_gl_program_uniform_matrix_3x4fv(GLuint(program), GLint(location), GLsizei(count), GLboolean(transpose ? 1 : 0), value)
    }

    static func programUniformMatrix4x3fv(program: Int, location: Int, count: Int, transpose: Bool, value: UnsafePointer<Float>) {
        raia_gl_program_uniform_matrix_4x3fv(GLuint(program), GLint(location), GLsizei(count), GLboolean(transpose ? 1 : 0), value)
    }

    static func validateProgramPipeline(pipeline: Int) {
        raia_gl_validate_program_pipeline(GLuint(pipeline))
    }

    static func getProgramPipelineInfoLog(pipeline: Int, bufSize: Int, length: UnsafeMutablePointer<Int32>?, infoLog: UnsafeMutablePointer<CChar>) {
        raia_gl_get_program_pipeline_info_log(GLuint(pipeline), GLsizei(bufSize), length, infoLog)
    }

    static func bindImageTexture(unit: Int, texture: Int, level: Int, layered: Bool, layer: Int, access: Int, format: Int) {
        raia_gl_bind_image_texture(GLuint(unit), GLuint(texture), GLint(level), GLboolean(layered ? 1 : 0), GLint(layer), GLenum(access), GLenum(format))
    }

    static func getBooleani_v(target: Int, index: Int, data: UnsafeMutablePointer<UInt8>) {
        raia_gl_get_boolean_i_v(GLenum(target), GLuint(index), data)
    }

    static func memoryBarrier(barriers: Int) {
        raia_gl_memory_barrier(GLbitfield(barriers))
    }

    static func memoryBarrierByRegion(barriers: Int) {
        raia_gl_memory_barrier_by_region(GLbitfield(barriers))
    }

    static func texStorage2DMultisample(target: Int, samples: Int, internalFormat: Int, width: Int, height: Int, fixedSampleLocations: Bool) {
        raia_gl_tex_storage_2d_multisample(GLenum(target), GLsizei(samples), GLenum(internalFormat), GLsizei(width), GLsizei(height), GLboolean(fixedSampleLocations ? 1 : 0))
    }

    static func getMultisamplefv(pname: Int, index: Int, val: UnsafeMutablePointer<Float>) {
        raia_gl_get_multisample_fv(GLenum(pname), GLuint(index), val)
    }

    static func sampleMaski(maskNumber: Int, mask: Int) {
        raia_gl_sample_mask_i(GLuint(maskNumber), GLbitfield(mask))
    }

    static func getTexLevelParameteriv(target: Int, level: Int, pname: Int, params: UnsafeMutablePointer<Int32>) {
        raia_gl_get_tex_level_parameter_iv(GLenum(target), GLint(level), GLenum(pname), params)
    }

    static func getTexLevelParameterfv(target: Int, level: Int, pname: Int, params: UnsafeMutablePointer<Float>) {
        raia_gl_get_tex_level_parameter_fv(GLenum(target), GLint(level), GLenum(pname), params)
    }

    static func bindVertexBuffer(bindingIndex: Int, buffer: Int, offset: Int, stride: Int) {
        raia_gl_bind_vertex_buffer(GLuint(bindingIndex), GLuint(buffer), GLintptr(offset), GLsizei(stride))
    }

    static func vertexAttribFormat(attribIndex: Int, size: Int, type: Int, normalized: Bool, relativeOffset: Int) {
        raia_gl_vertex_attrib_format(GLuint(attribIndex), GLint(size), GLenum(type), GLboolean(normalized ? 1 : 0), GLuint(relativeOffset))
    }

    static func vertexAttribIFormat(attribIndex: Int, size: Int, type: Int, relativeOffset: Int) {
        raia_gl_vertex_attrib_i_format(GLuint(attribIndex), GLint(size), GLenum(type), GLuint(relativeOffset))
    }

    static func vertexAttribBinding(attribIndex: Int, bindingIndex: Int) {
        raia_gl_vertex_attrib_binding(GLuint(attribIndex), GLuint(bindingIndex))
    }

    static func vertexBindingDivisor(bindingIndex: Int, divisor: Int) {
        raia_gl_vertex_binding_divisor(GLuint(bindingIndex), GLuint(divisor))
    }

    // MARK: GL ES 3.2

    static func blendBarrier() {
        raia_gl_blend_barrier()
    }

    static func copyImageSubData(srcName: Int, srcTarget: Int, srcLevel: Int, srcX: Int, srcY: Int, srcZ: Int, dstName: Int, dstTarget: Int, dstLevel: Int, dstX: Int, dstY: Int, dstZ: Int, srcWidth: Int, srcHeight: Int, srcDepth: Int) {
        raia_gl_copy_image_sub_data(GLuint(srcName), GLenum(srcTarget), GLint(srcLevel), GLint(srcX), GLint(srcY), GLint(srcZ), GLuint(dstName), GLenum(dstTarget), GLint(dstLevel), GLint(dstX), GLint(dstY), GLint(dstZ), GLsizei(srcWidth), GLsizei(srcHeight), GLsizei(srcDepth))
    }

    static func debugMessageControl(source: Int, type: Int, severity: Int, count: Int, ids: UnsafePointer<UInt32>?, enabled: Bool) {
        raia_gl_debug_message_control(GLenum(source), GLenum(type), GLenum(severity), GLsizei(count), ids, GLboolean(enabled ? 1 : 0))
    }

    static func debugMessageInsert(source: Int, type: Int, id: Int, severity: Int, length: Int, buf: String) {
        buf.withCString { cString in
            raia_gl_debug_message_insert(GLenum(source), GLenum(type), GLuint(id), GLenum(severity), GLsizei(length), cString)
        }
    }

    static func debugMessageCallback(callback: @escaping @convention(c) (GLenum, GLenum, GLuint, GLenum, GLsizei, UnsafePointer<CChar>?, UnsafeRawPointer?) -> Void, userParam: UnsafeRawPointer?) {
        raia_gl_debug_message_callback(callback, userParam)
    }

    static func getDebugMessageLog(count: Int, bufSize: Int, sources: UnsafeMutablePointer<UInt32>?, types: UnsafeMutablePointer<UInt32>?, ids: UnsafeMutablePointer<UInt32>?, severities: UnsafeMutablePointer<UInt32>?, lengths: UnsafeMutablePointer<Int32>?, messageLog: UnsafeMutablePointer<CChar>) -> Int {
        return Int(raia_gl_get_debug_message_log(GLuint(count), GLsizei(bufSize), sources, types, ids, severities, lengths, messageLog))
    }

    static func pushDebugGroup(source: Int, id: Int, length: Int, message: String) {
        message.withCString { cString in
            raia_gl_push_debug_group(GLenum(source), GLuint(id), GLsizei(length), cString)
        }
    }

    static func popDebugGroup() {
        raia_gl_pop_debug_group()
    }

    static func objectLabel(identifier: Int, name: Int, length: Int, label: String) {
        label.withCString { cString in
            raia_gl_object_label(GLenum(identifier), GLuint(name), GLsizei(length), cString)
        }
    }

    static func getObjectLabel(identifier: Int, name: Int, bufSize: Int, length: UnsafeMutablePointer<Int32>?, label: UnsafeMutablePointer<CChar>) {
        raia_gl_get_object_label(GLenum(identifier), GLuint(name), GLsizei(bufSize), length, label)
    }

    static func objectPtrLabel(ptr: UnsafeRawPointer, length: Int, label: String) {
        label.withCString { cString in
            raia_gl_object_ptr_label(ptr, GLsizei(length), cString)
        }
    }

    static func getObjectPtrLabel(ptr: UnsafeRawPointer, bufSize: Int, length: UnsafeMutablePointer<Int32>?, label: UnsafeMutablePointer<CChar>) {
        raia_gl_get_object_ptr_label(ptr, GLsizei(bufSize), length, label)
    }

    static func getPointerv(pname: Int, params: UnsafeMutablePointer<UnsafeMutableRawPointer?>) {
        raia_gl_get_pointer_v(GLenum(pname), params)
    }

    static func enablei(target: Int, index: Int) {
        raia_gl_enable_i(GLenum(target), GLuint(index))
    }

    static func disablei(target: Int, index: Int) {
        raia_gl_disable_i(GLenum(target), GLuint(index))
    }

    static func blendEquationi(buf: Int, mode: Int) {
        raia_gl_blend_equation_i(GLuint(buf), GLenum(mode))
    }

    static func blendEquationSeparatei(buf: Int, modeRGB: Int, modeAlpha: Int) {
        raia_gl_blend_equation_separate_i(GLuint(buf), GLenum(modeRGB), GLenum(modeAlpha))
    }

    static func blendFunci(buf: Int, src: Int, dst: Int) {
        raia_gl_blend_func_i(GLuint(buf), GLenum(src), GLenum(dst))
    }

    static func blendFuncSeparatei(buf: Int, srcRGB: Int, dstRGB: Int, srcAlpha: Int, dstAlpha: Int) {
        raia_gl_blend_func_separate_i(GLuint(buf), GLenum(srcRGB), GLenum(dstRGB), GLenum(srcAlpha), GLenum(dstAlpha))
    }

    static func colorMaski(index: Int, r: Bool, g: Bool, b: Bool, a: Bool) {
        raia_gl_color_mask_i(GLuint(index), GLboolean(r ? 1 : 0), GLboolean(g ? 1 : 0), GLboolean(b ? 1 : 0), GLboolean(a ? 1 : 0))
    }

    static func isEnabledi(target: Int, index: Int) -> Bool {
        return raia_gl_is_enabled_i(GLenum(target), GLuint(index)) == GLboolean(1)
    }

    static func drawElementsBaseVertex(mode: Int, count: Int, type: Int, indices: UnsafeRawPointer?, baseVertex: Int) {
        raia_gl_draw_elements_base_vertex(GLenum(mode), GLsizei(count), GLenum(type), indices, GLint(baseVertex))
    }

    static func drawRangeElementsBaseVertex(mode: Int, start: Int, end: Int, count: Int, type: Int, indices: UnsafeRawPointer?, baseVertex: Int) {
        raia_gl_draw_range_elements_base_vertex(GLenum(mode), GLuint(start), GLuint(end), GLsizei(count), GLenum(type), indices, GLint(baseVertex))
    }

    static func drawElementsInstancedBaseVertex(mode: Int, count: Int, type: Int, indices: UnsafeRawPointer?, instanceCount: Int, baseVertex: Int) {
        raia_gl_draw_elements_instanced_base_vertex(GLenum(mode), GLsizei(count), GLenum(type), indices, GLsizei(instanceCount), GLint(baseVertex))
    }

    static func framebufferTexture(target: Int, attachment: Int, texture: Int, level: Int) {
        raia_gl_framebuffer_texture(GLenum(target), GLenum(attachment), GLuint(texture), GLint(level))
    }

    static func primitiveBoundingBox(minX: Float, minY: Float, minZ: Float, minW: Float, maxX: Float, maxY: Float, maxZ: Float, maxW: Float) {
        raia_gl_primitive_bounding_box(GLfloat(minX), GLfloat(minY), GLfloat(minZ), GLfloat(minW), GLfloat(maxX), GLfloat(maxY), GLfloat(maxZ), GLfloat(maxW))
    }

    static func getGraphicsResetStatus() -> Int {
        return Int(raia_gl_get_graphics_reset_status())
    }

    static func readNPixels(x: Int, y: Int, width: Int, height: Int, format: Int, type: Int, bufSize: Int, data: UnsafeMutableRawPointer) {
        raia_gl_read_n_pixels(GLint(x), GLint(y), GLsizei(width), GLsizei(height), GLenum(format), GLenum(type), GLsizei(bufSize), data)
    }

    static func getNUniformfv(program: Int, location: Int, bufSize: Int, params: UnsafeMutablePointer<Float>) {
        raia_gl_get_n_uniform_fv(GLuint(program), GLint(location), GLsizei(bufSize), params)
    }

    static func getNUniformiv(program: Int, location: Int, bufSize: Int, params: UnsafeMutablePointer<Int32>) {
        raia_gl_get_n_uniform_iv(GLuint(program), GLint(location), GLsizei(bufSize), params)
    }

    static func getNUniformuiv(program: Int, location: Int, bufSize: Int, params: UnsafeMutablePointer<UInt32>) {
        raia_gl_get_n_uniform_uiv(GLuint(program), GLint(location), GLsizei(bufSize), params)
    }

    static func minSampleShading(value: Float) {
        raia_gl_min_sample_shading(GLfloat(value))
    }

    static func patchParameteri(pname: Int, value: Int) {
        raia_gl_patch_parameter_i(GLenum(pname), GLint(value))
    }

    static func texParameterIiv(target: Int, pname: Int, params: UnsafePointer<Int32>) {
        raia_gl_tex_parameter_iiv(GLenum(target), GLenum(pname), params)
    }

    static func texParameterIuiv(target: Int, pname: Int, params: UnsafePointer<UInt32>) {
        raia_gl_tex_parameter_iuiv(GLenum(target), GLenum(pname), params)
    }

    static func getTexParameterIiv(target: Int, pname: Int, params: UnsafeMutablePointer<Int32>) {
        raia_gl_get_tex_parameter_iiv(GLenum(target), GLenum(pname), params)
    }

    static func getTexParameterIuiv(target: Int, pname: Int, params: UnsafeMutablePointer<UInt32>) {
        raia_gl_get_tex_parameter_iuiv(GLenum(target), GLenum(pname), params)
    }

    static func samplerParameterIiv(sampler: Int, pname: Int, param: UnsafePointer<Int32>) {
        raia_gl_sampler_parameter_iiv(GLuint(sampler), GLenum(pname), param)
    }

    static func samplerParameterIuiv(sampler: Int, pname: Int, param: UnsafePointer<UInt32>) {
        raia_gl_sampler_parameter_iuiv(GLuint(sampler), GLenum(pname), param)
    }

    static func getSamplerParameterIiv(sampler: Int, pname: Int, params: UnsafeMutablePointer<Int32>) {
        raia_gl_get_sampler_parameter_iiv(GLuint(sampler), GLenum(pname), params)
    }

    static func getSamplerParameterIuiv(sampler: Int, pname: Int, params: UnsafeMutablePointer<UInt32>) {
        raia_gl_get_sampler_parameter_iuiv(GLuint(sampler), GLenum(pname), params)
    }

    static func texBuffer(target: Int, internalFormat: Int, buffer: Int) {
        raia_gl_tex_buffer(GLenum(target), GLenum(internalFormat), GLuint(buffer))
    }

    static func texBufferRange(target: Int, internalFormat: Int, buffer: Int, offset: Int, size: Int) {
        raia_gl_tex_buffer_range(GLenum(target), GLenum(internalFormat), GLuint(buffer), GLintptr(offset), GLsizeiptr(size))
    }

    static func texStorage3DMultisample(target: Int, samples: Int, internalFormat: Int, width: Int, height: Int, depth: Int, fixedSampleLocations: Bool) {
        raia_gl_tex_storage_3d_multisample(GLenum(target), GLsizei(samples), GLenum(internalFormat), GLsizei(width), GLsizei(height), GLsizei(depth), GLboolean(fixedSampleLocations ? 1 : 0))
    }
}