// main.mm

// C++ ヘッダファイル
#include <iostream>
#include <vector>
#include <fstream>
#include <cstddef>

// Filament ヘッダファイル
#include <filament/Engine.h>
#include <filament/Renderer.h>
#include <filament/SwapChain.h>
#include <filament/View.h>
#include <filament/Scene.h>
#include <filament/Camera.h>
#include <filament/Material.h>
#include <filament/MaterialInstance.h>
#include <filament/RenderableManager.h>
#include <filament/VertexBuffer.h>
#include <filament/IndexBuffer.h>
#include <filament/Viewport.h>
#include <utils/EntityManager.h>
#include <math/vec3.h>
#include <utils/Log.h>

// OpenGL ES ヘッダファイル（ANGLE）
#include <EGL/egl.h>
#include <EGL/eglext.h>
#include <GLES3/gl3.h>

// Objective-C ヘッダファイル
#import <Cocoa/Cocoa.h>

using namespace filament;
using namespace utils;
using namespace math;

// ネイティブウィンドウのラッパークラス
@interface MyWindow : NSWindow
@end

@implementation MyWindow
- (BOOL)canBecomeKeyWindow {
    return YES;
}
@end

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // アプリケーションの初期化
        [NSApplication sharedApplication];
        [NSApp setActivationPolicy:NSApplicationActivationPolicyRegular];

        // ウィンドウの作成
        NSRect frame = NSMakeRect(0, 0, 800, 600);
        MyWindow* window = [[MyWindow alloc] initWithContentRect:frame
                                                       styleMask:(NSWindowStyleMaskTitled |
                                                                  NSWindowStyleMaskClosable |
                                                                  NSWindowStyleMaskResizable)
                                                         backing:NSBackingStoreBuffered
                                                           defer:NO];
        [window setTitle:@"Filament with ANGLE and EGL"];
        [window makeKeyAndOrderFront:nil];
        [NSApp activateIgnoringOtherApps:YES];

        // ウィンドウのレイヤーを取得
        NSView* contentView = [window contentView];
        [contentView setWantsLayer:YES];
        CALayer* layer = [contentView layer];

        // EGLDisplay の取得
        EGLDisplay eglDisplay = eglGetDisplay(EGL_DEFAULT_DISPLAY);
        if (eglDisplay == EGL_NO_DISPLAY) {
            std::cerr << "Failed to get EGL display." << std::endl;
            return -1;
        }

        // EGL の初期化
        if (!eglInitialize(eglDisplay, nullptr, nullptr)) {
            std::cerr << "Failed to initialize EGL." << std::endl;
            return -1;
        }

        // EGLConfig の選択
        EGLint configAttribs[] = {
            EGL_SURFACE_TYPE, EGL_WINDOW_BIT,
            EGL_RENDERABLE_TYPE, EGL_OPENGL_ES3_BIT,
            EGL_RED_SIZE, 8,
            EGL_GREEN_SIZE, 8,
            EGL_BLUE_SIZE, 8,
            EGL_ALPHA_SIZE, 8,
            EGL_DEPTH_SIZE, 24,
            EGL_STENCIL_SIZE, 8,
            EGL_NONE
        };

        EGLConfig eglConfig;
        EGLint numConfigs;
        if (!eglChooseConfig(eglDisplay, configAttribs, &eglConfig, 1, &numConfigs)) {
            std::cerr << "Failed to choose EGL config." << std::endl;
            return -1;
        }

        // EGLSurface の作成
        EGLNativeWindowType eglWindow = (EGLNativeWindowType)contentView;
        EGLSurface eglSurface = eglCreateWindowSurface(eglDisplay, eglConfig, eglWindow, nullptr);
        if (eglSurface == EGL_NO_SURFACE) {
            std::cerr << "Failed to create EGL surface." << std::endl;
            return -1;
        }

        // EGLContext の作成
        EGLint contextAttribs[] = {
            EGL_CONTEXT_CLIENT_VERSION, 3,
            EGL_NONE
        };

        EGLContext eglContext = eglCreateContext(eglDisplay, eglConfig, EGL_NO_CONTEXT, contextAttribs);
        if (eglContext == EGL_NO_CONTEXT) {
            std::cerr << "Failed to create EGL context." << std::endl;
            return -1;
        }

        // コンテキストのバインド
        if (!eglMakeCurrent(eglDisplay, eglSurface, eglSurface, eglContext)) {
            std::cerr << "Failed to make EGL context current." << std::endl;
            return -1;
        }

        // Filament エンジンの初期化
        Engine* engine = Engine::create(Engine::Backend::OPENGL);

        // SwapChain の作成
        SwapChain* swapChain = engine->createSwapChain((void*)eglSurface);

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

        camera->setProjection(45.0f, 800.0f / 600.0f, 0.1f, 100.0f);
        camera->lookAt({ 0, 0, 5 }, { 0, 0, 0 }, { 0, 1, 0 });

        // マテリアルの読み込み
        Material* material = nullptr;
        {
            // マテリアルパッケージの読み込み
            std::ifstream matFile("default_material.filamat", std::ios::binary);
            if (!matFile) {
                std::cerr << "Failed to load material file." << std::endl;
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
                std::cerr << "Failed to build material." << std::endl;
                return -1;
            }
        }

        // 頂点データの定義
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

        // VertexBuffer の作成
        VertexBuffer* vertexBuffer = VertexBuffer::Builder()
            .vertexCount((uint32_t)vertices.size())
            .bufferCount(1)
            .attribute(VertexAttribute::POSITION, 0, VertexBuffer::AttributeType::FLOAT3, 0, sizeof(Vertex))
            .build(*engine);

        vertexBuffer->setBufferAt(*engine, 0,
            VertexBuffer::BufferDescriptor(vertices.data(), vertices.size() * sizeof(Vertex), nullptr));

        // IndexBuffer の作成
        IndexBuffer* indexBuffer = IndexBuffer::Builder()
            .indexCount((uint32_t)indices.size())
            .bufferType(IndexBuffer::IndexType::USHORT)
            .build(*engine);

        indexBuffer->setBuffer(*engine,
            IndexBuffer::BufferDescriptor(indices.data(), indices.size() * sizeof(uint16_t), nullptr));

        // Renderable の作成
        Entity renderable = em.create();
        RenderableManager::Builder(1)
            .boundingBox({{ -1, -1, -1 }, { 1, 1, 1 }})
            .geometry(0, RenderableManager::PrimitiveType::TRIANGLES,
                      vertexBuffer, indexBuffer, 0, (uint32_t)indices.size())
            .material(0, material->createInstance())
            .build(*engine, renderable);

        scene->addEntity(renderable);

        // Filament のログレベルをデバッグに設定
        //utils::slog.setLevel(utils::slog.level.DEBUG);

        // イベントループ
        BOOL running = YES;
        while (running) {
            // イベントの処理
            NSEvent* event;
            while ((event = [NSApp nextEventMatchingMask:NSEventMaskAny
                                               untilDate:[NSDate distantPast]
                                                  inMode:NSDefaultRunLoopMode
                                                 dequeue:YES])) {
                [NSApp sendEvent:event];
            }

            // ビューポートの更新
            CGRect contentRect = [contentView bounds];
            uint32_t display_w = contentRect.size.width;
            uint32_t display_h = contentRect.size.height;
            view->setViewport({ 0, 0, display_w, display_h });

            // フレームの描画
            if (renderer->beginFrame(swapChain)) {
                renderer->render(view);
                renderer->endFrame();
            }

            // バッファのスワップ
            eglSwapBuffers(eglDisplay, eglSurface);

            // アプリケーションの終了判定
            running = ![[NSApp windows] containsObject:window] || [NSApp isRunning];
        }

        // クリーンアップ
        engine->destroy(renderable);
        engine->destroy(vertexBuffer);
        engine->destroy(indexBuffer);
        engine->destroyCameraComponent(cameraEntity);
        engine->destroy(material);
        engine->destroy(view);
        engine->destroy(scene);
        engine->destroy(renderer);
        engine->destroy(swapChain);
        Engine::destroy(&engine);

        eglDestroyContext(eglDisplay, eglContext);
        eglDestroySurface(eglDisplay, eglSurface);
        eglTerminate(eglDisplay);
    }

    return 0;
}
