import {App} from "raia_app";
import {Draw} from "raia_draw";
import {Image} from "raia_image";

export class Window {
    constructor(title, width, height) {
        this.app = new App(width, height, title);
        this.draw = new Draw();
        this.image = new Image();
    }
    //onKey(f) {return __Raia__.App.Event.key(this.id, f);} // window, (key, scancode, action, mods)
    //onMouse(f) {__Raia__.App.Event.mouse(this.id, f);} // (button, action, mods)
    //onWindowPos(f) {__Raia__.App.Event.windowPos(this.id, f);}
    //onWindowSize(f) {__Raia__.App.Event.windowSize(this.id, f);}
    //onWindowClose(f) {__Raia__.App.Event.windowClose(this.id, f);}
    //onWindowRefresh(f) {__Raia__.App.Event.windowRefresh(this.id, f);}
    //onWindowFocus(f) {__Raia__.App.Event.windowFocus(this.id, f);}
    //onWindowIconify(f) {__Raia__.App.Event.windowIconify(this.id, f);}
    //onFrame(f) {__Raia__.App.Event.frame(this.id, f);}
    //onCursor(f) {__Raia__.App.Event.cursor(this.id, f);} // (xpos, ypos)
    //onChar(f) {__Raia__.App.Event.char(this.id, f);}
    //onCharMods(f) {__Raia__.App.Event.charMods(this.id, f);}
    //onEnter(f) {__Raia__.App.Event.enter(this.id, f);}
    //onScroll(f) {__Raia__.App.Event.scroll(this.id, f);}
    //onDrop(f) {__Raia__.App.Event.drop(this.id, f);}
    onUpdate(f, fps = this.app.fps) {
        var targetFrameDuration = 1.0 / fps;
        while (!this.app.shouldClose()) {
            var startTime = this.app.getCurrentTime();
            f();
            this.app.pollEvents();
            var endTime = this.app.getCurrentTime();
            var elapsedTime = endTime - startTime;
            if (elapsedTime < targetFrameDuration) {
                var sleepTime = targetFrameDuration - elapsedTime;
                while (this.app.getCurrentTime() - startTime < targetFrameDuration) {
                    this.app.pollEvents();
                }
            }
        }
    }
    setFPS(fps = 60.0) {
        this.app.fps = fps;
    }
    checkClose() {
        return this.app.shouldClose();
    }
    pollEvents() {
        return this.app.pollEvents();
    }
    waitEventTimeout(timeout) {
        return this.app.waitEventTimeout(timeout);
    }
    setTitle(title) {
        return this.app.setTitle(title);
    }
    redraw() {
        return this.app.redraw(
            this.app.vertices,
            this.app.indices,
            this.app.program,
            this.app.pos_location,
            this.app.tex_location,
            this.app.sampler_location,
            this.app.texture,
            this.app.size.width,
            this.app.size.height,
            this.app.resolution_width,
            this.app.resolution_height,
            this.app.id,
            this.app.pixels
        );
    }
    setCurrentColor(red, green, blue) {
        this.app.color.red = red;
        this.app.color.green = green;
        this.app.color.blue = blue;
    }
    drawPoint(posx, posy,
              red = this.app.color.red,
              green = this.app.color.green,
              blue = this.app.color.blue,
              width = this.app.size.width,
              height = this.app.size.height) {
        return this.draw.pointRGB(this.app.pixels, posx, posy, red, green, blue, width, height);
    }
    drawLine(startx, starty, endx, endy,
             red = this.app.color.red,
             green = this.app.color.green,
             blue = this.app.color.blue,
             width = this.app.size.width,
             height = this.app.size.height) {
        return this.draw.lineRGB(this.app.pixels, startx, starty, endx, endy, red, green, blue, width, height);
    }
    drawRect(start_x, start_y, end_x, end_y,
             red = this.app.color.red,
             green = this.app.color.green,
             blue = this.app.color.blue,
             width = this.app.size.width,
             height = this.app.size.height) {
        this.draw.lineRGB(this.app.pixels, start_x, start_y, end_x, start_y, red, green, blue, width, height);
        this.draw.lineRGB(this.app.pixels, end_x, start_y, end_x, end_y, red, green, blue, width, height);
        this.draw.lineRGB(this.app.pixels, end_x, end_y, start_x, end_y, red, green, blue, width, height);
        this.draw.lineRGB(this.app.pixels, start_x, end_y, start_x, start_y, red, green, blue, width, height);
    }
    drawFilledRect(start_x, start_y, end_x, end_y,
                   red = this.app.color.red,
                   green = this.app.color.green,
                   blue = this.app.color.blue,
                   width = this.app.size.width,
                   height = this.app.size.height) {
        return this.draw.fillRectRGB(this.app.pixels, start_x, start_y, end_x, end_y, red, green, blue, width, height);
    }
    drawEllipse(start_x, start_y, end_x, end_y,
                red = this.app.color.red,
                green = this.app.color.green,
                blue = this.app.color.blue,
                width = this.app.size.width,
                height = this.app.size.height) {
        return this.draw.drawEllipseRGB(this.app.pixels, start_x, start_y, end_x, end_y, red, green, blue, width, height);
    }
    drawFilledEllipse(start_x, start_y, end_x, end_y,
                      red = this.color.red,
                      green = this.color.green,
                      blue = this.color.blue,
                      width = this.size.width,
                      height = this.size.height) {
        return this.draw.drawFilledEllipseRGB(this.app.pixels, start_x, start_y, end_x, end_y, red, green, blue, width, height);
    }
    blendSurface(surface, pos_x = 0, pos_y = 0, trim_x1 = 0, trim_y1 = 0, trim_x2, trim_y2) {
        trim_x2 = (typeof trim_x2 !== 'undefined') ?  trim_x2 : surface.size.width;
        trim_y2 = (typeof trim_y2 !== 'undefined') ?  trim_y2 : surface.size.height;
        this.draw.blendPixelsRGBAtoRGB(
            this.app.pixels, this.app.size.width, this.app.size.height,
            surface.pixels, surface.size.width, surface.size.height,
            pos_x, pos_y,
            trim_x1, trim_y1, trim_x2, trim_y2);
    }
    init3D() {
        this.draw.d3mInit(this.app.size.width, this.app.size.height);
    }
    setCamera(pos_x, pos_y, pos_z, target_x, target_y, target_z) {
        this.draw.d3mSetCamera(pos_x, pos_y, pos_z,  target_x, target_y, target_z);
    }
    transform3Dto2D(x, y, z) {
        return this.draw.d3mTransform3Dto2D(x, y, z);
    }
    drawPoint3D(x, y, z) {
        var pos = this.transform3Dto2D(x, y, z);
        this.drawPoint(pos.x, pos.y);
    }
    drawLine3D(x1, y1, z1, x2, y2, z2) {
        var start = this.transform3Dto2D(x1, y1, z1);
        var end = this.transform3Dto2D(x2, y2, z2);
        this.drawLine(start.x, start.y, end.x, end.y);
    }
    drawText(font,
             text,
             font_size,
             color_red = this.app.color.red,
             color_green = this.app.color.green,
             color_blue = this.app.color.blue,
             pos_x = this.app.position.x,
             pos_y = this.app.position.y) {
        font_size = (typeof font_size !== 'undefined') ?  font_size : font.font_size;
        return font.drawTextRGB(
            this.app.pixels, // 0
            this.app.size.width, // 1
            this.app.size.height, //2
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
    drawString(font,
               str,
               font_size,
               color_red = this.app.color.red,
               color_green = this.app.color.green,
               color_blue = this.app.color.blue,
               pos_x = this.app.position.x,
               pos_y = this.app.position.y,
               wrap_width,
               wrap_height) {
        font_size = (typeof font_size !== 'undefined') ?  font_size : font.font_size;
        wrap_width = (typeof wrap_width !== 'undefined') ?  wrap_width : this.app.size.width - pos_x;
        wrap_height = (typeof wrap_height !== 'undefined') ?  wrap_height : this.app.size.height- pos_y;
        var x = 3;
        var y = 0;
        var line_height = 20;
        for(var i = 0; i < str.length; i++) {
            var size = this.drawText(font, str[i], font_size, color_red, color_green, color_blue, pos_x + x, pos_y + y);
            x += size.width + (font_size / 10);
            if ((x + font_size * 1.2) > wrap_width) {
                x = 3;
                y += font_size;
            }
        }
    }
    loadImage(filename, pos_x = 0, pos_y = 0, trim_x1 = 0, trim_y1 = 0, trim_x2 = -1, trim_y2 = -1) {
        this.image.loadImageRGB(
            this.app.pixels, this.app.size.width, this.app.size.height,
            filename,
            pos_x, pos_y,
            trim_x1, trim_y1, trim_x2, trim_y2);
    }
}