#ifndef RAIA_WINDOW_RAIA_APP_H
#define RAIA_WINDOW_RAIA_APP_H

#include <time.h>
#include "duktape/duktape.h"
#include "duk_glfw/duk_glfw.h"
#include "static/static_header.h"
#include "static/static_window.h"
#include "static/static_pixel_data.h"
#include "static/static_shader.h"
#include "static/static_ctx.h"
#include "wrapper/wrapper_gles.h"
#include "util/util_math.h"

#include "../../../../share/c/utility/export_api.h"
#include "../../../../share/c/utility/platform.h"
#include "../../../../share/c/wrapper/wrapper_yyjson.h"

#define GLFW_INCLUDE_ES2
#define GL_GLEXT_PROTOTYPES

#include "GLFW/glfw3.h"
#include "EGL/egl.h"

#ifdef __WINDOWS__
#define RAIA_EXPORT __declspec(dllexport)
#else
#define RAIA_EXPORT
#endif

void glfw_loop(void);
void glfw_start(void);
void glfw_redraw(void);

void regist_callbacks(duk_context *ctx);

void regist_func(duk_context *ctx, duk_c_function func, const char *str, int nargs);

RAIA_EXPORT duk_ret_t raia_app_glfw_init(duk_context *ctx);
RAIA_EXPORT duk_ret_t raia_app_event_key_callback(duk_context *ctx);
RAIA_EXPORT duk_ret_t raia_app_event_error_callback(duk_context *ctx);
RAIA_EXPORT duk_ret_t raia_app_event_update_callback(duk_context *ctx);
RAIA_EXPORT duk_ret_t raia_app_event_cursor_position_callback(duk_context *ctx);
RAIA_EXPORT duk_ret_t raia_app_event_mouse_button_callback(duk_context *ctx);
RAIA_EXPORT duk_ret_t raia_app_event_update_enable(duk_context *ctx);
RAIA_EXPORT duk_ret_t raia_app_screen_redraw(duk_context *ctx);
RAIA_EXPORT duk_ret_t raia_app_window_poll_events(duk_context *ctx);
RAIA_EXPORT duk_ret_t raia_app_window_should_close(duk_context *ctx);
RAIA_EXPORT duk_ret_t raia_app_window_init(duk_context *ctx);
RAIA_EXPORT duk_ret_t raia_app_window_set_title(duk_context *ctx);


void init(void);

#endif //RAIA_WINDOW_RAIA_APP_H
