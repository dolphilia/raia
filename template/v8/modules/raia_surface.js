import {Draw} from "raia_draw";
import {Image} from "raia_image";

export class Surface {
    
    constructor(width, height, pos_x = 0, pos_y = 0) {
        this.draw = new Draw();
        this.image = new Image();
        this.pixels = new ArrayBuffer(width * height * 4);
        this.size = {
            width: width,
            height: height
        }
        this.color = {
            red: 0,
            green: 0,
            blue: 0,
            alpha: 255
        };
        this.position = {
            x: pos_x,
            y: pos_y
        }
    }

    setCurrentColor(red, green, blue, alpha) {
        this.color.red = red;
        this.color.green = green;
        this.color.blue = blue;
        this.color.alpha = alpha;
    }

    drawPoint(posx, posy,
              red = this.color.red,
              green = this.color.green,
              blue = this.color.blue,
              alpha = this.color.alpha,
              width = this.size.width,
              height = this.size.height) {
        return this.draw.pointRGBA(this.pixels, posx, posy, red, green, blue, width, height);
    }

    drawLine(startx, starty, endx, endy,
             red = this.color.red,
             green = this.color.green,
             blue = this.color.blue,
             alpha = this.color.alpha,
             width = this.size.width,
             height = this.size.height) {
        return this.draw.lineRGBA(this.pixels, startx, starty, endx, endy, red, green, blue, width, height);
    }

    drawRect(start_x, start_y, end_x, end_y,
             red = this.color.red,
             green = this.color.green,
             blue = this.color.blue,
             alpha = this.color.alpha,
             width = this.size.width,
             height = this.size.height) {
        this.draw.lineRGBA(this.pixels, start_x, start_y, end_x, start_y, red, green, blue, alpha, width, height);
        this.draw.lineRGBA(this.pixels, end_x, start_y, end_x, end_y, red, green, blue, alpha, width, height);
        this.draw.lineRGBA(this.pixels, end_x, end_y, start_x, end_y, red, green, blue, alpha, width, height);
        this.draw.lineRGBA(this.pixels, start_x, end_y, start_x, start_y, red, green, blue, alpha, width, height);
    }

    drawFilledRect(start_x, start_y, end_x, end_y,
                   red = this.color.red,
                   green = this.color.green,
                   blue = this.color.blue,
                   alpha = this.color.alpha,
                   width = this.size.width,
                   height = this.size.height) {
        return this.draw.fillRectRGBA(this.pixels, start_x, start_y, end_x, end_y, red, green, blue, alpha, width, height);
    }

    drawEllipse(start_x, start_y, end_x, end_y,
                red = this.color.red,
                green = this.color.green,
                blue = this.color.blue,
                alpha = this.color.alpha,
                width = this.size.width,
                height = this.size.height) {
        return this.draw.drawEllipseRGBA(this.pixels, start_x, start_y, end_x, end_y, red, green, blue, alpha, width, height);
    }

    drawFilledEllipse(start_x, start_y, end_x, end_y,
                      red = this.color.red,
                      green = this.color.green,
                      blue = this.color.blue,
                      alpha = this.color.alpha,
                      width = this.size.width,
                      height = this.size.height) {
        return this.draw.drawFilledEllipseRGBA(this.pixels, start_x, start_y, end_x, end_y, red, green, blue, alpha, width, height);
    }

    blendSurface(surface, pos_x = 0, pos_y = 0, trim_x1 = 0, trim_y1 = 0, trim_x2, trim_y2) {
        trim_x2 = (typeof trim_x2 !== 'undefined') ?  trim_x2 : surface.size.width;
        trim_y2 = (typeof trim_y2 !== 'undefined') ?  trim_y2 : surface.size.height;
        this.draw.blendPixelsRGBAtoRGBA(
            this.pixels, this.size.width, this.size.height,
            surface.pixels, surface.size.width, surface.size.height,
            pos_x, pos_y,
            trim_x1, trim_y1, trim_x2, trim_y2);
        //__Raia__.Draw.copyPixelsRGBAtoRGB(this.pixels, this.size.width, this.size.height, surface.pixels, surface.size.width, surface.size.height)
    }

    loadImage(filename, pos_x = 0, pos_y = 0, trim_x1 = 0, trim_y1 = 0, trim_x2 = -1, trim_y2 = -1) {
        this.image.loadImageRGBA(
            this.pixels, this.size.width, this.size.height,
            filename,
            pos_x, pos_y,
            trim_x1, trim_y1, trim_x2, trim_y2);
    }

