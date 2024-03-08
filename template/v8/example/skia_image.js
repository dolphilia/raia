import {Skia} from 'raia_skia';
import {GLFW} from 'raia_glfw';
import {GLES} from 'raia_gles';
import {Std} from "raia_std";
let std = new Std();
const glfw = new GLFW();
const gl = new GLES();

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
const window = glfw.createWindow(width, height, "title");
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

// 画像を描画する
var image_file_id = skia.SkStream_MakeFromFile("miga.png");
var stream_asset = skia.static_sk_stream_asset_get(image_file_id);
var size = skia.SkStreamAsset_getLength(stream_asset);
var image_data_id = skia.SkData_MakeFromStream(stream_asset, size);
var image_id = skia.SkImages_DeferredFromEncodedData(image_data_id);
skia.SkCanvas_drawImage_4(canvas, skia.static_sk_image_get(image_id), 0, 0);

var pixels = skia.SkBitmap_getPixels(bitmap);

while(glfw.windowShouldClose(window) === 0) {
    gl.pixelStorei(GLES.UNPACK_ALIGNMENT, 1);
    gl.bindTexture(GLES.TEXTURE_2D, texture);
    gl.texImage2D(GLES.TEXTURE_2D, 0, GLES.RGBA, width, height, 0, GLES.RGBA, GLES.UNSIGNED_BYTE, pixels); // uint8.buffer
    gl.texParameteri(GLES.TEXTURE_2D, GLES.TEXTURE_MIN_FILTER, GLES.LINEAR);
    gl.texParameteri(GLES.TEXTURE_2D, GLES.TEXTURE_MAG_FILTER, GLES.LINEAR);
    gl.useProgram(program);
    gl.bindVertexArray(vao);
    gl.drawElements(GLES.TRIANGLES, 6, GLES.UNSIGNED_INT, null);
    glfw.swapBuffers(window);
    glfw.pollEvents();
}