## How to contribute to NWNX:EE

Thank you for your interest in contributing to NWNX:EE, all contribution are welcome. If adding a new plugin or extending an existing one, feel free to send a PR and we can hash out any details in review. For changes to core, please discuss it with us first, either through discord or on an RFC issue.

### Plugins

All of NWNX useful functionality comes from plugins. Plugins typically expose additional NWN engine functionality to nwscript, but also sometimes provide an interface to external tools (SQL, Redis, etc) or languages (Lua, DotNET), or simply expose various events to the developer. Adding a new plugin is no big deal, but please check first if your new functionality would be better suited in one of the existing plugins.

Many plugins are structured as extension methods on a given object: Object, Creature, Player, Area, Item, etc. By convention, these functions will always take the object they are operating on as the first parameter. Try to follow this convention in other plugins as well, if it makes sense.

Your code should be structured such that, if unused, it should have (near) zero cost and not pull additional dependencies. Some examples:

 - If you are adding support for a new language, as a separate plugin, anyone who does not want to use it will just skip the plugin. No additional action necessary on your part.
 - If you are adding a new backend for an existing plugin (e.g. alternative SpellChecker library), be sure there's no compile- or load-time dependencies unless someone explicitly opts in to use it. This usually means using `dlsym()` to get function pointers from the library.
 - If you are exposing additional events in an existing plugin, do not hook them until the user has indicated they want to use them (either via an env. variable or nwscript call). See the Events plugin for examples.

### C++ Guidelines

1.  Avoid unnecessary abstractions.
2.  Avoid overly OOP design. Chances are what you want is just a function.
3.  Sometimes a macro is better than a template. Use common sense, do not shy away from C features.
4.  Never use non-const references as arguments. If a function will change the value of an object, pass it as a pointer.
5.  Do not write your own alternatives to C++ standard library features (e.g. std::optional, std::variant, etc).
6.  Avoid manual memory management. Use std::unique_ptr or stack allocations.
7.  Never do memory patching hacks. Plugin services provide a way to hook function calls, use those. If there is a problem you don't know how to solve other than patching a memory address, speak to us first.
8.  Use modern C++ features such as foreach loops and `auto`. It is advised that when dealing with pointers or references, you explicitly qualify `auto` as `auto&` or `auto*`.
9.  Use `#pragma once` instead of include guards.
10. Be wary of unnecessary copies. Use rvalues and `std::move` where appropriate.
11. Exception use is acceptable. In case of error when processing a nwscript invoked function, throw an exception.
12. Use core provided utilities (logging, asserts, etc) and services (config, messaging, etc) whenever possible. If you have a need these services don't meet, file an RFE.
13. Update the [changelog] whenever making a user-facing change (e.g. adding a new nwscript function)


Additionally, please observe coding style rules:

1.  Prefix members variables with m\_, static globals with s\_.
2.  Use lowerCamelCase for variables.
3.  Use UpperCamelCase for functions.
4.  Use UpperCamelCase for classes.
5.  Use ALL_CAPS for macros.
6.  Namespaced::UpperCamelCase for constants.
7.  Braces always start on a new line and always end on a new line.
8.  Spaces, not tabs.
9.  Newline at the end of file
10. C++ header files have .hpp extension. Source files have .cpp extension.



### NWScript Guidelines

We use DoxyGen to automatically generate our documentation, please have a look at existing .nss files to familiarize yourself with the layout of the NWNX:EE NWScript files.

When exposing a function to nwscript, name it as `NWNX_<PluginName>_<FunctionName>()`. If possible, the function should be implemented in `<PluginName>.cpp`, with the same `<FunctionName>` as specified in nwscript, and the function name string passed to core should match that as well.

If at all possible, write unit tests for your new feature in `nwnx_<pluginname>_t.nss`.

[changelog]: CHANGELOG.md
