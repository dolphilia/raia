'use strict';

var _createClass = function () { function defineProperties(target, props) { for (var i = 0; i < props.length; i++) { var descriptor = props[i]; descriptor.enumerable = descriptor.enumerable || false; descriptor.configurable = true; if ("value" in descriptor) descriptor.writable = true; Object.defineProperty(target, descriptor.key, descriptor); } } return function (Constructor, protoProps, staticProps) { if (protoProps) defineProperties(Constructor.prototype, protoProps); if (staticProps) defineProperties(Constructor, staticProps); return Constructor; }; }();

function _classCallCheck(instance, Constructor) { if (!(instance instanceof Constructor)) { throw new TypeError("Cannot call a class as a function"); } }

__Raia__.App = require('raia_app');
__Raia__.App.init();

__Raia__.Draw = require('raia_draw');
__Raia__.File = require('raia_file');

var File = function () {
    function File() {
        _classCallCheck(this, File);
    }

    _createClass(File, [{
        key: 'exist',
        value: function exist(path) {
            return JSON.parse(__Raia__.File.exist(JSON.stringify({ "path": path, "@return": "string" }))).result;
        }
    }, {
        key: 'loadString',
        value: function loadString(path) {
            return JSON.parse(__Raia__.File.loadString(JSON.stringify({ "path": path, "@return": "string" }))).result;
        }
    }, {
        key: 'saveString',
        value: function saveString(path, data) {
            return JSON.parse(__Raia__.File.saveString(JSON.stringify({ "path": path, "data": data, "@return": "string" }))).result;
        }
    }, {
        key: 'loadBinary',
        value: function loadBinary(path) {
            return __Raia__.File.loadBinary(JSON.stringify({ "path": path, "@return": "pointer" }));
        }
    }, {
        key: 'saveBinary',
        value: function saveBinary(path, data) {
            var size = arguments.length > 2 && arguments[2] !== undefined ? arguments[2] : null;

            return JSON.parse(__Raia__.File.saveBinary(JSON.stringify({ "path": path, "@return": "string" }), data, size)).result;
        }
    }, {
        key: 'getCurPath',
        value: function getCurPath() {
            return JSON.parse(__Raia__.File.getCurPath(JSON.stringify({ "@return": "string" }))).result;
        }
    }, {
        key: 'getDirs',
        value: function getDirs(path) {
            return JSON.parse(__Raia__.File.getDirs(JSON.stringify({ "path": path, "@return": "string" }))).result;
        }
    }, {
        key: 'getDirsAll',
        value: function getDirsAll(path) {
            return JSON.parse(__Raia__.File.getDirsAll(JSON.stringify({ "path": path, "@return": "string" }))).result;
        }
    }]);

    return File;
}();

var Core = function () {
    function Core() {
        _classCallCheck(this, Core);
    }

    _createClass(Core, [{
        key: 'print',
        value: function print(message) {
            return __Raia__.Core.print(message);
        }
    }, {
        key: 'exit',
        value: function exit() {
            var status = arguments.length > 0 && arguments[0] !== undefined ? arguments[0] : 0;

            __Raia__.Core.exit(status);
        }
    }]);

    return Core;
}();

// Window


