import {Lib} from "raia_lib";
const lib = new Lib();

import {Std} from "raia_std";
const std = new Std();

(function() {
    if (globalThis.__RAIA_GLES__ === undefined) {
        var handle = lib.open("raia_gles");
        lib.add(handle, "raia_gl_viewport");
        lib.add(handle, "raia_gl_clear_color");
        lib.add(handle, "raia_gl_clear");
        lib.add(handle, "raia_gl_use_program");
        lib.add(handle, "raia_gl_vertex_attrib_pointer");
        lib.add(handle, "raia_gl_enable_vertex_attrib_array");
        lib.add(handle, "raia_gl_tex_image_2d");
        lib.add(handle, "raia_gl_active_texture");
        lib.add(handle, "raia_gl_bind_texture");
        lib.add(handle, "raia_gl_uniform_1i");
        lib.add(handle, "raia_gl_draw_elements");
        lib.add(handle, "raia_gl_create_shader");
        lib.add(handle, "raia_gl_shader_source");
        lib.add(handle, "raia_gl_compile_shader");
        lib.add(handle, "raia_gl_get_shader_iv");
        lib.add(handle, "raia_gl_create_program");
        lib.add(handle, "raia_gl_attach_shader");
        lib.add(handle, "raia_gl_delete_shader");
        lib.add(handle, "raia_gl_link_program");
        lib.add(handle, "raia_gl_pixel_store_i");
        lib.add(handle, "raia_gl_gen_textures");
        lib.add(handle, "raia_gl_tex_parameter_i");
        lib.add(handle, "raia_gl_get_attrib_location");
        lib.add(handle, "raia_gl_get_uniform_location");
        lib.add(handle, "raia_gl_gen_vertex_arrays");
        lib.add(handle, "raia_gl_gen_buffers");
        lib.add(handle, "raia_gl_bind_vertex_array");
        lib.add(handle, "raia_gl_bind_buffer");
        lib.add(handle, "raia_gl_buffer_data");
        lib.add(handle, "raia_gl_delete_vertex_arrays");
        lib.add(handle, "raia_gl_delete_buffers");
        lib.add(handle, "raia_gl_delete_textures");
        globalThis.__RAIA_GLES__ = {};
    }
})();

