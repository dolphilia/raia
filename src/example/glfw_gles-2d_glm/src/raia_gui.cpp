#include "raia_gui.h"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

extern "C" {
#include <stdio.h>
#include <stdlib.h>
#include "GLFW/glfw3.h" // Will drag system OpenGL headers
#include "GLES3/gl32.h"
#define STB_IMAGE_IMPLEMENTATION
#include "../../../third_party/c/nothings/stb/stb_image.h"
#ifdef _WIN32
#define GL_TEXTURE0 0x84C0
#endif
}

static const char* vertex_shader_source = R"(#version 300 es
layout(location = 0) in vec3 aPos;
layout(location = 1) in vec2 aTexCoord;

uniform mat4 uMVP;

out vec2 vTexCoord;

void main()
{
    gl_Position = uMVP * vec4(aPos, 1.0);
    vTexCoord = aTexCoord;
}
)";

static const char* fragment_shader_source = R"(#version 300 es
precision mediump float;

in vec2 vTexCoord;
out vec4 FragColor;

uniform sampler2D s_texture;

void main()
{
    FragColor = texture(s_texture, vTexCoord);
}
)";

#include <iostream>

// エラーチェック用ユーティリティ関数
static void checkCompileErrors(GLuint shader, const char* type) {
    GLint success;
    GLchar infoLog[1024];
    if (type == std::string("PROGRAM")) {
        glGetProgramiv(shader, GL_LINK_STATUS, &success);
        if (!success) {
            glGetProgramInfoLog(shader, 1024, NULL, infoLog);
            fprintf(stderr, "ERROR::PROGRAM_LINKING_ERROR of type: %s\n%s\n", type, infoLog);
        }
    } else {
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
        if (!success) {
            glGetShaderInfoLog(shader, 1024, NULL, infoLog);
            fprintf(stderr, "ERROR::SHADER_COMPILATION_ERROR of type: %s\n%s\n", type, infoLog);
        }
    }
}

