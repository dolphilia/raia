local skia = require("modules/bindings/skia")
local raia = require("modules/raia")

raia.window.setTitle("Hello")
raia.window.setMode(160, 90)
raia.window.center(160, 90)
raia.window.show()

-- Skia

local bitmap = skia.Bitmap.new();
skia.Bitmap.allocN32Pixels(bitmap, 160, 90, 0);
local canvas = skia.Canvas.new_3(bitmap);
local paint = skia.Paint.new();

skia.Paint.setColor(paint, 0xff00ffff);
local rect = skia.Rect.MakeXYWH(0, 0, 160, 90);
skia.Canvas.drawRect(canvas, rect, paint);

local pixels = skia.Bitmap.getPixels(bitmap);

--

while not raia.window.shouldClose() do
    raia.window.setPixels(pixels)
    raia.window.redraw()
end

os.exit()