import {Lib} from "raia_lib";
const lib = new Lib();

import {Std} from "raia_std";
const std = new Std();
var handle;

(function() {
    if (globalThis.__RAIA_DRAW__ === undefined) {
        handle = lib.open("raia_draw");
        lib.add(handle, "raia_draw_noise_cpu");
        lib.add(handle, "raia_draw_noise_gpu");
        lib.add(handle, "raia_draw_blend_pixels_rgba_to_rgb");
        lib.add(handle, "raia_draw_blend_pixels_rgba_to_rgba");
        lib.add(handle, "raia_draw_point");
        lib.add(handle, "raia_draw_point_rgba");
        lib.add(handle, "raia_draw_point_alpha");
        lib.add(handle, "raia_draw_line");
        lib.add(handle, "raia_draw_line_rgba");
        lib.add(handle, "raia_draw_fill_rect");
        lib.add(handle, "raia_draw_fill_rect_fast");
        lib.add(handle, "raia_draw_fill_rect_rgba");
        lib.add(handle, "raia_draw_fill_rect_alpha");
        lib.add(handle, "raia_draw_ellipse");
        lib.add(handle, "raia_draw_ellipse_rgba");
        lib.add(handle, "raia_draw_filled_ellipse");
        lib.add(handle, "raia_draw_filled_ellipse_rgba");
        lib.add(handle, "raia_draw_filled_ellipse_smooth");
        //lib.add(handle, "raia_draw_load_and_blend_image_rgb");
        //lib.add(handle, "raia_draw_load_and_blend_image_rgba");
        lib.add(handle, "raia_draw_d3m_init");
        lib.add(handle, "raia_draw_d3m_set_camera");
        lib.add(handle, "raia_draw_d3m_calc_position");
        globalThis.__RAIA_DRAW__ = {};
    }
}());

export class Draw {
    
    constructor() {
    }

    /**
     * @param {ArrayBuffer} pixels 
     * @param {number} width (int)
     * @param {number} height (int)
     * @returns 
     */

    noiseRGB_CPU(pixels, width, height) {
        var args = JSON.stringify({
            "pixels": std.bufToPtr(pixels),
            "width": width,
            "height": height
        });
        lib.call(handle, "raia_draw_noise_cpu", args);
    }

    noiseRGB_GPU(pixels, width, height) {
        var args = JSON.stringify({
            "pixels": std.bufToPtr(pixels),
            "width": width,
            "height": height
        });
        lib.call(handle, "raia_draw_noise_gpu", args);
    }

    /**
     * @param {ArrayBuffer} pixels_rgb
     * @param {number} pixels_rgb_width (int)
     * @param {number} pixels_rgb_height (int)
     * @param {ArrayBuffer} pixels_rgba
     * @param {number} pixels_rgba_width (int)
     * @param {number} pixels_rgba_height (int)
     * @param {number} position_x (int)
     * @param {number} position_y (int)
     * @param {number} trimming_x1 (int)
     * @param {number} trimming_y1 (int)
     * @param {number} trimming_x2 (int)
     * @param {number} trimming_y2 (int)
     */

    blendPixelsRGBAtoRGB(pixels_rgb, pixels_rgb_width, pixels_rgb_height,
                         pixels_rgba, pixels_rgba_width, pixels_rgba_height,
                         position_x, position_y,
                         trimming_x1, trimming_y1, trimming_x2, trimming_y2) {
        var args = JSON.stringify({
            "pixels_rgb": std.bufToPtr(pixels_rgb),
            "pixels_rgb_width": pixels_rgb_width,
            "pixels_rgb_height": pixels_rgb_height,
            "pixels_rgba": std.bufToPtr(pixels_rgba),
            "pixels_rgba_width": pixels_rgba_width,
            "pixels_rgba_height": pixels_rgba_height,
            "position_x": position_x,
            "position_y": position_y,
            "trimming_x1": trimming_x1,
            "trimming_y1": trimming_y1,
            "trimming_x2": trimming_x2,
            "trimming_y2": trimming_y2
        });
        lib.call(handle, "raia_draw_blend_pixels_rgba_to_rgb", args);
    }

