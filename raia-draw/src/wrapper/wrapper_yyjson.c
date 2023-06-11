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

joint_t *joint_init_in_with_str(const char *s) {
    joint_t *joint = (joint_t *)malloc(1 * sizeof(joint_t));
    joint->in_doc = yyjson_read(s, strlen(s), 0);
    joint->in_root = yyjson_doc_get_root(joint->in_doc);
    joint->out_doc = NULL;
    joint->out_root = NULL;
    return joint;
}

joint_t *joint_init_with_str(const char *s) {
    joint_t *joint = (joint_t *)malloc(1 * sizeof(joint_t));
    joint->in_doc = yyjson_read(s, strlen(s), 0);
    joint->in_root = yyjson_doc_get_root(joint->in_doc);
    joint->out_doc = yyjson_mut_doc_new(NULL);
    joint->out_root = yyjson_mut_obj(joint->out_doc);
    yyjson_mut_doc_set_root(joint->out_doc, joint->out_root);
    return joint;
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

const char *joint_out_write(joint_t* json) {
    const char* ret = yyjson_mut_write(json->out_doc, YYJSON_WRITE_PRETTY, NULL);
    joint_free(json);
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

void joint_get_in_arr_real(joint_t *joint, double *arr, const char *key) {
    yyjson_val *arg_arr = yyjson_obj_get(joint->in_root, key);
    size_t idx, max;
    yyjson_val *hit;
    yyjson_arr_foreach(arg_arr, idx, max, hit) {
        arr[idx] = yyjson_get_real(hit);
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

void joint_add_out_arr_bool(joint_t *joint, const char *key, bool *vals, size_t count) {
    yyjson_mut_val *val = yyjson_mut_arr_with_bool(joint->out_doc, vals, count);
    yyjson_mut_obj_add_val(joint->out_doc, joint->out_root, key, val);
}

void joint_add_out_arr_str(joint_t *joint, const char *key, const char **vals, size_t count) {
    yyjson_mut_val *val = yyjson_mut_arr_with_str(joint->out_doc, vals, count);
    yyjson_mut_obj_add_val(joint->out_doc, joint->out_root, key, val);
}