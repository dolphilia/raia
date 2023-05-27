#include "raia_app.h"

#ifdef __WINDOWS__
#define RAIA_EXPORT __declspec(dllexport) 
#else
#define RAIA_EXPORT
#endif

static double get_current_time() {
    double currentTime;
#ifdef __WINDOWS__
    LARGE_INTEGER frequency;
    QueryPerformanceFrequency(&frequency);

    LARGE_INTEGER counter;
    QueryPerformanceCounter(&counter);

    currentTime = (double)counter.QuadPart / (double)frequency.QuadPart;
#else
    struct timespec spec;
    clock_gettime(CLOCK_MONOTONIC, &spec);
    currentTime = (double)spec.tv_sec + ((double)spec.tv_nsec / 1.0e9);
#endif
    return currentTime;
}

static const char* raia_not_use_s(const char *s) {
    return s;
}

static void* raia_not_use_p(void *p) {
    return p;
}

static int raia_not_use_n(int n) {
    return n;
}

static void raia_not_use_spn(const char*s, void* p, int n) {
    raia_not_use_s(s);
    raia_not_use_p(p);
    raia_not_use_n(n);
}

static void raia_not_use_pn(void* p, int n) {
    raia_not_use_p(p);
    raia_not_use_n(n);
}

RAIA_EXPORT void *raia_app_get_error(const char *s, void *p, int n) {
    return get_error_callback_t();
}

RAIA_EXPORT void *raia_app_get_framebuffer_size(const char *s, void *p, int n) {
    return get_framebuffer_size_callback_t();
}

RAIA_EXPORT void *raia_app_get_key(const char *s, void *p, int n) {
    return get_key_callback_t();
}

RAIA_EXPORT void *raia_app_get_joystick(const char *s, void *p, int n) {
    return get_joystick_callback_t();
}

RAIA_EXPORT void *raia_app_get_window_pos(const char *s, void *p, int n) {
    return get_window_pos_callback_t();
}

RAIA_EXPORT void *raia_app_get_window_size(const char *s, void *p, int n) {
    return get_window_size_callback_t();
}

RAIA_EXPORT void *raia_app_get_window_close(const char *s, void *p, int n) {
    return get_window_close_callback_t();
}

RAIA_EXPORT void *raia_app_get_window_refresh(const char *s, void *p, int n) {
    return get_window_refresh_callback_t();
}

RAIA_EXPORT void *raia_app_get_window_focus(const char *s, void *p, int n) {
    return get_window_focus_callback_t();
}

RAIA_EXPORT void *raia_app_get_window_iconify(const char *s, void *p, int n) {
    return get_window_iconify_callback_t();
}

RAIA_EXPORT void *raia_app_get_cursor_position(const char *s, void *p, int n) {
    return get_cursor_position_callback_t();
}

RAIA_EXPORT void *raia_app_get_mouse_button(const char *s, void *p, int n) {
    return get_mouse_button_callback_t();
}

RAIA_EXPORT void *raia_app_get_character(const char *s, void *p, int n) {
    return get_character_callback_t();
}

RAIA_EXPORT void *raia_app_get_character_mods(const char *s, void *p, int n) {
    return get_character_mods_callback_t();
}

RAIA_EXPORT void *raia_app_get_cursor_enter(const char *s, void *p, int n) {
    return get_cursor_enter_callback_t();
}

RAIA_EXPORT void *raia_app_get_scroll(const char *s, void *p, int n) {
    return get_scroll_callback_t();
}

RAIA_EXPORT void *raia_app_get_drop(const char *s, void *p, int n) {
    return get_drop_callback_t();
}

//--

