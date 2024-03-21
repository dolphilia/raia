
import {Skia} from 'raia_skia';
import {GLFW} from 'raia_glfw';
import {GLES} from 'raia_gles';
import {Std} from "raia_std";

var std = new Std();
var glfw = new GLFW();
var gl = new GLES();

// GLFW を初期化する
glfw.init();
glfw.windowHint(GLFW.CLIENT_API, GLFW.OPENGL_ES_API);
glfw.windowHint(GLFW.CONTEXT_VERSION_MAJOR, 3);
glfw.windowHint(GLFW.CONTEXT_VERSION_MINOR, 0);
glfw.windowHint(GLFW.OPENGL_PROFILE, GLFW.OPENGL_CORE_PROFILE);
glfw.windowHint(GLFW.CONTEXT_CREATION_API, GLFW.EGL_CONTEXT_API);
glfw.setErrorCallbackAlt();
glfw.setJoystickCallbackAlt();

var width = 800;
var height = 600;
var window = glfw.createWindow(width, height, "title");

glfw.makeContextCurrent(window);
glfw.swapInterval(1);

// 頂点データを作成する
var vertices = new Float32Array([
    -1.0, 1.0,  0.0,   // Position 0
    0.0,  0.0,         // TexCoord 0
    -1.0, -1.0, 0.0,   // Position 1
    0.0,  1.0,         // TexCoord 1
    1.0,  -1.0, 0.0,   // Position 2
    1.0,  1.0,         // TexCoord 2
    1.0,  1.0,  0.0,   // Position 3
    1.0,  0.0          // TexCoord 3
]);
var indices = new Uint32Array([0, 1, 2, 0, 2, 3]);
var vbo = gl.genBuffersAlt(1);
var ebo = gl.genBuffersAlt(1);
var vao = gl.genVertexArraysAlt(1);
gl.bindVertexArrayAlt(vao);
gl.bindBufferAlt(GLES.ARRAY_BUFFER, vbo);
gl.bufferDataAlt(GLES.ARRAY_BUFFER, 20 * 4, vertices.buffer, GLES.STATIC_DRAW);
gl.bindBufferAlt(GLES.ELEMENT_ARRAY_BUFFER, ebo);
gl.bufferDataAlt(GLES.ELEMENT_ARRAY_BUFFER, 6 * 4, indices.buffer, GLES.STATIC_DRAW);
gl.vertexAttribPointerAlt(0, 3, GLES.FLOAT, GLES.FALSE, 5 * 4, 0); // x
gl.enableVertexAttribArrayAlt(0);
gl.vertexAttribPointerAlt(1, 2, GLES.FLOAT, GLES.FALSE, 5 * 4, 12); // x
gl.enableVertexAttribArrayAlt(1);
gl.bindVertexArrayAlt(0);
var vs_src = `
    attribute vec4 a_position;
    attribute vec2 a_texCoord;
    varying vec2 v_texCoord;
    void main() {
        gl_Position = a_position;
        v_texCoord = a_texCoord;
    }
`;
var fs_src = `
    precision mediump float;
    varying vec2 v_texCoord;
    uniform sampler2D s_texture;
    void main() {
        gl_FragColor = texture2D(s_texture, v_texCoord);
    }
`;
var vs = gl.createShaderAlt(GLES.VERTEX_SHADER);
gl.shaderSourceAlt(vs, 1, vs_src, null);
gl.compileShaderAlt(vs)
var fs = gl.createShaderAlt(GLES.FRAGMENT_SHADER);
gl.shaderSourceAlt(fs, 1, fs_src, null);
gl.compileShaderAlt(fs);
var program = gl.createProgramAlt();
gl.attachShaderAlt(program, vs);
gl.attachShaderAlt(program, fs);
gl.deleteShaderAlt(vs);
gl.deleteShaderAlt(fs);
gl.linkProgramAlt(program);

var texture = gl.genTexturesAlt(1);
gl.bindTextureAlt(GLES.TEXTURE_2D, texture);

// Skia
var skia = new Skia();
var bitmap = skia.SkBitmap_new();
skia.SkBitmap_allocN32Pixels(bitmap, 800, 600, 0);
var canvas = skia.SkCanvas_new_3(bitmap);
var paint = skia.SkPaint_new();

// 背景を塗りつぶす
skia.SkPaint_setColor(paint, 0xffffffff);
var rect = skia.SkRect_MakeXYWH(0, 0, 800, 600);
skia.SkCanvas_drawRect(canvas, rect, paint);
skia.static_sk_rect_delete(rect);

