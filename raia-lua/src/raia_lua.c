#include "raia_lua.h"

#include <stdio.h>
#include "lua/lua.h"
#include "lua/lualib.h"
#include "lua/lauxlib.h"

#ifdef __WINDOWS__
#define RAIA_EXPORT __declspec(dllexport)
#else
#define RAIA_EXPORT
#endif


int my_c_function(lua_State* L) {
    // 関数の引数を取得
    int arg1 = luaL_checkinteger(L, 1);
    int arg2 = luaL_checkinteger(L, 2);

    // 何かしらの計算
    int result = arg1 + arg2;

    // 結果をLuaスタックにプッシュ
    lua_pushinteger(L, result);

    // 戻り値の数を返す
    return 1;
}

int raia_lib_open(lua_State* L) {
    const char *dll_file = luaL_checkstring(L, 1);
#ifdef __WINDOWS__
    const char *extension = "dll";
#endif
#ifdef __MACOS__
    const char *extension = "dylib";
#endif
#ifdef __LINUX__
    const char *extension = "so";
#endif
    char dll_file_extension[500];
    SPRINTF(dll_file_extension, "%s.%s", dll_file, extension);
    open_plugin(dll_file_extension);
    return 0;
}

int raia_lib_close(lua_State* L) {
    close_plugin();
    return 0;
}

int raia_lib_close_all(lua_State* L) {
    close_all_plugin();
    return 0;
}

int raia_lib_add(lua_State* L) { // func_hash
    const char *dll_func_name = luaL_checkstring(L, 1);
    add_plugin_func_hash(dll_func_name);
    return 0;
}

//static duk_ret_t raia_lib_call(duk_context *ctx) { // func_hash
//    const char *dll_func_name = duk_to_string(ctx, 0);
//    char *src; //json string
//    void *data;
//    duk_size_t size;
//    if (duk_is_string(ctx, 1)) {
//        src = (char *)duk_require_string(ctx, 1);
//    } else {
//        src = NULL;
//    }
//    if (duk_is_buffer(ctx, 2)) {
//        data = (void *)duk_require_buffer_data(ctx, 2, &size);
//    } else if(duk_is_pointer(ctx, 2)) {
//        data = (void *)duk_require_pointer(ctx, 2);
//    } else {
//        data = NULL;
//        size = 0;
//    }
//    if (duk_is_number(ctx, 3)) {
//        size = (duk_size_t)duk_require_number(ctx, 3);
//    }
//    JSON_Value *root_value = json_parse_string(src);
//    if (root_value == ((void *) 0)) {
//        fprintf(__stderrp, "Error: Unable to parse JSON string.\n");
//        return 0;
//    }
//    if (src != NULL) {
//        JSON_Object *root_object = json_value_get_object(root_value);
//        const char *return_type = json_object_get_string(root_object, "@return");
//        if (strcmp(return_type, "pointer") == 0 && return_type != NULL) {
//            void *dest = call_func_hash(dll_func_name, src, data, (int)size);
//            duk_push_pointer(ctx, dest);
//            return 1;
//        }
//    }
//    char *dest = (char *)call_func_hash(dll_func_name, src, data, (int)size);
//    duk_push_string(ctx, dest);
//    if(dest != NULL) {
//        free(dest);
//    }
//    return 1;
//}

// Luaから呼び出される関数
static int raia_lib_call(lua_State *L) {
    // func_hash
    const char *dll_func_name = luaL_checkstring(L, 1);
    const char *src; // json string
    void *data;
    size_t size;

    if (lua_isstring(L, 2)) {
        src = lua_tostring(L, 2);
    } else {
        src = NULL;
    }

    if (lua_islightuserdata(L, 3)) {
        data = lua_touserdata(L, 3);
    } else {
        data = NULL;
    }

    if (lua_isnumber(L, 4)) {
        size = (size_t)lua_tonumber(L, 4);
    } else {
        size = 0;
    }

    JSON_Value *root_value = json_parse_string(src);
    if (root_value == NULL) {
        fprintf(stderr, "Error: Unable to parse JSON string.\n");
        return 0;
    }

    if (src != NULL) {
        JSON_Object *root_object = json_value_get_object(root_value);
        const char *return_type = json_object_get_string(root_object, "@return");
        if (return_type != NULL && strcmp(return_type, "pointer") == 0) {
            void *dest = call_func_hash(dll_func_name, src, data, (int)size);
            lua_pushlightuserdata(L, dest);
            return 1;
        }
    }

    char *dest = (char *)call_func_hash(dll_func_name, src, data, (int)size);
    lua_pushstring(L, dest);
    if (dest != NULL) {
        free(dest);
    }
    return 1;
}

RAIA_EXPORT int run(int argc, char *argv[]) {
    init_plugin_loader();
    init_func_hash();

    // 新しいLua環境を作成
    lua_State *L = luaL_newstate();

    // 標準ライブラリをロード
    luaL_openlibs(L);

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
    lua_pushcfunction(L, my_c_function);
    lua_setfield(L, -2, "my_func");


    lua_setfield(L, -2, "Lib"); // Lib テーブルを __Raia__ テーブルに登録
    lua_setglobal(L, "__Raia__"); // __Raia__ テーブルをグローバル変数として登録

    //lua_register(L, "my_func", my_c_function);
    //lua_register(L, "raia_lib_open", raia_lib_open);
    //lua_register(L, "raia_lib_close", raia_lib_close);
    //lua_register(L, "raia_lib_close_all", raia_lib_close_all);
    //lua_register(L, "raia_lib_add", raia_lib_add);
    //lua_register(L, "raia_lib_call", raia_lib_call);

    // Luaスクリプトをロード・実行
    if (luaL_dofile(L, "startup.lua") != LUA_OK) {
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
