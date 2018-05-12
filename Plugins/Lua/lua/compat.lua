_LUA_VERSION = tonumber(string.sub(_VERSION, 5))

if _LUA_VERSION > 5.1 then
  loadstring = load
  unpack = table.unpack
  function math.log10(x)
    return math.log(x, 10)
  end
end

if _LUA_VERSION > 5.2 then
  function math.pow(x,y)
    return x^y
  end
end