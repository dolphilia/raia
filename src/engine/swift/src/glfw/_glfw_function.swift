// glfw/_function.swift

import Foundation

extension GLFW {

    // MARK: コンテキスト

    static func makeContextCurrent(window:UnsafeMutableRawPointer?) -> Void {
        raia_glfw_make_context_current(window)
    }

    static func getCurrentContext() -> UnsafeMutableRawPointer? {
        return raia_glfw_get_current_context();
    }

    static func swapInterval(interval:Int) -> Void {
        raia_glfw_swap_interval(Int32(interval))
    }

    static func extensionSupported(extension_:String) -> Int {
        return extension_.withCString { cString in
            return Int(raia_glfw_extension_supported(cString))
        }
    }

    static func getProcAddress(procname:String) -> UnsafeMutableRawPointer? {
        return procname.withCString { cString in
            return raia_glfw_get_proc_address(cString)
        }
    }

    // MARK: 初期化・バージョン・エラー

    static func initialize() -> Int {
        return Int(raia_glfw_init())
    }

    static func terminate() {
        raia_glfw_terminate()
    }

    static func initHint(hint: Int, value: Int) {
        raia_glfw_init_hint(Int32(hint), Int32(value))
    }

    static func getVersion(major: inout Int, minor: inout Int, rev: inout Int) {
        var majorTemp: Int32 = 0
        var minorTemp: Int32 = 0
        var revTemp: Int32 = 0
        raia_glfw_get_version(&majorTemp, &minorTemp, &revTemp)
        major = Int(majorTemp)
        minor = Int(minorTemp)
        rev = Int(revTemp)
    }

    static func getVersionString() -> String? {
        guard let versionString = raia_glfw_get_version_string() else {
            return nil
        }
        return String(cString: versionString)
    }

    static func getError() -> (code: Int, description: String?) {
        var descriptionPointer: UnsafePointer<CChar>? = nil
        let errorCode = Int(raia_glfw_get_error(&descriptionPointer))
        let description = descriptionPointer != nil ? String(cString: descriptionPointer!) : nil
        return (errorCode, description)
    }

    static func setErrorCallback(callback: @escaping GLFWerrorfun) -> UnsafeMutableRawPointer? {
        return raia_glfw_set_error_callback(unsafeBitCast(callback, to: UnsafeMutableRawPointer.self))
    }

    // MARK: 入力

    static func getInputMode(window: UnsafeMutableRawPointer?, mode: Int) -> Int {
        return Int(raia_glfw_get_input_mode(window, Int32(mode)))
    }

    static func setInputMode(window: UnsafeMutableRawPointer?, mode: Int, value: Int) {
        raia_glfw_set_input_mode(window, Int32(mode), Int32(value))
    }

    static func rawMouseMotionSupported() -> Bool {
        return raia_glfw_raw_mouse_motion_supported() != 0
    }

    static func getKeyName(key: Int, scancode: Int) -> String? {
        guard let keyName = raia_glfw_get_key_name(Int32(key), Int32(scancode)) else {
            return nil
        }
        return String(cString: keyName)
    }

    static func getKeyScancode(key: Int) -> Int {
        return Int(raia_glfw_get_key_scancode(Int32(key)))
    }

    static func getKey(window: UnsafeMutableRawPointer?, key: Int) -> Int {
        return Int(raia_glfw_get_key(window, Int32(key)))
    }

    static func getMouseButton(window: UnsafeMutableRawPointer?, button: Int) -> Int {
        return Int(raia_glfw_get_mouse_button(window, Int32(button)))
    }

    static func getCursorPos(window: UnsafeMutableRawPointer?, xpos: inout Double, ypos: inout Double) {
        var xposTemp: Double = 0.0
        var yposTemp: Double = 0.0
        raia_glfw_get_cursor_pos(window, &xposTemp, &yposTemp)
        xpos = xposTemp
        ypos = yposTemp
    }

    static func setCursorPos(window: UnsafeMutableRawPointer?, xpos: Double, ypos: Double) {
        raia_glfw_set_cursor_pos(window, xpos, ypos)
    }

