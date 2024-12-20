// main.swift

import Foundation

_ = GLFW.Initializer.instance
let window = GLFW.Window(width: 800, height: 600, title: "GLFW Swift Window")

window.run { win in
    let size = win.getFramebufferSize()
    print("Window Size: \(size.width) x \(size.height)")
}

//--

let result = add_numbers(3, 5)
print("3 + 5 = \(result)")
