//
// Created by dolphilia on 2024/01/05.
//

#ifndef RAIA_SKIA_SK_AUTO_CANVAS_RESTORE_H
#define RAIA_SKIA_SK_AUTO_CANVAS_RESTORE_H

#include "include/core/SkCanvas.h"
#include "export_api.h"

extern "C" {
RAIA_API SkAutoCanvasRestore *SkAutoCanvasRestore_new(SkCanvas * canvas, bool doSave);
RAIA_API void SkAutoCanvasRestore_delete(SkAutoCanvasRestore *autoCanvasRestore);
RAIA_API void SkAutoCanvasRestore_restore(SkAutoCanvasRestore *autoCanvasRestore);
}

#endif //RAIA_SKIA_SK_AUTO_CANVAS_RESTORE_H
