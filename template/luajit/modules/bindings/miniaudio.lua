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
    typedef enum
    {
        MA_LOG_LEVEL_DEBUG   = 4,
        MA_LOG_LEVEL_INFO    = 3,
        MA_LOG_LEVEL_WARNING = 2,
        MA_LOG_LEVEL_ERROR   = 1
    } ma_log_level;

    typedef struct ma_context ma_context;
    typedef struct ma_device ma_device;

    typedef ma_uint8 ma_channel;
    typedef enum
    {
        MA_CHANNEL_NONE               = 0,
        MA_CHANNEL_MONO               = 1,
        MA_CHANNEL_FRONT_LEFT         = 2,
        MA_CHANNEL_FRONT_RIGHT        = 3,
        MA_CHANNEL_FRONT_CENTER       = 4,
        MA_CHANNEL_LFE                = 5,
        MA_CHANNEL_BACK_LEFT          = 6,
        MA_CHANNEL_BACK_RIGHT         = 7,
        MA_CHANNEL_FRONT_LEFT_CENTER  = 8,
        MA_CHANNEL_FRONT_RIGHT_CENTER = 9,
        MA_CHANNEL_BACK_CENTER        = 10,
        MA_CHANNEL_SIDE_LEFT          = 11,
        MA_CHANNEL_SIDE_RIGHT         = 12,
        MA_CHANNEL_TOP_CENTER         = 13,
        MA_CHANNEL_TOP_FRONT_LEFT     = 14,
        MA_CHANNEL_TOP_FRONT_CENTER   = 15,
        MA_CHANNEL_TOP_FRONT_RIGHT    = 16,
        MA_CHANNEL_TOP_BACK_LEFT      = 17,
        MA_CHANNEL_TOP_BACK_CENTER    = 18,
        MA_CHANNEL_TOP_BACK_RIGHT     = 19,
        MA_CHANNEL_AUX_0              = 20,
        MA_CHANNEL_AUX_1              = 21,
        MA_CHANNEL_AUX_2              = 22,
        MA_CHANNEL_AUX_3              = 23,
        MA_CHANNEL_AUX_4              = 24,
        MA_CHANNEL_AUX_5              = 25,
        MA_CHANNEL_AUX_6              = 26,
        MA_CHANNEL_AUX_7              = 27,
        MA_CHANNEL_AUX_8              = 28,
        MA_CHANNEL_AUX_9              = 29,
        MA_CHANNEL_AUX_10             = 30,
        MA_CHANNEL_AUX_11             = 31,
        MA_CHANNEL_AUX_12             = 32,
        MA_CHANNEL_AUX_13             = 33,
        MA_CHANNEL_AUX_14             = 34,
        MA_CHANNEL_AUX_15             = 35,
        MA_CHANNEL_AUX_16             = 36,
        MA_CHANNEL_AUX_17             = 37,
        MA_CHANNEL_AUX_18             = 38,
        MA_CHANNEL_AUX_19             = 39,
        MA_CHANNEL_AUX_20             = 40,
        MA_CHANNEL_AUX_21             = 41,
        MA_CHANNEL_AUX_22             = 42,
        MA_CHANNEL_AUX_23             = 43,
        MA_CHANNEL_AUX_24             = 44,
        MA_CHANNEL_AUX_25             = 45,
        MA_CHANNEL_AUX_26             = 46,
        MA_CHANNEL_AUX_27             = 47,
        MA_CHANNEL_AUX_28             = 48,
        MA_CHANNEL_AUX_29             = 49,
        MA_CHANNEL_AUX_30             = 50,
        MA_CHANNEL_AUX_31             = 51,
        MA_CHANNEL_LEFT               = MA_CHANNEL_FRONT_LEFT,
        MA_CHANNEL_RIGHT              = MA_CHANNEL_FRONT_RIGHT,
        MA_CHANNEL_POSITION_COUNT     = (MA_CHANNEL_AUX_31 + 1)
    } _ma_channel_position; /* Do not use `_ma_channel_position` directly. Use `ma_channel` instead. */

    typedef enum
    {
        MA_SUCCESS                        =  0,
        MA_ERROR                          = -1,  /* A generic error. */
        MA_INVALID_ARGS                   = -2,
        MA_INVALID_OPERATION              = -3,
        MA_OUT_OF_MEMORY                  = -4,
        MA_OUT_OF_RANGE                   = -5,
        MA_ACCESS_DENIED                  = -6,
        MA_DOES_NOT_EXIST                 = -7,
        MA_ALREADY_EXISTS                 = -8,
        MA_TOO_MANY_OPEN_FILES            = -9,
        MA_INVALID_FILE                   = -10,
        MA_TOO_BIG                        = -11,
        MA_PATH_TOO_LONG                  = -12,
        MA_NAME_TOO_LONG                  = -13,
        MA_NOT_DIRECTORY                  = -14,
        MA_IS_DIRECTORY                   = -15,
        MA_DIRECTORY_NOT_EMPTY            = -16,
        MA_AT_END                         = -17,
        MA_NO_SPACE                       = -18,
        MA_BUSY                           = -19,
        MA_IO_ERROR                       = -20,
        MA_INTERRUPT                      = -21,
        MA_UNAVAILABLE                    = -22,
        MA_ALREADY_IN_USE                 = -23,
        MA_BAD_ADDRESS                    = -24,
        MA_BAD_SEEK                       = -25,
        MA_BAD_PIPE                       = -26,
        MA_DEADLOCK                       = -27,
        MA_TOO_MANY_LINKS                 = -28,
        MA_NOT_IMPLEMENTED                = -29,
        MA_NO_MESSAGE                     = -30,
        MA_BAD_MESSAGE                    = -31,
        MA_NO_DATA_AVAILABLE              = -32,
        MA_INVALID_DATA                   = -33,
        MA_TIMEOUT                        = -34,
        MA_NO_NETWORK                     = -35,
        MA_NOT_UNIQUE                     = -36,
        MA_NOT_SOCKET                     = -37,
        MA_NO_ADDRESS                     = -38,
        MA_BAD_PROTOCOL                   = -39,
        MA_PROTOCOL_UNAVAILABLE           = -40,
        MA_PROTOCOL_NOT_SUPPORTED         = -41,
        MA_PROTOCOL_FAMILY_NOT_SUPPORTED  = -42,
        MA_ADDRESS_FAMILY_NOT_SUPPORTED   = -43,
        MA_SOCKET_NOT_SUPPORTED           = -44,
        MA_CONNECTION_RESET               = -45,
        MA_ALREADY_CONNECTED              = -46,
        MA_NOT_CONNECTED                  = -47,
        MA_CONNECTION_REFUSED             = -48,
        MA_NO_HOST                        = -49,
        MA_IN_PROGRESS                    = -50,
        MA_CANCELLED                      = -51,
        MA_MEMORY_ALREADY_MAPPED          = -52,

        /* General non-standard errors. */
        MA_CRC_MISMATCH                   = -100,

        /* General miniaudio-specific errors. */
        MA_FORMAT_NOT_SUPPORTED           = -200,
        MA_DEVICE_TYPE_NOT_SUPPORTED      = -201,
        MA_SHARE_MODE_NOT_SUPPORTED       = -202,
        MA_NO_BACKEND                     = -203,
        MA_NO_DEVICE                      = -204,
        MA_API_NOT_FOUND                  = -205,
        MA_INVALID_DEVICE_CONFIG          = -206,
        MA_LOOP                           = -207,
        MA_BACKEND_NOT_ENABLED            = -208,

        /* State errors. */
        MA_DEVICE_NOT_INITIALIZED         = -300,
        MA_DEVICE_ALREADY_INITIALIZED     = -301,
        MA_DEVICE_NOT_STARTED             = -302,
        MA_DEVICE_NOT_STOPPED             = -303,

        /* Operation errors. */
        MA_FAILED_TO_INIT_BACKEND         = -400,
        MA_FAILED_TO_OPEN_BACKEND_DEVICE  = -401,
        MA_FAILED_TO_START_BACKEND_DEVICE = -402,
        MA_FAILED_TO_STOP_BACKEND_DEVICE  = -403
    } ma_result;

    typedef enum
    {
        ma_stream_format_pcm = 0
    } ma_stream_format;

    typedef enum
    {
        ma_stream_layout_interleaved = 0,
        ma_stream_layout_deinterleaved
    } ma_stream_layout;

    typedef enum
    {
        ma_dither_mode_none = 0,
        ma_dither_mode_rectangle,
        ma_dither_mode_triangle
    } ma_dither_mode;

    typedef enum
    {
        /*
        I like to keep these explicitly defined because they're used as a key into a lookup table. When items are
        added to this, make sure there are no gaps and that they're added to the lookup table in ma_get_bytes_per_sample().
        */
        ma_format_unknown = 0,     /* Mainly used for indicating an error, but also used as the default for the output format for decoders. */
        ma_format_u8      = 1,
        ma_format_s16     = 2,     /* Seems to be the most widely supported format. */
        ma_format_s24     = 3,     /* Tightly packed. 3 bytes per sample. */
        ma_format_s32     = 4,
        ma_format_f32     = 5,
        ma_format_count
    } ma_format;

    typedef enum
    {
        /* Standard rates need to be in priority order. */
        ma_standard_sample_rate_48000  = 48000,     /* Most common */
        ma_standard_sample_rate_44100  = 44100,

        ma_standard_sample_rate_32000  = 32000,     /* Lows */
        ma_standard_sample_rate_24000  = 24000,
        ma_standard_sample_rate_22050  = 22050,

        ma_standard_sample_rate_88200  = 88200,     /* Highs */
        ma_standard_sample_rate_96000  = 96000,
        ma_standard_sample_rate_176400 = 176400,
        ma_standard_sample_rate_192000 = 192000,

        ma_standard_sample_rate_16000  = 16000,     /* Extreme lows */
        ma_standard_sample_rate_11025  = 11025,
        ma_standard_sample_rate_8000   = 8000,

        ma_standard_sample_rate_352800 = 352800,    /* Extreme highs */
        ma_standard_sample_rate_384000 = 384000,

        ma_standard_sample_rate_min    = ma_standard_sample_rate_8000,
        ma_standard_sample_rate_max    = ma_standard_sample_rate_384000,
        ma_standard_sample_rate_count  = 14         /* Need to maintain the count manually. Make sure this is updated if items are added to enum. */
    } ma_standard_sample_rate;


    typedef enum
    {
        ma_channel_mix_mode_rectangular = 0,   /* Simple averaging based on the plane(s) the channel is sitting on. */
        ma_channel_mix_mode_simple,            /* Drop excess channels; zeroed out extra channels. */
        ma_channel_mix_mode_custom_weights,    /* Use custom weights specified in ma_channel_converter_config. */
        ma_channel_mix_mode_default = ma_channel_mix_mode_rectangular
    } ma_channel_mix_mode;

    typedef enum
    {
        ma_standard_channel_map_microsoft,
        ma_standard_channel_map_alsa,
        ma_standard_channel_map_rfc3551,   /* Based off AIFF. */
        ma_standard_channel_map_flac,
        ma_standard_channel_map_vorbis,
        ma_standard_channel_map_sound4,    /* FreeBSD's sound(4). */
        ma_standard_channel_map_sndio,     /* www.sndio.org/tips.html */
        ma_standard_channel_map_webaudio = ma_standard_channel_map_flac, /* https://webaudio.github.io/web-audio-api/#ChannelOrdering. Only 1, 2, 4 and 6 channels are defined, but can fill in the gaps with logical assumptions. */
        ma_standard_channel_map_default = ma_standard_channel_map_microsoft
    } ma_standard_channel_map;

    typedef enum
    {
        ma_performance_profile_low_latency = 0,
        ma_performance_profile_conservative
    } ma_performance_profile;

    typedef struct
    {
        void* pUserData;
        void* (* onMalloc)(size_t sz, void* pUserData);
        void* (* onRealloc)(void* p, size_t sz, void* pUserData);
        void  (* onFree)(void* p, void* pUserData);
    } ma_allocation_callbacks;

    typedef struct
    {
        ma_int32 state;
    } ma_lcg;
]]

-- Atomics

ffi.cdef[[
    typedef struct {
        ma_uint32 value;
    } ma_atomic_uint32;

    typedef struct {
        ma_int32 value;
    } ma_atomic_int32;

    typedef struct {
        ma_uint64 value;
    } ma_atomic_uint64;

    typedef struct {
        ma_float value;
    } ma_atomic_float;

    typedef struct {
        ma_bool32 value;
    } ma_atomic_bool32;
]]

ffi.cdef[[
    typedef ma_uint32 ma_spinlock;
]]

-- Thread

ffi.cdef[[
    typedef enum
    {
        ma_thread_priority_idle     = -5,
        ma_thread_priority_lowest   = -4,
        ma_thread_priority_low      = -3,
        ma_thread_priority_normal   = -2,
        ma_thread_priority_high     = -1,
        ma_thread_priority_highest  =  0,
        ma_thread_priority_realtime =  1,
        ma_thread_priority_default  =  0
    } ma_thread_priority;
]]

if raia.os.isPosix() then
    ffi.cdef[[
        typedef ma_pthread_t ma_thread;
        typedef ma_pthread_mutex_t ma_mutex;
        typedef struct {
            ma_uint32 value;
            ma_pthread_mutex_t lock;
            ma_pthread_cond_t cond;
        } ma_event;
        typedef struct {
            int value;
            ma_pthread_mutex_t lock;
            ma_pthread_cond_t cond;
        } ma_semaphore;
    ]]
elseif raia.os.isWindows() == true then
    ffi.cdef[[
        typedef ma_handle ma_thread;
        typedef ma_handle ma_mutex;
        typedef ma_handle ma_event;
        typedef ma_handle ma_semaphore;
    ]]
end

-- Logging

ffi.cdef[[
    typedef void (* ma_log_callback_proc)(void* pUserData, ma_uint32 level, const char* pMessage);

    typedef struct {
        ma_log_callback_proc onLog;
        void* pUserData;
    } ma_log_callback;

    typedef struct {
        ma_log_callback callbacks[4];
        ma_uint32 callbackCount;
        ma_allocation_callbacks allocationCallbacks;    /* Need to store these persistently because ma_log_postv() might need to allocate a buffer on the heap. */
        ma_mutex lock;  /* For thread safety just to make it easier and safer for the logging implementation. */
    } ma_log;
]]

-- Biquad Filtering

ffi.cdef[[
    typedef union {
        float    f32;
        ma_int32 s32;
    } ma_biquad_coefficient;

    typedef struct {
        ma_format format;
        ma_uint32 channels;
        double b0;
        double b1;
        double b2;
        double a0;
        double a1;
        double a2;
    } ma_biquad_config;

    typedef struct {
        ma_format format;
        ma_uint32 channels;
        ma_biquad_coefficient b0;
        ma_biquad_coefficient b1;
        ma_biquad_coefficient b2;
        ma_biquad_coefficient a1;
        ma_biquad_coefficient a2;
        ma_biquad_coefficient* pR1;
        ma_biquad_coefficient* pR2;

        /* Memory management. */
        void* _pHeap;
        ma_bool32 _ownsHeap;
    } ma_biquad;
]]

-- Low-Pass Filtering

ffi.cdef[[
    typedef struct {
        ma_format format;
        ma_uint32 channels;
        ma_uint32 sampleRate;
        double cutoffFrequency;
        double q;
    } ma_lpf1_config, ma_lpf2_config;

    typedef struct {
        ma_format format;
        ma_uint32 channels;
        ma_biquad_coefficient a;
        ma_biquad_coefficient* pR1;
    
        /* Memory management. */
        void* _pHeap;
        ma_bool32 _ownsHeap;
    } ma_lpf1;

    typedef struct {
        ma_biquad bq;   /* The second order low-pass filter is implemented as a biquad filter. */
    } ma_lpf2;

    typedef struct {
        ma_format format;
        ma_uint32 channels;
        ma_uint32 sampleRate;
        double cutoffFrequency;
        ma_uint32 order;    /* If set to 0, will be treated as a passthrough (no filtering will be applied). */
    } ma_lpf_config;
    
    typedef struct {
        ma_format format;
        ma_uint32 channels;
        ma_uint32 sampleRate;
        ma_uint32 lpf1Count;
        ma_uint32 lpf2Count;
        ma_lpf1* pLPF1;
        ma_lpf2* pLPF2;
    
        /* Memory management. */
        void* _pHeap;
        ma_bool32 _ownsHeap;
    } ma_lpf; 
]]

-- High-Pass Filtering

ffi.cdef[[
    typedef struct {
        ma_format format;
        ma_uint32 channels;
        ma_uint32 sampleRate;
        double cutoffFrequency;
        double q;
    } ma_hpf1_config, ma_hpf2_config;
    
    typedef struct {
        ma_format format;
        ma_uint32 channels;
        ma_biquad_coefficient a;
        ma_biquad_coefficient* pR1;
    
        /* Memory management. */
        void* _pHeap;
        ma_bool32 _ownsHeap;
    } ma_hpf1;
    
    typedef struct {
        ma_biquad bq;   /* The second order high-pass filter is implemented as a biquad filter. */
    } ma_hpf2;
    
    typedef struct {
        ma_format format;
        ma_uint32 channels;
        ma_uint32 sampleRate;
        double cutoffFrequency;
        ma_uint32 order;    /* If set to 0, will be treated as a passthrough (no filtering will be applied). */
    } ma_hpf_config;
    
    typedef struct {
        ma_format format;
        ma_uint32 channels;
        ma_uint32 sampleRate;
        ma_uint32 hpf1Count;
        ma_uint32 hpf2Count;
        ma_hpf1* pHPF1;
        ma_hpf2* pHPF2;
    
        /* Memory management. */
        void* _pHeap;
        ma_bool32 _ownsHeap;
    } ma_hpf;
]]

-- Band-Pass Filtering

ffi.cdef[[
    typedef struct {
        ma_format format;
        ma_uint32 channels;
        ma_uint32 sampleRate;
        double cutoffFrequency;
        double q;
    } ma_bpf2_config;
    
    typedef struct {
        ma_biquad bq;   /* The second order band-pass filter is implemented as a biquad filter. */
    } ma_bpf2;
    
    typedef struct {
        ma_format format;
        ma_uint32 channels;
        ma_uint32 sampleRate;
        double cutoffFrequency;
        ma_uint32 order;    /* If set to 0, will be treated as a passthrough (no filtering will be applied). */
    } ma_bpf_config;
    
    typedef struct {
        ma_format format;
        ma_uint32 channels;
        ma_uint32 bpf2Count;
        ma_bpf2* pBPF2;
    
        /* Memory management. */
        void* _pHeap;
        ma_bool32 _ownsHeap;
    } ma_bpf;
]]

-- Notching Filter

ffi.cdef[[
    typedef struct {
        ma_format format;
        ma_uint32 channels;
        ma_uint32 sampleRate;
        double q;
        double frequency;
    } ma_notch2_config, ma_notch_config;
    
    typedef struct {
        ma_biquad bq;
    } ma_notch2;
]]

-- Peaking EQ Filter

ffi.cdef[[
    typedef struct {
        ma_format format;
        ma_uint32 channels;
        ma_uint32 sampleRate;
        double gainDB;
        double q;
        double frequency;
    } ma_peak2_config, ma_peak_config;
    
    typedef struct {
        ma_biquad bq;
    } ma_peak2;
]]

-- Low Shelf Filter

ffi.cdef[[
    typedef struct {
        ma_format format;
        ma_uint32 channels;
        ma_uint32 sampleRate;
        double gainDB;
        double shelfSlope;
        double frequency;
    } ma_loshelf2_config, ma_loshelf_config;
    
    typedef struct {
        ma_biquad bq;
    } ma_loshelf2;
]]

-- High Shelf Filter

ffi.cdef[[
    typedef struct {
        ma_format format;
        ma_uint32 channels;
        ma_uint32 sampleRate;
        double gainDB;
        double shelfSlope;
        double frequency;
    } ma_hishelf2_config, ma_hishelf_config;
    
    typedef struct {
        ma_biquad bq;
    } ma_hishelf2;
]]

-- Delay

ffi.cdef[[
    typedef struct {
        ma_uint32 channels;
        ma_uint32 sampleRate;
        ma_uint32 delayInFrames;
        ma_bool32 delayStart;       /* Set to true to delay the start of the output; false otherwise. */
        float wet;                  /* 0..1. Default = 1. */
        float dry;                  /* 0..1. Default = 1. */
        float decay;                /* 0..1. Default = 0 (no feedback). Feedback decay. Use this for echo. */
    } ma_delay_config;
    
    typedef struct {
        ma_delay_config config;
        ma_uint32 cursor;               /* Feedback is written to this cursor. Always equal or in front of the read cursor. */
        ma_uint32 bufferSizeInFrames;
        float* pBuffer;
    } ma_delay;
]]

-- Gainer

ffi.cdef[[
    typedef struct {
        ma_uint32 channels;
        ma_uint32 smoothTimeInFrames;
    } ma_gainer_config;

    typedef struct {
        ma_gainer_config config;
        ma_uint32 t;
        float masterVolume;
        float* pOldGains;
        float* pNewGains;
    
        /* Memory management. */
        void* _pHeap;
        ma_bool32 _ownsHeap;
    } ma_gainer;
]]

-- Stereo panner

ffi.cdef[[
    typedef enum {
        ma_pan_mode_balance = 0,    /* Does not blend one side with the other. Technically just a balance. Compatible with other popular audio engines and therefore the default. */
        ma_pan_mode_pan             /* A true pan. The sound from one side will "move" to the other side and blend with it. */
    } ma_pan_mode;
    
    typedef struct {
        ma_format format;
        ma_uint32 channels;
        ma_pan_mode mode;
        float pan;
    } ma_panner_config;
    
    typedef struct {
        ma_format format;
        ma_uint32 channels;
        ma_pan_mode mode;
        float pan;  /* -1..1 where 0 is no pan, -1 is left side, +1 is right side. Defaults to 0. */
    } ma_panner;
]]

-- Fader

ffi.cdef[[
    typedef struct {
        ma_format format;
        ma_uint32 channels;
        ma_uint32 sampleRate;
    } ma_fader_config;
    
    typedef struct {
        ma_fader_config config;
        float volumeBeg;            /* If volumeBeg and volumeEnd is equal to 1, no fading happens (ma_fader_process_pcm_frames() will run as a passthrough). */
        float volumeEnd;
        ma_uint64 lengthInFrames;   /* The total length of the fade. */
        ma_int64  cursorInFrames;   /* The current time in frames. Incremented by ma_fader_process_pcm_frames(). Signed because it'll be offset by startOffsetInFrames in set_fade_ex(). */
    } ma_fader;
]]

-- Spatializer

ffi.cdef[[
    typedef struct {
        float x;
        float y;
        float z;
    } ma_vec3f;
    
    typedef struct {
        ma_vec3f v;
        ma_spinlock lock;
    } ma_atomic_vec3f;
    
    typedef enum {
        ma_attenuation_model_none,          /* No distance attenuation and no spatialization. */
        ma_attenuation_model_inverse,       /* Equivalent to OpenAL's AL_INVERSE_DISTANCE_CLAMPED. */
        ma_attenuation_model_linear,        /* Linear attenuation. Equivalent to OpenAL's AL_LINEAR_DISTANCE_CLAMPED. */
        ma_attenuation_model_exponential    /* Exponential attenuation. Equivalent to OpenAL's AL_EXPONENT_DISTANCE_CLAMPED. */
    } ma_attenuation_model;
    
    typedef enum {
        ma_positioning_absolute,
        ma_positioning_relative
    } ma_positioning;
    
    typedef enum {
        ma_handedness_right,
        ma_handedness_left
    } ma_handedness;
    
    typedef struct {
        ma_uint32 channelsOut;
        ma_channel* pChannelMapOut;
        ma_handedness handedness;   /* Defaults to right. Forward is -1 on the Z axis. In a left handed system, forward is +1 on the Z axis. */
        float coneInnerAngleInRadians;
        float coneOuterAngleInRadians;
        float coneOuterGain;
        float speedOfSound;
        ma_vec3f worldUp;
    } ma_spatializer_listener_config;
    
    typedef struct {
        ma_spatializer_listener_config config;
        ma_atomic_vec3f position;  /* The absolute position of the listener. */
        ma_atomic_vec3f direction; /* The direction the listener is facing. The world up vector is config.worldUp. */
        ma_atomic_vec3f velocity;
        ma_bool32 isEnabled;
    
        /* Memory management. */
        ma_bool32 _ownsHeap;
        void* _pHeap;
    } ma_spatializer_listener;
    
    typedef struct {
        ma_uint32 channelsIn;
        ma_uint32 channelsOut;
        ma_channel* pChannelMapIn;
        ma_attenuation_model attenuationModel;
        ma_positioning positioning;
        ma_handedness handedness;           /* Defaults to right. Forward is -1 on the Z axis. In a left handed system, forward is +1 on the Z axis. */
        float minGain;
        float maxGain;
        float minDistance;
        float maxDistance;
        float rolloff;
        float coneInnerAngleInRadians;
        float coneOuterAngleInRadians;
        float coneOuterGain;
        float dopplerFactor;                /* Set to 0 to disable doppler effect. */
        float directionalAttenuationFactor; /* Set to 0 to disable directional attenuation. */
        float minSpatializationChannelGain; /* The minimal scaling factor to apply to channel gains when accounting for the direction of the sound relative to the listener. Must be in the range of 0..1. Smaller values means more aggressive directional panning, larger values means more subtle directional panning. */
        ma_uint32 gainSmoothTimeInFrames;   /* When the gain of a channel changes during spatialization, the transition will be linearly interpolated over this number of frames. */
    } ma_spatializer_config;
    
    typedef struct {
        ma_uint32 channelsIn;
        ma_uint32 channelsOut;
        ma_channel* pChannelMapIn;
        ma_attenuation_model attenuationModel;
        ma_positioning positioning;
        ma_handedness handedness;           /* Defaults to right. Forward is -1 on the Z axis. In a left handed system, forward is +1 on the Z axis. */
        float minGain;
        float maxGain;
        float minDistance;
        float maxDistance;
        float rolloff;
        float coneInnerAngleInRadians;
        float coneOuterAngleInRadians;
        float coneOuterGain;
        float dopplerFactor;                /* Set to 0 to disable doppler effect. */
        float directionalAttenuationFactor; /* Set to 0 to disable directional attenuation. */
        ma_uint32 gainSmoothTimeInFrames;   /* When the gain of a channel changes during spatialization, the transition will be linearly interpolated over this number of frames. */
        ma_atomic_vec3f position;
        ma_atomic_vec3f direction;
        ma_atomic_vec3f velocity;  /* For doppler effect. */
        float dopplerPitch; /* Will be updated by ma_spatializer_process_pcm_frames() and can be used by higher level functions to apply a pitch shift for doppler effect. */
        float minSpatializationChannelGain;
        ma_gainer gainer;   /* For smooth gain transitions. */
        float* pNewChannelGainsOut; /* An offset of _pHeap. Used by ma_spatializer_process_pcm_frames() to store new channel gains. The number of elements in this array is equal to config.channelsOut. */
    
        /* Memory management. */
        void* _pHeap;
        ma_bool32 _ownsHeap;
    } ma_spatializer;
]]

-- Resampling

ffi.cdef[[
    typedef struct {
        ma_format format;
        ma_uint32 channels;
        ma_uint32 sampleRateIn;
        ma_uint32 sampleRateOut;
        ma_uint32 lpfOrder;         /* The low-pass filter order. Setting this to 0 will disable low-pass filtering. */
        double    lpfNyquistFactor; /* 0..1. Defaults to 1. 1 = Half the sampling frequency (Nyquist Frequency), 0.5 = Quarter the sampling frequency (half Nyquest Frequency), etc. */
    } ma_linear_resampler_config;
    
    typedef struct {
        ma_linear_resampler_config config;
        ma_uint32 inAdvanceInt;
        ma_uint32 inAdvanceFrac;
        ma_uint32 inTimeInt;
        ma_uint32 inTimeFrac;
        union {
            float* f32;
            ma_int16* s16;
        } x0; /* The previous input frame. */
        union {
            float* f32;
            ma_int16* s16;
        } x1; /* The next input frame. */
        ma_lpf lpf;
    
        /* Memory management. */
        void* _pHeap;
        ma_bool32 _ownsHeap;
    } ma_linear_resampler;

    typedef struct ma_resampler_config ma_resampler_config;

    typedef void ma_resampling_backend;
    typedef struct {
        ma_result (* onGetHeapSize                )(void* pUserData, const ma_resampler_config* pConfig, size_t* pHeapSizeInBytes);
        ma_result (* onInit                       )(void* pUserData, const ma_resampler_config* pConfig, void* pHeap, ma_resampling_backend** ppBackend);
        void      (* onUninit                     )(void* pUserData, ma_resampling_backend* pBackend, const ma_allocation_callbacks* pAllocationCallbacks);
        ma_result (* onProcess                    )(void* pUserData, ma_resampling_backend* pBackend, const void* pFramesIn, ma_uint64* pFrameCountIn, void* pFramesOut, ma_uint64* pFrameCountOut);
        ma_result (* onSetRate                    )(void* pUserData, ma_resampling_backend* pBackend, ma_uint32 sampleRateIn, ma_uint32 sampleRateOut);                 /* Optional. Rate changes will be disabled. */
        ma_uint64 (* onGetInputLatency            )(void* pUserData, const ma_resampling_backend* pBackend);                                                            /* Optional. Latency will be reported as 0. */
        ma_uint64 (* onGetOutputLatency           )(void* pUserData, const ma_resampling_backend* pBackend);                                                            /* Optional. Latency will be reported as 0. */
        ma_result (* onGetRequiredInputFrameCount )(void* pUserData, const ma_resampling_backend* pBackend, ma_uint64 outputFrameCount, ma_uint64* pInputFrameCount);   /* Optional. Latency mitigation will be disabled. */
        ma_result (* onGetExpectedOutputFrameCount)(void* pUserData, const ma_resampling_backend* pBackend, ma_uint64 inputFrameCount, ma_uint64* pOutputFrameCount);   /* Optional. Latency mitigation will be disabled. */
        ma_result (* onReset                      )(void* pUserData, ma_resampling_backend* pBackend);
    } ma_resampling_backend_vtable;

    typedef enum {
        ma_resample_algorithm_linear = 0,    /* Fastest, lowest quality. Optional low-pass filtering. Default. */
        ma_resample_algorithm_custom,
    } ma_resample_algorithm;

    struct ma_resampler_config {
        ma_format format;   /* Must be either ma_format_f32 or ma_format_s16. */
        ma_uint32 channels;
        ma_uint32 sampleRateIn;
        ma_uint32 sampleRateOut;
        ma_resample_algorithm algorithm;    /* When set to ma_resample_algorithm_custom, pBackendVTable will be used. */
        ma_resampling_backend_vtable* pBackendVTable;
        void* pBackendUserData;
        struct
        {
            ma_uint32 lpfOrder;
        } linear;
    };

    typedef struct {
        ma_resampling_backend* pBackend;
        ma_resampling_backend_vtable* pBackendVTable;
        void* pBackendUserData;
        ma_format format;
        ma_uint32 channels;
        ma_uint32 sampleRateIn;
        ma_uint32 sampleRateOut;
        union {
            ma_linear_resampler linear;
        } state;    /* State for stock resamplers so we can avoid a malloc. For stock resamplers, pBackend will point here. */

        /* Memory management. */
        void* _pHeap;
        ma_bool32 _ownsHeap;
    } ma_resampler;
]]

-- Channel Conversion

ffi.cdef[[
    typedef enum {
        ma_channel_conversion_path_unknown,
        ma_channel_conversion_path_passthrough,
        ma_channel_conversion_path_mono_out,    /* Converting to mono. */
        ma_channel_conversion_path_mono_in,     /* Converting from mono. */
        ma_channel_conversion_path_shuffle,     /* Simple shuffle. Will use this when all channels are present in both input and output channel maps, but just in a different order. */
        ma_channel_conversion_path_weights      /* Blended based on weights. */
    } ma_channel_conversion_path;
    
    typedef enum {
        ma_mono_expansion_mode_duplicate = 0,   /* The default. */
        ma_mono_expansion_mode_average,         /* Average the mono channel across all channels. */
        ma_mono_expansion_mode_stereo_only,     /* Duplicate to the left and right channels only and ignore the others. */
        ma_mono_expansion_mode_default = ma_mono_expansion_mode_duplicate
    } ma_mono_expansion_mode;
    
    typedef struct {
        ma_format format;
        ma_uint32 channelsIn;
        ma_uint32 channelsOut;
        const ma_channel* pChannelMapIn;
        const ma_channel* pChannelMapOut;
        ma_channel_mix_mode mixingMode;
        ma_bool32 calculateLFEFromSpatialChannels;  /* When an output LFE channel is present, but no input LFE, set to true to set the output LFE to the average of all spatial channels (LR, FR, etc.). Ignored when an input LFE is present. */
        float** ppWeights;  /* [in][out]. Only used when mixingMode is set to ma_channel_mix_mode_custom_weights. */
    } ma_channel_converter_config;
    
    typedef struct {
        ma_format format;
        ma_uint32 channelsIn;
        ma_uint32 channelsOut;
        ma_channel_mix_mode mixingMode;
        ma_channel_conversion_path conversionPath;
        ma_channel* pChannelMapIn;
        ma_channel* pChannelMapOut;
        ma_uint8* pShuffleTable;    /* Indexed by output channel index. */
        union {
            float**    f32;
            ma_int32** s16;
        } weights;  /* [in][out] */
    
        /* Memory management. */
        void* _pHeap;
        ma_bool32 _ownsHeap;
    } ma_channel_converter;
]]

-- Data Conversion

ffi.cdef[[
    typedef struct {
        ma_format formatIn;
        ma_format formatOut;
        ma_uint32 channelsIn;
        ma_uint32 channelsOut;
        ma_uint32 sampleRateIn;
        ma_uint32 sampleRateOut;
        ma_channel* pChannelMapIn;
        ma_channel* pChannelMapOut;
        ma_dither_mode ditherMode;
        ma_channel_mix_mode channelMixMode;
        ma_bool32 calculateLFEFromSpatialChannels;  /* When an output LFE channel is present, but no input LFE, set to true to set the output LFE to the average of all spatial channels (LR, FR, etc.). Ignored when an input LFE is present. */
        float** ppChannelWeights;  /* [in][out]. Only used when mixingMode is set to ma_channel_mix_mode_custom_weights. */
        ma_bool32 allowDynamicSampleRate;
        ma_resampler_config resampling;
    } ma_data_converter_config;
    
    typedef enum {
        ma_data_converter_execution_path_passthrough,       /* No conversion. */
        ma_data_converter_execution_path_format_only,       /* Only format conversion. */
        ma_data_converter_execution_path_channels_only,     /* Only channel conversion. */
        ma_data_converter_execution_path_resample_only,     /* Only resampling. */
        ma_data_converter_execution_path_resample_first,    /* All conversions, but resample as the first step. */
        ma_data_converter_execution_path_channels_first     /* All conversions, but channels as the first step. */
    } ma_data_converter_execution_path;
    
    typedef struct {
        ma_format formatIn;
        ma_format formatOut;
        ma_uint32 channelsIn;
        ma_uint32 channelsOut;
        ma_uint32 sampleRateIn;
        ma_uint32 sampleRateOut;
        ma_dither_mode ditherMode;
        ma_data_converter_execution_path executionPath; /* The execution path the data converter will follow when processing. */
        ma_channel_converter channelConverter;
        ma_resampler resampler;
        ma_bool8 hasPreFormatConversion;
        ma_bool8 hasPostFormatConversion;
        ma_bool8 hasChannelConverter;
        ma_bool8 hasResampler;
        ma_bool8 isPassthrough;
    
        /* Memory management. */
        ma_bool8 _ownsHeap;
        void* _pHeap;
    } ma_data_converter;
]]

