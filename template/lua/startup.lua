local json = require("dkjson")

__Raia__.Lib.open("./raia_file")
__Raia__.Lib.add("raia_file_exist")
local result = json.decode(__Raia__.Lib.call("raia_file_exist", '{"path": "main.png"}')).result;
print(result)