
(function() {
    if (globalThis.__Raia__.GLES === undefined) {
        var handle = __Raia__.Lib.open("raia_gles");
        __Raia__.Lib.add(handle, "raia_gl_viewport");
        __Raia__.Lib.add(handle, "raia_gl_clear_color");
        __Raia__.Lib.add(handle, "raia_gl_clear");
        __Raia__.Lib.add(handle, "raia_gl_use_program");
        __Raia__.Lib.add(handle, "raia_gl_vertex_attrib_pointer");
        __Raia__.Lib.add(handle, "raia_gl_vertex_attrib_pointer_0");
        __Raia__.Lib.add(handle, "raia_gl_vertex_attrib_pointer_20");
        __Raia__.Lib.add(handle, "raia_gl_enable_vertex_attrib_array");
        __Raia__.Lib.add(handle, "raia_gl_tex_image_2d");
        __Raia__.Lib.add(handle, "raia_gl_active_texture");
        __Raia__.Lib.add(handle, "raia_gl_bind_texture");
        __Raia__.Lib.add(handle, "raia_gl_uniform_1i");
        __Raia__.Lib.add(handle, "raia_gl_draw_elements");
        __Raia__.Lib.add(handle, "raia_gl_create_shader");
        __Raia__.Lib.add(handle, "raia_gl_shader_source");
        __Raia__.Lib.add(handle, "raia_gl_compile_shader");
        __Raia__.Lib.add(handle, "raia_gl_get_shader_iv");
        __Raia__.Lib.add(handle, "raia_gl_create_program");
        __Raia__.Lib.add(handle, "raia_gl_attach_shader");
        __Raia__.Lib.add(handle, "raia_gl_delete_shader");
        __Raia__.Lib.add(handle, "raia_gl_link_program");
        __Raia__.Lib.add(handle, "raia_gl_pixel_store_i");
        __Raia__.Lib.add(handle, "raia_gl_gen_textures");
        __Raia__.Lib.add(handle, "raia_gl_tex_parameter_i");
        __Raia__.Lib.add(handle, "raia_gl_get_attrib_location");
        __Raia__.Lib.add(handle, "raia_gl_get_uniform_location");
        __Raia__.Lib.add(handle, "raia_gl_gen_vertex_arrays");
        __Raia__.Lib.add(handle, "raia_gl_gen_buffers");
        __Raia__.Lib.add(handle, "raia_gl_bind_vertex_array");
        __Raia__.Lib.add(handle, "raia_gl_bind_buffer");
        __Raia__.Lib.add(handle, "raia_gl_buffer_data");
        globalThis.__Raia__.GLES = {};
    }
})();

export class GLES {
    static FALSE = 0;
    static TRUE = 1;
    static TRIANGLES = 0x0004;
    static UNPACK_ALIGNMENT = 0x0CF5;
    static TEXTURE_2D = 0x0DE1;
    static UNSIGNED_BYTE = 0x1401;
    static UNSIGNED_SHORT = 0x1403;
    static UNSIGNED_INT = 0x1405;
    static FLOAT = 0x1406;
    static RGB = 0x1907;
    static RGBA = 0x1908;
    static NEAREST = 0x2600;
    static LINEAR = 0x2601;
    static TEXTURE_MAG_FILTER = 0x2800;
    static TEXTURE_MIN_FILTER = 0x2801;
    static TEXTURE0 = 0x84C0;
    static ARRAY_BUFFER = 0x8892;
    static ELEMENT_ARRAY_BUFFER = 0x8893;
    static STATIC_DRAW = 0x88E4;
    static FRAGMENT_SHADER = 0x8B30;
    static VERTEX_SHADER = 0x8B31;
    static COMPILE_STATUS = 0x8B81;
    static COLOR_BUFFER_BIT = 0x00004000;


