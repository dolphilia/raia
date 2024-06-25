-- Map

--[[
-- Mapクラスのインスタンスを作成
local myMap = Map:new()

-- 要素の追加
myMap:set("apple", 1)
myMap:set("banana", 2)
myMap:set("cherry", 3)

-- マップの内容を表示
print("Map contents:")
myMap:print()

-- 要素の取得
print("Value for 'banana':", myMap:get("banana"))  -- 出力: 2

-- 要素の存在確認
print("Contains 'banana'? ", myMap:contains("banana"))  -- 出力: true
print("Contains 'grape'? ", myMap:contains("grape"))    -- 出力: false

-- 要素の数を取得
print("Map size: ", myMap:size())  -- 出力: 3

-- 要素の削除
myMap:remove("banana")

-- マップの内容を再表示
print("Map contents after removal:")
myMap:print()

-- 要素の数を再取得
print("Map size after removal: ", myMap:size())  -- 出力: 2

-- イテレータを使用して要素を順に取得
print("Iterating over map elements:")
for key, value in myMap:iterator() do
    print(key, value)
end

-- __pairsメタメソッドを使用してイテレート
print("Iterating using pairs:")
for key, value in pairs(myMap) do
    print(key, value)
end

-- __tostringメタメソッドを使用してマップを文字列として表示
print("Map as string: ", tostring(myMap))

-- __lenメタメソッドを使用してマップのサイズを取得
print("Map size using length operator: ", #myMap)
]]

--[[
-- Mapクラス定義
Map = {}
Map.__index = Map

-- コンストラクタ
function Map:new()
    local self = setmetatable({}, Map)
    self.elements = {}
    self.keys = {}
    return self
end

-- 要素の追加
function Map:set(key, value)
    if self.elements[key] == nil then
        table.insert(self.keys, key)
        table.sort(self.keys)
    end
    self.elements[key] = value
end

-- 要素の取得
function Map:get(key)
    return self.elements[key]
end

-- 要素の削除
function Map:remove(key)
    if self.elements[key] ~= nil then
        self.elements[key] = nil
        for i, k in ipairs(self.keys) do
            if k == key then
                table.remove(self.keys, i)
                break
            end
        end
    end
end

-- 要素の存在確認
function Map:contains(key)
    return self.elements[key] ~= nil
end

-- 要素の数を取得
function Map:size()
    return #self.keys
end

-- マップの内容を表示
function Map:print()
    for _, key in ipairs(self.keys) do
        print(key, self.elements[key])
    end
end

-- イテレータの実装
function Map:iterator()
    local i = 0
    local n = #self.keys
    return function()
        i = i + 1
        if i <= n then
            local key = self.keys[i]
            return key, self.elements[key]
        end
    end
end

-- __pairsメタメソッドの実装
function Map:__pairs()
    return self:iterator()
end

-- __tostringメタメソッドの実装
function Map:__tostring()
    local parts = {}
    for _, key in ipairs(self.keys) do
        table.insert(parts, tostring(key) .. ": " .. tostring(self.elements[key]))
    end
    return "{" .. table.concat(parts, ", ") .. "}"
end

-- __lenメタメソッドの実装
function Map:__len()
    return self:size()
end
]]
--[[
-- Mapクラス定義
Map = {}
Map.__index = Map

function Map:new()
    local self = setmetatable({}, Map)
    self.elements = {}
    return self
end

function Map:set(key, value)
    self.elements[key] = value
end

function Map:get(key)
    return self.elements[key]
end

function Map:remove(key)
    self.elements[key] = nil
end

function Map:contains(key)
    return self.elements[key] ~= nil
end

function Map:size()
    local count = 0
    for _ in pairs(self.elements) do
        count = count + 1
    end
    return count
end

function Map:iterator()
    local keys = {}
    for key in pairs(self.elements) do
        table.insert(keys, key)
    end
    local i = 0
    return function()
        i = i + 1
        if i <= #keys then
            local key = keys[i]
            return key, self.elements[key]
        end
    end
end

function Map:__pairs()
    return self:iterator()
end

function Map:__tostring()
    local parts = {}
    for key, value in pairs(self.elements) do
        table.insert(parts, tostring(key) .. ": " .. tostring(value))
    end
    return "{" .. table.concat(parts, ", ") .. "}"
end

function Map:__len()
    return self:size()
end
]]
-- Mapクラス定義
Map = {}
Map.__index = Map

function Map:new()
    local self = setmetatable({}, Map)
    self.elements = {}
    return self
end

function Map:set(key, value)
    self.elements[key] = value
end

function Map:get(key)
    return self.elements[key]
end

function Map:remove(key)
    self.elements[key] = nil
end

function Map:contains(key)
    return self.elements[key] ~= nil
end

function Map:size()
    local count = 0
    for _ in pairs(self.elements) do
        count = count + 1
    end
    return count
end

function Map:iterator()
    local keys = {}
    for key in pairs(self.elements) do
        table.insert(keys, key)
    end
    local i = 0
    return function()
        i = i + 1
        if i <= #keys then
            local key = keys[i]
            return key, self.elements[key]
        end
    end
end

function Map:__pairs()
    return next, self.elements, nil
end

function Map:__tostring()
    local parts = {}
    for key, value in pairs(self.elements) do
        table.insert(parts, tostring(key) .. ": " .. tostring(value))
    end
    return "{" .. table.concat(parts, ", ") .. "}"
end

function Map:__len()
    return self:size()
end



return Map