find_package(OpenSSL)

if (${OPENSSL_FOUND})
    add_plugin(WebHook WebHook.cpp)
    target_link_libraries(WebHook ${OPENSSL_LIBRARIES})
    target_include_directories(WebHook PUBLIC ${OPENSSL_INCLUDE_DIR})
endif()