    static func createCursor(image: UnsafeMutableRawPointer?, xhot: Int, yhot: Int) -> UnsafeMutableRawPointer? {
        return raia_glfw_create_cursor(image, Int32(xhot), Int32(yhot))
    }

    static func createStandardCursor(shape: Int) -> UnsafeMutableRawPointer? {
        return raia_glfw_create_standard_cursor(Int32(shape))
    }

    static func destroyCursor(cursor: UnsafeMutableRawPointer?) {
        raia_glfw_destroy_cursor(cursor)
    }

    static func setCursor(window: UnsafeMutableRawPointer?, cursor: UnsafeMutableRawPointer?) {
        raia_glfw_set_cursor(window, cursor)
    }

    static func setKeyCallback(window: UnsafeMutableRawPointer?, callback: @escaping GLFWkeyfun) -> UnsafeMutableRawPointer? {
        return raia_glfw_set_key_callback(window, unsafeBitCast(callback, to: UnsafeMutableRawPointer.self))
    }

    static func setCharCallback(window: UnsafeMutableRawPointer?, callback: @escaping GLFWcharfun) -> UnsafeMutableRawPointer? {
        return raia_glfw_set_char_callback(window, unsafeBitCast(callback, to: UnsafeMutableRawPointer.self))
    }

    static func setCharModsCallback(window: UnsafeMutableRawPointer?, callback: @escaping GLFWcharmodsfun) -> UnsafeMutableRawPointer? {
        return raia_glfw_set_char_mods_callback(window, unsafeBitCast(callback, to: UnsafeMutableRawPointer.self))
    }

    static func setMouseButtonCallback(window: UnsafeMutableRawPointer?, callback: @escaping GLFWmousebuttonfun) -> UnsafeMutableRawPointer? {
        return raia_glfw_set_mouse_button_callback(window, unsafeBitCast(callback, to: UnsafeMutableRawPointer.self))
    }

    static func setCursorPosCallback(window: UnsafeMutableRawPointer?, callback: @escaping GLFWcursorposfun) -> UnsafeMutableRawPointer? {
        return raia_glfw_set_cursor_pos_callback(window, unsafeBitCast(callback, to: UnsafeMutableRawPointer.self))
    }

    static func setCursorEnterCallback(window: UnsafeMutableRawPointer?, callback: @escaping GLFWcursorenterfun) -> UnsafeMutableRawPointer? {
        return raia_glfw_set_cursor_enter_callback(window, unsafeBitCast(callback, to: UnsafeMutableRawPointer.self))
    }

    static func setScrollCallback(window: UnsafeMutableRawPointer?, callback: @escaping GLFWscrollfun) -> UnsafeMutableRawPointer? {
        return raia_glfw_set_scroll_callback(window, unsafeBitCast(callback, to: UnsafeMutableRawPointer.self))
    }

    static func setDropCallback(window: UnsafeMutableRawPointer?, callback: @escaping GLFWdropfun) -> UnsafeMutableRawPointer? {
        return raia_glfw_set_drop_callback(window, unsafeBitCast(callback, to: UnsafeMutableRawPointer.self))
    }

    static func joystickPresent(jid: Int) -> Bool {
        return raia_glfw_joystick_present(Int32(jid)) != 0
    }

    static func getJoystickAxes(jid: Int, count: UnsafeMutableRawPointer?) -> UnsafeRawPointer? {
        return raia_glfw_get_joystick_axes(Int32(jid), count)
    }

    static func getJoystickButtons(jid: Int, count: UnsafeMutableRawPointer?) -> UnsafePointer<UInt8>? {
        return raia_glfw_get_joystick_buttons(Int32(jid), count)
    }

    static func getJoystickHats(jid: Int, count: UnsafeMutableRawPointer?) -> UnsafePointer<UInt8>? {
        return raia_glfw_get_joystick_hats(Int32(jid), count)
    }

    static func getJoystickName(jid: Int) -> String? {
        guard let name = raia_glfw_get_joystick_name(Int32(jid)) else {
            return nil
        }
        return String(cString: name)
    }

    static func getJoystickGUID(jid: Int) -> String? {
        guard let guid = raia_glfw_get_joystick_guid(Int32(jid)) else {
            return nil
        }
        return String(cString: guid)
    }

