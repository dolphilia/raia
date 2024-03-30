//
// Created by dolphilia on 2024/01/12.
//

#include "gr_backend_texture.h"

extern "C" {

// GrBackendTexture & operator= (const GrBackendTexture &that)

GrBackendTexture *GrBackendTexture_new() {
    return new GrBackendTexture();
}

GrBackendTexture *
GrBackendTexture_new_2(int width, int height, skgpu::Mipmapped midmapped, const GrMockTextureInfo *mockInfo, string_view_t label) {
    return new GrBackendTexture(width, height, midmapped, *mockInfo, static_string_view_get(label));
}

GrBackendTexture *GrBackendTexture_new_3(const GrBackendTexture *that) {
    return new GrBackendTexture(*that);
}

void GrBackendTexture_delete(GrBackendTexture *backend_texture) {
    delete backend_texture;
}

sk_i_size_t GrBackendTexture_dimensions(GrBackendTexture *backend_texture) {
    return static_sk_i_size_make(backend_texture->dimensions());
}

int GrBackendTexture_width(GrBackendTexture *backend_texture) {
    return backend_texture->width();
}

int GrBackendTexture_height(GrBackendTexture *backend_texture) {
    return backend_texture->height();
}

string_view_t GrBackendTexture_getLabel(GrBackendTexture *backend_texture) {
    return static_string_view_make(backend_texture->getLabel());
}

skgpu::Mipmapped GrBackendTexture_mipmapped(GrBackendTexture *backend_texture) {
    return backend_texture->mipmapped();
}

bool GrBackendTexture_hasMipmaps(GrBackendTexture *backend_texture) {
    return backend_texture->hasMipmaps();
}

bool GrBackendTexture_hasMipMaps(GrBackendTexture *backend_texture) {
    return backend_texture->hasMipMaps();
}

GrBackendApi GrBackendTexture_backend(GrBackendTexture *backend_texture) {
    return backend_texture->backend();
}

GrTextureType GrBackendTexture_textureType(GrBackendTexture *backend_texture) {
    return backend_texture->textureType();
}

gr_backend_format_t GrBackendTexture_getBackendFormat(GrBackendTexture *backend_texture) {
    return static_gr_backend_format_make(backend_texture->getBackendFormat());
}

bool GrBackendTexture_getMockTextureInfo(GrBackendTexture *backend_texture, GrMockTextureInfo *info) {
    return backend_texture->getMockTextureInfo(info);
}

void GrBackendTexture_setMutableState(GrBackendTexture *backend_texture, const skgpu::MutableTextureState *state) {
    backend_texture->setMutableState(*state);
}

bool GrBackendTexture_isProtected(GrBackendTexture *backend_texture) {
    return backend_texture->isProtected();
}

bool GrBackendTexture_isValid(GrBackendTexture *backend_texture) {
    return backend_texture->isValid();
}

bool GrBackendTexture_isSameTexture(GrBackendTexture *backend_texture, const GrBackendTexture *texture) {
    return backend_texture->isSameTexture(*texture);
}

}