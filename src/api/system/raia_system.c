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

#ifdef _WIN32
RAIA_API PowerInfo get_power_info() {
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

    return result;
}
#endif

#ifdef __APPLE__
RAIA_API PowerInfo get_power_info() {
    printf("Power!");
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

    return result;
}
#endif

#ifdef __linux__
RAIA_API PowerInfo get_power_info() {
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

    return result;
}
#endif

#ifdef _WIN32
RAIA_API int get_processor_count() {
    SYSTEM_INFO sysinfo;
    GetSystemInfo(&sysinfo);
    return (int)sysinfo.dwNumberOfProcessors;
}
#endif

#ifdef __APPLE__
RAIA_API int get_processor_count() {
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
    return (int)count;
}
#endif

#ifdef __linux__
RAIA_API int get_processor_count() {
    return (int)sysconf(_SC_NPROCESSORS_ONLN);
}
#endif

#ifdef _WIN32
RAIA_API int open_url(const char* url) {
    ShellExecute(NULL, "open", url, NULL, NULL, SW_SHOWNORMAL);
    return 0;  // 通常、エラーチェックを行う必要があります
}
#endif

#ifdef __APPLE__
RAIA_API int open_url(const char* url) {
    char command[1024];
    sprintf(command, "open \"%s\"", url);
    return system(command);
}
#endif

#ifdef __linux__
RAIA_API int open_url(const char* url) {
    char command[1024];
    sprintf(command, "xdg-open \"%s\"", url);
    return system(command);
}
#endif


