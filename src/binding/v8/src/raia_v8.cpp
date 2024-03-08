//
// raia_v8
//

#include "raia_v8.h"

void raia_lib_open(const v8_args_t &args) {
    auto library_name = v8_args_to_str(args, 0) + "." + DYNAMIC_LIB_EXT;
    v8_rets_to_sint(args, open_shared_library(library_name.c_str()));
}

void raia_lib_close(const v8_args_t &args) {
    auto library_key = v8_args_to_sint(args, 0);
    close_shared_library(library_key);
}

void raia_lib_close_all(const v8_args_t &args) {
    close_all_shared_library();
}

void raia_lib_add(const v8_args_t &args) {
    auto library_key = v8_args_to_sint(args, 0);
    auto func_name = v8_args_to_str(args, 1);
    add_func_shared_library(library_key, func_name.c_str());
}

void raia_lib_call(const v8_args_t &args) {
    auto library_key = v8_args_to_sint(args, 0);
    auto func_name = v8_args_to_str(args, 1);
    auto src = v8_args_to_str(args, 2);
    auto rets = call_func_shared_library(library_key, func_name.c_str(), src.c_str());
    if (rets) {
        v8_rets_to_str(args, rets);
        delete rets;
    } else {
        v8_rets_to_null(args);
    }
}

