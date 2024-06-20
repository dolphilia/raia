//
// Created by dolphilia on 24/06/20.
//

#ifndef RAIA_STB_RAIA_STB_IMAGE_WRITE_H
#define RAIA_STB_RAIA_STB_IMAGE_WRITE_H

#include "export_api.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "../stb/stb_image_write.h"

#ifndef STB_IMAGE_WRITE_STATIC  // C++ forbids static forward declarations
RAIA_API int raia_stbi_write_tga_with_rle;
RAIA_API int raia_stbi_write_png_compression_level;
RAIA_API int raia_stbi_write_force_png_filter;
#endif

#ifndef STBI_WRITE_NO_STDIO
RAIA_API int raia_stbi_write_png(char const *filename, int w, int h, int comp, const void  *data, int stride_in_bytes);
RAIA_API int raia_stbi_write_bmp(char const *filename, int w, int h, int comp, const void  *data);
RAIA_API int raia_stbi_write_tga(char const *filename, int w, int h, int comp, const void  *data);
RAIA_API int raia_stbi_write_hdr(char const *filename, int w, int h, int comp, const float *data);
RAIA_API int raia_stbi_write_jpg(char const *filename, int x, int y, int comp, const void  *data, int quality);

#ifdef STBIW_WINDOWS_UTF8
RAIA_API int raia_stbiw_convert_wchar_to_utf8(char *buffer, size_t bufferlen, const wchar_t* input);
#endif
#endif

typedef void raia_stbi_write_func(void *context, void *data, int size);

RAIA_API int raia_stbi_write_png_to_func(stbi_write_func *func, void *context, int w, int h, int comp, const void  *data, int stride_in_bytes);
RAIA_API int raia_stbi_write_bmp_to_func(stbi_write_func *func, void *context, int w, int h, int comp, const void  *data);
RAIA_API int raia_stbi_write_tga_to_func(stbi_write_func *func, void *context, int w, int h, int comp, const void  *data);
RAIA_API int raia_stbi_write_hdr_to_func(stbi_write_func *func, void *context, int w, int h, int comp, const float *data);
RAIA_API int raia_stbi_write_jpg_to_func(stbi_write_func *func, void *context, int x, int y, int comp, const void  *data, int quality);

RAIA_API void raia_stbi_flip_vertically_on_write(int flip_boolean);

#endif //RAIA_STB_RAIA_STB_IMAGE_WRITE_H
