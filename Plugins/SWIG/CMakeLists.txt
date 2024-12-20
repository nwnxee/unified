find_package(SWIG 4.0 COMPONENTS csharp)

function(add_swig_plugin target language interfaces)
    add_custom_command(
        OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/${target}/NWNXLib.i
        DEPENDS Core
        DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/generate.sh
        COMMAND chmod a+x ../generate.sh && ../generate.sh
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${target}
    )

    set_property(SOURCE ${interfaces} PROPERTY CPLUSPLUS ON)
    set_property(SOURCE ${interfaces} PROPERTY DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/${target}/NWNXLib.i)
    set_property(SOURCE ${interfaces} PROPERTY COMPILE_OPTIONS ${ARGN})

    swig_add_library(${target} TYPE SHARED LANGUAGE ${language} SOURCES ${interfaces} OUTPUT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/${target}/out )
    configure_plugin(${target})

    # By adding nwserver-linux to the SWIG directory, we can check for any undefined symbols from mismatching headers.
    if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/nwserver-linux)
        add_library( nwserver SHARED IMPORTED )
        set_target_properties( nwserver PROPERTIES IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/nwserver-linux )
        target_link_libraries(${target} nwserver)
        target_link_options(${target} PRIVATE "LINKER:--no-undefined")
    endif()

    set_target_properties(${target} PROPERTIES
      SWIG_INCLUDE_DIRECTORIES ../../../NWNXLib/API
      SWIG_USE_TARGET_INCLUDE_DIRECTORIES ON
      POSITION_INDEPENDENT_CODE ON)

    if(CMAKE_GENERATOR MATCHES "Make")
        set(post_process_target ${target}_swig_compilation)
    else()
        message(STATUS "Generator '${CMAKE_GENERATOR}' does not create intermediate SWIG projects. Post processing will occur after plugin generation.")
        set(post_process_target ${target})
    endif()

    add_custom_command(TARGET ${post_process_target} POST_BUILD
            COMMAND chmod a+x postprocess.sh && ./postprocess.sh
            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${target}
    )
endfunction()

if(SWIG_FOUND)
    cmake_policy(SET CMP0078 NEW)
    INCLUDE(${SWIG_USE_FILE})

    add_swig_plugin(SWIG_DotNET csharp
        "${CMAKE_CURRENT_SOURCE_DIR}/SWIG_DotNET/API_NWNXLib.i"
        -DSWIGWORDSIZE64 -dllimport "${PLUGIN_PREFIX}SWIG_DotNET" -namespace "NWN.Native.API")
endif(SWIG_FOUND)
