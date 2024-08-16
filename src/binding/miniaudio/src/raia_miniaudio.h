//
// Created by dolphilia on 24/08/09.
//

#ifndef RAIA_RAUDIO_RAIA_MINIAUDIO_H
#define RAIA_RAUDIO_RAIA_MINIAUDIO_H

#define MINIAUDIO_IMPLEMENTATION
#include "external/miniaudio.h"

// Version

void raia_ma_version(ma_uint32* pMajor, ma_uint32* pMinor, ma_uint32* pRevision);
const char* raia_ma_version_string(void);

#endif //RAIA_RAUDIO_RAIA_MINIAUDIO_H
