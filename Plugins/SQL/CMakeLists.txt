add_plugin(SQL "SQL.cpp"
    "Targets/MySQL.cpp"
    "Targets/PostgreSQL.cpp")

find_package(MySQL)
if (MYSQL_FOUND)
    add_definitions(-DNWNX_SQL_MYSQL_SUPPORT)
    target_include_directories(SQL PRIVATE "${MYSQL_INCLUDE_DIR}")
    target_link_libraries(SQL ${MYSQL_LIBRARY})
else (MYSQL_FOUND)
    message(WARNING "Not compiling with MYSQL support, not found")
endif (MYSQL_FOUND)

find_package(PostgreSQL)
if (POSTGRESQL_FOUND)
    add_definitions(-DNWNX_SQL_POSTGRESQL_SUPPORT)
    target_include_directories(SQL PRIVATE "${POSTGRESQL_INCLUDE_DIR}")
    target_link_libraries(SQL ${POSTGRESQL_LIBRARY})
else (POSTGRESQL_FOUND)
    message(WARNING "Not compiling with PostgreSQL support, not found")
endif (POSTGRESQL_FOUND)
