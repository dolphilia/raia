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

RAIA_EXPORT const char * raia_app_get_error(const char *s) {
    raia_not_use_s(s);
    return get_error_callback_t();
}

RAIA_EXPORT const char * raia_app_get_framebuffer_size(const char *s) {
    raia_not_use_s(s);
    return get_framebuffer_size_callback_t();
}

RAIA_EXPORT const char * raia_app_get_key(const char *s) {
    raia_not_use_s(s);
    return get_key_callback_t();
}

RAIA_EXPORT const char * raia_app_get_joystick(const char *s) {
    raia_not_use_s(s);
    return get_joystick_callback_t();
}

RAIA_EXPORT const char * raia_app_get_window_pos(const char *s) {
    raia_not_use_s(s);
    return get_window_pos_callback_t();
}

RAIA_EXPORT const char * raia_app_get_window_size(const char *s) {
    raia_not_use_s(s);
    return get_window_size_callback_t();
}

RAIA_EXPORT const char * raia_app_get_window_close(const char *s) {
    raia_not_use_s(s);
    return get_window_close_callback_t();
}

RAIA_EXPORT const char * raia_app_get_window_refresh(const char *s) {
    raia_not_use_s(s);
    return get_window_refresh_callback_t();
}

RAIA_EXPORT const char * raia_app_get_window_focus(const char *s) {
    raia_not_use_s(s);
    return get_window_focus_callback_t();
}

RAIA_EXPORT const char * raia_app_get_window_iconify(const char *s) {
    raia_not_use_s(s);
    return get_window_iconify_callback_t();
}

RAIA_EXPORT const char * raia_app_get_cursor_position(const char *s) {
    raia_not_use_s(s);
    return get_cursor_position_callback_t();
}

RAIA_EXPORT const char * raia_app_get_mouse_button(const char *s) {
    raia_not_use_s(s);
    return get_mouse_button_callback_t();
}

RAIA_EXPORT const char * raia_app_get_character(const char *s) {
    raia_not_use_s(s);
    return get_character_callback_t();
}

RAIA_EXPORT const char * raia_app_get_character_mods(const char *s) {
    raia_not_use_s(s);
    return get_character_mods_callback_t();
}

RAIA_EXPORT const char * raia_app_get_cursor_enter(const char *s) {
    raia_not_use_s(s);
    return get_cursor_enter_callback_t();
}

RAIA_EXPORT const char * raia_app_get_scroll(const char *s) {
    raia_not_use_s(s);
    return get_scroll_callback_t();
}

RAIA_EXPORT const char * raia_app_get_drop(const char *s) {
    raia_not_use_s(s);
    return get_drop_callback_t();
}

RAIA_EXPORT const char * raia_app_init(const char *s) {
    raia_not_use_s(s);
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

    joint_t *joint = joint_init_out();
    joint_add_out_bool(joint, "result", true);
    return joint_out_write(joint);
}

RAIA_EXPORT const char * raia_app_window_create(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    int width = joint_get_in_int(joint, "width");
    int height = joint_get_in_int(joint, "height");
    const char *title = joint_get_in_str(joint, "title");
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

    joint_add_out_uint(joint, "id", (uint64_t)(uintptr_t)window);
    joint_add_out_str(joint, "title", title);
    joint_add_out_int(joint, "width", width);
    joint_add_out_int(joint, "height", height);
    joint_add_out_int(joint, "resolution_width", res_width);
    joint_add_out_int(joint, "resolution_height", res_height);
    return joint_out_write(joint);
}


RAIA_EXPORT const char * raia_app_time_get_current_time(const char *s) {
    raia_not_use_s(s);
    double time = get_current_time();

    joint_t *joint = joint_init_out();
    joint_add_out_real(joint, "result", time);
    return joint_out_write(joint);
}

RAIA_EXPORT const char * raia_app_glfw_get_timer_value(const char *s) {
    raia_not_use_s(s);
    uint64_t val = glfwGetTimerValue();

    joint_t *joint = joint_init_out();
    joint_add_out_uint(joint, "result", val);
    return joint_out_write(joint);
}

RAIA_EXPORT const char * raia_app_glfw_get_timer_frequency(const char *s) {
    raia_not_use_s(s);
    uint64_t val = glfwGetTimerFrequency();

    joint_t *joint = joint_init_out();
    joint_add_out_uint(joint, "result", val);
    return joint_out_write(joint);
}

RAIA_EXPORT const char * raia_app_glfw_get_time(const char *s) {
    raia_not_use_s(s);
    double time = glfwGetTime();

    joint_t *joint = joint_init_out();
    joint_add_out_real(joint, "result", time);
    return joint_out_write(joint);
}

