(function() {
    if (globalThis.__Raia__.Font === undefined) {
        var handle = __Raia__.Lib.open("raia_font");
        __Raia__.Lib.add(handle, "raia_font_open");
        __Raia__.Lib.add(handle, "raia_font_init_buffer");
        __Raia__.Lib.add(handle, "raia_font_text_rgb");
        __Raia__.Lib.add(handle, "raia_font_text_rgba");
        __Raia__.Lib.add(handle, "raia_font_text_rgba_old");
        __Raia__.Lib.add(handle, "raia_font_get_text_size");
        globalThis.__Raia__.Font = {};
    }
}());

export class Font {
    constructor(font_file, font_size = 16) {
        this.font_file = font_file;
        this.font_size = font_size;
        this.font_buffer_length = this.openFont(font_file);
        this.font_buffer = new ArrayBuffer(this.font_buffer_length);
        this.font_info = this.initFontBuffer(font_file, this.font_buffer);
    }
    openFont(font_path) {
        var json_str = JSON.stringify({
            "font_path": font_path
        });
        var ret = __Raia__.Lib.call("raia_font_open", json_str); // (window, title)
        return JSON.parse(ret).result;
    }
    initFontBuffer(font_path, font_buffer) {
        var json_str = JSON.stringify({
            "font_path": font_path,
            "font_buffer": __Raia__.Core.arrayBufferToPointer(font_buffer)
        });
        var ret = __Raia__.Lib.call("raia_font_init_buffer", json_str); // (window, title)
        return JSON.parse(ret);
    }
    getTextSize(text, font_size,
                userdata, data, fontstart, numGlyphs,
                loca, head, glyf, hhea, hmtx, kern, gpos, svg,
                index_map, indexToLocFormat,
                cff_data, cff_cursor, cff_size,
                charstrings_data, charstrings_cursor, charstrings_size,
                gsubrs_data, gsubrs_cursor, gsubrs_size,
                subrs_data, subrs_cursor, subrs_size,
                fontdicts_data, fontdicts_cursor, fontdicts_size,
                fdselect_data, fdselect_cursor, fdselect_size) {
        var json_str = JSON.stringify({
            "text": text,
            "font_size": font_size,
            "userdata": userdata,
            "data": data,
            "fontstart": fontstart,
            "numGlyphs": numGlyphs,
            "loca": loca,
            "head": head,
            "glyf": glyf,
            "hhea": hhea,
            "hmtx": hmtx,
            "kern": kern,
            "gpos": gpos,
            "svg": svg,
            "index_map": index_map,
            "indexToLocFormat": indexToLocFormat,
            "cff_data": cff_data,
            "cff_cursor": cff_cursor,
            "cff_size": cff_size,
            "charstrings_data": charstrings_data,
            "charstrings_cursor": charstrings_cursor,
            "charstrings_size": charstrings_size,
            "gsubrs_data": gsubrs_data,
            "gsubrs_cursor": gsubrs_cursor,
            "gsubrs_size": gsubrs_size,
            "subrs_data": subrs_data,
            "subrs_cursor": subrs_cursor,
            "subrs_size": subrs_size,
            "fontdicts_data": fontdicts_data,
            "fontdicts_cursor": fontdicts_cursor,
            "fontdicts_size": fontdicts_size,
            "fdselect_data": fdselect_data,
            "fdselect_cursor": fdselect_cursor,
            "fdselect_size": fdselect_size
        });
        var ret = __Raia__.Lib.call("raia_font_get_text_size", json_str); // (window, title)
        return JSON.parse(ret);
    }
    drawTextRGB(pixels_rgba, pixels_rgba_width, pixels_rgba_height,
                text, font_size,
                color_red, color_green, color_blue,
                position_x, position_y,
                font_buffer,
                userdata, data, fontstart, numGlyphs,
                loca, head, glyf, hhea, hmtx, kern, gpos, svg,
                index_map, indexToLocFormat,
                cff_data, cff_cursor, cff_size,
                charstrings_data, charstrings_cursor, charstrings_size,
                gsubrs_data, gsubrs_cursor, gsubrs_size,
                subrs_data, subrs_cursor, subrs_size,
                fontdicts_data, fontdicts_cursor, fontdicts_size,
                fdselect_data, fdselect_cursor, fdselect_size) {
        var json_str = JSON.stringify({
            "pixels_rgba": __Raia__.Core.arrayBufferToPointer(pixels_rgba),
            "pixels_rgba_width": pixels_rgba_width,
            "pixels_rgba_height": pixels_rgba_height,
            "text": text,
            "font_size": font_size,
            "color_red": color_red,
            "color_green": color_green,
            "color_blue": color_blue,
            "position_x": position_x,
            "position_y": position_y,
            "font_buffer": __Raia__.Core.arrayBufferToPointer(font_buffer),
            "userdata": userdata,
            "data": data,
            "fontstart": fontstart,
            "numGlyphs": numGlyphs,
            "loca": loca,
            "head": head,
            "glyf": glyf,
            "hhea": hhea,
            "hmtx": hmtx,
            "kern": kern,
            "gpos": gpos,
            "svg": svg,
            "index_map": index_map,
            "indexToLocFormat": indexToLocFormat,
            "cff_data": cff_data,
            "cff_cursor": cff_cursor,
            "cff_size": cff_size,
            "charstrings_data": charstrings_data,
            "charstrings_cursor": charstrings_cursor,
            "charstrings_size": charstrings_size,
            "gsubrs_data": gsubrs_data,
            "gsubrs_cursor": gsubrs_cursor,
            "gsubrs_size": gsubrs_size,
            "subrs_data": subrs_data,
            "subrs_cursor": subrs_cursor,
            "subrs_size": subrs_size,
            "fontdicts_data": fontdicts_data,
            "fontdicts_cursor": fontdicts_cursor,
            "fontdicts_size": fontdicts_size,
            "fdselect_data": fdselect_data,
            "fdselect_cursor": fdselect_cursor,
            "fdselect_size": fdselect_size
        });
        var ret = __Raia__.Lib.call("raia_font_text_rgb", json_str); // (window, title)
        return JSON.parse(ret);
    }
    drawTextRGBA(pixels_rgba, pixels_rgba_width, pixels_rgba_height,
                 text, font_size,
                 color_red, color_green, color_blue,
                 position_x, position_y,
                 font_buffer,
                 userdata, data, fontstart, numGlyphs,
                 loca, head, glyf, hhea, hmtx, kern, gpos, svg,
                 index_map, indexToLocFormat,
                 cff_data, cff_cursor, cff_size,
                 charstrings_data, charstrings_cursor, charstrings_size,
                 gsubrs_data, gsubrs_cursor, gsubrs_size,
                 subrs_data, subrs_cursor, subrs_size,
                 fontdicts_data, fontdicts_cursor, fontdicts_size,
                 fdselect_data, fdselect_cursor, fdselect_size) {
        var json_str = JSON.stringify({
            "pixels_rgba": __Raia__.Core.arrayBufferToPointer(pixels_rgba),
            "pixels_rgba_width": pixels_rgba_width,
            "pixels_rgba_height": pixels_rgba_height,
            "text": text,
            "font_size": font_size,
            "color_red": color_red,
            "color_green": color_green,
            "color_blue": color_blue,
            "position_x": position_x,
            "position_y": position_y,
            "font_buffer": __Raia__.Core.arrayBufferToPointer(font_buffer),
            "userdata": userdata,
            "data": data,
            "fontstart": fontstart,
            "numGlyphs": numGlyphs,
            "loca": loca,
            "head": head,
            "glyf": glyf,
            "hhea": hhea,
            "hmtx": hmtx,
            "kern": kern,
            "gpos": gpos,
            "svg": svg,
            "index_map": index_map,
            "indexToLocFormat": indexToLocFormat,
            "cff_data": cff_data,
            "cff_cursor": cff_cursor,
            "cff_size": cff_size,
            "charstrings_data": charstrings_data,
            "charstrings_cursor": charstrings_cursor,
            "charstrings_size": charstrings_size,
            "gsubrs_data": gsubrs_data,
            "gsubrs_cursor": gsubrs_cursor,
            "gsubrs_size": gsubrs_size,
            "subrs_data": subrs_data,
            "subrs_cursor": subrs_cursor,
            "subrs_size": subrs_size,
            "fontdicts_data": fontdicts_data,
            "fontdicts_cursor": fontdicts_cursor,
            "fontdicts_size": fontdicts_size,
            "fdselect_data": fdselect_data,
            "fdselect_cursor": fdselect_cursor,
            "fdselect_size": fdselect_size
        });
        var ret = __Raia__.Lib.call("raia_font_text_rgba", json_str); // (window, title)
        return JSON.parse(ret);
    }
}