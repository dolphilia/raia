//
// Created by dolphilia on 24/06/20.
//

#include "raia_stb_image.h"

stbi_uc *raia_stbi_load_from_memory(stbi_uc const *buffer, int len, int *x, int *y, int *channels_in_file, int desired_channels) {
    return stbi_load_from_memory(buffer, len, x, y, channels_in_file, desired_channels);
}

stbi_uc *raia_stbi_load_from_callbacks(stbi_io_callbacks const *clbk, void *user, int *x, int *y, int *channels_in_file, int desired_channels) {
    return stbi_load_from_callbacks(clbk, user, x, y, channels_in_file, desired_channels);
}

#ifndef STBI_NO_STDIO

stbi_uc *raia_stbi_load(char const *filename, int *x, int *y, int *channels_in_file, int desired_channels) {
    return stbi_load(filename, x, y, channels_in_file, desired_channels);
}

stbi_uc *raia_stbi_load_from_file(FILE *f, int *x, int *y, int *channels_in_file, int desired_channels) {
    return stbi_load_from_file(f, x, y, channels_in_file, desired_channels);
}

#endif

#ifndef STBI_NO_GIF

stbi_uc *raia_stbi_load_gif_from_memory(stbi_uc const *buffer, int len, int **delays, int *x, int *y, int *z, int *comp, int req_comp) {
    return stbi_load_gif_from_memory(buffer, len, delays, x, y, z, comp, req_comp);
}

#endif

#ifdef STBI_WINDOWS_UTF8

int raia_stbi_convert_wchar_to_utf8(char *buffer, size_t bufferlen, const wchar_t* input) {
    return stbi_convert_wchar_to_utf8(buffer, bufferlen, input);
}

#endif

stbi_us *raia_stbi_load_16_from_memory(stbi_uc const *buffer, int len, int *x, int *y, int *channels_in_file, int desired_channels) {
    return stbi_load_16_from_memory(buffer, len, x, y, channels_in_file, desired_channels);
}

stbi_us *raia_stbi_load_16_from_callbacks(stbi_io_callbacks const *clbk, void *user, int *x, int *y, int *channels_in_file, int desired_channels) {
    return stbi_load_16_from_callbacks(clbk, user, x, y, channels_in_file, desired_channels);
}

#ifndef STBI_NO_STDIO

stbi_us *raia_stbi_load_16(char const *filename, int *x, int *y, int *channels_in_file, int desired_channels) {
    return stbi_load_16(filename, x, y, channels_in_file, desired_channels);
}

stbi_us *raia_stbi_load_from_file_16(FILE *f, int *x, int *y, int *channels_in_file, int desired_channels) {
    return stbi_load_from_file_16(f, x, y, channels_in_file, desired_channels);
}

#endif

#ifndef STBI_NO_LINEAR

float *raia_stbi_loadf_from_memory(stbi_uc const *buffer, int len, int *x, int *y, int *channels_in_file, int desired_channels) {
    return stbi_loadf_from_memory(buffer, len, x, y, channels_in_file, desired_channels);
}

float *raia_stbi_loadf_from_callbacks(stbi_io_callbacks const *clbk, void *user, int *x, int *y,  int *channels_in_file, int desired_channels) {
    return stbi_loadf_from_callbacks(clbk, user, x, y, channels_in_file, desired_channels);
}

#ifndef STBI_NO_STDIO

float *raia_stbi_loadf(char const *filename, int *x, int *y, int *channels_in_file, int desired_channels) {
    return stbi_loadf(filename, x, y, channels_in_file, desired_channels);
}

float *raia_stbi_loadf_from_file(FILE *f, int *x, int *y, int *channels_in_file, int desired_channels) {
    return stbi_loadf_from_file(f, x, y, channels_in_file, desired_channels);
}

#endif
#endif

#ifndef STBI_NO_HDR

void raia_stbi_hdr_to_ldr_gamma(float gamma) {
    stbi_hdr_to_ldr_gamma(gamma);
}

void raia_stbi_hdr_to_ldr_scale(float scale) {
    stbi_hdr_to_ldr_scale(scale);
}

#endif // STBI_NO_HDR

#ifndef STBI_NO_LINEAR

void raia_stbi_ldr_to_hdr_gamma(float gamma) {
    stbi_ldr_to_hdr_gamma(gamma);
}

void raia_stbi_ldr_to_hdr_scale(float scale) {
    stbi_ldr_to_hdr_scale(scale);
}

#endif // STBI_NO_LINEAR

