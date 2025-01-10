// main.swift

import Foundation



func main() {
    let renderer = Game.Renderer2D(texWidth: 300, texHeight: 300)
    let window = Game.Window<Game.Renderer2D>(width: 300, height: 300, title: "RandomNoise", renderer: renderer)
    
    let pixelCount = 300 * 300 * 4
    let pixels = UnsafeMutablePointer<UInt8>.allocate(capacity: pixelCount)
    window.run {
        for i in 0..<pixelCount {
          pixels[i] = UInt8.random(in: 0...255)
        }
        //swift_generate_random_noise(pixels, Int32(pixelCount)) 
        renderer.setPixels(pixels:pixels)
    }
}

main()
