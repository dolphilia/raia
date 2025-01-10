import Foundation

extension GLFW {
    class System {

        // MARK: 初期化
        
        static func initHint(hint: Int, value: Int) {
            GLFW.initHint(hint:hint, value:value)
        }

        // MARK: バージョン

        static func getVersion() -> (major: Int, minor: Int, rev: Int) {
            var major: Int = 0
            var minor: Int = 0
            var rev: Int = 0
            GLFW.getVersion(major:&major, minor:&minor, rev:&rev)
            return (major, minor, rev)
        }

        static func getVersionString() -> String? {
            return GLFW.getVersionString()
        }

        // MARK: エラー

        static func getError() -> (code: Int, description: String?)? {
            return GLFW.getError()
        }

        private static var swiftErrorCallback: ((Int, String?) -> Void)?

        private static let cErrorCallback: GLFWerrorfun = { errorCode, descriptionPointer in
            let description = descriptionPointer.map { String(cString: $0) }
            swiftErrorCallback?(Int(errorCode), description)
        }

        static func setErrorCallback(callback: @escaping (Int, String?) -> Void) -> GLFWerrorfun? {
            swiftErrorCallback = callback
            return GLFW.setErrorCallback(callback: cErrorCallback).map { unsafeBitCast($0, to: GLFWerrorfun.self) }
        }

        // MARK: コンテキスト

        static func getCurrentContext() -> UnsafeMutableRawPointer? {
            guard let windowPointer = GLFW.getCurrentContext() else { return nil }
            return windowPointer
        }

        static func swapInterval(interval: Int) {
            GLFW.swapInterval(interval:interval)
        }

        static func extensionSupported(extension_: String) -> Bool {
            return raia_glfw_extension_supported(extension_) != 0
        }

        static func getProcAddress(procname: String) -> (@convention(c) () -> Void)? {
            return GLFW.getProcAddress(procname:procname).map { unsafeBitCast($0, to: (@convention(c) () -> Void).self) }
        }
    }
}