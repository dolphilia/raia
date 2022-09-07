//
// macos:
// HomebrewでGLFWとOpenAL-Softを導入済みの場合:
// $ clang -o raia-engine.out src/raia-engine.c include/duktape/duktape.c -lm -lglfw -framework OpenGL -framework OpenAL -I /opt/homebrew/include -I include -L /opt/homebrew/opt/openal-soft/lib -L /opt/homebrew/opt/glfw/lib
//

#ifdef _WIN32
#define __WIN32__
#define __WINDOWS__
#endif

#ifdef _WIN64
#define __WIN64__
#define __WINDOWS__
#endif

#ifdef _WINDOWS
#define __WINGUI__
#endif

#ifdef _CONSOLE
#define __WINCUI__
#endif

#ifdef __APPLE__
#define __MACOS__
#endif

#ifdef __linux
#define __LINUX__
#endif

#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <GLFW/glfw3.h>
#include <AL/al.h>
#include <AL/alc.h>
#include "duktape/duktape.h"

#ifdef __MACOS__
#include <unistd.h>
#endif

#ifdef __WINDOWS__
#include <windows.h>
#endif

int rnd(int _min, int _max) {
    return _min + (int)(rand() * (_max - _min + 1.0) / (1.0 + RAND_MAX));
}

int main(int argc, char* argv[]) {
    // OpenALのテスト
    ALCdevice* device;
    ALCcontext* context;
    ALshort data[44100 * 3];
    ALuint buffer, source;
    device = alcOpenDevice(NULL);
    context = alcCreateContext(device, NULL);
    alcMakeContextCurrent(context);
    alGenBuffers(1, &buffer);
    for (int i = 0; i < 44100 * 3; i++)
        data[i] = rnd(-32767, 32767);
    alBufferData(buffer, AL_FORMAT_MONO16, data, sizeof(data), 44100);
    alGenSources(1, &source);
    alSourcei(source, AL_BUFFER, buffer);
    alSourcePlay(source);
#ifdef __WINDOWS__
    Sleep(3000);
#else
    sleep(3);
#endif
    alSourceStop(source);
    alDeleteSources(1, &source);
    alDeleteBuffers(1, &buffer);
    alcMakeContextCurrent(NULL);
    alcDestroyContext(context);
    alcCloseDevice(device);

    // Duktapeのテスト
    duk_context* ctx = duk_create_heap_default();
    duk_eval_string(ctx, "1+2");
    printf("1+2=%d\n", (int)duk_get_int(ctx, -1));
    duk_destroy_heap(ctx);

    // GLFWのテスト
    GLFWwindow* window;
    if (glfwInit() != GL_TRUE) {
        fprintf(stderr, "Failed to initialize GLFW.\n");
        return EXIT_FAILURE;
    }

    // この記述があるとmacosでウィンドウ生成に失敗する
    //glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    //glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
    //glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    //glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE);
    //glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    window = glfwCreateWindow(640, 480, "Window", NULL, NULL);

    if (!window) {
        fprintf(stderr, "Failed to create window.\n");
        glfwTerminate();
        return EXIT_FAILURE;
    }

    glfwMakeContextCurrent(window);

    while (!glfwWindowShouldClose(window)) {
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();

    return EXIT_SUCCESS;
}
