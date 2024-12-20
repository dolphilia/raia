local ffi = require("ffi")

-- 汎用ファイナライザ設定関数
local function setFinalizer(key, deleteFunction)
    ffi.gc(ffi.new("int[1]", key), function(k)
        deleteFunction(k[0])
    end)
end

ffi.cdef [[
    // stb_image
    void *raia_stbi_load_from_memory(void const *buffer, int len, int *x, int *y, int *channels_in_file, int desired_channels);
    void *raia_stbi_load_from_callbacks(void const *clbk, void *user, int *x, int *y, int *channels_in_file, int desired_channels);
    void *raia_stbi_load(char const *filename, int *x, int *y, int *channels_in_file, int desired_channels);
    void *raia_stbi_load_from_file(void *f, int *x, int *y, int *channels_in_file, int desired_channels);
    void *raia_stbi_load_gif_from_memory(void const *buffer, int len, int **delays, int *x, int *y, int *z, int *comp, int req_comp);
    // int raia_stbi_convert_wchar_to_utf8(char *buffer, size_t bufferlen, const wchar_t* input); // Windows Only
    void *raia_stbi_load_16_from_memory(void const *buffer, int len, int *x, int *y, int *channels_in_file, int desired_channels);
    void *raia_stbi_load_16_from_callbacks(void const *clbk, void *user, int *x, int *y, int *channels_in_file, int desired_channels);
    void *raia_stbi_load_16(char const *filename, int *x, int *y, int *channels_in_file, int desired_channels);
    void *raia_stbi_load_from_file_16(void *f, int *x, int *y, int *channels_in_file, int desired_channels);
    float *raia_stbi_loadf_from_memory(void const *buffer, int len, int *x, int *y, int *channels_in_file, int desired_channels);
    float *raia_stbi_loadf_from_callbacks(void const *clbk, void *user, int *x, int *y,  int *channels_in_file, int desired_channels);
    float *raia_stbi_loadf(char const *filename, int *x, int *y, int *channels_in_file, int desired_channels);
    float *raia_stbi_loadf_from_file(void *f, int *x, int *y, int *channels_in_file, int desired_channels);
    void raia_stbi_hdr_to_ldr_gamma(float gamma);
    void raia_stbi_hdr_to_ldr_scale(float scale);
    void raia_stbi_ldr_to_hdr_gamma(float gamma);
    void raia_stbi_ldr_to_hdr_scale(float scale);
    int raia_stbi_is_hdr_from_callbacks(void const *clbk, void *user);
    int raia_stbi_is_hdr_from_memory(void const *buffer, int len);
    int raia_stbi_is_hdr(char const *filename);
    int raia_stbi_is_hdr_from_file(void *f);
    const char *raia_stbi_failure_reason(void);
    void raia_stbi_image_free(void *retval_from_stbi_load);
    int raia_stbi_info_from_memory(void const *buffer, int len, int *x, int *y, int *comp);
    int raia_stbi_info_from_callbacks(void const *clbk, void *user, int *x, int *y, int *comp);
    int raia_stbi_is_16_bit_from_memory(void const *buffer, int len);
    int raia_stbi_is_16_bit_from_callbacks(void const *clbk, void *user);
    int raia_stbi_info(char const *filename, int *x, int *y, int *comp);
    int raia_stbi_info_from_file(void *f, int *x, int *y, int *comp);
    int raia_stbi_is_16_bit(char const *filename);
    int raia_stbi_is_16_bit_from_file(void *f);
    void raia_stbi_set_unpremultiply_on_load(int flag_true_if_should_unpremultiply);
    void raia_stbi_convert_iphone_png_to_rgb(int flag_true_if_should_convert);
    void raia_stbi_set_flip_vertically_on_load(int flag_true_if_should_flip);
    void raia_stbi_set_unpremultiply_on_load_thread(int flag_true_if_should_unpremultiply);
    void raia_stbi_convert_iphone_png_to_rgb_thread(int flag_true_if_should_convert);
    void raia_stbi_set_flip_vertically_on_load_thread(int flag_true_if_should_flip);
    char *raia_stbi_zlib_decode_malloc_guesssize(const char *buffer, int len, int initial_size, int *outlen);
    char *raia_stbi_zlib_decode_malloc_guesssize_headerflag(const char *buffer, int len, int initial_size, int *outlen, int parse_header);
    char *raia_stbi_zlib_decode_malloc(const char *buffer, int len, int *outlen);
    int raia_stbi_zlib_decode_buffer(char *obuffer, int olen, const char *ibuffer, int ilen);
    char *raia_stbi_zlib_decode_noheader_malloc(const char *buffer, int len, int *outlen);
    int raia_stbi_zlib_decode_noheader_buffer(char *obuffer, int olen, const char *ibuffer, int ilen);
    // stb_image_write
    int raia_stbi_write_png(char const *filename, int w, int h, int comp, const void  *data, int stride_in_bytes);
    int raia_stbi_write_bmp(char const *filename, int w, int h, int comp, const void  *data);
    int raia_stbi_write_tga(char const *filename, int w, int h, int comp, const void  *data);
    int raia_stbi_write_hdr(char const *filename, int w, int h, int comp, const float *data);
    int raia_stbi_write_jpg(char const *filename, int x, int y, int comp, const void  *data, int quality);
    int raia_stbiw_convert_wchar_to_utf8(char *buffer, size_t bufferlen, const wchar_t* input); // windows only
    int raia_stbi_write_png_to_func(void *func, void *context, int w, int h, int comp, const void  *data, int stride_in_bytes);
    int raia_stbi_write_bmp_to_func(void *func, void *context, int w, int h, int comp, const void  *data);
    int raia_stbi_write_tga_to_func(void *func, void *context, int w, int h, int comp, const void  *data);
    int raia_stbi_write_hdr_to_func(void *func, void *context, int w, int h, int comp, const float *data);
    int raia_stbi_write_jpg_to_func(void *func, void *context, int x, int y, int comp, const void  *data, int quality);
    void raia_stbi_flip_vertically_on_write(int flip_boolean);
]]

