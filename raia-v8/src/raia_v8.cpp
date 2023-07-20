// Copyright 2015 the V8 project authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <iostream>
#include <filesystem>
#include <vector>
#include <map>
#include <unordered_map>
#include "libplatform/libplatform.h"
#include "v8-initialization.h"
#include "v8-function.h"
#include "v8-exception.h"
#include "v8-json.h"
#include "v8-script.h"
#include "raia_v8.h"
//#include "include/v8-context.h"
//#include "include/v8-isolate.h"
//#include "include/v8-local-handle.h"
//#include "include/v8-primitive.h"
//#include "include/v8-script.h"
//#include "include/v8-array-buffer.h"
//#include "include/v8.h"

#ifdef __WINDOWS__
#define RAIA_EXPORT __declspec(dllexport)
#else
#define RAIA_EXPORT
#endif

//--- util

#define isolate_t v8::Isolate
#define platform_t v8::Platform
#define local_obj_t v8::Local<v8::Object>
#define local_obj_tmp_t v8::Local<v8::ObjectTemplate>
#define local_ctx_t v8::Local<v8::Context>
#define local_arr_buf_t v8::Local<v8::ArrayBuffer>
#define local_fn_tmp_t v8::Local<v8::FunctionTemplate>
#define local_fn_t v8::Local<v8::Function>
#define local_str_t v8::Local<v8::String>
#define local_script_t v8::Local<v8::Script>
#define local_val_t v8::Local<v8::Value>
#define fn_cb_info_val_t v8::FunctionCallbackInfo<v8::Value>
#define unique_ptr_platform_t std::unique_ptr<v8::Platform>
#define shared_ptr_bs_t std::shared_ptr<v8::BackingStore>
#define unique_ptr_bs_t std::unique_ptr<v8::BackingStore>

local_str_t local_str(isolate_t *isolate, const char *data) {
    return v8::String::NewFromUtf8(isolate, data, v8::NewStringType::kNormal).ToLocalChecked();
}

local_script_t local_script(local_ctx_t context, local_str_t str) {
    return v8::Script::Compile(context, str).ToLocalChecked();
}

void v8_platform_init(platform_t *platform) {
    v8::V8::InitializePlatform(platform);
}

void v8_init() {
    v8::V8::Initialize();
}

int get_int_v8_fn_args(const fn_cb_info_val_t &args, int num) {
    return (int)args[num]->IntegerValue(args.GetIsolate()->GetCurrentContext()).ToChecked();
}

std::string get_str_v8_fn_args(const fn_cb_info_val_t &args, int num) {
    v8::String::Utf8Value str(args.GetIsolate(), args[num]);
    std::string cppStr(*str);
    return cppStr;
}

void set_int_v8_fn_ret(const fn_cb_info_val_t &args, int result) {
    args.GetReturnValue().Set(v8::Integer::New(args.GetIsolate(), result));
}

void set_local_obj(isolate_t *isolate, local_obj_t obj, const char *key, local_val_t value) {
    obj->Set(isolate->GetCurrentContext(), local_str(isolate, key), value).FromJust();
}

local_str_t new_local_str(isolate_t *isolate, const char *data) {
    return v8::String::NewFromUtf8(isolate, "exports").ToLocalChecked();
}

local_fn_tmp_t new_fn_tmp(isolate_t *isolate, v8::FunctionCallback callback = nullptr) {
    return v8::FunctionTemplate::New(isolate, callback);
}

local_fn_t new_local_fn(isolate_t *isolate, v8::FunctionCallback callback = nullptr) {
    return v8::FunctionTemplate::New(isolate, callback)->GetFunction(isolate->GetCurrentContext()).ToLocalChecked();
}

void set_local_fn_to_obj(isolate_t *isolate, local_obj_t obj, const char *key, v8::FunctionCallback callback = nullptr) {
    local_fn_t fn = new_local_fn(isolate, callback);
    set_local_obj(isolate, obj, key, fn);
}

