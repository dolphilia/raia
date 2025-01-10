// glfw/_typealias.swift

import Foundation

extension GLFW {

    typealias GLFWwindowposfun = @convention(c) (OpaquePointer?, Int32, Int32) -> Void
    typealias GLFWwindowsizefun = @convention(c) (OpaquePointer?, Int32, Int32) -> Void
    typealias GLFWwindowclosefun = @convention(c) (OpaquePointer?) -> Void
    typealias GLFWwindowrefreshfun = @convention(c) (OpaquePointer?) -> Void
    typealias GLFWwindowfocusfun = @convention(c) (OpaquePointer?, Int32) -> Void
    typealias GLFWwindowiconifyfun = @convention(c) (OpaquePointer?, Int32) -> Void
    typealias GLFWwindowmaximizefun = @convention(c) (OpaquePointer?, Int32) -> Void
    typealias GLFWframebuffersizefun = @convention(c) (OpaquePointer?, Int32, Int32) -> Void
    typealias GLFWwindowcontentscalefun = @convention(c) (OpaquePointer?, Float, Float) -> Void
    typealias GLFWkeyfun = @convention(c) (OpaquePointer?, Int32, Int32, Int32, Int32) -> Void
    typealias GLFWcharfun = @convention(c) (OpaquePointer?, UInt32) -> Void
    typealias GLFWcharmodsfun = @convention(c) (OpaquePointer?, UInt32, Int32) -> Void
    typealias GLFWmousebuttonfun = @convention(c) (OpaquePointer?, Int32, Int32, Int32) -> Void
    typealias GLFWcursorposfun = @convention(c) (OpaquePointer?, Double, Double) -> Void
    typealias GLFWcursorenterfun = @convention(c) (OpaquePointer?, Int32) -> Void
    typealias GLFWscrollfun = @convention(c) (OpaquePointer?, Double, Double) -> Void
    typealias GLFWdropfun = @convention(c) (OpaquePointer?, Int32, UnsafePointer<UnsafePointer<Int8>>?) -> Void
    typealias GLFWerrorfun = @convention(c) (Int32, UnsafePointer<CChar>?) -> Void
    typealias GLFWjoystickfun = @convention(c) (Int32, Int32) -> Void
    typealias GLFWmonitorfun = @convention(c) (OpaquePointer?, Int32) -> Void
}