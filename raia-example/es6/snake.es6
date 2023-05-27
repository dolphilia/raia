
var {Core, Window, Surface} = require('raia');

var window = new Window("title", 800, 600);
var core = new Core();

window.setTitle("スネークゲーム");

var canvasWidth = 800;
var canvasHeight = 600;

var snake = [
    { x: 400, y: 300 },
    { x: 380, y: 300 },
    { x: 360, y: 300 },
];

var dx = 20;
var dy = 0;

var food = {
    x: Math.floor(Math.random() * canvasWidth / 20) * 20,
    y: Math.floor(Math.random() * canvasHeight / 20) * 20,
};

function drawSnake() {
    window.setCurrentColor(0, 255, 0);
    snake.forEach(function (segment) {
        window.drawFilledRect(segment.x, segment.y, segment.x + 20, segment.y + 20);
    });
}

function drawFood() {
    window.setCurrentColor(255, 0, 0);
    window.drawFilledRect(food.x, food.y, food.x + 20, food.y + 20);
}

function moveSnake() {
    var head = {
        x: snake[0].x + dx,
        y: snake[0].y + dy,
    };

    snake.unshift(head);

    if (head.x === food.x && head.y === food.y) {
        food.x = Math.floor(Math.random() * canvasWidth / 20) * 20;
        food.y = Math.floor(Math.random() * canvasHeight / 20) * 20;
    } else {
        snake.pop();
    }
}

function checkCollision() {
    var head = snake[0];

    if (head.x < 0 || head.x >= canvasWidth || head.y < 0 || head.y >= canvasHeight) {
        return true;
    }

    for (var i = 1; i < snake.length; i++) {
        var segment = snake[i];
        if (head.x === segment.x && head.y === segment.y) {
            return true;
        }
    }

    return false;
}

window.onKey(function (window, key, scancode, action, mods) {
    core.print(key);
    if (action === 1) {
        if (key === 87 && dy === 0) { // W key
            dx = 0;
            dy = -20;
        } else if (key === 65 && dx === 0) { // A key
            dx = -20;
            dy = 0;
        } else if (key === 83 && dy === 0) { // S key
            dx = 0;
            dy = 20;
        } else if (key === 68 && dx === 0) { // D key
            dx = 20;
            dy = 0;
        }
    }
});

var cnt = 0;
window.onUpdate(function () {
    cnt++;
    if (cnt < 50000) {
        return;
    }
    window.setCurrentColor(0,0,0,255);
    window.drawFilledRect(0,0,800,600);
    moveSnake();

    if (checkCollision()) {
        snake = [
            { x: 400, y: 300 },
            { x: 380, y: 300 },
            { x: 360, y: 300 },
        ];
        dx = 20;
        dy = 0;
    }

    drawSnake();
    drawFood();
    window.redraw();
    cnt = 0;
});