    /**
     * @param {ArrayBuffer} pixels_rgba_a 
     * @param {number} pixels_rgba_a_width (int)
     * @param {number} pixels_rgba_a_height (int)
     * @param {ArrayBuffer} pixels_rgba_b 
     * @param {number} pixels_rgba_b_width (int)
     * @param {number} pixels_rgba_b_height (int)
     * @param {number} position_x (int)
     * @param {number} position_y (int)
     * @param {number} trimming_x1 (int)
     * @param {number} trimming_y1 (int)
     * @param {number} trimming_x2 (int)
     * @param {number} trimming_y2 (int)
     */

    blendPixelsRGBAtoRGBA (pixels_rgba_a, pixels_rgba_a_width, pixels_rgba_a_height,
                           pixels_rgba_b, pixels_rgba_b_width, pixels_rgba_b_height,
                           position_x, position_y,
                           trimming_x1, trimming_y1, trimming_x2, trimming_y2) {
        var args = JSON.stringify({
            "pixels_rgba_a": std.bufToPtr(pixels_rgba_a),
            "pixels_rgba_a_width": pixels_rgba_a_width,
            "pixels_rgba_a_height": pixels_rgba_a_height,
            "pixels_rgba_b": std.bufToPtr(pixels_rgba_b),
            "pixels_rgba_b_width": pixels_rgba_b_width,
            "pixels_rgba_b_height": pixels_rgba_b_height,
            "position_x": position_x,
            "position_y": position_y,
            "trimming_x1": trimming_x1,
            "trimming_y1": trimming_y1,
            "trimming_x2": trimming_x2,
            "trimming_y2": trimming_y2
        });
        lib.call(handle, "raia_draw_blend_pixels_rgba_to_rgba", args);
    }

    /**
     * @param {ArrayBuffer} pixels 
     * @param {number} point_x (int)
     * @param {number} point_y (int)
     * @param {number} color_red (int)
     * @param {number} color_green (int)
     * @param {number} color_blue (int)
     * @param {number} canvas_width (int)
     * @param {number} canvas_height (int)
     */

    pointRGB(pixels,
             point_x, point_y,
             color_red, color_green, color_blue,
             canvas_width, canvas_height) {
        var args = JSON.stringify({
            "pixels": std.bufToPtr(pixels),
            "point_x": point_x,
            "point_y": point_y,
            "color_red": color_red,
            "color_green": color_green,
            "color_blue": color_blue,
            "canvas_width": canvas_width,
            "canvas_height": canvas_height
        });
        lib.call(handle, "raia_draw_point", args);
    }

    /**
     * @param {ArrayBuffer} pixels 
     * @param {number} canvas_width (int)
     * @param {number} canvas_height (int)
     * @param {number} point_x (int)
     * @param {number} point_y (int)
     * @param {number} color_red (int)
     * @param {number} color_green (int)
     * @param {number} color_blue (int)
     * @param {number} color_alpha (int)
     */

    pointRGBA(pixels, canvas_width, canvas_height,
              point_x, point_y,
              color_red, color_green, color_blue, color_alpha) {
        var args = JSON.stringify({
            "pixels": std.bufToPtr(pixels),
            "canvas_width": canvas_width,
            "canvas_height": canvas_height,
            "point_x": point_x,
            "point_y": point_y,
            "color_red": color_red,
            "color_green": color_green,
            "color_blue": color_blue,
            "color_alpha": color_alpha,
        });
        lib.call(handle, "raia_draw_point_rgba", args);
    }

    /**
     * @param {ArrayBuffer} pixels 
     * @param {number} canvas_width (int)
     * @param {number} canvas_height (int)
     * @param {number} point_x (int)
     * @param {number} point_y (int)
     * @param {number} color_red (int)
     * @param {number} color_green (int)
     * @param {number} color_blue (int)
     * @param {number} color_alpha (int)
     */

    pointRGBAtoRGB(pixels, canvas_width, canvas_height,
                   point_x, point_y,
                   color_red, color_green, color_blue, color_alpha) {
        var args = JSON.stringify({
            "pixels": std.bufToPtr(pixels),
            "canvas_width": canvas_width,
            "canvas_height": canvas_height,
            "point_x": point_x,
            "point_y": point_y,
            "color_red": color_red,
            "color_green": color_green,
            "color_blue": color_blue,
            "color_alpha": color_alpha
        });
        lib.call(handle, "raia_draw_point_alpha", args);
    }

