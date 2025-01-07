extension Game {
    struct WindowConfig {
        let width: Int
        let height: Int
        let title: String
    }

    struct GLData {
        let vertices: [Float]
        let indices: [UInt32]
        let vertexShaderSource: String
        let fragmentShaderSource: String
    }

    struct GLResources {
        var program: UInt32 = 0
        var VAO: UInt32 = 0
        var VBO: UInt32 = 0
        var EBO: UInt32 = 0
    }

    struct TextureData {
        let width: Int
        let height: Int
        var pixels: UnsafeMutablePointer<GLubyte>?
        var id: UInt32 = 0
    }
}