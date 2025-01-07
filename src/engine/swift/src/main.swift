// main.swift

import Foundation

func main() {
    //let gameWindow = Game.Window3D(width: 800, height: 600, title: "3D Cube Example")
    //gameWindow.run {}
    let renderer2D = Game.Renderer2D(texWidth: 300, texHeight: 300)
    let window = Game.Window<Game.Renderer2D>(width: 300, height: 300, title: "2D Example", renderer: renderer2D)
    window.run {
        // 毎フレーム呼ばれる処理
    }
}

main()
