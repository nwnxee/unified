#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct GLES2_ShaderInstance;

struct GLES2_Shader
{
    int32_t instance_count;
    const GLES2_ShaderInstance* instances[4];
};

}

}