-- Format Conversion

-- Channel Maps

-- Conversion Helpers

-- Data Source

ffi.cdef[[
    typedef void ma_data_source;

    typedef struct {
        ma_result (* onRead)(ma_data_source* pDataSource, void* pFramesOut, ma_uint64 frameCount, ma_uint64* pFramesRead);
        ma_result (* onSeek)(ma_data_source* pDataSource, ma_uint64 frameIndex);
        ma_result (* onGetDataFormat)(ma_data_source* pDataSource, ma_format* pFormat, ma_uint32* pChannels, ma_uint32* pSampleRate, ma_channel* pChannelMap, size_t channelMapCap);
        ma_result (* onGetCursor)(ma_data_source* pDataSource, ma_uint64* pCursor);
        ma_result (* onGetLength)(ma_data_source* pDataSource, ma_uint64* pLength);
        ma_result (* onSetLooping)(ma_data_source* pDataSource, ma_bool32 isLooping);
        ma_uint32 flags;
    } ma_data_source_vtable;
    
    typedef ma_data_source* (* ma_data_source_get_next_proc)(ma_data_source* pDataSource);
    
    typedef struct {
        const ma_data_source_vtable* vtable;
    } ma_data_source_config;

    typedef struct {
        const ma_data_source_vtable* vtable;
        ma_uint64 rangeBegInFrames;
        ma_uint64 rangeEndInFrames;             /* Set to -1 for unranged (default). */
        ma_uint64 loopBegInFrames;              /* Relative to rangeBegInFrames. */
        ma_uint64 loopEndInFrames;              /* Relative to rangeBegInFrames. Set to -1 for the end of the range. */
        ma_data_source* pCurrent;               /* When non-NULL, the data source being initialized will act as a proxy and will route all operations to pCurrent. Used in conjunction with pNext/onGetNext for seamless chaining. */
        ma_data_source* pNext;                  /* When set to NULL, onGetNext will be used. */
        ma_data_source_get_next_proc onGetNext; /* Will be used when pNext is NULL. If both are NULL, no next will be used. */
        ma_bool32 isLooping;
    } ma_data_source_base;
    
    typedef struct {
        ma_data_source_base ds;
        ma_format format;
        ma_uint32 channels;
        ma_uint32 sampleRate;
        ma_uint64 cursor;
        ma_uint64 sizeInFrames;
        const void* pData;
    } ma_audio_buffer_ref;
    
    typedef struct {
        ma_format format;
        ma_uint32 channels;
        ma_uint32 sampleRate;
        ma_uint64 sizeInFrames;
        const void* pData;  /* If set to NULL, will allocate a block of memory for you. */
        ma_allocation_callbacks allocationCallbacks;
    } ma_audio_buffer_config;
    
    typedef struct {
        ma_audio_buffer_ref ref;
        ma_allocation_callbacks allocationCallbacks;
        ma_bool32 ownsData;             /* Used to control whether or not miniaudio owns the data buffer. If set to true, pData will be freed in ma_audio_buffer_uninit(). */
        ma_uint8 _pExtraData[1];        /* For allocating a buffer with the memory located directly after the other memory of the structure. */
    } ma_audio_buffer;
]]

-- Paged Audio Buffer

ffi.cdef[[
    typedef struct ma_paged_audio_buffer_page ma_paged_audio_buffer_page;
    struct ma_paged_audio_buffer_page {
        ma_paged_audio_buffer_page* pNext;
        ma_uint64 sizeInFrames;
        ma_uint8 pAudioData[1];
    };
    
    typedef struct {
        ma_format format;
        ma_uint32 channels;
        ma_paged_audio_buffer_page head;                                /* Dummy head for the lock-free algorithm. Always has a size of 0. */
        ma_paged_audio_buffer_page* pTail;    /* Never null. Initially set to &head. */
    } ma_paged_audio_buffer_data;
    
    typedef struct {
        ma_paged_audio_buffer_data* pData;  /* Must not be null. */
    } ma_paged_audio_buffer_config;
    
    typedef struct {
        ma_data_source_base ds;
        ma_paged_audio_buffer_data* pData;              /* Audio data is read from here. Cannot be null. */
        ma_paged_audio_buffer_page* pCurrent;
        ma_uint64 relativeCursor;                       /* Relative to the current page. */
        ma_uint64 absoluteCursor;
    } ma_paged_audio_buffer;
]]

-- Ring Buffer

ffi.cdef[[
    typedef struct {
        void* pBuffer;
        ma_uint32 subbufferSizeInBytes;
        ma_uint32 subbufferCount;
        ma_uint32 subbufferStrideInBytes;
        ma_uint32 encodedReadOffset;  /* Most significant bit is the loop flag. Lower 31 bits contains the actual offset in bytes. Must be used atomically. */
        ma_uint32 encodedWriteOffset; /* Most significant bit is the loop flag. Lower 31 bits contains the actual offset in bytes. Must be used atomically. */
        ma_bool8 ownsBuffer;                        /* Used to know whether or not miniaudio is responsible for free()-ing the buffer. */
        ma_bool8 clearOnWriteAcquire;               /* When set, clears the acquired write buffer before returning from ma_rb_acquire_write(). */
        ma_allocation_callbacks allocationCallbacks;
    } ma_rb;
    
    typedef struct {
        ma_data_source_base ds;
        ma_rb rb;
        ma_format format;
        ma_uint32 channels;
        ma_uint32 sampleRate; /* Not required for the ring buffer itself, but useful for associating the data with some sample rate, particularly for data sources. */
    } ma_pcm_rb;

    /*
    The idea of the duplex ring buffer is to act as the intermediary buffer when running two asynchronous devices in a duplex set up. The
    capture device writes to it, and then a playback device reads from it.
    
    At the moment this is just a simple naive implementation, but in the future I want to implement some dynamic resampling to seamlessly
    handle desyncs. Note that the API is work in progress and may change at any time in any version.
    
    The size of the buffer is based on the capture side since that's what'll be written to the buffer. It is based on the capture period size
    in frames. The internal sample rate of the capture device is also needed in order to calculate the size.
    */
    typedef struct {
        ma_pcm_rb rb;
    } ma_duplex_rb;
]]

-- Miscellaneous Helpers

-- Synchronization

-- Fence

ffi.cdef[[
    typedef struct {
        ma_event e;
        ma_uint32 counter;
    } ma_fence;
]]

-- Notification callback

ffi.cdef[[
    typedef void ma_async_notification;

    typedef struct {
        void (* onSignal)(ma_async_notification* pNotification);
    } ma_async_notification_callbacks;
]]


-- Simple polling notification

ffi.cdef[[
    typedef struct {
        ma_async_notification_callbacks cb;
        ma_bool32 signalled;
    } ma_async_notification_poll;
]]

-- Event Notification

ffi.cdef[[
    typedef struct {
        ma_async_notification_callbacks cb;
        ma_event e;
    } ma_async_notification_event;
]]

-- Slot Allocator

ffi.cdef[[
    typedef struct {
        ma_uint32 capacity;    /* The number of slots to make available. */
    } ma_slot_allocator_config;
    
    typedef struct {
        ma_uint32 bitfield;   /* Must be used atomically because the allocation and freeing routines need to make copies of this which must never be optimized away by the compiler. */
    } ma_slot_allocator_group;
    
    typedef struct {
        ma_slot_allocator_group* pGroups;   /* Slots are grouped in chunks of 32. */
        ma_uint32* pSlots;                  /* 32 bits for reference counting for ABA mitigation. */
        ma_uint32 count;                    /* Allocation count. */
        ma_uint32 capacity;
    
        /* Memory management. */
        ma_bool32 _ownsHeap;
        void* _pHeap;
    } ma_slot_allocator;
    
    typedef struct ma_job ma_job;
    
    /*
    Callback for processing a job. Each job type will have their own processing callback which will be
    called by ma_job_process().
    */
    typedef ma_result (* ma_job_proc)(ma_job* pJob);
    
    /* When a job type is added here an callback needs to be added go "g_jobVTable" in the implementation section. */
    typedef enum {
        /* Miscellaneous. */
        MA_JOB_TYPE_QUIT = 0,
        MA_JOB_TYPE_CUSTOM,
    
        /* Resource Manager. */
        MA_JOB_TYPE_RESOURCE_MANAGER_LOAD_DATA_BUFFER_NODE,
        MA_JOB_TYPE_RESOURCE_MANAGER_FREE_DATA_BUFFER_NODE,
        MA_JOB_TYPE_RESOURCE_MANAGER_PAGE_DATA_BUFFER_NODE,
        MA_JOB_TYPE_RESOURCE_MANAGER_LOAD_DATA_BUFFER,
        MA_JOB_TYPE_RESOURCE_MANAGER_FREE_DATA_BUFFER,
        MA_JOB_TYPE_RESOURCE_MANAGER_LOAD_DATA_STREAM,
        MA_JOB_TYPE_RESOURCE_MANAGER_FREE_DATA_STREAM,
        MA_JOB_TYPE_RESOURCE_MANAGER_PAGE_DATA_STREAM,
        MA_JOB_TYPE_RESOURCE_MANAGER_SEEK_DATA_STREAM,
    
        /* Device. */
        MA_JOB_TYPE_DEVICE_AAUDIO_REROUTE,
    
        /* Count. Must always be last. */
        MA_JOB_TYPE_COUNT
    } ma_job_type;
    
    struct ma_job {
        union {
            struct {
                ma_uint16 code;         /* Job type. */
                ma_uint16 slot;         /* Index into a ma_slot_allocator. */
                ma_uint32 refcount;
            } breakup;
            ma_uint64 allocation;
        } toc;  /* 8 bytes. We encode the job code into the slot allocation data to save space. */
        ma_uint64 next; /* refcount + slot for the next item. Does not include the job code. */
        ma_uint32 order;    /* Execution order. Used to create a data dependency and ensure a job is executed in order. Usage is contextual depending on the job type. */
    
        union {
            /* Miscellaneous. */
            struct {
                ma_job_proc proc;
                ma_uintptr data0;
                ma_uintptr data1;
            } custom;
    
            /* Resource Manager */
            union {
                struct {
                    /*ma_resource_manager**/ void* pResourceManager;
                    /*ma_resource_manager_data_buffer_node**/ void* pDataBufferNode;
                    char* pFilePath;
                    wchar_t* pFilePathW;
                    ma_uint32 flags;                                /* Resource manager data source flags that were used when initializing the data buffer. */
                    ma_async_notification* pInitNotification;       /* Signalled when the data buffer has been initialized and the format/channels/rate can be retrieved. */
                    ma_async_notification* pDoneNotification;       /* Signalled when the data buffer has been fully decoded. Will be passed through to MA_JOB_TYPE_RESOURCE_MANAGER_PAGE_DATA_BUFFER_NODE when decoding. */
                    ma_fence* pInitFence;                           /* Released when initialization of the decoder is complete. */
                    ma_fence* pDoneFence;                           /* Released if initialization of the decoder fails. Passed through to PAGE_DATA_BUFFER_NODE untouched if init is successful. */
                } loadDataBufferNode;
                struct {
                    /*ma_resource_manager**/ void* pResourceManager;
                    /*ma_resource_manager_data_buffer_node**/ void* pDataBufferNode;
                    ma_async_notification* pDoneNotification;
                    ma_fence* pDoneFence;
                } freeDataBufferNode;
                struct {
                    /*ma_resource_manager**/ void* pResourceManager;
                    /*ma_resource_manager_data_buffer_node**/ void* pDataBufferNode;
                    /*ma_decoder**/ void* pDecoder;
                    ma_async_notification* pDoneNotification;       /* Signalled when the data buffer has been fully decoded. */
                    ma_fence* pDoneFence;                           /* Passed through from LOAD_DATA_BUFFER_NODE and released when the data buffer completes decoding or an error occurs. */
                } pageDataBufferNode;
    
                struct {
                    /*ma_resource_manager_data_buffer**/ void* pDataBuffer;
                    ma_async_notification* pInitNotification;       /* Signalled when the data buffer has been initialized and the format/channels/rate can be retrieved. */
                    ma_async_notification* pDoneNotification;       /* Signalled when the data buffer has been fully decoded. */
                    ma_fence* pInitFence;                           /* Released when the data buffer has been initialized and the format/channels/rate can be retrieved. */
                    ma_fence* pDoneFence;                           /* Released when the data buffer has been fully decoded. */
                    ma_uint64 rangeBegInPCMFrames;
                    ma_uint64 rangeEndInPCMFrames;
                    ma_uint64 loopPointBegInPCMFrames;
                    ma_uint64 loopPointEndInPCMFrames;
                    ma_uint32 isLooping;
                } loadDataBuffer;
                struct {
                    /*ma_resource_manager_data_buffer**/ void* pDataBuffer;
                    ma_async_notification* pDoneNotification;
                    ma_fence* pDoneFence;
                } freeDataBuffer;
    
                struct {
                    /*ma_resource_manager_data_stream**/ void* pDataStream;
                    char* pFilePath;                            /* Allocated when the job is posted, freed by the job thread after loading. */
                    wchar_t* pFilePathW;                        /* ^ As above ^. Only used if pFilePath is NULL. */
                    ma_uint64 initialSeekPoint;
                    ma_async_notification* pInitNotification;   /* Signalled after the first two pages have been decoded and frames can be read from the stream. */
                    ma_fence* pInitFence;
                } loadDataStream;
                struct {
                    /*ma_resource_manager_data_stream**/ void* pDataStream;
                    ma_async_notification* pDoneNotification;
                    ma_fence* pDoneFence;
                } freeDataStream;
                struct {
                    /*ma_resource_manager_data_stream**/ void* pDataStream;
                    ma_uint32 pageIndex;                    /* The index of the page to decode into. */
                } pageDataStream;
                struct {
                    /*ma_resource_manager_data_stream**/ void* pDataStream;
                    ma_uint64 frameIndex;
                } seekDataStream;
            } resourceManager;
    
            /* Device. */
            union {
                union {
                    struct {
                        /*ma_device**/ void* pDevice;
                        /*ma_device_type*/ ma_uint32 deviceType;
                    } reroute;
                } aaudio;
            } device;
        } data;
    };
    
    /*
    When set, ma_job_queue_next() will not wait and no semaphore will be signaled in
    ma_job_queue_post(). ma_job_queue_next() will return MA_NO_DATA_AVAILABLE if nothing is available.
    
    This flag should always be used for platforms that do not support multithreading.
    */
    typedef enum {
        MA_JOB_QUEUE_FLAG_NON_BLOCKING = 0x00000001
    } ma_job_queue_flags;
    
    typedef struct {
        ma_uint32 flags;
        ma_uint32 capacity; /* The maximum number of jobs that can fit in the queue at a time. */
    } ma_job_queue_config;
    
    typedef struct {
        ma_uint32 flags;                /* Flags passed in at initialization time. */
        ma_uint32 capacity;             /* The maximum number of jobs that can fit in the queue at a time. Set by the config. */
        ma_uint64 head;   /* The first item in the list. Required for removing from the top of the list. */
        ma_uint64 tail;   /* The last item in the list. Required for appending to the end of the list. */
        ma_semaphore sem;               /* Only used when MA_JOB_QUEUE_FLAG_NON_BLOCKING is unset. */
        ma_slot_allocator allocator;
        ma_job* pJobs;
        ma_spinlock lock;
    
        /* Memory management. */
        void* _pHeap;
        ma_bool32 _ownsHeap;
    } ma_job_queue;
]]

-- DEVICE I/O

ffi.cdef[[
    typedef enum {
        ma_device_state_uninitialized = 0,
        ma_device_state_stopped       = 1,  /* The device's default state after initialization. */
        ma_device_state_started       = 2,  /* The device is started and is requesting and/or delivering audio data. */
        ma_device_state_starting      = 3,  /* Transitioning from a stopped state to started. */
        ma_device_state_stopping      = 4   /* Transitioning from a started state to stopped. */
    } ma_device_state;

    typedef struct {
        ma_device_state value;
    } ma_atomic_device_state;


]]

if raia.os.isWindows() == true then
    ffi.cdef[[
        typedef struct {
            void* lpVtbl;
            ma_uint32 counter;
            ma_device* pDevice;
        } ma_IMMNotificationClient;
    ]]
end

ffi.cdef[[
    /* Backend enums must be in priority order. */
    typedef enum {
        ma_backend_wasapi,
        ma_backend_dsound,
        ma_backend_winmm,
        ma_backend_coreaudio,
        ma_backend_sndio,
        ma_backend_audio4,
        ma_backend_oss,
        ma_backend_pulseaudio,
        ma_backend_alsa,
        ma_backend_jack,
        ma_backend_aaudio,
        ma_backend_opensl,
        ma_backend_webaudio,
        ma_backend_custom,  /* <-- Custom backend, with callbacks defined by the context config. */
        ma_backend_null     /* <-- Must always be the last item. Lowest priority, and used as the terminator for backend enumeration. */
    } ma_backend;

    /*
    Device job thread. This is used by backends that require asynchronous processing of certain
    operations. It is not used by all backends.

    The device job thread is made up of a thread and a job queue. You can post a job to the thread with
    ma_device_job_thread_post(). The thread will do the processing of the job.
    */
    typedef struct {
        ma_bool32 noThread; /* Set this to true if you want to process jobs yourself. */
        ma_uint32 jobQueueCapacity;
        ma_uint32 jobQueueFlags;
    } ma_device_job_thread_config;

    typedef struct {
        ma_thread thread;
        ma_job_queue jobQueue;
        ma_bool32 _hasThread;
    } ma_device_job_thread;

    /* Device notification types. */
    typedef enum {
        ma_device_notification_type_started,
        ma_device_notification_type_stopped,
        ma_device_notification_type_rerouted,
        ma_device_notification_type_interruption_began,
        ma_device_notification_type_interruption_ended,
        ma_device_notification_type_unlocked
    } ma_device_notification_type;

    typedef struct {
        ma_device* pDevice;
        ma_device_notification_type type;
        union {
            struct {
                int _unused;
            } started;
            struct {
                int _unused;
            } stopped;
            struct {
                int _unused;
            } rerouted;
            struct {
                int _unused;
            } interruption;
        } data;
    } ma_device_notification;

    /*
    The notification callback for when the application should be notified of a change to the device.

    This callback is used for notifying the application of changes such as when the device has started,
    stopped, rerouted or an interruption has occurred. Note that not all backends will post all
    notification types. For example, some backends will perform automatic stream routing without any
    kind of notification to the host program which means miniaudio will never know about it and will
    never be able to fire the rerouted notification. You should keep this in mind when designing your
    program.

    The stopped notification will *not* get fired when a device is rerouted.


    Parameters
    ----------
    pNotification (in)
        A pointer to a structure containing information about the event. Use the `pDevice` member of
        this object to retrieve the relevant device. The `type` member can be used to discriminate
        against each of the notification types.


    Remarks
    -------
    Do not restart or uninitialize the device from the callback.

    Not all notifications will be triggered by all backends, however the started and stopped events
    should be reliable for all backends. Some backends do not have a good way to detect device
    stoppages due to unplugging the device which may result in the stopped callback not getting
    fired. This has been observed with at least one BSD variant.

    The rerouted notification is fired *after* the reroute has occurred. The stopped notification will
    *not* get fired when a device is rerouted. The following backends are known to do automatic stream
    rerouting, but do not have a way to be notified of the change:

    * DirectSound

    The interruption notifications are used on mobile platforms for detecting when audio is interrupted
    due to things like an incoming phone call. Currently this is only implemented on iOS. None of the
    Android backends will report this notification.
    */
    typedef void (* ma_device_notification_proc)(const ma_device_notification* pNotification);


    /*
    The callback for processing audio data from the device.

    The data callback is fired by miniaudio whenever the device needs to have more data delivered to a playback device, or when a capture device has some data
    available. This is called as soon as the backend asks for more data which means it may be called with inconsistent frame counts. You cannot assume the
    callback will be fired with a consistent frame count.


    Parameters
    ----------
    pDevice (in)
        A pointer to the relevant device.

    pOutput (out)
        A pointer to the output buffer that will receive audio data that will later be played back through the speakers. This will be non-null for a playback or
        full-duplex device and null for a capture and loopback device.

    pInput (in)
        A pointer to the buffer containing input data from a recording device. This will be non-null for a capture, full-duplex or loopback device and null for a
        playback device.

    frameCount (in)
        The number of PCM frames to process. Note that this will not necessarily be equal to what you requested when you initialized the device. The
        `periodSizeInFrames` and `periodSizeInMilliseconds` members of the device config are just hints, and are not necessarily exactly what you'll get. You must
        not assume this will always be the same value each time the callback is fired.


    Remarks
    -------
    You cannot stop and start the device from inside the callback or else you'll get a deadlock. You must also not uninitialize the device from inside the
    callback. The following APIs cannot be called from inside the callback:

        ma_device_init()
        ma_device_init_ex()
        ma_device_uninit()
        ma_device_start()
        ma_device_stop()

    The proper way to stop the device is to call `ma_device_stop()` from a different thread, normally the main application thread.
    */
    typedef void (* ma_device_data_proc)(ma_device* pDevice, void* pOutput, const void* pInput, ma_uint32 frameCount);

    /*
    DEPRECATED. Use ma_device_notification_proc instead.

    The callback for when the device has been stopped.

    This will be called when the device is stopped explicitly with `ma_device_stop()` and also called implicitly when the device is stopped through external forces
    such as being unplugged or an internal error occurring.


    Parameters
    ----------
    pDevice (in)
        A pointer to the device that has just stopped.


    Remarks
    -------
    Do not restart or uninitialize the device from the callback.
    */
    typedef void (* ma_stop_proc)(ma_device* pDevice);  /* DEPRECATED. Use ma_device_notification_proc instead. */

    typedef enum {
        ma_device_type_playback = 1,
        ma_device_type_capture  = 2,
        ma_device_type_duplex   = ma_device_type_playback | ma_device_type_capture, /* 3 */
        ma_device_type_loopback = 4
    } ma_device_type;

    typedef enum {
        ma_share_mode_shared = 0,
        ma_share_mode_exclusive
    } ma_share_mode;

    /* iOS/tvOS/watchOS session categories. */
    typedef enum {
        ma_ios_session_category_default = 0,        /* AVAudioSessionCategoryPlayAndRecord. */
        ma_ios_session_category_none,               /* Leave the session category unchanged. */
        ma_ios_session_category_ambient,            /* AVAudioSessionCategoryAmbient */
        ma_ios_session_category_solo_ambient,       /* AVAudioSessionCategorySoloAmbient */
        ma_ios_session_category_playback,           /* AVAudioSessionCategoryPlayback */
        ma_ios_session_category_record,             /* AVAudioSessionCategoryRecord */
        ma_ios_session_category_play_and_record,    /* AVAudioSessionCategoryPlayAndRecord */
        ma_ios_session_category_multi_route         /* AVAudioSessionCategoryMultiRoute */
    } ma_ios_session_category;

    /* iOS/tvOS/watchOS session category options */
    typedef enum {
        ma_ios_session_category_option_mix_with_others                            = 0x01,   /* AVAudioSessionCategoryOptionMixWithOthers */
        ma_ios_session_category_option_duck_others                                = 0x02,   /* AVAudioSessionCategoryOptionDuckOthers */
        ma_ios_session_category_option_allow_bluetooth                            = 0x04,   /* AVAudioSessionCategoryOptionAllowBluetooth */
        ma_ios_session_category_option_default_to_speaker                         = 0x08,   /* AVAudioSessionCategoryOptionDefaultToSpeaker */
        ma_ios_session_category_option_interrupt_spoken_audio_and_mix_with_others = 0x11,   /* AVAudioSessionCategoryOptionInterruptSpokenAudioAndMixWithOthers */
        ma_ios_session_category_option_allow_bluetooth_a2dp                       = 0x20,   /* AVAudioSessionCategoryOptionAllowBluetoothA2DP */
        ma_ios_session_category_option_allow_air_play                             = 0x40,   /* AVAudioSessionCategoryOptionAllowAirPlay */
    } ma_ios_session_category_option;

    /* OpenSL stream types. */
    typedef enum {
        ma_opensl_stream_type_default = 0,              /* Leaves the stream type unset. */
        ma_opensl_stream_type_voice,                    /* SL_ANDROID_STREAM_VOICE */
        ma_opensl_stream_type_system,                   /* SL_ANDROID_STREAM_SYSTEM */
        ma_opensl_stream_type_ring,                     /* SL_ANDROID_STREAM_RING */
        ma_opensl_stream_type_media,                    /* SL_ANDROID_STREAM_MEDIA */
        ma_opensl_stream_type_alarm,                    /* SL_ANDROID_STREAM_ALARM */
        ma_opensl_stream_type_notification              /* SL_ANDROID_STREAM_NOTIFICATION */
    } ma_opensl_stream_type;

    /* OpenSL recording presets. */
    typedef enum {
        ma_opensl_recording_preset_default = 0,         /* Leaves the input preset unset. */
        ma_opensl_recording_preset_generic,             /* SL_ANDROID_RECORDING_PRESET_GENERIC */
        ma_opensl_recording_preset_camcorder,           /* SL_ANDROID_RECORDING_PRESET_CAMCORDER */
        ma_opensl_recording_preset_voice_recognition,   /* SL_ANDROID_RECORDING_PRESET_VOICE_RECOGNITION */
        ma_opensl_recording_preset_voice_communication, /* SL_ANDROID_RECORDING_PRESET_VOICE_COMMUNICATION */
        ma_opensl_recording_preset_voice_unprocessed    /* SL_ANDROID_RECORDING_PRESET_UNPROCESSED */
    } ma_opensl_recording_preset;

    /* WASAPI audio thread priority characteristics. */
    typedef enum {
        ma_wasapi_usage_default = 0,
        ma_wasapi_usage_games,
        ma_wasapi_usage_pro_audio,
    } ma_wasapi_usage;

    /* AAudio usage types. */
    typedef enum {
        ma_aaudio_usage_default = 0,                    /* Leaves the usage type unset. */
        ma_aaudio_usage_media,                          /* AAUDIO_USAGE_MEDIA */
        ma_aaudio_usage_voice_communication,            /* AAUDIO_USAGE_VOICE_COMMUNICATION */
        ma_aaudio_usage_voice_communication_signalling, /* AAUDIO_USAGE_VOICE_COMMUNICATION_SIGNALLING */
        ma_aaudio_usage_alarm,                          /* AAUDIO_USAGE_ALARM */
        ma_aaudio_usage_notification,                   /* AAUDIO_USAGE_NOTIFICATION */
        ma_aaudio_usage_notification_ringtone,          /* AAUDIO_USAGE_NOTIFICATION_RINGTONE */
        ma_aaudio_usage_notification_event,             /* AAUDIO_USAGE_NOTIFICATION_EVENT */
        ma_aaudio_usage_assistance_accessibility,       /* AAUDIO_USAGE_ASSISTANCE_ACCESSIBILITY */
        ma_aaudio_usage_assistance_navigation_guidance, /* AAUDIO_USAGE_ASSISTANCE_NAVIGATION_GUIDANCE */
        ma_aaudio_usage_assistance_sonification,        /* AAUDIO_USAGE_ASSISTANCE_SONIFICATION */
        ma_aaudio_usage_game,                           /* AAUDIO_USAGE_GAME */
        ma_aaudio_usage_assitant,                       /* AAUDIO_USAGE_ASSISTANT */
        ma_aaudio_usage_emergency,                      /* AAUDIO_SYSTEM_USAGE_EMERGENCY */
        ma_aaudio_usage_safety,                         /* AAUDIO_SYSTEM_USAGE_SAFETY */
        ma_aaudio_usage_vehicle_status,                 /* AAUDIO_SYSTEM_USAGE_VEHICLE_STATUS */
        ma_aaudio_usage_announcement                    /* AAUDIO_SYSTEM_USAGE_ANNOUNCEMENT */
    } ma_aaudio_usage;

    /* AAudio content types. */
    typedef enum {
        ma_aaudio_content_type_default = 0,             /* Leaves the content type unset. */
        ma_aaudio_content_type_speech,                  /* AAUDIO_CONTENT_TYPE_SPEECH */
        ma_aaudio_content_type_music,                   /* AAUDIO_CONTENT_TYPE_MUSIC */
        ma_aaudio_content_type_movie,                   /* AAUDIO_CONTENT_TYPE_MOVIE */
        ma_aaudio_content_type_sonification             /* AAUDIO_CONTENT_TYPE_SONIFICATION */
    } ma_aaudio_content_type;

    /* AAudio input presets. */
    typedef enum {
        ma_aaudio_input_preset_default = 0,             /* Leaves the input preset unset. */
        ma_aaudio_input_preset_generic,                 /* AAUDIO_INPUT_PRESET_GENERIC */
        ma_aaudio_input_preset_camcorder,               /* AAUDIO_INPUT_PRESET_CAMCORDER */
        ma_aaudio_input_preset_voice_recognition,       /* AAUDIO_INPUT_PRESET_VOICE_RECOGNITION */
        ma_aaudio_input_preset_voice_communication,     /* AAUDIO_INPUT_PRESET_VOICE_COMMUNICATION */
        ma_aaudio_input_preset_unprocessed,             /* AAUDIO_INPUT_PRESET_UNPROCESSED */
        ma_aaudio_input_preset_voice_performance        /* AAUDIO_INPUT_PRESET_VOICE_PERFORMANCE */
    } ma_aaudio_input_preset;

    typedef enum {
        ma_aaudio_allow_capture_default = 0,            /* Leaves the allowed capture policy unset. */
        ma_aaudio_allow_capture_by_all,                 /* AAUDIO_ALLOW_CAPTURE_BY_ALL */
        ma_aaudio_allow_capture_by_system,              /* AAUDIO_ALLOW_CAPTURE_BY_SYSTEM */
        ma_aaudio_allow_capture_by_none                 /* AAUDIO_ALLOW_CAPTURE_BY_NONE */
    } ma_aaudio_allowed_capture_policy;

    typedef union {
        ma_int64 counter;
        double counterD;
    } ma_timer;

    typedef union {
        ma_wchar_win32 wasapi[64];      /* WASAPI uses a wchar_t string for identification. */
        ma_uint8 dsound[16];            /* DirectSound uses a GUID for identification. */
        /*UINT_PTR*/ ma_uint32 winmm;   /* When creating a device, WinMM expects a Win32 UINT_PTR for device identification. In practice it's actually just a UINT. */
        char alsa[256];                 /* ALSA uses a name string for identification. */
        char pulse[256];                /* PulseAudio uses a name string for identification. */
        int jack;                       /* JACK always uses default devices. */
        char coreaudio[256];            /* Core Audio uses a string for identification. */
        char sndio[256];                /* "snd/0", etc. */
        char audio4[256];               /* "/dev/audio", etc. */
        char oss[64];                   /* "dev/dsp0", etc. "dev/dsp" for the default device. */
        ma_int32 aaudio;                /* AAudio uses a 32-bit integer for identification. */
        ma_uint32 opensl;               /* OpenSL|ES uses a 32-bit unsigned integer for identification. */
        char webaudio[32];              /* Web Audio always uses default devices for now, but if this changes it'll be a GUID. */
        union {
            int i;
            char s[256];
            void* p;
        } custom;                       /* The custom backend could be anything. Give them a few options. */
        int nullbackend;                /* The null backend uses an integer for device IDs. */
    } ma_device_id;

    typedef struct ma_context_config    ma_context_config;
    typedef struct ma_device_config     ma_device_config;
    typedef struct ma_backend_callbacks ma_backend_callbacks;

    typedef struct {
        /* Basic info. This is the only information guaranteed to be filled in during device enumeration. */
        ma_device_id id;
        char name[255 + 1];   /* +1 for null terminator. */
        ma_bool32 isDefault;

        ma_uint32 nativeDataFormatCount;
        struct {
            ma_format format;       /* Sample format. If set to ma_format_unknown, all sample formats are supported. */
            ma_uint32 channels;     /* If set to 0, all channels are supported. */
            ma_uint32 sampleRate;   /* If set to 0, all sample rates are supported. */
            ma_uint32 flags;        /* A combination of MA_DATA_FORMAT_FLAG_* flags. */
        } nativeDataFormats[/*ma_format_count * ma_standard_sample_rate_count * MA_MAX_CHANNELS*/ 64];  /* Not sure how big to make this. There can be *many* permutations for virtual devices which can support anything. */
    } ma_device_info;

    struct ma_device_config {
        ma_device_type deviceType;
        ma_uint32 sampleRate;
        ma_uint32 periodSizeInFrames;
        ma_uint32 periodSizeInMilliseconds;
        ma_uint32 periods;
        ma_performance_profile performanceProfile;
        ma_bool8 noPreSilencedOutputBuffer; /* When set to true, the contents of the output buffer passed into the data callback will be left undefined rather than initialized to silence. */
        ma_bool8 noClip;                    /* When set to true, the contents of the output buffer passed into the data callback will not be clipped after returning. Only applies when the playback sample format is f32. */
        ma_bool8 noDisableDenormals;        /* Do not disable denormals when firing the data callback. */
        ma_bool8 noFixedSizedCallback;      /* Disables strict fixed-sized data callbacks. Setting this to true will result in the period size being treated only as a hint to the backend. This is an optimization for those who don't need fixed sized callbacks. */
        ma_device_data_proc dataCallback;
        ma_device_notification_proc notificationCallback;
        ma_stop_proc stopCallback;
        void* pUserData;
        ma_resampler_config resampling;
        struct {
            const ma_device_id* pDeviceID;
            ma_format format;
            ma_uint32 channels;
            ma_channel* pChannelMap;
            ma_channel_mix_mode channelMixMode;
            ma_bool32 calculateLFEFromSpatialChannels;  /* When an output LFE channel is present, but no input LFE, set to true to set the output LFE to the average of all spatial channels (LR, FR, etc.). Ignored when an input LFE is present. */
            ma_share_mode shareMode;
        } playback;
        struct {
            const ma_device_id* pDeviceID;
            ma_format format;
            ma_uint32 channels;
            ma_channel* pChannelMap;
            ma_channel_mix_mode channelMixMode;
            ma_bool32 calculateLFEFromSpatialChannels;  /* When an output LFE channel is present, but no input LFE, set to true to set the output LFE to the average of all spatial channels (LR, FR, etc.). Ignored when an input LFE is present. */
            ma_share_mode shareMode;
        } capture;

        struct {
            ma_wasapi_usage usage;              /* When configured, uses Avrt APIs to set the thread characteristics. */
            ma_bool8 noAutoConvertSRC;          /* When set to true, disables the use of AUDCLNT_STREAMFLAGS_AUTOCONVERTPCM. */
            ma_bool8 noDefaultQualitySRC;       /* When set to true, disables the use of AUDCLNT_STREAMFLAGS_SRC_DEFAULT_QUALITY. */
            ma_bool8 noAutoStreamRouting;       /* Disables automatic stream routing. */
            ma_bool8 noHardwareOffloading;      /* Disables WASAPI's hardware offloading feature. */
            ma_uint32 loopbackProcessID;        /* The process ID to include or exclude for loopback mode. Set to 0 to capture audio from all processes. Ignored when an explicit device ID is specified. */
            ma_bool8 loopbackProcessExclude;    /* When set to true, excludes the process specified by loopbackProcessID. By default, the process will be included. */
        } wasapi;
        struct {
            ma_bool32 noMMap;           /* Disables MMap mode. */
            ma_bool32 noAutoFormat;     /* Opens the ALSA device with SND_PCM_NO_AUTO_FORMAT. */
            ma_bool32 noAutoChannels;   /* Opens the ALSA device with SND_PCM_NO_AUTO_CHANNELS. */
            ma_bool32 noAutoResample;   /* Opens the ALSA device with SND_PCM_NO_AUTO_RESAMPLE. */
        } alsa;
        struct {
            const char* pStreamNamePlayback;
            const char* pStreamNameCapture;
        } pulse;
        struct {
            ma_bool32 allowNominalSampleRateChange; /* Desktop only. When enabled, allows changing of the sample rate at the operating system level. */
        } coreaudio;
        struct {
            ma_opensl_stream_type streamType;
            ma_opensl_recording_preset recordingPreset;
            ma_bool32 enableCompatibilityWorkarounds;
        } opensl;
        struct {
            ma_aaudio_usage usage;
            ma_aaudio_content_type contentType;
            ma_aaudio_input_preset inputPreset;
            ma_aaudio_allowed_capture_policy allowedCapturePolicy;
            ma_bool32 noAutoStartAfterReroute;
            ma_bool32 enableCompatibilityWorkarounds;
        } aaudio;
    };


    /*
    The callback for handling device enumeration. This is fired from `ma_context_enumerate_devices()`.


    Parameters
    ----------
    pContext (in)
        A pointer to the context performing the enumeration.

    deviceType (in)
        The type of the device being enumerated. This will always be either `ma_device_type_playback` or `ma_device_type_capture`.

    pInfo (in)
        A pointer to a `ma_device_info` containing the ID and name of the enumerated device. Note that this will not include detailed information about the device,
        only basic information (ID and name). The reason for this is that it would otherwise require opening the backend device to probe for the information which
        is too inefficient.

    pUserData (in)
        The user data pointer passed into `ma_context_enumerate_devices()`.
    */
    typedef ma_bool32 (* ma_enum_devices_callback_proc)(ma_context* pContext, ma_device_type deviceType, const ma_device_info* pInfo, void* pUserData);


    /*
    Describes some basic details about a playback or capture device.
    */
    typedef struct
    {
        const ma_device_id* pDeviceID;
        ma_share_mode shareMode;
        ma_format format;
        ma_uint32 channels;
        ma_uint32 sampleRate;
        ma_channel channelMap[254];
        ma_uint32 periodSizeInFrames;
        ma_uint32 periodSizeInMilliseconds;
        ma_uint32 periodCount;
    } ma_device_descriptor;

    /*
    These are the callbacks required to be implemented for a backend. These callbacks are grouped into two parts: context and device. There is one context
    to many devices. A device is created from a context.

    The general flow goes like this:

    1) A context is created with `onContextInit()`
        1a) Available devices can be enumerated with `onContextEnumerateDevices()` if required.
        1b) Detailed information about a device can be queried with `onContextGetDeviceInfo()` if required.
    2) A device is created from the context that was created in the first step using `onDeviceInit()`, and optionally a device ID that was
        selected from device enumeration via `onContextEnumerateDevices()`.
    3) A device is started or stopped with `onDeviceStart()` / `onDeviceStop()`
    4) Data is delivered to and from the device by the backend. This is always done based on the native format returned by the prior call
        to `onDeviceInit()`. Conversion between the device's native format and the format requested by the application will be handled by
        miniaudio internally.

    Initialization of the context is quite simple. You need to do any necessary initialization of internal objects and then output the
    callbacks defined in this structure.

    Once the context has been initialized you can initialize a device. Before doing so, however, the application may want to know which
    physical devices are available. This is where `onContextEnumerateDevices()` comes in. This is fairly simple. For each device, fire the
    given callback with, at a minimum, the basic information filled out in `ma_device_info`. When the callback returns `MA_FALSE`, enumeration
    needs to stop and the `onContextEnumerateDevices()` function returns with a success code.

    Detailed device information can be retrieved from a device ID using `onContextGetDeviceInfo()`. This takes as input the device type and ID,
    and on output returns detailed information about the device in `ma_device_info`. The `onContextGetDeviceInfo()` callback must handle the
    case when the device ID is NULL, in which case information about the default device needs to be retrieved.

    Once the context has been created and the device ID retrieved (if using anything other than the default device), the device can be created.
    This is a little bit more complicated than initialization of the context due to it's more complicated configuration. When initializing a
    device, a duplex device may be requested. This means a separate data format needs to be specified for both playback and capture. On input,
    the data format is set to what the application wants. On output it's set to the native format which should match as closely as possible to
    the requested format. The conversion between the format requested by the application and the device's native format will be handled
    internally by miniaudio.

    On input, if the sample format is set to `ma_format_unknown`, the backend is free to use whatever sample format it desires, so long as it's
    supported by miniaudio. When the channel count is set to 0, the backend should use the device's native channel count. The same applies for
    sample rate. For the channel map, the default should be used when `ma_channel_map_is_blank()` returns true (all channels set to
    `MA_CHANNEL_NONE`). On input, the `periodSizeInFrames` or `periodSizeInMilliseconds` option should always be set. The backend should
    inspect both of these variables. If `periodSizeInFrames` is set, it should take priority, otherwise it needs to be derived from the period
    size in milliseconds (`periodSizeInMilliseconds`) and the sample rate, keeping in mind that the sample rate may be 0, in which case the
    sample rate will need to be determined before calculating the period size in frames. On output, all members of the `ma_device_descriptor`
    object should be set to a valid value, except for `periodSizeInMilliseconds` which is optional (`periodSizeInFrames` *must* be set).

    Starting and stopping of the device is done with `onDeviceStart()` and `onDeviceStop()` and should be self-explanatory. If the backend uses
    asynchronous reading and writing, `onDeviceStart()` and `onDeviceStop()` should always be implemented.

    The handling of data delivery between the application and the device is the most complicated part of the process. To make this a bit
    easier, some helper callbacks are available. If the backend uses a blocking read/write style of API, the `onDeviceRead()` and
    `onDeviceWrite()` callbacks can optionally be implemented. These are blocking and work just like reading and writing from a file. If the
    backend uses a callback for data delivery, that callback must call `ma_device_handle_backend_data_callback()` from within it's callback.
    This allows miniaudio to then process any necessary data conversion and then pass it to the miniaudio data callback.

    If the backend requires absolute flexibility with it's data delivery, it can optionally implement the `onDeviceDataLoop()` callback
    which will allow it to implement the logic that will run on the audio thread. This is much more advanced and is completely optional.

    The audio thread should run data delivery logic in a loop while `ma_device_get_state() == ma_device_state_started` and no errors have been
    encountered. Do not start or stop the device here. That will be handled from outside the `onDeviceDataLoop()` callback.

    The invocation of the `onDeviceDataLoop()` callback will be handled by miniaudio. When you start the device, miniaudio will fire this
    callback. When the device is stopped, the `ma_device_get_state() == ma_device_state_started` condition will fail and the loop will be terminated
    which will then fall through to the part that stops the device. For an example on how to implement the `onDeviceDataLoop()` callback,
    look at `ma_device_audio_thread__default_read_write()`. Implement the `onDeviceDataLoopWakeup()` callback if you need a mechanism to
    wake up the audio thread.

    If the backend supports an optimized retrieval of device information from an initialized `ma_device` object, it should implement the
    `onDeviceGetInfo()` callback. This is optional, in which case it will fall back to `onContextGetDeviceInfo()` which is less efficient.
    */
    struct ma_backend_callbacks
    {
        ma_result (* onContextInit)(ma_context* pContext, const ma_context_config* pConfig, ma_backend_callbacks* pCallbacks);
        ma_result (* onContextUninit)(ma_context* pContext);
        ma_result (* onContextEnumerateDevices)(ma_context* pContext, ma_enum_devices_callback_proc callback, void* pUserData);
        ma_result (* onContextGetDeviceInfo)(ma_context* pContext, ma_device_type deviceType, const ma_device_id* pDeviceID, ma_device_info* pDeviceInfo);
        ma_result (* onDeviceInit)(ma_device* pDevice, const ma_device_config* pConfig, ma_device_descriptor* pDescriptorPlayback, ma_device_descriptor* pDescriptorCapture);
        ma_result (* onDeviceUninit)(ma_device* pDevice);
        ma_result (* onDeviceStart)(ma_device* pDevice);
        ma_result (* onDeviceStop)(ma_device* pDevice);
        ma_result (* onDeviceRead)(ma_device* pDevice, void* pFrames, ma_uint32 frameCount, ma_uint32* pFramesRead);
        ma_result (* onDeviceWrite)(ma_device* pDevice, const void* pFrames, ma_uint32 frameCount, ma_uint32* pFramesWritten);
        ma_result (* onDeviceDataLoop)(ma_device* pDevice);
        ma_result (* onDeviceDataLoopWakeup)(ma_device* pDevice);
        ma_result (* onDeviceGetInfo)(ma_device* pDevice, ma_device_type type, ma_device_info* pDeviceInfo);
    };

    struct ma_context_config
    {
        ma_log* pLog;
        ma_thread_priority threadPriority;
        size_t threadStackSize;
        void* pUserData;
        ma_allocation_callbacks allocationCallbacks;
        struct
        {
            ma_bool32 useVerboseDeviceEnumeration;
        } alsa;
        struct
        {
            const char* pApplicationName;
            const char* pServerName;
            ma_bool32 tryAutoSpawn; /* Enables autospawning of the PulseAudio daemon if necessary. */
        } pulse;
        struct
        {
            ma_ios_session_category sessionCategory;
            ma_uint32 sessionCategoryOptions;
            ma_bool32 noAudioSessionActivate;   /* iOS only. When set to true, does not perform an explicit [[AVAudioSession sharedInstace] setActive:true] on initialization. */
            ma_bool32 noAudioSessionDeactivate; /* iOS only. When set to true, does not perform an explicit [[AVAudioSession sharedInstace] setActive:false] on uninitialization. */
        } coreaudio;
        struct
        {
            const char* pClientName;
            ma_bool32 tryStartServer;
        } jack;
        ma_backend_callbacks custom;
    };

    /* WASAPI specific structure for some commands which must run on a common thread due to bugs in WASAPI. */
    typedef struct
    {
        int code;
        ma_event* pEvent;   /* This will be signalled when the event is complete. */
        union
        {
            struct
            {
                int _unused;
            } quit;
            struct
            {
                ma_device_type deviceType;
                void* pAudioClient;
                void** ppAudioClientService;
                ma_result* pResult; /* The result from creating the audio client service. */
            } createAudioClient;
            struct
            {
                ma_device* pDevice;
                ma_device_type deviceType;
            } releaseAudioClient;
        } data;
    } ma_context_command__wasapi;
]]

