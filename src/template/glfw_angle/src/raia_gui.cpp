#include "raia_gui.h"

int main(int argc, char* argv[]) {
    // GLFWを初期化する
    {
        if (glfwInit() != GL_TRUE) {
            fprintf(stderr, "Initialization of GLFW failed.\n");
            exit(EXIT_FAILURE);
        }
        glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_ES_API);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
        glfwWindowHint(GLFW_CONTEXT_CREATION_API, GLFW_EGL_CONTEXT_API);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    }
    int width = 800;
    int height = 600;
    GLFWwindow *window;
    {
        window = glfwCreateWindow(width, height, "GUI", NULL, NULL);
        if (!window) {
            fprintf(stderr, "Window creation failed.\n");
            glfwTerminate();
            exit(EXIT_FAILURE);
        }
        glfwMakeContextCurrent(window);
        glfwSwapInterval(1);
    }

    // コールバックを設定する
    {
        glfwSetErrorCallback(event_error_callback);
        glfwSetJoystickCallback(event_joystick_callback);
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
    }

    // 頂点データを作成する
    GLuint vertex_array_object;
    GLuint vertex_buffer_object;
    GLuint element_buffer_object;
    {
        float vertices[] = {
                -1.0f, 1.0f, 0.0f,  // Position 0
                0.0f, 0.0f,         // TexCoord 0
                -1.0f, -1.0f, 0.0f,  // Position 1
                0.0f, 1.0f,         // TexCoord 1
                1.0f, -1.0f, 0.0f,  // Position 2
                1.0f, 1.0f,         // TexCoord 2
                1.0f, 1.0f, 0.0f,  // Position 3
                1.0f, 0.0f          // TexCoord 3
        };
        unsigned int indices[] = {
                0, 1, 2, 0, 2, 3
        };
        glGenVertexArrays(1, &vertex_array_object);
        glGenBuffers(1, &vertex_buffer_object);
        glGenBuffers(1, &element_buffer_object);
        glBindVertexArray(vertex_array_object);
        glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer_object);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, element_buffer_object);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *) 0);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *) (3 * sizeof(float)));
        glEnableVertexAttribArray(1);
        glBindVertexArray(0);
    }

    // シェーダーを作成する
    GLuint shader_program;
    {
        const char *vertex_shader_source =
                "attribute vec4 a_position;"
                "attribute vec2 a_texCoord;"
                "varying vec2 v_texCoord;"
                "void main() {"
                "    gl_Position = a_position;"
                "    v_texCoord = a_texCoord;"
                "}";
        const char *fragment_shader_source =
                "precision mediump float;"
                "varying vec2 v_texCoord;"
                "uniform sampler2D s_texture;"
                "void main() {"
                "    gl_FragColor = texture2D(s_texture, v_texCoord);"
                "}";
        GLuint vertex_shader = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertex_shader, 1, &vertex_shader_source, NULL);
        glCompileShader(vertex_shader);
        GLuint fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragment_shader, 1, &fragment_shader_source, NULL);
        glCompileShader(fragment_shader);
        shader_program = glCreateProgram();
        glAttachShader(shader_program, vertex_shader);
        glAttachShader(shader_program, fragment_shader);
        glLinkProgram(shader_program);
        glDeleteShader(vertex_shader);
        glDeleteShader(fragment_shader);
    }

    // ウィンドウのピクセルデータを初期化する
    GLubyte *image_pixels;
    int image_width = 800;
    int image_height = 600;
    int image_channels = 0;
    GLuint window_texture;
    {
        image_pixels = stbi_load("adv_sample_image.png", &image_width, &image_height, &image_channels, 0);
        glGenTextures(1, &window_texture);
    }

    // メインループ
    while (!glfwWindowShouldClose(window)) {
        glBindTexture(GL_TEXTURE_2D, window_texture);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image_width, image_height, 0, GL_RGB, GL_UNSIGNED_BYTE, image_pixels);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glUseProgram(shader_program);
        glBindVertexArray(vertex_array_object);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        glBindTexture(GL_TEXTURE_2D, 2);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // 不要なオブジェクトを解放する
    glDeleteVertexArrays(1, &vertex_array_object);
    glDeleteBuffers(1, &vertex_buffer_object);
    glDeleteBuffers(1, &element_buffer_object);
    glDeleteTextures(1, &window_texture);
    free(image_pixels);
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}

void event_error_callback(int error, const char *message) {}
void event_joystick_callback(int jid, int event) {}
void event_window_pos_callback(GLFWwindow *window, int x, int y) {}
void event_window_size_callback(GLFWwindow *window, int width, int height) {}
void event_window_close_callback(GLFWwindow *window) {}
void event_window_refresh_callback(GLFWwindow *window) {}
void event_window_focus_callback(GLFWwindow* window, int focused) {}
void event_window_iconify_callback(GLFWwindow *window, int iconified) {}
void event_framebuffer_size_callback(GLFWwindow *window, int width, int height) {}
void event_key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {}
void event_cursor_position_callback(GLFWwindow* window, double xpos, double ypos) {}
void event_mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {}
void event_character_callback(GLFWwindow* window, unsigned int codepoint) {}
void event_character_mods_callback(GLFWwindow *window, unsigned int codepoint, int mods) {}
void event_cursor_enter_callback(GLFWwindow* window, int entered) {}
void event_scroll_callback(GLFWwindow* window, double xoffset, double yoffset) {}
void event_drop_callback(GLFWwindow* window, int count, const char** paths) {}