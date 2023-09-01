(function() {
    if (globalThis.__Raia__.Draw === undefined) {
        var handle = __Raia__.Lib.open("raia_draw");
        __Raia__.Lib.add(handle, "raia_draw_noise");
        __Raia__.Lib.add(handle, "raia_draw_blend_pixels_rgba_to_rgb");
        __Raia__.Lib.add(handle, "raia_draw_blend_pixels_rgba_to_rgba");
        __Raia__.Lib.add(handle, "raia_draw_point");
        __Raia__.Lib.add(handle, "raia_draw_point_rgba");
        __Raia__.Lib.add(handle, "raia_draw_point_alpha");
        __Raia__.Lib.add(handle, "raia_draw_line");
        __Raia__.Lib.add(handle, "raia_draw_line_rgba");
        __Raia__.Lib.add(handle, "raia_draw_fill_rect");
        __Raia__.Lib.add(handle, "raia_draw_fill_rect_fast");
        __Raia__.Lib.add(handle, "raia_draw_fill_rect_rgba");
        __Raia__.Lib.add(handle, "raia_draw_fill_rect_alpha");
        __Raia__.Lib.add(handle, "raia_draw_ellipse");
        __Raia__.Lib.add(handle, "raia_draw_ellipse_rgba");
        __Raia__.Lib.add(handle, "raia_draw_filled_ellipse");
        __Raia__.Lib.add(handle, "raia_draw_filled_ellipse_rgba");
        __Raia__.Lib.add(handle, "raia_draw_filled_ellipse_smooth");
        __Raia__.Lib.add(handle, "raia_draw_load_and_blend_image_rgb");
        __Raia__.Lib.add(handle, "raia_draw_load_and_blend_image_rgba");
        __Raia__.Lib.add(handle, "raia_draw_d3m_init");
        __Raia__.Lib.add(handle, "raia_draw_d3m_set_camera");
        __Raia__.Lib.add(handle, "raia_draw_d3m_calc_position");
        globalThis.__Raia__.Draw = {};
    }
}());

