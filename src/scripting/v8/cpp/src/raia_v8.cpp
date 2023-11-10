//
// raia_v8
//

#include "raia_v8.h"

void raia_lib_open(const v8_args_t &args) {
    auto lib_name = v8_args_to_str(args, 0) + "." + DYNAMIC_LIB_EXT;
    v8_rets_to_ptr(args, add_plugin_hash(lib_name.c_str()));
}

void raia_lib_close(const v8_args_t &args) {
    auto lib_name = v8_args_to_str(args, 0);
    delete_plugin_hash(lib_name.c_str());
}

void raia_lib_close_all(const v8_args_t &args) {
    free_plugin_hash();
}

void raia_lib_add(const v8_args_t &args) {
    auto handle = v8_args_to_ptr(args, 0);
    auto func_name = v8_args_to_str(args, 1);
    add_plugin_func_hash(handle, func_name.c_str());
}

void raia_lib_call(const v8_args_t &args) {
    auto dll_func_name = v8_args_to_str(args, 0);
    auto src = v8_args_to_str(args, 1);
    auto rets = call_func_hash(dll_func_name.c_str(), src.c_str());
    if (rets) {
        v8_rets_to_str(args, rets);
        delete rets;
    } else {
        v8_rets_to_null(args);
    }
}

void raia_lib_ffi(const v8_args_t &args) {
    auto func_name = v8_args_to_str(args, 0);
    auto ret_type = v8_args_to_str(args, 1);
    int args_offset = 2; // 引数の始まる位置（0: 関数名, 1: 戻り値, 2から引数）
    int args_group = 3; // 1つの引数の含まれる情報の数(1: 型, 2: 引数名, 3: 値)
    int args_len = (args.Length() - args_offset) / args_group;
    ffi_type *ffi_args_type[512];
    void *ffi_args_values[512];
    args_key_t ffi_rets;
    // 引数の設定
    for(int i = args_offset, count = 0; i < args.Length(); i += args_group, count++) {
        auto arg_type = v8_args_to_str(args, i);
        if (arg_type == "uint8") {
            auto name = v8_args_to_str(args, i + 1);
            uint8_t value = v8_args_to_uint8(args, i + 2);
            ffi_args_values[count] = add_args_hash_to_uint8(name.c_str(), value);
            ffi_args_type[count] = &ffi_type_uint8;
        } else if (arg_type == "sint8") {
            auto name = v8_args_to_str(args, i + 1);
            int8_t value = v8_args_to_sint8(args, i + 2);
            ffi_args_values[count] = add_args_hash_to_sint8(name.c_str(), value);
            ffi_args_type[count] = &ffi_type_sint8;
        } else if (arg_type == "uint16") {
            auto name = v8_args_to_str(args, i + 1);
            uint16_t value = v8_args_to_uint16(args, i + 2);
            ffi_args_values[count] = add_args_hash_to_uint16(name.c_str(), value);
            ffi_args_type[count] = &ffi_type_uint16;
        } else if (arg_type == "sint16") {
            auto name = v8_args_to_str(args, i + 1);
            int16_t value = v8_args_to_sint16(args, i + 2);
            ffi_args_values[count] = add_args_hash_to_sint16(name.c_str(), value);
            ffi_args_type[count] = &ffi_type_sint16;
        } else if (arg_type == "uint32") {
            auto name = v8_args_to_str(args, i + 1);
            uint32_t value = v8_args_to_uint32(args, i + 2);
            ffi_args_values[count] = add_args_hash_to_uint32(name.c_str(), value);
            ffi_args_type[count] = &ffi_type_uint32;
        } else if (arg_type == "sint32") {
            auto name = v8_args_to_str(args, i + 1);
            int32_t value = v8_args_to_sint32(args, i + 2);
            ffi_args_values[count] = add_args_hash_to_sint32(name.c_str(), value);
            ffi_args_type[count] = &ffi_type_sint32;
        } else if (arg_type == "uint64") {
            auto name = v8_args_to_str(args, i + 1);
            uint64_t value = v8_args_to_uint64(args, i + 2);
            ffi_args_values[count] = add_args_hash_to_uint64(name.c_str(), value);
            ffi_args_type[count] = &ffi_type_uint64;
        } else if (arg_type == "sint64") {
            auto name = v8_args_to_str(args, i + 1);
            int64_t value = v8_args_to_sint64(args, i + 2);
            ffi_args_values[count] = add_args_hash_to_sint64(name.c_str(), value);
            ffi_args_type[count] = &ffi_type_sint64;
        } else if (arg_type == "float") {
            auto name = v8_args_to_str(args, i + 1);
            float value = v8_args_to_float(args, i + 2);
            ffi_args_values[count] = add_args_hash_to_float(name.c_str(), value);
            ffi_args_type[count] = &ffi_type_float;
        } else if (arg_type == "double") {
            auto name = v8_args_to_str(args, i + 1);
            double value = v8_args_to_double(args, i + 2);
            ffi_args_values[count] = add_args_hash_to_double(name.c_str(), value);
            ffi_args_type[count] = &ffi_type_double;
        } else if (arg_type == "uchar") {
            auto name = v8_args_to_str(args, i + 1);
            unsigned char value = v8_args_to_uchar(args, i + 2);
            ffi_args_values[count] = add_args_hash_to_uchar(name.c_str(), value);
            ffi_args_type[count] = &ffi_type_uchar;
        } else if (arg_type == "schar") {
            auto name = v8_args_to_str(args, i + 1);
            char value = v8_args_to_schar(args, i + 2);
            ffi_args_values[count] = add_args_hash_to_schar(name.c_str(), value);
            ffi_args_type[count] = &ffi_type_schar;
        } else if (arg_type == "ushort") {
            auto name = v8_args_to_str(args, i + 1);
            unsigned short value = v8_args_to_ushort(args, i + 2);
            ffi_args_values[count] = add_args_hash_to_ushort(name.c_str(), value);
            ffi_args_type[count] = &ffi_type_ushort;
        } else if (arg_type == "sshort") {
            auto name = v8_args_to_str(args, i + 1);
            short value = v8_args_to_sshort(args, i + 2);
            ffi_args_values[count] = add_args_hash_to_sshort(name.c_str(), value);
            ffi_args_type[count] = &ffi_type_sshort;
        } else if (arg_type == "uint") {
            auto name = v8_args_to_str(args, i + 1);
            unsigned int value = v8_args_to_uint(args, i + 2);
            ffi_args_values[count] = add_args_hash_to_uint(name.c_str(), value);
            ffi_args_type[count] = &ffi_type_uint;
        } else if (arg_type == "sint") {
            auto name = v8_args_to_str(args, i + 1);
            int value = v8_args_to_sint(args, i + 2);
            ffi_args_values[count] = add_args_hash_to_sint(name.c_str(), value);
            ffi_args_type[count] = &ffi_type_sint;
        } else if (arg_type == "ulong") {
            auto name = v8_args_to_str(args, i + 1);
            unsigned long value = v8_args_to_ulong(args, i + 2);
            ffi_args_values[count] = add_args_hash_to_ulong(name.c_str(), value);
            ffi_args_type[count] = &ffi_type_ulong;
        } else if (arg_type == "slong") {
            auto name = v8_args_to_str(args, i + 1);
            long value = v8_args_to_slong(args, i + 2);
            ffi_args_values[count] = add_args_hash_to_slong(name.c_str(), value);
            ffi_args_type[count] = &ffi_type_slong;
        } else if (arg_type == "longdouble") {
            auto name = v8_args_to_str(args, i + 1);
            long double value = v8_args_to_longdouble(args, i + 2);
            ffi_args_values[count] = add_args_hash_to_longdouble(name.c_str(), value);
            ffi_args_type[count] = &ffi_type_longdouble;
        } else if (arg_type == "string") {
            auto name = v8_args_to_str(args, i + 1);
            auto src = v8_args_to_str(args, i + 2);
            char* dst = new char[src.length() + 1];
            std::strcpy(dst, src.c_str());
            ffi_args_values[count] = add_args_hash_to_string(name.c_str(), dst);
            ffi_args_type[count] = &ffi_type_pointer;
        } else if (arg_type == "pointer") {
            auto name = v8_args_to_str(args, i + 1);
            void *value = v8_args_to_ptr(args, i + 2);
            ffi_args_values[count] = add_args_hash_to_pointer(name.c_str(), value);
            ffi_args_type[count] = &ffi_type_pointer;
        } else if (arg_type == "struct") {
            auto name = v8_args_to_str(args, i + 1);
            v8::Local<v8::Object> obj = args[i + 2]->ToObject(args.GetIsolate()->GetCurrentContext()).ToLocalChecked();
            ffi_type **struct_types = (ffi_type **)(uintptr_t)obj->Get(args.GetIsolate()->GetCurrentContext(), v8::String::NewFromUtf8(args.GetIsolate(), "types", v8::NewStringType::kNormal).ToLocalChecked()).ToLocalChecked()->NumberValue(args.GetIsolate()->GetCurrentContext()).FromJust();
            void *struct_binary = (void *)(uintptr_t)obj->Get(args.GetIsolate()->GetCurrentContext(), v8::String::NewFromUtf8(args.GetIsolate(), "binary", v8::NewStringType::kNormal).ToLocalChecked()).ToLocalChecked()->NumberValue(args.GetIsolate()->GetCurrentContext()).FromJust();
            ffi_type st_type;
            st_type.size = 0;
            st_type.alignment = 0;
            st_type.type = FFI_TYPE_STRUCT;
            st_type.elements = struct_types;
            ffi_args_values[count] = add_args_hash_to_struct(name.c_str(), struct_binary); //TODO ここでデータが破損する
            ffi_args_type[count] = &st_type;
        } else {
            fprintf(stderr, "Unknown type: %s\n", arg_type.c_str());
            exit(1);
        }
    }
    if (ret_type == "void") {
        ffi_call_ext(find_func_hash(func_name.c_str()), args_len, &ffi_type_void, ffi_args_type, nullptr, ffi_args_values);
        v8_rets_to_null(args);
    } else if (ret_type == "uint8") {
        ffi_call_ext(find_func_hash(func_name.c_str()), args_len, &ffi_type_uint8, ffi_args_type, &ffi_rets.data.value_uint8, ffi_args_values);
        v8_rets_to_uint8(args, ffi_rets.data.value_uint8);
    } else if (ret_type == "sint8") {
        ffi_call_ext(find_func_hash(func_name.c_str()), args_len, &ffi_type_sint8, ffi_args_type, &ffi_rets.data.value_sint8, ffi_args_values);
        v8_rets_to_sint8(args, ffi_rets.data.value_sint8);
    } else if (ret_type == "uint16") {
        ffi_call_ext(find_func_hash(func_name.c_str()), args_len, &ffi_type_uint16, ffi_args_type, &ffi_rets.data.value_uint16, ffi_args_values);
        v8_rets_to_uint16(args, ffi_rets.data.value_uint16);
    } else if (ret_type == "sint16") {
        ffi_call_ext(find_func_hash(func_name.c_str()), args_len, &ffi_type_sint16, ffi_args_type, &ffi_rets.data.value_sint16, ffi_args_values);
        v8_rets_to_sint16(args, ffi_rets.data.value_sint16);
    } else if (ret_type == "uint32") {
        ffi_call_ext(find_func_hash(func_name.c_str()), args_len, &ffi_type_uint32, ffi_args_type, &ffi_rets.data.value_uint32, ffi_args_values);
        v8_rets_to_uint32(args, ffi_rets.data.value_uint32);
    } else if (ret_type == "sint32") {
        ffi_call_ext(find_func_hash(func_name.c_str()), args_len, &ffi_type_sint32, ffi_args_type, &ffi_rets.data.value_sint32, ffi_args_values);
        v8_rets_to_sint32(args, ffi_rets.data.value_sint32);
    } else if (ret_type == "uint64") {
        ffi_call_ext(find_func_hash(func_name.c_str()), args_len, &ffi_type_uint64, ffi_args_type, &ffi_rets.data.value_uint64, ffi_args_values);
        v8_rets_to_uint64(args, ffi_rets.data.value_uint64);
    } else if (ret_type == "sint64") {
        ffi_call_ext(find_func_hash(func_name.c_str()), args_len, &ffi_type_sint64, ffi_args_type, &ffi_rets.data.value_sint64, ffi_args_values);
        v8_rets_to_sint64(args, ffi_rets.data.value_sint64);
    } else if (ret_type == "float") {
        ffi_call_ext(find_func_hash(func_name.c_str()), args_len, &ffi_type_float, ffi_args_type, &ffi_rets.data.value_float, ffi_args_values);
        v8_rets_to_float(args, ffi_rets.data.value_float);
    } else if (ret_type == "double") {
        ffi_call_ext(find_func_hash(func_name.c_str()), args_len, &ffi_type_double, ffi_args_type, &ffi_rets.data.value_double, ffi_args_values);
        v8_rets_to_double(args, ffi_rets.data.value_double);
    } else if (ret_type == "uchar") {
        ffi_call_ext(find_func_hash(func_name.c_str()), args_len, &ffi_type_uchar, ffi_args_type, &ffi_rets.data.value_uchar, ffi_args_values);
        v8_rets_to_uchar(args, ffi_rets.data.value_uchar);
    } else if (ret_type == "schar") {
        ffi_call_ext(find_func_hash(func_name.c_str()), args_len, &ffi_type_schar, ffi_args_type, &ffi_rets.data.value_schar, ffi_args_values);
        v8_rets_to_schar(args, ffi_rets.data.value_schar);
    } else if (ret_type == "ushort") {
        ffi_call_ext(find_func_hash(func_name.c_str()), args_len, &ffi_type_ushort, ffi_args_type, &ffi_rets.data.value_ushort, ffi_args_values);
        v8_rets_to_ushort(args, ffi_rets.data.value_ushort);
    } else if (ret_type == "sshort") {
        ffi_call_ext(find_func_hash(func_name.c_str()), args_len, &ffi_type_sshort, ffi_args_type, &ffi_rets.data.value_sshort, ffi_args_values);
        v8_rets_to_sshort(args, ffi_rets.data.value_sshort);
    } else if (ret_type == "uint") {
        ffi_call_ext(find_func_hash(func_name.c_str()), args_len, &ffi_type_uint, ffi_args_type, &ffi_rets.data.value_uint, ffi_args_values);
        v8_rets_to_uint(args, ffi_rets.data.value_uint);
    } else if (ret_type == "sint") {
        ffi_call_ext(find_func_hash(func_name.c_str()), args_len, &ffi_type_sint, ffi_args_type, &ffi_rets.data.value_sint, ffi_args_values);
        v8_rets_to_sint(args, ffi_rets.data.value_sint);
    } else if (ret_type == "ulong") {
        ffi_call_ext(find_func_hash(func_name.c_str()), args_len, &ffi_type_ulong, ffi_args_type, &ffi_rets.data.value_ulong, ffi_args_values);
        v8_rets_to_ulong(args, ffi_rets.data.value_ulong);
    } else if (ret_type == "slong") {
        ffi_call_ext(find_func_hash(func_name.c_str()), args_len, &ffi_type_slong, ffi_args_type, &ffi_rets.data.value_slong, ffi_args_values);
        v8_rets_to_slong(args, ffi_rets.data.value_slong);
    } else if (ret_type == "longdouble") {
        ffi_call_ext(find_func_hash(func_name.c_str()), args_len, &ffi_type_longdouble, ffi_args_type, &ffi_rets.data.value_longdouble, ffi_args_values);
        v8_rets_to_longdouble(args, ffi_rets.data.value_longdouble);
    } else if (ret_type == "string") {
        ffi_call_ext(find_func_hash(func_name.c_str()), args_len, &ffi_type_pointer, ffi_args_type, &ffi_rets.data.value_string, ffi_args_values);
        v8_rets_to_str(args, ffi_rets.data.value_string);
    } else if (ret_type == "pointer") {
        ffi_call_ext(find_func_hash(func_name.c_str()), args_len, &ffi_type_pointer, ffi_args_type, &ffi_rets.data.value_pointer, ffi_args_values);
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
    int args_offset = 0; // 引数の始まる位置（0から引数）
    int args_group = 2; // 1つの引数の含まれる情報の数(1: 型, 2: 値)
    int args_len = (args.Length() - args_offset) / args_group;
    // バイナリの合計サイズを計算する
    int binary_size = 0;
    for(int i = args_offset, count = 0; i < args.Length(); i += args_group, count++) {
        auto arg_type = v8_args_to_str(args, i);
        if (arg_type == "uint8") {
            binary_size += 1;
        } else if (arg_type == "sint8") {
            binary_size += 1;
        } else if (arg_type == "uint16") {
            binary_size += 2;
        } else if (arg_type == "sint16") {
            binary_size += 2;
        } else if (arg_type == "uint32") {
            binary_size += 4;
        } else if (arg_type == "sint32") {
            binary_size += 4;
        } else if (arg_type == "uint64") {
            binary_size += 8;
        } else if (arg_type == "sint64") {
            binary_size += 8;
        } else if (arg_type == "float") {
            binary_size += 4;
        } else if (arg_type == "double") {
            binary_size += 8;
        } else if (arg_type == "uchar") {
            binary_size += 1;
        } else if (arg_type == "schar") {
            binary_size += 1;
        } else if (arg_type == "ushort") {
            binary_size += 2;
        } else if (arg_type == "sshort") {
            binary_size += 2;
        } else if (arg_type == "uint") {
            binary_size += 4;
        } else if (arg_type == "sint") {
            binary_size += 4;
        } else if (arg_type == "ulong") {
            binary_size += 4;
        } else if (arg_type == "slong") {
            binary_size += 4;
        } else if (arg_type == "longdouble") {
            binary_size += 16;
        } else if (arg_type == "string") {
            auto str = v8_args_to_str(args, i + 1);
            binary_size += (int)str.length() + 1;
        } else if (arg_type == "pointer") {
            binary_size += sizeof(void*);
        } else {
            fprintf(stderr, "Unknown type: %s\n", arg_type.c_str());
            exit(1);
        }
    }
    // バイナリデータを初期化する
    uint8_t *binary = (uint8_t *)malloc(binary_size);
    int binary_offset = 0;
    for(int i = args_offset, count = 0; i < args.Length(); i += args_group, count++) {
        auto arg_type = v8_args_to_str(args, i);
        if (arg_type == "uint8") {
            uint8_t value = v8_args_to_uint8(args, i + 1);
            memcpy(binary + binary_offset, &value, 1);
            binary_offset += 1;
        } else if (arg_type == "sint8") {
            int8_t value = v8_args_to_sint8(args, i + 1);
            memcpy(binary + binary_offset, &value, 1);
            binary_offset += 1;
        } else if (arg_type == "uint16") {
            uint16_t value = v8_args_to_uint16(args, i + 1);
            memcpy(binary + binary_offset, &value, 2);
            binary_offset += 2;
        } else if (arg_type == "sint16") {
            int16_t value = v8_args_to_sint16(args, i + 1);
            memcpy(binary + binary_offset, &value, 2);
            binary_offset += 2;
        } else if (arg_type == "uint32") {
            uint32_t value = v8_args_to_uint32(args, i + 1);
            memcpy(binary + binary_offset, &value, 4);
            binary_offset += 4;
        } else if (arg_type == "sint32") {
            int32_t value = v8_args_to_sint32(args, i + 1);
            memcpy(binary + binary_offset, &value, 4);
            binary_offset += 4;
        } else if (arg_type == "uint64") {
            uint64_t value = v8_args_to_uint64(args, i + 1);
            memcpy(binary + binary_offset, &value, 8);
            binary_offset += 8;
        } else if (arg_type == "sint64") {
            int64_t value = v8_args_to_sint64(args, i + 1);
            memcpy(binary + binary_offset, &value, 8);
            binary_offset += 8;
        } else if (arg_type == "float") {
            float value = v8_args_to_float(args, i + 1);
            memcpy(binary + binary_offset, &value, 4);
            binary_offset += 4;
        } else if (arg_type == "double") {
            double value = v8_args_to_double(args, i + 1);
            memcpy(binary + binary_offset, &value, 8);
            binary_offset += 8;
        } else if (arg_type == "uchar") {
            unsigned char value = v8_args_to_uchar(args, i + 1);
            memcpy(binary + binary_offset, &value, 1);
            binary_offset += 1;
        } else if (arg_type == "schar") {
            char value = v8_args_to_schar(args, i + 1);
            memcpy(binary + binary_offset, &value, 1);
            binary_offset += 1;
        } else if (arg_type == "ushort") {
            unsigned short value = v8_args_to_ushort(args, i + 1);
            memcpy(binary + binary_offset, &value, 2);
            binary_offset += 2;
        } else if (arg_type == "sshort") {
            short value = v8_args_to_sshort(args, i + 1);
            memcpy(binary + binary_offset, &value, 2);
            binary_offset += 2;
        } else if (arg_type == "uint") {
            unsigned int value = v8_args_to_uint(args, i + 1);
            memcpy(binary + binary_offset, &value, 4);
            binary_offset += 4;
        } else if (arg_type == "sint") {
            int value = v8_args_to_sint(args, i + 1);
            memcpy(binary + binary_offset, &value, 4);
            binary_offset += 4;
        } else if (arg_type == "ulong") {
            unsigned long value = v8_args_to_ulong(args, i + 1);
            memcpy(binary + binary_offset, &value, 4);
            binary_offset += 4;
        } else if (arg_type == "slong") {
            long value = v8_args_to_slong(args, i + 1);
            memcpy(binary + binary_offset, &value, 4);
            binary_offset += 4;
        } else if (arg_type == "longdouble") {
            long double value = v8_args_to_longdouble(args, i + 1);
            memcpy(binary + binary_offset, &value, 16);
            binary_offset += 16;
        } else if (arg_type == "string") {
            auto src = v8_args_to_str(args, i + 1);
            char* dst = new char[src.length() + 1];
            std::strcpy(dst, src.c_str());
            memcpy(binary + binary_offset, dst, (int)src.length() + 1);
            free(dst);
            binary_offset += (int)src.length() + 1;
        } else if (arg_type == "pointer") {
            void *value = v8_args_to_ptr(args, i + 1);
            memcpy(binary + binary_offset, &value, sizeof(void*));
            binary_offset += sizeof(void*);
        } else {
            fprintf(stderr, "Unknown type: %s\n", arg_type.c_str());
            exit(1);
        }
    }

    // タイプ情報を得る
    ffi_type **type_elements = (ffi_type **)malloc((args_len + 1) * sizeof(ffi_type *));
    int count = 0;
    for(int i = args_offset; i < args.Length(); i += args_group, count++) {
        auto arg_type = v8_args_to_str(args, i);
        if (arg_type == "uint8") {
            type_elements[count] = &ffi_type_uint8;
        } else if (arg_type == "sint8") {
            type_elements[count] = &ffi_type_sint8;
        } else if (arg_type == "uint16") {
            type_elements[count] = &ffi_type_uint16;
        } else if (arg_type == "sint16") {
            type_elements[count] = &ffi_type_sint16;
        } else if (arg_type == "uint32") {
            type_elements[count] = &ffi_type_uint32;
        } else if (arg_type == "sint32") {
            type_elements[count] = &ffi_type_sint32;
        } else if (arg_type == "uint64") {
            type_elements[count] = &ffi_type_uint64;
        } else if (arg_type == "sint64") {
            type_elements[count] = &ffi_type_sint64;
        } else if (arg_type == "float") {
            type_elements[count] = &ffi_type_float;
        } else if (arg_type == "double") {
            type_elements[count] = &ffi_type_double;
        } else if (arg_type == "uchar") {
            type_elements[count] = &ffi_type_uchar;
        } else if (arg_type == "schar") {
            type_elements[count] = &ffi_type_schar;
        } else if (arg_type == "ushort") {
            type_elements[count] = &ffi_type_ushort;
        } else if (arg_type == "sshort") {
            type_elements[count] = &ffi_type_ushort;
        } else if (arg_type == "uint") {
            type_elements[count] = &ffi_type_uint;
        } else if (arg_type == "sint") {
            type_elements[count] = &ffi_type_sint;
        } else if (arg_type == "ulong") {
            type_elements[count] = &ffi_type_ulong;
        } else if (arg_type == "slong") {
            type_elements[count] = &ffi_type_slong;
        } else if (arg_type == "longdouble") {
            type_elements[count] = &ffi_type_longdouble;
        } else if (arg_type == "string") {
            type_elements[count] = &ffi_type_pointer;
        } else if (arg_type == "pointer") {
            type_elements[count] = &ffi_type_pointer;
        } else {
            fprintf(stderr, "Unknown type: %s\n", arg_type.c_str());
            exit(1);
        }
    }
    type_elements[count] = nullptr;
    v8::Local<v8::Object> obj = v8::Object::New(args.GetIsolate());
    obj->Set(args.GetIsolate()->GetCurrentContext(), v8::String::NewFromUtf8(args.GetIsolate(), "binary", v8::NewStringType::kNormal).ToLocalChecked(), v8::Number::New(args.GetIsolate(), (double)(uintptr_t)binary)).FromJust();
    obj->Set(args.GetIsolate()->GetCurrentContext(), v8::String::NewFromUtf8(args.GetIsolate(), "types", v8::NewStringType::kNormal).ToLocalChecked(), v8::Number::New(args.GetIsolate(), (double)(uintptr_t)type_elements)).FromJust();
    args.GetReturnValue().Set(obj);
}

void raia_core_delete_struct(const v8_args_t &args) {
    v8::Local<v8::Object> obj = args[0]->ToObject(args.GetIsolate()->GetCurrentContext()).ToLocalChecked();
    ffi_type **struct_types = (ffi_type **)(uintptr_t)obj->Get(args.GetIsolate()->GetCurrentContext(), v8::String::NewFromUtf8(args.GetIsolate(), "types", v8::NewStringType::kNormal).ToLocalChecked()).ToLocalChecked()->NumberValue(args.GetIsolate()->GetCurrentContext()).FromJust();
    void *struct_binary = (void *)(uintptr_t)obj->Get(args.GetIsolate()->GetCurrentContext(), v8::String::NewFromUtf8(args.GetIsolate(), "binary", v8::NewStringType::kNormal).ToLocalChecked()).ToLocalChecked()->NumberValue(args.GetIsolate()->GetCurrentContext()).FromJust();
    free((void *)struct_types);
    free((void *)struct_binary);
    v8_rets_to_null(args);
}

void raia_core_delete_pointer(const v8_args_t &args) {
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

void raia_gc_free(const v8_args_t &args) {
    args.GetIsolate()->LowMemoryNotification(); // メモリ不足時にガベージコレクションを強制的に実行する
    v8_rets_to_null(args);
}

int raia_v8_main(int argc, char *argv[]) {
    v8_init();
    v8_isolate_init(isolate, isolate_params);
    v8_isolate_set_callback(isolate, import_dynamic_callback, import_meta);
    v8_context_init(isolate, context);
    v8_set_obj(isolate, Raia, context->Global(), "__Raia__");
    v8_set_obj(isolate, Core, Raia, "Core");
    v8_set_func(isolate, Core, "print", raia_core_print);
    v8_set_func(isolate, Core, "exit", raia_core_exit);
    v8_set_func(isolate, Core, "pointerToArrayBuffer", raia_core_ptr_to_buf); // ptrToBuf
    v8_set_func(isolate, Core, "arrayBufferToPointer", raia_core_buf_to_ptr); // bufToPtr
    v8_set_func(isolate, Core, "makeStruct", raia_core_make_struct);
    v8_set_func(isolate, Core, "deleteStruct", raia_core_delete_struct);   // delStruct
    v8_set_func(isolate, Core, "deletePointer", raia_core_delete_pointer); // delPtr
    v8_set_obj(isolate, Lib, Raia, "Lib");
    v8_set_func(isolate, Lib, "open", raia_lib_open);
    v8_set_func(isolate, Lib, "close", raia_lib_close);
    v8_set_func(isolate, Lib, "closeAll", raia_lib_close_all);
    v8_set_func(isolate, Lib, "add", raia_lib_add);
    v8_set_func(isolate, Lib, "call", raia_lib_call);
    v8_set_func(isolate, Lib, "callWithJSON", raia_lib_call);
    v8_set_func(isolate, Lib, "ffi", raia_lib_ffi);
    v8_set_obj(isolate, GC, Raia, "GC");
    v8_set_func(isolate, GC, "free", raia_gc_free);
    v8_start();
    v8_destroy(isolate_params);
    return 0;
}

extern "C" RAIA_API char *init(int argc, char *argv[]) {
    init_plugin_hash();
    init_func_hash();
    init_startup_script();
    raia_v8_main(argc, argv);
    return nullptr;
}

//int main(int argc, char *argv[]) {
//    init(argc, argv);
//    return 0;
//}