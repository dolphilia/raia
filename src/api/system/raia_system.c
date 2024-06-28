#include "raia_system.h"

RAIA_API const char* get_os_name() {
#if defined(_WIN32) || defined(_WIN64)
    return "Windows";
#elif defined(__APPLE__) || defined(__MACH__)
    return "macOS";
#elif defined(__linux__) || defined(__linux)
    return "Linux";
#else
    return "Other";
#endif
}

RAIA_API PowerInfo get_power_info() {
#ifdef __WINDOWS__
    SYSTEM_POWER_STATUS sps;
    PowerInfo result = {POWER_UNKNOWN, -1, -1};

    if (GetSystemPowerStatus(&sps)) {
        if (sps.ACLineStatus == 1) {
            result.state = POWER_ON_AC;
        } else if (sps.BatteryFlag == 255) {
            result.state = POWER_UNKNOWN;
        } else {
            result.state = (sps.BatteryFlag & 8) ? POWER_CHARGING : POWER_ON_BATTERY;
        }

        result.percent = sps.BatteryLifePercent;
        result.seconds = sps.BatteryLifeTime;
    }
#elifdef __MACOS__
    PowerInfo result = {POWER_UNKNOWN, -1, -1};
    CFTypeRef blob = IOPSCopyPowerSourcesInfo();
    CFArrayRef sources = IOPSCopyPowerSourcesList(blob);
    for (CFIndex i = 0; i < CFArrayGetCount(sources); i++) {
        CFDictionaryRef pSource = IOPSGetPowerSourceDescription(blob, CFArrayGetValueAtIndex(sources, i));
        if (pSource) {
            CFStringRef type = CFDictionaryGetValue(pSource, CFSTR(kIOPSTransportTypeKey));
            if (CFStringCompare(type, CFSTR(kIOPSInternalType), 0) == kCFCompareEqualTo) {
                CFStringRef currentState = CFDictionaryGetValue(pSource, CFSTR(kIOPSPowerSourceStateKey));
                result.state = CFStringCompare(currentState, CFSTR(kIOPSACPowerValue), 0) == kCFCompareEqualTo ? POWER_ON_AC : POWER_ON_BATTERY;
                CFNumberRef capacity = CFDictionaryGetValue(pSource, CFSTR(kIOPSCurrentCapacityKey));
                CFNumberGetValue(capacity, kCFNumberIntType, &result.percent);
                CFNumberRef timeToEmpty = CFDictionaryGetValue(pSource, CFSTR(kIOPSTimeToEmptyKey));
                CFNumberGetValue(timeToEmpty, kCFNumberIntType, &result.seconds);
            }
        }
    }
    if (sources) CFRelease(sources);
    if (blob) CFRelease(blob);
#elifdef __LINUX__
    PowerInfo result = {POWER_UNKNOWN, -1, -1};
    FILE *fp;
    int capacity, charging_status;
    fp = fopen("/sys/class/power_supply/BAT0/capacity", "r");
    if (fp != NULL) {
        fscanf(fp, "%d", &capacity);
        fclose(fp);
        result.percent = capacity;
    }
    fp = fopen("/sys/class/power_supply/BAT0/status", "r");
    if (fp != NULL) {
        char buf[16];
        fscanf(fp, "%s", buf);
        fclose(fp);
        if (strcmp(buf, "Charging") == 0) {
            result.state = POWER_CHARGING;
        } else if (strcmp(buf, "Discharging") == 0) {
            result.state = POWER_ON_BATTERY;
        } else {
            result.state = POWER_ON_AC;
        }
    }
#endif
    return result;
}

RAIA_API int get_processor_count() {
#ifdef __WINDOWS__
    SYSTEM_INFO sysinfo;
    GetSystemInfo(&sysinfo);
    int result = (int)sysinfo.dwNumberOfProcessors;
#elifdef __MACOS__
    int nm[2];
    size_t len = 4;
    uint32_t count;
    nm[0] = CTL_HW;
    nm[1] = HW_AVAILCPU;
    sysctl(nm, 2, &count, &len, NULL, 0);
    if(count < 1) {
        nm[1] = HW_NCPU;
        sysctl(nm, 2, &count, &len, NULL, 0);
        if(count < 1) { count = 1; }
    }
    int result = (int)count;
#elifdef __LINUX__
    int result = (int)sysconf(_SC_NPROCESSORS_ONLN);
#endif
    return result;
}

