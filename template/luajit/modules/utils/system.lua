local ffi = require("ffi")

ffi.cdef[[
    typedef enum {
        POWER_UNKNOWN,  // 電源状態不明
        POWER_ON_AC,    // AC電源に接続
        POWER_ON_BATTERY,  // バッテリー使用中
        POWER_CHARGING  // 充電中
    } PowerState;
    
    typedef struct {
        PowerState state;
        int percent;  // バッテリー残量（パーセンテージ）
        int seconds;  // バッテリーの残り持続時間（秒）
    } PowerInfo;

    const char* get_os_name();
    PowerInfo get_power_info();
    int get_processor_count();
    int open_url(const char* url);
    void print_memory_usage();
    double get_memory_usage();
]]

local lib = ffi.load("raia_system")
local System = {}

function System.getOS()
    return ffi.string(lib.get_os_name())
end

function System.getPowerInfo()
    local info = lib.get_power_info()
    return tonumber(info.state), info.percent, info.seconds
end

function System.getProcessorCount()
    return lib.get_processor_count()
end

function System.openURL(url)
    return lib.open_url(url)
end

function System.printMemoryUsage()
    lib.print_memory_usage()
end

function System.getMemoryUsage()
    return lib.get_memory_usage()
end

return System