std::string new_str_from_val(isolate_t *isolate, local_val_t val) {
    v8::String::Utf8Value v8_str = v8::String::Utf8Value(isolate, val);
    std::string cpp_str(*v8_str);
    return cpp_str;
}

std::vector<std::string> get_directories(const std::string& s) {
    std::vector<std::string> r;
    for(auto& p : std::filesystem::recursive_directory_iterator(s))
        if (p.is_directory())
            r.push_back(p.path().string());
    return r;
}

std::string file_exists_in_directories(const std::string& filename, const std::vector<std::string>& directories) {
    for (const auto& dir : directories) {
        std::filesystem::path filePath = dir;
        filePath /= filename;
        if (std::filesystem::exists(filePath)) {
            return filePath;
        }
    }
    //return "";
    printf("\nFile does not exist: %s\n", filename.c_str());
    exit(EXIT_FAILURE);
}

//--- end util

void raia_lib_open(const fn_cb_info_val_t &args) {
    v8::String::Utf8Value v8_str(args.GetIsolate(), args[0]);
    std::string dll_file(*v8_str);
#ifdef __WINDOWS__
    std::string extension = "dll";
#endif
#ifdef __MACOS__
    std::string extension = "dylib";
#endif
#ifdef __LINUX__
    std::string extension = "so";
#endif
    std::string dll_file_extension = dll_file + "." + extension;
    void *handle = add_plugin_hash(dll_file_extension.c_str());
    double result = (double)(uintptr_t)handle;
    args.GetReturnValue().Set(v8::Number::New(args.GetIsolate(), result));
}

void raia_lib_close(const fn_cb_info_val_t &args) {
    v8::String::Utf8Value v8_str(args.GetIsolate(), args[0]);
    std::string cpp_str(*v8_str);
    const char *name = cpp_str.c_str();
    delete_plugin_hash(name);
}

void raia_lib_close_all(const fn_cb_info_val_t &args) {
    free_plugin_hash();
}

void raia_lib_add(const fn_cb_info_val_t &args) {
    void *handle = (void *)(uintptr_t)args[0].As<v8::Number>()->Value();
    v8::String::Utf8Value v8_str(args.GetIsolate(), args[1]);
    std::string cpp_str(*v8_str);
    const char *dll_func_name = cpp_str.c_str();
    add_plugin_func_hash(handle, dll_func_name);
}

void raia_lib_call(const fn_cb_info_val_t &args) {
    std::string cpp_dll_func_name = new_str_from_val(args.GetIsolate(), args[0]);//cpp_str(*v8_str);
    const char *dll_func_name = cpp_dll_func_name.c_str();

    std::string cpp_src = new_str_from_val(args.GetIsolate(), args[1]);
    const char *src = cpp_src.c_str();
//    if (duk_is_string(ctx, 1)) {
//        src = (char *)duk_require_string(ctx, 1);
//    } else {
//        src = NULL;
//    }
//
//    if (src != NULL) {
    joint_t *joint = joint_init_in_with_str(src);
    if (joint_in_exist(joint, "@return")) {
        const char *return_type = joint_get_in_str(joint, "@return");
        joint_free(joint);
        if (strcmp(return_type, "pointer") == 0 && return_type != nullptr) {
            const char *dest = call_func_hash(dll_func_name, src);
            args.GetReturnValue().Set(v8::String::NewFromUtf8(args.GetIsolate(), dest).ToLocalChecked());
            //duk_push_pointer(ctx, (void *)dest);
            return;
        }
    } else {
        joint_free(joint);
    }
    //}

    const char *dest = call_func_hash(dll_func_name, src);
    args.GetReturnValue().Set(v8::String::NewFromUtf8(args.GetIsolate(), dest).ToLocalChecked());
    if(dest != nullptr) {
        free((void *)dest);
    }
}

void hello_world(const fn_cb_info_val_t &args) {
    std::cout << "Hello, World!" << std::endl;
}

