//
// Created by dolphilia on 2024/01/10.
//

#include "sk_pixmap.h"

extern "C" {

SkPixmap *SkPixmap_new() {
    return new SkPixmap();
}

SkPixmap *SkPixmap_new_2(const SkImageInfo *info, const void *addr, size_t rowBytes) {
    return new SkPixmap(*info, addr, rowBytes);
}

void SkPixmap_delete(SkPixmap *pixmap) {
    delete pixmap;
}

void SkPixmap_reset(SkPixmap *pixmap) {
    return pixmap->reset();
}

void SkPixmap_reset_2(SkPixmap *pixmap, const SkImageInfo *info, const void *addr, size_t rowBytes) {
    return pixmap->reset(*info, addr, rowBytes);
}

bool SkPixmap_reset_3(SkPixmap *pixmap, const SkMask *mask) {
    return pixmap->reset(*mask);
}

void SkPixmap_setColorSpace(SkPixmap *pixmap, sk_color_space_t color_space) {
    return pixmap->setColorSpace(static_sk_color_space_move(color_space));
}

bool SkPixmap_extractSubset(SkPixmap *pixmap, SkPixmap *subset, const SkIRect *area) {
    return pixmap->extractSubset(subset, *area);
}

const SkImageInfo * SkPixmap_info(SkPixmap *pixmap) {
    return &pixmap->info();
}

size_t SkPixmap_rowBytes(SkPixmap *pixmap) {
    return pixmap->rowBytes();
}

const void * SkPixmap_addr(SkPixmap *pixmap) {
    return pixmap->addr();
}

int SkPixmap_width(SkPixmap *pixmap) {
    return pixmap->width();
}

int SkPixmap_height(SkPixmap *pixmap) {
    return pixmap->height();
}

sk_i_size_t SkPixmap_dimensions(SkPixmap *pixmap) {
    return static_sk_i_size_make(pixmap->dimensions());
}

SkColorType SkPixmap_colorType(SkPixmap *pixmap) {
    return pixmap->colorType();
}

SkAlphaType SkPixmap_alphaType(SkPixmap *pixmap) {
    return pixmap->alphaType();
}

SkColorSpace * SkPixmap_colorSpace(SkPixmap *pixmap) {
    return pixmap->colorSpace();
}

sk_color_space_t SkPixmap_refColorSpace(SkPixmap *pixmap) {
    return static_sk_color_space_make(pixmap->refColorSpace());
}

bool SkPixmap_isOpaque(SkPixmap *pixmap) {
    return pixmap->isOpaque();
}

sk_i_rect_t SkPixmap_bounds(SkPixmap *pixmap) {
    return static_sk_i_rect_make(pixmap->bounds());
}

int SkPixmap_rowBytesAsPixels(SkPixmap *pixmap) {
    return pixmap->rowBytesAsPixels();
}

int SkPixmap_shiftPerPixel(SkPixmap *pixmap) {
    return pixmap->shiftPerPixel();
}

size_t SkPixmap_computeByteSize(SkPixmap *pixmap) {
    return pixmap->computeByteSize();
}

bool SkPixmap_computeIsOpaque(SkPixmap *pixmap) {
    return pixmap->computeIsOpaque();
}

SkColor SkPixmap_getColor(SkPixmap *pixmap, int x, int y) {
    return pixmap->getColor(x, y);
}

sk_color_4f_t SkPixmap_getColor4f(SkPixmap *pixmap, int x, int y) {
    return static_sk_color_4f_make(pixmap->getColor4f(x, y));
}

float SkPixmap_getAlphaf(SkPixmap *pixmap, int x, int y) {
    return pixmap->getAlphaf(x, y);
}

const void * SkPixmap_addr_2(SkPixmap *pixmap, int x, int y) {
    return pixmap->addr(x, y);
}

const uint8_t * SkPixmap_addr8(SkPixmap *pixmap) {
    return pixmap->addr8();
}

const uint16_t * SkPixmap_addr16(SkPixmap *pixmap) {
    return pixmap->addr16();
}

const uint32_t * SkPixmap_addr32(SkPixmap *pixmap) {
    return pixmap->addr32();
}

const uint64_t * SkPixmap_addr64(SkPixmap *pixmap) {
    return pixmap->addr64();
}

const uint16_t * SkPixmap_addrF16(SkPixmap *pixmap) {
    return pixmap->addrF16();
}

const uint8_t * SkPixmap_addr8_2(SkPixmap *pixmap, int x, int y) {
    return pixmap->addr8(x, y);
}

const uint16_t * SkPixmap_addr16_2(SkPixmap *pixmap, int x, int y) {
    return pixmap->addr16(x, y);
}

const uint32_t * SkPixmap_addr32_2(SkPixmap *pixmap, int x, int y) {
    return pixmap->addr32(x, y);
}

const uint64_t * SkPixmap_addr64_2(SkPixmap *pixmap, int x, int y) {
    return pixmap->addr64(x, y);
}

const uint16_t * SkPixmap_addrF16_2(SkPixmap *pixmap, int x, int y) {
    return pixmap->addrF16(x, y);
}

void * SkPixmap_writable_addr(SkPixmap *pixmap) {
    return pixmap->writable_addr();
}

void * SkPixmap_writable_addr_2(SkPixmap *pixmap, int x, int y) {
    return pixmap->writable_addr(x, y);
}

uint8_t * SkPixmap_writable_addr8(SkPixmap *pixmap, int x, int y) {
    return pixmap->writable_addr8(x, y);
}

uint16_t * SkPixmap_writable_addr16(SkPixmap *pixmap, int x, int y) {
    return pixmap->writable_addr16(x, y);
}

uint32_t * SkPixmap_writable_addr32(SkPixmap *pixmap, int x, int y) {
    return pixmap->writable_addr32(x, y);
}

uint64_t * SkPixmap_writable_addr64(SkPixmap *pixmap, int x, int y) {
    return pixmap->writable_addr64(x, y);
}

uint16_t * SkPixmap_writable_addrF16(SkPixmap *pixmap, int x, int y) {
    return pixmap->writable_addrF16(x, y);
}

bool SkPixmap_readPixels(SkPixmap *pixmap, const SkImageInfo *dstInfo, void *dstPixels, size_t dstRowBytes) {
    return pixmap->readPixels(*dstInfo, dstPixels, dstRowBytes);
}

bool SkPixmap_readPixels_2(SkPixmap *pixmap, const SkImageInfo *dstInfo, void *dstPixels, size_t dstRowBytes, int srcX, int srcY) {
    return pixmap->readPixels(*dstInfo, dstPixels, dstRowBytes, srcX, srcY);
}

bool SkPixmap_readPixels_3(SkPixmap *pixmap, const SkPixmap *dst, int srcX, int srcY) {
    return pixmap->readPixels(*dst, srcX, srcY);
}

bool SkPixmap_readPixels_4(SkPixmap *pixmap, const SkPixmap *dst) {
    return pixmap->readPixels(*dst);
}

bool SkPixmap_scalePixels(SkPixmap *pixmap, const SkPixmap *dst, const SkSamplingOptions *options) {
    return pixmap->scalePixels(*dst, *options);
}

bool SkPixmap_erase(SkPixmap *pixmap, SkColor color, const SkIRect *subset) {
    return pixmap->erase(color, *subset);
}

bool SkPixmap_erase_2(SkPixmap *pixmap, SkColor color) {
    return pixmap->erase(color);
}

bool SkPixmap_erase_3(SkPixmap *pixmap, const SkColor4f *color, const SkIRect *subset) {
    return pixmap->erase(*color, subset);
}

}