void raia_lib_ffi(const v8_args_t &args) {
    auto library_key = v8_args_to_sint(args, 0);
    auto func_name = v8_args_to_str(args, 1);
    auto ret_type = v8_args_to_str(args, 2);
    ffi_type *ffi_args_type[512];
    void *ffi_args_values[512];
    args_key_t ffi_rets;
    // 引数の設定
    int args_len = 0;
    v8::Local<v8::Array> args_list;
    if(!args[2]->IsNull()) {
        args_list = v8_args_to_array(args, 3);
        args_len = (int)args_list->Length();
        auto isolate = args.GetIsolate();
        for (int i = 0; i < args_list->Length(); i++) {
            auto arg_list = v8_array_to_array(args_list, i);
            auto arg_type = v8_array_to_str(isolate, arg_list, 0);
            auto arg_name = v8_array_to_str(isolate, arg_list, 1);
            if (arg_type == "uint8") {
                uint8_t value = v8_array_to_uint8(isolate, arg_list, 2);
                ffi_args_values[i] = add_args_hash_to_uint8(arg_name.c_str(), value);
                ffi_args_type[i] = &ffi_type_uint8;
            } else if (arg_type == "sint8") {
                int8_t value = v8_array_to_sint8(isolate, arg_list, 2);
                ffi_args_values[i] = add_args_hash_to_sint8(arg_name.c_str(), value);
                ffi_args_type[i] = &ffi_type_sint8;
            } else if (arg_type == "uint16") {
                uint16_t value = v8_array_to_uint16(isolate, arg_list, 2);
                ffi_args_values[i] = add_args_hash_to_uint16(arg_name.c_str(), value);
                ffi_args_type[i] = &ffi_type_uint16;
            } else if (arg_type == "sint16") {
                int16_t value = v8_array_to_sint16(isolate, arg_list, 2);
                ffi_args_values[i] = add_args_hash_to_sint16(arg_name.c_str(), value);
                ffi_args_type[i] = &ffi_type_sint16;
            } else if (arg_type == "uint32") {
                uint32_t value = v8_array_to_uint32(isolate, arg_list, 2);
                ffi_args_values[i] = add_args_hash_to_uint32(arg_name.c_str(), value);
                ffi_args_type[i] = &ffi_type_uint32;
            } else if (arg_type == "sint32") {
                int32_t value = v8_array_to_sint32(isolate, arg_list, 2);
                ffi_args_values[i] = add_args_hash_to_sint32(arg_name.c_str(), value);
                ffi_args_type[i] = &ffi_type_sint32;
            } else if (arg_type == "uint64") {
                uint64_t value = v8_array_to_uint64(isolate, arg_list, 2);
                ffi_args_values[i] = add_args_hash_to_uint64(arg_name.c_str(), value);
                ffi_args_type[i] = &ffi_type_uint64;
            } else if (arg_type == "sint64") {
                int64_t value = v8_array_to_sint64(isolate, arg_list, 2);
                ffi_args_values[i] = add_args_hash_to_sint64(arg_name.c_str(), value);
                ffi_args_type[i] = &ffi_type_sint64;
            } else if (arg_type == "float") {
                float value = v8_array_to_float(isolate, arg_list, 2);
                ffi_args_values[i] = add_args_hash_to_float(arg_name.c_str(), value);
                ffi_args_type[i] = &ffi_type_float;
            } else if (arg_type == "double") {
                double value = v8_array_to_double(isolate, arg_list, 2);
                ffi_args_values[i] = add_args_hash_to_double(arg_name.c_str(), value);
                ffi_args_type[i] = &ffi_type_double;
            } else if (arg_type == "uchar") {
                unsigned char value = v8_array_to_uchar(isolate, arg_list, 2);
                ffi_args_values[i] = add_args_hash_to_uchar(arg_name.c_str(), value);
                ffi_args_type[i] = &ffi_type_uchar;
            } else if (arg_type == "schar") {
                char value = v8_array_to_schar(isolate, arg_list, 2);
                ffi_args_values[i] = add_args_hash_to_schar(arg_name.c_str(), value);
                ffi_args_type[i] = &ffi_type_schar;
            } else if (arg_type == "ushort") {
                unsigned short value = v8_array_to_ushort(isolate, arg_list, 2);
                ffi_args_values[i] = add_args_hash_to_ushort(arg_name.c_str(), value);
                ffi_args_type[i] = &ffi_type_ushort;
            } else if (arg_type == "sshort") {
                short value = v8_array_to_sshort(isolate, arg_list, 2);
                ffi_args_values[i] = add_args_hash_to_sshort(arg_name.c_str(), value);
                ffi_args_type[i] = &ffi_type_sshort;
            } else if (arg_type == "uint") {
                unsigned int value = v8_array_to_uint(isolate, arg_list, 2);
                ffi_args_values[i] = add_args_hash_to_uint(arg_name.c_str(), value);
                ffi_args_type[i] = &ffi_type_uint;
            } else if (arg_type == "sint") {
                int value = v8_array_to_sint(isolate, arg_list, 2);
                ffi_args_values[i] = add_args_hash_to_sint(arg_name.c_str(), value);
                ffi_args_type[i] = &ffi_type_sint;
            } else if (arg_type == "ulong") {
                unsigned long value = v8_array_to_ulong(isolate, arg_list, 2);
                ffi_args_values[i] = add_args_hash_to_ulong(arg_name.c_str(), value);
                ffi_args_type[i] = &ffi_type_ulong;
            } else if (arg_type == "slong") {
                long value = v8_array_to_slong(isolate, arg_list, 2);
                ffi_args_values[i] = add_args_hash_to_slong(arg_name.c_str(), value);
                ffi_args_type[i] = &ffi_type_slong;
            } else if (arg_type == "longdouble") {
                long double value = v8_array_to_longdouble(isolate, arg_list, 2);
                ffi_args_values[i] = add_args_hash_to_longdouble(arg_name.c_str(), value);
                ffi_args_type[i] = &ffi_type_longdouble;
            } else if (arg_type == "string") {
                auto src = v8_array_to_str(isolate, arg_list, 2);
                char *dst = new char[src.length() + 1];
                std::strcpy(dst, src.c_str());
                ffi_args_values[i] = add_args_hash_to_string(arg_name.c_str(), dst);
                ffi_args_type[i] = &ffi_type_pointer;
            } else if (arg_type == "pointer") {
                auto local_value = v8_array_to_value(isolate, arg_list, 2);
                void *value;
                if (local_value->IsNull()) {
                    value = nullptr;
                } else {
                    value = v8_array_to_ptr(isolate, arg_list, 2);
                }
                ffi_args_values[i] = add_args_hash_to_pointer(arg_name.c_str(), value);
                ffi_args_type[i] = &ffi_type_pointer;
            } else if (arg_type == "struct") {
                auto obj = v8_array_to_obj(isolate, arg_list, 2);
                ffi_type **struct_types = (ffi_type **)(uintptr_t)v8_obj_to_ptr(isolate, obj, "types");
                void *struct_binary = (void *)(uintptr_t)v8_obj_to_ptr(isolate, obj, "binary");
                ffi_type st_type = {
                        .size = 0,
                        .alignment = 0,
                        .type = FFI_TYPE_STRUCT,
                        .elements = struct_types
                };
                ffi_args_values[i] = add_args_hash_to_struct(arg_name.c_str(), struct_binary);
                ffi_args_type[i] = &st_type;
            } else {
                fprintf(stderr, "Unknown type: %s\n", arg_type.c_str());
                exit(1);
            }
        }
    }
    // 戻り値の設定
    if (ret_type == "void") {
        ffi_call_ext(find_func_shared_library(library_key, func_name.c_str()), args_len, &ffi_type_void, ffi_args_type, nullptr, ffi_args_values);
        v8_rets_to_null(args);
    } else if (ret_type == "uint8") {
        ffi_call_ext(find_func_shared_library(library_key, func_name.c_str()), args_len, &ffi_type_uint8, ffi_args_type, &ffi_rets.data.value_uint8, ffi_args_values);
        v8_rets_to_uint8(args, ffi_rets.data.value_uint8);
    } else if (ret_type == "sint8") {
        ffi_call_ext(find_func_shared_library(library_key, func_name.c_str()), args_len, &ffi_type_sint8, ffi_args_type, &ffi_rets.data.value_sint8, ffi_args_values);
        v8_rets_to_sint8(args, ffi_rets.data.value_sint8);
    } else if (ret_type == "uint16") {
        ffi_call_ext(find_func_shared_library(library_key, func_name.c_str()), args_len, &ffi_type_uint16, ffi_args_type, &ffi_rets.data.value_uint16, ffi_args_values);
        v8_rets_to_uint16(args, ffi_rets.data.value_uint16);
    } else if (ret_type == "sint16") {
        ffi_call_ext(find_func_shared_library(library_key, func_name.c_str()), args_len, &ffi_type_sint16, ffi_args_type, &ffi_rets.data.value_sint16, ffi_args_values);
        v8_rets_to_sint16(args, ffi_rets.data.value_sint16);
    } else if (ret_type == "uint32") {
        ffi_call_ext(find_func_shared_library(library_key, func_name.c_str()), args_len, &ffi_type_uint32, ffi_args_type, &ffi_rets.data.value_uint32, ffi_args_values);
        v8_rets_to_uint32(args, ffi_rets.data.value_uint32);
    } else if (ret_type == "sint32") {
        ffi_call_ext(find_func_shared_library(library_key, func_name.c_str()), args_len, &ffi_type_sint32, ffi_args_type, &ffi_rets.data.value_sint32, ffi_args_values);
        v8_rets_to_sint32(args, ffi_rets.data.value_sint32);
    } else if (ret_type == "uint64") {
        ffi_call_ext(find_func_shared_library(library_key, func_name.c_str()), args_len, &ffi_type_uint64, ffi_args_type, &ffi_rets.data.value_uint64, ffi_args_values);
        v8_rets_to_uint64(args, ffi_rets.data.value_uint64);
    } else if (ret_type == "sint64") {
        ffi_call_ext(find_func_shared_library(library_key, func_name.c_str()), args_len, &ffi_type_sint64, ffi_args_type, &ffi_rets.data.value_sint64, ffi_args_values);
        v8_rets_to_sint64(args, ffi_rets.data.value_sint64);
    } else if (ret_type == "float") {
        ffi_call_ext(find_func_shared_library(library_key, func_name.c_str()), args_len, &ffi_type_float, ffi_args_type, &ffi_rets.data.value_float, ffi_args_values);
        v8_rets_to_float(args, ffi_rets.data.value_float);
    } else if (ret_type == "double") {
        ffi_call_ext(find_func_shared_library(library_key, func_name.c_str()), args_len, &ffi_type_double, ffi_args_type, &ffi_rets.data.value_double, ffi_args_values);
        v8_rets_to_double(args, ffi_rets.data.value_double);
    } else if (ret_type == "uchar") {
        ffi_call_ext(find_func_shared_library(library_key, func_name.c_str()), args_len, &ffi_type_uchar, ffi_args_type, &ffi_rets.data.value_uchar, ffi_args_values);
        v8_rets_to_uchar(args, ffi_rets.data.value_uchar);
    } else if (ret_type == "schar") {
        ffi_call_ext(find_func_shared_library(library_key, func_name.c_str()), args_len, &ffi_type_schar, ffi_args_type, &ffi_rets.data.value_schar, ffi_args_values);
        v8_rets_to_schar(args, ffi_rets.data.value_schar);
    } else if (ret_type == "ushort") {
        ffi_call_ext(find_func_shared_library(library_key, func_name.c_str()), args_len, &ffi_type_ushort, ffi_args_type, &ffi_rets.data.value_ushort, ffi_args_values);
        v8_rets_to_ushort(args, ffi_rets.data.value_ushort);
    } else if (ret_type == "sshort") {
        ffi_call_ext(find_func_shared_library(library_key, func_name.c_str()), args_len, &ffi_type_sshort, ffi_args_type, &ffi_rets.data.value_sshort, ffi_args_values);
        v8_rets_to_sshort(args, ffi_rets.data.value_sshort);
    } else if (ret_type == "uint") {
        ffi_call_ext(find_func_shared_library(library_key, func_name.c_str()), args_len, &ffi_type_uint, ffi_args_type, &ffi_rets.data.value_uint, ffi_args_values);
        v8_rets_to_uint(args, ffi_rets.data.value_uint);
    } else if (ret_type == "sint") {
        ffi_call_ext(find_func_shared_library(library_key, func_name.c_str()), args_len, &ffi_type_sint, ffi_args_type, &ffi_rets.data.value_sint, ffi_args_values);
        v8_rets_to_sint(args, ffi_rets.data.value_sint);
    } else if (ret_type == "ulong") {
        ffi_call_ext(find_func_shared_library(library_key, func_name.c_str()), args_len, &ffi_type_ulong, ffi_args_type, &ffi_rets.data.value_ulong, ffi_args_values);
        v8_rets_to_ulong(args, ffi_rets.data.value_ulong);
    } else if (ret_type == "slong") {
        ffi_call_ext(find_func_shared_library(library_key, func_name.c_str()), args_len, &ffi_type_slong, ffi_args_type, &ffi_rets.data.value_slong, ffi_args_values);
        v8_rets_to_slong(args, ffi_rets.data.value_slong);
    } else if (ret_type == "longdouble") {
        ffi_call_ext(find_func_shared_library(library_key, func_name.c_str()), args_len, &ffi_type_longdouble, ffi_args_type, &ffi_rets.data.value_longdouble, ffi_args_values);
        v8_rets_to_longdouble(args, ffi_rets.data.value_longdouble);
    } else if (ret_type == "string") {
        ffi_call_ext(find_func_shared_library(library_key, func_name.c_str()), args_len, &ffi_type_pointer, ffi_args_type, &ffi_rets.data.value_string, ffi_args_values);
        v8_rets_to_str(args, ffi_rets.data.value_string);
    } else if (ret_type == "pointer") {
        ffi_call_ext(find_func_shared_library(library_key, func_name.c_str()), args_len, &ffi_type_pointer, ffi_args_type, &ffi_rets.data.value_pointer, ffi_args_values);
        v8_rets_to_ptr(args, ffi_rets.data.value_pointer);
    } else {
        fprintf(stderr, "Unknown type: %s\n", ret_type.c_str());
        exit(1);
    }
    delete_all_args_name_hash();
    delete_all_args_hash();
}

