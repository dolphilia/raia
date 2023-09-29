//
// Created by dolphilia on 2023/06/09.
//

#include "wrapper_yyjson.h"

joint_t *joint_init_null(void) {
    joint_t *joint = (joint_t *)malloc(1 * sizeof(joint_t));
    joint->in_doc = NULL;
    joint->in_root = NULL;
    joint->out_doc = NULL;
    joint->out_root = NULL;
    return joint;
}

joint_t *joint_init_out(void) {
    joint_t *joint = (joint_t *)malloc(1 * sizeof(joint_t));
    joint->in_doc = NULL;
    joint->in_root = NULL;
    joint->out_doc = yyjson_mut_doc_new(NULL);
    joint->out_root = yyjson_mut_obj(joint->out_doc);
    yyjson_mut_doc_set_root(joint->out_doc, joint->out_root);
    return joint;
}

joint_t *joint_init_in_with_str(const char *args) {
    joint_t *joint = (joint_t *)malloc(1 * sizeof(joint_t));
    joint->in_doc = yyjson_read(args, strlen(args), 0);
    joint->in_root = yyjson_doc_get_root(joint->in_doc);
    joint->out_doc = NULL;
    joint->out_root = NULL;
    return joint;
}

joint_t *joint_init_with_str(const char *args) {
    joint_t *joint = (joint_t *)malloc(1 * sizeof(joint_t));
    joint->in_doc = yyjson_read(args, strlen(args), 0);
    joint->in_root = yyjson_doc_get_root(joint->in_doc);
    joint->out_doc = yyjson_mut_doc_new(NULL);
    joint->out_root = yyjson_mut_obj(joint->out_doc);
    yyjson_mut_doc_set_root(joint->out_doc, joint->out_root);
    return joint;
}

joint_t *joint_init_in_with_file(const char *s) {
    joint_t *joint = (joint_t *)malloc(1 * sizeof(joint_t));
    joint->in_doc = yyjson_read_file(s, 0, NULL, NULL);
    joint->in_root = yyjson_doc_get_root(joint->in_doc);
    joint->out_doc = NULL;
    joint->out_root = NULL;
    return joint;
}

bool joint_in_exist(joint_t *joint, const char *key) {
    yyjson_val *val = yyjson_obj_get(joint->in_root, key);
    if (val != NULL) {
        return true;
    }
    return false;
}

const char *joint_get_in_str(joint_t *joint, const char *key) {
    return yyjson_get_str(yyjson_obj_get(joint->in_root, key));
}

int joint_get_in_int(joint_t *joint, const char *key) {
    return yyjson_get_int(yyjson_obj_get(joint->in_root, key));
}

int64_t joint_get_in_sint(joint_t *joint, const char *key) {
    return yyjson_get_sint(yyjson_obj_get(joint->in_root, key));
}

uint64_t joint_get_in_uint(joint_t *joint, const char *key) {
    return yyjson_get_uint(yyjson_obj_get(joint->in_root, key));
}

double joint_get_in_real(joint_t *joint, const char *key) {
    return yyjson_get_real(yyjson_obj_get(joint->in_root, key));
}

bool joint_get_in_bool(joint_t *joint, const char *key) {
    return yyjson_get_bool(yyjson_obj_get(joint->in_root, key));
}

void joint_add_out_bool(joint_t *joint, const char *key, bool val) {
    yyjson_mut_obj_add_bool(joint->out_doc, joint->out_root, key, val);
}

void joint_add_out_int(joint_t *joint, const char *key, int val) {
    yyjson_mut_obj_add_int(joint->out_doc, joint->out_root, key, val);
}

void joint_add_out_uint(joint_t *joint, const char *key, uint64_t val) {
    yyjson_mut_obj_add_uint(joint->out_doc, joint->out_root, key, val);
}

void joint_add_out_sint(joint_t *joint, const char *key, int64_t val) {
    yyjson_mut_obj_add_sint(joint->out_doc, joint->out_root, key, val);
}

void joint_add_out_str(joint_t *joint, const char *key, const char *val) {
    yyjson_mut_obj_add_str(joint->out_doc, joint->out_root, key, val);
}

void joint_add_out_real(joint_t *joint, const char *key, double val) {
    yyjson_mut_obj_add_real(joint->out_doc, joint->out_root, key, val);
}

void joint_add_out_null(joint_t *joint, const char *key) {
    yyjson_mut_obj_add_null(joint->out_doc, joint->out_root, key);
}

void joint_free(joint_t *joint) {
    if (joint->out_doc != NULL) {
        yyjson_mut_doc_free(joint->out_doc);
    }
    if (joint->in_doc != NULL) {
        yyjson_doc_free(joint->in_doc);
    }
    free(joint);
}

const char *joint_out_write(joint_t* joint) {
    const char* ret = yyjson_mut_write(joint->out_doc, YYJSON_WRITE_PRETTY, NULL);
    joint_free(joint);
    return ret;
}

