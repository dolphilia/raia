import {Std} from "raia_std";
let std = new Std();

var handle = __Raia__.Lib.open("libminilib");
__Raia__.Lib.add(handle, "plus");
__Raia__.Lib.add(handle, "minus");
__Raia__.Lib.add(handle, "hello");
__Raia__.Lib.add(handle, "put");
__Raia__.Lib.add(handle, "int_array");
__Raia__.Lib.add(handle, "add_struct");

std.print(handle);
var ret;

ret = __Raia__.Lib.ffi(
    handle,
    "plus", // 関数名
    "sint", // 戻り値の型
    [
        ["sint", "x", 100], // 型, 引数名, 値
        ["sint", "y", 200]
    ]
);

std.print("return value:" + ret);

var num_struct = std.makeStruct(
    [
        ["sint", 1000],
        ["sint", 2000]
    ]
);

var result_value =  __Raia__.Lib.ffi(
    handle,
    "add_struct", // 関数名
    "sint", // 戻り値の型
    [
        ["struct", "point", num_struct]
    ]
);

std.print("result:"+result_value);
std.delStruct(num_struct);

let int32Array = new Int32Array([1, 2, 3, 4, 5]);
let int32pointer = __Raia__.Core.bufToPtr(int32Array.buffer);

__Raia__.Lib.ffi(
    handle,
    "int_array", // 関数名
    "void", // 戻り値の型
    [
        ["pointer", "num", int32pointer], // 型, 引数名, 値
        ["sint", "size", 5]
    ]
);

std.print("---");

ret = __Raia__.Lib.ffi(
    handle,
    "minus", // 関数名
    "sint", // 戻り値の型
    [
        ["sint", "x", 100], // 型, 引数名, 値
        ["sint", "y", 200] // ...
    ]
);

std.print("return value:" + ret);

ret = __Raia__.Lib.ffi(
    handle,
    "hello", // 関数名
    "void", // 戻り値の型
    null
);

std.print("return value:" + ret);

ret = __Raia__.Lib.ffi(
    handle,
    "put", // 関数名
    "void", // 戻り値の型
    [
        ["string", "str", "PutFunction"]
    ]
);

std.print("return value:" + ret);
std.print("NEW");
std.print("@:"+std.rand(-100.11, 100.323));