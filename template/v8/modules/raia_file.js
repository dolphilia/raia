
(function() {
    if (globalThis.__RAIA_FILE__ === undefined) {
        globalThis.__RAIA_FILE__ = {};
        globalThis.__RAIA_FILE__.handle = __Raia__.Lib.open("raia_file");
        __Raia__.Lib.add(globalThis.__RAIA_FILE__.handle, "raia_file_exist");
        __Raia__.Lib.add(globalThis.__RAIA_FILE__.handle, "raia_file_load_string");
        __Raia__.Lib.add(globalThis.__RAIA_FILE__.handle, "raia_file_save_string");
        __Raia__.Lib.add(globalThis.__RAIA_FILE__.handle, "raia_file_load_binary");
        __Raia__.Lib.add(globalThis.__RAIA_FILE__.handle, "raia_file_save_binary");
        __Raia__.Lib.add(globalThis.__RAIA_FILE__.handle, "raia_file_get_cur_path");
        __Raia__.Lib.add(globalThis.__RAIA_FILE__.handle, "raia_file_get_dirs");
        __Raia__.Lib.add(globalThis.__RAIA_FILE__.handle, "raia_file_get_dirs_all");
    }
}());

export class File {

    constructor() {}

    /**
     * ファイルの存在を確認する
     * 
     * @param {string} path (string) ファイルのパス
     * 
     * @returns {number} (sint) 0:存在しない 1:ファイルが存在 2:ディレクトリが存在 
     */
    
    exist(path) {
        const args = JSON.stringify({
            "path": path
        });
        const rets = __Raia__.Lib.call(globalThis.__RAIA_FILE__.handle, "raia_file_exist", args);
        return JSON.parse(rets)["exist"];
    }

    /**
     * ファイルから文字列を読み込む
     * 
     * @param {string} path (string) ファイルのパス
     * 
     * @returns {string} (string) 読み込んだ文字列
     */

    loadString(path) {
        const args = JSON.stringify({
            "path": path
        });
        const rets = __Raia__.Lib.call(globalThis.__RAIA_FILE__.handle, "raia_file_load_string", args);
        return JSON.parse(rets)["str"];
    }

    /**
     * ファイルに文字列を保存する
     * 
     * @param {string} path (string) ファイルのパス
     * @param {string} str (string) 保存する文字列
     * 
     * @returns {boolean} (sint) 成功:true 失敗:false
     */

    saveString(path, str) {
        const args = JSON.stringify({
            "path": path,
            "str": str
        });
        const rets = __Raia__.Lib.call(globalThis.__RAIA_FILE__.handle, "raia_file_save_string", args);
        return JSON.parse(rets)["is_success"];
    }

    /**
     * ファイルからバイナリデータを読み込む
     * 
     * @param {string} path (string) ファイルのパス
     * 
     * @returns {number} (uintptr) バイナリデータのポインタ整数
     */

    loadBinary(path) {
        const args = JSON.stringify({
            "path": path
        });
        const rets = __Raia__.Lib.call(globalThis.__RAIA_FILE__.handle, "raia_file_load_binary", args);
        return JSON.parse(rets)["binary"];
    }

    /**
     * ファイルにバイナリデータを保存する
     * 
     * @param {string} path (string) ファイルのパス
     * @param {ArrayBuffer} binary バイナリデータ
     * @param {number} [size=null] (sint) データのサイズ
     * 
     * @returns {boolean} (sint) 成功:true 失敗:false
     */

    saveBinary(path, binary, size = null) {
        const args = JSON.stringify({
            "path": path, 
            "binary": __Raia__.Core.bufToPtr(binary),
            "size": size
        });
        const ret = __Raia__.Lib.call(globalThis.__RAIA_FILE__.handle, "raia_file_save_binary", args);
        return JSON.parse(ret)["is_success"];
    }

    getCurPath() {
        const rets = __Raia__.Lib.call(globalThis.__RAIA_FILE__.handle, "raia_file_get_cur_path", "");
        return JSON.parse(rets).result;
    }

    getDirs(path) {
        const args = JSON.stringify({
            "path": path
        });
        const rets = __Raia__.Lib.call(globalThis.__RAIA_FILE__.handle, "raia_file_get_dirs", args)
        return JSON.parse(rets).result;
    }
    
    getDirsAll(path) {
        const args = JSON.stringify({
            "path": path
        });
        const rets = __Raia__.Lib.call(globalThis.__RAIA_FILE__.handle, "raia_file_get_dirs_all", args);
        return JSON.parse(rets).result;
    }
}