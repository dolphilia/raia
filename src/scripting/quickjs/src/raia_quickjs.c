#include "raia_quickjs.h"

// 配列の長さを取得する関数
static uint32_t get_array_length(JSContext *ctx, JSValueConst array) {
    JSValue length_val = JS_GetPropertyStr(ctx, array, "length");
    uint32_t length = 0;

    if (JS_IsException(length_val)) {
        // エラー処理
    } else {
        // length を uint32_t に変換
        if (JS_ToUint32(ctx, &length, length_val)) {
            // 変換エラー処理
        }
    }

    JS_FreeValue(ctx, length_val); // length_val の使用が終わったら解放
    return length;
}

static JSValue raia_lib_open(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    if (argc != 1) {
        return JS_ThrowTypeError(ctx, "Incorrect number of arguments");
    }
    const char *library_path = JS_ToCString(ctx, argv[0]);
    if (!library_path) {
        return JS_EXCEPTION;
    }
    char library_name[500];
    SPRINTF(library_name, "%s.%s", library_path, DYNAMIC_LIB_EXT);
    int handle = open_shared_library(library_name);
    JS_FreeCString(ctx, library_path);
    return JS_NewInt32(ctx, handle);
}

static JSValue raia_lib_close(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    if (argc != 1) {
        return JS_ThrowTypeError(ctx, "Incorrect number of arguments");
    }
    int32_t library_key;
    if (JS_ToInt32(ctx, &library_key, argv[0])) {
        return JS_EXCEPTION;
    }
    close_shared_library(library_key);
    return JS_UNDEFINED; // JS_NULL
}

static JSValue raia_lib_close_all(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    if (argc != 0) {
        return JS_ThrowTypeError(ctx, "Incorrect number of arguments");
    }
    close_all_shared_library();
    return JS_UNDEFINED; // JS_NULL
}

static JSValue raia_lib_add(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    if (argc != 2) {
        return JS_ThrowTypeError(ctx, "Incorrect number of arguments");
    }
    int32_t library_key;
    if (JS_ToInt32(ctx, &library_key, argv[0])) {
        return JS_EXCEPTION;
    }
    const char *func_name = JS_ToCString(ctx, argv[1]);
    if (!func_name) {
        return JS_EXCEPTION;
    }
    add_func_shared_library(library_key, func_name);
    return JS_UNDEFINED; // JS_NULL
}

static JSValue raia_lib_call(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    if (argc != 3) {
        return JS_ThrowTypeError(ctx, "Incorrect number of arguments");
    }
    int32_t library_key;
    if (JS_ToInt32(ctx, &library_key, argv[0])) {
        return JS_EXCEPTION;
    }
    const char *func_name = JS_ToCString(ctx, argv[1]);
    const char *json = JS_ToCString(ctx, argv[2]);
    if (!func_name || !json) {
        return JS_EXCEPTION;
    }
    const char *rets = call_func_shared_library(library_key, func_name, json);
    JS_FreeCString(ctx, func_name);
    JS_FreeCString(ctx, json);
    if (rets) {
        JSValue value = JS_NewString(ctx, rets);
        free((void *)rets);
        return value;
    } else {
        return JS_UNDEFINED; // JS_NULL
    }
}

