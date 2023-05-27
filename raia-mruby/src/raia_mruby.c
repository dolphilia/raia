#include "raia_mruby.h"

#include <stdio.h>
#include "mruby.h"
#include "mruby/compile.h"

#ifdef __WINDOWS__
#define RAIA_EXPORT __declspec(dllexport)
#else
#define RAIA_EXPORT
#endif

mrb_value my_c_function(mrb_state *mrb, mrb_value self) {
    // 引数を取得します。この例では1つの文字列を取得します。
    char *str = NULL;
    mrb_get_args(mrb, "z", &str);

    printf("Hello, %s\n", str);

    // mruby関数は常に値を返さなければなりません。何も返さない場合はnilを返します。
    return mrb_nil_value();
}

RAIA_EXPORT int run(int argc, char *argv[]) {
    mrb_state *mrb = mrb_open();
    if (!mrb) { /* handle error */ }
    // mrb_load_string(mrb, str) to load from NULL terminated strings
    // mrb_load_nstring(mrb, str, len) for strings without null terminator or with known length
    mrb_load_string(mrb, "puts 'hello world'");
    mrb_close(mrb);
    return 0;
}
