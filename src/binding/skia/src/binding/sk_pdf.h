//
// Created by dolphilia on 2024/01/13.
//

#ifndef RAIA_SKIA_SK_PDF_H
#define RAIA_SKIA_SK_PDF_H

#include "include/docs/SkPDFDocument.h"
#include "../static/static_sk_document.h"

extern "C" {
void SkPDF_SetNodeId(SkCanvas *dst, int nodeID);
void SkPDF_MakeDocument(int sk_document_key_out, SkWStream *stream, const SkPDF::Metadata *metadata);
void SkPDF_MakeDocument_2(int sk_document_key_out, SkWStream *stream);
}

#endif //RAIA_SKIA_SK_PDF_H