local lib = ffi.load("raia_stb")
local STB = {}
STB.Image = {}

STB.Image.ColorMode = {
    Default = 0,
    Grey = 1,
    GreyAlpha = 2,
    RGB = 3,
    RGBA  = 4
}

function STB.Image.loadFromMemory(buffer, len, x, y, channels_in_file, desired_channels)
    return lib.raia_stbi_load_from_memory(buffer, len, x, y, channels_in_file, desired_channels)
end

function STB.Image.loadFromCallbacks(clbk, user, x, y, channels_in_file, desired_channels)
    return lib.raia_stbi_load_from_callbacks(clbk, user, x, y, channels_in_file, desired_channels)
end

function STB.Image.load(filename, x, y, channels_in_file, desired_channels)
    return lib.raia_stbi_load(filename, x, y, channels_in_file, desired_channels)
end

function STB.Image.loadFromFile(f, x, y, channels_in_file, desired_channels)
    return lib.raia_stbi_load_from_file(f, x, y, channels_in_file, desired_channels)
end

function STB.Image.loadGIFFromMemory(buffer, len, delays, x, y, z, comp, req_comp)
    return lib.raia_stbi_load_gif_from_memory(buffer, len, delays, x, y, z, comp, req_comp)
end

-- Windows Only
--function STB.Image.convertWcharToUTF8(buffer, bufferlen, input)
--    return lib.raia_stbi_convert_wchar_to_utf8(buffer, bufferlen, input)
--end

function STB.Image.load16FromMemory(buffer, len, x, y, channels_in_file, desired_channels)
    return lib.raia_stbi_load_16_from_memory(buffer, len, x, y, channels_in_file, desired_channels)
end

function STB.Image.load16FromCallbacks(clbk, user, x, y, channels_in_file, desired_channels)
    return lib.raia_stbi_load_16_from_callbacks(clbk, user, x, y, channels_in_file, desired_channels)
end

function STB.Image.load16(filename, x, y, channels_in_file, desired_channels)
    return lib.raia_stbi_load_16(filename, x, y, channels_in_file, desired_channels)
