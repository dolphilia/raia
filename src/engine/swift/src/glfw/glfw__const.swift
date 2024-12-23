// glfw/_const.swift

import Foundation

extension GLFW {
    static let VERSION_MAJOR                     = 3
    static let VERSION_MINOR                     = 4
    static let VERSION_REVISION                  = 0
    static let TRUE                              = 1
    static let FALSE                             = 0
    static let RELEASE                           = 0
    static let PRESS                             = 1
    static let REPEAT                            = 2
    static let HAT_CENTERED                      = 0
    static let HAT_UP                            = 1
    static let HAT_RIGHT                         = 2
    static let HAT_DOWN                          = 4
    static let HAT_LEFT                          = 8
    static let HAT_RIGHT_UP                      = GLFW.HAT_RIGHT | GLFW.HAT_UP
    static let HAT_RIGHT_DOWN                    = GLFW.HAT_RIGHT | GLFW.HAT_DOWN
    static let HAT_LEFT_UP                       = GLFW.HAT_LEFT  | GLFW.HAT_UP
    static let HAT_LEFT_DOWN                     = GLFW.HAT_LEFT  | GLFW.HAT_DOWN
    static let KEY_UNKNOWN                       = -1
    static let KEY_SPACE                         = 32
    static let KEY_APOSTROPHE                    = 39  // ' 
    static let KEY_COMMA                         = 44  // , 
    static let KEY_MINUS                         = 45  // - 
    static let KEY_PERIOD                        = 46  // . 
    static let KEY_SLASH                         = 47  // / 
    static let KEY_0                             = 48
    static let KEY_1                             = 49
    static let KEY_2                             = 50
    static let KEY_3                             = 51
    static let KEY_4                             = 52
    static let KEY_5                             = 53
    static let KEY_6                             = 54
    static let KEY_7                             = 55
    static let KEY_8                             = 56
    static let KEY_9                             = 57
    static let KEY_SEMICOLON                     = 59  // ;
    static let KEY_EQUAL                         = 61  // = 
    static let KEY_A                             = 65
    static let KEY_B                             = 66
    static let KEY_C                             = 67
    static let KEY_D                             = 68
    static let KEY_E                             = 69
    static let KEY_F                             = 70
    static let KEY_G                             = 71
    static let KEY_H                             = 72
    static let KEY_I                             = 73
    static let KEY_J                             = 74
    static let KEY_K                             = 75
    static let KEY_L                             = 76
    static let KEY_M                             = 77
    static let KEY_N                             = 78
    static let KEY_O                             = 79
    static let KEY_P                             = 80
    static let KEY_Q                             = 81
    static let KEY_R                             = 82
    static let KEY_S                             = 83
    static let KEY_T                             = 84
    static let KEY_U                             = 85
    static let KEY_V                             = 86
    static let KEY_W                             = 87
    static let KEY_X                             = 88
    static let KEY_Y                             = 89
    static let KEY_Z                             = 90
    static let KEY_LEFT_BRACKET                  = 91  // [ 
    static let KEY_BACKSLASH                     = 92  // \\
    static let KEY_RIGHT_BRACKET                 = 93  // ] 
    static let KEY_GRAVE_ACCENT                  = 96  // ` 
    static let KEY_WORLD_1                       = 161 // non-US #1 
    static let KEY_WORLD_2                       = 162 // non-US #2 
    static let KEY_ESCAPE                        = 256
    static let KEY_ENTER                         = 257
    static let KEY_TAB                           = 258
    static let KEY_BACKSPACE                     = 259
    static let KEY_INSERT                        = 260
    static let KEY_DELETE                        = 261
    static let KEY_RIGHT                         = 262
    static let KEY_LEFT                          = 263
    static let KEY_DOWN                          = 264
    static let KEY_UP                            = 265
    static let KEY_PAGE_UP                       = 266
    static let KEY_PAGE_DOWN                     = 267
    static let KEY_HOME                          = 268
    static let KEY_END                           = 269
    static let KEY_CAPS_LOCK                     = 280
    static let KEY_SCROLL_LOCK                   = 281
    static let KEY_NUM_LOCK                      = 282
    static let KEY_PRINT_SCREEN                  = 283
    static let KEY_PAUSE                         = 284
    static let KEY_F1                            = 290
    static let KEY_F2                            = 291
    static let KEY_F3                            = 292
    static let KEY_F4                            = 293
    static let KEY_F5                            = 294
    static let KEY_F6                            = 295
    static let KEY_F7                            = 296
    static let KEY_F8                            = 297
    static let KEY_F9                            = 298
    static let KEY_F10                           = 299
    static let KEY_F11                           = 300
    static let KEY_F12                           = 301
    static let KEY_F13                           = 302
    static let KEY_F14                           = 303
    static let KEY_F15                           = 304
    static let KEY_F16                           = 305
    static let KEY_F17                           = 306
    static let KEY_F18                           = 307
    static let KEY_F19                           = 308
    static let KEY_F20                           = 309
    static let KEY_F21                           = 310
    static let KEY_F22                           = 311
    static let KEY_F23                           = 312
    static let KEY_F24                           = 313
    static let KEY_F25                           = 314
    static let KEY_KP_0                          = 320
    static let KEY_KP_1                          = 321
    static let KEY_KP_2                          = 322
    static let KEY_KP_3                          = 323
    static let KEY_KP_4                          = 324
    static let KEY_KP_5                          = 325
    static let KEY_KP_6                          = 326
    static let KEY_KP_7                          = 327
    static let KEY_KP_8                          = 328
    static let KEY_KP_9                          = 329
    static let KEY_KP_DECIMAL                    = 330
    static let KEY_KP_DIVIDE                     = 331
    static let KEY_KP_MULTIPLY                   = 332
    static let KEY_KP_SUBTRACT                   = 333
    static let KEY_KP_ADD                        = 334
    static let KEY_KP_ENTER                      = 335
    static let KEY_KP_EQUAL                      = 336
    static let KEY_LEFT_SHIFT                    = 340
    static let KEY_LEFT_CONTROL                  = 341
    static let KEY_LEFT_ALT                      = 342
    static let KEY_LEFT_SUPER                    = 343
    static let KEY_RIGHT_SHIFT                   = 344
    static let KEY_RIGHT_CONTROL                 = 345
    static let KEY_RIGHT_ALT                     = 346
    static let KEY_RIGHT_SUPER                   = 347
    static let KEY_MENU                          = 348
    static let KEY_LAST                          = GLFW.KEY_MENU
    static let MOD_SHIFT                         = 0x0001
    static let MOD_CONTROL                       = 0x0002
    static let MOD_ALT                           = 0x0004
    static let MOD_SUPER                         = 0x0008
    static let MOD_CAPS_LOCK                     = 0x0010
    static let MOD_NUM_LOCK                      = 0x0020
    static let MOUSE_BUTTON_1                    = 0
    static let MOUSE_BUTTON_2                    = 1
    static let MOUSE_BUTTON_3                    = 2
    static let MOUSE_BUTTON_4                    = 3
    static let MOUSE_BUTTON_5                    = 4
    static let MOUSE_BUTTON_6                    = 5
    static let MOUSE_BUTTON_7                    = 6
    static let MOUSE_BUTTON_8                    = 7
    static let MOUSE_BUTTON_LAST                 = GLFW.MOUSE_BUTTON_8
    static let MOUSE_BUTTON_LEFT                 = GLFW.MOUSE_BUTTON_1
    static let MOUSE_BUTTON_RIGHT                = GLFW.MOUSE_BUTTON_2
    static let MOUSE_BUTTON_MIDDLE               = GLFW.MOUSE_BUTTON_3
    static let JOYSTICK_1                        = 0
    static let JOYSTICK_2                        = 1
    static let JOYSTICK_3                        = 2
    static let JOYSTICK_4                        = 3
    static let JOYSTICK_5                        = 4
    static let JOYSTICK_6                        = 5
    static let JOYSTICK_7                        = 6
    static let JOYSTICK_8                        = 7
    static let JOYSTICK_9                        = 8
    static let JOYSTICK_10                       = 9
    static let JOYSTICK_11                       = 10
    static let JOYSTICK_12                       = 11
    static let JOYSTICK_13                       = 12
    static let JOYSTICK_14                       = 13
    static let JOYSTICK_15                       = 14
    static let JOYSTICK_16                       = 15
    static let JOYSTICK_LAST                     = GLFW.JOYSTICK_16
    static let GAMEPAD_BUTTON_A                  = 0
    static let GAMEPAD_BUTTON_B                  = 1
    static let GAMEPAD_BUTTON_X                  = 2
    static let GAMEPAD_BUTTON_Y                  = 3
    static let GAMEPAD_BUTTON_LEFT_BUMPER        = 4
    static let GAMEPAD_BUTTON_RIGHT_BUMPER       = 5
    static let GAMEPAD_BUTTON_BACK               = 6
    static let GAMEPAD_BUTTON_START              = 7
    static let GAMEPAD_BUTTON_GUIDE              = 8
    static let GAMEPAD_BUTTON_LEFT_THUMB         = 9
    static let GAMEPAD_BUTTON_RIGHT_THUMB        = 10
    static let GAMEPAD_BUTTON_DPAD_UP            = 11
    static let GAMEPAD_BUTTON_DPAD_RIGHT         = 12
    static let GAMEPAD_BUTTON_DPAD_DOWN          = 13
    static let GAMEPAD_BUTTON_DPAD_LEFT          = 14
    static let GAMEPAD_BUTTON_LAST               = GLFW.GAMEPAD_BUTTON_DPAD_LEFT
    static let GAMEPAD_BUTTON_CROSS              = GLFW.GAMEPAD_BUTTON_A
    static let GAMEPAD_BUTTON_CIRCLE             = GLFW.GAMEPAD_BUTTON_B
    static let GAMEPAD_BUTTON_SQUARE             = GLFW.GAMEPAD_BUTTON_X
    static let GAMEPAD_BUTTON_TRIANGLE           = GLFW.GAMEPAD_BUTTON_Y
    static let GAMEPAD_AXIS_LEFT_X               = 0
    static let GAMEPAD_AXIS_LEFT_Y               = 1
    static let GAMEPAD_AXIS_RIGHT_X              = 2
    static let GAMEPAD_AXIS_RIGHT_Y              = 3
    static let GAMEPAD_AXIS_LEFT_TRIGGER         = 4
    static let GAMEPAD_AXIS_RIGHT_TRIGGER        = 5
    static let GAMEPAD_AXIS_LAST                 = GLFW.GAMEPAD_AXIS_RIGHT_TRIGGER
    static let NO_ERROR                          = 0
    static let NOT_INITIALIZED                   = 0x00010001
    static let NO_CURRENT_CONTEXT                = 0x00010002
    static let INVALID_ENUM                      = 0x00010003
    static let INVALID_VALUE                     = 0x00010004
    static let OUT_OF_MEMORY                     = 0x00010005
    static let API_UNAVAILABLE                   = 0x00010006
    static let VERSION_UNAVAILABLE               = 0x00010007
    static let PLATFORM_ERROR                    = 0x00010008
    static let FORMAT_UNAVAILABLE                = 0x00010009
    static let NO_WINDOW_CONTEXT                 = 0x0001000A
    static let CURSOR_UNAVAILABLE                = 0x0001000B
    static let FEATURE_UNAVAILABLE               = 0x0001000C
    static let FEATURE_UNIMPLEMENTED             = 0x0001000D
    static let PLATFORM_UNAVAILABLE              = 0x0001000E
    static let FOCUSED                           = 0x00020001
    static let ICONIFIED                         = 0x00020002
    static let RESIZABLE                         = 0x00020003
    static let VISIBLE                           = 0x00020004
    static let DECORATED                         = 0x00020005
    static let AUTO_ICONIFY                      = 0x00020006
    static let FLOATING                          = 0x00020007
    static let MAXIMIZED                         = 0x00020008
    static let CENTER_CURSOR                     = 0x00020009
    static let TRANSPARENT_FRAMEBUFFER           = 0x0002000A
    static let HOVERED                           = 0x0002000B
    static let FOCUS_ON_SHOW                     = 0x0002000C
    static let MOUSE_PASSTHROUGH                 = 0x0002000D
    static let POSITION_X                        = 0x0002000E
    static let POSITION_Y                        = 0x0002000F
    static let RED_BITS                          = 0x00021001
    static let GREEN_BITS                        = 0x00021002
    static let BLUE_BITS                         = 0x00021003
    static let ALPHA_BITS                        = 0x00021004
    static let DEPTH_BITS                        = 0x00021005
    static let STENCIL_BITS                      = 0x00021006
    static let ACCUM_RED_BITS                    = 0x00021007
    static let ACCUM_GREEN_BITS                  = 0x00021008
    static let ACCUM_BLUE_BITS                   = 0x00021009
    static let ACCUM_ALPHA_BITS                  = 0x0002100A
    static let AUX_BUFFERS                       = 0x0002100B
    static let STEREO                            = 0x0002100C
    static let SAMPLES                           = 0x0002100D
    static let SRGB_CAPABLE                      = 0x0002100E
    static let REFRESH_RATE                      = 0x0002100F
    static let DOUBLEBUFFER                      = 0x00021010
    static let CLIENT_API                        = 0x00022001
    static let CONTEXT_VERSION_MAJOR             = 0x00022002
    static let CONTEXT_VERSION_MINOR             = 0x00022003
    static let CONTEXT_REVISION                  = 0x00022004
    static let CONTEXT_ROBUSTNESS                = 0x00022005
    static let OPENGL_FORWARD_COMPAT             = 0x00022006
    static let CONTEXT_DEBUG                     = 0x00022007
    static let OPENGL_DEBUG_CONTEXT              = GLFW.CONTEXT_DEBUG
    static let OPENGL_PROFILE                    = 0x00022008
    static let CONTEXT_RELEASE_BEHAVIOR          = 0x00022009
    static let CONTEXT_NO_ERROR                  = 0x0002200A
    static let CONTEXT_CREATION_API              = 0x0002200B
    static let SCALE_TO_MONITOR                  = 0x0002200C
    static let COCOA_RETINA_FRAMEBUFFER          = 0x00023001
    static let COCOA_FRAME_NAME                  = 0x00023002
    static let COCOA_GRAPHICS_SWITCHING          = 0x00023003
    static let X11_CLASS_NAME                    = 0x00024001
    static let X11_INSTANCE_NAME                 = 0x00024002
    static let WIN32_KEYBOARD_MENU               = 0x00025001
    static let WAYLAND_APP_ID                    = 0x00026001
    static let NO_API                            = 0
    static let OPENGL_API                        = 0x00030001
    static let OPENGL_ES_API                     = 0x00030002
    static let NO_ROBUSTNESS                     = 0
    static let NO_RESET_NOTIFICATION             = 0x00031001
    static let LOSE_CONTEXT_ON_RESET             = 0x00031002
    static let OPENGL_ANY_PROFILE                = 0
    static let OPENGL_CORE_PROFILE               = 0x00032001
    static let OPENGL_COMPAT_PROFILE             = 0x00032002
    static let CURSOR                            = 0x00033001
    static let STICKY_KEYS                       = 0x00033002
    static let STICKY_MOUSE_BUTTONS              = 0x00033003
    static let LOCK_KEY_MODS                     = 0x00033004
    static let RAW_MOUSE_MOTION                  = 0x00033005
    static let CURSOR_NORMAL                     = 0x00034001
    static let CURSOR_HIDDEN                     = 0x00034002
    static let CURSOR_DISABLED                   = 0x00034003
    static let CURSOR_CAPTURED                   = 0x00034004
    static let ANY_RELEASE_BEHAVIOR              = 0
    static let RELEASE_BEHAVIOR_FLUSH            = 0x00035001
    static let RELEASE_BEHAVIOR_NONE             = 0x00035002
    static let NATIVE_CONTEXT_API                = 0x00036001
    static let EGL_CONTEXT_API                   = 0x00036002
    static let OSMESA_CONTEXT_API                = 0x00036003
    static let ANGLE_PLATFORM_TYPE_NONE          = 0x00037001
    static let ANGLE_PLATFORM_TYPE_OPENGL        = 0x00037002
    static let ANGLE_PLATFORM_TYPE_OPENGLES      = 0x00037003
    static let ANGLE_PLATFORM_TYPE_D3D9          = 0x00037004
    static let ANGLE_PLATFORM_TYPE_D3D11         = 0x00037005
    static let ANGLE_PLATFORM_TYPE_VULKAN        = 0x00037007
    static let ANGLE_PLATFORM_TYPE_METAL         = 0x00037008
    static let WAYLAND_PREFER_LIBDECOR           = 0x00038001
    static let WAYLAND_DISABLE_LIBDECOR          = 0x00038002
    static let ANY_POSITION                      = 0x80000000
    static let ARROW_CURSOR                      = 0x00036001
    static let IBEAM_CURSOR                      = 0x00036002
    static let CROSSHAIR_CURSOR                  = 0x00036003
    static let POINTING_HAND_CURSOR              = 0x00036004
    static let RESIZE_EW_CURSOR                  = 0x00036005
    static let RESIZE_NS_CURSOR                  = 0x00036006
    static let RESIZE_NWSE_CURSOR                = 0x00036007
    static let RESIZE_NESW_CURSOR                = 0x00036008
    static let RESIZE_ALL_CURSOR                 = 0x00036009
    static let NOT_ALLOWED_CURSOR                = 0x0003600A
    static let HRESIZE_CURSOR                    = GLFW.RESIZE_EW_CURSOR
    static let VRESIZE_CURSOR                    = GLFW.RESIZE_NS_CURSOR
    static let HAND_CURSOR                       = GLFW.POINTING_HAND_CURSOR
    static let CONNECTED                         = 0x00040001
    static let DISCONNECTED                      = 0x00040002
    static let JOYSTICK_HAT_BUTTONS              = 0x00050001
    static let ANGLE_PLATFORM_TYPE               = 0x00050002
    static let PLATFORM                          = 0x00050003
    static let COCOA_CHDIR_RESOURCES             = 0x00051001
    static let COCOA_MENUBAR                     = 0x00051002
    static let X11_XCB_VULKAN_SURFACE            = 0x00052001
    static let WAYLAND_LIBDECOR                  = 0x00053001
    static let ANY_PLATFORM                      = 0x00060000
    static let PLATFORM_WIN32                    = 0x00060001
    static let PLATFORM_COCOA                    = 0x00060002
    static let PLATFORM_WAYLAND                  = 0x00060003
    static let PLATFORM_X11                      = 0x00060004
    static let PLATFORM_NULL                     = 0x00060005
    static let DONT_CARE                         = -1
}