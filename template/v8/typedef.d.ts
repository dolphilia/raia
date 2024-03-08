// declare type int = number;
// declare type float = number;
// declare type double = number;
// declare type bool = boolean;

// declare type i8 = number;
// declare type i16 = number;
// declare type i32 = number;
// declare type i64 = number;
// declare type u8 = number;
// declare type u16 = number;
// declare type u32 = number;
// declare type u64 = number;

// declare type uint = number;
// declare type sint = number;
// declare type real = number;

// declare type uintptr = uint;
// declare type pointer = uintptr;

// declare type int_t = number;
// declare type uint_t = number;
// declare type sint_t = number;

// declare type color_rgb_t = {
//     r: real,
//     g: real,
//     b: real
// }

// declare type color_rgba_t = {
//     r: real,
//     g: real,
//     b: real,
//     a: real
// }

// declare type color_hsv_t = {
//     h: real,
//     s: real,
//     v: real
// }

// declare type point_t = {
//     x: number,
//     y: number
// }

// declare type segment_t = {
//     start: point_t,
//     end: point_t
// }

// declare type size_t = {
//     width: number,
//     height: number
// }

// declare type rect_t = {
//     pos: point_t,
//     size: size_t
// }

// declare type vec2_t = {
//     dx: number,
//     dy: number
// }

declare global {
    var __Raia__: Raia;
    function gc(): void;
}

interface Raia {
    Core: Core;
    Lib: Lib;
    Fs: Fs;
}

interface Core {
    print(message: any): void;
    exit(status: number): void; // (int)
    bufToPtr(ptr: ArrayBuffer): number; // (ArrayBuffer) -> uintptr
    ptrToBuf(ptr: number, size: number): ArrayBuffer; // (uintptr, int) -> ArrayBuffer
    makeStruct(args_list: any): any;
    delStruct(obj: any): void;
    newPtr(size: number): any; // (int)
    delPtr(ptr: any): void;
    ptrToInt(ptr: any): number;
}

interface Lib {
    open(path: string): number; // (string) -> int
    close(key: number): void; // (int)
    closeAll(): void;
    add(key: number, funcName: string): void; // (sint, string)
    call(key: number, funcName: string, json: string): string | null; // (int, string, string) -> string | null
    ffi(key: number, funcName: string, returnType: string, args: Array): any; // (int, string, string, Array) -> any
}

export {};