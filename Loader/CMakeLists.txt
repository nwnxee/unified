# Loader Build Script
# ------------------------------------------------------

add_executable(Loader
    "Main.cpp"
    "Loader.cpp")

target_link_libraries(Loader shlwapi)