end

function STB.Image.loadFromFile16(f, x, y, channels_in_file, desired_channels)
    return lib.raia_stbi_load_from_file_16(f, x, y, channels_in_file, desired_channels)
end

function STB.Image.loadfFromMemory(buffer, len, x, y, channels_in_file, desired_channels)
    return lib.raia_stbi_loadf_from_memory(buffer, len, x, y, channels_in_file, desired_channels)
end

function STB.Image.loadfFromCallbacks(clbk, user, x, y, channels_in_file, desired_channels)
    return lib.raia_stbi_loadf_from_callbacks(clbk, user, x, y, channels_in_file, desired_channels)
end

function STB.Image.loadf(filename, x, y, channels_in_file, desired_channels)
    return lib.raia_stbi_loadf(filename, x, y, channels_in_file, desired_channels)
end

function STB.Image.loadfFromFile(f, x, y, channels_in_file, desired_channels)
    return lib.raia_stbi_loadf_from_file(f, x, y, channels_in_file, desired_channels)
end

function STB.Image.hdrToLDRGamma(gamma)
    lib.raia_stbi_hdr_to_ldr_gamma(gamma)
end

function STB.Image.hdrToLDRScale(scale)
    lib.raia_stbi_hdr_to_ldr_scale(scale)
end

function STB.Image.ldrToHDRGamma(gamma)
    lib.raia_stbi_ldr_to_hdr_gamma(gamma)
end

function STB.Image.ldrToHDRScale(scale)
    lib.raia_stbi_ldr_to_hdr_scale(scale)
end

function STB.Image.isHDRFromCallbacks(clbk, user)
    return lib.raia_stbi_is_hdr_from_callbacks(clbk, user)
end

function STB.Image.isHDRFromMemory(buffer, len)
    return lib.raia_stbi_is_hdr_from_memory(buffer, len)
end

function STB.Image.isHDR(filename)
    return lib.raia_stbi_is_hdr(filename)
end

function STB.Image.isHDRFromFile(f)
    return lib.raia_stbi_is_hdr_from_file(f)
end

function STB.Image.failureReason()
    return lib.raia_stbi_failure_reason()
end

function STB.Image.imageFree(retval_from_stbi_load)
    lib.raia_stbi_image_free(retval_from_stbi_load)
end

function STB.Image.infoFromMemory(buffer, len, x, y, comp)
    return lib.raia_stbi_info_from_memory(buffer, len, x, y, comp)
end

function STB.Image.infoFromCallbacks(clbk, user, x, y, comp)
    return lib.raia_stbi_info_from_callbacks(clbk, user, x, y, comp)
end

function STB.Image.is16bitFromMemory(buffer, len)
    return lib.raia_stbi_is_16_bit_from_memory(buffer, len)
end

function STB.Image.is16bitFromCallbacks(clbk, user)
    return lib.raia_stbi_is_16_bit_from_callbacks(clbk, user)
end

function STB.Image.info(filename, x, y, comp)
    return lib.raia_stbi_info(filename, x, y, comp)
end

function STB.Image.infoFromFile(f, x, y, comp)
    return lib.raia_stbi_info_from_file(f, x, y, comp)
end

function STB.Image.is16bit(filename)
    return lib.raia_stbi_is_16_bit(filename)
end

function STB.Image.is16bitFromFile(f)
    return lib.raia_stbi_is_16_bit_from_file(f)
end

function STB.Image.setUnpremultiplyOnLoad(flag_true_if_should_unpremultiply)
    lib.raia_stbi_set_unpremultiply_on_load(flag_true_if_should_unpremultiply)
end

function STB.Image.convertIphonePNGToRGB(flag_true_if_should_convert)
    lib.raia_stbi_convert_iphone_png_to_rgb(flag_true_if_should_convert)
end

function STB.Image.setFlipVerticallyOnLoad(flag_true_if_should_flip)
    lib.raia_stbi_set_flip_vertically_on_load(flag_true_if_should_flip)
end

