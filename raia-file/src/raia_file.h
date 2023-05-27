#ifndef RAIA_FILE_RAIA_FILE_H
#define RAIA_FILE_RAIA_FILE_H

#include "yyjson/yyjson.h"
#include "util/util_file.h"

#ifdef __WINDOWS__
#define RAIA_EXPORT __declspec(dllexport) 
#else
#define RAIA_EXPORT
#endif

RAIA_EXPORT void *raia_file_exist(const char *s, void *p, int n);
RAIA_EXPORT void *raia_file_load_string(const char *s, void *p, int n);
RAIA_EXPORT void *raia_file_save_string(const char *s, void *p, int n);
RAIA_EXPORT void *raia_file_load_binary(const char *s, void *p, int n);
RAIA_EXPORT void *raia_file_save_binary(const char *s, void *p, int n);
RAIA_EXPORT void *raia_file_get_exe_path(const char *s, void *p, int n);
RAIA_EXPORT void *raia_file_get_cur_path(const char *s, void *p, int n);
RAIA_EXPORT void *raia_file_get_dirs(const char *s, void *p, int n);
RAIA_EXPORT void *raia_file_get_dirs_all(const char *s, void *p, int n);

#endif //RAIA_FILE_RAIA_FILE_H
