# raia-engine

## Todo

- [ ] Linuxでのビルド
- [ ] 拡張プラグインサポート(dlfun.h)
- [ ] Babel,TypeScriptによるトランスコンパイル
  - [ ] 複数ファイルのトランスコンパイル

## ビルド

### macOS コマンドライン

HomebrewでGLFWとOpenAL-Softを導入しておく。

```sh
clang -o raia-engine.out src/raia-engine.c include/duktape/duktape.c -lm -lglfw -framework OpenGL -framework OpenAL -I /opt/homebrew/include -I include -L /opt/homebrew/opt/openal-soft/lib -L /opt/homebrew/opt/glfw/lib
```