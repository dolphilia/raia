// main.swift

import Foundation
import Darwin

/// 現在のプロセスのメモリ使用量（resident size: バイト単位）を取得する関数
func getMemoryUsageMB() -> Double? {
    var info = mach_task_basic_info()
    var count = mach_msg_type_number_t(MemoryLayout<mach_task_basic_info>.size / MemoryLayout<natural_t>.size)
    
    let kerr: kern_return_t = withUnsafeMutablePointer(to: &info) { infoPtr in
        infoPtr.withMemoryRebound(to: integer_t.self, capacity: Int(count)) { intPtr in
            task_info(mach_task_self_, task_flavor_t(MACH_TASK_BASIC_INFO), intPtr, &count)
        }
    }
    
    if kerr == KERN_SUCCESS {
        // バイト単位をMB（メガバイト）単位に変換
        let memoryUsageMB = Double(info.resident_size) / (1024 * 1024)
        // 小数点以下2桁で丸める
        return (memoryUsageMB * 10).rounded() / 10
    } else {
        let errorString = String(cString: mach_error_string(kerr))
        print("task_info error: \(errorString)")
        return nil
    }
}

let cm = Skia.ColorMatrix()

//




func main() {
    let renderer = Game.Renderer2D(texWidth: 300, texHeight: 300)
    let window = Game.Window<Game.Renderer2D>(width: 300, height: 300, title: "RandomNoise", renderer: renderer)
    
    
    


    //let pixelCount = 300 * 300 * 4
    //let pixels = UnsafeMutablePointer<UInt8>.allocate(capacity: pixelCount)
    //for i in 0..<pixelCount {
    //  pixels[i] = UInt8.random(in: 0...255)
    //}
    


    window.run {
        let bitmap = Skia.Bitmap()
        bitmap.allocN32Pixels(width: 300, height: 300, isOpaque: false)
        let canvas = Skia.Canvas(bitmap: bitmap)
        let paint = Skia.Paint()
        paint.setColor(color: 0xFFFF0000)
        if let memoryUsage = getMemoryUsageMB() {
            window.title = "use memory: \(memoryUsage) MB"
        } else {
            window.title = "メモリ使用量の取得に失敗"
        }
        
        
        
        let rect = Skia.SkRect.MakeXYWH(x: 0, y: 0, w: 300, h: 300)
        canvas.drawRect(rect: rect, paint: paint)
        let pixels = bitmap.getPixels()
        renderer.setPixels(pixels: pixels)

        let image = bitmap.asImage()
    }
}

main()
