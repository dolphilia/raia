#include "raia_file.h"

/*
 * ファイルの存在を確認する
 *
 * - args
 *   - path (string): ファイルのパス
 * - rets
 *   - result (int): ファイルの有無。存在する 1 、存在しない 0
 */
RAIA_API const char *raia_file_exist(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    const char *path = joint_get_in_str(joint, "path");

    int exist = file_check_path(path);

    joint_add_out_int(joint, "result", exist);
    return joint_out_write(joint);
}

/*
 * ファイルから文字列を読み込む
 *
 * - args
 *   - path (string): ファイルのパス
 * - rets
 *   - result (string): 読み込んだ文字列
 */
RAIA_API const char *raia_file_load_string(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    const char *path = joint_get_in_str(joint, "path");

    const char *str = file_load_string(path);

    joint_add_out_str(joint, "result", str);
    return joint_out_write(joint);
}

/*
 * ファイルに文字列を保存する
 *
 * - args
 *   - path (string): ファイルのパス
 *   - data (string): 保存する文字列
 * - rets
 *   - result (boolean): 成功 or 失敗
 */
RAIA_API const char *raia_file_save_string(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    const char *path = joint_get_in_str(joint, "path");
    const char *data = joint_get_in_str(joint, "data");

    file_save_string(path, data);

    joint_add_out_bool(joint, "result", true);
    return joint_out_write(joint);
}

/*
 * ファイルからバイナリを読み込む
 *
 * - args
 *   - path (string): ファイルのパス
 * - rets
 *   - none
 */
RAIA_API const char *raia_file_load_binary(const char *s) {
    joint_t *joint = joint_init_in_with_str(s);
    const char *path = joint_get_in_str(joint, "path");

    size_t file_size;
    uint8_t *file_data = file_load_binary(path, &file_size);
    if (file_data == NULL) {
        fprintf(stderr, "Failed to read binary file: %s", path);
        return NULL;
    }

    joint_free(joint);
    return (const char *)file_data;
}

RAIA_API const char *raia_file_save_binary(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    const char *path = joint_get_in_str(joint, "path");
    uint8_t *data = (uint8_t *)(uintptr_t)joint_get_in_uint(joint, "data");
    size_t data_size = joint_get_in_int(joint, "size");

    int is_success = file_save_binary(path, data, data_size);

    if (is_success == 0) {
        joint_add_out_bool(joint, "result", true);
    } else {
        joint_add_out_bool(joint, "result", false);
    }
    return joint_out_write(joint);
}

RAIA_API const char *raia_file_get_exe_path(const char *s) {
    char *path = get_exe_path();

    joint_t *joint = joint_init_out();
    joint_add_out_str(joint, "result", path);
    return joint_out_write(joint);
}

RAIA_API const char *raia_file_get_cur_path(const char *s) {
    char *path = get_current_path();

    joint_t *joint = joint_init_out();
    joint_add_out_str(joint, "result", path);
    return joint_out_write(joint);
}

RAIA_API const char *raia_file_get_dirs(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    const char *path = joint_get_in_str(joint, "path");

    char **directories = NULL;
    size_t count = 0;
    get_directories(path, &directories, &count);

    joint_add_out_arr_str(joint, "result", (const char **)directories, count);
    return joint_out_write(joint);
}

RAIA_API const char *raia_file_get_dirs_all(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    const char *path = joint_get_in_str(joint, "path");

    char **directories = NULL;
    size_t count = 0;
    get_directories_recursive(path, &directories, &count);

    joint_add_out_arr_str(joint, "result", (const char **)directories, count);
    return joint_out_write(joint);
}