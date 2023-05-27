__Raia__.App = require('raia_app');
__Raia__.Draw = require('raia_draw');

__Raia__.App.Event.update = function(func) {
    while (!__Raia__.App.Window.shouldClose()) {
        func();
        __Raia__.App.Window.pollEvents();
    }
};

var width = 800;
var height = 600;
var name = "title"

__Raia__.App.Window.init(__Raia__.context, width, height, name);
function getRandomInt(max) {
    return Math.floor(Math.random() * max);
}

for(var i = 0; i < width * height * 3; i += 3) {
    raia.setPixels(i, getRandomInt(255));
    raia.setPixels(i + 1, getRandomInt(255));
    raia.setPixels(i + 2, getRandomInt(255));
}

__Raia__.Core.print(__Raia__.context.app.window.width);
__Raia__.Core.print(__Raia__.context.app.window.height);
__Raia__.Core.print(__Raia__.context.app.window.title);

__Raia__.App.Event.key(function(key, scancode, action, mods) {
    __Raia__.Core.print(key + ":" + scancode + ":" + action + ":" + mods);
});

var count = 0;
__Raia__.App.Event.update(function() {
    __Raia__.App.Screen.redraw(__Raia__.context.app.window.pixels);
    __Raia__.App.Window.setTitle(__Raia__.context, "hello" + count);
    if (__Raia__.App.GLFW.joystickPresent(0)===true) {
        //__Raia__.Core.print(__Raia__.App.GLFW.getJoystickAxes(0));
        __Raia__.Core.print(__Raia__.App.GLFW.getJoystickButtons(0));
    }
    count++;
});