static JSValue raia_lib_ffi(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    if (argc != 4) {
        return JS_ThrowTypeError(ctx, "Incorrect number of arguments");
    }
    int32_t library_key;
    if (JS_ToInt32(ctx, &library_key, argv[0])) {
        return JS_EXCEPTION;
    }
    const char *func_name = JS_ToCString(ctx, argv[1]);
    const char *ret_type = JS_ToCString(ctx, argv[2]);
    if (!func_name || !ret_type) {
        return JS_EXCEPTION;
    }
    ffi_type *ffi_args_type[512];
    void *ffi_args_values[512];
    args_key_t ffi_rets;
    uint32_t args_len = 0;
    if (!JS_IsNull(argv[3])) {
        if (!JS_IsArray(ctx, argv[3])) {
            return JS_ThrowTypeError(ctx, "Expected an array for the 4th argument");
        }
        args_len = get_array_length(ctx, argv[3]);
        for (uint32_t i = 0; i < args_len; ++i) {
            JSValue args_list = JS_GetPropertyUint32(ctx, argv[3], i);
            if (JS_IsArray(ctx, args_list)) {
                uint32_t inner_length = get_array_length(ctx, args_list);
                if (inner_length >= 3) {
                    JSValue type_val = JS_GetPropertyUint32(ctx, args_list, 0);
                    JSValue name_val = JS_GetPropertyUint32(ctx, args_list, 1);
                    JSValue value_val = JS_GetPropertyUint32(ctx, args_list, 2);
                    const char *arg_type = JS_ToCString(ctx, type_val);
                    const char *arg_name = JS_ToCString(ctx, name_val);
                    if (strcmp(arg_type, "uint8") == 0) {
                        int64_t temp_value;
                        if (JS_ToInt64(ctx, &temp_value, value_val)) {
                            return JS_EXCEPTION; // 変換エラー処理
                        }
                        if (temp_value < 0 || temp_value > 255) {
                            return JS_EXCEPTION;  // 範囲外エラー処理
                        }
                        uint8_t value = (uint8_t) temp_value;
                        ffi_args_values[i] = add_args_hash_to_uint8(arg_name, value);
                        ffi_args_type[i] = &ffi_type_uint8;
                    } else if (strcmp(arg_type, "sint8") == 0) {
                        int64_t temp_value;
                        if (JS_ToInt64(ctx, &temp_value, value_val)) {
                            return JS_EXCEPTION; // 変換エラー処理
                        }
                        if (temp_value < -128 || temp_value > 127) {
                            return JS_EXCEPTION;  // 範囲外エラー処理
                        }
                        int8_t value = (int8_t) temp_value;
                        ffi_args_values[i] = add_args_hash_to_sint8(arg_name, value);
                        ffi_args_type[i] = &ffi_type_sint8;
                    } else if (strcmp(arg_type, "uint16") == 0) {
                        int64_t temp_value;
                        if (JS_ToInt64(ctx, &temp_value, value_val)) {
                            return JS_EXCEPTION; // 変換エラー処理
                        }
                        if (temp_value < 0 || temp_value > 65535) {
                            return JS_EXCEPTION;  // 範囲外エラー処理
                        }
                        uint16_t value = (uint16_t) temp_value;
                        ffi_args_values[i] = add_args_hash_to_uint16(arg_name, value);
                        ffi_args_type[i] = &ffi_type_uint16;
                    } else if (strcmp(arg_type, "sint16") == 0) {
                        int64_t temp_value;
                        if (JS_ToInt64(ctx, &temp_value, value_val)) {
                            return JS_EXCEPTION; // 変換エラー処理
                        }
                        if (temp_value < -32768 || temp_value > 32767) {
                            return JS_EXCEPTION;  // 範囲外エラー処理
                        }
                        int16_t value = (int16_t) temp_value;
                        ffi_args_values[i] = add_args_hash_to_sint16(arg_name, value);
                        ffi_args_type[i] = &ffi_type_sint16;
                    } else if (strcmp(arg_type, "uint32") == 0) {
                        uint32_t value;
                        if (JS_ToUint32(ctx, &value, value_val)) {
                            return JS_EXCEPTION; // 変換エラー処理
                        }
                        ffi_args_values[i] = add_args_hash_to_uint32(arg_name, value);
                        ffi_args_type[i] = &ffi_type_uint32;
                    } else if (strcmp(arg_type, "sint32") == 0) {
                        int32_t value;
                        if (JS_ToInt32(ctx, &value, value_val)) {
                            return JS_EXCEPTION; // 変換エラー処理
                        }
                        ffi_args_values[i] = add_args_hash_to_sint32(arg_name, value);
                        ffi_args_type[i] = &ffi_type_sint32;
                    } else if (strcmp(arg_type, "uint64") == 0) {
                        int64_t temp_value;
                        if (JS_ToInt64(ctx, &temp_value, value_val)) {
                            return JS_EXCEPTION; // 変換エラー処理
                        }
                        if (temp_value < 0) {
                            return JS_EXCEPTION;  // 範囲外エラー処理
                        }
                        uint64_t value = (uint64_t) temp_value;
                        ffi_args_values[i] = add_args_hash_to_uint64(arg_name, value);
                        ffi_args_type[i] = &ffi_type_uint64;
                    } else if (strcmp(arg_type, "sint64") == 0) {
                        int64_t value;
                        if (JS_ToInt64(ctx, &value, value_val)) {
                            return JS_EXCEPTION; // 変換エラー処理
                        }
                        ffi_args_values[i] = add_args_hash_to_sint64(arg_name, value);
                        ffi_args_type[i] = &ffi_type_sint64;
                    } else if (strcmp(arg_type, "float") == 0) {
                        double temp_value;
                        if (JS_ToFloat64(ctx, &temp_value, value_val)) {
                            return JS_EXCEPTION; // 変換エラー
                        }
                        float value = (float) temp_value;
                        ffi_args_values[i] = add_args_hash_to_float(arg_name, value);
                        ffi_args_type[i] = &ffi_type_float;
                    } else if (strcmp(arg_type, "double") == 0) {
                        double value;
                        if (JS_ToFloat64(ctx, &value, value_val)) {
                            return JS_EXCEPTION; // 変換エラー
                        }
                        ffi_args_values[i] = add_args_hash_to_double(arg_name, value);
                        ffi_args_type[i] = &ffi_type_double;
                    } else if (strcmp(arg_type, "uchar") == 0) {
                        double temp_value;
                        if (JS_ToFloat64(ctx, &temp_value, value_val)) {
                            return JS_EXCEPTION; // 変換エラー
                        }
                        if (temp_value < 0 || temp_value > UCHAR_MAX) {
                            return JS_EXCEPTION; // 範囲外エラー
                        }
                        unsigned char value = (unsigned char) temp_value;
                        ffi_args_values[i] = add_args_hash_to_uchar(arg_name, value);
                        ffi_args_type[i] = &ffi_type_uchar;
                    } else if (strcmp(arg_type, "schar") == 0) {
                        double temp_value;
                        if (JS_ToFloat64(ctx, &temp_value, value_val)) {
                            return JS_EXCEPTION; // 変換エラー
                        }
                        if (temp_value < CHAR_MIN || temp_value > CHAR_MAX) {
                            return JS_EXCEPTION; // 範囲外エラー
                        }
                        char value = (char) temp_value;
                        ffi_args_values[i] = add_args_hash_to_schar(arg_name, value);
                        ffi_args_type[i] = &ffi_type_schar;
                    } else if (strcmp(arg_type, "ushort") == 0) {
                        double temp_value;
                        if (JS_ToFloat64(ctx, &temp_value, value_val)) {
                            return JS_EXCEPTION; // 変換エラー
                        }
                        if (temp_value < 0 || temp_value > USHRT_MAX) {
                            return JS_EXCEPTION; // 範囲外エラー
                        }
                        unsigned short value = (unsigned short) temp_value;
                        ffi_args_values[i] = add_args_hash_to_ushort(arg_name, value);
                        ffi_args_type[i] = &ffi_type_ushort;
                    } else if (strcmp(arg_type, "sshort") == 0) {
                        double temp_value;
                        if (JS_ToFloat64(ctx, &temp_value, value_val)) {
                            return JS_EXCEPTION; // 変換エラー
                        }
                        if (temp_value < SHRT_MIN || temp_value > SHRT_MAX) {
                            return JS_EXCEPTION; // 範囲外エラー
                        }
                        short value = (short) temp_value;
                        ffi_args_values[i] = add_args_hash_to_sshort(arg_name, value);
                        ffi_args_type[i] = &ffi_type_sshort;
                    } else if (strcmp(arg_type, "uint") == 0) {
                        double temp_value;
                        if (JS_ToFloat64(ctx, &temp_value, value_val)) {
                            return JS_EXCEPTION; // 変換エラー
                        }
                        if (temp_value < 0 || temp_value > UINT_MAX) {
                            return JS_EXCEPTION; // 範囲外エラー
                        }
                        unsigned int value = (unsigned int) temp_value;
                        ffi_args_values[i] = add_args_hash_to_uint(arg_name, value);
                        ffi_args_type[i] = &ffi_type_uint;
                    } else if (strcmp(arg_type, "sint") == 0) {
                        double temp_value;
                        if (JS_ToFloat64(ctx, &temp_value, value_val)) {
                            return JS_EXCEPTION; // 変換エラー
                        }
                        if (temp_value < INT_MIN || temp_value > INT_MAX) {
                            return JS_EXCEPTION; // 範囲外エラー
                        }
                        int value = (int) temp_value;
                        ffi_args_values[i] = add_args_hash_to_sint(arg_name, value);
                        ffi_args_type[i] = &ffi_type_sint;
                    } else if (strcmp(arg_type, "ulong") == 0) {
                        double temp_value;
                        if (JS_ToFloat64(ctx, &temp_value, value_val)) {
                            return JS_EXCEPTION; // 変換エラー
                        }
                        if (temp_value < 0 || temp_value > ULONG_MAX) {
                            return JS_EXCEPTION; // 範囲外エラー
                        }
                        unsigned long value = (unsigned long) temp_value;
                        ffi_args_values[i] = add_args_hash_to_ulong(arg_name, value);
                        ffi_args_type[i] = &ffi_type_ulong;
                    } else if (strcmp(arg_type, "slong") == 0) {
                        double temp_value;
                        if (JS_ToFloat64(ctx, &temp_value, value_val)) {
                            return JS_EXCEPTION; // 変換エラー
                        }
                        if (temp_value < LONG_MIN || temp_value > LONG_MAX) {
                            return JS_EXCEPTION; // 範囲外エラー
                        }
                        long value = (long) temp_value;
                        ffi_args_values[i] = add_args_hash_to_slong(arg_name, value);
                        ffi_args_type[i] = &ffi_type_slong;
                    } else if (strcmp(arg_type, "longdouble") == 0) {
                        double temp_value;
                        if (JS_ToFloat64(ctx, &temp_value, value_val)) {
                            return JS_EXCEPTION; // 変換エラー
                        }
                        long double value = (long double) temp_value;
                        ffi_args_values[i] = add_args_hash_to_longdouble(arg_name, value);
                        ffi_args_type[i] = &ffi_type_longdouble;
                    } else if (strcmp(arg_type, "string") == 0) {
                        const char *value = JS_ToCString(ctx, value_val);
                        if (!value) {
                            return JS_EXCEPTION;
                        }
                        ffi_args_values[i] = add_args_hash_to_string(arg_name, value);
                        ffi_args_type[i] = &ffi_type_pointer;
                        JS_FreeCString(ctx, value);
                    } else if (strcmp(arg_type, "pointer") == 0) {
                        void *value;
                        if (JS_IsNull(value_val)) {
                            value = NULL;
                        } else {
                            double temp_value;
                            if (JS_ToFloat64(ctx, &temp_value, value_val)) {
                                return JS_EXCEPTION; // 変換エラー
                            }
                            value = (void *) (uintptr_t) temp_value;
                        }
                        ffi_args_values[i] = add_args_hash_to_pointer(arg_name, value);
                        ffi_args_type[i] = &ffi_type_pointer;
                    } else if (strcmp(arg_type, "struct") == 0) {
                        JSValue struct_types_temp = JS_GetPropertyStr(ctx, value_val, "types");
                        double types;
                        if (JS_ToFloat64(ctx, &types, struct_types_temp)) {
                            JS_FreeValue(ctx, struct_types_temp);
                            return JS_EXCEPTION;
                        }
                        JSValue struct_binary_temp = JS_GetPropertyStr(ctx, value_val, "binary");
                        double binary;
                        if (JS_ToFloat64(ctx, &binary, struct_binary_temp)) {
                            JS_FreeValue(ctx, struct_binary_temp);
                            return JS_EXCEPTION;
                        }
                        ffi_type **struct_types = (ffi_type **)(uintptr_t)types;
                        void *struct_binary = (void *)(uintptr_t)binary;
                        ffi_args_values[i] = add_args_hash_to_struct(arg_name, struct_binary);
                        ffi_type st_type = {
                                .size = 0,
                                .alignment = 0,
                                .type = FFI_TYPE_STRUCT,
                                .elements = struct_types
                        };
                        ffi_args_type[i] = &st_type;
                        JS_FreeValue(ctx, struct_types_temp);
                        JS_FreeValue(ctx, struct_binary_temp);
                    } else {
                        fprintf(stderr, "Unknown type: %s\n", arg_type);
                        exit(1);
                    }
                    JS_FreeCString(ctx, arg_type);
                    JS_FreeCString(ctx, arg_name);
                    JS_FreeValue(ctx, type_val);
                    JS_FreeValue(ctx, name_val);
                    JS_FreeValue(ctx, value_val);
                }
            }
            JS_FreeValue(ctx, args_list);
        }
    }
    
    // 戻り値の設定
    JSValue rets;
    if (strcmp(ret_type, "void") == 0) {
        ffi_call_ext(find_func_shared_library(library_key, func_name), args_len, &ffi_type_void, ffi_args_type, NULL, ffi_args_values);
        rets = JS_NULL;
    } else if (strcmp(ret_type, "uint8") == 0) {
        ffi_call_ext(find_func_shared_library(library_key, func_name), args_len, &ffi_type_uint8, ffi_args_type, &ffi_rets.data.value_uint8, ffi_args_values);
        rets = JS_NewUint32(ctx, ffi_rets.data.value_uint8);
    } else if (strcmp(ret_type, "sint8") == 0) {
        ffi_call_ext(find_func_shared_library(library_key, func_name), args_len, &ffi_type_sint8, ffi_args_type, &ffi_rets.data.value_sint8, ffi_args_values);
        rets = JS_NewInt32(ctx, ffi_rets.data.value_sint8);
    } else if (strcmp(ret_type, "uint16") == 0) {
        ffi_call_ext(find_func_shared_library(library_key, func_name), args_len, &ffi_type_uint16, ffi_args_type, &ffi_rets.data.value_uint16, ffi_args_values);
        rets = JS_NewUint32(ctx, ffi_rets.data.value_uint16);
    } else if (strcmp(ret_type, "sint16") == 0) {
        ffi_call_ext(find_func_shared_library(library_key, func_name), args_len, &ffi_type_sint16, ffi_args_type, &ffi_rets.data.value_sint16, ffi_args_values);
        rets = JS_NewInt32(ctx, ffi_rets.data.value_sint16);
    } else if (strcmp(ret_type, "uint32") == 0) {
        ffi_call_ext(find_func_shared_library(library_key, func_name), args_len, &ffi_type_uint32, ffi_args_type, &ffi_rets.data.value_uint32, ffi_args_values);
        rets = JS_NewUint32(ctx, ffi_rets.data.value_uint32);
    } else if (strcmp(ret_type, "sint32") == 0) {
        ffi_call_ext(find_func_shared_library(library_key, func_name), args_len, &ffi_type_sint32, ffi_args_type, &ffi_rets.data.value_sint32, ffi_args_values);
        rets = JS_NewInt32(ctx, ffi_rets.data.value_sint32);
    } else if (strcmp(ret_type, "uint64") == 0) {
        ffi_call_ext(find_func_shared_library(library_key, func_name), args_len, &ffi_type_uint64, ffi_args_type, &ffi_rets.data.value_uint64, ffi_args_values);
        rets = JS_NewInt64(ctx, (int64_t)ffi_rets.data.value_uint64);
    } else if (strcmp(ret_type, "sint64") == 0) {
        ffi_call_ext(find_func_shared_library(library_key, func_name), args_len, &ffi_type_sint64, ffi_args_type, &ffi_rets.data.value_sint64, ffi_args_values);
        rets = JS_NewInt64(ctx, ffi_rets.data.value_sint64);
    } else if (strcmp(ret_type, "float") == 0) {
        ffi_call_ext(find_func_shared_library(library_key, func_name), args_len, &ffi_type_float, ffi_args_type, &ffi_rets.data.value_float, ffi_args_values);
        rets = JS_NewFloat64(ctx, ffi_rets.data.value_float);
    } else if (strcmp(ret_type, "double") == 0) {
        ffi_call_ext(find_func_shared_library(library_key, func_name), args_len, &ffi_type_double, ffi_args_type, &ffi_rets.data.value_double, ffi_args_values);
        rets = JS_NewFloat64(ctx, ffi_rets.data.value_double);
    } else if (strcmp(ret_type, "uchar") == 0) {
        ffi_call_ext(find_func_shared_library(library_key, func_name), args_len, &ffi_type_uchar, ffi_args_type, &ffi_rets.data.value_uchar, ffi_args_values);
        rets = JS_NewUint32(ctx, ffi_rets.data.value_uchar);
    } else if (strcmp(ret_type, "schar") == 0) {
        ffi_call_ext(find_func_shared_library(library_key, func_name), args_len, &ffi_type_schar, ffi_args_type, &ffi_rets.data.value_schar, ffi_args_values);
        rets = JS_NewInt32(ctx, ffi_rets.data.value_schar);
    } else if (strcmp(ret_type, "ushort") == 0) {
        ffi_call_ext(find_func_shared_library(library_key, func_name), args_len, &ffi_type_ushort, ffi_args_type, &ffi_rets.data.value_ushort, ffi_args_values);
        rets = JS_NewUint32(ctx, ffi_rets.data.value_ushort);
    } else if (strcmp(ret_type, "sshort") == 0) {
        ffi_call_ext(find_func_shared_library(library_key, func_name), args_len, &ffi_type_sshort, ffi_args_type, &ffi_rets.data.value_sshort, ffi_args_values);
        rets = JS_NewInt32(ctx, ffi_rets.data.value_sshort);
    } else if (strcmp(ret_type, "uint") == 0) {
        ffi_call_ext(find_func_shared_library(library_key, func_name), args_len, &ffi_type_uint, ffi_args_type, &ffi_rets.data.value_uint, ffi_args_values);
        rets = JS_NewUint32(ctx, ffi_rets.data.value_uint);
    } else if (strcmp(ret_type, "sint") == 0) {
        ffi_call_ext(find_func_shared_library(library_key, func_name), args_len, &ffi_type_sint, ffi_args_type, &ffi_rets.data.value_sint, ffi_args_values);
        rets = JS_NewInt32(ctx, ffi_rets.data.value_sint);
    } else if (strcmp(ret_type, "ulong") == 0) {
        ffi_call_ext(find_func_shared_library(library_key, func_name), args_len, &ffi_type_ulong, ffi_args_type, &ffi_rets.data.value_ulong, ffi_args_values);
        rets = JS_NewInt64(ctx, (int64_t)ffi_rets.data.value_ulong);
    } else if (strcmp(ret_type, "slong") == 0) {
        ffi_call_ext(find_func_shared_library(library_key, func_name), args_len, &ffi_type_slong, ffi_args_type, &ffi_rets.data.value_slong, ffi_args_values);
        rets = JS_NewInt64(ctx, ffi_rets.data.value_slong);
    } else if (strcmp(ret_type, "longdouble") == 0) {
        ffi_call_ext(find_func_shared_library(library_key, func_name), args_len, &ffi_type_longdouble, ffi_args_type, &ffi_rets.data.value_longdouble, ffi_args_values);
        rets = JS_NewFloat64(ctx, (double)ffi_rets.data.value_longdouble);
    } else if (strcmp(ret_type, "string") == 0) {
        ffi_call_ext(find_func_shared_library(library_key, func_name), args_len, &ffi_type_pointer, ffi_args_type, &ffi_rets.data.value_string, ffi_args_values);
        rets = JS_NewString(ctx, ffi_rets.data.value_string);
    } else if (strcmp(ret_type, "pointer") == 0) {
        ffi_call_ext(find_func_shared_library(library_key, func_name), args_len, &ffi_type_pointer, ffi_args_type, &ffi_rets.data.value_pointer, ffi_args_values);
        rets = JS_NewInt64(ctx, (int64_t)(uintptr_t)ffi_rets.data.value_pointer);
    } else {
        fprintf(stderr, "Unknown type: %s\n", ret_type);
        exit(1);
    }
    delete_all_args_name_hash();
    delete_all_args_hash();
    return rets;
}

