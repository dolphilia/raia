import {Std} from "raia_std";

// ffi(
//     "func_name", 
//     inout, type, value,
//     ...
// )
//
/*
ffi(
    "add",
    false, "int", 5,
    false, "int", 10
)
*/
let std = new Std();


var handle = __Raia__.Lib.open("libminilib");
__Raia__.Lib.add(handle, "plus");
__Raia__.Lib.add(handle, "minus");
__Raia__.Lib.add(handle, "hello");
__Raia__.Lib.add(handle, "put");
__Raia__.Lib.add(handle, "int_array");
__Raia__.Lib.add(handle, "add_struct");

var ret;

ret = __Raia__.Lib.ffi(
    "plus", // 関数名
    "sint", // 戻り値の型
    [
        ["sint", "x", 100], // 型, 引数名, 値
        ["sint", "y", 200]
    ]
);

std.print("return value:" + ret);

var num_struct = __Raia__.Core.makeStruct(
    [
        ["sint", 1000],
        ["sint", 2000]
    ]
);

var result_value =  __Raia__.Lib.ffi(
    "add_struct", // 関数名
    "sint", // 戻り値の型
    [
        ["struct", "point", num_struct]
    ]
);

std.print("result:"+result_value);

__Raia__.Core.deleteStruct(num_struct);




let int32Array = new Int32Array([1, 2, 3, 4, 5]);
let int32pointer = __Raia__.Core.arrayBufferToPointer(int32Array.buffer);

__Raia__.Lib.ffi(
    "int_array", // 関数名
    "void", // 戻り値の型
    [
        ["pointer", "num", int32pointer], // 型, 引数名, 値
        ["sint", "size", 5]
    ]
);

std.print("---");



ret = __Raia__.Lib.ffi(
    "minus", // 関数名
    "sint", // 戻り値の型
    [
        ["sint", "x", 100], // 型, 引数名, 値
        ["sint", "y", 200] // ...
    ]
);

std.print("return value:" + ret);

ret = __Raia__.Lib.ffi(
    "hello", // 関数名
    "void", // 戻り値の型
    null
);

std.print("return value:" + ret);

ret = __Raia__.Lib.ffi(
    "put", // 関数名
    "void", // 戻り値の型
    [
        ["string", "str", "PutFunction"]
    ]
);

std.print("return value:" + ret);



// segment start_x, start_y, end_x, end_y
// point x, y
// size width, height
// rect x, y, width, height
// vector dx, dy
// 



std.print("NEW");
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

    frame.start();
    frame.imgui.setNextWindowBgAlpha(0.35);
    var flags = 0;
    flags |= frame.imgui.WindowFlags.NoTitleBar;
    flags |= frame.imgui.WindowFlags.NoResize;
    frame.imgui.begin("日本語", null, flags);
    frame.text("フレームレート");
    frame.imgui.separator();
    frame.text(""+frame.imgui.getFramerate());
    frame.imgui.end();
    frame.render();
    //__Raia__.GC.free();
});