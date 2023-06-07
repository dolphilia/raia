#ifndef RAIA_MRUBY_RAIA_MRUBY_H
#define RAIA_MRUBY_RAIA_MRUBY_H

#include "platform.h"

#ifdef __WINDOWS__
#define RAIA_EXPORT __declspec(dllexport)
#else
#define RAIA_EXPORT
#endif

RAIA_EXPORT int run(int argc, char *argv[]);

#endif //RAIA_MRUBY_RAIA_MRUBY_H
