//
// Created by dolphilia on 2024/01/12.
//

#ifndef RAIA_SKIA_GR_BACKEND_FORMAT_H
#define RAIA_SKIA_GR_BACKEND_FORMAT_H

#include "include/gpu/GrBackendSurface.h"
#include "../static/static_gr_backend_format.h"
#include "../static/static_gr_color_format_desc.h"

extern "C" {
//GrBackendFormat & operator= (const GrBackendFormat &)
//bool operator==(const GrBackendFormat &that) const
//bool operator!=(const GrBackendFormat &that) const
GrBackendFormat *GrBackendFormat_new();
GrBackendFormat *GrBackendFormat_new_2(const GrBackendFormat *format);
void GrBackendFormat_delete(GrBackendFormat *backend_format);
GrBackendApi GrBackendFormat_backend(GrBackendFormat *backend_format);
GrTextureType GrBackendFormat_textureType(GrBackendFormat *backend_format);
uint32_t GrBackendFormat_channelMask(GrBackendFormat *backend_format);
gr_color_format_desc_t GrBackendFormat_desc(GrBackendFormat *backend_format);
GrColorType GrBackendFormat_asMockColorType(GrBackendFormat *backend_format);
SkTextureCompressionType GrBackendFormat_asMockCompressionType(GrBackendFormat *backend_format);
bool GrBackendFormat_isMockStencilFormat(GrBackendFormat *backend_format);
gr_backend_format_t GrBackendFormat_makeTexture2D(GrBackendFormat *backend_format);
bool GrBackendFormat_isValid(GrBackendFormat *backend_format);
// static
gr_backend_format_t GrBackendFormat_MakeMock(GrColorType colorType, SkTextureCompressionType compression, bool isStencilFormat);
}

#endif //RAIA_SKIA_GR_BACKEND_FORMAT_H
