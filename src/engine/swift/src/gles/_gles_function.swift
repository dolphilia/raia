import Foundation

extension GLES {

    // MARK: GL ES 2.0

    static func activeTexture(texture: Int) {
        raia_gl_active_texture(UInt32(texture))
    }
    
    static func attachShader(program: Int, shader: Int) {
        raia_gl_attach_shader(UInt32(program), UInt32(shader))
    }
    
    static func bindAttribLocation(program: Int, index: Int, name: String) {
        raia_gl_bind_attrib_location(UInt32(program), UInt32(index), name)
    }
    
    static func bindBuffer(target: Int, buffer: Int) {
        raia_gl_bind_buffer(UInt32(target), UInt32(buffer))
    }
    
    static func bindFramebuffer(target: Int, framebuffer: Int) {
        raia_gl_bind_framebuffer(UInt32(target), UInt32(framebuffer))
    }
    
    static func bindRenderbuffer(target: Int, renderbuffer: Int) {
        raia_gl_bind_renderbuffer(UInt32(target), UInt32(renderbuffer))
    }
    
    static func bindTexture(target: Int, texture: Int) {
        raia_gl_bind_texture(UInt32(target), UInt32(texture))
    }
    
    static func blendColor(red: Float, green: Float, blue: Float, alpha: Float) {
        raia_gl_blend_color(red, green, blue, alpha)
    }
    
    static func blendEquation(mode: Int) {
        raia_gl_blend_equation(UInt32(mode))
    }
    
    static func blendEquationSeparate(modeRGB: Int, modeAlpha: Int) {
        raia_gl_blend_equation_separate(UInt32(modeRGB), UInt32(modeAlpha))
    }
    
    static func blendFunc(sfactor: Int, dfactor: Int) {
        raia_gl_blend_func(UInt32(sfactor), UInt32(dfactor))
    }
    
    static func blendFuncSeparate(sfactorRGB: Int, dfactorRGB: Int, sfactorAlpha: Int, dfactorAlpha: Int) {
        raia_gl_blend_func_separate(UInt32(sfactorRGB), UInt32(dfactorRGB), UInt32(sfactorAlpha), UInt32(dfactorAlpha))
    }
    
    static func bufferData(target: Int, size: Int, data: UnsafeRawPointer?, usage: Int) {
        raia_gl_buffer_data(UInt32(target), Int32(size), data, UInt32(usage))
    }
    
    static func bufferSubData(target: Int, offset: Int, size: Int, data: UnsafeRawPointer?) {
        raia_gl_buffer_sub_data(UInt32(target), Int32(offset), Int32(size), data)
    }
    
    static func checkFramebufferStatus(target: Int) -> Int {
        return Int(raia_gl_check_framebuffer_status(UInt32(target)))
    }
    
    static func clear(mask: Int) {
        raia_gl_clear(UInt32(mask))
    }
    
    static func clearColor(red: Float, green: Float, blue: Float, alpha: Float) {
        raia_gl_clear_color(red, green, blue, alpha)
    }
    
    static func clearDepthf(depth: Float) {
        raia_gl_clear_depth_f(depth)
    }
    
    static func clearStencil(s: Int) {
        raia_gl_clear_stencil(Int32(s))
    }
    
    static func colorMask(red: Bool, green: Bool, blue: Bool, alpha: Bool) {
        raia_gl_color_mask(UInt8(red ? 1 : 0), UInt8(green ? 1 : 0), UInt8(blue ? 1 : 0), UInt8(alpha ? 1 : 0))
    }
    
    static func compileShader(shader: Int) {
        raia_gl_compile_shader(UInt32(shader))
    }
    
    static func compressedTexImage2D(target: Int, level: Int, internalFormat: Int, width: Int, height: Int, border: Int, imageSize: Int, data: UnsafeRawPointer?) {
        raia_gl_compressed_tex_image_2d(UInt32(target), Int32(level), UInt32(internalFormat), Int32(width), Int32(height), Int32(border), Int32(imageSize), data)
    }
    
    static func compressedTexSubImage2D(target: Int, level: Int, xoffset: Int, yoffset: Int, width: Int, height: Int, format: Int, imageSize: Int, data: UnsafeRawPointer?) {
        raia_gl_compressed_tex_sub_image_2d(UInt32(target), Int32(level), Int32(xoffset), Int32(yoffset), Int32(width), Int32(height), UInt32(format), Int32(imageSize), data)
    }
    
    static func copyTexImage2D(target: Int, level: Int, internalFormat: Int, x: Int, y: Int, width: Int, height: Int, border: Int) {
        raia_gl_copy_tex_image_2d(UInt32(target), Int32(level), UInt32(internalFormat), Int32(x), Int32(y), Int32(width), Int32(height), Int32(border))
    }
    
    static func copyTexSubImage2D(target: Int, level: Int, xoffset: Int, yoffset: Int, x: Int, y: Int, width: Int, height: Int) {
        raia_gl_copy_tex_sub_image_2d(UInt32(target), Int32(level), Int32(xoffset), Int32(yoffset), Int32(x), Int32(y), Int32(width), Int32(height))
    }

    static func createProgram() -> Int {
        return Int(raia_gl_create_program())
    }
    
    static func createShader(type: Int) -> Int {
        return Int(raia_gl_create_shader(UInt32(type)))
    }
    
    static func cullFace(mode: Int) {
        raia_gl_cull_face(UInt32(mode))
    }
    
    static func deleteBuffers(n: Int, buffers: UnsafeMutableRawPointer?) {
        raia_gl_delete_buffers(Int32(n), buffers)
    }
    
    static func deleteFramebuffers(n: Int, framebuffers: UnsafeMutableRawPointer?) {
        raia_gl_delete_framebuffers(Int32(n), framebuffers)
    }
    
    static func deleteProgram(program: Int) {
        raia_gl_delete_program(UInt32(program))
    }
    
    static func deleteRenderbuffers(n: Int, renderbuffers: UnsafeMutableRawPointer?) {
        raia_gl_delete_renderbuffers(Int32(n), renderbuffers)
    }
    
    static func deleteShader(shader: Int) {
        raia_gl_delete_shader(UInt32(shader))
    }
    
    static func deleteTextures(n: Int, textures: UnsafeMutableRawPointer?) {
        raia_gl_delete_textures(Int32(n), textures)
    }
    
    static func depthFunc(func_: Int) {
        raia_gl_depth_func(UInt32(func_))
    }
    
    static func depthMask(flag: Bool) {
        raia_gl_depth_mask(UInt8(flag ? 1 : 0))
    }
    
    static func depthRangef(n: Float, f: Float) {
        raia_gl_depth_range_f(n, f)
    }
    
    static func detachShader(program: Int, shader: Int) {
        raia_gl_detach_shader(UInt32(program), UInt32(shader))
    }
    
    static func disable(cap: Int) {
        raia_gl_disable(UInt32(cap))
    }
    
    static func disableVertexAttribArray(index: Int) {
        raia_gl_disable_vertex_attrib_array(UInt32(index))
    }
    
    static func drawArrays(mode: Int, first: Int, count: Int) {
        raia_gl_draw_arrays(UInt32(mode), Int32(first), Int32(count))
    }
    
    static func drawElements(mode: Int, count: Int, type: Int, indices: UnsafeRawPointer?) {
        raia_gl_draw_elements(UInt32(mode), Int32(count), UInt32(type), indices)
    }
    
    static func enable(cap: Int) {
        raia_gl_enable(UInt32(cap))
    }
    
    static func enableVertexAttribArray(index: Int) {
        raia_gl_enable_vertex_attrib_array(UInt32(index))
    }
    
    static func finish() {
        raia_gl_finish()
    }
    
    static func flush() {
        raia_gl_flush()
    }
    
    static func framebufferRenderbuffer(target: Int, attachment: Int, renderbufferTarget: Int, renderbuffer: Int) {
        raia_gl_framebuffer_renderbuffer(UInt32(target), UInt32(attachment), UInt32(renderbufferTarget), UInt32(renderbuffer))
    }
    
    static func framebufferTexture2D(target: Int, attachment: Int, textureTarget: Int, texture: Int, level: Int) {
        raia_gl_framebuffer_texture_2d(UInt32(target), UInt32(attachment), UInt32(textureTarget), UInt32(texture), Int32(level))
    }
    
    static func frontFace(mode: Int) {
        raia_gl_front_face(UInt32(mode))
    }

    static func genBuffers(n: Int, buffers: UnsafeMutableRawPointer?) {
        raia_gl_gen_buffers(Int32(n), buffers)
    }
    
    static func generateMipmap(target: Int) {
        raia_gl_generate_mipmap(UInt32(target))
    }
    
    static func genFramebuffers(n: Int, framebuffers: UnsafeMutableRawPointer?) {
        raia_gl_gen_framebuffers(Int32(n), framebuffers)
    }
    
    static func genRenderbuffers(n: Int, renderbuffers: UnsafeMutableRawPointer?) {
        raia_gl_gen_renderbuffers(Int32(n), renderbuffers)
    }
    
    static func genTextures(n: Int, textures: UnsafeMutableRawPointer?) {
        raia_gl_gen_textures(Int32(n), textures)
    }
    
    static func getActiveAttrib(program: Int, index: Int, bufSize: Int, length: UnsafeMutableRawPointer?, size: UnsafeMutableRawPointer?, type: UnsafeMutableRawPointer?, name: UnsafeMutableRawPointer?) {
        raia_gl_get_active_attrib(UInt32(program), UInt32(index), Int32(bufSize), length, size, type, name)
    }
    
