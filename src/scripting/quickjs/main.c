#include <stdio.h>
#include "quickjs/quickjs.h"
#include "quickjs/quickjs-libc.h"

//JSModuleDef *js_module_loader(JSContext *ctx, const char *module_name, void *opaque) {
//    size_t buf_len;
//    uint8_t *buf = js_load_file(ctx, &buf_len, module_name);
//    if (!buf) {
//        fprintf(stderr, "Module not found: %s\n", module_name);
//        return NULL;
//    }
//
//    JSValue func_val = JS_Eval(ctx, (char *)buf, buf_len, module_name, JS_EVAL_TYPE_MODULE | JS_EVAL_FLAG_COMPILE_ONLY);
//    js_free(ctx, buf);
//    if (JS_IsException(func_val)) {
//        js_std_dump_error(ctx);
//        return NULL;
//    }
//
//    JSModuleDef *m = (JSModuleDef *)JS_VALUE_GET_PTR(func_val);
//    JS_FreeValue(ctx, func_val);
//    return m;
//}

// console.log の実装
static JSValue js_console_log(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    int i;
    const char *str;

    for (i = 0; i < argc; i++) {
        if (i != 0)
            putchar(' ');
        str = JS_ToCString(ctx, argv[i]);
        if (!str)
            return JS_EXCEPTION;
        printf("%s", str);
        JS_FreeCString(ctx, str);
    }

    putchar('\n');
    return JS_UNDEFINED;
}

// console オブジェクトをグローバルオブジェクトに追加する関数
static int js_init_console(JSContext *ctx) {
    JSValue global_obj, console;

    global_obj = JS_GetGlobalObject(ctx);
    console = JS_NewObject(ctx);
    JS_SetPropertyStr(ctx, console, "log", JS_NewCFunction(ctx, js_console_log, "log", 1));
    JS_SetPropertyStr(ctx, global_obj, "console", console);
    JS_FreeValue(ctx, global_obj);

    return 0;
}

int main() {
    JSRuntime *rt;
    JSContext *ctx;
    rt = JS_NewRuntime();
    if (!rt) {
        fprintf(stderr, "Failed to create QuickJS runtime\n");
        return -1;
    }
    ctx = JS_NewContext(rt);
    if (!ctx) {
        fprintf(stderr, "Failed to create QuickJS context\n");
        JS_FreeRuntime(rt);
        return -1;
    }

    //
    //JS_SetModuleLoaderFunc(rt, NULL, js_module_loader, NULL);

    // consoleを登録
    js_init_console(ctx);

    // JSファイルの読み込みと実行
    const char *filename = "./example.js";
    uint8_t *buf;
    size_t buf_len;
    JSValue result;

    buf = js_load_file(ctx, &buf_len, filename);
    if (!buf) {
        fprintf(stderr, "Failed to load JS file: %s\n", filename);
        JS_FreeContext(ctx);
        JS_FreeRuntime(rt);
        return -1;
    }

    result = JS_Eval(ctx, (char *)buf, buf_len, filename, JS_EVAL_TYPE_GLOBAL);
    js_free(ctx, buf);
    if (JS_IsException(result)) {
        js_std_dump_error(ctx);
        result = JS_UNDEFINED;
    }
//    const char *main_js_path = "./example.js";
//    size_t buf_len;
//    uint8_t *buf = js_load_file(ctx, &buf_len, main_js_path);
//    if (buf) {
//        JSValue result = JS_Eval(ctx, (char *)buf, buf_len, main_js_path, JS_EVAL_TYPE_MODULE);
//        if (JS_IsException(result)) {
//            js_std_dump_error(ctx);
//        }
//        JS_FreeValue(ctx, result);
//        js_free(ctx, buf);
//    } else {
//        fprintf(stderr, "Failed to load the entry module: %s\n", main_js_path);
//    }

    JS_FreeValue(ctx, result);
    JS_FreeContext(ctx);
    JS_FreeRuntime(rt);

    return 0;
}
