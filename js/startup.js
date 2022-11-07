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
STDC.dlopen("foo.dylib");
STDC.dlsym("foo", "fooooo", 0);

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

var game_scene = 0; // 0 = タイトル画面, 1 = ゲーム中, 2 = ゲームオーバー
Window.setTitle("Click to start");

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

var bar_pos_x = 0;
var bar_pos_y = 440;
var bar_size_x = 60;
var bar_size_y = 4;

var ball_pos_x = 320;
var ball_pos_y = 430;
var ball_speed = 3;
var ball_direction_x = true;
var ball_direction_y = false;

var game_score = 0;

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
    if (xpos >= 0 && xpos <= (640 - bar_size_x)) {
        bar_pos_x = Math.floor(xpos);
    }
    if (ypos >= 0 && ypos <= (480 - bar_size_y)) {
        //bar_pos_y = Math.floor(ypos);
    }
    if (xpos < 0) {
        bar_pos_x = 0;
    }
    if (xpos > (640 - bar_size_x)) {
        bar_pos_x = 640 - bar_size_x;
    }
    if (ypos < 0) {
        //bar_pos_y = 0;
    }
    if (ypos > (480 - bar_size_y)) {
        //bar_pos_y = 480 - bar_size_y
    }
});

Event.setMouseButtonCallback(function(button, action, mods) {
    print("button"+button);
    print("action"+action);
    print("mods"+mods);
    if (game_scene === 1) { //ゲームが進行中の場合はクリック処理をしない
        return;
    }
    if (button === 0 && action === 1) {
        game_scene = game_scene + 1;
        if (game_scene >= 3) {
            game_scene = 1;
            game_score = 0;
            ball_pos_x = 320;
            ball_pos_y = 430;
            block = [
                [1,1,1,1,],
                [1,1,1,1,],
                [1,1,1,1,],
                [1,1,1,1,],
                [1,1,1,1,],
                [1,1,1,1,],
                [1,1,1,1,],
                [1,1,1,1,],
            ];
        }
    }
});

Event.setUpdateCallback(function() {
    Draw.setColor(255, 255, 255);
    Draw.fillRect(0, 0, 640, 480);
    Draw.setColor(0, 0, 0);
    Draw.fillRect(bar_pos_x, bar_pos_y, bar_pos_x + bar_size_x, bar_pos_y + bar_size_y);
    for(var block_x = 0; block_x < block.length; block_x++) {
        for(var block_y = 0; block_y < block[block_x].length; block_y++) {
            if (block[block_x][block_y] === 0) {
                continue;
            }
            Draw.setColor(0, 0, 0);
            var block_margin_left = 90;
            var block_margin_top = 40;
            var block_size_x = 50;
            var block_size_y = 50;
            var block_space_right = 10;
            var block_space_bottom = 10;
            var block_total_size_x = block_size_x + block_space_right;
            var block_total_size_y = block_size_y + block_space_bottom;
            Draw.fillRect(block_x * block_total_size_x + block_margin_left,
                          block_y * block_total_size_y + block_margin_top,
                          block_x * block_total_size_x + block_size_x + block_margin_left,
                          block_y * block_total_size_y + block_size_y + block_margin_top);
        }
    }
    
    Draw.fillRect(ball_pos_x, ball_pos_y, ball_pos_x + 5, ball_pos_y + 5);
    
    if (game_scene != 1) {
        return;
    }
    
    Window.setTitle("Score:" + game_score);
    
    if (ball_direction_x === true) {
        ball_pos_x = ball_pos_x + ball_speed;
    } else {
        ball_pos_x = ball_pos_x - ball_speed;
    }
    if (ball_direction_y === true) {
        ball_pos_y = ball_pos_y + ball_speed;
    } else {
        ball_pos_y = ball_pos_y - ball_speed;
    }
    
    // ボールの壁判定
    if (ball_pos_x > 640) {
        ball_direction_x = false;
    }
    if (ball_pos_x < 0) {
        ball_direction_x = true;
    }
    if (ball_pos_y > 480) { // ゲームオーバー
        ball_direction_x = true;
        ball_direction_y = false;
        game_scene = 2;
        Window.setTitle("game over. score:"+ game_score);
        return;
    }
    if (ball_pos_y < 0) {
        ball_direction_y = true;
    }
    
    // バーの跳ね返り判定
    if (ball_pos_x > bar_pos_x &&
        ball_pos_x < bar_pos_x + bar_size_x &&
        ball_pos_y > bar_pos_y &&
        ball_pos_y < bar_pos_y + bar_size_y) {
        ball_direction_y = !ball_direction_y;
    }
    
    // ブロックの当たり判定
    for(var block_x = 0; block_x < block.length; block_x++) {
        for(var block_y = 0; block_y < block[block_x].length; block_y++) {
            if (block[block_x][block_y] === 0) {
                continue;
            }
            var block_margin_left = 90;
            var block_margin_top = 40;
            var block_size_x = 50;
            var block_size_y = 50;
            var block_space_right = 10;
            var block_space_bottom = 10;
            var block_total_size_x = block_size_x + block_space_right;
            var block_total_size_y = block_size_y + block_space_bottom;
            var x1 = ((block_x * block_total_size_x) + block_margin_left);
            var x2 = ((block_x * block_total_size_x) + block_size_x + block_margin_left);
            var y1 = ((block_y * block_total_size_y) + block_margin_top);
            var y2 = ((block_y * block_total_size_y) + block_size_y + block_margin_top);
            if (ball_pos_x > x1 &&
                ball_pos_x < x2 &&
                ball_pos_y > y1 &&
                ball_pos_y < y2) {
                
                block[block_x][block_y] = 0;
                game_score = game_score + 100;
                // 側面と上下面、どちらに当たったか
                if (ball_direction_x === true && ball_direction_y === true) { //右下に進んでいる
                    if (ball_pos_x - x1 < ball_pos_y - y1) { // 側面に当たった
                        ball_direction_x = !ball_direction_x;
                    } else {
                        ball_direction_y = !ball_direction_y;
                    }
                    continue;
                }
                if (ball_direction_x === true && ball_direction_y === false) { //右上に進んでいる
                    if (ball_pos_x - x1 < y2 - ball_pos_y) { // 側面に当たった
                        ball_direction_x = !ball_direction_x;
                    } else {
                        ball_direction_y = !ball_direction_y;
                    }
                    continue;
                }
                if (ball_direction_x === false && ball_direction_y === false) { //左上に進んでいる
                    if (x2 - ball_pos_x < y2 - ball_pos_y) { // 側面に当たった
                        ball_direction_x = !ball_direction_x;
                    } else {
                        ball_direction_y = !ball_direction_y;
                    }
                    continue;
                }
                if (ball_direction_x === false && ball_direction_y === true) { //左下に進んでいる
                    if (x2 - ball_pos_x < ball_pos_y - y1) { // 側面に当たった
                        ball_direction_x = !ball_direction_x;
                    } else {
                        ball_direction_y = !ball_direction_y;
                    }
                    continue;
                }
            }
        }
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

STDC.puts("hello");

/*
while(!GLFW.windowShouldClose()) {
    GLFW.poolEvents();
}
*/