if raia.os.isWindows() == true then
    ffi.cdef[[
        struct ma_context
        {
            ma_backend_callbacks callbacks;
            ma_backend backend;                 /* DirectSound, ALSA, etc. */
            ma_log* pLog;
            ma_log log; /* Only used if the log is owned by the context. The pLog member will be set to &log in this case. */
            ma_thread_priority threadPriority;
            size_t threadStackSize;
            void* pUserData;
            ma_allocation_callbacks allocationCallbacks;
            ma_mutex deviceEnumLock;            /* Used to make ma_context_get_devices() thread safe. */
            ma_mutex deviceInfoLock;            /* Used to make ma_context_get_device_info() thread safe. */
            ma_uint32 deviceInfoCapacity;       /* Total capacity of pDeviceInfos. */
            ma_uint32 playbackDeviceInfoCount;
            ma_uint32 captureDeviceInfoCount;
            ma_device_info* pDeviceInfos;       /* Playback devices first, then capture. */
        
            union
            {
                struct
                {
                    ma_thread commandThread;
                    ma_mutex commandLock;
                    ma_semaphore commandSem;
                    ma_uint32 commandIndex;
                    ma_uint32 commandCount;
                    ma_context_command__wasapi commands[4];
                    ma_handle hAvrt;
                    ma_proc AvSetMmThreadCharacteristicsA;
                    ma_proc AvRevertMmThreadcharacteristics;
                    ma_handle hMMDevapi;
                    ma_proc ActivateAudioInterfaceAsync;
                } wasapi;

                struct
                {
                    ma_handle hDSoundDLL;
                    ma_proc DirectSoundCreate;
                    ma_proc DirectSoundEnumerateA;
                    ma_proc DirectSoundCaptureCreate;
                    ma_proc DirectSoundCaptureEnumerateA;
                } dsound;

                struct
                {
                    ma_handle hWinMM;
                    ma_proc waveOutGetNumDevs;
                    ma_proc waveOutGetDevCapsA;
                    ma_proc waveOutOpen;
                    ma_proc waveOutClose;
                    ma_proc waveOutPrepareHeader;
                    ma_proc waveOutUnprepareHeader;
                    ma_proc waveOutWrite;
                    ma_proc waveOutReset;
                    ma_proc waveInGetNumDevs;
                    ma_proc waveInGetDevCapsA;
                    ma_proc waveInOpen;
                    ma_proc waveInClose;
                    ma_proc waveInPrepareHeader;
                    ma_proc waveInUnprepareHeader;
                    ma_proc waveInAddBuffer;
                    ma_proc waveInStart;
                    ma_proc waveInReset;
                } winmm;
            };
        
            union
            {
                struct
                {
                    /*HMODULE*/ ma_handle hOle32DLL;
                    ma_proc CoInitialize;
                    ma_proc CoInitializeEx;
                    ma_proc CoUninitialize;
                    ma_proc CoCreateInstance;
                    ma_proc CoTaskMemFree;
                    ma_proc PropVariantClear;
                    ma_proc StringFromGUID2;
        
                    /*HMODULE*/ ma_handle hUser32DLL;
                    ma_proc GetForegroundWindow;
                    ma_proc GetDesktopWindow;
        
                    /*HMODULE*/ ma_handle hAdvapi32DLL;
                    ma_proc RegOpenKeyExA;
                    ma_proc RegCloseKey;
                    ma_proc RegQueryValueExA;
        
                    /*HRESULT*/ long CoInitializeResult;
                } win32;
                int _unused;
            };
        };

        struct ma_device
        {
            ma_context* pContext;
            ma_device_type type;
            ma_uint32 sampleRate;
            ma_atomic_device_state state;               /* The state of the device is variable and can change at any time on any thread. Must be used atomically. */
            ma_device_data_proc onData;                 /* Set once at initialization time and should not be changed after. */
            ma_device_notification_proc onNotification; /* Set once at initialization time and should not be changed after. */
            ma_stop_proc onStop;                        /* DEPRECATED. Use the notification callback instead. Set once at initialization time and should not be changed after. */
            void* pUserData;                            /* Application defined data. */
            ma_mutex startStopLock;
            ma_event wakeupEvent;
            ma_event startEvent;
            ma_event stopEvent;
            ma_thread thread;
            ma_result workResult;                       /* This is set by the worker thread after it's finished doing a job. */
            ma_bool8 isOwnerOfContext;                  /* When set to true, uninitializing the device will also uninitialize the context. Set to true when NULL is passed into ma_device_init(). */
            ma_bool8 noPreSilencedOutputBuffer;
            ma_bool8 noClip;
            ma_bool8 noDisableDenormals;
            ma_bool8 noFixedSizedCallback;
            ma_atomic_float masterVolumeFactor;         /* Linear 0..1. Can be read and written simultaneously by different threads. Must be used atomically. */
            ma_duplex_rb duplexRB;                      /* Intermediary buffer for duplex device on asynchronous backends. */
            struct
            {
                ma_resample_algorithm algorithm;
                ma_resampling_backend_vtable* pBackendVTable;
                void* pBackendUserData;
                struct
                {
                    ma_uint32 lpfOrder;
                } linear;
            } resampling;
            struct
            {
                ma_device_id* pID;                  /* Set to NULL if using default ID, otherwise set to the address of "id". */
                ma_device_id id;                    /* If using an explicit device, will be set to a copy of the ID used for initialization. Otherwise cleared to 0. */
                char name[255 + 1];                     /* Maybe temporary. Likely to be replaced with a query API. */
                ma_share_mode shareMode;            /* Set to whatever was passed in when the device was initialized. */
                ma_format format;
                ma_uint32 channels;
                ma_channel channelMap[254];
                ma_format internalFormat;
                ma_uint32 internalChannels;
                ma_uint32 internalSampleRate;
                ma_channel internalChannelMap[254];
                ma_uint32 internalPeriodSizeInFrames;
                ma_uint32 internalPeriods;
                ma_channel_mix_mode channelMixMode;
                ma_bool32 calculateLFEFromSpatialChannels;
                ma_data_converter converter;
                void* pIntermediaryBuffer;          /* For implementing fixed sized buffer callbacks. Will be null if using variable sized callbacks. */
                ma_uint32 intermediaryBufferCap;
                ma_uint32 intermediaryBufferLen;    /* How many valid frames are sitting in the intermediary buffer. */
                void* pInputCache;                  /* In external format. Can be null. */
                ma_uint64 inputCacheCap;
                ma_uint64 inputCacheConsumed;
                ma_uint64 inputCacheRemaining;
            } playback;
            struct
            {
                ma_device_id* pID;                  /* Set to NULL if using default ID, otherwise set to the address of "id". */
                ma_device_id id;                    /* If using an explicit device, will be set to a copy of the ID used for initialization. Otherwise cleared to 0. */
                char name[255 + 1];                     /* Maybe temporary. Likely to be replaced with a query API. */
                ma_share_mode shareMode;            /* Set to whatever was passed in when the device was initialized. */
                ma_format format;
                ma_uint32 channels;
                ma_channel channelMap[254];
                ma_format internalFormat;
                ma_uint32 internalChannels;
                ma_uint32 internalSampleRate;
                ma_channel internalChannelMap[254];
                ma_uint32 internalPeriodSizeInFrames;
                ma_uint32 internalPeriods;
                ma_channel_mix_mode channelMixMode;
                ma_bool32 calculateLFEFromSpatialChannels;
                ma_data_converter converter;
                void* pIntermediaryBuffer;          /* For implementing fixed sized buffer callbacks. Will be null if using variable sized callbacks. */
                ma_uint32 intermediaryBufferCap;
                ma_uint32 intermediaryBufferLen;    /* How many valid frames are sitting in the intermediary buffer. */
            } capture;

            union
            {
                struct
                {
                    /*IAudioClient**/ ma_ptr pAudioClientPlayback;
                    /*IAudioClient**/ ma_ptr pAudioClientCapture;
                    /*IAudioRenderClient**/ ma_ptr pRenderClient;
                    /*IAudioCaptureClient**/ ma_ptr pCaptureClient;
                    /*IMMDeviceEnumerator**/ ma_ptr pDeviceEnumerator;      /* Used for IMMNotificationClient notifications. Required for detecting default device changes. */
                    ma_IMMNotificationClient notificationClient;
                    /*HANDLE*/ ma_handle hEventPlayback;                    /* Auto reset. Initialized to signaled. */
                    /*HANDLE*/ ma_handle hEventCapture;                     /* Auto reset. Initialized to unsignaled. */
                    ma_uint32 actualBufferSizeInFramesPlayback;             /* Value from GetBufferSize(). internalPeriodSizeInFrames is not set to the _actual_ buffer size when low-latency shared mode is being used due to the way the IAudioClient3 API works. */
                    ma_uint32 actualBufferSizeInFramesCapture;
                    ma_uint32 originalPeriodSizeInFrames;
                    ma_uint32 originalPeriodSizeInMilliseconds;
                    ma_uint32 originalPeriods;
                    ma_performance_profile originalPerformanceProfile;
                    ma_uint32 periodSizeInFramesPlayback;
                    ma_uint32 periodSizeInFramesCapture;
                    void* pMappedBufferCapture;
                    ma_uint32 mappedBufferCaptureCap;
                    ma_uint32 mappedBufferCaptureLen;
                    void* pMappedBufferPlayback;
                    ma_uint32 mappedBufferPlaybackCap;
                    ma_uint32 mappedBufferPlaybackLen;
                    ma_atomic_bool32 isStartedCapture;                      /* Can be read and written simultaneously across different threads. Must be used atomically, and must be 32-bit. */
                    ma_atomic_bool32 isStartedPlayback;                     /* Can be read and written simultaneously across different threads. Must be used atomically, and must be 32-bit. */
                    ma_uint32 loopbackProcessID;
                    ma_bool8 loopbackProcessExclude;
                    ma_bool8 noAutoConvertSRC;                              /* When set to true, disables the use of AUDCLNT_STREAMFLAGS_AUTOCONVERTPCM. */
                    ma_bool8 noDefaultQualitySRC;                           /* When set to true, disables the use of AUDCLNT_STREAMFLAGS_SRC_DEFAULT_QUALITY. */
                    ma_bool8 noHardwareOffloading;
                    ma_bool8 allowCaptureAutoStreamRouting;
                    ma_bool8 allowPlaybackAutoStreamRouting;
                    ma_bool8 isDetachedPlayback;
                    ma_bool8 isDetachedCapture;
                    ma_wasapi_usage usage;
                    void* hAvrtHandle;
                    ma_mutex rerouteLock;
                } wasapi;

                struct
                {
                    /*LPDIRECTSOUND*/ ma_ptr pPlayback;
                    /*LPDIRECTSOUNDBUFFER*/ ma_ptr pPlaybackPrimaryBuffer;
                    /*LPDIRECTSOUNDBUFFER*/ ma_ptr pPlaybackBuffer;
                    /*LPDIRECTSOUNDCAPTURE*/ ma_ptr pCapture;
                    /*LPDIRECTSOUNDCAPTUREBUFFER*/ ma_ptr pCaptureBuffer;
                } dsound;

                struct
                {
                    /*HWAVEOUT*/ ma_handle hDevicePlayback;
                    /*HWAVEIN*/ ma_handle hDeviceCapture;
                    /*HANDLE*/ ma_handle hEventPlayback;
                    /*HANDLE*/ ma_handle hEventCapture;
                    ma_uint32 fragmentSizeInFrames;
                    ma_uint32 iNextHeaderPlayback;             /* [0,periods). Used as an index into pWAVEHDRPlayback. */
                    ma_uint32 iNextHeaderCapture;              /* [0,periods). Used as an index into pWAVEHDRCapture. */
                    ma_uint32 headerFramesConsumedPlayback;    /* The number of PCM frames consumed in the buffer in pWAVEHEADER[iNextHeader]. */
                    ma_uint32 headerFramesConsumedCapture;     /* ^^^ */
                    /*WAVEHDR**/ ma_uint8* pWAVEHDRPlayback;   /* One instantiation for each period. */
                    /*WAVEHDR**/ ma_uint8* pWAVEHDRCapture;    /* One instantiation for each period. */
                    ma_uint8* pIntermediaryBufferPlayback;
                    ma_uint8* pIntermediaryBufferCapture;
                    ma_uint8* _pHeapData;                      /* Used internally and is used for the heap allocated data for the intermediary buffer and the WAVEHDR structures. */
                } winmm;
            };
        };
    ]]
elseif raia.os.isLinux() == true then
    ffi.cdef[[
        struct ma_context
        {
            ma_backend_callbacks callbacks;
            ma_backend backend;                 /* DirectSound, ALSA, etc. */
            ma_log* pLog;
            ma_log log; /* Only used if the log is owned by the context. The pLog member will be set to &log in this case. */
            ma_thread_priority threadPriority;
            size_t threadStackSize;
            void* pUserData;
            ma_allocation_callbacks allocationCallbacks;
            ma_mutex deviceEnumLock;            /* Used to make ma_context_get_devices() thread safe. */
            ma_mutex deviceInfoLock;            /* Used to make ma_context_get_device_info() thread safe. */
            ma_uint32 deviceInfoCapacity;       /* Total capacity of pDeviceInfos. */
            ma_uint32 playbackDeviceInfoCount;
            ma_uint32 captureDeviceInfoCount;
            ma_device_info* pDeviceInfos;       /* Playback devices first, then capture. */
        
            union
            {
                struct
                {
                    ma_handle asoundSO;
                    ma_proc snd_pcm_open;
                    ma_proc snd_pcm_close;
                    ma_proc snd_pcm_hw_params_sizeof;
                    ma_proc snd_pcm_hw_params_any;
                    ma_proc snd_pcm_hw_params_set_format;
                    ma_proc snd_pcm_hw_params_set_format_first;
                    ma_proc snd_pcm_hw_params_get_format_mask;
                    ma_proc snd_pcm_hw_params_set_channels;
                    ma_proc snd_pcm_hw_params_set_channels_near;
                    ma_proc snd_pcm_hw_params_set_channels_minmax;
                    ma_proc snd_pcm_hw_params_set_rate_resample;
                    ma_proc snd_pcm_hw_params_set_rate;
                    ma_proc snd_pcm_hw_params_set_rate_near;
                    ma_proc snd_pcm_hw_params_set_buffer_size_near;
                    ma_proc snd_pcm_hw_params_set_periods_near;
                    ma_proc snd_pcm_hw_params_set_access;
                    ma_proc snd_pcm_hw_params_get_format;
                    ma_proc snd_pcm_hw_params_get_channels;
                    ma_proc snd_pcm_hw_params_get_channels_min;
                    ma_proc snd_pcm_hw_params_get_channels_max;
                    ma_proc snd_pcm_hw_params_get_rate;
                    ma_proc snd_pcm_hw_params_get_rate_min;
                    ma_proc snd_pcm_hw_params_get_rate_max;
                    ma_proc snd_pcm_hw_params_get_buffer_size;
                    ma_proc snd_pcm_hw_params_get_periods;
                    ma_proc snd_pcm_hw_params_get_access;
                    ma_proc snd_pcm_hw_params_test_format;
                    ma_proc snd_pcm_hw_params_test_channels;
                    ma_proc snd_pcm_hw_params_test_rate;
                    ma_proc snd_pcm_hw_params;
                    ma_proc snd_pcm_sw_params_sizeof;
                    ma_proc snd_pcm_sw_params_current;
                    ma_proc snd_pcm_sw_params_get_boundary;
                    ma_proc snd_pcm_sw_params_set_avail_min;
                    ma_proc snd_pcm_sw_params_set_start_threshold;
                    ma_proc snd_pcm_sw_params_set_stop_threshold;
                    ma_proc snd_pcm_sw_params;
                    ma_proc snd_pcm_format_mask_sizeof;
                    ma_proc snd_pcm_format_mask_test;
                    ma_proc snd_pcm_get_chmap;
                    ma_proc snd_pcm_state;
                    ma_proc snd_pcm_prepare;
                    ma_proc snd_pcm_start;
                    ma_proc snd_pcm_drop;
                    ma_proc snd_pcm_drain;
                    ma_proc snd_pcm_reset;
                    ma_proc snd_device_name_hint;
                    ma_proc snd_device_name_get_hint;
                    ma_proc snd_card_get_index;
                    ma_proc snd_device_name_free_hint;
                    ma_proc snd_pcm_mmap_begin;
                    ma_proc snd_pcm_mmap_commit;
                    ma_proc snd_pcm_recover;
                    ma_proc snd_pcm_readi;
                    ma_proc snd_pcm_writei;
                    ma_proc snd_pcm_avail;
                    ma_proc snd_pcm_avail_update;
                    ma_proc snd_pcm_wait;
                    ma_proc snd_pcm_nonblock;
                    ma_proc snd_pcm_info;
                    ma_proc snd_pcm_info_sizeof;
                    ma_proc snd_pcm_info_get_name;
                    ma_proc snd_pcm_poll_descriptors;
                    ma_proc snd_pcm_poll_descriptors_count;
                    ma_proc snd_pcm_poll_descriptors_revents;
                    ma_proc snd_config_update_free_global;
        
                    ma_mutex internalDeviceEnumLock;
                    ma_bool32 useVerboseDeviceEnumeration;
                } alsa;
            };
        
            union
            {
                struct
                {
                    int _unused;
                } posix;
                int _unused;
            };
        };

        struct ma_device
        {
            ma_context* pContext;
            ma_device_type type;
            ma_uint32 sampleRate;
            ma_atomic_device_state state;               /* The state of the device is variable and can change at any time on any thread. Must be used atomically. */
            ma_device_data_proc onData;                 /* Set once at initialization time and should not be changed after. */
            ma_device_notification_proc onNotification; /* Set once at initialization time and should not be changed after. */
            ma_stop_proc onStop;                        /* DEPRECATED. Use the notification callback instead. Set once at initialization time and should not be changed after. */
            void* pUserData;                            /* Application defined data. */
            ma_mutex startStopLock;
            ma_event wakeupEvent;
            ma_event startEvent;
            ma_event stopEvent;
            ma_thread thread;
            ma_result workResult;                       /* This is set by the worker thread after it's finished doing a job. */
            ma_bool8 isOwnerOfContext;                  /* When set to true, uninitializing the device will also uninitialize the context. Set to true when NULL is passed into ma_device_init(). */
            ma_bool8 noPreSilencedOutputBuffer;
            ma_bool8 noClip;
            ma_bool8 noDisableDenormals;
            ma_bool8 noFixedSizedCallback;
            ma_atomic_float masterVolumeFactor;         /* Linear 0..1. Can be read and written simultaneously by different threads. Must be used atomically. */
            ma_duplex_rb duplexRB;                      /* Intermediary buffer for duplex device on asynchronous backends. */
            struct
            {
                ma_resample_algorithm algorithm;
                ma_resampling_backend_vtable* pBackendVTable;
                void* pBackendUserData;
                struct
                {
                    ma_uint32 lpfOrder;
                } linear;
            } resampling;
            struct
            {
                ma_device_id* pID;                  /* Set to NULL if using default ID, otherwise set to the address of "id". */
                ma_device_id id;                    /* If using an explicit device, will be set to a copy of the ID used for initialization. Otherwise cleared to 0. */
                char name[255 + 1];                     /* Maybe temporary. Likely to be replaced with a query API. */
                ma_share_mode shareMode;            /* Set to whatever was passed in when the device was initialized. */
                ma_format format;
                ma_uint32 channels;
                ma_channel channelMap[254];
                ma_format internalFormat;
                ma_uint32 internalChannels;
                ma_uint32 internalSampleRate;
                ma_channel internalChannelMap[254];
                ma_uint32 internalPeriodSizeInFrames;
                ma_uint32 internalPeriods;
                ma_channel_mix_mode channelMixMode;
                ma_bool32 calculateLFEFromSpatialChannels;
                ma_data_converter converter;
                void* pIntermediaryBuffer;          /* For implementing fixed sized buffer callbacks. Will be null if using variable sized callbacks. */
                ma_uint32 intermediaryBufferCap;
                ma_uint32 intermediaryBufferLen;    /* How many valid frames are sitting in the intermediary buffer. */
                void* pInputCache;                  /* In external format. Can be null. */
                ma_uint64 inputCacheCap;
                ma_uint64 inputCacheConsumed;
                ma_uint64 inputCacheRemaining;
            } playback;
            struct
            {
                ma_device_id* pID;                  /* Set to NULL if using default ID, otherwise set to the address of "id". */
                ma_device_id id;                    /* If using an explicit device, will be set to a copy of the ID used for initialization. Otherwise cleared to 0. */
                char name[255 + 1];                     /* Maybe temporary. Likely to be replaced with a query API. */
                ma_share_mode shareMode;            /* Set to whatever was passed in when the device was initialized. */
                ma_format format;
                ma_uint32 channels;
                ma_channel channelMap[254];
                ma_format internalFormat;
                ma_uint32 internalChannels;
                ma_uint32 internalSampleRate;
                ma_channel internalChannelMap[254];
                ma_uint32 internalPeriodSizeInFrames;
                ma_uint32 internalPeriods;
                ma_channel_mix_mode channelMixMode;
                ma_bool32 calculateLFEFromSpatialChannels;
                ma_data_converter converter;
                void* pIntermediaryBuffer;          /* For implementing fixed sized buffer callbacks. Will be null if using variable sized callbacks. */
                ma_uint32 intermediaryBufferCap;
                ma_uint32 intermediaryBufferLen;    /* How many valid frames are sitting in the intermediary buffer. */
            } capture;

            union
            {
                struct
                {
                    /*snd_pcm_t**/ ma_ptr pPCMPlayback;
                    /*snd_pcm_t**/ ma_ptr pPCMCapture;
                    /*struct pollfd**/ void* pPollDescriptorsPlayback;
                    /*struct pollfd**/ void* pPollDescriptorsCapture;
                    int pollDescriptorCountPlayback;
                    int pollDescriptorCountCapture;
                    int wakeupfdPlayback;   /* eventfd for waking up from poll() when the playback device is stopped. */
                    int wakeupfdCapture;    /* eventfd for waking up from poll() when the capture device is stopped. */
                    ma_bool8 isUsingMMapPlayback;
                    ma_bool8 isUsingMMapCapture;
                } alsa;
            };
        };
    ]]
