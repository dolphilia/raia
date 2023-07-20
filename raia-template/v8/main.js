// Static import
var req = require("foo");
print(req.result);

import {repeat, shout} from 'lib';
let r = repeat('hello');
let s = shout('Modules in action');
print(r);
print(s);

// Dynamic import
// import('lib.mjs')
//     .then((module) => {
//         let a = module.repeat('hello');
//         let b = module.shout ('Modules in action');
//         print(a);
//         print(b);
//     });

import {ret} from 'raia.js';
print(ret);
//var req = require("raia.js");
//print(req.result);
//var uryu = require("uryu.js");
//print(uryu.result);
//var handle = __Raia__.Lib.open("raia_file");
//print(handle);
//__Raia__.Lib.add(handle, "raia_file_exist");
//var result = __Raia__.Lib.call("raia_file_exist", '{"path": "raia_v8"}');
//print(result);
__Raia__.printArrayBuffer(__Raia__.binaryData);
__Raia__.helloWorld();
print("Hello");
var result = __Raia__.add(3, 4);
print(result);

var buffer = new ArrayBuffer(10);
var view = new Uint8Array(buffer);
for (var i = 0; i < 10; ++i) {
    view[i] = i;
}
__Raia__.printArrayBuffer(buffer);

var buffer2 = __Raia__.createBinaryData();
var view2 = new Uint8Array(buffer2);
for (var i = 0; i < view2.length; ++i) {
    print(view2[i]);
}