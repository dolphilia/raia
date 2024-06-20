//
// Created by dolphilia on 24/06/20.
//

#ifndef STB_RAIA_STB_H
#define STB_RAIA_STB_H

#include "export_api.h"

#define STB_IMAGE_IMPLEMENTATION
#include "../stb/stb_image.h"

////////////////////////////////////
//
// 8-bits-per-channel interface
//

RAIA_API stbi_uc *raia_stbi_load_from_memory   (stbi_uc           const *buffer, int len   , int *x, int *y, int *channels_in_file, int desired_channels);
RAIA_API stbi_uc *raia_stbi_load_from_callbacks(stbi_io_callbacks const *clbk  , void *user, int *x, int *y, int *channels_in_file, int desired_channels);

#ifndef STBI_NO_STDIO
RAIA_API stbi_uc *raia_stbi_load            (char const *filename, int *x, int *y, int *channels_in_file, int desired_channels);
RAIA_API stbi_uc *raia_stbi_load_from_file  (FILE *f, int *x, int *y, int *channels_in_file, int desired_channels);
// for stbi_load_from_file, file pointer is left pointing immediately after image
#endif

#ifndef STBI_NO_GIF
RAIA_API stbi_uc *raia_stbi_load_gif_from_memory(stbi_uc const *buffer, int len, int **delays, int *x, int *y, int *z, int *comp, int req_comp);
#endif

#ifdef STBI_WINDOWS_UTF8
RAIA_API int raia_stbi_convert_wchar_to_utf8(char *buffer, size_t bufferlen, const wchar_t* input);
#endif

////////////////////////////////////
//
// 16-bits-per-channel interface
//

RAIA_API stbi_us *raia_stbi_load_16_from_memory   (stbi_uc const *buffer, int len, int *x, int *y, int *channels_in_file, int desired_channels);
RAIA_API stbi_us *raia_stbi_load_16_from_callbacks(stbi_io_callbacks const *clbk, void *user, int *x, int *y, int *channels_in_file, int desired_channels);

#ifndef STBI_NO_STDIO
RAIA_API stbi_us *raia_stbi_load_16          (char const *filename, int *x, int *y, int *channels_in_file, int desired_channels);
RAIA_API stbi_us *raia_stbi_load_from_file_16(FILE *f, int *x, int *y, int *channels_in_file, int desired_channels);
#endif

////////////////////////////////////
//
// float-per-channel interface
//
#ifndef STBI_NO_LINEAR
RAIA_API float *raia_stbi_loadf_from_memory     (stbi_uc const *buffer, int len, int *x, int *y, int *channels_in_file, int desired_channels);
RAIA_API float *raia_stbi_loadf_from_callbacks  (stbi_io_callbacks const *clbk, void *user, int *x, int *y,  int *channels_in_file, int desired_channels);

#ifndef STBI_NO_STDIO
RAIA_API float *raia_stbi_loadf            (char const *filename, int *x, int *y, int *channels_in_file, int desired_channels);
RAIA_API float *raia_stbi_loadf_from_file  (FILE *f, int *x, int *y, int *channels_in_file, int desired_channels);
#endif
#endif

#ifndef STBI_NO_HDR
RAIA_API void   raia_stbi_hdr_to_ldr_gamma(float gamma);
RAIA_API void   raia_stbi_hdr_to_ldr_scale(float scale);
#endif // STBI_NO_HDR

#ifndef STBI_NO_LINEAR
RAIA_API void   raia_stbi_ldr_to_hdr_gamma(float gamma);
RAIA_API void   raia_stbi_ldr_to_hdr_scale(float scale);
#endif // STBI_NO_LINEAR

// stbi_is_hdr is always defined, but always returns false if STBI_NO_HDR
RAIA_API int    raia_stbi_is_hdr_from_callbacks(stbi_io_callbacks const *clbk, void *user);
RAIA_API int    raia_stbi_is_hdr_from_memory(stbi_uc const *buffer, int len);
#ifndef STBI_NO_STDIO
RAIA_API int      raia_stbi_is_hdr          (char const *filename);
RAIA_API int      raia_stbi_is_hdr_from_file(FILE *f);
#endif // STBI_NO_STDIO


// get a VERY brief reason for failure
// on most compilers (and ALL modern mainstream compilers) this is threadsafe
RAIA_API const char *raia_stbi_failure_reason  (void);

// free the loaded image -- this is just free()
RAIA_API void     raia_stbi_image_free      (void *retval_from_stbi_load);

// get image dimensions & components without fully decoding
RAIA_API int      raia_stbi_info_from_memory(stbi_uc const *buffer, int len, int *x, int *y, int *comp);
RAIA_API int      raia_stbi_info_from_callbacks(stbi_io_callbacks const *clbk, void *user, int *x, int *y, int *comp);
RAIA_API int      raia_stbi_is_16_bit_from_memory(stbi_uc const *buffer, int len);
RAIA_API int      raia_stbi_is_16_bit_from_callbacks(stbi_io_callbacks const *clbk, void *user);

#ifndef STBI_NO_STDIO
RAIA_API int      raia_stbi_info               (char const *filename,     int *x, int *y, int *comp);
RAIA_API int      raia_stbi_info_from_file     (FILE *f,                  int *x, int *y, int *comp);
RAIA_API int      raia_stbi_is_16_bit          (char const *filename);
RAIA_API int      raia_stbi_is_16_bit_from_file(FILE *f);
#endif



// for image formats that explicitly notate that they have premultiplied alpha,
// we just return the colors as stored in the file. set this flag to force
// unpremultiplication. results are undefined if the unpremultiply overflow.
RAIA_API void raia_stbi_set_unpremultiply_on_load(int flag_true_if_should_unpremultiply);

// indicate whether we should process iphone images back to canonical format,
// or just pass them through "as-is"
RAIA_API void raia_stbi_convert_iphone_png_to_rgb(int flag_true_if_should_convert);

// flip the image vertically, so the first pixel in the output array is the bottom left
RAIA_API void raia_stbi_set_flip_vertically_on_load(int flag_true_if_should_flip);

// as above, but only applies to images loaded on the thread that calls the function
// this function is only available if your compiler supports thread-local variables;
// calling it will fail to link if your compiler doesn't
RAIA_API void raia_stbi_set_unpremultiply_on_load_thread(int flag_true_if_should_unpremultiply);
RAIA_API void raia_stbi_convert_iphone_png_to_rgb_thread(int flag_true_if_should_convert);
RAIA_API void raia_stbi_set_flip_vertically_on_load_thread(int flag_true_if_should_flip);

// ZLIB client - used by PNG, available for other purposes

RAIA_API char *raia_stbi_zlib_decode_malloc_guesssize(const char *buffer, int len, int initial_size, int *outlen);
RAIA_API char *raia_stbi_zlib_decode_malloc_guesssize_headerflag(const char *buffer, int len, int initial_size, int *outlen, int parse_header);
RAIA_API char *raia_stbi_zlib_decode_malloc(const char *buffer, int len, int *outlen);
RAIA_API int   raia_stbi_zlib_decode_buffer(char *obuffer, int olen, const char *ibuffer, int ilen);

RAIA_API char *raia_stbi_zlib_decode_noheader_malloc(const char *buffer, int len, int *outlen);
RAIA_API int   raia_stbi_zlib_decode_noheader_buffer(char *obuffer, int olen, const char *ibuffer, int ilen);

#endif //STB_RAIA_STB_H
