__Raia__.App = require('raia_app');
__Raia__.Draw = require('raia_draw');

__Raia__.App.init();

class Core {
    constructor() {}
    print(message) {
        return __Raia__.Core.print(message);
    }
}

// Window
class Window {
    constructor(title, width, height) {
        //__Raia__.Core.print("init");
        var window = __Raia__.App.Window.init(width, height, title);
        //__Raia__.Core.print(window);
        var shader = __Raia__.App.Shader.init(window.width, window.height);
        //this.contextWindow = window.id;
        this.id = window.id;
        this.title = window.title;
        this.resolution_width = window.resolution_width;
        this.resolution_height = window.resolution_height;
        this.vertices = shader.vertices;
        this.indices = shader.indices;
        this.program = shader.program;
        this.pos_location = shader.pos_location;
        this.tex_location = shader.tex_location;
        this.sampler_location = shader.sampler_location;
        this.texture = shader.texture;
        this.pixels = Uint8Array.allocPlain(width * height * 3);
        this.size = {
            width: window.width,
            height: window.height
        }
        this.color = {
            red: 0,
            green: 0,
            blue: 0
        };
        this.position = {
            x: 0,
            y: 0
        }
        this.fps = 60.0;
    }
    //none(f) {__Raia__.Core.print(this.id);}
    onKey(f) {return __Raia__.App.Event.key(this.id, f);} // window, (key, scancode, action, mods)
    onMouse(f) {__Raia__.App.Event.mouse(this.id, f);} // (button, action, mods)
    onWindowPos(f) {__Raia__.App.Event.windowPos(this.id, f);}
    onWindowSize(f) {__Raia__.App.Event.windowSize(this.id, f);}
    onWindowClose(f) {__Raia__.App.Event.windowClose(this.id, f);}
    onWindowRefresh(f) {__Raia__.App.Event.windowRefresh(this.id, f);}
    onWindowFocus(f) {__Raia__.App.Event.windowFocus(this.id, f);}
    onWindowIconify(f) {__Raia__.App.Event.windowIconify(this.id, f);}
    onFrame(f) {__Raia__.App.Event.frame(this.id, f);}
    onCursor(f) {__Raia__.App.Event.cursor(this.id, f);} // (xpos, ypos)
    onChar(f) {__Raia__.App.Event.char(this.id, f);}
    onCharMods(f) {__Raia__.App.Event.charMods(this.id, f);}
    onEnter(f) {__Raia__.App.Event.enter(this.id, f);}
    onScroll(f) {__Raia__.App.Event.scroll(this.id, f);}
    onDrop(f) {__Raia__.App.Event.drop(this.id, f);}
    onUpdate(f, fps = this.fps) {
        var targetFrameDuration = 1.0 / fps;
        while (!__Raia__.App.Window.shouldClose(this.id)) {
            var startTime = __Raia__.App.Time.getCurrentTime();
            f();
            __Raia__.App.Window.pollEvents();
            var endTime = __Raia__.App.Time.getCurrentTime();
            var elapsedTime = endTime - startTime;
            if (elapsedTime < targetFrameDuration) {
                var sleepTime = targetFrameDuration - elapsedTime;
                while (__Raia__.App.Time.getCurrentTime() - startTime < targetFrameDuration) {
                    __Raia__.App.Window.pollEvents();
                }
            }
        }
    }
    setFPS(fps = 60.0) {
        this.fps = fps;
    }
    checkClose() {
        return __Raia__.App.Window.shouldClose(this.id);
    }
    pollEvents() {
        return __Raia__.App.Window.pollEvents();
    }
    waitEventTimeout(timeout) {
        return __Raia__.App.Window.waitEventTimeout(timeout);
    }
    setTitle(title) {
        this.title = title;
        return __Raia__.App.Window.setTitle(this.id, title);
    }
    redraw() {
        return __Raia__.App.Screen.redraw(
            this.vertices,
            this.indices,
            this.program,
            this.pos_location,
            this.tex_location,
            this.sampler_location,
            this.texture,
            this.size.width,
            this.size.height,
            this.resolution_width,
            this.resolution_height,
            this.id,
            this.pixels
        );
    }
    setCurrentColor(red, green, blue) {
        this.color.red = red;
        this.color.green = green;
        this.color.blue = blue;
    }
    drawPoint(posx, posy,
              red = this.color.red,
              green = this.color.green,
              blue = this.color.blue,
              width = this.size.width,
              height = this.size.height) {
        return __Raia__.Draw.point(this.pixels, posx, posy, red, green, blue, width, height);
    }
    drawLine(startx, starty, endx, endy,
             red = this.color.red,
             green = this.color.green,
             blue = this.color.blue,
             width = this.size.width,
             height = this.size.height) {
        return __Raia__.Draw.line(this.pixels, startx, starty, endx, endy, red, green, blue, width, height);
    }
    drawRect(start_x, start_y, end_x, end_y,
             red = this.color.red,
             green = this.color.green,
             blue = this.color.blue,
             width = this.size.width,
             height = this.size.height) {
        __Raia__.Draw.line(this.pixels, start_x, start_y, end_x, start_y, red, green, blue, width, height);
        __Raia__.Draw.line(this.pixels, end_x, start_y, end_x, end_y, red, green, blue, width, height);
        __Raia__.Draw.line(this.pixels, end_x, end_y, start_x, end_y, red, green, blue, width, height);
        __Raia__.Draw.line(this.pixels, start_x, end_y, start_x, start_y, red, green, blue, width, height);
        //return __Raia__.Draw.fillRect(this.pixels, start_x, start_y, end_x, end_y, red, green, blue, width, height);
    }
    drawFilledRect(start_x, start_y, end_x, end_y,
                   red = this.color.red,
                   green = this.color.green,
                   blue = this.color.blue,
                   width = this.size.width,
                   height = this.size.height) {
        return __Raia__.Draw.fillRect(this.pixels, start_x, start_y, end_x, end_y, red, green, blue, width, height);
    }
    drawEllipse(start_x, start_y, end_x, end_y,
                red = this.color.red,
                green = this.color.green,
                blue = this.color.blue,
                width = this.size.width,
                height = this.size.height) {
        return __Raia__.Draw.drawEllipse(this.pixels, start_x, start_y, end_x, end_y, red, green, blue, width, height);
    }
    drawFilledEllipse(start_x, start_y, end_x, end_y,
                      red = this.color.red,
                      green = this.color.green,
                      blue = this.color.blue,
                      width = this.size.width,
                      height = this.size.height) {
        return __Raia__.Draw.drawFilledEllipse(this.pixels, start_x, start_y, end_x, end_y, red, green, blue, width, height);
    }
    blendSurface(surface, pos_x = 0, pos_y = 0, trim_x1 = 0, trim_y1 = 0, trim_x2, trim_y2) {
        trim_x2 = (typeof trim_x2 !== 'undefined') ?  trim_x2 : surface.size.width;
        trim_y2 = (typeof trim_y2 !== 'undefined') ?  trim_y2 : surface.size.height;
        __Raia__.Draw.blendPixelsRGBAtoRGB(
            this.pixels, this.size.width, this.size.height,
            surface.pixels, surface.size.width, surface.size.height,
            pos_x, pos_y,
            trim_x1, trim_y1, trim_x2, trim_y2);
        //__Raia__.Draw.copyPixelsRGBAtoRGB(this.pixels, this.size.width, this.size.height, surface.pixels, surface.size.width, surface.size.height)
    }
    init3D() {
        __Raia__.Draw.d3mInit(this.size.width, this.size.height);
    }
    setCamera(pos_x, pos_y, pos_z, target_x, target_y, target_z) {
        __Raia__.Draw.d3mSetCamera(pos_x, pos_y, pos_z,  target_x, target_y, target_z);
    }
    transform3Dto2D(x, y, z) {
        return __Raia__.Draw.d3mTransform3Dto2D(x, y, z);
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
    drawText(font, text, font_size, color_red = this.color.red, color_green = this.color.green, color_blue = this.color.blue, pos_x = this.position.x, pos_y = this.position.y) {
        font_size = (typeof font_size !== 'undefined') ?  font_size : font.font_size;
        return __Raia__.Draw.drawTextRGB(
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
    drawString(font, str, font_size, color_red = this.color.red, color_green = this.color.green, color_blue = this.color.blue, pos_x = this.position.x, pos_y = this.position.y, wrap_width, wrap_height) {
        font_size = (typeof font_size !== 'undefined') ?  font_size : font.font_size;
        wrap_width = (typeof wrap_width !== 'undefined') ?  wrap_width : this.size.width - pos_x;
        wrap_height = (typeof wrap_height !== 'undefined') ?  wrap_height : this.size.height- pos_y;
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
        __Raia__.Draw.loadImageRGB(
            this.pixels, this.size.width, this.size.height,
            filename,
            pos_x, pos_y,
            trim_x1, trim_y1, trim_x2, trim_y2);
    }
}

class Surface {
    constructor(width, height, pos_x = 0, pos_y = 0) {
        this.pixels = Uint8Array.allocPlain(width * height * 4);
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
    drawFilledRect(start_x, start_y, end_x, end_y,
                   red = this.color.red,
                   green = this.color.green,
                   blue = this.color.blue,
                   alpha = this.color.alpha,
                   width = this.size.width,
                   height = this.size.height) {
        return __Raia__.Draw.fillRectRGBA(this.pixels, start_x, start_y, end_x, end_y, red, green, blue, alpha, width, height);
    }
    blendSurface(surface, pos_x, pos_y, trim_x1, trim_y1, trim_x2, trim_y2) {
        __Raia__.Draw.blendPixelsRGBAtoRGBA(
            this.pixels, this.size.width, this.size.height,
            surface.pixels, surface.size.width, surface.size.height,
            pos_x, pos_y,
            trim_x1, trim_y1, trim_x2, trim_y2);
        //__Raia__.Draw.copyPixelsRGBAtoRGB(this.pixels, this.size.width, this.size.height, surface.pixels, surface.size.width, surface.size.height)
    }
    loadImage(filename, pos_x = 0, pos_y = 0, trim_x1 = 0, trim_y1 = 0, trim_x2 = -1, trim_y2 = -1) {
        __Raia__.Draw.loadImageRGBA(
            this.pixels, this.size.width, this.size.height,
            filename,
            pos_x, pos_y,
            trim_x1, trim_y1, trim_x2, trim_y2);
    }

    drawTextOld(text, font_path, font_size = 12, pos_x = this.position.x, pos_y = this.position.y) {
        __Raia__.Draw.drawTextOld(
            this.pixels, this.size.width, this.size.height,
            text, font_path, font_size,
            pos_x, pos_y);
    }
    drawText(font, text, font_size, color_red = this.color.red, color_green = this.color.green, color_blue = this.color.blue, pos_x = this.position.x, pos_y = this.position.y) {
        font_size = (typeof font_size !== 'undefined') ?  font_size : font.font_size;
        return __Raia__.Draw.drawText(
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
        return __Raia__.Draw.getTextSize(
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
            x += size.width + (font_size / 10);
            if ((x + font_size * 1.2) > wrap_width) {
                x = 3;
                y += font_size;
            }
        }
    }
}

class Font {
    constructor(font_file, font_size) {
        this.font_file = font_file;
        this.font_size = font_size;
        this.font_buffer_length = __Raia__.Draw.openFont(font_file);
        this.font_buffer = Uint8Array.allocPlain(this.font_buffer_length);
        this.font_info = __Raia__.Draw.initFontBuffer(font_file, this.font_buffer);
    }
}

class Event {
    constructor(){}
    onError(f){__Raia__.App.Event.error(f);} // (error, message)
    onGamepad(f){__Raia__.App.Event.joystick(f);}
}

class GLFW {
    constructor(){}
    checkGamepad(num) {
        return __Raia__.App.GLFW.joystickPresent(num);
    }
    getGamepadAxes(num) {
        return __Raia__.App.GLFW.getJoystickAxes(num);
    }
    getGamepadButtons(num) {
        return __Raia__.App.GLFW.getJoystickButtons(num);
    }
    getGamepadName(num) {
        return __Raia__.App.GLFW.getJoystickName(num);
    }
    getTimerValue() {
        return __Raia__.App.GLFW.getTimerValue();
    }
    getTimerFrequency() {
        return __Raia__.App.GLFW.getTimerFrequency();
    }
    getTime() {
        return __Raia__.App.GLFW.getTime();
    }
    setTime(val) {
        return __Raia__.App.GLFW.setTime(val);
    }
}

module.exports = {
    Core: Core,
    Window: Window,
    Surface: Surface,
    Event: Event,
    GLFW: GLFW,
    Font: Font,
};