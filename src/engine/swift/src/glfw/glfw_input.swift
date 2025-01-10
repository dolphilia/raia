import Foundation

extension GLFW {
    class Input {

        // MARK: Input Modes

        static func rawMouseMotionSupported() -> Bool {
            return GLFW.rawMouseMotionSupported()
        }

        // MARK: Key and Mouse Input

        static func getKeyName(key: Int, scancode: Int) -> String? {
            return GLFW.getKeyName(key: key, scancode: scancode)
        }

        static func getKeyScancode(key: Int) -> Int {
            return GLFW.getKeyScancode(key: key)
        }

        // MARK: Joystick Input

        static func joystickPresent(jid: Int) -> Bool {
            return GLFW.joystickPresent(jid: jid)
        }

        static func getJoystickAxes(jid: Int) -> [Float] {
            var count: Int32 = 0
            guard let pointer = GLFW.getJoystickAxes(jid: jid, count: &count) else {
                return []
            }
            let buffer = UnsafeBufferPointer(start: pointer.assumingMemoryBound(to: Float.self), count: Int(count))
            return Array(buffer)
        }

        static func getJoystickButtons(jid: Int) -> [UInt8] {
            var count: Int32 = 0
            guard let pointer = GLFW.getJoystickButtons(jid: jid, count: &count) else {
                return []
            }
            let buffer = UnsafeBufferPointer(start: pointer, count: Int(count))
            return Array(buffer)
        }

        static func getJoystickHats(jid: Int) -> [UInt8] {
            var count: Int32 = 0
            guard let pointer = GLFW.getJoystickHats(jid: jid, count: &count) else {
                return []
            }
            let buffer = UnsafeBufferPointer(start: pointer, count: Int(count))
            return Array(buffer)
        }

        static func getJoystickName(jid: Int) -> String? {
            return GLFW.getJoystickName(jid: jid)
        }

        static func getJoystickGUID(jid: Int) -> String? {
            return GLFW.getJoystickGUID(jid: jid)
        }

        static func setJoystickUserPointer(jid: Int, pointer: UnsafeMutableRawPointer?) {
            GLFW.setJoystickUserPointer(jid: jid, pointer: pointer)
        }

        static func getJoystickUserPointer(jid: Int) -> UnsafeRawPointer? {
            return GLFW.getJoystickUserPointer(jid: jid).flatMap { UnsafeRawPointer($0) }
        }

        static func joystickIsGamepad(jid: Int) -> Bool {
            return GLFW.joystickIsGamepad(jid: jid)
        }

        static func setJoystickCallback(callback: @escaping GLFWjoystickfun) -> GLFWjoystickfun? {
            return GLFW.setJoystickCallback(callback: callback).map { unsafeBitCast($0, to: GLFWjoystickfun.self) }
        }

        static func updateGamepadMappings(string: String) -> Bool {
            return GLFW.updateGamepadMappings(string: string)
        }

        static func getGamepadName(jid: Int) -> String? {
            return GLFW.getGamepadName(jid: jid)
        }

        static func getGamepadState(jid: Int) -> (connected: Bool, state: UnsafeMutableRawPointer?) {
            var state: UnsafeMutableRawPointer? = nil
            let connected = GLFW.getGamepadState(jid: jid, state: &state) != 0
            return (connected, connected ? state : nil)
        }
    }
}
