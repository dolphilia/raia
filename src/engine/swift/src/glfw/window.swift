// glfw/window.swift

import Foundation

extension GLFW {
    class Window {
        private var windowPointer: OpaquePointer?

        // コールバッククロージャの保持
        private var positionCallback: ((Int, Int) -> Void)?
        private var sizeCallback: ((Int, Int) -> Void)?
        private var closeCallback: (() -> Void)?
        private var refreshCallback: (() -> Void)?
        private var focusCallback: ((Bool) -> Void)?
        private var iconifyCallback: ((Bool) -> Void)?
        private var maximizeCallback: ((Bool) -> Void)?
        private var framebufferSizeCallback: ((Int, Int) -> Void)?
        private var contentScaleCallback: ((Float, Float) -> Void)?

        init(width: Int, height: Int, title: String) {
            _ = GLFW.Initializer.instance

            glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2)
            glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1)

            guard let pointer = GLFW.createWindow(width: width, height: height, title: title, monitor: nil, share: nil) else {
                fatalError("Failed to create GLFW window")
            }

            self.windowPointer = pointer
            GLFW.makeContextCurrent(pointer)

            // ユーザーポインタの設定
            setUserPointer()
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

        // サイズと位置管理
        func getWindowPosition() -> (x: Int, y: Int) {
            var x = 0, y = 0
            GLFW.getWindowPos(windowPointer, xpos: &x, ypos: &y)
            return (x, y)
        }

        func setWindowPosition(x: Int, y: Int) {
            GLFW.setWindowPos(windowPointer, xpos: x, ypos: y)
        }

        func setSizeLimits(minWidth: Int, minHeight: Int, maxWidth: Int, maxHeight: Int) {
            GLFW.setWindowSizeLimits(windowPointer, minWidth: minWidth, minHeight: minHeight, maxWidth: maxWidth, maxHeight: maxHeight)
        }

        func setAspectRatio(numer: Int, denom: Int) {
            GLFW.setWindowAspectRatio(windowPointer, numer: numer, denom: denom)
        }

        // 属性管理
        func setWindowOpacity(opacity: Float) {
            GLFW.setWindowOpacity(windowPointer, opacity: opacity)
        }

        func getWindowOpacity() -> Float {
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

        // コンテンツやフレームサイズ、スケールの取得
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

        // ウィンドウのライフサイクル
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
        // func getMonitor() -> Monitor? {
        //     guard let monitorPointer = GLFW.getWindowMonitor(windowPointer) else { return nil }
        //     return Monitor(pointer: monitorPointer)
        // }

        // func setMonitor(monitor: Monitor?, xpos: Int, ypos: Int, width: Int, height: Int, refreshRate: Int) {
        //     GLFW.setWindowMonitor(windowPointer, monitor: monitor?.pointer, xpos: xpos, ypos: ypos, width: width, height: height, refreshRate: refreshRate)
        // }

        // コールバック
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

        // ユーザーポインタの設定
        private func setUserPointer() {
            let pointer = Unmanaged.passUnretained(self).toOpaque()
            GLFW.setWindowUserPointer(windowPointer, pointer: pointer)
        }

        private func getUserPointer() -> UnsafeRawPointer? {
            guard let window = windowPointer else { return nil }
            return GLFW.getWindowUserPointer(window)
        }
    }
}

/*

import Foundation

extension GLFW {
    class Window {
        private var windowPointer: OpaquePointer?

        init(width: Int, height: Int, title: String) {
            _ = GLFW.Initializer.instance

            glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2)
            glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1)

            guard let pointer = GLFW.createWindow(width:width, height:height, title:title, monitor:nil, share:nil) else {
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

        func getSize() -> (width: Int, height: Int) {
            guard let window = windowPointer else { return (0, 0) }
            var width = 0
            var height = 0
            GLFW.getWindowSize(window, width:&width, height:&height)
            return (width, height)
        }

        func setSize(width: Int, height: Int) {
            guard let window = windowPointer else { return }
            GLFW.setWindowSize(window, width:width, height:height)
        }

        func setTitle(_ title: String) {
            guard let window = windowPointer else { return }
            GLFW.setWindowTitle(window, title:title)
        }

        func setShouldClose(_ shouldClose: Bool) {
            guard let window = windowPointer else { return }
            GLFW.setWindowShouldClose(window, value:shouldClose ? 1 : 0)
        }

        func shouldClose() -> Bool {
            guard let window = windowPointer else { return true }
            return GLFW.windowShouldClose(window) == 1
        }

        func setUserPointer(pointer: UnsafeRawPointer?) {
            guard let window = windowPointer else { return }
            GLFW.setWindowUserPointer(window, pointer:pointer)
        }

        func getUserPointer() -> UnsafeRawPointer? {
            guard let window = windowPointer else { return nil }
            return GLFW.getWindowUserPointer(window)
        }
    }
}
*/