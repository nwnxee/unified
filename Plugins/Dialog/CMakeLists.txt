if (NOT CMAKE_BUILD_TYPE STREQUAL "RelWithDebInfo")
    message( WARNING "The Dialog plugin can only be built with the CMAKE_BUILD_TYPE=RelWithDebInfo configuration." )
else()

    add_plugin(Dialog
        "Dialog.cpp")

endif()
