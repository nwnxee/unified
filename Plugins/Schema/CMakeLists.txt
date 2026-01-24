add_shared_plugin(Schema
    "Schema.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/external/ajv/dist/ajv_bundle_data.h"
    "external/quickjs/src/quickjs.c"
    "external/quickjs/src/quickjs-libc.c"
    "external/quickjs/src/cutils.c"
    "external/quickjs/src/libregexp.c"
    "external/quickjs/src/libunicode.c"
    "external/quickjs/src/dtoa.c"
)

target_include_directories(Schema PRIVATE 
    ${CMAKE_SOURCE_DIR}            
    ${CMAKE_CURRENT_SOURCE_DIR}   
    ${CMAKE_CURRENT_BINARY_DIR}    
    "${CMAKE_CURRENT_SOURCE_DIR}/external/quickjs/src" 
    "${CMAKE_CURRENT_SOURCE_DIR}/external/ajv/dist"
)

target_compile_definitions(Schema PRIVATE 
    _GNU_SOURCE                    
    CONFIG_VERSION="2026"          
)

set_target_properties(Schema PROPERTIES LINK_FLAGS "-rdynamic")
