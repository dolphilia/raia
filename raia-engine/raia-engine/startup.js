// sample

var a = 100;
var b = 200;

print(a + b);

function rnd(max) {
  return Math.floor(Math.random() * max);
}

var px = 0;
var py = 0;
var sx = 20;
var sy = 20;

while(!glfw_window_should_close()) {
    set_title(px);
    fill_rect_rgb(0,0,640,480, 255,255,255)
    fill_rect_rgb(px, py, px + sx, py + sy, 100,100,100);
    px += 5;
    py += 5;
    if ((px + sx) > 640) {
        px = 0;
    }
    if ((py + sy) > 480) {
        py = 0;
    }
    for (var x = 0; x < 640; x++) {
        set_pixel_rgb(x, 10, rnd(255),rnd(255),rnd(255));
    }
    glfw_redraw();
    glfw_pool_events();
}
