//
// Created by dolphilia on 2024/01/12.
//

#ifndef RAIA_SKIA_GR_BACKEND_TEXTURE_H
#define RAIA_SKIA_GR_BACKEND_TEXTURE_H

#include "include/gpu/GrBackendSurface.h"
#include "../static/static_gr_backend_format.h"
#include "../static/static_std_string_view.h"
#include "../static/static_sk_i_size.h"

extern "C" {
// GrBackendTexture & operator= (const GrBackendTexture &that)
GrBackendTexture *GrBackendTexture_new();
GrBackendTexture *GrBackendTexture_new_2(int width, int height, skgpu::Mipmapped midmapped, const GrMockTextureInfo *mockInfo, string_view_t label);
GrBackendTexture *GrBackendTexture_new_3(const GrBackendTexture *that);
void GrBackendTexture_delete(GrBackendTexture *backend_texture);
sk_i_size_t GrBackendTexture_dimensions(GrBackendTexture *backend_texture);
int GrBackendTexture_width(GrBackendTexture *backend_texture);
int GrBackendTexture_height(GrBackendTexture *backend_texture);
string_view_t GrBackendTexture_getLabel(GrBackendTexture *backend_texture);
skgpu::Mipmapped GrBackendTexture_mipmapped(GrBackendTexture *backend_texture);
bool GrBackendTexture_hasMipmaps(GrBackendTexture *backend_texture);
bool GrBackendTexture_hasMipMaps(GrBackendTexture *backend_texture);
GrBackendApi GrBackendTexture_backend(GrBackendTexture *backend_texture);
GrTextureType GrBackendTexture_textureType(GrBackendTexture *backend_texture);
gr_backend_format_t GrBackendTexture_getBackendFormat(GrBackendTexture *backend_texture);
bool GrBackendTexture_getMockTextureInfo(GrBackendTexture *backend_texture, GrMockTextureInfo *info);
void GrBackendTexture_setMutableState(GrBackendTexture *backend_texture, const skgpu::MutableTextureState *state);
bool GrBackendTexture_isProtected(GrBackendTexture *backend_texture);
bool GrBackendTexture_isValid(GrBackendTexture *backend_texture);
bool GrBackendTexture_isSameTexture(GrBackendTexture *backend_texture, const GrBackendTexture *texture);
}

#endif //RAIA_SKIA_GR_BACKEND_TEXTURE_H
