// glfw/_namespace.swift

enum GLFW {

    // MARK: Typealias

    typealias GLFWwindowposfun = @convention(c) (OpaquePointer?, Int32, Int32) -> Void
    typealias GLFWwindowsizefun = @convention(c) (OpaquePointer?, Int32, Int32) -> Void
    typealias GLFWwindowclosefun = @convention(c) (OpaquePointer?) -> Void
    typealias GLFWwindowrefreshfun = @convention(c) (OpaquePointer?) -> Void
    typealias GLFWwindowfocusfun = @convention(c) (OpaquePointer?, Int32) -> Void
    typealias GLFWwindowiconifyfun = @convention(c) (OpaquePointer?, Int32) -> Void
    typealias GLFWwindowmaximizefun = @convention(c) (OpaquePointer?, Int32) -> Void
    typealias GLFWframebuffersizefun = @convention(c) (OpaquePointer?, Int32, Int32) -> Void
    typealias GLFWwindowcontentscalefun = @convention(c) (OpaquePointer?, Float, Float) -> Void
    
    // MARK: -コンテキスト

    static func makeContextCurrent(_ window:OpaquePointer?) -> Void {
        raia_glfw_make_context_current(window)
    }

    static func getCurrentContext() -> OpaquePointer? {
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

    static func getProcAddress(procname:String) -> (@convention(c) () -> Void)? {
        return procname.withCString { cString in
            return raia_glfw_get_proc_address(cString)
        }
    }

    // MARK: - 初期化・バージョン・エラー

    static func initialize() -> Int {
        return Int(raia_glfw_init())
    }

    static func terminate() {
        raia_glfw_terminate()
    }

    static func initHint(hint: Int, value: Int) {
        raia_glfw_init_hint(Int32(hint), Int32(value))
    }

    static func getVersion() -> (major: Int, minor: Int, rev: Int) {
        var major: Int32 = 0
        var minor: Int32 = 0
        var rev: Int32 = 0
        raia_glfw_get_version(&major, &minor, &rev)
        return (Int(major), Int(minor), Int(rev))
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

    static func setErrorCallback(callback: @escaping GLFWerrorfun) -> GLFWerrorfun? {
        return raia_glfw_set_error_callback(callback)
    }

    // MARK: - 入力

    static func getInputMode(window: OpaquePointer?, mode: Int) -> Int {
        return Int(raia_glfw_get_input_mode(window, Int32(mode)))
    }

    static func setInputMode(window: OpaquePointer?, mode: Int, value: Int) {
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

    static func getKey(window: OpaquePointer?, key: Int) -> Int {
        return Int(raia_glfw_get_key(window, Int32(key)))
    }

    static func getMouseButton(window: OpaquePointer?, button: Int) -> Int {
        return Int(raia_glfw_get_mouse_button(window, Int32(button)))
    }

    static func getCursorPos(window: OpaquePointer?) -> (xpos: Double, ypos: Double) {
        var xpos: Double = 0.0
        var ypos: Double = 0.0
        raia_glfw_get_cursor_pos(window, &xpos, &ypos)
        return (xpos, ypos)
    }

    static func setCursorPos(window: OpaquePointer?, xpos: Double, ypos: Double) {
        raia_glfw_set_cursor_pos(window, xpos, ypos)
    }

    static func createCursor(image: UnsafePointer<GLFWimage>?, xhot: Int, yhot: Int) -> OpaquePointer? {
        return raia_glfw_create_cursor(image, Int32(xhot), Int32(yhot))
    }

    static func createStandardCursor(shape: Int) -> OpaquePointer? {
        return raia_glfw_create_standard_cursor(Int32(shape))
    }

    static func destroyCursor(cursor: OpaquePointer?) {
        raia_glfw_destroy_cursor(cursor)
    }

    static func setCursor(window: OpaquePointer?, cursor: OpaquePointer?) {
        raia_glfw_set_cursor(window, cursor)
    }

    static func setKeyCallback(window: OpaquePointer?, callback: @escaping GLFWkeyfun) -> GLFWkeyfun? {
        return raia_glfw_set_key_callback(window, callback)
    }

    static func setCharCallback(window: OpaquePointer?, callback: @escaping GLFWcharfun) -> GLFWcharfun? {
        return raia_glfw_set_char_callback(window, callback)
    }

    static func setCharModsCallback(window: OpaquePointer?, callback: @escaping GLFWcharmodsfun) -> GLFWcharmodsfun? {
        return raia_glfw_set_char_mods_callback(window, callback)
    }

    static func setMouseButtonCallback(window: OpaquePointer?, callback: @escaping GLFWmousebuttonfun) -> GLFWmousebuttonfun? {
        return raia_glfw_set_mouse_button_callback(window, callback)
    }

    static func setCursorPosCallback(window: OpaquePointer?, callback: @escaping GLFWcursorposfun) -> GLFWcursorposfun? {
        return raia_glfw_set_cursor_pos_callback(window, callback)
    }

    static func setCursorEnterCallback(window: OpaquePointer?, callback: @escaping GLFWcursorenterfun) -> GLFWcursorenterfun? {
        return raia_glfw_set_cursor_enter_callback(window, callback)
    }

    static func setScrollCallback(window: OpaquePointer?, callback: @escaping GLFWscrollfun) -> GLFWscrollfun? {
        return raia_glfw_set_scroll_callback(window, callback)
    }

    static func setDropCallback(window: OpaquePointer?, callback: @escaping GLFWdropfun) -> GLFWdropfun? {
        return raia_glfw_set_drop_callback(window, callback)
    }

    static func joystickPresent(jid: Int) -> Bool {
        return raia_glfw_joystick_present(Int32(jid)) != 0
    }

    static func getJoystickAxes(jid: Int) -> [Float] {
        var count: Int32 = 0
        guard let axes = raia_glfw_get_joystick_axes(Int32(jid), &count) else {
            return []
        }
        return Array(UnsafeBufferPointer(start: axes, count: Int(count)))
    }

    static func getJoystickButtons(jid: Int) -> [UInt8] {
        var count: Int32 = 0
        guard let buttons = raia_glfw_get_joystick_buttons(Int32(jid), &count) else {
            return []
        }
        return Array(UnsafeBufferPointer(start: buttons, count: Int(count)))
    }

    static func getJoystickHats(jid: Int) -> [UInt8] {
        var count: Int32 = 0
        guard let hats = raia_glfw_get_joystick_hats(Int32(jid), &count) else {
            return []
        }
        return Array(UnsafeBufferPointer(start: hats, count: Int(count)))
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

    static func setJoystickCallback(callback: @escaping GLFWjoystickfun) -> GLFWjoystickfun? {
        return raia_glfw_set_joystick_callback(callback)
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

    static func getGamepadState(jid: Int, state: inout GLFWgamepadstate) -> Bool {
        return raia_glfw_get_gamepad_state(Int32(jid), &state) != 0
    }

    static func setClipboardString(window: OpaquePointer?, string: String) {
        string.withCString { cString in
            raia_glfw_set_clipboard_string(window, cString)
        }
    }

    static func getClipboardString(window: OpaquePointer?) -> String? {
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

    // MARK: - モニター

    static func getMonitors() -> [OpaquePointer?] {
        var count: Int32 = 0
        guard let monitors = raia_glfw_get_monitors(&count) else {
            return []
        }
        return Array(UnsafeBufferPointer(start: monitors, count: Int(count)))
    }

    static func getPrimaryMonitor() -> OpaquePointer? {
        return raia_glfw_get_primary_monitor()
    }

    static func getMonitorPos(monitor: OpaquePointer?) -> (xpos: Int, ypos: Int) {
        var xpos: Int32 = 0
        var ypos: Int32 = 0
        raia_glfw_get_monitor_pos(monitor, &xpos, &ypos)
        return (Int(xpos), Int(ypos))
    }

    static func getMonitorWorkarea(monitor: OpaquePointer?) -> (xpos: Int, ypos: Int, width: Int, height: Int) {
        var xpos: Int32 = 0
        var ypos: Int32 = 0
        var width: Int32 = 0
        var height: Int32 = 0
        raia_glfw_get_monitor_workarea(monitor, &xpos, &ypos, &width, &height)
        return (Int(xpos), Int(ypos), Int(width), Int(height))
    }

    static func getMonitorPhysicalSize(monitor: OpaquePointer?) -> (widthMM: Int, heightMM: Int) {
        var widthMM: Int32 = 0
        var heightMM: Int32 = 0
        raia_glfw_get_monitor_physical_size(monitor, &widthMM, &heightMM)
        return (Int(widthMM), Int(heightMM))
    }

    static func getMonitorContentScale(monitor: OpaquePointer?) -> (xscale: Float, yscale: Float) {
        var xscale: Float = 0.0
        var yscale: Float = 0.0
        raia_glfw_get_monitor_content_scale(monitor, &xscale, &yscale)
        return (xscale, yscale)
    }

    static func getMonitorName(monitor: OpaquePointer?) -> String? {
        guard let name = raia_glfw_get_monitor_name(monitor) else {
            return nil
        }
        return String(cString: name)
    }

    static func setMonitorUserPointer(monitor: OpaquePointer?, pointer: UnsafeMutableRawPointer?) {
        raia_glfw_set_monitor_user_pointer(monitor, pointer)
    }

    static func getMonitorUserPointer(monitor: OpaquePointer?) -> UnsafeMutableRawPointer? {
        return raia_glfw_get_monitor_user_pointer(monitor)
    }

    static func setMonitorCallback(callback: @escaping GLFWmonitorfun) -> GLFWmonitorfun? {
        return raia_glfw_set_monitor_callback(callback)
    }

    static func getVideoModes(monitor: OpaquePointer?) -> [GLFWvidmode] {
        var count: Int32 = 0
        guard let modes = raia_glfw_get_video_modes(monitor, &count) else {
            return []
        }
        return Array(UnsafeBufferPointer(start: modes, count: Int(count)))
    }

    static func getVideoMode(monitor: OpaquePointer?) -> GLFWvidmode? {
        guard let mode = raia_glfw_get_video_mode(monitor) else {
            return nil
        }
        return mode.pointee
    }

    static func setGamma(monitor: OpaquePointer?, gamma: Float) {
        raia_glfw_set_gamma(monitor, gamma)
    }

    static func getGammaRamp(monitor: OpaquePointer?) -> GLFWgammaramp? {
        guard let ramp = raia_glfw_get_gamma_ramp(monitor) else {
            return nil
        }
        return ramp.pointee
    }

    static func setGammaRamp(monitor: OpaquePointer?, ramp: UnsafePointer<GLFWgammaramp>?) {
        raia_glfw_set_gamma_ramp(monitor, ramp)
    }

    // MARK: - Vulkanサポート

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

    // MARK: - ウィンドウ

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

    static func createWindow(width: Int, height: Int, title: String, monitor: OpaquePointer?, share: OpaquePointer?) -> OpaquePointer? {
        return title.withCString { cString in
            raia_glfw_create_window(Int32(width), Int32(height), cString, monitor, share)
        }
    }

    static func destroyWindow(_ window: OpaquePointer?) {
        raia_glfw_destroy_window(window)
    }

    static func windowShouldClose(_ window: OpaquePointer?) -> Int {
        return Int(raia_glfw_window_should_close(window))
    }

    static func setWindowShouldClose(_ window: OpaquePointer?, value: Int) {
        raia_glfw_set_window_should_close(window, Int32(value))
    }

    static func setWindowTitle(_ window: OpaquePointer?, title: String) {
        title.withCString { cString in
            raia_glfw_set_window_title(window, cString)
        }
    }

    static func setWindowIcon(_ window: OpaquePointer?, count: Int, images: UnsafePointer<GLFWimage>?) {
        raia_glfw_set_window_icon(window, Int32(count), images)
    }

    static func getWindowPos(_ window: OpaquePointer?, xpos: inout Int, ypos: inout Int) {
        var x: Int32 = 0
        var y: Int32 = 0
        raia_glfw_get_window_pos(window, &x, &y)
        xpos = Int(x)
        ypos = Int(y)
    }

    static func setWindowPos(_ window: OpaquePointer?, xpos: Int, ypos: Int) {
        raia_glfw_set_window_pos(window, Int32(xpos), Int32(ypos))
    }

    static func getWindowSize(_ window: OpaquePointer?, width: inout Int, height: inout Int) {
        var w: Int32 = 0
        var h: Int32 = 0
        raia_glfw_get_window_size(window, &w, &h)
        width = Int(w)
        height = Int(h)
    }

    static func setWindowSizeLimits(_ window: OpaquePointer?, minWidth: Int, minHeight: Int, maxWidth: Int, maxHeight: Int) {
        raia_glfw_set_window_size_limits(window, Int32(minWidth), Int32(minHeight), Int32(maxWidth), Int32(maxHeight))
    }

    static func setWindowAspectRatio(_ window: OpaquePointer?, numer: Int, denom: Int) {
        raia_glfw_set_window_aspect_ratio(window, Int32(numer), Int32(denom))
    }

    static func setWindowSize(_ window: OpaquePointer?, width: Int, height: Int) {
        raia_glfw_set_window_size(window, Int32(width), Int32(height))
    }

    static func getFramebufferSize(_ window: OpaquePointer?, width: inout Int, height: inout Int) {
        var w: Int32 = 0
        var h: Int32 = 0
        raia_glfw_get_framebuffer_size(window, &w, &h)
        width = Int(w)
        height = Int(h)
    }

    static func getWindowFrameSize(_ window: OpaquePointer?, left: inout Int, top: inout Int, right: inout Int, bottom: inout Int) {
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

    static func getWindowContentScale(_ window: OpaquePointer?, xscale: inout Float, yscale: inout Float) {
        var x: Float = 0.0
        var y: Float = 0.0
        raia_glfw_get_window_content_scale(window, &x, &y)
        xscale = x
        yscale = y
    }

    static func getWindowOpacity(_ window: OpaquePointer?) -> Float {
        return raia_glfw_get_window_opacity(window)
    }

    static func setWindowOpacity(_ window: OpaquePointer?, opacity: Float) {
        raia_glfw_set_window_opacity(window, opacity)
    }

    static func iconifyWindow(_ window: OpaquePointer?) {
        raia_glfw_iconify_window(window)
    }

    static func restoreWindow(_ window: OpaquePointer?) {
        raia_glfw_restore_window(window)
    }

    static func maximizeWindow(_ window: OpaquePointer?) {
        raia_glfw_maximize_window(window)
    }

    static func showWindow(_ window: OpaquePointer?) {
        raia_glfw_show_window(window)
    }

    static func hideWindow(_ window: OpaquePointer?) {
        raia_glfw_hide_window(window)
    }

    static func focusWindow(_ window: OpaquePointer?) {
        raia_glfw_focus_window(window)
    }

    static func requestWindowAttention(_ window: OpaquePointer?) {
        raia_glfw_request_window_attention(window)
    }

    static func getWindowMonitor(_ window: OpaquePointer?) -> OpaquePointer? {
        return raia_glfw_get_window_monitor(window)
    }

    static func setWindowMonitor(_ window: OpaquePointer?, monitor: OpaquePointer?, xpos: Int, ypos: Int, width: Int, height: Int, refreshRate: Int) {
        raia_glfw_set_window_monitor(window, monitor, Int32(xpos), Int32(ypos), Int32(width), Int32(height), Int32(refreshRate))
    }

    static func getWindowAttrib(_ window: OpaquePointer?, attrib: Int) -> Int {
        return Int(raia_glfw_get_window_attrib(window, Int32(attrib)))
    }

    static func setWindowAttrib(_ window: OpaquePointer?, attrib: Int, value: Int) {
        raia_glfw_set_window_attrib(window, Int32(attrib), Int32(value))
    }

    static func setWindowUserPointer(_ window: OpaquePointer?, pointer: UnsafeRawPointer?) {
        raia_glfw_set_window_user_pointer(window, UnsafeMutableRawPointer(mutating: pointer))
    }

    static func getWindowUserPointer(_ window: OpaquePointer?) -> UnsafeRawPointer? {
        return UnsafeRawPointer(raia_glfw_get_window_user_pointer(window))
    }

    static func setWindowPosCallback(_ window: OpaquePointer?, _ callback: @escaping GLFWwindowposfun) -> GLFWwindowposfun? {
        return raia_glfw_set_window_pos_callback(window, callback)
    }

    static func setWindowSizeCallback(_ window: OpaquePointer?, _ callback: @escaping GLFWwindowsizefun) -> GLFWwindowsizefun? {
        return raia_glfw_set_window_size_callback(window, callback)
    }

    static func setWindowCloseCallback(_ window: OpaquePointer?, _ callback: @escaping GLFWwindowclosefun) -> GLFWwindowclosefun? {
        return raia_glfw_set_window_close_callback(window, callback)
    }

    static func setWindowRefreshCallback(_ window: OpaquePointer?, _ callback: @escaping GLFWwindowrefreshfun) -> GLFWwindowrefreshfun? {
        return raia_glfw_set_window_refresh_callback(window, callback)
    }

    static func setWindowFocusCallback(_ window: OpaquePointer?, _ callback: @escaping GLFWwindowfocusfun) -> GLFWwindowfocusfun? {
        return raia_glfw_set_window_focus_callback(window, callback)
    }

    static func setWindowIconifyCallback(_ window: OpaquePointer?, _ callback: @escaping GLFWwindowiconifyfun) -> GLFWwindowiconifyfun? {
        return raia_glfw_set_window_iconify_callback(window, callback)
    }

    static func setWindowMaximizeCallback(_ window: OpaquePointer?, _ callback: @escaping GLFWwindowmaximizefun) -> GLFWwindowmaximizefun? {
        return raia_glfw_set_window_maximize_callback(window, callback)
    }

    static func setFramebufferSizeCallback(_ window: OpaquePointer?, _ callback: @escaping GLFWframebuffersizefun) -> GLFWframebuffersizefun? {
        return raia_glfw_set_framebuffer_size_callback(window, callback)
    }

    static func setWindowContentScaleCallback(_ window: OpaquePointer?, _ callback: @escaping GLFWwindowcontentscalefun) -> GLFWwindowcontentscalefun? {
        return raia_glfw_set_window_content_scale_callback(window, callback)
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

    static func swapBuffers(_ window: OpaquePointer?) {
        raia_glfw_swap_buffers(window)
    }
}