var Window = function () {
    function Window(title, width, height) {
        _classCallCheck(this, Window);

        var window = __Raia__.App.Window.init(width, height, title);
        var shader = __Raia__.App.Shader.init(window.width, window.height);
        this.id = __Raia__.Core.numberToPointer(window.id);
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
        };
        this.color = {
            red: 0,
            green: 0,
            blue: 0
        };
        this.position = {
            x: 0,
            y: 0
        };
        this.fps = 60.0;
    }

    _createClass(Window, [{
        key: 'onKey',
        value: function onKey(f) {
            return __Raia__.App.Event.key(this.id, f);
        } // window, (key, scancode, action, mods)

    }, {
        key: 'onMouse',
        value: function onMouse(f) {
            __Raia__.App.Event.mouse(this.id, f);
        } // (button, action, mods)

    }, {
        key: 'onWindowPos',
        value: function onWindowPos(f) {
            __Raia__.App.Event.windowPos(this.id, f);
        }
    }, {
        key: 'onWindowSize',
        value: function onWindowSize(f) {
            __Raia__.App.Event.windowSize(this.id, f);
        }
    }, {
        key: 'onWindowClose',
        value: function onWindowClose(f) {
            __Raia__.App.Event.windowClose(this.id, f);
        }
    }, {
        key: 'onWindowRefresh',
        value: function onWindowRefresh(f) {
            __Raia__.App.Event.windowRefresh(this.id, f);
        }
    }, {
        key: 'onWindowFocus',
        value: function onWindowFocus(f) {
            __Raia__.App.Event.windowFocus(this.id, f);
        }
    }, {
        key: 'onWindowIconify',
        value: function onWindowIconify(f) {
            __Raia__.App.Event.windowIconify(this.id, f);
        }
    }, {
        key: 'onFrame',
        value: function onFrame(f) {
            __Raia__.App.Event.frame(this.id, f);
        }
    }, {
        key: 'onCursor',
        value: function onCursor(f) {
            __Raia__.App.Event.cursor(this.id, f);
        } // (xpos, ypos)

    }, {
        key: 'onChar',
        value: function onChar(f) {
            __Raia__.App.Event.char(this.id, f);
        }
    }, {
        key: 'onCharMods',
        value: function onCharMods(f) {
            __Raia__.App.Event.charMods(this.id, f);
        }
    }, {
        key: 'onEnter',
        value: function onEnter(f) {
            __Raia__.App.Event.enter(this.id, f);
        }
    }, {
        key: 'onScroll',
        value: function onScroll(f) {
            __Raia__.App.Event.scroll(this.id, f);
        }
    }, {
        key: 'onDrop',
        value: function onDrop(f) {
            __Raia__.App.Event.drop(this.id, f);
        }
    }, {
        key: 'onUpdate',
        value: function onUpdate(f) {
            var fps = arguments.length > 1 && arguments[1] !== undefined ? arguments[1] : this.fps;

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
    }, {
        key: 'setFPS',
        value: function setFPS() {
            var fps = arguments.length > 0 && arguments[0] !== undefined ? arguments[0] : 60.0;

            this.fps = fps;
        }
    }, {
        key: 'checkClose',
        value: function checkClose() {
            return __Raia__.App.Window.shouldClose(this.id);
        }
    }, {
        key: 'pollEvents',
        value: function pollEvents() {
            return __Raia__.App.Window.pollEvents();
        }
    }, {
        key: 'waitEventTimeout',
        value: function waitEventTimeout(timeout) {
            return __Raia__.App.Window.waitEventTimeout(timeout);
        }
    }, {
        key: 'setTitle',
        value: function setTitle(title) {
            this.title = title;
            return __Raia__.App.Window.setTitle(this.id, title);
        }
    }, {
        key: 'redraw',
        value: function redraw() {
            return __Raia__.App.Window.redraw(this.vertices, this.indices, this.program, this.pos_location, this.tex_location, this.sampler_location, this.texture, this.size.width, this.size.height, this.resolution_width, this.resolution_height, this.id, this.pixels);
        }
    }, {
        key: 'setCurrentColor',
        value: function setCurrentColor(red, green, blue) {
            this.color.red = red;
            this.color.green = green;
            this.color.blue = blue;
        }
    }, {
        key: 'drawPoint',
        value: function drawPoint(posx, posy) {
            var red = arguments.length > 2 && arguments[2] !== undefined ? arguments[2] : this.color.red;
            var green = arguments.length > 3 && arguments[3] !== undefined ? arguments[3] : this.color.green;
            var blue = arguments.length > 4 && arguments[4] !== undefined ? arguments[4] : this.color.blue;
            var width = arguments.length > 5 && arguments[5] !== undefined ? arguments[5] : this.size.width;
            var height = arguments.length > 6 && arguments[6] !== undefined ? arguments[6] : this.size.height;

            return __Raia__.Draw.Shape.pointRGB(this.pixels, posx, posy, red, green, blue, width, height);
        }
    }, {
        key: 'drawLine',
        value: function drawLine(startx, starty, endx, endy) {
            var red = arguments.length > 4 && arguments[4] !== undefined ? arguments[4] : this.color.red;
            var green = arguments.length > 5 && arguments[5] !== undefined ? arguments[5] : this.color.green;
            var blue = arguments.length > 6 && arguments[6] !== undefined ? arguments[6] : this.color.blue;
            var width = arguments.length > 7 && arguments[7] !== undefined ? arguments[7] : this.size.width;
            var height = arguments.length > 8 && arguments[8] !== undefined ? arguments[8] : this.size.height;

            return __Raia__.Draw.Shape.lineRGB(this.pixels, startx, starty, endx, endy, red, green, blue, width, height);
        }
    }, {
        key: 'drawRect',
        value: function drawRect(start_x, start_y, end_x, end_y) {
            var red = arguments.length > 4 && arguments[4] !== undefined ? arguments[4] : this.color.red;
            var green = arguments.length > 5 && arguments[5] !== undefined ? arguments[5] : this.color.green;
            var blue = arguments.length > 6 && arguments[6] !== undefined ? arguments[6] : this.color.blue;
            var width = arguments.length > 7 && arguments[7] !== undefined ? arguments[7] : this.size.width;
            var height = arguments.length > 8 && arguments[8] !== undefined ? arguments[8] : this.size.height;

            __Raia__.Draw.Shape.lineRGB(this.pixels, start_x, start_y, end_x, start_y, red, green, blue, width, height);
            __Raia__.Draw.Shape.lineRGB(this.pixels, end_x, start_y, end_x, end_y, red, green, blue, width, height);
            __Raia__.Draw.Shape.lineRGB(this.pixels, end_x, end_y, start_x, end_y, red, green, blue, width, height);
            __Raia__.Draw.Shape.lineRGB(this.pixels, start_x, end_y, start_x, start_y, red, green, blue, width, height);
        }
    }, {
        key: 'drawFilledRect',
        value: function drawFilledRect(start_x, start_y, end_x, end_y) {
            var red = arguments.length > 4 && arguments[4] !== undefined ? arguments[4] : this.color.red;
            var green = arguments.length > 5 && arguments[5] !== undefined ? arguments[5] : this.color.green;
            var blue = arguments.length > 6 && arguments[6] !== undefined ? arguments[6] : this.color.blue;
            var width = arguments.length > 7 && arguments[7] !== undefined ? arguments[7] : this.size.width;
            var height = arguments.length > 8 && arguments[8] !== undefined ? arguments[8] : this.size.height;

            return __Raia__.Draw.Shape.fillRectRGB(this.pixels, start_x, start_y, end_x, end_y, red, green, blue, width, height);
        }
    }, {
        key: 'drawEllipse',
        value: function drawEllipse(start_x, start_y, end_x, end_y) {
            var red = arguments.length > 4 && arguments[4] !== undefined ? arguments[4] : this.color.red;
            var green = arguments.length > 5 && arguments[5] !== undefined ? arguments[5] : this.color.green;
            var blue = arguments.length > 6 && arguments[6] !== undefined ? arguments[6] : this.color.blue;
            var width = arguments.length > 7 && arguments[7] !== undefined ? arguments[7] : this.size.width;
            var height = arguments.length > 8 && arguments[8] !== undefined ? arguments[8] : this.size.height;

            return __Raia__.Draw.Shape.drawEllipseRGB(this.pixels, start_x, start_y, end_x, end_y, red, green, blue, width, height);
        }
    }, {
        key: 'drawFilledEllipse',
        value: function drawFilledEllipse(start_x, start_y, end_x, end_y) {
            var red = arguments.length > 4 && arguments[4] !== undefined ? arguments[4] : this.color.red;
            var green = arguments.length > 5 && arguments[5] !== undefined ? arguments[5] : this.color.green;
            var blue = arguments.length > 6 && arguments[6] !== undefined ? arguments[6] : this.color.blue;
            var width = arguments.length > 7 && arguments[7] !== undefined ? arguments[7] : this.size.width;
            var height = arguments.length > 8 && arguments[8] !== undefined ? arguments[8] : this.size.height;

            return __Raia__.Draw.Shape.drawFilledEllipseRGB(this.pixels, start_x, start_y, end_x, end_y, red, green, blue, width, height);
        }
    }, {
        key: 'blendSurface',
        value: function blendSurface(surface) {
            var pos_x = arguments.length > 1 && arguments[1] !== undefined ? arguments[1] : 0;
            var pos_y = arguments.length > 2 && arguments[2] !== undefined ? arguments[2] : 0;
            var trim_x1 = arguments.length > 3 && arguments[3] !== undefined ? arguments[3] : 0;
            var trim_y1 = arguments.length > 4 && arguments[4] !== undefined ? arguments[4] : 0;
            var trim_x2 = arguments[5];
            var trim_y2 = arguments[6];

            trim_x2 = typeof trim_x2 !== 'undefined' ? trim_x2 : surface.size.width;
            trim_y2 = typeof trim_y2 !== 'undefined' ? trim_y2 : surface.size.height;
            __Raia__.Draw.Pixel.blendPixelsRGBAtoRGB(this.pixels, this.size.width, this.size.height, surface.pixels, surface.size.width, surface.size.height, pos_x, pos_y, trim_x1, trim_y1, trim_x2, trim_y2);
            //__Raia__.Draw.copyPixelsRGBAtoRGB(this.pixels, this.size.width, this.size.height, surface.pixels, surface.size.width, surface.size.height)
        }
    }, {
        key: 'init3D',
        value: function init3D() {
            __Raia__.Draw.Primitive3D.d3mInit(this.size.width, this.size.height);
        }
    }, {
        key: 'setCamera',
        value: function setCamera(pos_x, pos_y, pos_z, target_x, target_y, target_z) {
            __Raia__.Draw.Primitive3D.d3mSetCamera(pos_x, pos_y, pos_z, target_x, target_y, target_z);
        }
    }, {
        key: 'transform3Dto2D',
        value: function transform3Dto2D(x, y, z) {
            return __Raia__.Draw.Primitive3D.d3mTransform3Dto2D(x, y, z);
        }
    }, {
        key: 'drawPoint3D',
        value: function drawPoint3D(x, y, z) {
            var pos = this.transform3Dto2D(x, y, z);
            this.drawPoint(pos.x, pos.y);
        }
    }, {
        key: 'drawLine3D',
        value: function drawLine3D(x1, y1, z1, x2, y2, z2) {
            var start = this.transform3Dto2D(x1, y1, z1);
            var end = this.transform3Dto2D(x2, y2, z2);
            this.drawLine(start.x, start.y, end.x, end.y);
        }
    }, {
        key: 'drawText',
        value: function drawText(font, text, font_size) {
            var color_red = arguments.length > 3 && arguments[3] !== undefined ? arguments[3] : this.color.red;
            var color_green = arguments.length > 4 && arguments[4] !== undefined ? arguments[4] : this.color.green;
            var color_blue = arguments.length > 5 && arguments[5] !== undefined ? arguments[5] : this.color.blue;
            var pos_x = arguments.length > 6 && arguments[6] !== undefined ? arguments[6] : this.position.x;
            var pos_y = arguments.length > 7 && arguments[7] !== undefined ? arguments[7] : this.position.y;

            font_size = typeof font_size !== 'undefined' ? font_size : font.font_size;
            return __Raia__.Draw.Font.drawTextRGB(this.pixels, // 0
            this.size.width, // 1
            this.size.height, //2
            text, //3
            font_size, //4
            color_red, color_green, color_blue, pos_x, //5
            pos_y, //6
            font.font_buffer, //7
            font.font_info.userdata, //8
            font.font_info.data, //9
            font.font_info.fontstart, //10
            font.font_info.numGlyphs, //11
            font.font_info.loca, //12
            font.font_info.head, //13
            font.font_info.glyf, //14
            font.font_info.hhea, //15
            font.font_info.hmtx, //16
            font.font_info.kern, //17
            font.font_info.gpos, //18
            font.font_info.svg, //19
            font.font_info.index_map, //20
            font.font_info.indexToLocFormat, //21
            font.font_info.cff_data, //22
            font.font_info.cff_cursor, //23
            font.font_info.cff_size, //24
            font.font_info.charstrings_data, //25
            font.font_info.charstrings_cursor, //26
            font.font_info.charstrings_size, //27
            font.font_info.gsubrs_data, //28
            font.font_info.gsubrs_cursor, //29
            font.font_info.gsubrs_size, //30
            font.font_info.subrs_data, //31
            font.font_info.subrs_cursor, //32
            font.font_info.subrs_size, //33
            font.font_info.fontdicts_data, //34
            font.font_info.fontdicts_cursor, //35
            font.font_info.fontdicts_size, //36
            font.font_info.fdselect_data, //37
            font.font_info.fdselect_cursor, //38
            font.font_info.fdselect_size); //39
        }
    }, {
        key: 'drawString',
        value: function drawString(font, str, font_size) {
            var color_red = arguments.length > 3 && arguments[3] !== undefined ? arguments[3] : this.color.red;
            var color_green = arguments.length > 4 && arguments[4] !== undefined ? arguments[4] : this.color.green;
            var color_blue = arguments.length > 5 && arguments[5] !== undefined ? arguments[5] : this.color.blue;
            var pos_x = arguments.length > 6 && arguments[6] !== undefined ? arguments[6] : this.position.x;
            var pos_y = arguments.length > 7 && arguments[7] !== undefined ? arguments[7] : this.position.y;
            var wrap_width = arguments[8];
            var wrap_height = arguments[9];

            font_size = typeof font_size !== 'undefined' ? font_size : font.font_size;
            wrap_width = typeof wrap_width !== 'undefined' ? wrap_width : this.size.width - pos_x;
            wrap_height = typeof wrap_height !== 'undefined' ? wrap_height : this.size.height - pos_y;
            var x = 3;
            var y = 0;
            var line_height = 20;
            for (var i = 0; i < str.length; i++) {
                var size = this.drawText(font, str[i], font_size, color_red, color_green, color_blue, pos_x + x, pos_y + y);
                x += size.width + font_size / 10;
                if (x + font_size * 1.2 > wrap_width) {
                    x = 3;
                    y += font_size;
                }
            }
        }
    }, {
        key: 'loadImage',
        value: function loadImage(filename) {
            var pos_x = arguments.length > 1 && arguments[1] !== undefined ? arguments[1] : 0;
            var pos_y = arguments.length > 2 && arguments[2] !== undefined ? arguments[2] : 0;
            var trim_x1 = arguments.length > 3 && arguments[3] !== undefined ? arguments[3] : 0;
            var trim_y1 = arguments.length > 4 && arguments[4] !== undefined ? arguments[4] : 0;
            var trim_x2 = arguments.length > 5 && arguments[5] !== undefined ? arguments[5] : -1;
            var trim_y2 = arguments.length > 6 && arguments[6] !== undefined ? arguments[6] : -1;

            __Raia__.Draw.Image.loadImageRGB(this.pixels, this.size.width, this.size.height, filename, pos_x, pos_y, trim_x1, trim_y1, trim_x2, trim_y2);
        }
    }]);

    return Window;
}();

