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
	    Lua(NWNXLib::Services::ProxyServiceList* services);
	    virtual ~Lua();
	    lua_State *m_luaInstance;
	    Events::ArgumentStack Eval(Events::ArgumentStack&& args);
	    Events::ArgumentStack EvalVoid(Events::ArgumentStack&& args);
	    Events::ArgumentStack RunEvent(Events::ArgumentStack&& args);
	    void OnToken(ObjectID oid, char* token);
	    bool OnScript(const char* scriptName, ObjectID objId, bool valid);
	private:
	    void SetObjectSelf(ObjectID objSelf = Constants::OBJECT_INVALID);
	    int m_tokenFunction;
	    int m_eventFunction;
	    int m_runScriptTable;
	    std::function<void(ObjectID objSelf)> m_setObjSelfFunction;
	    ObjectID m_object_self;
	};

}
