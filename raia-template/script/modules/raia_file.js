__Raia__.Core.Lib.open("raia_file");

module.exports = {
    exist: __Raia__.Core.Lib.func("raia_file_exist", 1),
    loadString: __Raia__.Core.Lib.func("raia_file_load_string", 1),
    saveString: __Raia__.Core.Lib.func("raia_file_save_string", 2),
    loadJson: __Raia__.Core.Lib.func("raia_file_load_json", 1),
    saveJson: __Raia__.Core.Lib.func("raia_file_save_json", 2),
    loadBinary: __Raia__.Core.Lib.func("raia_file_load_binary", 1),
    saveBinary: __Raia__.Core.Lib.func("raia_file_save_binary", 2),
}