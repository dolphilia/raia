//
// raia_v8
//

#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>
#include <unordered_map>
#include "libplatform/libplatform.h"
#include "v8.h"
#include "v8-initialization.h"
#include "v8-function.h"
#include "v8-exception.h"
#include "v8-script.h"
#include "raia_v8.h"
#include "wrapper/wrapper_v8.h"

#ifdef _WIN32
#include "v8config.h"
#undef V8_ENABLE_POINTER_COMPRESSION
#endif

#ifdef __WINDOWS__
#define RAIA_EXPORT __declspec(dllexport)
#else
#define RAIA_EXPORT
#endif

//-- static

std::unordered_map<std::string, v8::Global<v8::Context>> module_cache; // for Require

//-- register function

void raia_lib_open(const fci_val_t &args) {
    auto v8_str = v8::String::Utf8Value(args.GetIsolate(), args[0]);
    auto dll_file = std::string(*v8_str);
#ifdef __WINDOWS__
    const char * extension = "dll";
#endif
#ifdef __MACOS__
    const char * extension = "dylib";
#endif
#ifdef __LINUX__
    const char * extension = "so";
#endif
    auto dll_file_extension = dll_file + "." + extension;
    auto handle = add_plugin_hash(dll_file_extension.c_str());
    auto result = (double)(uintptr_t)handle;
    args.GetReturnValue().Set(v8::Number::New(args.GetIsolate(), result));
}

void raia_lib_close(const fci_val_t &args) {
    auto v8_str = v8::String::Utf8Value(args.GetIsolate(), args[0]);
    auto cpp_str = std::string (*v8_str);
    auto name = cpp_str.c_str();
    delete_plugin_hash(name);
}

void raia_lib_close_all(const fci_val_t &args) {
    free_plugin_hash();
}

void raia_lib_add(const fci_val_t &args) {
    auto handle = (void *)(uintptr_t)args[0].As<v8::Number>()->Value();
    auto v8_str = v8::String::Utf8Value(args.GetIsolate(), args[1]);
    auto cpp_str = std::string(*v8_str);
    auto dll_func_name = cpp_str.c_str();
    add_plugin_func_hash(handle, dll_func_name);
}

void raia_lib_call(const fci_val_t &args) {
    auto isolate = args.GetIsolate();
    auto cpp_dll_func_name = new_str_from_val(isolate, args[0]);//cpp_str(*v8_str);
    auto dll_func_name = cpp_dll_func_name.c_str();
    auto cpp_src = new_str_from_val(isolate, args[1]);
    auto src = cpp_src.c_str();
    auto dest = call_func_hash(dll_func_name, src);
    if (dest == nullptr) {
        args.GetReturnValue().SetNull();
    } else {
        args.GetReturnValue().Set(v8::String::NewFromUtf8(isolate, dest).ToLocalChecked());
        delete dest;
        //free((void *)dest);
    }
}

void raia_io_load_script(const fci_val_t &args) {
    auto filename = new_str_from_val(args.GetIsolate(), args[0]);
    auto ifs = std::ifstream(filename);
    auto str = std::string((std::istreambuf_iterator<char>(ifs)), std::istreambuf_iterator<char>());
    args.GetReturnValue().Set(v8::String::NewFromUtf8(args.GetIsolate(), str.c_str()).ToLocalChecked());
}

void raia_io_save_script(const fci_val_t &args) {
    auto filename = new_str_from_val(args.GetIsolate(), args[0]);
    auto code = new_str_from_val(args.GetIsolate(), args[1]);
    std::ofstream outFile(filename);
    if (!outFile) {
        args.GetReturnValue().Set(false);
        return;
    }
    outFile << code;
    args.GetReturnValue().Set(true);
    outFile.close();
}

void raia_print(const fci_val_t &args) {
    auto message = new_str_from_val(args.GetIsolate(), args[0]);
    std::cout << message << std::endl;
}

void raia_exit(const fci_val_t &args) {
    auto local_number = args[0].As<v8::Number>();
    auto number = local_number->Value();
    exit((int)number);
}

void raia_core_buf_to_ptr(const fci_val_t &args) {
    auto buffer = args[0].As<v8::ArrayBuffer>();
    auto backing_store = buffer->GetBackingStore();
    char* data = static_cast<char*>(backing_store->Data());
    args.GetReturnValue().Set((double)(uintptr_t)data);
}