    drawText(font, text, font_size, color_red = this.color.red, color_green = this.color.green, color_blue = this.color.blue, pos_x = this.position.x, pos_y = this.position.y) {
        font_size = (typeof font_size !== 'undefined') ?  font_size : font.font_size;
        return font.drawTextRGBA(
            this.pixels, // 0
            this.size.width, // 1
            this.size.height, //2
            text, //3
            font_size, //4
            color_red,
            color_green,
            color_blue,
            pos_x,//5
            pos_y,//6
            font.font_buffer,//7
            font.font_info.userdata,//8
            font.font_info.data,//9
            font.font_info.fontstart,//10
            font.font_info.numGlyphs,//11
            font.font_info.loca,//12
            font.font_info.head,//13
            font.font_info.glyf,//14
            font.font_info.hhea,//15
            font.font_info.hmtx,//16
            font.font_info.kern,//17
            font.font_info.gpos,//18
            font.font_info.svg,//19
            font.font_info.index_map,//20
            font.font_info.indexToLocFormat,//21
            font.font_info.cff_data,//22
            font.font_info.cff_cursor,//23
            font.font_info.cff_size,//24
            font.font_info.charstrings_data,//25
            font.font_info.charstrings_cursor,//26
            font.font_info.charstrings_size,//27
            font.font_info.gsubrs_data,//28
            font.font_info.gsubrs_cursor,//29
            font.font_info.gsubrs_size,//30
            font.font_info.subrs_data,//31
            font.font_info.subrs_cursor,//32
            font.font_info.subrs_size,//33
            font.font_info.fontdicts_data,//34
            font.font_info.fontdicts_cursor,//35
            font.font_info.fontdicts_size,//36
            font.font_info.fdselect_data,//37
            font.font_info.fdselect_cursor,//38
            font.font_info.fdselect_size)//39
    }

    getTextSize(font, text, font_size) {
        font_size = (typeof font_size !== 'undefined') ?  font_size : font.font_size;
        return font.getTextSize(
            text, //3
            font_size, //4
            font.font_info.userdata,//8
            font.font_info.data,//9
            font.font_info.fontstart,//10
            font.font_info.numGlyphs,//11
            font.font_info.loca,//12
            font.font_info.head,//13
            font.font_info.glyf,//14
            font.font_info.hhea,//15
            font.font_info.hmtx,//16
            font.font_info.kern,//17
            font.font_info.gpos,//18
            font.font_info.svg,//19
            font.font_info.index_map,//20
            font.font_info.indexToLocFormat,//21
            font.font_info.cff_data,//22
            font.font_info.cff_cursor,//23
            font.font_info.cff_size,//24
            font.font_info.charstrings_data,//25
            font.font_info.charstrings_cursor,//26
            font.font_info.charstrings_size,//27
            font.font_info.gsubrs_data,//28
            font.font_info.gsubrs_cursor,//29
            font.font_info.gsubrs_size,//30
            font.font_info.subrs_data,//31
            font.font_info.subrs_cursor,//32
            font.font_info.subrs_size,//33
            font.font_info.fontdicts_data,//34
            font.font_info.fontdicts_cursor,//35
            font.font_info.fontdicts_size,//36
            font.font_info.fdselect_data,//37
            font.font_info.fdselect_cursor,//38
            font.font_info.fdselect_size)//39
    }

    drawString(font, str, font_size, color_red = this.color.red, color_green = this.color.green, color_blue = this.color.blue, pos_x = this.position.x, pos_y = this.position.y, wrap_width, wrap_height) {
        font_size = (typeof font_size !== 'undefined') ?  font_size : font.font_size;
        wrap_width = (typeof wrap_width !== 'undefined') ?  wrap_width : this.size.width - pos_x;
        wrap_height = (typeof wrap_height !== 'undefined') ?  wrap_height : this.size.height- pos_y;
        var x = 3;
        var y = 0;
        var line_height = 20;
        for(var i = 0; i < str.length; i++) {
            var size = this.drawText(font, str[i], font_size, color_red, color_green, color_blue, pos_x + x, pos_y + y);
            x += size.width + 2;
            if ((x + font_size * 1.2) > wrap_width) {
                x = 3;
                y += font_size;
            }
        }
    }
}