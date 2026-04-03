add_shared_plugin(DotNET
    "DotNET.cpp"
    "DotNETExports.cpp")

target_compile_definitions(DotNET PUBLIC NETHOST_USE_AS_STATIC)
target_link_libraries(DotNET "${CMAKE_CURRENT_SOURCE_DIR}/External/Microsoft.NETCore.App.Host.linux-x64/libnethost.a")