    /**
     * @param {ArrayBuffer} pixels 
     * @param {number} canvas_width (int)
     * @param {number} canvas_height (int)
     * @param {number} start_x (int)
     * @param {number} start_y (int)
     * @param {number} end_x (int)
     * @param {number} end_y (int)
     * @param {number} color_red (int)
     * @param {number} color_green (int)
     * @param {number} color_blue (int)
     */

    lineRGB(pixels, canvas_width, canvas_height,
            start_x, start_y, end_x, end_y,
            color_red, color_green, color_blue) {
        var args = JSON.stringify({
            "pixels": std.bufToPtr(pixels),
            "canvas_width": canvas_width,
            "canvas_height": canvas_height,
            "start_x": start_x,
            "start_y": start_y,
            "end_x": end_x,
            "end_y": end_y,
            "color_red": color_red,
            "color_green": color_green,
            "color_blue": color_blue
        });
        lib.call(handle, "raia_draw_line", args);
    }

    /**
     * @param {ArrayBuffer} pixels 
     * @param {number} canvas_width (int)
     * @param {number} canvas_height (int)
     * @param {number} start_x (int)
     * @param {number} start_y (int)
     * @param {number} end_x (int)
     * @param {number} end_y (int)
     * @param {number} color_red (int)
     * @param {number} color_green (int)
     * @param {number} color_blue (int)
     * @param {number} color_alpha (int)
     */

    lineRGBA(pixels, canvas_width, canvas_height,
             start_x, start_y, end_x, end_y,
             color_red, color_green, color_blue, color_alpha) {
        var args = JSON.stringify({
            "pixels": std.bufToPtr(pixels),
            "canvas_width": canvas_width,
            "canvas_height": canvas_height,
            "start_x": start_x,
            "start_y": start_y,
            "end_x": end_x,
            "end_y": end_y,
            "color_red": color_red,
            "color_green": color_green,
            "color_blue": color_blue,
            "color_alpha": color_alpha
        });
        lib.call(handle, "raia_draw_line_rgba", args);
    }

    /**
     * @param {ArrayBuffer} pixels 
     * @param {number} canvas_width (int)
     * @param {number} canvas_height (int)
     * @param {number} start_x (int)
     * @param {number} start_y (int)
     * @param {number} end_x (int)
     * @param {number} end_y (int)
     * @param {number} color_red (int)
     * @param {number} color_green (int)
     * @param {number} color_blue (int)
     */

    fillRectRGB(pixels, canvas_width, canvas_height,
                start_x, start_y, end_x, end_y,
                color_red, color_green, color_blue) {
        var args = JSON.stringify({
            "pixels": std.bufToPtr(pixels),
            "canvas_width": canvas_width,
            "canvas_height": canvas_height,
            "start_x": start_x,
            "start_y": start_y,
            "end_x": end_x,
            "end_y": end_y,
            "color_red": color_red,
            "color_green": color_green,
            "color_blue": color_blue
        });
        lib.call(handle, "raia_draw_fill_rect", args);
    }

    /**
     * @param {ArrayBuffer} pixels 
     * @param {number} canvas_width (int)
     * @param {number} canvas_height (int)
     * @param {number} start_x (int)
     * @param {number} start_y (int)
     * @param {number} end_x (int)
     * @param {number} end_y (int)
     * @param {number} color_red (int)
     * @param {number} color_green (int)
     * @param {number} color_blue(int)
     */

    fillRectFastRGB(pixels, canvas_width, canvas_height,
                    start_x, start_y, end_x, end_y,
                    color_red, color_green, color_blue) {
        var args = JSON.stringify({
            "pixels": std.bufToPtr(pixels),
            "canvas_width": canvas_width,
            "canvas_height": canvas_height,
            "start_x": start_x,
            "start_y": start_y,
            "end_x": end_x,
            "end_y": end_y,
            "color_red": color_red,
            "color_green": color_green,
            "color_blue": color_blue
        });
        lib.call(handle, "raia_draw_fill_rect_fast", args);
    }

    /**
     * @param {ArrayBuffer} pixels 
     * @param {number} canvas_width (int)
     * @param {number} canvas_height (int)
     * @param {number} start_x (int)
     * @param {number} start_y (int)
     * @param {number} end_x (int)
     * @param {number} end_y (int)
     * @param {number} color_red (int)
     * @param {number} color_green (int)
     * @param {number} color_blue (int)
     * @param {number} color_alpha (int)
     */

