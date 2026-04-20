find_package(OpenSSL)

if (${OPENSSL_FOUND})
    add_plugin(OpenAI OpenAI.cpp)
    target_link_libraries(OpenAI ${OPENSSL_LIBRARIES})
    target_include_directories(OpenAI PUBLIC ${OPENSSL_INCLUDE_DIR})
endif()