RAIA_EXPORT void *raia_app_init(const char *s, void *p, int n) {
    if (glfwInit() != GL_TRUE) {
        fprintf(stderr, "Initialization of GLFW failed.\n");
        exit(EXIT_FAILURE);
    }
    glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_ES_API);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    glfwWindowHint(GLFW_CONTEXT_CREATION_API, GLFW_EGL_CONTEXT_API);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    init_raia_callback();
    glfwSetErrorCallback(event_error_callback);
    glfwSetJoystickCallback(event_joystick_callback);

    yyjson_mut_doc *ret_doc = yyjson_mut_doc_new(NULL);
    yyjson_mut_val *ret_root = yyjson_mut_obj(ret_doc);
    yyjson_mut_doc_set_root(ret_doc, ret_root);
    yyjson_mut_obj_add_bool(ret_doc, ret_root, "result", true);
    char *result = yyjson_mut_write(ret_doc, YYJSON_WRITE_PRETTY, NULL);

    yyjson_mut_doc_free(ret_doc);
    return (void *)result;
}

RAIA_EXPORT void *raia_app_window_create(const char *s, void *p, int n) {
    yyjson_doc *arg_doc = yyjson_read(s, strlen(s), 0);
    yyjson_val *arg_root = yyjson_doc_get_root(arg_doc);
    int width = yyjson_get_int(yyjson_obj_get(arg_root, "width"));
    int height = yyjson_get_int(yyjson_obj_get(arg_root, "height"));
    const char *title = yyjson_get_str(yyjson_obj_get(arg_root, "title"));
    int res_width = width;
    int res_height = height;

    GLFWwindow* window = glfwCreateWindow(width, height, title, NULL, NULL);

    if (!window) {
        fprintf(stderr, "Window creation failed.\n");
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);


    // HiDPI
    int now_width, now_height;
    glfwGetFramebufferSize(window, &now_width, &now_height);
    if (now_width > width) {
        res_width = width * 2;
        res_height = height * 2;
    }

    glfwSetKeyCallback(window, event_key_callback);
    glfwSetFramebufferSizeCallback(window, event_framebuffer_size_callback);
    glfwSetWindowPosCallback(window, event_window_pos_callback);
    glfwSetWindowSizeCallback(window, event_window_size_callback);
    glfwSetWindowCloseCallback(window, event_window_close_callback);
    glfwSetWindowRefreshCallback(window, event_window_refresh_callback);
    glfwSetWindowFocusCallback(window, event_window_focus_callback);
    glfwSetWindowIconifyCallback(window, event_window_iconify_callback);
    glfwSetCursorPosCallback(window, event_cursor_position_callback);
    glfwSetMouseButtonCallback(window, event_mouse_button_callback);
    glfwSetCharCallback(window, event_character_callback);
    glfwSetCharModsCallback(window, event_character_mods_callback);
    glfwSetCursorEnterCallback(window, event_cursor_enter_callback);
    glfwSetScrollCallback(window, event_scroll_callback);
    glfwSetDropCallback(window, event_drop_callback);


    yyjson_mut_doc *ret_doc = yyjson_mut_doc_new(NULL);
    yyjson_mut_val *ret_root = yyjson_mut_obj(ret_doc);
    yyjson_mut_doc_set_root(ret_doc, ret_root);
    yyjson_mut_obj_add_uint(ret_doc, ret_root, "id", (uint64_t)(uintptr_t)window);
    yyjson_mut_obj_add_str(ret_doc, ret_root, "title", title);
    yyjson_mut_obj_add_int(ret_doc, ret_root, "width", width);
    yyjson_mut_obj_add_int(ret_doc, ret_root, "height", height);
    yyjson_mut_obj_add_int(ret_doc, ret_root, "resolution_width", res_width);
    yyjson_mut_obj_add_uint(ret_doc, ret_root, "resolution_height", res_height);

    char *result = yyjson_mut_write(ret_doc, YYJSON_WRITE_PRETTY, NULL);

    yyjson_mut_doc_free(ret_doc);
    yyjson_doc_free(arg_doc);
    return (void *)result;
}


RAIA_EXPORT void *raia_app_time_get_current_time(const char *s, void *p, int n) {
    raia_not_use_spn(s, p, n);

    double time = get_current_time();

    yyjson_mut_doc *ret_doc = yyjson_mut_doc_new(NULL);
    yyjson_mut_val *ret_root = yyjson_mut_obj(ret_doc);
    yyjson_mut_doc_set_root(ret_doc, ret_root);
    yyjson_mut_obj_add_real(ret_doc, ret_root, "result", time);
    char *result = yyjson_mut_write(ret_doc, YYJSON_WRITE_PRETTY, NULL);

    yyjson_mut_doc_free(ret_doc);
    return (void *)result;
}

