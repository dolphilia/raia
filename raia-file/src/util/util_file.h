//
// Created by dolphilia on 2022/12/10.
//

#ifndef RAIA_CORE_UTIL_FILE_H
#define RAIA_CORE_UTIL_FILE_H

#ifdef __WINDOWS__
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_INTERNAL_NONSTDC_NAMES 1
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <sys/stat.h>
#include <sys/types.h>

#ifdef __WINDOWS__
#include "limits.h"
#include <windows.h>
#include <pathcch.h>
#include <shlwapi.h>
#include <tchar.h>
#else
#include <limits.h>
#include <libgen.h>
#include <dirent.h>
#include <unistd.h>
#endif

#ifdef __MACOS__
#include <mach-o/dyld.h>
#endif

#if !defined(S_ISREG) && defined(S_IFMT) && defined(S_IFREG)
#define S_ISREG(m) (((m) & S_IFMT) == S_IFREG)
#endif
#if !defined(S_ISDIR) && defined(S_IFMT) && defined(S_IFDIR)
#define S_ISDIR(m) (((m) & S_IFMT) == S_IFDIR)
#endif

#ifdef __WINDOWS__
#define WCSNCPY(dest, src, count) { size_t size = sizeof(dest) / sizeof(dest[0]); wcsncpy_s(dest, size, src, count); }
#else
#define WCSNCPY(dest, src, count) wcsncpy(dest, src, count)
#endif

void get_directories_recursive(const char *path, char ***directories, size_t *count);
void get_directories(const char *path, char ***directories, size_t *count);
char *get_current_path();
char *get_exe_path();
int file_check_path(const char *path);
char *file_load_string(const char *filename);
int file_save_string(const char *filename, const char *content);
uint8_t *file_load_binary(const char *filename, size_t *file_size);
int file_save_binary(const char *filename, uint8_t *data, size_t data_size);

#endif //RAIA_CORE_UTIL_FILE_H
