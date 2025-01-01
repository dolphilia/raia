// glfw/window.swift

import Foundation

extension GLFW {
    class Window {
        private var windowPointer: OpaquePointer?

        // MARK: コールバッククロージャ

        private var positionCallback: ((Int, Int) -> Void)?
        private var sizeCallback: ((Int, Int) -> Void)?
        private var closeCallback: (() -> Void)?
        private var refreshCallback: (() -> Void)?
        private var focusCallback: ((Bool) -> Void)?
        private var iconifyCallback: ((Bool) -> Void)?
        private var maximizeCallback: ((Bool) -> Void)?
        private var framebufferSizeCallback: ((Int, Int) -> Void)?
        private var contentScaleCallback: ((Float, Float) -> Void)?
        private var keyCallback: ((Int32, Int32, Int32, Int32) -> Void)?
        private var charCallback: ((UInt32) -> Void)?
        private var charModsCallback: ((UInt32, Int32) -> Void)?
        private var mouseButtonCallback: ((Int32, Int32, Int32) -> Void)?
        private var cursorPosCallback: ((Double, Double) -> Void)?
        private var cursorEnterCallback: ((Bool) -> Void)?
        private var scrollCallback: ((Double, Double) -> Void)?
        private var dropCallback: (([String]) -> Void)?

        // MARK: 初期化と実行

        init(width: Int, height: Int, title: String) {
            _ = GLFW.Initializer.instance

            GLFW.windowHint(hint:GLFW.CLIENT_API, value:GLFW.OPENGL_ES_API)
            GLFW.windowHint(hint:GLFW.CONTEXT_VERSION_MAJOR, value:3)
            GLFW.windowHint(hint:GLFW.CONTEXT_VERSION_MINOR, value:0)
            GLFW.windowHint(hint:GLFW.OPENGL_PROFILE, value:GLFW.OPENGL_CORE_PROFILE)
            GLFW.windowHint(hint:GLFW.CONTEXT_CREATION_API, value:GLFW.EGL_CONTEXT_API)

            guard let pointer = GLFW.createWindow(width: width, height: height, title: title, monitor: nil, share: nil) else {
                fatalError("Failed to create GLFW window")
            }

            self.windowPointer = pointer
            GLFW.makeContextCurrent(window:pointer)
        }

        deinit {
            if let window = windowPointer {
                GLFW.destroyWindow(window:window)
            }
        }

        func run(mainLoop: (Window) -> Void) {
            guard let window = windowPointer else { return }
            while GLFW.windowShouldClose(window:window) == 0 {
                mainLoop(self)
                GLFW.swapBuffers(window:window)
                GLFW.pollEvents()
            }
        }

        // MARK: プロパティ

        var position: (x: Int, y: Int) {
            get { return getWindowPosition() }
            set { setWindowPosition(x: newValue.x, y: newValue.y) }
        }

        var size: (width: Int, height: Int) {
            get { return getWindowSize() }
            set { setWindowSize(width: newValue.width, height: newValue.height) }
        }

        var sizeLimits: (minWidth: Int, minHeight: Int, maxWidth: Int, maxHeight: Int)? {
            didSet {
                guard let limits = sizeLimits else { return }
                setSizeLimits(minWidth: limits.minWidth, minHeight: limits.minHeight, maxWidth: limits.maxWidth, maxHeight: limits.maxHeight)
            }
        }

        var aspectRatio: (numer: Int, denom: Int)? {
            didSet {
                guard let ratio = aspectRatio else { return }
                setAspectRatio(numer: ratio.numer, denom: ratio.denom)
            }
        }

        var opacity: Float {
            get { return getWindowOpacity() }
            set { setWindowOpacity(opacity: newValue) }
        }

        var shouldClose: Bool {
            get { return GLFW.windowShouldClose(window:windowPointer) == 1 }
            set { GLFW.setWindowShouldClose(window:windowPointer, value: newValue ? 1 : 0) }
        }

        var clipboardString: String {
            get {
                return getClipboardString()
            }
            set {
                setClipboardString(string:newValue)
            }
        }

        // MARK: サイズと位置管理

        private func getWindowPosition() -> (x: Int, y: Int) {
            var x = 0, y = 0
            GLFW.getWindowPos(window:windowPointer, xpos: &x, ypos: &y)
            return (x, y)
        }

        private func setWindowPosition(x: Int, y: Int) {
            GLFW.setWindowPos(window:windowPointer, xpos: x, ypos: y)
        }

        private func getWindowSize() -> (width: Int, height: Int) {
            var width = 0, height = 0
            GLFW.getWindowSize(window:windowPointer, width: &width, height: &height)
            return (width, height)
        }

