(function() {
    if (globalThis.__Raia__.Image === undefined) {
        var handle = __Raia__.Lib.open("raia_image");
        __Raia__.Lib.add(handle, "raia_image_load");
        __Raia__.Lib.add(handle, "raia_image_load_blend_rgb");
        globalThis.__Raia__.Image = {};
    }
}());

export class Image {
    constructor() {
    }
    loadImageRGB(pixels_rgba, pixels_rgba_width, pixels_rgba_height,
                 filename,
                 position_x, position_y,
                 trimming_x1, trimming_y1, trimming_x2, trimming_y2) {
        var json_str = JSON.stringify({
            "pixels_rgba": __Raia__.Core.arrayBufferToPointer(pixels_rgba),
            "pixels_rgba_width": pixels_rgba_width,
            "pixels_rgba_height": pixels_rgba_height,
            "filename": filename,
            "position_x": position_x,
            "position_y": position_y,
            "trimming_x1": trimming_x1,
            "trimming_y1": trimming_y1,
            "trimming_x2": trimming_x2,
            "trimming_y2": trimming_y2
        });
        var ret = __Raia__.Lib.call("raia_draw_load_and_blend_image_rgb", json_str); // (window, title)
        return JSON.parse(ret).result;
    }
    loadImageRGBA(pixels_rgba, pixels_rgba_width, pixels_rgba_height,
                  filename,
                  position_x, position_y,
                  trimming_x1, trimming_y1, trimming_x2, trimming_y2) {
        var json_str = JSON.stringify({
            "pixels_rgba": __Raia__.Core.arrayBufferToPointer(pixels_rgba),
            "pixels_rgba_width": pixels_rgba_width,
            "pixels_rgba_height": pixels_rgba_height,
            "filename": filename,
            "position_x": position_x,
            "position_y": position_y,
            "trimming_x1": trimming_x1,
            "trimming_y1": trimming_y1,
            "trimming_x2": trimming_x2,
            "trimming_y2": trimming_y2
        });
        var ret = __Raia__.Lib.call("raia_draw_load_and_blend_image_rgba", json_str); // (window, title)
        return JSON.parse(ret).result;
    }
}