    static func getActiveUniform(program: Int, index: Int, bufSize: Int, length: UnsafeMutableRawPointer?, size: UnsafeMutableRawPointer?, type: UnsafeMutableRawPointer?, name: UnsafeMutableRawPointer?) {
        raia_gl_get_active_uniform(UInt32(program), UInt32(index), Int32(bufSize), length, size, type, name)
    }
    
    static func getAttachedShaders(program: Int, maxCount: Int, count: UnsafeMutableRawPointer?, shaders: UnsafeMutableRawPointer?) {
        raia_gl_get_attached_shaders(UInt32(program), Int32(maxCount), count, shaders)
    }
    
    static func getAttribLocation(program: Int, name: String) -> Int {
        return Int(raia_gl_get_attrib_location(UInt32(program), name))
    }
    
    static func getBooleanv(pname: Int, data: UnsafeMutableRawPointer?) {
        raia_gl_get_boolean_v(UInt32(pname), data)
    }
    
    static func getBufferParameteriv(target: Int, pname: Int, params: UnsafeMutableRawPointer?) {
        raia_gl_get_buffer_parameter_iv(UInt32(target), UInt32(pname), params)
    }
    
    static func getError() -> Int {
        return Int(raia_gl_get_error())
    }
    
    static func getFloatv(pname: Int, data: UnsafeMutableRawPointer?) {
        raia_gl_get_float_v(UInt32(pname), data)
    }
    
    static func getFramebufferAttachmentParameteriv(target: Int, attachment: Int, pname: Int, params: UnsafeMutableRawPointer?) {
        raia_gl_get_framebuffer_attachment_parameter_iv(UInt32(target), UInt32(attachment), UInt32(pname), params)
    }
    
    static func getIntegerv(pname: Int, data: UnsafeMutableRawPointer?) {
        raia_gl_get_integer_v(UInt32(pname), data)
    }
    
    static func getProgramiv(program: Int, pname: Int, params: UnsafeMutableRawPointer?) {
        raia_gl_get_program_iv(UInt32(program), UInt32(pname), params)
    }
    
    static func getProgramInfoLog(program: Int, bufSize: Int, length: UnsafeMutableRawPointer?, infoLog: UnsafeMutableRawPointer?) {
        raia_gl_get_program_info_log(UInt32(program), Int32(bufSize), length, infoLog)
    }
    
    static func getRenderbufferParameteriv(target: Int, pname: Int, params: UnsafeMutableRawPointer?) {
        raia_gl_get_renderbuffer_parameter_iv(UInt32(target), UInt32(pname), params)
    }
    
    static func getShaderiv(shader: Int, pname: Int, params: UnsafeMutableRawPointer?) {
        raia_gl_get_shader_iv(UInt32(shader), UInt32(pname), params)
    }
    
    static func getShaderInfoLog(shader: Int, bufSize: Int, length: UnsafeMutableRawPointer?, infoLog: UnsafeMutableRawPointer?) {
        raia_gl_get_shader_info_log(UInt32(shader), Int32(bufSize), length, infoLog)
    }
    
    static func getShaderPrecisionFormat(shaderType: Int, precisionType: Int, range: UnsafeMutableRawPointer?, precision: UnsafeMutableRawPointer?) {
        raia_gl_get_shader_precision_format(UInt32(shaderType), UInt32(precisionType), range, precision)
    }
    
    static func getShaderSource(shader: Int, bufSize: Int, length: UnsafeMutableRawPointer?, source: UnsafeMutableRawPointer?) {
        raia_gl_get_shader_source(UInt32(shader), Int32(bufSize), length, source)
    }

    static func getString(name: Int) -> String? {
        guard let result = raia_gl_get_string(UInt32(name)) else {
            return nil
        }
        return String(cString: result)
    }
    
    static func getTexParameterfv(target: Int, pname: Int, params: UnsafeMutableRawPointer?) {
        raia_gl_get_tex_parameter_fv(UInt32(target), UInt32(pname), params)
    }
    
    static func getTexParameteriv(target: Int, pname: Int, params: UnsafeMutableRawPointer?) {
        raia_gl_get_tex_parameter_iv(UInt32(target), UInt32(pname), params)
    }
    
    static func getUniformfv(program: Int, location: Int, params: UnsafeMutableRawPointer?) {
        raia_gl_get_uniform_fv(UInt32(program), Int32(location), params)
    }
    
    static func getUniformiv(program: Int, location: Int, params: UnsafeMutableRawPointer?) {
        raia_gl_get_uniform_iv(UInt32(program), Int32(location), params)
    }
    
    static func getUniformLocation(program: Int, name: String) -> Int {
        return Int(raia_gl_get_uniform_location(UInt32(program), name))
    }
    
    static func getVertexAttribfv(index: Int, pname: Int, params: UnsafeMutableRawPointer?) {
        raia_gl_get_vertex_attrib_fv(UInt32(index), UInt32(pname), params)
    }
    
    static func getVertexAttribiv(index: Int, pname: Int, params: UnsafeMutableRawPointer?) {
        raia_gl_get_vertex_attrib_iv(UInt32(index), UInt32(pname), params)
    }
    
    static func getVertexAttribPointerv(index: Int, pname: Int, pointer: UnsafeMutablePointer<UnsafeMutableRawPointer?>?) {
        raia_gl_get_vertex_attrib_pointer_v(UInt32(index), UInt32(pname), pointer)
    }
    
    static func hint(target: Int, mode: Int) {
        raia_gl_hint(UInt32(target), UInt32(mode))
    }
    
    static func isBuffer(buffer: Int) -> Bool {
        return raia_gl_is_buffer(UInt32(buffer)) == UInt8(1)
    }
    
    static func isEnabled(cap: Int) -> Bool {
        return raia_gl_is_enabled(UInt32(cap)) == UInt8(1)
    }
    
    static func isFramebuffer(framebuffer: Int) -> Bool {
        return raia_gl_is_framebuffer(UInt32(framebuffer)) == UInt8(1)
    }
    
    static func isProgram(program: Int) -> Bool {
        return raia_gl_is_program(UInt32(program)) == UInt8(1)
    }
    
    static func isRenderbuffer(renderbuffer: Int) -> Bool {
        return raia_gl_is_renderbuffer(UInt32(renderbuffer)) == UInt8(1)
    }
    
    static func isShader(shader: Int) -> Bool {
        return raia_gl_is_shader(UInt32(shader)) == UInt8(1)
    }
    
    static func isTexture(texture: Int) -> Bool {
        return raia_gl_is_texture(UInt32(texture)) == UInt8(1)
    }

    static func lineWidth(width: Float) {
        raia_gl_line_width(width)
    }
    
    static func linkProgram(program: Int) {
        raia_gl_link_program(UInt32(program))
    }
    
    static func pixelStorei(pname: Int, param: Int) {
        raia_gl_pixel_store_i(UInt32(pname), Int32(param))
    }
    
    static func polygonOffset(factor: Float, units: Float) {
        raia_gl_polygon_offset(factor, units)
    }
    
    static func readPixels(x: Int, y: Int, width: Int, height: Int, format: Int, type: Int, pixels: UnsafeMutableRawPointer) {
        raia_gl_read_pixels(Int32(x), Int32(y), Int32(width), Int32(height), UInt32(format), UInt32(type), pixels)
    }
    
    static func releaseShaderCompiler() {
        raia_gl_release_shader_compiler()
    }
    
    static func renderbufferStorage(target: Int, internalFormat: Int, width: Int, height: Int) {
        raia_gl_renderbuffer_storage(UInt32(target), UInt32(internalFormat), Int32(width), Int32(height))
    }
    
    static func sampleCoverage(value: Float, invert: Bool) {
        raia_gl_sample_coverage(value, UInt8(invert ? 1 : 0))
    }
    
    static func scissor(x: Int, y: Int, width: Int, height: Int) {
        raia_gl_scissor(Int32(x), Int32(y), Int32(width), Int32(height))
    }
    
    static func shaderBinary(count: Int, shaders: UnsafeMutableRawPointer?, binaryFormat: Int, binary: UnsafeRawPointer, length: Int) {
        raia_gl_shader_binary(Int32(count), shaders, UInt32(binaryFormat), binary, Int32(length))
    }
    
    static func shaderSource(shader: Int, count: Int, strings: UnsafePointer<UnsafePointer<CChar>?>?, lengths: UnsafeMutableRawPointer?) {
        raia_gl_shader_source(UInt32(shader), Int32(count), strings, lengths)
    }
    
    static func stencilFunc(func_: Int, ref: Int, mask: Int) {
        raia_gl_stencil_func(UInt32(func_), Int32(ref), UInt32(mask))
    }
    
    static func stencilFuncSeparate(face: Int, func_: Int, ref: Int, mask: Int) {
        raia_gl_stencil_func_separate(UInt32(face), UInt32(func_), Int32(ref), UInt32(mask))
    }
    
    static func stencilMask(mask: Int) {
        raia_gl_stencil_mask(UInt32(mask))
    }
    
    static func stencilMaskSeparate(face: Int, mask: Int) {
        raia_gl_stencil_mask_separate(UInt32(face), UInt32(mask))
    }
    
    static func stencilOp(fail: Int, zFail: Int, zPass: Int) {
        raia_gl_stencil_op(UInt32(fail), UInt32(zFail), UInt32(zPass))
    }
    
