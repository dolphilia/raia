(function() {
    if (globalThis.__Raia__.File === undefined) {
        var handle = __Raia__.Lib.open("raia_file");
        __Raia__.Lib.add(handle, "raia_file_exist");
        __Raia__.Lib.add(handle, "raia_file_load_string");
        __Raia__.Lib.add(handle, "raia_file_save_string");
        __Raia__.Lib.add(handle, "raia_file_load_binary");
        __Raia__.Lib.add(handle, "raia_file_save_binary");
        __Raia__.Lib.add(handle, "raia_file_get_cur_path");
        __Raia__.Lib.add(handle, "raia_file_get_dirs");
        __Raia__.Lib.add(handle, "raia_file_get_dirs_all");
        globalThis.__Raia__.File = {};
    }
}());

export class File {
    constructor (){}
    exist(path) {
        var json_str = JSON.stringify({
            "path": path
        });
        var ret = __Raia__.Lib.call("raia_file_exist", json_str);
        return JSON.parse(ret).result;
    }
    loadString(path) {
        var json_str = JSON.stringify({
            "path": path
        });
        var ret = __Raia__.Lib.call("raia_file_load_string", json_str);
        return JSON.parse(ret).result;
    }
    saveString(path, data) {
        var json_str = JSON.stringify({
            "path": path,
            "data": data
        });
        var ret = __Raia__.Lib.call("raia_file_save_string", json_str);
        return JSON.parse(ret).result;
    }
    loadBinary(path) {
        var json_str = JSON.stringify({
            "path": path
        });
        return __Raia__.Lib.call("raia_file_load_binary", json_str);
    }
    saveBinary(path, data, size = null) {
        var json_str = JSON.stringify({
            "path": path, 
            "data": __Raia__.Core.arrayBufferToPointer(data),
            "size": size
        });
        var ret = __Raia__.Lib.call("raia_file_save_binary", json_str);
        return JSON.parse(ret).result;
    }
    getCurPath() {
        var ret = __Raia__.Lib.call("raia_file_get_cur_path", "");
        return JSON.parse(ret).result;
    }
    getDirs(path) {
        var json_str = JSON.stringify({
            "path": path
        });
        var ret = __Raia__.Lib.call("raia_file_get_dirs", json_str)
        return JSON.parse(ret).result;
    }
    getDirsAll(path) {
        var json_str = JSON.stringify({
            "path": path
        });
        var ret = __Raia__.Lib.call("raia_file_get_dirs_all", json_str);
        return JSON.parse(ret).result;
    }
}