void raia_core_print(const v8_args_t &args) {
    std::cout << v8_args_to_str(args, 0) << std::endl;
}

void raia_core_exit(const v8_args_t &args) {
    exit(v8_args_to_sint(args, 0));
}

void raia_core_make_struct(const v8_args_t &args) {
    auto isolate = args.GetIsolate();
    auto args_list = v8_args_to_array(args, 0);
    // バイナリの合計サイズを計算する
    int binary_size = 0;
    for (int i = 0; i < args_list->Length(); i++) {
        auto arg_list = v8_array_to_array(args_list, i);
        auto arg_type = v8_array_to_str(isolate, arg_list, 0);
        if (arg_type == "uint8" || arg_type == "sint8" || arg_type == "uchar" || arg_type == "schar") {
            binary_size += 1;
        } else if (arg_type == "uint16" || arg_type == "sint16" || arg_type == "ushort" || arg_type == "sshort") {
            binary_size += 2;
        } else if (arg_type == "uint32" || arg_type == "sint32" || arg_type == "float" || arg_type == "uint" || arg_type == "sint" || arg_type == "ulong" || arg_type == "slong") {
            binary_size += 4;
        } else if (arg_type == "uint64" || arg_type == "sint64" || arg_type == "double") {
            binary_size += 8;
        } else if (arg_type == "longdouble") {
            binary_size += 16;
        } else if (arg_type == "string") {
            auto str = v8_array_to_str(isolate, arg_list, 1);
            binary_size += (int)str.length() + 1;
        } else if (arg_type == "pointer") {
            binary_size += sizeof(void*);
        } else {
            fprintf(stderr, "Unknown type: %s\n", arg_type.c_str());
            exit(1);
        }
    }
    // タイプ情報とバイナリデータを初期化・取得する
    ffi_type **type_elements = (ffi_type **)malloc((args_list->Length() + 1) * sizeof(ffi_type *));
    type_elements[args_list->Length() + 1] = nullptr;
    uint8_t *binary = (uint8_t *)malloc(binary_size);
    int binary_offset = 0;
    for(int i = 0; i < args_list->Length(); i ++) {
        auto arg_list = v8_array_to_array(args_list, i);
        auto arg_type = v8_array_to_str(isolate, arg_list, 0);
        if (arg_type == "uint8") {
            type_elements[i] = &ffi_type_uint8;
            uint8_t value = v8_array_to_uint8(isolate, arg_list, 1);
            memcpy(binary + binary_offset, &value, 1);
            binary_offset += 1;
        } else if (arg_type == "sint8") {
            type_elements[i] = &ffi_type_sint8;
            int8_t value = v8_array_to_sint8(isolate, arg_list, 1);
            memcpy(binary + binary_offset, &value, 1);
            binary_offset += 1;
        } else if (arg_type == "uint16") {
            type_elements[i] = &ffi_type_uint16;
            uint16_t value = v8_array_to_uint16(isolate, arg_list, 1);
            memcpy(binary + binary_offset, &value, 2);
            binary_offset += 2;
        } else if (arg_type == "sint16") {
            type_elements[i] = &ffi_type_sint16;
            int16_t value = v8_array_to_sint16(isolate, arg_list, 1);
            memcpy(binary + binary_offset, &value, 2);
            binary_offset += 2;
        } else if (arg_type == "uint32") {
            type_elements[i] = &ffi_type_uint32;
            uint32_t value = v8_array_to_uint32(isolate, arg_list, 1);
            memcpy(binary + binary_offset, &value, 4);
            binary_offset += 4;
        } else if (arg_type == "sint32") {
            type_elements[i] = &ffi_type_sint32;
            int32_t value = v8_array_to_sint32(isolate, arg_list, 1);
            memcpy(binary + binary_offset, &value, 4);
            binary_offset += 4;
        } else if (arg_type == "uint64") {
            type_elements[i] = &ffi_type_uint64;
            uint64_t value = v8_array_to_uint64(isolate, arg_list, 1);
            memcpy(binary + binary_offset, &value, 8);
            binary_offset += 8;
        } else if (arg_type == "sint64") {
            type_elements[i] = &ffi_type_sint64;
            int64_t value = v8_array_to_sint64(isolate, arg_list, 1);
            memcpy(binary + binary_offset, &value, 8);
            binary_offset += 8;
        } else if (arg_type == "float") {
            type_elements[i] = &ffi_type_float;
            float value = v8_array_to_float(isolate, arg_list, 1);
            memcpy(binary + binary_offset, &value, 4);
            binary_offset += 4;
        } else if (arg_type == "double") {
            type_elements[i] = &ffi_type_double;
            double value = v8_array_to_double(isolate, arg_list, 1);
            memcpy(binary + binary_offset, &value, 8);
            binary_offset += 8;
        } else if (arg_type == "uchar") {
            type_elements[i] = &ffi_type_uchar;
            unsigned char value = v8_array_to_uchar(isolate, arg_list, 1);
            memcpy(binary + binary_offset, &value, 1);
            binary_offset += 1;
        } else if (arg_type == "schar") {
            type_elements[i] = &ffi_type_schar;
            char value = v8_array_to_schar(isolate, arg_list, 1);
            memcpy(binary + binary_offset, &value, 1);
            binary_offset += 1;
        } else if (arg_type == "ushort") {
            type_elements[i] = &ffi_type_ushort;
            unsigned short value = v8_array_to_ushort(isolate, arg_list, 1);
            memcpy(binary + binary_offset, &value, 2);
            binary_offset += 2;
        } else if (arg_type == "sshort") {
            type_elements[i] = &ffi_type_ushort;
            short value = v8_array_to_sshort(isolate, arg_list, 1);
            memcpy(binary + binary_offset, &value, 2);
            binary_offset += 2;
        } else if (arg_type == "uint") {
            type_elements[i] = &ffi_type_uint;
            unsigned int value = v8_array_to_uint(isolate, arg_list, 1);
            memcpy(binary + binary_offset, &value, 4);
            binary_offset += 4;
        } else if (arg_type == "sint") {
            type_elements[i] = &ffi_type_sint;
            int value = v8_array_to_sint(isolate, arg_list, 1);
            memcpy(binary + binary_offset, &value, 4);
            binary_offset += 4;
        } else if (arg_type == "ulong") {
            type_elements[i] = &ffi_type_ulong;
            unsigned long value = v8_array_to_ulong(isolate, arg_list, 1);
            memcpy(binary + binary_offset, &value, 4);
            binary_offset += 4;
        } else if (arg_type == "slong") {
            type_elements[i] = &ffi_type_slong;
            long value = v8_array_to_slong(isolate, arg_list, 1);
            memcpy(binary + binary_offset, &value, 4);
            binary_offset += 4;
        } else if (arg_type == "longdouble") {
            type_elements[i] = &ffi_type_longdouble;
            long double value = v8_array_to_longdouble(isolate, arg_list, 1);
            memcpy(binary + binary_offset, &value, 16);
            binary_offset += 16;
        } else if (arg_type == "string") {
            type_elements[i] = &ffi_type_pointer;
            auto src = v8_array_to_str(isolate, arg_list, 1);
            char* dst = new char[src.length() + 1];
            std::strcpy(dst, src.c_str());
            memcpy(binary + binary_offset, dst, (int)src.length() + 1);
            free(dst);
            binary_offset += (int)src.length() + 1;
        } else if (arg_type == "pointer") {
            type_elements[i] = &ffi_type_pointer;
            void *value = v8_array_to_ptr(isolate, arg_list, 1);
            memcpy(binary + binary_offset, &value, sizeof(void*));
            binary_offset += sizeof(void*);
        } else {
            fprintf(stderr, "Unknown type: %s\n", arg_type.c_str());
            exit(1);
        }
    }
    auto obj = v8::Object::New(args.GetIsolate());
    v8_obj_add(args.GetIsolate(), obj, "types", (double)(uintptr_t)type_elements);
    v8_obj_add(args.GetIsolate(), obj, "binary", (double)(uintptr_t)binary);
    args.GetReturnValue().Set(obj);
}

