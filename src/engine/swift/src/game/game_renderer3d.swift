extension Game {
    class Renderer3D: RendererProtocol {
        var glResources = Game.GLResources()

        struct UniformLocations {
            var mvMatrix: Int32 = -1
            var projMatrix: Int32 = -1
            var lightPos: Int32 = -1
            var lightColor: Int32 = -1
            var baseColor: Int32 = -1
        }

        var uniformLocs = UniformLocations()

        private var rotationY: Float = 0.0

        private let glData = Game.GLData(
            vertices: [
                // 前面 (0,0,1)
                -0.5, -0.5,  0.5,   0, 0, 1,
                0.5, -0.5,  0.5,   0, 0, 1,
                0.5,  0.5,  0.5,   0, 0, 1,
                -0.5,  0.5,  0.5,   0, 0, 1,

                // 背面 (0,0,-1)
                -0.5, -0.5, -0.5,   0, 0, -1,
                0.5, -0.5, -0.5,   0, 0, -1,
                0.5,  0.5, -0.5,   0, 0, -1,
                -0.5,  0.5, -0.5,   0, 0, -1,

                // 左面 (-1,0,0)
                -0.5, -0.5, -0.5,  -1, 0, 0,
                -0.5, -0.5,  0.5,  -1, 0, 0,
                -0.5,  0.5,  0.5,  -1, 0, 0,
                -0.5,  0.5, -0.5,  -1, 0, 0,

                // 右面 (1,0,0)
                0.5, -0.5, -0.5,   1, 0, 0,
                0.5, -0.5,  0.5,   1, 0, 0,
                0.5,  0.5,  0.5,   1, 0, 0,
                0.5,  0.5, -0.5,   1, 0, 0,

                // 上面 (0,1,0)
                -0.5,  0.5,  0.5,   0, 1, 0,
                0.5,  0.5,  0.5,   0, 1, 0,
                0.5,  0.5, -0.5,   0, 1, 0,
                -0.5,  0.5, -0.5,   0, 1, 0,

                // 下面 (0,-1,0)
                -0.5, -0.5,  0.5,   0, -1, 0,
                0.5, -0.5,  0.5,   0, -1, 0,
                0.5, -0.5, -0.5,   0, -1, 0,
                -0.5, -0.5, -0.5,   0, -1, 0
            ],
            indices: [
                // 前面
                0,1,2,   2,3,0,
                // 背面
                4,5,6,   6,7,4,
                // 左面
                8,9,10, 10,11,8,
                // 右面
                12,13,14, 14,15,12,
                // 上面
                16,17,18, 18,19,16,
                // 下面
                20,21,22, 22,23,20
            ],
            vertexShaderSource: """
            uniform mat4 uMVMatrix;
            uniform mat4 uProjMatrix;
            attribute vec3 a_position;
            attribute vec3 a_normal;

            varying vec3 v_normal;
            varying vec3 v_pos;

            void main() {
                vec4 posCam = uMVMatrix * vec4(a_position, 1.0);
                gl_Position = uProjMatrix * posCam;

                // 法線を modelView の mat3 部分で変換 (拡大回転少ない前提)
                v_normal = mat3(uMVMatrix) * a_normal;
                v_pos = posCam.xyz;
            }
            """,
            fragmentShaderSource: """
            precision mediump float;
            varying vec3 v_normal;
            varying vec3 v_pos;

            uniform vec3 uLightPos;    // カメラ座標系でのライト位置
            uniform vec3 uLightColor;  // 光源色
            uniform vec3 uBaseColor;   // 立方体の基本色

            void main() {
                // 法線
                vec3 N = normalize(v_normal);
                // 光の方向
                vec3 L = normalize(uLightPos - v_pos);
                float diff = max(dot(N, L), 0.0);

                // ディフューズ
                vec3 diffuse = uBaseColor * uLightColor * diff;
                // アンビエント
                vec3 ambient = uBaseColor * 0.2;

                gl_FragColor = vec4(ambient + diffuse, 1.0);
            }
            """
        )

        init() {}

        func setup() {
            GLES.genVertexArrays(n: 1, arrays: &glResources.VAO)
            GLES.genBuffers(n: 1, buffers: &glResources.VBO)
            GLES.genBuffers(n: 1, buffers: &glResources.EBO)
            GLES.bindVertexArray(array: Int(glResources.VAO))
            GLES.bindBuffer(target: GLES.ARRAY_BUFFER, buffer: Int(glResources.VBO))
            
            glData.vertices.withUnsafeBytes { ptr in
                GLES.bufferData(target: GLES.ARRAY_BUFFER,
                                size: ptr.count,
                                data: ptr.baseAddress,
                                usage: GLES.STATIC_DRAW)
            }

            GLES.bindBuffer(target: GLES.ELEMENT_ARRAY_BUFFER, buffer: Int(glResources.EBO))
            glData.indices.withUnsafeBytes { ptr in
                GLES.bufferData(target: GLES.ELEMENT_ARRAY_BUFFER, size: ptr.count, data: ptr.baseAddress, usage: GLES.STATIC_DRAW)
            }

            let stride = 6 * MemoryLayout<Float>.stride
            GLES.vertexAttribPointer(index: 0, size: 3, type: GLES.FLOAT, normalized: false, stride: stride, pointer: nil)
            GLES.enableVertexAttribArray(index: 0)

            let normalOffset = UnsafeRawPointer(bitPattern: 3 * MemoryLayout<Float>.stride)
            GLES.vertexAttribPointer(index: 1, size: 3, type: GLES.FLOAT, normalized: false, stride: stride, pointer: normalOffset)
            GLES.enableVertexAttribArray(index: 1)

            GLES.bindVertexArray(array: 0)

            glResources.program = GLES.createProgram(
                vertexSource: glData.vertexShaderSource,
                fragmentSource: glData.fragmentShaderSource
            )

            let prog = Int(glResources.program)
            uniformLocs.mvMatrix   = Int32(GLES.getUniformLocation(program: prog, name: "uMVMatrix"))
            uniformLocs.projMatrix = Int32(GLES.getUniformLocation(program: prog, name: "uProjMatrix"))
            uniformLocs.lightPos   = Int32(GLES.getUniformLocation(program: prog, name: "uLightPos"))
            uniformLocs.lightColor = Int32(GLES.getUniformLocation(program: prog, name: "uLightColor"))
            uniformLocs.baseColor  = Int32(GLES.getUniformLocation(program: prog, name: "uBaseColor"))
        }

        func render(viewportWidth: Int, viewportHeight: Int) {
            rotationY += 0.0001

            GLES.viewport(x: 0, y: 0, width: viewportWidth, height: viewportHeight)
            GLES.clearColor(red: 0.2, green: 0.3, blue: 0.4, alpha: 1.0)
            GLES.clear(mask: GLES.COLOR_BUFFER_BIT | GLES.DEPTH_BUFFER_BIT)
            GLES.enable(cap: GLES.DEPTH_TEST)

            GLES.useProgram(program: Int(glResources.program))

            var model      = [Float](repeating: 0, count: 16)
            var view       = [Float](repeating: 0, count: 16)
            var projection = [Float](repeating: 0, count: 16)
            var mv         = [Float](repeating: 0, count: 16)

            swift_glm_mat4_identity(&model)
            swift_glm_mat4_identity(&view)
            swift_glm_mat4_identity(&projection)

            var eye:    [Float] = [0, 2, -4]
            var center: [Float] = [0, 0, 0]
            var up:     [Float] = [0, 1, 0]

            swift_glm_lookat(&eye, &center, &up, &view)

            let aspect = Float(viewportWidth) / Float(viewportHeight)
            swift_glm_perspective(Float.pi/3, aspect, 0.1, 100.0, &projection)

            var axisY = [Float](arrayLiteral: 0, 1, 0)
            swift_glm_rotate(&model, rotationY, &axisY)

            swift_glm_mat4_mul(&view, &model, &mv)

            mv.withUnsafeBufferPointer { ptr in
                GLES.uniformMatrix4fv(location: Int(uniformLocs.mvMatrix), count: 1, transpose: false, value: UnsafeMutableRawPointer(mutating: ptr.baseAddress))
            }
            projection.withUnsafeBufferPointer { ptr in
                GLES.uniformMatrix4fv(location: Int(uniformLocs.projMatrix), count: 1, transpose: false, value: UnsafeMutableRawPointer(mutating: ptr.baseAddress))
            }

            let lightPos: [Float] = [2, 2, 2]
            let lightColor: [Float] = [1, 1, 1]
            let baseColor: [Float] = [1, 1, 1]

            lightPos.withUnsafeBufferPointer { ptr in
                GLES.uniform3fv(location: Int(uniformLocs.lightPos), count: 1, value: UnsafeMutableRawPointer(mutating: ptr.baseAddress))
            }
            lightColor.withUnsafeBufferPointer { ptr in
                GLES.uniform3fv(location: Int(uniformLocs.lightColor), count: 1, value: UnsafeMutableRawPointer(mutating: ptr.baseAddress))
            }
            baseColor.withUnsafeBufferPointer { ptr in
                GLES.uniform3fv(location: Int(uniformLocs.baseColor), count: 1, value: UnsafeMutableRawPointer(mutating: ptr.baseAddress))
            }

            GLES.bindVertexArray(array: Int(glResources.VAO))
            GLES.drawElements(mode: GLES.TRIANGLES, count: glData.indices.count, type: GLES.UNSIGNED_INT, indices: nil)
        }

        func cleanup() {
            withUnsafePointer(to: glResources.VAO) {
                GLES.deleteVertexArrays(n: 1, arrays: UnsafeMutableRawPointer(mutating: $0))
            }
            withUnsafePointer(to: glResources.VBO) {
                GLES.deleteBuffers(n: 1, buffers: UnsafeMutableRawPointer(mutating: $0))
            }
            withUnsafePointer(to: glResources.EBO) {
                GLES.deleteBuffers(n: 1, buffers: UnsafeMutableRawPointer(mutating: $0))
            }
            GLES.deleteProgram(program: Int(glResources.program))
        }

        func setPixels(pixels: UnsafeMutablePointer<UInt8>?) {
            //textureData.pixels = pixels
        }
    }
}