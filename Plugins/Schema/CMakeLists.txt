add_plugin(Schema
    "Schema.cpp"
    "external/ajv/dist/ajv_bundle_data.h"
    "external/quickjs/src/quickjs.c"
    "external/quickjs/src/quickjs-libc.c"
    "external/quickjs/src/cutils.c"
    "external/quickjs/src/libregexp.c"
    "external/quickjs/src/libunicode.c"
    "external/quickjs/src/dtoa.c"
)

target_include_directories(Schema PRIVATE 
    "external/quickjs/src" 
    "external/ajv/dist"
)

target_compile_definitions(Schema PRIVATE 
    _GNU_SOURCE                    
    CONFIG_VERSION="2026"          
)