void raia_core_del_struct(const v8_args_t &args) {
    auto obj = v8_args_to_obj(args, 0);
    ffi_type **struct_types = (ffi_type **)(uintptr_t)v8_obj_to_ptr(args.GetIsolate(), obj, "types");
    void *struct_binary = (void *)(uintptr_t)v8_obj_to_ptr(args.GetIsolate(), obj, "binary");
    free((void *)struct_types);
    free((void *)struct_binary);
    v8_rets_to_null(args);
}

void raia_core_new_ptr(const v8_args_t &args) {
    auto size = v8_args_to_sint(args, 0);
    void *ptr = (void *)malloc(size);
    v8_rets_to_ptr(args, ptr);
}

void raia_core_del_ptr(const v8_args_t &args) {
    auto ptr = v8_args_to_ptr(args, 0);
    free(ptr);
    v8_rets_to_null(args);
}

void raia_core_buf_to_ptr(const v8_args_t &args) {
    auto buf = v8_args_to_buf(args, 0);
    auto ptr = v8_buf_to_ptr(buf);
    v8_rets_to_ptr(args, ptr);
}

void raia_core_ptr_to_buf(const v8_args_t &args) {
    auto ptr = v8_args_to_ptr(args, 0);
    auto size = v8_args_to_sint(args, 1);
    auto buf = v8::ArrayBuffer::New(args.GetIsolate(), size);
    memcpy(buf->Data(), ptr, size);
    v8_rets_to_buf(args, buf);
}