    static func setJoystickUserPointer(jid: Int, pointer: UnsafeMutableRawPointer?) {
        raia_glfw_set_joystick_user_pointer(Int32(jid), pointer)
    }

    static func getJoystickUserPointer(jid: Int) -> UnsafeMutableRawPointer? {
        return raia_glfw_get_joystick_user_pointer(Int32(jid))
    }

    static func joystickIsGamepad(jid: Int) -> Bool {
        return raia_glfw_joystick_is_gamepad(Int32(jid)) != 0
    }

    static func setJoystickCallback(callback: @escaping GLFWjoystickfun) -> UnsafeMutableRawPointer? {
        return raia_glfw_set_joystick_callback(unsafeBitCast(callback, to: UnsafeMutableRawPointer.self))
    }

    static func updateGamepadMappings(string: String) -> Bool {
        return string.withCString { cString in
            return raia_glfw_update_gamepad_mappings(cString) != 0
        }
    }

    static func getGamepadName(jid: Int) -> String? {
        guard let name = raia_glfw_get_gamepad_name(Int32(jid)) else {
            return nil
        }
        return String(cString: name)
    }

    static func getGamepadState(jid: Int, state: UnsafeMutableRawPointer?) -> Int {
        return Int(raia_glfw_get_gamepad_state(Int32(jid), state))
    }

    static func setClipboardString(window: UnsafeMutableRawPointer?, string: String) {
        string.withCString { cString in
            raia_glfw_set_clipboard_string(window, cString)
        }
    }

    static func getClipboardString(window: UnsafeMutableRawPointer?) -> String? {
        guard let clipboardString = raia_glfw_get_clipboard_string(window) else {
            return nil
        }
        return String(cString: clipboardString)
    }

    static func getTime() -> Double {
        return raia_glfw_get_time()
    }

    static func setTime(time: Double) {
        raia_glfw_set_time(time)
    }

    static func getTimerValue() -> UInt64 {
        return raia_glfw_get_timer_value()
    }

    static func getTimerFrequency() -> UInt64 {
        return raia_glfw_get_timer_frequency()
    }

    // MARK: モニター

    static func getMonitors() -> [UnsafeMutableRawPointer?] {
        var count: Int32 = 0
        guard let monitors = raia_glfw_get_monitors(&count) else {
            return []
        }
        return Array(UnsafeBufferPointer(start: monitors, count: Int(count)))
    }

    static func getPrimaryMonitor() -> UnsafeMutableRawPointer? {
        return raia_glfw_get_primary_monitor()
    }

    static func getMonitorPos(monitor: UnsafeMutableRawPointer?, xpos: inout Int, ypos: inout Int) {
        var xposTemp: Int32 = 0
        var yposTemp: Int32 = 0
        raia_glfw_get_monitor_pos(monitor, &xposTemp, &yposTemp)
        xpos = Int(xposTemp)
        ypos = Int(yposTemp)
    }

    static func getMonitorWorkarea(monitor: UnsafeMutableRawPointer?, xpos: inout Int, ypos: inout Int, width: inout Int, height: inout Int) {
        var xposTemp: Int32 = 0
        var yposTemp: Int32 = 0
        var widthTemp: Int32 = 0
        var heightTemp: Int32 = 0
        raia_glfw_get_monitor_workarea(monitor, &xposTemp, &yposTemp, &widthTemp, &heightTemp)
        xpos = Int(xposTemp)
        ypos = Int(yposTemp)
        width = Int(widthTemp)
        height = Int(heightTemp)
    }

    static func getMonitorPhysicalSize(monitor: UnsafeMutableRawPointer?, widthMM: inout Int, heightMM: inout Int) {
        var widthMMTemp: Int32 = 0
        var heightMMTemp: Int32 = 0
        raia_glfw_get_monitor_physical_size(monitor, &widthMMTemp, &heightMMTemp)
        widthMM = Int(widthMMTemp)
        heightMM = Int(heightMMTemp)
    }

