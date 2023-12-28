#include "raia_file.h"

/*
 * ファイルの存在を確認する
 *
 * - args
 *   - path (string): ファイルのパス
 * - rets
 *   - is_exist (int): ファイルの有無。存在する 1 、存在しない 0
 */
RAIA_API const char *raia_file_exist(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    const char *path = joint_get_in_str(joint, "path");

    int exist = file_check_path(path);

    joint_add_out_int(joint, "exist", exist);
    return joint_out_write(joint);
}

/*
 * ファイルから文字列を読み込む
 *
 * - args
 *   - path (string): ファイルのパス
 * - rets
 *   - str (string): 読み込んだ文字列
 */
RAIA_API const char *raia_file_load_string(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    const char *path = joint_get_in_str(joint, "path");

    const char *str = file_load_string(path);

    joint_add_out_str(joint, "str", str);
    return joint_out_write(joint);
}

/*
 * ファイルに文字列を保存する
 *
 * - args
 *   - path (string): ファイルのパス
 *   - str (string): 保存する文字列
 * - rets
 *   - is_success (boolean): 成功 = true, 失敗 = false
 */
RAIA_API const char *raia_file_save_string(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    const char *path = joint_get_in_str(joint, "path");
    const char *str = joint_get_in_str(joint, "str");

    bool is_success = false;
    if (file_save_string(path, str) == 0) {
        is_success = true;
    }

    joint_add_out_bool(joint, "is_success", is_success);
    return joint_out_write(joint);
}

/*
 * ファイルからバイナリを読み込む
 *
 * - args
 *   - path (string): ファイルのパス
 * - rets
 *   - binary (uintptr): バイナリデータのポインタ
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

    joint_add_out_uint(joint, "binary", (uint64_t)(uintptr_t)file_data);
    return joint_out_write(joint);
}

/**
 * ファイルにバイナリデータを保存する
 *
 * - args
 *   - path (string): ファイルのパス
 *   - binary (uintptr): バイナリデータのポインタ
 *   - size (int): バイナリデータのサイズ
 * - rets
 *   - is_success (bool): 成功 = true, 失敗 = false
 */
RAIA_API const char *raia_file_save_binary(const char *s) {
    joint_t *joint = joint_init_with_str(s);
    const char *path = joint_get_in_str(joint, "path");
    uint8_t *binary = (uint8_t *)(uintptr_t)joint_get_in_uint(joint, "binary");
    size_t size = joint_get_in_int(joint, "size");

    int is_success = file_save_binary(path, binary, size);

    if (is_success == 0) {
        joint_add_out_bool(joint, "is_success", true);
    } else {
        joint_add_out_bool(joint, "is_success", false);
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