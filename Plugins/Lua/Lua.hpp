#pragma once

#include "Plugin.hpp"
#include "Services/Events/Events.hpp"
#include "API/Constants.hpp"
extern "C" {
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"
#ifdef NWNX_LUA_LUAJIT
#include "luajit.h"
#endif
}
#include "Lua_Functions.hpp"

namespace Lua {
	using namespace NWNXLib::Services;
	using namespace NWNXLib::API;
	class Lua : public NWNXLib::Plugin
	{
	public:
	    Lua(const Plugin::CreateParams& params);
	    virtual ~Lua();
	    lua_State *m_luaInstance;
	    Events::ArgumentStack Eval(Events::ArgumentStack&& args);
	    Events::ArgumentStack EvalVoid(Events::ArgumentStack&& args);
	    Events::ArgumentStack RunEvent(Events::ArgumentStack&& args);
	    void OnToken(Types::ObjectID oid, char* token);
	    bool OnScript(const char* scriptName, NWNXLib::API::Types::ObjectID objId, bool valid);
	private:
	    void SetObjectSelf(Types::ObjectID objSelf = Constants::OBJECT_INVALID);
	    int m_tokenFunction;
	    int m_eventFunction;
	    int m_runScriptTable;
	    std::function<void(Types::ObjectID objSelf)> m_setObjSelfFunction;
	    Types::ObjectID m_object_self;
	};

}
