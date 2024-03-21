#include "raia_luajit.h"
#include "../../../common/c/static/shared_library_loader.h"
#include "../../../common/c/static/static_args_hash.h"

int raia_lib_open(lua_State* L) {
    const char *dll_file = luaL_checkstring(L, 1);
    char library_name[500];
    SPRINTF(library_name, "%s.%s", dll_file, DYNAMIC_LIB_EXT);
    int handle = open_shared_library(library_name);
    lua_pushinteger(L, handle);
    return 1;
}

int raia_lib_close(lua_State* L) {
    int library_key = (int)luaL_checkinteger(L, 1);
    close_shared_library(library_key);
    return 0;
}

int raia_lib_close_all(lua_State* L) {
    close_all_shared_library();
    return 0;
}

int raia_lib_add(lua_State* L) {
    int library_key = (int)luaL_checkinteger(L, 1);
    const char *func_name = luaL_checkstring(L, 2);
    add_func_shared_library(library_key, func_name);
    return 0;
}

int raia_lib_call(lua_State *L) {
    int library_key = (int)luaL_checkinteger(L, 1);
    const char *func_name = luaL_checkstring(L, 2);
    const char *json = luaL_checkstring(L, 3);
    const char *rets = call_func_shared_library(library_key, func_name, json);
    if (rets) {
        lua_pushstring(L, rets);
        free((void *)rets);
    } else {
        lua_pushnil(L);
    }
    return 1;
}

