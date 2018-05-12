-- Additional functions
local int_serializeObject = serializeobject
local int_deserializeObject = deserializeobject
local int_gettimeofday = gettimeofday
serializeobject = nil
deserializeobject = nil
gettimeofday = nil


-- serialize an object into a base64 encoded string
-- return the serialized string
function SerializeObject(oObject)
    return int_serializeObject(oObject)
end

-- deserialize an object from a base64 encoded string
-- oOwner can be a creature, container or area
-- if oOwner is an Area, vPosition is a vector representign the position in wich deserialize the object 
-- return the Object deserialized, OBJECT_INVALID on any error
function DeserializeObject(sString, oOwner, vPosition)
    vPosition = vPosition or Vector()
    return int_deserializeObject(sString, oOwner, vPosition)
end

-- return the number of seconds with microseconds precision since the Epoch
-- useful for tracking running events
function GetTimeOfDay()
    local sec, usec = int_gettimeofday()
    return sec + (usec / 1000000)
end

-- implements tostring(vVector) or vVector:tostring()
nwn_vector.__tostring = function(vVector)
    return string.format("%.4f;%.4f;%.4f", vVector:components())
end

-- vVector:x()
nwn_vector.x = function(vVector)
    local x, y, z = vVector:components()
    return x
end

--vVector:y()
nwn_vector.y = function(vVector)
    local x, y, z = vVector:components()
    return y
end

--vVector:z()
nwn_vector.z = function(vVector)
    local x, y, z = vVector:components()
    return z
end

-- implements tostring(lLocation) or lLocation:tostring()
nwn_location.__tostring = function(lLoc)
  local a, x, y, z, f = lLoc:components()
  if a == 0  or not GetIsObjectValid(a) then return "" end
  return string.format("%s;%.4f;%.4f;%.4f;%.4f", GetTag(a), x, y, z, f)  
end

-- boolean functions
function GetLocalBool(oObject, sName)
  return GetLocalInt(oObject, sName) > 0
end

function SetLocalBool(oObject, sName, bCond)
  bCond = bCond and 1 or 0
  SetLocalInt(oObject, sName, bCond) 
end

function DeleteLocalBool(oObject, sName)
  DeleteLocalInt(oObject, sName)
end

-- string functions
function string.eval(sString, ...)
  sString = string.format(sString, ...)
  local status, msg  = pcall(loadstring(sString))
  return status, msg
end

function string:split(sep)
  local sep, fields = sep or " ", {}
  local pattern = string.format("([^%s]+)", sep)
  self:gsub(pattern, function(c) fields[#fields+1] = c end)
  return fields
end

function string:color(nRed, nGreen, nBlue)
  return string.format("<c%c%c%c>%s</c>", nRed, nGreen, nBlue, self)
end

function string:blue()    return self:color(102, 204, 254) end -- used by saving throws.
function string:dblue()   return self:color( 32, 102, 254) end -- used for electric damage.
function string:gray()    return self:color(153, 153, 153) end -- used for negative damage.
function string:green()   return self:color( 32, 254,  32) end -- used for acid damage.
function string:lblue()   return self:color(153, 254, 254) end -- used for the player's name, and cold damage.
function string:lgray()   return self:color(176, 176, 176) end -- used for system messages.
function string:lorange() return self:color(254, 153,  32) end -- used for sonic damage.
function string:lpurple() return self:color(204, 153, 204) end -- used for a target's name.
function string:orange()  return self:color(254, 102,  32) end -- used for attack rolls and physical damage.
function string:purple()  return self:color(204, 119, 254) end -- used for spell casts, as well as magic damage.
function string:red()     return self:color(254,  32,  32) end -- used for fire damage.
function string:white()   return self:color(254, 254, 254) end -- used for positive damage.
function string:yellow()  return self:color(254, 254,  32) end -- used for healing, and sent messages.

-- implements sString:tovector
function string:tovector()
  local t = self:split(";")
  if #t < 3 then return Vector() end
  return Vector(tonumber(t[1]),tonumber(t[2]),tonumber(t[3]))
end

-- implements sString:tolocation
function string:tolocation()
  local t = self:split(";")
  if #t < 5 then return false end
  local a, x, y, z, f = GetObjectByTag(t[1], 0), tonumber(t[2]),tonumber(t[3]),tonumber(t[4]),tonumber(t[5])
  if not GetIsObjectValid(a) then return false end
  return Location(a, Vector(x,y,z), f)
end

