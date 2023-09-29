import {Lib} from "raia_lib";
const lib = new Lib();

import {Std} from "raia_std";
const std = new Std();

(function() {
    if (globalThis.__RAIA_IMAGE__ === undefined) {
        var handle = lib.open("raia_image");
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
     * @param {int} width 
     * @param {int} height 
     * @param {string} filename 
     * @param {int} pos_x 
     * @param {int} pos_y 
     * @returns {{width:int, height:int}}
     */
    loadImage(pixels, width, height, filename, pos_x = 0, pos_y = 0) {
        var json_str = JSON.stringify({
            "pixels": std.arrayBufferToPointer(pixels),
            "width": width,
            "height": height,
            "filename": filename,
            "pos_x": pos_x,
            "pos_y": pos_y
        });
        var ret = lib.call("raia_image_load", json_str); // (window, title)
        return JSON.parse(ret);
    }
    /**
     * 
     * @param {ArrayBuffer} pixels 
     * @param {int} width 
     * @param {int} height 
     * @param {string} filename 
     * @param {int} pos_x 
     * @param {int} pos_y 
     * @param {int} trim_x1 
     * @param {int} trim_y1 
     * @param {int} trim_x2 
     * @param {int} trim_y2 
     * @returns {{width:int, height:int}}
     */
    loadJpgBlendRGB(pixels, width, height, filename, pos_x = 0, pos_y = 0,
        trim_x1 = 0, trim_y1 = 0, trim_x2 = -1, trim_y2 = -1) {
        var json_str = JSON.stringify({
            "pixels": std.arrayBufferToPointer(pixels),
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
        var ret = lib.call("raia_image_load_jpg_blend_rgb", json_str); // (window, title)
        return JSON.parse(ret);
    }
    /**
     * 
     * @param {ArrayBuffer} pixels 
     * @param {int} width 
     * @param {int} height 
     * @param {string} filename 
     * @param {int} pos_x 
     * @param {int} pos_y 
     * @param {int} trim_x1 
     * @param {int} trim_y1 
     * @param {int} trim_x2 
     * @param {int} trim_y2 
     * @returns {{width:int, height:int}}
     */
    loadJpgBlendRGBA(pixels, width, height,
        filename,
        pos_x = 0, pos_y = 0,
        trim_x1 = 0, trim_y1 = 0, trim_x2 = -1, trim_y2 = -1) {
        var json_str = JSON.stringify({
            "pixels": std.arrayBufferToPointer(pixels),
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
        var ret = lib.call("raia_image_load_jpg_blend_rgba", json_str); // (window, title)
        return JSON.parse(ret);
    }
    /**
     * 
     * @param {ArrayBuffer} pixels 
     * @param {int} width 
     * @param {int} height 
     * @param {string} filename 
     * @param {int} pos_x 
     * @param {int} pos_y 
     * @param {int} trim_x1 
     * @param {int} trim_y1 
     * @param {int} trim_x2 
     * @param {int} trim_y2 
     * @returns {{width:int, height:int}}
     */
    loadPngBlendRGB(pixels, width, height, filename, pos_x = 0, pos_y = 0,
        trim_x1 = 0, trim_y1 = 0, trim_x2 = -1, trim_y2 = -1) {
        var json_str = JSON.stringify({
            "pixels": std.arrayBufferToPointer(pixels),
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
        var ret = lib.call("raia_image_load_png_blend_rgb", json_str); // (window, title)
        return JSON.parse(ret);
    }
    /**
     * 
     * @param {ArrayBuffer} pixels 
     * @param {int} width 
     * @param {int} height 
     * @param {string} filename 
     * @param {int} pos_x 
     * @param {int} pos_y 
     * @param {int} trim_x1 
     * @param {int} trim_y1 
     * @param {int} trim_x2 
     * @param {int} trim_y2 
     * @returns {{width:int, height:int}}
     */
    loadPngBlendRGBA(pixels, width, height, filename, pos_x = 0, pos_y = 0,
        trim_x1 = 0, trim_y1 = 0, trim_x2 = -1, trim_y2 = -1) {
        var json_str = JSON.stringify({
            "pixels": std.arrayBufferToPointer(pixels),
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
        var ret = lib.call("raia_image_load_png_blend_rgba", json_str); // (window, title)
        return JSON.parse(ret);
    }
}