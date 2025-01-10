//
// Created by dolphilia on 2024/01/05.
//

#ifndef RAIA_SKIA_SK_AUTO_CANVAS_RESTORE_H
#define RAIA_SKIA_SK_AUTO_CANVAS_RESTORE_H

#include "include/core/SkCanvas.h"

extern "C" {
SkAutoCanvasRestore *SkAutoCanvasRestore_new(SkCanvas * canvas, bool doSave);
void SkAutoCanvasRestore_delete(SkAutoCanvasRestore *autoCanvasRestore);
void SkAutoCanvasRestore_restore(SkAutoCanvasRestore *autoCanvasRestore);
}

#endif //RAIA_SKIA_SK_AUTO_CANVAS_RESTORE_H