RAIA_API int open_url(const char* url) {
#ifdef __WINDOWS__
    ShellExecute(NULL, "open", url, NULL, NULL, SW_SHOWNORMAL);
    int result = 0;
#elifdef __MACOS__
    char command[1024];
    sprintf(command, "open \"%s\"", url);
    int result = system(command);
#elifdef __LINUX__
    char command[1024];
    sprintf(command, "xdg-open \"%s\"", url);
    int result = system(command);
#endif
    return result;
}

RAIA_API void print_memory_usage() {
#ifdef __WINDOWS__
    PROCESS_MEMORY_COUNTERS info;
    if (GetProcessMemoryInfo(GetCurrentProcess(), &info, sizeof(info))) {
        printf("Windows - Memory in use (resident): %lu bytes\n", info.WorkingSetSize);
        printf("Windows - Pagefile usage: %lu bytes\n", info.PagefileUsage);
    } else {
        printf("Windows - Failed to get process memory info\n");
    }
#elifdef __MACOS__
    struct mach_task_basic_info info;
    mach_msg_type_number_t count = MACH_TASK_BASIC_INFO_COUNT;
    kern_return_t result = task_info(mach_task_self(), MACH_TASK_BASIC_INFO, (task_info_t)&info, &count);
    if (result == KERN_SUCCESS) {
        printf("macOS - Memory in use (resident): %llu bytes\n", info.resident_size);
        printf("macOS - Virtual memory size: %llu bytes\n", info.virtual_size);
    } else {
        printf("macOS - Failed to get task info: %s\n", mach_error_string(result));
    }
#elifdef __LINUX__
    FILE *file = fopen("/proc/self/statm", "r");
    if (!file) {
        printf("Linux - Failed to open /proc/self/statm\n");
        return;
    }
    long size, resident, share, text, lib, data, dt;
    if (fscanf(file, "%ld %ld %ld %ld %ld %ld %ld", &size, &resident, &share, &text, &lib, &data, &dt) != 7) {
        printf("Linux - Failed to read from /proc/self/statm\n");
        fclose(file);
        return;
    }
    fclose(file);
    long page_size = sysconf(_SC_PAGESIZE);
    printf("Linux - Memory in use (resident): %ld bytes\n", resident * page_size);
    printf("Linux - Virtual memory size: %ld bytes\n", size * page_size);
#endif
}

RAIA_API double get_memory_usage() {
    double memory_in_use = 0;
#ifdef __WINDOWS__
    PROCESS_MEMORY_COUNTERS info;
    if (GetProcessMemoryInfo(GetCurrentProcess(), &info, sizeof(info))) {
        memory_in_use = (double)info.WorkingSetSize;//printf("Windows - Memory in use (resident): %lu bytes\n", info.WorkingSetSize);
        //printf("Windows - Pagefile usage: %lu bytes\n", info.PagefileUsage);
    } else {
        printf("Windows - Failed to get process memory info\n");
    }
#elifdef __MACOS__
    struct mach_task_basic_info info;
    mach_msg_type_number_t count = MACH_TASK_BASIC_INFO_COUNT;
    kern_return_t result = task_info(mach_task_self(), MACH_TASK_BASIC_INFO, (task_info_t)&info, &count);
    if (result == KERN_SUCCESS) {
        memory_in_use = (double)info.resident_size;
        unsigned long long virtual_size = info.virtual_size;
    } else {
        printf("macOS - Failed to get task info: %s\n", mach_error_string(result));
        memory_in_use = -1;
    }
#elifdef __LINUX__
    FILE *file = fopen("/proc/self/statm", "r");
    if (!file) {
        printf("Linux - Failed to open /proc/self/statm\n");
        return;
    }
    long size, resident, share, text, lib, data, dt;
    if (fscanf(file, "%ld %ld %ld %ld %ld %ld %ld", &size, &resident, &share, &text, &lib, &data, &dt) != 7) {
        printf("Linux - Failed to read from /proc/self/statm\n");
        fclose(file);
        return;
    }
    fclose(file);
    long page_size = sysconf(_SC_PAGESIZE);
    printf("Linux - Memory in use (resident): %ld bytes\n", resident * page_size);
    printf("Linux - Virtual memory size: %ld bytes\n", size * page_size);
#endif
    return memory_in_use;
}