RAIA_EXPORT void *raia_app_glfw_get_timer_value(const char *s, void *p, int n) {
    raia_not_use_spn(s, p, n);

    uint64_t val = glfwGetTimerValue();

    yyjson_mut_doc *ret_doc = yyjson_mut_doc_new(NULL);
    yyjson_mut_val *ret_root = yyjson_mut_obj(ret_doc);
    yyjson_mut_doc_set_root(ret_doc, ret_root);
    yyjson_mut_obj_add_uint(ret_doc, ret_root, "result", val);
    char *result = yyjson_mut_write(ret_doc, YYJSON_WRITE_PRETTY, NULL);

    yyjson_mut_doc_free(ret_doc);
    return (void *)result;
}

RAIA_EXPORT void *raia_app_glfw_get_timer_frequency(const char *s, void *p, int n) {
    raia_not_use_spn(s, p, n);

    uint64_t val = glfwGetTimerFrequency();

    yyjson_mut_doc *ret_doc = yyjson_mut_doc_new(NULL);
    yyjson_mut_val *ret_root = yyjson_mut_obj(ret_doc);
    yyjson_mut_doc_set_root(ret_doc, ret_root);
    yyjson_mut_obj_add_uint(ret_doc, ret_root, "result", val);
    char *result = yyjson_mut_write(ret_doc, YYJSON_WRITE_PRETTY, NULL);

    yyjson_mut_doc_free(ret_doc);
    return (void *)result;
}

RAIA_EXPORT void *raia_app_glfw_get_time(const char *s, void *p, int n) {
    raia_not_use_spn(s, p, n);

    double time = glfwGetTime();

    yyjson_mut_doc *ret_doc = yyjson_mut_doc_new(NULL);
    yyjson_mut_val *ret_root = yyjson_mut_obj(ret_doc);
    yyjson_mut_doc_set_root(ret_doc, ret_root);
    yyjson_mut_obj_add_real(ret_doc, ret_root, "result", time);
    char *result = yyjson_mut_write(ret_doc, YYJSON_WRITE_PRETTY, NULL);

    yyjson_mut_doc_free(ret_doc);
    return (void *)result;
}

RAIA_EXPORT void *raia_app_glfw_set_time(const char *s, void *p, int n) {
    raia_not_use_pn(p, n);

    yyjson_doc *arg_doc = yyjson_read(s, strlen(s), 0);
    yyjson_val *arg_root = yyjson_doc_get_root(arg_doc);
    yyjson_val *arg_val = yyjson_obj_get(arg_root, "time");
    double time = yyjson_get_real(arg_val);

    glfwSetTime(time);

    yyjson_mut_doc *ret_doc = yyjson_mut_doc_new(NULL);
    yyjson_mut_val *ret_root = yyjson_mut_obj(ret_doc);
    yyjson_mut_doc_set_root(ret_doc, ret_root);
    yyjson_mut_obj_add_bool(ret_doc, ret_root, "result", true);
    char *result = yyjson_mut_write(ret_doc, YYJSON_WRITE_PRETTY, NULL);

    yyjson_mut_doc_free(ret_doc);
    yyjson_doc_free(arg_doc);
    return (void *)result;
}

RAIA_EXPORT void *raia_app_glfw_wait_event_timeout(const char *s, void *p, int n) {
    raia_not_use_pn(p, n);

    yyjson_doc *arg_doc = yyjson_read(s, strlen(s), 0);
    yyjson_val *arg_root = yyjson_doc_get_root(arg_doc);
    yyjson_val *arg_val = yyjson_obj_get(arg_root, "time");
    double time = yyjson_get_real(arg_val);

    glfwWaitEventsTimeout(time);

    yyjson_mut_doc *ret_doc = yyjson_mut_doc_new(NULL);
    yyjson_mut_val *ret_root = yyjson_mut_obj(ret_doc);
    yyjson_mut_doc_set_root(ret_doc, ret_root);
    yyjson_mut_obj_add_bool(ret_doc, ret_root, "result", true);
    char *result = yyjson_mut_write(ret_doc, YYJSON_WRITE_PRETTY, NULL);

    yyjson_mut_doc_free(ret_doc);
    yyjson_doc_free(arg_doc);
    return (void *)result;
}

