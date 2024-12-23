// glfw/initializer.swift

import Foundation

extension GLFW {
    class Initializer {
        static let instance = Initializer()
        private var isInitialized = false

        private init() {
            if GLFW.initialize() == 0 {
                fatalError("Failed to initialize GLFW")
            }
            isInitialized = true
        }

        deinit {
            if isInitialized {
                GLFW.terminate()
            }
        }
    }
}