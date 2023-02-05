# temporarily disabled
return()

find_package(SWIG 4.0 COMPONENTS csharp)

function(add_swig_plugin target language interfaces)
    add_custom_command(
        OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/${target}/NWNXLib.i
        DEPENDS Core
        DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/generate.sh
        COMMAND chmod a+x ../generate.sh && mkdir -p ./out && ../generate.sh
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${target}
    )

    set_property(SOURCE ${interfaces} PROPERTY CPLUSPLUS ON)
    set_property(SOURCE ${interfaces} PROPERTY DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/${target}/NWNXLib.i)
    set_property(SOURCE ${interfaces} PROPERTY COMPILE_OPTIONS ${ARGN})

    swig_add_library(${target} TYPE SHARED LANGUAGE ${language} SOURCES ${interfaces})
    configure_plugin(${target})

    set_target_properties(${target} PROPERTIES
      SWIG_INCLUDE_DIRECTORIES ../../../NWNXLib/API
      SWIG_USE_TARGET_INCLUDE_DIRECTORIES ON
      POSITION_INDEPENDENT_CODE ON)
endfunction()

if(SWIG_FOUND)
    cmake_policy(SET CMP0078 NEW)
    INCLUDE(${SWIG_USE_FILE})

    add_swig_plugin(SWIG_DotNET csharp
        "${CMAKE_CURRENT_SOURCE_DIR}/SWIG_DotNET/API_NWNXLib.i"
        -DSWIGWORDSIZE64 -dllimport "${PLUGIN_PREFIX}SWIG_DotNET" -namespace "NWN.Native.API")
endif(SWIG_FOUND)
