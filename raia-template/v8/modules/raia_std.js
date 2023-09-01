(function() {
    if (globalThis.__Raia__.Std === undefined) {
        globalThis.print = __Raia__.Core.print;
        globalThis.exit = __Raia__.Core.exit;
        globalThis.__Raia__.Std = {};
    }
})();
