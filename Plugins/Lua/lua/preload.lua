--USER_DIR is already defined by the plugin as the user directory
package.path = USER_DIR.."/lua/?.lua;"..USER_DIR.."/lua/libs/?.lua;"..package.path

require "compat"
require "nwn"
require "additions"
require "iterators"

-- GLOBALS
-- start values for globals
oModule = 0x0
OBJECT_INVALID = 0x7F000000
OBJECT_SELF = 0x7F000000

-- optional function
--function SetObjectSelf(oid)
--  OBJECT_SELF = NWObject.new(oid)
--end

--add you scripts here to load them on module load
local scripts = {               
                'systems.chat'
                }

-- loading functions
function loadscript(sScript)
  -- forcing reloading
  package.loaded[sScript] = nil
  require(sScript)
end

-- re-load all scripts
function loadscripts()
  for _, v in ipairs(scripts) do 
    loadscript(v) 
  end
end


-- EVENT FRAMEWORK
local Events={}

-- Add an event listener for a Module
-- Mod its the name of the module adding callback listener
-- event is the name of the event, you can add more listeners to the same event but they have to come from different Modules.
-- callback is a function accepting an object and an extra optional string parameter,
-- priority is a number, lower comes first.
function AddEvent(Mod, event, callback, priority)
  priority = priority or 10
  if not Events[event] then Events[event] = {} end
  local r = {modl = Mod, callback = callback, priority = priority}
  table.insert(Events[event], r)
  table.sort(Events[event], function(a,b) return (a.priority < b.priority) end)  
end

-- remove all listeners for a Module
function RemoveEvents(Mod)
  for k,v in pairs(Events) do
    if (type(v) == 'table') then
      for i,n in ipairs(v) do if (n['modl'] == Mod) then table.remove(Events[k], i) end end
    end
  end
end

-- run event callback from inside nwn script
function RunEvent(event, object, extra)
  local ev = Events[event]  
  if (type(ev) ~= 'table') then 
    return 
  end
  for i,v in ipairs(ev) do
    if (type(v['callback']) == 'function') then v['callback'](object, extra) end
  end
end

--Add the event that load scripts on module load
AddEvent('Events', 'mod_load', loadscripts, 1)


-- TOKEN FRAMEWORK, internal use
local Tokens = {current=0}

-- call token function, for AssignCommand, DelayCommand, ActionDoCommand 
function CallToken(sToken)
  if not sToken then
    return 
 end
  if Tokens[sToken] ~= nil then
    local f, a = Tokens[sToken]["f"], Tokens[sToken]["a"] 
    Tokens[sToken] = nil
    f(unpack(a))
  end
end

-- add a token 
function AddToken(action, ...)
  Tokens.current = Tokens.current + 1
  local scmd = tostring(Tokens.current)
  Tokens[scmd] = {f=action, a={...}, t=os.time()}
  return scmd
end

-- you can call this function sometimes to remove unused tokens,
-- shoud not be necessary
-- remove tokens olders than nSeconds, default 600
function FlushTokens(nSeconds)
  nSeconds = nSeconds or 600
  local i, n = 0, os.time()
  for k, v in pairs(Tokens) do
    if type(v) == "table" then
      if n > (Tokens[k]['t'] + nSeconds) then
        i = i + 1
        Tokens[k] = nil
      end
    end
  end
  return i
end

-- Example of a run script hook table, the basic definition must be present here in the preload
-- For how to use look at the RUNSCRIPT_TABLE env documentation
-- if you dont set the RUNSCRIPT_TABLE env to 'Scripts' you can delete this line
Scripts = {}

-- better to define the mod_load script hook function here in the preload
-- so it's already defined on module load
--[[
Scripts.mod_on_load = function()
  RunEvent('mod_load', GetModule())
end
]]