        private func setWindowSize(width: Int, height: Int) {
            GLFW.setWindowSize(window:windowPointer, width: width, height: height)
        }

        private func setSizeLimits(minWidth: Int, minHeight: Int, maxWidth: Int, maxHeight: Int) {
            GLFW.setWindowSizeLimits(window:windowPointer, minWidth: minWidth, minHeight: minHeight, maxWidth: maxWidth, maxHeight: maxHeight)
        }

        private func setAspectRatio(numer: Int, denom: Int) {
            GLFW.setWindowAspectRatio(window:windowPointer, numer: numer, denom: denom)
        }

        // MARK: 属性管理

        private func setWindowOpacity(opacity: Float) {
            GLFW.setWindowOpacity(window:windowPointer, opacity: opacity)
        }

        private func getWindowOpacity() -> Float {
            return GLFW.getWindowOpacity(window:windowPointer)
        }

        func iconify() {
            GLFW.iconifyWindow(window:windowPointer)
        }

        func restore() {
            GLFW.restoreWindow(window:windowPointer)
        }

        func maximize() {
            GLFW.maximizeWindow(window:windowPointer)
        }

        func show() {
            GLFW.showWindow(window:windowPointer)
        }

        func hide() {
            GLFW.hideWindow(window:windowPointer)
        }

        func focus() {
            GLFW.focusWindow(window:windowPointer)
        }

        func requestAttention() {
            GLFW.requestWindowAttention(window:windowPointer)
        }

        func getWindowAttribute(attribute: Int) -> Int {
            return GLFW.getWindowAttrib(window:windowPointer, attrib: attribute)
        }

        func setWindowAttribute(attribute: Int, value: Int) {
            GLFW.setWindowAttrib(window:windowPointer, attrib: attribute, value: value)
        }

        // MARK: サイズ・スケールの取得

        func getFramebufferSize() -> (width: Int, height: Int) {
            var width = 0, height = 0
            GLFW.getFramebufferSize(window:windowPointer, width: &width, height: &height)
            return (width, height)
        }

        func getWindowFrameSize() -> (left: Int, top: Int, right: Int, bottom: Int) {
            var left = 0, top = 0, right = 0, bottom = 0
            GLFW.getWindowFrameSize(window:windowPointer, left: &left, top: &top, right: &right, bottom: &bottom)
            return (left, top, right, bottom)
        }

        func getWindowContentScale() -> (xScale: Float, yScale: Float) {
            var xScale: Float = 0, yScale: Float = 0
            GLFW.getWindowContentScale(window:windowPointer, xscale: &xScale, yscale: &yScale)
            return (xScale, yScale)
        }

        // MARK: ウィンドウのライフサイクル

        func pollEvents() {
            GLFW.pollEvents()
        }

        func waitEvents() {
            GLFW.waitEvents()
        }

        func waitEventsTimeout(timeout: Double) {
            GLFW.waitEventsTimeout(timeout: timeout)
        }

        func postEmptyEvent() {
            GLFW.postEmptyEvent()
        }

        func swapBuffers() {
            GLFW.swapBuffers(window:windowPointer)
        }

        // MARK: モニター管理

        func getMonitor() -> Monitor? {
            guard let monitorPointer = GLFW.getWindowMonitor(window:windowPointer) else { return nil }
            return Monitor(pointer: monitorPointer)
        }

        func setMonitor(monitor: Monitor?, xpos: Int, ypos: Int, width: Int, height: Int, refreshRate: Int) {
            GLFW.setWindowMonitor(window:windowPointer, monitor: monitor?.monitorPointer, xpos: xpos, ypos: ypos, width: width, height: height, refreshRate: refreshRate)
        }

        // MARK: コールバック

        func setWindowPositionCallback(callback: @escaping (Int, Int) -> Void) {
            self.positionCallback = callback
            _ = GLFW.setWindowPosCallback(window:windowPointer) { window, x, y in
                guard let window = GLFW.getWindowUserPointer(window:window).map({ Unmanaged<Window>.fromOpaque($0).takeUnretainedValue() }) else { return }
                window.positionCallback?(Int(x), Int(y))
            }
        }

        func setWindowSizeCallback(callback: @escaping (Int, Int) -> Void) {
            self.sizeCallback = callback
            _ = GLFW.setWindowSizeCallback(window:windowPointer) { window, width, height in
                guard let window = GLFW.getWindowUserPointer(window:window).map({ Unmanaged<Window>.fromOpaque($0).takeUnretainedValue() }) else { return }
                window.sizeCallback?(Int(width), Int(height))
            }
        }

