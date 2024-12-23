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
            return GLFW.getJoystickAxes(jid: jid)
        }

        static func getJoystickButtons(jid: Int) -> [UInt8] {
            return GLFW.getJoystickButtons(jid: jid)
        }

        static func getJoystickHats(jid: Int) -> [UInt8] {
            return GLFW.getJoystickHats(jid: jid)
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
            return GLFW.setJoystickCallback(callback: callback)
        }

        static func updateGamepadMappings(string: String) -> Bool {
            return GLFW.updateGamepadMappings(string: string)
        }

        static func getGamepadName(jid: Int) -> String? {
            return GLFW.getGamepadName(jid: jid)
        }

        static func getGamepadState(jid: Int) -> (connected: Bool, state: GLFWgamepadstate?) {
            var state = GLFWgamepadstate()
            let connected = GLFW.getGamepadState(jid: jid, state: &state)
            return (connected, connected ? state : nil)
        }
    }
}
