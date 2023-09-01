import "raia_std"

function rand(min, max) {
    return Math.floor(Math.random() * (max - min + 1)) + min;
}

//
// var arr = new ArrayBuffer(100);
// var view = new Uint8Array(arr);
// for (var i = 0; i < view.length; i++) {
//     view[i] = 128;
// }
// print(arr);
// var ptr = __Raia__.Core.arrayBufferToPointer(arr);
// var arr2 = __Raia__.Core.pointerToArrayBuffer(ptr, 100);
// var view2 = new Uint8Array(arr2);
// print(arr2);
// print(view2[0]);
// print(ptr);
// print("Hello");
//
// print("End World");
//
// import {File} from 'raia_file';
// var file = new File();
// print(file.exist("config.json"));
//
// import {Window} from "raia_window";
// var window = new Window("Title", 300, 200);
//
// var getRandom =( min, max ) => {
//     var random = Math.floor( Math.random() * (max + 1 - min) ) + min;
//     return random;
// }
//
// import {Font} from "raia_font";
// var font = new Font("Mplus1-Regular.ttf");
// print(font.font_size);
//
// function randomAlphabet(length) {
//     let result = '';
//     let characters = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ';
//     let charactersLength = characters.length;
//     for (let i = 0; i < length; i++ ) {
//         result += characters.charAt(Math.floor(Math.random() * charactersLength));
//     }
//     return result;
// }
//
// import {Surface} from "raia_surface";
// var surface = new Surface(300,200);
//
// surface.loadImage("miga.png");
//
//
// window.onUpdate(() => {
//     window.setCurrentColor(0,0,0);
//     window.drawFilledRect(0,0,300,200);
//     window.setCurrentColor(255,255,255);
//     window.drawString(font, randomAlphabet(20), 20);
//     for (var i = 0; i < 100; i++) {
//         window.drawLine(getRandom(0,300),getRandom(0,200), getRandom(0,300),getRandom(0,200));
//     }
//     window.blendSurface(surface, 10, 20);
//     window.redraw();
// }, 60);
//
// while(window.app.shouldClose() == 0) {
//      window.app.redraw();
//      window.app.pollEvents();
// }

import {GLES} from 'raia_gles';
import {GLFW} from 'raia_glfw';
import {ImGui} from 'raia_imgui';

var gles = new GLES();
var glfw = new GLFW();
var imgui = new ImGui();

glfw.init();
glfw.windowHint(GLFW.CLIENT_API, GLFW.OPENGL_ES_API);
glfw.windowHint(GLFW.CONTEXT_VERSION_MAJOR, 3);
glfw.windowHint(GLFW.CONTEXT_VERSION_MINOR, 0);
glfw.windowHint(GLFW.OPENGL_PROFILE, GLFW.OPENGL_CORE_PROFILE);
glfw.windowHint(GLFW.CONTEXT_CREATION_API, GLFW.EGL_CONTEXT_API);
glfw.setErrorCallback();
glfw.setJoystickCallback();
var window = glfw.createWindow(800, 600, "title");
if(window === null) {
    print("Window creation failed.");
    glfw.terminate();
    exit(1);
}
glfw.makeContextCurrent(window);
glfw.swapInterval(1);
var res_size = glfw.getFramebufferSize(window);
var res_width = res_size.width;
var res_height = res_size.height;

glfw.setKeyCallback(window);
glfw.setFramebufferSizeCallback(window);
glfw.setWindowPosCallback(window);
glfw.setWindowSizeCallback(window);
glfw.setWindowCloseCallback(window);
glfw.setWindowRefreshCallback(window);
glfw.setWindowFocusCallback(window);
glfw.setWindowIconifyCallback(window);
glfw.setCursorPosCallback(window);
glfw.setMouseButtonCallback(window);
glfw.setCharCallback(window);
glfw.setCharModsCallback(window);
glfw.setCorsorEnterCallback(window);
glfw.setScrollCallback(window);
glfw.setDropCallback(window);

imgui.checkVersion();
imgui.createContext();
var config_flags = 0;
config_flags |= ImGui.ConfigFlags.NavEnableKeyboard;
config_flags |= ImGui.ConfigFlags.NavEnableGamepad;
config_flags |= ImGui.ConfigFlags.DockingEnable;
config_flags |= ImGui.ConfigFlags.ViewportsEnable;
imgui.setConfigFlags(config_flags);

