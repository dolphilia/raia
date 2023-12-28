#include "raia_gui.h"

#include <iostream>
#include <fstream>
#include "../../../third_party/cpp/nlohmann/json/json.hpp"
using json = nlohmann::json;

extern "C" {

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

RAIA_API const char * raia_app_get_error(const char *s) {
    raia_not_use_s(s);
    return get_error_callback_t();
}

RAIA_API const char * raia_app_get_framebuffer_size(const char *s) {
    raia_not_use_s(s);
    return get_framebuffer_size_callback_t();
}

RAIA_API const char * raia_app_get_key(const char *s) {
    raia_not_use_s(s);
    return get_key_callback_t();
}

RAIA_API const char * raia_app_get_joystick(const char *s) {
    raia_not_use_s(s);
    return get_joystick_callback_t();
}

RAIA_API const char * raia_app_get_window_pos(const char *s) {
    raia_not_use_s(s);
    return get_window_pos_callback_t();
}

RAIA_API const char * raia_app_get_window_size(const char *s) {
    raia_not_use_s(s);
    return get_window_size_callback_t();
}

RAIA_API const char * raia_app_get_window_close(const char *s) {
    raia_not_use_s(s);
    return get_window_close_callback_t();
}

RAIA_API const char * raia_app_get_window_refresh(const char *s) {
    raia_not_use_s(s);
    return get_window_refresh_callback_t();
}

RAIA_API const char * raia_app_get_window_focus(const char *s) {
    raia_not_use_s(s);
    return get_window_focus_callback_t();
}

RAIA_API const char * raia_app_get_window_iconify(const char *s) {
    raia_not_use_s(s);
    return get_window_iconify_callback_t();
}

RAIA_API const char * raia_app_get_cursor_position(const char *s) {
    raia_not_use_s(s);
    return get_cursor_position_callback_t();
}

RAIA_API const char * raia_app_get_mouse_button(const char *s) {
    raia_not_use_s(s);
    return get_mouse_button_callback_t();
}

RAIA_API const char * raia_app_get_character(const char *s) {
    raia_not_use_s(s);
    return get_character_callback_t();
}

RAIA_API const char * raia_app_get_character_mods(const char *s) {
    raia_not_use_s(s);
    return get_character_mods_callback_t();
}

RAIA_API const char * raia_app_get_cursor_enter(const char *s) {
    raia_not_use_s(s);
    return get_cursor_enter_callback_t();
}

RAIA_API const char * raia_app_get_scroll(const char *s) {
    raia_not_use_s(s);
    return get_scroll_callback_t();
}

RAIA_API const char * raia_app_get_drop(const char *s) {
    raia_not_use_s(s);
    return get_drop_callback_t();
}

RAIA_API const char * raia_app_init(const char *s) {
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

RAIA_API const char * raia_app_window_create(const char *s) {
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

RAIA_API const char * raia_app_time_get_current_time(const char *s) {
    raia_not_use_s(s);
    double time = get_current_time();

    joint_t *joint = joint_init_out();
    joint_add_out_real(joint, "result", time);
    return joint_out_write(joint);
}

RAIA_API const char * raia_app_glfw_get_timer_value(const char *s) {
    raia_not_use_s(s);
    uint64_t val = glfwGetTimerValue();

    joint_t *joint = joint_init_out();
    joint_add_out_uint(joint, "result", val);
    return joint_out_write(joint);
}

RAIA_API const char * raia_app_glfw_get_timer_frequency(const char *s) {
    raia_not_use_s(s);
    uint64_t val = glfwGetTimerFrequency();

    joint_t *joint = joint_init_out();
    joint_add_out_uint(joint, "result", val);
    return joint_out_write(joint);
}

RAIA_API const char * raia_app_glfw_get_time(const char *s) {
    raia_not_use_s(s);
    double time = glfwGetTime();

    joint_t *joint = joint_init_out();
    joint_add_out_real(joint, "result", time);
    return joint_out_write(joint);
}

RAIA_API const char * raia_app_glfw_set_time(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    double time = joint_get_in_real(joint, "time");

    glfwSetTime(time);

    joint_add_out_bool(joint, "result", true);
    return joint_out_write(joint);
}

RAIA_API const char * raia_app_glfw_wait_event_timeout(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    double time = joint_get_in_real(joint, "time");

    glfwWaitEventsTimeout(time);

    joint_add_out_bool(joint, "result", true);
    return joint_out_write(joint);
}

RAIA_API const char *raia_app_glfw_joystick_present(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    int jid = joint_get_in_int(joint, "jid");

    int val = glfwJoystickPresent(jid);

    joint_add_out_int(joint, "result", val);
    return joint_out_write(joint);
}

RAIA_API const char * raia_app_glfw_get_joystick_axes(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    int jid = joint_get_in_int(joint, "jid");

    int count = 0;
    const float *axes = glfwGetJoystickAxes(jid, &count); // 返された配列は，GLFWによって確保・解放される

    joint_add_out_arr_real(joint, "result", (double *)axes, count);
    return joint_out_write(joint);
}

RAIA_API const char * raia_app_glfw_get_joystick_buttons(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    int jid = joint_get_in_int(joint, "jid");

    int count = 0;
    const unsigned char *buttons = glfwGetJoystickButtons(jid, &count); // 返された配列は、GLFWによって割り当てられ、解放される。

    joint_add_out_arr_uint8(joint, "result", (uint8_t *)buttons, count);
    return joint_out_write(joint);
}

RAIA_API const char * raia_app_glfw_get_joystick_name(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    int jid = joint_get_in_int(joint, "jid");

    const char *name = glfwGetJoystickName(jid);

    joint_add_out_str(joint, "result", name);
    return joint_out_write(joint);
}

RAIA_API const char * raia_app_screen_redraw(const char *s) {
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

RAIA_API const char * raia_app_window_poll_events(const char *s) {
    raia_not_use_s(s);
    glfwPollEvents();

    joint_t *joint = joint_init_out();
    joint_add_out_bool(joint, "result", true);
    return joint_out_write(joint);
}

RAIA_API const char * raia_app_window_should_close(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    GLFWwindow* window_id = (GLFWwindow*)(uintptr_t)joint_get_in_uint(joint, "window_id");

    int ret = glfwWindowShouldClose(window_id);

    joint_add_out_int(joint, "result", ret);
    return joint_out_write(joint);
}

RAIA_API const char * raia_app_window_set_title(const char *s) {

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

RAIA_API const char * raia_app_shader_init(const char* s) {
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

}

extern "C" {
RAIA_API const char* raia_gui_init_glfw(const char* s) {
    raia_not_use_s(s);
    if (glfwInit() != GL_TRUE) {
        fprintf(stderr, "Initialization of GLFW failed.\n");
        exit(EXIT_FAILURE);
    }
    glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_ES_API);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // 2
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    glfwWindowHint(GLFW_CONTEXT_CREATION_API, GLFW_EGL_CONTEXT_API);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 3.2+ only
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            // Required on Mac
    init_raia_callback();
    glfwSetErrorCallback(event_error_callback);
    glfwSetJoystickCallback(event_joystick_callback);

    joint_t *joint = joint_init_out();
    joint_add_out_bool(joint, "result", true);
    return joint_out_write(joint);
}

RAIA_API const char* raia_gui_create_window(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    int width = joint_get_in_int(joint, "width");
    int height = joint_get_in_int(joint, "height");
    const char *title = joint_get_in_str(joint, "title");

    GLFWwindow* window = glfwCreateWindow(width, height, title, NULL, NULL);
    if (!window) {
        fprintf(stderr, "Window creation failed.\n");
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    // HiDPI
    int res_width = width;
    int res_height = height;
    int now_width, now_height;
    glfwGetFramebufferSize(window, &now_width, &now_height);
    if (now_width > width) {
        res_width = width * 2;
        res_height = height * 2;
    }

    //#ifdef __APPLE__
    //    int windowWidth, windowHeight;
    //    int framebufferWidth, framebufferHeight;
    //    glfwGetWindowSize(window, &windowWidth, &windowHeight);
    //    glfwGetFramebufferSize(window, &framebufferWidth, &framebufferHeight);
    //    float scaleX = (float)framebufferWidth / windowWidth;
    //    float scaleY = (float)framebufferHeight / windowHeight;
    //#endif

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

typedef struct {
    GLuint VAO;
    GLuint VBO;
    GLuint EBO;
} vertex_t;

vertex_t _raia_gui_window_init_vertex() {
    float vertices[] = {
            -1.0f, 1.0f,  0.0f,  // Position 0
            0.0f,  0.0f,         // TexCoord 0
            -1.0f, -1.0f, 0.0f,  // Position 1
            0.0f,  1.0f,         // TexCoord 1
            1.0f,  -1.0f, 0.0f,  // Position 2
            1.0f,  1.0f,         // TexCoord 2
            1.0f,  1.0f,  0.0f,  // Position 3
            1.0f,  0.0f          // TexCoord 3
    };
    unsigned int indices[] = {
            0, 1, 2, 0, 2, 3
    };
    vertex_t vertex;
    //GLuint VAO, VBO, EBO;
    glGenVertexArrays(1, &vertex.VAO); // vertex array object
    glGenBuffers(1, &vertex.VBO); // vertex buffer object
    glGenBuffers(1, &vertex.EBO); // element buffer object
    glBindVertexArray(vertex.VAO);
    glBindBuffer(GL_ARRAY_BUFFER, vertex.VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vertex.EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    glBindVertexArray(0);

    puts("");
    printf("%lu\n", sizeof(vertices));
    printf("%lu\n", sizeof(indices));
    printf("%lu\n", 5 * sizeof(float));
    printf("%lu\n", 3 * sizeof(float));


    return vertex;
}

RAIA_API const char* raia_gui_window_init_vertex(const char *s) {
    vertex_t vertex = _raia_gui_window_init_vertex();
    joint_t *joint = joint_init_out();
    joint_add_out_uint(joint, "vao", vertex.VAO);
    joint_add_out_uint(joint, "vbo", vertex.VBO);
    joint_add_out_uint(joint, "ebo", vertex.EBO);
    return joint_out_write(joint);
}

GLuint _raia_gui_window_create_program() {
    const char* vertex_shader_source =
            "attribute vec4 a_position;"
            "attribute vec2 a_texCoord;"
            "varying vec2 v_texCoord;"
            "void main() {"
            "    gl_Position = a_position;"
            "    v_texCoord = a_texCoord;"
            "}";

    const char* fragment_shader_source =
            "precision mediump float;"
            "varying vec2 v_texCoord;"
            "uniform sampler2D s_texture;"
            "void main() {"
            "    gl_FragColor = texture2D(s_texture, v_texCoord);"
            "}";

    GLuint vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertex_shader_source, NULL);
    glCompileShader(vertexShader);
    GLuint fragmentShader;
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragment_shader_source, NULL);
    glCompileShader(fragmentShader);
    GLuint shaderProgram;
    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
    return shaderProgram;
}

RAIA_API const char* raia_gui_window_create_program(const char *s) {
    GLuint program = _raia_gui_window_create_program();
    joint_t *joint = joint_init_out();
    joint_add_out_uint(joint, "program", program);
    return joint_out_write(joint);
}

} // extern "C"

void raia_gui_set_imgui_style(ImGuiIO& io) {
    //ImGui::StyleColorsDark();
    ImGui::StyleColorsLight();
    ImGuiStyle& style = ImGui::GetStyle();
    if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable) {
        style.WindowBorderSize = 1.0f;
        style.WindowRounding = 0.0f;
        style.Colors[ImGuiCol_WindowBg].w = 1.0f;
        style.Colors[ImGuiCol_Text].w = 1.0f;
    }
    // スタイルのスケーリングを行う
    //#ifdef __APPLE__
    //    style.ScaleAllSizes(scaleX/2);  // 通常はscaleXとscaleYは等しいため、一方の値を使用
    //    io.FontGlobalScale = scaleX/2/2;
    //#endif
}

void raia_gui_set_imgui_io(ImGuiIO& io) {
    (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;         // Enable Docking
    io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;       // Enable Multi-Viewport / Platform Windows
    //io.ConfigViewportsNoAutoMerge = true;
    //io.ConfigViewportsNoTaskBarIcon = true;
}

void raia_gui_init_imgui_opengl(GLFWwindow* window) {
    const char* glsl_version = "#version 300 es";
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(glsl_version);
}

void raia_gui_set_imgui_font(ImGuiIO& io) {
    io.Fonts->AddFontDefault();
    io.Fonts->AddFontFromFileTTF("./Mplus1-Regular.ttf", 18.0f);
    //io.Fonts->AddFontFromFileTTF("../../misc/fonts/DroidSans.ttf", 16.0f);
    ImFont* font = io.Fonts->AddFontFromFileTTF("Mplus1-Regular.ttf", 18.0f, nullptr, io.Fonts->GetGlyphRangesJapanese());
    IM_ASSERT(font != nullptr);
    io.FontDefault = font;
}

void raia_gui_new_frame() {
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
}

void show_debug_window(float framerate) {
    ImGui::Begin("デバッグ情報");
    ImGui::Text("フレームレート: %.1f FPS", framerate);
    ImGui::End();
}

void show_test_window() {
    //static float f = 0.0f;
    static int counter = 0;
    ImGui::Begin("テスト");                          // Create a window called "Hello, world!" and append into it.
    //ImGui::Checkbox("Demo Window", &show_demo_window);      // Edit bools storing our window open/close state
    //ImGui::Checkbox("警告ダイアログ", &show_another_window);
    //ImGui::SliderFloat("float", &f, 0.0f, 1.0f);            // Edit 1 float using a slider from 0.0f to 1.0f
    //ImGui::ColorEdit3("clear color", (float*)&clear_color); // Edit 3 floats representing a color
    if (ImGui::Button("Button")) {                            // Buttons return true when clicked (most widgets return true when edited/activated)
        counter++;
    }
    ImGui::SameLine();
    ImGui::Text("counter = %d", counter);
    ImGui::End();
}

void show_alert_window() {
    //        if (show_another_window) {
    ImGui::Begin("警告ダイアログ");//, &show_another_window);   // Pass a pointer to our bool variable (the window will have a closing button that will clear the bool when clicked)
    ImGui::Text("ここにエラーメッセージを表示する");
    if (ImGui::Button("OK")) {
        //show_another_window = false;
    }
    ImGui::End();
//        }
}

void _raia_gui_imgui_cleanup() {
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}

void _raia_gui_init_imgui(GLFWwindow *window) {
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    raia_gui_set_imgui_io(io);
    raia_gui_set_imgui_style(io);
    raia_gui_init_imgui_opengl(window);
    raia_gui_set_imgui_font(io);
}

void _raia_gui_imgui_render() {
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    //
    GLFWwindow* backup_current_context = glfwGetCurrentContext();
    ImGui::UpdatePlatformWindows();
    ImGui::RenderPlatformWindowsDefault();
    glfwMakeContextCurrent(backup_current_context);
}

void _raia_gui_imgui_begin(const char* name) {
    ImGui::Begin(name);
}

void _raia_gui_imgui_end() {
    ImGui::End();
}

extern "C" {

RAIA_API const char* raia_gui_init_imgui(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    GLFWwindow* window = (GLFWwindow*)(uintptr_t)joint_get_in_uint(joint, "window_id");

    _raia_gui_init_imgui(window);

    joint_add_out_bool(joint, "result", true);
    return joint_out_write(joint);
}

RAIA_API const char* raia_gui_imgui_cleanup(const char *s) {
    _raia_gui_imgui_cleanup();

    joint_t *joint = joint_init_out();
    joint_add_out_bool(joint, "result", true);
    return joint_out_write(joint);
}

RAIA_API const char* raia_gui_test(const char *s) {
    printf("test\n");
    joint_t *joint = joint_init_out();
    return joint_out_write(joint);
}

RAIA_API const char* raia_gui_glfw_get_framebuffer_size(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    GLFWwindow* window = (GLFWwindow*)(uintptr_t)joint_get_in_uint(joint, "window_id");

    int width, height;
    glfwGetFramebufferSize(window, &width, &height);

    joint_add_out_int(joint, "width", width);
    joint_add_out_int(joint, "height", height);
    return joint_out_write(joint);
}

RAIA_API const char* raia_gui_gl_viewport(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    int x = joint_get_in_int(joint, "x");
    int y = joint_get_in_int(joint, "y");
    GLsizei width = joint_get_in_int(joint, "width");
    GLsizei height = joint_get_in_int(joint, "height");

    glViewport(x, y, width, height);

    joint_add_out_bool(joint, "result", true);
    return joint_out_write(joint);
}

RAIA_API const char* raia_gui_gl_clear_color(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    GLfloat red = (GLfloat)joint_get_in_real(joint, "red");
    GLfloat green = (GLfloat)joint_get_in_real(joint, "green");
    GLfloat blue = (GLfloat)joint_get_in_real(joint, "blue");
    GLfloat alpha = (GLfloat)joint_get_in_real(joint, "alpha");

    glClearColor(red, green, blue, alpha);

    joint_add_out_bool(joint, "result", true);
    return joint_out_write(joint);
}

RAIA_API const char* raia_gui_gl_clear(const char *s) {
    glClear(GL_COLOR_BUFFER_BIT);
    joint_t *joint = joint_init_out();
    joint_add_out_bool(joint, "result", true);
    return joint_out_write(joint);
}

RAIA_API const char* raia_gui_glfw_swap_buffers(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    GLFWwindow* window = (GLFWwindow*)(uintptr_t)joint_get_in_uint(joint, "window_id");

    glfwSwapBuffers(window);

    joint_add_out_bool(joint, "result", true);
    return joint_out_write(joint);
}

RAIA_API const char* raia_gui_imgui_new_frame(const char *s) {
    raia_gui_new_frame();
    joint_t *joint = joint_init_out();
    joint_add_out_bool(joint, "result", true);
    return joint_out_write(joint);
}

RAIA_API const char* raia_gui_imgui_render(const char *s) {
    _raia_gui_imgui_render();
    joint_t *joint = joint_init_out();
    joint_add_out_bool(joint, "result", true);
    return joint_out_write(joint);
}

RAIA_API const char* raia_gui_imgui_show_test(const char *s) {
    show_test_window();
    joint_t *joint = joint_init_out();
    joint_add_out_bool(joint, "result", true);
    return joint_out_write(joint);
}

RAIA_API const char* raia_gui_imgui_begin(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    const char* name = joint_get_in_str(joint, "name");

    _raia_gui_imgui_begin(name);

    joint_add_out_bool(joint, "result", true);
    return joint_out_write(joint);
}

RAIA_API const char* raia_gui_imgui_end(const char *s) {
    _raia_gui_imgui_end();

    joint_t *joint = joint_init_out();
    joint_add_out_bool(joint, "result", true);
    return joint_out_write(joint);
}

}

int main(int argc, char* argv[]) {
    const char* result = raia_gui_init_glfw("");
    std::cout << json::parse(result)["result"] << std::endl;

    const char* result_window = raia_gui_create_window(R"(
        {
            "width": 800,
            "height": 600,
            "title": "RaiaEngine v0.3"
        }
    )");
    GLFWwindow *main_window = (GLFWwindow *)(uintptr_t)json::parse(result_window)["id"];

    std::string arg = std::to_string((int64_t)(uintptr_t)main_window);
    std::cout << arg << std::endl;
    arg = "{\"window_id\":" + arg + "}";
    raia_gui_init_imgui(arg.c_str());

    //

//    // ウィンドウ内の頂点データとシェーダー
    vertex_t main_window_vertex = _raia_gui_window_init_vertex();
    GLuint main_window_program = _raia_gui_window_create_program();
//
//    // ウィンドウ内ピクセル描画
    int main_window_width = 800;
    int main_window_height = 600;
    int main_window_channels = 0;
    //int width, height, nrChannels;
    GLubyte* main_window_pixels = stbi_load("adv_sample_image.png", &main_window_width, &main_window_height, &main_window_channels, 0);
    //glPixelStorei(GL_UNPACK_ALIGNMENT, 1); // Use tightly packed data
    GLuint main_window_texture;
    glGenTextures(1, &main_window_texture);

//    // フレーム内ピクセルデータ
    const int frame_width = 320;
    const int frame_height = 240;
    GLubyte* frame_pixels = (GLubyte*)malloc(sizeof(GLubyte) * frame_width * frame_height * 4);
    GLuint frame_texture;
    glGenTextures(1, &frame_texture);

    bool is_multi_viewport = true;
//    bool show_demo_window = true;
//    bool show_another_window = true;
    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
//
//    double time_old = 0.0;
//    double time_new = 0.0;
//    float fps = 0.0;

    while (!glfwWindowShouldClose(main_window)) {
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        ImGui::ShowDemoWindow();

//        {
//            for (int i = 0; i < frame_width * frame_height * 4; i += 4) {
//                frame_pixels[i]     = rand_xor128(0, 255); // Red
//                frame_pixels[i + 1] = rand_xor128(0, 255); // Green
//                frame_pixels[i + 2] = rand_xor128(0, 255); // Blue
//                frame_pixels[i + 3] = 255; // Alpha
//            }
//            glBindTexture(GL_TEXTURE_2D, frame_texture);
//            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, frame_width, frame_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, frame_pixels);
//            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
//            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
//            glBindTexture(GL_TEXTURE_2D, 1);
//
//            auto size = ImVec2(frame_width, frame_height);
//            if (ImGui::Begin("フレーム内にピクセルを描画する")) {
//                ImGui::Image((void*)(intptr_t)frame_texture, size);
//            }
//            ImGui::End();
//        }

        //int display_w, display_h;
        //glfwGetFramebufferSize(main_window, &display_w, &display_h);
        //glViewport(0, 0, display_w, display_h);
        //glClearColor(clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w);
        //glClear(GL_COLOR_BUFFER_BIT);

        glBindTexture(GL_TEXTURE_2D, main_window_texture);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, main_window_width, main_window_height, 0, GL_RGB, GL_UNSIGNED_BYTE, main_window_pixels);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glUseProgram(main_window_program);
        glBindVertexArray(main_window_vertex.VAO);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        glBindTexture(GL_TEXTURE_2D, 1);

        free((void *)raia_gui_imgui_render(""));

        glfwSwapBuffers(main_window);
        glfwPollEvents();
    }

    raia_gui_imgui_cleanup("");

    // Delete OpenGL objects
//    glDeleteVertexArrays(1, &main_window_vertex.VAO);
//    glDeleteBuffers(1, &main_window_vertex.VBO);
//    glDeleteBuffers(1, &main_window_vertex.EBO);
//
//    glDeleteTextures(1, &main_window_texture);
//    free(main_window_pixels);
//    glDeleteTextures(1, &frame_texture);
//    free(frame_pixels);
    glfwDestroyWindow(main_window);
    glfwTerminate();
    return 0;
}
