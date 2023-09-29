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
     * @returns {uintptr}
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
     * @param {uintptr} handle 
     * @param {string} func_name 
     */
    add(handle, func_name) {
        // @ts-ignore
        __Raia__.Lib.add(handle, func_name);
    }
    /**
     * @param {string} func_name 
     * @param {string} args
     * @returns {string | null}
     */
    call(func_name, args = "") {
        // @ts-ignore
        return __Raia__.Lib.call(func_name, args);
    }
}