#pragma once

#include <cstdint>

#include "unknown_GLDEBUGPROCARB.hpp"
#include "unknown_PFNGLACTIVETEXTUREARBPROC.hpp"
#include "unknown_PFNGLBINDFRAMEBUFFEREXTPROC.hpp"
#include "unknown_PFNGLCHECKFRAMEBUFFERSTATUSEXTPROC.hpp"
#include "unknown_PFNGLDELETEFRAMEBUFFERSEXTPROC.hpp"
#include "unknown_PFNGLFRAMEBUFFERTEXTURE2DEXTPROC.hpp"
#include "unknown_PFNGLGENFRAMEBUFFERSEXTPROC.hpp"
#include "unknown_SDL2_bool.hpp"
#include "unknown_TLS_E18F96875E62EB9BBEFD9E9CE746BF44.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct GL_FBOList;
struct GL_ShaderContext;

struct GL_RenderData
{
    void* context;
    SDL2_bool debug_enabled;
    SDL2_bool GL_ARB_debug_output_supported;
    int32_t errors;
    char** error_messages;
    GLDEBUGPROCARB next_error_callback;
    void* next_error_userparam;
    SDL2_bool GL_ARB_texture_non_power_of_two_supported;
    SDL2_bool GL_ARB_texture_rectangle_supported;
    TLS_E18F96875E62EB9BBEFD9E9CE746BF44 current;
    SDL2_bool GL_EXT_framebuffer_object_supported;
    GL_FBOList* framebuffers;
    void** m_funcPtrPlaceholder__0;
    void** m_funcPtrPlaceholder__1;
    void** m_funcPtrPlaceholder__2;
    void** m_funcPtrPlaceholder__3;
    void** m_funcPtrPlaceholder__4;
    void** m_funcPtrPlaceholder__5;
    void** m_funcPtrPlaceholder__6;
    void** m_funcPtrPlaceholder__7;
    void** m_funcPtrPlaceholder__8;
    void** m_funcPtrPlaceholder__9;
    void** m_funcPtrPlaceholder__10;
    void** m_funcPtrPlaceholder__11;
    void** m_funcPtrPlaceholder__12;
    void** m_funcPtrPlaceholder__13;
    void** m_funcPtrPlaceholder__14;
    void** m_funcPtrPlaceholder__15;
    void** m_funcPtrPlaceholder__16;
    void** m_funcPtrPlaceholder__17;
    void** m_funcPtrPlaceholder__18;
    void** m_funcPtrPlaceholder__19;
    void** m_funcPtrPlaceholder__20;
    void** m_funcPtrPlaceholder__21;
    void** m_funcPtrPlaceholder__22;
    void** m_funcPtrPlaceholder__23;
    void** m_funcPtrPlaceholder__24;
    void** m_funcPtrPlaceholder__25;
    void** m_funcPtrPlaceholder__26;
    void** m_funcPtrPlaceholder__27;
    void** m_funcPtrPlaceholder__28;
    void** m_funcPtrPlaceholder__29;
    void** m_funcPtrPlaceholder__30;
    void** m_funcPtrPlaceholder__31;
    void** m_funcPtrPlaceholder__32;
    void** m_funcPtrPlaceholder__33;
    void** m_funcPtrPlaceholder__34;
    void** m_funcPtrPlaceholder__35;
    void** m_funcPtrPlaceholder__36;
    void** m_funcPtrPlaceholder__37;
    void** m_funcPtrPlaceholder__38;
    void** m_funcPtrPlaceholder__39;
    void** m_funcPtrPlaceholder__40;
    void** m_funcPtrPlaceholder__41;
    void** m_funcPtrPlaceholder__42;
    void** m_funcPtrPlaceholder__43;
    SDL2_bool GL_ARB_multitexture_supported;
    PFNGLACTIVETEXTUREARBPROC glActiveTextureARB;
    int32_t num_texture_units;
    PFNGLGENFRAMEBUFFERSEXTPROC glGenFramebuffersEXT;
    PFNGLDELETEFRAMEBUFFERSEXTPROC glDeleteFramebuffersEXT;
    PFNGLFRAMEBUFFERTEXTURE2DEXTPROC glFramebufferTexture2DEXT;
    PFNGLBINDFRAMEBUFFEREXTPROC glBindFramebufferEXT;
    PFNGLCHECKFRAMEBUFFERSTATUSEXTPROC glCheckFramebufferStatusEXT;
    GL_ShaderContext* shaders;
};

}

}