    static func getMonitorContentScale(monitor: UnsafeMutableRawPointer?, xscale: inout Float, yscale: inout Float) {
        var xscaleTemp: Float = 0.0
        var yscaleTemp: Float = 0.0
        raia_glfw_get_monitor_content_scale(monitor, &xscaleTemp, &yscaleTemp)
        xscale = xscaleTemp
        yscale = yscaleTemp
    }

    static func getMonitorName(monitor: UnsafeMutableRawPointer?) -> String? {
        guard let name = raia_glfw_get_monitor_name(monitor) else {
            return nil
        }
        return String(cString: name)
    }

    static func setMonitorUserPointer(monitor: UnsafeMutableRawPointer?, pointer: UnsafeMutableRawPointer?) {
        raia_glfw_set_monitor_user_pointer(monitor, pointer)
    }

    static func getMonitorUserPointer(monitor: UnsafeMutableRawPointer?) -> UnsafeMutableRawPointer? {
        return raia_glfw_get_monitor_user_pointer(monitor)
    }

    static func setMonitorCallback(callback: @escaping GLFWmonitorfun) -> UnsafeMutableRawPointer? {
        return raia_glfw_set_monitor_callback(unsafeBitCast(callback, to: UnsafeMutableRawPointer.self))
    }

    static func getVideoModes(monitor: UnsafeMutableRawPointer?, count: UnsafeMutableRawPointer?) -> UnsafeRawPointer? {
        return raia_glfw_get_video_modes(monitor, count)
    }

    static func getVideoMode(monitor: UnsafeMutableRawPointer?) -> UnsafeRawPointer? {
        return raia_glfw_get_video_mode(monitor)
    }

    static func setGamma(monitor: UnsafeMutableRawPointer?, gamma: Float) {
        raia_glfw_set_gamma(monitor, gamma)
    }

    static func getGammaRamp(monitor: UnsafeMutableRawPointer?) -> UnsafeRawPointer? {
        return raia_glfw_get_gamma_ramp(monitor)
    }

    static func setGammaRamp(monitor: UnsafeMutableRawPointer?, ramp: UnsafeRawPointer?) {
        raia_glfw_set_gamma_ramp(monitor, ramp)
    }

    // MARK: Vulkanサポート

    static func vulkanSupported() -> Int {
        return Int(raia_glfw_vulkan_supported())
    }

    static func getRequiredInstanceExtensions() -> [String]? {
        var count: UInt32 = 0
        guard let extensions = raia_glfw_get_required_instance_extensions(&count) else {
            return nil
        }
        return (0..<Int(count)).compactMap { i in
            extensions[i].flatMap { String(cString: $0) }
        }
    }

    // MARK: ウィンドウ

    static func defaultWindowHints() {
        raia_glfw_default_window_hints()
    }

    static func windowHint(hint: Int, value: Int) {
        raia_glfw_window_hint(Int32(hint), Int32(value))
    }

    static func windowHintString(hint: Int, value: String) {
        value.withCString { cString in
            raia_glfw_window_hint_string(Int32(hint), cString)
        }
    }

    static func createWindow(width: Int, height: Int, title: String, monitor: UnsafeMutableRawPointer?, share: UnsafeMutableRawPointer?) -> UnsafeMutableRawPointer? {
        return title.withCString { cString in
            raia_glfw_create_window(Int32(width), Int32(height), cString, monitor, share)
        }
    }

    static func destroyWindow(window: UnsafeMutableRawPointer?) {
        raia_glfw_destroy_window(window)
    }

    static func windowShouldClose(window: UnsafeMutableRawPointer?) -> Int {
        return Int(raia_glfw_window_should_close(window))
    }

    static func setWindowShouldClose(window: UnsafeMutableRawPointer?, value: Int) {
        raia_glfw_set_window_should_close(window, Int32(value))
    }

    static func setWindowTitle(window: UnsafeMutableRawPointer?, title: String) {
        title.withCString { cString in
            raia_glfw_set_window_title(window, cString)
        }
    }

    static func setWindowIcon(window: UnsafeMutableRawPointer?, count: Int, images: UnsafeMutableRawPointer?) {
        raia_glfw_set_window_icon(window, Int32(count), images)
    }

