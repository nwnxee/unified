# NWNX_Core Build Script
# ------------------------------------------------------

if(WIN32)
    set(ENTRYPOINT "EntryPointWindows.cpp")
elseif(UNIX)
    set(ENTRYPOINT "EntryPointLinux.cpp")
endif()

add_library(Core SHARED ${ENTRYPOINT} NWNXCore.cpp)
add_sanitizers(Core)
set_target_properties(Core PROPERTIES PREFIX "${PLUGIN_PREFIX}")
target_compile_definitions(Core PRIVATE "-DPLUGIN_NAME=\"${PLUGIN_PREFIX}Core\"")
target_link_libraries(Core NWNXLib)

# The name defined here will be ignored when loading plugins.
add_definitions(-DNWNX_CORE_PLUGIN_NAME="${PLUGIN_PREFIX}Core")