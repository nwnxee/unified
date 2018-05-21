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
	    Events::ArgumentStack OnEval(Events::ArgumentStack&& args);
	    Events::ArgumentStack OnEvalVoid(Events::ArgumentStack&& args);
	    Events::ArgumentStack OnEvent(Events::ArgumentStack&& args);
	    void OnToken(Types::ObjectID oid, char* token);	    
	private:
	    void SetObjectSelf();
	    int m_tokenFunction;
	    int m_eventFunction;
	    std::function<void(Types::ObjectID objSelf)> m_setObjSelfFunction;
	    Types::ObjectID m_object_self;
	};

}
