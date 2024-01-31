//
// Created by dolphilia on 2024/01/08.
//

#include "sk_document.h"

extern "C" {

void SkDocument_delete(SkDocument *document) {
    delete &document;
}

SkCanvas * SkDocument_beginPage(SkDocument * document, SkScalar width, SkScalar height, const SkRect *content) {
    return document->beginPage(width, height, content);
}

void SkDocument_endPage(SkDocument *document) {
    document->endPage();
}

void SkDocument_close(SkDocument *document) {
    document->close();
}

void SkDocument_abort(SkDocument *document) {
    document->abort();
}

bool SkDocument_unique(SkDocument *document) {
    return document->unique();
}

void SkDocument_ref(SkDocument *document) {
    document->ref();
}

void SkDocument_unref(SkDocument *document) {
    document->unref();
}

}