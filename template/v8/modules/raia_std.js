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
     * @param {ArrayBuffer} buffer 
     * @returns {uintptr}
     */
    arrayBufferToPointer(buffer) {
        // @ts-ignore
        return __Raia__.Core.arrayBufferToPointer(buffer);
    }
    /**
     * @param {uintptr} pointer 
     * @returns {ArrayBuffer}
     */
    pointerToArrayBuffer(pointer) {
        // @ts-ignore
        return __Raia__.Core.pointerToArrayBuffer(pointer);
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