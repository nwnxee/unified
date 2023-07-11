add_executable(Launcher WIN32 main.cpp)
target_link_libraries(Launcher PRIVATE detours)

set_target_properties(Launcher PROPERTIES PREFIX "${PLUGIN_PREFIX}")
