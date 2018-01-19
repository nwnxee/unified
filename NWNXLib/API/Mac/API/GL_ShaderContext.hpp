#pragma once

#include <cstdint>

#include "GL_ShaderData.hpp"
#include "unknown_PFNGLATTACHOBJECTARBPROC.hpp"
#include "unknown_PFNGLCOMPILESHADERARBPROC.hpp"
#include "unknown_PFNGLCREATEPROGRAMOBJECTARBPROC.hpp"
#include "unknown_PFNGLCREATESHADEROBJECTARBPROC.hpp"
#include "unknown_PFNGLDELETEOBJECTARBPROC.hpp"
#include "unknown_PFNGLGETINFOLOGARBPROC.hpp"
#include "unknown_PFNGLGETOBJECTPARAMETERIVARBPROC.hpp"
#include "unknown_PFNGLGETUNIFORMLOCATIONARBPROC.hpp"
#include "unknown_PFNGLLINKPROGRAMARBPROC.hpp"
#include "unknown_PFNGLSHADERSOURCEARBPROC.hpp"
#include "unknown_PFNGLUNIFORM1FARBPROC.hpp"
#include "unknown_PFNGLUNIFORM1IARBPROC.hpp"
#include "unknown_PFNGLUSEPROGRAMOBJECTARBPROC.hpp"
#include "unknown_SDL2_bool.hpp"

namespace NWNXLib {

namespace API {

struct GL_ShaderContext
{
    void** m_funcPtrPlaceholder__0;
    PFNGLATTACHOBJECTARBPROC glAttachObjectARB;
    PFNGLCOMPILESHADERARBPROC glCompileShaderARB;
    PFNGLCREATEPROGRAMOBJECTARBPROC glCreateProgramObjectARB;
    PFNGLCREATESHADEROBJECTARBPROC glCreateShaderObjectARB;
    PFNGLDELETEOBJECTARBPROC glDeleteObjectARB;
    PFNGLGETINFOLOGARBPROC glGetInfoLogARB;
    PFNGLGETOBJECTPARAMETERIVARBPROC glGetObjectParameterivARB;
    PFNGLGETUNIFORMLOCATIONARBPROC glGetUniformLocationARB;
    PFNGLLINKPROGRAMARBPROC glLinkProgramARB;
    PFNGLSHADERSOURCEARBPROC glShaderSourceARB;
    PFNGLUNIFORM1IARBPROC glUniform1iARB;
    PFNGLUNIFORM1FARBPROC glUniform1fARB;
    PFNGLUSEPROGRAMOBJECTARBPROC glUseProgramObjectARB;
    SDL2_bool GL_ARB_texture_rectangle_supported;
    GL_ShaderData shaders[6];
};

}

}
