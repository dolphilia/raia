//
// Created by dolphilia on 2024/01/13.
//

#include "sk_pdf.h"

extern "C" {

void SkPDF_SetNodeId(SkCanvas *dst, int nodeID) {
    SkPDF::SetNodeId(dst, nodeID);
}

void SkPDF_MakeDocument(const char *sk_document_key_out, SkWStream *stream, const SkPDF::Metadata *metadata) {
    static_sk_document_set(sk_document_key_out, SkPDF::MakeDocument(stream, *metadata));
}

void SkPDF_MakeDocument_2(const char *sk_document_key_out, SkWStream *stream) {
    static_sk_document_set(sk_document_key_out, SkPDF::MakeDocument(stream));
}

}