#pragma once

#include <cstdint>

#include "GLES2_ProgramCache.hpp"
#include "GLES2_ShaderCache.hpp"
#include "unknown_SDL_bool.hpp"
#include "unknown_TLS_83B4CBC5F1D33A6D9C7B6F03B876B72E.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct GLES2_FBOList;
struct GLES2_ProgramCacheEntry;

struct GLES2_DriverContext
{
    void** context;
    SDL_bool debug_enabled;
    TLS_83B4CBC5F1D33A6D9C7B6F03B876B72E current;
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
    void** m_funcPtrPlaceholder__44;
    void** m_funcPtrPlaceholder__45;
    void** m_funcPtrPlaceholder__46;
    void** m_funcPtrPlaceholder__47;
    void** m_funcPtrPlaceholder__48;
    void** m_funcPtrPlaceholder__49;
    void** m_funcPtrPlaceholder__50;
    void** m_funcPtrPlaceholder__51;
    void** m_funcPtrPlaceholder__52;
    void** m_funcPtrPlaceholder__53;
    void** m_funcPtrPlaceholder__54;
    GLES2_FBOList* framebuffers;
    uint32_t window_framebuffer;
    int32_t shader_format_count;
    uint32_t* shader_formats;
    GLES2_ShaderCache shader_cache;
    GLES2_ProgramCache program_cache;
    GLES2_ProgramCacheEntry* current_program;
    uint8_t clear_r;
    uint8_t clear_g;
    uint8_t clear_b;
    uint8_t clear_a;
};

}

}
