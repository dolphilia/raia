//
// Created by dolphilia on 24/08/19.
//

#include "static_lua_state.h"

static lua_State *static_lua_state;

lua_State *get_static_lua_state() {
    return static_lua_state;
}

void set_static_lua_state(lua_State *state) {
    static_lua_state = state;
}