void raia_core_ptr_to_buf(const fci_val_t &args) {
    auto number = args[0].As<v8::Number>()->Value();
    auto data = (void *)(uintptr_t)number;
    auto size = args[1].As<v8::Integer>()->Value();
    auto array_buffer = v8::ArrayBuffer::New(args.GetIsolate(), size);
    memcpy(array_buffer->Data(), data, size);
    args.GetReturnValue().Set(array_buffer);
}

//-- module

void raia_require(const fci_val_t& args) {
    auto isolate = args.GetIsolate();
    auto try_catch = v8::TryCatch(isolate);
    auto str = v8::String::Utf8Value(isolate, args[0]);
    auto filename_extension = append_extension(*str, get_raia_config().ts_mode);
    auto directories = get_directories(get_raia_config().root_dir);
    auto path = file_exists_in_directories(filename_extension, directories);
    auto filepath = (char *)path.c_str();
    auto filename = (char *)path.c_str();
    char *code = load_script(filename, filepath, false);

    if (module_cache.find(*str) == module_cache.end()) {
        auto mod_tmp = v8::ObjectTemplate::New(isolate);
        mod_tmp->Set(new_local_str(isolate, "exports"), v8::ObjectTemplate::New(isolate));
        mod_tmp->Set(v8::String::NewFromUtf8(isolate, "require").ToLocalChecked(), v8::FunctionTemplate::New(isolate, raia_require));

        auto context = v8::Context::New(isolate, nullptr, mod_tmp);
        set_module_obj(context, mod_tmp, context->Global(), "module");

        auto Raia = set_module_obj(context, mod_tmp, context->Global(), "Raia");
        auto Core = set_module_obj(context, mod_tmp, Raia, "Core");
        set_module_fn(context, Core, "print", raia_print);
        set_module_fn(context, Core, "exit", raia_exit);
        set_module_fn(context, Core, "pointerToArrayBuffer", raia_core_ptr_to_buf);
        set_module_fn(context, Core, "arrayBufferToPointer", raia_core_buf_to_ptr);

        auto Lib = set_module_obj(context, mod_tmp, Raia, "Lib");
        set_module_fn(context, Lib, "open", raia_lib_open);
        set_module_fn(context, Lib, "close", raia_lib_close);
        set_module_fn(context, Lib, "closeAll", raia_lib_close_all);
        set_module_fn(context, Lib, "add", raia_lib_add);
        set_module_fn(context, Lib, "call", raia_lib_call);

        auto source = v8::String::NewFromUtf8(isolate, code).ToLocalChecked();
        v8::MaybeLocal<v8::Script> maybe_script = v8::Script::Compile(context, source);
        if (maybe_script.IsEmpty()) {
            auto exception = try_catch.Exception();
            auto exception_str = v8::String::Utf8Value(isolate, exception);
            std::cerr << *exception_str << std::endl;
            return;
        }
        auto script = maybe_script.ToLocalChecked();
        auto maybe_result = script->Run(context);
        if (maybe_result.IsEmpty()) {
            auto exception = try_catch.Exception();
            auto exception_str = v8::String::Utf8Value(isolate, exception);
            std::cerr << *exception_str << std::endl;
            return;
        }
        module_cache[*str].Reset(isolate, context);
    }
    auto context = v8::Local<v8::Context>::New(isolate, module_cache[*str]);
    auto module = context->Global()->Get(context, v8::String::NewFromUtf8(isolate, "module").ToLocalChecked()).ToLocalChecked().As<v8::Object>();
    auto result = module->Get(context, v8::String::NewFromUtf8(isolate, "exports").ToLocalChecked()).ToLocalChecked();
    args.GetReturnValue().Set(result);
}

ml_mod_t import_load(char code[], char name[], l_ctx_t context) {
    auto isolate = context->GetIsolate();
    auto v8code = v8::String::NewFromUtf8(isolate, code).ToLocalChecked();
    auto options = v8::PrimitiveArray::New(isolate, HostDefinedOptions::kLength);
    options->Set(isolate, HostDefinedOptions::kType, v8::Number::New(isolate, ScriptType::kModule));
    v8::ScriptOrigin origin( isolate, v8::String::NewFromUtf8(isolate, name).ToLocalChecked(), 0, 0, false, -1, v8::Local<v8::Value>(), false, false, true, options);
    auto context_scope = v8::Context::Scope(context);
    auto source = v8::ScriptCompiler::Source(v8code, origin);
    auto mod = v8::ScriptCompiler::CompileModule(isolate, &source);
    return mod;
}