void joint_get_in_arr_int(joint_t *joint, int *arr, const char *key) {
    yyjson_val *arg_arr = yyjson_obj_get(joint->in_root, key);
    size_t idx, max;
    yyjson_val *hit;
    yyjson_arr_foreach(arg_arr, idx, max, hit) {
        arr[idx] = yyjson_get_int(hit);
    }
}

void joint_get_in_arr_sint(joint_t *joint, int64_t *arr, const char *key) {
    yyjson_val *arg_arr = yyjson_obj_get(joint->in_root, key);
    size_t idx, max;
    yyjson_val *hit;
    yyjson_arr_foreach(arg_arr, idx, max, hit) {
        arr[idx] = yyjson_get_sint(hit);
    }
}

void joint_get_in_arr_uint(joint_t *joint, uint64_t *arr, const char *key) {
    yyjson_val *arg_arr = yyjson_obj_get(joint->in_root, key);
    size_t idx, max;
    yyjson_val *hit;
    yyjson_arr_foreach(arg_arr, idx, max, hit) {
        arr[idx] = yyjson_get_uint(hit);
    }
}

void joint_get_in_arr_uint8(joint_t *joint, uint8_t *arr, const char *key) {
    yyjson_val *arg_arr = yyjson_obj_get(joint->in_root, key);
    size_t idx, max;
    yyjson_val *hit;
    yyjson_arr_foreach(arg_arr, idx, max, hit) {
        arr[idx] = (uint8_t)yyjson_get_uint(hit);
    }
}

void joint_get_in_arr_uint16(joint_t *joint, uint16_t *arr, const char *key) {
    yyjson_val *arg_arr = yyjson_obj_get(joint->in_root, key);
    size_t idx, max;
    yyjson_val *hit;
    yyjson_arr_foreach(arg_arr, idx, max, hit) {
        arr[idx] = (uint16_t)yyjson_get_uint(hit);
    }
}

void joint_get_in_arr_uint32(joint_t *joint, uint32_t *arr, const char *key) {
    yyjson_val *arg_arr = yyjson_obj_get(joint->in_root, key);
    size_t idx, max;
    yyjson_val *hit;
    yyjson_arr_foreach(arg_arr, idx, max, hit) {
        arr[idx] = (uint32_t)yyjson_get_uint(hit);
    }
}

void joint_get_in_arr_real(joint_t *joint, double *arr, const char *key) {
    yyjson_val *arg_arr = yyjson_obj_get(joint->in_root, key);
    size_t idx, max;
    yyjson_val *hit;
    yyjson_arr_foreach(arg_arr, idx, max, hit) {
        arr[idx] = yyjson_get_real(hit);
    }
}

void joint_get_in_arr_int_to_float(joint_t *joint, float *arr, const char *key) {
    yyjson_val *arg_arr = yyjson_obj_get(joint->in_root, key);
    size_t idx, max;
    yyjson_val *hit;
    yyjson_arr_foreach(arg_arr, idx, max, hit) {
        arr[idx] = (float)yyjson_get_int(hit);
    }
}

void joint_get_in_arr_bool(joint_t *joint, bool *arr, const char *key) {
    yyjson_val *arg_arr = yyjson_obj_get(joint->in_root, key);
    size_t idx, max;
    yyjson_val *hit;
    yyjson_arr_foreach(arg_arr, idx, max, hit) {
        arr[idx] = yyjson_get_bool(hit);
    }
}

void joint_get_in_arr_str(joint_t *joint, const char **arr, const char *key) {
    yyjson_val *arg_arr = yyjson_obj_get(joint->in_root, key);
    size_t idx, max;
    yyjson_val *hit;
    yyjson_arr_foreach(arg_arr, idx, max, hit) {
        arr[idx] = yyjson_get_str(hit);
    }
}

void joint_add_out_arr_real(joint_t *joint, const char *key, double *vals, size_t count) {
    yyjson_mut_val *val = yyjson_mut_arr_with_real(joint->out_doc, vals, count);
    yyjson_mut_obj_add_val(joint->out_doc, joint->out_root, key, val);
}

void joint_add_out_arr_sint(joint_t *joint, const char *key, int64_t *vals, size_t count) {
    yyjson_mut_val *val = yyjson_mut_arr_with_sint(joint->out_doc, vals, count);
    yyjson_mut_obj_add_val(joint->out_doc, joint->out_root, key, val);
}

void joint_add_out_arr_sint32(joint_t *joint, const char *key, int32_t *vals, size_t count) {
    yyjson_mut_val *val = yyjson_mut_arr_with_sint32(joint->out_doc, vals, count);
    yyjson_mut_obj_add_val(joint->out_doc, joint->out_root, key, val);
}

void joint_add_out_arr_uint(joint_t *joint, const char *key, uint64_t *vals, size_t count) {
    yyjson_mut_val *val = yyjson_mut_arr_with_uint(joint->out_doc, vals, count);
    yyjson_mut_obj_add_val(joint->out_doc, joint->out_root, key, val);
}

void joint_add_out_arr_uint8(joint_t *joint, const char *key, uint8_t *vals, size_t count) {
    yyjson_mut_val *val = yyjson_mut_arr_with_uint8(joint->out_doc, vals, count);
    yyjson_mut_obj_add_val(joint->out_doc, joint->out_root, key, val);
}

