//
// Created by dolphilia on 2024/01/13.
//

#ifndef RAIA_SKIA_STATIC_GR_DIRECT_CONTEXT_DIRECT_CONTEXT_ID_H
#define RAIA_SKIA_STATIC_GR_DIRECT_CONTEXT_DIRECT_CONTEXT_ID_H

#include <string>
#include <map>
#include "include/gpu/GrDirectContext.h"

int static_gr_direct_context_direct_context_id_make(GrDirectContext::DirectContextID value);
void static_gr_direct_context_direct_context_id_delete(int key);
GrDirectContext::DirectContextID static_gr_direct_context_direct_context_id_get(int key);
void static_gr_direct_context_direct_context_id_set(int key, GrDirectContext::DirectContextID value);

#endif //RAIA_SKIA_STATIC_GR_DIRECT_CONTEXT_DIRECT_CONTEXT_ID_H