int main(int argc, char* argv[]) {
    if (glfwInit() != GL_TRUE) {
        fprintf(stderr, "Initialization of GLFW failed.\n");
        exit(EXIT_FAILURE);
    }

    // OpenGL ES 3.0 コンテキストを作成するためのヒントを設定
    glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_ES_API);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    glfwWindowHint(GLFW_CONTEXT_CREATION_API, GLFW_EGL_CONTEXT_API);
    // Core Profile は PC 向け OpenGL では有効だが、ANGLE 等では不要な場合もある
     glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    int width = 800;
    int height = 600;
    const char *title = "3D Cube with Texture";

    GLFWwindow* window = glfwCreateWindow(width, height, title, NULL, NULL);
    if (!window) {
        fprintf(stderr, "Window creation failed.\n");
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    // 深度テストを有効にする
    glEnable(GL_DEPTH_TEST);

    //------------------------------------------------
    // 1) 立方体の頂点データとインデックス
    //------------------------------------------------
    // 立方体を  [-0.5, 0.5] の範囲で作る例（各面にテクスチャを貼る）
    // 24個の頂点（各面4頂点 x 6面）
    float cubeVertices[] = {
        // Positions          // TexCoords
        // Front face
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
         0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
        -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,

        // Back face
        -0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
         0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
         0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
        -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,

        // Left face
        -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
        -0.5f,  0.5f, -0.5f,  0.0f, 0.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,  1.0f, 1.0f,

        // Right face
         0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
         0.5f,  0.5f, -0.5f,  1.0f, 0.0f,
         0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
         0.5f, -0.5f,  0.5f,  0.0f, 1.0f,

        // Top face
        -0.5f,  0.5f, -0.5f,  0.0f, 0.0f,
         0.5f,  0.5f, -0.5f,  1.0f, 0.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
        -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,

        // Bottom face
        -0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
         0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
         0.5f, -0.5f,  0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,  1.0f, 1.0f,
    };

    // 36個のインデックス（各面2つの三角形 x 6面 = 12三角形）
    unsigned int indices[] = {
        // Front face
        0, 1, 2,  0, 2, 3,
        // Back face
        4, 5, 6,  4, 6, 7,
        // Left face
        8, 9, 10, 8, 10,11,
        // Right face
        12,13,14, 12,14,15,
        // Top face
        16,17,18, 16,18,19,
        // Bottom face
        20,21,22, 20,22,23
    };

    //------------------------------------------------
    // 2) VAO, VBO, EBO の生成とバインド
    //------------------------------------------------
    GLuint VAO, VBO, EBO;
    glGenVertexArrays(1, &VAO); // Vertex Array Object
    glGenBuffers(1, &VBO);      // Vertex Buffer Object
    glGenBuffers(1, &EBO);      // Element Buffer Object

    glBindVertexArray(VAO);

    // VBO設定
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(cubeVertices), cubeVertices, GL_STATIC_DRAW);

    // EBO設定
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    // 頂点属性 (位置: layout(location = 0))
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // 頂点属性 (テクスチャ座標: layout(location = 1))
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glBindVertexArray(0);

    //------------------------------------------------
    // 3) シェーダーのコンパイルとリンク
    //------------------------------------------------
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertex_shader_source, NULL);
    glCompileShader(vertexShader);
    checkCompileErrors(vertexShader, "VERTEX");

    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragment_shader_source, NULL);
    glCompileShader(fragmentShader);
    checkCompileErrors(fragmentShader, "FRAGMENT");

    GLuint program = glCreateProgram();
    glAttachShader(program, vertexShader);
    glAttachShader(program, fragmentShader);
    glLinkProgram(program);
    checkCompileErrors(program, "PROGRAM");

    // シェーダーはリンク後に削除してOK
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    //------------------------------------------------
    // 4) テクスチャの読み込み
    //------------------------------------------------
    int image_width = 0;
    int image_height = 0;
    int channels = 0;
    unsigned char* pixels = stbi_load("adv_sample_image.png", &image_width, &image_height, &channels, 0);
    if (!pixels) {
        fprintf(stderr, "Failed to load texture image.\n");
        glfwDestroyWindow(window);
        glfwTerminate();
        return -1;
    }

    GLuint texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    // 読み込んだ画像をテクスチャに割り当て (RGB か RGBA かで引数を変える)
    GLint format = (channels == 4) ? GL_RGBA : GL_RGB;
    glTexImage2D(GL_TEXTURE_2D, 0, format, image_width, image_height, 0, format, GL_UNSIGNED_BYTE, pixels);
    glGenerateMipmap(GL_TEXTURE_2D);

    // テクスチャパラメータ
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    stbi_image_free(pixels);

    //------------------------------------------------
    // 5) メインループ
    //------------------------------------------------
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();

        // ウィンドウサイズ取得
        glfwGetFramebufferSize(window, &width, &height);
        glViewport(0, 0, width, height);

        // 画面クリア（色＋深度）
        glClearColor(0.5f, 0.6f, 0.7f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // シェーダー使用
        glUseProgram(program);

        // MVP行列を設定
        //  - 投影行列: 45度の透視投影
        //  - ビュー行列: (2,2,2)あたりから原点を見る
        //  - モデル行列: Y軸回転を追加（時間経過に応じて回転させる例）
        float timeValue = (float)glfwGetTime();
        glm::mat4 model = glm::mat4(1.0f);
        model = glm::rotate(model, timeValue, glm::vec3(0.0f, 1.0f, 0.0f)); // 回転

        glm::mat4 view = glm::lookAt(glm::vec3(2.0f, 2.0f, 2.0f),
                                     glm::vec3(0.0f, 0.0f, 0.0f),
                                     glm::vec3(0.0f, 1.0f, 0.0f));
        glm::mat4 projection = glm::perspective(glm::radians(45.0f),
                                                (float)width / (float)height,
                                                0.1f, 100.0f);
        glm::mat4 mvp = projection * view * model;

        // シェーダーユニフォームに送る
        GLint mvpLoc = glGetUniformLocation(program, "uMVP");
        glUniformMatrix4fv(mvpLoc, 1, GL_FALSE, glm::value_ptr(mvp));

        // テクスチャユニット 0 を使う
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texture);
        GLint texLoc = glGetUniformLocation(program, "s_texture");
        glUniform1i(texLoc, 0);

        // VAO バインド
        glBindVertexArray(VAO);

        // 立方体を描画（36頂点）
        glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

        glfwSwapBuffers(window);
    }

    // 後処理
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
    glDeleteProgram(program);
    glDeleteTextures(1, &texture);

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
