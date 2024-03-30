local ffi = require("ffi")

ffi.cdef[[
void raia_draw_noise_cpu(uint8_t *pixels, int width, int height, int depth);
void raia_draw_noise_gpu(uint8_t *pixels, int width, int height, int depth);
]]

local lib = ffi.load("raia_primitive")
local Primitive = {}

function Primitive.drawNoiseCPU(pixels, width, height, depth)
    lib.raia_draw_noise_cpu(pixels, width, height, depth)
end

function Primitive.drawNoiseGPU(pixels, width, height, depth)
    lib.raia_draw_noise_gpu(pixels, width, height, depth)
end

return Primitive