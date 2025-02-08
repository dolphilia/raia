extension Game {
    class Window<R: RendererProtocol> {
        private let window: GLFW.Window
        private let renderer: R
        private let config: Game.WindowConfig
        private var isHighDPI: Bool = false
        private var scaleFactor: Int = 1

        var title: String {
            get {
                return window.title
            }
            set {
                window.title = newValue
            }
        }

        init(width: Int, height: Int, title: String, renderer: R) {
            self.config = Game.WindowConfig(width: width, height: height, title: title)
            self.renderer = renderer

            _ = GLFW.Initializer.instance
            GLFW.windowHint(hint: GLFW.CLIENT_API, value: GLFW.OPENGL_ES_API)
            GLFW.windowHint(hint: GLFW.CONTEXT_VERSION_MAJOR, value: 3)
            GLFW.windowHint(hint: GLFW.CONTEXT_VERSION_MINOR, value: 0)
            GLFW.windowHint(hint: GLFW.OPENGL_PROFILE, value: GLFW.OPENGL_CORE_PROFILE)
            GLFW.windowHint(hint: GLFW.CONTEXT_CREATION_API, value: GLFW.EGL_CONTEXT_API)
            GLFW.windowHint(hint: GLFW.CLIENT_API, value: GLFW.OPENGL_ES_API)

            let win = GLFW.Window(width: width, height: height, title: title)
            win.makeContextCurrent()
            self.window = win

            let (scaleX, _) = win.getWindowContentScale()
            if scaleX > 1.0 {
                isHighDPI = true
                scaleFactor = Int(scaleX)
            }

            renderer.setup()
        }

        deinit {
           //window.destroy()
            //GLFW.terminate()
        }

        func run(mainLoop: () -> Void) {
            while !window.shouldClose {
                mainLoop()
                window.makeContextCurrent()

                let w = window.getFramebufferSize().width * scaleFactor
                let h = window.getFramebufferSize().height * scaleFactor
                renderer.render(viewportWidth: w, viewportHeight: h)

                window.swapBuffers()
                window.pollEvents()
            }
            //renderer.cleanup()
        }
    }
}