export class GLES {
    constructor() {
        this.FALSE = 0;
        this.TRUE = 1;
        this.TRIANGLES = 0x0004;
        this.UNPACK_ALIGNMENT = 0x0CF5;
        this.TEXTURE_2D = 0x0DE1;
        this.UNSIGNED_BYTE = 0x1401;
        this.UNSIGNED_SHORT = 0x1403;
        this.UNSIGNED_INT = 0x1405;
        this.FLOAT = 0x1406;
        this.RGB = 0x1907;
        this.RGBA = 0x1908;
        this.NEAREST = 0x2600;
        this.LINEAR = 0x2601;
        this.TEXTURE_MAG_FILTER = 0x2800;
        this.TEXTURE_MIN_FILTER = 0x2801;
        this.TEXTURE_WRAP_S = 0x2802;
        this.TEXTURE_WRAP_T = 0x2803;
        this.CLAMP_TO_EDGE = 0x812F;
        this.TEXTURE0 = 0x84C0;
        this.ARRAY_BUFFER = 0x8892;
        this.ELEMENT_ARRAY_BUFFER = 0x8893;
        this.STATIC_DRAW = 0x88E4;
        this.FRAGMENT_SHADER = 0x8B30;
        this.VERTEX_SHADER = 0x8B31;
        this.COMPILE_STATUS = 0x8B81;
        this.COLOR_BUFFER_BIT = 0x00004000;
    }
    /**
     * @param {int} x 
     * @param {int} y 
     * @param {int} width 
     * @param {int} height 
     */
    viewport(x, y, width, height) {
        var args = JSON.stringify({
            "x": x,
            "y": y,
            "width": width,
            "height": height
        });
        lib.call("raia_gl_viewport", args);
    }
    /**
     * @param {real} red 0.0 ~ 1.0
     * @param {real} green 0.0 ~ 1.0
     * @param {real} blue 0.0 ~ 1.0
     * @param {real} alpha 0.0 ~ 1.0
     */
    clearColor(red, green, blue, alpha) {
        var args = JSON.stringify({
            "red": red,
            "green": green,
            "blue": blue,
            "alpha": alpha
        });
        lib.call("raia_gl_clear_color", args);
    }
    /**
     * @param {uint} mask 
     */
    clear(mask) {
        var args = JSON.stringify({
            "mask": mask
        });
        lib.call("raia_gl_clear", args);
    }
    /**
     * @param {uint} program 
     */
    useProgram(program) {
        var args = JSON.stringify({
            "program": program
        });
        lib.call("raia_gl_use_program", args);
    }
    /**
     * @param {uint} index 
     * @param {int} size 
     * @param {uint} type 
     * @param {uint} normalized 0 or 1
     * @param {int} stride 
     * @param {uintptr} pointer 
     */
    vertexAttribPointer(index, size, type, normalized, stride, pointer) {
        var args = JSON.stringify({
            "index": index,
            "size": size,
            "type": type,
            "normalized": normalized,
            "stride": stride,
            "pointer": pointer
        });
        lib.call("raia_gl_vertex_attrib_pointer", args);
    }
    /**
     * @param {uint} index 
     */
    enableVertexAttribArray(index) {
        var args = JSON.stringify({
            "index": index
        });
        lib.call("raia_gl_enable_vertex_attrib_array", args);
    }
    /**
     * @param {uint} target 
     * @param {int} level 
     * @param {int} internalformat 
     * @param {int} width 
     * @param {int} height 
     * @param {int} border 
     * @param {uint} format 
     * @param {uint} type 
     * @param {ArrayBuffer} pixels 
     */
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
            "pixels": std.arrayBufferToPointer(pixels)
        });
        lib.call("raia_gl_tex_image_2d", args);
    }
    /**
     * @param {uint} texture 
     */
    activeTexture(texture) {
        var args = JSON.stringify({
            "texture": texture
        });
        lib.call("raia_gl_active_texture", args);
    }
    /**
     * 
     * @param {uint} target 
     * @param {uint} texture 
     */
    bindTexture(target, texture) {
        var args = JSON.stringify({
            "target": target,
            "texture": texture
        });
        lib.call("raia_gl_bind_texture", args);
    }
    /**
     * 
     * @param {int} location 
     * @param {int} v0 
     */
    uniform1i(location, v0) {
        var args = JSON.stringify({
            "location": location,
            "v0": v0
        });
        lib.call("raia_gl_uniform_1i", args);
    }
    /**
     * 
     * @param {uint} mode 
     * @param {int} count 
     * @param {uint} type 
     * @param {uintptr | null} indices 
     */
    drawElements(mode, count, type, indices) {
        var args = JSON.stringify({
            "mode": mode,
            "count": count,
            "type": type,
            "indices": indices
        });
        lib.call("raia_gl_draw_elements", args);
    }
    /**
     * 
     * @param {uint} type 
     * @returns {uint} shader
     */
    createShader(type) {
        var args = JSON.stringify({
            "type": type
        });
        var ret = lib.call("raia_gl_create_shader", args);
        return JSON.parse(ret).result;
    }
    /**
     * 
     * @param {uint} shader 
     * @param {int} count 
     * @param {string} string 
     * @param {int | null} length 
     */
    shaderSource(shader, count, string, length) {
        var args = JSON.stringify({
            "shader": shader,
            "count": count,
            "string": string,
            "length": length
        });
        lib.call("raia_gl_shader_source", args);
    }
    /**
     * 
     * @param {uint} shader 
     */
    compileShader(shader) {
        var args = JSON.stringify({
            "shader": shader
        });
        lib.call("raia_gl_compile_shader", args);
    }
    /**
     * 
     * @param {uint} shader 
     * @param {uint} pname 
     * @returns {int} params
     */
    getShaderiv(shader, pname) {
        var args = JSON.stringify({
            "shader": shader,
            "pname": pname
        });
        var ret = lib.call("raia_gl_get_shader_iv", args);
        return JSON.parse(ret).result;
    }
    /**
     * 
     * @returns {uint} program
     */
    createProgram() {
        var ret = lib.call("raia_gl_create_program");
        return JSON.parse(ret).result;
    }
    /**
     * 
     * @param {uint} program 
     * @param {uint} shader 
     */
    attachShader(program, shader) {
        var args = JSON.stringify({
            "program": program,
            "shader": shader
        });
        lib.call("raia_gl_attach_shader", args);
    }
    /**
     * 
     * @param {uint} shader 
     */
    deleteShader(shader) {
        var args = JSON.stringify({
            "shader": shader
        });
        lib.call("raia_gl_delete_shader", args);
    }
    /**
     * 
     * @param {uint} program 
     */
    linkProgram(program) {
        var args = JSON.stringify({
            "program": program
        });
        lib.call("raia_gl_link_program", args);
    }
    /**
     * 
     * @param {uint} pname 
     * @param {int} param 
     */
    pixelStorei(pname, param) {
        var args = JSON.stringify({
            "pname": pname,
            "param": param
        });
        lib.call("raia_gl_pixel_store_i", args);
    }
    /**
     * 
     * @param {int} n 
     * @returns {uint} textures
     */
    genTextures(n) {
        var args = JSON.stringify({
            "n": n
        });
        var ret = lib.call("raia_gl_gen_textures", args);
        return JSON.parse(ret).result;
    }
    /**
     * 
     * @param {uint} target 
     * @param {uint} pname 
     * @param {int} param 
     */
    texParameteri(target, pname, param) {
        var args = JSON.stringify({
            "target": target,
            "pname": pname,
            "param": param
        });
        lib.call("raia_gl_tex_parameter_i", args);
    }
    /**
     * 
     * @param {uint} program 
     * @param {string} name 
     * @returns {int} location
     */
    getAttribLocation(program, name) {
        var args = JSON.stringify({
            "program": program,
            "name": name
        });
        var ret = lib.call("raia_gl_get_attrib_location", args);
        return JSON.parse(ret).result;
    }
    /**
     * 
     * @param {uint} program 
     * @param {string} name 
     * @returns {int} location
     */
    getUniformLocation(program, name) {
        var args = JSON.stringify({
            "program": program,
            "name": name
        });
        var ret = lib.call("raia_gl_get_uniform_location", args);
        return JSON.parse(ret).result;
    }
    /**
     * 
     * @param {int} n 
     * @returns {uint} arrays
     */
    genVertexArrays(n) {
        var args = JSON.stringify({
            "n": n
        });
        var ret = lib.call("raia_gl_gen_vertex_arrays", args);
        return JSON.parse(ret).result;
    }
    /**
     * 
     * @param {int} n 
     * @returns {uint} buffers
     */
    genBuffers(n) {
        var args = JSON.stringify({
            "n": n
        });
        var ret = lib.call("raia_gl_gen_buffers", args);
        return JSON.parse(ret).result;
    }
    /**
     * 
     * @param {uint} array 
     */
    bindVertexArray(array) {
        var args = JSON.stringify({
            "array": array
        });
        lib.call("raia_gl_bind_vertex_array", args);
    }
    /**
     * 
     * @param {uint} target 
     * @param {uint} buffer 
     */
    bindBuffer(target, buffer) {
        var args = JSON.stringify({
            "target": target,
            "buffer": buffer
        });
        lib.call("raia_gl_bind_buffer", args);
    }
    /**
     * 
     * @param {uint} target 
     * @param {uint} size 
     * @param {ArrayBuffer} data 
     * @param {uint} usage 
     */
    bufferData(target, size, data, usage) {
        var args = JSON.stringify({
            "target": target,
            "size": size,
            "data": std.arrayBufferToPointer(data),
            "usage": usage
        });
        lib.call("raia_gl_buffer_data", args);
    }
    /**
     * 
     * @param {uint} arrays 
     */
    deleteVertexArrays(arrays) {
        var args = JSON.stringify({
            "arrays": arrays
        });
        lib.call("raia_gl_delete_vertex_arrays", args);
    }
    /**
     * 
     * @param {uint} buffers 
     */
    deleteBuffers(buffers) {
        var args = JSON.stringify({
            "buffers": buffers
        });
        lib.call("raia_gl_delete_buffers", args);
    }
    /**
     * 
     * @param {uint} textures 
     */
    deleteTextures(textures) {
        var args = JSON.stringify({
            "textures": textures
        });
        lib.call("raia_gl_delete_textures", args);
    }
}