//
// Created by dolphilia on 2023/07/18.
//

#ifndef RAIA_V8_RAIA_V8_H
#define RAIA_V8_RAIA_V8_H

extern "C" {
#include "../../../../common/c/utility/export_api.h"
#include "../../../../common/c/utility/platform.h"
#include "../../../../common/c/wrapper/wrapper_yyjson.h"
#include "../../../../common/c/static/static_plugin_hash.h"
#include "../../../../common/c/static/static_func_hash.h"
#include "../../../../common/c/static/static_entrust.h"
#include "../../../../common/c/utility/util_file.h"
#include "../../../../common/c/static/static_args_hash.h"
#include "ffi.h"
#include "../../../../common/c/wrapper/wrapper_ffi.h"
}
#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include "libplatform/libplatform.h"
#include "v8.h"
#include "wrapper/wrapper_v8.h"
#include "static/static_raia_config.h"

#ifdef _WIN32
#include "v8config.h"
#undef V8_ENABLE_POINTER_COMPRESSION
#endif

#ifdef _WIN32
#include <stdlib.h>
#define STRCAT(dest, src) { size_t size = sizeof(dest) / sizeof(dest[0]); strcat_s(dest, size, src); }
#define SPRINTF(dest, format, ...) { size_t size = sizeof(dest) / sizeof(dest[0]); sprintf_s(dest, size, format, __VA_ARGS__); }
#define STRNCPY(dest, src, count) { size_t size = sizeof(dest) / sizeof(dest[0]); strncpy_s(dest, size, src, count); }
#else
#define STRCAT(dest, src) strcat(dest, src)
#define SPRINTF(dest, format, ...) sprintf(dest, format, __VA_ARGS__)
#define STRNCPY(dest, src, count) strncpy(dest, src, count)
#endif

#ifdef __WINDOWS__
#define DYNAMIC_LIB_EXT "dll"
#endif
#ifdef __MACOS__
#define DYNAMIC_LIB_EXT "dylib"
#endif
#ifdef __LINUX__
#define DYNAMIC_LIB_EXT "so"
#endif

// macro

/*
    TYPE_UINT8,
    TYPE_SINT8,
    TYPE_UINT16,
    TYPE_SINT16,
    TYPE_UINT32,
    TYPE_SINT32,
    TYPE_UINT64,
    TYPE_SINT64,
    TYPE_FLOAT,
    TYPE_DOUBLE,
    TYPE_UCHAR,
    TYPE_SCHAR,
    TYPE_USHORT,
    TYPE_SSHORT,
    TYPE_UINT,
    TYPE_SINT,
    TYPE_ULONG,
    TYPE_SLONG,
    TYPE_LONGDOUBLE,
    TYPE_POINTER,
    TYPE_STRING
 */

#define v8_args_t v8::FunctionCallbackInfo<v8::Value>
#define v8_args_to_uint8(args, num) (uint8_t)args[num].As<v8::Uint32>()->Value()
#define v8_args_to_sint8(args, num) (int8_t)args[num].As<v8::Int32>()->Value()
#define v8_args_to_uint16(args, num) (uint16_t)args[num].As<v8::Uint32>()->Value()
#define v8_args_to_sint16(args, num) (int16_t)args[num].As<v8::Int32>()->Value()
#define v8_args_to_uint32(args, num) (uint32_t)args[num].As<v8::Uint32>()->Value()
#define v8_args_to_sint32(args, num) (int32_t)args[num].As<v8::Int32>()->Value()
#define v8_args_to_uint64(args, num) (uint64_t)args[num].As<v8::Number>()->Value()
#define v8_args_to_sint64(args, num) (int64_t)args[num].As<v8::Number>()->Value()
#define v8_args_to_float(args, num) (float)args[num].As<v8::Number>()->Value()
#define v8_args_to_double(args, num) (double)args[num].As<v8::Number>()->Value()
#define v8_args_to_uchar(args, num) (unsigned char)args[num].As<v8::Uint32>()->Value()
#define v8_args_to_schar(args, num) (char)args[num].As<v8::Uint32>()->Value()
#define v8_args_to_ushort(args, num) (unsigned short)args[num].As<v8::Uint32>()->Value()
#define v8_args_to_sshort(args, num) (short)args[num].As<v8::Int32>()->Value()
#define v8_args_to_uint(args, num) args[num].As<v8::Uint32>()->Value()
#define v8_args_to_sint(args, num) args[num].As<v8::Int32>()->Value()
#define v8_args_to_ulong(args, num) (unsigned long)args[num].As<v8::Number>()->Value()
#define v8_args_to_slong(args, num) (long)args[num].As<v8::Number>()->Value()
#define v8_args_to_longdouble(args, num) (long double)args[num].As<v8::Number>()->Value()
#define v8_args_to_str(args, num) std::string(*(v8::String::Utf8Value(args.GetIsolate(), args[num])))
#define v8_args_to_ptr(args, num) (void *)(uintptr_t)args[num].As<v8::Number>()->Value()
#define v8_args_to_buf(args, num) args[num].As<v8::ArrayBuffer>()
#define v8_args_to_array(args, value) args[value].As<v8::Array>()
#define v8_args_to_obj(args, value) args[value]->ToObject(args.GetIsolate()->GetCurrentContext()).ToLocalChecked()

