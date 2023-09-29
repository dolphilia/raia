"use strict";

var _require = require('raia'),
    Window = _require.Window,
    Core = _require.Core,
    Surface = _require.Surface,
    Font = _require.Font,
    File = _require.File;

var core = new Core();
var window = new Window("title", 800, 600);
var surface = new Surface(800, 600);
var font = new Font("Mplus1-Regular.ttf", 30);
var file = new File();

window.setTitle("hh");

// __Raia__.Core.Lib.open("library");
// __Raia__.Core.Lib.add("goFunc");
// var r = __Raia__.Core.Lib.call("goFunc", JSON.stringify({"path": "yeah!!!!!!","@return": "string"}) , null, null);
// core.print(r);
//
// __Raia__.Core.Lib.open("mylib");
// __Raia__.Core.Lib.add("my_func");
// var r = __Raia__.Core.Lib.call("my_func", JSON.stringify({"message": "yeah!","@return": "string"}) , null, null);
// core.print(r);
//
//
// __Raia__.Core.Lib.open("plugin_func_hash");
// __Raia__.Core.Lib.add("hello_world");
// __Raia__.Core.Lib.call("hello_world", JSON.stringify({
//     "message": "SUPPER",
//     "array": [0,1,2,3,4,5,6],
//     "@return": "string"}
// ) , null, null);
// __Raia__.Core.Lib.add("bye_world");
// var pointer = __Raia__.Core.Lib.call("bye_world",JSON.stringify({"@return": "pointer"})  , null, null);

// core.print("NowTest:");
// core.print(file.exist("fore.png"));
// core.print(file.loadString("main.js"));
// core.print(file.saveString("test.txt", "hello world!"));
// core.print(file.loadBinary("test.txt"));
// core.print(file.saveBinary("test.bin", window.pixels, null));
// core.print(file.getCurPath());
// core.print(file.getDirs("./"));
// core.print(file.getDirsAll("./"));
// core.print(window.id);
// core.print(__Raia__.App.Time.getCurrentTime());


// window.onKey((window, key, scancode, action, mods) => {
//     core.print("key:" + key + " action:" + action);
// });
//
surface.setCurrentColor(255, 255, 255, 255);
surface.drawFilledRect(0, 0, 300, 300);
surface.setCurrentColor(0, 0, 0, 255);
surface.drawPoint(10, 10);
surface.drawLine(0, 0, 200, 100);
surface.setCurrentColor(255, 255, 0, 255);
surface.drawEllipse(20, 20, 400, 400);
surface.drawFilledEllipse(100, 400, 500, 80);
surface.loadImage("main.png");
surface.setCurrentColor(0, 0, 0, 255);
surface.drawString(font, "Hello", 16);
window.blendSurface(surface);
window.redraw();

__Raia__.Core.entrust("next.js");

window.onUpdate(function () {
    //__Raia__.Core.print(__Raia__.App.Event.getKey());
    //__Raia__.Core.print(__Raia__.App.getFramebufferSize());
    //__Raia__.Core.print(__Raia__.App.getError());
});
// var fps = 60;
// var targetFrameDuration = 1.0 / fps;
// //while (!__Raia__.App.Window.shouldClose(window.id)) {
//     var startTime = __Raia__.App.Time.getCurrentTime();
//     __Raia__.App.Window.pollEvents();
//     // var endTime = __Raia__.App.Time.getCurrentTime();
//     // var elapsedTime = endTime - startTime;
//     // if (elapsedTime < targetFrameDuration) {
//     //     var sleepTime = targetFrameDuration - elapsedTime;
//     //     while (__Raia__.App.Time.getCurrentTime() - startTime < targetFrameDuration) {
//     //         __Raia__.App.Window.pollEvents();
//     //     }
//     // }
// //}

// var {Core, Event, GLFW, Window} = require('raia');
// var window = new Window("title", 800, 600);//Raia.initWindow("title", 800, 600);
// var event = new Event();
// var core = new Core();
// var glfw = new GLFW();
//
// window.setCurrentColor(255,255,0);
// window.drawFilledRect(0,0, 600, 600);
//
// window.onKey((key, action) => {
//     // 何もしない
// });
//
// window.onUpdate(() => {
//     window.redraw();
// });


// function getRandomInt(max) {
//     return Math.floor(Math.random() * max);
// }
//
// var isStart = false;
//
// event.onError((error, message) => {
//     core.print(error + ":" + message);
// });
//
// window.onKey((window, key, scancode, action, mods) => {
//     core.print(window + ":" + key + ":" + scancode + ":" + action + ":" + mods);
// });
//
// window.onMouse((window, button, action, mods) => {
//     core.print(window + ":" + button + ":" + action + ":" + mods);
//     isStart = true;
// });
//
//
// var canvasWidth = 800;
// var canvasHeight = 600;
// var cellSize = 10;
// var gridWidth = canvasWidth / cellSize;
// var gridHeight = canvasHeight / cellSize;
//
// function createGrid() {
//     var grid = [];
//     for (var i = 0; i < gridHeight; i++) {
//         var row = [];
//         for (var j = 0; j < gridWidth; j++) {
//             row.push(Math.random() > 0.5 ? 1 : 0);
//         }
//         grid.push(row);
//     }
//     return grid;
// }
//
// function updateGrid(grid) {
//     var newGrid = [];
//     for (var i = 0; i < gridHeight; i++) {
//         var newRow = [];
//         for (var j = 0; j < gridWidth; j++) {
//             var liveNeighbors = countLiveNeighbors(grid, i, j);
//             if (grid[i][j] === 1 && (liveNeighbors === 2 || liveNeighbors === 3)) {
//                 newRow.push(1);
//             } else if (grid[i][j] === 0 && liveNeighbors === 3) {
//                 newRow.push(1);
//             } else {
//                 newRow.push(0);
//             }
//         }
//         newGrid.push(newRow);
//     }
//     return newGrid;
// }
//
// function countLiveNeighbors(grid, x, y) {
//     var count = 0;
//     for (var i = -1; i <= 1; i++) {
//         for (var j = -1; j <= 1; j++) {
//             if (i === 0 && j === 0) continue;
//             var newX = x + i;
//             var newY = y + j;
//             if (newX >= 0 && newX < gridHeight && newY >= 0 && newY < gridWidth && grid[newX][newY] === 1) {
//                 count++;
//             }
//         }
//     }
//     return count;
// }
//
// function drawGrid(grid) {
//     for (var i = 0; i < gridHeight; i++) {
//         for (var j = 0; j < gridWidth; j++) {
//             if (grid[i][j] === 1) {
//                 window.drawFilledRect(j * cellSize, i * cellSize, (j + 1) * cellSize, (i + 1) * cellSize);
//             }
//         }
//     }
// }
//
// var grid = createGrid();
//
//
// window.setTitle("ライフゲーム");
//
// var cnt = 0;
// window.onUpdate(() => {
//     window.setCurrentColor(0, 0, 0);
//     if (isStart === true) {
//         window.drawFilledRect(0, 0, 800, 600);
//         window.setCurrentColor(255, 255, 255);
//         grid = updateGrid(grid);
//         drawGrid(grid);
//     }
//     //window.drawRect(0, 0, 100, 200);
//     //window.drawLine(200,200,300,400);
//     //window.drawFilledEllipse(400,400,500,550);
//     window.redraw();
//     window.waitEventTimeout(1.0 / 10.0);
//     if (glfw.checkGamepad(0) === true) {
//         core.print(glfw.getGamepadAxes(0));
//         core.print(glfw.getGamepadButtons(0));
//     }
//     cnt++;
// });