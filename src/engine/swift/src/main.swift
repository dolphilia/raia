// main.swift

import Foundation

func main() {
    let renderer = Game.Renderer2D(texWidth: 300, texHeight: 300)
    let window = Game.Window<Game.Renderer2D>(width: 300, height: 300, title: "2D Example", renderer: renderer)
    window.run {
        // 毎フレーム呼ばれる処理
        let pixelCount = 300 * 300 * 4
        let pixels = UnsafeMutablePointer<GLubyte>.allocate(capacity: pixelCount)
        //guard let px = pixels else { return }
        for i in 0..<pixelCount {
            pixels[i] = GLubyte.random(in: 0...255)
        }
        renderer.setPixels(pixels:pixels)
    }
}

main()
