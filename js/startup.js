//var str = IO.loadStringFilename('foo/bar.js');
//print(str);
//var __tsc = require('typescriptServices.min');
var tsc = require('tsc');
var Raia = require('raia');
Raia.yeah();
//var mod = require('foo/bar');
//mod.hello();
//adder(2,3);
// sample

var a = 100;
var b = 200;

print(a + b);

const byebye = function(){
  print('byebye');
}

const hello = function(){
  print('hello');
}

callback(byebye);
call();
callback(hello);
call();

// Event.setErrorCallback
// Event.setKeyCallback
// Event.setMouseCallback
// Event.setUpdateCallback

Event.setErrorCallback(function(error, message) {
    print(error);
    print(message);
});

Event.setKeyCallback(function(key, scancode, action, mods) {
    print(key);
    print(scancode);
    print(action);
    print(mods);
});

Event.setUpdateCallback(function() {
    Window.setTitle(px);
    Draw.setColor(0, 255, 0);
    Draw.fillRect(0, 0, 640, 480);
    Draw.setColor(0, 0, 0);
    Draw.fillRect(px, py, px + sx, py + sy);
    px += 5;
    py += 5;
    if ((px + sx) > Window.getWidth()) {
        px = 0;
    }
    if ((py + sy) > Window.getHeight()) {
        py = 0;
    }
    for (var x = 0; x < 640; x++) {
        Draw.setColor(rnd(255), rnd(255), rnd(255));
        Draw.setPixel(x, 10);
    }
});

function rnd(max) {
  return Math.floor(Math.random() * max);
}


if (OS.platform == 'windows') {
    print('windows');
}
if (OS.platform == 'macos') {
    print('macos');
}

var px = 0;
var py = 0;
var sx = 20;
var sy = 20;

STDC.puts("hello");

/*
while(!GLFW.windowShouldClose()) {
    GLFW.poolEvents();
}
*/
