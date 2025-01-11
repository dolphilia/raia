//
// Created by dolphilia on 2024/01/08.
//

#ifndef RAIA_SKIA_SK_DOCUMENT_H
#define RAIA_SKIA_SK_DOCUMENT_H

#include "include/core/SkDocument.h"
#include "export_api.h"

extern "C" {
RAIA_API void SkDocument_delete(SkDocument *document);
RAIA_API SkCanvas * SkDocument_beginPage(SkDocument * document, SkScalar width, SkScalar height, const SkRect *content);
RAIA_API void SkDocument_endPage(SkDocument *document);
RAIA_API void SkDocument_close(SkDocument *document);
RAIA_API void SkDocument_abort(SkDocument *document);
RAIA_API bool SkDocument_unique(SkDocument *document);
RAIA_API void SkDocument_ref(SkDocument *document);
RAIA_API void SkDocument_unref(SkDocument *document);
}

#endif //RAIA_SKIA_SK_DOCUMENT_H
