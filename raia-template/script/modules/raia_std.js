__Raia__.App = require('raia_app');
__Raia__.Draw = require('raia_draw');

// init surface
__Raia__.context.current = {
    monitor: 0,
    window: 0,
    surface: 0,
    position: {
        x: 0,
        y: 0
    },
    size: {
        width: 0,
        height: 0,
    },
    color: {
        red: 0,
        green: 0,
        blue: 0,
        alpha: 255
    }
};

__Raia__.context.window = [{
    title: "",
    pixels: 0,
    position: {
        x: 0,
        y: 0
    },
    size: {
        width: 0,
        height: 0
    }
}];

__Raia__.context.surface = [{
    pixels: 0,
    position: {
        x: 0,
        y: 0
    },
    size: {
        width: 0,
        height: 0
    }
}];

// メインループ用のコールバック
__Raia__.App.Event.onUpdate = function(func) {
    while (!__Raia__.App.Window.shouldClose()) {
        func();
        __Raia__.App.Window.pollEvents();
    }
};

module.exports = {
    // context
    context: __Raia__.context,
    getPixels:
        function() {
            return __Raia__.context.window[0].pixels;
        },
    setPixels:
        function(index, num) {
            __Raia__.context.window[0].pixels[index] = num;
        },

    // Core
    print:
        function(message) {
            return __Raia__.Core.print(message);
        },
    // App
    // Window
    initWindow:
        function(width, height, title) {
            __Raia__.context.window = [{
                title: title,
                pixels: Uint8Array.allocPlain(width * height * 3),
                position: {
                    x: 0,
                    y: 0
                },
                size: {
                    width: width,
                    height: height
                }
            }];
            return __Raia__.App.Window.init(width, height, title);
        },
    setWindowTitle:
        function(title) {
            __Raia__.context.window[0].title = title;
            return __Raia__.App.Window.setTitle(title);
        },
    checkWindowClose:
        function() {
            return __Raia__.App.Window.shouldClose();
        },
    pollEvents:
        function() {
            return __Raia__.App.Window.pollEvents();
        },
    // Screen
    initScreenPixels:
        function() {
            return __Raia__.App.Screen.init();
        },
    setScreenPixels:
        function(pixels) {
            return __Raia__.App.Screen.setPixels(pixels);
        },
    redrawScreen:
        function(pixels) {
            return __Raia__.App.Screen.redraw(pixels);
        },
    // Event
    onKey: __Raia__.App.Event.key, // (key, scancode, action, mods)
    onError: __Raia__.App.Event.error, // (error, message)
    onCursor: __Raia__.App.Event.cursor, // (xpos, ypos)
    onMouse: __Raia__.App.Event.mouse, // (button, action, mods)
    onChar: __Raia__.App.Event.char,
    onEnter: __Raia__.App.Event.enter,
    onScroll: __Raia__.App.Event.scroll,
    onGamepad: __Raia__.App.Event.joystick,
    onDrop: __Raia__.App.Event.drop,
    onUpdate: __Raia__.App.Event.onUpdate,
    // GLFW
    checkGamepad:
        function(num) {
            return __Raia__.App.GLFW.joystickPresent(num);
        },
    getGamepadAxes:
        function(num) {
            return __Raia__.App.GLFW.getJoystickAxes(num);
        },
    getGamepadButtons:
        function(num) {
            return __Raia__.App.GLFW.getJoystickButtons(num);
        },
    getGamepadName:
        function(num) {
            return __Raia_App.GLFW.getJoystickName(num);
        },
    // Draw
    pushSurface:
        function(pixels, posx, posy, width, height) {
            __Raia__.context.surface.push({
                pixels: pixels,
                position: {
                    x: posx,
                    y: posy
                },
                size: {
                    width: width,
                    height: height
                }
            });
        },
    popSurface:
        function() {
            __Raia__.context.surface.pop();
        },
    unshiftSurface:
        function(pixels, posx, posy, width, height) {
            __Raia__.context.surface.unshift({
                pixels: pixels,
                position: {
                    x: posx,
                    y: posy
                },
                size: {
                    width: width,
                    height: height
                }
            });
        },
    shiftSurface:
        function() {
            __Raia__.context.surface.shift();
        },
    rewriteSurface:
        function(index, pixels, posx, posy, width, height) {
            __Raia__.context.surface[index].pixels = pixels;
            __Raia__.context.surface[index].position.x = posx;
            __Raia__.context.surface[index].position.y = posy;
            __Raia__.context.surface[index].size.width = width;
            __Raia__.context.surface[index].size.height = height;
        },
    drawNoise:
        function(pixels, width, height) {
            return __Raia__.Draw.noise(pixels, width, height);
        },
    drawPoint:
        function(pixels, posx, posy, red, green, blue, width, height) {
            return __Raia__.Draw.point(pixels, posx, posy, red, green, blue, width, height);
        },
    drawPointAlpha:
        function(pixels, posx, posy, red, green, blue, alpha, width, height) {
            return __Raia__.Draw.point(pixels, posx, posy, red, green, blue, alpha, width, height);
        },
    drawLine:
        function(pixels, startx, starty, endx, endy, red, gree, blue, width, height) {
            return __Raia__.Draw.line(pixels, startx, starty, endx, endy, red, gree, blue, width, height);
        },
    drawRect:
        function(pixels, startx, starty, endx, endy, red, gree, blue, width, height) {
            return __Raia__.Draw.fillRect(pixels, startx, starty, endx, endy, red, gree, blue, width, height);
        },
    drawRectFast:
        function(pixels, startx, starty, endx, endy, red, gree, blue, width, height) {
            return __Raia__.Draw.fillRectFast(pixels, startx, starty, endx, endy, red, gree, blue, width, height);
        },
    drawRectAlpha:
        function(pixels, startx, starty, endx, endy, red, gree, blue, alpha, width, height) {
            return __Raia__.Draw.fillRectAlpha(pixels, startx, starty, endx, endy, red, gree, blue, alpha, width, height);
        },
    drawEllipse:
        function(pixels, startx, starty, endx, endy, red, gree, blue, width, height) {
            return __Raia__.Draw.drawEllipse(pixels, startx, starty, endx, endy, red, gree, blue, width, height);
        },
    drawFilledEllipse:
        function(pixels, startx, starty, endx, endy, red, gree, blue, width, height) {
            return __Raia__.Draw.drawFilledEllipse(pixels, startx, starty, endx, endy, red, gree, blue, width, height);
        },
    drawFilledEllipseSmooth:
        function(pixels, startx, starty, endx, endy, red, gree, blue, width, height) {
            return __Raia__.Draw.drawFilledEllipseSmooth(pixels, startx, starty, endx, endy, red, gree, blue, width, height);
        },
    drawCircle:
        function(pixels, startx, starty, endx, endy, red, gree, blue, width, height) {
            return __Raia__.Draw.fillCircle(pixels, startx, starty, endx, endy, red, gree, blue, width, height);
        },
    loadImage:
        function(pixels, posx, posy, width, height, filename) {
            return __Raia__.Draw.loadImage(pixels, posx, posy, width, height, filename);
        },
    changeCurrentPosition:
        function(x, y) {
            if (typeof x === 'undefined') {
                x = 0;
            }
            if (typeof y === 'undefined') {
                y = 0;
            }
            __Raia__.context.current.position.x = x;
            __Raia__.context.current.position.y = y;
        },
    changeCurrentColor:
        function(red, green, blue, alpha) {
            if (typeof red === 'undefined') {
                red = 0;
            }
            if (typeof green === 'undefined') {
                green = 0;
            }
            if (typeof blue === 'undefined') {
                blue = 0;
            }
            if (typeof alpha === 'undefined') {
                alpha = 255;
            }
            __Raia__.context.current.color.red = red;
            __Raia__.context.current.color.green = green;
            __Raia__.context.current.color.blue = blue;
            __Raia__.context.current.color.alpha = alpha;
        },
    changeCurrentSize:
        function(width, height) {
            if (typeof width === 'undefined') {
                width = 0;
            }
            if (typeof height === 'undefined') {
                height = 0;
            }
            __Raia__.context.current.size.width = width;
            __Raia__.context.current.size.height = height;
        },
    changeCurrentSurface:
        function(index) {
            if (typeof index === 'undefined') {
                index = 0;
            }
            __Raia__.context.current.surface = index;
        },
};