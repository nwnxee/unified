macro(nwnxlib_scope)
    set(NWNXLIB_SOURCE ${NWNXLIB_SOURCE} PARENT_SCOPE)
endmacro()

macro(nwnxlib_add)
    file(RELATIVE_PATH rel "${CMAKE_SOURCE_DIR}/NWNXLib" "${CMAKE_CURRENT_SOURCE_DIR}")
    foreach(abs ${ARGN})
        if(rel)
            list (APPEND NWNXLIB_SOURCE "${rel}/${abs}")
        else()
            list (APPEND NWNXLIB_SOURCE "${abs}")
        endif()
    endforeach()
    if(rel)
        nwnxlib_scope()
    endif()
endmacro()

nwnxlib_add(
    "Assert.cpp"
    "Log.cpp"
    "Serialize.cpp"
    "Utils.cpp"
    "Encoding.cpp"
    "Plugin.cpp"
    "Commands.cpp"
    "Events.cpp"
    "MessageBus.cpp"
    "Hooks.cpp"
    "Tasks.cpp"
    "POS.cpp"
)

add_subdirectory(API)
add_subdirectory(External)
add_subdirectory(Platform)
add_subdirectory(Services)
add_subdirectory(Utils)

add_library(NWNXLib STATIC "${NWNXLIB_SOURCE}")
add_sanitizers(NWNXLib)

target_compile_definitions(NWNXLib PRIVATE "-DPLUGIN_NAME=\"NWNXLib\"")

target_include_directories(NWNXLib PUBLIC "." "API")

# We need this for dlopen/dlclose/dlsym.
target_link_libraries(NWNXLib ${CMAKE_DL_LIBS})

# For hooks -- pulled in from External.
target_link_libraries(NWNXLib funchook-static)
