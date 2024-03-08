// 標準モジュールの使用例
// @ts-ignore
//import * as std from 'std';
// import * as std from "std";
// import * as os from "os";
// OS モジュールの使用例
// @ts-ignore
//import * as os from 'os';
//std.exit();
//console.log(getcwd());

import { hello } from './foo.js';
hello();
console.log('Hello from QuickJS!');
var handle = __Raia__.Lib.open("libminilib");
console.log('id:', handle);
__Raia__.Lib.add(handle, "plus");
__Raia__.Lib.add(handle, "minus");
__Raia__.Lib.add(handle, "hello");
__Raia__.Lib.add(handle, "put");
__Raia__.Lib.add(handle, "int_array");
__Raia__.Lib.add(handle, "add_struct");
var ret = __Raia__.Lib.ffi(
    handle,
    "plus", // 関数名
    "sint", // 戻り値の型
    [
        ["sint", "x", 100], // 型, 引数名, 値
        ["sint", "y", 200]
    ]
);
console.log("plus:", ret);

ret = __Raia__.Lib.ffi(
    handle,
    "minus", // 関数名
    "sint", // 戻り値の型
    [
        ["sint", "x", 100], // 型, 引数名, 値
        ["sint", "y", 200] // ...
    ]
);
console.log("minus:", ret);

ret = __Raia__.Lib.ffi(
    handle,
    "hello", // 関数名
    "void", // 戻り値の型
    null
);
console.log("hello:", ret);

var num_struct = __Raia__.Lib.makeStruct(
    [
        ["sint", 1000],
        ["sint", 2000]
    ]
);

console.log("types:" + num_struct.types);
console.log("binary:" + num_struct.binary);

var result_value =  __Raia__.Lib.ffi(
    handle,
    "add_struct", // 関数名
    "sint", // 戻り値の型
    [
        ["struct", "point", num_struct]
    ]
);

console.log("result:"+result_value);