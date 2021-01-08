add_custom_target(
    DotNETGenerate
    COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/generate.sh
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

add_library(DotNET SHARED "DotNET.cpp" "DotNETExports.cpp" "DotNETInterop.cpp")
set_property(SOURCE ${CMAKE_CURRENT_SOURCE_DIR}/DotNETInterop.cpp PROPERTY GENERATED 1)
add_sanitizers(DotNET)
target_link_libraries(DotNET Core)
set_target_properties(DotNET PROPERTIES PREFIX "${PLUGIN_PREFIX}")
target_include_directories(DotNET PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_compile_definitions(DotNET PRIVATE "-DPLUGIN_NAME=\"${PLUGIN_PREFIX}DotNET\"")
add_dependencies(DotNET DotNETGenerate)