var Surface = function () {
    function Surface(width, height) {
        var pos_x = arguments.length > 2 && arguments[2] !== undefined ? arguments[2] : 0;
        var pos_y = arguments.length > 3 && arguments[3] !== undefined ? arguments[3] : 0;

        _classCallCheck(this, Surface);

        this.pixels = Uint8Array.allocPlain(width * height * 4);
        this.size = {
            width: width,
            height: height
        };
        this.color = {
            red: 0,
            green: 0,
            blue: 0,
            alpha: 255
        };
        this.position = {
            x: pos_x,
            y: pos_y
        };
    }

    _createClass(Surface, [{
        key: 'setCurrentColor',
        value: function setCurrentColor(red, green, blue, alpha) {
            this.color.red = red;
            this.color.green = green;
            this.color.blue = blue;
            this.color.alpha = alpha;
        }
    }, {
        key: 'drawPoint',
        value: function drawPoint(posx, posy) {
            var red = arguments.length > 2 && arguments[2] !== undefined ? arguments[2] : this.color.red;
            var green = arguments.length > 3 && arguments[3] !== undefined ? arguments[3] : this.color.green;
            var blue = arguments.length > 4 && arguments[4] !== undefined ? arguments[4] : this.color.blue;
            var alpha = arguments.length > 5 && arguments[5] !== undefined ? arguments[5] : this.color.alpha;
            var width = arguments.length > 6 && arguments[6] !== undefined ? arguments[6] : this.size.width;
            var height = arguments.length > 7 && arguments[7] !== undefined ? arguments[7] : this.size.height;

            return __Raia__.Draw.Shape.pointRGBA(this.pixels, posx, posy, red, green, blue, width, height);
        }
    }, {
        key: 'drawLine',
        value: function drawLine(startx, starty, endx, endy) {
            var red = arguments.length > 4 && arguments[4] !== undefined ? arguments[4] : this.color.red;
            var green = arguments.length > 5 && arguments[5] !== undefined ? arguments[5] : this.color.green;
            var blue = arguments.length > 6 && arguments[6] !== undefined ? arguments[6] : this.color.blue;
            var alpha = arguments.length > 7 && arguments[7] !== undefined ? arguments[7] : this.color.alpha;
            var width = arguments.length > 8 && arguments[8] !== undefined ? arguments[8] : this.size.width;
            var height = arguments.length > 9 && arguments[9] !== undefined ? arguments[9] : this.size.height;

            return __Raia__.Draw.Shape.lineRGBA(this.pixels, startx, starty, endx, endy, red, green, blue, width, height);
        }
    }, {
        key: 'drawRect',
        value: function drawRect(start_x, start_y, end_x, end_y) {
            var red = arguments.length > 4 && arguments[4] !== undefined ? arguments[4] : this.color.red;
            var green = arguments.length > 5 && arguments[5] !== undefined ? arguments[5] : this.color.green;
            var blue = arguments.length > 6 && arguments[6] !== undefined ? arguments[6] : this.color.blue;
            var alpha = arguments.length > 7 && arguments[7] !== undefined ? arguments[7] : this.color.alpha;
            var width = arguments.length > 8 && arguments[8] !== undefined ? arguments[8] : this.size.width;
            var height = arguments.length > 9 && arguments[9] !== undefined ? arguments[9] : this.size.height;

            __Raia__.Draw.Shape.lineRGBA(this.pixels, start_x, start_y, end_x, start_y, red, green, blue, alpha, width, height);
            __Raia__.Draw.Shape.lineRGBA(this.pixels, end_x, start_y, end_x, end_y, red, green, blue, alpha, width, height);
            __Raia__.Draw.Shape.lineRGBA(this.pixels, end_x, end_y, start_x, end_y, red, green, blue, alpha, width, height);
            __Raia__.Draw.Shape.lineRGBA(this.pixels, start_x, end_y, start_x, start_y, red, green, blue, alpha, width, height);
        }
    }, {
        key: 'drawFilledRect',
        value: function drawFilledRect(start_x, start_y, end_x, end_y) {
            var red = arguments.length > 4 && arguments[4] !== undefined ? arguments[4] : this.color.red;
            var green = arguments.length > 5 && arguments[5] !== undefined ? arguments[5] : this.color.green;
            var blue = arguments.length > 6 && arguments[6] !== undefined ? arguments[6] : this.color.blue;
            var alpha = arguments.length > 7 && arguments[7] !== undefined ? arguments[7] : this.color.alpha;
            var width = arguments.length > 8 && arguments[8] !== undefined ? arguments[8] : this.size.width;
            var height = arguments.length > 9 && arguments[9] !== undefined ? arguments[9] : this.size.height;

            return __Raia__.Draw.Shape.fillRectRGBA(this.pixels, start_x, start_y, end_x, end_y, red, green, blue, alpha, width, height);
        }
    }, {
        key: 'drawEllipse',
        value: function drawEllipse(start_x, start_y, end_x, end_y) {
            var red = arguments.length > 4 && arguments[4] !== undefined ? arguments[4] : this.color.red;
            var green = arguments.length > 5 && arguments[5] !== undefined ? arguments[5] : this.color.green;
            var blue = arguments.length > 6 && arguments[6] !== undefined ? arguments[6] : this.color.blue;
            var alpha = arguments.length > 7 && arguments[7] !== undefined ? arguments[7] : this.color.alpha;
            var width = arguments.length > 8 && arguments[8] !== undefined ? arguments[8] : this.size.width;
            var height = arguments.length > 9 && arguments[9] !== undefined ? arguments[9] : this.size.height;

            return __Raia__.Draw.Shape.drawEllipseRGBA(this.pixels, start_x, start_y, end_x, end_y, red, green, blue, alpha, width, height);
        }
    }, {
        key: 'drawFilledEllipse',
        value: function drawFilledEllipse(start_x, start_y, end_x, end_y) {
            var red = arguments.length > 4 && arguments[4] !== undefined ? arguments[4] : this.color.red;
            var green = arguments.length > 5 && arguments[5] !== undefined ? arguments[5] : this.color.green;
            var blue = arguments.length > 6 && arguments[6] !== undefined ? arguments[6] : this.color.blue;
            var alpha = arguments.length > 7 && arguments[7] !== undefined ? arguments[7] : this.color.alpha;
            var width = arguments.length > 8 && arguments[8] !== undefined ? arguments[8] : this.size.width;
            var height = arguments.length > 9 && arguments[9] !== undefined ? arguments[9] : this.size.height;

            return __Raia__.Draw.Shape.drawFilledEllipseRGBA(this.pixels, start_x, start_y, end_x, end_y, red, green, blue, alpha, width, height);
        }
    }, {
        key: 'blendSurface',
        value: function blendSurface(surface, pos_x, pos_y, trim_x1, trim_y1, trim_x2, trim_y2) {
            __Raia__.Draw.Pixel.blendPixelsRGBAtoRGBA(this.pixels, this.size.width, this.size.height, surface.pixels, surface.size.width, surface.size.height, pos_x, pos_y, trim_x1, trim_y1, trim_x2, trim_y2);
            //__Raia__.Draw.copyPixelsRGBAtoRGB(this.pixels, this.size.width, this.size.height, surface.pixels, surface.size.width, surface.size.height)
        }
    }, {
        key: 'loadImage',
        value: function loadImage(filename) {
            var pos_x = arguments.length > 1 && arguments[1] !== undefined ? arguments[1] : 0;
            var pos_y = arguments.length > 2 && arguments[2] !== undefined ? arguments[2] : 0;
            var trim_x1 = arguments.length > 3 && arguments[3] !== undefined ? arguments[3] : 0;
            var trim_y1 = arguments.length > 4 && arguments[4] !== undefined ? arguments[4] : 0;
            var trim_x2 = arguments.length > 5 && arguments[5] !== undefined ? arguments[5] : -1;
            var trim_y2 = arguments.length > 6 && arguments[6] !== undefined ? arguments[6] : -1;

            __Raia__.Draw.Image.loadImageRGBA(this.pixels, this.size.width, this.size.height, filename, pos_x, pos_y, trim_x1, trim_y1, trim_x2, trim_y2);
        }
    }, {
        key: 'drawText',
        value: function drawText(font, text, font_size) {
            var color_red = arguments.length > 3 && arguments[3] !== undefined ? arguments[3] : this.color.red;
            var color_green = arguments.length > 4 && arguments[4] !== undefined ? arguments[4] : this.color.green;
            var color_blue = arguments.length > 5 && arguments[5] !== undefined ? arguments[5] : this.color.blue;
            var pos_x = arguments.length > 6 && arguments[6] !== undefined ? arguments[6] : this.position.x;
            var pos_y = arguments.length > 7 && arguments[7] !== undefined ? arguments[7] : this.position.y;

            font_size = typeof font_size !== 'undefined' ? font_size : font.font_size;
            return __Raia__.Draw.Font.drawTextRGBA(this.pixels, // 0
            this.size.width, // 1
            this.size.height, //2
            text, //3
            font_size, //4
            color_red, color_green, color_blue, pos_x, //5
            pos_y, //6
            font.font_buffer, //7
            font.font_info.userdata, //8
            font.font_info.data, //9
            font.font_info.fontstart, //10
            font.font_info.numGlyphs, //11
            font.font_info.loca, //12
            font.font_info.head, //13
            font.font_info.glyf, //14
            font.font_info.hhea, //15
            font.font_info.hmtx, //16
            font.font_info.kern, //17
            font.font_info.gpos, //18
            font.font_info.svg, //19
            font.font_info.index_map, //20
            font.font_info.indexToLocFormat, //21
            font.font_info.cff_data, //22
            font.font_info.cff_cursor, //23
            font.font_info.cff_size, //24
            font.font_info.charstrings_data, //25
            font.font_info.charstrings_cursor, //26
            font.font_info.charstrings_size, //27
            font.font_info.gsubrs_data, //28
            font.font_info.gsubrs_cursor, //29
            font.font_info.gsubrs_size, //30
            font.font_info.subrs_data, //31
            font.font_info.subrs_cursor, //32
            font.font_info.subrs_size, //33
            font.font_info.fontdicts_data, //34
            font.font_info.fontdicts_cursor, //35
            font.font_info.fontdicts_size, //36
            font.font_info.fdselect_data, //37
            font.font_info.fdselect_cursor, //38
            font.font_info.fdselect_size); //39
        }
    }, {
        key: 'getTextSize',
        value: function getTextSize(font, text, font_size) {
            font_size = typeof font_size !== 'undefined' ? font_size : font.font_size;
            return __Raia__.Draw.Font.getTextSize(text, //3
            font_size, //4
            font.font_info.userdata, //8
            font.font_info.data, //9
            font.font_info.fontstart, //10
            font.font_info.numGlyphs, //11
            font.font_info.loca, //12
            font.font_info.head, //13
            font.font_info.glyf, //14
            font.font_info.hhea, //15
            font.font_info.hmtx, //16
            font.font_info.kern, //17
            font.font_info.gpos, //18
            font.font_info.svg, //19
            font.font_info.index_map, //20
            font.font_info.indexToLocFormat, //21
            font.font_info.cff_data, //22
            font.font_info.cff_cursor, //23
            font.font_info.cff_size, //24
            font.font_info.charstrings_data, //25
            font.font_info.charstrings_cursor, //26
            font.font_info.charstrings_size, //27
            font.font_info.gsubrs_data, //28
            font.font_info.gsubrs_cursor, //29
            font.font_info.gsubrs_size, //30
            font.font_info.subrs_data, //31
            font.font_info.subrs_cursor, //32
            font.font_info.subrs_size, //33
            font.font_info.fontdicts_data, //34
            font.font_info.fontdicts_cursor, //35
            font.font_info.fontdicts_size, //36
            font.font_info.fdselect_data, //37
            font.font_info.fdselect_cursor, //38
            font.font_info.fdselect_size); //39
        }
    }, {
        key: 'drawString',
        value: function drawString(font, str, font_size) {
            var color_red = arguments.length > 3 && arguments[3] !== undefined ? arguments[3] : this.color.red;
            var color_green = arguments.length > 4 && arguments[4] !== undefined ? arguments[4] : this.color.green;
            var color_blue = arguments.length > 5 && arguments[5] !== undefined ? arguments[5] : this.color.blue;
            var pos_x = arguments.length > 6 && arguments[6] !== undefined ? arguments[6] : this.position.x;
            var pos_y = arguments.length > 7 && arguments[7] !== undefined ? arguments[7] : this.position.y;
            var wrap_width = arguments[8];
            var wrap_height = arguments[9];

            font_size = typeof font_size !== 'undefined' ? font_size : font.font_size;
            wrap_width = typeof wrap_width !== 'undefined' ? wrap_width : this.size.width - pos_x;
            wrap_height = typeof wrap_height !== 'undefined' ? wrap_height : this.size.height - pos_y;
            var x = 3;
            var y = 0;
            var line_height = 20;
            for (var i = 0; i < str.length; i++) {
                var size = this.drawText(font, str[i], font_size, color_red, color_green, color_blue, pos_x + x, pos_y + y);
                x += size.width + 2;
                if (x + font_size * 1.2 > wrap_width) {
                    x = 3;
                    y += font_size;
                }
            }
        }
    }]);

    return Surface;
}();

