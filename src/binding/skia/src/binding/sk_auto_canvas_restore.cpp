//
// Created by dolphilia on 2024/01/05.
//

#include "sk_auto_canvas_restore.h"

extern "C" {

SkAutoCanvasRestore *SkAutoCanvasRestore_new(SkCanvas *canvas, bool doSave) {
    return new SkAutoCanvasRestore(canvas, doSave);
}

void SkAutoCanvasRestore_delete(SkAutoCanvasRestore *autoCanvasRestore) {
    delete autoCanvasRestore;
}

void SkAutoCanvasRestore_restore(SkAutoCanvasRestore *autoCanvasRestore) {
    autoCanvasRestore->restore();
}

}