# Services: Hooks

This service provides three mechanisms for hooking `nwserver` functions: Shared, Exclusive, and Chained, which is used depends on a plugin author's goals.  The usage examples below are fairly basic and contrived, so best to just look at how other plugins use these hooks.

**Notes**
* It's important to be mindful of how C++ deduces template parameters, namely it will default to pass-by-value.  If a hooked function isn't working or crashing the server, try specifing the exact types.

## Shared

Shared hooks allow multiple plugins to hook the same function without concern for plugin load order.  In general, if you only want to inspect or act on the the values passed into a function or it's return value **without** modification; or when the parameters and return value aren't inspected at all (e.g. MainLoop) then this is the hook type you should use.

The function signature of your hook must be `void(bool, OriginaFunctionParameters...)`, where the boolean value indicates whether it's being run before or after the original function is called.

If the return value is of interest one needs to cast it to depending on the original return type.  If the original return type is a pointer, simply cast it as that type; if it is not a pointer type, cast is a pointer to the original type. **This is only availble after the original function has been called**. Example:
* If the function returns `CExoString*` then `reinterpret_cast<CExoString*>`
* If the function returns `int32_t` then `reinterpret_cast<int32_t*>` and dereference.

**Usage Example**
```c++
using NWNXLib::API;

// ...

// Note here that you don't need to bother with the storing the hook unless you want to inspect the return value.
m_myhook = GetServices->m_hooks->RequestSharedHook<RequestSharedHook<Functions::_ZN21CServerExoAppInternal8MainLoopEv, int32_t>(&MainLoopInternalHandler);

// ...

// This needs to be a static function.
void MyPlugin::MainLoopInternalHandler(bool before, CServerExoAppInternal*)
{
    if (before)
    {
        // Do Something before the main loop
    }
    else
    {
        // Do Something after the main loop
        int32_t mainloopReturn = *reinterpret_cast<int32_t*>(m_myhook->m_sharedResult);
        // Consider what this return value means.
    }
}
```

## Exclusive

An exclusive hooks take complete control over a particular function.  There can only be one active exclusive hook at a time.  Attempting to hook a function that already has an exclusive hook in place, regardless of hook type, will result in an exception being thrown and the server process terminating.

**Usage Example**
```c++
m_myhook = GetServices()->m_hooks->RequestExclusiveHook<Functions::_ZN11CNWSMessage29SendServerToPlayerChatMessageEhj10CExoStringjRKS0_>(&MyPlugin::SendServerToPlayerChatMessage);

// ...

void MyPlugin::SendServerToPlayerChatMessage(CNWSMessage* thisPtr, Constants::ChatChannel::TYPE channel, Types::ObjectID sender,
    CExoString message, Types::PlayerID target, CExoString* tellName)
{
    if (theresSomethingToDo)
    {
        // Do It.
        return;
    }
    else
    {
        // Don't do anything and just call the original function.
        m_myhook->CallOriginal(thisPtr, channel, sender, message, target, tellName);
    }
}

```

## Chained

Chained hooks are much like exclusive hooks, except they allow daisy chaining.  Exclusive hooks have one, and only one owner, chained hooks have one owner and any number of sub-owners.  Each chained hook is called in order of registration until one decides to return a value and end the chain.  If the chain is exhausted, the original function will be called.

Plugin load order can matter.  If a plugin needs their hook to be called first (e.g. `NWNX_Profiler`) it should request a chained hook when the plugin is created, if not it's best to defer requesting a chained hook until after all plugins have been loaded or by user request.

**Usage Example**
```c++
s_RunScriptHook = GetServices()->m_hooks->RequestChainedHook<Functions::_ZN15CVirtualMachine9RunScriptEP10CExoStringji, int32_t>(
                    +[](CVirtualMachine* thisPtr, CExoString* script, Types::ObjectID objId, int32_t valid)
                    {
                        bool skip = false;
                        // Determine whether or not whether the plugin should return a value and end the chain or defer to the next chained hook.
                        return skip ? 1 : s_RunScriptHook->CallNext<int32_t>(thisPtr, script, objId, valid);
                    }
                );
```