export class Draw {
    constructor() {
    }
    noiseRGB(pixels, width, height) {
        var json_str = JSON.stringify({
            "pixels": __Raia__.arrayBufferToPointer(pixels),
            "width": width,
            "height": height
        });
        var ret = __Raia__.Lib.call("raia_draw_noise", json_str); // (window, title)
        return JSON.parse(ret).result;
    }
    blendPixelsRGBAtoRGB(pixels_rgb, pixels_rgb_width, pixels_rgb_height,
                         pixels_rgba, pixels_rgba_width, pixels_rgba_height,
                         position_x, position_y,
                         trimming_x1, trimming_y1, trimming_x2, trimming_y2) {
        var json_str = JSON.stringify({
            "pixels_rgb": __Raia__.Core.arrayBufferToPointer(pixels_rgb),
            "pixels_rgb_width": pixels_rgb_width,
            "pixels_rgb_height": pixels_rgb_height,
            "pixels_rgba": __Raia__.Core.arrayBufferToPointer(pixels_rgba),
            "pixels_rgba_width": pixels_rgba_width,
            "pixels_rgba_height": pixels_rgba_height,
            "position_x": position_x,
            "position_y": position_y,
            "trimming_x1": trimming_x1,
            "trimming_y1": trimming_y1,
            "trimming_x2": trimming_x2,
            "trimming_y2": trimming_y2
        });
        var ret = __Raia__.Lib.call("raia_draw_blend_pixels_rgba_to_rgb", json_str); // (window, title)
        return JSON.parse(ret).result;
    }
    blendPixelsRGBAtoRGBA (pixels_rgba_a, pixels_rgba_a_width, pixels_rgba_a_height,
                           pixels_rgba_b, pixels_rgba_b_width, pixels_rgba_b_height,
                           position_x, position_y,
                           trimming_x1, trimming_y1, trimming_x2, trimming_y2) {
        var json_str = JSON.stringify({
            "pixels_rgba_a": __Raia__.Core.arrayBufferToPointer(pixels_rgba_a),
            "pixels_rgba_a_width": pixels_rgba_a_width,
            "pixels_rgba_a_height": pixels_rgba_a_height,
            "pixels_rgba_b": __Raia__.Core.arrayBufferToPointer(pixels_rgba_b),
            "pixels_rgba_b_width": pixels_rgba_b_width,
            "pixels_rgba_b_height": pixels_rgba_b_height,
            "position_x": position_x,
            "position_y": position_y,
            "trimming_x1": trimming_x1,
            "trimming_y1": trimming_y1,
            "trimming_x2": trimming_x2,
            "trimming_y2": trimming_y2
        });
        var ret = __Raia__.Lib.call("raia_draw_blend_pixels_rgba_to_rgba", json_str); // (window, title)
        return JSON.parse(ret).result;
    }
    pointRGB(pixels,
             point_x, point_y,
             color_red, color_green, color_blue,
             canvas_width, canvas_height) {
        var json_str = JSON.stringify({
            "pixels": __Raia__.Core.arrayBufferToPointer(pixels),
            "point_x": point_x,
            "point_y": point_y,
            "color_red": color_red,
            "color_green": color_green,
            "color_blue": color_blue,
            "canvas_width": canvas_width,
            "canvas_height": canvas_height
        });
        var ret = __Raia__.Lib.call("raia_draw_point", json_str); // (window, title)
        return JSON.parse(ret).result;
    }
    pointRGBA(pixels,
              point_x, point_y,
              color_red, color_green, color_blue, color_alpha,
              canvas_width, canvas_height) {
        var json_str = JSON.stringify({
            "pixels": __Raia__.Core.arrayBufferToPointer(pixels),
            "point_x": point_x,
            "point_y": point_y,
            "color_red": color_red,
            "color_green": color_green,
            "color_blue": color_blue,
            "color_alpha": color_alpha,
            "canvas_width": canvas_width,
            "canvas_height": canvas_height
        });
        var ret = __Raia__.Lib.call("raia_draw_point_rgba", json_str); // (window, title)
        return JSON.parse(ret).result;
    }
    pointRGBAtoRGB(pixels,
                   point_x, point_y,
                   color_red, color_green, color_blue, color_alpha,
                   canvas_width, canvas_height) {
        var json_str = JSON.stringify({
            "pixels": __Raia__.Core.arrayBufferToPointer(pixels),
            "point_x": point_x,
            "point_y": point_y,
            "color_red": color_red,
            "color_green": color_green,
            "color_blue": color_blue,
            "color_alpha": color_alpha,
            "canvas_width": canvas_width,
            "canvas_height": canvas_height
        });
        var ret = __Raia__.Lib.call("raia_draw_point_alpha", json_str); // (window, title)
        return JSON.parse(ret).result;
    }
    lineRGB(pixels,
            start_x, start_y, end_x, end_y,
            color_red, color_green, color_blue,
            canvas_width, canvas_height) {
        var json_str = JSON.stringify({
            "pixels": __Raia__.Core.arrayBufferToPointer(pixels),
            "start_x": start_x,
            "start_y": start_y,
            "end_x": end_x,
            "end_y": end_y,
            "color_red": color_red,
            "color_green": color_green,
            "color_blue": color_blue,
            "canvas_width": canvas_width,
            "canvas_height": canvas_height
        });
        var ret = __Raia__.Lib.call("raia_draw_line", json_str); // (window, title)
        return JSON.parse(ret).result;
    }
    lineRGBA(pixels,
             start_x, start_y, end_x, end_y,
             color_red, color_green, color_blue, color_alpha,
             canvas_width, canvas_height) {
        var json_str = JSON.stringify({
            "pixels": __Raia__.Core.arrayBufferToPointer(pixels),
            "start_x": start_x,
            "start_y": start_y,
            "end_x": end_x,
            "end_y": end_y,
            "color_red": color_red,
            "color_green": color_green,
            "color_blue": color_blue,
            "color_alpha": color_alpha,
            "canvas_width": canvas_width,
            "canvas_height": canvas_height
        });
        var ret = __Raia__.Lib.call("raia_draw_line_rgba", json_str); // (window, title)
        return JSON.parse(ret).result;
    }
    fillRectRGB(pixels,
                start_x, start_y, end_x, end_y,
                color_red, color_green, color_blue,
                canvas_width, canvas_height) {
        var json_str = JSON.stringify({
            "pixels": __Raia__.Core.arrayBufferToPointer(pixels),
            "start_x": start_x,
            "start_y": start_y,
            "end_x": end_x,
            "end_y": end_y,
            "color_red": color_red,
            "color_green": color_green,
            "color_blue": color_blue,
            "canvas_width": canvas_width,
            "canvas_height": canvas_height
        });
        var ret = __Raia__.Lib.call("raia_draw_fill_rect", json_str); // (window, title)
        return JSON.parse(ret).result;
    }
    fillRectFastRGB(pixels,
                    start_x, start_y, end_x, end_y,
                    color_red, color_green, color_blue,
                    canvas_width, canvas_height) {
        var json_str = JSON.stringify({
            "pixels": __Raia__.Core.arrayBufferToPointer(pixels),
            "start_x": start_x,
            "start_y": start_y,
            "end_x": end_x,
            "end_y": end_y,
            "color_red": color_red,
            "color_green": color_green,
            "color_blue": color_blue,
            "canvas_width": canvas_width,
            "canvas_height": canvas_height
        });
        var ret = __Raia__.Lib.call("raia_draw_fill_rect_fast", json_str); // (window, title)
        return JSON.parse(ret).result;
    }
    fillRectRGBA(pixels,
                 start_x, start_y, end_x, end_y,
                 color_red, color_green, color_blue, color_alpha,
                 canvas_width, canvas_height) {
        var json_str = JSON.stringify({
            "pixels": __Raia__.Core.arrayBufferToPointer(pixels),
            "start_x": start_x,
            "start_y": start_y,
            "end_x": end_x,
            "end_y": end_y,
            "color_red": color_red,
            "color_green": color_green,
            "color_blue": color_blue,
            "color_alpha": color_alpha,
            "canvas_width": canvas_width,
            "canvas_height": canvas_height
        });
        var ret = __Raia__.Lib.call("raia_draw_fill_rect_rgba", json_str); // (window, title)
        return JSON.parse(ret).result;
    }
    fillRectRGBAtoRGB(pixels,
                      start_x, start_y, end_x, end_y,
                      color_red, color_green, color_blue, color_alpha,
                      canvas_width, canvas_height) {
        var json_str = JSON.stringify({
            "pixels": __Raia__.Core.arrayBufferToPointer(pixels),
            "start_x": start_x,
            "start_y": start_y,
            "end_x": end_x,
            "end_y": end_y,
            "color_red": color_red,
            "color_green": color_green,
            "color_blue": color_blue,
            "color_alpha": color_alpha,
            "canvas_width": canvas_width,
            "canvas_height": canvas_height
        });
        var ret = __Raia__.Lib.call("raia_draw_fill_rect_alpha", json_str); // (window, title)
        return JSON.parse(ret).result;
    }
    drawEllipseRGB(pixels,
                   start_x, start_y, end_x, end_y,
                   color_red, color_green, color_blue,
                   canvas_width, canvas_height) {
        var json_str = JSON.stringify({
            "pixels": __Raia__.Core.arrayBufferToPointer(pixels),
            "start_x": start_x,
            "start_y": start_y,
            "end_x": end_x,
            "end_y": end_y,
            "color_red": color_red,
            "color_green": color_green,
            "color_blue": color_blue,
            "canvas_width": canvas_width,
            "canvas_height": canvas_height
        });
        var ret = __Raia__.Lib.call("raia_draw_ellipse", json_str); // (window, title)
        return JSON.parse(ret).result;
    }
    drawEllipseRGBA(pixels,
                    start_x, start_y, end_x, end_y,
                    color_red, color_green, color_blue, color_alpha,
                    canvas_width, canvas_height) {
        var json_str = JSON.stringify({
            "pixels": __Raia__.Core.arrayBufferToPointer(pixels),
            "start_x": start_x,
            "start_y": start_y,
            "end_x": end_x,
            "end_y": end_y,
            "color_red": color_red,
            "color_green": color_green,
            "color_blue": color_blue,
            "color_alpha": color_alpha,
            "canvas_width": canvas_width,
            "canvas_height": canvas_height
        });
        var ret = __Raia__.Lib.call("raia_draw_ellipse_rgba", json_str); // (window, title)
        return JSON.parse(ret).result;
    }
    drawFilledEllipseRGB(pixels,
                         start_x, start_y, end_x, end_y,
                         color_red, color_green, color_blue,
                         canvas_width, canvas_height) {
        var json_str = JSON.stringify({
            "pixels": __Raia__.Core.arrayBufferToPointer(pixels),
            "start_x": start_x,
            "start_y": start_y,
            "end_x": end_x,
            "end_y": end_y,
            "color_red": color_red,
            "color_green": color_green,
            "color_blue": color_blue,
            "canvas_width": canvas_width,
            "canvas_height": canvas_height
        });
        var ret = __Raia__.Lib.call("raia_draw_filled_ellipse", json_str); // (window, title)
        return JSON.parse(ret).result;
    }
    drawFilledEllipseRGBA(pixels,
                          start_x, start_y, end_x, end_y,
                          color_red, color_green, color_blue, color_alpha,
                          canvas_width, canvas_height) {
        var json_str = JSON.stringify({
            "pixels": __Raia__.Core.arrayBufferToPointer(pixels),
            "start_x": start_x,
            "start_y": start_y,
            "end_x": end_x,
            "end_y": end_y,
            "color_red": color_red,
            "color_green": color_green,
            "color_blue": color_blue,
            "color_alpha": color_alpha,
            "canvas_width": canvas_width,
            "canvas_height": canvas_height
        });
        var ret = __Raia__.Lib.call("raia_draw_filled_ellipse_rgba", json_str); // (window, title)
        return JSON.parse(ret).result;
    }
    drawFilledEllipseSmooth(pixels,
                            start_x, start_y, end_x, end_y,
                            color_red, color_green, color_blue,
                            canvas_width, canvas_height) {
        var json_str = JSON.stringify({
            "pixels": __Raia__.Core.arrayBufferToPointer(pixels),
            "start_x": start_x,
            "start_y": start_y,
            "end_x": end_x,
            "end_y": end_y,
            "color_red": color_red,
            "color_green": color_green,
            "color_blue": color_blue,
            "canvas_width": canvas_width,
            "canvas_height": canvas_height
        });
        var ret = __Raia__.Lib.call("raia_draw_filled_ellipse_smooth", json_str); // (window, title)
        return JSON.parse(ret).result;
    }
    d3mInit(width, height) {
        var json_str = JSON.stringify({
            "width": width,
            "height": height
        });
        var ret = __Raia__.Lib.call("raia_draw_d3m_init", json_str); // (window, title)
        return JSON.parse(ret).result;
    }
    d3mSetCamera(pos_x, pos_y, pos_z, target_x, target_y, target_z) {
        var json_str = JSON.stringify({
            "pos_x": pos_x,
            "pos_y": pos_y,
            "pos_z": pos_z,
            "target_x": target_x,
            "target_y": target_y,
            "target_z": target_z
        });
        var ret = __Raia__.Lib.call("raia_draw_d3m_set_camera", json_str); // (window, title)
        return JSON.parse(ret).result;
    }
    d3mTransform3Dto2D(pos_x, pos_y, pos_z) {
        var json_str = JSON.stringify({
            "pos_x": pos_x,
            "pos_y": pos_y,
            "pos_z": pos_z
        });
        var ret = __Raia__.Lib.call("raia_draw_d3m_calc_position", json_str); // (window, title)
        return JSON.parse(ret);
    }
}
