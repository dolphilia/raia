// main.swift

import Foundation

let bitmap = SkBitmap_new()
SkBitmap_allocN32Pixels(bitmap, 300, 300, false)
let canvas = SkCanvas_new_3(bitmap)
let paint = SkPaint_new()

SkPaint_setColor(paint, 0xFFFF0000)
let rect = SkRect_MakeXYWH(0, 0, 300, 300)
SkCanvas_drawRect(canvas, rect, paint)

let pixels = SkBitmap_getPixels(bitmap)?.assumingMemoryBound(to: UInt8.self)

//print(bitmap)

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
