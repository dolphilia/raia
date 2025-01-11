//
// Created by dolphilia on 2024/01/13.
//

#ifndef RAIA_SKIA_SK_PDF_H
#define RAIA_SKIA_SK_PDF_H

#include "include/docs/SkPDFDocument.h"
#include "../static/static_sk_document.h"

extern "C" {
RAIA_API void SkPDF_SetNodeId(SkCanvas *dst, int nodeID);
RAIA_API sk_document_t SkPDF_MakeDocument(SkWStream *stream, const SkPDF::Metadata *metadata);
RAIA_API sk_document_t SkPDF_MakeDocument_2(SkWStream *stream);
}

#endif //RAIA_SKIA_SK_PDF_H