int raia_stbi_is_hdr_from_callbacks(stbi_io_callbacks const *clbk, void *user) {
    return stbi_is_hdr_from_callbacks(clbk, user);
}

int raia_stbi_is_hdr_from_memory(stbi_uc const *buffer, int len) {
    return stbi_is_hdr_from_memory(buffer, len);
}

#ifndef STBI_NO_STDIO

int raia_stbi_is_hdr(char const *filename) {
    return stbi_is_hdr(filename);
}

int raia_stbi_is_hdr_from_file(FILE *f) {
    return stbi_is_hdr_from_file(f);
}

#endif // STBI_NO_STDIO

const char *raia_stbi_failure_reason(void) {
    return stbi_failure_reason();
}

void raia_stbi_image_free(void *retval_from_stbi_load) {
    stbi_image_free(retval_from_stbi_load);
}

int raia_stbi_info_from_memory(stbi_uc const *buffer, int len, int *x, int *y, int *comp) {
    return stbi_info_from_memory(buffer, len, x, y, comp);
}

int raia_stbi_info_from_callbacks(stbi_io_callbacks const *clbk, void *user, int *x, int *y, int *comp) {
    return stbi_info_from_callbacks(clbk, user, x, y, comp);
}

int raia_stbi_is_16_bit_from_memory(stbi_uc const *buffer, int len) {
    return stbi_is_16_bit_from_memory(buffer, len);
}

int raia_stbi_is_16_bit_from_callbacks(stbi_io_callbacks const *clbk, void *user) {
    return stbi_is_16_bit_from_callbacks(clbk, user);
}

#ifndef STBI_NO_STDIO

int raia_stbi_info(char const *filename, int *x, int *y, int *comp) {
    return stbi_info(filename, x, y, comp);
}

int raia_stbi_info_from_file(FILE *f, int *x, int *y, int *comp) {
    return stbi_info_from_file(f, x, y, comp);
}

int raia_stbi_is_16_bit(char const *filename) {
    return stbi_is_16_bit(filename);
}

int raia_stbi_is_16_bit_from_file(FILE *f) {
    return stbi_is_16_bit_from_file(f);
}

#endif

void raia_stbi_set_unpremultiply_on_load(int flag_true_if_should_unpremultiply) {
    stbi_set_unpremultiply_on_load(flag_true_if_should_unpremultiply);
}

void raia_stbi_convert_iphone_png_to_rgb(int flag_true_if_should_convert) {
    stbi_convert_iphone_png_to_rgb(flag_true_if_should_convert);
}

void raia_stbi_set_flip_vertically_on_load(int flag_true_if_should_flip) {
    stbi_set_flip_vertically_on_load(flag_true_if_should_flip);
}

void raia_stbi_set_unpremultiply_on_load_thread(int flag_true_if_should_unpremultiply) {
    stbi_set_unpremultiply_on_load_thread(flag_true_if_should_unpremultiply);
}

void raia_stbi_convert_iphone_png_to_rgb_thread(int flag_true_if_should_convert) {
    stbi_convert_iphone_png_to_rgb_thread(flag_true_if_should_convert);
}

void raia_stbi_set_flip_vertically_on_load_thread(int flag_true_if_should_flip) {
    stbi_set_flip_vertically_on_load_thread(flag_true_if_should_flip);
}

char *raia_stbi_zlib_decode_malloc_guesssize(const char *buffer, int len, int initial_size, int *outlen) {
    return stbi_zlib_decode_malloc_guesssize(buffer, len, initial_size, outlen);
}

char *raia_stbi_zlib_decode_malloc_guesssize_headerflag(const char *buffer, int len, int initial_size, int *outlen, int parse_header) {
    return stbi_zlib_decode_malloc_guesssize_headerflag(buffer, len, initial_size, outlen, parse_header);
}

char *raia_stbi_zlib_decode_malloc(const char *buffer, int len, int *outlen) {
    return stbi_zlib_decode_malloc(buffer, len, outlen);
}

int raia_stbi_zlib_decode_buffer(char *obuffer, int olen, const char *ibuffer, int ilen) {
    return stbi_zlib_decode_buffer(obuffer, olen, ibuffer, ilen);
}

char *raia_stbi_zlib_decode_noheader_malloc(const char *buffer, int len, int *outlen) {
    return stbi_zlib_decode_noheader_malloc(buffer, len, outlen);
}

int raia_stbi_zlib_decode_noheader_buffer(char *obuffer, int olen, const char *ibuffer, int ilen) {
    return stbi_zlib_decode_noheader_buffer(obuffer, olen, ibuffer, ilen);
}