void raia_core_ptr_to_sint(const v8_args_t &args) {
    auto ptr = v8_args_to_ptr(args, 0);
    v8_rets_to_sint(args, *(int *)ptr);
}

void raia_gc_free(const v8_args_t &args) {
    args.GetIsolate()->LowMemoryNotification();
    v8_rets_to_null(args);
}

int raia_v8_main(int argc, char *argv[]) {
    v8::V8::SetFlagsFromString("--expose-gc");
    v8_init();
    v8_isolate_init(isolate, isolate_params);
    v8_isolate_set_callback(isolate, import_dynamic_callback, import_meta);
    v8_context_init(isolate, context);
    v8_set_obj(isolate, Raia, context->Global(), "__Raia__");
    v8_set_obj(isolate, Core, Raia, "Core");
    v8_set_func(isolate, Core, "print", raia_core_print);
    v8_set_func(isolate, Core, "exit", raia_core_exit);
    v8_set_func(isolate, Core, "ptrToBuf", raia_core_ptr_to_buf); // ptrToBuf
    v8_set_func(isolate, Core, "bufToPtr", raia_core_buf_to_ptr); // bufToPtr
    v8_set_func(isolate, Core, "makeStruct", raia_core_make_struct);
    v8_set_func(isolate, Core, "delStruct", raia_core_del_struct);   // delStruct
    v8_set_func(isolate, Core, "newPtr", raia_core_new_ptr); // delPtr
    v8_set_func(isolate, Core, "delPtr", raia_core_del_ptr); // delPtr
    v8_set_func(isolate, Core, "ptrToInt", raia_core_ptr_to_sint); // delPtr
    v8_set_obj(isolate, Lib, Raia, "Lib");
    v8_set_func(isolate, Lib, "open", raia_lib_open);
    v8_set_func(isolate, Lib, "close", raia_lib_close);
    v8_set_func(isolate, Lib, "closeAll", raia_lib_close_all);
    v8_set_func(isolate, Lib, "add", raia_lib_add);
    v8_set_func(isolate, Lib, "call", raia_lib_call);
    v8_set_func(isolate, Lib, "ffi", raia_lib_ffi);
    v8_set_obj(isolate, GC, Raia, "GC");
    v8_set_func(isolate, GC, "free", raia_gc_free);
    v8_start();
    v8_destroy(isolate_params);
    return 0;
}