#define v8_rets_to_null(args) args.GetReturnValue().SetNull()
#define v8_rets_to_uint8(args, value) args.GetReturnValue().Set(v8::Uint32::New(args.GetIsolate(), value))
#define v8_rets_to_sint8(args, value) args.GetReturnValue().Set(v8::Int32::New(args.GetIsolate(), value))
#define v8_rets_to_uint16(args, value) args.GetReturnValue().Set(v8::Uint32::New(args.GetIsolate(), value))
#define v8_rets_to_sint16(args, value) args.GetReturnValue().Set(v8::Int32::New(args.GetIsolate(), value))
#define v8_rets_to_uint32(args, value) args.GetReturnValue().Set(v8::Uint32::New(args.GetIsolate(), value))
#define v8_rets_to_sint32(args, value) args.GetReturnValue().Set(v8::Int32::New(args.GetIsolate(), value))
#define v8_rets_to_uint64(args, value) args.GetReturnValue().Set(v8::Number::New(args.GetIsolate(), value))
#define v8_rets_to_sint64(args, value) args.GetReturnValue().Set(v8::Number::New(args.GetIsolate(), value))
#define v8_rets_to_float(args, value) args.GetReturnValue().Set(v8::Number::New(args.GetIsolate(), value))
#define v8_rets_to_double(args, value) args.GetReturnValue().Set(v8::Number::New(args.GetIsolate(), value))
#define v8_rets_to_uchar(args, value) args.GetReturnValue().Set(v8::Uint32::New(args.GetIsolate(), value))
#define v8_rets_to_schar(args, value) args.GetReturnValue().Set(v8::Uint32::New(args.GetIsolate(), value))
#define v8_rets_to_ushort(args, value) args.GetReturnValue().Set(v8::Uint32::New(args.GetIsolate(), value))
#define v8_rets_to_sshort(args, value) args.GetReturnValue().Set(v8::Int32::New(args.GetIsolate(), value))
#define v8_rets_to_uint(args, value) args.GetReturnValue().Set(v8::Uint32::New(args.GetIsolate(), value))
#define v8_rets_to_sint(args, value) args.GetReturnValue().Set(v8::Int32::New(args.GetIsolate(), value))
#define v8_rets_to_ulong(args, value) args.GetReturnValue().Set(v8::Number::New(args.GetIsolate(), value))
#define v8_rets_to_slong(args, value) args.GetReturnValue().Set(v8::Number::New(args.GetIsolate(), value))
#define v8_rets_to_longdouble(args, value) args.GetReturnValue().Set(v8::Number::New(args.GetIsolate(), value))
#define v8_rets_to_str(args, str) args.GetReturnValue().Set(v8::String::NewFromUtf8(args.GetIsolate(), str).ToLocalChecked())
#define v8_rets_to_ptr(args, ptr) args.GetReturnValue().Set(v8::Number::New(args.GetIsolate(), (uint64_t)(uintptr_t)ptr))
#define v8_rets_to_buf(args, buf) args.GetReturnValue().Set(buf)

