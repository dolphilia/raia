extension Game {
    protocol RendererProtocol {
        func setupGL()
        func render(viewportWidth: Int, viewportHeight: Int)
        func cleanup()
    }
}