    static func getWindowPos(window: UnsafeMutableRawPointer?, xpos: inout Int, ypos: inout Int) {
        var x: Int32 = 0
        var y: Int32 = 0
        raia_glfw_get_window_pos(window, &x, &y)
        xpos = Int(x)
        ypos = Int(y)
    }

    static func setWindowPos(window: UnsafeMutableRawPointer?, xpos: Int, ypos: Int) {
        raia_glfw_set_window_pos(window, Int32(xpos), Int32(ypos))
    }

    static func getWindowSize(window: UnsafeMutableRawPointer?, width: inout Int, height: inout Int) {
        var w: Int32 = 0
        var h: Int32 = 0
        raia_glfw_get_window_size(window, &w, &h)
        width = Int(w)
        height = Int(h)
    }

    static func setWindowSizeLimits(window: UnsafeMutableRawPointer?, minWidth: Int, minHeight: Int, maxWidth: Int, maxHeight: Int) {
        raia_glfw_set_window_size_limits(window, Int32(minWidth), Int32(minHeight), Int32(maxWidth), Int32(maxHeight))
    }

    static func setWindowAspectRatio(window: UnsafeMutableRawPointer?, numer: Int, denom: Int) {
        raia_glfw_set_window_aspect_ratio(window, Int32(numer), Int32(denom))
    }

    static func setWindowSize(window: UnsafeMutableRawPointer?, width: Int, height: Int) {
        raia_glfw_set_window_size(window, Int32(width), Int32(height))
    }

    static func getFramebufferSize(window: UnsafeMutableRawPointer?, width: inout Int, height: inout Int) {
        var w: Int32 = 0
        var h: Int32 = 0
        raia_glfw_get_framebuffer_size(window, &w, &h)
        width = Int(w)
        height = Int(h)
    }

    static func getWindowFrameSize(window: UnsafeMutableRawPointer?, left: inout Int, top: inout Int, right: inout Int, bottom: inout Int) {
        var l: Int32 = 0
        var t: Int32 = 0
        var r: Int32 = 0
        var b: Int32 = 0
        raia_glfw_get_window_frame_size(window, &l, &t, &r, &b)
        left = Int(l)
        top = Int(t)
        right = Int(r)
        bottom = Int(b)
    }

    static func getWindowContentScale(window: UnsafeMutableRawPointer?, xscale: inout Float, yscale: inout Float) {
        var x: Float = 0.0
        var y: Float = 0.0
        raia_glfw_get_window_content_scale(window, &x, &y)
        xscale = x
        yscale = y
    }

    static func getWindowOpacity(window: UnsafeMutableRawPointer?) -> Float {
        return raia_glfw_get_window_opacity(window)
    }

    static func setWindowOpacity(window: UnsafeMutableRawPointer?, opacity: Float) {
        raia_glfw_set_window_opacity(window, opacity)
    }

    static func iconifyWindow(window: UnsafeMutableRawPointer?) {
        raia_glfw_iconify_window(window)
    }

    static func restoreWindow(window: UnsafeMutableRawPointer?) {
        raia_glfw_restore_window(window)
    }

    static func maximizeWindow(window: UnsafeMutableRawPointer?) {
        raia_glfw_maximize_window(window)
    }

    static func showWindow(window: UnsafeMutableRawPointer?) {
        raia_glfw_show_window(window)
    }

    static func hideWindow(window: UnsafeMutableRawPointer?) {
        raia_glfw_hide_window(window)
    }

    static func focusWindow(window: UnsafeMutableRawPointer?) {
        raia_glfw_focus_window(window)
    }

    static func requestWindowAttention(window: UnsafeMutableRawPointer?) {
        raia_glfw_request_window_attention(window)
    }

    static func getWindowMonitor(window: UnsafeMutableRawPointer?) -> UnsafeMutableRawPointer? {
        return raia_glfw_get_window_monitor(window)
    }

    static func setWindowMonitor(window: UnsafeMutableRawPointer?, monitor: UnsafeMutableRawPointer?, xpos: Int, ypos: Int, width: Int, height: Int, refreshRate: Int) {
        raia_glfw_set_window_monitor(window, monitor, Int32(xpos), Int32(ypos), Int32(width), Int32(height), Int32(refreshRate))
    }