static JSValue raia_ffi_make_struct(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    if (!JS_IsArray(ctx, argv[0])) {
        return JS_ThrowTypeError(ctx, "Expected an array for the 1th argument");
    }
    int binary_size = 0;
    uint32_t args_len = get_array_length(ctx, argv[0]);
    for (uint32_t i = 0; i < args_len; ++i) {
        JSValue args_list = JS_GetPropertyUint32(ctx, argv[0], i);

        if (JS_IsArray(ctx, args_list)) {
            uint32_t inner_length = get_array_length(ctx, args_list);

            if (inner_length >= 2) {
                JSValue type_val = JS_GetPropertyUint32(ctx, args_list, 0);
                const char *arg_type = JS_ToCString(ctx, type_val);
                if (strcmp(arg_type, "uint8") == 0 || strcmp(arg_type, "sint8") == 0 || strcmp(arg_type, "uchar") == 0 || strcmp(arg_type, "schar") == 0) {
                    binary_size += 1;
                } else if (strcmp(arg_type, "uint16") == 0 || strcmp(arg_type, "sint16") == 0 || strcmp(arg_type, "ushort") == 0 || strcmp(arg_type, "sshort") == 0) {
                    binary_size += 2;
                } else if (strcmp(arg_type, "uint32") == 0 || strcmp(arg_type, "sint32") == 0 || strcmp(arg_type, "float") == 0 || strcmp(arg_type, "uint") == 0 || strcmp(arg_type, "sint") == 0 || strcmp(arg_type, "ulong") == 0 || strcmp(arg_type, "slong") == 0) {
                    binary_size += 4;
                } else if (strcmp(arg_type, "uint64") == 0 || strcmp(arg_type, "sint64") == 0 || strcmp(arg_type, "double") == 0) {
                    binary_size += 8;
                } else if (strcmp(arg_type, "longdouble") == 0) {
                    binary_size += 16;
                } else if (strcmp(arg_type, "string") == 0) {
                    JSValue temp_value = JS_GetPropertyUint32(ctx, args_list, 1);
                    size_t len;
                    const char *ret_str = JS_ToCStringLen(ctx, &len, temp_value);
                    if (!ret_str) {
                        return JS_EXCEPTION;
                    }
                    binary_size += (int)len + 1;
                } else if (strcmp(arg_type, "pointer") == 0) {
                    binary_size += sizeof(void*);
                } else {
                    fprintf(stderr, "Unknown type: %s\n", arg_type);
                    exit(1);
                }
                JS_FreeCString(ctx, arg_type);
                JS_FreeValue(ctx, type_val);
            }
        }
        JS_FreeValue(ctx, args_list);
    }
    // タイプ情報とバイナリデータを初期化・取得する
    ffi_type **type_elements = (ffi_type **)malloc((args_len + 1) * sizeof(ffi_type *));
    for (int i = 0; i < args_len + 1; i++) {
        type_elements[i] = NULL;
    }
    uint8_t *binary = (uint8_t *)malloc(binary_size);
    int binary_offset = 0;
    for (uint32_t i = 0; i < args_len; ++i) {
        JSValue args_list = JS_GetPropertyUint32(ctx, argv[0], i);
        if (JS_IsArray(ctx, args_list)) {
            uint32_t inner_length = get_array_length(ctx, args_list);
            if (inner_length >= 2) {
                JSValue type_val = JS_GetPropertyUint32(ctx, args_list, 0);
                JSValue value_val = JS_GetPropertyUint32(ctx, args_list, 1);
                const char *arg_type = JS_ToCString(ctx, type_val);

                if (strcmp(arg_type, "uint8") == 0) {
                    int64_t temp_value;
                    if (JS_ToInt64(ctx, &temp_value, value_val)) {
                        return JS_EXCEPTION; // 変換エラー処理
                    }
                    if (temp_value < 0 || temp_value > 255) {
                        return JS_EXCEPTION;  // 範囲外エラー処理
                    }
                    uint8_t value = (uint8_t) temp_value;
                    type_elements[i] = &ffi_type_uint8;
                    memcpy(binary + binary_offset, &value, 1);
                    binary_offset += 1;
                } else if (strcmp(arg_type, "sint8") == 0) {
                    int64_t temp_value;
                    if (JS_ToInt64(ctx, &temp_value, value_val)) {
                        return JS_EXCEPTION; // 変換エラー処理
                    }
                    if (temp_value < -128 || temp_value > 127) {
                        return JS_EXCEPTION;  // 範囲外エラー処理
                    }
                    int8_t value = (int8_t) temp_value;
                    type_elements[i] = &ffi_type_sint8;
                    memcpy(binary + binary_offset, &value, 1);
                    binary_offset += 1;
                } else if (strcmp(arg_type, "uint16") == 0) {
                    int64_t temp_value;
                    if (JS_ToInt64(ctx, &temp_value, value_val)) {
                        return JS_EXCEPTION; // 変換エラー処理
                    }
                    if (temp_value < 0 || temp_value > 65535) {
                        return JS_EXCEPTION;  // 範囲外エラー処理
                    }
                    uint16_t value = (uint16_t) temp_value;
                    type_elements[i] = &ffi_type_uint16;
                    memcpy(binary + binary_offset, &value, 2);
                    binary_offset += 2;
                } else if (strcmp(arg_type, "sint16") == 0) {
                    int64_t temp_value;
                    if (JS_ToInt64(ctx, &temp_value, value_val)) {
                        return JS_EXCEPTION; // 変換エラー処理
                    }
                    if (temp_value < -32768 || temp_value > 32767) {
                        return JS_EXCEPTION;  // 範囲外エラー処理
                    }
                    int16_t value = (int16_t) temp_value;
                    type_elements[i] = &ffi_type_sint16;
                    memcpy(binary + binary_offset, &value, 2);
                    binary_offset += 2;
                } else if (strcmp(arg_type, "uint32") == 0) {
                    uint32_t value;
                    if (JS_ToUint32(ctx, &value, value_val)) {
                        return JS_EXCEPTION; // 変換エラー処理
                    }
                    type_elements[i] = &ffi_type_uint32;
                    memcpy(binary + binary_offset, &value, 4);
                    binary_offset += 4;
                } else if (strcmp(arg_type, "sint32") == 0) {
                    int32_t value;
                    if (JS_ToInt32(ctx, &value, value_val)) {
                        return JS_EXCEPTION; // 変換エラー処理
                    }
                    type_elements[i] = &ffi_type_sint32;
                    memcpy(binary + binary_offset, &value, 4);
                    binary_offset += 4;
                } else if (strcmp(arg_type, "uint64") == 0) {
                    int64_t temp_value;
                    if (JS_ToInt64(ctx, &temp_value, value_val)) {
                        return JS_EXCEPTION; // 変換エラー処理
                    }
                    if (temp_value < 0) {
                        return JS_EXCEPTION;  // 範囲外エラー処理
                    }
                    uint64_t value = (uint64_t) temp_value;
                    type_elements[i] = &ffi_type_uint64;
                    memcpy(binary + binary_offset, &value, 8);
                    binary_offset += 8;
                } else if (strcmp(arg_type, "sint64") == 0) {
                    int64_t value;
                    if (JS_ToInt64(ctx, &value, value_val)) {
                        return JS_EXCEPTION; // 変換エラー処理
                    }
                    type_elements[i] = &ffi_type_sint64;
                    memcpy(binary + binary_offset, &value, 8);
                    binary_offset += 8;
                } else if (strcmp(arg_type, "float") == 0) {
                    double temp_value;
                    if (JS_ToFloat64(ctx, &temp_value, value_val)) {
                        return JS_EXCEPTION; // 変換エラー
                    }
                    float value = (float) temp_value;
                    type_elements[i] = &ffi_type_float;
                    memcpy(binary + binary_offset, &value, 4);
                    binary_offset += 4;
                } else if (strcmp(arg_type, "double") == 0) {
                    double value;
                    if (JS_ToFloat64(ctx, &value, value_val)) {
                        return JS_EXCEPTION; // 変換エラー
                    }
                    type_elements[i] = &ffi_type_double;
                    memcpy(binary + binary_offset, &value, 8);
                    binary_offset += 8;
                } else if (strcmp(arg_type, "uchar") == 0) {
                    double temp_value;
                    if (JS_ToFloat64(ctx, &temp_value, value_val)) {
                        return JS_EXCEPTION; // 変換エラー
                    }
                    if (temp_value < 0 || temp_value > UCHAR_MAX) {
                        return JS_EXCEPTION; // 範囲外エラー
                    }
                    unsigned char value = (unsigned char) temp_value;
                    type_elements[i] = &ffi_type_uchar;
                    memcpy(binary + binary_offset, &value, 1);
                    binary_offset += 1;
                } else if (strcmp(arg_type, "schar") == 0) {
                    double temp_value;
                    if (JS_ToFloat64(ctx, &temp_value, value_val)) {
                        return JS_EXCEPTION; // 変換エラー
                    }
                    if (temp_value < CHAR_MIN || temp_value > CHAR_MAX) {
                        return JS_EXCEPTION; // 範囲外エラー
                    }
                    char value = (char) temp_value;
                    type_elements[i] = &ffi_type_schar;
                    memcpy(binary + binary_offset, &value, 1);
                    binary_offset += 1;
                } else if (strcmp(arg_type, "ushort") == 0) {
                    double temp_value;
                    if (JS_ToFloat64(ctx, &temp_value, value_val)) {
                        return JS_EXCEPTION; // 変換エラー
                    }
                    if (temp_value < 0 || temp_value > USHRT_MAX) {
                        return JS_EXCEPTION; // 範囲外エラー
                    }
                    unsigned short value = (unsigned short) temp_value;
                    type_elements[i] = &ffi_type_ushort;
                    memcpy(binary + binary_offset, &value, 2);
                    binary_offset += 2;
                } else if (strcmp(arg_type, "sshort") == 0) {
                    double temp_value;
                    if (JS_ToFloat64(ctx, &temp_value, value_val)) {
                        return JS_EXCEPTION; // 変換エラー
                    }
                    if (temp_value < SHRT_MIN || temp_value > SHRT_MAX) {
                        return JS_EXCEPTION; // 範囲外エラー
                    }
                    short value = (short) temp_value;
                    type_elements[i] = &ffi_type_ushort;
                    memcpy(binary + binary_offset, &value, 2);
                    binary_offset += 2;
                } else if (strcmp(arg_type, "uint") == 0) {
                    double temp_value;
                    if (JS_ToFloat64(ctx, &temp_value, value_val)) {
                        return JS_EXCEPTION; // 変換エラー
                    }
                    if (temp_value < 0 || temp_value > UINT_MAX) {
                        return JS_EXCEPTION; // 範囲外エラー
                    }
                    unsigned int value = (unsigned int) temp_value;
                    type_elements[i] = &ffi_type_uint;
                    memcpy(binary + binary_offset, &value, 4);
                    binary_offset += 4;
                } else if (strcmp(arg_type, "sint") == 0) {
                    double temp_value;
                    if (JS_ToFloat64(ctx, &temp_value, value_val)) {
                        return JS_EXCEPTION; // 変換エラー
                    }
                    if (temp_value < INT_MIN || temp_value > INT_MAX) {
                        return JS_EXCEPTION; // 範囲外エラー
                    }
                    int value = (int) temp_value;
                    type_elements[i] = &ffi_type_sint;
                    memcpy(binary + binary_offset, &value, 4);
                    binary_offset += 4;
                } else if (strcmp(arg_type, "ulong") == 0) {
                    double temp_value;
                    if (JS_ToFloat64(ctx, &temp_value, value_val)) {
                        return JS_EXCEPTION; // 変換エラー
                    }
                    if (temp_value < 0 || temp_value > ULONG_MAX) {
                        return JS_EXCEPTION; // 範囲外エラー
                    }
                    unsigned long value = (unsigned long) temp_value;
                    type_elements[i] = &ffi_type_ulong;
                    memcpy(binary + binary_offset, &value, 4);
                    binary_offset += 4;
                } else if (strcmp(arg_type, "slong") == 0) {
                    double temp_value;
                    if (JS_ToFloat64(ctx, &temp_value, value_val)) {
                        return JS_EXCEPTION; // 変換エラー
                    }
                    if (temp_value < LONG_MIN || temp_value > LONG_MAX) {
                        return JS_EXCEPTION; // 範囲外エラー
                    }
                    long value = (long) temp_value;
                    type_elements[i] = &ffi_type_slong;
                    memcpy(binary + binary_offset, &value, 4);
                    binary_offset += 4;
                } else if (strcmp(arg_type, "longdouble") == 0) {
                    double temp_value;
                    if (JS_ToFloat64(ctx, &temp_value, value_val)) {
                        return JS_EXCEPTION; // 変換エラー
                    }
                    long double value = (long double) temp_value;
                    type_elements[i] = &ffi_type_longdouble;
                    memcpy(binary + binary_offset, &value, 16);
                    binary_offset += 16;
                } else if (strcmp(arg_type, "string") == 0) {
                    size_t len;
                    const char *value = JS_ToCStringLen(ctx, &len, value_val);
                    if (!value) {
                        return JS_EXCEPTION;
                    }
                    type_elements[i] = &ffi_type_pointer;
                    memcpy(binary + binary_offset, value, (int)len + 1);
                    binary_offset += (int)len + 1;
                    JS_FreeCString(ctx, value);
                } else if (strcmp(arg_type, "pointer") == 0) {
                    void *value;
                    if (JS_IsNull(value_val)) {
                        value = NULL;
                    } else {
                        double temp_value;
                        if (JS_ToFloat64(ctx, &temp_value, value_val)) {
                            return JS_EXCEPTION; // 変換エラー
                        }
                        value = (void *) (uintptr_t) temp_value;
                    }
                    type_elements[i] = &ffi_type_pointer;
                    memcpy(binary + binary_offset, &value, sizeof(void*));
                    binary_offset += sizeof(void*);
                } else {
                    fprintf(stderr, "Unknown type: %s\n", arg_type);
                    exit(1);
                }

                JS_FreeCString(ctx, arg_type);
                JS_FreeValue(ctx, type_val);
            }
        }
        JS_FreeValue(ctx, args_list);
    }
    JSValue obj = JS_NewObject(ctx);
    JS_SetPropertyStr(ctx, obj, "types", JS_NewFloat64(ctx, (double)(uintptr_t)type_elements));
    JS_SetPropertyStr(ctx, obj, "binary", JS_NewFloat64(ctx, (double)(uintptr_t)binary));
    return obj;
}

