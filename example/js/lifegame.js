"use strict";

var _require = require('raia'),
    Core = _require.Core,
    Event = _require.Event,
    GLFW = _require.GLFW,
    Window = _require.Window;
//var Raia = require('raia_std');


var window = new Window("title", 800, 600); //Raia.initWindow("title", 800, 600);
var event = new Event();
var core = new Core();
var glfw = new GLFW();

function getRandomInt(max) {
    return Math.floor(Math.random() * max);
}

var isStart = false;

event.onError(function (error, message) {
    core.print(error + ":" + message);
});

window.onKey(function (window, key, scancode, action, mods) {
    core.print(window + ":" + key + ":" + scancode + ":" + action + ":" + mods);
});

window.onMouse(function (window, button, action, mods) {
    core.print(window + ":" + button + ":" + action + ":" + mods);
    isStart = true;
});

var canvasWidth = 800;
var canvasHeight = 600;
var cellSize = 10;
var gridWidth = canvasWidth / cellSize;
var gridHeight = canvasHeight / cellSize;

function createGrid() {
    var grid = [];
    for (var i = 0; i < gridHeight; i++) {
        var row = [];
        for (var j = 0; j < gridWidth; j++) {
            row.push(Math.random() > 0.5 ? 1 : 0);
        }
        grid.push(row);
    }
    return grid;
}

function updateGrid(grid) {
    var newGrid = [];
    for (var i = 0; i < gridHeight; i++) {
        var newRow = [];
        for (var j = 0; j < gridWidth; j++) {
            var liveNeighbors = countLiveNeighbors(grid, i, j);
            if (grid[i][j] === 1 && (liveNeighbors === 2 || liveNeighbors === 3)) {
                newRow.push(1);
            } else if (grid[i][j] === 0 && liveNeighbors === 3) {
                newRow.push(1);
            } else {
                newRow.push(0);
            }
        }
        newGrid.push(newRow);
    }
    return newGrid;
}

function countLiveNeighbors(grid, x, y) {
    var count = 0;
    for (var i = -1; i <= 1; i++) {
        for (var j = -1; j <= 1; j++) {
            if (i === 0 && j === 0) continue;
            var newX = x + i;
            var newY = y + j;
            if (newX >= 0 && newX < gridHeight && newY >= 0 && newY < gridWidth && grid[newX][newY] === 1) {
                count++;
            }
        }
    }
    return count;
}

function drawGrid(grid) {
    for (var i = 0; i < gridHeight; i++) {
        for (var j = 0; j < gridWidth; j++) {
            if (grid[i][j] === 1) {
                window.drawFilledRect(j * cellSize, i * cellSize, (j + 1) * cellSize, (i + 1) * cellSize);
            }
        }
    }
}

var grid = createGrid();

window.setTitle("ライフゲーム");

var cnt = 0;
window.onUpdate(function () {
    window.setCurrentColor(0, 0, 0);
    if (isStart === true) {
        window.drawFilledRect(0, 0, 800, 600);
        window.setCurrentColor(255, 255, 255);
        grid = updateGrid(grid);
        drawGrid(grid);
    }
    //window.drawRect(0, 0, 100, 200);
    //window.drawLine(200,200,300,400);
    //window.drawFilledEllipse(400,400,500,550);
    window.redraw();
    window.waitEventTimeout(1.0 / 10.0);
    if (glfw.checkGamepad(0) === true) {
        core.print(glfw.getGamepadAxes(0));
        core.print(glfw.getGamepadButtons(0));
    }
    cnt++;
});