var raia_draw_handle = __Raia__.Core.Lib.open("raia_draw");
__Raia__.Core.Lib.add(raia_draw_handle, "raia_draw_noise");
__Raia__.Core.Lib.add(raia_draw_handle, "raia_draw_blend_pixels_rgba_to_rgb");
__Raia__.Core.Lib.add(raia_draw_handle, "raia_draw_blend_pixels_rgba_to_rgba");
__Raia__.Core.Lib.add(raia_draw_handle, "raia_draw_point");
__Raia__.Core.Lib.add(raia_draw_handle, "raia_draw_point_rgba");
__Raia__.Core.Lib.add(raia_draw_handle, "raia_draw_point_alpha");
__Raia__.Core.Lib.add(raia_draw_handle, "raia_draw_line");
__Raia__.Core.Lib.add(raia_draw_handle, "raia_draw_line_rgba");
__Raia__.Core.Lib.add(raia_draw_handle, "raia_draw_fill_rect");
__Raia__.Core.Lib.add(raia_draw_handle, "raia_draw_fill_rect_fast");
__Raia__.Core.Lib.add(raia_draw_handle, "raia_draw_fill_rect_rgba");
__Raia__.Core.Lib.add(raia_draw_handle, "raia_draw_fill_rect_alpha");
__Raia__.Core.Lib.add(raia_draw_handle, "raia_draw_ellipse");
__Raia__.Core.Lib.add(raia_draw_handle, "raia_draw_ellipse_rgba");
__Raia__.Core.Lib.add(raia_draw_handle, "raia_draw_filled_ellipse");
__Raia__.Core.Lib.add(raia_draw_handle, "raia_draw_filled_ellipse_rgba");
__Raia__.Core.Lib.add(raia_draw_handle, "raia_draw_filled_ellipse_smooth");
__Raia__.Core.Lib.add(raia_draw_handle, "raia_draw_font_open");
__Raia__.Core.Lib.add(raia_draw_handle, "raia_draw_font_init_buffer");
__Raia__.Core.Lib.add(raia_draw_handle, "raia_draw_get_text_size");
__Raia__.Core.Lib.add(raia_draw_handle, "raia_draw_text_rgb");
__Raia__.Core.Lib.add(raia_draw_handle, "raia_draw_text_rgba");
__Raia__.Core.Lib.add(raia_draw_handle, "raia_draw_load_and_blend_image_rgb");
__Raia__.Core.Lib.add(raia_draw_handle, "raia_draw_load_and_blend_image_rgba");
__Raia__.Core.Lib.add(raia_draw_handle, "raia_draw_d3m_init");
__Raia__.Core.Lib.add(raia_draw_handle, "raia_draw_d3m_set_camera");
__Raia__.Core.Lib.add(raia_draw_handle, "raia_draw_d3m_calc_position");