        func setWindowCloseCallback(callback: @escaping () -> Void) {
            self.closeCallback = callback
            _ = GLFW.setWindowCloseCallback(window:windowPointer) { window in
                guard let window = GLFW.getWindowUserPointer(window:window).map({ Unmanaged<Window>.fromOpaque($0).takeUnretainedValue() }) else { return }
                window.closeCallback?()
            }
        }

        func setWindowRefreshCallback(callback: @escaping () -> Void) {
            self.refreshCallback = callback
            _ = GLFW.setWindowRefreshCallback(window:windowPointer) { window in
                guard let window = GLFW.getWindowUserPointer(window:window).map({ Unmanaged<Window>.fromOpaque($0).takeUnretainedValue() }) else { return }
                window.refreshCallback?()
            }
        }

        func setWindowFocusCallback(callback: @escaping (Bool) -> Void) {
            self.focusCallback = callback
            _ = GLFW.setWindowFocusCallback(window:windowPointer) { window, focused in
                guard let window = GLFW.getWindowUserPointer(window:window).map({ Unmanaged<Window>.fromOpaque($0).takeUnretainedValue() }) else { return }
                window.focusCallback?(focused == GLFW_TRUE)
            }
        }

        func setWindowIconifyCallback(callback: @escaping (Bool) -> Void) {
            self.iconifyCallback = callback
            _ = GLFW.setWindowIconifyCallback(window:windowPointer) { window, iconified in
                guard let window = GLFW.getWindowUserPointer(window:window).map({ Unmanaged<Window>.fromOpaque($0).takeUnretainedValue() }) else { return }
                window.iconifyCallback?(iconified == GLFW_TRUE)
            }
        }

        func setWindowMaximizeCallback(callback: @escaping (Bool) -> Void) {
            self.maximizeCallback = callback
            _ = GLFW.setWindowMaximizeCallback(window:windowPointer) { window, maximized in
                guard let window = GLFW.getWindowUserPointer(window:window).map({ Unmanaged<Window>.fromOpaque($0).takeUnretainedValue() }) else { return }
                window.maximizeCallback?(maximized == GLFW_TRUE)
            }
        }

        func setFramebufferSizeCallback(callback: @escaping (Int, Int) -> Void) {
            self.framebufferSizeCallback = callback
            _ = GLFW.setFramebufferSizeCallback(window:windowPointer) { window, width, height in
                guard let window = GLFW.getWindowUserPointer(window:window).map({ Unmanaged<Window>.fromOpaque($0).takeUnretainedValue() }) else { return }
                window.framebufferSizeCallback?(Int(width), Int(height))
            }
        }

        func setWindowContentScaleCallback(callback: @escaping (Float, Float) -> Void) {
            self.contentScaleCallback = callback
            _ = GLFW.setWindowContentScaleCallback(window:windowPointer) { window, xscale, yscale in
                guard let window = GLFW.getWindowUserPointer(window:window).map({ Unmanaged<Window>.fromOpaque($0).takeUnretainedValue() }) else { return }
                window.contentScaleCallback?(xscale, yscale)
            }
        }

        func setKeyCallback(callback: @escaping (Int32, Int32, Int32, Int32) -> Void) {
            self.keyCallback = callback
            _ = GLFW.setKeyCallback(window: windowPointer) { window, key, scancode, action, mods in
                guard let window = GLFW.getWindowUserPointer(window:window).map({ Unmanaged<Window>.fromOpaque($0).takeUnretainedValue() }) else { return }
                window.keyCallback?(key, scancode, action, mods)
            }
        }

        func setCharCallback(callback: @escaping (UInt32) -> Void) {
            self.charCallback = callback
            _ = GLFW.setCharCallback(window: windowPointer) { window, char in
                guard let window = GLFW.getWindowUserPointer(window:window).map({ Unmanaged<Window>.fromOpaque($0).takeUnretainedValue() }) else { return }
                window.charCallback?(char)
            }
        }

        func setCharModsCallback(callback: @escaping (UInt32, Int32) -> Void) {
            self.charModsCallback = callback
            _ = GLFW.setCharModsCallback(window: windowPointer) { window, char, mods in
                guard let window = GLFW.getWindowUserPointer(window:window).map({ Unmanaged<Window>.fromOpaque($0).takeUnretainedValue() }) else { return }
                window.charModsCallback?(char, mods)
            }
        }

        func setMouseButtonCallback(callback: @escaping (Int32, Int32, Int32) -> Void) {
            self.mouseButtonCallback = callback
            _ = GLFW.setMouseButtonCallback(window: windowPointer) { window, button, action, mods in
                guard let window = GLFW.getWindowUserPointer(window:window).map({ Unmanaged<Window>.fromOpaque($0).takeUnretainedValue() }) else { return }
                window.mouseButtonCallback?(button, action, mods)
            }
        }

