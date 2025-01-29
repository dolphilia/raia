// main.swift

import Foundation

let cm = Skia.ColorMatrix()

//

let bitmap = Skia.Bitmap()
bitmap.allocN32Pixels(width: 300, height: 300, isOpaque: false)
let canvas = Skia.Canvas(bitmap: bitmap)
let paint = Skia.Paint()
paint.setColor(color: 0xFFFF0000)
let rect = Skia.Rect.MakeXYWH(x: 0, y: 0, w: 300, h: 300)
canvas.drawRect(rect: rect, paint: paint)

let pixels = bitmap.getPixels()

func main() {
    let renderer = Game.Renderer2D(texWidth: 300, texHeight: 300)
    let window = Game.Window<Game.Renderer2D>(width: 300, height: 300, title: "RandomNoise", renderer: renderer)
    
    //let pixelCount = 300 * 300 * 4
    //let pixels = UnsafeMutablePointer<UInt8>.allocate(capacity: pixelCount)
    window.run {
        //for i in 0..<pixelCount {
        //  pixels[i] = UInt8.random(in: 0...255)
        //}
        renderer.setPixels(pixels: pixels)
    }
}

main()
