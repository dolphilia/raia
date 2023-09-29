import {Lib} from "raia_lib";
const lib = new Lib();

import {Std} from "raia_std";
const std = new Std();

(function() {
    if (globalThis.__RAIA_DRAW__ === undefined) {
        var handle = lib.open("raia_draw");
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
        lib.add(handle, "raia_draw_load_and_blend_image_rgb");
        lib.add(handle, "raia_draw_load_and_blend_image_rgba");
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
     * 
     * @param {ArrayBuffer} pixels 
     * @param {int} width 
     * @param {int} height 
     * @returns 
     */
    noiseRGB_CPU(pixels, width, height) {
        var args = JSON.stringify({
            "pixels": std.arrayBufferToPointer(pixels),
            "width": width,
            "height": height
        });
        lib.call("raia_draw_noise_cpu", args);
    }
    noiseRGB_GPU(pixels, width, height) {
        var args = JSON.stringify({
            "pixels": std.arrayBufferToPointer(pixels),
            "width": width,
            "height": height
        });
        lib.call("raia_draw_noise_gpu", args);
    }
    /**
     * @param {ArrayBuffer} pixels_rgb
     * @param {int} pixels_rgb_width
     * @param {int} pixels_rgb_height
     * @param {ArrayBuffer} pixels_rgba
     * @param {int} pixels_rgba_width
     * @param {int} pixels_rgba_height
     * @param {int} position_x
     * @param {int} position_y
     * @param {int} trimming_x1
     * @param {int} trimming_y1
     * @param {int} trimming_x2
     * @param {int} trimming_y2
     */
    blendPixelsRGBAtoRGB(pixels_rgb, pixels_rgb_width, pixels_rgb_height,
                         pixels_rgba, pixels_rgba_width, pixels_rgba_height,
                         position_x, position_y,
                         trimming_x1, trimming_y1, trimming_x2, trimming_y2) {
        var args = JSON.stringify({
            "pixels_rgb": std.arrayBufferToPointer(pixels_rgb),
            "pixels_rgb_width": pixels_rgb_width,
            "pixels_rgb_height": pixels_rgb_height,
            "pixels_rgba": std.arrayBufferToPointer(pixels_rgba),
            "pixels_rgba_width": pixels_rgba_width,
            "pixels_rgba_height": pixels_rgba_height,
            "position_x": position_x,
            "position_y": position_y,
            "trimming_x1": trimming_x1,
            "trimming_y1": trimming_y1,
            "trimming_x2": trimming_x2,
            "trimming_y2": trimming_y2
        });
        lib.call("raia_draw_blend_pixels_rgba_to_rgb", args);
    }
    /**
     * 
     * @param {ArrayBuffer} pixels_rgba_a 
     * @param {int} pixels_rgba_a_width 
     * @param {int} pixels_rgba_a_height 
     * @param {ArrayBuffer} pixels_rgba_b 
     * @param {int} pixels_rgba_b_width 
     * @param {int} pixels_rgba_b_height 
     * @param {int} position_x 
     * @param {int} position_y 
     * @param {int} trimming_x1 
     * @param {int} trimming_y1 
     * @param {int} trimming_x2 
     * @param {int} trimming_y2 
     */
    blendPixelsRGBAtoRGBA (pixels_rgba_a, pixels_rgba_a_width, pixels_rgba_a_height,
                           pixels_rgba_b, pixels_rgba_b_width, pixels_rgba_b_height,
                           position_x, position_y,
                           trimming_x1, trimming_y1, trimming_x2, trimming_y2) {
        var args = JSON.stringify({
            "pixels_rgba_a": std.arrayBufferToPointer(pixels_rgba_a),
            "pixels_rgba_a_width": pixels_rgba_a_width,
            "pixels_rgba_a_height": pixels_rgba_a_height,
            "pixels_rgba_b": std.arrayBufferToPointer(pixels_rgba_b),
            "pixels_rgba_b_width": pixels_rgba_b_width,
            "pixels_rgba_b_height": pixels_rgba_b_height,
            "position_x": position_x,
            "position_y": position_y,
            "trimming_x1": trimming_x1,
            "trimming_y1": trimming_y1,
            "trimming_x2": trimming_x2,
            "trimming_y2": trimming_y2
        });
        lib.call("raia_draw_blend_pixels_rgba_to_rgba", args);
    }
    /**
     * 
     * @param {ArrayBuffer} pixels 
     * @param {int} point_x 
     * @param {int} point_y 
     * @param {int} color_red 
     * @param {int} color_green 
     * @param {int} color_blue 
     * @param {int} canvas_width 
     * @param {int} canvas_height 
     */
    pointRGB(pixels,
             point_x, point_y,
             color_red, color_green, color_blue,
             canvas_width, canvas_height) {
        var args = JSON.stringify({
            "pixels": std.arrayBufferToPointer(pixels),
            "point_x": point_x,
            "point_y": point_y,
            "color_red": color_red,
            "color_green": color_green,
            "color_blue": color_blue,
            "canvas_width": canvas_width,
            "canvas_height": canvas_height
        });
        lib.call("raia_draw_point", args);
    }
    /**
     * 
     * @param {ArrayBuffer} pixels 
     * @param {int} canvas_width 
     * @param {int} canvas_height 
     * @param {int} point_x 
     * @param {int} point_y 
     * @param {int} color_red 
     * @param {int} color_green 
     * @param {int} color_blue 
     * @param {int} color_alpha 
     */
    pointRGBA(pixels, canvas_width, canvas_height,
              point_x, point_y,
              color_red, color_green, color_blue, color_alpha) {
        var args = JSON.stringify({
            "pixels": std.arrayBufferToPointer(pixels),
            "canvas_width": canvas_width,
            "canvas_height": canvas_height,
            "point_x": point_x,
            "point_y": point_y,
            "color_red": color_red,
            "color_green": color_green,
            "color_blue": color_blue,
            "color_alpha": color_alpha,
        });
        lib.call("raia_draw_point_rgba", args);
    }
    /**
     * 
     * @param {ArrayBuffer} pixels 
     * @param {int} canvas_width 
     * @param {int} canvas_height 
     * @param {int} point_x 
     * @param {int} point_y 
     * @param {int} color_red 
     * @param {int} color_green 
     * @param {int} color_blue 
     * @param {int} color_alpha 
     */
    pointRGBAtoRGB(pixels, canvas_width, canvas_height,
                   point_x, point_y,
                   color_red, color_green, color_blue, color_alpha) {
        var args = JSON.stringify({
            "pixels": std.arrayBufferToPointer(pixels),
            "canvas_width": canvas_width,
            "canvas_height": canvas_height,
            "point_x": point_x,
            "point_y": point_y,
            "color_red": color_red,
            "color_green": color_green,
            "color_blue": color_blue,
            "color_alpha": color_alpha
        });
        lib.call("raia_draw_point_alpha", args);
    }
    /**
     * 
     * @param {ArrayBuffer} pixels 
     * @param {int} canvas_width 
     * @param {int} canvas_height 
     * @param {int} start_x 
     * @param {int} start_y 
     * @param {int} end_x 
     * @param {int} end_y 
     * @param {int} color_red 
     * @param {int} color_green 
     * @param {int} color_blue 
     */
    lineRGB(pixels, canvas_width, canvas_height,
            start_x, start_y, end_x, end_y,
            color_red, color_green, color_blue) {
        var args = JSON.stringify({
            "pixels": std.arrayBufferToPointer(pixels),
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
        lib.call("raia_draw_line", args);
    }
    /**
     * 
     * @param {ArrayBuffer} pixels 
     * @param {int} canvas_width 
     * @param {int} canvas_height 
     * @param {int} start_x 
     * @param {int} start_y 
     * @param {int} end_x 
     * @param {int} end_y 
     * @param {int} color_red 
     * @param {int} color_green 
     * @param {int} color_blue 
     * @param {int} color_alpha 
     */
    lineRGBA(pixels, canvas_width, canvas_height,
             start_x, start_y, end_x, end_y,
             color_red, color_green, color_blue, color_alpha) {
        var args = JSON.stringify({
            "pixels": std.arrayBufferToPointer(pixels),
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
        lib.call("raia_draw_line_rgba", args);
    }
    /**
     * 
     * @param {ArrayBuffer} pixels 
     * @param {int} canvas_width 
     * @param {int} canvas_height 
     * @param {int} start_x 
     * @param {int} start_y 
     * @param {int} end_x 
     * @param {int} end_y 
     * @param {int} color_red 
     * @param {int} color_green 
     * @param {int} color_blue 
     */
    fillRectRGB(pixels, canvas_width, canvas_height,
                start_x, start_y, end_x, end_y,
                color_red, color_green, color_blue) {
        var args = JSON.stringify({
            "pixels": std.arrayBufferToPointer(pixels),
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
        lib.call("raia_draw_fill_rect", args);
    }
    /**
     * 
     * @param {ArrayBuffer} pixels 
     * @param {int} canvas_width 
     * @param {int} canvas_height 
     * @param {int} start_x 
     * @param {int} start_y 
     * @param {int} end_x 
     * @param {int} end_y 
     * @param {int} color_red 
     * @param {int} color_green 
     * @param {int} color_blue
     */
    fillRectFastRGB(pixels, canvas_width, canvas_height,
                    start_x, start_y, end_x, end_y,
                    color_red, color_green, color_blue) {
        var args = JSON.stringify({
            "pixels": std.arrayBufferToPointer(pixels),
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
        lib.call("raia_draw_fill_rect_fast", args);
    }
    /**
     * 
     * @param {ArrayBuffer} pixels 
     * @param {int} canvas_width 
     * @param {int} canvas_height 
     * @param {int} start_x 
     * @param {int} start_y 
     * @param {int} end_x 
     * @param {int} end_y 
     * @param {int} color_red 
     * @param {int} color_green 
     * @param {int} color_blue 
     * @param {int} color_alpha 
     */
    fillRectRGBA(pixels, canvas_width, canvas_height,
                 start_x, start_y, end_x, end_y,
                 color_red, color_green, color_blue, color_alpha) {
        var args = JSON.stringify({
            "pixels": std.arrayBufferToPointer(pixels),
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
        lib.call("raia_draw_fill_rect_rgba", args);
    }
    /**
     * 
     * @param {ArrayBuffer} pixels 
     * @param {int} canvas_width 
     * @param {int} canvas_height 
     * @param {int} start_x 
     * @param {int} start_y 
     * @param {int} end_x 
     * @param {int} end_y 
     * @param {int} color_red 
     * @param {int} color_green 
     * @param {int} color_blue 
     * @param {int} color_alpha 
     */
    fillRectRGBAtoRGB(pixels, canvas_width, canvas_height,
                      start_x, start_y, end_x, end_y,
                      color_red, color_green, color_blue, color_alpha) {
        var args = JSON.stringify({
            "pixels": std.arrayBufferToPointer(pixels),
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
        lib.call("raia_draw_fill_rect_alpha", args);
    }
    /**
     * 
     * @param {ArrayBuffer} pixels 
     * @param {int} canvas_width 
     * @param {int} canvas_height 
     * @param {int} start_x 
     * @param {int} start_y 
     * @param {int} end_x 
     * @param {int} end_y 
     * @param {int} color_red 
     * @param {int} color_green 
     * @param {int} color_blue 
     */
    drawEllipseRGB(pixels, canvas_width, canvas_height,
                   start_x, start_y, end_x, end_y,
                   color_red, color_green, color_blue) {
        var args = JSON.stringify({
            "pixels": std.arrayBufferToPointer(pixels),
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
        lib.call("raia_draw_ellipse", args);
    }
    /**
     * 
     * @param {ArrayBuffer} pixels 
     * @param {int} canvas_width 
     * @param {int} canvas_height 
     * @param {int} start_x 
     * @param {int} start_y 
     * @param {int} end_x 
     * @param {int} end_y 
     * @param {int} color_red 
     * @param {int} color_green 
     * @param {int} color_blue 
     * @param {int} color_alpha 
     */
    drawEllipseRGBA(pixels, canvas_width, canvas_height,
                    start_x, start_y, end_x, end_y,
                    color_red, color_green, color_blue, color_alpha) {
        var args = JSON.stringify({
            "pixels": std.arrayBufferToPointer(pixels),
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
        lib.call("raia_draw_ellipse_rgba", args);
    }
    /**
     * 
     * @param {ArrayBuffer} pixels 
     * @param {int} canvas_width 
     * @param {int} canvas_height 
     * @param {int} start_x 
     * @param {int} start_y 
     * @param {int} end_x 
     * @param {int} end_y 
     * @param {int} color_red 
     * @param {int} color_green 
     * @param {int} color_blue 
     */
    drawFilledEllipseRGB(pixels, canvas_width, canvas_height,
                         start_x, start_y, end_x, end_y,
                         color_red, color_green, color_blue) {
        var args = JSON.stringify({
            "pixels": std.arrayBufferToPointer(pixels),
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
        lib.call("raia_draw_filled_ellipse", args);
    }
    /**
     * 
     * @param {ArrayBuffer} pixels 
     * @param {int} canvas_width 
     * @param {int} canvas_height 
     * @param {int} start_x 
     * @param {int} start_y 
     * @param {int} end_x 
     * @param {int} end_y 
     * @param {int} color_red 
     * @param {int} color_green 
     * @param {int} color_blue 
     * @param {int} color_alpha 
     */
    drawFilledEllipseRGBA(pixels, canvas_width, canvas_height,
                          start_x, start_y, end_x, end_y,
                          color_red, color_green, color_blue, color_alpha) {
        var args = JSON.stringify({
            "pixels": std.arrayBufferToPointer(pixels),
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
        lib.call("raia_draw_filled_ellipse_rgba", args);
    }
    /**
     * 
     * @param {ArrayBuffer} pixels 
     * @param {int} canvas_width 
     * @param {int} canvas_height 
     * @param {int} start_x 
     * @param {int} start_y 
     * @param {int} end_x 
     * @param {int} end_y 
     * @param {int} color_red 
     * @param {int} color_green 
     * @param {int} color_blue 
     */
    drawFilledEllipseSmooth(pixels, canvas_width, canvas_height,
                            start_x, start_y, end_x, end_y,
                            color_red, color_green, color_blue) {
        var args = JSON.stringify({
            "pixels": std.arrayBufferToPointer(pixels),
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
        lib.call("raia_draw_filled_ellipse_smooth", args);
    }
    /**
     * 
     * @param {real} width 
     * @param {real} height 
     */
    d3mInit(width, height) {
        var args = JSON.stringify({
            "width": width,
            "height": height
        });
        lib.call("raia_draw_d3m_init", args);
    }
    /**
     * 
     * @param {real} pos_x 
     * @param {real} pos_y 
     * @param {real} pos_z 
     * @param {real} target_x 
     * @param {real} target_y 
     * @param {real} target_z 
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
        lib.call("raia_draw_d3m_set_camera", args);
    }
    /**
     * 
     * @param {real} pos_x 
     * @param {real} pos_y 
     * @param {real} pos_z 
     * @returns {{x:int, y:int}}
     */
    d3mTransform3Dto2D(pos_x, pos_y, pos_z) {
        var args = JSON.stringify({
            "pos_x": pos_x,
            "pos_y": pos_y,
            "pos_z": pos_z
        });
        var ret = lib.call("raia_draw_d3m_calc_position", args);
        return JSON.parse(ret);
    }
}
