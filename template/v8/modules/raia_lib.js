(function() {
    if (globalThis.__RAIA_LIB__ === undefined) {
        globalThis.__RAIA_LIB__ = {};
    }
})();

export class Lib {
    
    constructor() {
    }

    /**
     * @param {string} lib_name
     * @returns {number}
     */

    open(lib_name) {
        // @ts-ignore
        return __Raia__.Lib.open(lib_name);
    }

    /**
     * @param {string} lib_name 
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
     * @param {number} handle 
     * @param {string} func_name 
     */

    add(handle, func_name) {
        // @ts-ignore
        __Raia__.Lib.add(handle, func_name);
    }

    /**
     * @param {number} library_key
     * @param {string} func_name 
     * @param {string} args
     * @returns {string | null}
     */

    call(library_key, func_name, args = "") {
        // @ts-ignore
        return __Raia__.Lib.call(library_key, func_name, args);
    }

    /**
     * @param {number} library_key
     * @param {string} func_name
     * @param {string} ret_type
     * @param {Array | null} args
     * @returns {any} 
     */

    ffi(library_key, func_name, ret_type, args = null) {
        // @ts-ignore
        return __Raia__.Lib.ffi(library_key, func_name, ret_type, args);
    }
}