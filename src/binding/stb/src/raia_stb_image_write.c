//
// Created by dolphilia on 24/06/20.
//

#include "raia_stb_image_write.h"

#ifndef STBI_WRITE_NO_STDIO

int raia_stbi_write_png(char const *filename, int w, int h, int comp, const void  *data, int stride_in_bytes) {
    return stbi_write_png(filename, w, h, comp, data, stride_in_bytes);
}

int raia_stbi_write_bmp(char const *filename, int w, int h, int comp, const void  *data) {
    return stbi_write_bmp(filename, w, h, comp, data);
}

int raia_stbi_write_tga(char const *filename, int w, int h, int comp, const void  *data) {
    return stbi_write_tga(filename, w, h, comp, data);
}

int raia_stbi_write_hdr(char const *filename, int w, int h, int comp, const float *data) {
    return stbi_write_hdr(filename, w, h, comp, data);
}

int raia_stbi_write_jpg(char const *filename, int x, int y, int comp, const void  *data, int quality) {
    return stbi_write_jpg(filename, x, y, comp, data, quality);
}

#ifdef STBIW_WINDOWS_UTF8

int raia_stbiw_convert_wchar_to_utf8(char *buffer, size_t bufferlen, const wchar_t* input) {
    return stbiw_convert_wchar_to_utf8(buffer, bufferlen, input);
}

#endif
#endif

int raia_stbi_write_png_to_func(stbi_write_func *func, void *context, int w, int h, int comp, const void  *data, int stride_in_bytes) {
    return stbi_write_png_to_func(func, context, w, h, comp, data, stride_in_bytes);
}

int raia_stbi_write_bmp_to_func(stbi_write_func *func, void *context, int w, int h, int comp, const void  *data) {
    return stbi_write_bmp_to_func(func, context, w, h, comp, data);
}

int raia_stbi_write_tga_to_func(stbi_write_func *func, void *context, int w, int h, int comp, const void  *data) {
    return stbi_write_tga_to_func(func, context, w, h, comp, data);
}

int raia_stbi_write_hdr_to_func(stbi_write_func *func, void *context, int w, int h, int comp, const float *data) {
    return stbi_write_hdr_to_func(func, context, w, h, comp, data);
}

int raia_stbi_write_jpg_to_func(stbi_write_func *func, void *context, int x, int y, int comp, const void  *data, int quality) {
    return stbi_write_jpg_to_func(func, context, x, y, comp, data, quality);
}

void raia_stbi_flip_vertically_on_write(int flip_boolean) {
    stbi_flip_vertically_on_write(flip_boolean);
}
