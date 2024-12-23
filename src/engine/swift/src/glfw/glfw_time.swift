import Foundation

extension GLFW {
    class Time {
        static func getTime() -> Double {
            return GLFW.getTime()
        }

        static func setTime(_ time: Double) {
            GLFW.setTime(time:time)
        }

        static func getTimerValue() -> UInt64 {
            return GLFW.getTimerValue()
        }

        static func getTimerFrequency() -> UInt64 {
            return GLFW.getTimerFrequency()
        }
    }
}