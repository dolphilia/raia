(function() {
    if (globalThis.__RAIA_LIB__ === undefined) {
        globalThis.__RAIA_LIB__ = {};
    }
})();

export class Lib {
    constructor() {
    }
    /**
     * @param {String} lib_name
     * @returns {Number}
     */
    open(lib_name) {
        // @ts-ignore
        return __Raia__.Lib.open(lib_name);
    }
    /**
     * @param {String} lib_name 
     */
    close(lib_name) {
        // @ts-ignore
        __Raia__.Lib.close(lib_name);
    }
    closeAll() {
        // @ts-ignore
        __Raia__.Lib.closeAll();
    }
    /**
     * @param {Number} handle 
     * @param {String} func_name 
     */
    add(handle, func_name) {
        // @ts-ignore
        __Raia__.Lib.add(handle, func_name);
    }
    /**
     * @param {Number} library_key
     * @param {String} func_name 
     * @param {String} args
     * @returns {String | null}
     */
    call(library_key, func_name, args = "") {
        // @ts-ignore
        return __Raia__.Lib.call(library_key, func_name, args);
    }
    /**
     * @param {Number} library_key
     * @param {String} func_name
     * @param {String} ret_type
     * @param {Array | null} args
     * @returns {Any} 
     */
    ffi(library_key, func_name, ret_type, args = null) {
        // @ts-ignore
        return __Raia__.Lib.ffi(library_key, func_name, ret_type, args);
    }
}