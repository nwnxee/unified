#pragma once

extern "C" {
    #include "quickjs.h"
    #include "quickjs-libc.h"
}

#include "nwnx.hpp"
#include "ajv_bundle_data.h" 

namespace Schema {

using json = nlohmann::json;
using ArgumentStack = NWNXLib::ArgumentStack;

class Schema : public NWNXLib::Plugin
{
public:
    Schema(NWNXLib::Services::ProxyServiceList* services);
    virtual ~Schema();

    // These must be static for the NWNX Event system to call them
    static ArgumentStack RegisterMetaSchema(ArgumentStack&& args);
    static ArgumentStack ValidateSchema(ArgumentStack&& args);
    static ArgumentStack ValidateInstance(ArgumentStack&& args);
    static ArgumentStack ValidateInstanceByID(ArgumentStack&& args);

    static ArgumentStack IsRegistered(ArgumentStack&& args);
    static ArgumentStack RemoveSchema(ArgumentStack&& args);
    static ArgumentStack ClearCache(ArgumentStack&& args);

private:
    static JSContext* GetContext();
    static json JSValueToJSON(JSValue val);

    static JSRuntime *global_rt;
    static JSContext *global_ctx;
};

} // namespace Schema
