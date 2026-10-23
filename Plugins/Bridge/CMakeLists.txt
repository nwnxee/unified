find_package(OpenSSL)
unset(CEREAL_INCLUDE_DIR CACHE)
find_path(CEREAL_INCLUDE_DIR
    NAMES "cereal/cereal.hpp")

if (${OPENSSL_FOUND})
    if(CEREAL_INCLUDE_DIR)
        add_plugin(Bridge 
        "Bridge.cpp"
        "BridgeClient.cpp"
        "BridgeMessage.cpp"
        "BridgeHooks.cpp"
        "BridgeWebserver.cpp")
        target_link_libraries(Bridge ${OPENSSL_LIBRARIES})
        target_include_directories(Bridge PUBLIC ${OPENSSL_INCLUDE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/External ${CEREAL_INCLUDE_DIR})
    else()
        message(WARNING "Bridge module skipped: Cereal not found. Try installing libcereal-dev.")
    endif()
else()
    message(WARNING "Bridge module skipped: OpenSSL not found.")
endif()