//var str = IO.loadStringFilename('foo/bar.js');
//print(str);
//var __tsc = require('typescriptServices.min');
//var tsc = require('tsc');
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

var block = [
    [1,1,1,1,],
    [1,1,1,1,],
    [1,1,1,1,],
    [1,1,1,1,],
    [1,1,1,1,],
    [1,1,1,1,],
    [1,1,1,1,],
    [1,1,1,1,],
];

var px = 0;
var py = 440;
var sx = 60;
var sy = 4;

var ball_x = 320;
var ball_y = 430;

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

Event.setCursorPositionCallback(function(xpos, ypos) {
    Window.setTitle(Math.floor(xpos)+":"+Math.floor(ypos));
    if (xpos >= 0 && xpos <= (640 - sx)) {
        px = Math.floor(xpos);
    }
    if (ypos >= 0 && ypos <= (480 - sy)) {
        //py = Math.floor(ypos);
    }
    if (xpos < 0) {
        px = 0;
    }
    if (xpos > (640 - sx)) {
        px = 640 - sx;
    }
    if (ypos < 0) {
        //py = 0;
    }
    if (ypos > (480 - sy)) {
        //py = 480 - sy
    }
});

Event.setUpdateCallback(function() {
    Draw.setColor(255, 255, 255);
    Draw.fillRect(0, 0, 640, 480);
    Draw.setColor(0, 0, 0);
    Draw.fillRect(px, py, px + sx, py + sy);
    
    for(var bx = 0; bx < block.length; bx++) {
        for(var by = 0; by < block[bx].length; by++) {
            Draw.setColor(0, 0, 0);
            Draw.fillRect(bx * 60 + 90, by * 60 + 40, bx * 60 + 50 + 90, by * 60 + 50 + 40);
            //print("bx="+bx+":by="+by+"==="+block[bx][by]);
        }
    }
    
    Draw.fillRect(ball_x, ball_y, ball_x + 5, ball_y + 5);
    /*px += 5;
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
    }*/
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

STDC.puts("hello");

/*
while(!GLFW.windowShouldClose()) {
    GLFW.poolEvents();
}
*/
