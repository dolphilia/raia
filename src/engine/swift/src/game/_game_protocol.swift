extension Game {
    protocol WindowProtocol: AnyObject {
        var config: WindowConfig { get }
        var window: GLFW.Window { get }
        var isHighDPI: Bool { get set }
        var scaleFactor: Int { get set }
        var glData: GLData { get }
        var glResources: GLResources { get set }
        init(width: Int, height: Int, title: String)
        func setupGL()
        func setupAttributes()
        func cleanup()
        func render()
        func run(mainLoop: () -> Void)
    }
}