    static func stencilOpSeparate(face: Int, sFail: Int, dpFail: Int, dpPass: Int) {
        raia_gl_stencil_op_separate(UInt32(face), UInt32(sFail), UInt32(dpFail), UInt32(dpPass))
    }

    static func texImage2D(target: Int, level: Int, internalFormat: Int, width: Int, height: Int, border: Int, format: Int, type: Int, pixels: UnsafeRawPointer?) {
        raia_gl_tex_image_2d(UInt32(target), Int32(level), Int32(internalFormat), Int32(width), Int32(height), Int32(border), UInt32(format), UInt32(type), pixels)
    }

    static func texParameterf(target: Int, pname: Int, param: Float) {
        raia_gl_tex_parameter_f(UInt32(target), UInt32(pname), param)
    }

    static func texParameterfv(target: Int, pname: Int, params: UnsafeMutableRawPointer?) {
        raia_gl_tex_parameter_fv(UInt32(target), UInt32(pname), params)
    }

    static func texParameteri(target: Int, pname: Int, param: Int) {
        raia_gl_tex_parameter_i(UInt32(target), UInt32(pname), Int32(param))
    }

    static func texParameteriv(target: Int, pname: Int, params: UnsafeMutableRawPointer?) {
        raia_gl_tex_parameter_iv(UInt32(target), UInt32(pname), params)
    }

    static func texSubImage2D(target: Int, level: Int, xOffset: Int, yOffset: Int, width: Int, height: Int, format: Int, type: Int, pixels: UnsafeRawPointer?) {
        raia_gl_tex_sub_image_2d(UInt32(target), Int32(level), Int32(xOffset), Int32(yOffset), Int32(width), Int32(height), UInt32(format), UInt32(type), pixels)
    }

    static func uniform1f(location: Int, v0: Float) {
        raia_gl_uniform_1f(Int32(location), v0)
    }

    static func uniform1fv(location: Int, count: Int, value: UnsafeMutableRawPointer?) {
        raia_gl_uniform_1fv(Int32(location), Int32(count), value)
    }

    static func uniform1i(location: Int, v0: Int) {
        raia_gl_uniform_1i(Int32(location), Int32(v0))
    }

    static func uniform1iv(location: Int, count: Int, value: UnsafeMutableRawPointer?) {
        raia_gl_uniform_1iv(Int32(location), Int32(count), value)
    }

    static func uniform2f(location: Int, v0: Float, v1: Float) {
        raia_gl_uniform_2f(Int32(location), v0, v1)
    }

    static func uniform2fv(location: Int, count: Int, value: UnsafeMutableRawPointer?) {
        raia_gl_uniform_2fv(Int32(location), Int32(count), value)
    }

    static func uniform2i(location: Int, v0: Int, v1: Int) {
        raia_gl_uniform_2i(Int32(location), Int32(v0), Int32(v1))
    }

    static func uniform2iv(location: Int, count: Int, value: UnsafeMutableRawPointer?) {
        raia_gl_uniform_2iv(Int32(location), Int32(count), value)
    }

    static func uniform3f(location: Int, v0: Float, v1: Float, v2: Float) {
        raia_gl_uniform_3f(Int32(location), v0, v1, v2)
    }

    static func uniform3fv(location: Int, count: Int, value: UnsafeMutableRawPointer?) {
        raia_gl_uniform_3fv(Int32(location), Int32(count), value)
    }

    static func uniform3i(location: Int, v0: Int, v1: Int, v2: Int) {
        raia_gl_uniform_3i(Int32(location), Int32(v0), Int32(v1), Int32(v2))
    }

    static func uniform3iv(location: Int, count: Int, value: UnsafeMutableRawPointer?) {
        raia_gl_uniform_3iv(Int32(location), Int32(count), value)
    }

    static func uniform4f(location: Int, v0: Float, v1: Float, v2: Float, v3: Float) {
        raia_gl_uniform_4f(Int32(location), v0, v1, v2, v3)
    }

    static func uniform4fv(location: Int, count: Int, value: UnsafeMutableRawPointer?) {
        raia_gl_uniform_4fv(Int32(location), Int32(count), value)
    }

    static func uniform4i(location: Int, v0: Int, v1: Int, v2: Int, v3: Int) {
        raia_gl_uniform_4i(Int32(location), Int32(v0), Int32(v1), Int32(v2), Int32(v3))
    }

    static func uniform4iv(location: Int, count: Int, value: UnsafeMutableRawPointer?) {
        raia_gl_uniform_4iv(Int32(location), Int32(count), value)
    }

    static func uniformMatrix2fv(location: Int, count: Int, transpose: Bool, value: UnsafeMutableRawPointer?) {
        raia_gl_uniform_matrix_2fv(Int32(location), Int32(count), UInt8(transpose ? 1 : 0), value)
    }

    static func uniformMatrix3fv(location: Int, count: Int, transpose: Bool, value: UnsafeMutableRawPointer?) {
        raia_gl_uniform_matrix_3fv(Int32(location), Int32(count), UInt8(transpose ? 1 : 0), value)
    }

    static func uniformMatrix4fv(location: Int, count: Int, transpose: Bool, value: UnsafeMutableRawPointer?) {
        raia_gl_uniform_matrix_4fv(Int32(location), Int32(count), UInt8(transpose ? 1 : 0), value)
    }

    static func useProgram(program: Int) {
        raia_gl_use_program(UInt32(program))
    }
    
    static func validateProgram(program: Int) {
        raia_gl_validate_program(UInt32(program))
    }
    
    static func vertexAttrib1f(index: Int, x: Float) {
        raia_gl_vertex_attrib_1f(UInt32(index), x)
    }
    
    static func vertexAttrib1fv(index: Int, v: UnsafeMutableRawPointer?) {
        raia_gl_vertex_attrib_1fv(UInt32(index), v)
    }
    
    static func vertexAttrib2f(index: Int, x: Float, y: Float) {
        raia_gl_vertex_attrib_2f(UInt32(index), x, y)
    }
    
    static func vertexAttrib2fv(index: Int, v: UnsafeMutableRawPointer?) {
        raia_gl_vertex_attrib_2fv(UInt32(index), v)
    }
    
    static func vertexAttrib3f(index: Int, x: Float, y: Float, z: Float) {
        raia_gl_vertex_attrib_3f(UInt32(index), x, y, z)
    }
    
    static func vertexAttrib3fv(index: Int, v: UnsafeMutableRawPointer?) {
        raia_gl_vertex_attrib_3fv(UInt32(index), v)
    }
    
    static func vertexAttrib4f(index: Int, x: Float, y: Float, z: Float, w: Float) {
        raia_gl_vertex_attrib_4f(UInt32(index), x, y, z, w)
    }
    
    static func vertexAttrib4fv(index: Int, v: UnsafeMutableRawPointer?) {
        raia_gl_vertex_attrib_4fv(UInt32(index), v)
    }
    
    static func vertexAttribPointer(index: Int, size: Int, type: Int, normalized: Bool, stride: Int, pointer: UnsafeRawPointer?) {
        raia_gl_vertex_attrib_pointer(UInt32(index), Int32(size), UInt32(type), UInt8(normalized ? 1 : 0), Int32(stride), pointer)
    }
    
    static func viewport(x: Int, y: Int, width: Int, height: Int) {
        raia_gl_viewport(Int32(x), Int32(y), Int32(width), Int32(height))
    }

    // MARK: GL ES 3.0

    static func readBuffer(src: Int) {
        raia_gl_read_buffer(UInt32(src))
    }
    
    static func drawRangeElements(mode: Int, start: Int, end: Int, count: Int, type: Int, indices: UnsafeRawPointer?) {
        raia_gl_draw_range_elements(UInt32(mode), UInt32(start), UInt32(end), Int32(count), UInt32(type), indices)
    }
    
    static func texImage3D(target: Int, level: Int, internalFormat: Int, width: Int, height: Int, depth: Int, border: Int, format: Int, type: Int, pixels: UnsafeRawPointer?) {
        raia_gl_tex_image_3d(UInt32(target), Int32(level), Int32(internalFormat), Int32(width), Int32(height), Int32(depth), Int32(border), UInt32(format), UInt32(type), pixels)
    }
    
    static func texSubImage3D(target: Int, level: Int, xOffset: Int, yOffset: Int, zOffset: Int, width: Int, height: Int, depth: Int, format: Int, type: Int, pixels: UnsafeRawPointer?) {
        raia_gl_tex_sub_image_3d(UInt32(target), Int32(level), Int32(xOffset), Int32(yOffset), Int32(zOffset), Int32(width), Int32(height), Int32(depth), UInt32(format), UInt32(type), pixels)
    }
    
    static func copyTexSubImage3D(target: Int, level: Int, xOffset: Int, yOffset: Int, zOffset: Int, x: Int, y: Int, width: Int, height: Int) {
        raia_gl_copy_tex_sub_image_3d(UInt32(target), Int32(level), Int32(xOffset), Int32(yOffset), Int32(zOffset), Int32(x), Int32(y), Int32(width), Int32(height))
    }
    
    static func compressedTexImage3D(target: Int, level: Int, internalFormat: Int, width: Int, height: Int, depth: Int, border: Int, imageSize: Int, data: UnsafeRawPointer?) {
        raia_gl_compressed_tex_image_3d(UInt32(target), Int32(level), UInt32(internalFormat), Int32(width), Int32(height), Int32(depth), Int32(border), Int32(imageSize), data)
    }
    