    fillRectRGBA(pixels, canvas_width, canvas_height,
                 start_x, start_y, end_x, end_y,
                 color_red, color_green, color_blue, color_alpha) {
        var args = JSON.stringify({
            "pixels": std.bufToPtr(pixels),
            "canvas_width": canvas_width,
            "canvas_height": canvas_height,
            "start_x": start_x,
            "start_y": start_y,
            "end_x": end_x,
            "end_y": end_y,
            "color_red": color_red,
            "color_green": color_green,
            "color_blue": color_blue,
            "color_alpha": color_alpha
        });
        lib.call(handle, "raia_draw_fill_rect_rgba", args);
    }

    /**
     * @param {ArrayBuffer} pixels 
     * @param {number} canvas_width (int)
     * @param {number} canvas_height (int)
     * @param {number} start_x (int)
     * @param {number} start_y (int)
     * @param {number} end_x (int)
     * @param {number} end_y (int)
     * @param {number} color_red (int)
     * @param {number} color_green (int)
     * @param {number} color_blue (int)
     * @param {number} color_alpha (int)
     */

    fillRectRGBAtoRGB(pixels, canvas_width, canvas_height,
                      start_x, start_y, end_x, end_y,
                      color_red, color_green, color_blue, color_alpha) {
        var args = JSON.stringify({
            "pixels": std.bufToPtr(pixels),
            "canvas_width": canvas_width,
            "canvas_height": canvas_height,
            "start_x": start_x,
            "start_y": start_y,
            "end_x": end_x,
            "end_y": end_y,
            "color_red": color_red,
            "color_green": color_green,
            "color_blue": color_blue,
            "color_alpha": color_alpha
        });
        lib.call(handle, "raia_draw_fill_rect_alpha", args);
    }

    /**
     * @param {ArrayBuffer} pixels 
     * @param {number} canvas_width (int)
     * @param {number} canvas_height (int)
     * @param {number} start_x (int)
     * @param {number} start_y (int)
     * @param {number} end_x (int)
     * @param {number} end_y (int)
     * @param {number} color_red (int)
     * @param {number} color_green (int)
     * @param {number} color_blue (int)
     */

    drawEllipseRGB(pixels, canvas_width, canvas_height,
                   start_x, start_y, end_x, end_y,
                   color_red, color_green, color_blue) {
        var args = JSON.stringify({
            "pixels": std.bufToPtr(pixels),
            "canvas_width": canvas_width,
            "canvas_height": canvas_height,
            "start_x": start_x,
            "start_y": start_y,
            "end_x": end_x,
            "end_y": end_y,
            "color_red": color_red,
            "color_green": color_green,
            "color_blue": color_blue
        });
        lib.call(handle, "raia_draw_ellipse", args);
    }

    /**
     * @param {ArrayBuffer} pixels 
     * @param {number} canvas_width (int)
     * @param {number} canvas_height (int)
     * @param {number} start_x (int)
     * @param {number} start_y (int)
     * @param {number} end_x (int)
     * @param {number} end_y (int)
     * @param {number} color_red (int)
     * @param {number} color_green (int)
     * @param {number} color_blue (int)
     * @param {number} color_alpha (int)
     */

    drawEllipseRGBA(pixels, canvas_width, canvas_height,
                    start_x, start_y, end_x, end_y,
                    color_red, color_green, color_blue, color_alpha) {
        var args = JSON.stringify({
            "pixels": std.bufToPtr(pixels),
            "canvas_width": canvas_width,
            "canvas_height": canvas_height,
            "start_x": start_x,
            "start_y": start_y,
            "end_x": end_x,
            "end_y": end_y,
            "color_red": color_red,
            "color_green": color_green,
            "color_blue": color_blue,
            "color_alpha": color_alpha
        });
        lib.call(handle, "raia_draw_ellipse_rgba", args);
    }

    /**
     * @param {ArrayBuffer} pixels 
     * @param {number} canvas_width (int)
     * @param {number} canvas_height (int)
     * @param {number} start_x (int)
     * @param {number} start_y (int)
     * @param {number} end_x (int)
     * @param {number} end_y (int)
     * @param {number} color_red (int)
     * @param {number} color_green (int)
     * @param {number} color_blue (int)
     */

