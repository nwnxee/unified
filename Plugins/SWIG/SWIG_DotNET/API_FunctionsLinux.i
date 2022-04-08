%module FunctionsLinux

%include <stdint.i>

#pragma SWIG nowarn=317
#define NWNXLIB_FUNCTION_NO_VERSION_CHECK
#define NWNX_SWIG_PARSING

%pragma(csharp) moduleclassmodifiers="public static class"

%define NWNXLIB_FUNCTION(name, address)
%constant uintptr_t name = address;
%enddef

%include "FunctionsLinux.hpp"

#undef NWNXLIB_FUNCTION
