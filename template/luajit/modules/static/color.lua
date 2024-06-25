local Set = require("modules/utils/set")
local Map = require("modules/utils/map")

-- 静的変数の初期化
Color = {}
Color.availableKeys = Set:new()
Color.values = Map:new()
Color.index = 0

-- color_t構造体の定義
function Color.t(r, g, b, a)
    return {r = r, g = g, b = b, a = a}
end

-- 色を作成する関数
function Color.make(value)
    local key
    local it = Color.availableKeys:iterator()
    key = it()
    if key then
        Color.availableKeys:remove(key)
    else
        key = Color.index
        Color.index = Color.index + 1
    end
    Color.values:set(key, value)
    return key
end

-- 色を削除する関数
function Color.delete(key)
    Color.values:remove(key)
    Color.availableKeys:add(key)
end

-- 色を取得する関数
function Color.get(key)
    return Color.values:get(key)
end

-- 色を設定する関数
function Color.set(key, value)
    Color.values:set(key, value)
end

-- 特定の要素を変更する関数
function Color.update(key, element, value)
    local color = Color.values:get(key)
    if color then
        if color[element] ~= nil then
            color[element] = value
            Color.values:set(key, color)
        else
            error("Invalid element: " .. element)
        end
    else
        error("Invalid key: " .. key)
    end
end

return Color