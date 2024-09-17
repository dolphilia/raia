// main.cpp

#include "GLFW/glfw3.h"          // GLFWヘッダ
#define GLFW_EXPOSE_NATIVE_COCOA
#include <GLFW/glfw3native.h>
#include "GLES3/gl32.h"          // ANGLEのOpenGL ES 3.2ヘッダ
#include <filament/Engine.h>     // Filamentヘッダ
#include <filament/Renderer.h>
#include <filament/SwapChain.h>
#include <filament/View.h>
#include <filament/Scene.h>
#include <filament/Camera.h>
#include <filament/LightManager.h>
#include <filament/Material.h>
#include <filament/MaterialInstance.h>
#include <filament/RenderableManager.h>
#include <utils/EntityManager.h>
#include <filament/VertexBuffer.h>
#include <filament/IndexBuffer.h>
#include <math/mathfwd.h>
#include <math/vec3.h>
#include <filament/Viewport.h>   // Viewportクラスのヘッダファイルを追加
#include <iostream>
#include <vector>
#include <fstream>
#include <cstddef> // offsetofマクロを使用するために必要

using namespace filament;
using namespace utils;
using namespace math;

int main() {
    // GLFWの初期化
    if (!glfwInit()) {
        std::cerr << "GLFWの初期化に失敗しました。" << std::endl;
        return -1;
    }

    // GLFWウィンドウの設定（ANGLEのOpenGL ESコンテキストを使用）
    glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_ES_API);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // OpenGL ES 3.0以上
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    glfwWindowHint(GLFW_CONTEXT_CREATION_API, GLFW_EGL_CONTEXT_API);

    // ウィンドウの作成
    int width = 800;
    int height = 600;
    GLFWwindow* window = glfwCreateWindow(width, height, "Filament with GLFW and ANGLE", nullptr, nullptr);
    if (!window) {
        std::cerr << "GLFWウィンドウの作成に失敗しました。" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    // Filamentエンジンの初期化（OpenGL ESバックエンドを指定）
    Engine* engine = Engine::create(Engine::Backend::OPENGL);

    // SwapChainの作成（既存のコンテキストを使用）
    SwapChain* swapChain = engine->createSwapChain(nullptr);

    // レンダラーの作成
    Renderer* renderer = engine->createRenderer();

    // シーンとビューの作成
    Scene* scene = engine->createScene();
    View* view = engine->createView();
    view->setScene(scene);

    // カメラの設定
    EntityManager& em = EntityManager::get();
    Entity cameraEntity = em.create();
    Camera* camera = engine->createCamera(cameraEntity);
    view->setCamera(camera);

    camera->setProjection(45.0f, (float)width / height, 0.1f, 100.0f);
    camera->lookAt({ 0, 0, 2 }, { 0, 0, 0 }, { 0, 1, 0 });


    // ライトの追加（unlitマテリアルでは不要ですが、例として残します）
    Entity light = em.create();
    LightManager::Builder(LightManager::Type::DIRECTIONAL)
        .color({ 1.0f, 1.0f, 1.0f })
        .intensity(100000.0f)
        .direction({ 0.0f, -1.0f, -1.0f })
        .castShadows(true)
        .build(*engine, light);
    scene->addEntity(light);

    // マテリアルの読み込み
    Material* material = nullptr;
    {
        // マテリアルパッケージの読み込み
        std::ifstream matFile("default_material.filamat", std::ios::binary);
        if (!matFile) {
            std::cerr << "マテリアルファイルの読み込みに失敗しました。" << std::endl;
            return -1;
        }
        matFile.seekg(0, std::ios::end);
        size_t size = matFile.tellg();
        matFile.seekg(0, std::ios::beg);
        std::vector<uint8_t> buffer(size);
        matFile.read(reinterpret_cast<char*>(buffer.data()), size);

        // マテリアルのビルド
        material = Material::Builder()
            .package(buffer.data(), size)
            .build(*engine);
        if (!material) {
            std::cerr << "マテリアルのビルドに失敗しました。" << std::endl;
            return -1;
        }
    }

    // 頂点データの定義（基本的な図形）
    struct Vertex {
        float3 position;
    };

    // 三角形の頂点データ
    std::vector<Vertex> vertices = {
        {{ 0.0f,  1.0f, 0.0f}},
        {{-1.0f, -1.0f, 0.0f}},
        {{ 1.0f, -1.0f, 0.0f}},
    };

    // インデックスデータ
    std::vector<uint16_t> indices = {0, 1, 2};

    // VertexBufferの作成
    VertexBuffer* vertexBuffer = VertexBuffer::Builder()
        .vertexCount((uint32_t)vertices.size())
        .bufferCount(1)
        .attribute(VertexAttribute::POSITION, 0, VertexBuffer::AttributeType::FLOAT3, 0, sizeof(Vertex))
        .build(*engine);

    vertexBuffer->setBufferAt(*engine, 0,
        VertexBuffer::BufferDescriptor(vertices.data(), vertices.size() * sizeof(Vertex), nullptr));

    // IndexBufferの作成
    IndexBuffer* indexBuffer = IndexBuffer::Builder()
        .indexCount((uint32_t)indices.size())
        .bufferType(IndexBuffer::IndexType::USHORT)
        .build(*engine);

    indexBuffer->setBuffer(*engine,
        IndexBuffer::BufferDescriptor(indices.data(), indices.size() * sizeof(uint16_t), nullptr));

    // Renderableの作成
    Entity renderable = em.create();
    RenderableManager::Builder(1)
        .boundingBox({{ -1, -1, -1 }, { 1, 1, 1 }})
        .geometry(0, RenderableManager::PrimitiveType::TRIANGLES, vertexBuffer, indexBuffer, 0, (uint32_t)indices.size())
        .material(0, material->createInstance())
        .build(*engine, renderable);

    scene->addEntity(renderable);

    // メインループ
    while (!glfwWindowShouldClose(window)) {
        // GLenum error = glGetError();
        // if (error != GL_NO_ERROR) {
        //     std::cerr << "OpenGL Error: " << error << std::endl;
        // }

        glfwPollEvents();

        // ビューポートの更新
        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        view->setViewport({ 0, 0, (uint32_t)display_w, (uint32_t)display_h });

        // フレームの描画
        if (renderer->beginFrame(swapChain)) {
            renderer->render(view);
            renderer->endFrame();
        }

        glfwSwapBuffers(window);
    }

    // クリーンアップ
    engine->destroy(renderable);
    engine->destroy(vertexBuffer);
    engine->destroy(indexBuffer);
    engine->destroy(light);
    engine->destroyCameraComponent(cameraEntity);
    engine->destroy(material);
    engine->destroy(view);
    engine->destroy(scene);
    engine->destroy(renderer);
    engine->destroy(swapChain);
    Engine::destroy(&engine);

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}