var Font = function Font(font_file) {
    var font_size = arguments.length > 1 && arguments[1] !== undefined ? arguments[1] : 16;

    _classCallCheck(this, Font);

    this.font_file = font_file;
    this.font_size = font_size;
    this.font_buffer_length = __Raia__.Draw.Font.openFont(font_file);
    this.font_buffer = Uint8Array.allocPlain(this.font_buffer_length);
    this.font_info = __Raia__.Draw.Font.initFontBuffer(font_file, this.font_buffer);
};

var Event = function () {
    function Event() {
        _classCallCheck(this, Event);
    }

    _createClass(Event, [{
        key: 'onError',
        value: function onError(f) {
            __Raia__.App.Event.error(f);
        } // (error, message)

    }, {
        key: 'onGamepad',
        value: function onGamepad(f) {
            __Raia__.App.Event.joystick(f);
        }
    }]);

    return Event;
}();

var GLFW = function () {
    function GLFW() {
        _classCallCheck(this, GLFW);
    }

    _createClass(GLFW, [{
        key: 'checkGamepad',
        value: function checkGamepad(num) {
            return __Raia__.App.GLFW.joystickPresent(num);
        }
    }, {
        key: 'getGamepadAxes',
        value: function getGamepadAxes(num) {
            return __Raia__.App.GLFW.getJoystickAxes(num);
        }
    }, {
        key: 'getGamepadButtons',
        value: function getGamepadButtons(num) {
            return __Raia__.App.GLFW.getJoystickButtons(num);
        }
    }, {
        key: 'getGamepadName',
        value: function getGamepadName(num) {
            return __Raia__.App.GLFW.getJoystickName(num);
        }
    }, {
        key: 'getTimerValue',
        value: function getTimerValue() {
            return __Raia__.App.GLFW.getTimerValue();
        }
    }, {
        key: 'getTimerFrequency',
        value: function getTimerFrequency() {
            return __Raia__.App.GLFW.getTimerFrequency();
        }
    }, {
        key: 'getTime',
        value: function getTime() {
            return __Raia__.App.GLFW.getTime();
        }
    }, {
        key: 'setTime',
        value: function setTime(val) {
            return __Raia__.App.GLFW.setTime(val);
        }
    }]);

    return GLFW;
}();

module.exports = {
    Core: Core,
    Window: Window,
    Surface: Surface,
    Event: Event,
    GLFW: GLFW,
    Font: Font,
    File: File
};