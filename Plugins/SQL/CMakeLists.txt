add_plugin(SQL "SQL.cpp"
    "Targets/MySQL.cpp")

find_package(MySQL)
if (MYSQL_FOUND)
    add_definitions(-DNWNX_SQL_MYSQL_SUPPORT)
    target_include_directories(SQL PRIVATE "${MYSQL_INCLUDE_DIR}")
    target_link_libraries(SQL ${MYSQL_LIBRARY})
else (MYSQL_FOUND)
    message(WARNING "Not compiling with MYSQL support, not found")
endif (MYSQL_FOUND)
