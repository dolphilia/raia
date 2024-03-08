import {Lib} from "raia_lib";
const lib = new Lib();

import {Std} from "raia_std";
const std = new Std();

var handle;
(function() {
    if (globalThis.__RAIA_FONT__ === undefined) {
        handle = lib.open("raia_font");
        lib.add(handle, "raia_font_open");
        lib.add(handle, "raia_font_init_buffer");
        lib.add(handle, "raia_font_draw_char_rgb");
        lib.add(handle, "raia_font_draw_char_rgba");
        lib.add(handle, "raia_font_get_char_size");
        globalThis.__RAIA_FONT__ = {};
    }
}());

export class Font {

    /**
     * @param {string} font_file 
     * @param {number} font_size (int)
     */

    constructor(font_file, font_size = 16) {
        this.font_file = font_file;
        this.font_size = font_size;
        this.font_buffer_length = this.openFont(font_file);
        this.font_buffer = new ArrayBuffer(this.font_buffer_length);
        this.font_info = this.initFontBuffer(font_file, this.font_buffer);
    }

    /**
     * @param {string} font_path 
     * @returns {number} (int) font_size_in_bytes
     */

    openFont(font_path) {
        var args = JSON.stringify({
            "font_path": font_path
        });
        var ret = lib.call(handle, "raia_font_open", args); // (window, title)
        return JSON.parse(ret).result;
    }

    /**
     * @param {string} font_path 
     * @param {ArrayBuffer} font_buffer 
     * @returns {{userdata:uintptr,data:uintptr,fontstart:int,numGlyphs:int,loca:int,head:int,glyf:int,hhea:int,hmtx:int,kern:int,gpos:int,svg:int,index_map:int,indexToLocFormat:int,cff_data:uintptr,cff_cursor:int,cff_size:int,charstrings_data:uintptr,charstrings_curso:int,charstrings_size:int,gsubrs_data:uintptr,gsubrs_cursor:int,gsubrs_size:int,subrs_data:uintptr,subrs_cursor:int,subrs_size:int,fontdicts_data:uintptr,fontdicts_cursor:int,fontdicts_size:int,fdselect_data:uintptr,fdselect_cursor:int,fdselect_size:int}} font_info
     */

    initFontBuffer(font_path, font_buffer) {
        var args = JSON.stringify({
            "font_path": font_path,
            "font_buffer": std.bufToPtr(font_buffer)
        });
        var ret = lib.call(handle, "raia_font_init_buffer", args);
        return JSON.parse(ret);
    }

    /**
     * @param {number} text (uintptr)
     * @param {number} font_size (int)
     * @returns {{width:number, height:number}} {int, int}
     */

    getTextSize(text, font_size = this.font_size) {
        var args = this.font_info;
        args["text"] = text;
        args["font_size"] = font_size;
        var ret = lib.call(handle, "raia_font_get_char_size", JSON.stringify(args));
        return JSON.parse(ret);
    }

    /**
     * @param {ArrayBuffer} pixels 
     * @param {number} width (int)
     * @param {number} height (int)
     * @param {string} text 
     * @param {number} font_size (int)
     * @param {number} color_red (int)
     * @param {number} color_green (int)
     * @param {number} color_blue (int)
     * @param {number} pos_x (int)
     * @param {number} pos_y (int)
     * @returns {{width:number, height:number}} {int, int}
     */

    drawCharRGB(pixels, width, height,
                text, font_size = this.font_size,
                color_red, color_green, color_blue,
                pos_x, pos_y) {
        var args = this.font_info;
        args["pixels"] = std.bufToPtr(pixels);
        args["width"] = width;
        args["height"] = height;
        args["text"] = text;
        args["font_size"] = font_size;
        args["color_red"] = color_red;
        args["color_green"] = color_green;
        args["color_blue"] = color_blue;
        args["pos_x"] = pos_x;
        args["pos_y"] = pos_y;
        var ret = lib.call(handle, "raia_font_draw_char_rgb", JSON.stringify(args));
        return JSON.parse(ret);
    }

    /**
     * @param {ArrayBuffer} pixels 
     * @param {number} width (int)
     * @param {number} height (int)
     * @param {string} text 
     * @param {number} font_size (int)
     * @param {number} color_red (int)
     * @param {number} color_green (int)
     * @param {number} color_blue (int)
     * @param {number} pos_x (int)
     * @param {number} pos_y (int)
     * @returns {{width:number, height:number}} {int, int}
     */

    drawCharRGBA(pixels, width, height,
                 text, font_size = this.font_size,
                 color_red, color_green, color_blue,
                 pos_x, pos_y) {
        var args = this.font_info;
        args["pixels"] = std.bufToPtr(pixels);
        args["width"] = width;
        args["height"] = height;
        args["text"] = text;
        args["font_size"] = font_size;
        args["color_red"] = color_red;
        args["color_green"] = color_green;
        args["color_blue"] = color_blue;
        args["pos_x"] = pos_x;
        args["pos_y"] = pos_y;
        var ret = lib.call(handle, "raia_font_draw_char_rgba", JSON.stringify(args));
        return JSON.parse(ret);
    }
}