//
// Created by dolphilia on 24/08/19.
//

#ifndef STATIC_LUA_STATE_H
#define STATIC_LUA_STATE_H

#include <luajit/lua.h>

lua_State *get_static_lua_state();
void set_static_lua_state(lua_State *state);

#endif //STATIC_LUA_STATE_H
