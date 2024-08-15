find_package(OpenSSL)

if (${OPENSSL_FOUND})
    add_plugin(HTTP HTTP.cpp HTTP/Client.cpp)
    add_definitions(-DCPPHTTPLIB_OPENSSL_SUPPORT)
    target_link_libraries(HTTP ${OPENSSL_LIBRARIES})
    target_include_directories(HTTP PUBLIC ${OPENSSL_INCLUDE_DIR})
endif()
