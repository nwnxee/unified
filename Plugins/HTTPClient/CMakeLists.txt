find_package(OpenSSL)

if (${OPENSSL_FOUND})
    add_plugin(HTTPClient HTTPClient.cpp)
    add_definitions(-DCPPHTTPLIB_OPENSSL_SUPPORT)
    target_link_libraries(HTTPClient ${OPENSSL_LIBRARIES})
    target_include_directories(HTTPClient PUBLIC ${OPENSSL_INCLUDE_DIR})
endif()
