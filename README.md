# raia-engine

## Todo

- [ ] コマンドラインからのビルド
  - [ ] clang/gcc単体
    - [x] macOS
    - [ ] Linux
    - [ ] Windows(MinGW)
- [ ] 拡張プラグインサポート(dlfun.h)
- [ ] トランスコンパイル
  - [ ] Babel
  - [ ] TypeScript
  - [ ] 複数ファイルのトランスコンパイル
  - [ ] RaiaToolsとの連携
- [ ] APIの選定
- [ ] ドキュメント
  - [ ] ウェブサイト
  - [ ] 翻訳

## ビルド

### macOS コマンドライン

HomebrewでGLFWとOpenAL-Softを導入しておく。

```sh
clang \
-o raia-engine.out \
src/raia-engine.c \
src/duktape/duktape.c \
src/duktape_module/duk_module_duktape.c \
src/raia/raia_al.c \
src/raia/raia_duktape.c \
src/raia/raia_gl.c \
src/static/static_duk_ctx.c \
src/static/static_header.c \
src/static/static_pixel_data.c \
src/static/static_shader.c \
src/static/static_window.c \
src/stb/stb_image.c \
src/util/util_io.c \
src/util/util_math.c \
src/util/util_pixel.c \
src/util/util_string.c \
src/wrapper/wrapper_duktape.c \
src/wrapper/wrapper_gles.c \
src/wrapper/wrapper_glfw.c \
src/wrapper/wrapper_stb_image.c \
-lm \
-framework OpenAL \
-I /opt/homebrew/include \
-I include \
-I src \
-L /opt/homebrew/opt/openal-soft/lib \
-L /opt/homebrew/opt/glfw/lib \
-L lib \
-lEGL \
-lGLESv2 \
-lglfw \
-Wl,-rpath,'.'
```