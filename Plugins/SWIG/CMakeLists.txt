function(add_swig_plugin target interopfile)
    add_custom_target(
        Generate_${target}
        COMMAND mkdir -p ./${target} && ${CMAKE_CURRENT_SOURCE_DIR}/generate.sh -v -c++ -fcompact -o ${interopfile} -outdir ./${target} -I../../NWNXLib/API ${ARGN}
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    )

    add_library(${target} SHARED ${interopfile})
    set_property(SOURCE ${CMAKE_CURRENT_SOURCE_DIR}/${interopfile} PROPERTY GENERATED 1)
    add_sanitizers(${target})
    target_link_libraries(${target} Core "-Wl,--no-undefined")
    set_target_properties(${target} PROPERTIES PREFIX "${PLUGIN_PREFIX}")
    target_include_directories(${target} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
    target_compile_definitions(${target} PRIVATE "-DPLUGIN_NAME=\"${PLUGIN_PREFIX}${target}\"")
    add_dependencies(${target} Generate_${target})
endfunction()

add_swig_plugin(SWIG_DotNET "DotNETInterop.cpp" -csharp -dllimport "${PLUGIN_PREFIX}SWIG_DotNET" -namespace "NWN.Native.API" "DotNET.i")