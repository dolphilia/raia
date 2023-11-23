#include "raia_gui.h"

// Skiaヘッダのインクルード
#include "include/core/SkBitmap.h"
#include "include/core/SkCanvas.h"
#include "include/core/SkPaint.h"
#include "include/core/SkRect.h"
#include "include/core/SkImage.h"
#include "include/codec/SkPngDecoder.h"
#include "include/core/SkStream.h"
#include "include/core/SkData.h"
#include "include/core/SkPath.h"

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

    // SkBitmapとSkCanvasを初期化する
    SkBitmap skBitmap;
    skBitmap.allocN32Pixels(image_width, image_height);
    SkCanvas canvas(skBitmap);

    // PNG画像を読み込む
    std::unique_ptr<SkStream> stream = SkStream::MakeFromFile("adv_sample_image.png");
    auto data = SkData::MakeFromStream(stream.get(), stream->getLength());
    sk_sp<SkImage> image = SkImages::DeferredFromEncodedData(data);

    // 画像をキャンバスに描画
    canvas.drawImage(image.get(), 0, 0);

    // 図形を描画する
    SkPaint paint;
    paint.setBlendMode(SkBlendMode::kOverlay);
    paint.setColor(SK_ColorBLUE); // 赤色を選択
    SkRect rect = SkRect::MakeXYWH(100, 100, 200, 200); // 四角形の位置とサイズ
    canvas.drawRect(rect, paint); // 四角形を描画

    // パスを描画する
    const SkScalar scale = 256.0f;
    const SkScalar R = 0.45f * scale;
    const SkScalar TAU = 6.2831853f;
    SkPath path;
    path.moveTo(R, 0.0f);
    for (int i = 1; i < 7; ++i) {
        SkScalar theta = 3 * i * TAU / 7;
        path.lineTo(R * cos(theta), R * sin(theta));
    }
    path.close();
    SkPaint p;
    p.setAntiAlias(true);
    //canvas.clear(SK_ColorWHITE);
    //canvas.translate(0.5f * scale, 0.5f * scale);
    canvas.drawPath(path, p);

    // ピクセルデータを書き込む
    //skBitmap.setPixels(image_pixels);

    // Skiaのビットマップからピクセルデータを取得
    GLubyte* skia_pixels = (GLubyte*)skBitmap.getPixels();


    // メインループ
    while (!glfwWindowShouldClose(window)) {
        glBindTexture(GL_TEXTURE_2D, window_texture);
        //glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image_width, image_height, 0, GL_RGB, GL_UNSIGNED_BYTE, image_pixels);
        // Skiaで描画したピクセルデータをOpenGLテクスチャにコピー
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        //glBindTexture(GL_TEXTURE_2D, window_texture);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image_width, image_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, skia_pixels);

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

//#include "../skia/include/core/SkRefCnt.h"
//#include "../skia/include/core/SkImage.h"
//#include "../skia/include/core/SkImageInfo.h"
//#include "../skia/include/core/SkCanvas.h"
//#include "../skia/include/core/SkGraphics.h"
//#include "../skia/include/core/SkPaint.h"
//#include "../skia/include/core/SkSurface.h"
//#include "../skia/include/core/SkColor.h"
//#include "../skia/include/private/gpu/ganesh/GrImageContext.h"
//#include "../skia/include/private/gpu/ganesh/GrContext_Base.h"
//#define SK_GL
////#define SK_METAL
//#include "../skia/include/gpu/GrTypes.h"
//#include "../skia/include/gpu/GrDirectContext.h"
//#include "../skia/include/gpu/ganesh/gl/GrGLBackendSurface.h"
//#include "../skia/include/gpu/ganesh/gl/GrGLDirectContext.h"
//#include "../skia/include/gpu/ganesh/SkSurfaceGanesh.h"
//#include "../skia/include/gpu/gl/GrGLInterface.h"
//#include "../skia/include/gpu/mtl/GrMtlBackendContext.h"
//#include "../skia/include/gpu/mtl/MtlMemoryAllocator.h"
//#include "../skia/include/gpu/mtl/GrMtlTypes.h"
//#include "../skia/include/gpu/gl/egl/GrGLMakeEGLInterface.h"
//
//#include "include/gpu/GrDirectContext.h"
//#include "include/gpu/gl/GrGLInterface.h"
//#include "../skia/include/gpu/gl/GrGLInterface.h"
//#include "include/core/SkData.h"
//#include "include/core/SkImage.h"
//#include "include/core/SkStream.h"
//#include "include/core/SkSurface.h"
//
////class GrDirectContext;
////using namespace skgpu;
////using namespace sktext;
////using namespace GrDirectContexts;
//
//int main(int argc, char* argv[]) {
//
//    // GLFWを初期化する
//    if (glfwInit() != GL_TRUE) {
//        fprintf(stderr, "Initialization of GLFW failed.\n");
//        exit(EXIT_FAILURE);
//    }
//    glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_ES_API);
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
//    glfwWindowHint(GLFW_CONTEXT_CREATION_API, GLFW_EGL_CONTEXT_API);
//    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//    int width = 800;
//    int height = 600;
//    GLFWwindow *window = glfwCreateWindow(width, height, "GUI", NULL, NULL);
//    if (!window) {
//        fprintf(stderr, "Window creation failed.\n");
//        glfwTerminate();
//        exit(EXIT_FAILURE);
//    }
//    glfwMakeContextCurrent(window);
//    glfwSwapInterval(1);
//
//
//    //auto *vkContex = new GrMtlBackendContext;
//    // GrRecordingContext
//
//    // Skiaの初期化
//
//    // GrGLMakeNativeInterface, GrGLMakeEGLInterface();
//    //GrDirectContext(GrBackendApi backend, const GrContextOptions& options)
//    sk_sp<const GrGLInterface> interface = nullptr;
//    //sk_sp<const GrGLInterface> glInterface = GrGLMakeNativeInterface();
//    auto * grContext = new GrDirectContexts::MakeGL(interface);
//
//
//
//    //            glInterface,
//    //            nullptr, // 抽象バックエンド
//
//
//    //SkImageInfo info = SkImageInfo::MakeN32Premul(width, height);
//    //sk_sp<SkSurface> surface = SkSurfaces::RenderTarget(grContext.get(), skgpu::Budgeted::kNo, info);
//    //SkCanvas* canvas = surface->getCanvas();
//
//
//
//    // メインループ
//    while (!glfwWindowShouldClose(window)) {
//        // Skiaを使用して図形を描画
////        canvas->clear(SK_ColorWHITE);
////        SkPaint paint;
////        paint.setColor(SK_ColorBLUE);
////        canvas->drawRect(SkRect::MakeXYWH(100, 100, 600, 400), paint);
////
////        // Skiaの描画結果をOpenGL ESを介してウィンドウに表示
////
////        surface->flushAndSubmit();
//        glfwSwapBuffers(window);
//        glfwPollEvents();
//    }
//
//    glfwDestroyWindow(window);
//    glfwTerminate();
//    return 0;
//}


// #include "stb/stb_image.h"
// #include "GLFW/glfw3.h"
// #include "EGL/egl.h"
// #include "GLES3/gl32.h"




/*
#include "include/core/SkAlphaType.h"
#include "include/core/SkCanvas.h"
#include "include/core/SkColor.h"
#include "include/core/SkColorType.h"
#include "include/core/SkImageInfo.h"
#include "include/core/SkRefCnt.h"
#include "include/core/SkSurface.h"
#include "include/core/SkTypes.h"
#include "include/gpu/GrDirectContext.h"
#include "include/gpu/ganesh/SkSurfaceGanesh.h"
#include "include/gpu/ganesh/vk/GrVkDirectContext.h"
#include "include/gpu/vk/GrVkBackendContext.h"
#include "include/gpu/vk/VulkanExtensions.h"
//#include "tools/gpu/vk/VkTestUtils.h"

#include <string.h>
//#include <vulkan/vulkan_core.h>
#include <functional>
#include <memory>

#define ACQUIRE_INST_VK_PROC(name)                                                           \
    do {                                                                                     \
    fVk##name = reinterpret_cast<PFN_vk##name>(getProc("vk" #name, backendContext.fInstance, \
                                                       VK_NULL_HANDLE));                     \
    if (fVk##name == nullptr) {                                                              \
        SkDebugf("Function ptr for vk%s could not be acquired\n", #name);                    \
        return 1;                                                                            \
    }                                                                                        \
    } while(false)

int main(int argc, char** argv) {
    GrVkBackendContext backendContext;
    VkDebugReportCallbackEXT debugCallback;
    std::unique_ptr<skgpu::VulkanExtensions> extensions(new skgpu::VulkanExtensions());
    std::unique_ptr<VkPhysicalDeviceFeatures2> features(new VkPhysicalDeviceFeatures2);

    // First we need to create a GrVkBackendContext so that we can make a Vulkan GrDirectContext.
    // The vast majority of this chunk of code is setting up the VkInstance and VkDevice objects.
    // Normally a client will have their own way of creating these objects. This example uses Skia's
    // test helper sk_gpu_test::CreateVkBackendContext to aid in this. Clients can look at this
    // function as a guide on things to consider when setting up Vulkan for themselves, but they
    // should not depend on that function. We may arbitrarily change it as it is meant only for Skia
    // internal testing. Additionally it may do some odd things that a normal Vulkan user wouldn't
    // do because it is againt meant for Skia testing.
    {
        PFN_vkGetInstanceProcAddr instProc;
        //if (!sk_gpu_test::LoadVkLibraryAndGetProcAddrFuncs(&instProc)) {
        //    return 1;
        //}

        memset(features.get(), 0, sizeof(VkPhysicalDeviceFeatures2));
        features->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2;
        features->pNext = nullptr;
        // Fill in features you want to enable here

        backendContext.fInstance = VK_NULL_HANDLE;
        backendContext.fDevice = VK_NULL_HANDLE;

        //if (!sk_gpu_test::CreateVkBackendContext(instProc, &backendContext, extensions.get(),
        //                                         features.get(), &debugCallback)) {
        //    return 1;
        //}
    }

    auto getProc = backendContext.fGetProc;
    PFN_vkDestroyInstance fVkDestroyInstance;
    PFN_vkDestroyDebugReportCallbackEXT fVkDestroyDebugReportCallbackEXT = nullptr;
    PFN_vkDestroyDevice fVkDestroyDevice;
    ACQUIRE_INST_VK_PROC(DestroyInstance);
    if (debugCallback != VK_NULL_HANDLE) {
        ACQUIRE_INST_VK_PROC(DestroyDebugReportCallbackEXT);
    }
    ACQUIRE_INST_VK_PROC(DestroyDevice);

    // Create a GrDirectContext with our GrVkBackendContext
    sk_sp<GrDirectContext> context = GrDirectContexts::MakeVulkan(backendContext);
    if (!context) {
        fVkDestroyDevice(backendContext.fDevice, nullptr);
        if (debugCallback != VK_NULL_HANDLE) {
            fVkDestroyDebugReportCallbackEXT(backendContext.fInstance, debugCallback, nullptr);
        }
        fVkDestroyInstance(backendContext.fInstance, nullptr);
        return 1;
    }

    SkImageInfo imageInfo = SkImageInfo::Make(16, 16, kRGBA_8888_SkColorType, kPremul_SkAlphaType);

    // Create an SkSurface backed by a Vulkan VkImage. Often clients will be getting VkImages from
    // swapchains. In those cases they should use SkSurfaces::WrapBackendTexture or
    // SkSurfaces::WrapBackendRenderTarget to wrap those premade VkImages in Skia. See the
    // HelloWorld example app to see how this is done.
    sk_sp<SkSurface> surface =
            SkSurfaces::RenderTarget(context.get(), skgpu::Budgeted::kYes, imageInfo);
    if (!surface) {
        context.reset();
        fVkDestroyDevice(backendContext.fDevice, nullptr);
        if (debugCallback != VK_NULL_HANDLE) {
            fVkDestroyDebugReportCallbackEXT(backendContext.fInstance, debugCallback, nullptr);
        }        fVkDestroyInstance(backendContext.fInstance, nullptr);
        return 1;
    }

    surface->getCanvas()->clear(SK_ColorRED);

    // After drawing to our surface, we must first flush the recorded work (i.e. convert all our
    // recorded SkCanvas calls into a VkCommandBuffer). Then we call submit to submit our
    // VkCommandBuffers to the gpu queue.
    context->flush(surface.get());
    context->submit();

    surface.reset();
    context.reset();

    // Skia doesn't own the VkDevice or VkInstance so the client must manage their lifetime. The
    // client must not delete these objects until cleaning up all Skia objects that may have used
    // them first.
    fVkDestroyDevice(backendContext.fDevice, nullptr);
    if (debugCallback != VK_NULL_HANDLE) {
        fVkDestroyDebugReportCallbackEXT(backendContext.fInstance, debugCallback, nullptr);
    }    fVkDestroyInstance(backendContext.fInstance, nullptr);
    return 0;
}
*/