RAIA_EXPORT const char * raia_app_glfw_set_time(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    double time = joint_get_in_real(joint, "time");

    glfwSetTime(time);

    joint_add_out_bool(joint, "result", true);
    return joint_out_write(joint);
}

RAIA_EXPORT const char * raia_app_glfw_wait_event_timeout(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    double time = joint_get_in_real(joint, "time");

    glfwWaitEventsTimeout(time);

    joint_add_out_bool(joint, "result", true);
    return joint_out_write(joint);
}

RAIA_EXPORT const char *raia_app_glfw_joystick_present(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    int jid = joint_get_in_int(joint, "jid");

    int val = glfwJoystickPresent(jid);

    joint_add_out_int(joint, "result", val);
    return joint_out_write(joint);
}

RAIA_EXPORT const char * raia_app_glfw_get_joystick_axes(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    int jid = joint_get_in_int(joint, "jid");

    int count = 0;
    const float *axes = glfwGetJoystickAxes(jid, &count); // 返された配列は，GLFWによって確保・解放される

    joint_add_out_arr_real(joint, "result", (double *)axes, count);
    return joint_out_write(joint);
}

RAIA_EXPORT const char * raia_app_glfw_get_joystick_buttons(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    int jid = joint_get_in_int(joint, "jid");

    int count = 0;
    const unsigned char *buttons = glfwGetJoystickButtons(jid, &count); // 返された配列は、GLFWによって割り当てられ、解放される。

    joint_add_out_arr_uint8(joint, "result", (uint8_t *)buttons, count);
    return joint_out_write(joint);
}

RAIA_EXPORT const char * raia_app_glfw_get_joystick_name(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    int jid = joint_get_in_int(joint, "jid");

    const char *name = glfwGetJoystickName(jid);

    joint_add_out_str(joint, "result", name);
    return joint_out_write(joint);
}

RAIA_EXPORT const char * raia_app_screen_redraw(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    GLfloat vertices[20];
    joint_get_in_arr_int_to_float(joint, vertices, "vertices");
    GLushort indices[6];
    joint_get_in_arr_uint16(joint, indices, "indices");
    GLuint program = (GLuint)joint_get_in_uint(joint, "program");
    GLint pos_location= (GLint)joint_get_in_int(joint, "pos_location");
    GLint tex_location = (GLint)joint_get_in_int(joint, "tex_location");
    GLint sampler_location = (GLint)joint_get_in_int(joint, "sampler_location");
    GLuint texture = (GLuint)joint_get_in_int(joint, "texture");
    int32_t window_width = (int32_t)joint_get_in_int(joint, "window_width");
    int32_t window_height = (int32_t)joint_get_in_int(joint, "window_height");
    int resolution_width = joint_get_in_int(joint, "resolution_width");
    int resolution_height = joint_get_in_int(joint, "resolution_height");
    GLFWwindow* glfw_window = (GLFWwindow*)(uintptr_t)joint_get_in_uint(joint, "window_id");
    uint8_t *pixels = (uint8_t *)(uintptr_t)joint_get_in_uint(joint, "pixels");

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

    joint_add_out_bool(joint, "result", true);
    return joint_out_write(joint);
}

RAIA_EXPORT const char * raia_app_window_poll_events(const char *s) {
    raia_not_use_s(s);
    glfwPollEvents();

    joint_t *joint = joint_init_out();
    joint_add_out_bool(joint, "result", true);
    return joint_out_write(joint);
}

RAIA_EXPORT const char * raia_app_window_should_close(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    GLFWwindow* window_id = (GLFWwindow*)(uintptr_t)joint_get_in_uint(joint, "window_id");

    int ret = glfwWindowShouldClose(window_id);

    joint_add_out_int(joint, "result", ret);
    return joint_out_write(joint);
}

RAIA_EXPORT const char * raia_app_window_set_title(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    GLFWwindow* window_id = (GLFWwindow*)(uintptr_t)joint_get_in_uint(joint, "window_id");
    const char *title = joint_get_in_str(joint, "title");

    glfwSetWindowTitle(window_id, title);

    joint_add_out_bool(joint, "result", true);
    return joint_out_write(joint);
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

RAIA_EXPORT const char * raia_app_shader_init(const char* s) {
    joint_t *joint = joint_init_with_str(s);
    int window_width = joint_get_in_int(joint, "window_width");
    int window_height = joint_get_in_int(joint, "window_height");

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

    joint_add_out_arr_real(joint, "vertices", vertices, vertices_count);
    joint_add_out_arr_sint32(joint, "indices", indices, indices_count);
    joint_add_out_uint(joint, "program", program);
    joint_add_out_int(joint, "pos_location", pos_location);
    joint_add_out_int(joint, "tex_location", tex_location);
    joint_add_out_int(joint, "sampler_location", sampler_location);
    joint_add_out_uint(joint, "texture", texture);
    return joint_out_write(joint);
}