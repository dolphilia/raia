//
// Created by dolphilia on 2024/01/08.
//

#ifndef RAIA_SKIA_SK_DOCUMENT_H
#define RAIA_SKIA_SK_DOCUMENT_H

#ifdef __cplusplus
extern "C" {
#endif

void SkDocument_delete(void *document); // (SkDocument *document)
void * SkDocument_beginPage(void * document, float width, float height, const void *content); // (SkDocument *document, SkScalar width, SkScalar height, const SkRect *content) -> SkCanvas *
void SkDocument_endPage(void *document); // (SkDocument *document)
void SkDocument_close(void *document); // (SkDocument *document)
void SkDocument_abort(void *document); // (SkDocument *document)
bool SkDocument_unique(void *document); // (SkDocument *document) -> bool
void SkDocument_ref(void *document); // (SkDocument *document)
void SkDocument_unref(void *document); // (SkDocument *document)

#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_SK_DOCUMENT_H
