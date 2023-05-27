#include "raia_sound.h"

#define YES_RETURN_VALUE 1
#define NO_RETURN_VALUE 0 // = undefined

/// OpenALの開始
void openal_start(void) {
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
    sleep(1);
#endif
    alSourceStop(source);
    alDeleteSources(1, &source);
    alDeleteBuffers(1, &buffer);
    alcMakeContextCurrent(NULL);
    alcDestroyContext(context);
    alcCloseDevice(device);
}

duk_ret_t hello(duk_context *ctx) {
    printf("Sound Start\n");
    openal_start();
    printf("Sound End\n");
    return NO_RETURN_VALUE;
}