    static func compressedTexSubImage3D(target: Int, level: Int, xOffset: Int, yOffset: Int, zOffset: Int, width: Int, height: Int, depth: Int, format: Int, imageSize: Int, data: UnsafeRawPointer?) {
        raia_gl_compressed_tex_sub_image_3d(UInt32(target), Int32(level), Int32(xOffset), Int32(yOffset), Int32(zOffset), Int32(width), Int32(height), Int32(depth), UInt32(format), Int32(imageSize), data)
    }
    
    static func genQueries(n: Int, ids: UnsafeMutableRawPointer?) {
        raia_gl_gen_queries(Int32(n), ids)
    }
    
    static func deleteQueries(n: Int, ids: UnsafeMutableRawPointer?) {
        raia_gl_delete_queries(Int32(n), ids)
    }
    
    static func isQuery(id: Int) -> Bool {
        return raia_gl_is_query(UInt32(id)) == UInt8(1)
    }
    
    static func beginQuery(target: Int, id: Int) {
        raia_gl_begin_query(UInt32(target), UInt32(id))
    }
    
    static func endQuery(target: Int) {
        raia_gl_end_query(UInt32(target))
    }
    
    static func getQueryiv(target: Int, pname: Int, params: UnsafeMutableRawPointer?) {
        raia_gl_get_query_iv(UInt32(target), UInt32(pname), params)
    }
    
    static func getQueryObjectuiv(id: Int, pname: Int, params: UnsafeMutableRawPointer?) {
        raia_gl_get_query_object_uiv(UInt32(id), UInt32(pname), params)
    }
    
    static func unmapBuffer(target: Int) -> Bool {
        return raia_gl_unmap_buffer(UInt32(target)) == UInt8(1)
    }
    
    static func getBufferPointerv(target: Int, pname: Int, params: UnsafeMutablePointer<UnsafeMutableRawPointer?>?) {
        raia_gl_get_buffer_pointer_v(UInt32(target), UInt32(pname), params)
    }
    
    static func drawBuffers(n: Int, bufs: UnsafeMutableRawPointer?) {
        raia_gl_draw_buffers(Int32(n), bufs)
    }

    static func uniformMatrix2x3fv(location: Int, count: Int, transpose: Bool, value: UnsafeMutableRawPointer?) {
        raia_gl_uniform_matrix_2x3fv(Int32(location), Int32(count), UInt8(transpose ? 1 : 0), value)
    }

    static func uniformMatrix3x2fv(location: Int, count: Int, transpose: Bool, value: UnsafeMutableRawPointer?) {
        raia_gl_uniform_matrix_3x2fv(Int32(location), Int32(count), UInt8(transpose ? 1 : 0), value)
    }

    static func uniformMatrix2x4fv(location: Int, count: Int, transpose: Bool, value: UnsafeMutableRawPointer?) {
        raia_gl_uniform_matrix_2x4fv(Int32(location), Int32(count), UInt8(transpose ? 1 : 0), value)
    }

    static func uniformMatrix4x2fv(location: Int, count: Int, transpose: Bool, value: UnsafeMutableRawPointer?) {
        raia_gl_uniform_matrix_4x2fv(Int32(location), Int32(count), UInt8(transpose ? 1 : 0), value)
    }

    static func uniformMatrix3x4fv(location: Int, count: Int, transpose: Bool, value: UnsafeMutableRawPointer?) {
        raia_gl_uniform_matrix_3x4fv(Int32(location), Int32(count), UInt8(transpose ? 1 : 0), value)
    }

    static func uniformMatrix4x3fv(location: Int, count: Int, transpose: Bool, value: UnsafeMutableRawPointer?) {
        raia_gl_uniform_matrix_4x3fv(Int32(location), Int32(count), UInt8(transpose ? 1 : 0), value)
    }

    static func blitFramebuffer(srcX0: Int, srcY0: Int, srcX1: Int, srcY1: Int, dstX0: Int, dstY0: Int, dstX1: Int, dstY1: Int, mask: Int, filter: Int) {
        raia_gl_blit_framebuffer(Int32(srcX0), Int32(srcY0), Int32(srcX1), Int32(srcY1), Int32(dstX0), Int32(dstY0), Int32(dstX1), Int32(dstY1), UInt32(mask), UInt32(filter))
    }

    static func renderbufferStorageMultisample(target: Int, samples: Int, internalFormat: Int, width: Int, height: Int) {
        raia_gl_renderbuffer_storage_multisample(UInt32(target), Int32(samples), UInt32(internalFormat), Int32(width), Int32(height))
    }

    static func framebufferTextureLayer(target: Int, attachment: Int, texture: Int, level: Int, layer: Int) {
        raia_gl_framebuffer_texture_layer(UInt32(target), UInt32(attachment), UInt32(texture), Int32(level), Int32(layer))
    }

    static func mapBufferRange(target: Int, offset: Int, length: Int, access: Int) -> UnsafeMutableRawPointer? {
        return raia_gl_map_buffer_range(UInt32(target), Int32(offset), Int32(length), UInt32(access))
    }

    static func flushMappedBufferRange(target: Int, offset: Int, length: Int) {
        raia_gl_flush_mapped_buffer_range(UInt32(target), Int32(offset), Int32(length))
    }

    static func bindVertexArray(array: Int) {
        raia_gl_bind_vertex_array(UInt32(array))
    }

    static func deleteVertexArrays(n: Int, arrays: UnsafeMutableRawPointer?) {
        raia_gl_delete_vertex_arrays(Int32(n), arrays)
    }

    static func genVertexArrays(n: Int, arrays: UnsafeMutableRawPointer?) {
        raia_gl_gen_vertex_arrays(Int32(n), arrays)
    }

    static func isVertexArray(array: Int) -> Bool {
        return raia_gl_is_vertex_array(UInt32(array)) == UInt8(1)
    }

    static func getIntegeri_v(target: Int, index: Int, data: UnsafeMutableRawPointer?) {
        raia_gl_get_integer_i_v(UInt32(target), UInt32(index), data)
    }

    static func beginTransformFeedback(primitiveMode: Int) {
        raia_gl_begin_transform_feedback(UInt32(primitiveMode))
    }

    static func endTransformFeedback() {
        raia_gl_end_transform_feedback()
    }

    static func bindBufferRange(target: Int, index: Int, buffer: Int, offset: Int, size: Int) {
        raia_gl_bind_buffer_range(UInt32(target), UInt32(index), UInt32(buffer), Int32(offset), Int32(size))
    }

    static func bindBufferBase(target: Int, index: Int, buffer: Int) {
        raia_gl_bind_buffer_base(UInt32(target), UInt32(index), UInt32(buffer))
    }

    static func transformFeedbackVaryings(program: Int, count: Int, varyings: UnsafePointer<UnsafePointer<CChar>?>?, bufferMode: Int) {
        raia_gl_transform_feedback_varyings(UInt32(program), Int32(count), varyings, UInt32(bufferMode))
    }

    static func getTransformFeedbackVarying(program: Int, index: Int, bufSize: Int, length: UnsafeMutableRawPointer?, size: UnsafeMutableRawPointer?, type: UnsafeMutableRawPointer?, name: UnsafeMutableRawPointer?) {
        raia_gl_get_transform_feedback_varying(UInt32(program), UInt32(index), Int32(bufSize), length, size, type, name)
    }

    static func vertexAttribIPointer(index: Int, size: Int, type: Int, stride: Int, pointer: UnsafeRawPointer?) {
        raia_gl_vertex_attrib_i_pointer(UInt32(index), Int32(size), UInt32(type), Int32(stride), pointer)
    }

    static func getVertexAttribIiv(index: Int, pname: Int, params: UnsafeMutableRawPointer?) {
        raia_gl_get_vertex_attrib_iiv(UInt32(index), UInt32(pname), params)
    }

    static func getVertexAttribIuiv(index: Int, pname: Int, params: UnsafeMutableRawPointer?) {
        raia_gl_get_vertex_attrib_iuiv(UInt32(index), UInt32(pname), params)
    }

    static func vertexAttribI4i(index: Int, x: Int, y: Int, z: Int, w: Int) {
        raia_gl_vertex_attrib_i4i(UInt32(index), Int32(x), Int32(y), Int32(z), Int32(w))
    }

    static func vertexAttribI4ui(index: Int, x: UInt32, y: UInt32, z: UInt32, w: UInt32) {
        raia_gl_vertex_attrib_i4ui(UInt32(index), UInt32(x), UInt32(y), UInt32(z), UInt32(w))
    }

    static func vertexAttribI4iv(index: Int, v: UnsafeMutableRawPointer?) {
        raia_gl_vertex_attrib_i4iv(UInt32(index), v)
    }

    static func vertexAttribI4uiv(index: Int, v: UnsafeMutableRawPointer?) {
        raia_gl_vertex_attrib_i4uiv(UInt32(index), v)
    }

    static func getUniformuiv(program: Int, location: Int, params: UnsafeMutableRawPointer?) {
        raia_gl_get_uniform_uiv(UInt32(program), Int32(location), params)
    }

    static func getFragDataLocation(program: Int, name: String) -> Int {
        return Int(raia_gl_get_frag_data_location(UInt32(program), name))
    }

    static func uniform1ui(location: Int, v0: UInt32) {
        raia_gl_uniform_1ui(Int32(location), UInt32(v0))
    }

    static func uniform2ui(location: Int, v0: UInt32, v1: UInt32) {
        raia_gl_uniform_2ui(Int32(location), UInt32(v0), UInt32(v1))
    }