void add(const fn_cb_info_val_t &args) {
    int a = args[0].As<v8::Integer>()->Value();
    int b = args[1].As<v8::Integer>()->Value();
    int result = a + b;
    set_int_v8_fn_ret(args, result);
}
//local_fn_tmp_t add_fn(isolate_t *isolate) {
//    return new_fn_tmp(isolate, [](const fn_cb_info_val_t &args) {
//        int a = get_int_v8_fn_args(args, 0);
//        int b = get_int_v8_fn_args(args, 1);
//        int result = add(a, b);
//        set_int_v8_fn_ret(args, result);
//    });
//}

local_fn_tmp_t print_fn(isolate_t *isolate) {
    return new_fn_tmp(isolate, [](const fn_cb_info_val_t& args){
        for (int i = 0; i < args.Length(); i++) {
            std::string cppStr = get_str_v8_fn_args(args, i);
            const char* cstr = cppStr.c_str();
            std::cout << cstr << (i < args.Length() - 1 ? ' ' : '\n');
        }
    });
}

void print_array_buffer(const fn_cb_info_val_t &args) {
    local_arr_buf_t buffer = args[0].As<v8::ArrayBuffer>();
    shared_ptr_bs_t backing_store = buffer->GetBackingStore();
    char* data = static_cast<char*>(backing_store->Data());
    for (size_t i = 0; i < backing_store->ByteLength(); ++i) {
        std::cout << "Byte " << i << ": " << static_cast<int>(data[i]) << std::endl;
    }
}

void create_binary_data(const fn_cb_info_val_t &args) {
    isolate_t *isolate = args.GetIsolate();
    const int buffer_size = 20;
    unique_ptr_bs_t backing_store = v8::ArrayBuffer::NewBackingStore(isolate,buffer_size);
    for (size_t i = 0; i < buffer_size; ++i) {
        static_cast<char*>(backing_store->Data())[i] = (char)i;
    }
    local_arr_buf_t buffer = v8::ArrayBuffer::New(isolate, std::move(backing_store));
    args.GetReturnValue().Set(buffer);
}

local_arr_buf_t create_array_buffer(isolate_t *isolate) {
    const int buffer_size = 10;
    shared_ptr_bs_t backing_store = v8::ArrayBuffer::NewBackingStore(new char[buffer_size], buffer_size, [](void* data, size_t length, void* deleter_data) {
        delete[] static_cast<char*>(data);
    }, nullptr);
    for (size_t i = 0; i < buffer_size; ++i) {
        static_cast<char*>(backing_store->Data())[i] = (char)i;
    }
    local_arr_buf_t buffer = v8::ArrayBuffer::New(isolate, std::move(backing_store));
    return buffer;
}

std::string LoadFile(const std::string& filename) {
    std::ifstream file(filename);
    return {std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>()};
}

//void Require(const fn_cb_info_val_t& args) {
//    isolate_t* isolate = args.GetIsolate();
//    v8::String::Utf8Value str(isolate, args[0]);
//    std::string code = LoadFile(*str);
//
//    local_obj_tmp_t module_template = v8::ObjectTemplate::New(isolate);
//    module_template->Set(new_local_str(isolate, "exports"), v8::ObjectTemplate::New(isolate));
//
//    local_ctx_t context = isolate->GetCurrentContext();
//    local_obj_t module = module_template->NewInstance(context).ToLocalChecked();
//    set_local_obj(isolate, context->Global(), "module", module);
//
//    local_str_t source = v8::String::NewFromUtf8(isolate, code.c_str()).ToLocalChecked();
//    local_script_t script = v8::Script::Compile(context, source).ToLocalChecked();
//    script->Run(context).ToLocalChecked();
//
//    local_val_t result = module->Get(context, v8::String::NewFromUtf8(isolate, "exports").ToLocalChecked()).ToLocalChecked();
//    args.GetReturnValue().Set(result);
//}

std::unordered_map<std::string, v8::Global<v8::Context>> module_cache;