    constructor() {
    }
    viewport(x, y, width, height) {
        var args = JSON.stringify({
            "x": x,
            "y": y,
            "width": width,
            "height": height
        });
        __Raia__.Lib.call("raia_gl_viewport", args);
    }
    clearColor(red, green, blue, alpha) {
        var args = JSON.stringify({
            "red": red,
            "green": green,
            "blue": blue,
            "alpha": alpha
        });
        __Raia__.Lib.call("raia_gl_clear_color", args);
    }
    clear(mask) {
        var args = JSON.stringify({
            "mask": mask
        });
        __Raia__.Lib.call("raia_gl_clear", args);
    }
    useProgram(program) {
        var args = JSON.stringify({
            "program": program
        });
        __Raia__.Lib.call("raia_gl_use_program", args);
    }
    vertexAttribPointer(index, size, type, normalized, stride, pointer) {
        var args = JSON.stringify({
            "index": index,
            "size": size,
            "type": type,
            "normalized": normalized,
            "stride": stride,
            "pointer": pointer
        });
        __Raia__.Lib.call("raia_gl_vertex_attrib_pointer", args);
    }
    vertexAttribPointer0(index, size, type, normalized, stride) {
        var args = JSON.stringify({
            "index": index,
            "size": size,
            "type": type,
            "normalized": normalized,
            "stride": stride
        });
        __Raia__.Lib.call("raia_gl_vertex_attrib_pointer_0", args);
    }
    vertexAttribPointer20(index, size, type, normalized, stride) {
        var args = JSON.stringify({
            "index": index,
            "size": size,
            "type": type,
            "normalized": normalized,
            "stride": stride
        });
        __Raia__.Lib.call("raia_gl_vertex_attrib_pointer_20", args);
    }
    enableVertexAttribArray(index) {
        var args = JSON.stringify({
            "index": index
        });
        __Raia__.Lib.call("raia_gl_enable_vertex_attrib_array", args);
    }
    texImage2D(target, level, internalformat, width, height, border, format, type, pixels) {
        var args = JSON.stringify({
            "target": target,
            "level": level,
            "internalformat": internalformat,
            "width": width,
            "height": height,
            "border": border,
            "format": format,
            "type": type,
            "pixels": __Raia__.Core.arrayBufferToPointer(pixels)
        });
        __Raia__.Lib.call("raia_gl_tex_image_2d", args);
    }
    activeTexture(texture) {
        var args = JSON.stringify({
            "texture": texture
        });
        __Raia__.Lib.call("raia_gl_active_texture", args);
    }
    bindTexture(target, texture) {
        var args = JSON.stringify({
            "target": target,
            "texture": texture
        });
        __Raia__.Lib.call("raia_gl_bind_texture", args);
    }
    uniform1i(location, v0) {
        var args = JSON.stringify({
            "location": location,
            "v0": v0
        });
        __Raia__.Lib.call("raia_gl_uniform_1i", args);
    }
    drawElements(mode, count, type, indices) {
        var args = JSON.stringify({
            "mode": mode,
            "count": count,
            "type": type,
            "indices": indices
        });
        __Raia__.Lib.call("raia_gl_draw_elements", args);
    }
    createShader(type) {
        var args = JSON.stringify({
            "type": type
        });
        var ret = __Raia__.Lib.call("raia_gl_create_shader", args);
        return JSON.parse(ret).result;
    }
    shaderSource(shader, count, string, length) {
        var args = JSON.stringify({
            "shader": shader,
            "count": count,
            "string": string,
            "length": length
        });
        __Raia__.Lib.call("raia_gl_shader_source", args);
    }
    compileShader(shader) {
        var args = JSON.stringify({
            "shader": shader
        });
        __Raia__.Lib.call("raia_gl_compile_shader", args);
    }
    getShaderiv(shader, pname) {
        var args = JSON.stringify({
            "shader": shader,
            "pname": pname
        });
        var ret = __Raia__.Lib.call("raia_gl_get_shader_iv", args);
        return JSON.parse(ret).result;
    }
    createProgram() {
        var ret = __Raia__.Lib.call("raia_gl_create_program", "");
        return JSON.parse(ret).result;
    }
    attachShader(program, shader) {
        var args = JSON.stringify({
            "program": program,
            "shader": shader
        });
        __Raia__.Lib.call("raia_gl_attach_shader", args);
    }
    deleteShader(shader) {
        var args = JSON.stringify({
            "shader": shader
        });
        __Raia__.Lib.call("raia_gl_delete_shader", args);
    }
    linkProgram(program) {
        var args = JSON.stringify({
            "program": program
        });
        __Raia__.Lib.call("raia_gl_link_program", args);
    }
    pixelStorei(pname, param) {
        var args = JSON.stringify({
            "pname": pname,
            "param": param
        });
        __Raia__.Lib.call("raia_gl_pixel_store_i", args);
    }
    genTextures(n) {
        var args = JSON.stringify({
            "n": n
        });
        var ret = __Raia__.Lib.call("raia_gl_gen_textures", args);
        return JSON.parse(ret).result;
    }
    texParameteri(target, pname, param) {
        var args = JSON.stringify({
            "target": target,
            "pname": pname,
            "param": param
        });
        __Raia__.Lib.call("raia_gl_tex_parameter_i", args);
    }
    getAttribLocation(program, name) {
        var args = JSON.stringify({
            "program": program,
            "name": name
        });
        var ret = __Raia__.Lib.call("raia_gl_get_attrib_location", args);
        return JSON.parse(ret).result;
    }
    getUniformLocation(program, name) {
        var args = JSON.stringify({
            "program": program,
            "name": name
        });
        var ret = __Raia__.Lib.call("raia_gl_get_uniform_location", args);
        return JSON.parse(ret).result;
    }
    genVertexArrays(n) {
        var args = JSON.stringify({
            "n": n
        });
        var ret = __Raia__.Lib.call("raia_gl_gen_vertex_arrays", args);
        return JSON.parse(ret).result;
    }
    genBuffers(n) {
        var args = JSON.stringify({
            "n": n
        });
        var ret = __Raia__.Lib.call("raia_gl_gen_buffers", args);
        return JSON.parse(ret).result;
    }
    bindVertexArray(array) {
        var args = JSON.stringify({
            "array": array
        });
        __Raia__.Lib.call("raia_gl_bind_vertex_array", args);
    }
    bindBuffer(target, buffer) {
        var args = JSON.stringify({
            "target": target,
            "buffer": buffer
        });
        __Raia__.Lib.call("raia_gl_bind_buffer", args);
    }
    bufferData(target, size, data, usage) {
        var args = JSON.stringify({
            "target": target,
            "size": size,
            "data": __Raia__.Core.arrayBufferToPointer(data),
            "usage": usage
        });
        __Raia__.Lib.call("raia_gl_buffer_data", args);
    }
}