//
// Created by dolphilia on 2023/06/09.
//

#ifndef YYJSON_MACROS_WRAPPER_YYJSON_H
#define YYJSON_MACROS_WRAPPER_YYJSON_H

#include "../../../third_party/c/ibireme/yyjson/yyjson.h"

typedef struct json_t {
    yyjson_doc *in_doc;
    yyjson_val *in_root;
    yyjson_mut_doc *out_doc;
    yyjson_mut_val *out_root;
} joint_t;

joint_t *joint_init_null(void);
joint_t *joint_init_out(void);
joint_t *joint_init_with_str(const char *args);
joint_t *joint_init_in_with_str(const char *args);
joint_t *joint_init_in_with_file(const char *s);
bool joint_in_exist(joint_t *joint, const char *key);
const char *joint_get_in_str(joint_t *joint, const char *key);
int joint_get_in_int(joint_t *joint, const char *key);
int64_t joint_get_in_sint(joint_t *joint, const char *key);
uint64_t joint_get_in_uint(joint_t *joint, const char *key);
double joint_get_in_real(joint_t *joint, const char *key);
bool joint_get_in_bool(joint_t *joint, const char *key);
void joint_add_out_bool(joint_t *joint, const char *key, bool val);
void joint_add_out_int(joint_t *joint, const char *key, int val);
void joint_add_out_uint(joint_t *joint, const char *key, uint64_t val);
void joint_add_out_sint(joint_t *joint, const char *key, int64_t val);
void joint_add_out_str(joint_t *joint, const char *key, const char *val);
void joint_add_out_real(joint_t *joint, const char *key, double val);
void joint_add_out_null(joint_t *joint, const char *key);
void joint_get_in_arr_int(joint_t *joint, int *arr, const char *key);
void joint_get_in_arr_sint(joint_t *joint, int64_t *arr, const char *key);
void joint_get_in_arr_uint(joint_t *joint, uint64_t *arr, const char *key);
void joint_get_in_arr_uint8(joint_t *joint, uint8_t *arr, const char *key);
void joint_get_in_arr_uint16(joint_t *joint, uint16_t *arr, const char *key);
void joint_get_in_arr_uint32(joint_t *joint, uint32_t *arr, const char *key);
void joint_get_in_arr_real(joint_t *joint, double *arr, const char *key);
void joint_get_in_arr_int_to_float(joint_t *joint, float *arr, const char *key);
void joint_get_in_arr_bool(joint_t *joint, bool *arr, const char *key);
void joint_get_in_arr_str(joint_t *joint, const char **arr, const char *key);
void joint_add_out_arr_real(joint_t *joint, const char *key, double *vals, size_t count);
void joint_add_out_arr_sint(joint_t *joint, const char *key, int64_t *vals, size_t count);
void joint_add_out_arr_sint32(joint_t *joint, const char *key, int32_t *vals, size_t count);
void joint_add_out_arr_uint(joint_t *joint, const char *key, uint64_t *vals, size_t count);
void joint_add_out_arr_uint8(joint_t *joint, const char *key, uint8_t *vals, size_t count);
void joint_add_out_arr_bool(joint_t *joint, const char *key, bool *vals, size_t count);
void joint_add_out_arr_str(joint_t *joint, const char *key, const char **vals, size_t count);
void joint_free(joint_t *joint);
const char *joint_out_write(joint_t* joint);
//
bool joint_is_in_null(joint_t *joint, const char *key);
bool joint_is_in_int(joint_t *joint, const char *key);
bool joint_is_in_uint(joint_t *joint, const char *key);
bool joint_is_in_real(joint_t *joint, const char *key);
bool joint_is_in_str(joint_t *joint, const char *key);
bool joint_is_in_arr(joint_t *joint, const char *key);
double joint_get_in_int_or_real(joint_t *joint, const char *key);
void *joint_get_in_uint_to_ptr(joint_t *joint, const char *key);

#endif //YYJSON_MACROS_WRAPPER_YYJSON_H