void Require(const fn_cb_info_val_t& args) {
    isolate_t* isolate = args.GetIsolate();
    v8::TryCatch try_catch(isolate);

    v8::String::Utf8Value str(isolate, args[0]);
    //std::string code = LoadFile(*str);
    const char *code = load_module_script(*str);

    if (module_cache.find(*str) == module_cache.end()) {
        //v8::Local<v8::ObjectTemplate> global = v8::ObjectTemplate::New(isolate);
        //global->Set(isolate, "print", print_fn(isolate));

        local_obj_tmp_t module_template = v8::ObjectTemplate::New(isolate);
        module_template->Set(new_local_str(isolate, "exports"), v8::ObjectTemplate::New(isolate));
        module_template->Set(isolate, "print", print_fn(isolate));
        module_template->Set(v8::String::NewFromUtf8(isolate, "require").ToLocalChecked(),
                    v8::FunctionTemplate::New(isolate, Require));
        //local_fn_t fn = new_local_fn(isolate, Require);
        //module_template->Set(isolate, "require", Require);

        local_ctx_t context = v8::Context::New(isolate, nullptr, module_template);
        //set_local_fn_to_obj(isolate, context->Global(), "require", Require);


        local_obj_t module = module_template->NewInstance(context).ToLocalChecked();



        //context->Global()->Set(context, local_str(isolate, "require"), Require).FromJust();

        context->Global()->Set(context, local_str(isolate, "module"), module).FromJust();
        //--
        local_str_t source = v8::String::NewFromUtf8(isolate, code).ToLocalChecked();
        v8::MaybeLocal<v8::Script> maybe_script = v8::Script::Compile(context, source);
        if (maybe_script.IsEmpty()) {
            // Handle the error
            v8::Local<v8::Value> exception = try_catch.Exception();
            v8::String::Utf8Value exception_str(isolate, exception);
            std::cerr << *exception_str << std::endl;
            //isolate->ThrowException(v8::String::NewFromUtf8(isolate, "Script compilation failed"));
            return;
        }

        local_script_t script = maybe_script.ToLocalChecked();
        v8::MaybeLocal<v8::Value> maybe_result = script->Run(context);
        if (maybe_result.IsEmpty()) {
            // Handle the error
            //isolate->ThrowException(v8::String::NewFromUtf8(isolate, "Script execution failed"));
            v8::Local<v8::Value> exception = try_catch.Exception();
            v8::String::Utf8Value exception_str(isolate, exception);
            std::cerr << *exception_str << std::endl;
            //isolate->ThrowException(v8::String::NewFromUtf8(isolate, "Script execution failed"));
            return;
        }

        module_cache[*str].Reset(isolate, context);
    }

    local_ctx_t context = local_ctx_t::New(isolate, module_cache[*str]);
    local_obj_t module = context->Global()->Get(context, v8::String::NewFromUtf8(isolate, "module").ToLocalChecked()).ToLocalChecked().As<v8::Object>();
    local_val_t result = module->Get(context, v8::String::NewFromUtf8(isolate, "exports").ToLocalChecked()).ToLocalChecked();
    args.GetReturnValue().Set(result);
}

std::string appendExtensionIfNeeded(const char* filename) {
    std::string str(filename);

    // Check if the filename has an extension
    size_t pos = str.rfind(".");
    if (pos == std::string::npos || pos == 0 || str.substr(pos) != ".js" ) {
        // If the filename does not have an extension, append ".js"
        str += ".js";
    }

    return str;
}

/*****************************************************************************
 * char* load_module_script
 * Reads file contents to a null-terminated string.
 *****************************************************************************/
char* load_module_script(char filename[]) {

    std::string filename_extension = appendExtensionIfNeeded(filename);
    //path += filename;

    std::vector<std::string> directories = get_directories("v8");
    std::string path = file_exists_in_directories(filename_extension, directories);
    //std::cout << path << std::endl;

    // Opening file; ifstream::ate is use to determine file size
    std::ifstream file;
    file.open(path, std::ifstream::ate);
    char* contents;
    if (!file) {
        contents = new char[1];
        return contents;
    }

    // Get file size
    size_t file_size = file.tellg();

    // Return file pointer from end of the file (set by ifstream::ate) to beginning
    file.seekg(0);

    // Reading file to char array and returing it
    std::filebuf* file_buf = file.rdbuf();
    contents = new char[file_size + 1]();
    file_buf->sgetn(contents, file_size);
    file.close();
    return contents;
}

