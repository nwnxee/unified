add_subdirectory(cpp_redis)
include_directories(cpp_redis/includes)

add_plugin(Redis
  Redis.cpp
  NWScript.cpp
  Config.cpp
  Connection.cpp
  PubSub.cpp
  Util.cpp
)

target_link_libraries(Redis cpp_redis)
