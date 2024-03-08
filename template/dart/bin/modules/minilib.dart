import 'dart:ffi' as ffi;
import 'lib.dart';

class MiniLib {
  static var library = Lib.open("libminilib");
  static final plusFunc = library.lookupFunction<
      ffi.Int32 Function(ffi.Int32, ffi.Int32),
      int Function(int, int)
  >("plus");
    
  int plus(int a, int b) {
    return plusFunc(a, b);
  }
}