    static func uniform3ui(location: Int, v0: UInt32, v1: UInt32, v2: UInt32) {
        raia_gl_uniform_3ui(Int32(location), UInt32(v0), UInt32(v1), UInt32(v2))
    }

    static func uniform4ui(location: Int, v0: UInt32, v1: UInt32, v2: UInt32, v3: UInt32) {
        raia_gl_uniform_4ui(Int32(location), UInt32(v0), UInt32(v1), UInt32(v2), UInt32(v3))
    }

    static func uniform1uiv(location: Int, count: Int, value: UnsafeMutableRawPointer?) {
        raia_gl_uniform_1uiv(Int32(location), Int32(count), value)
    }

    static func uniform2uiv(location: Int, count: Int, value: UnsafeMutableRawPointer?) {
        raia_gl_uniform_2uiv(Int32(location), Int32(count), value)
    }

    static func uniform3uiv(location: Int, count: Int, value: UnsafeMutableRawPointer?) {
        raia_gl_uniform_3uiv(Int32(location), Int32(count), value)
    }

    static func uniform4uiv(location: Int, count: Int, value: UnsafeMutableRawPointer?) {
        raia_gl_uniform_4uiv(Int32(location), Int32(count), value)
    }

    static func clearBufferiv(buffer: Int, drawbuffer: Int, value: UnsafeMutableRawPointer?) {
        raia_gl_clear_buffer_iv(UInt32(buffer), Int32(drawbuffer), value)
    }

    static func clearBufferuiv(buffer: Int, drawbuffer: Int, value: UnsafeMutableRawPointer?) {
        raia_gl_clear_buffer_uiv(UInt32(buffer), Int32(drawbuffer), value)
    }

    static func clearBufferfv(buffer: Int, drawbuffer: Int, value: UnsafeMutableRawPointer?) {
        raia_gl_clear_buffer_fv(UInt32(buffer), Int32(drawbuffer), value)
    }

    static func clearBufferfi(buffer: Int, drawbuffer: Int, depth: Float, stencil: Int) {
        raia_gl_clear_buffer_fi(UInt32(buffer), Int32(drawbuffer), depth, Int32(stencil))
    }

    static func getStringi(name: Int, index: Int) -> String? {
        guard let result = raia_gl_get_string_i(UInt32(name), UInt32(index)) else {
            return nil
        }
        return String(cString: result)
    }

    static func copyBufferSubData(readTarget: Int, writeTarget: Int, readOffset: Int, writeOffset: Int, size: Int) {
        raia_gl_copy_buffer_sub_data(UInt32(readTarget), UInt32(writeTarget), Int32(readOffset), Int32(writeOffset), Int32(size))
    }

    static func getUniformIndices(program: Int, uniformCount: Int, uniformNames: UnsafePointer<UnsafePointer<CChar>?>?, uniformIndices: UnsafeMutableRawPointer?) {
        raia_gl_get_uniform_indices(UInt32(program), Int32(uniformCount), uniformNames, uniformIndices)
    }

    static func getActiveUniformsiv(program: Int, uniformCount: Int, uniformIndices: UnsafeMutableRawPointer?, pname: Int, params: UnsafeMutableRawPointer?) {
        raia_gl_get_active_uniforms_iv(UInt32(program), Int32(uniformCount), uniformIndices, UInt32(pname), params)
    }

    static func getUniformBlockIndex(program: Int, uniformBlockName: String) -> Int {
        return Int(raia_gl_get_uniform_block_index(UInt32(program), uniformBlockName))
    }

    static func getActiveUniformBlockiv(program: Int, uniformBlockIndex: Int, pname: Int, params: UnsafeMutableRawPointer?) {
        raia_gl_get_active_uniform_block_iv(UInt32(program), UInt32(uniformBlockIndex), UInt32(pname), params)
    }

    static func getActiveUniformBlockName(program: Int, uniformBlockIndex: Int, bufSize: Int, length: UnsafeMutableRawPointer?, uniformBlockName: UnsafeMutableRawPointer?) {
        raia_gl_get_active_uniform_block_name(UInt32(program), UInt32(uniformBlockIndex), Int32(bufSize), length, uniformBlockName)
    }

    static func uniformBlockBinding(program: Int, uniformBlockIndex: Int, uniformBlockBinding: Int) {
        raia_gl_uniform_block_binding(UInt32(program), UInt32(uniformBlockIndex), UInt32(uniformBlockBinding))
    }

    static func drawArraysInstanced(mode: Int, first: Int, count: Int, instanceCount: Int) {
        raia_gl_draw_arrays_instanced(UInt32(mode), Int32(first), Int32(count), Int32(instanceCount))
    }

    static func drawElementsInstanced(mode: Int, count: Int, type: Int, indices: UnsafeRawPointer?, instanceCount: Int) {
        raia_gl_draw_elements_instanced(UInt32(mode), Int32(count), UInt32(type), indices, Int32(instanceCount))
    }

    // MARK: TODO

    static func fenceSync(condition: Int, flags: Int) -> UnsafeMutableRawPointer? {
        return raia_gl_fence_sync(UInt32(condition), UInt32(flags))
    }

    static func isSync(sync: UnsafeMutableRawPointer?) -> Bool {
        return raia_gl_is_sync(sync) == UInt8(1)
    }

    static func deleteSync(sync: UnsafeMutableRawPointer?) {
        raia_gl_delete_sync(sync)
    }

    static func clientWaitSync(sync: UnsafeMutableRawPointer?, flags: Int, timeout: UInt64) -> Int {
        return Int(raia_gl_client_wait_sync(sync, UInt32(flags), timeout))
    }

    static func waitSync(sync: UnsafeMutableRawPointer?, flags: Int, timeout: UInt64) {
        raia_gl_wait_sync(sync, UInt32(flags), timeout)
    }

    static func getInteger64v(pname: Int, data: UnsafeMutableRawPointer?) {
        raia_gl_get_integer_64v(UInt32(pname), data)
    }

    static func getSynciv(sync: UnsafeMutableRawPointer?, pname: Int, bufSize: Int, length: UnsafeMutableRawPointer?, values: UnsafeMutableRawPointer?) {
        raia_gl_get_sync_iv(sync, UInt32(pname), Int32(bufSize), length, values)
    }

    static func getInteger64i_v(target: Int, index: Int, data: UnsafeMutableRawPointer?) {
        raia_gl_get_integer_64i_v(UInt32(target), UInt32(index), data)
    }

    static func getBufferParameteri64v(target: Int, pname: Int, params: UnsafeMutableRawPointer?) {
        raia_gl_get_buffer_parameter_i64v(UInt32(target), UInt32(pname), params)
    }

    static func genSamplers(count: Int, samplers: UnsafeMutableRawPointer?) {
        raia_gl_gen_samplers(Int32(count), samplers)
    }

    static func deleteSamplers(count: Int, samplers: UnsafeMutableRawPointer?) {
        raia_gl_delete_samplers(Int32(count), samplers)
    }

    static func isSampler(sampler: Int) -> Bool {
        return raia_gl_is_sampler(UInt32(sampler)) == UInt8(1)
    }

    static func bindSampler(unit: Int, sampler: Int) {
        raia_gl_bind_sampler(UInt32(unit), UInt32(sampler))
    }

    static func samplerParameteri(sampler: Int, pname: Int, param: Int) {
        raia_gl_sampler_parameter_i(UInt32(sampler), UInt32(pname), Int32(param))
    }

    static func samplerParameteriv(sampler: Int, pname: Int, param: UnsafeMutableRawPointer?) {
        raia_gl_sampler_parameter_iv(UInt32(sampler), UInt32(pname), param)
    }

    static func samplerParameterf(sampler: Int, pname: Int, param: Float) {
        raia_gl_sampler_parameter_f(UInt32(sampler), UInt32(pname), param)
    }

    static func samplerParameterfv(sampler: Int, pname: Int, param: UnsafeMutableRawPointer?) {
        raia_gl_sampler_parameter_fv(UInt32(sampler), UInt32(pname), param)
    }

    static func getSamplerParameteriv(sampler: Int, pname: Int, params: UnsafeMutableRawPointer?) {
        raia_gl_get_sampler_parameter_iv(UInt32(sampler), UInt32(pname), params)
    }

    static func getSamplerParameterfv(sampler: Int, pname: Int, params: UnsafeMutableRawPointer?) {
        raia_gl_get_sampler_parameter_fv(UInt32(sampler), UInt32(pname), params)
    }

    static func vertexAttribDivisor(index: Int, divisor: Int) {
        raia_gl_vertex_attrib_divisor(UInt32(index), UInt32(divisor))
    }

    static func bindTransformFeedback(target: Int, id: Int) {
        raia_gl_bind_transform_feedback(UInt32(target), UInt32(id))
    }

    static func deleteTransformFeedbacks(n: Int, ids: UnsafeMutableRawPointer?) {
        raia_gl_delete_transform_feedbacks(Int32(n), ids)
    }

    static func genTransformFeedbacks(n: Int, ids: UnsafeMutableRawPointer?) {
        raia_gl_gen_transform_feedbacks(Int32(n), ids)
    }

    static func isTransformFeedback(id: Int) -> Bool {
        return raia_gl_is_transform_feedback(UInt32(id)) == UInt8(1)
    }

    static func pauseTransformFeedback() {
        raia_gl_pause_transform_feedback()
    }

    static func resumeTransformFeedback() {
        raia_gl_resume_transform_feedback()
    }

