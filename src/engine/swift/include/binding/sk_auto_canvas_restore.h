//
// Created by dolphilia on 2024/01/05.
//

#ifndef RAIA_SKIA_SK_AUTO_CANVAS_RESTORE_H
#define RAIA_SKIA_SK_AUTO_CANVAS_RESTORE_H

#ifdef __cplusplus
extern "C" {
#endif

void * SkAutoCanvasRestore_new(void * canvas, bool doSave); // (SkCanvas * canvas, bool doSave) -> SkAutoCanvasRestore *
void SkAutoCanvasRestore_delete(void * autoCanvasRestore); // (SkAutoCanvasRestore *autoCanvasRestore)

#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_SK_AUTO_CANVAS_RESTORE_H