        func setCursorPosCallback(callback: @escaping (Double, Double) -> Void) {
            self.cursorPosCallback = callback
            _ = GLFW.setCursorPosCallback(window: windowPointer) { window, xpos, ypos in
                guard let window = GLFW.getWindowUserPointer(window:window).map({ Unmanaged<Window>.fromOpaque($0).takeUnretainedValue() }) else { return }
                window.cursorPosCallback?(xpos, ypos)
            }
        }

        func setCursorEnterCallback(callback: @escaping (Bool) -> Void) {
            self.cursorEnterCallback = callback
            _ = GLFW.setCursorEnterCallback(window: windowPointer) { window, entered in
                guard let window = GLFW.getWindowUserPointer(window:window).map({ Unmanaged<Window>.fromOpaque($0).takeUnretainedValue() }) else { return }
                window.cursorEnterCallback?(entered == GLFW_TRUE)
            }
        }

        func setScrollCallback(callback: @escaping (Double, Double) -> Void) {
            self.scrollCallback = callback
            _ = GLFW.setScrollCallback(window: windowPointer) { window, xoffset, yoffset in
                guard let window = GLFW.getWindowUserPointer(window:window).map({ Unmanaged<Window>.fromOpaque($0).takeUnretainedValue() }) else { return }
                window.scrollCallback?(xoffset, yoffset)
            }
        }

        typealias WrapDropFunType = @convention(c) (OpaquePointer?, Int32, UnsafePointer<UnsafePointer<Int8>>?) -> Void

        @_silgen_name("wrap_raia_glfw_set_drop_callback")
        func bridging_wrap_raia_glfw_set_drop_callback( window: OpaquePointer?, callback: @escaping WrapDropFunType) -> WrapDropFunType?

        @discardableResult
        func setMyDropCallback(window: OpaquePointer?, callback: @escaping WrapDropFunType) -> WrapDropFunType? {
            return bridging_wrap_raia_glfw_set_drop_callback(window:window, callback:callback)
        }

        func setDropCallback(callback: @escaping ([String]) -> Void) {
            self.dropCallback = callback
            _ = setMyDropCallback(window: windowPointer) { (winPointer: OpaquePointer?, count: Int32, paths: UnsafePointer<UnsafePointer<Int8>>?) in
                guard let swiftWindow = GLFW.getWindowUserPointer(window:winPointer)
                    .map({ Unmanaged<Window>.fromOpaque($0).takeUnretainedValue() }) else { 
                    return
                }
                guard let paths = paths else { return }
                let filePaths = (0..<Int(count)).compactMap { index -> String? in
                    String(cString: paths[index])
                }
                swiftWindow.dropCallback?(filePaths)
            }
        }
 

        // MARK: ユーザーポインタの操作

        private func setUserPointer( pointer: UnsafeRawPointer?) {
            //let pointer = Unmanaged.passUnretained(self).toOpaque()
            GLFW.setWindowUserPointer(window:windowPointer, pointer: pointer)
        }

        private func getUserPointer() -> UnsafeRawPointer? {
            guard let window = windowPointer else { return nil }
            return GLFW.getWindowUserPointer(window:window)
        }

        // MARK: 入力

        func getInputMode(mode: Int) -> Int {
            return GLFW.getInputMode(window: windowPointer, mode: mode)
        }

        func setInputMode(mode: Int, value: Int) {
            GLFW.setInputMode(window: windowPointer, mode: mode, value: value)
        }

        // MARK: キーボード・マウス

        func getKey(key: Int) -> Int {
            return GLFW.getKey(window: windowPointer, key: key)
        }

        func getMouseButton(button: Int) -> Int {
            return GLFW.getMouseButton(window: windowPointer, button: button)
        }

        func getCursorPos() -> (xpos: Double, ypos: Double) {
            var xpos: Double = 0.0
            var ypos: Double = 0.0
            GLFW.getCursorPos(window: windowPointer, xpos: &xpos, ypos: &ypos)
            return (xpos, ypos)
        }

        func setCursorPos(xpos: Double, ypos: Double) {
            GLFW.setCursorPos(window: windowPointer, xpos: xpos, ypos: ypos)
        }

        func setCursor( cursor: GLFW.Cursor) {
            cursor.setCursor(window: windowPointer)
        }

        // Mark: クリップボード

        private func setClipboardString( string: String) {
            GLFW.setClipboardString(window: windowPointer, string: string)
        }

        private func getClipboardString() -> String {
            return GLFW.getClipboardString(window: windowPointer) ?? ""
        }

        // Mark: コンテキスト
        
        func makeContextCurrent() {
            GLFW.makeContextCurrent(window:windowPointer)
        }
    }
}