/*****************************************************************************
 * void print
 * Binding of simple console print function to the VM
 *****************************************************************************/
void print(const v8::FunctionCallbackInfo<v8::Value>& args) {

    // Getting arguments; error handling
    v8::Isolate* isolate = args.GetIsolate();
    v8::String::Utf8Value val(isolate, args[0]);
    if (*val == nullptr)
        isolate->ThrowException(
                v8::String::NewFromUtf8(isolate, "First argument of function is empty")
                        .ToLocalChecked());

    // Printing
    printf("%s\n", *val);
}

enum ScriptType : int {
    kScript,
    kModule,
    kFunction,
};

enum HostDefinedOptions : int {
    kType = 8,
    kID = 9,
    kLength = 10,
};



/*****************************************************************************
 * v8::MaybeLocal<v8::Module> loadModule
 * Loads module from code[] without checking it
 *****************************************************************************/
v8::MaybeLocal<v8::Module> loadModule(char code[],
                                      char name[],
                                      v8::Local<v8::Context> cx) {

    // Convert char[] to VM's string type
    v8::Local<v8::String> vcode =
            v8::String::NewFromUtf8(cx->GetIsolate(), code).ToLocalChecked();

    v8::Local<v8::PrimitiveArray> host_defined_options =
            v8::PrimitiveArray::New(cx->GetIsolate(), HostDefinedOptions::kLength);
    host_defined_options->Set(cx->GetIsolate(), HostDefinedOptions::kType,
                              v8::Number::New(cx->GetIsolate(), ScriptType::kModule));

    // Create script origin to determine if it is module or not.
    // Only first and last argument matters; other ones are default values.
    // First argument gives script name (useful in error messages), last
    // informs that it is a module.
    v8::ScriptOrigin origin(
            cx->GetIsolate(),
            v8::String::NewFromUtf8(cx->GetIsolate(), name).ToLocalChecked(),
            0,
            0,
            false,
            -1,
            v8::Local<v8::Value>(),
            false,
            false,
            true,
            host_defined_options);

    // Compiling module from source (code + origin)
    v8::Context::Scope context_scope(cx);
    v8::ScriptCompiler::Source source(vcode, origin);
    v8::MaybeLocal<v8::Module> mod;
    mod = v8::ScriptCompiler::CompileModule(cx->GetIsolate(), &source);

    // Returning non-checked module
    return mod;
}

/*****************************************************************************
 * v8::Local<v8::Module> checkModule
 * Checks out module (if it isn't nullptr/empty)
 *****************************************************************************/
v8::Local<v8::Module> checkModule(v8::MaybeLocal<v8::Module> maybeModule,
                                  v8::Local<v8::Context> cx) {

    // Checking out
    v8::Local<v8::Module> mod;
    if (!maybeModule.ToLocal(&mod)) {
        printf("Error loading module!\n");
        exit(EXIT_FAILURE);
    }

    // Instantianing (including checking out depedencies). It uses callResolve
    // as callback: check #
    v8::Maybe<bool> result = mod->InstantiateModule(cx,
                                                    reinterpret_cast<v8::Module::ResolveModuleCallback>(callResolve));
    if (result.IsNothing()) {
        printf("\nCan't instantiate module.\n");
        exit(EXIT_FAILURE);
    }

    // Returning check-out module
    return mod;
}

/*****************************************************************************
 * v8::Local<v8::Value> execModule
 * Executes module's code
 *****************************************************************************/
v8::Local<v8::Value> execModule(v8::Local<v8::Module> mod,
                                v8::Local<v8::Context> cx,
                                bool nsObject) {

    // Executing module with return value
    v8::Local<v8::Value> retValue;
    if (!mod->Evaluate(cx).ToLocal(&retValue)) {
        printf("Error evaluating module!\n");
        exit(EXIT_FAILURE);
    }

    // nsObject determins, if module namespace or return value has to be returned.
    // Module namespace is required during import callback; see lines # and #.
    if (nsObject)
        return mod->GetModuleNamespace();
    else
        return retValue;
}