    static func getProgramBinary(program: Int, bufSize: Int, length: UnsafeMutableRawPointer?, binaryFormat: UnsafeMutableRawPointer?, binary: UnsafeMutableRawPointer) {
        raia_gl_get_program_binary(UInt32(program), Int32(bufSize), length, binaryFormat, binary)
    }

    static func programBinary(program: Int, binaryFormat: Int, binary: UnsafeRawPointer, length: Int) {
        raia_gl_program_binary(UInt32(program), UInt32(binaryFormat), binary, Int32(length))
    }

    static func programParameteri(program: Int, pname: Int, value: Int) {
        raia_gl_program_parameter_i(UInt32(program), UInt32(pname), Int32(value))
    }

    static func invalidateFramebuffer(target: Int, numAttachments: Int, attachments: UnsafeMutableRawPointer?) {
        raia_gl_invalidate_framebuffer(UInt32(target), Int32(numAttachments), attachments)
    }

    static func invalidateSubFramebuffer(target: Int, numAttachments: Int, attachments: UnsafeMutableRawPointer?, x: Int, y: Int, width: Int, height: Int) {
        raia_gl_invalidate_sub_framebuffer(UInt32(target), Int32(numAttachments), attachments, Int32(x), Int32(y), Int32(width), Int32(height))
    }

    static func texStorage2D(target: Int, levels: Int, internalFormat: Int, width: Int, height: Int) {
        raia_gl_tex_storage_2d(UInt32(target), Int32(levels), UInt32(internalFormat), Int32(width), Int32(height))
    }

    static func texStorage3D(target: Int, levels: Int, internalFormat: Int, width: Int, height: Int, depth: Int) {
        raia_gl_tex_storage_3d(UInt32(target), Int32(levels), UInt32(internalFormat), Int32(width), Int32(height), Int32(depth))
    }

    static func getInternalFormativ(target: Int, internalFormat: Int, pname: Int, bufSize: Int, params: UnsafeMutableRawPointer?) {
        raia_gl_get_internal_format_iv(UInt32(target), UInt32(internalFormat), UInt32(pname), Int32(bufSize), params)
    }

    // MARK: GL ES 3.1

    static func dispatchCompute(numGroupsX: Int, numGroupsY: Int, numGroupsZ: Int) {
        raia_gl_dispatch_compute(UInt32(numGroupsX), UInt32(numGroupsY), UInt32(numGroupsZ))
    }

    static func dispatchComputeIndirect(indirect: Int) {
        raia_gl_dispatch_compute_indirect(Int32(indirect))
    }

    static func drawArraysIndirect(mode: Int, indirect: UnsafeRawPointer) {
        raia_gl_draw_arrays_indirect(UInt32(mode), indirect)
    }

    static func drawElementsIndirect(mode: Int, type: Int, indirect: UnsafeRawPointer) {
        raia_gl_draw_elements_indirect(UInt32(mode), UInt32(type), indirect)
    }

    static func framebufferParameteri(target: Int, pname: Int, param: Int) {
        raia_gl_framebuffer_parameter_i(UInt32(target), UInt32(pname), Int32(param))
    }

    static func getFramebufferParameteriv(target: Int, pname: Int, params: UnsafeMutableRawPointer?) {
        raia_gl_get_framebuffer_parameter_iv(UInt32(target), UInt32(pname), params)
    }

    static func getProgramInterfaceiv(program: Int, programInterface: Int, pname: Int, params: UnsafeMutableRawPointer?) {
        raia_gl_get_program_interface_iv(UInt32(program), UInt32(programInterface), UInt32(pname), params)
    }

    static func getProgramResourceIndex(program: Int, programInterface: Int, name: String) -> Int {
        return Int(raia_gl_get_program_resource_index(UInt32(program), UInt32(programInterface), name))
    }

    static func getProgramResourceName(program: Int, programInterface: Int, index: Int, bufSize: Int, length: UnsafeMutableRawPointer?, name: UnsafeMutableRawPointer?) {
        raia_gl_get_program_resource_name(UInt32(program), UInt32(programInterface), UInt32(index), Int32(bufSize), length, name)
    }

    static func getProgramResourceiv(program: Int, programInterface: Int, index: Int, propCount: Int, props: UnsafeMutableRawPointer?, bufSize: Int, length: UnsafeMutableRawPointer?, params: UnsafeMutableRawPointer?) {
        raia_gl_get_program_resource_iv(UInt32(program), UInt32(programInterface), UInt32(index), Int32(propCount), props, Int32(bufSize), length, params)
    }

    static func getProgramResourceLocation(program: Int, programInterface: Int, name: String) -> Int {
        return Int(raia_gl_get_program_resource_location(UInt32(program), UInt32(programInterface), name))
    }

    static func useProgramStages(pipeline: Int, stages: Int, program: Int) {
        raia_gl_use_program_stages(UInt32(pipeline), UInt32(stages), UInt32(program))
    }

    static func activeShaderProgram(pipeline: Int, program: Int) {
        raia_gl_active_shader_program(UInt32(pipeline), UInt32(program))
    }

    static func createShaderProgramv(type: Int, count: Int, strings: UnsafePointer<UnsafePointer<CChar>?>?) -> Int {
        return Int(raia_gl_create_shader_program_v(UInt32(type), Int32(count), strings))
    }

    static func bindProgramPipeline(pipeline: Int) {
        raia_gl_bind_program_pipeline(UInt32(pipeline))
    }

    static func deleteProgramPipelines(n: Int, pipelines: UnsafeMutableRawPointer?) {
        raia_gl_delete_program_pipelines(Int32(n), pipelines)
    }

    static func genProgramPipelines(n: Int, pipelines: UnsafeMutableRawPointer?) {
        raia_gl_gen_program_pipelines(Int32(n), pipelines)
    }

    static func isProgramPipeline(pipeline: Int) -> Bool {
        return raia_gl_is_program_pipeline(UInt32(pipeline)) == UInt8(1)
    }

    static func getProgramPipelineiv(pipeline: Int, pname: Int, params: UnsafeMutableRawPointer?) {
        raia_gl_get_program_pipeline_iv(UInt32(pipeline), UInt32(pname), params)
    }

    static func programUniform1i(program: Int, location: Int, v0: Int) {
        raia_gl_program_uniform_1i(UInt32(program), Int32(location), Int32(v0))
    }

    static func programUniform2i(program: Int, location: Int, v0: Int, v1: Int) {
        raia_gl_program_uniform_2i(UInt32(program), Int32(location), Int32(v0), Int32(v1))
    }

    static func programUniform3i(program: Int, location: Int, v0: Int, v1: Int, v2: Int) {
        raia_gl_program_uniform_3i(UInt32(program), Int32(location), Int32(v0), Int32(v1), Int32(v2))
    }

    static func programUniform4i(program: Int, location: Int, v0: Int, v1: Int, v2: Int, v3: Int) {
        raia_gl_program_uniform_4i(UInt32(program), Int32(location), Int32(v0), Int32(v1), Int32(v2), Int32(v3))
    }

    static func programUniform1ui(program: Int, location: Int, v0: UInt32) {
        raia_gl_program_uniform_1ui(UInt32(program), Int32(location), UInt32(v0))
    }

    static func programUniform2ui(program: Int, location: Int, v0: UInt32, v1: UInt32) {
        raia_gl_program_uniform_2ui(UInt32(program), Int32(location), UInt32(v0), UInt32(v1))
    }

    static func programUniform3ui(program: Int, location: Int, v0: UInt32, v1: UInt32, v2: UInt32) {
        raia_gl_program_uniform_3ui(UInt32(program), Int32(location), UInt32(v0), UInt32(v1), UInt32(v2))
    }

    static func programUniform4ui(program: Int, location: Int, v0: UInt32, v1: UInt32, v2: UInt32, v3: UInt32) {
        raia_gl_program_uniform_4ui(UInt32(program), Int32(location), UInt32(v0), UInt32(v1), UInt32(v2), UInt32(v3))
    }

    static func programUniform1f(program: Int, location: Int, v0: Float) {
        raia_gl_program_uniform_1f(UInt32(program), Int32(location), v0)
    }

    static func programUniform2f(program: Int, location: Int, v0: Float, v1: Float) {
        raia_gl_program_uniform_2f(UInt32(program), Int32(location), v0, v1)
    }

    static func programUniform3f(program: Int, location: Int, v0: Float, v1: Float, v2: Float) {
        raia_gl_program_uniform_3f(UInt32(program), Int32(location), v0, v1, v2)
    }

    static func programUniform4f(program: Int, location: Int, v0: Float, v1: Float, v2: Float, v3: Float) {
        raia_gl_program_uniform_4f(UInt32(program), Int32(location), v0, v1, v2, v3)
    }

    static func programUniform1iv(program: Int, location: Int, count: Int, value: UnsafeMutableRawPointer?) {
        raia_gl_program_uniform_1iv(UInt32(program), Int32(location), Int32(count), value)
    }

    static func programUniform2iv(program: Int, location: Int, count: Int, value: UnsafeMutableRawPointer?) {
        raia_gl_program_uniform_2iv(UInt32(program), Int32(location), Int32(count), value)
    }

    static func programUniform3iv(program: Int, location: Int, count: Int, value: UnsafeMutableRawPointer?) {
        raia_gl_program_uniform_3iv(UInt32(program), Int32(location), Int32(count), value)
    }

