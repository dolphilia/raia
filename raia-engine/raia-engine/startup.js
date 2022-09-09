// sample

var a = 100;
var b = 200;

print(a + b);

function rnd(max) {
  return Math.floor(Math.random() * max);
}

while(!glfw_window_should_close()) {
    fill_rect_rgb(0,0,100,100, 255,255,0);
    for (var x = 0; x < 640; x++) {
        set_pixel_rgb(x, 10, rnd(255),rnd(255),rnd(255));
    }
    glfw_redraw();
    glfw_pool_events();
}
