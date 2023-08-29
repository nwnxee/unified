add_subdirectory(funchook)
add_subdirectory(sqlite3)

if(MSVC)
add_subdirectory(detours)
endif()