elseif raia.os.isMacOS() == true then
    ffi.cdef[[
        struct ma_context
        {
            ma_backend_callbacks callbacks;
            ma_backend backend;                 /* DirectSound, ALSA, etc. */
            ma_log* pLog;
            ma_log log; /* Only used if the log is owned by the context. The pLog member will be set to &log in this case. */
            ma_thread_priority threadPriority;
            size_t threadStackSize;
            void* pUserData;
            ma_allocation_callbacks allocationCallbacks;
            ma_mutex deviceEnumLock;            /* Used to make ma_context_get_devices() thread safe. */
            ma_mutex deviceInfoLock;            /* Used to make ma_context_get_device_info() thread safe. */
            ma_uint32 deviceInfoCapacity;       /* Total capacity of pDeviceInfos. */
            ma_uint32 playbackDeviceInfoCount;
            ma_uint32 captureDeviceInfoCount;
            ma_device_info* pDeviceInfos;       /* Playback devices first, then capture. */
        
            union
            {
                struct
                {
                    ma_handle hCoreFoundation;
                    ma_proc CFStringGetCString;
                    ma_proc CFRelease;
        
                    ma_handle hCoreAudio;
                    ma_proc AudioObjectGetPropertyData;
                    ma_proc AudioObjectGetPropertyDataSize;
                    ma_proc AudioObjectSetPropertyData;
                    ma_proc AudioObjectAddPropertyListener;
                    ma_proc AudioObjectRemovePropertyListener;
        
                    ma_handle hAudioUnit;  /* Could possibly be set to AudioToolbox on later versions of macOS. */
                    ma_proc AudioComponentFindNext;
                    ma_proc AudioComponentInstanceDispose;
                    ma_proc AudioComponentInstanceNew;
                    ma_proc AudioOutputUnitStart;
                    ma_proc AudioOutputUnitStop;
                    ma_proc AudioUnitAddPropertyListener;
                    ma_proc AudioUnitGetPropertyInfo;
                    ma_proc AudioUnitGetProperty;
                    ma_proc AudioUnitSetProperty;
                    ma_proc AudioUnitInitialize;
                    ma_proc AudioUnitRender;
        
                    /*AudioComponent*/ ma_ptr component;
                    ma_bool32 noAudioSessionDeactivate; /* For tracking whether or not the iOS audio session should be explicitly deactivated. Set from the config in ma_context_init__coreaudio(). */
                } coreaudio;
            };
        
            union
            {
                struct
                {
                    int _unused;
                } posix;
                int _unused;
            };
        };

        struct ma_device
        {
            ma_context* pContext;
            ma_device_type type;
            ma_uint32 sampleRate;
            ma_atomic_device_state state;               /* The state of the device is variable and can change at any time on any thread. Must be used atomically. */
            ma_device_data_proc onData;                 /* Set once at initialization time and should not be changed after. */
            ma_device_notification_proc onNotification; /* Set once at initialization time and should not be changed after. */
            ma_stop_proc onStop;                        /* DEPRECATED. Use the notification callback instead. Set once at initialization time and should not be changed after. */
            void* pUserData;                            /* Application defined data. */
            ma_mutex startStopLock;
            ma_event wakeupEvent;
            ma_event startEvent;
            ma_event stopEvent;
            ma_thread thread;
            ma_result workResult;                       /* This is set by the worker thread after it's finished doing a job. */
            ma_bool8 isOwnerOfContext;                  /* When set to true, uninitializing the device will also uninitialize the context. Set to true when NULL is passed into ma_device_init(). */
            ma_bool8 noPreSilencedOutputBuffer;
            ma_bool8 noClip;
            ma_bool8 noDisableDenormals;
            ma_bool8 noFixedSizedCallback;
            ma_atomic_float masterVolumeFactor;         /* Linear 0..1. Can be read and written simultaneously by different threads. Must be used atomically. */
            ma_duplex_rb duplexRB;                      /* Intermediary buffer for duplex device on asynchronous backends. */
            struct
            {
                ma_resample_algorithm algorithm;
                ma_resampling_backend_vtable* pBackendVTable;
                void* pBackendUserData;
                struct
                {
                    ma_uint32 lpfOrder;
                } linear;
            } resampling;
            struct
            {
                ma_device_id* pID;                  /* Set to NULL if using default ID, otherwise set to the address of "id". */
                ma_device_id id;                    /* If using an explicit device, will be set to a copy of the ID used for initialization. Otherwise cleared to 0. */
                char name[255 + 1];                     /* Maybe temporary. Likely to be replaced with a query API. */
                ma_share_mode shareMode;            /* Set to whatever was passed in when the device was initialized. */
                ma_format format;
                ma_uint32 channels;
                ma_channel channelMap[254];
                ma_format internalFormat;
                ma_uint32 internalChannels;
                ma_uint32 internalSampleRate;
                ma_channel internalChannelMap[254];
                ma_uint32 internalPeriodSizeInFrames;
                ma_uint32 internalPeriods;
                ma_channel_mix_mode channelMixMode;
                ma_bool32 calculateLFEFromSpatialChannels;
                ma_data_converter converter;
                void* pIntermediaryBuffer;          /* For implementing fixed sized buffer callbacks. Will be null if using variable sized callbacks. */
                ma_uint32 intermediaryBufferCap;
                ma_uint32 intermediaryBufferLen;    /* How many valid frames are sitting in the intermediary buffer. */
                void* pInputCache;                  /* In external format. Can be null. */
                ma_uint64 inputCacheCap;
                ma_uint64 inputCacheConsumed;
                ma_uint64 inputCacheRemaining;
            } playback;
            struct
            {
                ma_device_id* pID;                  /* Set to NULL if using default ID, otherwise set to the address of "id". */
                ma_device_id id;                    /* If using an explicit device, will be set to a copy of the ID used for initialization. Otherwise cleared to 0. */
                char name[255 + 1];                     /* Maybe temporary. Likely to be replaced with a query API. */
                ma_share_mode shareMode;            /* Set to whatever was passed in when the device was initialized. */
                ma_format format;
                ma_uint32 channels;
                ma_channel channelMap[254];
                ma_format internalFormat;
                ma_uint32 internalChannels;
                ma_uint32 internalSampleRate;
                ma_channel internalChannelMap[254];
                ma_uint32 internalPeriodSizeInFrames;
                ma_uint32 internalPeriods;
                ma_channel_mix_mode channelMixMode;
                ma_bool32 calculateLFEFromSpatialChannels;
                ma_data_converter converter;
                void* pIntermediaryBuffer;          /* For implementing fixed sized buffer callbacks. Will be null if using variable sized callbacks. */
                ma_uint32 intermediaryBufferCap;
                ma_uint32 intermediaryBufferLen;    /* How many valid frames are sitting in the intermediary buffer. */
            } capture;

            union
            {
                struct
                {
                    ma_uint32 deviceObjectIDPlayback;
                    ma_uint32 deviceObjectIDCapture;
                    /*AudioUnit*/ ma_ptr audioUnitPlayback;
                    /*AudioUnit*/ ma_ptr audioUnitCapture;
                    /*AudioBufferList**/ ma_ptr pAudioBufferList;   /* Only used for input devices. */
                    ma_uint32 audioBufferCapInFrames;               /* Only used for input devices. The capacity in frames of each buffer in pAudioBufferList. */
                    ma_event stopEvent;
                    ma_uint32 originalPeriodSizeInFrames;
                    ma_uint32 originalPeriodSizeInMilliseconds;
                    ma_uint32 originalPeriods;
                    ma_performance_profile originalPerformanceProfile;
                    ma_bool32 isDefaultPlaybackDevice;
                    ma_bool32 isDefaultCaptureDevice;
                    ma_bool32 isSwitchingPlaybackDevice;   /* <-- Set to true when the default device has changed and miniaudio is in the process of switching. */
                    ma_bool32 isSwitchingCaptureDevice;    /* <-- Set to true when the default device has changed and miniaudio is in the process of switching. */
                    void* pNotificationHandler;             /* Only used on mobile platforms. Obj-C object for handling route changes. */
                } coreaudio;
            };
        };
    ]]
end

-- Utilities

-- VFS

ffi.cdef[[
    typedef void      ma_vfs;
    typedef ma_handle ma_vfs_file;
    
    typedef enum {
        MA_OPEN_MODE_READ  = 0x00000001,
        MA_OPEN_MODE_WRITE = 0x00000002
    } ma_open_mode_flags;
    
    typedef enum {
        ma_seek_origin_start,
        ma_seek_origin_current,
        ma_seek_origin_end  /* Not used by decoders. */
    } ma_seek_origin;
    
    typedef struct {
        ma_uint64 sizeInBytes;
    } ma_file_info;
    
    typedef struct {
        ma_result (* onOpen) (ma_vfs* pVFS, const char* pFilePath, ma_uint32 openMode, ma_vfs_file* pFile);
        ma_result (* onOpenW)(ma_vfs* pVFS, const wchar_t* pFilePath, ma_uint32 openMode, ma_vfs_file* pFile);
        ma_result (* onClose)(ma_vfs* pVFS, ma_vfs_file file);
        ma_result (* onRead) (ma_vfs* pVFS, ma_vfs_file file, void* pDst, size_t sizeInBytes, size_t* pBytesRead);
        ma_result (* onWrite)(ma_vfs* pVFS, ma_vfs_file file, const void* pSrc, size_t sizeInBytes, size_t* pBytesWritten);
        ma_result (* onSeek) (ma_vfs* pVFS, ma_vfs_file file, ma_int64 offset, ma_seek_origin origin);
        ma_result (* onTell) (ma_vfs* pVFS, ma_vfs_file file, ma_int64* pCursor);
        ma_result (* onInfo) (ma_vfs* pVFS, ma_vfs_file file, ma_file_info* pInfo);
    } ma_vfs_callbacks;
    
    typedef struct {
        ma_vfs_callbacks cb;
        ma_allocation_callbacks allocationCallbacks;    /* Only used for the wchar_t version of open() on non-Windows platforms. */
    } ma_default_vfs;
    
    typedef ma_result (* ma_read_proc)(void* pUserData, void* pBufferOut, size_t bytesToRead, size_t* pBytesRead);
    typedef ma_result (* ma_seek_proc)(void* pUserData, ma_int64 offset, ma_seek_origin origin);
    typedef ma_result (* ma_tell_proc)(void* pUserData, ma_int64* pCursor);
    
    typedef enum
    {
        ma_encoding_format_unknown = 0,
        ma_encoding_format_wav,
        ma_encoding_format_flac,
        ma_encoding_format_mp3,
        ma_encoding_format_vorbis
    } ma_encoding_format;
]]

-- Decoding

ffi.cdef[[
    typedef struct ma_decoder ma_decoder;

    typedef struct {
        ma_format preferredFormat;
        ma_uint32 seekPointCount;   /* Set to > 0 to generate a seektable if the decoding backend supports it. */
    } ma_decoding_backend_config;
    
    typedef struct {
        ma_result (* onInit      )(void* pUserData, ma_read_proc onRead, ma_seek_proc onSeek, ma_tell_proc onTell, void* pReadSeekTellUserData, const ma_decoding_backend_config* pConfig, const ma_allocation_callbacks* pAllocationCallbacks, ma_data_source** ppBackend);
        ma_result (* onInitFile  )(void* pUserData, const char* pFilePath, const ma_decoding_backend_config* pConfig, const ma_allocation_callbacks* pAllocationCallbacks, ma_data_source** ppBackend);               /* Optional. */
        ma_result (* onInitFileW )(void* pUserData, const wchar_t* pFilePath, const ma_decoding_backend_config* pConfig, const ma_allocation_callbacks* pAllocationCallbacks, ma_data_source** ppBackend);            /* Optional. */
        ma_result (* onInitMemory)(void* pUserData, const void* pData, size_t dataSize, const ma_decoding_backend_config* pConfig, const ma_allocation_callbacks* pAllocationCallbacks, ma_data_source** ppBackend);  /* Optional. */
        void      (* onUninit    )(void* pUserData, ma_data_source* pBackend, const ma_allocation_callbacks* pAllocationCallbacks);
    } ma_decoding_backend_vtable;
    
    typedef ma_result (* ma_decoder_read_proc)(ma_decoder* pDecoder, void* pBufferOut, size_t bytesToRead, size_t* pBytesRead);         /* Returns the number of bytes read. */
    typedef ma_result (* ma_decoder_seek_proc)(ma_decoder* pDecoder, ma_int64 byteOffset, ma_seek_origin origin);
    typedef ma_result (* ma_decoder_tell_proc)(ma_decoder* pDecoder, ma_int64* pCursor);
    
    typedef struct {
        ma_format format;      /* Set to 0 or ma_format_unknown to use the stream's internal format. */
        ma_uint32 channels;    /* Set to 0 to use the stream's internal channels. */
        ma_uint32 sampleRate;  /* Set to 0 to use the stream's internal sample rate. */
        ma_channel* pChannelMap;
        ma_channel_mix_mode channelMixMode;
        ma_dither_mode ditherMode;
        ma_resampler_config resampling;
        ma_allocation_callbacks allocationCallbacks;
        ma_encoding_format encodingFormat;
        ma_uint32 seekPointCount;   /* When set to > 0, specifies the number of seek points to use for the generation of a seek table. Not all decoding backends support this. */
        ma_decoding_backend_vtable** ppCustomBackendVTables;
        ma_uint32 customBackendCount;
        void* pCustomBackendUserData;
    } ma_decoder_config;
    
    struct ma_decoder {
        ma_data_source_base ds;
        ma_data_source* pBackend;                   /* The decoding backend we'll be pulling data from. */
        const ma_decoding_backend_vtable* pBackendVTable; /* The vtable for the decoding backend. This needs to be stored so we can access the onUninit() callback. */
        void* pBackendUserData;
        ma_decoder_read_proc onRead;
        ma_decoder_seek_proc onSeek;
        ma_decoder_tell_proc onTell;
        void* pUserData;
        ma_uint64 readPointerInPCMFrames;      /* In output sample rate. Used for keeping track of how many frames are available for decoding. */
        ma_format outputFormat;
        ma_uint32 outputChannels;
        ma_uint32 outputSampleRate;
        ma_data_converter converter;    /* Data conversion is achieved by running frames through this. */
        void* pInputCache;              /* In input format. Can be null if it's not needed. */
        ma_uint64 inputCacheCap;        /* The capacity of the input cache. */
        ma_uint64 inputCacheConsumed;   /* The number of frames that have been consumed in the cache. Used for determining the next valid frame. */
        ma_uint64 inputCacheRemaining;  /* The number of valid frames remaining in the cahce. */
        ma_allocation_callbacks allocationCallbacks;
        union {
            struct {
                ma_vfs* pVFS;
                ma_vfs_file file;
            } vfs;
            struct {
                const ma_uint8* pData;
                size_t dataSize;
                size_t currentReadPos;
            } memory;               /* Only used for decoders that were opened against a block of memory. */
        } data;
    };
]]

-- Encoding

ffi.cdef[[
    typedef struct ma_encoder ma_encoder;

    typedef ma_result (* ma_encoder_write_proc)           (ma_encoder* pEncoder, const void* pBufferIn, size_t bytesToWrite, size_t* pBytesWritten);
    typedef ma_result (* ma_encoder_seek_proc)            (ma_encoder* pEncoder, ma_int64 offset, ma_seek_origin origin);
    typedef ma_result (* ma_encoder_init_proc)            (ma_encoder* pEncoder);
    typedef void      (* ma_encoder_uninit_proc)          (ma_encoder* pEncoder);
    typedef ma_result (* ma_encoder_write_pcm_frames_proc)(ma_encoder* pEncoder, const void* pFramesIn, ma_uint64 frameCount, ma_uint64* pFramesWritten);
    
    typedef struct
    {
        ma_encoding_format encodingFormat;
        ma_format format;
        ma_uint32 channels;
        ma_uint32 sampleRate;
        ma_allocation_callbacks allocationCallbacks;
    } ma_encoder_config;
    
    struct ma_encoder
    {
        ma_encoder_config config;
        ma_encoder_write_proc onWrite;
        ma_encoder_seek_proc onSeek;
        ma_encoder_init_proc onInit;
        ma_encoder_uninit_proc onUninit;
        ma_encoder_write_pcm_frames_proc onWritePCMFrames;
        void* pUserData;
        void* pInternalEncoder;
        union
        {
            struct
            {
                ma_vfs* pVFS;
                ma_vfs_file file;
            } vfs;
        } data;
    };
]]

-- Generation

ffi.cdef[[
    typedef enum
    {
        ma_waveform_type_sine,
        ma_waveform_type_square,
        ma_waveform_type_triangle,
        ma_waveform_type_sawtooth
    } ma_waveform_type;
    
    typedef struct
    {
        ma_format format;
        ma_uint32 channels;
        ma_uint32 sampleRate;
        ma_waveform_type type;
        double amplitude;
        double frequency;
    } ma_waveform_config;
    
    typedef struct
    {
        ma_data_source_base ds;
        ma_waveform_config config;
        double advance;
        double time;
    } ma_waveform;
    
    typedef struct
    {
        ma_format format;
        ma_uint32 channels;
        ma_uint32 sampleRate;
        double dutyCycle;
        double amplitude;
        double frequency;
    } ma_pulsewave_config;
    
    typedef struct
    {
        ma_waveform waveform;
        ma_pulsewave_config config;
    } ma_pulsewave;
    
    typedef enum
    {
        ma_noise_type_white,
        ma_noise_type_pink,
        ma_noise_type_brownian
    } ma_noise_type;
    
    typedef struct
    {
        ma_format format;
        ma_uint32 channels;
        ma_noise_type type;
        ma_int32 seed;
        double amplitude;
        ma_bool32 duplicateChannels;
    } ma_noise_config;
    
    typedef struct
    {
        ma_data_source_base ds;
        ma_noise_config config;
        ma_lcg lcg;
        union
        {
            struct
            {
                double** bin;
                double* accumulation;
                ma_uint32* counter;
            } pink;
            struct
            {
                double* accumulation;
            } brownian;
        } state;
    
        /* Memory management. */
        void* _pHeap;
        ma_bool32 _ownsHeap;
    } ma_noise;
]]

-- Resource Manager

ffi.cdef[[
    typedef struct ma_resource_manager                  ma_resource_manager;
    typedef struct ma_resource_manager_data_buffer_node ma_resource_manager_data_buffer_node;
    typedef struct ma_resource_manager_data_buffer      ma_resource_manager_data_buffer;
    typedef struct ma_resource_manager_data_stream      ma_resource_manager_data_stream;
    typedef struct ma_resource_manager_data_source      ma_resource_manager_data_source;
    
    typedef enum
    {
        MA_RESOURCE_MANAGER_DATA_SOURCE_FLAG_STREAM         = 0x00000001,   /* When set, does not load the entire data source in memory. Disk I/O will happen on job threads. */
        MA_RESOURCE_MANAGER_DATA_SOURCE_FLAG_DECODE         = 0x00000002,   /* Decode data before storing in memory. When set, decoding is done at the resource manager level rather than the mixing thread. Results in faster mixing, but higher memory usage. */
        MA_RESOURCE_MANAGER_DATA_SOURCE_FLAG_ASYNC          = 0x00000004,   /* When set, the resource manager will load the data source asynchronously. */
        MA_RESOURCE_MANAGER_DATA_SOURCE_FLAG_WAIT_INIT      = 0x00000008,   /* When set, waits for initialization of the underlying data source before returning from ma_resource_manager_data_source_init(). */
        MA_RESOURCE_MANAGER_DATA_SOURCE_FLAG_UNKNOWN_LENGTH = 0x00000010    /* Gives the resource manager a hint that the length of the data source is unknown and calling `ma_data_source_get_length_in_pcm_frames()` should be avoided. */
    } ma_resource_manager_data_source_flags;
    
    
    /*
    Pipeline notifications used by the resource manager. Made up of both an async notification and a fence, both of which are optional.
    */
    typedef struct
    {
        ma_async_notification* pNotification;
        ma_fence* pFence;
    } ma_resource_manager_pipeline_stage_notification;
    
    typedef struct
    {
        ma_resource_manager_pipeline_stage_notification init;    /* Initialization of the decoder. */
        ma_resource_manager_pipeline_stage_notification done;    /* Decoding fully completed. */
    } ma_resource_manager_pipeline_notifications;
    
    typedef enum
    {
        /* Indicates ma_resource_manager_next_job() should not block. Only valid when the job thread count is 0. */
        MA_RESOURCE_MANAGER_FLAG_NON_BLOCKING = 0x00000001,
    
        /* Disables any kind of multithreading. Implicitly enables MA_RESOURCE_MANAGER_FLAG_NON_BLOCKING. */
        MA_RESOURCE_MANAGER_FLAG_NO_THREADING = 0x00000002
    } ma_resource_manager_flags;
    
    typedef struct
    {
        const char* pFilePath;
        const wchar_t* pFilePathW;
        const ma_resource_manager_pipeline_notifications* pNotifications;
        ma_uint64 initialSeekPointInPCMFrames;
        ma_uint64 rangeBegInPCMFrames;
        ma_uint64 rangeEndInPCMFrames;
        ma_uint64 loopPointBegInPCMFrames;
        ma_uint64 loopPointEndInPCMFrames;
        ma_bool32 isLooping;
        ma_uint32 flags;
    } ma_resource_manager_data_source_config;
    
    typedef enum
    {
        ma_resource_manager_data_supply_type_unknown = 0,   /* Used for determining whether or the data supply has been initialized. */
        ma_resource_manager_data_supply_type_encoded,       /* Data supply is an encoded buffer. Connector is ma_decoder. */
        ma_resource_manager_data_supply_type_decoded,       /* Data supply is a decoded buffer. Connector is ma_audio_buffer. */
        ma_resource_manager_data_supply_type_decoded_paged  /* Data supply is a linked list of decoded buffers. Connector is ma_paged_audio_buffer. */
    } ma_resource_manager_data_supply_type;
    
    typedef struct
    {
        ma_resource_manager_data_supply_type type;    /* Read and written from different threads so needs to be accessed atomically. */
        union
        {
            struct
            {
                const void* pData;
                size_t sizeInBytes;
            } encoded;
            struct
            {
                const void* pData;
                ma_uint64 totalFrameCount;
                ma_uint64 decodedFrameCount;
                ma_format format;
                ma_uint32 channels;
                ma_uint32 sampleRate;
            } decoded;
            struct
            {
                ma_paged_audio_buffer_data data;
                ma_uint64 decodedFrameCount;
                ma_uint32 sampleRate;
            } decodedPaged;
        } backend;
    } ma_resource_manager_data_supply;
    
    struct ma_resource_manager_data_buffer_node
    {
        ma_uint32 hashedName32;                         /* The hashed name. This is the key. */
        ma_uint32 refCount;
        ma_result result;                 /* Result from asynchronous loading. When loading set to MA_BUSY. When fully loaded set to MA_SUCCESS. When deleting set to MA_UNAVAILABLE. */
        ma_uint32 executionCounter;       /* For allocating execution orders for jobs. */
        ma_uint32 executionPointer;       /* For managing the order of execution for asynchronous jobs relating to this object. Incremented as jobs complete processing. */
        ma_bool32 isDataOwnedByResourceManager;         /* Set to true when the underlying data buffer was allocated the resource manager. Set to false if it is owned by the application (via ma_resource_manager_register_*()). */
        ma_resource_manager_data_supply data;
        ma_resource_manager_data_buffer_node* pParent;
        ma_resource_manager_data_buffer_node* pChildLo;
        ma_resource_manager_data_buffer_node* pChildHi;
    };
    
    struct ma_resource_manager_data_buffer
    {
        ma_data_source_base ds;                         /* Base data source. A data buffer is a data source. */
        ma_resource_manager* pResourceManager;          /* A pointer to the resource manager that owns this buffer. */
        ma_resource_manager_data_buffer_node* pNode;    /* The data node. This is reference counted and is what supplies the data. */
        ma_uint32 flags;                                /* The flags that were passed used to initialize the buffer. */
        ma_uint32 executionCounter;       /* For allocating execution orders for jobs. */
        ma_uint32 executionPointer;       /* For managing the order of execution for asynchronous jobs relating to this object. Incremented as jobs complete processing. */
        ma_uint64 seekTargetInPCMFrames;                /* Only updated by the public API. Never written nor read from the job thread. */
        ma_bool32 seekToCursorOnNextRead;               /* On the next read we need to seek to the frame cursor. */
        ma_result result;                 /* Keeps track of a result of decoding. Set to MA_BUSY while the buffer is still loading. Set to MA_SUCCESS when loading is finished successfully. Otherwise set to some other code. */
        ma_bool32 isLooping;              /* Can be read and written by different threads at the same time. Must be used atomically. */
        ma_atomic_bool32 isConnectorInitialized;        /* Used for asynchronous loading to ensure we don't try to initialize the connector multiple times while waiting for the node to fully load. */
        union
        {
            ma_decoder decoder;                 /* Supply type is ma_resource_manager_data_supply_type_encoded */
            ma_audio_buffer buffer;             /* Supply type is ma_resource_manager_data_supply_type_decoded */
            ma_paged_audio_buffer pagedBuffer;  /* Supply type is ma_resource_manager_data_supply_type_decoded_paged */
        } connector;    /* Connects this object to the node's data supply. */
    };
    
    struct ma_resource_manager_data_stream
    {
        ma_data_source_base ds;                     /* Base data source. A data stream is a data source. */
        ma_resource_manager* pResourceManager;      /* A pointer to the resource manager that owns this data stream. */
        ma_uint32 flags;                            /* The flags that were passed used to initialize the stream. */
        ma_decoder decoder;                         /* Used for filling pages with data. This is only ever accessed by the job thread. The public API should never touch this. */
        ma_bool32 isDecoderInitialized;             /* Required for determining whether or not the decoder should be uninitialized in MA_JOB_TYPE_RESOURCE_MANAGER_FREE_DATA_STREAM. */
        ma_uint64 totalLengthInPCMFrames;           /* This is calculated when first loaded by the MA_JOB_TYPE_RESOURCE_MANAGER_LOAD_DATA_STREAM. */
        ma_uint32 relativeCursor;                   /* The playback cursor, relative to the current page. Only ever accessed by the public API. Never accessed by the job thread. */
        ma_uint64 absoluteCursor;     /* The playback cursor, in absolute position starting from the start of the file. */
        ma_uint32 currentPageIndex;                 /* Toggles between 0 and 1. Index 0 is the first half of pPageData. Index 1 is the second half. Only ever accessed by the public API. Never accessed by the job thread. */
        ma_uint32 executionCounter;   /* For allocating execution orders for jobs. */
        ma_uint32 executionPointer;   /* For managing the order of execution for asynchronous jobs relating to this object. Incremented as jobs complete processing. */
    
        /* Written by the public API, read by the job thread. */
        ma_bool32 isLooping;          /* Whether or not the stream is looping. It's important to set the looping flag at the data stream level for smooth loop transitions. */
    
        /* Written by the job thread, read by the public API. */
        void* pPageData;                            /* Buffer containing the decoded data of each page. Allocated once at initialization time. */
        ma_uint32 pageFrameCount[2];  /* The number of valid PCM frames in each page. Used to determine the last valid frame. */
    
        /* Written and read by both the public API and the job thread. These must be atomic. */
        ma_result result;             /* Result from asynchronous loading. When loading set to MA_BUSY. When initialized set to MA_SUCCESS. When deleting set to MA_UNAVAILABLE. If an error occurs when loading, set to an error code. */
        ma_bool32 isDecoderAtEnd;     /* Whether or not the decoder has reached the end. */
        ma_bool32 isPageValid[2];     /* Booleans to indicate whether or not a page is valid. Set to false by the public API, set to true by the job thread. Set to false as the pages are consumed, true when they are filled. */
        ma_bool32 seekCounter;        /* When 0, no seeking is being performed. When > 0, a seek is being performed and reading should be delayed with MA_BUSY. */
    };
    
    struct ma_resource_manager_data_source
    {
        union
        {
            ma_resource_manager_data_buffer buffer;
            ma_resource_manager_data_stream stream;
        } backend;  /* Must be the first item because we need the first item to be the data source callbacks for the buffer or stream. */
    
        ma_uint32 flags;                          /* The flags that were passed in to ma_resource_manager_data_source_init(). */
        ma_uint32 executionCounter;     /* For allocating execution orders for jobs. */
        ma_uint32 executionPointer;     /* For managing the order of execution for asynchronous jobs relating to this object. Incremented as jobs complete processing. */
    };
    
    typedef struct
    {
        ma_allocation_callbacks allocationCallbacks;
        ma_log* pLog;
        ma_format decodedFormat;        /* The decoded format to use. Set to ma_format_unknown (default) to use the file's native format. */
        ma_uint32 decodedChannels;      /* The decoded channel count to use. Set to 0 (default) to use the file's native channel count. */
        ma_uint32 decodedSampleRate;    /* the decoded sample rate to use. Set to 0 (default) to use the file's native sample rate. */
        ma_uint32 jobThreadCount;       /* Set to 0 if you want to self-manage your job threads. Defaults to 1. */
        size_t jobThreadStackSize;
        ma_uint32 jobQueueCapacity;     /* The maximum number of jobs that can fit in the queue at a time. Defaults to MA_JOB_TYPE_RESOURCE_MANAGER_QUEUE_CAPACITY. Cannot be zero. */
        ma_uint32 flags;
        ma_vfs* pVFS;                   /* Can be NULL in which case defaults will be used. */
        ma_decoding_backend_vtable** ppCustomDecodingBackendVTables;
        ma_uint32 customDecodingBackendCount;
        void* pCustomDecodingBackendUserData;
    } ma_resource_manager_config;
    
    struct ma_resource_manager
    {
        ma_resource_manager_config config;
        ma_resource_manager_data_buffer_node* pRootDataBufferNode;      /* The root buffer in the binary tree. */
        ma_mutex dataBufferBSTLock;                                     /* For synchronizing access to the data buffer binary tree. */
        ma_thread jobThreads[64]; /* The threads for executing jobs. */
        ma_job_queue jobQueue;                                          /* Multi-consumer, multi-producer job queue for managing jobs for asynchronous decoding and streaming. */
        ma_default_vfs defaultVFS;                                      /* Only used if a custom VFS is not specified. */
        ma_log log;                                                     /* Only used if no log was specified in the config. */
    };
]]

-- Node Graph

ffi.cdef[[
    typedef struct ma_node_graph ma_node_graph;
    typedef void ma_node;
    
    
    /* Node flags. */
    typedef enum
    {
        MA_NODE_FLAG_PASSTHROUGH                = 0x00000001,
        MA_NODE_FLAG_CONTINUOUS_PROCESSING      = 0x00000002,
        MA_NODE_FLAG_ALLOW_NULL_INPUT           = 0x00000004,
        MA_NODE_FLAG_DIFFERENT_PROCESSING_RATES = 0x00000008,
        MA_NODE_FLAG_SILENT_OUTPUT              = 0x00000010
    } ma_node_flags;
    
    
    /* The playback state of a node. Either started or stopped. */
    typedef enum
    {
        ma_node_state_started = 0,
        ma_node_state_stopped = 1
    } ma_node_state;
    
    
    typedef struct
    {
        /*
        Extended processing callback. This callback is used for effects that process input and output
        at different rates (i.e. they perform resampling). This is similar to the simple version, only
        they take two separate frame counts: one for input, and one for output.
    
        On input, `pFrameCountOut` is equal to the capacity of the output buffer for each bus, whereas
        `pFrameCountIn` will be equal to the number of PCM frames in each of the buffers in `ppFramesIn`.
    
        On output, set `pFrameCountOut` to the number of PCM frames that were actually output and set
        `pFrameCountIn` to the number of input frames that were consumed.
        */
        void (* onProcess)(ma_node* pNode, const float** ppFramesIn, ma_uint32* pFrameCountIn, float** ppFramesOut, ma_uint32* pFrameCountOut);
    
        /*
        A callback for retrieving the number of a input frames that are required to output the
        specified number of output frames. You would only want to implement this when the node performs
        resampling. This is optional, even for nodes that perform resampling, but it does offer a
        small reduction in latency as it allows miniaudio to calculate the exact number of input frames
        to read at a time instead of having to estimate.
        */
        ma_result (* onGetRequiredInputFrameCount)(ma_node* pNode, ma_uint32 outputFrameCount, ma_uint32* pInputFrameCount);
    
        /*
        The number of input buses. This is how many sub-buffers will be contained in the `ppFramesIn`
        parameters of the callbacks above.
        */
        ma_uint8 inputBusCount;
    
        /*
        The number of output buses. This is how many sub-buffers will be contained in the `ppFramesOut`
        parameters of the callbacks above.
        */
        ma_uint8 outputBusCount;
    
        /*
        Flags describing characteristics of the node. This is currently just a placeholder for some
        ideas for later on.
        */
        ma_uint32 flags;
    } ma_node_vtable;
    
    typedef struct
    {
        const ma_node_vtable* vtable;       /* Should never be null. Initialization of the node will fail if so. */
        ma_node_state initialState;         /* Defaults to ma_node_state_started. */
        ma_uint32 inputBusCount;            /* Only used if the vtable specifies an input bus count of `MA_NODE_BUS_COUNT_UNKNOWN`, otherwise must be set to `MA_NODE_BUS_COUNT_UNKNOWN` (default). */
        ma_uint32 outputBusCount;           /* Only used if the vtable specifies an output bus count of `MA_NODE_BUS_COUNT_UNKNOWN`, otherwise  be set to `MA_NODE_BUS_COUNT_UNKNOWN` (default). */
        const ma_uint32* pInputChannels;    /* The number of elements are determined by the input bus count as determined by the vtable, or `inputBusCount` if the vtable specifies `MA_NODE_BUS_COUNT_UNKNOWN`. */
        const ma_uint32* pOutputChannels;   /* The number of elements are determined by the output bus count as determined by the vtable, or `outputBusCount` if the vtable specifies `MA_NODE_BUS_COUNT_UNKNOWN`. */
    } ma_node_config;
    
    /*
    A node has multiple output buses. An output bus is attached to an input bus as an item in a linked
    list. Think of the input bus as a linked list, with the output bus being an item in that list.
    */
    typedef struct ma_node_output_bus ma_node_output_bus;
    struct ma_node_output_bus
    {
        /* Immutable. */
        ma_node* pNode;                                         /* The node that owns this output bus. The input node. Will be null for dummy head and tail nodes. */
        ma_uint8 outputBusIndex;                                /* The index of the output bus on pNode that this output bus represents. */
        ma_uint8 channels;                                      /* The number of channels in the audio stream for this bus. */
    
        /* Mutable via multiple threads. Must be used atomically. The weird ordering here is for packing reasons. */
        ma_uint8 inputNodeInputBusIndex;                        /* The index of the input bus on the input. Required for detaching. Will only be used within the spinlock so does not need to be atomic. */
        ma_uint32 flags;                          /* Some state flags for tracking the read state of the output buffer. A combination of MA_NODE_OUTPUT_BUS_FLAG_*. */
        ma_uint32 refCount;                       /* Reference count for some thread-safety when detaching. */
        ma_bool32 isAttached;                     /* This is used to prevent iteration of nodes that are in the middle of being detached. Used for thread safety. */
        ma_spinlock lock;                         /* Unfortunate lock, but significantly simplifies the implementation. Required for thread-safe attaching and detaching. */
        float volume;                             /* Linear. */
        ma_node_output_bus* pNext;    /* If null, it's the tail node or detached. */
        ma_node_output_bus* pPrev;    /* If null, it's the head node or detached. */
        ma_node* pInputNode;          /* The node that this output bus is attached to. Required for detaching. */
    };
    
    /*
    A node has multiple input buses. The output buses of a node are connecting to the input busses of
    another. An input bus is essentially just a linked list of output buses.
    */
    typedef struct ma_node_input_bus ma_node_input_bus;
    struct ma_node_input_bus
    {
        /* Mutable via multiple threads. */
        ma_node_output_bus head;                /* Dummy head node for simplifying some lock-free thread-safety stuff. */
        ma_uint32 nextCounter;    /* This is used to determine whether or not the input bus is finding the next node in the list. Used for thread safety when detaching output buses. */
        ma_spinlock lock;         /* Unfortunate lock, but significantly simplifies the implementation. Required for thread-safe attaching and detaching. */
    
        /* Set once at startup. */
        ma_uint8 channels;                      /* The number of channels in the audio stream for this bus. */
    };
    
    
    typedef struct ma_node_base ma_node_base;
    struct ma_node_base
    {
        /* These variables are set once at startup. */
        ma_node_graph* pNodeGraph;              /* The graph this node belongs to. */
        const ma_node_vtable* vtable;
        float* pCachedData;                     /* Allocated on the heap. Fixed size. Needs to be stored on the heap because reading from output buses is done in separate function calls. */
        ma_uint16 cachedDataCapInFramesPerBus;  /* The capacity of the input data cache in frames, per bus. */
    
        /* These variables are read and written only from the audio thread. */
        ma_uint16 cachedFrameCountOut;
        ma_uint16 cachedFrameCountIn;
        ma_uint16 consumedFrameCountIn;
    
        /* These variables are read and written between different threads. */
        ma_node_state state;      /* When set to stopped, nothing will be read, regardless of the times in stateTimes. */
        ma_uint64 stateTimes[2];  /* Indexed by ma_node_state. Specifies the time based on the global clock that a node should be considered to be in the relevant state. */
        ma_uint64 localTime;      /* The node's local clock. This is just a running sum of the number of output frames that have been processed. Can be modified by any thread with `ma_node_set_time()`. */
        ma_uint32 inputBusCount;
        ma_uint32 outputBusCount;
        ma_node_input_bus* pInputBuses;
        ma_node_output_bus* pOutputBuses;
    
        /* Memory management. */
        ma_node_input_bus _inputBuses[2];
        ma_node_output_bus _outputBuses[2];
        void* _pHeap;   /* A heap allocation for internal use only. pInputBuses and/or pOutputBuses will point to this if the bus count exceeds MA_MAX_NODE_LOCAL_BUS_COUNT. */
        ma_bool32 _ownsHeap;    /* If set to true, the node owns the heap allocation and _pHeap will be freed in ma_node_uninit(). */
    };
    
    typedef struct
    {
        ma_uint32 channels;
        ma_uint16 nodeCacheCapInFrames;
    } ma_node_graph_config;
    
    struct ma_node_graph
    {
        /* Immutable. */
        ma_node_base base;                  /* The node graph itself is a node so it can be connected as an input to different node graph. This has zero inputs and calls ma_node_graph_read_pcm_frames() to generate it's output. */
        ma_node_base endpoint;              /* Special node that all nodes eventually connect to. Data is read from this node in ma_node_graph_read_pcm_frames(). */
        ma_uint16 nodeCacheCapInFrames;
    
        /* Read and written by multiple threads. */
        ma_bool32 isReading;
    };
    
    /* Data source node. 0 input buses, 1 output bus. Used for reading from a data source. */
    typedef struct
    {
        ma_node_config nodeConfig;
        ma_data_source* pDataSource;
    } ma_data_source_node_config;
    
    typedef struct
    {
        ma_node_base base;
        ma_data_source* pDataSource;
    } ma_data_source_node;
    
    /* Splitter Node. 1 input, many outputs. Used for splitting/copying a stream so it can be as input into two separate output nodes. */
    typedef struct
    {
        ma_node_config nodeConfig;
        ma_uint32 channels;
        ma_uint32 outputBusCount;
    } ma_splitter_node_config;
    
    typedef struct
    {
        ma_node_base base;
    } ma_splitter_node;
    
    /*
    Biquad Node
    */
    typedef struct
    {
        ma_node_config nodeConfig;
        ma_biquad_config biquad;
    } ma_biquad_node_config;
    
    typedef struct
    {
        ma_node_base baseNode;
        ma_biquad biquad;
    } ma_biquad_node;
    
    /*
    Low Pass Filter Node
    */
    typedef struct
    {
        ma_node_config nodeConfig;
        ma_lpf_config lpf;
    } ma_lpf_node_config;
    
    typedef struct
    {
        ma_node_base baseNode;
        ma_lpf lpf;
    } ma_lpf_node;
    
    /*
    High Pass Filter Node
    */
    typedef struct
    {
        ma_node_config nodeConfig;
        ma_hpf_config hpf;
    } ma_hpf_node_config;
    
    typedef struct
    {
        ma_node_base baseNode;
        ma_hpf hpf;
    } ma_hpf_node;
    
    /*
    Band Pass Filter Node
    */
    typedef struct
    {
        ma_node_config nodeConfig;
        ma_bpf_config bpf;
    } ma_bpf_node_config;
    
    typedef struct
    {
        ma_node_base baseNode;
        ma_bpf bpf;
    } ma_bpf_node;
    
    /*
    Notching Filter Node
    */
    typedef struct
    {
        ma_node_config nodeConfig;
        ma_notch_config notch;
    } ma_notch_node_config;
    
    typedef struct
    {
        ma_node_base baseNode;
        ma_notch2 notch;
    } ma_notch_node;
    
    /*
    Peaking Filter Node
    */
    typedef struct
    {
        ma_node_config nodeConfig;
        ma_peak_config peak;
    } ma_peak_node_config;
    
    typedef struct
    {
        ma_node_base baseNode;
        ma_peak2 peak;
    } ma_peak_node;
    
    /*
    Low Shelf Filter Node
    */
    typedef struct
    {
        ma_node_config nodeConfig;
        ma_loshelf_config loshelf;
    } ma_loshelf_node_config;
    
    typedef struct
    {
        ma_node_base baseNode;
        ma_loshelf2 loshelf;
    } ma_loshelf_node;
    
    /*
    High Shelf Filter Node
    */
    typedef struct
    {
        ma_node_config nodeConfig;
        ma_hishelf_config hishelf;
    } ma_hishelf_node_config;
    
    typedef struct
    {
        ma_node_base baseNode;
        ma_hishelf2 hishelf;
    } ma_hishelf_node;
    
    typedef struct
    {
        ma_node_config nodeConfig;
        ma_delay_config delay;
    } ma_delay_node_config;
    
    typedef struct
    {
        ma_node_base baseNode;
        ma_delay delay;
    } ma_delay_node;
]]

