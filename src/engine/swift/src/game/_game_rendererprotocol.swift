extension Game {
    protocol RendererProtocol {
        func setup()
        func cleanup()
        func render(viewportWidth: Int, viewportHeight: Int)
        func setPixels(pixels: UnsafeMutablePointer<GLubyte>?)
    }
}