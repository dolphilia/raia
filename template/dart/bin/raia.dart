//import 'package:raia/raia.dart' as raia;

// void main(List<String> arguments) {
//   print('Hello world: ${raia.calculate()}!');
// }

import 'modules/minilib.dart';
import 'modules/glfw.dart';
import 'dart:io';


void main() {
  var miniLib = MiniLib();
  int result = miniLib.plus(5, 3);
  print("Result: $result");

  var glfw = GLFW();
  glfw.init();
}
