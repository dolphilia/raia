import Foundation

// 初期化
if glfwInit() == GLFW_FALSE {
    print("Failed to initialize GLFW")
    exit(EXIT_FAILURE)
}

// ウィンドウのヒント設定 (ここではOpenGL 3.3 Core Profileを使用)
glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2)
glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1)
//glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE)

#if os(macOS)
//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE) // macOSの互換性
#endif

glfwSetErrorCallback { error, description in
    if let desc = description {
        print("GLFW Error: \(String(cString: desc))")
    }
}

// ウィンドウ作成
guard let window = glfwCreateWindow(800, 600, "GLFW Window", nil, nil) else {
    print("Failed to create GLFW window")
    glfwTerminate()
    exit(EXIT_FAILURE)
}

// OpenGLコンテキストを現在のスレッドに設定
glfwMakeContextCurrent(window)

// メインループ
while glfwWindowShouldClose(window) == GLFW_FALSE {
    // 描画処理（今回は背景色を塗るだけ）
    glClear(GLbitfield(GL_COLOR_BUFFER_BIT))

    // バッファをスワップ
    glfwSwapBuffers(window)

    // イベントをポーリング
    glfwPollEvents()
}

// クリーンアップ
glfwDestroyWindow(window)
glfwTerminate()
print("GLFW terminated")