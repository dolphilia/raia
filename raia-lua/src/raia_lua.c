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

    if (src != NULL) {
        yyjson_doc *arg_doc = yyjson_read(src, strlen(src), 0);
        yyjson_val *arg_root = yyjson_doc_get_root(arg_doc);
        yyjson_val *arg_val = yyjson_obj_get(arg_root, "@return");
        const char *return_type = yyjson_get_str(arg_val);
        if (return_type != NULL && strcmp(return_type, "pointer") == 0) {
            void *dest = call_func_hash(dll_func_name, src, data, (int)size);
            lua_pushlightuserdata(L, dest);
            yyjson_doc_free(arg_doc);
            return 1;
        }
        yyjson_doc_free(arg_doc);
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
