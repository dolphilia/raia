// preprocess.js
//
// This script file is for pre-processing the programme before running it. Do not modify or delete it.
// このスクリプトファイルはプログラムを実行する前に事前処理をするためのものです。変更したり削除したりしないでください。

var raia_preprocess_handle = __Raia__.Core.Lib.open("raia_file");
__Raia__.Core.Lib.add(raia_preprocess_handle, "raia_file_exist");
__Raia__.Core.Lib.add(raia_preprocess_handle, "raia_file_get_dirs");
__Raia__.Core.Lib.add(raia_preprocess_handle, "raia_file_get_cur_path");
__Raia__.Core.Lib.add(raia_preprocess_handle, "raia_file_load_string");
__Raia__.Core.Lib.add(raia_preprocess_handle, "raia_file_save_string");

__Raia__.allDirs = undefined; // 実行ファイルがあるディレクトリ内の子ディレクトリを含むすべてのディレクトリ
__Raia__.babel = undefined; // babelオブジェクト

(function () {
    var getDirs = function(path) {
        return JSON.parse(__Raia__.Core.Lib.call("raia_file_get_dirs", JSON.stringify({"path": path, "@return": "string"}))).result;
    };
    var getAllDirs = function(path) {
        var allDirs = [];
        var dirs = getDirs(path);
        dirs.forEach(function(directory) {
            var fullPath = path + '/' + directory;
            allDirs.push(fullPath);
            var childDirs = getAllDirs(fullPath);
            allDirs = allDirs.concat(childDirs);
        });
        return allDirs;
    };
    var getCurPath = function() {
        return JSON.parse(__Raia__.Core.Lib.call("raia_file_get_cur_path", JSON.stringify({"@return": "string"}))).result;
    };
    __Raia__.allDirs = getAllDirs(getCurPath());
    __Raia__.allDirs.unshift('.');
    __Raia__.allDirs.unshift(getCurPath());
}());

Duktape.modSearch = function (path, require, exports, module) {
    var replaceLast = function(str, search, replacement) {
        var lastIndex = str.lastIndexOf(search);
        if (lastIndex === -1) {
            return str;
        }
        return str.slice(0, lastIndex) + replacement + str.slice(lastIndex + search.length);
    }
    var exist = function(path) {
        return JSON.parse(__Raia__.Core.Lib.call("raia_file_exist", JSON.stringify({"path": path, "@return": "string"}))).result;
    };
    var loadString = function(path) {
        return JSON.parse(__Raia__.Core.Lib.call("raia_file_load_string", JSON.stringify({"path": path, "@return": "string"}))).result;
    };
    var saveString = function(path, data) {
        return JSON.parse(__Raia__.Core.Lib.call("raia_file_save_string", JSON.stringify({"path": path, "data": data, "@return": "string"}))).result;
    };
    // var exist = function(path) {
    //     return __Raia__.Core.File.exist(path);
    // }
    var ts = __Raia__.typescript_mode;
    var es6 = __Raia__.es2015_mode;
    var isCurrentModule = false;
    var checkPath = function(basePath) {
        if (exist(basePath) === 1) {
            return basePath;
        } else if (exist(basePath) === 2) {
            if (exist(basePath + '/index.ts') === 1 && ts === true ) {
                isCurrentModule = true;
                return basePath + '/index.ts';
            } else if (exist(basePath + '/index.es6') === 1 && es6 === true) {
                isCurrentModule = true;
                return basePath + '/index.es6';
            }
            return basePath + '/index.js';
        } else if (exist(basePath + '.ts') === 1 && ts === true) {
            isCurrentModule = true;
            return basePath + '.ts';
        } else if (exist(basePath + '.es6') === 1 && es6 === true) {
            isCurrentModule = true;
            return basePath + '.es6';
        } else if (exist(basePath + '.js') === 1) {
            return basePath + '.js';
        }
        return '';
    }
    var new_path = checkPath(path) || checkPath('modules/' + path);
    if (!new_path) {
        var dirs = __Raia__.allDirs;
        for (var i = 0; i < dirs.length; i++) {
            var basePath = dirs[i] + '/' + path;
            new_path = checkPath(basePath);
            if (new_path) break;
        }
    }
    var ret = loadString(new_path);
    if (typeof ret !== 'string') {
        throw new Error('module not found: ' + id);
    }
    if (ts === true && isCurrentModule === true && typeof __Raia__.typescript !== 'undefined') {
        var code = ret;
        var result = __Raia__.typescript.transpileModule(code, { compilerOptions: { target: __Raia__.typescript.ScriptTarget.ES5, module: __Raia__.typescript.ModuleKind.CommonJS }});
        var replaced_path = replaceLast(new_path, '.ts', '.js');
        var check = saveString(replaced_path, result.outputText);
        if (check !== true) {
            throw new Error('Failed to write file. File Name: ' + replaced_path);
        }
        ret = result.outputText;
    }
    if (es6 === true && isCurrentModule === true && typeof __Raia__.babel !== 'undefined') {
        var code = ret;
        var options = {presets: ['es2015']};
        var result = __Raia__.babel.transform(code, options, function(err, result) {
             return result.code;
        });
        var replaced_path = replaceLast(new_path, '.es6', '.js');
        var check = saveString(replaced_path, result.code);
        if (check !== true) {
            throw new Error('Failed to write file. File Name: ' + replaced_path);
        }
        ret = result.code;
    }
    return ret;
};

(function () {
    var getCurPath = function() {
        return JSON.parse(__Raia__.Core.Lib.call("raia_file_get_cur_path", JSON.stringify({"@return": "string"}))).result;
    };
    var loadString = function(path) {
        return JSON.parse(__Raia__.Core.Lib.call("raia_file_load_string", JSON.stringify({"path": path, "@return": "string"}))).result;
    };
    var saveString = function(path, data) {
        return JSON.parse(__Raia__.Core.Lib.call("raia_file_save_string", JSON.stringify({"path": path, "data": data, "@return": "string"}))).result;
    };
    var startup_script = __Raia__.startup_script.split('.').slice(0, -1).join('.');
    if (__Raia__.typescript_mode === true) {
        __Raia__.typescript = require('typescript'); // 3.9.10
        var ts = __Raia__.typescript;
        var source = loadString(getCurPath() + '/' + startup_script + '.ts');
        var result = ts.transpileModule(source, { compilerOptions: { target: ts.ScriptTarget.ES5, module: ts.ModuleKind.CommonJS }});
        var ret = saveString(getCurPath() + '/' + startup_script + '.js', result.outputText);
        if (ret !== true) {
            throw new Error('Failed to write file. File Name: ' + getCurPath() + '/' + startup_script + '.js');
        }
    } else if (__Raia__.es2015_mode === true) {
        __Raia__.babel = require('babel');
        var source = loadString(getCurPath() + '/' + startup_script + '.es6');
        var options = {presets: ['es2015']}; // or es2015, es2016, es2017, latest
        var result = __Raia__.babel.transform(source, options, function(err, result) {
            return result.code;
        });
        var ret = saveString(getCurPath() + '/' + startup_script + '.js', result.code);
        if (ret !== true) {
            throw new Error('Failed to write file. File Name: ' + getCurPath() + '/' + startup_script + '.js');
        }
    }
}());

// if (__Raia__.typescript_mode === true) {
//     var exports = {};
// }

var exports = {};