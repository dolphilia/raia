(function() {
    if (globalThis.__RAIA_STD__ === undefined) {
        globalThis.__RAIA_STD__ = {};
    }
})();

export class Std {
    constructor() {}
    /**
     * @param {string} message 
     */
    print(message) {
        // @ts-ignore
        __Raia__.Core.print(message);
    }
    /**
     * @param {int} status - (int) 0: 正常終了 , 1以上: エラー終了
     */
    exit(status) {
        // @ts-ignore
        __Raia__.Core.exit(status);
    }
    /**
     * @param {uintptr} pointer 
     * @returns {ArrayBuffer}
     */
    ptrToBuf(pointer) {
        // @ts-ignore
        return __Raia__.Core.ptrToBuf(pointer);
    }
    /**
     * @param {ArrayBuffer} buffer 
     * @returns {uintptr}
     */
    bufToPtr(buffer) {
        // @ts-ignore
        return __Raia__.Core.bufToPtr(buffer);
    }
    makeStruct(args_list) {
        // @ts-ignore
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
     * @param {int} min 
     * @param {int} max 
     * @returns {int}
     */
    rand(min, max) {
        return Math.floor(Math.random() * (max - min + 1)) + min;
    }
}