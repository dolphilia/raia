#include <iostream>
#include <fstream>
#include <cassert>

#include "luau/lua.h"
#include "luau/lualib.h"
#include "luacode.h"

int main() {

    lua_State* L = luaL_newstate();
    luaL_openlibs(L);

    std::ifstream ifs;
    ifs.open("main.luau", std::ifstream::in);

    std::string content;
    content.assign( (std::istreambuf_iterator<char>(ifs) ),
                    (std::istreambuf_iterator<char>()    ) );

    size_t bytecodeSize = 0;
    char* bytecode = luau_compile(content.c_str(), content.length(), nullptr, &bytecodeSize);
    assert(luau_load(L, "foo", bytecode, bytecodeSize, 0) == 0);
    free(bytecode);

    lua_pcall(L, 0, 0, 0);

    lua_close(L);

    return 0;

}