// 角丸
skia.SkPaint_setColor(paint, 0xffff0000);
skia.SkPaint_setAntiAlias(paint, 1);
var rect2_key = skia.SkRect_MakeXYWH(100, 100, 300, 300); // 矩形の位置とサイズ
var rect2 = skia.static_sk_rect_get_ptr(rect2_key);
skia.SkCanvas_drawRoundRect(canvas, rect2, 10, 10, paint);

skia.static_sk_rect_delete(rect);
skia.static_sk_rect_delete(rect2_key);

var pixels = skia.SkBitmap_getPixels(bitmap);

var w_ptr = std.newPtr(4);
var h_ptr = std.newPtr(4);
glfw.getFramebufferSize(window, w_ptr, h_ptr);
var w = std.ptrToInt(w_ptr);
var h = std.ptrToInt(h_ptr);
std.delPtr(w_ptr);
std.delPtr(h_ptr);

gc();

var uint8 = new Uint8Array(800*600*4);
for(var i = 0; i < 800*600*4; i++) {
    uint8[i] = Math.ceil(Math.random()*255)
}
var pixels = std.bufToPtr(uint8.buffer);

var previousTime = glfw.getTime();
var frameCount = 0;

while(glfw.windowShouldClose(window) === 0) {
    gl.viewport(0, 0, w, h);
    gl.clearColor(1.0, 1.0, 1.0, 1.0);
    gl.clear(GLES.COLOR_BUFFER_BIT);

    for(var i = 0; i < 800*600*4; i++) {
        //     uint8[i] = Math.ceil(Math.random()*255)
    }
    // pixels = std.bufToPtr(uint8.buffer);
    
    gl.pixelStorei(GLES.UNPACK_ALIGNMENT, 1);
    gl.bindTexture(GLES.TEXTURE_2D, texture);
    gl.texImage2D(GLES.TEXTURE_2D, 0, GLES.RGBA, width, height, 0, GLES.RGBA, GLES.UNSIGNED_BYTE, pixels); // uint8.buffer
    gl.texParameteri(GLES.TEXTURE_2D, GLES.TEXTURE_MIN_FILTER, GLES.NEAREST);
    gl.texParameteri(GLES.TEXTURE_2D, GLES.TEXTURE_MAG_FILTER, GLES.NEAREST);
    gl.useProgram(program);
    gl.bindVertexArray(vao);
    gl.drawElements(GLES.TRIANGLES, 6, GLES.UNSIGNED_INT, null);

    // フレームレート
    frameCount++;
    var currentTime = glfw.getTime();
    var elapsedTime = currentTime - previousTime;

    // 1秒ごとにフレームレートを計算して表示
    if (elapsedTime >= 1.0) {
        std.print("FPS: " + (frameCount / elapsedTime));
        previousTime = currentTime;
        frameCount = 0;
    }

    glfw.swapBuffers(window);
    glfw.pollEvents();
}


/*
import {Image} from 'raia_image';
import {Font} from 'raia_font';
import 'raia_gui';
import {Window} from 'raia_window';
import {Frame} from 'raia_frame';
import {Texture} from 'raia_texture';
import {Draw} from 'raia_draw';
var window = new Window("Raia v0.5", 800, 600);
std.print("window.pixels:"+window.pixels);
var draw = new Draw();
var frame = new Frame(window.id);
var texture = new Texture(240, 240);
var image = new Image();
image.loadPngBlendRGB(window.pixels, 800, 600, "bg2.png");
//
draw.lineRGBA(texture.pixels, 240, 240,
    0,0,100,100, 255,255,255,255);
var font = new Font("Mplus1-Regular.ttf", 24);
var font_size = font.drawCharRGBA(texture.pixels, 240, 240, "A", 40, 255, 255, 255, 0, 0);
std.print(font_size.width + ":" + font_size.height);
var version = window.glfw.getVersionString();
std.print("GLFW Version: " + version);

//
//window.pixels = std.ptrToBuf(pixels);
//

window.onUpdate(()=>{
    //window.clear(0.45, 0.55, 0.6, 1.0);
    window.draw();
    // frame.start();
    // frame.imgui.setNextWindowBgAlpha(0.35);
    // var flags = 0;
    // flags |= frame.imgui.WindowFlags.NoTitleBar;
    // flags |= frame.imgui.WindowFlags.NoResize;
    // frame.imgui.begin("日本語", null, flags);
    // frame.text("フレームレート");
    // frame.imgui.separator();
    // frame.text(""+frame.imgui.getFramerate());
    // frame.imgui.end();
    // frame.render();
});
*/