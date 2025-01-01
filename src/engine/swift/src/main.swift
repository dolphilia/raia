// main.swift

import Foundation

_ = GLFW.Initializer.instance
let window = GLFW.Window(width: 300, height: 300, title: "GLFW Swift Window")

let vertices: [Float] = [
    -1.0,  1.0,  0.0,  // Position 0
     0.0,  0.0,        // TexCoord 0
    -1.0, -1.0,  0.0,  // Position 1
     0.0,  1.0,        // TexCoord 1
     1.0, -1.0,  0.0,  // Position 2
     1.0,  1.0,        // TexCoord 2
     1.0,  1.0,  0.0,  // Position 3
     1.0,  0.0         // TexCoord 3
]
let indices: [UInt32] = [
    0, 1, 2, 0, 2, 3
]
var VAO: UInt32 = 0
var VBO: UInt32 = 0
var EBO: UInt32 = 0
GLES.genVertexArrays(n: 1, arrays: &VAO)
GLES.genBuffers(n: 1, buffers: &VBO)
GLES.genBuffers(n: 1, buffers: &EBO)
GLES.bindVertexArray(array: Int(VAO))
GLES.bindBuffer(target: GLES.ARRAY_BUFFER, buffer: Int(VBO))
vertices.withUnsafeBytes { pointer in
    GLES.bufferData(target: GLES.ARRAY_BUFFER, size: pointer.count, data: pointer.baseAddress, usage: GLES.STATIC_DRAW)
}
GLES.bindBuffer(target: GLES.ELEMENT_ARRAY_BUFFER, buffer: Int(EBO))
indices.withUnsafeBytes { pointer in
    GLES.bufferData(target: GLES.ELEMENT_ARRAY_BUFFER, size: pointer.count, data: pointer.baseAddress, usage: GLES.STATIC_DRAW)
}
GLES.vertexAttribPointer(index: 0, size: 3, type: GLES.FLOAT, normalized: false, stride: 5 * MemoryLayout<Float>.stride, pointer: nil)
GLES.enableVertexAttribArray(index: 0)
GLES.vertexAttribPointer(index: 1, size: 2, type: GLES.FLOAT, normalized: false, stride: 5 * MemoryLayout<Float>.stride, pointer: UnsafeRawPointer(bitPattern: 3 * MemoryLayout<Float>.stride))
GLES.enableVertexAttribArray(index: 1)
GLES.bindVertexArray(array: 0)
let vertexShaderSource = """
attribute vec4 a_position;
attribute vec2 a_texCoord;
varying vec2 v_texCoord;
void main() {
    gl_Position = a_position;
    v_texCoord = a_texCoord;
}
"""
let fragmentShaderSource = """
precision mediump float;
varying vec2 v_texCoord;
uniform sampler2D s_texture;
void main() {
    gl_FragColor = texture2D(s_texture, v_texCoord);
}
"""
let vertexShader = GLES.createShader(type: GLES.VERTEX_SHADER)
vertexShaderSource.withCString { pointer in
    var sourcePointer: UnsafePointer<CChar>? = pointer
    GLES.shaderSource(shader: vertexShader, count: 1, strings: &sourcePointer, lengths: nil)
}
GLES.compileShader(shader: vertexShader)
let fragmentShader = GLES.createShader(type: GLES.FRAGMENT_SHADER)
fragmentShaderSource.withCString { pointer in
    var sourcePointer: UnsafePointer<CChar>? = pointer
    GLES.shaderSource(shader: fragmentShader, count: 1, strings: &sourcePointer, lengths: nil)
}
GLES.compileShader(shader: fragmentShader)
let program = GLES.createProgram()
GLES.attachShader(program: program, shader: vertexShader)
GLES.attachShader(program: program, shader: fragmentShader)
GLES.linkProgram(program: program)
GLES.deleteShader(shader: vertexShader)
GLES.deleteShader(shader: fragmentShader)

let width = 600
let height = 600
let pixels = UnsafeMutablePointer<GLubyte>.allocate(capacity: width * height * 4)
for i in 0..<(width * height * 4) {
    pixels[i] = GLubyte.random(in: 0...255)
}
var texture: UInt32 = 0
GLES.genTextures(n: 1, textures: &texture)
GLES.bindTexture(target: GLES.TEXTURE_2D, texture: Int(texture))
GLES.texImage2D(target: GLES.TEXTURE_2D, level: 0, internalFormat: GLES.RGBA, width: width, height: height, border: 0, format: GLES.RGBA, type: GLES.UNSIGNED_BYTE, pixels: pixels)
GLES.texParameteri(target: GLES.TEXTURE_2D, pname: GLES.TEXTURE_MIN_FILTER, param: GLES.NEAREST)
GLES.texParameteri(target: GLES.TEXTURE_2D, pname: GLES.TEXTURE_MAG_FILTER, param: GLES.NEAREST)

window.run { win in
    GLES.viewport(x: 0, y: 0, width: width, height: height)
    GLES.clearColor(red: 1.0, green: 1.0, blue: 1.0, alpha: 1.0)
    GLES.clear(mask: GLES.COLOR_BUFFER_BIT)
    GLES.bindTexture(target: GLES.TEXTURE_2D, texture: Int(texture))
    GLES.texImage2D(target: GLES.TEXTURE_2D, level: 0, internalFormat: GLES.RGB, width: width, height: height, border: 0, format: GLES.RGB, type: GLES.UNSIGNED_BYTE, pixels: pixels)
    GLES.texParameteri(target: GLES.TEXTURE_2D, pname: GLES.TEXTURE_MIN_FILTER, param: GLES.NEAREST)
    GLES.useProgram(program: Int(program))
    GLES.bindVertexArray(array: Int(VAO))
    GLES.activeTexture(texture: GLES.TEXTURE0)
    GLES.drawElements(mode: GLES.TRIANGLES, count: 6, type: GLES.UNSIGNED_INT, indices: nil)
}

pixels.deallocate()
withUnsafePointer(to: VAO) { vaoPointer in
    GLES.deleteVertexArrays(n: 1, arrays: vaoPointer)
}
withUnsafePointer(to: texture) { texturePointer in
    GLES.deleteTextures(n: 1, textures: texturePointer)
}