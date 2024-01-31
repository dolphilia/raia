//
// Created by dolphilia on 2024/01/08.
//

#ifndef RAIA_SKIA_SK_DOCUMENT_H
#define RAIA_SKIA_SK_DOCUMENT_H

#include "include/core/SkDocument.h"

extern "C" {
void SkDocument_delete(SkDocument *document);
SkCanvas * SkDocument_beginPage(SkDocument * document, SkScalar width, SkScalar height, const SkRect *content);
void SkDocument_endPage(SkDocument *document);
void SkDocument_close(SkDocument *document);
void SkDocument_abort(SkDocument *document);
bool SkDocument_unique(SkDocument *document);
void SkDocument_ref(SkDocument *document);
void SkDocument_unref(SkDocument *document);
}

#endif //RAIA_SKIA_SK_DOCUMENT_H