#define v8_array_to_uint8(isolate, array, value) (uint8_t)array->Get(isolate->GetCurrentContext(), value).ToLocalChecked().As<v8::Uint32>()->Value()
#define v8_array_to_sint8(isolate, array, value) (int8_t)array->Get(isolate->GetCurrentContext(), value).ToLocalChecked().As<v8::Int32>()->Value()
#define v8_array_to_uint16(isolate, array, value) (uint16_t)array->Get(isolate->GetCurrentContext(), value).ToLocalChecked().As<v8::Uint32>()->Value()
#define v8_array_to_sint16(isolate, array, value) (int16_t)array->Get(isolate->GetCurrentContext(), value).ToLocalChecked().As<v8::Int32>()->Value()
#define v8_array_to_uint32(isolate, array, value) (uint32_t)array->Get(isolate->GetCurrentContext(), value).ToLocalChecked().As<v8::Uint32>()->Value()
#define v8_array_to_sint32(isolate, array, value) (int32_t)array->Get(isolate->GetCurrentContext(), value).ToLocalChecked().As<v8::Int32>()->Value()
#define v8_array_to_uint64(isolate, array, value) (uint64_t)array->Get(isolate->GetCurrentContext(), value).ToLocalChecked().As<v8::Number>()->Value()
#define v8_array_to_sint64(isolate, array, value) (int64_t)array->Get(isolate->GetCurrentContext(), value).ToLocalChecked().As<v8::Number>()->Value()
#define v8_array_to_float(isolate, array, value) (float)array->Get(isolate->GetCurrentContext(), value).ToLocalChecked().As<v8::Number>()->Value()
#define v8_array_to_double(isolate, array, value) (double)array->Get(isolate->GetCurrentContext(), value).ToLocalChecked().As<v8::Number>()->Value()
#define v8_array_to_uchar(isolate, array, value) (unsigned char)array->Get(isolate->GetCurrentContext(), value).ToLocalChecked().As<v8::Uint32>()->Value()
#define v8_array_to_schar(isolate, array, value) (char)array->Get(isolate->GetCurrentContext(), value).ToLocalChecked().As<v8::Uint32>()->Value()
#define v8_array_to_ushort(isolate, array, value) (unsigned short)array->Get(isolate->GetCurrentContext(), value).ToLocalChecked().As<v8::Uint32>()->Value()
#define v8_array_to_sshort(isolate, array, value) (short)array->Get(isolate->GetCurrentContext(), value).ToLocalChecked().As<v8::Int32>()->Value()
#define v8_array_to_uint(isolate, array, value) array->Get(isolate->GetCurrentContext(), value).ToLocalChecked().As<v8::Uint32>()->Value()
#define v8_array_to_sint(isolate, array, value) array->Get(isolate->GetCurrentContext(), value).ToLocalChecked().As<v8::Int32>()->Value()
#define v8_array_to_ulong(isolate, array, value) (unsigned long)array->Get(isolate->GetCurrentContext(), value).ToLocalChecked().As<v8::Number>()->Value()
#define v8_array_to_slong(isolate, array, value) (long)array->Get(isolate->GetCurrentContext(), value).ToLocalChecked().As<v8::Number>()->Value()
#define v8_array_to_longdouble(isolate, array, value) (long double)array->Get(isolate->GetCurrentContext(), value).ToLocalChecked().As<v8::Number>()->Value()
#define v8_array_to_str(isolate, array, value) std::string(*(v8::String::Utf8Value(isolate, array->Get(isolate->GetCurrentContext(), value).ToLocalChecked())))
#define v8_array_to_ptr(isolate, array, value) (void *)(uintptr_t)(array->Get(isolate->GetCurrentContext(), value).ToLocalChecked().As<v8::Number>()->Value())
#define v8_array_to_buf(isolate, array, value) array->Get(isolate->GetCurrentContext(), num).ToLocalChecked().As<v8::ArrayBuffer>()
#define v8_array_to_obj(isolate, array, value) array->Get(isolate->GetCurrentContext(), value).ToLocalChecked()->ToObject(isolate->GetCurrentContext()).ToLocalChecked()
#define v8_array_to_value(isolate, array, value) array->Get(isolate->GetCurrentContext(), value).ToLocalChecked()

