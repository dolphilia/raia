#include "raia_lua.h"
#include "../../../common/c/static/shared_library_loader.h"
#include "../../../common/c/static/static_args_hash.h"
#include "ffi.h"

int raia_lib_open(lua_State* L) {
    const char *dll_file = luaL_checkstring(L, 1);
    char library_name[500];
    SPRINTF(library_name, "%s.%s", dll_file, DYNAMIC_LIB_EXT);
    int handle = open_shared_library(library_name);
    lua_pushinteger(L, handle);
    return 1;
}

int raia_lib_close(lua_State* L) {
    int library_key = lua_tointeger(L, 1);
    close_shared_library(library_key);
    return 0;
}

int raia_lib_close_all(lua_State* L) {
    close_all_shared_library();
    return 0;
}

int raia_lib_add(lua_State* L) {
    int library_key = lua_tointeger(L, 1);
    const char *func_name = lua_tostring(L, 2);
    add_func_shared_library(library_key, func_name);
    return 0;
}

int raia_lib_call(lua_State *L) {
    int library_key = lua_tointeger(L, 1);
    const char *func_name = luaL_checkstring(L, 2);
    const char *json = lua_tostring(L, 3);
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
    int library_key = lua_tointeger(L, 1);
    const char * func_name = lua_tostring(L, 2);
    const char * ret_type = lua_tostring(L, 3);
    ffi_type *ffi_args_type[512];
    void *ffi_args_values[512];
    args_key_t ffi_rets;
    //
    int args_len = 0;

    // テーブルからデータを読み取る
    int index = 4;

    lua_pushnil(L);  // 最初のキー
    while (lua_next(L, index - 1) != 0) {
        // 'key' は -2 に、'value' は -1 に置かれる
        if (lua_istable(L, -1)) {
            int len = luaL_len(L, -1);
            for (int i = 1; i <= len; i++) {
                lua_rawgeti(L, -1, i);
                if (lua_isstring(L, -1)) {
                    printf("%s ", lua_tostring(L, -1));
                } else if (lua_isnumber(L, -1)) {
                    printf("%d ", (int)lua_tonumber(L, -1));
                }
                lua_pop(L, 1);  // 取得した値をスタックから削除
            }
            printf("\n");
        }
        lua_pop(L, 1);  // 'value' をスタックから削除
    }
    return 0;
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
