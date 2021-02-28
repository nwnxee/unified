add_subdirectory(cpp_redis)

add_plugin(Redis
  Redis.cpp
  NWScript.cpp
  Config.cpp
  Connection.cpp
  PubSub.cpp
)

target_include_directories(Redis PRIVATE cpp_redis/includes)
target_link_libraries(Redis cpp_redis)