RAIA_EXPORT void *raia_app_glfw_joystick_present(const char *s, void *p, int n) {
    raia_not_use_pn(p, n);

    yyjson_doc *arg_doc = yyjson_read(s, strlen(s), 0);
    yyjson_val *arg_root = yyjson_doc_get_root(arg_doc);
    yyjson_val *arg_val = yyjson_obj_get(arg_root, "jid");
    int jid = yyjson_get_int(arg_val);

    int val = glfwJoystickPresent(jid);

    yyjson_mut_doc *ret_doc = yyjson_mut_doc_new(NULL);
    yyjson_mut_val *ret_root = yyjson_mut_obj(ret_doc);
    yyjson_mut_doc_set_root(ret_doc, ret_root);
    yyjson_mut_obj_add_int(ret_doc, ret_root, "result", val);
    char *result = yyjson_mut_write(ret_doc, YYJSON_WRITE_PRETTY, NULL);

    yyjson_mut_doc_free(ret_doc);
    yyjson_doc_free(arg_doc);
    return (void *)result;
}

RAIA_EXPORT void *raia_app_glfw_get_joystick_axes(const char *s, void *p, int n) {
    raia_not_use_pn(p, n);

    yyjson_doc *arg_doc = yyjson_read(s, strlen(s), 0);
    yyjson_val *arg_root = yyjson_doc_get_root(arg_doc);
    yyjson_val *arg_val = yyjson_obj_get(arg_root, "jid");
    int jid = yyjson_get_int(arg_val);

    int count = 0;
    const float *axes = glfwGetJoystickAxes(jid, &count); // 返された配列は，GLFWによって確保・解放される

    yyjson_mut_doc *ret_doc = yyjson_mut_doc_new(NULL);
    yyjson_mut_val *ret_root = yyjson_mut_obj(ret_doc);
    yyjson_mut_doc_set_root(ret_doc, ret_root);
    yyjson_mut_val *ret_vals = yyjson_mut_arr_with_real(ret_doc, (const double *)axes, count);
    yyjson_mut_obj_add_val(ret_doc, ret_root, "result", ret_vals);
    char *result = yyjson_mut_write(ret_doc, YYJSON_WRITE_PRETTY, NULL);

    yyjson_mut_doc_free(ret_doc);
    yyjson_doc_free(arg_doc);
    return (void *)result;
}

RAIA_EXPORT void *raia_app_glfw_get_joystick_buttons(const char *s, void *p, int n) {
    raia_not_use_pn(p, n);

    yyjson_doc *arg_doc = yyjson_read(s, strlen(s), 0);
    yyjson_val *arg_root = yyjson_doc_get_root(arg_doc);
    yyjson_val *arg_val = yyjson_obj_get(arg_root, "jid");
    int jid = yyjson_get_int(arg_val);

    int count = 0;
    const unsigned char *buttons = glfwGetJoystickButtons(jid, &count); // 返された配列は、GLFWによって割り当てられ、解放される。

    yyjson_mut_doc *ret_doc = yyjson_mut_doc_new(NULL);
    yyjson_mut_val *ret_root = yyjson_mut_obj(ret_doc);
    yyjson_mut_doc_set_root(ret_doc, ret_root);
    yyjson_mut_val *ret_vals = yyjson_mut_arr_with_uint8(ret_doc, (const uint8_t *)buttons, count);
    yyjson_mut_obj_add_val(ret_doc, ret_root, "result", ret_vals);
    char *result = yyjson_mut_write(ret_doc, YYJSON_WRITE_PRETTY, NULL);

    yyjson_mut_doc_free(ret_doc);
    yyjson_doc_free(arg_doc);
    return (void *)result;
}

