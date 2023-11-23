#include "raia_gui.h"

extern "C" {

typedef struct {
    GLuint VAO;
    GLuint VBO;
    GLuint EBO;
} vertex_t;

}

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
    // HiDPI
    {
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
    }

    // コールバックを設定する
    {
        init_raia_callback();
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

    // ImGuiを開始する
    {
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGuiIO &io = ImGui::GetIO();

        //raia_gui_set_imgui_io(io);
        //(void)io;
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
        io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;         // Enable Docking
        io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;       // Enable Multi-Viewport / Platform Windows
        //io.ConfigViewportsNoAutoMerge = true;
        //io.ConfigViewportsNoTaskBarIcon = true;

        //raia_gui_set_imgui_style(io);
        //ImGui::StyleColorsDark();
        ImGui::StyleColorsLight();
        ImGuiStyle &style = ImGui::GetStyle();
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

        //raia_gui_init_imgui_opengl(main_window);
        const char *glsl_version = "#version 300 es";
        ImGui_ImplGlfw_InitForOpenGL(window, true);
        ImGui_ImplOpenGL3_Init(glsl_version);
        //raia_gui_set_imgui_font(io);
        io.Fonts->AddFontDefault();
        io.Fonts->AddFontFromFileTTF("./Mplus1-Regular.ttf", 18.0f);
        //io.Fonts->AddFontFromFileTTF("../../misc/fonts/DroidSans.ttf", 16.0f);
        ImFont *font = io.Fonts->AddFontFromFileTTF("Mplus1-Regular.ttf", 18.0f, nullptr,
                                                    io.Fonts->GetGlyphRangesJapanese());
        IM_ASSERT(font != nullptr);
        io.FontDefault = font;
    }


    // 頂点データを作成する
    vertex_t main_window_vertex;
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
        glGenVertexArrays(1, &main_window_vertex.VAO); // vertex array object
        glGenBuffers(1, &main_window_vertex.VBO); // vertex buffer object
        glGenBuffers(1, &main_window_vertex.EBO); // element buffer object
        glBindVertexArray(main_window_vertex.VAO);
        glBindBuffer(GL_ARRAY_BUFFER, main_window_vertex.VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, main_window_vertex.EBO);
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

    // ImGuiウィンドウのピクセルデータを初期化する
    const int imgui_window_width = 320;
    const int imgui_window_height = 240;
    GLubyte* imgui_window_pixels = (GLubyte*)malloc(sizeof(GLubyte) * imgui_window_width * imgui_window_height * 4);
    GLuint imgui_window_texture;
    glGenTextures(1, &imgui_window_texture);

    while (!glfwWindowShouldClose(window)) {
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        // ImGuiのフレームを描画する
        {
            for (int i = 0; i < imgui_window_width * imgui_window_height * 4; i += 4) {
                imgui_window_pixels[i]     = rand_xor128(0, 255); // Red
                imgui_window_pixels[i + 1] = rand_xor128(0, 255); // Green
                imgui_window_pixels[i + 2] = rand_xor128(0, 255); // Blue
                imgui_window_pixels[i + 3] = 255; // Alpha
            }
            glBindTexture(GL_TEXTURE_2D, imgui_window_texture);
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, imgui_window_width, imgui_window_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, imgui_window_pixels);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
            glBindTexture(GL_TEXTURE_2D, 1);
            auto size = ImVec2(imgui_window_width, imgui_window_height);
            if (ImGui::Begin("フレーム内にピクセルを描画する")) {
                ImGui::Image((void*)(intptr_t)imgui_window_texture, size);
            }
            ImGui::End();
        }

        glBindTexture(GL_TEXTURE_2D, window_texture);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image_width, image_height, 0, GL_RGB, GL_UNSIGNED_BYTE, image_pixels);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glUseProgram(shader_program);
        glBindVertexArray(main_window_vertex.VAO);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        glBindTexture(GL_TEXTURE_2D, 1);

        // ImGuiの描画を実行する
        {
            ImGui::Render();
            ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
            GLFWwindow* current_context = glfwGetCurrentContext();
            ImGui::UpdatePlatformWindows();
            ImGui::RenderPlatformWindowsDefault();
            glfwMakeContextCurrent(current_context);
        }

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    //raia_gui_imgui_cleanup("");
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    // Delete OpenGL objects
    glDeleteVertexArrays(1, &main_window_vertex.VAO);
    glDeleteBuffers(1, &main_window_vertex.VBO);
    glDeleteBuffers(1, &main_window_vertex.EBO);
    glDeleteTextures(1, &window_texture);
    free(image_pixels);
    glDeleteTextures(1, &imgui_window_texture);
    free(imgui_window_pixels);
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