int raia_lib_ffi(lua_State *L) {
    int library_key = (int)luaL_checkinteger(L, 1);
    const char * func_name = luaL_checkstring(L, 2);
    const char * ret_type = luaL_checkstring(L, 3);
    //
    ffi_type *ffi_args_type[512];
    void *ffi_args_values[512];
    args_key_t ffi_rets;
    // 引数の設定

    int args_len = (int)lua_objlen(L, 4);
    if (lua_gettop(L) >= 4 && lua_istable(L, 4)) {
        int i = 0;
        lua_pushnil(L);  // 最初のキー
        while (lua_next(L, 4) != 0) {
            // 'key'（-2）と 'value'（-1）
            if (lua_istable(L, -1)) {
                // テーブル内の値を読み取る
                lua_pushinteger(L, 1);
                lua_gettable(L, -2); // type
                const char *arg_type = lua_tostring(L, -1);
                lua_pop(L, 1);

                lua_pushinteger(L, 2);
                lua_gettable(L, -2); // name
                const char *arg_name = lua_tostring(L, -1);
                lua_pop(L, 1);

                lua_pushinteger(L, 3);
                lua_gettable(L, -2); // value

                // ここでtype, name, valueを使う
                if (strcmp(arg_type, "uint8") == 0) {
                    uint8_t value = (uint8_t)luaL_checkinteger(L, -1);
                    ffi_args_values[i] = add_args_hash_to_uint8(arg_name, value);
                    ffi_args_type[i] = &ffi_type_uint8;
                } else if (strcmp(arg_type, "sint8") == 0) {
                    int8_t value = (int8_t)luaL_checkinteger(L, -1);
                    ffi_args_values[i] = add_args_hash_to_sint8(arg_name, value);
                    ffi_args_type[i] = &ffi_type_sint8;
                } else if (strcmp(arg_type, "uint16") == 0) {
                    uint16_t value = (uint16_t)luaL_checkinteger(L, -1);
                    ffi_args_values[i] = add_args_hash_to_uint16(arg_name, value);
                    ffi_args_type[i] = &ffi_type_uint16;
                } else if (strcmp(arg_type, "sint16") == 0) {
                    int16_t value = (int16_t)luaL_checkinteger(L, -1);
                    ffi_args_values[i] = add_args_hash_to_sint16(arg_name, value);
                    ffi_args_type[i] = &ffi_type_sint16;
                } else if (strcmp(arg_type, "uint32") == 0) {
                    uint32_t value = (uint32_t)luaL_checkinteger(L, -1);
                    ffi_args_values[i] = add_args_hash_to_uint32(arg_name, value);
                    ffi_args_type[i] = &ffi_type_uint32;
                } else if (strcmp(arg_type, "sint32") == 0) {
                    int32_t value = (int32_t)luaL_checkinteger(L, -1);
                    ffi_args_values[i] = add_args_hash_to_sint32(arg_name, value);
                    ffi_args_type[i] = &ffi_type_sint32;
                } else if (strcmp(arg_type, "uint64") == 0) {
                    uint64_t value = (uint64_t)luaL_checkinteger(L, -1);
                    ffi_args_values[i] = add_args_hash_to_uint64(arg_name, value);
                    ffi_args_type[i] = &ffi_type_uint64;
                } else if (strcmp(arg_type, "sint64") == 0) {
                    int64_t value = (int64_t)luaL_checkinteger(L, -1);
                    ffi_args_values[i] = add_args_hash_to_sint64(arg_name, value);
                    ffi_args_type[i] = &ffi_type_sint64;
                } else if (strcmp(arg_type, "float") == 0) {
                    float value = (float)luaL_checknumber(L, -1);
                    ffi_args_values[i] = add_args_hash_to_float(arg_name, value);
                    ffi_args_type[i] = &ffi_type_float;
                } else if (strcmp(arg_type, "double") == 0) {
                    double value = (double)luaL_checknumber(L, -1);
                    ffi_args_values[i] = add_args_hash_to_double(arg_name, value);
                    ffi_args_type[i] = &ffi_type_double;
                } else if (strcmp(arg_type, "uchar") == 0) {
                    unsigned char value = (unsigned char) luaL_checkinteger(L, -1);
                    ffi_args_values[i] = add_args_hash_to_uchar(arg_name, value);
                    ffi_args_type[i] = &ffi_type_uchar;
                } else if (strcmp(arg_type, "schar") == 0) {
                    char value = (char) luaL_checkinteger(L, -1);
                    ffi_args_values[i] = add_args_hash_to_schar(arg_name, value);
                    ffi_args_type[i] = &ffi_type_schar;
                } else if (strcmp(arg_type, "ushort") == 0) {
                    unsigned short value = (unsigned short) luaL_checkinteger(L, -1);
                    ffi_args_values[i] = add_args_hash_to_ushort(arg_name, value);
                    ffi_args_type[i] = &ffi_type_ushort;
                } else if (strcmp(arg_type, "sshort") == 0) {
                    short value = (short) luaL_checkinteger(L, -1);
                    ffi_args_values[i] = add_args_hash_to_sshort(arg_name, value);
                    ffi_args_type[i] = &ffi_type_sshort;
                } else if (strcmp(arg_type, "uint") == 0) {
                    unsigned int value = (unsigned int) luaL_checkinteger(L, -1);
                    ffi_args_values[i] = add_args_hash_to_uint(arg_name, value);
                    ffi_args_type[i] = &ffi_type_uint;
                } else if (strcmp(arg_type, "sint") == 0) {
                    int value = (int) luaL_checkinteger(L, -1);
                    ffi_args_values[i] = add_args_hash_to_sint(arg_name, value);
                    ffi_args_type[i] = &ffi_type_sint;
                } else if (strcmp(arg_type, "ulong") == 0) {
                    unsigned long value = (unsigned long) luaL_checkinteger(L, -1);
                    ffi_args_values[i] = add_args_hash_to_ulong(arg_name, value);
                    ffi_args_type[i] = &ffi_type_ulong;
                } else if (strcmp(arg_type, "slong") == 0) {
                    long value = (long) luaL_checkinteger(L, -1);
                    ffi_args_values[i] = add_args_hash_to_slong(arg_name, value);
                    ffi_args_type[i] = &ffi_type_slong;
                }
//                else if (strcmp(arg_type, "longdouble") == 0) {
//                    long double value = (long double) luaL_checknumber(L, -1);
//                    ffi_args_values[i] = add_args_hash_to_longdouble(arg_name, value);
//                    ffi_args_type[i] = &ffi_type_longdouble;
//                }
                else if (strcmp(arg_type, "string") == 0) {
                    const char *value = luaL_checkstring(L, -1);
                    ffi_args_values[i] = add_args_hash_to_string(arg_name, value);
                    ffi_args_type[i] = &ffi_type_pointer;
                } else if (strcmp(arg_type, "pointer") == 0) {
                    void *value = (void *) (uintptr_t) luaL_checknumber(L, -1);
                    ffi_args_values[i] = add_args_hash_to_pointer(arg_name, value);
                    ffi_args_type[i] = &ffi_type_pointer;
                } else if (strcmp(arg_type, "struct") == 0) {
                    double types = 0.0;
                    double binary = 0.0;
                    if (lua_istable(L, -1)) {
                        lua_pushnil(L);
                        while (lua_next(L, -2) != 0) {
                            if (lua_istable(L, -1)) {
                                lua_getfield(L, -1, "types");
                                if (lua_isstring(L, -1)) {
                                    types = lua_tonumber(L, -1);
                                }
                                lua_pop(L, 1); // スタックから値を削除
                                lua_getfield(L, -1, "binary");
                                if (lua_isstring(L, -1)) {
                                    binary = lua_tonumber(L, -1);
                                }
                                lua_pop(L, 1); // スタックから値を削除
                            }
                            lua_pop(L, 1);  // 内部テーブルの値をスタックから削除
                        }
                    }
                    ffi_type **struct_types = (ffi_type **)(uintptr_t)types;
                    printf("%x\n",struct_types[0] == &ffi_type_sint);
                    printf("%x\n",struct_types[1] == &ffi_type_sint);
                    printf("%x\n",struct_types[2] == &ffi_type_sint);
                    void *struct_binary = (void *)(uintptr_t)binary;
                    int * a = (int *)(uintptr_t)binary;
                    printf("a:%d\n", *a);
                    a++;
                    printf("a:%d\n", *a);
                    ffi_type st_type = {
                            .size = 0,
                            .alignment = 0,
                            .type = FFI_TYPE_STRUCT,
                            .elements = struct_types
                    };
                    ffi_args_values[i] = add_args_hash_to_struct(arg_name, struct_binary);
                    ffi_args_type[i] = &st_type;

                } else {
                    fprintf(stderr, "Unknown type: %s\n", arg_type);
                    exit(1);
                }
                lua_pop(L, 1);
            }
            // スタックからvalueを取り除くがkeyは次のイテレーションのために残す
            lua_pop(L, 1);
            i++;
        }
    }

    // 戻り値の設定
    if (strcmp(ret_type, "void") == 0) {
        ffi_call_ext(find_func_shared_library(library_key, func_name), args_len, &ffi_type_void, ffi_args_type, NULL, ffi_args_values);
        return 0;
    } else if (strcmp(ret_type, "uint8") == 0) {
        ffi_call_ext(find_func_shared_library(library_key, func_name), args_len, &ffi_type_uint8, ffi_args_type, &ffi_rets.data.value_uint8, ffi_args_values);
        lua_pushinteger(L, ffi_rets.data.value_uint8);
    } else if (strcmp(ret_type, "sint8") == 0) {
        ffi_call_ext(find_func_shared_library(library_key, func_name), args_len, &ffi_type_sint8, ffi_args_type, &ffi_rets.data.value_sint8, ffi_args_values);
        lua_pushinteger(L, ffi_rets.data.value_sint8);
    } else if (strcmp(ret_type, "uint16") == 0) {
        ffi_call_ext(find_func_shared_library(library_key, func_name), args_len, &ffi_type_uint16, ffi_args_type, &ffi_rets.data.value_uint16, ffi_args_values);
        lua_pushinteger(L, ffi_rets.data.value_uint16);
    } else if (strcmp(ret_type, "sint16") == 0) {
        ffi_call_ext(find_func_shared_library(library_key, func_name), args_len, &ffi_type_sint16, ffi_args_type, &ffi_rets.data.value_sint16, ffi_args_values);
        lua_pushinteger(L, ffi_rets.data.value_sint16);
    } else if (strcmp(ret_type, "uint32") == 0) {
        ffi_call_ext(find_func_shared_library(library_key, func_name), args_len, &ffi_type_uint32, ffi_args_type, &ffi_rets.data.value_uint32, ffi_args_values);
        lua_pushinteger(L, ffi_rets.data.value_uint32);
    } else if (strcmp(ret_type, "sint32") == 0) {
        ffi_call_ext(find_func_shared_library(library_key, func_name), args_len, &ffi_type_sint32, ffi_args_type, &ffi_rets.data.value_sint32, ffi_args_values);
        lua_pushinteger(L, ffi_rets.data.value_sint32);
    } else if (strcmp(ret_type, "uint64") == 0) {
        ffi_call_ext(find_func_shared_library(library_key, func_name), args_len, &ffi_type_uint64, ffi_args_type, &ffi_rets.data.value_uint64, ffi_args_values);
        lua_pushinteger(L, (int64_t)ffi_rets.data.value_uint64);
    } else if (strcmp(ret_type, "sint64") == 0) {
        ffi_call_ext(find_func_shared_library(library_key, func_name), args_len, &ffi_type_sint64, ffi_args_type, &ffi_rets.data.value_sint64, ffi_args_values);
        lua_pushinteger(L, ffi_rets.data.value_sint64);
    } else if (strcmp(ret_type, "float") == 0) {
        ffi_call_ext(find_func_shared_library(library_key, func_name), args_len, &ffi_type_float, ffi_args_type, &ffi_rets.data.value_float, ffi_args_values);
        lua_pushnumber(L, ffi_rets.data.value_float);
    } else if (strcmp(ret_type, "double") == 0) {
        ffi_call_ext(find_func_shared_library(library_key, func_name), args_len, &ffi_type_double, ffi_args_type, &ffi_rets.data.value_double, ffi_args_values);
        lua_pushnumber(L, ffi_rets.data.value_double);
    } else if (strcmp(ret_type, "uchar") == 0) {
        ffi_call_ext(find_func_shared_library(library_key, func_name), args_len, &ffi_type_uchar, ffi_args_type, &ffi_rets.data.value_uchar, ffi_args_values);
        lua_pushinteger(L, ffi_rets.data.value_uchar);
    } else if (strcmp(ret_type, "schar") == 0) {
        ffi_call_ext(find_func_shared_library(library_key, func_name), args_len, &ffi_type_schar, ffi_args_type, &ffi_rets.data.value_schar, ffi_args_values);
        lua_pushinteger(L, ffi_rets.data.value_schar);
    } else if (strcmp(ret_type, "ushort") == 0) {
        ffi_call_ext(find_func_shared_library(library_key, func_name), args_len, &ffi_type_ushort, ffi_args_type, &ffi_rets.data.value_ushort, ffi_args_values);
        lua_pushinteger(L, ffi_rets.data.value_ushort);
    } else if (strcmp(ret_type, "sshort") == 0) {
        ffi_call_ext(find_func_shared_library(library_key, func_name), args_len, &ffi_type_sshort, ffi_args_type, &ffi_rets.data.value_sshort, ffi_args_values);
        lua_pushinteger(L, ffi_rets.data.value_sshort);
    } else if (strcmp(ret_type, "uint") == 0) {
        ffi_call_ext(find_func_shared_library(library_key, func_name), args_len, &ffi_type_uint, ffi_args_type, &ffi_rets.data.value_uint, ffi_args_values);
        lua_pushinteger(L, ffi_rets.data.value_uint);
    } else if (strcmp(ret_type, "sint") == 0) {
        ffi_call_ext(find_func_shared_library(library_key, func_name), args_len, &ffi_type_sint, ffi_args_type, &ffi_rets.data.value_sint, ffi_args_values);
        lua_pushinteger(L, ffi_rets.data.value_sint);
    } else if (strcmp(ret_type, "ulong") == 0) {
        ffi_call_ext(find_func_shared_library(library_key, func_name), args_len, &ffi_type_ulong, ffi_args_type, &ffi_rets.data.value_ulong, ffi_args_values);
        lua_pushinteger(L, (int64_t)ffi_rets.data.value_ulong);
    } else if (strcmp(ret_type, "slong") == 0) {
        ffi_call_ext(find_func_shared_library(library_key, func_name), args_len, &ffi_type_slong, ffi_args_type, &ffi_rets.data.value_slong, ffi_args_values);
        lua_pushinteger(L, ffi_rets.data.value_slong);
    }
//    else if (strcmp(ret_type, "longdouble") == 0) {
//        ffi_call_ext(find_func_shared_library(library_key, func_name), args_len, &ffi_type_longdouble, ffi_args_type, &ffi_rets.data.value_longdouble, ffi_args_values);
//        lua_pushnumber(L, (double)ffi_rets.data.value_longdouble);
//    }
    else if (strcmp(ret_type, "string") == 0) {
        ffi_call_ext(find_func_shared_library(library_key, func_name), args_len, &ffi_type_pointer, ffi_args_type, &ffi_rets.data.value_string, ffi_args_values);
        lua_pushstring(L, ffi_rets.data.value_string);
    } else if (strcmp(ret_type, "pointer") == 0) {
        ffi_call_ext(find_func_shared_library(library_key, func_name), args_len, &ffi_type_pointer, ffi_args_type, &ffi_rets.data.value_pointer, ffi_args_values);
        lua_pushnumber(L, (double)(uintptr_t)ffi_rets.data.value_pointer);
    } else {
        fprintf(stderr, "Unknown type: %s\n", ret_type);
        exit(1);
    }
    return 1;
}