// console.log の実装
static JSValue js_console_log(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    int i;
    const char *str;

    for (i = 0; i < argc; i++) {
        if (i != 0)
            putchar(' ');
        str = JS_ToCString(ctx, argv[i]);
        if (!str)
            return JS_EXCEPTION;
        printf("%s", str);
        JS_FreeCString(ctx, str);
    }

    putchar('\n');
    return JS_UNDEFINED;
}

// console オブジェクトをグローバルオブジェクトに追加する関数
static int js_init_console(JSContext *ctx) {
    JSValue global_obj, console;

    global_obj = JS_GetGlobalObject(ctx);
    console = JS_NewObject(ctx);
    JS_SetPropertyStr(ctx, console, "log", JS_NewCFunction(ctx, js_console_log, "log", 1));
    JS_SetPropertyStr(ctx, global_obj, "console", console);
    JS_FreeValue(ctx, global_obj);

    return 0;
}


RAIA_API const char *init(int argc, char *argv[]) {
    JSRuntime *rt;
    JSContext *ctx;
    rt = JS_NewRuntime();
    if (!rt) {
        fprintf(stderr, "Failed to create QuickJS runtime\n");
        return NULL;
    }
    ctx = JS_NewContext(rt);
    if (!ctx) {
        fprintf(stderr, "Failed to create QuickJS context\n");
        JS_FreeRuntime(rt);
        return NULL;
    }

    // 標準モジュールとOSモジュールの初期化
    js_init_module_std(ctx, "std");
    js_init_module_os(ctx, "os");


    js_std_add_helpers(ctx, argc, argv); // quickjs-libc の初期化（コンソールログなどの機能を追加）

    // Module機能を有効にする
    JS_SetModuleLoaderFunc(rt, NULL, js_module_loader, NULL);


    // 関数を登録
    // グローバルオブジェクトを取得
    JSValue global_obj = JS_GetGlobalObject(ctx);
    JSValue raia_obj = JS_GetPropertyStr(ctx, global_obj, "__Raia__");
    if (JS_IsUndefined(raia_obj)) {
        raia_obj = JS_NewObject(ctx);
        JS_SetPropertyStr(ctx, global_obj, "__Raia__", JS_DupValue(ctx, raia_obj));
    }
    // Lib オブジェクトを取得または作成
    JSValue lib_obj = JS_GetPropertyStr(ctx, raia_obj, "Lib");
    if (JS_IsUndefined(lib_obj)) {
        lib_obj = JS_NewObject(ctx);
        JS_SetPropertyStr(ctx, raia_obj, "Lib", JS_DupValue(ctx, lib_obj));
    }

    // Lib オブジェクトに関数を登録
    JS_SetPropertyStr(ctx, lib_obj, "open", JS_NewCFunction(ctx, raia_lib_open, "open", 1));
    JS_SetPropertyStr(ctx, lib_obj, "close", JS_NewCFunction(ctx, raia_lib_close, "close", 1));
    JS_SetPropertyStr(ctx, lib_obj, "add", JS_NewCFunction(ctx, raia_lib_add, "add", 2));
    JS_SetPropertyStr(ctx, lib_obj, "call", JS_NewCFunction(ctx, raia_lib_call, "call", 3));
    JS_SetPropertyStr(ctx, lib_obj, "ffi", JS_NewCFunction(ctx, raia_lib_ffi, "ffi", 4));

    JS_SetPropertyStr(ctx, lib_obj, "makeStruct", JS_NewCFunction(ctx, raia_ffi_make_struct, "makeStruct", 1));

    // グローバルオブジェクトに関数を追加
    //JS_SetPropertyStr(ctx, global_obj, "openLibrary", JS_NewCFunction(ctx, raia_lib_open, "openLibrary", 1));

    // 作成したオブジェクトの参照を解放
    JS_FreeValue(ctx, lib_obj);
    JS_FreeValue(ctx, raia_obj);
    JS_FreeValue(ctx, global_obj);
    // consoleを登録
    //js_init_console(ctx);

    // JSファイルの読み込みと実行
//    const char *filename = "./example.js";
//    uint8_t *buf;
//    size_t buf_len;
//    JSValue result;
//
//    buf = js_load_file(ctx, &buf_len, filename);
//    if (!buf) {
//        fprintf(stderr, "Failed to load JS file: %s\n", filename);
//        JS_FreeContext(ctx);
//        JS_FreeRuntime(rt);
//        return NULL;
//    }
//
//    result = JS_Eval(ctx, (char *)buf, buf_len, filename, JS_EVAL_TYPE_GLOBAL);
//    js_free(ctx, buf);
//    if (JS_IsException(result)) {
//        js_std_dump_error(ctx);
//        result = JS_UNDEFINED;
//    }
    const char *main_js_path = "./example.js";
    size_t buf_len;
    uint8_t *buf = js_load_file(ctx, &buf_len, main_js_path);
    if (buf) {
        JSValue result = JS_Eval(ctx, (char *)buf, buf_len, main_js_path, JS_EVAL_TYPE_MODULE);
        if (JS_IsException(result)) {
            js_std_dump_error(ctx);
        }
        JS_FreeValue(ctx, result);
        js_free(ctx, buf);
    } else {
        fprintf(stderr, "Failed to load the entry module: %s\n", main_js_path);
    }

    //JS_FreeValue(ctx, result);
    JS_FreeContext(ctx);
    JS_FreeRuntime(rt);

    return NULL;
}

int main(int argc, char *argv[]) {
    printf("aaaaaaaaaaaaaaaaa\n");
    init(argc, argv);
}