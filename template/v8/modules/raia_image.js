import {Lib} from "raia_lib";
const lib = new Lib();

import {Std} from "raia_std";
const std = new Std();

var handle;
(function() {
    if (globalThis.__RAIA_IMAGE__ === undefined) {
        handle = lib.open("raia_image");
        lib.add(handle, "raia_image_load");
        lib.add(handle, "raia_image_load_jpg_blend_rgb");
        lib.add(handle, "raia_image_load_jpg_blend_rgba");
        lib.add(handle, "raia_image_load_png_blend_rgb");
        lib.add(handle, "raia_image_load_png_blend_rgba");
        globalThis.__RAIA_IMAGE__ = {};
    }
}());

export class Image {
    constructor() {
    }
    /**
     * 
     * @param {ArrayBuffer} pixels 
     * @param {number} width (int)
     * @param {number} height (int)
     * @param {string} filename 
     * @param {number} pos_x (int)
     * @param {number} pos_y (int)
     * @returns {{width:number, height:number}} {int, int}
     */
    loadImage(pixels, width, height, filename, pos_x = 0, pos_y = 0) {
        var json_str = JSON.stringify({
            "pixels": std.bufToPtr(pixels),
            "width": width,
            "height": height,
            "filename": filename,
            "pos_x": pos_x,
            "pos_y": pos_y
        });
        var ret = lib.call(handle, "raia_image_load", json_str); // (window, title)
        return JSON.parse(ret);
    }
    /**
     * 
     * @param {ArrayBuffer} pixels 
     * @param {number} width (int)
     * @param {number} height (int)
     * @param {string} filename 
     * @param {number} pos_x (int)
     * @param {number} pos_y (int)
     * @param {number} trim_x1 (int)
     * @param {number} trim_y1 (int)
     * @param {number} trim_x2 (int)
     * @param {number} trim_y2 (int)
     * @returns {{width:number, height:number}} {int, int}
     */
    loadJpgBlendRGB(pixels, width, height, filename, pos_x = 0, pos_y = 0,
        trim_x1 = 0, trim_y1 = 0, trim_x2 = -1, trim_y2 = -1) {
        var json_str = JSON.stringify({
            "pixels": std.bufToPtr(pixels),
            "width": width,
            "height": height,
            "filename": filename,
            "pos_x": pos_x,
            "pos_y": pos_y,
            "trim_x1": trim_x1,
            "trim_y1": trim_y1,
            "trim_x2": trim_x2,
            "trim_y2": trim_y2
        });
        var ret = lib.call(handle, "raia_image_load_jpg_blend_rgb", json_str); // (window, title)
        return JSON.parse(ret);
    }

    /**
     * @param {ArrayBuffer} pixels 
     * @param {number} width (int)
     * @param {number} height (int)
     * @param {string} filename 
     * @param {number} pos_x (int)
     * @param {number} pos_y (int)
     * @param {number} trim_x1 (int)
     * @param {number} trim_y1 (int)
     * @param {number} trim_x2 (int)
     * @param {number} trim_y2 (int)
     * @returns {{width:number, height:number}} {int, int}
     */

    loadJpgBlendRGBA(pixels, width, height,
        filename,
        pos_x = 0, pos_y = 0,
        trim_x1 = 0, trim_y1 = 0, trim_x2 = -1, trim_y2 = -1) {
        var json_str = JSON.stringify({
            "pixels": std.bufToPtr(pixels),
            "width": width,
            "height": height,
            "filename": filename,
            "pos_x": pos_x,
            "pos_y": pos_y,
            "trim_x1": trim_x1,
            "trim_y1": trim_y1,
            "trim_x2": trim_x2,
            "trim_y2": trim_y2
        });
        var ret = lib.call(handle, "raia_image_load_jpg_blend_rgba", json_str); // (window, title)
        return JSON.parse(ret);
    }

    /**
     * @param {ArrayBuffer} pixels 
     * @param {number} width (int)
     * @param {number} height (int)
     * @param {string} filename 
     * @param {number} pos_x (int)
     * @param {number} pos_y (int)
     * @param {number} trim_x1 (int)
     * @param {number} trim_y1 (int)
     * @param {number} trim_x2 (int)
     * @param {number} trim_y2 (int)
     * @returns {{width:number, height:number}} {int, int}
     */

    loadPngBlendRGB(pixels, width, height, filename, pos_x = 0, pos_y = 0,
        trim_x1 = 0, trim_y1 = 0, trim_x2 = -1, trim_y2 = -1) {
        var json_str = JSON.stringify({
            "pixels": std.bufToPtr(pixels),
            "width": width,
            "height": height,
            "filename": filename,
            "pos_x": pos_x,
            "pos_y": pos_y,
            "trim_x1": trim_x1,
            "trim_y1": trim_y1,
            "trim_x2": trim_x2,
            "trim_y2": trim_y2
        });
        var ret = lib.call(handle, "raia_image_load_png_blend_rgb", json_str); // (window, title)
        return JSON.parse(ret);
    }

    /**
     * @param {ArrayBuffer} pixels 
     * @param {number} width (int)
     * @param {number} height (int)
     * @param {string} filename 
     * @param {number} pos_x (int)
     * @param {number} pos_y (int)
     * @param {number} trim_x1 (int)
     * @param {number} trim_y1 (int)
     * @param {number} trim_x2 (int)
     * @param {number} trim_y2 (int)
     * @returns {{width:number, height:number}} {int, int}
     */

    loadPngBlendRGBA(pixels, width, height, filename, pos_x = 0, pos_y = 0,
        trim_x1 = 0, trim_y1 = 0, trim_x2 = -1, trim_y2 = -1) {
        var json_str = JSON.stringify({
            "pixels": std.bufToPtr(pixels),
            "width": width,
            "height": height,
            "filename": filename,
            "pos_x": pos_x,
            "pos_y": pos_y,
            "trim_x1": trim_x1,
            "trim_y1": trim_y1,
            "trim_x2": trim_x2,
            "trim_y2": trim_y2
        });
        var ret = lib.call(handle, "raia_image_load_png_blend_rgba", json_str); // (window, title)
        return JSON.parse(ret);
    }
}