#define v8_array_get(array, value) array->Get(args.GetIsolate()->GetCurrentContext(), value).ToLocalChecked()
#define v8_array_to_array(array, value) array->Get(args.GetIsolate()->GetCurrentContext(), value).ToLocalChecked().As<v8::Array>()

#define v8_obj_to_ptr(isolate, obj, key) obj->Get(isolate->GetCurrentContext(), v8::String::NewFromUtf8(isolate, key, v8::NewStringType::kNormal).ToLocalChecked()).ToLocalChecked()->NumberValue(isolate->GetCurrentContext()).FromJust()
#define v8_obj_add(isolate, obj, key, value)  obj->Set(isolate->GetCurrentContext(), v8::String::NewFromUtf8(isolate, key, v8::NewStringType::kNormal).ToLocalChecked(), v8::Number::New(isolate, value)).FromJust()

#define v8_value_to_str(value) std::string(*(v8::String::Utf8Value(args.GetIsolate(), value)))
#define v8_value_to_array(value) value.As<v8::Array>()

#define v8_buf_to_ptr(buf) static_cast<void*>(buf->GetBackingStore()->Data())
#define v8_local_str(isolate, data) v8::String::NewFromUtf8(isolate, data, v8::NewStringType::kNormal).ToLocalChecked()

#define v8_init()                                       \
    v8::V8::InitializeICUDefaultLocation(argv[0]);      \
    v8::V8::InitializeExternalStartupData(argv[1]);     \
    auto platform = v8::platform::NewDefaultPlatform(); \
    v8::V8::InitializePlatform(platform.get());         \
    v8::V8::Initialize()

#define v8_set_func(isolate, obj, key, callback) obj->Set(isolate->GetCurrentContext(), v8_local_str(isolate, key), v8::FunctionTemplate::New(isolate, callback)->GetFunction(isolate->GetCurrentContext()).ToLocalChecked()).FromJust()

#define v8_set_obj(isolate, value, obj, key) \
    v8::Local<v8::Object> value = v8::Object::New(isolate); \
    obj->Set(isolate->GetCurrentContext(), v8_local_str(isolate, key), value).FromJust()

#define v8_context_init(isolate, context) \
    auto isolate_scope = v8::Isolate::Scope(isolate); \
    auto handle_scope = v8::HandleScope(isolate); \
    v8::Local<v8::Context> context = v8::Context::New(isolate, nullptr, v8::ObjectTemplate::New(isolate)); \
    auto context_scope = v8::Context::Scope(context)

#define v8_isolate_init(isolate, isolate_params) \
    v8::Isolate::CreateParams isolate_params; \
    isolate_params.array_buffer_allocator = v8::ArrayBuffer::Allocator::NewDefaultAllocator(); \
    v8::Isolate *isolate = v8::Isolate::New(isolate_params)

#define v8_isolate_set_callback(isolate, import_dynamic, import_meta) \
    isolate->SetHostImportModuleDynamicallyCallback(reinterpret_cast<v8::HostImportModuleDynamicallyCallback>(import_dynamic)); \
    isolate->SetHostInitializeImportMetaObjectCallback(import_meta);

#define v8_destroy(isolate_params) \
    v8::V8::Dispose(); \
    v8::V8::DisposePlatform(); \
    delete isolate_params.array_buffer_allocator

#define v8_start()                                                                                               \
do {                                                                                                             \
    auto new_filename = get_raia_config().startup_script;                                                        \
    auto code = load_script((char *) get_raia_config().startup_script.c_str(), get_raia_config().root_dir,true); \
    auto ml_mod = import_load(code, (char *) new_filename.c_str(), context);                                     \
    auto mod = import_check(ml_mod, context);                                                                    \
    auto ret = import_exec(mod, context);                                                                        \
} while(0)

#define init_startup_script()                                                \
do {                                                                         \
    init_raia_config("config.json");                                         \
    auto filename_extension = get_raia_config().startup_script + ".js";      \
    auto directories = get_directories(get_raia_config().root_dir);          \
    auto path = file_exists_in_directories(filename_extension, directories); \
    set_raia_config_startup_script(path);                                    \
} while(0)

#endif //RAIA_V8_RAIA_V8_H
