import 'dart:io';
import 'dart:ffi' as ffi;

typedef SharedLibrary = ffi.DynamicLibrary;

class Lib {
  static String getCurrentPath() {
    Uri scriptUri = Platform.script; // 現在のスクリプトのURIを取得
    String scriptPath = scriptUri.toFilePath(); // ファイルシステム上のパスに変換（`toFilePath`は`file:`スキームのURIにのみ使用可能）
    String directoryPath = File(scriptPath).parent.path; // ディレクトリのパスを取得
    return directoryPath;
  }

  // 現在のOSを判別して、共有ライブラリの拡張子を返す
  static String getCurLibExt() {
    String libext = "";
    if (Platform.isWindows) {
      libext = "dll";
    } else if (Platform.isMacOS) {
      libext = "dylib";
    } else if (Platform.isLinux) {
      libext = "so";
    } else {
      stderr.writeln('エラーが発生しました');
      exit(1);
    }
    return libext;
  }

  static SharedLibrary open(String path) {
    String curDir = getCurrentPath();
    String libExt = getCurLibExt();
    return ffi.DynamicLibrary.open("$curDir/$path.$libExt");
  }
}