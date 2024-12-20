local Set = require("modules/utils/set")
local Map = require("modules/utils/map")

-- 静的変数の初期化
Window = {}
Window.availableKeys = Set:new()
Window.values = Map:new()
Window.index = 0

-- 構造体の定義
function window_info_t(r, g, b, a)
    return {
        r = r,
        g = g,
        b = b,
        a = a
    }
end

function Window.make(value)
    local key
    local it = Window.availableKeys:iterator()
    key = it()
    if key then
        Window.availableKeys:remove(key)
    else
        key = Window.index
        Window.index = Window.index + 1
    end
    Window.values:set(key, value)
    return key
end

function Window.delete(key)
    Window.values:remove(key)
    Window.availableKeys:add(key)
end

function Window.get(key)
    return Window.values:get(key)
end

function Window.set(key, value)
    Window.values:set(key, value)
end

function Window.update(key, element, value)
    local window = Window.values:get(key)
    if window then
        if window[element] ~= nil then
            window[element] = value
            Window.values:set(key, window)
        else
            error("Invalid element: " .. element)
        end
    else
        error("Invalid key: " .. key)
    end
end

return Window