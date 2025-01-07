extension Game.WindowProtocol {
    func setupAttributes() {}

    func setupGL() {
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
        setupAttributes()
        GLES.bindVertexArray(array: 0)
        glResources.program = GLES.createProgram(vertexSource: glData.vertexShaderSource, fragmentSource: glData.fragmentShaderSource)
    }

    func cleanup() {
        withUnsafePointer(to: glResources.VAO) {
            GLES.deleteVertexArrays(n: 1, arrays: $0)
        }
        withUnsafePointer(to: glResources.VBO) {
            GLES.deleteBuffers(n: 1, buffers: $0)
        }
        withUnsafePointer(to: glResources.EBO) {
            GLES.deleteBuffers(n: 1, buffers: $0)
        }
        GLES.deleteProgram(program: Int(glResources.program))
    }

    func render() {
        fatalError("render() must be implemented in conforming type.")
    }

    func run(mainLoop: () -> Void) {
        while !window.shouldClose {
            mainLoop()
            render()
            window.swapBuffers()
            window.pollEvents()
        }
    }
}