    drawFilledEllipseRGB(pixels, canvas_width, canvas_height,
                         start_x, start_y, end_x, end_y,
                         color_red, color_green, color_blue) {
        var args = JSON.stringify({
            "pixels": std.bufToPtr(pixels),
            "canvas_width": canvas_width,
            "canvas_height": canvas_height,
            "start_x": start_x,
            "start_y": start_y,
            "end_x": end_x,
            "end_y": end_y,
            "color_red": color_red,
            "color_green": color_green,
            "color_blue": color_blue
        });
        lib.call(handle, "raia_draw_filled_ellipse", args);
    }

    /**
     * @param {ArrayBuffer} pixels 
     * @param {number} canvas_width (int)
     * @param {number} canvas_height (int)
     * @param {number} start_x (int)
     * @param {number} start_y (int)
     * @param {number} end_x (int)
     * @param {number} end_y (int)
     * @param {number} color_red (int)
     * @param {number} color_green (int)
     * @param {number} color_blue (int)
     * @param {number} color_alpha (int)
     */

    drawFilledEllipseRGBA(pixels, canvas_width, canvas_height,
                          start_x, start_y, end_x, end_y,
                          color_red, color_green, color_blue, color_alpha) {
        var args = JSON.stringify({
            "pixels": std.bufToPtr(pixels),
            "canvas_width": canvas_width,
            "canvas_height": canvas_height,
            "start_x": start_x,
            "start_y": start_y,
            "end_x": end_x,
            "end_y": end_y,
            "color_red": color_red,
            "color_green": color_green,
            "color_blue": color_blue,
            "color_alpha": color_alpha
        });
        lib.call(handle, "raia_draw_filled_ellipse_rgba", args);
    }

    /**
     * @param {ArrayBuffer} pixels 
     * @param {number} canvas_width (int)
     * @param {number} canvas_height (int)
     * @param {number} start_x (int)
     * @param {number} start_y (int)
     * @param {number} end_x (int)
     * @param {number} end_y (int)
     * @param {number} color_red (int)
     * @param {number} color_green (int)
     * @param {number} color_blue (int)
     */

    drawFilledEllipseSmooth(pixels, canvas_width, canvas_height,
                            start_x, start_y, end_x, end_y,
                            color_red, color_green, color_blue) {
        var args = JSON.stringify({
            "pixels": std.bufToPtr(pixels),
            "canvas_width": canvas_width,
            "canvas_height": canvas_height,
            "start_x": start_x,
            "start_y": start_y,
            "end_x": end_x,
            "end_y": end_y,
            "color_red": color_red,
            "color_green": color_green,
            "color_blue": color_blue
        });
        lib.call(handle, "raia_draw_filled_ellipse_smooth", args);
    }

    /**
     * @param {number} width (real)
     * @param {number} height (real)
     */

    d3mInit(width, height) {
        var args = JSON.stringify({
            "width": width,
            "height": height
        });
        lib.call(handle, "raia_draw_d3m_init", args);
    }

    /**
     * @param {number} pos_x (real)
     * @param {number} pos_y (real)
     * @param {number} pos_z (real)
     * @param {number} target_x (real)
     * @param {number} target_y (real)
     * @param {number} target_z (real)
     */

    d3mSetCamera(pos_x, pos_y, pos_z, target_x, target_y, target_z) {
        var args = JSON.stringify({
            "pos_x": pos_x,
            "pos_y": pos_y,
            "pos_z": pos_z,
            "target_x": target_x,
            "target_y": target_y,
            "target_z": target_z
        });
        lib.call(handle, "raia_draw_d3m_set_camera", args);
    }

    /**
     * @param {number} pos_x (real)
     * @param {number} pos_y (real)
     * @param {number} pos_z (real)
     * @returns {{x:number, y:number}} {int, int}
     */

    d3mTransform3Dto2D(pos_x, pos_y, pos_z) {
        var args = JSON.stringify({
            "pos_x": pos_x,
            "pos_y": pos_y,
            "pos_z": pos_z
        });
        var ret = lib.call(handle, "raia_draw_d3m_calc_position", args);
        return JSON.parse(ret);
    }
}