int raia_lib_make_struct(lua_State *L) {
    // バイナリの合計サイズを計算する
    int binary_size = 0;
    int args_len = (int)lua_objlen(L, 1);
    if (lua_gettop(L) >= 1 && lua_istable(L, 1)) {
        int i = 0;
        lua_pushnil(L);  // 最初のキー
        while (lua_next(L, 1) != 0) {
            // 'key'（-2）と 'value'（-1）
            if (lua_istable(L, -1)) {
                // テーブル内の値を読み取る
                lua_pushinteger(L, 1);
                lua_gettable(L, -2); // type
                const char *arg_type = lua_tostring(L, -1);
                lua_pop(L, 1);

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
                    lua_pushinteger(L, 2);
                    lua_gettable(L, -2); // value
                    size_t *len = (size_t *)malloc(sizeof(size_t) * 10);
                    luaL_checklstring(L, -1, len);
                    binary_size += (int)*len + 1;
                    free(len);
                    lua_pop(L, 1);
                } else if (strcmp(arg_type, "pointer") == 0) {
                    binary_size += sizeof(void*);
                } else {
                    fprintf(stderr, "Unknown type: %s\n", arg_type);
                    exit(1);
                }
            }
            // スタックからvalueを取り除くがkeyは次のイテレーションのために残す
            lua_pop(L, 1);
            i++;
        }
    }


    // タイプ情報とバイナリデータを初期化・取得する
    ffi_type **type_elements = (ffi_type **)malloc((args_len + 1) * sizeof(ffi_type *));
    for (int i = 0; i < args_len + 1; i++) {
        type_elements[i] = NULL;
    }
    uint8_t *binary = (uint8_t *)malloc(binary_size);


    int binary_offset = 0;

    if (lua_gettop(L) >= 1 && lua_istable(L, 1)) {
        int i = 0;
        lua_pushnil(L);  // 最初のキー
        while (lua_next(L, 1) != 0) {
            // 'key'（-2）と 'value'（-1）
            if (lua_istable(L, -1)) {
                // テーブル内の値を読み取る
                lua_pushinteger(L, 1);
                lua_gettable(L, -2); // type
                const char *arg_type = lua_tostring(L, -1);
                lua_pop(L, 1);


                lua_pushinteger(L, 2);
                lua_gettable(L, -2); // value
                if (strcmp(arg_type, "uint8") == 0) {
                    uint8_t value = (uint8_t)luaL_checkinteger(L, -1);
                    type_elements[i] = &ffi_type_uint8;
                    memcpy(binary + binary_offset, &value, 1);
                    binary_offset += 1;
                } else if (strcmp(arg_type, "sint8") == 0) {
                    int8_t value = (int8_t)luaL_checkinteger(L, -1);
                    type_elements[i] = &ffi_type_sint8;
                    memcpy(binary + binary_offset, &value, 1);
                    binary_offset += 1;
                } else if (strcmp(arg_type, "uint16") == 0) {
                    uint16_t value = (uint16_t)luaL_checkinteger(L, -1);
                    type_elements[i] = &ffi_type_uint16;
                    memcpy(binary + binary_offset, &value, 2);
                    binary_offset += 2;
                } else if (strcmp(arg_type, "sint16") == 0) {
                    int16_t value = (int16_t)luaL_checkinteger(L, -1);
                    type_elements[i] = &ffi_type_sint16;
                    memcpy(binary + binary_offset, &value, 2);
                    binary_offset += 2;
                } else if (strcmp(arg_type, "uint32") == 0) {
                    uint32_t value = (uint32_t)luaL_checkinteger(L, -1);
                    type_elements[i] = &ffi_type_uint32;
                    memcpy(binary + binary_offset, &value, 4);
                    binary_offset += 4;
                } else if (strcmp(arg_type, "sint32") == 0) {
                    int32_t value = (int32_t)luaL_checkinteger(L, -1);
                    type_elements[i] = &ffi_type_sint32;
                    memcpy(binary + binary_offset, &value, 4);
                    binary_offset += 4;
                } else if (strcmp(arg_type, "uint64") == 0) {
                    uint64_t value = (uint64_t)luaL_checkinteger(L, -1);
                    type_elements[i] = &ffi_type_uint64;
                    memcpy(binary + binary_offset, &value, 8);
                    binary_offset += 8;
                } else if (strcmp(arg_type, "sint64") == 0) {
                    int64_t value = (int64_t)luaL_checkinteger(L, -1);
                    type_elements[i] = &ffi_type_sint64;
                    memcpy(binary + binary_offset, &value, 8);
                    binary_offset += 8;
                } else if (strcmp(arg_type, "float") == 0) {
                    float value = (float)luaL_checknumber(L, -1);
                    type_elements[i] = &ffi_type_float;
                    memcpy(binary + binary_offset, &value, 4);
                    binary_offset += 4;
                } else if (strcmp(arg_type, "double") == 0) {
                    double value = luaL_checknumber(L, -1);
                    type_elements[i] = &ffi_type_double;
                    memcpy(binary + binary_offset, &value, 8);
                    binary_offset += 8;
                } else if (strcmp(arg_type, "uchar") == 0) {
                    unsigned char value = (unsigned char) luaL_checkinteger(L, -1);
                    type_elements[i] = &ffi_type_uchar;
                    memcpy(binary + binary_offset, &value, 1);
                    binary_offset += 1;
                } else if (strcmp(arg_type, "schar") == 0) {
                    char value = (char) luaL_checkinteger(L, -1);
                    type_elements[i] = &ffi_type_schar;
                    memcpy(binary + binary_offset, &value, 1);
                    binary_offset += 1;
                } else if (strcmp(arg_type, "ushort") == 0) {
                    unsigned short value = (unsigned short) luaL_checkinteger(L, -1);
                    type_elements[i] = &ffi_type_ushort;
                    memcpy(binary + binary_offset, &value, 2);
                    binary_offset += 2;
                } else if (strcmp(arg_type, "sshort") == 0) {
                    short value = (short) luaL_checkinteger(L, -1);
                    type_elements[i] = &ffi_type_ushort;
                    memcpy(binary + binary_offset, &value, 2);
                    binary_offset += 2;
                } else if (strcmp(arg_type, "uint") == 0) {
                    unsigned int value = (unsigned int) luaL_checkinteger(L, -1);
                    type_elements[i] = &ffi_type_uint;
                    memcpy(binary + binary_offset, &value, 4);
                    binary_offset += 4;
                } else if (strcmp(arg_type, "sint") == 0) {
                    int value = (int) luaL_checkinteger(L, -1);
                    type_elements[i] = &ffi_type_sint;
                    memcpy(binary + binary_offset, &value, 4);
                    binary_offset += 4;
                } else if (strcmp(arg_type, "ulong") == 0) {
                    unsigned long value = (unsigned long) luaL_checkinteger(L, -1);
                    type_elements[i] = &ffi_type_ulong;
                    memcpy(binary + binary_offset, &value, 4);
                    binary_offset += 4;
                } else if (strcmp(arg_type, "slong") == 0) {
                    long value = (long) luaL_checkinteger(L, -1);
                    type_elements[i] = &ffi_type_slong;
                    memcpy(binary + binary_offset, &value, 4);
                    binary_offset += 4;
                }
                //else if (strcmp(arg_type, "longdouble") == 0) {
                //    long double value = (long double) luaL_checknumber(L, -1);
                //    type_elements[i] = &ffi_type_longdouble;
                //    memcpy(binary + binary_offset, &value, 16);
                //    binary_offset += 16;
                //}
                else if (strcmp(arg_type, "string") == 0) {
                    size_t *len = (size_t *)malloc(sizeof(size_t) * 10);
                    const char *value = luaL_checklstring(L, -1, len);
                    type_elements[i] = &ffi_type_pointer;
                    memcpy(binary + binary_offset, value, (int)*len + 1);
                    binary_offset += (int)*len + 1;
                    free(len);
                } else if (strcmp(arg_type, "pointer") == 0) {
                    void *value = (void *) (uintptr_t) luaL_checknumber(L, -1);
                    type_elements[i] = &ffi_type_pointer;
                    memcpy(binary + binary_offset, &value, sizeof(void*));
                    binary_offset += sizeof(void*);
                } else {
                    fprintf(stderr, "Unknown type: %s\n", arg_type);
                    exit(1);
                }
                lua_pop(L, 1);
            }
            // スタックからvalueを取り除くがkeyは次のイテレーションのために残す
            lua_pop(L, 1);
            i++;
        }
    }



    // Luaスタック上に新しいテーブルを作成
    lua_newtable(L);

    // テーブルのインデックス1に新しいテーブルをプッシュ
    lua_pushnumber(L, 1); // キー
    lua_newtable(L);      // 値（新しいテーブル）

    // サブテーブルに"types"キーをプッシュ
    lua_pushstring(L, "types");
    lua_pushnumber(L, (double)(uintptr_t)type_elements); // 任意の値A
    lua_settable(L, -3); // サブテーブルに設定

    // インデックス1のテーブルをメインテーブルにセット
    lua_settable(L, -3);

    // テーブルのインデックス2に新しいテーブルをプッシュ
    lua_pushnumber(L, 2); // キー
    lua_newtable(L);      // 値（新しいテーブル）

    // サブテーブルに"binary"キーをプッシュ
    lua_pushstring(L, "binary");
    lua_pushnumber(L, (double)(uintptr_t)binary); // 任意の値B
    lua_settable(L, -3); // サブテーブルに設定

    // インデックス2のテーブルをメインテーブルにセット
    lua_settable(L, -3);

    // テーブルをスタックに残し、Luaに戻る（1は戻り値の数を表す）

    //free(type_elements);
    //free(binary);
    return 1;
}