imgui.styleColorsDark();
imgui.setStyleWindowBorderSize(0.5);
imgui.setStyleWindowRounding(3.5);
imgui.setStyleColors(ImGui.Col.WindowBg, 0, 0, 0, 0.8);
imgui.setStyleColors(ImGui.Col.Text, 1,1,1,1);
imgui.setStyleColors(ImGui.Col.TitleBg, 0, 0, 0, 1);
imgui.setStyleColors(ImGui.Col.Border, 0, 0, 0, 1);
imgui.implGlfwInitForOpenGL(window, true);
imgui.implOpenGL3Init("#version 300 es");

imgui.addFontDefault();
var glyph_ranges_japanese = imgui.getGlyphRangesJapanese();
var font = imgui.addFontFromFileTTF("./Mplus1-Regular.ttf", 18, null, glyph_ranges_japanese);

imgui.setFontDefault(font);

// GLES
var vertices = new Float32Array([
    -1.0, 1.0,  0.0,  // Position 0
    0.0,  0.0,         // TexCoord 0
    -1.0, -1.0, 0.0,  // Position 1
    0.0,  1.0,         // TexCoord 1
    1.0,  -1.0, 0.0,  // Position 2
    1.0,  1.0,         // TexCoord 2
    1.0,  1.0,  0.0,  // Position 3
    1.0,  0.0          // TexCoord 3
]);
var indices = new Uint32Array([0, 1, 2, 0, 2, 3]);
var vao = gles.genVertexArrays(1);
var vbo = gles.genBuffers(1);
var ebo = gles.genBuffers(1);

gles.bindVertexArray(vao);
gles.bindBuffer(GLES.ARRAY_BUFFER, vbo);
gles.bufferData(GLES.ARRAY_BUFFER, 20 * 4, vertices.buffer, GLES.STATIC_DRAW);
gles.bindBuffer(GLES.ELEMENT_ARRAY_BUFFER, ebo);
gles.bufferData(GLES.ELEMENT_ARRAY_BUFFER, 6 * 4, indices.buffer, GLES.STATIC_DRAW);
gles.vertexAttribPointer(0, 3, GLES.FLOAT, GLES.FALSE, 5 * 4, 0); // x
gles.enableVertexAttribArray(0);
gles.vertexAttribPointer(1, 2, GLES.FLOAT, GLES.FALSE, 5 * 4, 0); // x
gles.enableVertexAttribArray(1);
gles.bindVertexArray(0);

// shader
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

var vs = gles.createShader(GLES.VERTEX_SHADER);
gles.shaderSource(vs, 1, vs_src, null);
gles.compileShader(vs);

var fs = gles.createShader(GLES.FRAGMENT_SHADER);
gles.shaderSource(fs, 1, fs_src, null);
gles.compileShader(fs);

var program = gles.createProgram();
gles.attachShader(program, vs);
gles.attachShader(program, fs);
gles.linkProgram(program);
gles.deleteShader(vs);
gles.deleteShader(fs);

var pixels = new ArrayBuffer(800 * 600 * 3);
var view = new Uint8Array(pixels);
for(var i = 0; i < 800 * 600 * 3; i++) {
    view[i] = rand(200, 255);
}
var texture_id = gles.genTextures(1);
//var nul = new Uint8Array([0]);

var width_frame = 300;
var height_frame = 200;
var pixels_frame = new ArrayBuffer(width_frame * height_frame * 4);
var view_frame = new Uint8Array(pixels_frame);
for(var i = 0; i < width_frame * height_frame * 4; i++) {
    view_frame[i] = rand(0, 255);
}
var texture_id_frame = gles.genTextures(1);