RAIA_EXPORT void *raia_app_glfw_get_joystick_name(const char *s, void *p, int n) {
    raia_not_use_pn(p, n);

    yyjson_doc *arg_doc = yyjson_read(s, strlen(s), 0);
    yyjson_val *arg_root = yyjson_doc_get_root(arg_doc);
    yyjson_val *arg_val = yyjson_obj_get(arg_root, "jid");
    int jid = yyjson_get_int(arg_val);

    const char *name = glfwGetJoystickName(jid);

    yyjson_mut_doc *ret_doc = yyjson_mut_doc_new(NULL);
    yyjson_mut_val *ret_root = yyjson_mut_obj(ret_doc);
    yyjson_mut_doc_set_root(ret_doc, ret_root);
    yyjson_mut_obj_add_str(ret_doc, ret_root, "result", name);
    char *result = yyjson_mut_write(ret_doc, YYJSON_WRITE_PRETTY, NULL);

    yyjson_mut_doc_free(ret_doc);
    yyjson_doc_free(arg_doc);
    return (void *)result;
}

#ifdef __WINDOWS__
#define GL_TEXTURE0 0x84C0
#endif

RAIA_EXPORT void *raia_app_screen_redraw(const char *s, void *p, int n) {
    raia_not_use_n(n);

    //duk_size_t length;
    GLfloat vertices[20];
    GLushort indices[6];
    yyjson_doc *arg_doc = yyjson_read(s, strlen(s), 0);
    yyjson_val *arg_root = yyjson_doc_get_root(arg_doc);
    yyjson_val *arg_arr = yyjson_obj_get(arg_root, "vertices");
    size_t idx, max;
    yyjson_val *hit;
    yyjson_arr_foreach(arg_arr, idx, max, hit) {
        vertices[idx] = (GLfloat)yyjson_get_int(hit);
    }
    yyjson_val *arg_arr2 = yyjson_obj_get(arg_root, "indices");
    size_t idx2, max2;
    yyjson_val *hit2;
    yyjson_arr_foreach(arg_arr2, idx2, max2, hit2) {
        indices[idx2] = (GLushort)yyjson_get_uint(hit2);
    }
    GLuint program = (GLuint)yyjson_get_uint(yyjson_obj_get(arg_root, "program"));
    GLint pos_location= (GLint)yyjson_get_int(yyjson_obj_get(arg_root, "pos_location"));
    GLint tex_location = (GLint)yyjson_get_int(yyjson_obj_get(arg_root, "tex_location"));
    GLint sampler_location = (GLint)yyjson_get_int(yyjson_obj_get(arg_root, "sampler_location"));
    GLuint texture = (GLuint)yyjson_get_uint(yyjson_obj_get(arg_root, "texture"));
    int32_t window_width = (int32_t)yyjson_get_int(yyjson_obj_get(arg_root, "window_width"));
    int32_t window_height = (int32_t)yyjson_get_int(yyjson_obj_get(arg_root, "window_height"));
    int resolution_width = yyjson_get_int(yyjson_obj_get(arg_root, "resolution_width"));
    int resolution_height = yyjson_get_int(yyjson_obj_get(arg_root, "resolution_height"));
    GLFWwindow* glfw_window = (GLFWwindow*)(uintptr_t)yyjson_get_uint(yyjson_obj_get(arg_root, "window_id"));
    uint8_t *pixels = (uint8_t *)p;

    glViewport(0, 0, resolution_width, resolution_height); // Set the viewport
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer
    glUseProgram(program); // Use the program object
    glVertexAttribPointer(pos_location, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), vertices); // Load the vertex position
    glVertexAttribPointer(tex_location, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), vertices + 3); // Load the texture coordinate
    glEnableVertexAttribArray(pos_location);
    glEnableVertexAttribArray(tex_location);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, window_width, window_height, 0, GL_RGB, GL_UNSIGNED_BYTE, pixels);
    glActiveTexture(GL_TEXTURE0); // Bind the texture
    glBindTexture(GL_TEXTURE_2D, texture);
    glUniform1i(sampler_location, 0); // Set the texture sampler to texture unit to 0
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_SHORT, indices);
    glfwMakeContextCurrent(glfw_window);
    glfwSwapBuffers(glfw_window);

    yyjson_mut_doc *ret_doc = yyjson_mut_doc_new(NULL);
    yyjson_mut_val *ret_root = yyjson_mut_obj(ret_doc);
    yyjson_mut_doc_set_root(ret_doc, ret_root);
    yyjson_mut_obj_add_bool(ret_doc, ret_root, "result", true);
    char *result = yyjson_mut_write(ret_doc, YYJSON_WRITE_PRETTY, NULL);

    yyjson_mut_doc_free(ret_doc);
    yyjson_doc_free(arg_doc);
    return (void *)result;
}

