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

            GLFW.windowHint(hint:GLFW.CONTEXT_VERSION_MAJOR, value:2)
            GLFW.windowHint(hint:GLFW.CONTEXT_VERSION_MINOR, value:1)

            guard let pointer = GLFW.createWindow(width: width, height: height, title: title, monitor: nil, share: nil) else {
                fatalError("Failed to create GLFW window")
            }

            self.windowPointer = pointer
            GLFW.makeContextCurrent(pointer)
        }

        deinit {
            if let window = windowPointer {
                GLFW.destroyWindow(window)
            }
        }

        func run(mainLoop: (Window) -> Void) {
            guard let window = windowPointer else { return }
            while GLFW.windowShouldClose(window) == 0 {
                mainLoop(self)
                GLFW.swapBuffers(window)
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
            get { return GLFW.windowShouldClose(windowPointer) == 1 }
            set { GLFW.setWindowShouldClose(windowPointer, value: newValue ? 1 : 0) }
        }

        var clipboardString: String {
            get {
                return getClipboardString()
            }
            set {
                setClipboardString(newValue)
            }
        }

        // MARK: サイズと位置管理

        private func getWindowPosition() -> (x: Int, y: Int) {
            var x = 0, y = 0
            GLFW.getWindowPos(windowPointer, xpos: &x, ypos: &y)
            return (x, y)
        }

        private func setWindowPosition(x: Int, y: Int) {
            GLFW.setWindowPos(windowPointer, xpos: x, ypos: y)
        }

        private func getWindowSize() -> (width: Int, height: Int) {
            var width = 0, height = 0
            GLFW.getWindowSize(windowPointer, width: &width, height: &height)
            return (width, height)
        }

        private func setWindowSize(width: Int, height: Int) {
            GLFW.setWindowSize(windowPointer, width: width, height: height)
        }

        private func setSizeLimits(minWidth: Int, minHeight: Int, maxWidth: Int, maxHeight: Int) {
            GLFW.setWindowSizeLimits(windowPointer, minWidth: minWidth, minHeight: minHeight, maxWidth: maxWidth, maxHeight: maxHeight)
        }

        private func setAspectRatio(numer: Int, denom: Int) {
            GLFW.setWindowAspectRatio(windowPointer, numer: numer, denom: denom)
        }

        // MARK: 属性管理

        private func setWindowOpacity(opacity: Float) {
            GLFW.setWindowOpacity(windowPointer, opacity: opacity)
        }

        private func getWindowOpacity() -> Float {
            return GLFW.getWindowOpacity(windowPointer)
        }

        func iconify() {
            GLFW.iconifyWindow(windowPointer)
        }

        func restore() {
            GLFW.restoreWindow(windowPointer)
        }

        func maximize() {
            GLFW.maximizeWindow(windowPointer)
        }

        func show() {
            GLFW.showWindow(windowPointer)
        }

        func hide() {
            GLFW.hideWindow(windowPointer)
        }

        func focus() {
            GLFW.focusWindow(windowPointer)
        }

        func requestAttention() {
            GLFW.requestWindowAttention(windowPointer)
        }

        func getWindowAttribute(attribute: Int) -> Int {
            return GLFW.getWindowAttrib(windowPointer, attrib: attribute)
        }

        func setWindowAttribute(attribute: Int, value: Int) {
            GLFW.setWindowAttrib(windowPointer, attrib: attribute, value: value)
        }

        // MARK: サイズ・スケールの取得

        func getFramebufferSize() -> (width: Int, height: Int) {
            var width = 0, height = 0
            GLFW.getFramebufferSize(windowPointer, width: &width, height: &height)
            return (width, height)
        }

        func getWindowFrameSize() -> (left: Int, top: Int, right: Int, bottom: Int) {
            var left = 0, top = 0, right = 0, bottom = 0
            GLFW.getWindowFrameSize(windowPointer, left: &left, top: &top, right: &right, bottom: &bottom)
            return (left, top, right, bottom)
        }

        func getWindowContentScale() -> (xScale: Float, yScale: Float) {
            var xScale: Float = 0, yScale: Float = 0
            GLFW.getWindowContentScale(windowPointer, xscale: &xScale, yscale: &yScale)
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
            GLFW.swapBuffers(windowPointer)
        }

        // MARK: モニター管理

        func getMonitor() -> Monitor? {
            guard let monitorPointer = GLFW.getWindowMonitor(windowPointer) else { return nil }
            return Monitor(pointer: monitorPointer)
        }

        func setMonitor(monitor: Monitor?, xpos: Int, ypos: Int, width: Int, height: Int, refreshRate: Int) {
            GLFW.setWindowMonitor(windowPointer, monitor: monitor?.monitorPointer, xpos: xpos, ypos: ypos, width: width, height: height, refreshRate: refreshRate)
        }

        // MARK: コールバック

        func setWindowPositionCallback(_ callback: @escaping (Int, Int) -> Void) {
            self.positionCallback = callback
            _ = GLFW.setWindowPosCallback(windowPointer) { window, x, y in
                guard let window = GLFW.getWindowUserPointer(window).map({ Unmanaged<Window>.fromOpaque($0).takeUnretainedValue() }) else { return }
                window.positionCallback?(Int(x), Int(y))
            }
        }

        func setWindowSizeCallback(_ callback: @escaping (Int, Int) -> Void) {
            self.sizeCallback = callback
            _ = GLFW.setWindowSizeCallback(windowPointer) { window, width, height in
                guard let window = GLFW.getWindowUserPointer(window).map({ Unmanaged<Window>.fromOpaque($0).takeUnretainedValue() }) else { return }
                window.sizeCallback?(Int(width), Int(height))
            }
        }

        func setWindowCloseCallback(_ callback: @escaping () -> Void) {
            self.closeCallback = callback
            _ = GLFW.setWindowCloseCallback(windowPointer) { window in
                guard let window = GLFW.getWindowUserPointer(window).map({ Unmanaged<Window>.fromOpaque($0).takeUnretainedValue() }) else { return }
                window.closeCallback?()
            }
        }

        func setWindowRefreshCallback(_ callback: @escaping () -> Void) {
            self.refreshCallback = callback
            _ = GLFW.setWindowRefreshCallback(windowPointer) { window in
                guard let window = GLFW.getWindowUserPointer(window).map({ Unmanaged<Window>.fromOpaque($0).takeUnretainedValue() }) else { return }
                window.refreshCallback?()
            }
        }

        func setWindowFocusCallback(_ callback: @escaping (Bool) -> Void) {
            self.focusCallback = callback
            _ = GLFW.setWindowFocusCallback(windowPointer) { window, focused in
                guard let window = GLFW.getWindowUserPointer(window).map({ Unmanaged<Window>.fromOpaque($0).takeUnretainedValue() }) else { return }
                window.focusCallback?(focused == GLFW_TRUE)
            }
        }

        func setWindowIconifyCallback(_ callback: @escaping (Bool) -> Void) {
            self.iconifyCallback = callback
            _ = GLFW.setWindowIconifyCallback(windowPointer) { window, iconified in
                guard let window = GLFW.getWindowUserPointer(window).map({ Unmanaged<Window>.fromOpaque($0).takeUnretainedValue() }) else { return }
                window.iconifyCallback?(iconified == GLFW_TRUE)
            }
        }

        func setWindowMaximizeCallback(_ callback: @escaping (Bool) -> Void) {
            self.maximizeCallback = callback
            _ = GLFW.setWindowMaximizeCallback(windowPointer) { window, maximized in
                guard let window = GLFW.getWindowUserPointer(window).map({ Unmanaged<Window>.fromOpaque($0).takeUnretainedValue() }) else { return }
                window.maximizeCallback?(maximized == GLFW_TRUE)
            }
        }

        func setFramebufferSizeCallback(_ callback: @escaping (Int, Int) -> Void) {
            self.framebufferSizeCallback = callback
            _ = GLFW.setFramebufferSizeCallback(windowPointer) { window, width, height in
                guard let window = GLFW.getWindowUserPointer(window).map({ Unmanaged<Window>.fromOpaque($0).takeUnretainedValue() }) else { return }
                window.framebufferSizeCallback?(Int(width), Int(height))
            }
        }

        func setWindowContentScaleCallback(_ callback: @escaping (Float, Float) -> Void) {
            self.contentScaleCallback = callback
            _ = GLFW.setWindowContentScaleCallback(windowPointer) { window, xscale, yscale in
                guard let window = GLFW.getWindowUserPointer(window).map({ Unmanaged<Window>.fromOpaque($0).takeUnretainedValue() }) else { return }
                window.contentScaleCallback?(xscale, yscale)
            }
        }

        func setKeyCallback(_ callback: @escaping (Int32, Int32, Int32, Int32) -> Void) {
            self.keyCallback = callback
            _ = GLFW.setKeyCallback(window: windowPointer) { window, key, scancode, action, mods in
                guard let window = GLFW.getWindowUserPointer(window).map({ Unmanaged<Window>.fromOpaque($0).takeUnretainedValue() }) else { return }
                window.keyCallback?(key, scancode, action, mods)
            }
        }

        func setCharCallback(_ callback: @escaping (UInt32) -> Void) {
            self.charCallback = callback
            _ = GLFW.setCharCallback(window: windowPointer) { window, char in
                guard let window = GLFW.getWindowUserPointer(window).map({ Unmanaged<Window>.fromOpaque($0).takeUnretainedValue() }) else { return }
                window.charCallback?(char)
            }
        }

        func setCharModsCallback(_ callback: @escaping (UInt32, Int32) -> Void) {
            self.charModsCallback = callback
            _ = GLFW.setCharModsCallback(window: windowPointer) { window, char, mods in
                guard let window = GLFW.getWindowUserPointer(window).map({ Unmanaged<Window>.fromOpaque($0).takeUnretainedValue() }) else { return }
                window.charModsCallback?(char, mods)
            }
        }

        func setMouseButtonCallback(_ callback: @escaping (Int32, Int32, Int32) -> Void) {
            self.mouseButtonCallback = callback
            _ = GLFW.setMouseButtonCallback(window: windowPointer) { window, button, action, mods in
                guard let window = GLFW.getWindowUserPointer(window).map({ Unmanaged<Window>.fromOpaque($0).takeUnretainedValue() }) else { return }
                window.mouseButtonCallback?(button, action, mods)
            }
        }

        func setCursorPosCallback(_ callback: @escaping (Double, Double) -> Void) {
            self.cursorPosCallback = callback
            _ = GLFW.setCursorPosCallback(window: windowPointer) { window, xpos, ypos in
                guard let window = GLFW.getWindowUserPointer(window).map({ Unmanaged<Window>.fromOpaque($0).takeUnretainedValue() }) else { return }
                window.cursorPosCallback?(xpos, ypos)
            }
        }

        func setCursorEnterCallback(_ callback: @escaping (Bool) -> Void) {
            self.cursorEnterCallback = callback
            _ = GLFW.setCursorEnterCallback(window: windowPointer) { window, entered in
                guard let window = GLFW.getWindowUserPointer(window).map({ Unmanaged<Window>.fromOpaque($0).takeUnretainedValue() }) else { return }
                window.cursorEnterCallback?(entered == GLFW_TRUE)
            }
        }

        func setScrollCallback(_ callback: @escaping (Double, Double) -> Void) {
            self.scrollCallback = callback
            _ = GLFW.setScrollCallback(window: windowPointer) { window, xoffset, yoffset in
                guard let window = GLFW.getWindowUserPointer(window).map({ Unmanaged<Window>.fromOpaque($0).takeUnretainedValue() }) else { return }
                window.scrollCallback?(xoffset, yoffset)
            }
        }

        typealias WrapDropFunType = @convention(c) (OpaquePointer?, Int32, UnsafePointer<UnsafePointer<Int8>>?) -> Void

        @_silgen_name("wrap_raia_glfw_set_drop_callback")
        func bridging_wrap_raia_glfw_set_drop_callback(_ window: OpaquePointer?, _ cb: @escaping WrapDropFunType) -> WrapDropFunType?

        @discardableResult
        func setMyDropCallback(window: OpaquePointer?, callback: @escaping WrapDropFunType) -> WrapDropFunType? {
            return bridging_wrap_raia_glfw_set_drop_callback(window, callback)
        }

        func setDropCallback(_ callback: @escaping ([String]) -> Void) {
            self.dropCallback = callback
            _ = setMyDropCallback(window: windowPointer) { (winPointer: OpaquePointer?, count: Int32, paths: UnsafePointer<UnsafePointer<Int8>>?) in
                guard let swiftWindow = GLFW.getWindowUserPointer(winPointer)
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

        private func setUserPointer(_ pointer: UnsafeRawPointer?) {
            //let pointer = Unmanaged.passUnretained(self).toOpaque()
            GLFW.setWindowUserPointer(windowPointer, pointer: pointer)
        }

        private func getUserPointer() -> UnsafeRawPointer? {
            guard let window = windowPointer else { return nil }
            return GLFW.getWindowUserPointer(window)
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

        func setCursor(_ cursor: GLFW.Cursor) {
            cursor.setCursor(window: windowPointer)
        }

        // Mark: クリップボード

        private func setClipboardString(_ string: String) {
            GLFW.setClipboardString(window: windowPointer, string: string)
        }

        private func getClipboardString() -> String {
            return GLFW.getClipboardString(window: windowPointer) ?? ""
        }

        // Mark: コンテキスト
        
        func makeContextCurrent() {
            GLFW.makeContextCurrent(windowPointer)
        }
    }
}