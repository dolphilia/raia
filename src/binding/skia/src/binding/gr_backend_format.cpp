//
// Created by dolphilia on 2024/01/12.
//

#include "gr_backend_format.h"

extern "C" {

//GrBackendFormat & operator= (const GrBackendFormat &)
//bool operator==(const GrBackendFormat &that) const
//bool operator!=(const GrBackendFormat &that) const

GrBackendFormat *GrBackendFormat_new() {
    return new GrBackendFormat();
}

GrBackendFormat *GrBackendFormat_new_2(const GrBackendFormat *format) {
    return new GrBackendFormat(*format);
}

void GrBackendFormat_delete(GrBackendFormat *backend_format) {
    delete backend_format;
}

GrBackendApi GrBackendFormat_backend(GrBackendFormat *backend_format) {
    return backend_format->backend();
}

GrTextureType GrBackendFormat_textureType(GrBackendFormat *backend_format) {
    return backend_format->textureType();
}

uint32_t GrBackendFormat_channelMask(GrBackendFormat *backend_format) {
    return backend_format->channelMask();
}

void GrBackendFormat_desc(int gr_color_format_desc_key_out, GrBackendFormat *backend_format) {
    static_gr_color_format_desc_set(gr_color_format_desc_key_out, backend_format->desc());
}

GrColorType GrBackendFormat_asMockColorType(GrBackendFormat *backend_format) {
    return backend_format->asMockColorType();
}

SkTextureCompressionType GrBackendFormat_asMockCompressionType(GrBackendFormat *backend_format) {
    return backend_format->asMockCompressionType();
}

bool GrBackendFormat_isMockStencilFormat(GrBackendFormat *backend_format) {
    return backend_format->isMockStencilFormat();
}

void GrBackendFormat_makeTexture2D(int gr_backend_format_key_out, GrBackendFormat *backend_format) {
    static_gr_backend_format_set(gr_backend_format_key_out, backend_format->makeTexture2D());
}

bool GrBackendFormat_isValid(GrBackendFormat *backend_format) {
    return backend_format->isValid();
}

// static

void GrBackendFormat_MakeMock(int gr_backend_format_key_out, GrColorType colorType, SkTextureCompressionType compression, bool isStencilFormat) {
    static_gr_backend_format_set(gr_backend_format_key_out, GrBackendFormat::MakeMock(colorType, compression, isStencilFormat));
}

}