/*****************************************************************************
 * v8::MaybeLocal<v8::Module> callResolve
 * Callback from static import.
 *****************************************************************************/
 v8::MaybeLocal<v8::Module> callResolve(v8::Local<v8::Context> context,
                                       v8::Local<v8::String> specifier,
                                       //v8::Local<v8::FixedArray> import_assertions,
                                       v8::Local<v8::Module> referrer) {

    // Get module name from specifier (given name in import args)
    v8::String::Utf8Value str(context->GetIsolate(), specifier);

    // Return unchecked module
    return loadModule(load_module_script(*str), *str, context);
}


/*****************************************************************************
 * v8::MaybeLocal<v8::Promise> callDynamic
 * Callback from dynamic import.
 *****************************************************************************/
v8::MaybeLocal<v8::Promise> callDynamic(v8::Local<v8::Context> context,
                                        v8::Local<v8::ScriptOrModule> referrer,
                                        v8::Local<v8::String> specifier) {

    // Promise resolver: that way promise for dynamic import can be rejected
    // or full-filed
    v8::Local<v8::Promise::Resolver> resolver =
            v8::Promise::Resolver::New(context).ToLocalChecked();
    v8::MaybeLocal<v8::Promise> promise(resolver->GetPromise());

    // Loading module (with checking)
    v8::String::Utf8Value name(context->GetIsolate(), specifier);
    v8::Local<v8::Module> mod =
            checkModule(loadModule(load_module_script(*name), *name, context), context);
    v8::Local<v8::Value> retValue = execModule(mod, context, true);

    // Resolving (fulfilling) promise with module global namespace
    resolver->Resolve(context, retValue);
    return promise;
}

/*****************************************************************************
 * void callMeta
 * Callback for module metadata.
 *****************************************************************************/
void callMeta(v8::Local<v8::Context> context,
              v8::Local<v8::Module> module,
              v8::Local<v8::Object> meta) {

    // In this example, this is throw-away function. But it shows that you can bind module's url. Here, placeholder is used.
    meta->Set(
            context,
            v8::String::NewFromUtf8(context->GetIsolate(), "url").ToLocalChecked(),
            v8::String::NewFromUtf8(context->GetIsolate(), "https://something.sh")
                    .ToLocalChecked());
}

static raia_config_t load_raia_config(const char *json_file_name) {
    joint_t *joint = joint_init_in_with_file(json_file_name);

    raia_config_t config;
    config.debug_mode = joint_get_in_bool(joint, "debug_mode");
    config.typescript_mode = joint_get_in_bool(joint, "typescript_mode");
    config.es2015_mode = joint_get_in_bool(joint, "es2015_mode");
    config.preprocess = joint_get_in_bool(joint, "preprocess");

    const char *startup_script = joint_get_in_str(joint, "startup_script");
    STRNCPY(config.startup_script, startup_script, sizeof(config.startup_script) - 1);
    config.startup_script[sizeof(config.startup_script) - 1] = '\0';

    const char *preprocess_script = joint_get_in_str(joint, "preprocess_script");
    STRNCPY(config.preprocess_script, preprocess_script, sizeof(config.preprocess_script) - 1);
    config.preprocess_script[sizeof(config.preprocess_script) - 1] = '\0';

    joint_free(joint);
    return config;
}