extern "C" RAIA_API char *init(int argc, char *argv[]) {
    init_startup_script();
    raia_v8_main(argc, argv);
    return nullptr;
}

// static

extern "C" {

//
// v8::V8
//

bool v8_V8_Initialize() {
    return v8::V8::Initialize();
}

void v8_V8_InitializePlatform(int v8_platform_key_in) {
    v8::V8::InitializePlatform(static_v8_platform_get(v8_platform_key_in));
}

bool v8_V8_Dispose() {
    return v8::V8::Dispose();
}

void v8_V8_DisposePlatform() {
    v8::V8::DisposePlatform();
}


//
// v8::Platform
//

int v8_Platform_NewDefaultPlatform () {
    return static_v8_platform_make(v8::platform::NewDefaultPlatform());
}

//
// v8::Isolate
//

// static

v8::Isolate * v8_Isolate_New(const v8::Isolate::CreateParams *params) {
    return v8::Isolate::New(*params);
}

//
// v8::Isolate::CreateParams
//

v8::Isolate::CreateParams* v8_Isolate_CreateParams_new() {
    return new v8::Isolate::CreateParams();
}

//
// v8::Isolate::Scope
//

v8::Isolate::Scope v8_Isolate_Scope_new(v8::Isolate *isolate) {
    return v8::Isolate::Scope(isolate);
}

//
// v8::ArrayBuffer::Allocator
//

v8::ArrayBuffer::Allocator * v8_ArrayBuffer_Allocator_NewDefaultAllocator() {
    return v8::ArrayBuffer::Allocator::NewDefaultAllocator();
}

//
// v8::HandleScope
//

v8::HandleScope v8_HandleScope_new(v8::Isolate *isolate) {
    return v8::HandleScope(isolate);
}

//
// v8::Context
//

// static

v8::Local<v8::Context> v8_Context_New(v8::Isolate *isolate, v8::ExtensionConfiguration *extensions=nullptr, v8::MaybeLocal<v8::ObjectTemplate > global_template=v8::MaybeLocal< v8::ObjectTemplate >(), v8::MaybeLocal< v8::Value > global_object=v8::MaybeLocal< v8::Value >(), v8::DeserializeInternalFieldsCallback internal_fields_deserializer=v8::DeserializeInternalFieldsCallback(), v8::MicrotaskQueue *microtask_queue=nullptr) {
    return v8::Context::New(isolate, extensions, global_template, global_object, internal_fields_deserializer, microtask_queue);
}

//
// v8::Context::Scope
//

v8::Context::Scope v8_Context_ScopeScope_new(v8::Local<v8::Context> context) {
    return v8::Context::Scope(context);
}


//
// v8::ObjectTemplate
//

v8::Local<v8::ObjectTemplate> v8_ObjectTemplate_New(v8::Isolate *isolate, v8::Local<v8::FunctionTemplate> constructor=v8::Local<v8::FunctionTemplate >()) {
    return v8::ObjectTemplate::New(isolate);
}

}
//
//int main(int argc, char *argv[]) {
//    //int platform = v8_Platform_NewDefaultPlatform();
//    //v8_V8_InitializePlatform(platform);
//    //v8_V8_Initialize();
//    //auto isolate_params = v8_Isolate_CreateParams_new();
//    //static_v8_isolate_create_params_set_array_buffer_allocator(isolate_params, v8_ArrayBuffer_Allocator_NewDefaultAllocator());
//    //auto isolate = v8_Isolate_New(isolate_params);
//    //auto isolate_scope = v8_Isolate_Scope_new(isolate);
//    //auto handle_scope = v8_HandleScope_new(isolate);
//    //auto context = v8_Context_New(isolate, nullptr, v8_ObjectTemplate_New(isolate));
//    //auto context_scope = v8_Context_ScopeScope_new(context);
//    //v8_V8_Dispose();
//    //v8_V8_DisposePlatform();
//    //static_v8_platform_delete(platform);
//    //static_v8_isolate_create_params_delete_array_buffer_allocator(isolate_params);
//    //printf("Hello V8.");
//    //init(argc, argv);
//    return 0;
//}