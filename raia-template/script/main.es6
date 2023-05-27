var {Core, Window, Surface} = require('raia');

var window = new Window("title", 800, 600);
var core = new Core();

window.setTitle("サンプル");

window.onUpdate(function () {
    window.setCurrentColor(0,0,0,255);
    window.drawFilledRect(0,0,800,600);
});
