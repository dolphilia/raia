#include "raia_gui.h"

#include "../../../third_party/cpp/ocornut/imgui/imgui.h"
#include "../../../third_party/cpp/ocornut/imgui/imgui_impl_glfw.h"
#include "../../../third_party/cpp/ocornut/imgui/imgui_impl_opengl3.h"

extern "C" {
#include <time.h>
#include "util/util_math.h"
#include "GLFW/glfw3.h" // Will drag system OpenGL headers
#define STB_IMAGE_IMPLEMENTATION
#include "../../../third_party/c/nothings/stb/stb_image.h"
#ifdef _WIN32
#define GL_TEXTURE0 0x84C0
#endif
}

int main(int argc, char* argv[]) {
    if (glfwInit() != GL_TRUE) {
        fprintf(stderr, "Initialization of GLFW failed.\n");
        exit(EXIT_FAILURE);
    }
    glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_ES_API);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // 2
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    glfwWindowHint(GLFW_CONTEXT_CREATION_API, GLFW_EGL_CONTEXT_API);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 3.2+ only

    int width = 800;
    int height = 600;
    const char *title = "RaiaEngine";
    GLFWwindow* window = glfwCreateWindow(width, height, title, NULL, NULL);
    if (!window) {
        fprintf(stderr, "Window creation failed.\n");
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;         // Enable Docking
    io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;       // Enable Multi-Viewport / Platform Windows
    ImGui::StyleColorsLight();
    ImGuiStyle& style = ImGui::GetStyle();
    if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable) {
        style.WindowBorderSize = 1.0f;
        style.WindowRounding = 0.0f;
        style.Colors[ImGuiCol_WindowBg].w = 1.0f;
        style.Colors[ImGuiCol_Text].w = 1.0f;
    }

    const char* glsl_version = "#version 300 es";
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(glsl_version);

    io.Fonts->AddFontDefault();
    io.Fonts->AddFontFromFileTTF("./Mplus1-Regular.ttf", 18.0f);
    ImFont* font = io.Fonts->AddFontFromFileTTF("Mplus1-Regular.ttf", 18.0f, nullptr, io.Fonts->GetGlyphRangesJapanese());
    IM_ASSERT(font != nullptr);
    io.FontDefault = font;

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
    GLuint VAO, VBO, EBO;
    glGenVertexArrays(1, &VAO); // vertex array object
    glGenBuffers(1, &VBO); // vertex buffer object
    glGenBuffers(1, &EBO); // element buffer object
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    glBindVertexArray(0);

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
    GLuint program;
    program = glCreateProgram();
    glAttachShader(program, vertexShader);
    glAttachShader(program, fragmentShader);
    glLinkProgram(program);
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    int image_width = 800;
    int image_height = 600;
    int channels = 0;
    GLubyte* pixels = stbi_load("adv_sample_image.png", &image_width, &image_height, &channels, 0);
    GLuint texture;
    glGenTextures(1, &texture);

    const int frame_width = 320;
    const int frame_height = 240;
    GLubyte* frame_pixels = (GLubyte*)malloc(sizeof(GLubyte) * frame_width * frame_height * 4);
    GLuint frame_texture;
    glGenTextures(1, &frame_texture);

    while (!glfwWindowShouldClose(window)) {
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
        ImGui::ShowDemoWindow();
        {
            for (int i = 0; i < frame_width * frame_height * 4; i += 4) {
                frame_pixels[i]     = rand_xor128(0, 255); // Red
                frame_pixels[i + 1] = rand_xor128(0, 255); // Green
                frame_pixels[i + 2] = rand_xor128(0, 255); // Blue
                frame_pixels[i + 3] = 255; // Alpha
            }
            glBindTexture(GL_TEXTURE_2D, frame_texture);
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, frame_width, frame_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, frame_pixels);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

            auto size = ImVec2(frame_width, frame_height);
            if (ImGui::Begin("フレーム内にピクセルを描画する")) {
                ImGui::Image((void*)(intptr_t)frame_texture, size);
            }
            ImGui::End();
        }
        glViewport(0, 0, width, height);
        glClearColor(1,1,1,1);
        glClear(GL_COLOR_BUFFER_BIT);
        glBindTexture(GL_TEXTURE_2D, texture);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, pixels);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glUseProgram(program);
        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        GLFWwindow* backup_current_context = glfwGetCurrentContext();
        ImGui::UpdatePlatformWindows();
        ImGui::RenderPlatformWindowsDefault();
        glfwMakeContextCurrent(backup_current_context);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    free(pixels);
    glDeleteVertexArrays(1, &VAO);
    glDeleteTextures(1, &texture);
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
