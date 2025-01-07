/// 2D用の描画ロジックのみを担うクラス
extension Game {
    class Renderer2D: RendererProtocol {
        // MARK: - リソースID
        private var program: UInt32 = 0
        private var VAO: UInt32 = 0
        private var VBO: UInt32 = 0
        private var EBO: UInt32 = 0
        private var texture: UInt32 = 0
        private var pixels: UnsafeMutablePointer<GLubyte>?

        // MARK: - 内部に glData (頂点配列, インデックス, シェーダソース) を持つ
        private struct GLData {
            let vertices: [Float]    // 頂点配列
            let indices: [UInt32]    // インデックス
            let vertexShaderSource: String
            let fragmentShaderSource: String
        }

        // glData を直接ここで定義 (2D用)
        private let glData = GLData(
            vertices: [
                // x, y, z,  u, v
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

        // MARK: - テクスチャ用
        private let texWidth: Int
        private let texHeight: Int

        // MARK: - イニシャライザ
        /// - Parameters:
        ///   - width, height: テクスチャサイズ (実際のウィンドウサイズと同じでも良い)
        init(texWidth: Int, texHeight: Int) {
            self.texWidth = texWidth
            self.texHeight = texHeight
        }

        // MARK: - setupGL
        /// カレントコンテキストが設定されている前提で呼ぶ
        func setupGL() {
            // VAO, VBO, EBO
            GLES.genVertexArrays(n: 1, arrays: &VAO)
            GLES.genBuffers(n: 1, buffers: &VBO)
            GLES.genBuffers(n: 1, buffers: &EBO)

            GLES.bindVertexArray(array: Int(VAO))

            // VBO
            GLES.bindBuffer(target: GLES.ARRAY_BUFFER, buffer: Int(VBO))
            glData.vertices.withUnsafeBytes { ptr in
                GLES.bufferData(target: GLES.ARRAY_BUFFER,
                                size: ptr.count,
                                data: ptr.baseAddress,
                                usage: GLES.STATIC_DRAW)
            }

            // EBO
            GLES.bindBuffer(target: GLES.ELEMENT_ARRAY_BUFFER, buffer: Int(EBO))
            glData.indices.withUnsafeBytes { ptr in
                GLES.bufferData(target: GLES.ELEMENT_ARRAY_BUFFER,
                                size: ptr.count,
                                data: ptr.baseAddress,
                                usage: GLES.STATIC_DRAW)
            }

            // 頂点属性 (a_position=0, a_texCoord=1)
            let stride = 5 * MemoryLayout<Float>.stride
            // a_position
            GLES.vertexAttribPointer(index: 0, size: 3, type: GLES.FLOAT,
                                    normalized: false,
                                    stride: stride,
                                    pointer: nil)
            GLES.enableVertexAttribArray(index: 0)
            // a_texCoord
            let texOffset = UnsafeRawPointer(bitPattern: 3 * MemoryLayout<Float>.stride)
            GLES.vertexAttribPointer(index: 1, size: 2, type: GLES.FLOAT,
                                    normalized: false,
                                    stride: stride,
                                    pointer: texOffset)
            GLES.enableVertexAttribArray(index: 1)

            GLES.bindVertexArray(array: 0)

            // シェーダコンパイル & リンク
            program = GLES.createProgram(
                vertexSource: glData.vertexShaderSource,
                fragmentSource: glData.fragmentShaderSource
            )

            // ランダムピクセル
            let pixelCount = texWidth * texHeight * 4
            pixels = UnsafeMutablePointer<GLubyte>.allocate(capacity: pixelCount)
            guard let px = pixels else { return }
            for i in 0..<pixelCount {
                px[i] = GLubyte.random(in: 0...255)
            }

            // テクスチャ生成
            GLES.genTextures(n: 1, textures: &texture)
            GLES.bindTexture(target: GLES.TEXTURE_2D, texture: Int(texture))
            GLES.texParameteri(target: GLES.TEXTURE_2D, pname: GLES.TEXTURE_MIN_FILTER, param: GLES.NEAREST)
            GLES.texParameteri(target: GLES.TEXTURE_2D, pname: GLES.TEXTURE_MAG_FILTER, param: GLES.NEAREST)
        }

        // MARK: - render
        func render(viewportWidth: Int, viewportHeight: Int) {
            // ビューポート・クリア
            GLES.viewport(x: 0, y: 0, width: viewportWidth, height: viewportHeight)
            GLES.clearColor(red: 1, green: 1, blue: 1, alpha: 1)
            GLES.clear(mask: GLES.COLOR_BUFFER_BIT)

            // テクスチャ更新
            if let px = pixels {
                GLES.bindTexture(target: GLES.TEXTURE_2D, texture: Int(texture))
                GLES.texImage2D(target: GLES.TEXTURE_2D, level: 0,
                                internalFormat: GLES.RGBA,
                                width: texWidth,
                                height: texHeight,
                                border: 0,
                                format: GLES.RGBA,
                                type: GLES.UNSIGNED_BYTE,
                                pixels: px)
            }

            GLES.useProgram(program: Int(program))
            GLES.bindVertexArray(array: Int(VAO))
            GLES.drawElements(mode: GLES.TRIANGLES,
                            count: glData.indices.count,
                            type: GLES.UNSIGNED_INT,
                            indices: nil)
        }

        // MARK: - cleanup
        func cleanup() {
            // ピクセル領域解放
            pixels?.deallocate()

            // VBO, EBO, VAO, テクスチャ, program の解放
            withUnsafePointer(to: VAO) {
                GLES.deleteVertexArrays(n: 1, arrays: $0)
            }
            withUnsafePointer(to: VBO) {
                GLES.deleteBuffers(n: 1, buffers: $0)
            }
            withUnsafePointer(to: EBO) {
                GLES.deleteBuffers(n: 1, buffers: $0)
            }
            withUnsafePointer(to: texture) {
                GLES.deleteTextures(n: 1, textures: $0)
            }
            GLES.deleteProgram(program: Int(program))
        }
    }
}