-- Engine

ffi.cdef[[
    typedef struct ma_engine ma_engine;
    typedef struct ma_sound  ma_sound;
    
    
    /* Sound flags. */
    typedef enum
    {
        /* Resource manager flags. */
        MA_SOUND_FLAG_STREAM                = 0x00000001,   /* MA_RESOURCE_MANAGER_DATA_SOURCE_FLAG_STREAM */
        MA_SOUND_FLAG_DECODE                = 0x00000002,   /* MA_RESOURCE_MANAGER_DATA_SOURCE_FLAG_DECODE */
        MA_SOUND_FLAG_ASYNC                 = 0x00000004,   /* MA_RESOURCE_MANAGER_DATA_SOURCE_FLAG_ASYNC */
        MA_SOUND_FLAG_WAIT_INIT             = 0x00000008,   /* MA_RESOURCE_MANAGER_DATA_SOURCE_FLAG_WAIT_INIT */
        MA_SOUND_FLAG_UNKNOWN_LENGTH        = 0x00000010,   /* MA_RESOURCE_MANAGER_DATA_SOURCE_FLAG_UNKNOWN_LENGTH */
    
        /* ma_sound specific flags. */
        MA_SOUND_FLAG_NO_DEFAULT_ATTACHMENT = 0x00001000,   /* Do not attach to the endpoint by default. Useful for when setting up nodes in a complex graph system. */
        MA_SOUND_FLAG_NO_PITCH              = 0x00002000,   /* Disable pitch shifting with ma_sound_set_pitch() and ma_sound_group_set_pitch(). This is an optimization. */
        MA_SOUND_FLAG_NO_SPATIALIZATION     = 0x00004000    /* Disable spatialization. */
    } ma_sound_flags;
    
    typedef enum
    {
        ma_engine_node_type_sound,
        ma_engine_node_type_group
    } ma_engine_node_type;
    
    typedef struct
    {
        ma_engine* pEngine;
        ma_engine_node_type type;
        ma_uint32 channelsIn;
        ma_uint32 channelsOut;
        ma_uint32 sampleRate;               /* Only used when the type is set to ma_engine_node_type_sound. */
        ma_uint32 volumeSmoothTimeInPCMFrames;  /* The number of frames to smooth over volume changes. Defaults to 0 in which case no smoothing is used. */
        ma_mono_expansion_mode monoExpansionMode;
        ma_bool8 isPitchDisabled;           /* Pitching can be explicitly disabled with MA_SOUND_FLAG_NO_PITCH to optimize processing. */
        ma_bool8 isSpatializationDisabled;  /* Spatialization can be explicitly disabled with MA_SOUND_FLAG_NO_SPATIALIZATION. */
        ma_uint8 pinnedListenerIndex;       /* The index of the listener this node should always use for spatialization. If set to MA_LISTENER_INDEX_CLOSEST the engine will use the closest listener. */
    } ma_engine_node_config;
    
    /* Base node object for both ma_sound and ma_sound_group. */
    typedef struct
    {
        ma_node_base baseNode;                              /* Must be the first member for compatiblity with the ma_node API. */
        ma_engine* pEngine;                                 /* A pointer to the engine. Set based on the value from the config. */
        ma_uint32 sampleRate;                               /* The sample rate of the input data. For sounds backed by a data source, this will be the data source's sample rate. Otherwise it'll be the engine's sample rate. */
        ma_uint32 volumeSmoothTimeInPCMFrames;
        ma_mono_expansion_mode monoExpansionMode;
        ma_fader fader;
        ma_linear_resampler resampler;                      /* For pitch shift. */
        ma_spatializer spatializer;
        ma_panner panner;
        ma_gainer volumeGainer;                             /* This will only be used if volumeSmoothTimeInPCMFrames is > 0. */
        ma_atomic_float volume;                             /* Defaults to 1. */
        float pitch;
        float oldPitch;                                     /* For determining whether or not the resampler needs to be updated to reflect the new pitch. The resampler will be updated on the mixing thread. */
        float oldDopplerPitch;                              /* For determining whether or not the resampler needs to be updated to take a new doppler pitch into account. */
        ma_bool32 isPitchDisabled;            /* When set to true, pitching will be disabled which will allow the resampler to be bypassed to save some computation. */
        ma_bool32 isSpatializationDisabled;   /* Set to false by default. When set to false, will not have spatialisation applied. */
        ma_uint32 pinnedListenerIndex;        /* The index of the listener this node should always use for spatialization. If set to MA_LISTENER_INDEX_CLOSEST the engine will use the closest listener. */
    
        /* When setting a fade, it's not done immediately in ma_sound_set_fade(). It's deferred to the audio thread which means we need to store the settings here. */
        struct
        {
            ma_atomic_float volumeBeg;
            ma_atomic_float volumeEnd;
            ma_atomic_uint64 fadeLengthInFrames;            /* <-- Defaults to (~(ma_uint64)0) which is used to indicate that no fade should be applied. */
            ma_atomic_uint64 absoluteGlobalTimeInFrames;    /* <-- The time to start the fade. */
        } fadeSettings;
    
        /* Memory management. */
        ma_bool8 _ownsHeap;
        void* _pHeap;
    } ma_engine_node;
    
    /* Callback for when a sound reaches the end. */
    typedef void (* ma_sound_end_proc)(void* pUserData, ma_sound* pSound);
    
    typedef struct
    {
        const char* pFilePath;                      /* Set this to load from the resource manager. */
        const wchar_t* pFilePathW;                  /* Set this to load from the resource manager. */
        ma_data_source* pDataSource;                /* Set this to load from an existing data source. */
        ma_node* pInitialAttachment;                /* If set, the sound will be attached to an input of this node. This can be set to a ma_sound. If set to NULL, the sound will be attached directly to the endpoint unless MA_SOUND_FLAG_NO_DEFAULT_ATTACHMENT is set in `flags`. */
        ma_uint32 initialAttachmentInputBusIndex;   /* The index of the input bus of pInitialAttachment to attach the sound to. */
        ma_uint32 channelsIn;                       /* Ignored if using a data source as input (the data source's channel count will be used always). Otherwise, setting to 0 will cause the engine's channel count to be used. */
        ma_uint32 channelsOut;                      /* Set this to 0 (default) to use the engine's channel count. Set to MA_SOUND_SOURCE_CHANNEL_COUNT to use the data source's channel count (only used if using a data source as input). */
        ma_mono_expansion_mode monoExpansionMode;   /* Controls how the mono channel should be expanded to other channels when spatialization is disabled on a sound. */
        ma_uint32 flags;                            /* A combination of MA_SOUND_FLAG_* flags. */
        ma_uint32 volumeSmoothTimeInPCMFrames;      /* The number of frames to smooth over volume changes. Defaults to 0 in which case no smoothing is used. */
        ma_uint64 initialSeekPointInPCMFrames;      /* Initializes the sound such that it's seeked to this location by default. */
        ma_uint64 rangeBegInPCMFrames;
        ma_uint64 rangeEndInPCMFrames;
        ma_uint64 loopPointBegInPCMFrames;
        ma_uint64 loopPointEndInPCMFrames;
        ma_bool32 isLooping;
        ma_sound_end_proc endCallback;              /* Fired when the sound reaches the end. Will be fired from the audio thread. Do not restart, uninitialize or otherwise change the state of the sound from here. Instead fire an event or set a variable to indicate to a different thread to change the start of the sound. Will not be fired in response to a scheduled stop with ma_sound_set_stop_time_*(). */
        void* pEndCallbackUserData;
        ma_resource_manager_pipeline_notifications initNotifications;
        ma_fence* pDoneFence;                       /* Deprecated. Use initNotifications instead. Released when the resource manager has finished decoding the entire sound. Not used with streams. */
    } ma_sound_config;
    
    struct ma_sound
    {
        ma_engine_node engineNode;          /* Must be the first member for compatibility with the ma_node API. */
        ma_data_source* pDataSource;
        ma_uint64 seekTarget; /* The PCM frame index to seek to in the mixing thread. Set to (~(ma_uint64)0) to not perform any seeking. */
        ma_bool32 atEnd;
        ma_sound_end_proc endCallback;
        void* pEndCallbackUserData;
        ma_bool8 ownsDataSource;
    
        /*
        We're declaring a resource manager data source object here to save us a malloc when loading a
        sound via the resource manager, which I *think* will be the most common scenario.
        */
        ma_resource_manager_data_source* pResourceManagerDataSource;
    };
    
    /* Structure specifically for sounds played with ma_engine_play_sound(). Making this a separate structure to reduce overhead. */
    typedef struct ma_sound_inlined ma_sound_inlined;
    struct ma_sound_inlined
    {
        ma_sound sound;
        ma_sound_inlined* pNext;
        ma_sound_inlined* pPrev;
    };
    
    /* A sound group is just a sound. */
    typedef ma_sound_config ma_sound_group_config;
    typedef ma_sound        ma_sound_group;
    
    typedef void (* ma_engine_process_proc)(void* pUserData, float* pFramesOut, ma_uint64 frameCount);
    
    typedef struct
    {
        ma_resource_manager* pResourceManager;          /* Can be null in which case a resource manager will be created for you. */
        ma_context* pContext;
        ma_device* pDevice;                             /* If set, the caller is responsible for calling ma_engine_data_callback() in the device's data callback. */
        ma_device_id* pPlaybackDeviceID;                /* The ID of the playback device to use with the default listener. */
        ma_device_data_proc dataCallback;               /* Can be null. Can be used to provide a custom device data callback. */
        ma_device_notification_proc notificationCallback;
        ma_log* pLog;                                   /* When set to NULL, will use the context's log. */
        ma_uint32 listenerCount;                        /* Must be between 1 and MA_ENGINE_MAX_LISTENERS. */
        ma_uint32 channels;                             /* The number of channels to use when mixing and spatializing. When set to 0, will use the native channel count of the device. */
        ma_uint32 sampleRate;                           /* The sample rate. When set to 0 will use the native channel count of the device. */
        ma_uint32 periodSizeInFrames;                   /* If set to something other than 0, updates will always be exactly this size. The underlying device may be a different size, but from the perspective of the mixer that won't matter.*/
        ma_uint32 periodSizeInMilliseconds;             /* Used if periodSizeInFrames is unset. */
        ma_uint32 gainSmoothTimeInFrames;               /* The number of frames to interpolate the gain of spatialized sounds across. If set to 0, will use gainSmoothTimeInMilliseconds. */
        ma_uint32 gainSmoothTimeInMilliseconds;         /* When set to 0, gainSmoothTimeInFrames will be used. If both are set to 0, a default value will be used. */
        ma_uint32 defaultVolumeSmoothTimeInPCMFrames;   /* Defaults to 0. Controls the default amount of smoothing to apply to volume changes to sounds. High values means more smoothing at the expense of high latency (will take longer to reach the new volume). */
        ma_allocation_callbacks allocationCallbacks;
        ma_bool32 noAutoStart;                          /* When set to true, requires an explicit call to ma_engine_start(). This is false by default, meaning the engine will be started automatically in ma_engine_init(). */
        ma_bool32 noDevice;                             /* When set to true, don't create a default device. ma_engine_read_pcm_frames() can be called manually to read data. */
        ma_mono_expansion_mode monoExpansionMode;       /* Controls how the mono channel should be expanded to other channels when spatialization is disabled on a sound. */
        ma_vfs* pResourceManagerVFS;                    /* A pointer to a pre-allocated VFS object to use with the resource manager. This is ignored if pResourceManager is not NULL. */
        ma_engine_process_proc onProcess;               /* Fired at the end of each call to ma_engine_read_pcm_frames(). For engine's that manage their own internal device (the default configuration), this will be fired from the audio thread, and you do not need to call ma_engine_read_pcm_frames() manually in order to trigger this. */
        void* pProcessUserData;                         /* User data that's passed into onProcess. */
    } ma_engine_config;
    
    struct ma_engine
    {
        ma_node_graph nodeGraph;                /* An engine is a node graph. It should be able to be plugged into any ma_node_graph API (with a cast) which means this must be the first member of this struct. */
        ma_resource_manager* pResourceManager;
        ma_device* pDevice;                     /* Optionally set via the config, otherwise allocated by the engine in ma_engine_init(). */
        ma_log* pLog;
        ma_uint32 sampleRate;
        ma_uint32 listenerCount;
        ma_spatializer_listener listeners[4];
        ma_allocation_callbacks allocationCallbacks;
        ma_bool8 ownsResourceManager;
        ma_bool8 ownsDevice;
        ma_spinlock inlinedSoundLock;               /* For synchronizing access so the inlined sound list. */
        ma_sound_inlined* pInlinedSoundHead;        /* The first inlined sound. Inlined sounds are tracked in a linked list. */
        ma_uint32 inlinedSoundCount;  /* The total number of allocated inlined sound objects. Used for debugging. */
        ma_uint32 gainSmoothTimeInFrames;           /* The number of frames to interpolate the gain of spatialized sounds across. */
        ma_uint32 defaultVolumeSmoothTimeInPCMFrames;
        ma_mono_expansion_mode monoExpansionMode;
        ma_engine_process_proc onProcess;
        void* pProcessUserData;
    };
]]

