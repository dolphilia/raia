//
// Created by dolphilia on 2023/07/23.
//

#include "wrapper_v8.h"

//-- util function

l_str_t local_str(isol_t *isolate, const char *data) {
    return v8::String::NewFromUtf8(isolate, data, v8::NewStringType::kNormal).ToLocalChecked();
}

l_script_t local_script(l_ctx_t context, l_str_t str) {
    return v8::Script::Compile(context, str).ToLocalChecked();
}

std::string get_str_v8_fn_args(const fci_val_t &args, int num) {
    auto str = v8::String::Utf8Value(args.GetIsolate(), args[num]);
    auto cppStr = std::string(*str);
    return cppStr;
}

void set_int_v8_fn_ret(const fci_val_t &args, int result) {
    args.GetReturnValue().Set(v8::Integer::New(args.GetIsolate(), result));
}

void set_local_obj(isol_t *isolate, l_obj_t obj, const char *key, l_val_t value) {
    obj->Set(isolate->GetCurrentContext(), local_str(isolate, key), value).FromJust();
}

l_obj_t set_new_local_obj(isol_t *isolate, l_obj_t obj, const char *key) {
    auto local_obj = v8::Object::New(isolate);
    set_local_obj(isolate, obj, key, local_obj);
    return local_obj;
}

l_str_t new_local_str(isol_t *isolate, const char *data) {
    return v8::String::NewFromUtf8(isolate, "exports").ToLocalChecked();
}

l_fn_tmp_t new_fn_tmp(isol_t *isolate, fc_t callback = nullptr) {
    return v8::FunctionTemplate::New(isolate, callback);
}

l_fn_t new_local_fn(isol_t *isolate, fc_t callback = nullptr) {
    return v8::FunctionTemplate::New(isolate, callback)->GetFunction(isolate->GetCurrentContext()).ToLocalChecked();
}

ml_fn_t new_maybe_local_fn(l_ctx_t context, fc_t callback = nullptr) {
    auto ret = v8::FunctionTemplate::New(context->GetIsolate(), callback)->GetFunction(context);
    return ret;
}

void set_local_fn(isol_t *isolate, l_obj_t obj, const char *key, fc_t callback = nullptr) {
    auto fn = new_local_fn(isolate, callback);
    set_local_obj(isolate, obj, key, fn);
}

string_t new_str_from_val(isol_t *isolate, l_val_t val) {
    auto v8_str = v8::String::Utf8Value(isolate, val);
    auto cpp_str = std::string (*v8_str);
    return cpp_str;
}

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

//void get_directories(const std::string& dir, std::vector<std::string>& dirs) {
//    for(auto& p: std::filesystem::recursive_directory_iterator(dir)) {
//        if (p.is_directory())
//            dirs.push_back(p.path().string());
//    }
//}

std::string find_file_in_directories(const std::string& filename, const std::vector<std::string>& dirs) {
    for(const auto& dir : dirs) {
        for(const auto& p : std::filesystem::directory_iterator(dir)) {
            if(!std::filesystem::is_directory(p) && p.path().filename() == filename) {
                return p.path().string();
            }
        }
    }
    return "";
}

string_t append_extension(const char* filename, bool ts_mode) {
    auto str = std::string(filename);
    auto pos = str.rfind(".");
    if (ts_mode) {
        if (pos == std::string::npos || pos == 0 || str.substr(pos) != ".ts") {
            str += ".ts";
        }
    } else {
        if (pos == std::string::npos || pos == 0 || str.substr(pos) != ".js") {
            str += ".js";
        }
    }
    return str;
}

char* load_script(char filename[], const string_t& root_dir , bool is_startup) {
    //std::string cpp_str = filename;
    //char *path = filename;
    //std::string cpp_path;
    //if (is_startup) {
    //    path ;
    //} else {
    //    auto filename_extension = append_extension(filename);
    //    auto directories = get_directories(root_dir);
    //    cpp_path = find_file_in_directories(filename_extension, directories);
    //    path = (char *)cpp_path.c_str();
    //}
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

bool write_script(const std::string& filename, const std::string& code) {
    // ファイルを開く
    std::ofstream outFile(filename);
    if (!outFile) {
        return false;  // ファイルが開けない場合、エラーとしてfalseを返す
    }

    // 文字列をファイルに書き込む
    outFile << code;

    // ファイルを閉じる
    outFile.close();

    return true;  // 書き込み成功
}

std::string replace_extension(const std::string& filepath, const std::string& new_extension) {
    std::string::size_type i = filepath.rfind('.', filepath.length());

    if (i != std::string::npos) {
        // ファイルの拡張子を新しい拡張子に置き換える
        return(filepath.substr(0, i) + new_extension);
    }

    // '.'が見つからない場合、filepathをそのまま返す
    return filepath;
}

char* load_module_script(char filename[], const string_t& root_dir, bool is_startup, bool ts_mode) {
    auto filename_extension = append_extension(filename, ts_mode);
    auto directories = get_directories(root_dir);
    auto path = file_exists_in_directories(filename_extension, directories);
    return load_script((char *) path.c_str(),root_dir, is_startup);
}

void set_module_fn(l_ctx_t context, l_obj_t obj, const char *name, fc_t callback = nullptr) {
    auto local_fn = new_maybe_local_fn(context, callback).ToLocalChecked();
    obj->Set(context, local_str(context->GetIsolate(), name), local_fn).FromJust();
}

l_obj_t set_module_obj(l_ctx_t context, l_obj_tmp_t obj_tmp, l_obj_t obj, const char *name) {
    auto Core = obj_tmp->NewInstance(context).ToLocalChecked();
    obj->Set(context, local_str(context->GetIsolate(), name), Core).FromJust();
    return Core;
}