RAIA_EXPORT void *raia_app_window_poll_events(const char *s, void *p, int n) {
    raia_not_use_spn(s, p, n);

    glfwPollEvents();

    yyjson_mut_doc *ret_doc = yyjson_mut_doc_new(NULL);
    yyjson_mut_val *ret_root = yyjson_mut_obj(ret_doc);
    yyjson_mut_doc_set_root(ret_doc, ret_root);
    yyjson_mut_obj_add_bool(ret_doc, ret_root, "result", true);
    char *result = yyjson_mut_write(ret_doc, YYJSON_WRITE_PRETTY, NULL);

    yyjson_mut_doc_free(ret_doc);
    return (void *)result;
}

RAIA_EXPORT void *raia_app_window_should_close(const char *s, void *p, int n) {
    raia_not_use_pn(p, n);

    yyjson_doc *arg_doc = yyjson_read(s, strlen(s), 0);
    yyjson_val *arg_root = yyjson_doc_get_root(arg_doc);
    GLFWwindow* window_id = (GLFWwindow*)(uintptr_t)yyjson_get_uint(yyjson_obj_get(arg_root, "window_id"));

    int ret = glfwWindowShouldClose(window_id);

    yyjson_mut_doc *ret_doc = yyjson_mut_doc_new(NULL);
    yyjson_mut_val *ret_root = yyjson_mut_obj(ret_doc);
    yyjson_mut_doc_set_root(ret_doc, ret_root);
    yyjson_mut_obj_add_int(ret_doc, ret_root, "result", ret);
    char *result = yyjson_mut_write(ret_doc, YYJSON_WRITE_PRETTY, NULL);

    yyjson_mut_doc_free(ret_doc);
    yyjson_doc_free(arg_doc);
    return (void *)result;
}

RAIA_EXPORT void *raia_app_window_set_title(const char *s, void *p, int n) {
    yyjson_doc *arg_doc = yyjson_read(s, strlen(s), 0);
    yyjson_val *arg_root = yyjson_doc_get_root(arg_doc);
    GLFWwindow* window_id = (GLFWwindow*)(uintptr_t)yyjson_get_uint(yyjson_obj_get(arg_root, "window_id"));
    const char *title = yyjson_get_str(yyjson_obj_get(arg_root, "title"));

    glfwSetWindowTitle(window_id, title);

    yyjson_mut_doc *ret_doc = yyjson_mut_doc_new(NULL);
    yyjson_mut_val *ret_root = yyjson_mut_obj(ret_doc);
    yyjson_mut_doc_set_root(ret_doc, ret_root);
    yyjson_mut_obj_add_bool(ret_doc, ret_root, "result", true);
    char *result = yyjson_mut_write(ret_doc, YYJSON_WRITE_PRETTY, NULL);

    yyjson_mut_doc_free(ret_doc);
    yyjson_doc_free(arg_doc);
    return (void *)result;
}

GLuint create_shader(GLenum type, const char *shader_src) {
    GLuint shader = glCreateShader(type);
    glShaderSource (shader, 1, &shader_src, NULL);
    glCompileShader (shader);
    GLint compiled;
    glGetShaderiv (shader, GL_COMPILE_STATUS, &compiled);
    return shader;
}

