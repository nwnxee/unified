# NWNX_Core Build Script
# ------------------------------------------------------

add_library(Core SHARED ${ENTRYPOINT} NWNXCore.cpp NWNXCoreVM.cpp)
add_sanitizers(Core)
set_target_properties(Core PROPERTIES PREFIX "${PLUGIN_PREFIX}")
target_compile_definitions(Core PRIVATE "-DPLUGIN_NAME=\"${PLUGIN_PREFIX}Core\"")
target_link_libraries(Core NWNXLib)

if(MSVC)
    file(DOWNLOAD https://nwn.beamdog.net/downloads/nwnee-dedicated-8193.35-40.zip nwserver.zip)
    file(ARCHIVE_EXTRACT INPUT nwserver.zip DESTINATION "." PATTERNS "bin/win32/nwserver.exe")

    add_custom_command(
        OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/nwserver.lib"
        DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/create_lib.bat
        COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/create_lib.bat ARGS "bin/win32/nwserver.exe"
    )

    add_custom_target(NWServerLib DEPENDS "${CMAKE_CURRENT_BINARY_DIR}/nwserver.lib")

    add_dependencies(Core NWServerLib)
    set_target_properties(Core PROPERTIES WINDOWS_EXPORT_ALL_SYMBOLS TRUE)
    set_target_properties(Core PROPERTIES BUILD_SHARED_LIBS TRUE)
    set_target_properties(Core PROPERTIES ENABLE_EXPORTS TRUE)
    target_link_libraries(Core "${CMAKE_CURRENT_BINARY_DIR}/nwserver.lib")
endif ()

# The name defined here will be ignored when loading plugins.
add_definitions(-DNWNX_CORE_PLUGIN_NAME="${PLUGIN_PREFIX}Core")