function STB.Image.setUnpremultiplyOnLoadThread(flag_true_if_should_unpremultiply)
    lib.raia_stbi_set_unpremultiply_on_load_thread(flag_true_if_should_unpremultiply)
end

function STB.Image.convertIphonePNGToRGBThread(flag_true_if_should_convert)
    lib.raia_stbi_convert_iphone_png_to_rgb_thread(flag_true_if_should_convert)
end

function STB.Image.setFlipVerticallyOnLoadThread(flag_true_if_should_flip)
    lib.raia_stbi_set_flip_vertically_on_load_thread(flag_true_if_should_flip)
end

function STB.Image.zlibDecodeMallocGuessSize(buffer, len, initial_size, outlen)
    return lib.raia_stbi_zlib_decode_malloc_guesssize(buffer, len, initial_size, outlen)
end

function STB.Image.zlibDecodeMallocGuessSizeHeaderFlag(buffer, len, initial_size, outlen, parse_header)
    return lib.raia_stbi_zlib_decode_malloc_guesssize_headerflag(buffer, len, initial_size, outlen, parse_header)
end

function STB.Image.zlibDecodeMalloc(buffer, len, outlen)
    return lib.raia_stbi_zlib_decode_malloc(buffer, len, outlen)
end

function STB.Image.zlibDecodeBuffer(obuffer, olen, ibuffer, ilen)
    return lib.raia_stbi_zlib_decode_buffer(obuffer, olen, ibuffer, ilen)
end

function STB.Image.zlibDecodeNoHeaderMalloc(buffer, len, outlen)
    return lib.raia_stbi_zlib_decode_noheader_malloc(buffer, len, outlen)
end

function STB.Image.zlibDecodeNoHeaderBuffer(obuffer, olen, ibuffer, ilen)
    return lib.raia_stbi_zlib_decode_noheader_buffer(obuffer, olen, ibuffer, ilen)
end

STB.ImageWrite = {}

function STB.ImageWrite.png(filename, w, h, comp, data, stride_in_bytes)
    return lib.raia_stbi_write_png(filename, w, h, comp, data, stride_in_bytes)
end

function STB.ImageWrite.bmp(filename, w, h, comp, data)
    return lib.raia_stbi_write_bmp(filename, w, h, comp, data)
end

function STB.ImageWrite.tga(filename, w, h, comp, data)
    return lib.raia_stbi_write_tga(filename, w, h, comp, data)
end

function STB.ImageWrite.hdr(filename, w, h, comp, data)
    return lib.raia_stbi_write_hdr(filename, w, h, comp, data)
end

function STB.ImageWrite.jpg(filename, x, y, comp, data, quality)
    return lib.raia_stbi_write_jpg(filename, x, y, comp, data, quality)
end

-- windows only
function STB.ImageWrite.convertWcharToUTF8(buffer, bufferlen, input)
    return lib.raia_stbiw_convert_wchar_to_utf8(buffer, bufferlen, input);
end

function STB.ImageWrite.pngToFunc(func, context, w, h, comp, data, stride_in_bytes)
    return lib.raia_stbi_write_png_to_func(func, context, w, h, comp, data, stride_in_bytes)
end

function STB.ImageWrite.bmpToFunc(func, context, w, h, comp, data)
    return lib.raia_stbi_write_bmp_to_func(func, context, w, h, comp, data)
end

function STB.ImageWrite.tgaToFunc(func, context, w, h, comp, data)
    return lib.raia_stbi_write_tga_to_func(func, context, w, h, comp, data)
end

function STB.ImageWrite.hdrToFunc(func, context, w, h, comp, data)
    return lib.raia_stbi_write_hdr_to_func(func, context, w, h, comp, data)
end

function STB.ImageWrite.jpgToFunc(func, context, x, y, comp, data, quality)
    return lib.raia_stbi_write_jpg_to_func(func, context, x, y, comp, data, quality)
end

function STB.ImageWrite.flipVerticallyOnWrite(flip_boolean)
    lib.raia_stbi_flip_vertically_on_write(flip_boolean)
end

return STB