void joint_add_out_arr_bool(joint_t *joint, const char *key, bool *vals, size_t count) {
    yyjson_mut_val *val = yyjson_mut_arr_with_bool(joint->out_doc, vals, count);
    yyjson_mut_obj_add_val(joint->out_doc, joint->out_root, key, val);
}

void joint_add_out_arr_str(joint_t *joint, const char *key, const char **vals, size_t count) {
    yyjson_mut_val *val = yyjson_mut_arr_with_str(joint->out_doc, vals, count);
    yyjson_mut_obj_add_val(joint->out_doc, joint->out_root, key, val);
}

//
bool joint_is_in_null(joint_t *joint, const char *key) {
    return yyjson_is_null(yyjson_obj_get(joint->in_root, key));
}

bool joint_is_in_int(joint_t *joint, const char *key) {
    return yyjson_is_int(yyjson_obj_get(joint->in_root, key));
}

bool joint_is_in_uint(joint_t *joint, const char *key) {
    return yyjson_is_uint(yyjson_obj_get(joint->in_root, key));
}

bool joint_is_in_real(joint_t *joint, const char *key) {
    return yyjson_is_real(yyjson_obj_get(joint->in_root, key));
}

bool joint_is_in_str(joint_t *joint, const char *key) {
    return yyjson_is_str(yyjson_obj_get(joint->in_root, key));
}

bool joint_is_in_arr(joint_t *joint, const char *key) {
    return yyjson_is_arr(yyjson_obj_get(joint->in_root, key));
}

double joint_get_in_int_or_real(joint_t *joint, const char *key) {
    if (joint_is_in_real(joint, key)) {
        return (double)joint_get_in_real(joint, key);
    }
    return (double)joint_get_in_int(joint, key);
}

void *joint_get_in_uint_to_ptr(joint_t *joint, const char *key) {
    if (joint_is_in_null(joint, key)) {
        return NULL;
    }
    return (void *)(uintptr_t)joint_get_in_uint(joint, key);
}

//void test_() {
//    joint_init_null();
//    joint_init_out();
//    joint_init_with_str("");
//    joint_init_in_with_str("");
//    joint_t *joint = joint_init_with_str("");
//    joint_get_in_str(joint, "");
//    joint_get_in_int(joint, "");
//    joint_get_in_sint(joint, "");
//    joint_get_in_uint(joint, "");
//    joint_get_in_real(joint, "");
//    joint_get_in_bool(joint, "");
//    joint_add_out_bool(joint, "", false);
//    joint_add_out_int(joint, "", 0);
//    joint_add_out_uint(joint, "", 0);
//    joint_add_out_sint(joint, "", 0);
//    joint_add_out_str(joint, "", "");
//    joint_add_out_real(joint, "", 0);
//    joint_add_out_null(joint, "");
//    int *arr_int = NULL;
//    int64_t *arr_int64 = NULL;
//    int64_t *arr_sint = NULL;
//    uint64_t *arr_uint = NULL;
//    uint8_t  *arr_uint8 = NULL;
//    uint16_t *arr_uint16 = NULL;
//    uint32_t *arr_uint32 = NULL;
//    double *arr_double = NULL;
//    float *arr_float = NULL;
//    bool *arr_bool = NULL;
//    const char** arr_char = NULL;
//    joint_get_in_arr_int(joint, arr_int, "");
//    joint_get_in_arr_sint(joint, arr_sint, "");
//    joint_get_in_arr_uint(joint, arr_uint, "");
//    joint_get_in_arr_uint8(joint, arr_uint8, "");
//    joint_get_in_arr_uint16(joint, arr_uint16, "");
//    joint_get_in_arr_uint32(joint, arr_uint32, "");
//    joint_get_in_arr_real(joint, arr_double, "");
//    joint_get_in_arr_int_to_float(joint, arr_float, "");
//    joint_get_in_arr_bool(joint, arr_bool, "");
//    joint_get_in_arr_str(joint, arr_char, "");
//    joint_add_out_arr_real(joint, "", arr_double, 0);
//    joint_add_out_arr_sint(joint, "", arr_int64, 0);
//    joint_add_out_arr_sint32(joint, "", arr_int, 0);
//    joint_add_out_arr_uint(joint, "", arr_uint, 0);
//    joint_add_out_arr_uint8(joint, "", arr_uint8, 0);
//    joint_add_out_arr_bool(joint, "", arr_bool, 0);
//    joint_add_out_arr_str(joint, "", arr_char, 0);
//    joint_is_in_null(joint, "");
//    joint_is_in_int(joint, "");
//    joint_is_in_uint(joint, "");
//    joint_is_in_real(joint, "");
//    joint_is_in_str(joint, "");
//    joint_is_in_arr(joint, "");
//    joint_get_in_int_or_real(joint, "");
//    joint_get_in_uint_to_ptr(joint, "");
//    joint_out_write(joint);
//    joint_free(joint);
//}