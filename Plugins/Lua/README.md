# Lua Plugin Reference

## Description

Allows users to call Lua code with NWScript binding.

## Environment Variables

| Variable Name     |  Type  | Default Value            |
| -------------     | :----: | -------------            |
| PRELOAD_SCRIPT    | string |  USERDIR/lua/preload.lua |
| TOKEN_FUNCTION    | string |  CallToken               |
| EVENT_FUNCTION    | string |  RunEvent                |
| OBJSELF_FUNCTION  | string |  _none_                  |
| RUNSCRIPT_TABLE   | string |  _none_                  |

## Quick start

### Docker

1. Include `nwnx_lua.nss` in your module
2. Enable the plugin and mount a complete copy of `unified/Plugins/Lua/lua` to your container. This is where all your scripts will go. Compose example: 
```yaml
    volumes:
      - ./server/:/nwn/home
      - ./lua:/nwn/run/lua/
    environment:
      - NWNX_LUA_SKIP=n
```
3. Continue from step 6 in the list below.

### Native

1. Install **LuaJIT**, i.e `sudo apt-get install luajit libluajit-5.1-dev`
2. Compile your plugin and install as any other nwnxee plugin
3. Don't set any configuration env variable
4. Import the `nwnx_lua.nss` script in the **NWScript** directory in your module
5. Copy the Lua directory inside your **USERDIR** (usually `.local/Neverwinter Nights/`), so you will have a **USERDIR/lua/preload.lua** file.
6. In your *"on module load script"* include *"nwnx_lua"* and add this line `NWNX_Lua_RunEvent("mod_load", OBJECT_SELF);`
7. In your *"on module chat script"* include *"nwnx_lua"* and add this line `NWNX_Lua_RunEvent("mod_chat",  GetPCChatSpeaker());`
8. Enter your module and put this line in your talk chat: `/c =GetName(oPC)` dont forget the '='
9. Press enter and you will get your name as server message
10. try the same with `/c ApplyEffectToObject(2, EffectHeal(10), oPC)` or `/c return GetName(GetArea(oPC))` or `/c =3+5` or `/c DelayCommand(oPC, 1.5, SpeakString, 'Foo')`
11. Have some fun with your chat command interpreter, every command you want evaled by Lua must start with `/c `, if you want a return value start with `/c =` or `/c return `
12. Look at the Lua scripts provided for some examples. The different ways to use this plugin are a lot, now you have NWScript binding in a interpred language, Lua, so you can do things like change a Lua script and hot reload it without even restart the module; for an example look at the `loadscript()` function in the preload script.


## Documentation
This plugin let you execute Lua code inside *NWscript* via two functions NWNX_Lua_EvalVoid() and NWNX_Lua_Eval(), the second one returning (as string) the result of the Lua code execution. With the NWNX_Lua_RunEvent() function you can generate events in NWScript, receive them on the Lua side and executing all the Lua functions registered to listen to that event in order of priority. For details on events just look at the three `*Event()` functions in `preload.lua`. 
Lastly the *run script hook* permit to run a Lua function before a script is executed in the module, with returning values from the function having special effects: from skipping the script execution to being treated as a StartingConditional() result (for details see the configuration section). 

In the Lua space all the basics NWScript functions are already defined, that by simply requiring the file `nwn.lua`. 

All functions returning a NWScript boolean (1 or 0) in Lua now returns a **boolean** (`true` or `false`), the same for functions accepting booleans, so in Lua you can write: `ClearAllActions(true)` or `if GetIsObjectValid(oObject) then .... end`

`OBJECT_SELF` and `OBJECT_INVALID` are defined too, the first changing and following the script context.

Only these functions are different from NWScript: `DelayCommand`, `AssignCommand` and `ActionDoCommand`

The signatures of the functions are:
```ruby
DelayCommand(oObject, fDelay, Function, 1stFunctionArg, 2ndFunctionArg .....)

AssignCommand(oObject, Function, 1stFunctionArg, 2ndFunctionArg .....)

ActionDoCommand(Function, 1stFunctionArg, 2ndFunctionArg .....)
```
For Example:
```ruby
DelayCommand(oPC, 2.5, SetLocalInt, oPC, "LOCAL_INT", 42)

AssignCommand(OBJECT_SELF, SpeakString, "Bar")

ActionDoCommand(SpeakString, "Here's my seat!");

```
Beware that for `DelayCommand` there is an additional argument (oObject) respect to the NWScript counterpart, so you can avoid to write `AssignCommand(oObject, DelayCommand, ...`. Just write `DelayCommand(oObject, 2.0  ....`. If you dont know how to set oObject just use `OBJECT_SELF`.

In the Lua namespace are defined, by the plugin, some additional utility functions. You can find them in the file `lua/additions.lua`, among these there are `SerializeObject()` and `DeserializeObject()`, useful if you want to use Lua to connect to database and saving/retrieving objects in it. 

They are also implemented `tostring(vVector)` or `vVector:tostring()`, `tostring(lLocation)` or `lLocation:tostring()` and the inverse `string.tovector()` or `sVector:vector()` and `string.tolocation()` or `sLocation:tolocation()`, the same as above useful if you want to save/retrieve vectors and locations in a database via lua.