var count = 0;
var check = true;
var slider = 0.0;
var red = 0;
var green = 0;
var blue = 0;
while(glfw.windowShouldClose(window) === 0) {
    imgui.implOpenGL3NewFrame();
    imgui.implGlfwNewFrame();
    imgui.newFrame();
    //print("getTimerValue: " + glfw.getTimerValue());
    //print("getTimerFrequency: " + glfw.getTimerFrequency());
    //print("getTime: " + glfw.getTime());
    //print("joystickPresent: " + glfw.joystickPresent(0));
    glfw.setWindowTitle(window, "" + glfw.getCursorPosCallback().xpos + ":" + glfw.getCursorPosCallback().ypos);
    var frame_buffer_size = glfw.getFramebufferSize(window);
    gles.viewport(0, 0, frame_buffer_size.width, frame_buffer_size.height);
    gles.clearColor(0.45, 0.55, 0.6, 1.0);
    gles.clear(GLES.COLOR_BUFFER_BIT);
    //for(var i = 0; i < pixels.byteLength; i++) {
    //    view[i] = rand(0, 255);
    //}

    imgui.begin("Hello");
    check = imgui.checkbox("Check", check);
    slider = imgui.sliderFloat("Slider", slider, 0, 1);
    var col = imgui.colorEdit3("Color", red, green, blue);
    red = col.red;
    green = col.green;
    blue = col.blue;
    imgui.sameLine();
    if(imgui.button("OK")) {
        count++;
    }
    imgui.text("OK!" + imgui.getFramerate());
    imgui.end();

    //
    //gles.draw(__Raia__.Core.arrayBufferToPointer(pixels), t.program, t.vao);

    gles.bindTexture(GLES.TEXTURE_2D, texture_id_frame);
    gles.texImage2D(GLES.TEXTURE_2D, 0, GLES.RGBA, width_frame, height_frame, 0, GLES.RGBA, GLES.UNSIGNED_BYTE, pixels_frame);
    gles.texParameteri(GLES.TEXTURE_2D, GLES.TEXTURE_MIN_FILTER, GLES.LINEAR);
    gles.texParameteri(GLES.TEXTURE_2D, GLES.TEXTURE_MAG_FILTER, GLES.LINEAR);
    //gles.bindTexture(GLES.TEXTURE_2D, 1);
    imgui.begin("Image");
    imgui.image(texture_id_frame, width_frame, height_frame);
    imgui.end();


    // Draw the texture
    gles.bindTexture(GLES.TEXTURE_2D, texture_id);
    gles.texImage2D(GLES.TEXTURE_2D, 0, GLES.RGB, 800, 600, 0, GLES.RGB, GLES.UNSIGNED_BYTE, pixels);
    gles.texParameteri(GLES.TEXTURE_2D, GLES.TEXTURE_MIN_FILTER, GLES.NEAREST);
    gles.texParameteri(GLES.TEXTURE_2D, GLES.TEXTURE_MAG_FILTER, GLES.NEAREST);
    gles.useProgram(program);
    gles.bindVertexArray(vao);
    gles.drawElements(GLES.TRIANGLES, 6, GLES.UNSIGNED_INT, null);
    //gles.bindTexture(GLES.TEXTURE_2D, 1);

    imgui.render();
    var draw_data = imgui.getDrawData();
    imgui.implOpenGL3RenderDrawData(draw_data);
    var ctx = glfw.getCurrentContext();
    imgui.updatePlatformWindows();
    imgui.renderPlatformWindowsDefault();
    glfw.makeContextCurrent(ctx);

    glfw.swapBuffers(window);
    glfw.pollEvents();
}

imgui.implOpenGL3Shutdown();
imgui.implGlfwShutdown();
imgui.destroyContext();

glfw.destroyWindow(window);
glfw.terminate();

//
//
// print(gui.test());
//
//
//
// var vertex = gui.initVertex();
// print(vertex.vao);
// print(vertex.vbo);
// print(vertex.ebo);
//
// var program = gui.createProgram();
// print(program);
//
// var size = gui.glfwGetFramebufferSize();
// print(size.width);
// print(size.height);


//while(gui.shouldClose() == 0) {
    // gui.imguiNewFrame();
    //
    // gui.imguiBegin("Hello");
    // gui.imguiEnd();
    //
    // gui.imguiBegin("Hello2");
    // gui.imguiEnd();
    //
    // gui.imguiShowTest();
    //
    // gui.glViewport();
    // gui.glClearColor(0.45, 0.55, 0.6, 1.0);
    // gui.glClear();
    // gui.imguiRender();
    //
    // gui.glfwSwapBuffers();
    //gui.pollEvents();
//}