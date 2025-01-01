import Foundation

extension GLFW {
    class Cursor {
        private var cursorPointer: OpaquePointer?

        init(image: UnsafePointer<GLFWimage>?, xhot: Int, yhot: Int) {
            self.cursorPointer = GLFW.createCursor(image: image, xhot: xhot, yhot: yhot)
        }

        init(shape: Int) {
            self.cursorPointer = GLFW.createStandardCursor(shape: shape)
        }

        deinit {
            GLFW.destroyCursor(cursor: cursorPointer)
        }

        func setCursor(window: OpaquePointer?) {
            GLFW.setCursor(window: window, cursor: cursorPointer)
        }
    }
}