@page nwnx Core Functions
@ingroup nwnx

## Core Functions For Plugin Developers
The core functions in nwnx.nss should be called by NWNX plugin developers, who should expose their own, more friendly headers.

#### Sample
This following function would wrap a call which passes three parameters, receives three back, and constructs a vector from the result.
```c
    vector GetVectorFromCoords(float x, float y, float z)
    {
        string pluginName = "NWNX_TestPlugin";
        string funcName = "GiveMeBackTheSameValues";

        // Note the inverse argument push order.
        // C++-side, arguments will be consumed from right to left.
        NWNX_PushArgumentFloat(pluginName, funcName, z);
        NWNX_PushArgumentFloat(pluginName, funcName, y);
        NWNX_PushArgumentFloat(pluginName, funcName, x);

        // This calls the function, which will prepare the return values.
        NWNX_CallFunction(pluginName, funcName);

        // C++-side pushes the return values in reverse order so we can consume them naturally here.
        float _x = NWNX_GetReturnValueFloat(pluginName, funcName);
        float _y = NWNX_GetReturnValueFloat(pluginName, funcName);
        float _z = NWNX_GetReturnValueFloat(pluginName, funcName);

        return vector(_x, _y, _z);
    }
```
@{
