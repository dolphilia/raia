import {GLES} from 'raia_gles';

export class GlesEx extends GLES {
    /**
     * 
     * @param {string} source 
     * @returns {uint}
     */
    createVertexShader(source) {
        var vs = super.createShader(this.VERTEX_SHADER);
        super.shaderSource(vs, 1, source, null);
        super.compileShader(vs);
        return vs;
    }
    /**
     * 
     * @param {string} source 
     * @returns {uint}
     */
    createFragmentShader(source) {
        var fs = super.createShader(this.FRAGMENT_SHADER);
        super.shaderSource(fs, 1, source, null);
        super.compileShader(fs);
        return fs;
    }
    /**
     * 
     * @param {string} vs_src 
     * @param {string} fs_src 
     * @returns {uint} program
     */
    createShaderProgram(vs_src, fs_src) {
        var vs = this.createVertexShader(vs_src);
        var fs = this.createFragmentShader(fs_src);
        var program = super.createProgram();
        super.attachShader(program, vs);
        super.attachShader(program, fs);
        super.deleteShader(vs);
        super.deleteShader(fs);
        super.linkProgram(program);
        return program;
    }
    /**
     * 
     * @returns {uint} program
     */
    createShaderProgram2D() {
        var vs_src = `
            attribute vec4 a_position;
            attribute vec2 a_texCoord;
            varying vec2 v_texCoord;
            void main() {
                gl_Position = a_position;
                v_texCoord = a_texCoord;
            }
        `;
        var fs_src = `
            precision mediump float;
            varying vec2 v_texCoord;
            uniform sampler2D s_texture;
            void main() {
                gl_FragColor = texture2D(s_texture, v_texCoord);
            }
        `;
        return this.createShaderProgram(vs_src, fs_src);
    }
    /**
     * 
     * @param {int} width 
     * @param {int} height 
     * @param {real} red 
     * @param {real} green 
     * @param {real} blue 
     * @param {real} alpha 
     */
    clearViewportColor(width, height, red, green, blue, alpha) {
        super.viewport(0, 0, width, height);
        super.clearColor(red, green, blue, alpha);
        super.clear(this.COLOR_BUFFER_BIT);
    }
    /**
     * 
     * @param {uint} texture 
     * @param {int} width 
     * @param {int} height 
     * @param {ArrayBuffer} pixels 
     * @param {int} color_type 
     */
    setTexture(texture, width, height, pixels, color_type) {
        super.pixelStorei(this.UNPACK_ALIGNMENT, 1);
        super.bindTexture(this.TEXTURE_2D, texture);
        super.texImage2D(this.TEXTURE_2D, 0, color_type, width, height, 0, color_type, this.UNSIGNED_BYTE, pixels);
        super.texParameteri(this.TEXTURE_2D, this.TEXTURE_MIN_FILTER, this.LINEAR);
        super.texParameteri(this.TEXTURE_2D, this.TEXTURE_MAG_FILTER, this.LINEAR);
    }
    /**
     * 
     * @param {uint} texture 
     * @param {int} width 
     * @param {int} height 
     * @param {ArrayBuffer} pixels 
     */
    setTextureRGB(texture, width, height, pixels) {
        this.setTexture(texture, width, height, pixels, this.RGB);
    }
    /**
     * 
     * @param {uint} texture 
     * @param {int} width 
     * @param {int} height 
     * @param {ArrayBuffer} pixels 
     */
    setTextureRGBA(texture, width, height, pixels) {
        this.setTexture(texture, width, height, pixels, this.RGBA);
    }
    /**
     * 
     * @param {uint} vao 
     * @param {uint} vbo 
     * @param {uint} ebo 
     */
    setVertexArray2D(vao, vbo, ebo) {
        var vertices = new Float32Array([
            -1.0, 1.0,  0.0,   // Position 0
            0.0,  0.0,         // TexCoord 0
            -1.0, -1.0, 0.0,   // Position 1
            0.0,  1.0,         // TexCoord 1
            1.0,  -1.0, 0.0,   // Position 2
            1.0,  1.0,         // TexCoord 2
            1.0,  1.0,  0.0,   // Position 3
            1.0,  0.0          // TexCoord 3
        ]);
        var indices = new Uint32Array([0, 1, 2, 0, 2, 3]);
        super.bindVertexArray(vao);
        super.bindBuffer(this.ARRAY_BUFFER, vbo);
        super.bufferData(this.ARRAY_BUFFER, 20 * 4, vertices.buffer, this.STATIC_DRAW);
        super.bindBuffer(this.ELEMENT_ARRAY_BUFFER, ebo);
        super.bufferData(this.ELEMENT_ARRAY_BUFFER, 6 * 4, indices.buffer, this.STATIC_DRAW);
        super.vertexAttribPointer(0, 3, this.FLOAT, this.FALSE, 5 * 4, 0); // x
        super.enableVertexAttribArray(0);
        super.vertexAttribPointer(1, 2, this.FLOAT, this.FALSE, 5 * 4, 12); // x
        super.enableVertexAttribArray(1);
        super.bindVertexArray(0);
    }
    /**
     * 
     * @returns {uint} textures
     */
    genTexture() {
        return super.genTextures(1);
    }
    /**
     * 
     * @param {uint} texture 
     */
    bindTexture2D(texture) {
        super.bindTexture(this.TEXTURE_2D, texture);
    }
}