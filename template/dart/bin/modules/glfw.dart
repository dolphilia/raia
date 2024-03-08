import 'dart:ffi' as ffi;
import 'lib.dart';

class GLFW {
  static var library = Lib.open("libglfw.3.4");
  static var initFunc = library.lookupFunction<
      ffi.Int32 Function(),
      int Function()
  >("glfwInit");

  int init() {
    return initFunc();
  }
}