l_mod_t import_check(ml_mod_t maybeModule, l_ctx_t context) {
    l_mod_t mod;
    if (!maybeModule.ToLocal(&mod)) {
        printf("Error loading module!\n");
        exit(EXIT_FAILURE);
    }
    auto result = mod->InstantiateModule(context, reinterpret_cast<v8::Module::ResolveModuleCallback>(import_static_callback));
    if (result.IsNothing()) {
        printf("\nCan't instantiate module.\n");
        exit(EXIT_FAILURE);
    }
    return mod;
}

l_val_t import_exec(l_mod_t mod, l_ctx_t context, bool nsObject) {
    auto isolate = context->GetIsolate();
    auto try_catch = v8::TryCatch(isolate);
    auto maybe_result = mod->Evaluate(context);
    auto retValue = v8::Local<v8::Value>();
    if (maybe_result.IsEmpty()) {
        auto error = v8::String::Utf8Value(isolate, try_catch.Exception());
        auto message = try_catch.Message();
        if (!message.IsEmpty()) {
            auto filename = v8::String::Utf8Value(isolate, message->GetScriptOrigin().ResourceName());
            auto msg = v8::String::Utf8Value(isolate, message->Get());
            fprintf(stderr, "%s:%d: %s\n", *filename, message->GetLineNumber(context).FromJust(), *msg);
        } else {
            fprintf(stderr, "%s\n", *error);
        }
    } else {
        retValue = maybe_result.ToLocalChecked();
    }
    if (nsObject) {
        return mod->GetModuleNamespace();
    }
    else {
        return retValue;
    }
}

ml_mod_t import_static_callback(l_ctx_t context, l_str_t specifier, l_mod_t referrer) {
    std::string filename_extension;
    std::vector<std::string> directories;
    std::string path;
    std::string std_code;
    char * filepath;
    char * filename;
    char * code;
    std::string new_filename;

    auto str = v8::String::Utf8Value(context->GetIsolate(), specifier);

    filename_extension = append_extension(*str, get_raia_config().ts_mode);
    directories = get_directories(get_raia_config().root_dir);
    path = file_exists_in_directories(filename_extension, directories);
    filepath = (char *)path.c_str();
    filename = (char *)path.c_str();

    if (get_raia_config().ts_mode) {
        auto source = "var typescript_source = __Raia__.IO.loadScript('" + path +"');";
        source += "typescript_transpile(typescript_source);";
        auto source_str = local_str(context->GetIsolate(), source.c_str());
        auto script = local_script(context, source_str);
        auto result = script->Run(context).ToLocalChecked();
        v8::String::Utf8Value utf8(context->GetIsolate(), result);
        std_code = std::string(*utf8);
        new_filename = replace_extension(path, ".js");
        write_script(new_filename, std_code);
        code = (char *)std_code.c_str();//load_script((char *)std_code.c_str(), config.root_dir, true);
    } else {
        new_filename = filename;
        code = load_script(filename, filepath, false);
    }

    return import_load(code, (char *)new_filename.c_str(), context);
}

ml_promise_t import_dynamic_callback(l_ctx_t context, l_som_t referrer, l_str_t specifier) {
    auto resolver = v8::Promise::Resolver::New(context).ToLocalChecked();
    auto promise = v8::MaybeLocal<v8::Promise>(resolver->GetPromise());
    auto name = v8::String::Utf8Value(context->GetIsolate(), specifier);
    auto filename_extension = append_extension(*name, get_raia_config().ts_mode);
    auto directories = get_directories(get_raia_config().root_dir);
    auto path = file_exists_in_directories(filename_extension, directories);
    auto filepath = (char *)path.c_str();
    auto filename = (char *)path.c_str();
    char *code = load_script(filename, filepath, false);
    auto ml_mod = import_load(code, *name, context);
    auto mod = import_check(ml_mod, context);
    auto retValue = import_exec(mod, context, true);
    resolver->Resolve(context, retValue);
    return promise;
}

void import_meta(v8::Local<v8::Context> context, v8::Local<v8::Module> module, v8::Local<v8::Object> meta) {
    auto isolate = context->GetIsolate();
    auto key = v8::String::NewFromUtf8(isolate, "").ToLocalChecked();
    auto val = v8::String::NewFromUtf8(isolate, "").ToLocalChecked();
    meta->Set(context, key, val);
}

