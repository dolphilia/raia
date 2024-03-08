import {Std} from 'raia_std';
import {GlesEx} from 'raia_gles_ex';

const std = new Std();

/**
 * @extends GlesEx
 */

export class Texture extends GlesEx {

    /**
     * @param {number} width (int)
     * @param {number} height (int)
     * @param {number} depth (uint)
     */

    constructor(width = 32, height = 32, depth = 4) {
        super();
        this.width = width;
        this.height = height;
        this.pixels = new ArrayBuffer(this.width * this.height * depth);
        this.view = new Uint8Array(this.pixels);
        for(var i = 0; i < this.width * this.height * depth; i++) {
            this.view[i] = std.rand(0, 255);
        }
        this.texture = super.genTexture();
        super.bindTexture2D(this.texture);
    }
}