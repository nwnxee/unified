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
	    Events::ArgumentStack OnToken(Events::ArgumentStack&& args);
	    Events::ArgumentStack OnEvent(Events::ArgumentStack&& args);
	private:
	    void SetObjectSelf();
	    std::string m_tokenFunction;
	    std::string m_eventFunction;
	    std::string m_setObjSelfFunction;
	    Types::ObjectID m_object_self;
	};

}
