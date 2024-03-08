(function() {
    if (globalThis.__RAIA_STD__ === undefined) {
        globalThis.__RAIA_STD__ = {};
    }
})();

export class Std {
    
    constructor() {}
    
    /**
     * @param {any} message 
     */
    
    print(message) {
        __Raia__.Core.print(message);
    }

    /**
     * @param {number} status (sint) 0: 正常終了, 1以上: エラー終了
     */
    
    exit(status) {
        __Raia__.Core.exit(status);
    }
    
    /**
     * @param {any} pointer (uintptr)
     * @param {number} size (int)
     * @returns {ArrayBuffer}
     */

    ptrToBuf(pointer, size) {
        return __Raia__.Core.ptrToBuf(pointer, size);
    }

    /**
     * @param {ArrayBuffer} buffer
     * @returns {any} (uintptr)
     */

    bufToPtr(buffer) {
        return __Raia__.Core.bufToPtr(buffer);
    }

    makeStruct(args_list) {
        return __Raia__.Core.makeStruct(args_list);
    }

    delStruct(obj) {
        __Raia__.Core.delStruct(obj);
    }

    newPtr(size) {
        return __Raia__.Core.newPtr(size);
    }

    delPtr(ptr) {
        __Raia__.Core.delPtr(ptr);
    }

    ptrToInt(ptr) {
        return __Raia__.Core.ptrToInt(ptr);
    }

    /**
     * @param {number} min (sint)
     * @param {number} max (sint)
     * @returns {number} (sint)
     */

    rand(min, max) {
        return Math.floor(Math.random() * (max - min + 1)) + min;
    }
}