Last but not least the function `GetTimeOfDay()` returns the time since Epoch in microseconds, useful for tracing execution speed.

**Important**: dont call *directly* **any** NWScript function in the preload script or any other directly required script, so avoid writing lines like SetLocalString(...), GetModule() etc, you can write them inside function definitions but, again, dont call these functions directly during preload. The preload script is loaded during the start of nwserver and before the module is even loaded. So any direct call to NWScript functions during preload time will crash the server. 

The trick is to load/require the others scripts in the module_load event, you can see how in the preload script.

The entire system is configurable ad hoc, if you have time you can even change the name of any NWScript function, use OOP programming, i.e using Lua classes instead of numbers for objects; with LuaJIT and FFi you can even directly access C structures.

## Installation and configuration

1) Just import in your module the two scripts in the NWScript directory.
2) Copy the *lua* directory inside your NWN user directory (usually `.local/share/Neverwinter Nights/`)

Here is the complete list of the configuration environment variables:

**NWNX_LUA_PRELOAD_SCRIPT** mandatory, the default value is `your_default_NWN_user_directory/lua/preload.lua`.

**NWNX_LUA_TOKEN_FUNCTION** mandatory, it's the name of the function used internally to emulate `DelayCommand`, `AssignCommand` and `ActionDoCommand`. The function is already defined in the preload script provided, default: `CallToken()`.

**NWNX_LUA_EVENT_FUNCTION** mandatory: you can use the event system for generate events inside NWScript, via the function `NWNX_Lua_RunEvent` provided in nwnx_lua.nss. These events can be consumend by a Lua function registered to observe the events, the default is `RunEvent()`, and it's already defined in the preload script. If you dont want to use the event system just dont call `NWNX_Lua_RunEvent()` on the NWScript side.

**NWNX_LUA_OBJSELF_FUNCTION** optional and advanced: in the Lua global namespace there is already a OBJECT_SELF global variable synced by the plugin at the right integer value following the context change. If you need to be more OOP and don't want to use integers for objects you have to change first the `RunEvent` function, because is accepting integers as objects. So you have to transform them in real objects inside the `RunEvent` function, just before the function call the observers callbacks. Second you have to set this configuration variable to the name of the function responsible for setting OBJECT_SELF to an object. The function will be called by the plugin with an integer value (the value of OBJECT_SELF) as argument when needed, i.e. when the context change. There is an example of `SetObjectSelf()` commented out in the preload script, note: it does not work by itself, you have to write oop code (i.e. a class for objects) before setting the configuration and uncommenting/modifying it. If this configuration is defined the function **must** be present in the preload script. Default: none.

**NWNX_LUA_RUNSCRIPT_TABLE** optional: this is the name of the *global* Lua **table** containing the functions called in the *run script hook*. A function with the same name of the script executed in the module will be run before the script itself. If the function returns something different from `nil` (i.e.: string, numbers or booleans) the script execution will be skipped, if the function returns a Lua boolean (`true` or `false`) it's treated like a return value from a StartingConditional(). 
For example if you have the script 'mod_on_chat.nss' in your module *onchat* event, if this configuration parameter is set to `Scripts`, when the `mod_on_chat` script is called the plugin search for a Lua function `Scripts.mod_on_chat()`. If the function is found it will be called before the 'mod_on_chat' script and the returned value determine if the original script is to be skipped. No argument is passed to the function, the context object is already represented by OBJECT_SELF. 
If this parameter is not defined no *run script hook* is set up. If this parameter is defined the basic table definition **must** be present in the preload script, a line like this one is enough:  `Scripts = {}` all the other functions of the run script table could be defined after the preloading phase, obviously apart from the mod_load function if you want one. Default: none.
**WARNING** dont set this config with any other *RunScript* hook in place, i.e. if you have the ENABLE_SCRIPTS of the Profiler plugin enabled dont set this config or you will have a server crash at startup. For the same reason enabling this setting makes this plugin not compatible with the Mono Plugin.

## Notes on Compilation
NWNX_Lua is configured to compile first against *LuaJIT*, and only if LuaJIT (and its library) cannot be find search for a regular Lua library.
So if you want to compile against LuaJIT just install it, otherwise install a regular Lua with liblua-dev provided by your distro; something like `sudo apt-get install luajit libluajit-5.1-dev` for luajit or `sudo apt-get install lua5.3 liblua5.3-dev` for regular Lua. 

I highly reccomend to use or try LuaJIT, it is really fast and has the FFI library for C bindings. There is a script provided ('compat.lua') that try to mantain compatibility with differents Lua versions, it's tested with LuaJIT and Lua 5.3 but should work with Lua 5.2 and Lua 5.1.

## Note on LuaJIT and extensions
If you want to use extensions in *LuaJIT* I highly reccomend to use *luarocks* to install them. To install and compile *luarocks* for *LuaJIT* downlowd it and compile/install with this two commands:
1) `./configure --lua-suffix=jit --with-lua-include=/usr/include/luajit-2.0`
2) `make build && sudo make install`

