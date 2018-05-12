
local function eval_chat(sString, ...) 
	local status, msg = pcall(loadstring(string.format(sString, ...)))
	if status then
		msg = msg or "Command executed"
	else
		msg = msg or "Error parsing command"
	end
	return tostring(msg)
end

local on_chat = function (oPC)	
	local sMessage = GetPCChatMessage()
	if sMessage:sub(1 ,3) == "/c " then
		SetPCChatMessage("")
		sMessage = sMessage:sub(4)
		if sMessage:sub(1, 1) == "=" then
		  sMessage = "return "..sMessage:sub(2)
		end
		local sresult = eval_chat("local oPC = %d\n%s", oPC, sMessage)
		if sresult then SendMessageToPC(oPC, sresult ) end
	end
end

-- we remove events before in case we want to hot reload this script
RemoveEvents('Chat')
-- add the event listener, the on_chat function defined before (could be local!!)
AddEvent('Chat', 'mod_chat', on_chat, 1)