int my_c_function(lua_State* L) {
    // 関数の引数を取得
    int arg1 = (int)luaL_checkinteger(L, 1);
    int arg2 = (int)luaL_checkinteger(L, 2);

    // 何かしらの計算
    int result = arg1 + arg2;

    // 結果をLuaスタックにプッシュ
    lua_pushinteger(L, result);

    // 戻り値の数を返す
    return 1;
}

RAIA_API const char *init(int argc, char *argv[]) {


    // 新しいLua環境を作成
    lua_State *L = luaL_newstate();

    // 標準ライブラリをロード
    luaL_openlibs(L);
    // JITを有効にする
    //luaJIT_setmode(L, 0, LUAJIT_MODE_ENGINE | LUAJIT_MODE_ON);

    lua_newtable(L); // __Raia__ オブジェクト（テーブル）を作成
    lua_newtable(L); // __Raia__ テーブルの中に Lib オブジェクト（テーブル）を作成

    // Lib テーブルの中に C関数を登録
    lua_pushcfunction(L, raia_lib_open);
    lua_setfield(L, -2, "open");
    lua_pushcfunction(L, raia_lib_close);
    lua_setfield(L, -2, "close");
    lua_pushcfunction(L, raia_lib_close_all);
    lua_setfield(L, -2, "closeAll");
    lua_pushcfunction(L, raia_lib_add);
    lua_setfield(L, -2, "add");
    lua_pushcfunction(L, raia_lib_call);
    lua_setfield(L, -2, "call");
    lua_pushcfunction(L, raia_lib_ffi);
    lua_setfield(L, -2, "ffi");
    lua_pushcfunction(L, raia_lib_make_struct);
    lua_setfield(L, -2, "makeStruct");

    lua_setfield(L, -2, "Lib"); // Lib テーブルを __Raia__ テーブルに登録

    lua_newtable(L);
    lua_pushcfunction(L, my_c_function);
    lua_setfield(L, -2, "my_func");
    lua_setfield(L, -2, "Core");

    lua_setglobal(L, "__Raia__"); // __Raia__ テーブルをグローバル変数として登録


    // Luaスクリプトをロード・実行
    if (luaL_dofile(L, "main.lua") != LUA_OK) {
        // エラーメッセージを取得して表示
        const char *errorMessage = lua_tostring(L, -1);
        printf("Error: %s\n", errorMessage);

        // エラーメッセージをスタックから削除
        lua_pop(L, 1);
    }

    // Lua環境を閉じる
    lua_close(L);

    return 0;
}

int main(int argc, char *argv[]) {
    const char *result = init(argc, argv);
}