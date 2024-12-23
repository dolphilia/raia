import Foundation

extension GLFW {
    class Monitor {
        let monitorPointer: OpaquePointer?

        init(pointer: OpaquePointer?) {
            self.monitorPointer = pointer
        }

        // MARK: Monitor Management

        static func from(pointer: OpaquePointer?) -> Monitor? {
            guard let validPointer = pointer else { return nil }
            return Monitor(pointer: validPointer)
        }

        static func getMonitors() -> [Monitor] {
            return GLFW.getMonitors().compactMap { from(pointer: $0) }
        }

        static func getPrimaryMonitor() -> Monitor? {
            return from(pointer: GLFW.getPrimaryMonitor())
        }

        // MARK: Monitor Attributes

        func getPosition() -> (x: Int, y: Int) {
            var x = 0
            var y = 0
            GLFW.getMonitorPos(monitorPointer, xpos: &x, ypos: &y)
            return (x, y)
        }

        func getWorkArea() -> (x: Int, y: Int, width: Int, height: Int) {
            var x = 0
            var y = 0
            var width = 0
            var height = 0
            GLFW.getMonitorWorkarea(monitorPointer, xpos: &x, ypos: &y, width: &width, height: &height)
            return (x, y, width, height)
        }

        func getPhysicalSize() -> (widthMM: Int, heightMM: Int) {
            var widthMM = 0
            var heightMM = 0
            GLFW.getMonitorPhysicalSize(monitorPointer, widthMM: &widthMM, heightMM: &heightMM)
            return (widthMM, heightMM)
        }

        func getContentScale() -> (xScale: Float, yScale: Float) {
            var xScale: Float = 0.0
            var yScale: Float = 0.0
            GLFW.getMonitorContentScale(monitorPointer, xscale: &xScale, yscale: &yScale)
            return (xScale, yScale)
        }

        func getName() -> String? {
            return GLFW.getMonitorName(monitor: monitorPointer)
        }

        // MARK: User Pointer

        func setUserPointer(_ pointer: UnsafeRawPointer?) {
            GLFW.setMonitorUserPointer(monitor: monitorPointer, pointer: UnsafeMutableRawPointer(mutating: pointer))
        }

        func getUserPointer() -> UnsafeRawPointer? {
            return GLFW.getMonitorUserPointer(monitor: monitorPointer).flatMap { UnsafeRawPointer($0) }
        }

        // MARK: Video Modes

        func getVideoModes() -> [GLFWvidmode] {
            return GLFW.getVideoModes(monitor: monitorPointer)
        }

        func getVideoMode() -> GLFWvidmode? {
            return GLFW.getVideoMode(monitor: monitorPointer)
        }

        // MARK: Gamma and Gamma Ramp

        func setGamma(_ gamma: Float) {
            GLFW.setGamma(monitor: monitorPointer, gamma: gamma)
        }

        func getGammaRamp() -> GLFWgammaramp? {
            return GLFW.getGammaRamp(monitor: monitorPointer)
        }

        func setGammaRamp(_ ramp: GLFWgammaramp) {
            withUnsafePointer(to: ramp) { pointer in
                GLFW.setGammaRamp(monitor: monitorPointer, ramp: pointer)
            }
        }
    }
}