-- Functions

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
    
    // Biquad Filtering
    ma_biquad_config raia_ma_biquad_config_init(ma_format format, ma_uint32 channels, double b0, double b1, double b2, double a0, double a1, double a2);
    ma_result raia_ma_biquad_get_heap_size(const ma_biquad_config* pConfig, size_t* pHeapSizeInBytes);
    ma_result raia_ma_biquad_init_preallocated(const ma_biquad_config* pConfig, void* pHeap, ma_biquad* pBQ);
    ma_result raia_ma_biquad_init(const ma_biquad_config* pConfig, const ma_allocation_callbacks* pAllocationCallbacks, ma_biquad* pBQ);
    void raia_ma_biquad_uninit(ma_biquad* pBQ, const ma_allocation_callbacks* pAllocationCallbacks);
    ma_result raia_ma_biquad_reinit(const ma_biquad_config* pConfig, ma_biquad* pBQ);
    ma_result raia_ma_biquad_clear_cache(ma_biquad* pBQ);
    ma_result raia_ma_biquad_process_pcm_frames(ma_biquad* pBQ, void* pFramesOut, const void* pFramesIn, ma_uint64 frameCount);
    ma_uint32 raia_ma_biquad_get_latency(const ma_biquad* pBQ);
    
    // Low-Pass Filtering
    ma_lpf1_config raia_ma_lpf1_config_init(ma_format format, ma_uint32 channels, ma_uint32 sampleRate, double cutoffFrequency);
    ma_lpf2_config raia_ma_lpf2_config_init(ma_format format, ma_uint32 channels, ma_uint32 sampleRate, double cutoffFrequency, double q);
    ma_result raia_ma_lpf1_get_heap_size(const ma_lpf1_config* pConfig, size_t* pHeapSizeInBytes);
    ma_result raia_ma_lpf1_init_preallocated(const ma_lpf1_config* pConfig, void* pHeap, ma_lpf1* pLPF);
    ma_result raia_ma_lpf1_init(const ma_lpf1_config* pConfig, const ma_allocation_callbacks* pAllocationCallbacks, ma_lpf1* pLPF);
    void raia_ma_lpf1_uninit(ma_lpf1* pLPF, const ma_allocation_callbacks* pAllocationCallbacks);
    ma_result raia_ma_lpf1_reinit(const ma_lpf1_config* pConfig, ma_lpf1* pLPF);
    ma_result raia_ma_lpf1_clear_cache(ma_lpf1* pLPF);
    ma_result raia_ma_lpf1_process_pcm_frames(ma_lpf1* pLPF, void* pFramesOut, const void* pFramesIn, ma_uint64 frameCount);
    ma_uint32 raia_ma_lpf1_get_latency(const ma_lpf1* pLPF);
    ma_result raia_ma_lpf2_get_heap_size(const ma_lpf2_config* pConfig, size_t* pHeapSizeInBytes);
    ma_result raia_ma_lpf2_init_preallocated(const ma_lpf2_config* pConfig, void* pHeap, ma_lpf2* pHPF);
    ma_result raia_ma_lpf2_init(const ma_lpf2_config* pConfig, const ma_allocation_callbacks* pAllocationCallbacks, ma_lpf2* pLPF);
    void raia_ma_lpf2_uninit(ma_lpf2* pLPF, const ma_allocation_callbacks* pAllocationCallbacks);
    ma_result raia_ma_lpf2_reinit(const ma_lpf2_config* pConfig, ma_lpf2* pLPF);
    ma_result raia_ma_lpf2_clear_cache(ma_lpf2* pLPF);
    ma_result raia_ma_lpf2_process_pcm_frames(ma_lpf2* pLPF, void* pFramesOut, const void* pFramesIn, ma_uint64 frameCount);
    ma_uint32 raia_ma_lpf2_get_latency(const ma_lpf2* pLPF);
    ma_lpf_config raia_ma_lpf_config_init(ma_format format, ma_uint32 channels, ma_uint32 sampleRate, double cutoffFrequency, ma_uint32 order);
    ma_result raia_ma_lpf_get_heap_size(const ma_lpf_config* pConfig, size_t* pHeapSizeInBytes);
    ma_result raia_ma_lpf_init_preallocated(const ma_lpf_config* pConfig, void* pHeap, ma_lpf* pLPF);
    ma_result raia_ma_lpf_init(const ma_lpf_config* pConfig, const ma_allocation_callbacks* pAllocationCallbacks, ma_lpf* pLPF);
    void raia_ma_lpf_uninit(ma_lpf* pLPF, const ma_allocation_callbacks* pAllocationCallbacks);
    ma_result raia_ma_lpf_reinit(const ma_lpf_config* pConfig, ma_lpf* pLPF);
    ma_result raia_ma_lpf_clear_cache(ma_lpf* pLPF);
    ma_result raia_ma_lpf_process_pcm_frames(ma_lpf* pLPF, void* pFramesOut, const void* pFramesIn, ma_uint64 frameCount);
    ma_uint32 raia_ma_lpf_get_latency(const ma_lpf* pLPF);
    
    // High-Pass Filtering
    ma_hpf1_config raia_ma_hpf1_config_init(ma_format format, ma_uint32 channels, ma_uint32 sampleRate, double cutoffFrequency);
    ma_hpf2_config raia_ma_hpf2_config_init(ma_format format, ma_uint32 channels, ma_uint32 sampleRate, double cutoffFrequency, double q);
    ma_result raia_ma_hpf1_get_heap_size(const ma_hpf1_config* pConfig, size_t* pHeapSizeInBytes);
    ma_result raia_ma_hpf1_init_preallocated(const ma_hpf1_config* pConfig, void* pHeap, ma_hpf1* pLPF);
    ma_result raia_ma_hpf1_init(const ma_hpf1_config* pConfig, const ma_allocation_callbacks* pAllocationCallbacks, ma_hpf1* pHPF);
    void raia_ma_hpf1_uninit(ma_hpf1* pHPF, const ma_allocation_callbacks* pAllocationCallbacks);
    ma_result raia_ma_hpf1_reinit(const ma_hpf1_config* pConfig, ma_hpf1* pHPF);
    ma_result raia_ma_hpf1_process_pcm_frames(ma_hpf1* pHPF, void* pFramesOut, const void* pFramesIn, ma_uint64 frameCount);
    ma_uint32 raia_ma_hpf1_get_latency(const ma_hpf1* pHPF);
    ma_result raia_ma_hpf2_get_heap_size(const ma_hpf2_config* pConfig, size_t* pHeapSizeInBytes);
    ma_result raia_ma_hpf2_init_preallocated(const ma_hpf2_config* pConfig, void* pHeap, ma_hpf2* pHPF);
    ma_result raia_ma_hpf2_init(const ma_hpf2_config* pConfig, const ma_allocation_callbacks* pAllocationCallbacks, ma_hpf2* pHPF);
    void raia_ma_hpf2_uninit(ma_hpf2* pHPF, const ma_allocation_callbacks* pAllocationCallbacks);
    ma_result raia_ma_hpf2_reinit(const ma_hpf2_config* pConfig, ma_hpf2* pHPF);
    ma_result raia_ma_hpf2_process_pcm_frames(ma_hpf2* pHPF, void* pFramesOut, const void* pFramesIn, ma_uint64 frameCount);
    ma_uint32 raia_ma_hpf2_get_latency(const ma_hpf2* pHPF);
    ma_hpf_config raia_ma_hpf_config_init(ma_format format, ma_uint32 channels, ma_uint32 sampleRate, double cutoffFrequency, ma_uint32 order);
    ma_result raia_ma_hpf_get_heap_size(const ma_hpf_config* pConfig, size_t* pHeapSizeInBytes);
    ma_result raia_ma_hpf_init_preallocated(const ma_hpf_config* pConfig, void* pHeap, ma_hpf* pLPF);
    ma_result raia_ma_hpf_init(const ma_hpf_config* pConfig, const ma_allocation_callbacks* pAllocationCallbacks, ma_hpf* pHPF);
    void raia_ma_hpf_uninit(ma_hpf* pHPF, const ma_allocation_callbacks* pAllocationCallbacks);
    ma_result raia_ma_hpf_reinit(const ma_hpf_config* pConfig, ma_hpf* pHPF);
    ma_result raia_ma_hpf_process_pcm_frames(ma_hpf* pHPF, void* pFramesOut, const void* pFramesIn, ma_uint64 frameCount);
    ma_uint32 raia_ma_hpf_get_latency(const ma_hpf* pHPF);
    
    // Band-Pass Filtering
    ma_bpf2_config raia_ma_bpf2_config_init(ma_format format, ma_uint32 channels, ma_uint32 sampleRate, double cutoffFrequency, double q);
    ma_result raia_ma_bpf2_get_heap_size(const ma_bpf2_config* pConfig, size_t* pHeapSizeInBytes);
    ma_result raia_ma_bpf2_init_preallocated(const ma_bpf2_config* pConfig, void* pHeap, ma_bpf2* pBPF);
    ma_result raia_ma_bpf2_init(const ma_bpf2_config* pConfig, const ma_allocation_callbacks* pAllocationCallbacks, ma_bpf2* pBPF);
    void raia_ma_bpf2_uninit(ma_bpf2* pBPF, const ma_allocation_callbacks* pAllocationCallbacks);
    ma_result raia_ma_bpf2_reinit(const ma_bpf2_config* pConfig, ma_bpf2* pBPF);
    ma_result raia_ma_bpf2_process_pcm_frames(ma_bpf2* pBPF, void* pFramesOut, const void* pFramesIn, ma_uint64 frameCount);
    ma_uint32 raia_ma_bpf2_get_latency(const ma_bpf2* pBPF);
    ma_bpf_config raia_ma_bpf_config_init(ma_format format, ma_uint32 channels, ma_uint32 sampleRate, double cutoffFrequency, ma_uint32 order);
    ma_result raia_ma_bpf_get_heap_size(const ma_bpf_config* pConfig, size_t* pHeapSizeInBytes);
    ma_result raia_ma_bpf_init_preallocated(const ma_bpf_config* pConfig, void* pHeap, ma_bpf* pBPF);
    ma_result raia_ma_bpf_init(const ma_bpf_config* pConfig, const ma_allocation_callbacks* pAllocationCallbacks, ma_bpf* pBPF);
    void raia_ma_bpf_uninit(ma_bpf* pBPF, const ma_allocation_callbacks* pAllocationCallbacks);
    ma_result raia_ma_bpf_reinit(const ma_bpf_config* pConfig, ma_bpf* pBPF);
    ma_result raia_ma_bpf_process_pcm_frames(ma_bpf* pBPF, void* pFramesOut, const void* pFramesIn, ma_uint64 frameCount);
    ma_uint32 raia_ma_bpf_get_latency(const ma_bpf* pBPF);
    
    // Notching Filter
    ma_notch2_config raia_ma_notch2_config_init(ma_format format, ma_uint32 channels, ma_uint32 sampleRate, double q, double frequency);
    ma_result raia_ma_notch2_get_heap_size(const ma_notch2_config* pConfig, size_t* pHeapSizeInBytes);
    ma_result raia_ma_notch2_init_preallocated(const ma_notch2_config* pConfig, void* pHeap, ma_notch2* pFilter);
    ma_result raia_ma_notch2_init(const ma_notch2_config* pConfig, const ma_allocation_callbacks* pAllocationCallbacks, ma_notch2* pFilter);
    void raia_ma_notch2_uninit(ma_notch2* pFilter, const ma_allocation_callbacks* pAllocationCallbacks);
    ma_result raia_ma_notch2_reinit(const ma_notch2_config* pConfig, ma_notch2* pFilter);
    ma_result raia_ma_notch2_process_pcm_frames(ma_notch2* pFilter, void* pFramesOut, const void* pFramesIn, ma_uint64 frameCount);
    ma_uint32 raia_ma_notch2_get_latency(const ma_notch2* pFilter);
    
    // Peaking EQ Filter
    ma_peak2_config raia_ma_peak2_config_init(ma_format format, ma_uint32 channels, ma_uint32 sampleRate, double gainDB, double q, double frequency);
    ma_result raia_ma_peak2_get_heap_size(const ma_peak2_config* pConfig, size_t* pHeapSizeInBytes);
    ma_result raia_ma_peak2_init_preallocated(const ma_peak2_config* pConfig, void* pHeap, ma_peak2* pFilter);
    ma_result raia_ma_peak2_init(const ma_peak2_config* pConfig, const ma_allocation_callbacks* pAllocationCallbacks, ma_peak2* pFilter);
    void raia_ma_peak2_uninit(ma_peak2* pFilter, const ma_allocation_callbacks* pAllocationCallbacks);
    ma_result raia_ma_peak2_reinit(const ma_peak2_config* pConfig, ma_peak2* pFilter);
    ma_result raia_ma_peak2_process_pcm_frames(ma_peak2* pFilter, void* pFramesOut, const void* pFramesIn, ma_uint64 frameCount);
    ma_uint32 raia_ma_peak2_get_latency(const ma_peak2* pFilter);

    // Low Shelf Filter
    ma_loshelf2_config raia_ma_loshelf2_config_init(ma_format format, ma_uint32 channels, ma_uint32 sampleRate, double gainDB, double shelfSlope, double frequency);
    ma_result raia_ma_loshelf2_get_heap_size(const ma_loshelf2_config* pConfig, size_t* pHeapSizeInBytes);
    ma_result raia_ma_loshelf2_init_preallocated(const ma_loshelf2_config* pConfig, void* pHeap, ma_loshelf2* pFilter);
    ma_result raia_ma_loshelf2_init(const ma_loshelf2_config* pConfig, const ma_allocation_callbacks* pAllocationCallbacks, ma_loshelf2* pFilter);
    void raia_ma_loshelf2_uninit(ma_loshelf2* pFilter, const ma_allocation_callbacks* pAllocationCallbacks);
    ma_result raia_ma_loshelf2_reinit(const ma_loshelf2_config* pConfig, ma_loshelf2* pFilter);
    ma_result raia_ma_loshelf2_process_pcm_frames(ma_loshelf2* pFilter, void* pFramesOut, const void* pFramesIn, ma_uint64 frameCount);
    ma_uint32 raia_ma_loshelf2_get_latency(const ma_loshelf2* pFilter);
    
    // High Shelf Filter
    ma_hishelf2_config raia_ma_hishelf2_config_init(ma_format format, ma_uint32 channels, ma_uint32 sampleRate, double gainDB, double shelfSlope, double frequency);
    ma_result raia_ma_hishelf2_get_heap_size(const ma_hishelf2_config* pConfig, size_t* pHeapSizeInBytes);
    ma_result raia_ma_hishelf2_init_preallocated(const ma_hishelf2_config* pConfig, void* pHeap, ma_hishelf2* pFilter);
    ma_result raia_ma_hishelf2_init(const ma_hishelf2_config* pConfig, const ma_allocation_callbacks* pAllocationCallbacks, ma_hishelf2* pFilter);
    void raia_ma_hishelf2_uninit(ma_hishelf2* pFilter, const ma_allocation_callbacks* pAllocationCallbacks);
    ma_result raia_ma_hishelf2_reinit(const ma_hishelf2_config* pConfig, ma_hishelf2* pFilter);
    ma_result raia_ma_hishelf2_process_pcm_frames(ma_hishelf2* pFilter, void* pFramesOut, const void* pFramesIn, ma_uint64 frameCount);
    ma_uint32 raia_ma_hishelf2_get_latency(const ma_hishelf2* pFilter);
    
    // (Delay)
    ma_delay_config raia_ma_delay_config_init(ma_uint32 channels, ma_uint32 sampleRate, ma_uint32 delayInFrames, float decay);
    ma_result raia_ma_delay_init(const ma_delay_config* pConfig, const ma_allocation_callbacks* pAllocationCallbacks, ma_delay* pDelay);
    void raia_ma_delay_uninit(ma_delay* pDelay, const ma_allocation_callbacks* pAllocationCallbacks);
    ma_result raia_ma_delay_process_pcm_frames(ma_delay* pDelay, void* pFramesOut, const void* pFramesIn, ma_uint32 frameCount);
    void raia_ma_delay_set_wet(ma_delay* pDelay, float value);
    float raia_ma_delay_get_wet(const ma_delay* pDelay);
    void raia_ma_delay_set_dry(ma_delay* pDelay, float value);
    float raia_ma_delay_get_dry(const ma_delay* pDelay);
    void raia_ma_delay_set_decay(ma_delay* pDelay, float value);
    float raia_ma_delay_get_decay(const ma_delay* pDelay);
    
    // (Gainer)
    ma_gainer_config raia_ma_gainer_config_init(ma_uint32 channels, ma_uint32 smoothTimeInFrames);
    ma_result raia_ma_gainer_get_heap_size(const ma_gainer_config* pConfig, size_t* pHeapSizeInBytes);
    ma_result raia_ma_gainer_init_preallocated(const ma_gainer_config* pConfig, void* pHeap, ma_gainer* pGainer);
    ma_result raia_ma_gainer_init(const ma_gainer_config* pConfig, const ma_allocation_callbacks* pAllocationCallbacks, ma_gainer* pGainer);
    void raia_ma_gainer_uninit(ma_gainer* pGainer, const ma_allocation_callbacks* pAllocationCallbacks);
    ma_result raia_ma_gainer_process_pcm_frames(ma_gainer* pGainer, void* pFramesOut, const void* pFramesIn, ma_uint64 frameCount);
    ma_result raia_ma_gainer_set_gain(ma_gainer* pGainer, float newGain);
    ma_result raia_ma_gainer_set_gains(ma_gainer* pGainer, float* pNewGains);
    ma_result raia_ma_gainer_set_master_volume(ma_gainer* pGainer, float volume);
    ma_result raia_ma_gainer_get_master_volume(const ma_gainer* pGainer, float* pVolume);
    
    // (Stereo panner)
    ma_panner_config raia_ma_panner_config_init(ma_format format, ma_uint32 channels);
    ma_result raia_ma_panner_init(const ma_panner_config* pConfig, ma_panner* pPanner);
    ma_result raia_ma_panner_process_pcm_frames(ma_panner* pPanner, void* pFramesOut, const void* pFramesIn, ma_uint64 frameCount);
    void raia_ma_panner_set_mode(ma_panner* pPanner, ma_pan_mode mode);
    ma_pan_mode raia_ma_panner_get_mode(const ma_panner* pPanner);
    void raia_ma_panner_set_pan(ma_panner* pPanner, float pan);
    float raia_ma_panner_get_pan(const ma_panner* pPanner);
    
    // (Fader)
    ma_fader_config raia_ma_fader_config_init(ma_format format, ma_uint32 channels, ma_uint32 sampleRate);
    ma_result raia_ma_fader_init(const ma_fader_config* pConfig, ma_fader* pFader);
    ma_result raia_ma_fader_process_pcm_frames(ma_fader* pFader, void* pFramesOut, const void* pFramesIn, ma_uint64 frameCount);
    void raia_ma_fader_get_data_format(const ma_fader* pFader, ma_format* pFormat, ma_uint32* pChannels, ma_uint32* pSampleRate);
    void raia_ma_fader_set_fade(ma_fader* pFader, float volumeBeg, float volumeEnd, ma_uint64 lengthInFrames);
    void raia_ma_fader_set_fade_ex(ma_fader* pFader, float volumeBeg, float volumeEnd, ma_uint64 lengthInFrames, ma_int64 startOffsetInFrames);
    float raia_ma_fader_get_current_volume(const ma_fader* pFader);

    // (Spatializer)
    ma_spatializer_listener_config raia_ma_spatializer_listener_config_init(ma_uint32 channelsOut);
    ma_result raia_ma_spatializer_listener_get_heap_size(const ma_spatializer_listener_config* pConfig, size_t* pHeapSizeInBytes);
    ma_result raia_ma_spatializer_listener_init_preallocated(const ma_spatializer_listener_config* pConfig, void* pHeap, ma_spatializer_listener* pListener);
    ma_result raia_ma_spatializer_listener_init(const ma_spatializer_listener_config* pConfig, const ma_allocation_callbacks* pAllocationCallbacks, ma_spatializer_listener* pListener);
    void raia_ma_spatializer_listener_uninit(ma_spatializer_listener* pListener, const ma_allocation_callbacks* pAllocationCallbacks);
    ma_channel* raia_ma_spatializer_listener_get_channel_map(ma_spatializer_listener* pListener);
    void raia_ma_spatializer_listener_set_cone(ma_spatializer_listener* pListener, float innerAngleInRadians, float outerAngleInRadians, float outerGain);
    void raia_ma_spatializer_listener_get_cone(const ma_spatializer_listener* pListener, float* pInnerAngleInRadians, float* pOuterAngleInRadians, float* pOuterGain);
    void raia_ma_spatializer_listener_set_position(ma_spatializer_listener* pListener, float x, float y, float z);
    ma_vec3f raia_ma_spatializer_listener_get_position(const ma_spatializer_listener* pListener);
    void raia_ma_spatializer_listener_set_direction(ma_spatializer_listener* pListener, float x, float y, float z);
    ma_vec3f raia_ma_spatializer_listener_get_direction(const ma_spatializer_listener* pListener);
    void raia_ma_spatializer_listener_set_velocity(ma_spatializer_listener* pListener, float x, float y, float z);
    ma_vec3f raia_ma_spatializer_listener_get_velocity(const ma_spatializer_listener* pListener);
    void raia_ma_spatializer_listener_set_speed_of_sound(ma_spatializer_listener* pListener, float speedOfSound);
    float raia_ma_spatializer_listener_get_speed_of_sound(const ma_spatializer_listener* pListener);
    void raia_ma_spatializer_listener_set_world_up(ma_spatializer_listener* pListener, float x, float y, float z);
    ma_vec3f raia_ma_spatializer_listener_get_world_up(const ma_spatializer_listener* pListener);
    void raia_ma_spatializer_listener_set_enabled(ma_spatializer_listener* pListener, ma_bool32 isEnabled);
    ma_bool32 raia_ma_spatializer_listener_is_enabled(const ma_spatializer_listener* pListener);
    ma_spatializer_config raia_ma_spatializer_config_init(ma_uint32 channelsIn, ma_uint32 channelsOut);
    ma_result raia_ma_spatializer_get_heap_size(const ma_spatializer_config* pConfig, size_t* pHeapSizeInBytes);
    ma_result raia_ma_spatializer_init_preallocated(const ma_spatializer_config* pConfig, void* pHeap, ma_spatializer* pSpatializer);
    ma_result raia_ma_spatializer_init(const ma_spatializer_config* pConfig, const ma_allocation_callbacks* pAllocationCallbacks, ma_spatializer* pSpatializer);
    void raia_ma_spatializer_uninit(ma_spatializer* pSpatializer, const ma_allocation_callbacks* pAllocationCallbacks);
    ma_result raia_ma_spatializer_process_pcm_frames(ma_spatializer* pSpatializer, ma_spatializer_listener* pListener, void* pFramesOut, const void* pFramesIn, ma_uint64 frameCount);
    ma_result raia_ma_spatializer_set_master_volume(ma_spatializer* pSpatializer, float volume);
    ma_result raia_ma_spatializer_get_master_volume(const ma_spatializer* pSpatializer, float* pVolume);
    ma_uint32 raia_ma_spatializer_get_input_channels(const ma_spatializer* pSpatializer);
    ma_uint32 raia_ma_spatializer_get_output_channels(const ma_spatializer* pSpatializer);
    void raia_ma_spatializer_set_attenuation_model(ma_spatializer* pSpatializer, ma_attenuation_model attenuationModel);
    ma_attenuation_model raia_ma_spatializer_get_attenuation_model(const ma_spatializer* pSpatializer);
    void raia_ma_spatializer_set_positioning(ma_spatializer* pSpatializer, ma_positioning positioning);
    ma_positioning raia_ma_spatializer_get_positioning(const ma_spatializer* pSpatializer);
    void raia_ma_spatializer_set_rolloff(ma_spatializer* pSpatializer, float rolloff);
    float raia_ma_spatializer_get_rolloff(const ma_spatializer* pSpatializer);
    void raia_ma_spatializer_set_min_gain(ma_spatializer* pSpatializer, float minGain);
    float raia_ma_spatializer_get_min_gain(const ma_spatializer* pSpatializer);
    void raia_ma_spatializer_set_max_gain(ma_spatializer* pSpatializer, float maxGain);
    float raia_ma_spatializer_get_max_gain(const ma_spatializer* pSpatializer);
    void raia_ma_spatializer_set_min_distance(ma_spatializer* pSpatializer, float minDistance);
    float raia_ma_spatializer_get_min_distance(const ma_spatializer* pSpatializer);
    void raia_ma_spatializer_set_max_distance(ma_spatializer* pSpatializer, float maxDistance);
    float raia_ma_spatializer_get_max_distance(const ma_spatializer* pSpatializer);
    void raia_ma_spatializer_set_cone(ma_spatializer* pSpatializer, float innerAngleInRadians, float outerAngleInRadians, float outerGain);
    void raia_ma_spatializer_get_cone(const ma_spatializer* pSpatializer, float* pInnerAngleInRadians, float* pOuterAngleInRadians, float* pOuterGain);
    void raia_ma_spatializer_set_doppler_factor(ma_spatializer* pSpatializer, float dopplerFactor);
    float raia_ma_spatializer_get_doppler_factor(const ma_spatializer* pSpatializer);
    void raia_ma_spatializer_set_directional_attenuation_factor(ma_spatializer* pSpatializer, float directionalAttenuationFactor);
    float raia_ma_spatializer_get_directional_attenuation_factor(const ma_spatializer* pSpatializer);
    void raia_ma_spatializer_set_position(ma_spatializer* pSpatializer, float x, float y, float z);
    ma_vec3f raia_ma_spatializer_get_position(const ma_spatializer* pSpatializer);
    void raia_ma_spatializer_set_direction(ma_spatializer* pSpatializer, float x, float y, float z);
    ma_vec3f raia_ma_spatializer_get_direction(const ma_spatializer* pSpatializer);
    void raia_ma_spatializer_set_velocity(ma_spatializer* pSpatializer, float x, float y, float z);
    ma_vec3f raia_ma_spatializer_get_velocity(const ma_spatializer* pSpatializer);
    void raia_ma_spatializer_get_relative_position_and_direction(const ma_spatializer* pSpatializer, const ma_spatializer_listener* pListener, ma_vec3f* pRelativePos, ma_vec3f* pRelativeDir);

    // Resampling
    ma_linear_resampler_config raia_ma_linear_resampler_config_init(ma_format format, ma_uint32 channels, ma_uint32 sampleRateIn, ma_uint32 sampleRateOut);
    ma_result raia_ma_linear_resampler_get_heap_size(const ma_linear_resampler_config* pConfig, size_t* pHeapSizeInBytes);
    ma_result raia_ma_linear_resampler_init_preallocated(const ma_linear_resampler_config* pConfig, void* pHeap, ma_linear_resampler* pResampler);
    ma_result raia_ma_linear_resampler_init(const ma_linear_resampler_config* pConfig, const ma_allocation_callbacks* pAllocationCallbacks, ma_linear_resampler* pResampler);
    void raia_ma_linear_resampler_uninit(ma_linear_resampler* pResampler, const ma_allocation_callbacks* pAllocationCallbacks);
    ma_result raia_ma_linear_resampler_process_pcm_frames(ma_linear_resampler* pResampler, const void* pFramesIn, ma_uint64* pFrameCountIn, void* pFramesOut, ma_uint64* pFrameCountOut);
    ma_result raia_ma_linear_resampler_set_rate(ma_linear_resampler* pResampler, ma_uint32 sampleRateIn, ma_uint32 sampleRateOut);
    ma_result raia_ma_linear_resampler_set_rate_ratio(ma_linear_resampler* pResampler, float ratioInOut);
    ma_uint64 raia_ma_linear_resampler_get_input_latency(const ma_linear_resampler* pResampler);
    ma_uint64 raia_ma_linear_resampler_get_output_latency(const ma_linear_resampler* pResampler);
    ma_result raia_ma_linear_resampler_get_required_input_frame_count(const ma_linear_resampler* pResampler, ma_uint64 outputFrameCount, ma_uint64* pInputFrameCount);
    ma_result raia_ma_linear_resampler_get_expected_output_frame_count(const ma_linear_resampler* pResampler, ma_uint64 inputFrameCount, ma_uint64* pOutputFrameCount);
    ma_result raia_ma_linear_resampler_reset(ma_linear_resampler* pResampler);
    ma_resampler_config raia_ma_resampler_config_init(ma_format format, ma_uint32 channels, ma_uint32 sampleRateIn, ma_uint32 sampleRateOut, ma_resample_algorithm algorithm);
    ma_result raia_ma_resampler_get_heap_size(const ma_resampler_config* pConfig, size_t* pHeapSizeInBytes);
    ma_result raia_ma_resampler_init_preallocated(const ma_resampler_config* pConfig, void* pHeap, ma_resampler* pResampler);
    ma_result raia_ma_resampler_init(const ma_resampler_config* pConfig, const ma_allocation_callbacks* pAllocationCallbacks, ma_resampler* pResampler);
    void raia_ma_resampler_uninit(ma_resampler* pResampler, const ma_allocation_callbacks* pAllocationCallbacks);
    ma_result raia_ma_resampler_process_pcm_frames(ma_resampler* pResampler, const void* pFramesIn, ma_uint64* pFrameCountIn, void* pFramesOut, ma_uint64* pFrameCountOut);
    ma_result raia_ma_resampler_set_rate(ma_resampler* pResampler, ma_uint32 sampleRateIn, ma_uint32 sampleRateOut);
    ma_result raia_ma_resampler_set_rate_ratio(ma_resampler* pResampler, float ratio);
    ma_uint64 raia_ma_resampler_get_input_latency(const ma_resampler* pResampler);
    ma_uint64 raia_ma_resampler_get_output_latency(const ma_resampler* pResampler);
    ma_result raia_ma_resampler_get_required_input_frame_count(const ma_resampler* pResampler, ma_uint64 outputFrameCount, ma_uint64* pInputFrameCount) ;
    ma_result raia_ma_resampler_get_expected_output_frame_count(const ma_resampler* pResampler, ma_uint64 inputFrameCount, ma_uint64* pOutputFrameCount);
    ma_result raia_ma_resampler_reset(ma_resampler* pResampler);

    // Channel Conversion
    ma_channel_converter_config raia_ma_channel_converter_config_init(ma_format format, ma_uint32 channelsIn, const ma_channel* pChannelMapIn, ma_uint32 channelsOut, const ma_channel* pChannelMapOut, ma_channel_mix_mode mixingMode);
    ma_result raia_ma_channel_converter_get_heap_size(const ma_channel_converter_config* pConfig, size_t* pHeapSizeInBytes);
    ma_result raia_ma_channel_converter_init_preallocated(const ma_channel_converter_config* pConfig, void* pHeap, ma_channel_converter* pConverter);
    ma_result raia_ma_channel_converter_init(const ma_channel_converter_config* pConfig, const ma_allocation_callbacks* pAllocationCallbacks, ma_channel_converter* pConverter);
    void raia_ma_channel_converter_uninit(ma_channel_converter* pConverter, const ma_allocation_callbacks* pAllocationCallbacks);
    ma_result raia_ma_channel_converter_process_pcm_frames(ma_channel_converter* pConverter, void* pFramesOut, const void* pFramesIn, ma_uint64 frameCount);
    ma_result raia_ma_channel_converter_get_input_channel_map(const ma_channel_converter* pConverter, ma_channel* pChannelMap, size_t channelMapCap);
    ma_result raia_ma_channel_converter_get_output_channel_map(const ma_channel_converter* pConverter, ma_channel* pChannelMap, size_t channelMapCap);

    // Data Conversion
    ma_data_converter_config raia_ma_data_converter_config_init_default(void);
    ma_data_converter_config raia_ma_data_converter_config_init(ma_format formatIn, ma_format formatOut, ma_uint32 channelsIn, ma_uint32 channelsOut, ma_uint32 sampleRateIn, ma_uint32 sampleRateOut);
    ma_result raia_ma_data_converter_get_heap_size(const ma_data_converter_config* pConfig, size_t* pHeapSizeInBytes);
    ma_result raia_ma_data_converter_init_preallocated(const ma_data_converter_config* pConfig, void* pHeap, ma_data_converter* pConverter);
    ma_result raia_ma_data_converter_init(const ma_data_converter_config* pConfig, const ma_allocation_callbacks* pAllocationCallbacks, ma_data_converter* pConverter);
    void raia_ma_data_converter_uninit(ma_data_converter* pConverter, const ma_allocation_callbacks* pAllocationCallbacks);
    ma_result raia_ma_data_converter_process_pcm_frames(ma_data_converter* pConverter, const void* pFramesIn, ma_uint64* pFrameCountIn, void* pFramesOut, ma_uint64* pFrameCountOut);
    ma_result raia_ma_data_converter_set_rate(ma_data_converter* pConverter, ma_uint32 sampleRateIn, ma_uint32 sampleRateOut);
    ma_result raia_ma_data_converter_set_rate_ratio(ma_data_converter* pConverter, float ratioInOut);
    ma_uint64 raia_ma_data_converter_get_input_latency(const ma_data_converter* pConverter);
    ma_uint64 raia_ma_data_converter_get_output_latency(const ma_data_converter* pConverter);
    ma_result raia_ma_data_converter_get_required_input_frame_count(const ma_data_converter* pConverter, ma_uint64 outputFrameCount, ma_uint64* pInputFrameCount);
    ma_result raia_ma_data_converter_get_expected_output_frame_count(const ma_data_converter* pConverter, ma_uint64 inputFrameCount, ma_uint64* pOutputFrameCount);
    ma_result raia_ma_data_converter_get_input_channel_map(const ma_data_converter* pConverter, ma_channel* pChannelMap, size_t channelMapCap);
    ma_result raia_ma_data_converter_get_output_channel_map(const ma_data_converter* pConverter, ma_channel* pChannelMap, size_t channelMapCap);
    ma_result raia_ma_data_converter_reset(ma_data_converter* pConverter);

    // Format Conversion
    void raia_ma_pcm_u8_to_s16(void* pOut, const void* pIn, ma_uint64 count, ma_dither_mode ditherMode);
    void raia_ma_pcm_u8_to_s24(void* pOut, const void* pIn, ma_uint64 count, ma_dither_mode ditherMode);
    void raia_ma_pcm_u8_to_s32(void* pOut, const void* pIn, ma_uint64 count, ma_dither_mode ditherMode);
    void raia_ma_pcm_u8_to_f32(void* pOut, const void* pIn, ma_uint64 count, ma_dither_mode ditherMode);
    void raia_ma_pcm_s16_to_u8(void* pOut, const void* pIn, ma_uint64 count, ma_dither_mode ditherMode);
    void raia_ma_pcm_s16_to_s24(void* pOut, const void* pIn, ma_uint64 count, ma_dither_mode ditherMode);
    void raia_ma_pcm_s16_to_s32(void* pOut, const void* pIn, ma_uint64 count, ma_dither_mode ditherMode);
    void raia_ma_pcm_s16_to_f32(void* pOut, const void* pIn, ma_uint64 count, ma_dither_mode ditherMode);
    void raia_ma_pcm_s24_to_u8(void* pOut, const void* pIn, ma_uint64 count, ma_dither_mode ditherMode);
    void raia_ma_pcm_s24_to_s16(void* pOut, const void* pIn, ma_uint64 count, ma_dither_mode ditherMode);
    void raia_ma_pcm_s24_to_s32(void* pOut, const void* pIn, ma_uint64 count, ma_dither_mode ditherMode);
    void raia_ma_pcm_s24_to_f32(void* pOut, const void* pIn, ma_uint64 count, ma_dither_mode ditherMode);
    void raia_ma_pcm_s32_to_u8(void* pOut, const void* pIn, ma_uint64 count, ma_dither_mode ditherMode);
    void raia_ma_pcm_s32_to_s16(void* pOut, const void* pIn, ma_uint64 count, ma_dither_mode ditherMode);
    void raia_ma_pcm_s32_to_s24(void* pOut, const void* pIn, ma_uint64 count, ma_dither_mode ditherMode);
    void raia_ma_pcm_s32_to_f32(void* pOut, const void* pIn, ma_uint64 count, ma_dither_mode ditherMode);
    void raia_ma_pcm_f32_to_u8(void* pOut, const void* pIn, ma_uint64 count, ma_dither_mode ditherMode);
    void raia_ma_pcm_f32_to_s16(void* pOut, const void* pIn, ma_uint64 count, ma_dither_mode ditherMode);
    void raia_ma_pcm_f32_to_s24(void* pOut, const void* pIn, ma_uint64 count, ma_dither_mode ditherMode);
    void raia_ma_pcm_f32_to_s32(void* pOut, const void* pIn, ma_uint64 count, ma_dither_mode ditherMode);
    void raia_ma_pcm_convert(void* pOut, ma_format formatOut, const void* pIn, ma_format formatIn, ma_uint64 sampleCount, ma_dither_mode ditherMode);
    void raia_ma_convert_pcm_frames_format(void* pOut, ma_format formatOut, const void* pIn, ma_format formatIn, ma_uint64 frameCount, ma_uint32 channels, ma_dither_mode ditherMode);
    void raia_ma_deinterleave_pcm_frames(ma_format format, ma_uint32 channels, ma_uint64 frameCount, const void* pInterleavedPCMFrames, void** ppDeinterleavedPCMFrames);
    void raia_ma_interleave_pcm_frames(ma_format format, ma_uint32 channels, ma_uint64 frameCount, const void** ppDeinterleavedPCMFrames, void* pInterleavedPCMFrames);

    // Channel Maps
    ma_channel raia_ma_channel_map_get_channel(const ma_channel* pChannelMap, ma_uint32 channelCount, ma_uint32 channelIndex);
    void raia_ma_channel_map_init_blank(ma_channel* pChannelMap, ma_uint32 channels);
    void raia_ma_channel_map_init_standard(ma_standard_channel_map standardChannelMap, ma_channel* pChannelMap, size_t channelMapCap, ma_uint32 channels);
    void raia_ma_channel_map_copy(ma_channel* pOut, const ma_channel* pIn, ma_uint32 channels);
    void raia_ma_channel_map_copy_or_default(ma_channel* pOut, size_t channelMapCapOut, const ma_channel* pIn, ma_uint32 channels);
    ma_bool32 raia_ma_channel_map_is_valid(const ma_channel* pChannelMap, ma_uint32 channels);
    ma_bool32 raia_ma_channel_map_is_equal(const ma_channel* pChannelMapA, const ma_channel* pChannelMapB, ma_uint32 channels);
    ma_bool32 raia_ma_channel_map_is_blank(const ma_channel* pChannelMap, ma_uint32 channels);
    ma_bool32 raia_ma_channel_map_contains_channel_position(ma_uint32 channels, const ma_channel* pChannelMap, ma_channel channelPosition);
    ma_bool32 raia_ma_channel_map_find_channel_position(ma_uint32 channels, const ma_channel* pChannelMap, ma_channel channelPosition, ma_uint32* pChannelIndex);
    size_t raia_ma_channel_map_to_string(const ma_channel* pChannelMap, ma_uint32 channels, char* pBufferOut, size_t bufferCap);
    const char* raia_ma_channel_position_to_string(ma_channel channel);

    // Conversion Helpers
    ma_uint64 raia_ma_convert_frames(void* pOut, ma_uint64 frameCountOut, ma_format formatOut, ma_uint32 channelsOut, ma_uint32 sampleRateOut, const void* pIn, ma_uint64 frameCountIn, ma_format formatIn, ma_uint32 channelsIn, ma_uint32 sampleRateIn);
    ma_uint64 raia_ma_convert_frames_ex(void* pOut, ma_uint64 frameCountOut, const void* pIn, ma_uint64 frameCountIn, const ma_data_converter_config* pConfig);

    // Data Source
    ma_data_source_config raia_ma_data_source_config_init(void);
    ma_result raia_ma_data_source_init(const ma_data_source_config* pConfig, ma_data_source* pDataSource);
    void raia_ma_data_source_uninit(ma_data_source* pDataSource);
    ma_result raia_ma_data_source_read_pcm_frames(ma_data_source* pDataSource, void* pFramesOut, ma_uint64 frameCount, ma_uint64* pFramesRead);
    ma_result raia_ma_data_source_seek_pcm_frames(ma_data_source* pDataSource, ma_uint64 frameCount, ma_uint64* pFramesSeeked);
    ma_result raia_ma_data_source_seek_to_pcm_frame(ma_data_source* pDataSource, ma_uint64 frameIndex);
    ma_result raia_ma_data_source_get_data_format(ma_data_source* pDataSource, ma_format* pFormat, ma_uint32* pChannels, ma_uint32* pSampleRate, ma_channel* pChannelMap, size_t channelMapCap);
    ma_result raia_ma_data_source_get_cursor_in_pcm_frames(ma_data_source* pDataSource, ma_uint64* pCursor);
    ma_result raia_ma_data_source_get_length_in_pcm_frames(ma_data_source* pDataSource, ma_uint64* pLength);
    ma_result raia_ma_data_source_get_cursor_in_seconds(ma_data_source* pDataSource, float* pCursor);
    ma_result raia_ma_data_source_get_length_in_seconds(ma_data_source* pDataSource, float* pLength);
    ma_result raia_ma_data_source_set_looping(ma_data_source* pDataSource, ma_bool32 isLooping);
    ma_bool32 raia_ma_data_source_is_looping(const ma_data_source* pDataSource);
    ma_result raia_ma_data_source_set_range_in_pcm_frames(ma_data_source* pDataSource, ma_uint64 rangeBegInFrames, ma_uint64 rangeEndInFrames);
    void raia_ma_data_source_get_range_in_pcm_frames(const ma_data_source* pDataSource, ma_uint64* pRangeBegInFrames, ma_uint64* pRangeEndInFrames);
    ma_result raia_ma_data_source_set_loop_point_in_pcm_frames(ma_data_source* pDataSource, ma_uint64 loopBegInFrames, ma_uint64 loopEndInFrames);
    void raia_ma_data_source_get_loop_point_in_pcm_frames(const ma_data_source* pDataSource, ma_uint64* pLoopBegInFrames, ma_uint64* pLoopEndInFrames);
    ma_result raia_ma_data_source_set_current(ma_data_source* pDataSource, ma_data_source* pCurrentDataSource);
    ma_data_source* raia_ma_data_source_get_current(const ma_data_source* pDataSource);
    ma_result raia_ma_data_source_set_next(ma_data_source* pDataSource, ma_data_source* pNextDataSource);
    ma_data_source* raia_ma_data_source_get_next(const ma_data_source* pDataSource);
    ma_result raia_ma_data_source_set_next_callback(ma_data_source* pDataSource, ma_data_source_get_next_proc onGetNext);
    ma_data_source_get_next_proc raia_ma_data_source_get_next_callback(const ma_data_source* pDataSource);
    ma_result raia_ma_audio_buffer_ref_init(ma_format format, ma_uint32 channels, const void* pData, ma_uint64 sizeInFrames, ma_audio_buffer_ref* pAudioBufferRef);
    void raia_ma_audio_buffer_ref_uninit(ma_audio_buffer_ref* pAudioBufferRef);
    ma_result raia_ma_audio_buffer_ref_set_data(ma_audio_buffer_ref* pAudioBufferRef, const void* pData, ma_uint64 sizeInFrames);
    ma_uint64 raia_ma_audio_buffer_ref_read_pcm_frames(ma_audio_buffer_ref* pAudioBufferRef, void* pFramesOut, ma_uint64 frameCount, ma_bool32 loop);
    ma_result raia_ma_audio_buffer_ref_seek_to_pcm_frame(ma_audio_buffer_ref* pAudioBufferRef, ma_uint64 frameIndex);
    ma_result raia_ma_audio_buffer_ref_map(ma_audio_buffer_ref* pAudioBufferRef, void** ppFramesOut, ma_uint64* pFrameCount);
    ma_result raia_ma_audio_buffer_ref_unmap(ma_audio_buffer_ref* pAudioBufferRef, ma_uint64 frameCount);
    ma_bool32 raia_ma_audio_buffer_ref_at_end(const ma_audio_buffer_ref* pAudioBufferRef);
    ma_result raia_ma_audio_buffer_ref_get_cursor_in_pcm_frames(const ma_audio_buffer_ref* pAudioBufferRef, ma_uint64* pCursor);
    ma_result raia_ma_audio_buffer_ref_get_length_in_pcm_frames(const ma_audio_buffer_ref* pAudioBufferRef, ma_uint64* pLength);
    ma_result raia_ma_audio_buffer_ref_get_available_frames(const ma_audio_buffer_ref* pAudioBufferRef, ma_uint64* pAvailableFrames);
    ma_audio_buffer_config raia_ma_audio_buffer_config_init(ma_format format, ma_uint32 channels, ma_uint64 sizeInFrames, const void* pData, const ma_allocation_callbacks* pAllocationCallbacks);
    ma_result raia_ma_audio_buffer_init(const ma_audio_buffer_config* pConfig, ma_audio_buffer* pAudioBuffer);
    ma_result raia_ma_audio_buffer_init_copy(const ma_audio_buffer_config* pConfig, ma_audio_buffer* pAudioBuffer);
    ma_result raia_ma_audio_buffer_alloc_and_init(const ma_audio_buffer_config* pConfig, ma_audio_buffer** ppAudioBuffer);
    void raia_ma_audio_buffer_uninit(ma_audio_buffer* pAudioBuffer);
    void raia_ma_audio_buffer_uninit_and_free(ma_audio_buffer* pAudioBuffer);
    ma_uint64 raia_ma_audio_buffer_read_pcm_frames(ma_audio_buffer* pAudioBuffer, void* pFramesOut, ma_uint64 frameCount, ma_bool32 loop);
    ma_result raia_ma_audio_buffer_seek_to_pcm_frame(ma_audio_buffer* pAudioBuffer, ma_uint64 frameIndex);
    ma_result raia_ma_audio_buffer_map(ma_audio_buffer* pAudioBuffer, void** ppFramesOut, ma_uint64* pFrameCount);
    ma_result raia_ma_audio_buffer_unmap(ma_audio_buffer* pAudioBuffer, ma_uint64 frameCount);
    ma_bool32 raia_ma_audio_buffer_at_end(const ma_audio_buffer* pAudioBuffer);
    ma_result raia_ma_audio_buffer_get_cursor_in_pcm_frames(const ma_audio_buffer* pAudioBuffer, ma_uint64* pCursor);
    ma_result raia_ma_audio_buffer_get_length_in_pcm_frames(const ma_audio_buffer* pAudioBuffer, ma_uint64* pLength);
    ma_result raia_ma_audio_buffer_get_available_frames(const ma_audio_buffer* pAudioBuffer, ma_uint64* pAvailableFrames);

    // Ring Buffer
    ma_result raia_ma_paged_audio_buffer_data_init(ma_format format, ma_uint32 channels, ma_paged_audio_buffer_data* pData);
    void raia_ma_paged_audio_buffer_data_uninit(ma_paged_audio_buffer_data* pData, const ma_allocation_callbacks* pAllocationCallbacks);
    ma_paged_audio_buffer_page* raia_ma_paged_audio_buffer_data_get_head(ma_paged_audio_buffer_data* pData);
    ma_paged_audio_buffer_page* raia_ma_paged_audio_buffer_data_get_tail(ma_paged_audio_buffer_data* pData);
    ma_result raia_ma_paged_audio_buffer_data_get_length_in_pcm_frames(ma_paged_audio_buffer_data* pData, ma_uint64* pLength);
    ma_result raia_ma_paged_audio_buffer_data_allocate_page(ma_paged_audio_buffer_data* pData, ma_uint64 pageSizeInFrames, const void* pInitialData, const ma_allocation_callbacks* pAllocationCallbacks, ma_paged_audio_buffer_page** ppPage);
    ma_result raia_ma_paged_audio_buffer_data_free_page(ma_paged_audio_buffer_data* pData, ma_paged_audio_buffer_page* pPage, const ma_allocation_callbacks* pAllocationCallbacks);
    ma_result raia_ma_paged_audio_buffer_data_append_page(ma_paged_audio_buffer_data* pData, ma_paged_audio_buffer_page* pPage);
    ma_result raia_ma_paged_audio_buffer_data_allocate_and_append_page(ma_paged_audio_buffer_data* pData, ma_uint32 pageSizeInFrames, const void* pInitialData, const ma_allocation_callbacks* pAllocationCallbacks);
    ma_paged_audio_buffer_config raia_ma_paged_audio_buffer_config_init(ma_paged_audio_buffer_data* pData);
    ma_result raia_ma_paged_audio_buffer_init(const ma_paged_audio_buffer_config* pConfig, ma_paged_audio_buffer* pPagedAudioBuffer);
    void raia_ma_paged_audio_buffer_uninit(ma_paged_audio_buffer* pPagedAudioBuffer);
    ma_result raia_ma_paged_audio_buffer_read_pcm_frames(ma_paged_audio_buffer* pPagedAudioBuffer, void* pFramesOut, ma_uint64 frameCount, ma_uint64* pFramesRead);
    ma_result raia_ma_paged_audio_buffer_seek_to_pcm_frame(ma_paged_audio_buffer* pPagedAudioBuffer, ma_uint64 frameIndex);
    ma_result raia_ma_paged_audio_buffer_get_cursor_in_pcm_frames(ma_paged_audio_buffer* pPagedAudioBuffer, ma_uint64* pCursor);
    ma_result raia_ma_paged_audio_buffer_get_length_in_pcm_frames(ma_paged_audio_buffer* pPagedAudioBuffer, ma_uint64* pLength);

    // Ring Buffer
    ma_result raia_ma_rb_init_ex(size_t subbufferSizeInBytes, size_t subbufferCount, size_t subbufferStrideInBytes, void* pOptionalPreallocatedBuffer, const ma_allocation_callbacks* pAllocationCallbacks, ma_rb* pRB);
    ma_result raia_ma_rb_init(size_t bufferSizeInBytes, void* pOptionalPreallocatedBuffer, const ma_allocation_callbacks* pAllocationCallbacks, ma_rb* pRB);
    void raia_ma_rb_uninit(ma_rb* pRB);
    void raia_ma_rb_reset(ma_rb* pRB);
    ma_result raia_ma_rb_acquire_read(ma_rb* pRB, size_t* pSizeInBytes, void** ppBufferOut);
    ma_result raia_ma_rb_commit_read(ma_rb* pRB, size_t sizeInBytes);
    ma_result raia_ma_rb_acquire_write(ma_rb* pRB, size_t* pSizeInBytes, void** ppBufferOut);
    ma_result raia_ma_rb_commit_write(ma_rb* pRB, size_t sizeInBytes);
    ma_result raia_ma_rb_seek_read(ma_rb* pRB, size_t offsetInBytes);
    ma_result raia_ma_rb_seek_write(ma_rb* pRB, size_t offsetInBytes);
    ma_int32 raia_ma_rb_pointer_distance(ma_rb* pRB);
    ma_uint32 raia_ma_rb_available_read(ma_rb* pRB);
    ma_uint32 raia_ma_rb_available_write(ma_rb* pRB);
    size_t raia_ma_rb_get_subbuffer_size(ma_rb* pRB);
    size_t raia_ma_rb_get_subbuffer_stride(ma_rb* pRB);
    size_t raia_ma_rb_get_subbuffer_offset(ma_rb* pRB, size_t subbufferIndex);
    void* raia_ma_rb_get_subbuffer_ptr(ma_rb* pRB, size_t subbufferIndex, void* pBuffer);
    ma_result raia_ma_pcm_rb_init_ex(ma_format format, ma_uint32 channels, ma_uint32 subbufferSizeInFrames, ma_uint32 subbufferCount, ma_uint32 subbufferStrideInFrames, void* pOptionalPreallocatedBuffer, const ma_allocation_callbacks* pAllocationCallbacks, ma_pcm_rb* pRB);
    ma_result raia_ma_pcm_rb_init(ma_format format, ma_uint32 channels, ma_uint32 bufferSizeInFrames, void* pOptionalPreallocatedBuffer, const ma_allocation_callbacks* pAllocationCallbacks, ma_pcm_rb* pRB);
    void raia_ma_pcm_rb_uninit(ma_pcm_rb* pRB);
    void raia_ma_pcm_rb_reset(ma_pcm_rb* pRB);
    ma_result raia_ma_pcm_rb_acquire_read(ma_pcm_rb* pRB, ma_uint32* pSizeInFrames, void** ppBufferOut);
    ma_result raia_ma_pcm_rb_commit_read(ma_pcm_rb* pRB, ma_uint32 sizeInFrames);
    ma_result raia_ma_pcm_rb_acquire_write(ma_pcm_rb* pRB, ma_uint32* pSizeInFrames, void** ppBufferOut);
    ma_result raia_ma_pcm_rb_commit_write(ma_pcm_rb* pRB, ma_uint32 sizeInFrames);
    ma_result raia_ma_pcm_rb_seek_read(ma_pcm_rb* pRB, ma_uint32 offsetInFrames);
    ma_result raia_ma_pcm_rb_seek_write(ma_pcm_rb* pRB, ma_uint32 offsetInFrames);
    ma_int32 raia_ma_pcm_rb_pointer_distance(ma_pcm_rb* pRB);
    ma_uint32 raia_ma_pcm_rb_available_read(ma_pcm_rb* pRB);
    ma_uint32 raia_ma_pcm_rb_available_write(ma_pcm_rb* pRB);
    ma_uint32 raia_ma_pcm_rb_get_subbuffer_size(ma_pcm_rb* pRB);
    ma_uint32 raia_ma_pcm_rb_get_subbuffer_stride(ma_pcm_rb* pRB);
    ma_uint32 raia_ma_pcm_rb_get_subbuffer_offset(ma_pcm_rb* pRB, ma_uint32 subbufferIndex);
    void* raia_ma_pcm_rb_get_subbuffer_ptr(ma_pcm_rb* pRB, ma_uint32 subbufferIndex, void* pBuffer);
    ma_format raia_ma_pcm_rb_get_format(const ma_pcm_rb* pRB);
    ma_uint32 raia_ma_pcm_rb_get_channels(const ma_pcm_rb* pRB);
    ma_uint32 raia_ma_pcm_rb_get_sample_rate(const ma_pcm_rb* pRB);
    void raia_ma_pcm_rb_set_sample_rate(ma_pcm_rb* pRB, ma_uint32 sampleRate);
    ma_result raia_ma_duplex_rb_init(ma_format captureFormat, ma_uint32 captureChannels, ma_uint32 sampleRate, ma_uint32 captureInternalSampleRate, ma_uint32 captureInternalPeriodSizeInFrames, const ma_allocation_callbacks* pAllocationCallbacks, ma_duplex_rb* pRB);
    ma_result raia_ma_duplex_rb_uninit(ma_duplex_rb* pRB);

    // Miscellaneous Helpers
    const char* raia_ma_result_description(ma_result result);
    void* raia_ma_malloc(size_t sz, const ma_allocation_callbacks* pAllocationCallbacks);
    void* raia_ma_calloc(size_t sz, const ma_allocation_callbacks* pAllocationCallbacks);
    void* raia_ma_realloc(void* p, size_t sz, const ma_allocation_callbacks* pAllocationCallbacks);
    void raia_ma_free(void* p, const ma_allocation_callbacks* pAllocationCallbacks);
    void* raia_ma_aligned_malloc(size_t sz, size_t alignment, const ma_allocation_callbacks* pAllocationCallbacks);
    void raia_ma_aligned_free(void* p, const ma_allocation_callbacks* pAllocationCallbacks);
    const char* raia_ma_get_format_name(ma_format format);
    void raia_ma_blend_f32(float* pOut, float* pInA, float* pInB, float factor, ma_uint32 channels);
    ma_uint32 raia_ma_get_bytes_per_sample(ma_format format);
    const char* raia_ma_log_level_to_string(ma_uint32 logLevel);

    // Synchronization
    ma_result raia_ma_spinlock_lock(volatile ma_spinlock* pSpinlock);
    ma_result raia_ma_spinlock_lock_noyield(volatile ma_spinlock* pSpinlock);
    ma_result raia_ma_spinlock_unlock(volatile ma_spinlock* pSpinlock);
    ma_result raia_ma_mutex_init(ma_mutex* pMutex);
    void raia_ma_mutex_uninit(ma_mutex* pMutex);
    void raia_ma_mutex_lock(ma_mutex* pMutex);
    void raia_ma_mutex_unlock(ma_mutex* pMutex);
    ma_result raia_ma_event_init(ma_event* pEvent);
    void raia_ma_event_uninit(ma_event* pEvent);
    ma_result raia_ma_event_wait(ma_event* pEvent);
    ma_result raia_ma_event_signal(ma_event* pEvent);

    // Fence
    ma_result raia_ma_fence_init(ma_fence* pFence);
    void raia_ma_fence_uninit(ma_fence* pFence);
    ma_result raia_ma_fence_acquire(ma_fence* pFence);
    ma_result raia_ma_fence_release(ma_fence* pFence);
    ma_result raia_ma_fence_wait(ma_fence* pFence);

    // Notification callback
    ma_result raia_ma_async_notification_signal(ma_async_notification* pNotification);

    // Simple polling notification
    ma_result raia_ma_async_notification_poll_init(ma_async_notification_poll* pNotificationPoll);
    ma_bool32 raia_ma_async_notification_poll_is_signalled(const ma_async_notification_poll* pNotificationPoll);

    // Event Notification
    ma_result raia_ma_async_notification_event_init(ma_async_notification_event* pNotificationEvent);
    ma_result raia_ma_async_notification_event_uninit(ma_async_notification_event* pNotificationEvent);
    ma_result raia_ma_async_notification_event_wait(ma_async_notification_event* pNotificationEvent);
    ma_result raia_ma_async_notification_event_signal(ma_async_notification_event* pNotificationEvent);

    // Slot Allocator
    ma_slot_allocator_config raia_ma_slot_allocator_config_init(ma_uint32 capacity);
    ma_result raia_ma_slot_allocator_get_heap_size(const ma_slot_allocator_config* pConfig, size_t* pHeapSizeInBytes);
    ma_result raia_ma_slot_allocator_init_preallocated(const ma_slot_allocator_config* pConfig, void* pHeap, ma_slot_allocator* pAllocator);
    ma_result raia_ma_slot_allocator_init(const ma_slot_allocator_config* pConfig, const ma_allocation_callbacks* pAllocationCallbacks, ma_slot_allocator* pAllocator);
    void raia_ma_slot_allocator_uninit(ma_slot_allocator* pAllocator, const ma_allocation_callbacks* pAllocationCallbacks);
    ma_result raia_ma_slot_allocator_alloc(ma_slot_allocator* pAllocator, ma_uint64* pSlot);
    ma_result raia_ma_slot_allocator_free(ma_slot_allocator* pAllocator, ma_uint64 slot);
    ma_job raia_ma_job_init(ma_uint16 code);
    ma_result raia_ma_job_process(ma_job* pJob);
    ma_job_queue_config raia_ma_job_queue_config_init(ma_uint32 flags, ma_uint32 capacity);
    ma_result raia_ma_job_queue_get_heap_size(const ma_job_queue_config* pConfig, size_t* pHeapSizeInBytes);
    ma_result raia_ma_job_queue_init_preallocated(const ma_job_queue_config* pConfig, void* pHeap, ma_job_queue* pQueue);
    ma_result raia_ma_job_queue_init(const ma_job_queue_config* pConfig, const ma_allocation_callbacks* pAllocationCallbacks, ma_job_queue* pQueue);
    void raia_ma_job_queue_uninit(ma_job_queue* pQueue, const ma_allocation_callbacks* pAllocationCallbacks);
    ma_result raia_ma_job_queue_post(ma_job_queue* pQueue, const ma_job* pJob);
    ma_result raia_ma_job_queue_next(ma_job_queue* pQueue, ma_job* pJob);

    // DEVICE I/O
    ma_device_job_thread_config raia_ma_device_job_thread_config_init(void);
    ma_result raia_ma_device_job_thread_init(const ma_device_job_thread_config* pConfig, const ma_allocation_callbacks* pAllocationCallbacks, ma_device_job_thread* pJobThread);
    void raia_ma_device_job_thread_uninit(ma_device_job_thread* pJobThread, const ma_allocation_callbacks* pAllocationCallbacks);
    ma_result raia_ma_device_job_thread_post(ma_device_job_thread* pJobThread, const ma_job* pJob);
    ma_result raia_ma_device_job_thread_next(ma_device_job_thread* pJobThread, ma_job* pJob);
    //---
    ma_context_config raia_ma_context_config_init(void);
    ma_result raia_ma_context_init(const ma_backend backends[], ma_uint32 backendCount, const ma_context_config* pConfig, ma_context* pContext);
    ma_result raia_ma_context_uninit(ma_context* pContext);
    size_t raia_ma_context_sizeof(void);
    ma_log* raia_ma_context_get_log(ma_context* pContext);
    ma_result raia_ma_context_enumerate_devices(ma_context* pContext, ma_enum_devices_callback_proc callback, void* pUserData);
    ma_result raia_ma_context_get_devices(ma_context* pContext, ma_device_info** ppPlaybackDeviceInfos, ma_uint32* pPlaybackDeviceCount, ma_device_info** ppCaptureDeviceInfos, ma_uint32* pCaptureDeviceCount);
    ma_result raia_ma_context_get_device_info(ma_context* pContext, ma_device_type deviceType, const ma_device_id* pDeviceID, ma_device_info* pDeviceInfo);
    ma_bool32 raia_ma_context_is_loopback_supported(ma_context* pContext);
    ma_device_config raia_ma_device_config_init(ma_device_type deviceType);
    ma_result raia_ma_device_init(ma_context* pContext, const ma_device_config* pConfig, ma_device* pDevice);
    ma_result raia_ma_device_init_ex(const ma_backend backends[], ma_uint32 backendCount, const ma_context_config* pContextConfig, const ma_device_config* pConfig, ma_device* pDevice);
    void raia_ma_device_uninit(ma_device* pDevice);
    ma_context* raia_ma_device_get_context(ma_device* pDevice);
    ma_log* raia_ma_device_get_log(ma_device* pDevice);
    ma_result raia_ma_device_get_info(ma_device* pDevice, ma_device_type type, ma_device_info* pDeviceInfo);
    ma_result raia_ma_device_get_name(ma_device* pDevice, ma_device_type type, char* pName, size_t nameCap, size_t* pLengthNotIncludingNullTerminator);
    ma_result raia_ma_device_start(ma_device* pDevice);
    ma_result raia_ma_device_stop(ma_device* pDevice);
    ma_bool32 raia_ma_device_is_started(const ma_device* pDevice);
    ma_device_state raia_ma_device_get_state(const ma_device* pDevice);
    ma_result raia_ma_device_post_init(ma_device* pDevice, ma_device_type deviceType, const ma_device_descriptor* pPlaybackDescriptor, const ma_device_descriptor* pCaptureDescriptor);
    ma_result raia_ma_device_set_master_volume(ma_device* pDevice, float volume);
    ma_result raia_ma_device_get_master_volume(ma_device* pDevice, float* pVolume);
    ma_result raia_ma_device_set_master_volume_db(ma_device* pDevice, float gainDB);
    ma_result raia_ma_device_get_master_volume_db(ma_device* pDevice, float* pGainDB);
    ma_result raia_ma_device_handle_backend_data_callback(ma_device* pDevice, void* pOutput, const void* pInput, ma_uint32 frameCount);
    ma_uint32 raia_ma_calculate_buffer_size_in_frames_from_descriptor(const ma_device_descriptor* pDescriptor, ma_uint32 nativeSampleRate, ma_performance_profile performanceProfile);
    const char* raia_ma_get_backend_name(ma_backend backend);
    ma_result raia_ma_get_backend_from_name(const char* pBackendName, ma_backend* pBackend);
    ma_bool32 raia_ma_is_backend_enabled(ma_backend backend);
    ma_result raia_ma_get_enabled_backends(ma_backend* pBackends, size_t backendCap, size_t* pBackendCount);
    ma_bool32 raia_ma_is_loopback_supported(ma_backend backend);

    // Utilities
    ma_uint32 raia_ma_calculate_buffer_size_in_milliseconds_from_frames(ma_uint32 bufferSizeInFrames, ma_uint32 sampleRate);
    ma_uint32 raia_ma_calculate_buffer_size_in_frames_from_milliseconds(ma_uint32 bufferSizeInMilliseconds, ma_uint32 sampleRate);
    void raia_ma_copy_pcm_frames(void* dst, const void* src, ma_uint64 frameCount, ma_format format, ma_uint32 channels);
    void raia_ma_silence_pcm_frames(void* p, ma_uint64 frameCount, ma_format format, ma_uint32 channels);
    void* raia_ma_offset_pcm_frames_ptr(void* p, ma_uint64 offsetInFrames, ma_format format, ma_uint32 channels);
    const void* raia_ma_offset_pcm_frames_const_ptr(const void* p, ma_uint64 offsetInFrames, ma_format format, ma_uint32 channels);
    void raia_ma_clip_samples_u8(ma_uint8* pDst, const ma_int16* pSrc, ma_uint64 count);
    void raia_ma_clip_samples_s16(ma_int16* pDst, const ma_int32* pSrc, ma_uint64 count);
    void raia_ma_clip_samples_s24(ma_uint8* pDst, const ma_int64* pSrc, ma_uint64 count);
    void raia_ma_clip_samples_s32(ma_int32* pDst, const ma_int64* pSrc, ma_uint64 count);
    void raia_ma_clip_samples_f32(float* pDst, const float* pSrc, ma_uint64 count);
    void raia_ma_clip_pcm_frames(void* pDst, const void* pSrc, ma_uint64 frameCount, ma_format format, ma_uint32 channels);
    void raia_ma_copy_and_apply_volume_factor_u8(ma_uint8* pSamplesOut, const ma_uint8* pSamplesIn, ma_uint64 sampleCount, float factor);
    void raia_ma_copy_and_apply_volume_factor_s16(ma_int16* pSamplesOut, const ma_int16* pSamplesIn, ma_uint64 sampleCount, float factor);
    void raia_ma_copy_and_apply_volume_factor_s24(void* pSamplesOut, const void* pSamplesIn, ma_uint64 sampleCount, float factor);
    void raia_ma_copy_and_apply_volume_factor_s32(ma_int32* pSamplesOut, const ma_int32* pSamplesIn, ma_uint64 sampleCount, float factor);
    void raia_ma_copy_and_apply_volume_factor_f32(float* pSamplesOut, const float* pSamplesIn, ma_uint64 sampleCount, float factor);
    void raia_ma_apply_volume_factor_u8(ma_uint8* pSamples, ma_uint64 sampleCount, float factor);
    void raia_ma_apply_volume_factor_s16(ma_int16* pSamples, ma_uint64 sampleCount, float factor);
    void raia_ma_apply_volume_factor_s24(void* pSamples, ma_uint64 sampleCount, float factor);
    void raia_ma_apply_volume_factor_s32(ma_int32* pSamples, ma_uint64 sampleCount, float factor);
    void raia_ma_apply_volume_factor_f32(float* pSamples, ma_uint64 sampleCount, float factor);
    void raia_ma_copy_and_apply_volume_factor_pcm_frames_u8(ma_uint8* pFramesOut, const ma_uint8* pFramesIn, ma_uint64 frameCount, ma_uint32 channels, float factor);
    void raia_ma_copy_and_apply_volume_factor_pcm_frames_s16(ma_int16* pFramesOut, const ma_int16* pFramesIn, ma_uint64 frameCount, ma_uint32 channels, float factor);
    void raia_ma_copy_and_apply_volume_factor_pcm_frames_s24(void* pFramesOut, const void* pFramesIn, ma_uint64 frameCount, ma_uint32 channels, float factor);
    void raia_ma_copy_and_apply_volume_factor_pcm_frames_s32(ma_int32* pFramesOut, const ma_int32* pFramesIn, ma_uint64 frameCount, ma_uint32 channels, float factor);
    void raia_ma_copy_and_apply_volume_factor_pcm_frames_f32(float* pFramesOut, const float* pFramesIn, ma_uint64 frameCount, ma_uint32 channels, float factor);
    void raia_ma_copy_and_apply_volume_factor_pcm_frames(void* pFramesOut, const void* pFramesIn, ma_uint64 frameCount, ma_format format, ma_uint32 channels, float factor);
    void raia_ma_apply_volume_factor_pcm_frames_u8(ma_uint8* pFrames, ma_uint64 frameCount, ma_uint32 channels, float factor);
    void raia_ma_apply_volume_factor_pcm_frames_s16(ma_int16* pFrames, ma_uint64 frameCount, ma_uint32 channels, float factor);
    void raia_ma_apply_volume_factor_pcm_frames_s24(void* pFrames, ma_uint64 frameCount, ma_uint32 channels, float factor);
    void raia_ma_apply_volume_factor_pcm_frames_s32(ma_int32* pFrames, ma_uint64 frameCount, ma_uint32 channels, float factor);
    void raia_ma_apply_volume_factor_pcm_frames_f32(float* pFrames, ma_uint64 frameCount, ma_uint32 channels, float factor);
    void raia_ma_apply_volume_factor_pcm_frames(void* pFrames, ma_uint64 frameCount, ma_format format, ma_uint32 channels, float factor);
    void raia_ma_copy_and_apply_volume_factor_per_channel_f32(float* pFramesOut, const float* pFramesIn, ma_uint64 frameCount, ma_uint32 channels, float* pChannelGains);
    void raia_ma_copy_and_apply_volume_and_clip_samples_u8(ma_uint8* pDst, const ma_int16* pSrc, ma_uint64 count, float volume);
    void raia_ma_copy_and_apply_volume_and_clip_samples_s16(ma_int16* pDst, const ma_int32* pSrc, ma_uint64 count, float volume);
    void raia_ma_copy_and_apply_volume_and_clip_samples_s24(ma_uint8* pDst, const ma_int64* pSrc, ma_uint64 count, float volume);
    void raia_ma_copy_and_apply_volume_and_clip_samples_s32(ma_int32* pDst, const ma_int64* pSrc, ma_uint64 count, float volume);
    void raia_ma_copy_and_apply_volume_and_clip_samples_f32(float* pDst, const float* pSrc, ma_uint64 count, float volume);
    void raia_ma_copy_and_apply_volume_and_clip_pcm_frames(void* pDst, const void* pSrc, ma_uint64 frameCount, ma_format format, ma_uint32 channels, float volume);
    float raia_ma_volume_linear_to_db(float factor);
    float raia_ma_volume_db_to_linear(float gain);
    ma_result raia_ma_mix_pcm_frames_f32(float* pDst, const float* pSrc, ma_uint64 frameCount, ma_uint32 channels, float volume);

    // VFS
    ma_result raia_ma_vfs_open(ma_vfs* pVFS, const char* pFilePath, ma_uint32 openMode, ma_vfs_file* pFile);
    ma_result raia_ma_vfs_open_w(ma_vfs* pVFS, const wchar_t* pFilePath, ma_uint32 openMode, ma_vfs_file* pFile);
    ma_result raia_ma_vfs_close(ma_vfs* pVFS, ma_vfs_file file);
    ma_result raia_ma_vfs_read(ma_vfs* pVFS, ma_vfs_file file, void* pDst, size_t sizeInBytes, size_t* pBytesRead);
    ma_result raia_ma_vfs_write(ma_vfs* pVFS, ma_vfs_file file, const void* pSrc, size_t sizeInBytes, size_t* pBytesWritten);
    ma_result raia_ma_vfs_seek(ma_vfs* pVFS, ma_vfs_file file, ma_int64 offset, ma_seek_origin origin);
    ma_result raia_ma_vfs_tell(ma_vfs* pVFS, ma_vfs_file file, ma_int64* pCursor);
    ma_result raia_ma_vfs_info(ma_vfs* pVFS, ma_vfs_file file, ma_file_info* pInfo);
    ma_result raia_ma_vfs_open_and_read_file(ma_vfs* pVFS, const char* pFilePath, void** ppData, size_t* pSize, const ma_allocation_callbacks* pAllocationCallbacks);
    ma_result raia_ma_default_vfs_init(ma_default_vfs* pVFS, const ma_allocation_callbacks* pAllocationCallbacks);

    // Decoding
    ma_decoding_backend_config raia_ma_decoding_backend_config_init(ma_format preferredFormat, ma_uint32 seekPointCount);
    ma_decoder_config raia_ma_decoder_config_init(ma_format outputFormat, ma_uint32 outputChannels, ma_uint32 outputSampleRate);
    ma_decoder_config raia_ma_decoder_config_init_default(void);
    ma_result raia_ma_decoder_init(ma_decoder_read_proc onRead, ma_decoder_seek_proc onSeek, void* pUserData, const ma_decoder_config* pConfig, ma_decoder* pDecoder);
    ma_result raia_ma_decoder_init_memory(const void* pData, size_t dataSize, const ma_decoder_config* pConfig, ma_decoder* pDecoder);
    ma_result raia_ma_decoder_init_vfs(ma_vfs* pVFS, const char* pFilePath, const ma_decoder_config* pConfig, ma_decoder* pDecoder);
    ma_result raia_ma_decoder_init_vfs_w(ma_vfs* pVFS, const wchar_t* pFilePath, const ma_decoder_config* pConfig, ma_decoder* pDecoder);
    ma_result raia_ma_decoder_init_file(const char* pFilePath, const ma_decoder_config* pConfig, ma_decoder* pDecoder);
    ma_result raia_ma_decoder_init_file_w(const wchar_t* pFilePath, const ma_decoder_config* pConfig, ma_decoder* pDecoder);
    ma_result raia_ma_decoder_uninit(ma_decoder* pDecoder);
    ma_result raia_ma_decoder_read_pcm_frames(ma_decoder* pDecoder, void* pFramesOut, ma_uint64 frameCount, ma_uint64* pFramesRead);
    ma_result raia_ma_decoder_seek_to_pcm_frame(ma_decoder* pDecoder, ma_uint64 frameIndex);
    ma_result raia_ma_decoder_get_data_format(ma_decoder* pDecoder, ma_format* pFormat, ma_uint32* pChannels, ma_uint32* pSampleRate, ma_channel* pChannelMap, size_t channelMapCap);
    ma_result raia_ma_decoder_get_cursor_in_pcm_frames(ma_decoder* pDecoder, ma_uint64* pCursor);
    ma_result raia_ma_decoder_get_length_in_pcm_frames(ma_decoder* pDecoder, ma_uint64* pLength);
    ma_result raia_ma_decoder_get_available_frames(ma_decoder* pDecoder, ma_uint64* pAvailableFrames);
    ma_result raia_ma_decode_from_vfs(ma_vfs* pVFS, const char* pFilePath, ma_decoder_config* pConfig, ma_uint64* pFrameCountOut, void** ppPCMFramesOut);
    ma_result raia_ma_decode_file(const char* pFilePath, ma_decoder_config* pConfig, ma_uint64* pFrameCountOut, void** ppPCMFramesOut);
    ma_result raia_ma_decode_memory(const void* pData, size_t dataSize, ma_decoder_config* pConfig, ma_uint64* pFrameCountOut, void** ppPCMFramesOut);

    // Encoding
    ma_encoder_config raia_ma_encoder_config_init(ma_encoding_format encodingFormat, ma_format format, ma_uint32 channels, ma_uint32 sampleRate);
    ma_result raia_ma_encoder_init(ma_encoder_write_proc onWrite, ma_encoder_seek_proc onSeek, void* pUserData, const ma_encoder_config* pConfig, ma_encoder* pEncoder);
    ma_result raia_ma_encoder_init_vfs(ma_vfs* pVFS, const char* pFilePath, const ma_encoder_config* pConfig, ma_encoder* pEncoder);
    ma_result raia_ma_encoder_init_vfs_w(ma_vfs* pVFS, const wchar_t* pFilePath, const ma_encoder_config* pConfig, ma_encoder* pEncoder);
    ma_result raia_ma_encoder_init_file(const char* pFilePath, const ma_encoder_config* pConfig, ma_encoder* pEncoder);
    ma_result raia_ma_encoder_init_file_w(const wchar_t* pFilePath, const ma_encoder_config* pConfig, ma_encoder* pEncoder);
    void raia_ma_encoder_uninit(ma_encoder* pEncoder);
    ma_result raia_ma_encoder_write_pcm_frames(ma_encoder* pEncoder, const void* pFramesIn, ma_uint64 frameCount, ma_uint64* pFramesWritten);

    // Generation
    ma_waveform_config raia_ma_waveform_config_init(ma_format format, ma_uint32 channels, ma_uint32 sampleRate, ma_waveform_type type, double amplitude, double frequency);
    ma_result raia_ma_waveform_init(const ma_waveform_config* pConfig, ma_waveform* pWaveform);
    void raia_ma_waveform_uninit(ma_waveform* pWaveform);
    ma_result raia_ma_waveform_read_pcm_frames(ma_waveform* pWaveform, void* pFramesOut, ma_uint64 frameCount, ma_uint64* pFramesRead);
    ma_result raia_ma_waveform_seek_to_pcm_frame(ma_waveform* pWaveform, ma_uint64 frameIndex);
    ma_result raia_ma_waveform_set_amplitude(ma_waveform* pWaveform, double amplitude);
    ma_result raia_ma_waveform_set_frequency(ma_waveform* pWaveform, double frequency);
    ma_result raia_ma_waveform_set_type(ma_waveform* pWaveform, ma_waveform_type type);
    ma_result raia_ma_waveform_set_sample_rate(ma_waveform* pWaveform, ma_uint32 sampleRate);
    ma_pulsewave_config raia_ma_pulsewave_config_init(ma_format format, ma_uint32 channels, ma_uint32 sampleRate, double dutyCycle, double amplitude, double frequency);
    ma_result raia_ma_pulsewave_init(const ma_pulsewave_config* pConfig, ma_pulsewave* pWaveform);
    void raia_ma_pulsewave_uninit(ma_pulsewave* pWaveform);
    ma_result raia_ma_pulsewave_read_pcm_frames(ma_pulsewave* pWaveform, void* pFramesOut, ma_uint64 frameCount, ma_uint64* pFramesRead);
    ma_result raia_ma_pulsewave_seek_to_pcm_frame(ma_pulsewave* pWaveform, ma_uint64 frameIndex);
    ma_result raia_ma_pulsewave_set_amplitude(ma_pulsewave* pWaveform, double amplitude);
    ma_result raia_ma_pulsewave_set_frequency(ma_pulsewave* pWaveform, double frequency);
    ma_result raia_ma_pulsewave_set_sample_rate(ma_pulsewave* pWaveform, ma_uint32 sampleRate);
    ma_result raia_ma_pulsewave_set_duty_cycle(ma_pulsewave* pWaveform, double dutyCycle);
    ma_noise_config raia_ma_noise_config_init(ma_format format, ma_uint32 channels, ma_noise_type type, ma_int32 seed, double amplitude);
    ma_result raia_ma_noise_get_heap_size(const ma_noise_config* pConfig, size_t* pHeapSizeInBytes);
    ma_result raia_ma_noise_init_preallocated(const ma_noise_config* pConfig, void* pHeap, ma_noise* pNoise);
    ma_result raia_ma_noise_init(const ma_noise_config* pConfig, const ma_allocation_callbacks* pAllocationCallbacks, ma_noise* pNoise);
    void raia_ma_noise_uninit(ma_noise* pNoise, const ma_allocation_callbacks* pAllocationCallbacks);
    ma_result raia_ma_noise_read_pcm_frames(ma_noise* pNoise, void* pFramesOut, ma_uint64 frameCount, ma_uint64* pFramesRead);
    ma_result raia_ma_noise_set_amplitude(ma_noise* pNoise, double amplitude);
    ma_result raia_ma_noise_set_seed(ma_noise* pNoise, ma_int32 seed);
    ma_result raia_ma_noise_set_type(ma_noise* pNoise, ma_noise_type type);

    // Resource Manager
    ma_resource_manager_pipeline_notifications raia_ma_resource_manager_pipeline_notifications_init(void);
    ma_resource_manager_data_source_config raia_ma_resource_manager_data_source_config_init(void);
    ma_resource_manager_config raia_ma_resource_manager_config_init(void);
    ma_result raia_ma_resource_manager_init(const ma_resource_manager_config* pConfig, ma_resource_manager* pResourceManager);
    void raia_ma_resource_manager_uninit(ma_resource_manager* pResourceManager);
    ma_log* raia_ma_resource_manager_get_log(ma_resource_manager* pResourceManager);
    ma_result raia_ma_resource_manager_register_file(ma_resource_manager* pResourceManager, const char* pFilePath, ma_uint32 flags);
    ma_result raia_ma_resource_manager_register_file_w(ma_resource_manager* pResourceManager, const wchar_t* pFilePath, ma_uint32 flags);
    ma_result raia_ma_resource_manager_register_decoded_data(ma_resource_manager* pResourceManager, const char* pName, const void* pData, ma_uint64 frameCount, ma_format format, ma_uint32 channels, ma_uint32 sampleRate);
    ma_result raia_ma_resource_manager_register_decoded_data_w(ma_resource_manager* pResourceManager, const wchar_t* pName, const void* pData, ma_uint64 frameCount, ma_format format, ma_uint32 channels, ma_uint32 sampleRate);
    ma_result raia_ma_resource_manager_register_encoded_data(ma_resource_manager* pResourceManager, const char* pName, const void* pData, size_t sizeInBytes);
    ma_result raia_ma_resource_manager_register_encoded_data_w(ma_resource_manager* pResourceManager, const wchar_t* pName, const void* pData, size_t sizeInBytes);
    ma_result raia_ma_resource_manager_unregister_file(ma_resource_manager* pResourceManager, const char* pFilePath);
    ma_result raia_ma_resource_manager_unregister_file_w(ma_resource_manager* pResourceManager, const wchar_t* pFilePath);
    ma_result raia_ma_resource_manager_unregister_data(ma_resource_manager* pResourceManager, const char* pName);
    ma_result raia_ma_resource_manager_unregister_data_w(ma_resource_manager* pResourceManager, const wchar_t* pName);
    ma_result raia_ma_resource_manager_data_buffer_init_ex(ma_resource_manager* pResourceManager, const ma_resource_manager_data_source_config* pConfig, ma_resource_manager_data_buffer* pDataBuffer);
    ma_result raia_ma_resource_manager_data_buffer_init(ma_resource_manager* pResourceManager, const char* pFilePath, ma_uint32 flags, const ma_resource_manager_pipeline_notifications* pNotifications, ma_resource_manager_data_buffer* pDataBuffer);
    ma_result raia_ma_resource_manager_data_buffer_init_w(ma_resource_manager* pResourceManager, const wchar_t* pFilePath, ma_uint32 flags, const ma_resource_manager_pipeline_notifications* pNotifications, ma_resource_manager_data_buffer* pDataBuffer);
    ma_result raia_ma_resource_manager_data_buffer_init_copy(ma_resource_manager* pResourceManager, const ma_resource_manager_data_buffer* pExistingDataBuffer, ma_resource_manager_data_buffer* pDataBuffer);
    ma_result raia_ma_resource_manager_data_buffer_uninit(ma_resource_manager_data_buffer* pDataBuffer);
    ma_result raia_ma_resource_manager_data_buffer_read_pcm_frames(ma_resource_manager_data_buffer* pDataBuffer, void* pFramesOut, ma_uint64 frameCount, ma_uint64* pFramesRead);
    ma_result raia_ma_resource_manager_data_buffer_seek_to_pcm_frame(ma_resource_manager_data_buffer* pDataBuffer, ma_uint64 frameIndex);
    ma_result raia_ma_resource_manager_data_buffer_get_data_format(ma_resource_manager_data_buffer* pDataBuffer, ma_format* pFormat, ma_uint32* pChannels, ma_uint32* pSampleRate, ma_channel* pChannelMap, size_t channelMapCap);
    ma_result raia_ma_resource_manager_data_buffer_get_cursor_in_pcm_frames(ma_resource_manager_data_buffer* pDataBuffer, ma_uint64* pCursor);
    ma_result raia_ma_resource_manager_data_buffer_get_length_in_pcm_frames(ma_resource_manager_data_buffer* pDataBuffer, ma_uint64* pLength);
    ma_result raia_ma_resource_manager_data_buffer_result(const ma_resource_manager_data_buffer* pDataBuffer);
    ma_result raia_ma_resource_manager_data_buffer_set_looping(ma_resource_manager_data_buffer* pDataBuffer, ma_bool32 isLooping);
    ma_bool32 raia_ma_resource_manager_data_buffer_is_looping(const ma_resource_manager_data_buffer* pDataBuffer);
    ma_result raia_ma_resource_manager_data_buffer_get_available_frames(ma_resource_manager_data_buffer* pDataBuffer, ma_uint64* pAvailableFrames);
    ma_result raia_ma_resource_manager_data_stream_init_ex(ma_resource_manager* pResourceManager, const ma_resource_manager_data_source_config* pConfig, ma_resource_manager_data_stream* pDataStream);
    ma_result raia_ma_resource_manager_data_stream_init(ma_resource_manager* pResourceManager, const char* pFilePath, ma_uint32 flags, const ma_resource_manager_pipeline_notifications* pNotifications, ma_resource_manager_data_stream* pDataStream);
    ma_result raia_ma_resource_manager_data_stream_init_w(ma_resource_manager* pResourceManager, const wchar_t* pFilePath, ma_uint32 flags, const ma_resource_manager_pipeline_notifications* pNotifications, ma_resource_manager_data_stream* pDataStream);
    ma_result raia_ma_resource_manager_data_stream_uninit(ma_resource_manager_data_stream* pDataStream);
    ma_result raia_ma_resource_manager_data_stream_read_pcm_frames(ma_resource_manager_data_stream* pDataStream, void* pFramesOut, ma_uint64 frameCount, ma_uint64* pFramesRead);
    ma_result raia_ma_resource_manager_data_stream_seek_to_pcm_frame(ma_resource_manager_data_stream* pDataStream, ma_uint64 frameIndex);
    ma_result raia_ma_resource_manager_data_stream_get_data_format(ma_resource_manager_data_stream* pDataStream, ma_format* pFormat, ma_uint32* pChannels, ma_uint32* pSampleRate, ma_channel* pChannelMap, size_t channelMapCap);
    ma_result raia_ma_resource_manager_data_stream_get_cursor_in_pcm_frames(ma_resource_manager_data_stream* pDataStream, ma_uint64* pCursor);
    ma_result raia_ma_resource_manager_data_stream_get_length_in_pcm_frames(ma_resource_manager_data_stream* pDataStream, ma_uint64* pLength);
    ma_result raia_ma_resource_manager_data_stream_result(const ma_resource_manager_data_stream* pDataStream);
    ma_result raia_ma_resource_manager_data_stream_set_looping(ma_resource_manager_data_stream* pDataStream, ma_bool32 isLooping);
    ma_bool32 raia_ma_resource_manager_data_stream_is_looping(const ma_resource_manager_data_stream* pDataStream);
    ma_result raia_ma_resource_manager_data_stream_get_available_frames(ma_resource_manager_data_stream* pDataStream, ma_uint64* pAvailableFrames);
    ma_result raia_ma_resource_manager_data_source_init_ex(ma_resource_manager* pResourceManager, const ma_resource_manager_data_source_config* pConfig, ma_resource_manager_data_source* pDataSource);
    ma_result raia_ma_resource_manager_data_source_init(ma_resource_manager* pResourceManager, const char* pName, ma_uint32 flags, const ma_resource_manager_pipeline_notifications* pNotifications, ma_resource_manager_data_source* pDataSource);
    ma_result raia_ma_resource_manager_data_source_init_w(ma_resource_manager* pResourceManager, const wchar_t* pName, ma_uint32 flags, const ma_resource_manager_pipeline_notifications* pNotifications, ma_resource_manager_data_source* pDataSource);
    ma_result raia_ma_resource_manager_data_source_init_copy(ma_resource_manager* pResourceManager, const ma_resource_manager_data_source* pExistingDataSource, ma_resource_manager_data_source* pDataSource);
    ma_result raia_ma_resource_manager_data_source_uninit(ma_resource_manager_data_source* pDataSource);
    ma_result raia_ma_resource_manager_data_source_read_pcm_frames(ma_resource_manager_data_source* pDataSource, void* pFramesOut, ma_uint64 frameCount, ma_uint64* pFramesRead);
    ma_result raia_ma_resource_manager_data_source_seek_to_pcm_frame(ma_resource_manager_data_source* pDataSource, ma_uint64 frameIndex);
    ma_result raia_ma_resource_manager_data_source_get_data_format(ma_resource_manager_data_source* pDataSource, ma_format* pFormat, ma_uint32* pChannels, ma_uint32* pSampleRate, ma_channel* pChannelMap, size_t channelMapCap);
    ma_result raia_ma_resource_manager_data_source_get_cursor_in_pcm_frames(ma_resource_manager_data_source* pDataSource, ma_uint64* pCursor);
    ma_result raia_ma_resource_manager_data_source_get_length_in_pcm_frames(ma_resource_manager_data_source* pDataSource, ma_uint64* pLength);
    ma_result raia_ma_resource_manager_data_source_result(const ma_resource_manager_data_source* pDataSource);
    ma_result raia_ma_resource_manager_data_source_set_looping(ma_resource_manager_data_source* pDataSource, ma_bool32 isLooping);
    ma_bool32 raia_ma_resource_manager_data_source_is_looping(const ma_resource_manager_data_source* pDataSource);
    ma_result raia_ma_resource_manager_data_source_get_available_frames(ma_resource_manager_data_source* pDataSource, ma_uint64* pAvailableFrames);
    ma_result raia_ma_resource_manager_post_job(ma_resource_manager* pResourceManager, const ma_job* pJob);
    ma_result raia_ma_resource_manager_post_job_quit(ma_resource_manager* pResourceManager);
    ma_result raia_ma_resource_manager_next_job(ma_resource_manager* pResourceManager, ma_job* pJob);
    ma_result raia_ma_resource_manager_process_job(ma_resource_manager* pResourceManager, ma_job* pJob);
    ma_result raia_ma_resource_manager_process_next_job(ma_resource_manager* pResourceManager);

    // Node Graph
    ma_node_config raia_ma_node_config_init(void);
    ma_result raia_ma_node_get_heap_size(ma_node_graph* pNodeGraph, const ma_node_config* pConfig, size_t* pHeapSizeInBytes);
    ma_result raia_ma_node_init_preallocated(ma_node_graph* pNodeGraph, const ma_node_config* pConfig, void* pHeap, ma_node* pNode);
    ma_result raia_ma_node_init(ma_node_graph* pNodeGraph, const ma_node_config* pConfig, const ma_allocation_callbacks* pAllocationCallbacks, ma_node* pNode);
    void raia_ma_node_uninit(ma_node* pNode, const ma_allocation_callbacks* pAllocationCallbacks);
    ma_node_graph* raia_ma_node_get_node_graph(const ma_node* pNode);
    ma_uint32 raia_ma_node_get_input_bus_count(const ma_node* pNode);
    ma_uint32 raia_ma_node_get_output_bus_count(const ma_node* pNode);
    ma_uint32 raia_ma_node_get_input_channels(const ma_node* pNode, ma_uint32 inputBusIndex);
    ma_uint32 raia_ma_node_get_output_channels(const ma_node* pNode, ma_uint32 outputBusIndex);
    ma_result raia_ma_node_attach_output_bus(ma_node* pNode, ma_uint32 outputBusIndex, ma_node* pOtherNode, ma_uint32 otherNodeInputBusIndex);
    ma_result raia_ma_node_detach_output_bus(ma_node* pNode, ma_uint32 outputBusIndex);
    ma_result raia_ma_node_detach_all_output_buses(ma_node* pNode);
    ma_result raia_ma_node_set_output_bus_volume(ma_node* pNode, ma_uint32 outputBusIndex, float volume);
    float raia_ma_node_get_output_bus_volume(const ma_node* pNode, ma_uint32 outputBusIndex);
    ma_result raia_ma_node_set_state(ma_node* pNode, ma_node_state state);
    ma_node_state raia_ma_node_get_state(const ma_node* pNode);
    ma_result raia_ma_node_set_state_time(ma_node* pNode, ma_node_state state, ma_uint64 globalTime);
    ma_uint64 raia_ma_node_get_state_time(const ma_node* pNode, ma_node_state state);
    ma_node_state raia_ma_node_get_state_by_time(const ma_node* pNode, ma_uint64 globalTime);
    ma_node_state raia_ma_node_get_state_by_time_range(const ma_node* pNode, ma_uint64 globalTimeBeg, ma_uint64 globalTimeEnd);
    ma_uint64 raia_ma_node_get_time(const ma_node* pNode);
    ma_result raia_ma_node_set_time(ma_node* pNode, ma_uint64 localTime);
    ma_node_graph_config raia_ma_node_graph_config_init(ma_uint32 channels);
    ma_result raia_ma_node_graph_init(const ma_node_graph_config* pConfig, const ma_allocation_callbacks* pAllocationCallbacks, ma_node_graph* pNodeGraph);
    void raia_ma_node_graph_uninit(ma_node_graph* pNodeGraph, const ma_allocation_callbacks* pAllocationCallbacks);
    ma_node* raia_ma_node_graph_get_endpoint(ma_node_graph* pNodeGraph);
    ma_result raia_ma_node_graph_read_pcm_frames(ma_node_graph* pNodeGraph, void* pFramesOut, ma_uint64 frameCount, ma_uint64* pFramesRead);
    ma_uint32 raia_ma_node_graph_get_channels(const ma_node_graph* pNodeGraph);
    ma_uint64 raia_ma_node_graph_get_time(const ma_node_graph* pNodeGraph);
    ma_result raia_ma_node_graph_set_time(ma_node_graph* pNodeGraph, ma_uint64 globalTime);
    ma_data_source_node_config raia_ma_data_source_node_config_init(ma_data_source* pDataSource);
    ma_result raia_ma_data_source_node_init(ma_node_graph* pNodeGraph, const ma_data_source_node_config* pConfig, const ma_allocation_callbacks* pAllocationCallbacks, ma_data_source_node* pDataSourceNode);
    void raia_ma_data_source_node_uninit(ma_data_source_node* pDataSourceNode, const ma_allocation_callbacks* pAllocationCallbacks);
    ma_result raia_ma_data_source_node_set_looping(ma_data_source_node* pDataSourceNode, ma_bool32 isLooping);
    ma_bool32 raia_ma_data_source_node_is_looping(ma_data_source_node* pDataSourceNode);
    ma_splitter_node_config raia_ma_splitter_node_config_init(ma_uint32 channels);
    ma_result raia_ma_splitter_node_init(ma_node_graph* pNodeGraph, const ma_splitter_node_config* pConfig, const ma_allocation_callbacks* pAllocationCallbacks, ma_splitter_node* pSplitterNode);
    void raia_ma_splitter_node_uninit(ma_splitter_node* pSplitterNode, const ma_allocation_callbacks* pAllocationCallbacks);
    ma_biquad_node_config raia_ma_biquad_node_config_init(ma_uint32 channels, float b0, float b1, float b2, float a0, float a1, float a2);
    ma_result raia_ma_biquad_node_init(ma_node_graph* pNodeGraph, const ma_biquad_node_config* pConfig, const ma_allocation_callbacks* pAllocationCallbacks, ma_biquad_node* pNode);
    ma_result raia_ma_biquad_node_reinit(const ma_biquad_config* pConfig, ma_biquad_node* pNode);
    void raia_ma_biquad_node_uninit(ma_biquad_node* pNode, const ma_allocation_callbacks* pAllocationCallbacks);
    ma_lpf_node_config raia_ma_lpf_node_config_init(ma_uint32 channels, ma_uint32 sampleRate, double cutoffFrequency, ma_uint32 order);
    ma_result raia_ma_lpf_node_init(ma_node_graph* pNodeGraph, const ma_lpf_node_config* pConfig, const ma_allocation_callbacks* pAllocationCallbacks, ma_lpf_node* pNode);
    ma_result raia_ma_lpf_node_reinit(const ma_lpf_config* pConfig, ma_lpf_node* pNode);
    void raia_ma_lpf_node_uninit(ma_lpf_node* pNode, const ma_allocation_callbacks* pAllocationCallbacks);
    ma_hpf_node_config raia_ma_hpf_node_config_init(ma_uint32 channels, ma_uint32 sampleRate, double cutoffFrequency, ma_uint32 order);
    ma_result raia_ma_hpf_node_init(ma_node_graph* pNodeGraph, const ma_hpf_node_config* pConfig, const ma_allocation_callbacks* pAllocationCallbacks, ma_hpf_node* pNode);
    ma_result raia_ma_hpf_node_reinit(const ma_hpf_config* pConfig, ma_hpf_node* pNode);
    void raia_ma_hpf_node_uninit(ma_hpf_node* pNode, const ma_allocation_callbacks* pAllocationCallbacks);
    ma_bpf_node_config raia_ma_bpf_node_config_init(ma_uint32 channels, ma_uint32 sampleRate, double cutoffFrequency, ma_uint32 order);
    ma_result raia_ma_bpf_node_init(ma_node_graph* pNodeGraph, const ma_bpf_node_config* pConfig, const ma_allocation_callbacks* pAllocationCallbacks, ma_bpf_node* pNode);
    ma_result raia_ma_bpf_node_reinit(const ma_bpf_config* pConfig, ma_bpf_node* pNode);
    void raia_ma_bpf_node_uninit(ma_bpf_node* pNode, const ma_allocation_callbacks* pAllocationCallbacks);
    ma_notch_node_config raia_ma_notch_node_config_init(ma_uint32 channels, ma_uint32 sampleRate, double q, double frequency);
    ma_result raia_ma_notch_node_init(ma_node_graph* pNodeGraph, const ma_notch_node_config* pConfig, const ma_allocation_callbacks* pAllocationCallbacks, ma_notch_node* pNode);
    ma_result raia_ma_notch_node_reinit(const ma_notch_config* pConfig, ma_notch_node* pNode);
    void raia_ma_notch_node_uninit(ma_notch_node* pNode, const ma_allocation_callbacks* pAllocationCallbacks);
    ma_peak_node_config raia_ma_peak_node_config_init(ma_uint32 channels, ma_uint32 sampleRate, double gainDB, double q, double frequency);
    ma_result raia_ma_peak_node_init(ma_node_graph* pNodeGraph, const ma_peak_node_config* pConfig, const ma_allocation_callbacks* pAllocationCallbacks, ma_peak_node* pNode);
    ma_result raia_ma_peak_node_reinit(const ma_peak_config* pConfig, ma_peak_node* pNode);
    void raia_ma_peak_node_uninit(ma_peak_node* pNode, const ma_allocation_callbacks* pAllocationCallbacks);
    ma_loshelf_node_config raia_ma_loshelf_node_config_init(ma_uint32 channels, ma_uint32 sampleRate, double gainDB, double q, double frequency);
    ma_result raia_ma_loshelf_node_init(ma_node_graph* pNodeGraph, const ma_loshelf_node_config* pConfig, const ma_allocation_callbacks* pAllocationCallbacks, ma_loshelf_node* pNode);
    ma_result raia_ma_loshelf_node_reinit(const ma_loshelf_config* pConfig, ma_loshelf_node* pNode);
    void raia_ma_loshelf_node_uninit(ma_loshelf_node* pNode, const ma_allocation_callbacks* pAllocationCallbacks);
    ma_hishelf_node_config raia_ma_hishelf_node_config_init(ma_uint32 channels, ma_uint32 sampleRate, double gainDB, double q, double frequency);
    ma_result raia_ma_hishelf_node_init(ma_node_graph* pNodeGraph, const ma_hishelf_node_config* pConfig, const ma_allocation_callbacks* pAllocationCallbacks, ma_hishelf_node* pNode);
    ma_result raia_ma_hishelf_node_reinit(const ma_hishelf_config* pConfig, ma_hishelf_node* pNode);
    void raia_ma_hishelf_node_uninit(ma_hishelf_node* pNode, const ma_allocation_callbacks* pAllocationCallbacks);
    ma_delay_node_config raia_ma_delay_node_config_init(ma_uint32 channels, ma_uint32 sampleRate, ma_uint32 delayInFrames, float decay);
    ma_result raia_ma_delay_node_init(ma_node_graph* pNodeGraph, const ma_delay_node_config* pConfig, const ma_allocation_callbacks* pAllocationCallbacks, ma_delay_node* pDelayNode);
    void raia_ma_delay_node_uninit(ma_delay_node* pDelayNode, const ma_allocation_callbacks* pAllocationCallbacks);
    void raia_ma_delay_node_set_wet(ma_delay_node* pDelayNode, float value);
    float raia_ma_delay_node_get_wet(const ma_delay_node* pDelayNode);
    void raia_ma_delay_node_set_dry(ma_delay_node* pDelayNode, float value);
    float raia_ma_delay_node_get_dry(const ma_delay_node* pDelayNode);
    void raia_ma_delay_node_set_decay(ma_delay_node* pDelayNode, float value);
    float raia_ma_delay_node_get_decay(const ma_delay_node* pDelayNode);

    // Engine
    ma_engine_node_config raia_ma_engine_node_config_init(ma_engine* pEngine, ma_engine_node_type type, ma_uint32 flags);
    ma_result raia_ma_engine_node_get_heap_size(const ma_engine_node_config* pConfig, size_t* pHeapSizeInBytes);
    ma_result raia_ma_engine_node_init_preallocated(const ma_engine_node_config* pConfig, void* pHeap, ma_engine_node* pEngineNode);
    ma_result raia_ma_engine_node_init(const ma_engine_node_config* pConfig, const ma_allocation_callbacks* pAllocationCallbacks, ma_engine_node* pEngineNode);
    void raia_ma_engine_node_uninit(ma_engine_node* pEngineNode, const ma_allocation_callbacks* pAllocationCallbacks);
    ma_sound_config raia_ma_sound_config_init(void);
    ma_sound_config raia_ma_sound_config_init_2(ma_engine* pEngine);
    ma_sound_group_config raia_ma_sound_group_config_init(void);
    ma_sound_group_config raia_ma_sound_group_config_init_2(ma_engine* pEngine);
    ma_engine_config raia_ma_engine_config_init(void);
    ma_result raia_ma_engine_init(const ma_engine_config* pConfig, ma_engine* pEngine);
    void raia_ma_engine_uninit(ma_engine* pEngine);
    ma_result raia_ma_engine_read_pcm_frames(ma_engine* pEngine, void* pFramesOut, ma_uint64 frameCount, ma_uint64* pFramesRead);
    ma_node_graph* raia_ma_engine_get_node_graph(ma_engine* pEngine);
    ma_resource_manager* raia_ma_engine_get_resource_manager(ma_engine* pEngine);
    ma_device* raia_ma_engine_get_device(ma_engine* pEngine);
    ma_log* raia_ma_engine_get_log(ma_engine* pEngine);
    ma_node* raia_ma_engine_get_endpoint(ma_engine* pEngine);
    ma_uint64 raia_ma_engine_get_time_in_pcm_frames(const ma_engine* pEngine);
    ma_uint64 raia_ma_engine_get_time_in_milliseconds(const ma_engine* pEngine);
    ma_result raia_ma_engine_set_time_in_pcm_frames(ma_engine* pEngine, ma_uint64 globalTime);
    ma_result raia_ma_engine_set_time_in_milliseconds(ma_engine* pEngine, ma_uint64 globalTime);
    ma_uint64 raia_ma_engine_get_time(const ma_engine* pEngine);
    ma_result raia_ma_engine_set_time(ma_engine* pEngine, ma_uint64 globalTime);
    ma_uint32 raia_ma_engine_get_channels(const ma_engine* pEngine);
    ma_uint32 raia_ma_engine_get_sample_rate(const ma_engine* pEngine);
    ma_result raia_ma_engine_start(ma_engine* pEngine);
    ma_result raia_ma_engine_stop(ma_engine* pEngine);
    ma_result raia_ma_engine_set_volume(ma_engine* pEngine, float volume);
    float raia_ma_engine_get_volume(ma_engine* pEngine);
    ma_result raia_ma_engine_set_gain_db(ma_engine* pEngine, float gainDB);
    float raia_ma_engine_get_gain_db(ma_engine* pEngine);
    ma_uint32 raia_ma_engine_get_listener_count(const ma_engine* pEngine);
    ma_uint32 raia_ma_engine_find_closest_listener(const ma_engine* pEngine, float absolutePosX, float absolutePosY, float absolutePosZ);
    void raia_ma_engine_listener_set_position(ma_engine* pEngine, ma_uint32 listenerIndex, float x, float y, float z);
    ma_vec3f raia_ma_engine_listener_get_position(const ma_engine* pEngine, ma_uint32 listenerIndex);
    void raia_ma_engine_listener_set_direction(ma_engine* pEngine, ma_uint32 listenerIndex, float x, float y, float z);
    ma_vec3f raia_ma_engine_listener_get_direction(const ma_engine* pEngine, ma_uint32 listenerIndex);
    void raia_ma_engine_listener_set_velocity(ma_engine* pEngine, ma_uint32 listenerIndex, float x, float y, float z);
    ma_vec3f raia_ma_engine_listener_get_velocity(const ma_engine* pEngine, ma_uint32 listenerIndex);
    void raia_ma_engine_listener_set_cone(ma_engine* pEngine, ma_uint32 listenerIndex, float innerAngleInRadians, float outerAngleInRadians, float outerGain);
    void raia_ma_engine_listener_get_cone(const ma_engine* pEngine, ma_uint32 listenerIndex, float* pInnerAngleInRadians, float* pOuterAngleInRadians, float* pOuterGain);
    void raia_ma_engine_listener_set_world_up(ma_engine* pEngine, ma_uint32 listenerIndex, float x, float y, float z);
    ma_vec3f raia_ma_engine_listener_get_world_up(const ma_engine* pEngine, ma_uint32 listenerIndex);
    void raia_ma_engine_listener_set_enabled(ma_engine* pEngine, ma_uint32 listenerIndex, ma_bool32 isEnabled);
    ma_bool32 raia_ma_engine_listener_is_enabled(const ma_engine* pEngine, ma_uint32 listenerIndex);
    ma_result raia_ma_engine_play_sound_ex(ma_engine* pEngine, const char* pFilePath, ma_node* pNode, ma_uint32 nodeInputBusIndex);
    ma_result raia_ma_engine_play_sound(ma_engine* pEngine, const char* pFilePath, ma_sound_group* pGroup);
    ma_result raia_ma_sound_init_from_file(ma_engine* pEngine, const char* pFilePath, ma_uint32 flags, ma_sound_group* pGroup, ma_fence* pDoneFence, ma_sound* pSound);
    ma_result raia_ma_sound_init_from_file_w(ma_engine* pEngine, const wchar_t* pFilePath, ma_uint32 flags, ma_sound_group* pGroup, ma_fence* pDoneFence, ma_sound* pSound);
    ma_result raia_ma_sound_init_copy(ma_engine* pEngine, const ma_sound* pExistingSound, ma_uint32 flags, ma_sound_group* pGroup, ma_sound* pSound);
    ma_result raia_ma_sound_init_from_data_source(ma_engine* pEngine, ma_data_source* pDataSource, ma_uint32 flags, ma_sound_group* pGroup, ma_sound* pSound);
    ma_result raia_ma_sound_init_ex(ma_engine* pEngine, const ma_sound_config* pConfig, ma_sound* pSound);
    void raia_ma_sound_uninit(ma_sound* pSound);
    ma_engine* raia_ma_sound_get_engine(const ma_sound* pSound);
    ma_data_source* raia_ma_sound_get_data_source(const ma_sound* pSound);
    ma_result raia_ma_sound_start(ma_sound* pSound);
    ma_result raia_ma_sound_stop(ma_sound* pSound);
    ma_result raia_ma_sound_stop_with_fade_in_pcm_frames(ma_sound* pSound, ma_uint64 fadeLengthInFrames);
    ma_result raia_ma_sound_stop_with_fade_in_milliseconds(ma_sound* pSound, ma_uint64 fadeLengthInFrames);
    void raia_ma_sound_set_volume(ma_sound* pSound, float volume);
    float raia_ma_sound_get_volume(const ma_sound* pSound);
    void raia_ma_sound_set_pan(ma_sound* pSound, float pan);
    float raia_ma_sound_get_pan(const ma_sound* pSound);
    void raia_ma_sound_set_pan_mode(ma_sound* pSound, ma_pan_mode panMode);
    ma_pan_mode raia_ma_sound_get_pan_mode(const ma_sound* pSound);
    void raia_ma_sound_set_pitch(ma_sound* pSound, float pitch);
    float raia_ma_sound_get_pitch(const ma_sound* pSound);
    void raia_ma_sound_set_spatialization_enabled(ma_sound* pSound, ma_bool32 enabled);
    ma_bool32 raia_ma_sound_is_spatialization_enabled(const ma_sound* pSound);
    void raia_ma_sound_set_pinned_listener_index(ma_sound* pSound, ma_uint32 listenerIndex);
    ma_uint32 raia_ma_sound_get_pinned_listener_index(const ma_sound* pSound);
    ma_uint32 raia_ma_sound_get_listener_index(const ma_sound* pSound);
    ma_vec3f raia_ma_sound_get_direction_to_listener(const ma_sound* pSound);
    void raia_ma_sound_set_position(ma_sound* pSound, float x, float y, float z);
    ma_vec3f raia_ma_sound_get_position(const ma_sound* pSound);
    void raia_ma_sound_set_direction(ma_sound* pSound, float x, float y, float z);
    ma_vec3f raia_ma_sound_get_direction(const ma_sound* pSound);
    void raia_ma_sound_set_velocity(ma_sound* pSound, float x, float y, float z);
    ma_vec3f raia_ma_sound_get_velocity(const ma_sound* pSound);
    void raia_ma_sound_set_attenuation_model(ma_sound* pSound, ma_attenuation_model attenuationModel);
    ma_attenuation_model raia_ma_sound_get_attenuation_model(const ma_sound* pSound);
    void raia_ma_sound_set_positioning(ma_sound* pSound, ma_positioning positioning);
    ma_positioning raia_ma_sound_get_positioning(const ma_sound* pSound);
    void raia_ma_sound_set_rolloff(ma_sound* pSound, float rolloff);
    float raia_ma_sound_get_rolloff(const ma_sound* pSound);
    void raia_ma_sound_set_min_gain(ma_sound* pSound, float minGain);
    float raia_ma_sound_get_min_gain(const ma_sound* pSound);
    void raia_ma_sound_set_max_gain(ma_sound* pSound, float maxGain);
    float raia_ma_sound_get_max_gain(const ma_sound* pSound);
    void raia_ma_sound_set_min_distance(ma_sound* pSound, float minDistance);
    float raia_ma_sound_get_min_distance(const ma_sound* pSound);
    void raia_ma_sound_set_max_distance(ma_sound* pSound, float maxDistance);
    float raia_ma_sound_get_max_distance(const ma_sound* pSound);
    void raia_ma_sound_set_cone(ma_sound* pSound, float innerAngleInRadians, float outerAngleInRadians, float outerGain);
    void raia_ma_sound_get_cone(const ma_sound* pSound, float* pInnerAngleInRadians, float* pOuterAngleInRadians, float* pOuterGain);
    void raia_ma_sound_set_doppler_factor(ma_sound* pSound, float dopplerFactor);
    float raia_ma_sound_get_doppler_factor(const ma_sound* pSound);
    void raia_ma_sound_set_directional_attenuation_factor(ma_sound* pSound, float directionalAttenuationFactor);
    float raia_ma_sound_get_directional_attenuation_factor(const ma_sound* pSound);
    void raia_ma_sound_set_fade_in_pcm_frames(ma_sound* pSound, float volumeBeg, float volumeEnd, ma_uint64 fadeLengthInFrames);
    void raia_ma_sound_set_fade_in_milliseconds(ma_sound* pSound, float volumeBeg, float volumeEnd, ma_uint64 fadeLengthInMilliseconds);
    void raia_ma_sound_set_fade_start_in_pcm_frames(ma_sound* pSound, float volumeBeg, float volumeEnd, ma_uint64 fadeLengthInFrames, ma_uint64 absoluteGlobalTimeInFrames);
    void raia_ma_sound_set_fade_start_in_milliseconds(ma_sound* pSound, float volumeBeg, float volumeEnd, ma_uint64 fadeLengthInMilliseconds, ma_uint64 absoluteGlobalTimeInMilliseconds);
    float raia_ma_sound_get_current_fade_volume(const ma_sound* pSound);
    void raia_ma_sound_set_start_time_in_pcm_frames(ma_sound* pSound, ma_uint64 absoluteGlobalTimeInFrames);
    void raia_ma_sound_set_start_time_in_milliseconds(ma_sound* pSound, ma_uint64 absoluteGlobalTimeInMilliseconds);
    void raia_ma_sound_set_stop_time_in_pcm_frames(ma_sound* pSound, ma_uint64 absoluteGlobalTimeInFrames);
    void raia_ma_sound_set_stop_time_in_milliseconds(ma_sound* pSound, ma_uint64 absoluteGlobalTimeInMilliseconds);
    void raia_ma_sound_set_stop_time_with_fade_in_pcm_frames(ma_sound* pSound, ma_uint64 stopAbsoluteGlobalTimeInFrames, ma_uint64 fadeLengthInFrames);
    void raia_ma_sound_set_stop_time_with_fade_in_milliseconds(ma_sound* pSound, ma_uint64 stopAbsoluteGlobalTimeInMilliseconds, ma_uint64 fadeLengthInMilliseconds);
    ma_bool32 raia_ma_sound_is_playing(const ma_sound* pSound);
    ma_uint64 raia_ma_sound_get_time_in_pcm_frames(const ma_sound* pSound);
    ma_uint64 raia_ma_sound_get_time_in_milliseconds(const ma_sound* pSound);
    void raia_ma_sound_set_looping(ma_sound* pSound, ma_bool32 isLooping);
    ma_bool32 raia_ma_sound_is_looping(const ma_sound* pSound);
    ma_bool32 raia_ma_sound_at_end(const ma_sound* pSound);
    ma_result raia_ma_sound_seek_to_pcm_frame(ma_sound* pSound, ma_uint64 frameIndex);
    ma_result raia_ma_sound_get_data_format(ma_sound* pSound, ma_format* pFormat, ma_uint32* pChannels, ma_uint32* pSampleRate, ma_channel* pChannelMap, size_t channelMapCap);
    ma_result raia_ma_sound_get_cursor_in_pcm_frames(ma_sound* pSound, ma_uint64* pCursor);
    ma_result raia_ma_sound_get_length_in_pcm_frames(ma_sound* pSound, ma_uint64* pLength);
    ma_result raia_ma_sound_get_cursor_in_seconds(ma_sound* pSound, float* pCursor);
    ma_result raia_ma_sound_get_length_in_seconds(ma_sound* pSound, float* pLength);
    ma_result raia_ma_sound_set_end_callback(ma_sound* pSound, ma_sound_end_proc callback, void* pUserData);
    ma_result raia_ma_sound_group_init(ma_engine* pEngine, ma_uint32 flags, ma_sound_group* pParentGroup, ma_sound_group* pGroup);
    ma_result raia_ma_sound_group_init_ex(ma_engine* pEngine, const ma_sound_group_config* pConfig, ma_sound_group* pGroup);
    void raia_ma_sound_group_uninit(ma_sound_group* pGroup);
    ma_engine* raia_ma_sound_group_get_engine(const ma_sound_group* pGroup);
    ma_result raia_ma_sound_group_start(ma_sound_group* pGroup);
    ma_result raia_ma_sound_group_stop(ma_sound_group* pGroup);
    void raia_ma_sound_group_set_volume(ma_sound_group* pGroup, float volume);
    float raia_ma_sound_group_get_volume(const ma_sound_group* pGroup);
    void raia_ma_sound_group_set_pan(ma_sound_group* pGroup, float pan);
    float raia_ma_sound_group_get_pan(const ma_sound_group* pGroup);
    void raia_ma_sound_group_set_pan_mode(ma_sound_group* pGroup, ma_pan_mode panMode);
    ma_pan_mode raia_ma_sound_group_get_pan_mode(const ma_sound_group* pGroup);
    void raia_ma_sound_group_set_pitch(ma_sound_group* pGroup, float pitch);
    float raia_ma_sound_group_get_pitch(const ma_sound_group* pGroup);
    void raia_ma_sound_group_set_spatialization_enabled(ma_sound_group* pGroup, ma_bool32 enabled);
    ma_bool32 raia_ma_sound_group_is_spatialization_enabled(const ma_sound_group* pGroup);
    void raia_ma_sound_group_set_pinned_listener_index(ma_sound_group* pGroup, ma_uint32 listenerIndex);
    ma_uint32 raia_ma_sound_group_get_pinned_listener_index(const ma_sound_group* pGroup);
    ma_uint32 raia_ma_sound_group_get_listener_index(const ma_sound_group* pGroup);
    ma_vec3f raia_ma_sound_group_get_direction_to_listener(const ma_sound_group* pGroup);
    void raia_ma_sound_group_set_position(ma_sound_group* pGroup, float x, float y, float z);
    ma_vec3f raia_ma_sound_group_get_position(const ma_sound_group* pGroup);
    void raia_ma_sound_group_set_direction(ma_sound_group* pGroup, float x, float y, float z);
    ma_vec3f raia_ma_sound_group_get_direction(const ma_sound_group* pGroup);
    void raia_ma_sound_group_set_velocity(ma_sound_group* pGroup, float x, float y, float z);
    ma_vec3f raia_ma_sound_group_get_velocity(const ma_sound_group* pGroup);
    void raia_ma_sound_group_set_attenuation_model(ma_sound_group* pGroup, ma_attenuation_model attenuationModel);
    ma_attenuation_model raia_ma_sound_group_get_attenuation_model(const ma_sound_group* pGroup);
    void raia_ma_sound_group_set_positioning(ma_sound_group* pGroup, ma_positioning positioning);
    ma_positioning raia_ma_sound_group_get_positioning(const ma_sound_group* pGroup);
    void raia_ma_sound_group_set_rolloff(ma_sound_group* pGroup, float rolloff);
    float raia_ma_sound_group_get_rolloff(const ma_sound_group* pGroup);
    void raia_ma_sound_group_set_min_gain(ma_sound_group* pGroup, float minGain);
    float raia_ma_sound_group_get_min_gain(const ma_sound_group* pGroup);
    void raia_ma_sound_group_set_max_gain(ma_sound_group* pGroup, float maxGain);
    float raia_ma_sound_group_get_max_gain(const ma_sound_group* pGroup);
    void raia_ma_sound_group_set_min_distance(ma_sound_group* pGroup, float minDistance);
    float raia_ma_sound_group_get_min_distance(const ma_sound_group* pGroup);
    void raia_ma_sound_group_set_max_distance(ma_sound_group* pGroup, float maxDistance);
    float raia_ma_sound_group_get_max_distance(const ma_sound_group* pGroup);
    void raia_ma_sound_group_set_cone(ma_sound_group* pGroup, float innerAngleInRadians, float outerAngleInRadians, float outerGain);
    void raia_ma_sound_group_get_cone(const ma_sound_group* pGroup, float* pInnerAngleInRadians, float* pOuterAngleInRadians, float* pOuterGain);
    void raia_ma_sound_group_set_doppler_factor(ma_sound_group* pGroup, float dopplerFactor);
    float raia_ma_sound_group_get_doppler_factor(const ma_sound_group* pGroup);
    void raia_ma_sound_group_set_directional_attenuation_factor(ma_sound_group* pGroup, float directionalAttenuationFactor);
    float raia_ma_sound_group_get_directional_attenuation_factor(const ma_sound_group* pGroup);
    void raia_ma_sound_group_set_fade_in_pcm_frames(ma_sound_group* pGroup, float volumeBeg, float volumeEnd, ma_uint64 fadeLengthInFrames);
    void raia_ma_sound_group_set_fade_in_milliseconds(ma_sound_group* pGroup, float volumeBeg, float volumeEnd, ma_uint64 fadeLengthInMilliseconds);
    float raia_ma_sound_group_get_current_fade_volume(ma_sound_group* pGroup);
    void raia_ma_sound_group_set_start_time_in_pcm_frames(ma_sound_group* pGroup, ma_uint64 absoluteGlobalTimeInFrames);
    void raia_ma_sound_group_set_start_time_in_milliseconds(ma_sound_group* pGroup, ma_uint64 absoluteGlobalTimeInMilliseconds);
    void raia_ma_sound_group_set_stop_time_in_pcm_frames(ma_sound_group* pGroup, ma_uint64 absoluteGlobalTimeInFrames);
    void raia_ma_sound_group_set_stop_time_in_milliseconds(ma_sound_group* pGroup, ma_uint64 absoluteGlobalTimeInMilliseconds);
    ma_bool32 raia_ma_sound_group_is_playing(const ma_sound_group* pGroup);
    ma_uint64 raia_ma_sound_group_get_time_in_pcm_frames(const ma_sound_group* pGroup);
]]

local lib = ffi.load("raia_miniaudio")
local MA = {}

return MA