find_package(OpenSSL)

if (${OPENSSL_FOUND})
    add_plugin(Bridge 
    "Bridge.cpp"
    "BridgeClient.cpp"
    "BridgeMessage.cpp"
    "BridgeHooks.cpp")
    target_link_libraries(Bridge ${OPENSSL_LIBRARIES})
    target_include_directories(Bridge PUBLIC ${OPENSSL_INCLUDE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/External)
endif()