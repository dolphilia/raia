// sample

var a = 100;
var b = 200;

print(a + b);

while(!glfw_window_should_close()) {
    for (var x = 0; x < 640; x++) {
        set_pixel(x, 10);
    }
    glfw_redraw();
    glfw_pool_events();
}