    static func programUniform4iv(program: Int, location: Int, count: Int, value: UnsafeMutableRawPointer?) {
        raia_gl_program_uniform_4iv(UInt32(program), Int32(location), Int32(count), value)
    }

    static func programUniform1uiv(program: Int, location: Int, count: Int, value: UnsafeMutableRawPointer?) {
        raia_gl_program_uniform_1uiv(UInt32(program), Int32(location), Int32(count), value)
    }

    static func programUniform2uiv(program: Int, location: Int, count: Int, value: UnsafeMutableRawPointer?) {
        raia_gl_program_uniform_2uiv(UInt32(program), Int32(location), Int32(count), value)
    }

    static func programUniform3uiv(program: Int, location: Int, count: Int, value: UnsafeMutableRawPointer?) {
        raia_gl_program_uniform_3uiv(UInt32(program), Int32(location), Int32(count), value)
    }

    static func programUniform4uiv(program: Int, location: Int, count: Int, value: UnsafeMutableRawPointer?) {
        raia_gl_program_uniform_4uiv(UInt32(program), Int32(location), Int32(count), value)
    }

    static func programUniform1fv(program: Int, location: Int, count: Int, value: UnsafeMutableRawPointer?) {
        raia_gl_program_uniform_1fv(UInt32(program), Int32(location), Int32(count), value)
    }

    static func programUniform2fv(program: Int, location: Int, count: Int, value: UnsafeMutableRawPointer?) {
        raia_gl_program_uniform_2fv(UInt32(program), Int32(location), Int32(count), value)
    }

    static func programUniform3fv(program: Int, location: Int, count: Int, value: UnsafeMutableRawPointer?) {
        raia_gl_program_uniform_3fv(UInt32(program), Int32(location), Int32(count), value)
    }

    static func programUniform4fv(program: Int, location: Int, count: Int, value: UnsafeMutableRawPointer?) {
        raia_gl_program_uniform_4fv(UInt32(program), Int32(location), Int32(count), value)
    }

    static func programUniformMatrix2fv(program: Int, location: Int, count: Int, transpose: Bool, value: UnsafeMutableRawPointer?) {
        raia_gl_program_uniform_matrix_2fv(UInt32(program), Int32(location), Int32(count), UInt8(transpose ? 1 : 0), value)
    }

    static func programUniformMatrix3fv(program: Int, location: Int, count: Int, transpose: Bool, value: UnsafeMutableRawPointer?) {
        raia_gl_program_uniform_matrix_3fv(UInt32(program), Int32(location), Int32(count), UInt8(transpose ? 1 : 0), value)
    }

    static func programUniformMatrix4fv(program: Int, location: Int, count: Int, transpose: Bool, value: UnsafeMutableRawPointer?) {
        raia_gl_program_uniform_matrix_4fv(UInt32(program), Int32(location), Int32(count), UInt8(transpose ? 1 : 0), value)
    }

    static func programUniformMatrix2x3fv(program: Int, location: Int, count: Int, transpose: Bool, value: UnsafeMutableRawPointer?) {
        raia_gl_program_uniform_matrix_2x3fv(UInt32(program), Int32(location), Int32(count), UInt8(transpose ? 1 : 0), value)
    }

    static func programUniformMatrix3x2fv(program: Int, location: Int, count: Int, transpose: Bool, value: UnsafeMutableRawPointer?) {
        raia_gl_program_uniform_matrix_3x2fv(UInt32(program), Int32(location), Int32(count), UInt8(transpose ? 1 : 0), value)
    }

    static func programUniformMatrix2x4fv(program: Int, location: Int, count: Int, transpose: Bool, value: UnsafeMutableRawPointer?) {
        raia_gl_program_uniform_matrix_2x4fv(UInt32(program), Int32(location), Int32(count), UInt8(transpose ? 1 : 0), value)
    }

    static func programUniformMatrix4x2fv(program: Int, location: Int, count: Int, transpose: Bool, value: UnsafeMutableRawPointer?) {
        raia_gl_program_uniform_matrix_4x2fv(UInt32(program), Int32(location), Int32(count), UInt8(transpose ? 1 : 0), value)
    }

    static func programUniformMatrix3x4fv(program: Int, location: Int, count: Int, transpose: Bool, value: UnsafeMutableRawPointer?) {
        raia_gl_program_uniform_matrix_3x4fv(UInt32(program), Int32(location), Int32(count), UInt8(transpose ? 1 : 0), value)
    }

    static func programUniformMatrix4x3fv(program: Int, location: Int, count: Int, transpose: Bool, value: UnsafeMutableRawPointer?) {
        raia_gl_program_uniform_matrix_4x3fv(UInt32(program), Int32(location), Int32(count), UInt8(transpose ? 1 : 0), value)
    }

    static func validateProgramPipeline(pipeline: Int) {
        raia_gl_validate_program_pipeline(UInt32(pipeline))
    }

    static func getProgramPipelineInfoLog(pipeline: Int, bufSize: Int, length: UnsafeMutableRawPointer?, infoLog: UnsafeMutableRawPointer?) {
        raia_gl_get_program_pipeline_info_log(UInt32(pipeline), Int32(bufSize), length, infoLog)
    }

    static func bindImageTexture(unit: Int, texture: Int, level: Int, layered: Bool, layer: Int, access: Int, format: Int) {
        raia_gl_bind_image_texture(UInt32(unit), UInt32(texture), Int32(level), UInt8(layered ? 1 : 0), Int32(layer), UInt32(access), UInt32(format))
    }

    static func getBooleani_v(target: Int, index: Int, data: UnsafeMutableRawPointer?) {
        raia_gl_get_boolean_i_v(UInt32(target), UInt32(index), data)
    }

    static func memoryBarrier(barriers: Int) {
        raia_gl_memory_barrier(UInt32(barriers))
    }

    static func memoryBarrierByRegion(barriers: Int) {
        raia_gl_memory_barrier_by_region(UInt32(barriers))
    }

    static func texStorage2DMultisample(target: Int, samples: Int, internalFormat: Int, width: Int, height: Int, fixedSampleLocations: Bool) {
        raia_gl_tex_storage_2d_multisample(UInt32(target), Int32(samples), UInt32(internalFormat), Int32(width), Int32(height), UInt8(fixedSampleLocations ? 1 : 0))
    }

    static func getMultisamplefv(pname: Int, index: Int, val: UnsafeMutableRawPointer?) {
        raia_gl_get_multisample_fv(UInt32(pname), UInt32(index), val)
    }

    static func sampleMaski(maskNumber: Int, mask: Int) {
        raia_gl_sample_mask_i(UInt32(maskNumber), UInt32(mask))
    }

    static func getTexLevelParameteriv(target: Int, level: Int, pname: Int, params: UnsafeMutableRawPointer?) {
        raia_gl_get_tex_level_parameter_iv(UInt32(target), Int32(level), UInt32(pname), params)
    }

    static func getTexLevelParameterfv(target: Int, level: Int, pname: Int, params: UnsafeMutableRawPointer?) {
        raia_gl_get_tex_level_parameter_fv(UInt32(target), Int32(level), UInt32(pname), params)
    }

    static func bindVertexBuffer(bindingIndex: Int, buffer: Int, offset: Int, stride: Int) {
        raia_gl_bind_vertex_buffer(UInt32(bindingIndex), UInt32(buffer), Int32(offset), Int32(stride))
    }

    static func vertexAttribFormat(attribIndex: Int, size: Int, type: Int, normalized: Bool, relativeOffset: Int) {
        raia_gl_vertex_attrib_format(UInt32(attribIndex), Int32(size), UInt32(type), UInt8(normalized ? 1 : 0), UInt32(relativeOffset))
    }

    static func vertexAttribIFormat(attribIndex: Int, size: Int, type: Int, relativeOffset: Int) {
        raia_gl_vertex_attrib_i_format(UInt32(attribIndex), Int32(size), UInt32(type), UInt32(relativeOffset))
    }

    static func vertexAttribBinding(attribIndex: Int, bindingIndex: Int) {
        raia_gl_vertex_attrib_binding(UInt32(attribIndex), UInt32(bindingIndex))
    }

    static func vertexBindingDivisor(bindingIndex: Int, divisor: Int) {
        raia_gl_vertex_binding_divisor(UInt32(bindingIndex), UInt32(divisor))
    }

    // MARK: GL ES 3.2

    static func blendBarrier() {
        raia_gl_blend_barrier()
    }

    static func copyImageSubData(srcName: Int, srcTarget: Int, srcLevel: Int, srcX: Int, srcY: Int, srcZ: Int, dstName: Int, dstTarget: Int, dstLevel: Int, dstX: Int, dstY: Int, dstZ: Int, srcWidth: Int, srcHeight: Int, srcDepth: Int) {
        raia_gl_copy_image_sub_data(UInt32(srcName), UInt32(srcTarget), Int32(srcLevel), Int32(srcX), Int32(srcY), Int32(srcZ), UInt32(dstName), UInt32(dstTarget), Int32(dstLevel), Int32(dstX), Int32(dstY), Int32(dstZ), Int32(srcWidth), Int32(srcHeight), Int32(srcDepth))
    }

    static func debugMessageControl(source: Int, type: Int, severity: Int, count: Int, ids: UnsafeMutableRawPointer?, enabled: Bool) {
        raia_gl_debug_message_control(UInt32(source), UInt32(type), UInt32(severity), Int32(count), ids, UInt8(enabled ? 1 : 0))
    }

