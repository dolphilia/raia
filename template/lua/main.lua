
--[[
local json = require("dkjson")

__Raia__.Lib.open("./raia_file")
__Raia__.Lib.add("raia_file_exist")
local result = json.decode(__Raia__.Lib.call("raia_file_exist", '{"path": "main.png"}')).result;
print(result)
]]
local handle = __Raia__.Lib.open("libminilib")
__Raia__.Lib.add(handle, "plus")
__Raia__.Lib.add(handle, "add_struct")

local ret = __Raia__.Lib.ffi(
    handle,
    "plus",
    "sint",
    {
        {"sint", "x", 100},
        {"sint", "y", 200}
    }
)

local num_struct = __Raia__.Lib.makeStruct(
    {
        {"sint", 1000},
        {"sint", 2000},
    }
)

local result_value = __Raia__.Lib.ffi(
    handle,
    "add_struct",
    "sint",
    {
        {"struct", "point", num_struct}
    }
)

print(ret)
print(result_value)