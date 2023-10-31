//
// Created by dolphilia on 2023/07/23.
//

#include "wrapper_v8.h"

vec_str_t get_directories(const string_t &s) {
    vec_str_t r;
    r.push_back(s);
    for(auto& p : std::filesystem::recursive_directory_iterator(s)) {
        if (p.is_directory()) {
            r.push_back(p.path().string());
        }
    }
    return r;
}

string_t file_exists_in_directories(const string_t &filename, const vec_str_t &directories) {
    for (const auto& dir : directories) {
        std::filesystem::path filePath = dir;
        filePath /= filename;
        if (std::filesystem::exists(filePath)) {
            return filePath.string();
        }
    }
    printf("\nFile does not exist: %s\n", filename.c_str());
    exit(EXIT_FAILURE);
}

char* load_script(char filename[], const string_t& root_dir , bool is_startup) {
    ifstream_t file;
    file.open(filename, std::ifstream::ate);
    char* contents;
    if (!file) {
        contents = new char[1];
        return contents;
    }
    auto file_size = (size_t)file.tellg();
    file.seekg(0);
    auto *file_buf = file.rdbuf();
    contents = new char[file_size + 1]();
    file_buf->sgetn(contents, file_size);
    file.close();
    return contents;
}

ml_mod_t import_load(char code[], char name[], l_ctx_t context) {
    auto isolate = context->GetIsolate();
    auto v8code = v8::String::NewFromUtf8(isolate, code).ToLocalChecked();
    auto options = v8::PrimitiveArray::New(isolate, HostDefinedOptions::kLength);
    options->Set(isolate, HostDefinedOptions::kType, v8::Number::New(isolate, ScriptType::kModule));
    v8::ScriptOrigin origin(isolate, v8::String::NewFromUtf8(isolate, name).ToLocalChecked(), 0, 0, false, -1,
                            v8::Local<v8::Value>(), false, false, true, options);
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
    auto result = mod->InstantiateModule(context,  reinterpret_cast<v8::Module::ResolveModuleCallback>(import_static_callback));
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
    } else {
        return retValue;
    }
}

ml_mod_t import_static_callback(l_ctx_t context, l_str_t specifier, l_mod_t referrer) {
    auto str = v8::String::Utf8Value(context->GetIsolate(), specifier);
    auto filename_extension = std::string(*str) + ".js";
    auto directories = get_directories(get_raia_config().root_dir);
    auto path = file_exists_in_directories(filename_extension, directories);
    auto filepath = (char *) path.c_str();
    auto filename = (char *) path.c_str();
    auto new_filename = filename;
    auto code = load_script(filename, filepath, false);
    return import_load(code, (char *) new_filename, context);
}

ml_promise_t import_dynamic_callback(l_ctx_t context, l_som_t referrer, l_str_t specifier) {
    auto resolver = v8::Promise::Resolver::New(context).ToLocalChecked();
    auto promise = v8::MaybeLocal<v8::Promise>(resolver->GetPromise());
    auto name = v8::String::Utf8Value(context->GetIsolate(), specifier);
    auto filename_extension = std::string(*name) + ".js";
    auto directories = get_directories(get_raia_config().root_dir);
    auto path = file_exists_in_directories(filename_extension, directories);
    auto filepath = (char *) path.c_str();
    auto filename = (char *) path.c_str();
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