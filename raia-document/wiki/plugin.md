# プラグインの作成

RaiaEngineはCインターフェースを用いた共有ライブラリをプラグインとして使用します。共有ライブラリを作成できる環境であればプログラミング言語を問わずプラグインを作成することができます。

現在、C, C++, Rust, Zig, Go, D, V でプラグインを作成できることを確認しています。

## C言語でプラグインを作成する

### CMakeを使用する場合:

以下のコマンドをターミナルで実行します。

```sh
mkdir library # プロジェクトを格納するためのディレクトリを作成します。ディレクトリ名は任意です。
cd library # 移動します
touch library.c # C言語のソースファイルを作成します。ファイル名は任意です。
touch CMakeLists.txt # CMakeに必要なファイルを作成します
```

C言語のソースファイル`library.c`を編集します。

```c
#include <stdio.h>

#ifdef __WINDOWS__
#define RAIA_EXPORT __declspec(dllexport)
#else
#define RAIA_EXPORT
#endif

RAIA_EXPORT const char *foo(const char *s) {
    printf("%s\n", s);
    return NULL;
}
```

CMakeLists.txtを編集します。

```cmake
cmake_minimum_required(VERSION 3.25)
project(library C)

set(CMAKE_C_STANDARD 11)

add_library(library SHARED library.c)
```

ビルドします。

```sh
cmake .
make
```

### TODO Makefileを使用する

## Rustでプラグインを作成する

まず新しいプロジェクトを作成します。ターミナルで次のコマンドを実行してください。

```sh
cargo new --lib library
cd library
```

プロジェクトディレクトリ内の Cargo.toml ファイルを開き、`[lib]`セクションを追加し、crate-type を設定して共有ライブラリとしてコンパイルされるように指定します。

```toml
[lib]
name = "library"
crate-type = ["cdylib"]

[dependencies]
libc = "0.2"
serde = { version = "1.0", features = ["derive"] }
serde_json = "1.0"
```

src/lib.rs ファイルを開き、共有ライブラリからエクスポートする関数を定義します。ここで、`#[no_mangle]` 属性を使用して、Rustコンパイラが関数名をマングリングしないように指示します。また、pub extern を使用して、関数が外部からアクセス可能になるように指定します。

```rust
use std::ffi::{CString, CStr};
use std::os::raw::{c_char, c_void};
use serde_json::Value;

fn c_json_to_json(s: *const c_char) -> Value {
    let src_str = unsafe { CStr::from_ptr(s).to_str().unwrap() };
    let parsed_data: Value = serde_json::from_str(src_str).unwrap();
    return parsed_data;
}

fn json_to_c_ptr(s: String) -> *const c_char {
    let c_result_str = CString::new(s).unwrap();
    return c_result_str.into_raw();
}

#[no_mangle]
pub extern "C" fn function_name(src: *const c_char) -> *const c_char {
    let parsed_data: Value = c_json_to_json(src);

    let result_str = format!("Result: {}", serde_json::to_string_pretty(&parsed_data).unwrap());

    return json_to_c_ptr(result_str);
}
```

プロジェクトディレクトリで、次のコマンドを実行して共有ライブラリをビルドします:

```sh
cargo build --release
```

## Zigでプラグインを作成する

まず、共有ライブラリに含めるソースファイルを作成します。例として、my_shared_lib.zigというファイルを作成し、次のようなコードを記述します。

```zig
const std = @import("std");
const c = @cImport({
    @cInclude("stddef.h");
});

pub export fn function_name(src: [*c]const u8) [*c]u8 {
    // ここで、src、data、sizeを使って処理を行います。
    // この例では、単純にsrcを返すだけです。
    return src;
}
```

次に、zig build-libコマンドを使って共有ライブラリをビルドします。以下のコマンドを実行して、共有ライブラリをビルドしてください。

```sh
zig build-lib my_shared_lib.zig -dynamic
```

## Goでプラグインを作成する

```sh
go mod init library
```

go.modとgo.sumが作成されます

```go
package main

import "C"
import (
	"encoding/json"
	"fmt"
	"runtime"
	"unsafe"
)

func cCharToJSON(s *C.char) map[string]interface{} {
	var goJson = C.GoString(s)
	var parsed map[string]interface{}
	var err = json.Unmarshal([]byte(goJson), &parsed)
	if err != nil {
		return nil
	}
	return parsed
}

func JSONtoCPtr(s map[string]interface{}) unsafe.Pointer {
	var bytes, _ = json.Marshal(s)
	var cStr = C.CString(string(bytes))
	runtime.KeepAlive(cStr)
	return unsafe.Pointer(cStr)
}

//export goFunc
func goFunc(s *C.char) unsafe.Pointer {
	var parsed = cCharToJSON(s)

	return JSONtoCPtr(map[string]interface{}{
		"result": "true",
	})
}

func main() {} // Required but does nothing

```

ビルドします

```sh
go build -o library.dylib -buildmode=c-shared
```

## V言語

```v
module mylib

[export]
fn func(s string) string {
    return s // あるいは他の文字列を返す
}
```

```sh
v -shared -o library.dylib library.v
```

## D言語

```d
import core.stdc.stdlib: malloc, free;

extern (C) char* my_func(const char* s, void* p, int n) {
    // ここに具体的な処理を記述します
    import core.stdc.string : strlen, strcpy;

    size_t len = strlen(s);
    char* res = cast(char*) malloc(len + 1);
    strcpy(res, s);

    return res;
}
```

```sh
ldc2 -shared library.d -of=library.dylib
```

