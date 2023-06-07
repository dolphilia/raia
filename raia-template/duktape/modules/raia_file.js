"use strict";

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
    exist: function exist(json_str) {
        return __Raia__.Core.Lib.call("raia_file_exist", json_str, null, null);
    },
    loadString: function loadString(json_str) {
        return __Raia__.Core.Lib.call("raia_file_load_string", json_str, null, null);
    },
    saveString: function saveString(json_str) {
        return __Raia__.Core.Lib.call("raia_file_save_string", json_str, null, null);
    },
    loadBinary: function loadBinary(json_str) {
        return __Raia__.Core.Lib.call("raia_file_load_binary", json_str, null, null);
    },
    saveBinary: function saveBinary(json_str, data) {
        var size = arguments.length > 2 && arguments[2] !== undefined ? arguments[2] : null;

        return __Raia__.Core.Lib.call("raia_file_save_binary", json_str, data, size);
    },
    getCurPath: function getCurPath(json_str) {
        return __Raia__.Core.Lib.call("raia_file_get_cur_path", json_str, null, null);
    },
    getDirs: function getDirs(json_str) {
        return __Raia__.Core.Lib.call("raia_file_get_dirs", json_str, null, null);
    },
    getDirsAll: function getDirsAll(json_str) {
        return __Raia__.Core.Lib.call("raia_file_get_dirs_all", json_str, null, null);
    }
};