//-- main

int raia_v8_main(int argc, char* argv[]) {
    //v8::V8::InitializeICUDefaultLocation("v8/icudtl.dat");
    //v8::V8::InitializeExternalStartupData("./");
    v8::V8::InitializeICUDefaultLocation(argv[0]);
    v8::V8::InitializeExternalStartupData(argv[0]);

    auto platform = v8::platform::NewDefaultPlatform();
    v8::V8::InitializePlatform(platform.get());
    v8::V8::Initialize();
    isol_cp_t create_params;
    create_params.array_buffer_allocator = v8::ArrayBuffer::Allocator::NewDefaultAllocator();
    auto *isolate = v8::Isolate::New(create_params);

    isolate->SetHostImportModuleDynamicallyCallback(reinterpret_cast<v8::HostImportModuleDynamicallyCallback>(import_dynamic_callback));
    isolate->SetHostInitializeImportMetaObjectCallback(import_meta);



    {
        auto isolate_scope = v8::Isolate::Scope(isolate);
        auto handle_scope = v8::HandleScope(isolate);
        auto global = v8::ObjectTemplate::New(isolate);
        auto context = v8::Context::New(isolate, nullptr, global);
        auto context_scope = v8::Context::Scope(context);
        set_local_fn(isolate, context->Global(), "require", raia_require);
        auto Raia = set_new_local_obj(isolate, context->Global(), "__Raia__");
        auto Core = set_new_local_obj(isolate, Raia, "Core");
        set_local_fn(isolate, Core, "print", raia_print);
        set_local_fn(isolate, Core, "exit", raia_exit);
        set_local_fn(isolate, Core, "pointerToArrayBuffer", raia_core_ptr_to_buf);
        set_local_fn(isolate, Core, "arrayBufferToPointer", raia_core_buf_to_ptr);
        auto Lib = set_new_local_obj(isolate, Raia, "Lib");
        set_local_fn(isolate, Lib, "open", raia_lib_open);
        set_local_fn(isolate, Lib, "close", raia_lib_close);
        set_local_fn(isolate, Lib, "closeAll", raia_lib_close_all);
        set_local_fn(isolate, Lib, "add", raia_lib_add);
        set_local_fn(isolate, Lib, "call", raia_lib_call);
        auto IO = set_new_local_obj(isolate, Raia, "IO");
        set_local_fn(isolate, IO, "loadScript", raia_io_load_script);
        set_local_fn(isolate, IO, "saveScript", raia_io_save_script);

//        {
//            auto source = typescript();
//            auto source_str = local_str(isolate, source.c_str());
//            auto script = local_script(context, source_str);
//            script->Run(context).ToLocalChecked();
//        }

        init_raia_config("config.json");
        auto startup = get_raia_config().startup_script;
        auto filename_extension = append_extension(startup.c_str(), get_raia_config().ts_mode);
        auto directories = get_directories(get_raia_config().root_dir);
        auto path = file_exists_in_directories(filename_extension, directories);
        set_raia_config_startup_script(path);

        std::string std_code;
        std::string new_filename;
        char *code;

        if (get_raia_config().ts_mode) {
            auto source = "var typescript_source = __Raia__.IO.loadScript('" + path +"');";
            source += "typescript_transpile(typescript_source);";
            auto source_str = local_str(isolate, source.c_str());
            auto script = local_script(context, source_str);
            auto result = script->Run(context).ToLocalChecked();
            v8::String::Utf8Value utf8(isolate, result);
            std_code = std::string(*utf8);
            new_filename = replace_extension(path, ".js");
            write_script(new_filename, std_code);
            code = (char *)std_code.c_str();
        } else {
            new_filename = get_raia_config().startup_script;
            code = load_script((char *)get_raia_config().startup_script.c_str(), get_raia_config().root_dir, true);
        }
        auto ml_mod = import_load(code, (char *)new_filename.c_str(), context);
        auto mod = import_check(ml_mod, context);
        auto ret = import_exec(mod, context);
        auto ret_val = v8::String::Utf8Value(isolate, ret);
    }
    v8::V8::Dispose();
    v8::V8::DisposePlatform();
    delete create_params.array_buffer_allocator;
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

int main(int argc, char* argv[]) {
    init(argc, argv);
    return 0;
}