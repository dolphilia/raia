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

gr_color_format_desc_t GrBackendFormat_desc(GrBackendFormat *backend_format) {
    return static_gr_color_format_desc_make(backend_format->desc());
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

gr_backend_format_t GrBackendFormat_makeTexture2D(GrBackendFormat *backend_format) {
    return static_gr_backend_format_make(backend_format->makeTexture2D());
}

bool GrBackendFormat_isValid(GrBackendFormat *backend_format) {
    return backend_format->isValid();
}

// static

gr_backend_format_t GrBackendFormat_MakeMock(GrColorType colorType, SkTextureCompressionType compression, bool isStencilFormat) {
    return static_gr_backend_format_make(GrBackendFormat::MakeMock(colorType, compression, isStencilFormat));
}

}