    static func getWindowAttrib(window: UnsafeMutableRawPointer?, attrib: Int) -> Int {
        return Int(raia_glfw_get_window_attrib(window, Int32(attrib)))
    }

    static func setWindowAttrib(window: UnsafeMutableRawPointer?, attrib: Int, value: Int) {
        raia_glfw_set_window_attrib(window, Int32(attrib), Int32(value))
    }

    static func setWindowUserPointer(window: UnsafeMutableRawPointer?, pointer: UnsafeRawPointer?) {
        raia_glfw_set_window_user_pointer(window, UnsafeMutableRawPointer(mutating: pointer))
    }

    static func getWindowUserPointer(window: UnsafeMutableRawPointer?) -> UnsafeRawPointer? {
        return UnsafeRawPointer(raia_glfw_get_window_user_pointer(window))
    }

    static func setWindowPosCallback(window: UnsafeMutableRawPointer?, callback: @escaping GLFWwindowposfun) -> UnsafeMutableRawPointer? {
        return raia_glfw_set_window_pos_callback(window, unsafeBitCast(callback, to: UnsafeMutableRawPointer.self))
    }

    static func setWindowSizeCallback(window: UnsafeMutableRawPointer?, callback: @escaping GLFWwindowsizefun) -> UnsafeMutableRawPointer? {
        return raia_glfw_set_window_size_callback(window, unsafeBitCast(callback, to: UnsafeMutableRawPointer.self))
    }

    static func setWindowCloseCallback(window: UnsafeMutableRawPointer?, callback: @escaping GLFWwindowclosefun) -> UnsafeMutableRawPointer? {
        return raia_glfw_set_window_close_callback(window, unsafeBitCast(callback, to: UnsafeMutableRawPointer.self))
    }

    static func setWindowRefreshCallback(window: UnsafeMutableRawPointer?, callback: @escaping GLFWwindowrefreshfun) -> UnsafeMutableRawPointer? {
        return raia_glfw_set_window_refresh_callback(window, unsafeBitCast(callback, to: UnsafeMutableRawPointer.self))
    }

    static func setWindowFocusCallback(window: UnsafeMutableRawPointer?, callback: @escaping GLFWwindowfocusfun) -> UnsafeMutableRawPointer? {
        return raia_glfw_set_window_focus_callback(window, unsafeBitCast(callback, to: UnsafeMutableRawPointer.self))
    }

    static func setWindowIconifyCallback(window: UnsafeMutableRawPointer?, callback: @escaping GLFWwindowiconifyfun) -> UnsafeMutableRawPointer? {
        return raia_glfw_set_window_iconify_callback(window, unsafeBitCast(callback, to: UnsafeMutableRawPointer.self))
    }

    static func setWindowMaximizeCallback(window: UnsafeMutableRawPointer?, callback: @escaping GLFWwindowmaximizefun) -> UnsafeMutableRawPointer? {
        return raia_glfw_set_window_maximize_callback(window, unsafeBitCast(callback, to: UnsafeMutableRawPointer.self))
    }

    static func setFramebufferSizeCallback(window: UnsafeMutableRawPointer?, callback: @escaping GLFWframebuffersizefun) -> UnsafeMutableRawPointer? {
        return raia_glfw_set_framebuffer_size_callback(window, unsafeBitCast(callback, to: UnsafeMutableRawPointer.self))
    }

    static func setWindowContentScaleCallback(window: UnsafeMutableRawPointer?, callback: @escaping GLFWwindowcontentscalefun) -> UnsafeMutableRawPointer? {
        return raia_glfw_set_window_content_scale_callback(window, unsafeBitCast(callback, to: UnsafeMutableRawPointer.self))
    }

    static func pollEvents() {
        raia_glfw_poll_events()
    }

    static func waitEvents() {
        raia_glfw_wait_events()
    }

    static func waitEventsTimeout(timeout: Double) {
        raia_glfw_wait_events_timeout(timeout)
    }

    static func postEmptyEvent() {
        raia_glfw_post_empty_event()
    }

    static func swapBuffers(window: UnsafeMutableRawPointer?) {
        raia_glfw_swap_buffers(window)
    }
}