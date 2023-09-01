# raia-v8

```sh
python3 tools\dev\v8gen.py x64.release
# args.gn を編集したのち・・・
ninja -C out.gn/x64.release v8_monolith
```

WindowsでV8をビルドするときのargs.gnの設定

```txt
is_debug = false
target_cpu = "x64"
treat_warnings_as_errors = false
is_component_build = false
v8_enable_i18n_support = false
symbol_level = 0
v8_use_external_startup_data = false
v8_static_library = true
v8_enable_i18n_support = false
v8_monolithic = true
use_custom_libcxx = false
v8_enable_pointer_compression = false
```

---

macOSでV8をビルドするときの設定

```
dcheck_always_on = false
is_component_build = false
is_debug = false
target_cpu = "arm64"
use_custom_libcxx = false
v8_monolithic = true
v8_use_external_startup_data = false
v8_enable_pointer_compression = false
v8_enable_31bit_smis_on_64bit_arch = false
```