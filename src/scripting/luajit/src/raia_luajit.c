#include "raia_luajit.h"

static int lua_function_ref = LUA_NOREF; // Lua関数への参照を保持する変数

// Lua関数を呼び出すC関数
void call_lua_function(lua_State *L) {
    lua_rawgeti(L, LUA_REGISTRYINDEX, lua_function_ref); // Lua関数をスタックにプッシュ
    if (lua_isfunction(L, -1)) { // 関数が正しく取得できたか確認
        if (lua_pcall(L, 0, 0, 0) != LUA_OK) {
            const char *error_msg = lua_tostring(L, -1); // エラーハンドリング
            printf("Error calling Lua function: %s\n", error_msg);
            lua_pop(L, 1); // エラーメッセージをポップ
        }
    } else {
        lua_pop(L, 1); // 関数ではない場合にスタックからポップ
        printf("Lua function reference is invalid.\n");
    }
}

// Lua関数を登録するC関数
int register_lua_function(lua_State *L) {
    if (lua_isfunction(L, 1)) { // スタックの最初の引数が関数かどうかを確認
        if (lua_function_ref != LUA_NOREF) {
            luaL_unref(L, LUA_REGISTRYINDEX, lua_function_ref); // 既存の関数参照を解除
        }
        lua_function_ref = luaL_ref(L, LUA_REGISTRYINDEX); // Lua関数をレジストリに登録し、参照を保持
    } else {
        printf("Expected a function as argument.\n");
    }
    return 0;
}

int raia_core_plus(lua_State* L) {
    int arg1 = (int)luaL_checkinteger(L, 1); // 関数の引数を取得
    int arg2 = (int)luaL_checkinteger(L, 2);
    int result = arg1 + arg2; // 何かしらの計算
    lua_pushinteger(L, result); // 結果をLuaスタックにプッシュ
    return 1; // 戻り値の数を返す
}

int raia_core_get_lua_state(lua_State* L) {
    lua_pushnumber(L, (double)(uintptr_t)L);
    return 1;
}

void *raia_internal_number_to_pointer(double number) {
    return (void *)(uintptr_t)number;
}

double raia_internal_pointer_to_number(void *pointer) {
    return (double)(uintptr_t)pointer;
}

int raia_core_pointer_to_number(lua_State* L) {
    const void *pointer = lua_topointer(L, 1);
    lua_pushnumber(L, (double)(uintptr_t)pointer);
    return 1;
}

int raia_core_number_to_pointer(lua_State* L) {
    double number = lua_tonumber(L, 1);
    lua_pushlightuserdata(L, (void *)(uintptr_t)number);
    return 1;
}

static int raia_core_is_lua_type(lua_State *L) {
    int t = lua_type(L, 1);  // スタックの1番目の引数の型を取得
    const char *tname = lua_typename(L, t);  // 型名を文字列で取得
    lua_pushstring(L, tname);  // 型名をスタックにプッシュ
    return 1;  // 戻り値の数
}

RAIA_API const char *init(int argc, char *argv[]) {
    lua_State *L = luaL_newstate(); // 新しいLua環境を作成
    luaL_openlibs(L); // 標準ライブラリをロード

    lua_newtable(L); // raia
    {
        lua_newtable(L); // raia.lib
        {
            // Lib テーブルの中に C関数を登録
//    lua_pushcfunction(L, raia_lib_open);
//    lua_setfield(L, -2, "open");
//    lua_pushcfunction(L, raia_lib_close);
//    lua_setfield(L, -2, "close");
//    lua_pushcfunction(L, raia_lib_close_all);
//    lua_setfield(L, -2, "closeAll");
//    lua_pushcfunction(L, raia_lib_add);
//    lua_setfield(L, -2, "add");
//    lua_pushcfunction(L, raia_lib_call);
//    lua_setfield(L, -2, "call");
//    lua_pushcfunction(L, raia_lib_ffi);
//    lua_setfield(L, -2, "ffi");
//    lua_pushcfunction(L, raia_lib_make_struct);
//    lua_setfield(L, -2, "makeStruct");
        }
        lua_setfield(L, -2, "Lib"); // Lib テーブルを __Raia__ テーブルに登録
        lua_newtable(L); // raia.core
        {
            lua_pushcfunction(L, raia_core_plus);
            lua_setfield(L, -2, "plus");
            lua_pushcfunction(L, register_lua_function);
            lua_setfield(L, -2, "registerLuaFunction");
            lua_pushcfunction(L, raia_core_get_lua_state);
            lua_setfield(L, -2, "getLuaState");
            lua_pushcfunction(L, raia_core_is_lua_type);
            lua_setfield(L, -2, "isType");
        }
        lua_setfield(L, -2, "core");
    }
    lua_setglobal(L, "raia"); // __Raia__ テーブルをグローバル変数として登録

    if (luaL_dofile(L, "main.lua") != LUA_OK) { // Luaスクリプトをロード・実行
        const char *errorMessage = lua_tostring(L, -1); // エラーメッセージを取得して表示
        printf("Error: %s\n", errorMessage);
        lua_pop(L, 1); // エラーメッセージをスタックから削除
    }

    lua_close(L); // Lua環境を閉じる
    return 0;
}

int main(int argc, char *argv[]) {
    printf("now test");
    const char *result = init(argc, argv);
}