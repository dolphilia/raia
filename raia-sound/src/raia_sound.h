#ifndef RAIA_SOUND_RAIA_SOUND_H
#define RAIA_SOUND_RAIA_SOUND_H

#include <stdio.h>
#include "duktape/duktape.h"

#include "platforms.h"
#include <stdio.h>
#include <AL/al.h>
#include <AL/alc.h>

#ifdef __MACOS__
#include <unistd.h>
#endif
#ifdef __WINDOWS__
#include <windows.h>
#endif

#include "util/util_math.h"

duk_ret_t hello(duk_context *ctx);

#endif //RAIA_SOUND_RAIA_SOUND_H
