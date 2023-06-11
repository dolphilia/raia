#ifndef RAIA_FILE_RAIA_FILE_H
#define RAIA_FILE_RAIA_FILE_H

#include "yyjson/yyjson.h"
#include "wrapper/wrapper_yyjson.h"
#include "util/util_file.h"

#ifdef __WINDOWS__
#define RAIA_EXPORT __declspec(dllexport) 
#else
#define RAIA_EXPORT
#endif

RAIA_EXPORT const char *raia_file_exist(const char *s);
RAIA_EXPORT const char *raia_file_load_string(const char *s);
RAIA_EXPORT const char *raia_file_save_string(const char *s);
RAIA_EXPORT const char *raia_file_load_binary(const char *s);
RAIA_EXPORT const char *raia_file_save_binary(const char *s);
RAIA_EXPORT const char *raia_file_get_exe_path(const char *s);
RAIA_EXPORT const char *raia_file_get_cur_path(const char *s);
RAIA_EXPORT const char *raia_file_get_dirs(const char *s);
RAIA_EXPORT const char *raia_file_get_dirs_all(const char *s);

#endif //RAIA_FILE_RAIA_FILE_H
