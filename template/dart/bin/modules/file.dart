import 'dart:ffi' as ffi;
import 'package:ffi/ffi.dart';
import 'lib.dart';

class File {
  static var library = Lib.open("raia_file");
  static final existFunc = library.lookupFunction<
      ffi.Void Function(ffi.Pointer<Utf8>),
      void Function(ffi.Pointer<Utf8>)
  >("raia_file_exist");
    
  void exist(String path) {
    existFunc(path.toNativeUtf8());
  }
}

