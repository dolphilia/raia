-- Set

--[[

-- Setクラスのインスタンスを作成
local mySet = Set:new()

-- 要素の追加
mySet:add("apple")
mySet:add("banana")
mySet:add("cherry")

-- セットの内容を表示
print("Set contents:")
mySet:print()

-- 要素の存在確認
print("Contains 'banana'? ", mySet:contains("banana"))  -- 出力: true
print("Contains 'grape'? ", mySet:contains("grape"))    -- 出力: false

-- 要素の数を取得
print("Set size: ", mySet:size())  -- 出力: 3

-- 要素の削除
mySet:remove("banana")

-- セットの内容を再表示
print("Set contents after removal:")
mySet:print()

-- 要素の数を再取得
print("Set size after removal: ", mySet:size())  -- 出力: 2

-- イテレータを使用して要素を順に取得
print("Iterating over set elements:")
for element in mySet:iterator() do
    print(element)
end
]]

--[[
-- Setクラス定義
Set = {}
Set.__index = Set

-- コンストラクタ
function Set:new()
    local self = setmetatable({}, Set)
    self.elements = {}
    return self
end

-- 要素の追加
function Set:add(element)
    if not self.elements[element] then
        self.elements[element] = true
        table.insert(self.elements, element)
        table.sort(self.elements)  -- ソートして順序を保つ
    end
end

-- 要素の削除
function Set:remove(element)
    if self.elements[element] then
        self.elements[element] = nil
        for i, v in ipairs(self.elements) do
            if v == element then
                table.remove(self.elements, i)
                break
            end
        end
    end
end

-- 要素の存在確認
function Set:contains(element)
    return self.elements[element] ~= nil
end

-- 要素の数を取得
function Set:size()
    local count = 0
    for k, v in pairs(self.elements) do
        if type(k) ~= "number" then  -- 要素カウントにテーブルインデックスを含めない
            count = count + 1
        end
    end
    return count
end

-- セットの内容を表示
function Set:print()
    for i, element in ipairs(self.elements) do
        if type(element) ~= "table" then
            print(element)
        end
    end
end

-- イテレータの実装
function Set:iterator()
    local i = 0
    local n = #self.elements
    return function()
        i = i + 1
        if i <= n then
            return self.elements[i]
        end
    end
end
]]
--[[
-- Setクラス定義
Set = {}
Set.__index = Set

function Set:new()
    local self = setmetatable({}, Set)
    self.elements = {}
    return self
end

function Set:add(element)
    self.elements[element] = true
end

function Set:remove(element)
    self.elements[element] = nil
end

function Set:contains(element)
    return self.elements[element] ~= nil
end

function Set:size()
    local count = 0
    for _ in pairs(self.elements) do
        count = count + 1
    end
    return count
end

function Set:iterator()
    local keys = {}
    for key in pairs(self.elements) do
        table.insert(keys, key)
    end
    local i = 0
    return function()
        i = i + 1
        if i <= #keys then
            return keys[i]
        end
    end
end

function Set:__pairs()
    return self:iterator()
end
]]
-- Setクラス定義
-- Setクラス定義
Set = {}
Set.__index = Set

function Set:new()
    local self = setmetatable({}, Set)
    self.elements = {}
    return self
end

function Set:add(element)
    self.elements[element] = true
end

function Set:remove(element)
    self.elements[element] = nil
end

function Set:contains(element)
    return self.elements[element] ~= nil
end

function Set:size()
    local count = 0
    for _ in pairs(self.elements) do
        count = count + 1
    end
    return count
end

function Set:iterator()
    local keys = {}
    for key in pairs(self.elements) do
        table.insert(keys, key)
    end
    local i = 0
    return function()
        i = i + 1
        if i <= #keys then
            return keys[i]
        end
    end
end

function Set:__pairs()
    return self:iterator()
end


return Set