GLuint create_program(void) {
    GLbyte vShaderStr[] =
            "attribute vec4 a_position;"
            "attribute vec2 a_texCoord;"
            "varying vec2 v_texCoord;"
            "void main() {"
            "    gl_Position = a_position;"
            "    v_texCoord = a_texCoord;"
            "}";
    GLbyte fShaderStr[] =
            "precision mediump float;"
            "varying vec2 v_texCoord;"
            "uniform sampler2D s_texture;"
            "void main() {"
            "    gl_FragColor = texture2D(s_texture, v_texCoord);"
            "}";
    GLuint program = glCreateProgram(); // Handle to a program object
    GLuint vs = create_shader(GL_VERTEX_SHADER, (const char*)vShaderStr);
    GLuint fs = create_shader(GL_FRAGMENT_SHADER, (const char*)fShaderStr);
    glAttachShader(program, vs);
    glDeleteShader(vs);
    glAttachShader(program, fs);
    glDeleteShader(fs);
    glLinkProgram (program); // Link the program
    return program;
}

GLuint create_texture(GLubyte* pixels, int width, int height) {
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1); // Use tightly packed data
    GLuint texture; // Generate a texture object
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture); // Bind the texture object
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, pixels);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); // Set the filtering mode
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    return texture;
}

RAIA_EXPORT void *raia_app_shader_init(const char* s, void *p, int n) {
    yyjson_doc *arg_doc = yyjson_read(s, strlen(s), 0);
    yyjson_val *arg_root = yyjson_doc_get_root(arg_doc);
    int window_width = yyjson_get_int(yyjson_obj_get(arg_root, "window_width"));
    int window_height = yyjson_get_int(yyjson_obj_get(arg_root, "window_height"));

    GLuint program;
    GLint pos_location;
    GLint tex_location;
    GLint sampler_location;
    GLuint texture;
    int vertices_count = 20;
    double vertices[] = {
            -1.0f, 1.0f,  0.0f,  // Position 0
            0.0f,  0.0f,         // TexCoord 0
            -1.0f, -1.0f, 0.0f,  // Position 1
            0.0f,  1.0f,         // TexCoord 1
            1.0f,  -1.0f, 0.0f,  // Position 2
            1.0f,  1.0f,         // TexCoord 2
            1.0f,  1.0f,  0.0f,  // Position 3
            1.0f,  0.0f          // TexCoord 3
    };
    int indices_count = 6;
    int32_t indices[] = {0, 1, 2, 0, 2, 3};

    // create shader program
    program = create_program();
    pos_location = glGetAttribLocation(program, "a_position"); // Attribute locations
    tex_location = glGetAttribLocation(program, "a_texCoord"); // texture coordinate locations
    sampler_location = glGetUniformLocation(program, "s_texture"); // Sampler location

    // Create Texture 2D
    uint8_t* pixel_data = NULL;
    texture = create_texture(pixel_data, window_width, window_height);

    //----
    yyjson_mut_doc *ret_doc = yyjson_mut_doc_new(NULL);
    yyjson_mut_val *ret_root = yyjson_mut_obj(ret_doc);
    yyjson_mut_doc_set_root(ret_doc, ret_root);
    yyjson_mut_val *vertices_val = yyjson_mut_arr_with_real(ret_doc, vertices, vertices_count);
    yyjson_mut_obj_add_val(ret_doc, ret_root, "vertices", vertices_val);
    yyjson_mut_val *indices_val = yyjson_mut_arr_with_sint32(ret_doc, indices, indices_count);
    yyjson_mut_obj_add_val(ret_doc, ret_root, "indices", indices_val);
    yyjson_mut_obj_add_uint(ret_doc, ret_root, "program", program);
    yyjson_mut_obj_add_int(ret_doc, ret_root, "pos_location", pos_location);
    yyjson_mut_obj_add_int(ret_doc, ret_root, "tex_location", tex_location);
    yyjson_mut_obj_add_int(ret_doc, ret_root, "sampler_location", sampler_location);
    yyjson_mut_obj_add_uint(ret_doc, ret_root, "texture", texture);

    char *result = yyjson_mut_write(ret_doc, YYJSON_WRITE_PRETTY, NULL);

    yyjson_mut_doc_free(ret_doc);
    yyjson_doc_free(arg_doc);
    return (void *)result;
}