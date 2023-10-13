import {Std} from "raia_std";



// segment start_x, start_y, end_x, end_y
// point x, y
// size width, height
// rect x, y, width, height
// vector dx, dy
// 


let std = new Std();
std.print("@:"+std.rand(-100.11, 100.323));


import {Image} from 'raia_image';
import {Font} from 'raia_font';
import 'raia_gui';
import {Window} from 'raia_window';
import {Frame} from 'raia_frame'
import {Texture} from 'raia_texture';
import {Draw} from 'raia_draw';

var draw = new Draw();
var window = new Window("Raia v0.5", 800, 600);
var frame = new Frame(window.id);
var texture = new Texture(240, 240);

var image = new Image();
image.loadPngBlendRGB(window.pixels, 800, 600, "bg2.png");
//image.loadJpgBlendRGB(window.pixels, 800, 600, "miga.jpg");
//image.loadPngBlendRGBA(texture.pixels, 240, 240, "miga.png");
//image.loadJpgBlendRGBA(texture.pixels, 240, 240, "miga.jpg");

draw.lineRGBA(texture.pixels, 240, 240,
    0,0,100,100, 255,255,255,255);

var font = new Font("Mplus1-Regular.ttf", 24);
var font_size = font.drawCharRGBA(texture.pixels, 240, 240, "A", 40, 255, 255, 255, 0, 0);
std.print(font_size.width + ":" + font_size.height);



window.onUpdate(()=>{
    window.clear(0.45, 0.55, 0.6, 1.0);
    window.draw();

    //draw.noiseRGB_CPU(window.pixels, 800, 600);

    //window.glfw.setWindowTitle(window.id, "FPS:"+frame.imgui.getFramerate());
    frame.start();
    frame.imgui.setNextWindowBgAlpha(0.35);
    var flags = 0;
        flags |= frame.imgui.WindowFlags.NoTitleBar;
        flags |= frame.imgui.WindowFlags.NoResize;
    frame.imgui.begin("日本語", null, flags);
    //frame.show("日本語", ()=>{
        //frame.imgui.pushStyleColorVec4(0, 1, 1, 1, 1.0);
        frame.text("フレームレート");
        frame.imgui.separator();
        frame.text(""+frame.imgui.getFramerate());
        //frame.imgui.popStyleColor();
        //frame.drawImage(texture);
    //});
    frame.imgui.end();
    frame.render();
});