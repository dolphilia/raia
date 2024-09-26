local ffi = require("ffi")

-- 汎用ファイナライザ設定関数
local function setFinalizer(key, deleteFunction)
    ffi.gc(ffi.new("int[1]", key), function(k)
        deleteFunction(k[0])
    end)
end

ffi.cdef[[
    typedef int8_t   ma_int8;
    typedef uint8_t  ma_uint8;
    typedef int16_t  ma_int16;
    typedef uint16_t ma_uint16;
    typedef int32_t  ma_int32;
    typedef uint32_t ma_uint32;
    typedef int64_t  ma_int64;
    typedef uint64_t ma_uint64;
]]

if raia.os.getSizeofPtr() == 8 then
    ffi.cdef[[
        typedef ma_uint64 ma_uintptr;
    ]]
else
    ffi.cdef[[
        typedef ma_uint32 ma_uintptr;
    ]]
end

ffi.cdef[[
    typedef ma_uint8    ma_bool8;
    typedef ma_uint32   ma_bool32;
    typedef float       ma_float;
    typedef double      ma_double;
    typedef void* ma_handle;
    typedef void* ma_ptr;
]]

if raia.os.isCompiledGCC() == true then
    ffi.cdef[[
        typedef void (*ma_proc)(void);
    ]]
else
    ffi.cdef[[
        typedef void* ma_proc;
    ]]
end

if isCompiledMSVC == true and isDefinedWCharT == false then
    ffi.cdef[[
        typedef ma_uint16 wchar_t;
    ]]
end

if raia.os.isLinux() == true then
    ffi.cdef[[
        typedef unsigned long int ma_pthread_t;
        typedef unsigned long int ma_pthread_mutex_t;
        typedef unsigned long int ma_pthread_cond_t;
    ]]
elseif raia.os.isMacOS() == true then
    ffi.cdef[[
        typedef void * ma_pthread_t;
        typedef void * ma_pthread_mutex_t;
        typedef void * ma_pthread_cond_t;
    ]]
end

if raia.os.isWindows() == true and raia.os.isPosix() == false then
    ffi.cdef[[
        typedef wchar_t ma_wchar_win32;
    ]]
else
    ffi.cdef[[
        typedef ma_uint16 ma_wchar_win32;
    ]]
end

ffi.cdef[[
    // Version
    void raia_ma_version(ma_uint32* pMajor, ma_uint32* pMinor, ma_uint32* pRevision);
    const char* raia_ma_version_string(void);
    // Logging
    ma_log_callback raia_ma_log_callback_init(ma_log_callback_proc onLog, void* pUserData);
    ma_result raia_ma_log_init(const ma_allocation_callbacks* pAllocationCallbacks, ma_log* pLog);
    void raia_ma_log_uninit(ma_log* pLog);
    ma_result raia_ma_log_register_callback(ma_log* pLog, ma_log_callback callback);
    ma_result raia_ma_log_unregister_callback(ma_log* pLog, ma_log_callback callback);
    ma_result raia_ma_log_post(ma_log* pLog, ma_uint32 level, const char* pMessage);
    ma_result raia_ma_log_postv(ma_log* pLog, ma_uint32 level, const char* pFormat, va_list args);
    //ma_result ma_log_postf(ma_log* pLog, ma_uint32 level, const char* pFormat, ...); // TODO
]]

local lib = ffi.load("raia_miniaudio")
local MA = {}

return MA