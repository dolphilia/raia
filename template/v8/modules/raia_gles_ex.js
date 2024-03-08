import {GLES} from 'raia_gles';

export class GlesEx extends GLES {

    /**
     * @param {string} source 
     * @returns {number} (uint)
     */

    createVertexShader(source) {
        var vs = super.createShaderAlt(GLES.VERTEX_SHADER);
        super.shaderSourceAlt(vs, 1, source, null);
        super.compileShaderAlt(vs);
        return vs;
    }

    /**
     * @param {string} source 
     * @returns {number} (uint)
     */

    createFragmentShader(source) {
        var fs = super.createShaderAlt(GLES.FRAGMENT_SHADER);
        super.shaderSourceAlt(fs, 1, source, null);
        super.compileShaderAlt(fs);
        return fs;
    }

    /**
     * @param {string} vs_src 
     * @param {string} fs_src 
     * @returns {number} (uint) program
     */

    createShaderProgram(vs_src, fs_src) {
        var vs = this.createVertexShader(vs_src);
        var fs = this.createFragmentShader(fs_src);
        var program = super.createProgramAlt();
        super.attachShaderAlt(program, vs);
        super.attachShaderAlt(program, fs);
        super.deleteShaderAlt(vs);
        super.deleteShaderAlt(fs);
        super.linkProgramAlt(program);
        return program;
    }

    /**
     * @returns {number} (uint) program
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
     * @param {number} width (int)
     * @param {number} height (int)
     * @param {number} red (real)
     * @param {number} green (real)
     * @param {number} blue (real)
     * @param {number} alpha (real)
     */

    clearViewportColor(width, height, red, green, blue, alpha) {
        super.viewportAlt(0, 0, width, height);
        super.clearColorAlt(red, green, blue, alpha);
        super.clearAlt(GLES.COLOR_BUFFER_BIT);
    }

    /**
     * @param {number} texture (uint)
     * @param {number} width (int)
     * @param {number} height (int)
     * @param {ArrayBuffer} pixels 
     * @param {number} color_type (int)
     */

    setTexture(texture, width, height, pixels, color_type) {
        super.pixelStoreiAlt(GLES.UNPACK_ALIGNMENT, 1);
        super.bindTextureAlt(GLES.TEXTURE_2D, texture);
        super.texImage2DAlt(GLES.TEXTURE_2D, 0, color_type, width, height, 0, color_type, GLES.UNSIGNED_BYTE, pixels);
        super.texParameteriAlt(GLES.TEXTURE_2D, GLES.TEXTURE_MIN_FILTER, GLES.LINEAR);
        super.texParameteriAlt(GLES.TEXTURE_2D, GLES.TEXTURE_MAG_FILTER, GLES.LINEAR);
    }

    /**
     * @param {number} texture (uint)
     * @param {number} width (int)
     * @param {number} height (int)
     * @param {ArrayBuffer} pixels 
     */

    setTextureRGB(texture, width, height, pixels) {
        this.setTexture(texture, width, height, pixels, GLES.RGB);
    }

    /**
     * @param {number} texture (uint)
     * @param {number} width (int)
     * @param {number} height (int)
     * @param {ArrayBuffer} pixels 
     */

    setTextureRGBA(texture, width, height, pixels) {
        this.setTexture(texture, width, height, pixels, GLES.RGBA);
    }

    /**
     * @param {number} vao (uint)
     * @param {number} vbo (uint)
     * @param {number} ebo (uint)
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
        super.bindVertexArrayAlt(vao);
        super.bindBufferAlt(GLES.ARRAY_BUFFER, vbo);
        super.bufferDataAlt(GLES.ARRAY_BUFFER, 20 * 4, vertices.buffer, GLES.STATIC_DRAW);
        super.bindBufferAlt(GLES.ELEMENT_ARRAY_BUFFER, ebo);
        super.bufferDataAlt(GLES.ELEMENT_ARRAY_BUFFER, 6 * 4, indices.buffer, GLES.STATIC_DRAW);
        super.vertexAttribPointerAlt(0, 3, GLES.FLOAT, GLES.FALSE, 5 * 4, 0); // x
        super.enableVertexAttribArrayAlt(0);
        super.vertexAttribPointerAlt(1, 2, GLES.FLOAT, GLES.FALSE, 5 * 4, 12); // x
        super.enableVertexAttribArrayAlt(1);
        super.bindVertexArrayAlt(0);
    }

    /**
     * @returns {number} textures (uint)
     */

    genTexture() {
        return super.genTexturesAlt(1);
    }

    /**
     * @param {number} texture (uint)
     */

    bindTexture2D(texture) {
        super.bindTextureAlt(GLES.TEXTURE_2D, texture);
    }
}