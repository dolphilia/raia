#ifndef RAIA_FILE_RAIA_FILE_H
#define RAIA_FILE_RAIA_FILE_H

#include <stdio.h>
#include "../../../../common/c/utility/export_api.h"
#include "../../../../common/c/utility/platform.h"
#include "../../../../common/c/wrapper/wrapper_yyjson.h"
#include "../../../../common/c/utility/util_file.h"

RAIA_API const char *raia_file_exist(const char *s);
RAIA_API const char *raia_file_load_string(const char *s);
RAIA_API const char *raia_file_save_string(const char *s);
RAIA_API const char *raia_file_load_binary(const char *s);
RAIA_API const char *raia_file_save_binary(const char *s);
RAIA_API const char *raia_file_get_exe_path(const char *s);
RAIA_API const char *raia_file_get_cur_path(const char *s);
RAIA_API const char *raia_file_get_dirs(const char *s);
RAIA_API const char *raia_file_get_dirs_all(const char *s);

#endif //RAIA_FILE_RAIA_FILE_H
