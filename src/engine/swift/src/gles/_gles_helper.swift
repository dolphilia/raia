extension GLES {
    static func createProgram(vertexSource: String, fragmentSource: String) -> UInt32 {
        let vsObj = GLES.createShader(type: GLES.VERTEX_SHADER)
        vertexSource.withCString { cstr in
            var p: UnsafePointer<CChar>? = cstr
            GLES.shaderSource(shader: vsObj, count: 1, strings: &p, lengths: nil)
        }
        GLES.compileShader(shader: vsObj)
        let fsObj = GLES.createShader(type: GLES.FRAGMENT_SHADER)
        fragmentSource.withCString { cstr in
            var p: UnsafePointer<CChar>? = cstr
            GLES.shaderSource(shader: fsObj, count: 1, strings: &p, lengths: nil)
        }
        GLES.compileShader(shader: fsObj)
        let prog = GLES.createProgram()
        GLES.attachShader(program: prog, shader: vsObj)
        GLES.attachShader(program: prog, shader: fsObj)
        GLES.linkProgram(program: prog)
        GLES.deleteShader(shader: vsObj)
        GLES.deleteShader(shader: fsObj)
        return UInt32(prog)
    }
}