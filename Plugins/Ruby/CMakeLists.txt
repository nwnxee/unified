find_package(Ruby)

# Newer FindRuby reports Ruby_* variables, older RUBY_*.
if (Ruby_FOUND OR RUBY_FOUND)
    if (NOT Ruby_INCLUDE_DIRS)
        set(Ruby_INCLUDE_DIRS ${RUBY_INCLUDE_DIRS})
    endif ()
    if (NOT Ruby_LIBRARIES)
        set(Ruby_LIBRARIES ${RUBY_LIBRARY})
    endif ()

    # FindRuby can succeed without the development headers.
    find_file(NWNX_RUBY_HEADER ruby.h PATHS ${Ruby_INCLUDE_DIRS} NO_DEFAULT_PATH)
endif ()

if (NWNX_RUBY_HEADER AND Ruby_LIBRARIES)
    add_plugin(Ruby "Ruby.cpp")
    target_include_directories(Ruby SYSTEM PRIVATE ${Ruby_INCLUDE_DIRS})
    target_link_libraries(Ruby ${Ruby_LIBRARIES})
else ()
    message(STATUS "Ruby headers not found, skipping Ruby plugin (install the Ruby development package, e.g. ruby-dev, to build it)")
endif ()
