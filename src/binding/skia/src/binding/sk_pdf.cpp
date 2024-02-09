//
// Created by dolphilia on 2024/01/13.
//

#include "sk_pdf.h"

extern "C" {

void SkPDF_SetNodeId(SkCanvas *dst, int nodeID) {
    SkPDF::SetNodeId(dst, nodeID);
}

sk_document_t SkPDF_MakeDocument(SkWStream *stream, const SkPDF::Metadata *metadata) {
    return static_sk_document_make(SkPDF::MakeDocument(stream, *metadata));
}

sk_document_t SkPDF_MakeDocument_2(SkWStream *stream) {
    return static_sk_document_make(SkPDF::MakeDocument(stream));
}

}