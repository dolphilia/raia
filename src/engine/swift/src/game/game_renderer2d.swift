extension Game {
    class Renderer2D: RendererProtocol {
        var textureData: Game.TextureData
        var glResources = Game.GLResources()
        private let glData = Game.GLData(
            vertices: [
                -1.0,  1.0,  0.0,   0.0, 0.0,
                -1.0, -1.0,  0.0,   0.0, 1.0,
                1.0, -1.0,  0.0,   1.0, 1.0,
                1.0,  1.0,  0.0,   1.0, 0.0
            ],
            indices: [0,1,2, 0,2,3],
            vertexShaderSource: """
                attribute vec4 a_position;
                attribute vec2 a_texCoord;
                varying vec2 v_texCoord;
                void main() {
                    gl_Position = a_position;
                    v_texCoord = a_texCoord;
                }
            """,
            fragmentShaderSource: """
                precision mediump float;
                varying vec2 v_texCoord;
                uniform sampler2D s_texture;
                void main() {
                    gl_FragColor = texture2D(s_texture, v_texCoord);
                }
            """
        )

        init(texWidth: Int, texHeight: Int) {
            self.textureData = Game.TextureData(width: texWidth, height: texHeight, pixels: nil, id: 0)
        }

        deinit {
            cleanup()
        }

        func setup() {
            GLES.genVertexArrays(n: 1, arrays: &glResources.VAO)
            GLES.genBuffers(n: 1, buffers: &glResources.VBO)
            GLES.genBuffers(n: 1, buffers: &glResources.EBO)
            GLES.bindVertexArray(array: Int(glResources.VAO))
            GLES.bindBuffer(target: GLES.ARRAY_BUFFER, buffer: Int(glResources.VBO))
            
            glData.vertices.withUnsafeBytes { ptr in
                GLES.bufferData(target: GLES.ARRAY_BUFFER, size: ptr.count, data: ptr.baseAddress, usage: GLES.STATIC_DRAW)
            }

            GLES.bindBuffer(target: GLES.ELEMENT_ARRAY_BUFFER, buffer: Int(glResources.EBO))
            glData.indices.withUnsafeBytes { ptr in
                GLES.bufferData(target: GLES.ELEMENT_ARRAY_BUFFER, size: ptr.count, data: ptr.baseAddress, usage: GLES.STATIC_DRAW)
            }

            let stride = 5 * MemoryLayout<Float>.stride
            GLES.vertexAttribPointer(index: 0, size: 3, type: GLES.FLOAT, normalized: false, stride: stride, pointer: nil)
            GLES.enableVertexAttribArray(index: 0)
            let texOffset = UnsafeRawPointer(bitPattern: 3 * MemoryLayout<Float>.stride)
            GLES.vertexAttribPointer(index: 1, size: 2, type: GLES.FLOAT, normalized: false, stride: stride, pointer: texOffset)
            GLES.enableVertexAttribArray(index: 1)

            GLES.bindVertexArray(array: 0)

            glResources.program = GLES.createProgram(vertexSource: glData.vertexShaderSource, fragmentSource: glData.fragmentShaderSource)

            let pixelCount = textureData.width * textureData.height * 4
            textureData.pixels = UnsafeMutablePointer<UInt8>.allocate(capacity: pixelCount)
            guard let px = textureData.pixels else { return }
            for i in 0..<pixelCount {
               px[i] = 255
            }

            GLES.genTextures(n: 1, textures: &textureData.id)
            GLES.bindTexture(target: GLES.TEXTURE_2D, texture: Int(textureData.id))
            GLES.texParameteri(target: GLES.TEXTURE_2D, pname: GLES.TEXTURE_MIN_FILTER, param: GLES.NEAREST)
            GLES.texParameteri(target: GLES.TEXTURE_2D, pname: GLES.TEXTURE_MAG_FILTER, param: GLES.NEAREST)
        }

        func cleanup() {
            //textureData.pixels?.deallocate()
            withUnsafePointer(to: glResources.VAO) {
                GLES.deleteVertexArrays(n: 1, arrays: UnsafeMutableRawPointer(mutating: $0))
            }
            withUnsafePointer(to: glResources.VBO) {
                GLES.deleteBuffers(n: 1, buffers: UnsafeMutableRawPointer(mutating: $0))
            }
            withUnsafePointer(to: glResources.EBO) {
                GLES.deleteBuffers(n: 1, buffers: UnsafeMutableRawPointer(mutating: $0))
            }
            withUnsafePointer(to: textureData.id) {
                GLES.deleteTextures(n: 1, textures: UnsafeMutableRawPointer(mutating: $0))
            }
            GLES.deleteProgram(program: Int(glResources.program))
        }

        func render(viewportWidth: Int, viewportHeight: Int) {
            GLES.viewport(x: 0, y: 0, width: viewportWidth, height: viewportHeight)
            GLES.clearColor(red: 1, green: 1, blue: 1, alpha: 1)
            GLES.clear(mask: GLES.COLOR_BUFFER_BIT)
            if let px = textureData.pixels {
                GLES.bindTexture(target: GLES.TEXTURE_2D, texture: Int(textureData.id))
                GLES.texImage2D(target: GLES.TEXTURE_2D, level: 0, internalFormat: GLES.RGBA, width: textureData.width, height: textureData.height, border: 0, format: GLES.RGBA, type: GLES.UNSIGNED_BYTE, pixels: px)
            }
            GLES.useProgram(program: Int(glResources.program))
            GLES.bindVertexArray(array: Int(glResources.VAO))
            GLES.drawElements(mode: GLES.TRIANGLES, count: glData.indices.count, type: GLES.UNSIGNED_INT, indices: nil)
        }

        func setPixels(pixels: UnsafeMutablePointer<UInt8>?) {
            textureData.pixels = pixels
        }
    }
}