int raia_v8_main(int argc, char* argv[]) {

    v8::V8::InitializeICUDefaultLocation("v8/icudtl.dat");
    v8::V8::InitializeExternalStartupData("./");

    unique_ptr_platform_t platform = v8::platform::NewDefaultPlatform();
    v8_platform_init(platform.get());
    v8_init();
    v8::Isolate::CreateParams create_params;
    create_params.array_buffer_allocator = v8::ArrayBuffer::Allocator::NewDefaultAllocator();
    isolate_t *isolate = v8::Isolate::New(create_params);


    isolate->SetHostImportModuleDynamicallyCallback(
            reinterpret_cast<v8::HostImportModuleDynamicallyCallback>(callDynamic));
    isolate->SetHostInitializeImportMetaObjectCallback(callMeta);

    {
        //v8::Isolate::Scope isolate_scope(isolate);
        v8::HandleScope handle_scope(isolate);
        local_obj_tmp_t global = v8::ObjectTemplate::New(isolate);

        // グローバル関数の登録
        global->Set(isolate, "print", print_fn(isolate));
        global->Set(v8::String::NewFromUtf8(isolate, "require").ToLocalChecked(),
                    v8::FunctionTemplate::New(isolate, Require));

        local_ctx_t context = v8::Context::New(isolate, nullptr, global);
        v8::Context::Scope context_scope(context);

        set_local_fn_to_obj(isolate, context->Global(), "require", Require);

        local_obj_t Raia = v8::Object::New(isolate);
        set_local_obj(isolate, context->Global(), "__Raia__", Raia);


        raia_config_t config = load_raia_config("v8/config.json");

        local_arr_buf_t buffer = create_array_buffer(isolate);
        set_local_obj(isolate, Raia, "binaryData", buffer);
        local_str_t startup_script = v8::String::NewFromUtf8(isolate, config.startup_script).ToLocalChecked();
        set_local_obj(isolate, Raia, "startup_script", startup_script);

        // ローカル関数の登録
        set_local_fn_to_obj(isolate, Raia, "helloWorld", hello_world);
        set_local_fn_to_obj(isolate, Raia, "add", add);
        set_local_fn_to_obj(isolate, Raia, "printArrayBuffer", print_array_buffer);
        set_local_fn_to_obj(isolate, Raia, "createBinaryData", create_binary_data);



        local_obj_t Lib = v8::Object::New(isolate);
        set_local_obj(isolate, Raia, "Lib", Lib);
        set_local_fn_to_obj(isolate, Lib, "open", raia_lib_open);
        set_local_fn_to_obj(isolate, Lib, "close", raia_lib_close);
        set_local_fn_to_obj(isolate, Lib, "closeAll", raia_lib_close_all);
        set_local_fn_to_obj(isolate, Lib, "add", raia_lib_add);
        set_local_fn_to_obj(isolate, Lib, "call", raia_lib_call);


//        if (config.preprocess == 1) {
//            char *preprocess_script = file_load_string(config.preprocess_script);
//            {
//                local_str_t source_str = local_str(isolate, preprocess_script);
//                local_script_t script = local_script(context, source_str);
//                script->Run(context).ToLocalChecked();
//            }
//        }

        const char* source = R"(
            global = 100;
            print("preprocess");
        )";

        local_str_t source_str = local_str(isolate, source);
        local_script_t script = local_script(context, source_str);
        script->Run(context).ToLocalChecked();


        const char * src = LoadFile(config.startup_script).c_str();

        // Executing module
        v8::Local<v8::Module> mod = checkModule(loadModule((char *)src, config.startup_script, context), context);
        v8::Local<v8::Value> returned = execModule(mod, context);
        v8::String::Utf8Value val(isolate, returned);
        printf("Returned value: %s\n", *val);
    }

    //isolate->Dispose();
    v8::V8::Dispose();
    v8::V8::DisposePlatform();
    delete create_params.array_buffer_allocator;
    std::cout << "End" << std::endl;
    //printf("End2\n");
    return 0;
}

extern "C" RAIA_EXPORT char *init(int argc, char *argv[]) {
    init_entrust();
    init_plugin_hash();
    init_func_hash();
    raia_v8_main(argc, argv);

    if (get_is_entrust()) {
        joint_t *joint = joint_init_out();
        joint_add_out_str(joint, "script", (const char *)get_entrust_script());
        joint_add_out_bool(joint, "entrust", true);
        char *result = (char *)joint_out_write(joint);
        free_entrust();
        return result;
    }
    return nullptr;
}

//int main(int argc, char* argv[]) {
//    raia_v8_main(argc, argv);
//    return 0;
//}