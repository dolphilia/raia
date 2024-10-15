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

int raia_os_get_sizeof_ptr(lua_State *L) {
    #if defined(__LP64__) || defined(_WIN64) || (defined(__x86_64__) && !defined(__ILP32__)) || defined(_M_X64) || defined(__ia64__) || defined(_M_IA64) || defined(__aarch64__) || defined(_M_ARM64) || defined(__powerpc64__)
        lua_pushinteger(L, 8);  // 64-bit system
    #else
        lua_pushinteger(L, 4);  // 32-bit system
    #endif
    return 1;
}

int raia_os_is_compiled_gcc(lua_State *L) {
    #if defined(__GNUC__)
        lua_pushboolean(L, true);
    #else
        lua_pushboolean(L, false);
    #endif
    return 1;
}

int raia_os_is_compiled_msvc(lua_State *L) {
    #if defined(_MSC_VER)
        lua_pushboolean(L, true);
    #else
        lua_pushboolean(L, false);
    #endif
    return 1;
}

int raia_os_is_compiled_clang(lua_State *L) {
    #if defined(__clang__)
        lua_pushboolean(L, true);
    #else
        lua_pushboolean(L, false);
    #endif
    return 1;
}

int raia_os_is_defined_wchar_t(lua_State *L) {
    #if defined(_WCHAR_T_DEFINED)
        lua_pushboolean(L, true);
    #else
        lua_pushboolean(L, false);
    #endif
    return 1;
}

int raia_os_is_windows(lua_State *L) {
#if defined(_WIN32)
    lua_pushboolean(L, true);
#else
    lua_pushboolean(L, false);
#endif
    return 1;
}

int raia_os_is_posix(lua_State *L) {
#if !defined(_WIN32)
    lua_pushboolean(L, true);
#else
    lua_pushboolean(L, false);
#endif
    return 1;
}

int raia_os_is_unix(lua_State *L) {
#if !defined(__unix__)
    lua_pushboolean(L, true);
#else
    lua_pushboolean(L, false);
#endif
    return 1;
}

int raia_os_is_linux(lua_State *L) {
#if !defined(__linux__)
    lua_pushboolean(L, true);
#else
    lua_pushboolean(L, false);
#endif
    return 1;
}

int raia_os_is_macos(lua_State *L) {
#if !defined(__APPLE__)
    lua_pushboolean(L, true);
#else
    lua_pushboolean(L, false);
#endif
    return 1;
}

// string.concat 関数の実装
int string_concat(lua_State *L) {
    const char *str1 = luaL_checkstring(L, 1); // 第1引数を取得
    const char *str2 = luaL_checkstring(L, 2); // 第2引数を取得

    lua_pushstring(L, strcat(strdup(str1), str2)); // 2つの文字列を連結してスタックにプッシュ
    return 1; // 1つの値を返す
}

RAIA_API const char *init(int argc, char *argv[]) {
    lua_State *L = luaL_newstate(); // 新しいLua環境を作成
    luaL_openlibs(L); // 標準ライブラリをロード

    // Luaのstringテーブルを取得
    lua_getglobal(L, "string");
    // stringテーブルにconcat関数を登録
    lua_pushcfunction(L, string_concat);
    lua_setfield(L, -2, "concat");

    // 新規テーブル raia に追加
    lua_newtable(L); // raia
    {
        lua_newtable(L); // raia.os
        {
            lua_pushcfunction(L, raia_os_get_sizeof_ptr);
            lua_setfield(L, -2, "getSizeofPtr");
            lua_pushcfunction(L, raia_os_is_compiled_gcc);
            lua_setfield(L, -2, "isCompiledGCC");
            lua_pushcfunction(L, raia_os_is_compiled_msvc);
            lua_setfield(L, -2, "isCompiledMSVC");
            lua_pushcfunction(L, raia_os_is_compiled_clang);
            lua_setfield(L, -2, "isCompiledClang");
            lua_pushcfunction(L, raia_os_is_defined_wchar_t);
            lua_setfield(L, -2, "isDefinedWCharT");
            lua_pushcfunction(L, raia_os_is_windows);
            lua_setfield(L, -2, "isWindows");
            lua_pushcfunction(L, raia_os_is_posix);
            lua_setfield(L, -2, "isPosix");
            lua_pushcfunction(L, raia_os_is_unix);
            lua_setfield(L, -2, "isUnix");
            lua_pushcfunction(L, raia_os_is_linux);
            lua_setfield(L, -2, "isLinux");
            lua_pushcfunction(L, raia_os_is_macos);
            lua_setfield(L, -2, "isMacOS");
        }
        lua_setfield(L, -2, "os");
        lua_newtable(L); // raia.lib
        {
            lua_pushcfunction(L, raia_core_is_lua_type);
            lua_setfield(L, -2, "type");
        }
        lua_setfield(L, -2, "lua");
        lua_newtable(L); // raia.core
        {
            lua_pushcfunction(L, raia_core_plus);
            lua_setfield(L, -2, "plus");
            lua_pushcfunction(L, register_lua_function);
            lua_setfield(L, -2, "registerLuaFunction");
            lua_pushcfunction(L, raia_core_get_lua_state);
            lua_setfield(L, -2, "getLuaState");
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