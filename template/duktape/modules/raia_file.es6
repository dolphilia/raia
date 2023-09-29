var raia_file_handle = __Raia__.Core.Lib.open("raia_file");
__Raia__.Core.Lib.add(raia_file_handle, "raia_file_exist");
__Raia__.Core.Lib.add(raia_file_handle, "raia_file_load_string");
__Raia__.Core.Lib.add(raia_file_handle, "raia_file_save_string");
__Raia__.Core.Lib.add(raia_file_handle, "raia_file_load_binary");
__Raia__.Core.Lib.add(raia_file_handle, "raia_file_save_binary");
__Raia__.Core.Lib.add(raia_file_handle, "raia_file_get_cur_path");
__Raia__.Core.Lib.add(raia_file_handle, "raia_file_get_dirs");
__Raia__.Core.Lib.add(raia_file_handle, "raia_file_get_dirs_all");

module.exports = {
    exist: (path) => {
        var json_str = JSON.stringify({
            "path": path, 
            "@return": "string"
        });
        var ret = __Raia__.Core.Lib.call("raia_file_exist", json_str);
        return JSON.parse(ret).result;
    },
    loadString: (path) => {
        var json_str = JSON.stringify({
            "path": path,
             "@return": "string"
        });
        var ret = __Raia__.Core.Lib.call("raia_file_load_string", json_str);
        return JSON.parse(ret).result;
    },
    saveString: (path, data) => {
        var json_str = JSON.stringify({
            "path": path,
            "data": data, 
            "@return": "string"
        });
        var ret = __Raia__.Core.Lib.call("raia_file_save_string", json_str);
        return JSON.parse(ret).result;
    },
    loadBinary: (path) => {
        var json_str = JSON.stringify({
            "path": path,
            "@return": "pointer"
        });
        return __Raia__.Core.Lib.call("raia_file_load_binary", json_str);
    },
    saveBinary: (path, data, size = null) => {
        var raw_data;
        if (__Raia__.Core.isPointer(data)) {
            raw_data = __Raia__.Core.pointerToNumber(data);
        } else if (__Raia__.Core.isBuffer(data)) {
            raw_data = __Raia__.Core.arrayBufferToNumber(data);
        }
        var json_str = JSON.stringify({
            "path": path, 
            "data": raw_data,
            "size": size,
            "@return": "string"
        });
        var ret = __Raia__.Core.Lib.call("raia_file_save_binary", json_str);
        return JSON.parse(ret).result;
    },
    getCurPath: () => {
        var json_str = JSON.stringify({
            "@return": "string"
        });
        var ret = __Raia__.Core.Lib.call("raia_file_get_cur_path", json_str);
        return JSON.parse(ret).result;
    },
    getDirs: (path) => {
        var json_str = JSON.stringify({
            "path": path,
             "@return": "string"
        });
        var ret = __Raia__.Core.Lib.call("raia_file_get_dirs", json_str)
        return JSON.parse(ret).result;
    },
    getDirsAll: (path) => {
        var json_str = JSON.stringify({
            "path": path,
            "@return": "string"
        });
        var ret = __Raia__.Core.Lib.call("raia_file_get_dirs_all", json_str);
        return JSON.parse(ret).result;
    },
}