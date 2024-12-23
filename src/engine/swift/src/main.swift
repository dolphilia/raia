// main.swift

import Foundation

_ = GLFW.Initializer.instance
let window = GLFW.Window(width: 800, height: 600, title: "GLFW Swift Window")

window.size = (width:300, height:300)

window.run { win in
    let size = win.size
    print("Window Size: \(size.width) x \(size.height)")
}
