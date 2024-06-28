#ifndef SYSTEM_LIBRARY_H
#define SYSTEM_LIBRARY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../common/c/utility/export_api.h"
#include "../../common/c/utility/platform.h"

#ifdef __WINDOWS__
#include <windows.h>
#include <psapi.h>
#elifdef __MACOS__
#include <IOKit/ps/IOPowerSources.h>
#include <IOKit/ps/IOPSKeys.h>
#include <mach/mach.h>
#include <sys/param.h>
#include <sys/sysctl.h>
#elifdef __LINUX__
#include <X11/Xlib.h>
#include <X11/Xatom.h>
#include <unistd.h>
#endif

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


#endif //SYSTEM_LIBRARY_H
