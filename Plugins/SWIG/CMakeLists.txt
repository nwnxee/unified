find_package(SWIG 4.0 COMPONENTS csharp)

function(add_swig_plugin target interopfile)
    add_custom_command(
        OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/${interopfile}
        DEPENDS Core
        DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/DotNET.i
        COMMAND chmod a+x ./generate.sh && mkdir -p ./${target} && ${CMAKE_CURRENT_SOURCE_DIR}/generate.sh -v -c++ -fcompact -o ${interopfile} -outdir ./${target} -I../../NWNXLib/API ${ARGN}
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    )

    add_library(${target} SHARED ${interopfile})
    add_sanitizers(${target})
    target_link_libraries(${target} Core "-Wl,--no-undefined")
    set_target_properties(${target} PROPERTIES PREFIX "${PLUGIN_PREFIX}")
    target_include_directories(${target} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
    target_compile_definitions(${target} PRIVATE "-DPLUGIN_NAME=\"${PLUGIN_PREFIX}${target}\"")
endfunction()

if(SWIG_FOUND)
    message("-- Found SWIG library: ${SWIG_EXECUTABLE}")
    add_swig_plugin(SWIG_DotNET "DotNETInterop.cpp" -csharp -dllimport "${PLUGIN_PREFIX}SWIG_DotNET" -namespace "NWN.Native.API" "DotNET.i")
endif(SWIG_FOUND)
