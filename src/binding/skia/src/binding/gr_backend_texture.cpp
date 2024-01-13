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
GrBackendTexture_new_2(int width, int height, skgpu::Mipmapped midmapped, const GrMockTextureInfo *mockInfo,
                       std::string_view label) {
    return new GrBackendTexture(width, height, midmapped, *mockInfo, label);
}

GrBackendTexture *GrBackendTexture_new_3(const GrBackendTexture *that) {
    return new GrBackendTexture(*that);
}

void GrBackendTexture_delete(GrBackendTexture *backend_texture) {
    delete backend_texture;
}

SkISize GrBackendTexture_dimensions(GrBackendTexture *backend_texture) {
    return backend_texture->dimensions();
}

int GrBackendTexture_width(GrBackendTexture *backend_texture) {
    return backend_texture->width();
}

int GrBackendTexture_height(GrBackendTexture *backend_texture) {
    return backend_texture->height();
}

void GrBackendTexture_getLabel(const char *string_view_key_out, GrBackendTexture *backend_texture) {
    static_string_view_set(string_view_key_out, backend_texture->getLabel());
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

void GrBackendTexture_getBackendFormat(const char *gr_backend_format_key_out, GrBackendTexture *backend_texture) {
    static_gr_backend_format_set(gr_backend_format_key_out, backend_texture->getBackendFormat());
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