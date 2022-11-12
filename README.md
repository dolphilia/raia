# raia-engine

## ToDo

- [ ] ToDoリストの移動（issues）
- [ ] コマンドラインからのビルド
  - [ ] clang/gcc単体
    - [x] macOS
    - [ ] Linux
    - [ ] Windows(MinGW)
- [x] 拡張プラグインサポート(dlfun.h)
  - [x] C言語
  - [x] C++言語
- [ ] プラグイン作成のサポート(SDK)
- [ ] トランスコンパイル
  - [x] Babel
  - [x] TypeScript
  - [ ] 複数ファイルのトランスコンパイル
  - [ ] RaiaToolsとの連携
- [ ] APIの選定
- [ ] ドキュメントの作成
  - [ ] ウェブサイトの作成
  - [ ] ドキュメントの翻訳
- [ ] パッケージ処理
- [ ] コーディングルールの作成


## ビルド

### macOS コマンドライン

HomebrewでGLFWとOpenAL-Softを導入しておく。

```sh
clang \
-o raia-engine \
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
-I include \
-I src \
-L lib \
-lEGL \
-lGLESv2 \
-lglfw \
-Wl,-rpath,'.'
```

## macOS App化（シェルスクリプト経由）

- raia_engine.app
  - Contents
    - Info.plist
    - MacOS
      - run.sh
      - raia-engine
      - .dylib
      - ...
    - Resources
      - startup.js
      - app.icns

```xml
<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE plist PUBLIC "-//Apple//DTD PLIST 1.0//EN" "http://www.apple.com/DTDs/PropertyList-1.0.dtd">
<plist version="1.0">
<dict>
    <key>CFBundleExecutable</key>
    <string>run.sh</string>
    <key>CFBundlePackageType</key>
    <string>APPL</string>
    <key>CFBundleSignature</key>
    <string>run</string>
    <key>CFBundleIconFile</key>
    <string>app.icns</string>
</dict>
</plist>
```

```sh
#!/bin/bash

CURRENT=$(cd $(dirname $0);pwd)
cd $CURRENT
$CURRENT/raia-engine
```

`run.sh`にスクリプトの実行権限を付与しておく

```
chmod +x run.sh
```