    static func debugMessageInsert(source: Int, type: Int, id: Int, severity: Int, length: Int, buf: String) {
        buf.withCString { cString in
            raia_gl_debug_message_insert(UInt32(source), UInt32(type), UInt32(id), UInt32(severity), Int32(length), cString)
        }
    }

    static func debugMessageCallback(callback: @escaping GLDEBUGPROC, userParam: UnsafeRawPointer?) {
        raia_gl_debug_message_callback(unsafeBitCast(callback, to: UnsafeMutableRawPointer.self), userParam)
    }

    static func getDebugMessageLog(count: Int, bufSize: Int, sources: UnsafeMutableRawPointer?, types: UnsafeMutableRawPointer?, ids: UnsafeMutableRawPointer?, severities: UnsafeMutableRawPointer?, lengths: UnsafeMutableRawPointer?, messageLog: UnsafeMutableRawPointer?) -> Int {
        return Int(raia_gl_get_debug_message_log(UInt32(count), Int32(bufSize), sources, types, ids, severities, lengths, messageLog))
    }

    static func pushDebugGroup(source: Int, id: Int, length: Int, message: String) {
        message.withCString { cString in
            raia_gl_push_debug_group(UInt32(source), UInt32(id), Int32(length), cString)
        }
    }

    static func popDebugGroup() {
        raia_gl_pop_debug_group()
    }

    static func objectLabel(identifier: Int, name: Int, length: Int, label: String) {
        label.withCString { cString in
            raia_gl_object_label(UInt32(identifier), UInt32(name), Int32(length), cString)
        }
    }

    static func getObjectLabel(identifier: Int, name: Int, bufSize: Int, length: UnsafeMutableRawPointer?, label: UnsafeMutableRawPointer?) {
        raia_gl_get_object_label(UInt32(identifier), UInt32(name), Int32(bufSize), length, label)
    }

    static func objectPtrLabel(ptr: UnsafeRawPointer, length: Int, label: String) {
        label.withCString { cString in
            raia_gl_object_ptr_label(ptr, Int32(length), cString)
        }
    }

    static func getObjectPtrLabel(ptr: UnsafeRawPointer, bufSize: Int, length: UnsafeMutableRawPointer?, label: UnsafeMutableRawPointer?) {
        raia_gl_get_object_ptr_label(ptr, Int32(bufSize), length, label)
    }

    static func getPointerv(pname: Int, params: UnsafeMutablePointer<UnsafeMutableRawPointer?>?) {
        raia_gl_get_pointer_v(UInt32(pname), params)
    }

    static func enablei(target: Int, index: Int) {
        raia_gl_enable_i(UInt32(target), UInt32(index))
    }

    static func disablei(target: Int, index: Int) {
        raia_gl_disable_i(UInt32(target), UInt32(index))
    }

    static func blendEquationi(buf: Int, mode: Int) {
        raia_gl_blend_equation_i(UInt32(buf), UInt32(mode))
    }

    static func blendEquationSeparatei(buf: Int, modeRGB: Int, modeAlpha: Int) {
        raia_gl_blend_equation_separate_i(UInt32(buf), UInt32(modeRGB), UInt32(modeAlpha))
    }

    static func blendFunci(buf: Int, src: Int, dst: Int) {
        raia_gl_blend_func_i(UInt32(buf), UInt32(src), UInt32(dst))
    }

    static func blendFuncSeparatei(buf: Int, srcRGB: Int, dstRGB: Int, srcAlpha: Int, dstAlpha: Int) {
        raia_gl_blend_func_separate_i(UInt32(buf), UInt32(srcRGB), UInt32(dstRGB), UInt32(srcAlpha), UInt32(dstAlpha))
    }

    static func colorMaski(index: Int, r: Bool, g: Bool, b: Bool, a: Bool) {
        raia_gl_color_mask_i(UInt32(index), UInt8(r ? 1 : 0), UInt8(g ? 1 : 0), UInt8(b ? 1 : 0), UInt8(a ? 1 : 0))
    }

    static func isEnabledi(target: Int, index: Int) -> Bool {
        return raia_gl_is_enabled_i(UInt32(target), UInt32(index)) == UInt8(1)
    }

    static func drawElementsBaseVertex(mode: Int, count: Int, type: Int, indices: UnsafeRawPointer?, baseVertex: Int) {
        raia_gl_draw_elements_base_vertex(UInt32(mode), Int32(count), UInt32(type), indices, Int32(baseVertex))
    }

    static func drawRangeElementsBaseVertex(mode: Int, start: Int, end: Int, count: Int, type: Int, indices: UnsafeRawPointer?, baseVertex: Int) {
        raia_gl_draw_range_elements_base_vertex(UInt32(mode), UInt32(start), UInt32(end), Int32(count), UInt32(type), indices, Int32(baseVertex))
    }

    static func drawElementsInstancedBaseVertex(mode: Int, count: Int, type: Int, indices: UnsafeRawPointer?, instanceCount: Int, baseVertex: Int) {
        raia_gl_draw_elements_instanced_base_vertex(UInt32(mode), Int32(count), UInt32(type), indices, Int32(instanceCount), Int32(baseVertex))
    }

    static func framebufferTexture(target: Int, attachment: Int, texture: Int, level: Int) {
        raia_gl_framebuffer_texture(UInt32(target), UInt32(attachment), UInt32(texture), Int32(level))
    }

    static func primitiveBoundingBox(minX: Float, minY: Float, minZ: Float, minW: Float, maxX: Float, maxY: Float, maxZ: Float, maxW: Float) {
        raia_gl_primitive_bounding_box(minX, minY, minZ, minW, maxX, maxY, maxZ, maxW)
    }

    static func getGraphicsResetStatus() -> Int {
        return Int(raia_gl_get_graphics_reset_status())
    }

    static func readNPixels(x: Int, y: Int, width: Int, height: Int, format: Int, type: Int, bufSize: Int, data: UnsafeMutableRawPointer) {
        raia_gl_read_n_pixels(Int32(x), Int32(y), Int32(width), Int32(height), UInt32(format), UInt32(type), Int32(bufSize), data)
    }

    static func getNUniformfv(program: Int, location: Int, bufSize: Int, params: UnsafeMutableRawPointer?) {
        raia_gl_get_n_uniform_fv(UInt32(program), Int32(location), Int32(bufSize), params)
    }

    static func getNUniformiv(program: Int, location: Int, bufSize: Int, params: UnsafeMutableRawPointer?) {
        raia_gl_get_n_uniform_iv(UInt32(program), Int32(location), Int32(bufSize), params)
    }

    static func getNUniformuiv(program: Int, location: Int, bufSize: Int, params: UnsafeMutableRawPointer?) {
        raia_gl_get_n_uniform_uiv(UInt32(program), Int32(location), Int32(bufSize), params)
    }

    static func minSampleShading(value: Float) {
        raia_gl_min_sample_shading(value)
    }

    static func patchParameteri(pname: Int, value: Int) {
        raia_gl_patch_parameter_i(UInt32(pname), Int32(value))
    }

    static func texParameterIiv(target: Int, pname: Int, params: UnsafeMutableRawPointer?) {
        raia_gl_tex_parameter_iiv(UInt32(target), UInt32(pname), params)
    }

    static func texParameterIuiv(target: Int, pname: Int, params: UnsafeMutableRawPointer?) {
        raia_gl_tex_parameter_iuiv(UInt32(target), UInt32(pname), params)
    }

    static func getTexParameterIiv(target: Int, pname: Int, params: UnsafeMutableRawPointer?) {
        raia_gl_get_tex_parameter_iiv(UInt32(target), UInt32(pname), params)
    }

    static func getTexParameterIuiv(target: Int, pname: Int, params: UnsafeMutableRawPointer?) {
        raia_gl_get_tex_parameter_iuiv(UInt32(target), UInt32(pname), params)
    }

    static func samplerParameterIiv(sampler: Int, pname: Int, param: UnsafeMutableRawPointer?) {
        raia_gl_sampler_parameter_iiv(UInt32(sampler), UInt32(pname), param)
    }

    static func samplerParameterIuiv(sampler: Int, pname: Int, param: UnsafeMutableRawPointer?) {
        raia_gl_sampler_parameter_iuiv(UInt32(sampler), UInt32(pname), param)
    }

    static func getSamplerParameterIiv(sampler: Int, pname: Int, params: UnsafeMutableRawPointer?) {
        raia_gl_get_sampler_parameter_iiv(UInt32(sampler), UInt32(pname), params)
    }

    static func getSamplerParameterIuiv(sampler: Int, pname: Int, params: UnsafeMutableRawPointer?) {
        raia_gl_get_sampler_parameter_iuiv(UInt32(sampler), UInt32(pname), params)
    }

    static func texBuffer(target: Int, internalFormat: Int, buffer: Int) {
        raia_gl_tex_buffer(UInt32(target), UInt32(internalFormat), UInt32(buffer))
    }

    static func texBufferRange(target: Int, internalFormat: Int, buffer: Int, offset: Int, size: Int) {
        raia_gl_tex_buffer_range(UInt32(target), UInt32(internalFormat), UInt32(buffer), Int32(offset), Int32(size))
    }

    static func texStorage3DMultisample(target: Int, samples: Int, internalFormat: Int, width: Int, height: Int, depth: Int, fixedSampleLocations: Bool) {
        raia_gl_tex_storage_3d_multisample(UInt32(target), Int32(samples), UInt32(internalFormat), Int32(width), Int32(height), Int32(depth), UInt8(fixedSampleLocations ? 1 : 0))
    }
}