module.exports = {
    Pixel: {
        noiseRGB: (pixels, width, height) => {
            var json_str = JSON.stringify({
                "pixels": __Raia__.Core.arrayBufferToNumber(pixels),
                "width": width,
                "height": height,
                "@return": "string"
            });
            var ret = __Raia__.Core.Lib.call("raia_draw_noise", json_str); // (window, title)
            return JSON.parse(ret).result;
        },
        blendPixelsRGBAtoRGB: (pixels_rgb, pixels_rgb_width, pixels_rgb_height,
                               pixels_rgba, pixels_rgba_width, pixels_rgba_height,
                               position_x, position_y,
                               trimming_x1, trimming_y1, trimming_x2, trimming_y2) => {
            var json_str = JSON.stringify({
                "pixels_rgb": __Raia__.Core.arrayBufferToNumber(pixels_rgb),
                "pixels_rgb_width": pixels_rgb_width,
                "pixels_rgb_height": pixels_rgb_height,
                "pixels_rgba": __Raia__.Core.arrayBufferToNumber(pixels_rgba),
                "pixels_rgba_width": pixels_rgba_width,
                "pixels_rgba_height": pixels_rgba_height,
                "position_x": position_x,
                "position_y": position_y,
                "trimming_x1": trimming_x1,
                "trimming_y1": trimming_y1,
                "trimming_x2": trimming_x2,
                "trimming_y2": trimming_y2,
                "@return": "string"
            });
            var ret = __Raia__.Core.Lib.call("raia_draw_blend_pixels_rgba_to_rgb", json_str); // (window, title)
            return JSON.parse(ret).result;
        },
        blendPixelsRGBAtoRGBA: (pixels_rgba_a, pixels_rgba_a_width, pixels_rgba_a_height,
                                pixels_rgba_b, pixels_rgba_b_width, pixels_rgba_b_height,
                                position_x, position_y,
                                trimming_x1, trimming_y1, trimming_x2, trimming_y2) => {
            var json_str = JSON.stringify({
                "pixels_rgba_a": __Raia__.Core.arrayBufferToNumber(pixels_rgba_a),
                "pixels_rgba_a_width": pixels_rgba_a_width,
                "pixels_rgba_a_height": pixels_rgba_a_height,
                "pixels_rgba_b": __Raia__.Core.arrayBufferToNumber(pixels_rgba_b),
                "pixels_rgba_b_width": pixels_rgba_b_width,
                "pixels_rgba_b_height": pixels_rgba_b_height,
                "position_x": position_x,
                "position_y": position_y,
                "trimming_x1": trimming_x1,
                "trimming_y1": trimming_y1,
                "trimming_x2": trimming_x2,
                "trimming_y2": trimming_y2,
                "@return": "string"
            });
            var ret = __Raia__.Core.Lib.call("raia_draw_blend_pixels_rgba_to_rgba", json_str); // (window, title)
            return JSON.parse(ret).result;
        },
    },
    Shape: {
        pointRGB: (pixels,
                   point_x, point_y,
                   color_red, color_green, color_blue,
                   canvas_width, canvas_height) => {
            var json_str = JSON.stringify({
                "pixels": __Raia__.Core.arrayBufferToNumber(pixels),
                "point_x": point_x,
                "point_y": point_y,
                "color_red": color_red,
                "color_green": color_green,
                "color_blue": color_blue,
                "canvas_width": canvas_width,
                "canvas_height": canvas_height,
                "@return": "string"
            });
            var ret = __Raia__.Core.Lib.call("raia_draw_point", json_str); // (window, title)
            return JSON.parse(ret).result;
        },
        pointRGBA: (pixels,
                    point_x, point_y,
                    color_red, color_green, color_blue, color_alpha,
                    canvas_width, canvas_height) => {
            var json_str = JSON.stringify({
                "pixels": __Raia__.Core.arrayBufferToNumber(pixels),
                "point_x": point_x,
                "point_y": point_y,
                "color_red": color_red,
                "color_green": color_green,
                "color_blue": color_blue,
                "color_alpha": color_alpha,
                "canvas_width": canvas_width,
                "canvas_height": canvas_height,
                "@return": "string"
            });
            var ret = __Raia__.Core.Lib.call("raia_draw_point_rgba", json_str); // (window, title)
            return JSON.parse(ret).result;
        },
        pointRGBAtoRGB: (pixels,
                         point_x, point_y,
                         color_red, color_green, color_blue, color_alpha,
                         canvas_width, canvas_height) => {
            var json_str = JSON.stringify({
                "pixels": __Raia__.Core.arrayBufferToNumber(pixels),
                "point_x": point_x,
                "point_y": point_y,
                "color_red": color_red,
                "color_green": color_green,
                "color_blue": color_blue,
                "color_alpha": color_alpha,
                "canvas_width": canvas_width,
                "canvas_height": canvas_height,
                "@return": "string"
            });
            var ret = __Raia__.Core.Lib.call("raia_draw_point_alpha", json_str); // (window, title)
            return JSON.parse(ret).result;
        },
        lineRGB: (pixels,
                  start_x, start_y, end_x, end_y,
                  color_red, color_green, color_blue,
                  canvas_width, canvas_height) => {
            var json_str = JSON.stringify({
                "pixels": __Raia__.Core.arrayBufferToNumber(pixels),
                "start_x": start_x,
                "start_y": start_y,
                "end_x": end_x,
                "end_y": end_y,
                "color_red": color_red,
                "color_green": color_green,
                "color_blue": color_blue,
                "canvas_width": canvas_width,
                "canvas_height": canvas_height,
                "@return": "string"
            });
            var ret = __Raia__.Core.Lib.call("raia_draw_line", json_str); // (window, title)
            return JSON.parse(ret).result;
        },
        lineRGBA: (pixels,
                   start_x, start_y, end_x, end_y,
                   color_red, color_green, color_blue, color_alpha,
                   canvas_width, canvas_height) => {
            var json_str = JSON.stringify({
                "pixels": __Raia__.Core.arrayBufferToNumber(pixels),
                "start_x": start_x,
                "start_y": start_y,
                "end_x": end_x,
                "end_y": end_y,
                "color_red": color_red,
                "color_green": color_green,
                "color_blue": color_blue,
                "color_alpha": color_alpha,
                "canvas_width": canvas_width,
                "canvas_height": canvas_height,
                "@return": "string"
            });
            var ret = __Raia__.Core.Lib.call("raia_draw_line_rgba", json_str); // (window, title)
            return JSON.parse(ret).result;
        },
        fillRectRGB: (pixels,
                      start_x, start_y, end_x, end_y,
                      color_red, color_green, color_blue,
                      canvas_width, canvas_height) => {
            var json_str = JSON.stringify({
                "pixels": __Raia__.Core.arrayBufferToNumber(pixels),
                "start_x": start_x,
                "start_y": start_y,
                "end_x": end_x,
                "end_y": end_y,
                "color_red": color_red,
                "color_green": color_green,
                "color_blue": color_blue,
                "canvas_width": canvas_width,
                "canvas_height": canvas_height,
                "@return": "string"
            });
            var ret = __Raia__.Core.Lib.call("raia_draw_fill_rect", json_str); // (window, title)
            return JSON.parse(ret).result;
        },
        fillRectFastRGB: (pixels,
                          start_x, start_y, end_x, end_y,
                          color_red, color_green, color_blue,
                          canvas_width, canvas_height) => {
            var json_str = JSON.stringify({
                "pixels": __Raia__.Core.arrayBufferToNumber(pixels),
                "start_x": start_x,
                "start_y": start_y,
                "end_x": end_x,
                "end_y": end_y,
                "color_red": color_red,
                "color_green": color_green,
                "color_blue": color_blue,
                "canvas_width": canvas_width,
                "canvas_height": canvas_height,
                "@return": "string"
            });
            var ret = __Raia__.Core.Lib.call("raia_draw_fill_rect_fast", json_str); // (window, title)
            return JSON.parse(ret).result;
        },
        fillRectRGBA: (pixels,
                       start_x, start_y, end_x, end_y,
                       color_red, color_green, color_blue, color_alpha,
                       canvas_width, canvas_height) => {
            var json_str = JSON.stringify({
                "pixels": __Raia__.Core.arrayBufferToNumber(pixels),
                "start_x": start_x,
                "start_y": start_y,
                "end_x": end_x,
                "end_y": end_y,
                "color_red": color_red,
                "color_green": color_green,
                "color_blue": color_blue,
                "color_alpha": color_alpha,
                "canvas_width": canvas_width,
                "canvas_height": canvas_height,
                "@return": "string"
            });
            var ret = __Raia__.Core.Lib.call("raia_draw_fill_rect_rgba", json_str); // (window, title)
            return JSON.parse(ret).result;
        },
        fillRectRGBAtoRGB: (pixels,
                            start_x, start_y, end_x, end_y,
                            color_red, color_green, color_blue, color_alpha,
                            canvas_width, canvas_height) => {
            var json_str = JSON.stringify({
                "pixels": __Raia__.Core.arrayBufferToNumber(pixels),
                "start_x": start_x,
                "start_y": start_y,
                "end_x": end_x,
                "end_y": end_y,
                "color_red": color_red,
                "color_green": color_green,
                "color_blue": color_blue,
                "color_alpha": color_alpha,
                "canvas_width": canvas_width,
                "canvas_height": canvas_height,
                "@return": "string"
            });
            var ret = __Raia__.Core.Lib.call("raia_draw_fill_rect_alpha", json_str); // (window, title)
            return JSON.parse(ret).result;
        },
        drawEllipseRGB: (pixels,
                         start_x, start_y, end_x, end_y,
                         color_red, color_green, color_blue,
                         canvas_width, canvas_height) => {
            var json_str = JSON.stringify({
                "pixels": __Raia__.Core.arrayBufferToNumber(pixels),
                "start_x": start_x,
                "start_y": start_y,
                "end_x": end_x,
                "end_y": end_y,
                "color_red": color_red,
                "color_green": color_green,
                "color_blue": color_blue,
                "canvas_width": canvas_width,
                "canvas_height": canvas_height,
                "@return": "string"
            });
            var ret = __Raia__.Core.Lib.call("raia_draw_ellipse", json_str); // (window, title)
            return JSON.parse(ret).result;
        },
        drawEllipseRGBA: (pixels,
                          start_x, start_y, end_x, end_y,
                          color_red, color_green, color_blue, color_alpha,
                          canvas_width, canvas_height) => {
            var json_str = JSON.stringify({
                "pixels": __Raia__.Core.arrayBufferToNumber(pixels),
                "start_x": start_x,
                "start_y": start_y,
                "end_x": end_x,
                "end_y": end_y,
                "color_red": color_red,
                "color_green": color_green,
                "color_blue": color_blue,
                "color_alpha": color_alpha,
                "canvas_width": canvas_width,
                "canvas_height": canvas_height,
                "@return": "string"
            });
            var ret = __Raia__.Core.Lib.call("raia_draw_ellipse_rgba", json_str); // (window, title)
            return JSON.parse(ret).result;
        },
        drawFilledEllipseRGB: (pixels,
                               start_x, start_y, end_x, end_y,
                               color_red, color_green, color_blue,
                               canvas_width, canvas_height) => {
            var json_str = JSON.stringify({
                "pixels": __Raia__.Core.arrayBufferToNumber(pixels),
                "start_x": start_x,
                "start_y": start_y,
                "end_x": end_x,
                "end_y": end_y,
                "color_red": color_red,
                "color_green": color_green,
                "color_blue": color_blue,
                "canvas_width": canvas_width,
                "canvas_height": canvas_height,
                "@return": "string"
            });
            var ret = __Raia__.Core.Lib.call("raia_draw_filled_ellipse", json_str); // (window, title)
            return JSON.parse(ret).result;
        },
        drawFilledEllipseRGBA: (pixels,
                                start_x, start_y, end_x, end_y,
                                color_red, color_green, color_blue, color_alpha,
                                canvas_width, canvas_height) => {
            var json_str = JSON.stringify({
                "pixels": __Raia__.Core.arrayBufferToNumber(pixels),
                "start_x": start_x,
                "start_y": start_y,
                "end_x": end_x,
                "end_y": end_y,
                "color_red": color_red,
                "color_green": color_green,
                "color_blue": color_blue,
                "color_alpha": color_alpha,
                "canvas_width": canvas_width,
                "canvas_height": canvas_height,
                "@return": "string"
            });
            var ret = __Raia__.Core.Lib.call("raia_draw_filled_ellipse_rgba", json_str); // (window, title)
            return JSON.parse(ret).result;
        },
        drawFilledEllipseSmooth: (pixels,
                                  start_x, start_y, end_x, end_y,
                                  color_red, color_green, color_blue,
                                  canvas_width, canvas_height) => {
            var json_str = JSON.stringify({
                "pixels": __Raia__.Core.arrayBufferToNumber(pixels),
                "start_x": start_x,
                "start_y": start_y,
                "end_x": end_x,
                "end_y": end_y,
                "color_red": color_red,
                "color_green": color_green,
                "color_blue": color_blue,
                "canvas_width": canvas_width,
                "canvas_height": canvas_height,
                "@return": "string"
            });
            var ret = __Raia__.Core.Lib.call("raia_draw_filled_ellipse_smooth", json_str); // (window, title)
            return JSON.parse(ret).result;
        },
    },
    Font: {
        openFont: (font_path) => {
            var json_str = JSON.stringify({
                "font_path": font_path,
                "@return": "string"
            });
            var ret = __Raia__.Core.Lib.call("raia_draw_font_open", json_str); // (window, title)
            return JSON.parse(ret).result;
        },
        initFontBuffer: (font_path, font_buffer) => {
            var json_str = JSON.stringify({
                "font_path": font_path,
                "font_buffer": __Raia__.Core.arrayBufferToNumber(font_buffer),
                "@return": "string"
            });
            var ret = __Raia__.Core.Lib.call("raia_draw_font_init_buffer", json_str); // (window, title)
            return JSON.parse(ret);
        },
        getTextSize: (text, font_size,
                      userdata, data, fontstart, numGlyphs,
                      loca, head, glyf, hhea, hmtx, kern, gpos, svg,
                      index_map, indexToLocFormat,
                      cff_data, cff_cursor, cff_size,
                      charstrings_data, charstrings_cursor, charstrings_size,
                      gsubrs_data, gsubrs_cursor, gsubrs_size,
                      subrs_data, subrs_cursor, subrs_size,
                      fontdicts_data, fontdicts_cursor, fontdicts_size,
                      fdselect_data, fdselect_cursor, fdselect_size) => {
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
                "fdselect_size": fdselect_size,
                "@return": "string"
            });
            var ret = __Raia__.Core.Lib.call("raia_draw_get_text_size", json_str); // (window, title)
            return JSON.parse(ret);
        },
        drawTextRGB: (pixels_rgba, pixels_rgba_width, pixels_rgba_height,
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
                      fdselect_data, fdselect_cursor, fdselect_size) => {
            var json_str = JSON.stringify({
                "pixels_rgba": __Raia__.Core.arrayBufferToNumber(pixels_rgba),
                "pixels_rgba_width": pixels_rgba_width,
                "pixels_rgba_height": pixels_rgba_height,
                "text": text,
                "font_size": font_size,
                "color_red": color_red,
                "color_green": color_green,
                "color_blue": color_blue,
                "position_x": position_x,
                "position_y": position_y,
                "font_buffer": __Raia__.Core.arrayBufferToNumber(font_buffer),
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
                "fdselect_size": fdselect_size,
                "@return": "string"
            });
            var ret = __Raia__.Core.Lib.call("raia_draw_text_rgb", json_str); // (window, title)
            return JSON.parse(ret);
        },
        drawTextRGBA: (pixels_rgba, pixels_rgba_width, pixels_rgba_height,
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
                       fdselect_data, fdselect_cursor, fdselect_size) => {
            var json_str = JSON.stringify({
                "pixels_rgba": __Raia__.Core.arrayBufferToNumber(pixels_rgba),
                "pixels_rgba_width": pixels_rgba_width,
                "pixels_rgba_height": pixels_rgba_height,
                "text": text,
                "font_size": font_size,
                "color_red": color_red,
                "color_green": color_green,
                "color_blue": color_blue,
                "position_x": position_x,
                "position_y": position_y,
                "font_buffer": __Raia__.Core.arrayBufferToNumber(font_buffer),
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
                "fdselect_size": fdselect_size,
                "@return": "string"
            });
            var ret = __Raia__.Core.Lib.call("raia_draw_text_rgba", json_str); // (window, title)
            return JSON.parse(ret);
        },
    },
    Image: {
        loadImageRGB: (pixels_rgba, pixels_rgba_width, pixels_rgba_height,
                       filename,
                       position_x, position_y,
                       trimming_x1, trimming_y1, trimming_x2, trimming_y2) => {
            var json_str = JSON.stringify({
                "pixels_rgba": __Raia__.Core.arrayBufferToNumber(pixels_rgba),
                "pixels_rgba_width": pixels_rgba_width,
                "pixels_rgba_height": pixels_rgba_height,
                "filename": filename,
                "position_x": position_x,
                "position_y": position_y,
                "trimming_x1": trimming_x1,
                "trimming_y1": trimming_y1,
                "trimming_x2": trimming_x2,
                "trimming_y2": trimming_y2,
                "@return": "string"
            });
            var ret = __Raia__.Core.Lib.call("raia_draw_load_and_blend_image_rgb", json_str); // (window, title)
            return JSON.parse(ret).result;
        },
        loadImageRGBA: (pixels_rgba, pixels_rgba_width, pixels_rgba_height,
                        filename,
                        position_x, position_y,
                        trimming_x1, trimming_y1, trimming_x2, trimming_y2) => {
            var json_str = JSON.stringify({
                "pixels_rgba": __Raia__.Core.arrayBufferToNumber(pixels_rgba),
                "pixels_rgba_width": pixels_rgba_width,
                "pixels_rgba_height": pixels_rgba_height,
                "filename": filename,
                "position_x": position_x,
                "position_y": position_y,
                "trimming_x1": trimming_x1,
                "trimming_y1": trimming_y1,
                "trimming_x2": trimming_x2,
                "trimming_y2": trimming_y2,
                "@return": "string"
            });
            var ret = __Raia__.Core.Lib.call("raia_draw_load_and_blend_image_rgba", json_str); // (window, title)
            return JSON.parse(ret).result;
        },
    },
    Primitive3D: {
        d3mInit: (width, height) => {
            var json_str = JSON.stringify({
                "width": width,
                "height": height,
                "@return": "string"
            });
            var ret = __Raia__.Core.Lib.call("raia_draw_d3m_init", json_str); // (window, title)
            return JSON.parse(ret).result;
        },
        d3mSetCamera: (pos_x, pos_y, pos_z, target_x, target_y, target_z) => {
            var json_str = JSON.stringify({
                "pos_x": pos_x,
                "pos_y": pos_y,
                "pos_z": pos_z,
                "target_x": target_x,
                "target_y": target_y,
                "target_z": target_z,
                "@return": "string"
            });
            var ret = __Raia__.Core.Lib.call("raia_draw_d3m_set_camera", json_str); // (window, title)
            return JSON.parse(ret).result;
        },
        d3mTransform3Dto2D: (pos_x, pos_y, pos_z) => {
            var json_str = JSON.stringify({
                "pos_x": pos_x,
                "pos_y": pos_y,
                "pos_z": pos_z,
                "@return": "string"
            });
            var ret = __Raia__.Core.Lib.call("raia_draw_d3m_calc_position", json_str); // (window, title)
            return JSON.parse(ret);
        },
    }
};
